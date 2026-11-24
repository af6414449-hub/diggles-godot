
undefined4 FUN_1002b7b0(int param_1,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int in_ECX;
  int in_EDX;
  ulonglong uVar3;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (((in_ECX != 0) && (param_1 != 0 || param_2 != 0)) && (in_EDX != 0)) {
    uVar3 = __allmul(*(undefined2 *)(in_ECX + 0x50),0,param_1,param_2);
    if ((uVar3 & 0x7fffffff00000000) != 0 || (int)uVar3 < 0) {
      param_1 = (int)(0x7fffffff / (ulonglong)*(ushort *)(in_ECX + 0x50));
      param_2 = 0;
    }
    sVar1 = *(short *)(in_ECX + 0x54);
    if (sVar1 == 1) {
      uVar2 = FUN_1002ae10(param_1,param_2);
      return uVar2;
    }
    if (sVar1 == 3) {
      uVar2 = FUN_1002b080(param_1,param_2);
      return uVar2;
    }
    if (sVar1 == 6) {
      uVar2 = FUN_1002b2f0(param_1,param_2);
      return uVar2;
    }
    if (sVar1 == 7) {
      uVar2 = FUN_1002b550(param_1,param_2);
      return uVar2;
    }
    if (sVar1 == 2) {
      uVar2 = FUN_1002a0d0(param_1,param_2);
      return uVar2;
    }
    if (sVar1 == 0x11) {
      uVar2 = FUN_1002a660(param_1,param_2);
      return uVar2;
    }
  }
  return 0;
}

