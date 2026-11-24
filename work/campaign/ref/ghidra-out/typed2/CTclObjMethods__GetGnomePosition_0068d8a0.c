
undefined4
CTclObjMethods__GetGnomePosition
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  int local_38;
  int local_28;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c3dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca78d0) {
    FUN_006cebf4(&DAT_00ca78d0,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca78d0 == -1) {
      iVar5 = DAT_00783650 * 0x40;
      DAT_00ca78d4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::GetGnomePosition()";
      *(int *)(&DAT_00773650 + iVar5) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca78d0);
    }
  }
  iVar5 = DAT_00ca78d4;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca78d4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar7;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,2,1);
  if (iVar2 == 0) {
    uVar7 = 1;
    goto LAB_0068dacb;
  }
  uVar3 = (uint)ROUND(*(float *)(iVar2 + 0x10) * 8.0);
  local_14 = (int *)(*(float *)(iVar2 + 0xc) * 8.0);
  uVar1 = (uint)ROUND((float)local_14);
  DAT_00772dd8 = uVar1;
  if (((((int)uVar1 < PTR_0077241c->x0_8 + 1) || (PTR_0077241c->x1_8 + -1 <= (int)uVar1)) ||
      ((int)uVar3 < PTR_0077241c->y0_8 + 1)) || (PTR_0077241c->y1_8 + -1 <= (int)uVar3)) {
LAB_0068da93:
    piVar4 = (int *)Tcl_NewIntObj(0);
    *piVar4 = *piVar4 + 1;
    iVar2 = *piVar4;
    if (local_38 != 0) {
      Tcl_SetObjResult(local_38,piVar4);
      iVar2 = *piVar4;
    }
    *piVar4 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj(piVar4);
    }
  }
  else {
    local_14 = (int *)(uVar1 & 7);
    uVar6 = (uVar3 + 1 & 7) << 3 | (uint)local_14;
    iVar2 = FUN_00592f10(PTR_0077241c);
    if ((*(byte *)(iVar2 + 0x3c + uVar6) & 2) != 0) goto LAB_0068da93;
    uVar6 = (uVar3 & 7) << 3 | (uint)local_14;
    iVar2 = FUN_00592f10(PTR_0077241c);
    if ((*(byte *)(uVar6 + 0x3c + iVar2) & 2) != 0) goto LAB_0068da93;
    uVar3 = FUN_00407e70(uVar1,uVar3 - 1);
    if ((uVar3 & 2) != 0) goto LAB_0068da93;
    local_14 = (int *)Tcl_NewIntObj(1);
    *local_14 = *local_14 + 1;
    FUN_006bc670(&local_14);
    FUN_006bad60();
  }
  uVar7 = 0;
LAB_0068dacb:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_28 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

