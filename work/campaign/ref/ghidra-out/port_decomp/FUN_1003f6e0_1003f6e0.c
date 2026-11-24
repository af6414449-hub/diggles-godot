
void FUN_1003f6e0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 local_18;
  int local_14 [3];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*(char *)(in_ECX + 0x3c) != '\0') {
    *(undefined4 *)(in_ECX + 0x70) = 2;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (*(int *)(in_ECX + 0x328) == 0) {
    if (*(int *)(in_ECX + 0x2c) == 0) {
      (**(code **)(**(int **)(in_ECX + 0x20) + 0x14))();
    }
    FUN_10038bd0();
    iVar1 = FUN_1003f210(local_14);
    if (iVar1 == 0) {
      *(undefined4 *)(in_ECX + 0x70) = 0x24;
      iVar3 = -1;
    }
    else {
      if (*(char *)(in_ECX + 0x3c) == '\0') {
        if (*(int *)(in_ECX + 0x2c) == 0) {
          iVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x14))();
          iVar1 = iVar1 - *(int *)(in_ECX + 0x24);
        }
        else {
          iVar1 = *(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x30);
        }
      }
      else {
        iVar1 = 0;
      }
      while (local_14[0] == 0) {
        FUN_10038bd0();
        iVar3 = FUN_1003f210(local_14);
        if (iVar3 == 0) break;
        if (*(char *)(in_ECX + 0x3c) == '\0') {
          if (*(int *)(in_ECX + 0x2c) == 0) {
            iVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x14))();
            iVar1 = iVar1 - *(int *)(in_ECX + 0x24);
          }
          else {
            iVar1 = *(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x30);
          }
        }
        else {
          iVar1 = 0;
        }
      }
      FUN_10038bd0();
      FUN_10038b20(6);
      iVar3 = FUN_10038ad0();
      iVar2 = FUN_10038ad0();
      if ((iVar3 == -1) && (iVar2 == -1)) {
        *(undefined4 *)(in_ECX + 0x70) = 0x24;
      }
      else {
        *(int *)(in_ECX + 0x50) = iVar1;
        if (iVar2 != 0) {
          iVar3 = -2;
        }
        *(undefined4 *)(in_ECX + 0x54) = local_18;
        *(int *)(in_ECX + 0x58) = iVar3;
      }
    }
    *(int *)(in_ECX + 0x328) = iVar3;
    FUN_10038bd0();
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

