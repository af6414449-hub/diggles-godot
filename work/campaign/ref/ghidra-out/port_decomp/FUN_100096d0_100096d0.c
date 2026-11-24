
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100096d0(void)

{
  int *piVar1;
  int *piVar2;
  undefined3 uVar3;
  void *_Dst;
  int iVar4;
  undefined2 *in_ECX;
  undefined4 in_EDX;
  undefined1 local_98 [4];
  undefined *local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_7c;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined8 local_2c;
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_10041cb7;
  local_1c = ExceptionList;
  local_24 = DAT_1005000c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,local_24);
  *in_ECX = 0x101;
  *(undefined1 *)(in_ECX + 1) = 6;
  *(undefined4 *)(in_ECX + 2) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 6) = 0;
  *(undefined4 *)(in_ECX + 8) = 0x40;
  *(undefined4 *)(in_ECX + 10) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0x100;
  *(undefined4 *)(in_ECX + 0xe) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x12) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x16) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1a) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x1e) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x2e) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x32) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x36) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3a) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x3e) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x42) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x46) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4a) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x4e) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x52) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  local_14._1_3_ = 0;
  uVar3 = local_14._1_3_;
  local_14._0_1_ = 0x19;
  local_14._1_3_ = 0;
  if (DAT_10050c64 == (int *)0x0) {
    _Dst = (void *)FUN_1003ff62(0xcbc);
    local_14._0_1_ = 0x1a;
    memset(_Dst,0,0xcbc);
    DAT_10050c64 = (int *)FUN_1000e160();
    uVar3 = local_14._1_3_;
  }
  local_14._1_3_ = uVar3;
  local_14._0_1_ = 0x19;
  piVar1 = *(int **)(in_ECX + 0x54);
  local_2c = 0;
  local_3c = 0x10;
  piVar2 = *(int **)(*DAT_10050c64 + 4);
  local_38 = 0;
  local_34 = 4;
  local_30 = 0;
  if (piVar1 != (int *)0x0) {
    *(int *)(in_ECX + 0x54) = 0;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  iVar4 = (**(code **)(*piVar2 + 0xc))(piVar2,&local_3c,0,in_ECX + 0x54);
  if (-1 < iVar4) {
    piVar1 = *(int **)(in_ECX + 0x50);
    local_50 = 0;
    local_54 = 0x50;
    local_4c = 1;
    local_48 = 0;
    local_44 = 0;
    local_94 = &DAT_10044d30;
    local_90 = 0;
    local_8c = 0;
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(in_ECX + 0x50) = 0;
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    iVar4 = (**(code **)(*piVar2 + 0xc))(piVar2,&local_54,&local_94,in_ECX + 0x50);
    if (-1 < iVar4) {
      piVar1 = *(int **)(in_ECX + 0x52);
      local_50 = 0;
      local_54 = 0x70;
      local_4c = 1;
      local_48 = 0;
      local_44 = 0;
      local_94 = &DAT_10044cc0;
      local_90 = 0;
      local_8c = 0;
      if (piVar1 != (int *)0x0) {
        *(undefined4 *)(in_ECX + 0x52) = 0;
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      iVar4 = (**(code **)(*piVar2 + 0xc))(piVar2,&local_54,&local_94,in_ECX + 0x52);
      if (-1 < iVar4) {
        piVar1 = *(int **)(in_ECX + 0x4e);
        local_50 = 0;
        local_54 = 0xc;
        local_4c = 2;
        local_48 = 0;
        local_44 = 0;
        local_94 = &DAT_10044d80;
        local_90 = 0;
        local_8c = 0;
        if (piVar1 != (int *)0x0) {
          *(undefined4 *)(in_ECX + 0x4e) = 0;
          (**(code **)(*piVar1 + 8))(piVar1);
        }
        iVar4 = (**(code **)(*piVar2 + 0xc))(piVar2,&local_54,&local_94,in_ECX + 0x4e);
        if (-1 < iVar4) {
          FUN_10009b60();
          piVar1 = *(int **)(in_ECX + 0x2e);
          if (piVar1 != (int *)0x0) {
            *(undefined4 *)(in_ECX + 0x2e) = 0;
            (**(code **)(*piVar1 + 8))(piVar1);
          }
          iVar4 = (**(code **)(*piVar2 + 0x5c))(piVar2,&DAT_10044d8c,in_ECX + 0x2e);
          if (-1 < iVar4) {
            _DAT_1416e858 = 0;
            DAT_1416e874 = 0xf;
            piVar1 = *(int **)(in_ECX + 0x18);
            if (piVar1 != (int *)0x0) {
              *(undefined4 *)(in_ECX + 0x18) = 0;
              (**(code **)(*piVar1 + 8))(piVar1);
            }
            iVar4 = (**(code **)(*piVar2 + 0x50))(piVar2,&DAT_1416e850,in_ECX + 0x18);
            if (-1 < iVar4) {
              _DAT_1416e820 = 3;
              _DAT_1416e824 = 1;
              iVar4 = (**(code **)(*piVar2 + 0x58))(piVar2,&DAT_1416e820,in_ECX + 0x1a);
              if (-1 < iVar4) {
                local_88 = 0;
                local_84 = 0;
                local_7c = 0;
                iVar4 = (**(code **)(*piVar2 + 0x54))(piVar2,&local_88,in_ECX + 0x16);
                if (-1 < iVar4) {
                  ExceptionList = local_1c;
                  __security_check_cookie(local_24 ^ (uint)&stack0xfffffff0);
                  return;
                }
              }
            }
          }
        }
      }
    }
    FUN_100053a0(iVar4);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_34,(ThrowInfo *)&DAT_1004a24c);
  }
  FUN_100053a0(iVar4);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_98,(ThrowInfo *)&DAT_1004a24c);
}

