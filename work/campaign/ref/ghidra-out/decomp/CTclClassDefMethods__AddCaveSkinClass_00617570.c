
undefined4
CTclClassDefMethods__AddCaveSkinClass
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070aaed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6be8) &&
     (FUN_006cebf4(&DAT_00ca6be8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6be8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6bec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclClassDefMethods::AddCaveSkinClass()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6be8);
  }
  iVar4 = DAT_00ca6bec;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6bec * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar10 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  iVar3 = DAT_00772440;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar8 = 1;
  }
  else if (param_3 == 4) {
    *(undefined1 *)(*(int *)(DAT_00772440 + 4) + 0xcc2) = 1;
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_30 + 1;
    }
    piVar2 = (int *)*puVar9;
    if (piVar2 == (int *)0x0) {
      local_18 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar4 = Tcl_GetIntFromObj(0,piVar2,&local_18);
      *piVar2 = *piVar2 + -1;
      local_18 = local_18 & -(uint)(iVar4 != 1);
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_30 + 2;
    }
    piVar2 = (int *)*puVar9;
    if (piVar2 == (int *)0x0) {
      local_14 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar4 = Tcl_GetIntFromObj(0,piVar2,&local_14);
      *piVar2 = *piVar2 + -1;
      local_14 = local_14 & -(uint)(iVar4 != 1);
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_28 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_30 + 3;
    }
    piVar2 = (int *)*puVar9;
    if (piVar2 == (int *)0x0) {
      uVar7 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar4 = Tcl_GetIntFromObj(0,piVar2,&local_1c);
      *piVar2 = *piVar2 + -1;
      uVar7 = -(uint)(iVar4 != 1) & local_1c;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    uVar1 = *(undefined4 *)(*(int *)(iVar3 + 4) + 8);
    iVar3 = FUN_0058a820();
    uVar6 = *(uint *)(iVar3 + 0x2c);
    if ((uVar6 + 0x10 & 0xfffffff0) != (uVar6 + 0xf & 0xfffffff0)) {
      uVar8 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                           0x9b);
      uVar6 = *(uint *)(iVar3 + 0x2c);
      *(undefined4 *)(iVar3 + 0x28) = uVar8;
    }
    uVar5 = uVar6 + 1;
    *(uint *)(iVar3 + 0x2c) = uVar5;
    if (uVar5 <= uVar6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar5 = *(uint *)(iVar3 + 0x2c);
    }
    iVar3 = *(int *)(iVar3 + 0x28);
    uVar8 = 0;
    *(undefined4 *)(iVar3 + -4 + uVar5 * 0x1c) = uVar1;
    *(uint *)(iVar3 + -8 + uVar5 * 0x1c) = local_14;
    *(undefined4 *)(iVar3 + -0x1c + uVar5 * 0x1c) = 0xffffffff;
    *(undefined4 *)(iVar3 + -0x18 + uVar5 * 0x1c) = 0xffffffff;
    *(uint *)(iVar3 + -0x10 + uVar5 * 0x1c) = local_18;
    *(uint *)(iVar3 + -0xc + uVar5 * 0x1c) = uVar7;
  }
  else {
    FUN_006bc8f0(3);
    uVar8 = 1;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

