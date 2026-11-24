
/* Library Function - Single Match
    ___acrt_get_qualified_locale_downlevel
   
   Library: Visual Studio 2019 Release */

void ___acrt_get_qualified_locale_downlevel(int param_1,uint *param_2,LPWSTR param_3)

{
  int *piVar1;
  short *psVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint _Val;
  BOOL BVar7;
  int local_14;
  LCID local_10;
  LCID local_c;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  iVar4 = ___acrt_getptd();
  piVar5 = (int *)(iVar4 + 0x50);
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  iVar6 = ___acrt_getptd();
  *(int **)(iVar6 + 0x34c) = &local_14;
  psVar2 = (short *)(param_1 + 0x80);
  *piVar5 = param_1;
  piVar1 = (int *)(iVar4 + 0x54);
  *piVar1 = (int)psVar2;
  if ((psVar2 != (short *)0x0) && (*psVar2 != 0)) {
    _TranslateName(&PTR_u_america_00719150,0x16,piVar1);
  }
  local_14 = 0;
  if (((short *)*piVar5 == (short *)0x0) || (*(short *)*piVar5 == 0)) {
    if (((short *)*piVar1 == (short *)0x0) || (*(short *)*piVar1 == 0)) {
      local_14 = 0x104;
      local_10 = GetUserDefaultLCID();
      local_c = local_10;
    }
    else {
      _GetLcidFromCountry(&local_14);
    }
LAB_006ef8a4:
    if (local_14 == 0) goto LAB_006ef8ac;
  }
  else {
    if (((short *)*piVar1 == (short *)0x0) || (*(short *)*piVar1 == 0)) {
      _GetLcidFromLanguage(&local_14);
    }
    else {
      _GetLcidFromLangCountry(&local_14);
    }
    if (local_14 == 0) {
      cVar3 = _TranslateName(&PTR_u_american_00718e40,0x40,piVar5);
      if (cVar3 != '\0') {
        if (((short *)*piVar1 == (short *)0x0) || (*(short *)*piVar1 == 0)) {
          _GetLcidFromLanguage(&local_14);
        }
        else {
          _GetLcidFromLangCountry(&local_14);
        }
      }
      goto LAB_006ef8a4;
    }
  }
  _Val = _ProcessCodePage(-(uint)(param_1 != 0) & param_1 + 0x100U,&local_14);
  if (((_Val != 0) && (BVar7 = IsValidCodePage(_Val & 0xffff), BVar7 != 0)) &&
     (BVar7 = IsValidLocale(local_10,1), BVar7 != 0)) {
    if (param_2 != (uint *)0x0) {
      *param_2 = _Val;
    }
    ___acrt_LCIDToLocaleName_16(local_10,iVar4 + 0x2a0,0x55,0);
    if (param_3 != (LPWSTR)0x0) {
      ___acrt_LCIDToLocaleName_16(local_10,param_3 + 0x90,0x55,0);
      iVar4 = GetLocaleInfoW(local_10,0x1001,param_3,0x40);
      if ((iVar4 != 0) && (iVar4 = GetLocaleInfoW(local_c,0x1002,param_3 + 0x40,0x40), iVar4 != 0))
      {
        __itow_s(_Val,param_3 + 0x80,0x10,10);
      }
    }
  }
LAB_006ef8ac:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

