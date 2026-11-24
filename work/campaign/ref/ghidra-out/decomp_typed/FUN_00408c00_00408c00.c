
void FUN_00408c00(byte param_1)

{
  int *piVar1;
  uint uVar2;
  undefined4 *this;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9400;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *this = CAct_Attack::vftable;
  if (((*(char *)((int)this + 0x51) == '\0') &&
      (this->c_14 = 1, (int)this[0x13] < 3)) && (this[7] != 0)) {
    *(undefined1 *)(this[7] + 0x50) = 1;
    *(undefined4 *)(this[7] + 0x20) = 0;
  }
  if (this[3] != 0) {
    *(bool *)(this[3] + 0x2b5) = *(char *)((int)this + 0x52) != '\0';
  }
  if (this[8] != 0) {
    *(undefined4 *)(this[8] + 0x1c) = 0;
    this[8] = 0;
  }
  if (this[7] != 0) {
    *(undefined4 *)(this[7] + 0x20) = 0;
    this[7] = 0;
  }
  piVar1 = (int *)this[10];
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 1) {
      TclFreeObj(this[10],uVar2);
    }
    this[10] = 0;
  }
  local_8 = 0;
  piVar1 = (int *)this[9];
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    FUN_006ba940();
  }
  FUN_004065c0();
  if ((param_1 & 1) != 0) {
    FUN_006cecd8();
  }
  ExceptionList = local_10;
  return;
}

