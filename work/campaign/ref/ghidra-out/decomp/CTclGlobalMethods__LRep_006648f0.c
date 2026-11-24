
undefined4
CTclGlobalMethods__LRep(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  code *pcVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f595;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7438) &&
     (FUN_006cebf4(&DAT_00ca7438,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7438 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca743c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::LRep()";
    *(int *)(&DAT_00773650 + iVar4) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7438);
  }
  iVar4 = DAT_00ca743c;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca743c * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar8;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar1 == 0) {
    uVar9 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar3 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar3 != (int *)&DAT_00000004) {
    FUN_006bc8f0(3);
    uVar8 = 1;
    goto LAB_00664cb3;
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
    local_14 = (int *)0x0;
  }
  else {
    local_14 = (int *)Tcl_ObjGetVar2(local_38,*puVar2,0,0);
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
  }
  piVar3 = local_14;
  local_8 = CONCAT31(local_8._1_3_,3);
  if (local_14 == (int *)0x0) {
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
    FUN_006bc6a0("unknown variable",piVar5);
    uVar8 = 1;
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
      piVar7 = (int *)0x0;
      param_3 = (int *)0x0;
    }
    else {
      *piVar5 = *piVar5 + 1;
      iVar1 = Tcl_GetIntFromObj(0,piVar5,&param_3);
      *piVar5 = *piVar5 + -1;
      piVar7 = (int *)(-(uint)(iVar1 != 1) & (uint)param_3);
      param_3 = piVar7;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
    }
    iVar1 = Tcl_ListObjLength(0,piVar3,&local_18);
    piVar5 = local_18;
    if (iVar1 != 0) {
      piVar5 = (int *)0x0;
    }
    if ((int)piVar7 < (int)piVar5) {
      puVar2 = (undefined4 *)FUN_004295e0(3);
      piVar7 = param_3;
      piVar5 = (int *)*puVar2;
      if (piVar5 != (int *)0x0) {
        *piVar5 = *piVar5 + 1;
      }
      iVar1 = Tcl_ListObjIndex(0,piVar3,param_3,&local_18);
      if (iVar1 == 0) {
        pcVar6 = Tcl_DuplicateObj_exref;
        param_3 = piVar5;
        if (1 < *piVar3) {
          *piVar3 = *piVar3 + -1;
          piVar3 = (int *)Tcl_DuplicateObj(piVar3);
          pcVar6 = Tcl_DuplicateObj_exref;
          *piVar3 = *piVar3 + 1;
          local_14 = piVar3;
        }
        if ((param_3 != (int *)0x0) && (1 < *param_3)) {
          param_3 = (int *)(*pcVar6)(param_3);
        }
        Tcl_ListObjReplace(0,piVar3,piVar7,1,1,&param_3);
        if (local_18 != (int *)0x0) {
          *local_18 = *local_18 + 1;
        }
        pcVar6 = TclFreeObj_exref;
        if ((piVar5 != (int *)0x0) &&
           (*piVar5 = *piVar5 + -1, pcVar6 = TclFreeObj_exref, *piVar5 < 1)) {
          TclFreeObj(piVar5);
        }
        if (local_18 != (int *)0x0) {
          *local_18 = *local_18 + -1;
          iVar1 = *local_18;
          piVar5 = local_18;
          goto joined_r0x00664c36;
        }
      }
      else if (piVar5 != (int *)0x0) {
        *piVar5 = *piVar5 + -1;
        iVar1 = *piVar5;
        pcVar6 = TclFreeObj_exref;
joined_r0x00664c36:
        if (iVar1 < 1) {
          (*pcVar6)(piVar5);
        }
      }
      piVar5 = (int *)FUN_004295e0(1);
      if (local_38 != 0) {
        if ((*piVar5 != 0) && (iVar1 = Tcl_ObjSetVar2(local_38,*piVar5,0,piVar3,0x200), iVar1 == 0))
        {
          uVar8 = Tcl_GetStringResult(local_38);
          uVar8 = FUN_006b9200(uVar8);
          FUN_006b91c0(uVar8);
        }
        if (local_38 != 0) {
          Tcl_SetObjResult(local_38,piVar3);
        }
      }
      uVar8 = 0;
    }
    else {
      puVar2 = (undefined4 *)FUN_004295e0(2);
      piVar5 = (int *)*puVar2;
      if (piVar5 != (int *)0x0) {
        *piVar5 = *piVar5 + 1;
      }
      FUN_006bc6a0("index to high",piVar5);
      uVar8 = 1;
    }
  }
  if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
    TclFreeObj(piVar3);
  }
LAB_00664cb3:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

