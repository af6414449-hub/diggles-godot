
undefined1 __thiscall FUN_005204d0(ViWinPerformance *this)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 uVar6;
  undefined4 *in_stack_00000004;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0070150d;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (in_stack_00000004[2] == DAT_007723a0) {
    iVar4 = in_stack_00000004[6];
    if (iVar4 == this->i_60) {
      *(bool *)(DAT_0076a338 + 0x101) = *(char *)(DAT_0076a338 + 0x101) == '\0';
      iVar4 = in_stack_00000004[6];
    }
    iVar2 = DAT_00772400;
    if (iVar4 == this->i_64) {
      DAT_00768369 = DAT_00768369 == '\0';
      iVar4 = in_stack_00000004[6];
    }
    if (iVar4 == this->i_68) {
      DAT_00768370 = DAT_00768370 == '\0';
      iVar4 = in_stack_00000004[6];
    }
    if (iVar4 == this->i_6c) {
      DAT_00768378 = DAT_00768378 == '\0';
      iVar4 = in_stack_00000004[6];
    }
    if (iVar4 == this->i_70) {
      DAT_00768371 = DAT_00768371 == '\0';
      iVar4 = in_stack_00000004[6];
    }
    if (iVar4 == this->i_74) {
      *(bool *)(DAT_00772400 + 0x140) = *(char *)(DAT_00772400 + 0x140) == '\0';
    }
    if ((*(char *)(iVar2 + 0x590) != '\0') && (in_stack_00000004[6] == this->i_78)) {
      cVar1 = this->c_80;
      this->c_80 = cVar1 == '\0';
      iVar4 = this->i_54;
      if (cVar1 == '\0') {
        uVar5 = *(uint *)(iVar4 + 0x24) & 0xffffffef;
      }
      else {
        uVar5 = *(uint *)(iVar4 + 0x24) | 0x10;
      }
      if (uVar5 != *(uint *)(iVar4 + 0x24)) {
        *(uint *)(iVar4 + 0x24) = uVar5;
        FUN_00504ee0(uVar3);
      }
    }
    uVar6 = 1;
  }
  else {
    uVar6 = 0;
  }
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    iVar4 = in_stack_00000004[1] + -1;
    in_stack_00000004[1] = iVar4;
    UNLOCK();
    if ((iVar4 == 0) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar6;
}

