
/* Library Function - Single Match
    __wcsicmp_l
   
   Library: Visual Studio 2019 Release */

int __cdecl __wcsicmp_l(wchar_t *_Str1,wchar_t *_Str2,_locale_t _Locale)

{
  wchar_t wVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int local_14;
  int local_10 [2];
  char local_8;
  
  if (_Str1 == (wchar_t *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    iVar3 = 0x7fffffff;
  }
  else if (_Str2 == (wchar_t *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    iVar3 = 0x7fffffff;
  }
  else {
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,(__crt_locale_pointers *)_Locale);
    if (*(int *)(local_10[0] + 0xa8) == 0) {
      iVar3 = ___ascii_wcsicmp(_Str1,_Str2);
    }
    else {
      do {
        uVar4 = __towlower_internal(*_Str1,local_10);
        wVar1 = *_Str2;
        _Str1 = _Str1 + 1;
        _Str2 = _Str2 + 1;
        uVar5 = __towlower_internal(wVar1,local_10);
        iVar3 = (uVar4 & 0xffff) - (uVar5 & 0xffff);
        if (iVar3 != 0) break;
      } while ((uVar4 & 0xffff) != 0);
    }
    if (local_8 != '\0') {
      *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
    }
  }
  return iVar3;
}

