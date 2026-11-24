
undefined4 FUN_0041fe30(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int this;
  
  puVar2 = *(undefined4 **)(this + 0xc);
  *(undefined4 **)(this + 0xc) = param_1;
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    param_1[1] = param_1[1] + 1;
    UNLOCK();
  }
  if (puVar2 != (undefined4 *)0x0) {
    LOCK();
    iVar3 = puVar2[1] + -1;
    puVar2[1] = iVar3;
    UNLOCK();
    if (iVar3 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  this->i_04 = param_2;
  puVar2 = *(undefined4 **)(this + 0x10);
  *(undefined4 **)(this + 0x10) = param_3;
  if (param_3 != (undefined4 *)0x0) {
    LOCK();
    param_3[1] = param_3[1] + 1;
    UNLOCK();
  }
  if (puVar2 != (undefined4 *)0x0) {
    LOCK();
    iVar3 = puVar2[1] + -1;
    puVar2[1] = iVar3;
    UNLOCK();
    if (iVar3 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar3 = param_1[1] + -1;
    param_1[1] = iVar3;
    UNLOCK();
    if ((iVar3 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = param_3 + 1;
    iVar3 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if ((iVar3 == 1) && (param_3 != (undefined4 *)0x0)) {
      (**(code **)*param_3)(1);
    }
  }
  return 1;
}

