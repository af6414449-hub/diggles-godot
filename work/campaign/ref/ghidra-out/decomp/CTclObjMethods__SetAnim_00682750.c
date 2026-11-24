
undefined4
CTclObjMethods__SetAnim(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined **ppuVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  code *pcVar11;
  bool bVar12;
  double in_XMM0_Qa;
  undefined8 uVar13;
  int *local_50;
  int *local_4c;
  undefined4 *local_44;
  uint local_40;
  int local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  undefined4 *local_2c;
  uint local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071121d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca76f8) &&
     (FUN_006cebf4(&DAT_00ca76f8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca76f8 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca76fc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclObjMethods::SetAnim()";
    *(int *)(&DAT_00773650 + iVar8) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca76f8);
  }
  iVar8 = DAT_00ca76fc;
  local_2c = &DAT_00ca76fc;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca76fc * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar9;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar5 == 0) {
    uVar13 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  iVar5 = FUN_005c71c0(param_4,5,1);
  local_18 = iVar5;
  FUN_006bc170(param_2);
  if (iVar5 == 0) {
    uVar9 = 1;
    goto LAB_00682b85;
  }
  if (local_3c < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_44;
    if (local_40 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_44;
    }
  }
  else {
    if (local_40 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_44 + 2;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_30 = piVar1;
  if (local_3c < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_44;
    if (local_40 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_44;
    }
  }
  else {
    if (local_40 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_44 + 3;
  }
  local_34 = (int *)*puVar6;
  if (local_34 != (int *)0x0) {
    *local_34 = *local_34 + 1;
  }
  local_20 = local_34;
  if (local_3c < 5) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_44;
    if (local_40 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_44;
    }
  }
  else {
    if (local_40 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_44 + 4;
  }
  piVar2 = (int *)*puVar6;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_8._0_1_ = 5;
  local_38 = piVar2;
  if (param_3 == 6) {
    if (local_3c < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_44;
      }
    }
    else {
      if (local_40 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_44 + 5;
    }
    local_14 = (int *)*puVar6;
    if (local_14 == (int *)0x0) goto LAB_006829c0;
    *local_14 = *local_14 + 1;
    iVar5 = Tcl_GetBooleanFromObj(0,local_14,&local_1c);
    bVar12 = local_1c == (int *)0x0;
    *local_14 = *local_14 + -1;
    if (*local_14 < 1) {
      TclFreeObj(local_14);
    }
    if (iVar5 == 1 || bVar12) goto LAB_006829c0;
    uVar9 = 0;
  }
  else {
LAB_006829c0:
    if (piVar1 == (int *)0x0) {
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar7);
    if (*(int *)(*(int *)(local_18 + 0xd4) + 0xcc4) == 0) {
      cVar4 = '\0';
    }
    else {
      cVar4 = FUN_004613d0(&local_14,&local_50);
    }
    local_8._0_1_ = 6;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 5;
    if (cVar4 == '\0') {
      if (piVar1 == (int *)0x0) {
        ppuVar7 = &PTR_0071ce50;
      }
      else {
        ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
      }
      FUN_006b8fb0(ppuVar7);
      local_8._0_1_ = 7;
      cVar4 = FUN_00460fc0(&local_14,&local_1c,&local_28,&local_24);
      local_8._0_1_ = 8;
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 5;
      local_50 = local_1c;
      local_4c = local_24;
      if (cVar4 != '\0') goto LAB_00682a9c;
    }
    else {
LAB_00682a9c:
      local_8._0_1_ = 5;
      local_14 = local_50;
      if ((*(uint *)(local_18 + 0x3d0) & 0x2000) != 0) {
        local_14 = (int *)((int)local_50 + 1);
      }
      local_1c = local_4c;
      if (piVar2 == (int *)0x0) {
        uVar10 = 0;
      }
      else {
        iVar5 = Tcl_GetIntFromObj(0,piVar2,&local_24);
        uVar10 = -(uint)(iVar5 != 1) & (uint)local_24;
      }
      if (local_20 == (int *)0x0) {
        local_28 = 0;
      }
      else {
        iVar5 = Tcl_GetIntFromObj(0,local_20,&local_28);
        local_28 = -(uint)(iVar5 != 1) & local_28;
      }
      piVar3 = local_14;
      FUN_006b49b0(local_18,local_14,local_1c,local_28,uVar10);
      if ((in_XMM0_Qa != 0.0) && (piVar3 != (int *)0xffffffff)) {
        uVar9 = 0;
        goto LAB_00682b41;
      }
    }
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("unknown anim",piVar1);
    uVar9 = 1;
  }
LAB_00682b41:
  pcVar11 = TclFreeObj_exref;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, pcVar11 = TclFreeObj_exref, *piVar2 < 1)) {
    TclFreeObj(piVar2);
  }
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 < 1)) {
    (*pcVar11)(local_20);
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar11)(piVar1);
  }
LAB_00682b85:
  FUN_006bc0d0();
  local_8._0_1_ = 9;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_004297b0(0);
  if (local_44 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

