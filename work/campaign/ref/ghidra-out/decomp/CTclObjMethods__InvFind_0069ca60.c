
undefined4
CTclObjMethods__InvFind(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  code *pcVar8;
  undefined4 uVar9;
  int iVar10;
  undefined8 uVar11;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711ee5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7b30) &&
     (FUN_006cebf4(&DAT_00ca7b30,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7b30 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca7b34 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CTclObjMethods::InvFind()";
    *(int *)(&DAT_00773650 + iVar10) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7b30);
  }
  iVar10 = DAT_00ca7b34;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7b34 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar9;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar3 == 0) {
    uVar11 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_005c71c0(param_4,3,1);
  if (iVar3 == 0) {
    uVar9 = 1;
  }
  else {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_30 + 2;
    }
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar4);
    iVar3 = DAT_00772478;
    cVar2 = FUN_006037d0(&local_18,&local_14);
    if (cVar2 == '\0') {
      iVar3 = 0;
    }
    else {
      if (*(uint *)(iVar3 + 0x801c) <= local_14) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar3 = *(int *)(*(int *)(iVar3 + 0x8018) + local_14 * 4);
    }
    local_8._0_1_ = 4;
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (iVar3 == 0) {
      if (local_28 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_30;
        if (local_2c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_2c < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar7 = local_30 + 2;
      }
      piVar6 = (int *)*puVar7;
      if (piVar6 != (int *)0x0) {
        *piVar6 = *piVar6 + 1;
      }
      FUN_006bc6a0("unknown class",piVar6);
      uVar9 = 1;
      pcVar8 = TclFreeObj_exref;
    }
    else {
      local_18 = (int *)FUN_005cf210();
      iVar10 = 0;
      if (0 < (int)local_18) {
        do {
          iVar5 = FUN_005cef70(iVar10);
          if (*(int *)(iVar5 + 0xd4) == iVar3) goto LAB_0069ccaa;
          iVar10 = iVar10 + 1;
        } while (iVar10 < (int)local_18);
      }
      iVar10 = -1;
LAB_0069ccaa:
      piVar6 = (int *)Tcl_NewIntObj(iVar10);
      *piVar6 = *piVar6 + 1;
      iVar3 = *piVar6;
      if (local_40 != 0) {
        Tcl_SetObjResult(local_40,piVar6);
        iVar3 = *piVar6;
      }
      pcVar8 = TclFreeObj_exref;
      *piVar6 = iVar3 + -1;
      if (iVar3 + -1 < 1) {
        TclFreeObj(piVar6);
      }
      uVar9 = 0;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar8)(piVar1);
    }
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

