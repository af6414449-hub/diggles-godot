
/* public: void __thiscall ScreenResolutionManager::ShowAllMonitorsInfo(void) */

void __thiscall ScreenResolutionManager::ShowAllMonitorsInfo(ScreenResolutionManager *this)

{
  undefined4 *puVar1;
  int *piVar2;
  void *_Dst;
  int iVar3;
  int iVar4;
  undefined4 in_EDX;
  int iVar5;
  int *local_1a4;
  int *local_1a0;
  undefined1 local_19c [296];
  undefined1 local_74 [64];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
                    /* 0x13160  256  ?ShowAllMonitorsInfo@ScreenResolutionManager@@QAEXXZ */
  local_8 = 0xffffffff;
  puStack_c = &LAB_100426ca;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 == (undefined4 *)0x0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = (undefined4 *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  puVar1 = (undefined4 *)*DAT_10050c64;
  iVar5 = 0;
  local_1a0 = (int *)0x0;
  piVar2 = (int *)*puVar1;
  local_1a4 = (int *)0x0;
  iVar3 = (**(code **)(*piVar2 + 0x30))(piVar2,0,&local_1a0);
  while (iVar3 != -0x7785fffe) {
    (**(code **)(*local_1a0 + 0x28))(local_1a0,local_19c);
    FUN_100028b0(&DAT_1416e310,0x100,"Enumerated adapter %d : %ls \n",iVar5,local_19c);
    OutputDebugStringA(&DAT_1416e310);
    iVar3 = 0;
    iVar4 = (**(code **)(*local_1a0 + 0x1c))(local_1a0,0,&local_1a4);
    while (iVar4 != -0x7785fffe) {
      (**(code **)(*local_1a4 + 0x1c))(local_1a4,local_74);
      FUN_100028b0(&DAT_1416e310,0x100,"Output coords : %d-%d, %d-%d \n",local_34,local_2c,local_30,
                   local_28);
      OutputDebugStringA(&DAT_1416e310);
      iVar3 = iVar3 + 1;
      iVar4 = (**(code **)(*local_1a0 + 0x1c))(local_1a0,iVar3,&local_1a4);
    }
    iVar5 = iVar5 + 1;
    piVar2 = (int *)*puVar1;
    iVar3 = (**(code **)(*piVar2 + 0x30))(piVar2,iVar5,&local_1a0);
  }
  if (local_1a0 != (int *)0x0) {
    (**(code **)(*local_1a0 + 8))(local_1a0);
    local_1a0 = (int *)0x0;
  }
  if (local_1a4 != (int *)0x0) {
    (**(code **)(*local_1a4 + 8))(local_1a4);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

