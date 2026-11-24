
undefined4
CTclGlobalMethods__LAnd(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  code *pcVar10;
  undefined4 *puVar11;
  int *piVar12;
  bool bVar13;
  undefined8 uVar14;
  int local_54;
  char local_50;
  int *local_4c;
  int *local_48;
  undefined4 *local_44;
  uint local_40;
  int local_3c;
  int *local_34;
  int *local_30;
  int local_2c;
  int *local_28;
  int local_24;
  int local_20;
  undefined **local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070de05;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca72e8) &&
     (FUN_006cebf4(&DAT_00ca72e8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca72e8 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca72ec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::LAnd()";
    *(int *)(&DAT_00773650 + iVar8) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca72e8);
  }
  iVar8 = DAT_00ca72ec;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca72ec * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar9;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar3 == 0) {
    uVar14 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 != (int *)0x3) {
    FUN_006bc8f0(2);
    uVar9 = 1;
LAB_00659dd9:
    if ((local_50 != '\0') && (local_54 != 0)) {
      LOCK();
      DAT_00772dd4 = DAT_00772dd4 + -1;
      UNLOCK();
      Tcl_DeleteInterp(local_54);
    }
    if (DAT_00772dd4 == 0) {
      Tcl_Finalize();
    }
    local_8._0_1_ = 4;
    if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    if ((local_4c != (int *)0x0) && (*local_4c = *local_4c + -1, *local_4c == 0)) {
      FUN_006ba940();
    }
    FUN_0043fd30();
    ExceptionList = local_10;
    return uVar9;
  }
  FUN_004298b0(3,param_4);
  param_3 = (int *)0x0;
  if (local_3c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar11 = local_44;
    if (local_40 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar11 = local_44 + 1;
  }
  piVar12 = (int *)*puVar11;
  if (piVar12 != (int *)0x0) {
    *piVar12 = *piVar12 + 1;
  }
  local_18 = piVar12;
  if (local_3c < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar11 = local_44;
    if (local_40 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_40 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar11 = local_44 + 2;
  }
  piVar2 = (int *)*puVar11;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_14 = 0;
  pcVar10 = TclFreeObj_exref;
LAB_00659b5c:
  if (piVar12 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar8 = Tcl_ListObjLength(0,piVar12,&local_24);
    iVar3 = local_24;
    if (iVar8 != 0) {
      iVar3 = 0;
    }
  }
  if (local_14 < iVar3) {
    if (((piVar12 == (int *)0x0) ||
        (iVar3 = Tcl_ListObjIndex(0,piVar12,local_14,&local_28), piVar12 = local_28, iVar3 != 0)) ||
       (local_28 == (int *)0x0)) {
      local_1c = &PTR_0071ce50;
    }
    else {
      *local_28 = *local_28 + 1;
      local_1c = (undefined **)Tcl_GetStringFromObj(local_28,0);
      *piVar12 = *piVar12 + -1;
      if (*piVar12 < 1) {
        (*pcVar10)(piVar12);
      }
    }
    iVar3 = 0;
    do {
      local_20 = iVar3;
      if (piVar2 == (int *)0x0) {
        iVar8 = 0;
      }
      else {
        iVar4 = Tcl_ListObjLength(0,piVar2,&local_2c);
        iVar8 = local_2c;
        if (iVar4 != 0) {
          iVar8 = 0;
        }
      }
      if (iVar8 <= iVar3) goto LAB_00659d12;
      if (((piVar2 == (int *)0x0) ||
          (iVar3 = Tcl_ListObjIndex(0,piVar2,iVar3,&local_30), piVar12 = local_30, iVar3 != 0)) ||
         (local_30 == (int *)0x0)) {
        ppuVar5 = &PTR_0071ce50;
        ppuVar6 = local_1c;
      }
      else {
        *local_30 = *local_30 + 1;
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(local_30,0);
        *piVar12 = *piVar12 + -1;
        ppuVar6 = local_1c;
        if (*piVar12 < 1) {
          TclFreeObj(piVar12);
          ppuVar6 = local_1c;
        }
      }
      do {
        bVar1 = *(byte *)ppuVar6;
        bVar13 = bVar1 < *(byte *)ppuVar5;
        if (bVar1 != *(byte *)ppuVar5) {
LAB_00659c70:
          uVar7 = -(uint)bVar13 | 1;
          goto LAB_00659c75;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar6 + 1);
        bVar13 = bVar1 < *(byte *)((int)ppuVar5 + 1);
        if (bVar1 != *(byte *)((int)ppuVar5 + 1)) goto LAB_00659c70;
        ppuVar5 = (undefined **)((int)ppuVar5 + 2);
        ppuVar6 = (undefined **)((int)ppuVar6 + 2);
      } while (bVar1 != 0);
      uVar7 = 0;
LAB_00659c75:
      if (uVar7 == 0) goto LAB_00659c82;
      iVar3 = local_20 + 1;
    } while( true );
  }
  if (local_54 != 0) {
    if (param_3 == (int *)0x0) {
      Tcl_ResetResult(local_54);
    }
    else {
      Tcl_SetObjResult(local_54,param_3);
    }
  }
  uVar9 = 0;
  pcVar10 = TclFreeObj_exref;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, pcVar10 = TclFreeObj_exref, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
    (*pcVar10)(local_18);
  }
  if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 < 1)) {
    (*pcVar10)(param_3);
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_44 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  goto LAB_00659dd9;
LAB_00659c82:
  if (local_18 == (int *)0x0) {
    piVar12 = (int *)0x0;
  }
  else {
    iVar3 = Tcl_ListObjIndex(0,local_18,local_14,&local_34);
    if (iVar3 == 0) {
      piVar12 = local_34;
      if (local_34 != (int *)0x0) {
        *local_34 = *local_34 + 1;
      }
    }
    else {
      piVar12 = (int *)0x0;
    }
  }
  if (param_3 == (int *)0x0) {
    param_3 = (int *)Tcl_NewListObj(0,0);
    if (param_3 != (int *)0x0) {
      *param_3 = *param_3 + 1;
      goto LAB_00659ccc;
    }
    if (piVar12 == (int *)0x0) goto LAB_00659d12;
  }
  else {
LAB_00659ccc:
    if (1 < *param_3) {
      *param_3 = *param_3 + -1;
      param_3 = (int *)Tcl_DuplicateObj(param_3);
      *param_3 = *param_3 + 1;
    }
    if (piVar12 == (int *)0x0) goto LAB_00659d12;
    if (*piVar12 < 2) {
      Tcl_ListObjAppendElement(0,param_3,piVar12);
    }
    else {
      uVar9 = Tcl_DuplicateObj();
      Tcl_ListObjAppendElement(0,param_3,uVar9);
    }
  }
  *piVar12 = *piVar12 + -1;
  pcVar10 = TclFreeObj_exref;
  if (*piVar12 < 1) {
    TclFreeObj(piVar12);
    local_14 = local_14 + 1;
    piVar12 = local_18;
    goto LAB_00659b5c;
  }
LAB_00659d12:
  local_14 = local_14 + 1;
  pcVar10 = TclFreeObj_exref;
  piVar12 = local_18;
  goto LAB_00659b5c;
}

