
undefined4 FUN_00423730(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint in_ECX;
  char in_DL;
  undefined4 uVar5;
  
  if ((uint)param_1[3] <= in_ECX) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  uVar2 = *(uint *)(param_1[2] + in_ECX * 8);
  uVar3 = *(uint *)(param_1[2] + 4 + in_ECX * 8);
  iVar4 = FUN_00592f10(PTR_0077241c);
  bVar1 = *(byte *)(((uVar3 & 7) << 3 | uVar2 & 7) + 0x3c + iVar4);
  if ((in_DL != '\0') && ((bVar1 & 4) != 0)) {
    iVar4 = FUN_004237e0();
    if (*(int *)(iVar4 + 0xdc) != 0) {
      uVar5 = 1;
      goto LAB_004237bb;
    }
  }
  if ((bVar1 & 2) == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = 2;
  }
LAB_004237bb:
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar4 = param_1[1] + -1;
    param_1[1] = iVar4;
    UNLOCK();
    if ((iVar4 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  return uVar5;
}

