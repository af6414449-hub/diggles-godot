
void FUN_1000ff90(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *in_ECX;
  bool bVar3;
  undefined4 uVar4;
  undefined1 local_14 [16];
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  puVar1 = (undefined4 *)*in_ECX;
  bVar3 = (*(byte *)(puVar1 + 0x20) & 2) == 0;
  if (bVar3) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x200;
  }
  iVar2 = (**(code **)(*(int *)puVar1[3] + 0x20))((int *)puVar1[3],bVar3,uVar4);
  if (*(char *)((int)puVar1 + 0xc5) == '\0') {
    uVar4 = puVar1[7];
  }
  else {
    uVar4 = puVar1[0x10];
  }
  (**(code **)(*(int *)puVar1[2] + 0x1d8))((int *)puVar1[2],uVar4);
  if (puVar1[8] != 0) {
    (**(code **)(*(int *)puVar1[2] + 0x1d8))((int *)puVar1[2],puVar1[8]);
  }
  if ((iVar2 == -0x7785fffb) || (iVar2 == -0x7785fff9)) {
    FUN_10006740();
  }
  else {
    if (iVar2 < 0) {
      FUN_100053a0(iVar2);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_14,(ThrowInfo *)&DAT_1004a24c);
    }
    iVar2 = (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1);
    if (iVar2 == 0) {
      FUN_100068a0();
      *(undefined1 *)(in_ECX + 0x32e) = 0;
      return;
    }
  }
  *(undefined1 *)(in_ECX + 0x32e) = 0;
  return;
}

