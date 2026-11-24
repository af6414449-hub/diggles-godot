
undefined4
CTclGlobalMethods__ShowLoading
          (undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4)

{
  int *piVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  bool bVar8;
  float in_XMM0_Da;
  undefined8 uVar9;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  int local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c565;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  bVar3 = false;
  local_24 = 0;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d70) &&
     (FUN_006cebf4(&DAT_00ca6d70,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6d70 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6d74 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::ShowLoading()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d70);
  }
  iVar6 = DAT_00ca6d74;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d74 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar7;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar9 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)param_3 < 2) {
    FUN_006bc8f0(1);
    uVar7 = 1;
    goto LAB_0062b481;
  }
  if (local_30 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_38;
    if (local_34 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_34 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_38 + 1;
  }
  piVar1 = (int *)*puVar5;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (piVar1 == (int *)0x0) {
    bVar8 = false;
  }
  else {
    iVar4 = Tcl_GetBooleanFromObj(0,piVar1,&local_24);
    if (iVar4 == 1) {
      bVar8 = false;
    }
    else {
      bVar8 = local_24 != 0;
    }
  }
  if ((DAT_0076a338 != 0) && (*(bool *)(DAT_0076a338 + 0x2839) = bVar8, bVar8 != false)) {
    if (param_3 == 4.2039e-45) {
      puVar5 = (undefined4 *)FUN_004295e0(2);
      local_20 = (int *)*puVar5;
      if (local_20 != (int *)0x0) {
        *local_20 = *local_20 + 1;
      }
      FUN_006baf80();
      if (in_XMM0_Da < 0.0) {
LAB_0062b39d:
        puVar5 = (undefined4 *)FUN_004295e0(2);
        local_18 = (int *)*puVar5;
        if (local_18 != (int *)0x0) {
          *local_18 = *local_18 + 1;
        }
        bVar2 = true;
        bVar8 = false;
        FUN_006baf80();
        if (0.0 <= in_XMM0_Da) {
          puVar5 = (undefined4 *)FUN_004295e0(2);
          local_14 = (int *)*puVar5;
          if (local_14 != (int *)0x0) {
            *local_14 = *local_14 + 1;
          }
          bVar2 = true;
          bVar8 = true;
          FUN_006baf80();
          param_3 = in_XMM0_Da;
        }
        else {
          param_3 = 0.0;
        }
      }
      else {
        puVar5 = (undefined4 *)FUN_004295e0(2);
        local_1c = (int *)*puVar5;
        if (local_1c != (int *)0x0) {
          *local_1c = *local_1c + 1;
        }
        bVar3 = true;
        bVar2 = false;
        bVar8 = false;
        FUN_006baf80();
        param_3 = 1.0;
        if (in_XMM0_Da <= 1.0) goto LAB_0062b39d;
      }
      if (bVar8) {
        FUN_006bad60();
      }
      if (bVar2) {
        FUN_006bad60();
      }
      if (bVar3) {
        FUN_006bad60();
      }
      FUN_006bad60();
      DAT_00772dd8 = (int)ROUND((float)*(int *)(DAT_00772400 + 0x5bc) * param_3);
      *(int *)(DAT_00772400 + 0x5b8) = DAT_00772dd8;
    }
    FUN_00479c10(1,1);
  }
  uVar7 = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_0062b481:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

