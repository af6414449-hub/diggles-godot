
undefined4 FUN_1001ac60(uint param_1)

{
  uint uVar1;
  uint *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  free((void *)in_ECX[1]);
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  *in_ECX = 0;
  uVar1 = FUN_100402f0(param_1 * 4 + 0x10);
  in_ECX[1] = uVar1;
  *in_ECX = uVar1 + 0xf & 0xfffffff0;
  return 0;
}

