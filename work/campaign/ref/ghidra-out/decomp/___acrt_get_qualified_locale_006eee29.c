
/* Library Function - Single Match
    ___acrt_get_qualified_locale
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_get_qualified_locale(short *param_1,uint *param_2,int param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  short *psVar3;
  undefined2 *puVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  uint _Val;
  BOOL BVar8;
  short *psVar9;
  
  iVar6 = ___acrt_getptd();
  puVar1 = (undefined4 *)(iVar6 + 0x50);
  psVar3 = (short *)(iVar6 + 0x2a0);
  *(undefined4 *)(iVar6 + 0x58) = 0;
  *psVar3 = 0;
  piVar2 = (int *)(iVar6 + 0x54);
  *puVar1 = param_1;
  *piVar2 = (int)(param_1 + 0x40);
  psVar9 = param_1;
  if (param_1[0x40] != 0) {
    _TranslateName(&PTR_u_america_00719150,0x16,piVar2);
    psVar9 = (short *)*puVar1;
  }
  if (*psVar9 == 0) {
    _GetLocaleNameFromDefault(puVar1);
  }
  else {
    if (*(short *)*piVar2 == 0) {
      _GetLocaleNameFromLanguage();
    }
    else {
      _GetLocaleNameFromLangCountry();
    }
    if ((*(int *)(iVar6 + 0x58) == 0) &&
       (iVar7 = _TranslateName(&PTR_u_american_00718e40,0x40,puVar1), iVar7 != 0)) {
      if (*(short *)*piVar2 == 0) {
        _GetLocaleNameFromLanguage(puVar1);
      }
      else {
        _GetLocaleNameFromLangCountry();
      }
    }
  }
  if (*(int *)(iVar6 + 0x58) != 0) {
    if ((*param_1 == 0) && (param_1[0x80] == 0)) {
      _Val = GetACP();
    }
    else {
      _Val = _ProcessCodePage(param_1 + 0x80,puVar1);
    }
    if (((_Val != 0) && (_Val != 65000)) && (BVar8 = IsValidCodePage(_Val & 0xffff), BVar8 != 0)) {
      if (param_2 != (uint *)0x0) {
        *param_2 = _Val;
      }
      if (param_3 == 0) {
        return 1;
      }
      puVar4 = (undefined2 *)(param_3 + 0x120);
      *puVar4 = 0;
      psVar9 = psVar3;
      do {
        sVar5 = *psVar9;
        psVar9 = psVar9 + 1;
      } while (sVar5 != 0);
      iVar6 = FUN_006ed6af(puVar4,0x55,psVar3,((int)psVar9 - (iVar6 + 0x2a2) >> 1) + 1);
      if (iVar6 != 0) {
LAB_006ef017:
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      iVar6 = ___acrt_GetLocaleInfoEx_16(puVar4,0x1001,param_3,0x40);
      if (iVar6 != 0) {
        iVar6 = param_3 + 0x80;
        iVar7 = ___acrt_GetLocaleInfoEx_16(param_3 + 0x120,0x1002,iVar6,0x40);
        if ((iVar7 != 0) &&
           (((iVar7 = FUN_006f4dc5(iVar6,0x5f), iVar7 == 0 &&
             (iVar7 = FUN_006f4dc5(iVar6,0x2e), iVar7 == 0)) ||
            (iVar6 = ___acrt_GetLocaleInfoEx_16(param_3 + 0x120,7,iVar6,0x40), iVar6 != 0)))) {
          if (_Val != 0xfde9) {
            __itow_s(_Val,(wchar_t *)(param_3 + 0x100),0x10,10);
            return 1;
          }
          iVar6 = FUN_006ed6af((wchar_t *)(param_3 + 0x100),0x10,L"utf8",5);
          if (iVar6 == 0) {
            return 1;
          }
          goto LAB_006ef017;
        }
      }
    }
  }
  return 0;
}

