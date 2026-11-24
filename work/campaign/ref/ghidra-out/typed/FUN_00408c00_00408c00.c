
CAct_Attack * __thiscall FUN_00408c00(CAct_Attack *this)

{
  int *piVar1;
  uint uVar2;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9400;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = CAct_Attack::vftable;
  if (((this->c_51 == '\0') && (this->c_50 = '\x01', this->i_4c < 3)) && (this->i_1c != 0)) {
    *(undefined1 *)(this->i_1c + 0x50) = 1;
    *(undefined4 *)(this->i_1c + 0x20) = 0;
  }
  if (this->i_0c != 0) {
    *(bool *)(this->i_0c + 0x2b5) = this->field_0x52 != '\0';
  }
  if (this->i_20 != 0) {
    *(undefined4 *)(this->i_20 + 0x1c) = 0;
    this->i_20 = 0;
  }
  if (this->i_1c != 0) {
    *(undefined4 *)(this->i_1c + 0x20) = 0;
    this->i_1c = 0;
  }
  piVar1 = *(int **)&this->field_0x28;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 1) {
      TclFreeObj(*(undefined4 *)&this->field_0x28,uVar2);
    }
    *(undefined4 *)&this->field_0x28 = 0;
  }
  local_8 = 0;
  piVar1 = *(int **)&this->field_0x24;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    FUN_006ba940();
  }
  FUN_004065c0();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x70);
  }
  ExceptionList = local_10;
  return this;
}

