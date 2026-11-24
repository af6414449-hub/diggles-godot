
void FUN_100168f0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 in_EDX;
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  void *local_20;
  int *local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100428b7;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  if (DAT_10050c64 == 0) {
    local_20 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(local_20,0,0xcbc);
    DAT_10050c64 = FUN_1000e160();
    local_8 = 0xffffffff;
  }
  iVar1 = DAT_10050c64;
  if (param_2 == (int *)0x0) {
    iVar1 = DAT_10050c64 + param_1 * 4;
    *(undefined4 *)(DAT_10050c64 + 0xc84 + param_1 * 4) = 0;
    piVar4 = *(int **)(iVar1 + 0x814);
    if (piVar4 == (int *)0x0) goto LAB_10016a41;
    *(undefined4 *)(iVar1 + 0x814) = 0;
  }
  else {
    local_18 = (int *)0x0;
    local_1c = (int *)0x0;
    iVar2 = (**(code **)(*param_2 + 0x54))(&local_18);
    if (iVar2 < 0) {
      FUN_100053a0(iVar2);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_30,(ThrowInfo *)&DAT_1004a24c);
    }
    iVar2 = (**(code **)(*param_2 + 0x58))(&local_1c);
    piVar4 = local_18;
    if (iVar2 < 0) {
      FUN_100053a0(iVar2);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_40,(ThrowInfo *)&DAT_1004a24c);
    }
    *(uint *)(iVar1 + 0xc84 + param_1 * 4) = (uint)(local_18 != (int *)0x0);
    piVar3 = *(int **)(iVar1 + 0x814 + param_1 * 4);
    if (piVar3 != local_18) {
      if (local_18 != (int *)0x0) {
        (**(code **)(*local_18 + 4))(local_18);
        piVar3 = *(int **)(iVar1 + 0x814 + param_1 * 4);
      }
      *(int **)(iVar1 + 0x814 + param_1 * 4) = piVar4;
      if (piVar3 != (int *)0x0) {
        (**(code **)(*piVar3 + 8))(piVar3);
      }
    }
    piVar3 = local_1c;
    piVar4 = *(int **)(iVar1 + 0x834 + param_1 * 4);
    iVar1 = iVar1 + param_1 * 4;
    if (piVar4 == local_1c) goto LAB_10016a41;
    if (local_1c != (int *)0x0) {
      (**(code **)(*local_1c + 4))(local_1c);
      piVar4 = *(int **)(iVar1 + 0x834);
    }
    *(int **)(iVar1 + 0x834) = piVar3;
    if (piVar4 == (int *)0x0) goto LAB_10016a41;
  }
  (**(code **)(*piVar4 + 8))(piVar4);
LAB_10016a41:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

