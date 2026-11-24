
undefined4 FUN_1001ff00(double param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  int *in_ECX;
  uint uVar2;
  uint uVar3;
  double dVar4;
  double local_50;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_50 = param_1 - *(double *)(in_ECX + 0x18);
  if (local_50 <= 0.0) {
    iVar1 = (**(code **)(*in_ECX + 0x10))();
    if (iVar1 != 0) {
      return 6;
    }
    local_50 = param_1;
  }
  dVar4 = floor((double)(float)in_ECX[0x11] * local_50);
  for (uVar2 = (uint)dVar4; uVar2 != 0; uVar2 = uVar2 - uVar3) {
    uVar3 = param_3 / (uint)in_ECX[0x12];
    if ((int)uVar2 < (int)(param_3 / (uint)in_ECX[0x12])) {
      uVar3 = uVar2;
    }
    (**(code **)(*in_ECX + 4))(param_2,uVar3,uVar3);
  }
  *(double *)(in_ECX + 0x18) = local_50;
  return 0;
}

