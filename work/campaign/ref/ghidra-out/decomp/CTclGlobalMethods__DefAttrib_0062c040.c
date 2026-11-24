
undefined4
CTclGlobalMethods__DefAttrib(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  float fVar8;
  undefined8 uVar9;
  int *piVar10;
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  undefined4 local_2c;
  float fStack_28;
  undefined4 local_24;
  float fStack_20;
  undefined4 local_1c;
  int *piStack_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c6a5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d98) &&
     (FUN_006cebf4(&DAT_00ca6d98,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6d98 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6d9c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::DefAttrib()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d98);
  }
  iVar4 = DAT_00ca6d9c;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d9c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 5) {
    FUN_006bc8f0(4);
    uVar5 = 1;
  }
  else {
    if (local_38 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_3c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_40 + 1;
    }
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (local_38 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_3c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_40 + 2;
    }
    piVar10 = (int *)*puVar7;
    if (piVar10 == (int *)0x0) {
      local_14 = 0.0;
      fStack_28 = 0.0;
    }
    else {
      *piVar10 = *piVar10 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar10,&local_2c);
      fVar8 = 0.0;
      local_14 = 0.0;
      if (iVar2 != 1) {
        fVar8 = (float)(double)CONCAT44(fStack_28,local_2c);
      }
      *piVar10 = *piVar10 + -1;
      fStack_28 = fVar8;
      if (*piVar10 < 1) {
        TclFreeObj(piVar10);
      }
    }
    if (local_38 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_3c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_40 + 3;
    }
    piVar10 = (int *)*puVar7;
    if (piVar10 == (int *)0x0) {
      fStack_20 = 0.0;
    }
    else {
      *piVar10 = *piVar10 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar10,&local_24);
      if (iVar2 == 1) {
        fStack_20 = 0.0;
      }
      else {
        fStack_20 = (float)(double)CONCAT44(fStack_20,local_24);
      }
      *piVar10 = *piVar10 + -1;
      if (*piVar10 < 1) {
        TclFreeObj(piVar10);
      }
    }
    if (local_38 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_3c < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_40 + 4;
    }
    piVar10 = (int *)*puVar7;
    if (piVar10 == (int *)0x0) {
      local_14 = 0.0;
    }
    else {
      *piVar10 = *piVar10 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar10,&local_1c);
      if (iVar2 != 1) {
        local_14 = (float)(double)CONCAT44(piStack_18,local_1c);
      }
      *piVar10 = *piVar10 + -1;
      if (*piVar10 < 1) {
        TclFreeObj(piVar10);
      }
    }
    piStack_18 = (int *)FUN_006ba810(0x19);
    piStack_18[1] = 4;
    *(undefined1 *)(piStack_18 + 3) = 0;
    piStack_18[2] = 0;
    *piStack_18 = 1;
    local_8 = CONCAT31(local_8._1_3_,4);
    if (param_3 == 6) {
      if (local_38 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_40;
        if (local_3c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_3c < 6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar7 = local_40 + 5;
      }
      piVar10 = (int *)*puVar7;
      if (piVar10 != (int *)0x0) {
        *piVar10 = *piVar10 + 1;
      }
      local_8._0_1_ = 5;
      if (piVar10 == (int *)0x0) {
        ppuVar3 = &PTR_0071ce50;
        piVar6 = (int *)0x0;
      }
      else {
        ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar10,0);
        piVar6 = piVar10;
      }
      FUN_006b9200(ppuVar3);
      local_8 = CONCAT31(local_8._1_3_,4);
      if ((piVar6 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
        TclFreeObj(piVar10);
      }
    }
    piVar6 = piStack_18;
    piVar10 = piStack_18 + 3;
    if (piVar1 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    fVar8 = local_14;
    FUN_005da0f0(ppuVar3,local_14,piVar10);
    FUN_005da380(ppuVar3,fVar8,piVar10);
    uVar5 = 0;
    local_8 = CONCAT31(local_8._1_3_,6);
    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
      FUN_006ba940();
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_40 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

