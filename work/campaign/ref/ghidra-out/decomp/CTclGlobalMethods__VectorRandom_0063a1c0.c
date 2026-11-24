
/* WARNING: Removing unreachable block (ram,0x0063a5d6) */
/* WARNING: Removing unreachable block (ram,0x0063a5e7) */
/* WARNING: Removing unreachable block (ram,0x0063a5ed) */

undefined4
CTclGlobalMethods__VectorRandom
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  float fVar6;
  undefined8 uVar7;
  int local_48;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  double local_2c;
  double local_24;
  undefined4 *local_1c;
  undefined8 local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a81d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6fb0) &&
     (FUN_006cebf4(&DAT_00ca6fb0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6fb0 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6fb4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::VectorRandom()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6fb0);
  }
  iVar3 = DAT_00ca6fb4;
  local_1c = &DAT_00ca6fb4;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6fb4 * 0x40);
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
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 4) {
    FUN_006bc8f0(3);
    uVar5 = 1;
  }
  else {
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_34 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_38 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 == (int *)0x0) {
      iVar2 = _rand();
      local_18 = (double)((float)iVar2 * 0.0) * 3.0517578125e-05;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar1,&local_2c);
      if (iVar2 == 1) {
        iVar2 = _rand();
        fVar6 = (float)iVar2 * 0.0;
      }
      else {
        fVar6 = (float)local_2c;
        iVar2 = _rand();
        fVar6 = (float)iVar2 * fVar6;
      }
      *piVar1 = *piVar1 + -1;
      local_18 = (double)fVar6 * 3.0517578125e-05;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    if (local_30 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_34 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_38 + 2;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 == (int *)0x0) {
      iVar2 = _rand();
      local_24 = (double)((float)iVar2 * 0.0) * 3.0517578125e-05;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar1,&local_2c);
      if (iVar2 == 1) {
        iVar2 = _rand();
        fVar6 = (float)iVar2 * 0.0;
      }
      else {
        fVar6 = (float)local_2c;
        iVar2 = _rand();
        fVar6 = (float)iVar2 * fVar6;
      }
      *piVar1 = *piVar1 + -1;
      local_24 = (double)fVar6 * 3.0517578125e-05;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    if (local_30 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_34 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_38 + 3;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 == (int *)0x0) {
      iVar2 = _rand();
      local_2c = (double)((float)iVar2 * 0.0) * 3.0517578125e-05;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar1,&local_2c);
      if (iVar2 == 1) {
        iVar2 = _rand();
        fVar6 = (float)iVar2 * 0.0;
      }
      else {
        iVar2 = _rand();
        fVar6 = (float)iVar2 * (float)local_2c;
      }
      *piVar1 = *piVar1 + -1;
      local_2c = (double)fVar6 * 3.0517578125e-05;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if ((local_18._4_4_ != (int *)0x0) &&
       (*local_18._4_4_ = *local_18._4_4_ + -1, *local_18._4_4_ < 1)) {
      TclFreeObj(local_18._4_4_);
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if ((local_18._4_4_ != (int *)0x0) &&
       (*local_18._4_4_ = *local_18._4_4_ + -1, *local_18._4_4_ < 1)) {
      TclFreeObj(local_18._4_4_);
    }
    uVar5 = FUN_006bad90();
    FUN_006bb930(uVar5);
    if ((local_18._4_4_ != (int *)0x0) &&
       (*local_18._4_4_ = *local_18._4_4_ + -1, *local_18._4_4_ < 1)) {
      TclFreeObj(local_18._4_4_);
    }
    if (local_48 == 0) {
      uVar5 = 0;
    }
    else {
      Tcl_ResetResult(local_48);
      uVar5 = 0;
    }
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

