
undefined4
CTclGlobalMethods__IsDigMarked(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  CMap *pCVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  CMapCell *pCVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined1 uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  float fVar12;
  undefined8 uVar13;
  int local_68;
  char local_64;
  int *local_60;
  int *local_5c;
  undefined4 *local_58;
  uint local_54;
  int local_50;
  double local_4c;
  double local_44;
  double local_3c;
  double local_34;
  undefined4 *local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e6ad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7208) &&
     (FUN_006cebf4(&DAT_00ca7208,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7208 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca720c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::IsDigMarked()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7208);
  }
  iVar6 = DAT_00ca720c;
  local_2c = &DAT_00ca720c;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca720c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar10;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 5) {
    if (local_50 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_58 + 1;
    }
    piVar7 = (int *)*puVar11;
    if (piVar7 == (int *)0x0) {
      local_14 = 0;
    }
    else {
      *piVar7 = *piVar7 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar7,&local_34);
      fVar12 = 0.0;
      if (iVar3 != 1) {
        fVar12 = (float)local_34;
      }
      *piVar7 = *piVar7 + -1;
      local_14 = (int)fVar12;
      if (*piVar7 < 1) {
        TclFreeObj(piVar7);
      }
    }
    if (local_50 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_58 + 2;
    }
    piVar7 = (int *)*puVar11;
    if (piVar7 == (int *)0x0) {
      local_1c = 0;
    }
    else {
      *piVar7 = *piVar7 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar7,&local_3c);
      if (iVar3 == 1) {
        fVar12 = 0.0;
      }
      else {
        fVar12 = (float)local_3c;
      }
      *piVar7 = *piVar7 + -1;
      local_1c = (int)fVar12;
      if (*piVar7 < 1) {
        TclFreeObj(piVar7);
      }
    }
    if (local_50 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_58 + 3;
    }
    piVar7 = (int *)*puVar11;
    if (piVar7 == (int *)0x0) {
      local_20 = 0;
    }
    else {
      *piVar7 = *piVar7 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar7,&local_44);
      if (iVar3 == 1) {
        fVar12 = 0.0;
      }
      else {
        fVar12 = (float)local_44;
      }
      *piVar7 = *piVar7 + -1;
      local_20 = (int)fVar12;
      if (*piVar7 < 1) {
        TclFreeObj(piVar7);
      }
    }
    if (local_50 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_58 + 4;
    }
    piVar7 = (int *)*puVar11;
    if (piVar7 == (int *)0x0) {
      local_18 = 0;
    }
    else {
      *piVar7 = *piVar7 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar7,&local_4c);
      if (iVar3 == 1) {
        fVar12 = 0.0;
      }
      else {
        fVar12 = (float)local_4c;
      }
      *piVar7 = *piVar7 + -1;
      local_18 = (int)fVar12;
      if (*piVar7 < 1) {
        TclFreeObj(piVar7);
      }
    }
    uVar9 = 0;
    local_28 = *(undefined4 *)(DAT_00772400 + 100);
    iVar3 = local_18;
    iVar6 = local_1c;
    uVar2 = 0;
    if (local_14 < local_20) {
      do {
        uVar9 = uVar2;
        iVar8 = iVar6;
        local_24 = iVar6;
        if (iVar6 < iVar3) {
          do {
            pCVar1 = PTR_0077241c;
            iVar3 = PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= local_14) {
              iVar3 = local_14;
            }
            iVar8 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= iVar6) {
              iVar8 = iVar6;
            }
            iVar4 = PTR_0077241c->cellY1 + -1;
            if (iVar8 < PTR_0077241c->cellY1) {
              iVar4 = iVar8;
            }
            iVar8 = PTR_0077241c->cellX1 + -1;
            if (iVar3 < PTR_0077241c->cellX1) {
              iVar8 = iVar3;
            }
            iVar3 = (iVar4 * PTR_0077241c->mapWidth + iVar8) % PTR_0077241c->cellCountTotal;
            local_24 = iVar6;
            if ((iVar3 < 0) || (PTR_0077241c->cellCount <= iVar3)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar5 = pCVar1->cells;
            }
            else {
              pCVar5 = PTR_0077241c->cells + iVar3;
            }
            iVar3 = local_18;
            iVar8 = local_1c;
            if ((pCVar5->digMarks >> ((char)local_28 * '\x04' & 0x1fU) & 0xf) != 0) {
              uVar9 = 1;
              break;
            }
            iVar6 = local_24 + 1;
            local_24 = iVar6;
          } while (iVar6 < local_18);
        }
        local_14 = local_14 + 1;
        iVar6 = iVar8;
        uVar2 = uVar9;
      } while (local_14 < local_20);
    }
    piVar7 = (int *)Tcl_NewBooleanObj(uVar9);
    *piVar7 = *piVar7 + 1;
    iVar3 = *piVar7;
    if (local_68 != 0) {
      Tcl_SetObjResult(local_68,piVar7);
      iVar3 = *piVar7;
    }
    *piVar7 = iVar3 + -1;
    if (iVar3 + -1 < 1) {
      TclFreeObj(piVar7);
    }
    uVar10 = 0;
  }
  else {
    FUN_006bc8f0(4);
    uVar10 = 1;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_58 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_64 != '\0') && (local_68 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_68);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 5;
  if ((local_5c != (int *)0x0) && (*local_5c = *local_5c + -1, *local_5c == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((local_60 != (int *)0x0) && (*local_60 = *local_60 + -1, *local_60 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

