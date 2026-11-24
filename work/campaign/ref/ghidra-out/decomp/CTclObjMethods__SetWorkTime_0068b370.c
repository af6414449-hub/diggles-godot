
undefined4
CTclObjMethods__SetWorkTime
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  float fVar8;
  undefined8 uVar9;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  undefined4 local_20;
  float fStack_1c;
  undefined4 local_18;
  float fStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070aaed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7860) &&
     (FUN_006cebf4(&DAT_00ca7860,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7860 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7864 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::SetWorkTime()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7860);
  }
  iVar5 = DAT_00ca7864;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7864 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_005c71c0(param_4,4,1);
  if (iVar3 == 0) {
    uVar7 = 1;
    goto LAB_0068b6d9;
  }
  if (local_28 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_30 + 2;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if (local_28 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_2c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_30 + 3;
  }
  piVar2 = (int *)*puVar6;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  fStack_14 = *(float *)(iVar3 + 0x354);
  fStack_1c = *(float *)(iVar3 + 0x358);
  if (piVar1 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
  }
  else {
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  iVar5 = __stricmp((char *)ppuVar4,"start");
  if (iVar5 == 0) {
    if (piVar2 != (int *)0x0) {
      iVar5 = Tcl_GetDoubleFromObj(0,piVar2,&local_18);
      if (iVar5 == 1) {
        *(undefined4 *)(iVar3 + 0x354) = 0;
        fVar8 = fStack_1c;
LAB_0068b6aa:
        *(float *)(iVar3 + 0x358) = fVar8;
      }
      else {
        fStack_14 = (float)(double)CONCAT44(fStack_14,local_18);
        fVar8 = fStack_1c;
LAB_0068b607:
        *(float *)(iVar3 + 0x354) = fStack_14;
        *(float *)(iVar3 + 0x358) = fVar8;
        if (piVar2 == (int *)0x0) goto LAB_0068b6c3;
      }
      goto LAB_0068b6b2;
    }
    *(undefined4 *)(iVar3 + 0x354) = 0;
    *(float *)(iVar3 + 0x358) = fStack_1c;
  }
  else {
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    iVar5 = __stricmp((char *)ppuVar4,"duration");
    if (iVar5 == 0) {
      if (piVar2 == (int *)0x0) {
        *(float *)(iVar3 + 0x354) = fStack_14;
        *(undefined4 *)(iVar3 + 0x358) = 0;
      }
      else {
        iVar5 = Tcl_GetDoubleFromObj(0,piVar2,&local_20);
        if (iVar5 != 1) {
          fVar8 = (float)(double)CONCAT44(fStack_1c,local_20);
          goto LAB_0068b607;
        }
        *(float *)(iVar3 + 0x354) = fStack_14;
        *(undefined4 *)(iVar3 + 0x358) = 0;
LAB_0068b6b2:
        *piVar2 = *piVar2 + -1;
        if (*piVar2 < 1) {
          TclFreeObj(piVar2);
        }
      }
    }
    else {
      fStack_14 = 0.0;
      if (piVar1 != (int *)0x0) {
        iVar5 = Tcl_GetDoubleFromObj(0,piVar1,&local_20);
        if (iVar5 == 1) {
          fStack_14 = 0.0;
        }
        else {
          fStack_14 = (float)(double)CONCAT44(fStack_1c,local_20);
        }
      }
      if (piVar2 != (int *)0x0) {
        iVar5 = Tcl_GetDoubleFromObj(0,piVar2,&local_20);
        *(float *)(iVar3 + 0x354) = fStack_14;
        if (iVar5 != 1) {
          fVar8 = (float)(double)CONCAT44(fStack_1c,local_20);
          goto LAB_0068b6aa;
        }
        *(undefined4 *)(iVar3 + 0x358) = 0;
        goto LAB_0068b6b2;
      }
      *(float *)(iVar3 + 0x354) = fStack_14;
      *(undefined4 *)(iVar3 + 0x358) = 0;
    }
  }
LAB_0068b6c3:
  uVar7 = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_0068b6d9:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

