
ViWinObjJoin * __thiscall FUN_0051c4a0(ViWinObjJoin *this)

{
  uint uVar1;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9360;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ViWinObjJoin::vftable;
  local_8 = 0;
  FUN_0051e830(this);
  if (*(int *)(this + 1) != 0) {
    FUN_006ba940(uVar1);
  }
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x7c);
  }
  ExceptionList = local_10;
  return this;
}

