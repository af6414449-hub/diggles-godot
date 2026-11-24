
uint FUN_10013a60(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b8b);
  uVar1 = *(uint *)(param_2 + 0x10);
  uVar2 = *(uint *)(param_1 + 0x10);
  uVar3 = uVar2;
  if (uVar1 < uVar2) {
    uVar3 = uVar1;
  }
  uVar3 = FUN_10003ee0(uVar3);
  if (uVar3 == 0) {
    if (uVar2 < uVar1) {
      return 1;
    }
    uVar3 = 0;
  }
  return uVar3 >> 0x1f;
}

