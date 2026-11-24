
/* Library Function - Single Match
    __towlower_l
   
   Library: Visual Studio 2019 Release */

wint_t __cdecl __towlower_l(wint_t _C,_locale_t _Locale)

{
  int iVar1;
  byte bVar2;
  int local_18;
  int local_14;
  char local_c;
  ushort local_8 [2];
  
  if (_C == 0xffff) {
    return 0xffff;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_18,(__crt_locale_pointers *)_Locale);
  if (_C < 0x100) {
    bVar2 = (byte)_C;
    if (((&DAT_0071874a)[(uint)bVar2 * 2] & 1) != 0) {
      bVar2 = *(byte *)(*(int *)(local_14 + 0x94) + (uint)bVar2);
    }
    _C = (wint_t)bVar2;
  }
  else if ((*(int *)(local_14 + 0xa8) != 0) &&
          (iVar1 = ___acrt_LCMapStringW(*(int *)(local_14 + 0xa8),0x100,&_C,1,local_8,1), iVar1 != 0
          )) goto LAB_006f24d2;
  local_8[0] = _C;
LAB_006f24d2:
  if (local_c != '\0') {
    *(uint *)(local_18 + 0x350) = *(uint *)(local_18 + 0x350) & 0xfffffffd;
  }
  return local_8[0];
}

