
ViWinRoot * __thiscall FUN_00527d80(ViWinRoot *this)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007027c0;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ViWinRoot::vftable;
  local_8 = 0;
  piVar1 = (int *)this[1].i_10;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
    FUN_006ba940(uVar3);
  }
  local_8 = 1;
  FUN_00444ea0(0);
  if (*(int *)&this->field_0x84 != 0) {
    FUN_006ba940(uVar3);
  }
  local_8 = 2;
  FUN_00444ea0(0);
  if (*(int *)&this->field_0x7c != 0) {
    FUN_006ba940(uVar3);
  }
  local_8 = 3;
  FUN_0042f870(0);
  if (*(int *)&this->field_0x70 != 0) {
    FUN_006ba940();
  }
  local_8 = 4;
  FUN_004423d0(0);
  if (*(int *)&this->field_0x68 != 0) {
    FUN_006ba940();
  }
  local_8 = 5;
  FUN_004423d0(0);
  if (*(int *)&this->field_0x60 != 0) {
    FUN_006ba940();
  }
  local_8 = 6;
  iVar2 = *(int *)&this->field_0x5c;
  if (iVar2 < 0) {
    FUN_00442060(-iVar2);
  }
  else if (0 < iVar2) {
    FUN_00442590(iVar2);
  }
  if (*(int *)&this->field_0x58 != 0) {
    FUN_006ba940();
  }
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x140);
  }
  ExceptionList = local_10;
  return this;
}

