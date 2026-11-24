
undefined4
CTclObjMethods__ObjFindNearestStorable
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  void *lp;
  int iVar4;
  int iVar5;
  BOOL BVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  int *piVar11;
  float fVar12;
  float fVar13;
  undefined8 uVar14;
  int local_44;
  int local_34;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007122fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c58) &&
     (FUN_006cebf4(&DAT_00ca7c58,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7c58 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca7c5c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::ObjFindNearestStorable()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c58);
  }
  iVar7 = DAT_00ca7c5c;
  uVar3 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c5c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar3;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar14 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  iVar4 = FUN_005c71c0(param_4,2,1);
  if (iVar4 == 0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
LAB_006a455f:
    FUN_004297b0(0);
    if (local_34 != 0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  fVar1 = *(float *)(iVar4 + 0xc);
  uVar8 = 0xffffffff;
  uVar3 = *(undefined4 *)(iVar4 + 0x36c);
  uVar9 = 0;
  fVar2 = *(float *)(iVar4 + 0x10);
  local_14 = 1e+06;
  do {
    piVar11 = (int *)(DAT_0077244c + 0x488);
    if (uVar9 < 0x2000) {
      piVar11 = piVar11 + uVar9;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar7 = *piVar11;
    if ((((iVar7 != 0) && (iVar7 != iVar4)) && (((byte)*(undefined4 *)(iVar7 + 0x3d0) & 0xd) == 9))
       && (iVar5 = FUN_005cb3a0(uVar3), 0 < iVar5)) {
      fVar12 = *(float *)(iVar7 + 0x10) - fVar2;
      fVar13 = *(float *)(iVar7 + 0xc) - fVar1;
      fVar12 = fVar12 * fVar12 + fVar13 * fVar13;
      FUN_0040b7e0();
      if (fVar12 < local_14) {
        uVar8 = uVar9;
        local_14 = fVar12;
      }
    }
    uVar9 = uVar9 + 1;
  } while ((int)uVar9 < 0x2000);
  if (uVar8 == 0xffffffff) {
    piVar11 = (int *)Tcl_NewIntObj(0);
    *piVar11 = *piVar11 + 1;
    iVar4 = *piVar11;
    if (local_44 != 0) {
      Tcl_SetObjResult(local_44,piVar11);
      iVar4 = *piVar11;
    }
    *piVar11 = iVar4 + -1;
    if (iVar4 + -1 < 1) {
      TclFreeObj(piVar11);
    }
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
    goto LAB_006a440d;
  }
  puVar10 = (undefined4 *)(DAT_0077244c + 0x488);
  if (uVar8 < 0x2000) {
    puVar10 = puVar10 + uVar8;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  lp = (void *)*puVar10;
  if (((lp == (void *)0x0) || (BVar6 = IsBadReadPtr(lp,0x10), BVar6 != 0)) ||
     ((*(int *)((int)lp + 8) != 0x616e4f62 ||
      ((DAT_00768398 != '\0' && (*(int *)((int)lp + 0xdc) == 0)))))) {
    local_8._0_1_ = 7;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,8);
    goto LAB_006a455f;
  }
  if (0x1fff < uVar8) {
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
  if (local_44 == 0) {
    if (piVar11 != (int *)0x0) goto LAB_006a4525;
  }
  else if (piVar11 == (int *)0x0) {
    Tcl_ResetResult(local_44);
  }
  else {
    Tcl_SetObjResult(local_44,piVar11);
LAB_006a4525:
    *piVar11 = *piVar11 + -1;
    if (*piVar11 < 1) {
      TclFreeObj(piVar11);
    }
  }
  local_8._0_1_ = 9;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,10);
LAB_006a440d:
  FUN_004297b0(0);
  if (local_34 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

