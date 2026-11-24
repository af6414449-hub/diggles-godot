
undefined4
CTclGlobalMethods__ObjList(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int local_30;
  int local_20;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bd9d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6cb0) {
    FUN_006cebf4(&DAT_00ca6cb0,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar1 = DAT_00783650;
    if (DAT_00ca6cb0 == -1) {
      iVar4 = DAT_00783650 * 0x40;
      DAT_00ca6cb4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::ObjList()";
      *(int *)(&DAT_00773650 + iVar4) = iVar1;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca6cb0);
    }
  }
  iVar4 = DAT_00ca6cb4;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6cb4 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar5;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar1 == 0) {
    uVar6 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (1 < param_3) {
    piVar2 = (int *)FUN_006ba810(0x19);
    piVar3 = piVar2 + 3;
    piVar2[2] = -1;
    *piVar2 = 0;
    *(undefined1 *)piVar3 = 0;
    piVar2[1] = 0x14;
    *piVar3 = 0x73696874;
    *(undefined1 *)(piVar2 + 4) = 0;
    piVar2[2] = 4;
    *piVar2 = 1;
    if (local_30 == 0) {
      iVar4 = 0;
      iVar1 = 1;
    }
    else {
      iVar4 = Tcl_GetAssocData(local_30,piVar3,0);
      iVar1 = *piVar2;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar2 = iVar1 + -1;
    if (iVar1 + -1 == 0) {
      FUN_006ba940();
    }
    if (iVar4 != 0) {
      if (*(int *)(iVar4 + 0xd0) != 0) {
        piVar3 = (int *)Tcl_NewListObj(0,0);
        if (piVar3 != (int *)0x0) {
          *piVar3 = *piVar3 + 1;
        }
        if (local_30 == 0) {
          uVar5 = 0;
          if (piVar3 == (int *)0x0) goto LAB_00623ded;
        }
        else {
          if (piVar3 == (int *)0x0) {
            Tcl_ResetResult(local_30);
            uVar5 = 0;
            goto LAB_00623ded;
          }
          Tcl_SetObjResult(local_30,piVar3);
        }
        *piVar3 = *piVar3 + -1;
        uVar5 = 0;
        if (*piVar3 < 1) {
          TclFreeObj(piVar3);
        }
        goto LAB_00623ded;
      }
      piVar3 = (int *)Tcl_NewListObj(0,0);
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      if (local_30 == 0) {
        if (piVar3 != (int *)0x0) goto LAB_00623d82;
      }
      else {
        if (piVar3 == (int *)0x0) {
          Tcl_ResetResult(local_30);
          uVar5 = 0;
          goto LAB_00623ded;
        }
        Tcl_SetObjResult(local_30,piVar3);
LAB_00623d82:
        *piVar3 = *piVar3 + -1;
        if (*piVar3 < 1) {
          TclFreeObj(piVar3);
        }
      }
      uVar5 = 0;
      goto LAB_00623ded;
    }
  }
  uVar5 = 1;
LAB_00623ded:
  FUN_006bc0d0();
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_20 != 0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

