
/* Library Function - Single Match
    _CountryEnumProc@4
   
   Library: Visual Studio 2019 Release */

void _CountryEnumProc_4(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  LCID Locale;
  WCHAR local_f8 [120];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  iVar2 = ___acrt_getptd();
  iVar3 = ___acrt_getptd();
  puVar1 = *(uint **)(iVar3 + 0x34c);
  Locale = _LcidFromHexString(param_1);
  iVar3 = GetLocaleInfoW(Locale,(-(uint)(*(int *)(iVar2 + 100) != 0) & 0xfffff005) + 0x1002,local_f8
                         ,0x78);
  if (iVar3 == 0) {
    *puVar1 = 0;
  }
  else {
    iVar2 = __wcsicmp(*(wchar_t **)(iVar2 + 0x54),local_f8);
    if ((iVar2 == 0) && (iVar2 = _TestDefaultCountry(Locale), iVar2 != 0)) {
      *puVar1 = *puVar1 | 4;
      puVar1[2] = Locale;
      puVar1[1] = Locale;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

