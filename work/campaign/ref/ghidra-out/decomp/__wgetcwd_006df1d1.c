
/* Library Function - Single Match
    __wgetcwd
   
   Library: Visual Studio 2019 Release */

wchar_t * __cdecl __wgetcwd(wchar_t *_DstBuf,int _SizeInWords)

{
  wchar_t *pwVar1;
  
  pwVar1 = common_getdcwd<wchar_t>(0,_DstBuf,_SizeInWords,1,(char *)0x0,0);
  return pwVar1;
}

