
undefined4
CTclGlobalMethods__LRem(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  int *piVar8;
  code *pcVar9;
  undefined8 uVar10;
  char *pcVar11;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f5ed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7440) &&
     (FUN_006cebf4(&DAT_00ca7440,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7440 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7444 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::LRem()";
    *(int *)(&DAT_00773650 + iVar4) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7440);
  }
  iVar4 = DAT_00ca7444;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7444 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar6;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar1 == 0) {
    uVar10 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 != 3) {
    FUN_006bc8f0(2);
    uVar6 = 1;
    goto LAB_00665003;
  }
  if (local_20 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar2 = local_28;
    if (local_24 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar2 = local_28 + 1;
  }
  if (local_38 == 0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)Tcl_ObjGetVar2(local_38,*puVar2,0,0);
    if (piVar8 != (int *)0x0) {
      *piVar8 = *piVar8 + 1;
    }
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (piVar8 == (int *)0x0) {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar2 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar2 = local_28 + 1;
    }
    piVar5 = (int *)*puVar2;
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
    }
    pcVar11 = "unknown variable";
LAB_00664fdf:
    FUN_006bc6a0(pcVar11,piVar5);
    uVar6 = 1;
    pcVar9 = TclFreeObj_exref;
  }
  else {
    if (local_20 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar2 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar2 = local_28 + 2;
    }
    piVar5 = (int *)*puVar2;
    if (piVar5 == (int *)0x0) {
      uVar7 = 0;
    }
    else {
      *piVar5 = *piVar5 + 1;
      iVar1 = Tcl_GetIntFromObj(0,piVar5,&local_14);
      *piVar5 = *piVar5 + -1;
      uVar7 = -(uint)(iVar1 != 1) & (uint)local_14;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
      if ((int)uVar7 < 0) {
        puVar2 = (undefined4 *)FUN_004295e0(2);
        piVar5 = (int *)*puVar2;
        if (piVar5 != (int *)0x0) {
          *piVar5 = *piVar5 + 1;
        }
        pcVar11 = "index is negative";
        goto LAB_00664fdf;
      }
    }
    iVar1 = Tcl_ListObjLength(0,piVar8,&local_14);
    piVar5 = local_14;
    if (iVar1 != 0) {
      piVar5 = (int *)0x0;
    }
    if ((int)piVar5 <= (int)uVar7) {
      puVar2 = (undefined4 *)FUN_004295e0(2);
      piVar5 = (int *)*puVar2;
      if (piVar5 != (int *)0x0) {
        *piVar5 = *piVar5 + 1;
      }
      pcVar11 = "index to high";
      goto LAB_00664fdf;
    }
    iVar1 = Tcl_ListObjIndex(0,piVar8,uVar7,&local_14);
    if (iVar1 == 0) {
      if (1 < *piVar8) {
        *piVar8 = *piVar8 + -1;
        piVar8 = (int *)Tcl_DuplicateObj(piVar8);
        *piVar8 = *piVar8 + 1;
      }
      Tcl_ListObjReplace(0,piVar8,uVar7,1,0,0);
      piVar5 = local_14;
      if (local_14 != (int *)0x0) {
        *local_14 = *local_14 + 1;
      }
    }
    else {
      piVar5 = (int *)0x0;
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    piVar3 = (int *)FUN_004295e0(1);
    if (local_38 == 0) {
LAB_00665125:
      uVar6 = 0;
      pcVar9 = TclFreeObj_exref;
      if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, pcVar9 = TclFreeObj_exref, *piVar5 < 1)
         ) {
        TclFreeObj(piVar5);
      }
    }
    else {
      if ((*piVar3 != 0) && (iVar1 = Tcl_ObjSetVar2(local_38,*piVar3,0,piVar8,0x200), iVar1 == 0)) {
        uVar6 = Tcl_GetStringResult(local_38);
        uVar6 = FUN_006b9200(uVar6);
        FUN_006b91c0(uVar6);
      }
      if (local_38 == 0) goto LAB_00665125;
      if (piVar5 != (int *)0x0) {
        Tcl_SetObjResult(local_38,piVar5);
        goto LAB_00665125;
      }
      Tcl_ResetResult(local_38);
      uVar6 = 0;
      pcVar9 = TclFreeObj_exref;
    }
  }
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
    (*pcVar9)(piVar8);
  }
LAB_00665003:
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

