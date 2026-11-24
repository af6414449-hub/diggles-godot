
void FUN_1003ba30(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  int *in_EDX;
  int local_14;
  undefined1 local_9;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar4 = *(int *)(in_ECX + 0x6c);
  *(undefined4 *)(in_ECX + 0x5f0) = 0;
  *(undefined4 *)(in_ECX + 0x5ec) = 0;
  while( true ) {
    if ((iVar4 != 0) || (iVar4 = FUN_10039070(), iVar4 == 0)) goto LAB_1003bb4b;
    iVar4 = FUN_100392f0();
    if (iVar4 == 0) break;
    if (*(char *)(in_ECX + 0x3c) != '\0') {
      *(undefined4 *)(in_ECX + 0x70) = 0x23;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    while ((*(char *)(in_ECX + 0x56c) != '\0' ||
           ((*(int *)(in_ECX + 0x574) == 0 && (iVar4 = FUN_10039100(), iVar4 != 0))))) {
      *(char *)(in_ECX + 0x56c) = *(char *)(in_ECX + 0x56c) + -1;
      *(int *)(in_ECX + 0x584) = *(int *)(in_ECX + 0x584) + 1;
      uVar2 = *(uint *)(in_ECX + 0x2c);
      if (uVar2 == 0) {
        piVar3 = *(int **)(in_ECX + 0x20);
        iVar4 = (**(code **)(*piVar3 + 4))();
        if (iVar4 != 0) goto LAB_1003bae7;
        local_9 = 0;
        (**(code **)(*piVar3 + 8))(&local_9,1);
        *(undefined4 *)(in_ECX + 0x580) = 0;
      }
      else if (uVar2 < *(uint *)(in_ECX + 0x34)) {
        *(undefined4 *)(in_ECX + 0x580) = 0;
        *(uint *)(in_ECX + 0x2c) = uVar2 + 1;
      }
      else {
LAB_1003bae7:
        *(undefined4 *)(in_ECX + 0x6c) = 1;
        *(undefined4 *)(in_ECX + 0x580) = 0;
      }
    }
    *(undefined4 *)(in_ECX + 0x580) = 0;
    iVar4 = *(int *)(in_ECX + 0x6c);
  }
  FUN_10038070();
  iVar4 = FUN_100392f0();
  if ((iVar4 != -1) && (iVar4 < *(int *)(in_ECX + 0x1a4))) {
    *param_4 = iVar4;
    iVar1 = in_ECX + iVar4 * 6;
    if (*(char *)(in_ECX + 0x1a8 + iVar4 * 6) == '\0') {
      iVar4 = *(int *)(in_ECX + 0x7c);
      local_14 = 0;
      iVar6 = iVar4 >> 1;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x80);
      iVar5 = FUN_100392f0();
      local_14 = FUN_100392f0();
      iVar6 = iVar4 >> 1;
      if ((*(char *)(iVar1 + 0x1a8) != '\0') && (iVar5 == 0)) {
        *in_EDX = iVar4 - *(int *)(in_ECX + 0x7c) >> 2;
        iVar5 = *(int *)(in_ECX + 0x7c) + iVar4 >> 2;
        goto LAB_1003bc15;
      }
    }
    *in_EDX = 0;
    iVar5 = iVar6;
LAB_1003bc15:
    *param_1 = iVar5;
    if ((*(char *)(iVar1 + 0x1a8) != '\0') && (local_14 == 0)) {
      *param_2 = iVar4 * 3 - *(int *)(in_ECX + 0x7c) >> 2;
      *param_3 = *(int *)(in_ECX + 0x7c) + iVar4 * 3 >> 2;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    *param_2 = iVar6;
    *param_3 = iVar4;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_1003bb4b:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

