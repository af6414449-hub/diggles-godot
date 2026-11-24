
/* Library Function - Single Match
    _strtok
   
   Library: Visual Studio 2019 Release */

char * __cdecl _strtok(char *_Str,char *_Delim)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = ___acrt_getptd();
  pcVar2 = (char *)___acrt_strtok_s_novalidation(_Str,_Delim,iVar1 + 0x1c);
  return pcVar2;
}

