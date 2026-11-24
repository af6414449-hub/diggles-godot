
/* Library Function - Single Match
    __getcwd
   
   Library: Visual Studio 2019 Release */

char * __cdecl __getcwd(char *_DstBuf,int _SizeInBytes)

{
  char *pcVar1;
  
  pcVar1 = common_getdcwd<char>(0,_DstBuf,_SizeInBytes,1,(char *)0x0,0);
  return pcVar1;
}

