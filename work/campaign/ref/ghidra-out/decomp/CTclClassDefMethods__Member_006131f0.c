
undefined4
CTclClassDefMethods__Member(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined8 uVar10;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a6fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6b70) &&
     (FUN_006cebf4(&DAT_00ca6b70,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6b70 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6b74 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclClassDefMethods::Member()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6b70);
  }
  iVar6 = DAT_00ca6b74;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6b74 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  iVar4 = DAT_00772440;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar8 = 1;
  }
  else if (param_3 < 2) {
    FUN_006bc8f0(1);
    uVar8 = 1;
  }
  else {
    local_18 = 1;
    do {
      if ((int)local_18 < local_28) {
        if (local_2c <= local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_30 + local_18;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_30;
        if (local_2c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      piVar2 = (int *)*puVar5;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      if (local_40 == 0) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = (int *)Tcl_ObjGetVar2(local_40,piVar2,0,0);
        if (piVar9 != (int *)0x0) {
          *piVar9 = *piVar9 + 1;
        }
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      iVar6 = *(int *)(iVar4 + 4);
      FUN_00604250(1);
      uVar7 = *(int *)(iVar6 + 0x84) - 1;
      iVar6 = *(int *)(iVar4 + 4);
      if (*(uint *)(iVar6 + 0x84) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar1 = uVar7 * 8;
      puVar5 = (undefined4 *)(*(int *)(iVar6 + 0x80) + iVar1);
      piVar3 = (int *)*puVar5;
      *puVar5 = piVar2;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
        TclFreeObj(piVar3);
      }
      iVar6 = *(int *)(iVar4 + 4);
      if (*(uint *)(iVar6 + 0x84) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar6 = *(int *)(iVar6 + 0x80);
      piVar3 = *(int **)(iVar1 + 4 + iVar6);
      *(int **)(iVar1 + 4 + iVar6) = piVar9;
      if (piVar9 != (int *)0x0) {
        *piVar9 = *piVar9 + 1;
      }
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
        TclFreeObj(piVar3);
      }
      if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
        TclFreeObj(piVar9);
      }
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj(piVar2);
      }
      local_18 = local_18 + 1;
    } while ((int)local_18 < param_3);
    uVar8 = 0;
  }
  FUN_006bc0d0();
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

