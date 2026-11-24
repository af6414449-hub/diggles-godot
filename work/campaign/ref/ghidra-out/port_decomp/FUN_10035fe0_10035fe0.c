
undefined4 FUN_10035fe0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  if (param_3 == 0) {
    iVar2 = FUN_10035ae0(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) >> 0x1f);
    if ((iVar2 == 0) || (iVar2 = FUN_10035be0(), iVar2 == 0)) {
      return 0;
    }
    __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  }
  if (0 < param_2) {
    iVar2 = 0;
    while( true ) {
      uVar1 = *(uint *)(param_1 + 0x268);
      if ((uint)(param_2 - iVar2) <= uVar1) break;
      if (uVar1 != 0) {
        iVar2 = iVar2 + uVar1;
        *(undefined4 *)(param_1 + 0x268) = 0;
      }
      iVar3 = FUN_10035be0();
      if (iVar3 == 0) {
        return 0;
      }
      if (param_2 <= iVar2) {
        return 1;
      }
    }
    *(uint *)(param_1 + 0x268) = uVar1 - (param_2 - iVar2);
  }
  return 1;
}

