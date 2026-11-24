
undefined4
CTclObjMethods__ObjFindNextNearestType
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined4 *puVar6;
  BOOL BVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  float fVar11;
  double dVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  int local_68;
  undefined4 *local_58;
  uint local_54;
  int local_50;
  double local_4c;
  undefined4 *local_44;
  int *local_40;
  undefined8 local_3c;
  float local_34;
  float local_30;
  int local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071225d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c48) &&
     (FUN_006cebf4(&DAT_00ca7c48,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7c48 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca7c4c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclObjMethods::ObjFindNextNearestType()";
    *(int *)(&DAT_00773650 + iVar8) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c48);
  }
  iVar8 = DAT_00ca7c4c;
  local_44 = &DAT_00ca7c4c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c4c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar4 == 0) {
    uVar14 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_20 = (int *)FUN_005c71c0(param_4,3,1);
  if (local_20 == (int *)0x0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
LAB_006a34b7:
    FUN_004297b0(0);
    if (local_58 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  if (local_50 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_58;
    if (local_54 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_54 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_58 + 2;
  }
  piVar2 = (int *)*puVar6;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_8._0_1_ = 5;
  local_40 = piVar2;
  local_28 = piVar2;
  if (piVar2 == (int *)0x0) {
    ppuVar5 = &PTR_0071ce50;
  }
  else {
    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
  }
  FUN_006b8fb0(ppuVar5);
  local_8._0_1_ = 6;
  local_2c = FUN_006bba50(&local_28,&DAT_00722ca4,"dummy","gnome","monster","material",&DAT_0072bdb8
                          ,"production","energy","protection","store","transport","elevator",
                          &DAT_0072bde8,&DAT_00727b60,0);
  if (local_2c == -1) {
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    FUN_006bc6a0("unknown type",piVar2);
    local_8 = CONCAT31(local_8._1_3_,7);
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 8;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,9);
    goto LAB_006a34b7;
  }
  dVar12 = 1.7976931348623157e+308;
  if (param_3 == 4) {
    puVar6 = (undefined4 *)FUN_004295e0(3);
    piVar2 = (int *)*puVar6;
    if (piVar2 == (int *)0x0) {
      dVar12 = 0.0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar4 = Tcl_GetDoubleFromObj(0,piVar2,&local_4c);
      if (iVar4 == 1) {
        fVar11 = 0.0;
      }
      else {
        fVar11 = (float)local_4c;
      }
      *piVar2 = *piVar2 + -1;
      local_3c = (double)fVar11;
      dVar12 = local_3c;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
        dVar12 = local_3c;
      }
    }
  }
  uVar9 = 0;
  local_18 = (float)dVar12;
  uVar13 = (ulonglong)(uint)local_18;
  local_14 = 0xffffffff;
  local_24 = (int *)local_20[0xdb];
  local_30 = (float)local_20[3];
  local_34 = (float)local_20[4];
  local_3c = (double)CONCAT44(local_18,(undefined4)local_3c);
  do {
    puVar6 = (undefined4 *)(DAT_0077244c + 0x488);
    if (uVar9 < 0x2000) {
      puVar6 = puVar6 + uVar9;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar13 = (ulonglong)(uint)local_18;
    }
    piVar2 = (int *)*puVar6;
    fVar11 = local_18;
    uVar3 = local_14;
    if ((((piVar2 != (int *)0x0) && (piVar2 != local_20)) && (piVar2[0x3a] == local_2c)) &&
       (((byte)piVar2[0xf4] & 5) == 1)) {
      iVar4 = FUN_005cb3a0(local_24);
      if (0 < iVar4) {
        uVar13 = (ulonglong)
                 (uint)(((float)piVar2[4] - local_34) * ((float)piVar2[4] - local_34) +
                       ((float)piVar2[3] - local_30) * ((float)piVar2[3] - local_30));
        FUN_0040b7e0();
        fVar11 = (float)uVar13;
        uVar3 = uVar9;
        if ((float)uVar13 < local_18) goto LAB_006a3781;
      }
      uVar13 = (ulonglong)(uint)local_18;
      fVar11 = local_18;
      uVar3 = local_14;
    }
LAB_006a3781:
    local_14 = uVar3;
    local_18 = fVar11;
    uVar3 = local_14;
    piVar2 = local_40;
    uVar9 = uVar9 + 1;
  } while ((int)uVar9 < 0x2000);
  if ((local_3c._4_4_ <= (float)uVar13) || (local_14 == 0xffffffff)) {
    piVar10 = (int *)Tcl_NewIntObj(0);
    *piVar10 = *piVar10 + 1;
    iVar4 = *piVar10;
    if (local_68 != 0) {
      Tcl_SetObjResult(local_68,piVar10);
      iVar4 = *piVar10;
    }
    *piVar10 = iVar4 + -1;
    if (iVar4 + -1 < 1) {
      TclFreeObj(piVar10);
    }
    local_8 = CONCAT31(local_8._1_3_,10);
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 0xb;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,0xc);
    goto LAB_006a3a35;
  }
  local_40 = (int *)(DAT_0077244c + 0x488);
  if (local_14 < 0x2000) {
    local_40 = local_40 + local_14;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  local_40 = (int *)*local_40;
  if ((((local_40 == (int *)0x0) || (BVar7 = IsBadReadPtr(local_40,0x10), BVar7 != 0)) ||
      (local_40[2] != 0x616e4f62)) || ((DAT_00768398 != '\0' && (local_40[0x37] == 0)))) {
    local_8 = CONCAT31(local_8._1_3_,0xd);
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 0xe;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,0xf);
    goto LAB_006a34b7;
  }
  local_40 = (int *)(DAT_0077244c + 0x488);
  local_20 = (int *)0x0;
  if (0x1fff < uVar3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar4 = FUN_005caf90();
  if (iVar4 == 0) {
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = (int *)Tcl_NewStringObj(iVar4,0xffffffff);
    *piVar10 = *piVar10 + 1;
  }
  local_24 = piVar10;
  FUN_006bb930(&local_24);
  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
    TclFreeObj(piVar10);
  }
  piVar10 = (int *)(DAT_0077244c + 0x488);
  if (local_14 < 0x2000) {
    piVar10 = piVar10 + local_14;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar4 = *(int *)(*(int *)(*piVar10 + 0xd4) + 0xc) + 0xc;
  if (iVar4 == 0) {
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = (int *)Tcl_NewStringObj(iVar4,0xffffffff);
    *piVar10 = *piVar10 + 1;
  }
  local_24 = piVar10;
  FUN_006bb930(&local_24);
  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
    TclFreeObj(piVar10);
  }
  piVar10 = local_20;
  if (local_68 == 0) {
LAB_006a392c:
    if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
      TclFreeObj(piVar10);
    }
  }
  else {
    if (local_20 != (int *)0x0) {
      Tcl_SetObjResult(local_68,local_20);
      goto LAB_006a392c;
    }
    Tcl_ResetResult(local_68);
  }
  local_8 = CONCAT31(local_8._1_3_,0x10);
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
  local_8._0_1_ = 0x11;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x12);
LAB_006a3a35:
  FUN_004297b0(0);
  if (local_58 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

