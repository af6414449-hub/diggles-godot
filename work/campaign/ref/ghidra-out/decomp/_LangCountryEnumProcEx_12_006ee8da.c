
/* Library Function - Single Match
    _LangCountryEnumProcEx@12
   
   Library: Visual Studio 2019 Release */

void _LangCountryEnumProcEx_12(short *param_1)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  wchar_t local_88 [64];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  iVar4 = ___acrt_getptd();
  iVar5 = ___acrt_GetLocaleInfoEx_16
                    (param_1,(-(uint)(*(int *)(iVar4 + 100) != 0) & 0xfffff005) + 0x1002,local_88,
                     0x40);
  if (iVar5 == 0) {
    *(undefined4 *)(iVar4 + 0x58) = 0;
    goto LAB_006eeb9d;
  }
  iVar5 = __wcsicmp(*(wchar_t **)(iVar4 + 0x54),local_88);
  if (iVar5 != 0) goto LAB_006eea0a;
  iVar5 = ___acrt_GetLocaleInfoEx_16
                    (param_1,(-(uint)(*(int *)(iVar4 + 0x60) != 0) & 0xfffff002) + 0x1001,local_88,
                     0x40);
  if (iVar5 == 0) {
    *(undefined4 *)(iVar4 + 0x58) = 0;
    goto LAB_006eeb9d;
  }
  iVar5 = __wcsicmp(*(wchar_t **)(iVar4 + 0x50),local_88);
  psVar6 = param_1;
  if (iVar5 == 0) {
    *(uint *)(iVar4 + 0x58) = *(uint *)(iVar4 + 0x58) | 0x304;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
LAB_006ee9e8:
    iVar5 = FUN_006ed6af(iVar4 + 0x2a0,0x55,param_1,((int)psVar6 - (int)(param_1 + 1) >> 1) + 1);
    if (iVar5 != 0) goto LAB_006eebaf;
  }
  else if ((*(uint *)(iVar4 + 0x58) & 2) == 0) {
    if ((*(int *)(iVar4 + 0x5c) == 0) ||
       (iVar5 = __wcsnicmp(*(wchar_t **)(iVar4 + 0x50),local_88,*(size_t *)(iVar4 + 0x5c)),
       iVar5 != 0)) {
      if (((*(byte *)(iVar4 + 0x58) & 1) != 0) || (iVar5 = _TestDefaultCountry(param_1), iVar5 == 0)
         ) goto LAB_006eea0a;
      *(uint *)(iVar4 + 0x58) = *(uint *)(iVar4 + 0x58) | 1;
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
    }
    else {
      *(uint *)(iVar4 + 0x58) = *(uint *)(iVar4 + 0x58) | 2;
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
    }
    goto LAB_006ee9e8;
  }
LAB_006eea0a:
  if ((*(uint *)(iVar4 + 0x58) & 0x300) == 0x300) goto LAB_006eeb9d;
  iVar5 = ___acrt_GetLocaleInfoEx_16
                    (param_1,(-(uint)(*(int *)(iVar4 + 0x60) != 0) & 0xfffff002) + 0x1001,local_88,
                     0x40);
  if (iVar5 == 0) {
    *(undefined4 *)(iVar4 + 0x58) = 0;
    goto LAB_006eeb9d;
  }
  iVar5 = __wcsicmp(*(wchar_t **)(iVar4 + 0x50),local_88);
  if (iVar5 != 0) goto LAB_006eeb9d;
  uVar3 = *(uint *)(iVar4 + 0x58);
  *(uint *)(iVar4 + 0x58) = uVar3 | 0x200;
  psVar6 = param_1;
  if (*(int *)(iVar4 + 0x60) == 0) {
    if (*(int *)(iVar4 + 0x5c) != 0) {
      psVar7 = *(short **)(iVar4 + 0x50);
      psVar1 = psVar7 + 1;
      do {
        sVar2 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar2 != 0);
      if ((int)psVar7 - (int)psVar1 >> 1 == *(int *)(iVar4 + 0x5c)) {
        iVar5 = _TestDefaultCountry(param_1);
        if (iVar5 == 0) {
          psVar7 = *(short **)(iVar4 + 0x50);
          psVar1 = psVar7 + 1;
          do {
            sVar2 = *psVar7;
            psVar7 = psVar7 + 1;
          } while (sVar2 != 0);
          iVar5 = _GetPrimaryLen(*(undefined4 *)(iVar4 + 0x50));
          if (iVar5 == (int)psVar7 - (int)psVar1 >> 1) goto LAB_006eeb9d;
        }
        *(uint *)(iVar4 + 0x58) = *(uint *)(iVar4 + 0x58) | 0x100;
        if (*(short *)(iVar4 + 0x2a0) != 0) goto LAB_006eeb9d;
        do {
          sVar2 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar2 != 0);
        goto LAB_006eeb79;
      }
    }
    *(uint *)(iVar4 + 0x58) = uVar3 | 0x300;
    if (*(short *)(iVar4 + 0x2a0) != 0) goto LAB_006eeb9d;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
  }
  else {
    *(uint *)(iVar4 + 0x58) = uVar3 | 0x300;
    if (*(short *)(iVar4 + 0x2a0) != 0) goto LAB_006eeb9d;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
  }
LAB_006eeb79:
  iVar4 = FUN_006ed6af(iVar4 + 0x2a0,0x55,param_1,((int)psVar6 - (int)(param_1 + 1) >> 1) + 1);
  if (iVar4 != 0) {
LAB_006eebaf:
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
LAB_006eeb9d:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

