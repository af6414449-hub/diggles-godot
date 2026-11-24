
void FUN_10017750(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 in_EDX;
  int *piVar3;
  undefined1 local_4c [16];
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  undefined1 local_2c [8];
  undefined4 local_24;
  undefined4 local_1c;
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100429ef;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  local_34 = DAT_10050c64;
  if (DAT_10050c64 == (int *)0x0) {
    local_18 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(local_18,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar3 = DAT_10050c64;
  local_34 = DAT_10050c64;
  FUN_1000f260();
  FUN_1000f890();
  FUN_1000f550();
  piVar3[800] = 0;
  iVar2 = (**(code **)(*param_2 + 0x1c))(local_2c);
  if (-1 < iVar2) {
    iVar2 = (**(code **)(*param_2 + 0x20))(&local_30);
    if (-1 < iVar2) {
      local_38 = local_30;
      if (local_30 != (int *)0x0) {
        (**(code **)(*local_30 + 4))(local_30);
      }
      local_8 = 1;
      local_3c = *(int **)(*piVar3 + 8);
      FUN_1000c480(local_24);
      piVar1 = *(int **)(*piVar3 + 8);
      (**(code **)(*piVar1 + 0x1c))(piVar1,0,1,piVar3 + 3);
      (**(code **)(*piVar1 + 0x40))(piVar1,0,1,piVar3 + 3);
      piVar3 = local_34 + 4;
      (**(code **)(*piVar1 + 0x1c))(piVar1,2,1,piVar3);
      (**(code **)(*piVar1 + 0x40))(piVar1,2,1,piVar3);
      local_18 = (void *)FUN_10009340();
      piVar3 = local_3c;
      local_1c = param_3;
      (**(code **)(*local_3c + 0x48))(local_3c,0,1,&local_38,&local_18,&local_1c);
      (**(code **)(*piVar3 + 0x60))(piVar3,param_1);
      (**(code **)(*piVar3 + 0x34))(piVar3,param_4,0);
      piVar3 = local_38;
      local_8 = 0xffffffff;
      *(undefined1 *)((int)local_34 + 0xcb9) = 0;
      if (local_38 != (int *)0x0) {
        local_38 = (int *)0x0;
        (**(code **)(*piVar3 + 8))(piVar3);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  FUN_100053a0(iVar2);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_4c,(ThrowInfo *)&DAT_1004a24c);
}

