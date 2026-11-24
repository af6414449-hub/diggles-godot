
void __thiscall FUN_00512440(ViWinInventory *this)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *local_20;
  int *local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00701865;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004fef30("data/gui/InventorySlot.tga");
  FUN_004fef30("data/gui/Hand.tga");
  local_18 = 8;
  uVar3 = 1;
  do {
    iVar4 = DAT_00772478 + 0x10;
    if (uVar3 < 6) {
      iVar4 = iVar4 + local_18;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_006b95d0(iVar4,uVar1);
    local_8 = 0;
    piVar2 = (int *)FUN_006b9500(&DAT_00722400);
    local_8._0_1_ = 1;
    iVar4 = *piVar2;
    if (5 < uVar3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_004fef30(iVar4 + 0xc);
    local_8 = CONCAT31(local_8._1_3_,2);
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8 = 3;
    if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
      FUN_006ba940();
    }
    uVar3 = uVar3 + 1;
    local_18 = local_18 + 8;
    local_8 = 0xffffffff;
  } while ((int)uVar3 < 6);
  ExceptionList = local_10;
  return;
}

