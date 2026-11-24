
undefined4
CTclObjMethods__SetFogOfWar
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  float fVar5;
  undefined8 uVar6;
  int *local_34;
  uint local_30;
  int local_2c;
  double local_28;
  undefined4 *local_20;
  undefined4 local_1c;
  int *piStack_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007116fd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7848) &&
     (FUN_006cebf4(&DAT_00ca7848,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7848 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca784c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::SetFogOfWar()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7848);
  }
  iVar3 = DAT_00ca784c;
  local_20 = &DAT_00ca784c;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca784c * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar6 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,4,1);
  if (iVar1 == 0) {
    uVar4 = 1;
  }
  else {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar2 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar2 = local_34 + 2;
    }
    if (*piVar2 == 0) {
      local_14 = (int *)0x0;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,*piVar2,&local_1c);
      if (iVar3 == 1) {
        local_14 = (int *)0x0;
      }
      else {
        local_14 = (int *)(float)(double)CONCAT44(piStack_18,local_1c);
      }
    }
    if (local_2c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar2 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar2 = local_34 + 3;
    }
    if (*piVar2 == 0) {
      piStack_18 = (int *)0x0;
    }
    else {
      iVar3 = Tcl_GetDoubleFromObj(0,*piVar2,&local_1c);
      if (iVar3 == 1) {
        piStack_18 = (int *)0x0;
      }
      else {
        piStack_18 = (int *)(float)(double)CONCAT44(piStack_18,local_1c);
      }
    }
    if (((float)local_14 == -1.0) || ((float)piStack_18 == -1.0)) {
      *(undefined4 *)(iVar1 + 0x364) = 0xffffffff;
      *(undefined4 *)(iVar1 + 0x368) = 0xffffffff;
    }
    else {
      piVar2 = (int *)FUN_006bad90();
      if (*piVar2 == 0) {
        fVar5 = 0.0;
      }
      else {
        iVar3 = Tcl_GetDoubleFromObj(0,*piVar2,&local_28);
        if (iVar3 == 1) {
          fVar5 = 0.0;
        }
        else {
          fVar5 = (float)local_28;
        }
      }
      *(int *)(iVar1 + 0x364) = (int)(fVar5 * 8.0);
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
        TclFreeObj(local_14);
      }
      piVar2 = (int *)FUN_006bad90();
      if (*piVar2 == 0) {
        fVar5 = 0.0;
      }
      else {
        iVar3 = Tcl_GetDoubleFromObj(0,*piVar2,&local_28);
        if (iVar3 == 1) {
          fVar5 = 0.0;
        }
        else {
          fVar5 = (float)local_28;
        }
      }
      *(int *)(iVar1 + 0x368) = (int)(fVar5 * 8.0);
      if ((piStack_18 != (int *)0x0) && (*piStack_18 = *piStack_18 + -1, *piStack_18 < 1)) {
        TclFreeObj(piStack_18);
      }
    }
    uVar4 = 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_34 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

