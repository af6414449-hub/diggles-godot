
undefined4 FUN_10035ae0(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  int in_EDX;
  bool bVar4;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  if (in_EDX == 0) {
    if ((param_2 == 0) && (param_1 < 0x80000000)) {
      iVar3 = (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 8),param_1,0);
      if (iVar3 == 0) {
        return 0;
      }
      *(uint *)(in_ECX + 0x10) = param_1;
      *(undefined4 *)(in_ECX + 0x14) = 0;
      return 1;
    }
    iVar3 = (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 8),0x7fffffff,0);
    if (iVar3 == 0) {
      return 0;
    }
    *(uint *)(in_ECX + 0x10) = param_1;
    bVar4 = 0x7ffffffe < param_1;
    param_1 = param_1 + 0x80000001;
    *(int *)(in_ECX + 0x14) = param_2;
    param_2 = param_2 + -1 + (uint)bVar4;
    __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  }
  for (; (param_2 != 0 || (0x7fffffff < param_1)); param_1 = param_1 + 0x80000001) {
    iVar3 = (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 8),0x7fffffff,1);
    if (iVar3 == 0) {
      return 0;
    }
    puVar1 = (uint *)(in_ECX + 0x10);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + 0x7fffffff;
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + (uint)(0x80000000 < uVar2);
    param_2 = param_2 + -1 + (uint)(0x7ffffffe < param_1);
  }
  iVar3 = (**(code **)(in_ECX + 4))(*(undefined4 *)(in_ECX + 8),param_1,1);
  if (iVar3 == 0) {
    return 0;
  }
  puVar1 = (uint *)(in_ECX + 0x10);
  uVar2 = *puVar1;
  *puVar1 = *puVar1 + param_1;
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + (uint)CARRY4(uVar2,param_1);
  return 1;
}

