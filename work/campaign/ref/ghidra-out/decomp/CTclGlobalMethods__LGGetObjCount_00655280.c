
undefined4
CTclGlobalMethods__LGGetObjCount
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined8 uVar11;
  int local_48;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  int *local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ea45;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7260) &&
     (FUN_006cebf4(&DAT_00ca7260,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7260 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca7264 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::LGGetObjCount()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7260);
  }
  iVar5 = DAT_00ca7264;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7264 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar11 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
    iVar3 = FUN_0058a820();
    local_14 = 0;
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_34 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_38 + 1;
    }
    piVar6 = (int *)*puVar9;
    if (piVar6 != (int *)0x0) {
      *piVar6 = *piVar6 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (piVar6 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar6,0);
    }
    FUN_006b8fb0(ppuVar4);
    uVar7 = 0;
    if (0 < *(int *)(iVar3 + 0x1a0)) {
      bVar10 = *(int *)(iVar3 + 0x1a0) != 0;
LAB_006553f3:
      if (!bVar10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      cVar2 = FUN_006b97f0(&local_1c);
      if (cVar2 == '\0') goto code_r0x0065541c;
      local_14 = 0;
      local_18 = 0;
      if (0 < *(int *)(iVar3 + 0x188)) {
        bVar10 = *(int *)(iVar3 + 0x188) != 0;
        param_3 = 0;
        do {
          if (!bVar10) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar1 = *(uint *)(param_3 + *(int *)(iVar3 + 0x184));
          if (*(uint *)(iVar3 + 0x1a8) <= uVar1) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar5 = uVar1 * 0x54 + *(int *)(iVar3 + 0x1a4);
          if (*(uint *)(iVar5 + 0x38) <= uVar7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          param_3 = param_3 + 0x10;
          local_14 = local_14 + *(int *)(*(int *)(iVar5 + 0x34) + uVar7 * 4);
          local_18 = local_18 + 1;
          bVar10 = local_18 < *(uint *)(iVar3 + 0x188);
        } while ((int)local_18 < (int)*(uint *)(iVar3 + 0x188));
      }
      bVar10 = false;
      goto LAB_00655427;
    }
LAB_00655425:
    bVar10 = true;
LAB_00655427:
    local_8._0_1_ = 4;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
      TclFreeObj(piVar6);
    }
    if (bVar10) {
      FUN_006bc6a0("invalid leveltype",0);
      uVar8 = 1;
    }
    else {
      piVar6 = (int *)Tcl_NewIntObj(local_14);
      *piVar6 = *piVar6 + 1;
      iVar3 = *piVar6;
      if (local_48 != 0) {
        Tcl_SetObjResult(local_48,piVar6);
        iVar3 = *piVar6;
      }
      *piVar6 = iVar3 + -1;
      if (iVar3 + -1 < 1) {
        TclFreeObj(piVar6);
      }
      uVar8 = 0;
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar8 = 1;
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
code_r0x0065541c:
  uVar7 = uVar7 + 1;
  bVar10 = uVar7 < *(uint *)(iVar3 + 0x1a0);
  if ((int)*(uint *)(iVar3 + 0x1a0) <= (int)uVar7) goto LAB_00655425;
  goto LAB_006553f3;
}

