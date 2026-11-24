
ViWinBMButton * __thiscall FUN_00507c20(ViWinBMButton *this)

{
  int *piVar1;
  uint uVar2;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9300;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ViWinBMButton::vftable;
  local_8 = 0;
  piVar1 = *(int **)(this + 1);
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    FUN_006ba940(uVar2);
  }
  local_8 = 1;
  piVar1 = *(int **)&this->field_0x54;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    FUN_006ba940(uVar2);
  }
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,100);
  }
  ExceptionList = local_10;
  return this;
}

