
void FUN_10010c60(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 local_14 [16];
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  uVar4 = 0;
  iVar1 = *(int *)(in_ECX + 8);
  while (iVar1 < param_1) {
    uVar4 = uVar4 + 1;
    iVar1 = *(int *)(in_ECX + 8) << ((byte)uVar4 & 0x1f);
  }
  if ((uint)(*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc) >> 2) < uVar4) {
    FUN_100053a0(0x80004005);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_14,(ThrowInfo *)&DAT_1004a24c);
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xc) + uVar4 * 4);
  iVar5 = *(int *)(iVar1 + 0x10);
  uVar4 = *(uint *)(iVar1 + 0xc);
  if (((uVar4 + iVar5 & 3) == 0) && (*(uint *)(iVar1 + 8) <= iVar5 + 4U >> 2)) {
    FUN_10011270(iVar5);
    uVar4 = *(uint *)(iVar1 + 0xc);
    iVar5 = *(int *)(iVar1 + 0x10);
  }
  uVar4 = *(int *)(iVar1 + 8) * 4 - 1U & uVar4;
  uVar6 = iVar5 + uVar4;
  *(uint *)(iVar1 + 0xc) = uVar4;
  iVar3 = *(int *)(iVar1 + 4);
  iVar5 = (*(int *)(iVar1 + 8) - 1U & uVar6 >> 2) * 4;
  if (*(int *)(iVar5 + iVar3) == 0) {
    uVar2 = FUN_1003ff62(0x10);
    *(undefined4 *)(iVar5 + *(int *)(iVar1 + 4)) = uVar2;
    iVar3 = *(int *)(iVar1 + 4);
  }
  *(undefined4 *)(*(int *)(iVar5 + iVar3) + (uVar6 & 3) * 4) = *param_2;
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + 1;
  return;
}

