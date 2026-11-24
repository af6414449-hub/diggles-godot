
undefined4
CTclObjMethods__AddAttrib
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined **ppuVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 uVar11;
  bool bVar12;
  undefined8 uVar13;
  int local_48;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  double local_2c;
  int *local_24;
  int *local_20;
  undefined4 *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071090d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca74b0) &&
     (FUN_006cebf4(&DAT_00ca74b0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca74b0 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca74b4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclObjMethods::AddAttrib()";
    *(int *)(&DAT_00773650 + iVar8) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca74b0);
  }
  iVar8 = DAT_00ca74b4;
  local_1c = &DAT_00ca74b4;
  uVar11 = *(undefined4 *)(&DAT_00773650 + DAT_00ca74b4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar11;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar4 == 0) {
    uVar13 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = FUN_005c71c0(param_4,4,1);
  if (local_14 == 0) {
    uVar11 = 1;
    goto LAB_0067488d;
  }
  if (local_30 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar10 = local_38;
    if (local_34 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_34 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar10 = local_38 + 2;
  }
  piVar2 = (int *)*puVar10;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_20 = piVar2;
  if (local_30 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar10 = local_38;
    if (local_34 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_34 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar10 = local_38 + 3;
  }
  piVar3 = (int *)*puVar10;
  if (piVar3 != (int *)0x0) {
    *piVar3 = *piVar3 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  local_24 = piVar3;
  if (piVar2 == (int *)0x0) {
    ppuVar5 = &PTR_0071ce50;
  }
  else {
    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
  }
  pcVar9 = "atr_Hitpoints";
  do {
    bVar1 = *(byte *)ppuVar5;
    bVar12 = bVar1 < (byte)*pcVar9;
    if (bVar1 != *pcVar9) {
LAB_00674742:
      uVar6 = -(uint)bVar12 | 1;
      goto LAB_00674747;
    }
    if (bVar1 == 0) break;
    bVar1 = *(byte *)((int)ppuVar5 + 1);
    bVar12 = bVar1 < ((byte *)pcVar9)[1];
    if (bVar1 != ((byte *)pcVar9)[1]) goto LAB_00674742;
    ppuVar5 = (undefined **)((int)ppuVar5 + 2);
    pcVar9 = (char *)((byte *)pcVar9 + 2);
  } while (bVar1 != 0);
  uVar6 = 0;
LAB_00674747:
  local_18 = (int *)0x0;
  if ((uVar6 == 0) && ((*(uint *)(local_14 + 0x3d0) & 0x10000000) != 0)) {
    if (piVar3 == (int *)0x0) goto LAB_006747c7;
    iVar4 = Tcl_GetDoubleFromObj(0,piVar3,&local_2c);
    if (iVar4 == 1) goto LAB_0067479f;
    if (0.0 <= (float)local_2c) goto LAB_00674796;
LAB_0067486e:
    *piVar3 = *piVar3 + -1;
    if (*piVar3 < 1) {
      TclFreeObj(piVar3);
    }
  }
  else {
LAB_00674796:
    if (piVar3 != (int *)0x0) {
LAB_0067479f:
      iVar4 = Tcl_GetDoubleFromObj(0,piVar3,&local_2c);
      if (iVar4 == 1) {
        local_18 = (int *)0x0;
      }
      else {
        local_18 = (int *)(float)local_2c;
      }
    }
LAB_006747c7:
    if (piVar2 == (int *)0x0) {
      FUN_005daff0(&PTR_0071ce50);
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      uVar11 = Tcl_GetStringFromObj(piVar2,0);
      FUN_005daff0(uVar11);
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
    }
    FUN_005dae40(ppuVar5);
    piVar7 = (int *)FUN_006bad90();
    if (local_48 != 0) {
      if (*piVar7 == 0) {
        Tcl_ResetResult(local_48);
      }
      else {
        Tcl_SetObjResult(local_48,*piVar7);
      }
    }
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
      TclFreeObj(local_18);
    }
    if (piVar3 != (int *)0x0) goto LAB_0067486e;
  }
  uVar11 = 0;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
LAB_0067488d:
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar11;
}

