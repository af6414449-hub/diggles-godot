
ulonglong FUN_10029cf0(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *in_ECX;
  int in_EDX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (((((in_ECX == (undefined4 *)0x0) || (param_1 == 0 && param_2 == 0)) || (in_EDX == 0)) ||
      ((*(short *)(in_ECX + 0x15) == 2 || (*(short *)(in_ECX + 0x15) == 0x11)))) ||
     (uVar3 = FUN_10028d70(), uVar3 == 0)) {
    return 0;
  }
  if (param_2 * uVar3 + (int)((ulonglong)param_1 * (ulonglong)uVar3 >> 0x20) != 0) {
    param_1 = (uint)(0xffffffff / (ulonglong)uVar3);
  }
  param_1 = param_1 * uVar3;
  if (param_1 != 0) {
    uVar2 = in_ECX[0x1c];
    if ((in_ECX[0x1d] == 0) && (uVar2 <= param_1 && param_1 - uVar2 != 0)) {
      param_1 = uVar2;
    }
    uVar4 = (*(code *)*in_ECX)(in_ECX[3],in_EDX,param_1);
    puVar1 = in_ECX + 0x1c;
    uVar2 = *puVar1;
    *puVar1 = *puVar1 - uVar4;
    in_ECX[0x1d] = in_ECX[0x1d] - (uint)(uVar2 < uVar4);
    return (ulonglong)uVar4 / (ulonglong)uVar3;
  }
  return 0;
}

