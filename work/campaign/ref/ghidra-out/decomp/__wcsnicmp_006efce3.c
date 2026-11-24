
/* Library Function - Single Match
    __wcsnicmp
   
   Library: Visual Studio 2019 Release */

int __cdecl __wcsnicmp(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount)

{
  int *piVar1;
  int iVar2;
  
  if (DAT_00769d54 != 0) {
    iVar2 = __wcsnicmp_l(_Str1,_Str2,_MaxCount,(_locale_t)0x0);
    return iVar2;
  }
  if ((_Str1 != (wchar_t *)0x0) && (_Str2 != (wchar_t *)0x0)) {
    iVar2 = ___ascii_wcsnicmp();
    return iVar2;
  }
  piVar1 = __errno();
  *piVar1 = 0x16;
  FUN_006e510d();
  return 0x7fffffff;
}

