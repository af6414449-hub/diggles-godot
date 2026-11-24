
/* Library Function - Single Match
    ___vcrt_getptd_noexit
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int ___vcrt_getptd_noexit(void)

{
  DWORD dwErrCode;
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_00767020 == -1) {
    return 0;
  }
  dwErrCode = GetLastError();
  iVar1 = ___vcrt_FlsGetValue(DAT_00767020);
  if (iVar1 == -1) {
LAB_006d0760:
    iVar1 = 0;
    goto LAB_006d07a6;
  }
  if (iVar1 != 0) goto LAB_006d07a6;
  iVar1 = ___vcrt_FlsSetValue(DAT_00767020,0xffffffff);
  if (iVar1 == 0) goto LAB_006d0760;
  iVar2 = FUN_006e4f1c(1,0x28);
  if (iVar2 == 0) {
LAB_006d0788:
    ___vcrt_FlsSetValue(DAT_00767020,0);
    iVar1 = 0;
    iVar3 = iVar2;
  }
  else {
    iVar1 = ___vcrt_FlsSetValue(DAT_00767020,iVar2);
    if (iVar1 == 0) goto LAB_006d0788;
    iVar3 = 0;
    iVar1 = iVar2;
  }
  FUN_006df631(iVar3);
LAB_006d07a6:
  SetLastError(dwErrCode);
  return iVar1;
}

