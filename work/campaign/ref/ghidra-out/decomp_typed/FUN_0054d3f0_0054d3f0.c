
undefined1 FUN_0054d3f0(undefined4 *param_1)

{
  int iVar1;
  undefined1 uVar2;
  int this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006fc57d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar1 = param_1[2];
  if ((iVar1 != DAT_007723c4) && (iVar1 != DAT_007723cc)) {
    if (iVar1 != DAT_007723d0) {
      if (param_1 != (undefined4 *)0x0) {
        LOCK();
        param_1[1] = param_1[1] + 1;
        UNLOCK();
      }
      uVar2 = FUN_005145b0(param_1);
      goto LAB_0054d452;
    }
    if (this->c_1c != '\0') {
      FUN_00504ee0(DAT_0076700c ^ (uint)&stack0xfffffffc);
      this->c_1c = 0;
    }
  }
  uVar2 = 1;
LAB_0054d452:
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar1 = param_1[1] + -1;
    param_1[1] = iVar1;
    UNLOCK();
    if ((iVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return uVar2;
}

