
undefined4
CTclObjMethods__ObjFindNearestStorableCB
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  void *lp;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  BOOL BVar7;
  uint uVar8;
  uint uVar9;
  code *pcVar10;
  int *piVar11;
  float fVar12;
  float fVar13;
  undefined8 uVar14;
  int **ppiVar15;
  int local_5c;
  undefined4 *local_4c;
  uint local_48;
  int local_44;
  int local_34;
  int *local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  float local_20;
  int local_1c;
  uint local_18;
  bool local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712345;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c60) &&
     (FUN_006cebf4(&DAT_00ca7c60,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7c60 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7c64 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::ObjFindNearestStorableCB()";
    *(int *)(&DAT_00773650 + iVar5) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c60);
  }
  iVar5 = DAT_00ca7c64;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c64 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar4 == 0) {
    uVar14 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_1c = FUN_005c71c0(param_4,3,1);
  if (local_1c == 0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
LAB_006a4a9c:
    FUN_004297b0(0);
    if (local_4c != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  if (local_44 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_4c;
    if (local_48 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_48 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_4c + 2;
  }
  piVar2 = (int *)*puVar6;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  uVar8 = 0xffffffff;
  local_8 = CONCAT31(local_8._1_3_,5);
  uVar9 = 0;
  local_18 = 0xffffffff;
  local_28 = *(float *)(local_1c + 0xc);
  local_24 = *(undefined4 *)(local_1c + 0x36c);
  local_2c = *(float *)(local_1c + 0x10);
  local_20 = 1e+06;
  local_30 = piVar2;
  do {
    piVar11 = (int *)(DAT_0077244c + 0x488);
    if (uVar9 < 0x2000) {
      piVar11 = piVar11 + uVar9;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar8 = local_18;
    }
    iVar4 = *piVar11;
    fVar12 = local_20;
    uVar3 = local_18;
    if (((iVar4 != 0) && (iVar4 != local_1c)) && (((byte)*(undefined4 *)(iVar4 + 0x3d0) & 0xd) == 9)
       ) {
      iVar5 = FUN_005cb3a0(local_24);
      if (0x7f < iVar5) {
        fVar12 = *(float *)(iVar4 + 0x10) - local_2c;
        fVar13 = *(float *)(iVar4 + 0xc) - local_28;
        fVar12 = fVar12 * fVar12 + fVar13 * fVar13;
        FUN_0040b7e0();
        if (fVar12 < local_20) {
          ppiVar15 = &local_30;
          FUN_005c9cc0(ppiVar15);
          FUN_00555a00(ppiVar15);
          puVar6 = (undefined4 *)FUN_005c9cc0();
          piVar11 = (int *)Tcl_GetObjResult(*puVar6);
          if (piVar11 != (int *)0x0) {
            *piVar11 = *piVar11 + 1;
            iVar4 = Tcl_GetBooleanFromObj(0,piVar11,&local_34);
            local_11 = iVar4 != 1 && local_34 != 0;
            *piVar11 = *piVar11 + -1;
            if (*piVar11 < 1) {
              TclFreeObj(piVar11);
            }
            uVar8 = uVar9;
            uVar3 = uVar9;
            if (local_11 != false) goto LAB_006a48a0;
          }
        }
      }
      uVar8 = local_18;
      fVar12 = local_20;
      uVar3 = local_18;
    }
LAB_006a48a0:
    local_18 = uVar3;
    local_20 = fVar12;
    uVar9 = uVar9 + 1;
  } while ((int)uVar9 < 0x2000);
  if (uVar8 == 0xffffffff) {
    piVar11 = (int *)Tcl_NewIntObj(0);
    *piVar11 = *piVar11 + 1;
    iVar4 = *piVar11;
    if (local_5c != 0) {
      Tcl_SetObjResult(local_5c,piVar11);
      iVar4 = *piVar11;
    }
    *piVar11 = iVar4 + -1;
    if (iVar4 + -1 < 1) {
      TclFreeObj(piVar11);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 6;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,7);
    goto LAB_006a4917;
  }
  puVar6 = (undefined4 *)(DAT_0077244c + 0x488);
  if (uVar8 < 0x2000) {
    puVar6 = puVar6 + uVar8;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  lp = (void *)*puVar6;
  if (((lp == (void *)0x0) || (BVar7 = IsBadReadPtr(lp,0x10), BVar7 != 0)) ||
     ((*(int *)((int)lp + 8) != 0x616e4f62 ||
      ((DAT_00768398 != '\0' && (*(int *)((int)lp + 0xdc) == 0)))))) {
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 8;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,9);
    goto LAB_006a4a9c;
  }
  if (0x1fff < local_18) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar4 = FUN_005caf90();
  if (iVar4 == 0) {
    piVar11 = (int *)0x0;
  }
  else {
    piVar11 = (int *)Tcl_NewStringObj(iVar4,0xffffffff);
    *piVar11 = *piVar11 + 1;
  }
  if (local_5c == 0) {
    pcVar10 = TclFreeObj_exref;
    if (piVar11 != (int *)0x0) goto LAB_006a4a60;
  }
  else if (piVar11 == (int *)0x0) {
    Tcl_ResetResult(local_5c);
    pcVar10 = TclFreeObj_exref;
  }
  else {
    Tcl_SetObjResult(local_5c,piVar11);
LAB_006a4a60:
    *piVar11 = *piVar11 + -1;
    pcVar10 = TclFreeObj_exref;
    if (*piVar11 < 1) {
      TclFreeObj(piVar11);
    }
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    (*pcVar10)(piVar2);
  }
  local_8._0_1_ = 10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xb);
LAB_006a4917:
  FUN_004297b0(0);
  if (local_4c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

