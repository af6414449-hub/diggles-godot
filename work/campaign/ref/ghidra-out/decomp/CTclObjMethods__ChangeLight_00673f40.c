
undefined4
CTclObjMethods__ChangeLight(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  float fVar8;
  undefined8 uVar9;
  undefined4 *local_3c;
  uint local_38;
  int local_34;
  undefined1 local_30 [4];
  double local_2c;
  int *local_24;
  int *local_20;
  int *local_1c;
  code *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007108bd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = (code *)0x0;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca74a8) &&
     (FUN_006cebf4(&DAT_00ca74a8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca74a8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca74ac = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::ChangeLight()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca74a8);
  }
  iVar5 = DAT_00ca74ac;
  local_24 = &DAT_00ca74ac;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca74ac * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,5,1);
  local_14 = iVar2;
  if (iVar2 == 0) {
    uVar7 = 1;
    goto LAB_006744ce;
  }
  if (local_34 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar3 = local_3c;
    if (local_38 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_38 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar3 = local_3c + 2;
  }
  local_20 = (int *)*puVar3;
  if (local_20 != (int *)0x0) {
    *local_20 = *local_20 + 1;
  }
  local_1c = local_20;
  if (local_34 < 5) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar3 = local_3c;
    if (local_38 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_38 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar3 = local_3c + 4;
  }
  piVar1 = (int *)*puVar3;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  puVar3 = (undefined4 *)FUN_006bafe0(local_30);
  *(undefined4 *)(iVar2 + 0x280) = *puVar3;
  *(undefined4 *)(iVar2 + 0x284) = puVar3[1];
  *(undefined4 *)(iVar2 + 0x288) = puVar3[2];
  if (local_34 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar3 = local_3c;
    if (local_38 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_38 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar3 = local_3c + 3;
  }
  local_1c = (int *)*puVar3;
  if (local_1c == (int *)0x0) {
LAB_006741fc:
    fVar8 = 0.1;
    pcVar4 = local_18;
    piVar6 = local_24;
  }
  else {
    *local_1c = *local_1c + 1;
    iVar2 = Tcl_GetDoubleFromObj(0,local_1c,&local_2c);
    if ((iVar2 == 1) || ((float)local_2c < 0.1)) goto LAB_006741fc;
    if (local_34 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_3c + 3;
    }
    piVar6 = (int *)*puVar3;
    if (piVar6 == (int *)0x0) {
      fVar8 = 0.0;
      pcVar4 = (code *)0x1;
    }
    else {
      *piVar6 = *piVar6 + 1;
      local_18 = (code *)0x1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar6,&local_2c);
      pcVar4 = local_18;
      if (iVar2 == 1) {
        fVar8 = 0.0;
      }
      else {
        fVar8 = (float)local_2c;
      }
    }
  }
  *(float *)(local_14 + 0x290) = fVar8;
  local_18 = TclFreeObj_exref;
  if (((((uint)pcVar4 & 1) != 0) && (piVar6 != (int *)0x0)) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)
     ) {
    TclFreeObj(piVar6);
  }
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c < 1)) {
    (*local_18)(local_1c);
  }
  if ((piVar1 == (int *)0x0) ||
     (iVar2 = Tcl_ListObjIndex(0,piVar1,0,&local_1c), piVar6 = local_1c, iVar2 != 0)) {
    piVar6 = (int *)0x0;
LAB_006742b3:
    *(undefined4 *)(local_14 + 0x298) = 0;
    if (piVar6 != (int *)0x0) goto LAB_006742cf;
  }
  else {
    if (local_1c == (int *)0x0) goto LAB_006742b3;
    *local_1c = *local_1c + 1;
    iVar2 = Tcl_GetDoubleFromObj(0,local_1c,&local_2c);
    if (iVar2 == 1) {
      *(undefined4 *)(local_14 + 0x298) = 0;
    }
    else {
      *(int *)(local_14 + 0x298) = (int)((float)local_2c * 31.0);
    }
LAB_006742cf:
    *piVar6 = *piVar6 + -1;
    if (*piVar6 < 1) {
      (*local_18)(piVar6);
    }
  }
  if ((piVar1 == (int *)0x0) ||
     (iVar2 = Tcl_ListObjIndex(0,piVar1,1,&local_1c), piVar6 = local_1c, iVar2 != 0)) {
    piVar6 = (int *)0x0;
LAB_00674346:
    *(undefined4 *)(local_14 + 0x29c) = 0;
    if (piVar6 != (int *)0x0) goto LAB_00674362;
  }
  else {
    if (local_1c == (int *)0x0) goto LAB_00674346;
    *local_1c = *local_1c + 1;
    iVar2 = Tcl_GetDoubleFromObj(0,local_1c,&local_2c);
    if (iVar2 == 1) {
      *(undefined4 *)(local_14 + 0x29c) = 0;
    }
    else {
      *(int *)(local_14 + 0x29c) = (int)((float)local_2c * 31.0);
    }
LAB_00674362:
    *piVar6 = *piVar6 + -1;
    if (*piVar6 < 1) {
      (*local_18)(piVar6);
    }
  }
  if ((piVar1 == (int *)0x0) ||
     (iVar2 = Tcl_ListObjIndex(0,piVar1,2,&local_1c), piVar6 = local_1c, iVar2 != 0)) {
    piVar6 = (int *)0x0;
LAB_006743d9:
    *(undefined4 *)(local_14 + 0x2a0) = 0;
    if (piVar6 != (int *)0x0) goto LAB_006743f5;
  }
  else {
    if (local_1c == (int *)0x0) goto LAB_006743d9;
    *local_1c = *local_1c + 1;
    iVar2 = Tcl_GetDoubleFromObj(0,local_1c,&local_2c);
    if (iVar2 == 1) {
      *(undefined4 *)(local_14 + 0x2a0) = 0;
    }
    else {
      *(int *)(local_14 + 0x2a0) = (int)((float)local_2c * 31.0);
    }
LAB_006743f5:
    *piVar6 = *piVar6 + -1;
    if (*piVar6 < 1) {
      (*local_18)(piVar6);
    }
  }
  pcVar4 = local_18;
  if (param_3 == 6) {
    if (local_34 < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_3c + 5;
    }
    piVar6 = (int *)*puVar3;
    if (piVar6 == (int *)0x0) {
      *(undefined4 *)(local_14 + 0x294) = 0;
      pcVar4 = local_18;
    }
    else {
      *piVar6 = *piVar6 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar6,&local_2c);
      pcVar4 = local_18;
      if (iVar2 == 1) {
        fVar8 = 0.0;
      }
      else {
        fVar8 = (float)local_2c;
      }
      *(float *)(local_14 + 0x294) = fVar8;
      *piVar6 = *piVar6 + -1;
      if (*piVar6 < 1) {
        (*local_18)(piVar6);
      }
    }
  }
  uVar7 = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar4)(piVar1);
  }
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 < 1)) {
    (*pcVar4)(local_20);
  }
LAB_006744ce:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_3c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

