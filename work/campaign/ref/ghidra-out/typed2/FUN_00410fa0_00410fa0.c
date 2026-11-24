
undefined4
FUN_00410fa0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  
  if (param_3 != (undefined4 *)0x0) {
    LOCK();
    param_3[1] = param_3[1] + 1;
    UNLOCK();
  }
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    param_1[1] = param_1[1] + 1;
    UNLOCK();
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xc);
  *(undefined4 **)(in_ECX + 0xc) = param_1;
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    param_1[1] = param_1[1] + 1;
    UNLOCK();
  }
  if (puVar2 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = puVar2[1] + -1;
    puVar2[1] = iVar5;
    UNLOCK();
    if (iVar5 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  *(undefined4 *)(in_ECX + 4) = param_2;
  puVar2 = *(undefined4 **)(in_ECX + 0x10);
  *(undefined4 **)(in_ECX + 0x10) = param_3;
  if (param_3 != (undefined4 *)0x0) {
    LOCK();
    param_3[1] = param_3[1] + 1;
    UNLOCK();
  }
  if (puVar2 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = puVar2[1] + -1;
    puVar2[1] = iVar5;
    UNLOCK();
    if (iVar5 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = param_1[1] + -1;
    param_1[1] = iVar5;
    UNLOCK();
    if (iVar5 == 0) {
      (**(code **)*param_1)(1);
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = param_3[1] + -1;
    param_3[1] = iVar5;
    UNLOCK();
    if (iVar5 == 0) {
      (**(code **)*param_3)(1);
    }
  }
  *(undefined4 *)(in_ECX + 0x54) = param_4;
  *(int *)(in_ECX + 0x5c) = param_6;
  *(undefined4 *)(in_ECX + 0x58) = param_5;
  *(undefined4 *)(in_ECX + 8) = 2;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  FUN_00445640(-(uint)(param_6 != 0) & param_6 + 4U);
  *(code **)(in_ECX + 0x20) = FUN_00410c30;
  uVar4 = FUN_00410c50();
  *(undefined4 *)(in_ECX + 0x28) = uVar4;
  uVar4 = FUN_00410e00();
  *(undefined4 *)(in_ECX + 0x2c) = uVar4;
  uVar6 = *(int *)(in_ECX + 0x58) - 1;
  iVar5 = *(int *)(in_ECX + 0x10);
  if (*(uint *)(iVar5 + 0xc) <= uVar6) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar5 = *(int *)(iVar5 + 8);
  uVar4 = 0x41600000;
  uVar3 = *(uint *)(iVar5 + uVar6 * 8);
  uVar6 = *(uint *)(iVar5 + 4 + uVar6 * 8);
  if (*(int *)(in_ECX + 0x2c) == 1) {
    iVar5 = FUN_00592f10(PTR_0077241c);
    if ((*(byte *)(((uVar6 & 7) << 3 | uVar3 & 7) + 0x3c + iVar5) & 2) == 0) {
      FUN_004238e0();
    }
    else {
      uVar4 = 0x41600000;
    }
  }
  *(float *)(in_ECX + 0x30) = (float)(int)uVar3 * 0.125;
  *(float *)(in_ECX + 0x34) = (float)(int)uVar6 * 0.125;
  *(undefined4 *)(in_ECX + 0x38) = uVar4;
  *(undefined4 *)(in_ECX + 0x3c) = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar5 = param_1[1] + -1;
    param_1[1] = iVar5;
    UNLOCK();
    if ((iVar5 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = param_3 + 1;
    iVar5 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar5 == 1) && (param_3 != (undefined4 *)0x0)) {
      (**(code **)*param_3)(1);
    }
  }
  return 1;
}

