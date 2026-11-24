
ViWinInfoOpts * __thiscall FUN_0050fe10(ViWinInfoOpts *this)

{
  int *piVar1;
  uint uVar2;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9c40;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ViWinInfoOpts::vftable;
  if (*(int *)&this->field_0x44 != 0) {
    FUN_004f4d00(*(int *)&this->field_0x44);
  }
  local_8 = 0;
  FUN_00444ea0(0);
  if (this->i_68 != 0) {
    FUN_006ba940(uVar2);
  }
  local_8 = 1;
  piVar1 = (int *)this->i_64;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    FUN_006ba940(uVar2);
  }
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x70);
  }
  ExceptionList = local_10;
  return this;
}

