
void __thiscall FUN_0051ee50(ViWinOverlayMsg *this)

{
  uint uVar1;
  int *piVar2;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  undefined1 local_14;
  undefined2 local_13;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070215d;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_13 = 0;
  local_14 = 0;
  local_11 = 0xc0;
  local_28 = 0;
  local_20 = 0x1000;
  local_24 = 0;
  local_1c = 0x1000;
  FUN_004fdfa0(&local_28,&local_14);
  FUN_004ef860(&DAT_00725a00);
  local_8 = 0;
  uVar5 = 0;
  local_18 = this->i_48;
  iVar4 = 5;
  if (0 < local_18) {
    local_13 = 0xffff;
    local_14 = 0xff;
    local_11 = 200;
    local_20 = 5;
    do {
      piVar2 = (int *)FUN_004ef240(uVar1);
      if (local_2c == *piVar2) {
        iVar3 = local_2c;
        if (local_30 == 0) goto LAB_0051ef13;
      }
      else {
        local_30 = 0;
        local_2c = *piVar2;
LAB_0051ef13:
        local_30 = FUN_004ef660(local_34 + 3);
        iVar3 = extraout_ECX;
      }
      iVar4 = iVar4 + *(int *)(local_30 + 0x204);
      if ((uint)this->i_48 <= uVar5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = extraout_ECX_00;
      }
      local_1c = iVar4;
      FUN_004fdff0(&local_20,*(int *)(this->i_44 + uVar5 * 4) + 0xc,&local_14,&local_34,1,iVar3);
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < local_18);
  }
  local_8 = 1;
  if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

