
undefined1 __thiscall FUN_0050db70(ViWinDigButtons *this)

{
  int iVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006fc57d;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (in_stack_00000004[2] == DAT_007723a0) {
    iVar4 = 0;
    piVar5 = &this->i_44;
    do {
      iVar1 = *piVar5;
      if (in_stack_00000004[6] == iVar1) {
        if (this->i_5c == iVar4) {
          if (*(char *)(iVar1 + 0x5d) != '\0') {
            *(undefined1 *)(iVar1 + 0x5d) = 0;
            FUN_00504ee0();
          }
          this->i_5c = -1;
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
    piVar5 = in_stack_00000004 + 1;
    LOCK();
    *piVar5 = *piVar5 + 1;
    UNLOCK();
    if (in_stack_00000004[2] == DAT_007723ec) {
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar4 = *piVar5;
        *piVar5 = iVar4 + -1;
        UNLOCK();
        if (iVar4 + -1 == 0) {
          (**(code **)*in_stack_00000004)(1);
        }
      }
    }
    else {
      if (in_stack_00000004[2] != DAT_007723e8) {
        if (in_stack_00000004 != (undefined4 *)0x0) {
          LOCK();
          iVar4 = *piVar5;
          *piVar5 = iVar4 + -1;
          UNLOCK();
          if (iVar4 + -1 == 0) {
            (**(code **)*in_stack_00000004)(1,uVar2);
          }
        }
        uVar3 = 0;
        goto LAB_0050dc6b;
      }
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar4 = *piVar5;
        *piVar5 = iVar4 + -1;
        UNLOCK();
        if (iVar4 + -1 == 0) {
          (**(code **)*in_stack_00000004)(1);
          uVar3 = 1;
          goto LAB_0050dc6b;
        }
      }
    }
    uVar3 = 1;
  }
LAB_0050dc6b:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar5 = in_stack_00000004 + 1;
    iVar4 = *piVar5;
    *piVar5 = *piVar5 + -1;
    UNLOCK();
    if ((iVar4 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar3;
}

