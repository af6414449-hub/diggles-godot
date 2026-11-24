
undefined4
CTclGlobalMethods__HMax(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *piVar7;
  float fVar8;
  double dVar9;
  undefined8 uVar10;
  int local_50;
  undefined4 *local_40;
  int *local_3c;
  int local_38;
  double local_2c;
  double local_24;
  undefined4 *local_1c;
  undefined4 local_18;
  int *piStack_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d3dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6fd8) &&
     (FUN_006cebf4(&DAT_00ca6fd8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6fd8 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6fdc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::HMax()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6fd8);
  }
  iVar3 = DAT_00ca6fdc;
  local_1c = &DAT_00ca6fdc;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6fdc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar10 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar7 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar7 < 2) {
    FUN_006bc8f0(3);
    uVar5 = 1;
    goto LAB_0063b3be;
  }
  local_24 = 0.0;
  if (piVar7 == (int *)0x2) {
    if (local_38 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_40;
      if (local_3c == (int *)0x0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_3c < (int *)0x2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_40 + 1;
    }
    piVar7 = (int *)*puVar6;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
      iVar2 = Tcl_ListObjLength(0,piVar7,&param_3);
      piVar4 = param_3;
      if (iVar2 == 0) {
        while (0 < (int)piVar4) {
          piVar4 = (int *)((int)piVar4 + -1);
          iVar2 = Tcl_ListObjIndex(0,piVar7,piVar4,&piStack_14);
          piVar1 = piStack_14;
          if ((iVar2 == 0) && (piStack_14 != (int *)0x0)) {
            *piStack_14 = *piStack_14 + 1;
            iVar2 = Tcl_GetDoubleFromObj(0,piStack_14,&local_2c);
            if (iVar2 == 1) {
              fVar8 = 0.0;
            }
            else {
              fVar8 = (float)local_2c;
            }
            *piVar1 = *piVar1 + -1;
            dVar9 = (double)fVar8;
            if (*piVar1 < 1) {
              TclFreeObj(piVar1);
            }
          }
          else {
            dVar9 = 0.0;
          }
          if ((local_24 < dVar9) || (piVar4 == (int *)((int)param_3 + -1))) {
            local_24 = dVar9;
          }
        }
      }
      *piVar7 = *piVar7 + -1;
      if (*piVar7 < 1) {
        TclFreeObj(piVar7);
      }
    }
  }
  else {
    piVar7 = (int *)((int)piVar7 + -1);
    param_3 = piVar7;
    do {
      if ((int)piVar7 < local_38) {
        if (local_3c <= piVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar6 = local_40 + (int)piVar7;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_40;
        if (local_3c == (int *)0x0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      piVar4 = (int *)*puVar6;
      if (piVar4 == (int *)0x0) {
        dVar9 = 0.0;
      }
      else {
        *piVar4 = *piVar4 + 1;
        iVar2 = Tcl_GetDoubleFromObj(0,piVar4,&local_18);
        if (iVar2 == 1) {
          fVar8 = 0.0;
        }
        else {
          fVar8 = (float)(double)CONCAT44(piStack_14,local_18);
        }
        *piVar4 = *piVar4 + -1;
        local_2c = (double)fVar8;
        dVar9 = local_2c;
        if (*piVar4 < 1) {
          TclFreeObj(piVar4);
          dVar9 = local_2c;
        }
      }
      if ((local_24 < dVar9) || (piVar7 == param_3)) {
        local_24 = dVar9;
      }
      piVar7 = (int *)((int)piVar7 + -1);
    } while (0 < (int)piVar7);
  }
  if (local_24 - (double)(int)local_24 == 0.0) {
    piVar7 = (int *)Tcl_NewIntObj((int)local_24);
    *piVar7 = *piVar7 + 1;
    iVar2 = *piVar7;
    if (local_50 != 0) {
      Tcl_SetObjResult(local_50,piVar7);
      iVar2 = *piVar7;
    }
    iVar2 = iVar2 + -1;
    *piVar7 = iVar2;
joined_r0x0063b3b0:
    if (iVar2 < 1) {
      TclFreeObj(piVar7);
    }
  }
  else {
    piVar7 = (int *)FUN_006bad90();
    if (local_50 != 0) {
      if (*piVar7 == 0) {
        Tcl_ResetResult(local_50);
      }
      else {
        Tcl_SetObjResult(local_50,*piVar7);
      }
    }
    if (param_3 != (int *)0x0) {
      *param_3 = *param_3 + -1;
      iVar2 = *param_3;
      piVar7 = param_3;
      goto joined_r0x0063b3b0;
    }
  }
  uVar5 = 0;
LAB_0063b3be:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_40 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

