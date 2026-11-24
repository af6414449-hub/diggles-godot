
ViWinClock * __thiscall FUN_0050a720(ViWinClock *this)

{
  uint uVar1;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f9300;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = ViWinClock::vftable;
  local_8 = 0;
  FUN_004fede0(uVar1);
  local_8 = 1;
  FUN_004fede0();
  FUN_00504770();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0xec);
  }
  ExceptionList = local_10;
  return this;
}

