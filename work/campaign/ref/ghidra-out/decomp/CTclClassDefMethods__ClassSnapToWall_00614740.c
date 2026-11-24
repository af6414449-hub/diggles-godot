
undefined4
CTclClassDefMethods__ClassSnapToWall
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a7dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6bb0) &&
     (FUN_006cebf4(&DAT_00ca6bb0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6bb0 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6bb4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclClassDefMethods::ClassSnapToWall()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6bb0);
  }
  iVar3 = DAT_00ca6bb4;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6bb4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  iVar2 = DAT_00772440;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar5 = 1;
    goto LAB_006148e2;
  }
  if (param_3 != 2) {
    FUN_006bc8f0(1);
    uVar5 = 1;
    goto LAB_006148e2;
  }
  if (local_1c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_24;
    if (local_20 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_24 + 1;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 == (int *)0x0) {
    puVar4 = (uint *)(*(int *)(iVar2 + 4) + 0x2c);
LAB_006148dd:
    *puVar4 = *puVar4 & 0xfffffff7;
  }
  else {
    *piVar1 = *piVar1 + 1;
    iVar3 = Tcl_GetBooleanFromObj(0,piVar1,&local_14);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 1) {
      TclFreeObj(piVar1);
    }
    puVar4 = (uint *)(*(int *)(iVar2 + 4) + 0x2c);
    if (iVar3 == 1 || local_14 == 0) goto LAB_006148dd;
    *puVar4 = *puVar4 | 8;
  }
  uVar5 = 0;
LAB_006148e2:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

