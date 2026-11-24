
ViWin * __thiscall FUN_00505dd0(ViWin *this)

{
  int iVar1;
  ViWin *pVVar2;
  uint uVar3;
  int in_stack_00000004;
  int in_stack_00000008;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if ((((this->c_1c == '\0') || (this->c_2c == '\0')) ||
      (iVar1 = FUN_00501450(), (this->i_28 & *(uint *)(iVar1 + 0x101f8)) == 0)) ||
     (((FUN_00504c80(&local_18), in_stack_00000004 < local_18 || (local_10 <= in_stack_00000004)) ||
      ((in_stack_00000008 < local_14 || (local_c <= in_stack_00000008)))))) {
    return (ViWin *)0x0;
  }
  iVar1 = this->i_3c;
  uVar3 = 0;
  if (0 < iVar1) {
    do {
      if ((uint)this->i_3c <= uVar3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      pVVar2 = (ViWin *)(**(code **)(**(int **)(this->i_38 + uVar3 * 4) + 0x34))
                                  (in_stack_00000004,in_stack_00000008);
      if (pVVar2 != (ViWin *)0x0) {
        return pVVar2;
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < iVar1);
  }
  return this;
}

