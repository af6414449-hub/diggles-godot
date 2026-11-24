
ViWinClickPicBox * __thiscall FUN_0050a490(ViWinClickPicBox *this)

{
  int iVar1;
  uint uVar2;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9360;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = *(int *)&this[1].field_0x16;
  *(undefined ***)this = ViWinClickPicBox::vftable;
  if (iVar1 != 0) {
    local_8 = 0;
    FUN_004fede0(uVar2);
    FUN_006cecd8(iVar1,0x1c);
  }
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x48);
  }
  ExceptionList = local_10;
  return this;
}

