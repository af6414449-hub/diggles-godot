
undefined4
CTclGlobalMethods__HasCMap(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  bool bVar9;
  undefined8 uVar10;
  int local_44;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  undefined1 local_28 [4];
  int *local_24;
  undefined4 *local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ecad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca72d8) &&
     (FUN_006cebf4(&DAT_00ca72d8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca72d8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca72dc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::HasCMap()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca72d8);
  }
  iVar5 = DAT_00ca72dc;
  local_20 = &DAT_00ca72dc;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca72dc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar10 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8 = CONCAT31(local_8._1_3_,1);
  if ((param_3 == (int *)0x2) || (param_3 == (int *)0x3)) {
    uVar8 = 0;
    FUN_004298b0(param_3,param_4);
    if (piVar1 == (int *)0x3) {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_34;
        if (local_30 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_30 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar6 = local_34 + 2;
      }
      piVar1 = (int *)*puVar6;
      if (piVar1 == (int *)0x0) {
        uVar8 = 0;
      }
      else {
        *piVar1 = *piVar1 + 1;
        iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_18);
        *piVar1 = *piVar1 + -1;
        uVar8 = -(uint)(iVar2 != 1) & local_18;
        if (*piVar1 < 1) {
          TclFreeObj(piVar1);
        }
      }
    }
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_34 + 1;
    }
    piVar1 = (int *)*puVar6;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 3;
    local_24 = piVar1;
    if (piVar1 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar3);
    local_8._0_1_ = 4;
    FUN_00460fc0(&param_3,&local_14,local_28,&local_1c);
    local_8 = CONCAT31(local_8._1_3_,5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
    param_3 = (int *)0x0;
    if (local_14 != 0xffffffff) {
      param_3 = (int *)(DAT_00772400 + 0x5c8);
      if (local_14 < 0x100) {
        param_3 = param_3 + local_14;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      param_3 = (int *)*param_3;
    }
    bVar9 = false;
    if ((param_3 != (int *)0x0) && (local_1c != -1)) {
      if ((local_1c < 0) || (param_3[0x14] <= local_1c)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        local_14 = param_3[0x13];
      }
      else {
        local_14 = param_3[0x13] + local_1c * 0x3c;
      }
      if (((int)uVar8 < 0) || (*(int *)(local_14 + 0xc) <= (int)uVar8)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar4 = *(int **)(local_14 + 8);
      }
      else {
        piVar4 = (int *)(*(int *)(local_14 + 8) + uVar8 * 4);
      }
      bVar9 = false;
      if (*piVar4 != -1) {
        piVar4 = (int *)FUN_004059a0(*piVar4);
        bVar9 = *piVar4 != -1;
      }
    }
    piVar4 = (int *)Tcl_NewBooleanObj(bVar9);
    *piVar4 = *piVar4 + 1;
    iVar2 = *piVar4;
    if (local_44 != 0) {
      Tcl_SetObjResult(local_44,piVar4);
      iVar2 = *piVar4;
    }
    *piVar4 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj(piVar4);
    }
    uVar7 = 0;
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    local_8._0_1_ = 6;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_004297b0(0);
    if (local_34 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar7 = 1;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

