
void FUN_10017560(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 in_EDX;
  int *piVar5;
  undefined1 local_54 [16];
  int *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int *local_38;
  void *local_34;
  void *local_30;
  undefined1 local_2c [8];
  undefined4 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_100429a7;
  local_10 = ExceptionList;
  local_14 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_40 = param_5;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_14);
  local_38 = DAT_10050c64;
  if (DAT_10050c64 == (int *)0x0) {
    local_30 = (void *)FUN_1003ff62(0xcbc);
    local_8 = 0;
    memset(local_30,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    local_8 = 0xffffffff;
  }
  piVar5 = DAT_10050c64;
  local_38 = DAT_10050c64;
  FUN_1000f260();
  FUN_1000f890();
  FUN_1000f550();
  piVar5[800] = 0;
  iVar4 = (**(code **)(*param_2 + 0x1c))(local_2c);
  if (-1 < iVar4) {
    iVar4 = (**(code **)(*param_2 + 0x20))(&local_34);
    if (-1 < iVar4) {
      local_30 = local_34;
      local_44 = *(int **)(*piVar5 + 8);
      FUN_1000c480(local_24);
      piVar1 = *(int **)(*piVar5 + 8);
      (**(code **)(*piVar1 + 0x1c))(piVar1,0,1,piVar5 + 3);
      (**(code **)(*piVar1 + 0x40))(piVar1,0,1,piVar5 + 3);
      piVar5 = local_38 + 4;
      (**(code **)(*piVar1 + 0x1c))(piVar1,2,1,piVar5);
      (**(code **)(*piVar1 + 0x40))(piVar1,2,1,piVar5);
      local_1c = FUN_10009340();
      local_18 = param_3;
      local_3c = 0;
      uVar2 = *(undefined4 *)(*local_38 + 4);
      uVar3 = *(undefined4 *)(*local_38 + 8);
      FUN_10010da0();
      FUN_100109d0(param_6,local_40,uVar2,uVar3,&local_3c);
      piVar5 = local_44;
      (**(code **)(*local_44 + 0x48))(local_44,0,1,&local_30,&local_1c,&local_18);
      (**(code **)(*piVar5 + 0x4c))(piVar5,local_3c,0x39,0);
      (**(code **)(*piVar5 + 0x60))(piVar5,param_1);
      (**(code **)(*piVar5 + 0x30))(piVar5,param_6,0,0);
      FUN_10010da0();
      FUN_10010c60(param_6,&local_3c);
      *(undefined1 *)((int)local_38 + 0xcb9) = 0;
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  FUN_100053a0(iVar4);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_54,(ThrowInfo *)&DAT_1004a24c);
}

