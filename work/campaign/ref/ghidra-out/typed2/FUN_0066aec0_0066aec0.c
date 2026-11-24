
undefined4 FUN_0066aec0(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  CMap *pCVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  uint uVar12;
  CMapCell *pCVar13;
  undefined1 *puVar14;
  int iVar15;
  undefined4 *local_4c;
  uint local_48;
  int local_44;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  CMap *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070fbf5;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006bc170(param_2);
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 6) {
    if (local_44 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_4c + 1;
    }
    piVar1 = (int *)*puVar11;
    if (piVar1 == (int *)0x0) {
      uVar2 = 0;
      local_1c = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_28,uVar2);
      *piVar1 = *piVar1 + -1;
      uVar2 = -(uint)(iVar3 != 1) & local_28;
      local_1c = uVar2;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    if (local_44 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_4c + 2;
    }
    piVar1 = (int *)*puVar11;
    if (piVar1 == (int *)0x0) {
      param_3 = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_2c);
      *piVar1 = *piVar1 + -1;
      param_3 = -(uint)(iVar3 != 1) & local_2c;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    if (local_44 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_4c + 3;
    }
    piVar1 = (int *)*puVar11;
    if (piVar1 == (int *)0x0) {
      local_14 = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_30);
      *piVar1 = *piVar1 + -1;
      local_14 = -(uint)(iVar3 != 1) & local_30;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    if (local_44 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_4c + 4;
    }
    piVar1 = (int *)*puVar11;
    if (piVar1 == (int *)0x0) {
      local_18 = (CMap *)0x0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_34);
      *piVar1 = *piVar1 + -1;
      local_18 = (CMap *)(-(uint)(iVar3 != 1) & local_34);
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    if (local_44 < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_4c + 5;
    }
    piVar1 = (int *)*puVar11;
    if (piVar1 == (int *)0x0) {
      local_24 = 0;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_38);
      *piVar1 = *piVar1 + -1;
      local_24 = -(uint)(iVar3 != 1) & local_38;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    local_20 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= (int)param_3) {
      local_20 = param_3;
    }
    uVar7 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= (int)local_14) {
      uVar7 = local_14;
    }
    pCVar8 = (CMap *)PTR_0077241c->cellX1;
    if ((int)local_18 <= PTR_0077241c->cellX1) {
      pCVar8 = local_18;
    }
    uVar4 = uVar7;
    uVar12 = PTR_0077241c->cellY1;
    if ((int)local_24 <= PTR_0077241c->cellY1) {
      uVar12 = local_24;
    }
    for (; local_24 = uVar4, uVar4 = local_20, (int)uVar7 < (int)uVar12; uVar7 = uVar7 + 1) {
      while (local_14 = uVar4, (int)local_14 < (int)pCVar8) {
        uVar2 = PTR_0077241c->cellX0;
        if (PTR_0077241c->cellX0 <= (int)local_14) {
          uVar2 = local_14;
        }
        uVar4 = PTR_0077241c->cellY0;
        if (PTR_0077241c->cellY0 <= (int)uVar7) {
          uVar4 = uVar7;
        }
        uVar9 = PTR_0077241c->cellY1 - 1;
        if ((int)uVar4 < PTR_0077241c->cellY1) {
          uVar9 = uVar4;
        }
        uVar4 = PTR_0077241c->cellX1 - 1;
        if ((int)uVar2 < PTR_0077241c->cellX1) {
          uVar4 = uVar2;
        }
        iVar3 = (int)(uVar4 + uVar9 * PTR_0077241c->mapWidth) % PTR_0077241c->cellCountTotal;
        local_18 = PTR_0077241c;
        if ((iVar3 < 0) || (PTR_0077241c->cellCount <= iVar3)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar13 = local_18->cells;
        }
        else {
          pCVar13 = PTR_0077241c->cells + iVar3;
        }
        uVar2 = local_1c;
        if (local_1c < 8) {
          pCVar13 = (CMapCell *)(pCVar13->ownerIndex + (local_1c - 0x34));
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (pCVar13->ownerIndex[0] == '\0') {
          iVar3 = FUN_00592f10(PTR_0077241c);
          puVar14 = (undefined1 *)(iVar3 + 0x34);
          if (uVar2 < 8) {
            puVar14 = puVar14 + uVar2;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *puVar14 = 1;
        }
        uVar4 = local_14 + 1;
      }
      uVar4 = local_24;
    }
    if (uVar2 == *(uint *)(DAT_00772400 + 100)) {
      iVar5 = local_20 << 3;
      iVar6 = local_24 << 3;
      iVar3 = (int)pCVar8 * 8;
      iVar15 = uVar12 * 8;
      uVar10 = 0x10;
      FUN_005a3dd0(iVar5,iVar6,iVar3,iVar15,0x10);
      FUN_005a3fd0(iVar5,iVar6,iVar3,iVar15,uVar10);
    }
    uVar10 = 0;
  }
  else {
    FUN_006bc8f0(5);
    uVar10 = 1;
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_4c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  ExceptionList = local_10;
  return uVar10;
}

