
/* Library Function - Single Match
    ___acrt_DownlevelLCIDToLocaleName
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int ___acrt_DownlevelLCIDToLocaleName(int param_1,wchar_t *param_2,rsize_t param_3)

{
  wchar_t *_Src;
  int iVar1;
  errno_t eVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_1 != 0) && (param_1 != 0x400)) && (param_1 != 0x800)) &&
     (((param_2 != (wchar_t *)0x0 || ((int)param_3 < 1)) && (-1 < (int)param_3)))) {
    iVar4 = 0;
    iVar3 = 0xe3;
    do {
      iVar1 = (iVar3 + iVar4) / 2;
      if (param_1 == *(int *)(&DAT_00719cc8 + iVar1 * 8)) goto LAB_006f1392;
      if (param_1 - *(int *)(&DAT_00719cc8 + iVar1 * 8) < 0) {
        iVar3 = iVar1 + -1;
      }
      else {
        iVar4 = iVar1 + 1;
      }
    } while (iVar4 <= iVar3);
    iVar1 = -1;
LAB_006f1392:
    if (-1 < iVar1) {
      _Src = *(wchar_t **)(&UNK_00719ccc + iVar1 * 8);
      iVar3 = FUN_006e5dfa(_Src,0x55);
      if (0 < (int)param_3) {
        if ((int)param_3 <= iVar3) {
          return 0;
        }
        eVar2 = _wcscpy_s(param_2,param_3,_Src);
        if (eVar2 != 0) {
                    /* WARNING: Subroutine does not return */
          __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
      }
      return iVar3 + 1;
    }
  }
  return 0;
}

