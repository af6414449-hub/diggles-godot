
void FUN_100108b0(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 *in_ECX;
  undefined4 in_EDX;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10042400;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  __CheckForDebuggerJustMyCode(&DAT_14170d01,in_EDX,DAT_1005000c ^ (uint)&stack0xfffffffc);
  piVar1 = in_ECX + 3;
  *in_ECX = CommonBufferPool::vftable;
  iVar5 = *piVar1;
  local_14 = 0;
  if (in_ECX[4] - iVar5 >> 2 != 0) {
    do {
      iVar6 = *(int *)(*(int *)(iVar5 + local_14 * 4) + 0x10);
      while (iVar6 != 0) {
        iVar5 = *(int *)(iVar5 + local_14 * 4);
        uVar3 = *(uint *)(iVar5 + 0xc);
        piVar4 = *(int **)(*(int *)(*(int *)(iVar5 + 4) +
                                   (uVar3 >> 2 & *(int *)(iVar5 + 8) - 1U) * 4) + (uVar3 & 3) * 4);
        piVar2 = (int *)(iVar5 + 0x10);
        *piVar2 = *piVar2 + -1;
        if (*piVar2 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = uVar3 + 1;
        }
        *(int *)(iVar5 + 0xc) = iVar6;
        (**(code **)(*piVar4 + 8))(piVar4);
        iVar5 = *piVar1;
        iVar6 = *(int *)(*(int *)(iVar5 + local_14 * 4) + 0x10);
      }
      iVar5 = *(int *)(iVar5 + local_14 * 4);
      if (iVar5 != 0) {
        FUN_10010f40();
        FUN_100402ac(iVar5,0x14);
      }
      free(*(void **)(in_ECX[6] + local_14 * 4));
      local_14 = local_14 + 1;
      iVar5 = *piVar1;
    } while (local_14 < (uint)(in_ECX[4] - iVar5 >> 2));
  }
  FUN_10007af0();
  FUN_10007af0();
  ExceptionList = local_10;
  return;
}

