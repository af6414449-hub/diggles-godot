
int FUN_10011fb0(int *param_1,int *param_2)

{
  int iVar1;
  uint3 uVar2;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  iVar1 = *param_1;
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if (iVar1 < *param_2) {
    return CONCAT31(uVar2,1);
  }
  if (iVar1 == *param_2) {
    return CONCAT31((int3)((uint)param_1[1] >> 8),param_1[1] < param_2[1]);
  }
  return (uint)uVar2 << 8;
}

