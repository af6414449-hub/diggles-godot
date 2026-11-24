
undefined4
CTclObjMethods__InvAdd(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined8 uVar9;
  int local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_20;
  undefined4 *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711dfd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7b10) &&
     (FUN_006cebf4(&DAT_00ca7b10,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7b10 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca7b14 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclObjMethods::InvAdd()";
    *(int *)(&DAT_00773650 + iVar8) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7b10);
  }
  iVar8 = DAT_00ca7b14;
  local_1c = &DAT_00ca7b14;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7b14 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_18 = FUN_005c71c0(param_4,3,1);
  if (local_18 == 0) {
    uVar6 = 1;
  }
  else {
    piVar3 = (int *)FUN_006ba810(0x19);
    piVar1 = piVar3 + 3;
    piVar3[2] = -1;
    *piVar3 = 0;
    *(undefined1 *)piVar1 = 0;
    piVar3[1] = 0x14;
    *piVar1 = 0x73696874;
    *(undefined1 *)(piVar3 + 4) = 0;
    piVar3[2] = 4;
    *piVar3 = 1;
    if (local_48 == 0) {
      uVar6 = 0;
      iVar2 = 1;
    }
    else {
      uVar6 = Tcl_GetAssocData(local_48,piVar1,0);
      iVar2 = *piVar3;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar3 = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      FUN_006ba940();
    }
    if (local_24 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_2c;
      }
    }
    else {
      if (local_28 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_2c + 2;
    }
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 4;
    local_20 = piVar1;
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 5;
    iVar2 = FUN_006055d0(param_2,uVar6,&local_14);
    local_8._0_1_ = 6;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if ((iVar2 == 0) || (iVar2 = CTclObjMethods__Base2Obj(), iVar2 == 0)) {
      uVar6 = 1;
    }
    else {
      *(uint *)(iVar2 + 0x3d0) = *(uint *)(iVar2 + 0x3d0) & 0xfffffffe;
      local_14 = (int *)FUN_005cf210();
      iVar8 = 0;
      if (0 < (int)local_14) {
        do {
          iVar5 = FUN_005cef70(iVar8);
          if (iVar5 == iVar2) goto LAB_0069bff3;
          iVar8 = iVar8 + 1;
        } while (iVar8 < (int)local_14);
      }
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      if ((((*(float *)(iVar2 + 0xc) != 0.0) || (*(float *)(iVar2 + 0x10) != 0.0)) ||
          (*(float *)(iVar2 + 0x14) != 0.0)) &&
         (FUN_005cd8e0(&local_38), *(int *)(iVar2 + 0x238) == 0)) {
        iVar8 = iVar2;
        FUN_005ebc90(iVar2);
        FUN_005eb470(iVar8);
      }
      iVar8 = FUN_005ce010(iVar2);
LAB_0069bff3:
      piVar3 = (int *)Tcl_NewIntObj(iVar8);
      *piVar3 = *piVar3 + 1;
      iVar2 = *piVar3;
      if (local_48 != 0) {
        Tcl_SetObjResult(local_48,piVar3);
        iVar2 = *piVar3;
      }
      *piVar3 = iVar2 + -1;
      if (iVar2 + -1 < 1) {
        TclFreeObj(piVar3);
      }
      uVar6 = 0;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

