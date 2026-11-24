
CAct_WalkFloor * __thiscall FUN_0041a120(CAct_WalkFloor *this)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  byte in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9360;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined ***)this = CAct_WalkFloor::vftable;
  if ((undefined4 *)this->i_18 != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)this->i_18)(1,uVar4);
    this->i_18 = 0;
  }
  if (*(int *)&this->field_0x14 != 0) {
    FUN_0041a240(*(int *)&this->field_0x14);
    *(undefined4 *)&this->field_0x14 = 0;
  }
  if (*(int *)(this + 1) != 0) {
    FUN_0040baf0(*(int *)(this + 1));
    *(undefined4 *)(this + 1) = 0;
  }
  local_8 = 0;
  iVar2 = this[2].i_04;
  if (iVar2 < 0) {
    iVar6 = iVar2;
    if ((iVar2 + 0xfU & 0xfffffff0) != 0) {
      uVar5 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                           0x9b);
      iVar6 = this[2].i_04;
      *(undefined4 *)(this + 2) = uVar5;
    }
    this[2].i_04 = iVar6 - iVar2;
  }
  else if (0 < iVar2) {
    this[2].i_04 = 0;
  }
  if (*(int *)(this + 2) != 0) {
    FUN_006ba940();
  }
  *(undefined ***)this = CSubWalk::vftable;
  puVar3 = *(undefined4 **)&this->field_0x10;
  if (puVar3 != (undefined4 *)0x0) {
    LOCK();
    iVar2 = puVar3[1] + -1;
    puVar3[1] = iVar2;
    UNLOCK();
    if (iVar2 == 0) {
      (**(code **)*puVar3)(1);
    }
  }
  puVar3 = (undefined4 *)this->i_0c;
  if (puVar3 != (undefined4 *)0x0) {
    LOCK();
    piVar1 = puVar3 + 1;
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 == 1) {
      (**(code **)*puVar3)(1);
    }
  }
  *(undefined ***)this = CSubAction::vftable;
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x4c);
  }
  ExceptionList = local_10;
  return this;
}

