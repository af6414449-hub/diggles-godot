
void FUN_10008a90(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *_Dst;
  undefined4 *in_ECX;
  uint uVar5;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b7b);
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  uVar1 = param_1[4];
  if (0xf < (uint)param_1[5]) {
    param_1 = (undefined4 *)*param_1;
  }
  if (uVar1 < 0x10) {
    uVar2 = param_1[1];
    uVar3 = param_1[2];
    uVar4 = param_1[3];
    *in_ECX = *param_1;
    in_ECX[1] = uVar2;
    in_ECX[2] = uVar3;
    in_ECX[3] = uVar4;
    in_ECX[4] = uVar1;
    in_ECX[5] = 0xf;
    return;
  }
  uVar5 = uVar1 | 0xf;
  if (0x7fffffff < uVar5) {
    uVar5 = 0x7fffffff;
  }
  _Dst = (void *)FUN_10003e80(-(uint)(0xfffffffe < uVar5) | uVar5 + 1);
  *in_ECX = _Dst;
  memcpy(_Dst,param_1,uVar1 + 1);
  in_ECX[4] = uVar1;
  in_ECX[5] = uVar5;
  return;
}

