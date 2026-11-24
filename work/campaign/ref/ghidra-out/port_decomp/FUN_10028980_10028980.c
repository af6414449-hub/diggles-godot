
undefined4 FUN_10028980(uint param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  code *in_ECX;
  uint uVar4;
  bool bVar5;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if ((param_2 == 0) && (param_1 < 0x80000000)) {
    uVar1 = (*in_ECX)();
    return uVar1;
  }
  iVar2 = (*in_ECX)();
  if (iVar2 != 0) {
    uVar4 = param_1 + 0x80000001;
    iVar2 = param_2 + -1 + (uint)(0x7ffffffe < param_1);
    while( true ) {
      if ((iVar2 == 0) && (uVar4 < 0x80000000)) {
        uVar1 = (*in_ECX)();
        return uVar1;
      }
      iVar3 = (*in_ECX)();
      if (iVar3 == 0) break;
      bVar5 = 0x7ffffffe < uVar4;
      uVar4 = uVar4 + 0x80000001;
      iVar2 = iVar2 + -1 + (uint)bVar5;
    }
  }
  return 0;
}

