
/* Library Function - Single Match
    _LangCountryEnumProc@4
   
   Library: Visual Studio 2019 Release */

void _LangCountryEnumProc_4(undefined4 param_1)

{
  short *psVar1;
  short sVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  LCID Locale;
  short *psVar7;
  undefined8 uVar8;
  WCHAR local_f8 [120];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  iVar5 = ___acrt_getptd();
  iVar6 = ___acrt_getptd();
  puVar3 = *(uint **)(iVar6 + 0x34c);
  Locale = _LcidFromHexString(param_1);
  iVar6 = GetLocaleInfoW(Locale,(-(uint)(*(int *)(iVar5 + 100) != 0) & 0xfffff005) + 0x1002,local_f8
                         ,0x78);
  if (iVar6 == 0) {
LAB_006ef479:
    *puVar3 = 0;
    goto LAB_006ef47e;
  }
  iVar6 = __wcsicmp(*(wchar_t **)(iVar5 + 0x54),local_f8);
  if (iVar6 == 0) {
    iVar6 = GetLocaleInfoW(Locale,(-(uint)(*(int *)(iVar5 + 0x60) != 0) & 0xfffff002) + 0x1001,
                           local_f8,0x78);
    if (iVar6 == 0) goto LAB_006ef479;
    iVar6 = __wcsicmp(*(wchar_t **)(iVar5 + 0x50),local_f8);
    if (iVar6 == 0) {
      puVar3[1] = Locale;
      *puVar3 = *puVar3 | 0x304;
LAB_006ef370:
      puVar3[2] = Locale;
    }
    else if ((*puVar3 & 2) == 0) {
      if ((*(int *)(iVar5 + 0x5c) == 0) ||
         (iVar6 = __wcsnicmp(*(wchar_t **)(iVar5 + 0x50),local_f8,*(size_t *)(iVar5 + 0x5c)),
         iVar6 != 0)) {
        if ((*puVar3 & 1) == 0) {
          uVar8 = _TestDefaultCountry(Locale);
          if ((int)uVar8 != 0) {
            *puVar3 = (uint)((ulonglong)uVar8 >> 0x20) | 1;
            goto LAB_006ef370;
          }
        }
      }
      else {
        *puVar3 = *puVar3 | 2;
        puVar3[2] = Locale;
        psVar7 = *(short **)(iVar5 + 0x50);
        psVar1 = psVar7 + 1;
        do {
          sVar2 = *psVar7;
          psVar7 = psVar7 + 1;
        } while (sVar2 != 0);
        if ((int)psVar7 - (int)psVar1 >> 1 == *(int *)(iVar5 + 0x5c)) {
          puVar3[1] = Locale;
        }
      }
    }
  }
  if ((*puVar3 & 0x300) == 0x300) goto LAB_006ef47e;
  iVar6 = GetLocaleInfoW(Locale,(-(uint)(*(int *)(iVar5 + 0x60) != 0) & 0xfffff002) + 0x1001,
                         local_f8,0x78);
  if (iVar6 == 0) goto LAB_006ef479;
  iVar6 = __wcsicmp(*(wchar_t **)(iVar5 + 0x50),local_f8);
  if (iVar6 == 0) {
    uVar4 = *puVar3;
    *puVar3 = uVar4 | 0x200;
    if ((*(int *)(iVar5 + 0x60) == 0) && (*(int *)(iVar5 + 0x5c) != 0)) {
      psVar7 = *(short **)(iVar5 + 0x50);
      psVar1 = psVar7 + 1;
      do {
        sVar2 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar2 != 0);
      if ((int)psVar7 - (int)psVar1 >> 1 != *(int *)(iVar5 + 0x5c)) goto LAB_006ef3d2;
      iVar5 = _TestDefaultLanguage(Locale,1,puVar3);
      if (iVar5 == 0) goto LAB_006ef47e;
      *puVar3 = *puVar3 | 0x100;
    }
    else {
LAB_006ef3d2:
      *puVar3 = uVar4 | 0x300;
    }
    uVar4 = puVar3[1];
  }
  else {
    if ((((*(int *)(iVar5 + 0x60) != 0) || (*(int *)(iVar5 + 0x5c) == 0)) ||
        (iVar5 = __wcsicmp(*(wchar_t **)(iVar5 + 0x50),local_f8), iVar5 != 0)) ||
       (iVar5 = _TestDefaultLanguage(Locale,0,puVar3), iVar5 == 0)) goto LAB_006ef47e;
    *puVar3 = *puVar3 | 0x100;
    uVar4 = puVar3[1];
  }
  if (uVar4 == 0) {
    puVar3[1] = Locale;
  }
LAB_006ef47e:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

