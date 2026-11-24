
/* Library Function - Single Match
    __strnicmp
   
   Library: Visual Studio 2019 Release */

int __cdecl __strnicmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  int *piVar1;
  int iVar2;
  
  if (DAT_00769d54 == 0) {
    if ((_Str1 == (char *)0x0) || (_Str2 == (char *)0x0)) {
      piVar1 = __errno();
      *piVar1 = 0x16;
      FUN_006e510d();
      iVar2 = 0x7fffffff;
    }
    else {
      if (_MaxCount < 0x80000000) {
        iVar2 = ___ascii_strnicmp(_Str1,_Str2,_MaxCount);
        return iVar2;
      }
      piVar1 = __errno();
      *piVar1 = 0x16;
      FUN_006e510d();
      iVar2 = 0x7fffffff;
    }
  }
  else {
    iVar2 = __strnicmp_l(_Str1,_Str2,_MaxCount,(_locale_t)0x0);
  }
  return iVar2;
}

