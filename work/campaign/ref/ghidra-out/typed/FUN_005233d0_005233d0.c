
ViWinProduction * __thiscall FUN_005233d0(ViWinProduction *this)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_007023a0;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *(int *)&this->field_0x20360;
  *(undefined ***)this = ViWinProduction::vftable;
  if (iVar1 != 0) {
    local_8 = 0;
    FUN_004fede0(uVar3);
    FUN_006cecd8(iVar1,0x1c);
  }
  iVar1 = *(int *)&this->field_0x20364;
  if (iVar1 != 0) {
    local_8 = 1;
    FUN_004fede0(uVar3);
    FUN_006cecd8(iVar1,0x1c);
  }
  iVar1 = *(int *)&this->field_0x20368;
  if (iVar1 != 0) {
    local_8 = 2;
    FUN_004fede0(uVar3);
    FUN_006cecd8(iVar1,0x1c);
  }
  local_8 = 3;
  piVar2 = (int *)this->i_2035c;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  local_8 = 4;
  piVar2 = *(int **)&this->field_0x20358;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  local_8 = 5;
  _eh_vector_destructor_iterator_(&this->field_0x54,0x1018,0x20,FUN_00523540);
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x20390);
  }
  ExceptionList = local_10;
  return this;
}

