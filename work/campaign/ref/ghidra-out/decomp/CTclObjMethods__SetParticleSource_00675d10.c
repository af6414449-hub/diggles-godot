
undefined4
CTclObjMethods__SetParticleSource
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined1 local_58 [12];
  float local_4c;
  float local_48;
  float local_44;
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  int *local_34;
  undefined4 *local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined4 *local_20;
  int *local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710a85;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca74d0) &&
     (FUN_006cebf4(&DAT_00ca74d0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca74d0 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca74d4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::SetParticleSource()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca74d0);
  }
  iVar5 = DAT_00ca74d4;
  local_30 = &DAT_00ca74d4;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca74d4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_20 = (undefined4 *)FUN_005c71c0(param_4,4,1);
  if (local_20 == (undefined4 *)0x0) {
    uVar6 = 1;
    local_20 = (undefined4 *)0x0;
  }
  else {
    if (local_38 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_40;
      }
    }
    else {
      if (local_3c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_40 + 2;
    }
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_34 = piVar1;
    if (local_38 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_40;
      }
    }
    else {
      if (local_3c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_40 + 3;
    }
    piVar2 = (int *)*puVar7;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_1c = piVar2;
    if (piVar1 == (int *)0x0) {
      local_14 = 0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_18);
      local_14 = -(uint)(iVar3 != 1) & local_18;
    }
    pfVar4 = (float *)FUN_006bafe0(local_58);
    local_20 = *(undefined4 **)((int)local_20 + 0x2b0);
    if (local_20 != (undefined4 *)0x0) {
      local_4c = *pfVar4;
      local_48 = pfVar4[1];
      local_44 = pfVar4[2];
      local_8 = CONCAT31(local_8._1_3_,5);
      local_2c = local_44;
      local_28 = local_48;
      local_24 = local_4c;
      if (local_14 < 0x20) {
        local_20 = local_20 + local_14;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_20 = (undefined4 *)*local_20;
      local_1c = (int *)FUN_00492250();
      if (-1 < (int)local_20) {
        if ((int)local_20 < local_1c[0x22e]) {
          iVar3 = (int)local_20 * 0x88 + local_1c[0x22d];
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = local_1c[0x22d];
        }
        *(float *)(iVar3 + 0x30) = local_24 + *(float *)(iVar3 + 0x30);
        *(float *)(iVar3 + 0x34) = *(float *)(iVar3 + 0x34) + local_28;
        *(float *)(iVar3 + 0x38) = local_2c + *(float *)(iVar3 + 0x38);
      }
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar6 = 0;
  }
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_40 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

