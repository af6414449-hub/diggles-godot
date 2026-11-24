
undefined4
CTclGlobalMethods__GroundPos(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  int local_3c;
  float local_2c;
  float local_28;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070cb5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e48) &&
     (FUN_006cebf4(&DAT_00ca6e48,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca6e48 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6e4c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::GroundPos()";
    *(int *)(&DAT_00773650 + iVar7) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e48);
  }
  iVar7 = DAT_00ca6e4c;
  local_14 = &DAT_00ca6e4c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e4c * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar1;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar5 == 0) {
    uVar9 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  uVar3 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (param_3 == 2) {
    local_8._0_1_ = uVar3;
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_20;
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_20 + 1;
    }
    piVar2 = (int *)*puVar8;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    FUN_006bafe0(&local_2c);
    DAT_00772dd8 = (int)ROUND(local_28 + 0.5);
    if (((((int)ROUND(local_2c + 0.5) < PTR_0077241c->cellX0) ||
         (PTR_0077241c->cellX1 <= (int)ROUND(local_2c + 0.5))) ||
        (DAT_00772dd8 < PTR_0077241c->cellY0)) || (PTR_0077241c->cellY1 <= DAT_00772dd8)) {
      uVar4 = 0;
    }
    else {
      iVar5 = FUN_00592f10(PTR_0077241c);
      uVar4 = *(ushort *)(iVar5 + 0x18) & 3;
    }
    piVar6 = (int *)Tcl_NewIntObj(uVar4);
    *piVar6 = *piVar6 + 1;
    iVar5 = *piVar6;
    if (local_3c != 0) {
      Tcl_SetObjResult(local_3c,piVar6);
      iVar5 = *piVar6;
    }
    *piVar6 = iVar5 + -1;
    if (iVar5 + -1 < 1) {
      TclFreeObj(piVar6);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_004297b0(0);
    if (local_20 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 0;
  }
  FUN_006bc8f0(1);
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

