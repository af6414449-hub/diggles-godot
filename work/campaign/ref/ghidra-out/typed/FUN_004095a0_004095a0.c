
CAct_AttackBallistic * __thiscall FUN_004095a0(CAct_AttackBallistic *this)

{
  void *lp;
  uint uVar1;
  int iVar2;
  BOOL BVar3;
  uint uVar4;
  bool bVar5;
  byte in_stack_00000004;
  undefined4 uVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006f98c0;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  uVar4 = 0;
  *(undefined ***)this = CAct_AttackBallistic::vftable;
  if (0 < this->i_38) {
    bVar5 = this->i_38 != 0;
    do {
      if (!bVar5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar2 = this->i_34;
      if (-1 < *(int *)(iVar2 + uVar4 * 4)) {
        if ((uint)this->i_38 <= uVar4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar2 = this->i_34;
        }
        uVar6 = *(undefined4 *)(iVar2 + uVar4 * 4);
        FUN_00492250(uVar6,uVar1);
        FUN_00495750(uVar6);
      }
      uVar4 = uVar4 + 1;
      bVar5 = uVar4 < (uint)this->i_38;
    } while ((int)uVar4 < this->i_38);
  }
  lp = (void *)this->i_0c;
  if (lp != (void *)0x0) {
    BVar3 = IsBadReadPtr(lp,0x10);
    if (((BVar3 == 0) && (*(int *)((int)lp + 8) == 0x616e4f62)) &&
       ((DAT_00768398 == '\0' || (*(int *)((int)lp + 0xdc) != 0)))) {
      *(undefined1 *)(this->i_0c + 0x401) = 0;
    }
  }
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0040b980(0);
  if (this->i_34 != 0) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_0040b980(0);
  if (this->i_24 != 0) {
    FUN_006ba940();
  }
  FUN_004065c0();
  if ((in_stack_00000004 & 1) != 0) {
    FUN_006cecd8(this,0x68);
  }
  ExceptionList = local_10;
  return this;
}

