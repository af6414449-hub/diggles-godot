
void FUN_1000b330(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 ****ppppuVar5;
  undefined4 in_EDX;
  uint uVar6;
  int iVar7;
  undefined1 local_58 [16];
  void *local_48;
  undefined4 ***local_44 [4];
  int local_34;
  uint local_30;
  undefined2 local_2c;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_10041f57;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 == (int *)0x0) {
    local_48 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(local_48,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar1 = *(int **)(*DAT_10050c64 + 4);
  FUN_1000b760(&DAT_10050ec8);
  local_8 = 1;
  if (local_30 < 0x10) {
    iVar7 = (int)local_44 + local_34;
    ppppuVar5 = local_44;
    if (local_30 < 0x10) goto LAB_1000b3e8;
  }
  else {
    iVar7 = local_34 + (int)local_44[0];
  }
  ppppuVar5 = (undefined4 ****)local_44[0];
LAB_1000b3e8:
  local_1c = 0;
  local_2c = 0;
  local_18 = 7;
  FUN_1000b8c0(iVar7 - (int)ppppuVar5);
  local_48 = (void *)((uint)local_48 & 0xffffff00);
  FUN_1000ba20(ppppuVar5,iVar7,local_48);
  piVar2 = DAT_10050f18;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (DAT_10050f18 != (int *)0x0) {
    DAT_10050f18 = (int *)0x0;
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  iVar7 = FUN_1000afd0("cs_5_0",&DAT_10050f18);
  piVar3 = DAT_10050f24;
  piVar2 = DAT_10050f18;
  if (-1 < iVar7) {
    if (DAT_10050f24 != (int *)0x0) {
      DAT_10050f24 = (int *)0x0;
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    iVar7 = *piVar1;
    uVar4 = (**(code **)(*piVar2 + 0x10))(piVar2,0,&DAT_10050f24);
    uVar4 = (**(code **)(*piVar2 + 0xc))(piVar2,uVar4);
    iVar7 = (**(code **)(iVar7 + 0x48))(piVar1,uVar4);
    if (-1 < iVar7) {
      FUN_1000b6b0();
      if (0xf < local_30) {
        uVar6 = local_30 + 1;
        ppppuVar5 = (undefined4 ****)local_44[0];
        if (0xfff < uVar6) {
          ppppuVar5 = (undefined4 ****)local_44[0][-1];
          uVar6 = local_30 + 0x24;
          if (0x1f < (uint)((int)local_44[0] + (-4 - (int)ppppuVar5))) {
                    /* WARNING: Subroutine does not return */
            _invalid_parameter_noinfo_noreturn();
          }
        }
        FUN_100402ac(ppppuVar5,uVar6);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  FUN_100053a0(iVar7);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_58,(ThrowInfo *)&DAT_1004a24c);
}

