
void __thiscall FUN_00527990(ViWinQuickHelp *this)

{
  uint uVar1;
  int *piVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar3;
  int iVar4;
  bool bVar5;
  int in_stack_00000004;
  int *local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 local_14;
  undefined2 local_13;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00701d9d;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (this->i_4c == 0) {
    return;
  }
  ExceptionList = &local_10;
  FUN_004ef7b0(in_stack_00000004 + 0x10);
  local_8 = 0;
  piVar2 = (int *)FUN_004ef240(uVar1);
  if (local_20 == *piVar2) {
    iVar3 = local_20;
    if (local_24 != 0) goto LAB_00527a0e;
  }
  else {
    local_24 = 0;
    local_20 = *piVar2;
  }
  local_24 = FUN_004ef660(local_28 + 3);
  iVar3 = extraout_ECX;
LAB_00527a0e:
  uVar1 = 0;
  iVar4 = *(int *)(local_24 + 0x200) + 2;
  if (0 < this->i_4c) {
    bVar5 = this->i_4c != 0;
    local_13 = 0xc8c8;
    local_14 = 200;
    local_11 = 0xa0;
    local_1c = 5;
    do {
      if (!bVar5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = extraout_ECX_00;
      }
      local_18 = iVar4;
      FUN_004fdff0(&local_1c,*(int *)(this->i_48 + uVar1 * 4) + 0xc,&local_14,&local_28,1,iVar3);
      piVar2 = (int *)FUN_004ef240();
      if (local_20 == *piVar2) {
        iVar3 = local_20;
        if (local_24 == 0) goto LAB_00527a94;
      }
      else {
        local_24 = 0;
        local_20 = *piVar2;
LAB_00527a94:
        local_24 = FUN_004ef660(local_28 + 3);
        iVar3 = extraout_ECX_01;
      }
      uVar1 = uVar1 + 1;
      iVar4 = iVar4 + 3 + *(int *)(local_24 + 0x200);
      bVar5 = uVar1 < (uint)this->i_4c;
    } while ((int)uVar1 < this->i_4c);
  }
  local_8 = 1;
  if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

