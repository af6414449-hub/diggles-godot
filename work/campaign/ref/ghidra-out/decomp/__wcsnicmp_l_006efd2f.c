
/* Library Function - Single Match
    __wcsnicmp_l
   
   Library: Visual Studio 2019 Release */

int __cdecl __wcsnicmp_l(wchar_t *_Str1,wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale)

{
  wchar_t wVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int local_18;
  int local_14 [2];
  char local_c;
  uint local_8;
  
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
  else if (_MaxCount == 0) {
    iVar3 = 0;
  }
  else {
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_18,(__crt_locale_pointers *)_Locale);
    if (*(int *)(local_14[0] + 0xa8) == 0) {
      iVar3 = ___ascii_wcsnicmp(_Str1,_Str2,_MaxCount);
    }
    else {
      do {
        local_8 = __towlower_internal(*_Str1,local_14);
        local_8 = local_8 & 0xffff;
        _Str1 = _Str1 + 1;
        wVar1 = *_Str2;
        _Str2 = _Str2 + 1;
        uVar4 = __towlower_internal(wVar1,local_14);
        iVar3 = local_8 - (uVar4 & 0xffff);
        if ((iVar3 != 0) || (local_8 == 0)) break;
        _MaxCount = _MaxCount - 1;
      } while (_MaxCount != 0);
    }
    if (local_c != '\0') {
      *(uint *)(local_18 + 0x350) = *(uint *)(local_18 + 0x350) & 0xfffffffd;
    }
  }
  return iVar3;
}

