
/* Library Function - Single Match
    ___acrt_DownlevelLocaleNameToLCID
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_DownlevelLocaleNameToLCID(wchar_t *param_1)

{
  uint uVar1;
  
  if (param_1 != (wchar_t *)0x0) {
    uVar1 = GetTableIndexFromLocaleName(param_1);
    if ((-1 < (int)uVar1) && (uVar1 < 0xe4)) {
      return *(undefined4 *)(&DAT_00719cc8 + uVar1 * 8);
    }
  }
  return 0;
}

