
undefined1 FUN_0050db70(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  int this;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006fc57d;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1[2] == DAT_007723a0) {
    iVar4 = 0;
    piVar5 = (int *)(this + 0x44);
    do {
      iVar1 = *piVar5;
      if (param_1[6] == iVar1) {
        if (this->i_5c == iVar4) {
          if (*(char *)(iVar1 + 0x5d) != '\0') {
            *(undefined1 *)(iVar1 + 0x5d) = 0;
            FUN_00504ee0();
          }
          this->i_5c = 0xffffffff;
        }
        else {
          if (*(char *)(iVar1 + 0x5d) != '\x01') {
            *(undefined1 *)(iVar1 + 0x5d) = 1;
            FUN_00504ee0();
          }
          this->i_5c = iVar4;
        }
      }
      else if (*(char *)(iVar1 + 0x5d) != '\0') {
        *(undefined1 *)(iVar1 + 0x5d) = 0;
        FUN_00504ee0();
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar4 < 6);
    uVar3 = 1;
  }
  else {
    piVar5 = param_1 + 1;
    LOCK();
    *piVar5 = *piVar5 + 1;
    UNLOCK();
    if (param_1[2] == DAT_007723ec) {
      if (param_1 != (undefined4 *)0x0) {
        LOCK();
        iVar4 = *piVar5;
        *piVar5 = iVar4 + -1;
        UNLOCK();
        if (iVar4 + -1 == 0) {
          (**(code **)*param_1)(1);
        }
      }
    }
    else {
      if (param_1[2] != DAT_007723e8) {
        if (param_1 != (undefined4 *)0x0) {
          LOCK();
          iVar4 = *piVar5;
          *piVar5 = iVar4 + -1;
          UNLOCK();
          if (iVar4 + -1 == 0) {
            (**(code **)*param_1)(1,uVar2);
          }
        }
        uVar3 = 0;
        goto LAB_0050dc6b;
      }
      if (param_1 != (undefined4 *)0x0) {
        LOCK();
        iVar4 = *piVar5;
        *piVar5 = iVar4 + -1;
        UNLOCK();
        if (iVar4 + -1 == 0) {
          (**(code **)*param_1)(1);
          uVar3 = 1;
          goto LAB_0050dc6b;
        }
      }
    }
    uVar3 = 1;
  }
LAB_0050dc6b:
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    piVar5 = param_1 + 1;
    iVar4 = *piVar5;
    *piVar5 = *piVar5 + -1;
    UNLOCK();
    if ((iVar4 == 1) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return uVar3;
}

