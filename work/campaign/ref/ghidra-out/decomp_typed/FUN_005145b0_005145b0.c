
undefined1 FUN_005145b0(undefined4 *param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00701abd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar2 = param_1[2];
  if (iVar2 == DAT_007723d4) {
    iVar2 = FUN_005147e0(param_1[9],param_1[10]);
    if (this->i_1c0 != iVar2) {
      this->i_1c0 = iVar2;
      FUN_00504ee0();
    }
  }
  else if ((iVar2 != DAT_007723c4) && (iVar2 != DAT_007723cc)) {
    if (iVar2 == DAT_007723d0) {
      if (this->i_1c0 != -1) {
        iVar2 = FUN_004e3d30(this->i_1c0);
        if ((((*(uint *)(iVar2 + 0x34) >> 0x1b & 1) == 0) &&
            (iVar2 = *(int *)(iVar2 + 0x3c), 0 < iVar2)) && (iVar2 < this->i_1b4)) {
          iVar3 = FUN_00441fe0(iVar2);
          if (*(int *)(iVar3 + 4) != 0) {
            iVar3 = FUN_00441fe0(iVar2);
            if (*(char *)(iVar3 + 8) == '\0') {
              FUN_00441fe0(iVar2);
              uVar4 = FUN_006bafc0();
              FUN_00515340(uVar4);
            }
            else {
              iVar2 = FUN_00441fe0(iVar2);
              iVar2 = iVar2 + 4;
LAB_005146a6:
              FUN_005152e0(iVar2);
            }
          }
        }
      }
    }
    else {
      if (iVar2 != DAT_007723c8) {
        if ((iVar2 == DAT_007723d8) && (param_1[0x10] == 0x1b)) {
          FUN_00501450(DAT_0076700c ^ (uint)&stack0xfffffffc);
          FUN_00531f40();
        }
        if (param_1 != (undefined4 *)0x0) {
          LOCK();
          param_1[1] = param_1[1] + 1;
          UNLOCK();
        }
        uVar1 = FUN_00505d60(param_1);
        goto LAB_005146b0;
      }
      iVar2 = this->i_1c0;
      if (iVar2 != -1) {
        if (iVar2 < this->i_134) {
          iVar2 = FUN_004e3d30(iVar2);
          if ((((*(uint *)(iVar2 + 0x34) >> 0x1b & 1) == 0) &&
              (iVar2 = *(int *)(iVar2 + 0x3c), 0 < iVar2)) && (iVar2 < this->i_1b4)) {
            iVar3 = FUN_00441fe0(iVar2);
            if (*(char *)(iVar3 + 8) != '\0') {
              iVar2 = FUN_00441fe0(iVar2);
              goto LAB_005146a6;
            }
            FUN_00441fe0(iVar2);
            uVar4 = FUN_006bafc0();
            FUN_00515340(uVar4);
          }
        }
        else {
          this->i_1c0 = 0xffffffff;
        }
      }
    }
  }
  uVar1 = 1;
LAB_005146b0:
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar2 = param_1[1] + -1;
    param_1[1] = iVar2;
    UNLOCK();
    if ((iVar2 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return uVar1;
}

