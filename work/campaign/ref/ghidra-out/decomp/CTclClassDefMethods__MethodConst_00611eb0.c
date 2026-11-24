
undefined4
CTclClassDefMethods__MethodConst
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined **ppuVar7;
  int iVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  undefined1 local_6c [4];
  int *local_68;
  undefined2 local_4c;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  int *local_28;
  int *local_24;
  undefined4 *local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a60d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6b40) &&
     (FUN_006cebf4(&DAT_00ca6b40,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca6b40 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca6b44 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclClassDefMethods::MethodConst()";
    *(int *)(&DAT_00773650 + iVar8) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6b40);
  }
  iVar8 = DAT_00ca6b44;
  local_20 = &DAT_00ca6b44;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6b44 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar9;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar5 == 0) {
    uVar10 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = DAT_00772440;
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar9 = 1;
  }
  else if (param_3 == 4) {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_34;
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
    local_24 = piVar1;
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_34;
      }
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_34 + 2;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_28 = piVar2;
    if (local_2c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_34;
      }
    }
    else {
      if (local_30 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_34 + 3;
    }
    local_1c = (int *)*puVar6;
    if (local_1c != (int *)0x0) {
      *local_1c = *local_1c + 1;
    }
    local_8._0_1_ = 5;
    local_18 = local_1c;
    FUN_005ffd20();
    local_8 = CONCAT31(local_8._1_3_,6);
    if (piVar1 == (int *)0x0) {
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b9200(ppuVar7);
    FUN_0042fce0(&local_18);
    piVar3 = local_68;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    piVar4 = piVar2;
    if ((local_68 != (int *)0x0) && (*local_68 = *local_68 + -1, *local_68 < 1)) {
      local_68 = piVar2;
      TclFreeObj(piVar3);
      piVar4 = local_68;
    }
    local_68 = piVar4;
    local_4c = 0x100;
    FUN_00601d90(local_6c);
    *(undefined1 *)(*(int *)(local_14 + 4) + 0xcc0) = 1;
    FUN_006048e0();
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c < 1)) {
      TclFreeObj(local_1c);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar9 = 0;
  }
  else {
    FUN_006bc8f0(3);
    uVar9 = 1;
  }
  FUN_006bc0d0();
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

