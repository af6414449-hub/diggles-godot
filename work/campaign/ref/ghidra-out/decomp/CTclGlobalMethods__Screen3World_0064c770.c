
undefined4
CTclGlobalMethods__Screen3World
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined8 uVar12;
  int local_3c;
  float local_2c;
  float local_28;
  float local_24;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d25d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7170) &&
     (FUN_006cebf4(&DAT_00ca7170,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7170 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca7174 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::Screen3World()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7170);
  }
  iVar6 = DAT_00ca7174;
  local_14 = &DAT_00ca7174;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7174 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar12 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  uVar3 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (1 < param_3) {
    local_8._0_1_ = uVar3;
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_20;
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_20 + 1;
    }
    piVar2 = (int *)*puVar7;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    FUN_006bafe0(&local_2c);
    fVar10 = (float)*(int *)(DAT_0076a338 + 0x2830) * local_2c;
    fVar11 = 1.0 - 1.0 / local_24;
    fVar8 = (float)*(int *)(DAT_0076a338 + 0x2834) * local_28;
    fVar9 = *(float *)(DAT_0076a338 + 0x27b0) * fVar8 + *(float *)(DAT_0076a338 + 0x27a0) * fVar10 +
            *(float *)(DAT_0076a338 + 0x27c0) * fVar11 + *(float *)(DAT_0076a338 + 0x27d0);
    local_2c = (*(float *)(DAT_0076a338 + 0x27a4) * fVar8 +
                fVar10 * *(float *)(DAT_0076a338 + 0x2794) +
                *(float *)(DAT_0076a338 + 0x27b4) * fVar11 + *(float *)(DAT_0076a338 + 0x27c4)) /
               fVar9;
    local_28 = (*(float *)(DAT_0076a338 + 0x27a8) * fVar8 +
                *(float *)(DAT_0076a338 + 0x2798) * fVar10 +
                *(float *)(DAT_0076a338 + 0x27b8) * fVar11 + *(float *)(DAT_0076a338 + 0x27c8)) /
               fVar9;
    local_24 = (*(float *)(DAT_0076a338 + 0x27ac) * fVar8 +
                *(float *)(DAT_0076a338 + 0x279c) * fVar10 +
                *(float *)(DAT_0076a338 + 0x27bc) * fVar11 + *(float *)(DAT_0076a338 + 0x27cc)) /
               fVar9 - 7.0;
    local_24 = local_24 + local_24;
    piVar5 = (int *)FUN_006badc0(&local_2c);
    if (local_3c != 0) {
      if (*piVar5 == 0) {
        Tcl_ResetResult(local_3c);
      }
      else {
        Tcl_SetObjResult(local_3c,*piVar5);
      }
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
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

