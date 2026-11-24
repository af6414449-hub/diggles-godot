
/* Library Function - Single Match
    _LanguageEnumProc@4
   
   Library: Visual Studio 2019 Release */

void _LanguageEnumProc_4(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  LCID Locale;
  undefined4 uVar4;
  WCHAR local_f8 [120];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  iVar2 = ___acrt_getptd();
  iVar3 = ___acrt_getptd();
  puVar1 = *(uint **)(iVar3 + 0x34c);
  Locale = _LcidFromHexString(param_1);
  iVar3 = GetLocaleInfoW(Locale,(-(uint)(*(int *)(iVar2 + 0x60) != 0) & 0xfffff002) + 0x1001,
                         local_f8,0x78);
  if (iVar3 == 0) {
    *puVar1 = 0;
    goto LAB_006ef553;
  }
  iVar3 = __wcsicmp(*(wchar_t **)(iVar2 + 0x50),local_f8);
  if (iVar3 == 0) {
    if (*(int *)(iVar2 + 0x60) == 0) {
      uVar4 = 1;
      goto LAB_006ef533;
    }
  }
  else {
    if (((*(int *)(iVar2 + 0x60) != 0) || (*(int *)(iVar2 + 0x5c) == 0)) ||
       (iVar2 = __wcsicmp(*(wchar_t **)(iVar2 + 0x50),local_f8), iVar2 != 0)) goto LAB_006ef553;
    uVar4 = 0;
LAB_006ef533:
    iVar2 = _TestDefaultLanguage(Locale,uVar4,puVar1);
    if (iVar2 == 0) goto LAB_006ef553;
  }
  *puVar1 = *puVar1 | 4;
  puVar1[1] = Locale;
  puVar1[2] = Locale;
LAB_006ef553:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

