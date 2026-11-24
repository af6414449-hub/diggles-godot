
undefined4
CTclObjMethods__ObjFindNextVar
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int *piVar4;
  void *lp;
  uint uVar5;
  char cVar6;
  int iVar7;
  undefined **ppuVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  BOOL BVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  code *pcVar16;
  uint uVar17;
  float fVar18;
  float fVar19;
  undefined8 uVar20;
  int local_5c;
  undefined4 *local_4c;
  uint local_48;
  int local_44;
  int *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007122bd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c50) &&
     (FUN_006cebf4(&DAT_00ca7c50,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar7 = DAT_00783650,
     DAT_00ca7c50 == -1)) {
    iVar13 = DAT_00783650 * 0x40;
    DAT_00ca7c54 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar13) = "TCL:CTclObjMethods::ObjFindNextVar()";
    *(int *)(&DAT_00773650 + iVar13) = iVar7;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c50);
  }
  iVar13 = DAT_00ca7c54;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c54 * 0x40);
  iVar7 = FUN_0043fcc0();
  *(undefined4 *)(iVar7 + *(int *)(iVar7 + 0x8000) * 4) = uVar10;
  *(int *)(iVar7 + 0x8000) = *(int *)(iVar7 + 0x8000) + 1;
  iVar7 = (&DAT_00773654)[iVar13 * 0x10];
  if (iVar7 == 0) {
    uVar20 = FUN_006bd180();
    iVar7 = (&DAT_00773654)[iVar13 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar13 * 0x10) = uVar20;
  }
  (&DAT_00773654)[iVar13 * 0x10] = iVar7 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  iVar7 = FUN_005c71c0(param_4,4,1);
  if (iVar7 == 0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  else {
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
    piVar3 = (int *)*puVar11;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
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
    piVar4 = (int *)*puVar11;
    if (piVar4 != (int *)0x0) {
      *piVar4 = *piVar4 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,6);
    if (piVar3 == (int *)0x0) {
      ppuVar8 = &PTR_0071ce50;
    }
    else {
      ppuVar8 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
    }
    FUN_006b8fb0(ppuVar8);
    local_18 = DAT_00772478;
    cVar6 = FUN_006037d0(&local_1c,&local_14);
    if (cVar6 == '\0') {
      local_18 = 0;
    }
    else {
      if (*(uint *)(local_18 + 0x801c) <= local_14) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_18 = *(int *)(*(int *)(local_18 + 0x8018) + local_14 * 4);
    }
    local_8._0_1_ = 7;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,6);
    if (local_18 != 0) {
      uVar14 = 0xffffffff;
      uVar17 = 0;
      local_14 = 0xffffffff;
      fVar1 = *(float *)(iVar7 + 0xc);
      fVar2 = *(float *)(iVar7 + 0x10);
      uVar10 = *(undefined4 *)(iVar7 + 0x36c);
      local_1c = (int *)0x49742400;
      do {
        piVar15 = (int *)(DAT_0077244c + 0x488);
        if (uVar17 < 0x2000) {
          piVar15 = piVar15 + uVar17;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar14 = local_14;
        }
        iVar13 = *piVar15;
        piVar15 = local_1c;
        uVar5 = local_14;
        if ((((iVar13 != 0) && (iVar13 != iVar7)) && (*(int *)(iVar13 + 0xd4) == local_18)) &&
           (((byte)*(undefined4 *)(iVar13 + 0x3d0) & 5) == 1)) {
          iVar9 = FUN_005cb3a0(uVar10);
          if (0 < iVar9) {
            fVar18 = *(float *)(iVar13 + 0x10) - fVar2;
            fVar19 = *(float *)(iVar13 + 0xc) - fVar1;
            piVar15 = (int *)(fVar18 * fVar18 + fVar19 * fVar19);
            FUN_0040b7e0();
            uVar14 = uVar17;
            uVar5 = uVar17;
            if ((float)piVar15 < (float)local_1c) goto LAB_006a3e68;
          }
          uVar14 = local_14;
          piVar15 = local_1c;
          uVar5 = local_14;
        }
LAB_006a3e68:
        local_14 = uVar5;
        local_1c = piVar15;
        uVar17 = uVar17 + 1;
      } while ((int)uVar17 < 0x2000);
      if (uVar14 == 0xffffffff) {
        piVar15 = (int *)Tcl_NewBooleanObj(0);
        *piVar15 = *piVar15 + 1;
        iVar7 = *piVar15;
        if (local_5c != 0) {
          Tcl_SetObjResult(local_5c,piVar15);
          iVar7 = *piVar15;
        }
        *piVar15 = iVar7 + -1;
        if (iVar7 + -1 < 1) {
          TclFreeObj(piVar15);
        }
        piVar15 = (int *)Tcl_NewIntObj(0);
        *piVar15 = *piVar15 + 1;
        local_8 = CONCAT31(local_8._1_3_,10);
        if (((local_5c != 0) && (piVar4 != (int *)0x0)) &&
           (iVar7 = Tcl_ObjSetVar2(local_5c,piVar4,0,piVar15,0x200), iVar7 == 0)) {
          uVar10 = Tcl_GetStringResult(local_5c);
          uVar10 = FUN_006b9200(uVar10);
          FUN_006b91c0(uVar10);
        }
        *piVar15 = *piVar15 + -1;
        pcVar16 = TclFreeObj_exref;
        if (*piVar15 < 1) {
          TclFreeObj(piVar15);
          pcVar16 = TclFreeObj_exref;
        }
      }
      else {
        puVar11 = (undefined4 *)(DAT_0077244c + 0x488);
        if (uVar14 < 0x2000) {
          puVar11 = puVar11 + uVar14;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        lp = (void *)*puVar11;
        if (((lp == (void *)0x0) || (BVar12 = IsBadReadPtr(lp,0x10), BVar12 != 0)) ||
           ((*(int *)((int)lp + 8) != 0x616e4f62 ||
            ((DAT_00768398 != '\0' && (*(int *)((int)lp + 0xdc) == 0)))))) {
          if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
            TclFreeObj(piVar4);
          }
          if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
            TclFreeObj(piVar3);
          }
          local_8._0_1_ = 0xb;
          FUN_004297b0(0);
          local_8 = CONCAT31(local_8._1_3_,0xc);
          goto LAB_006a4158;
        }
        piVar15 = (int *)Tcl_NewBooleanObj(1);
        *piVar15 = *piVar15 + 1;
        iVar7 = *piVar15;
        if (local_5c != 0) {
          Tcl_SetObjResult(local_5c,piVar15);
          iVar7 = *piVar15;
        }
        *piVar15 = iVar7 + -1;
        if (iVar7 + -1 < 1) {
          TclFreeObj(piVar15);
        }
        if (0x1fff < local_14) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar15 = (int *)FUN_005caf90();
        if (piVar15 != (int *)0x0) {
          piVar15 = (int *)Tcl_NewStringObj(piVar15,0xffffffff);
          *piVar15 = *piVar15 + 1;
        }
        local_8 = CONCAT31(local_8._1_3_,0xd);
        if (local_5c != 0) {
          if (piVar15 == (int *)0x0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pcVar16 = TclFreeObj_exref;
            goto LAB_006a3f2d;
          }
          if ((piVar4 != (int *)0x0) &&
             (iVar7 = Tcl_ObjSetVar2(local_5c,piVar4,0,piVar15,0x200), iVar7 == 0)) {
            uVar10 = Tcl_GetStringResult(local_5c);
            uVar10 = FUN_006b9200(uVar10);
            FUN_006b91c0(uVar10);
          }
        }
        pcVar16 = TclFreeObj_exref;
        if ((piVar15 != (int *)0x0) &&
           (*piVar15 = *piVar15 + -1, pcVar16 = TclFreeObj_exref, *piVar15 < 1)) {
          TclFreeObj(piVar15);
        }
      }
LAB_006a3f2d:
      if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
        (*pcVar16)(piVar4);
      }
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
        (*pcVar16)(piVar3);
      }
      local_8._0_1_ = 0xe;
      FUN_004297b0(0);
      local_8 = CONCAT31(local_8._1_3_,0xf);
      FUN_004297b0(0);
      if (local_4c != (undefined4 *)0x0) {
        FUN_006ba940();
      }
      FUN_006bc0d0();
      FUN_0043fd30();
      ExceptionList = local_10;
      return 0;
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
    piVar15 = (int *)*puVar11;
    if (piVar15 != (int *)0x0) {
      *piVar15 = *piVar15 + 1;
    }
    FUN_006bc6a0("unknown class",piVar15);
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
    }
    local_8._0_1_ = 8;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,9);
  }
LAB_006a4158:
  FUN_004297b0(0);
  if (local_4c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

