
undefined4
CTclGlobalMethods__Smalltalk(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  code *pcVar9;
  int *piVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  bool bVar13;
  undefined8 uVar14;
  int local_38;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f2d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca73c0) &&
     (FUN_006cebf4(&DAT_00ca73c0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca73c0 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca73c4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::Smalltalk()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca73c0);
  }
  iVar7 = DAT_00ca73c4;
  local_14 = &DAT_00ca73c4;
  uVar11 = *(undefined4 *)(&DAT_00773650 + DAT_00ca73c4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar11;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar3 == 0) {
    uVar14 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  if (param_3 < 3) {
    FUN_006bc8f0(2);
    uVar11 = 1;
    goto LAB_00661d1b;
  }
  FUN_004298b0(param_3,param_4);
  piVar10 = (int *)0x0;
  local_18 = 0;
  local_8 = CONCAT31(local_8._1_3_,3);
  if (local_20 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar12 = local_28;
    if (local_24 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar12 = local_28 + 1;
  }
  piVar2 = (int *)*puVar12;
  if (piVar2 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
  }
  else {
    *piVar2 = *piVar2 + 1;
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
    *piVar2 = *piVar2 + -1;
    if (*piVar2 < 1) {
      TclFreeObj(piVar2);
    }
  }
  pbVar8 = &DAT_00722abc;
  ppuVar5 = ppuVar4;
  do {
    bVar1 = *(byte *)ppuVar5;
    bVar13 = bVar1 < *pbVar8;
    if (bVar1 != *pbVar8) {
LAB_00661ad8:
      uVar6 = -(uint)bVar13 | 1;
      goto LAB_00661add;
    }
    if (bVar1 == 0) break;
    bVar1 = *(byte *)((int)ppuVar5 + 1);
    bVar13 = bVar1 < pbVar8[1];
    if (bVar1 != pbVar8[1]) goto LAB_00661ad8;
    ppuVar5 = (undefined **)((int)ppuVar5 + 2);
    pbVar8 = pbVar8 + 2;
  } while (bVar1 != 0);
  uVar6 = 0;
LAB_00661add:
  if (uVar6 == 0) {
    if (param_3 == 4) {
      uVar11 = FUN_004295e0(3);
      piVar10 = (int *)FUN_004295e0(2);
      iVar3 = FUN_005f8080();
      if (*piVar10 == 0) {
        ppuVar4 = &PTR_0071ce50;
      }
      else {
        ppuVar4 = (undefined **)Tcl_GetStringFromObj(*piVar10,0);
      }
      iVar7 = *(int *)(iVar3 + 0x28);
      if (((iVar7 == 0) || (iVar7 = (**(code **)(iVar7 + 0x2c))(iVar7,ppuVar4), iVar7 == 0)) ||
         (uVar6 = *(int *)(iVar7 + 0xc) - 1, uVar6 == 0xffffffff)) {
        uVar6 = FUN_005fde90();
        if (*piVar10 == 0) {
          ppuVar4 = &PTR_0071ce50;
        }
        else {
          ppuVar4 = (undefined **)Tcl_GetStringFromObj(*piVar10,0);
        }
        iVar7 = *(int *)(iVar3 + 0x28);
        if ((iVar7 != 0) &&
           (iVar7 = (**(code **)(iVar7 + 0x30))(iVar7,ppuVar4,local_1c), iVar7 != 0)) {
          *(uint *)(iVar7 + 0xc) = uVar6 + 1;
        }
      }
      if (*(uint *)(iVar3 + 0x24) <= uVar6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_006bb930(uVar11);
      piVar10 = (int *)Tcl_NewIntObj(uVar6);
      pcVar9 = TclFreeObj_exref;
      iVar3 = *piVar10;
      *piVar10 = iVar3 + 1;
      if (iVar3 + 1 < 1) {
        TclFreeObj(piVar10);
      }
      goto LAB_00661cbc;
    }
    FUN_006bc8f0(3);
    uVar11 = 1;
  }
  else {
    pbVar8 = &DAT_0072e624;
    do {
      bVar1 = *(byte *)ppuVar4;
      bVar13 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_00661c10:
        uVar6 = -(uint)bVar13 | 1;
        goto LAB_00661c15;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar4 + 1);
      bVar13 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_00661c10;
      ppuVar4 = (undefined **)((int)ppuVar4 + 2);
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_00661c15:
    pcVar9 = TclFreeObj_exref;
    if (uVar6 == 0) {
      piVar10 = (int *)FUN_004295e0(2);
      iVar3 = FUN_005f8080();
      if (*piVar10 == 0) {
        ppuVar4 = &PTR_0071ce50;
      }
      else {
        ppuVar4 = (undefined **)Tcl_GetStringFromObj(*piVar10,0);
      }
      iVar7 = *(int *)(iVar3 + 0x28);
      if (((iVar7 == 0) || (iVar7 = (**(code **)(iVar7 + 0x2c))(iVar7,ppuVar4), iVar7 == 0)) ||
         (uVar6 = *(int *)(iVar7 + 0xc) - 1, uVar6 == 0xffffffff)) {
        piVar10 = (int *)0x0;
      }
      else {
        if (*(uint *)(iVar3 + 0x24) <= uVar6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar10 = *(int **)(*(int *)(iVar3 + 0x20) + uVar6 * 4);
        if (piVar10 != (int *)0x0) {
          *piVar10 = *piVar10 + 1;
          *piVar10 = *piVar10 + 1;
        }
      }
      pcVar9 = TclFreeObj_exref;
      if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
        TclFreeObj(piVar10);
      }
    }
LAB_00661cbc:
    if (local_38 == 0) {
      uVar11 = 0;
      if (piVar10 != (int *)0x0) goto LAB_00661ce3;
    }
    else {
      if (piVar10 == (int *)0x0) {
        Tcl_ResetResult(local_38);
      }
      else {
        Tcl_SetObjResult(local_38,piVar10);
LAB_00661ce3:
        *piVar10 = *piVar10 + -1;
        uVar11 = 0;
        if (0 < *piVar10) goto LAB_00661cf3;
        (*pcVar9)(piVar10);
      }
      uVar11 = 0;
    }
  }
LAB_00661cf3:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
LAB_00661d1b:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar11;
}

