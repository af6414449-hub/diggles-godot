
void CTclGlobalMethods__LGMarkArea
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  CMapCell *pCVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  CMap *pCVar9;
  uint uVar10;
  undefined8 uVar11;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070eadd;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7270) &&
     (FUN_006cebf4(&DAT_00ca7270,local_14), iVar3 = DAT_00783650, DAT_00ca7270 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7274 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::LGMarkArea()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7270);
  }
  iVar5 = DAT_00ca7274;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7274 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar11 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 5) {
    FUN_006bc8f0(4);
  }
  else {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_20;
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_20 + 1;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 == (int *)0x0) {
      local_24 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_34);
      *piVar2 = *piVar2 + -1;
      local_24 = -(uint)(iVar3 != 1) & local_34;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_18 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_20;
      }
    }
    else {
      if (local_1c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_20 + 2;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 == (int *)0x0) {
      local_28 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_38);
      *piVar2 = *piVar2 + -1;
      local_28 = -(uint)(iVar3 != 1) & local_38;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_18 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_20;
      }
    }
    else {
      if (local_1c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_20 + 3;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 == (int *)0x0) {
      local_2c = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_3c);
      *piVar2 = *piVar2 + -1;
      local_2c = -(uint)(iVar3 != 1) & local_3c;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_18 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_20;
      }
    }
    else {
      if (local_1c < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_20 + 4;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 == (int *)0x0) {
      uVar10 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_40);
      *piVar2 = *piVar2 + -1;
      uVar10 = -(uint)(iVar3 != 1) & local_40;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    FUN_0058a820();
    uVar6 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= (int)local_24) {
      uVar6 = local_24;
    }
    local_24 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= (int)local_28) {
      local_24 = local_28;
    }
    uVar7 = PTR_0077241c->cellX1;
    if ((int)local_2c <= PTR_0077241c->cellX1) {
      uVar7 = local_2c;
    }
    local_28 = PTR_0077241c->cellY1;
    if ((int)uVar10 <= PTR_0077241c->cellY1) {
      local_28 = uVar10;
    }
    pCVar9 = PTR_0077241c;
    local_30 = uVar6;
    local_2c = uVar7;
    if ((int)local_24 < (int)local_28) {
      do {
        uVar10 = uVar6;
        if ((int)uVar6 < (int)uVar7) {
          do {
            uVar6 = pCVar9->cellX0;
            if (pCVar9->cellX0 <= (int)uVar10) {
              uVar6 = uVar10;
            }
            uVar7 = pCVar9->cellX1 - 1;
            if ((int)uVar6 < pCVar9->cellX1) {
              uVar7 = uVar6;
            }
            uVar6 = pCVar9->cellY0;
            if (pCVar9->cellY0 <= (int)local_24) {
              uVar6 = local_24;
            }
            if (pCVar9->cellY1 <= (int)uVar6) {
              uVar6 = pCVar9->cellY1 - 1;
            }
            iVar3 = (int)(pCVar9->mapWidth * uVar6 + uVar7) % pCVar9->cellCountTotal;
            if ((iVar3 < 0) || (pCVar9->cellCount <= iVar3)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar4 = pCVar9->cells;
              pCVar9 = PTR_0077241c;
            }
            else {
              pCVar4 = pCVar9->cells + iVar3;
            }
            pCVar4->flags = pCVar4->flags | 1;
            uVar10 = uVar10 + 1;
            uVar7 = local_2c;
            uVar6 = local_30;
          } while ((int)uVar10 < (int)local_2c);
        }
        local_24 = local_24 + 1;
      } while ((int)local_24 < (int)local_28);
    }
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

