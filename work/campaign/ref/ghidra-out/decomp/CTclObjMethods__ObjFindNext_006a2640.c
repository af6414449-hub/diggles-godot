
undefined4
CTclObjMethods__ObjFindNext(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  void *lp;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  BOOL BVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  code *pcVar13;
  float fVar14;
  double dVar15;
  float fVar16;
  undefined8 uVar17;
  int local_60;
  undefined4 *local_50;
  uint local_4c;
  int local_48;
  double local_44;
  int *local_3c;
  undefined4 *local_38;
  int *local_34;
  undefined8 local_30;
  float local_28;
  undefined4 local_24;
  int local_20;
  int *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007121b5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c38) &&
     (FUN_006cebf4(&DAT_00ca7c38,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7c38 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca7c3c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::ObjFindNext()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c38);
  }
  iVar7 = DAT_00ca7c3c;
  local_38 = &DAT_00ca7c3c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c3c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar17 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar17;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_18 = FUN_005c71c0(param_4,3,1);
  if (local_18 == 0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
LAB_006a2bd2:
    FUN_004297b0(0);
    if (local_50 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  if (local_48 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_50;
    if (local_4c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_4c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_50 + 2;
  }
  piVar12 = (int *)*puVar6;
  if (piVar12 != (int *)0x0) {
    *piVar12 = *piVar12 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  local_3c = piVar12;
  local_34 = piVar12;
  if (piVar12 == (int *)0x0) {
    ppuVar5 = &PTR_0071ce50;
  }
  else {
    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
  }
  FUN_006b8fb0(ppuVar5);
  iVar4 = DAT_00772478;
  cVar3 = FUN_006037d0(&local_1c,&local_14);
  if (cVar3 == '\0') {
    iVar4 = 0;
  }
  else {
    if (*(uint *)(iVar4 + 0x801c) <= local_14) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar4 = *(int *)(*(int *)(iVar4 + 0x8018) + local_14 * 4);
  }
  local_8._0_1_ = 6;
  local_20 = iVar4;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  if (iVar4 == 0) {
    if (local_48 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_50;
      if (local_4c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_4c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_50 + 2;
    }
    piVar8 = (int *)*puVar6;
    if (piVar8 != (int *)0x0) {
      *piVar8 = *piVar8 + 1;
    }
    FUN_006bc6a0("unknown class",piVar8);
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    local_8._0_1_ = 7;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,8);
    goto LAB_006a2bd2;
  }
  dVar15 = 1.7976931348623157e+308;
  if (param_3 == 4) {
    puVar6 = (undefined4 *)FUN_004295e0(3);
    piVar12 = (int *)*puVar6;
    if (piVar12 == (int *)0x0) {
      dVar15 = 0.0;
    }
    else {
      *piVar12 = *piVar12 + 1;
      iVar4 = Tcl_GetDoubleFromObj(0,piVar12,&local_44);
      if (iVar4 == 1) {
        fVar14 = 0.0;
      }
      else {
        fVar14 = (float)local_44;
      }
      *piVar12 = *piVar12 + -1;
      local_30 = (double)fVar14;
      dVar15 = local_30;
      if (*piVar12 < 1) {
        TclFreeObj(piVar12);
        dVar15 = local_30;
      }
    }
  }
  uVar10 = 0xffffffff;
  uVar11 = 0;
  local_1c = (int *)(float)dVar15;
  local_14 = 0xffffffff;
  local_24 = *(undefined4 *)(local_18 + 0x36c);
  local_28 = *(float *)(local_18 + 0xc);
  local_30 = (double)CONCAT44(*(undefined4 *)(local_18 + 0x10),(undefined4)local_30);
  do {
    piVar12 = (int *)(DAT_0077244c + 0x488);
    if (uVar11 < 0x2000) {
      piVar12 = piVar12 + uVar11;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar10 = local_14;
    }
    iVar4 = *piVar12;
    piVar12 = local_1c;
    uVar2 = local_14;
    if ((((iVar4 != 0) && (iVar4 != local_18)) && (*(int *)(iVar4 + 0xd4) == local_20)) &&
       (((byte)*(undefined4 *)(iVar4 + 0x3d0) & 7) == 1)) {
      iVar7 = FUN_005cb3a0(local_24);
      if (0 < iVar7) {
        fVar14 = *(float *)(iVar4 + 0x10) - local_30._4_4_;
        fVar16 = *(float *)(iVar4 + 0xc) - local_28;
        piVar12 = (int *)(fVar14 * fVar14 + fVar16 * fVar16);
        FUN_0040b7e0();
        uVar10 = uVar11;
        uVar2 = uVar11;
        if ((float)piVar12 < (float)local_1c) goto LAB_006a29cc;
      }
      uVar10 = local_14;
      piVar12 = local_1c;
      uVar2 = local_14;
    }
LAB_006a29cc:
    local_14 = uVar2;
    local_1c = piVar12;
    piVar12 = local_34;
    uVar11 = uVar11 + 1;
  } while ((int)uVar11 < 0x2000);
  if (uVar10 == 0xffffffff) {
    piVar8 = (int *)Tcl_NewIntObj(0);
    *piVar8 = *piVar8 + 1;
    iVar4 = *piVar8;
    if (local_60 != 0) {
      Tcl_SetObjResult(local_60,piVar8);
      iVar4 = *piVar8;
    }
    *piVar8 = iVar4 + -1;
    if (iVar4 + -1 < 1) {
      TclFreeObj(piVar8);
    }
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    local_8._0_1_ = 9;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,10);
    goto LAB_006a2a4b;
  }
  puVar6 = (undefined4 *)(DAT_0077244c + 0x488);
  if (uVar10 < 0x2000) {
    puVar6 = puVar6 + uVar10;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  lp = (void *)*puVar6;
  if (((lp == (void *)0x0) || (BVar9 = IsBadReadPtr(lp,0x10), BVar9 != 0)) ||
     ((*(int *)((int)lp + 8) != 0x616e4f62 ||
      ((DAT_00768398 != '\0' && (*(int *)((int)lp + 0xdc) == 0)))))) {
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    local_8._0_1_ = 0xb;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,0xc);
    goto LAB_006a2bd2;
  }
  if (0x1fff < local_14) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar4 = FUN_005caf90();
  if (iVar4 == 0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)Tcl_NewStringObj(iVar4,0xffffffff);
    *piVar8 = *piVar8 + 1;
  }
  if (local_60 == 0) {
    pcVar13 = TclFreeObj_exref;
    if (piVar8 != (int *)0x0) goto LAB_006a2b94;
  }
  else if (piVar8 == (int *)0x0) {
    Tcl_ResetResult(local_60);
    pcVar13 = TclFreeObj_exref;
  }
  else {
    Tcl_SetObjResult(local_60,piVar8);
LAB_006a2b94:
    *piVar8 = *piVar8 + -1;
    pcVar13 = TclFreeObj_exref;
    if (*piVar8 < 1) {
      TclFreeObj(piVar8);
    }
  }
  if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
    (*pcVar13)(piVar12);
  }
  local_8._0_1_ = 0xd;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xe);
LAB_006a2a4b:
  FUN_004297b0(0);
  if (local_50 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

