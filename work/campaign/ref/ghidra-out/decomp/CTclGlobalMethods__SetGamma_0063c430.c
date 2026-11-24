
undefined4
CTclGlobalMethods__SetGamma(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  GammaManager *this;
  int iVar5;
  code *pcVar6;
  undefined8 uVar7;
  int *local_48;
  uint local_44;
  int local_40;
  undefined4 local_38;
  float fStack_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined4 local_1c;
  float fStack_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar4 = (int)param_3;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d4ed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6ff8) &&
     (FUN_006cebf4(&DAT_00ca6ff8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6ff8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6ffc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::SetGamma()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6ff8);
  }
  iVar5 = DAT_00ca6ffc;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6ffc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  param_3 = 1.0;
  local_20 = 0.0;
  local_24 = 1.0;
  local_14 = 1.0;
  local_28 = 0.0;
  local_2c = 1.0;
  fStack_18 = 1.0;
  local_30 = 0.0;
  fStack_34 = 1.0;
  if (iVar4 == 10) {
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 1;
    }
    pcVar6 = Tcl_GetDoubleFromObj_exref;
    if (*piVar3 == 0) {
      local_20 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,*piVar3,&local_38);
      if (iVar4 == 1) {
        local_20 = 0.0;
      }
      else {
        local_20 = (float)(double)CONCAT44(fStack_34,local_38);
      }
    }
    local_20 = local_20 / 100.0;
    if (local_40 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 2;
    }
    if (*piVar3 == 0) {
      local_24 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,*piVar3,&local_38);
      if (iVar4 == 1) {
        local_24 = 0.0;
      }
      else {
        local_24 = (float)(double)CONCAT44(fStack_34,local_38);
      }
    }
    local_24 = local_24 / 100.0;
    if (local_40 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 3;
    }
    if (*piVar3 == 0) {
      param_3 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,*piVar3,&local_38);
      if (iVar4 == 1) {
        param_3 = 0.0;
      }
      else {
        param_3 = (float)(double)CONCAT44(fStack_34,local_38);
      }
    }
    param_3 = param_3 / 100.0;
    if (local_40 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 4;
    }
    if (*piVar3 == 0) {
      local_28 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,*piVar3,&local_38);
      if (iVar4 == 1) {
        local_28 = 0.0;
      }
      else {
        local_28 = (float)(double)CONCAT44(fStack_34,local_38);
      }
    }
    local_28 = local_28 / 100.0;
    if (local_40 < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 5;
    }
    if (*piVar3 == 0) {
      local_2c = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,*piVar3,&local_38);
      if (iVar4 == 1) {
        local_2c = 0.0;
      }
      else {
        local_2c = (float)(double)CONCAT44(fStack_34,local_38);
      }
    }
    local_2c = local_2c / 100.0;
    if (local_40 < 7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 6;
    }
    if (*piVar3 == 0) {
      local_14 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,*piVar3,&local_38);
      if (iVar4 == 1) {
        local_14 = 0.0;
      }
      else {
        local_14 = (float)(double)CONCAT44(fStack_34,local_38);
      }
    }
    local_14 = local_14 / 100.0;
    if (local_40 < 8) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 8) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 7;
    }
    if (*piVar3 == 0) {
      local_30 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,*piVar3,&local_38);
      if (iVar4 == 1) {
        local_30 = 0.0;
      }
      else {
        local_30 = (float)(double)CONCAT44(fStack_34,local_38);
      }
    }
    local_30 = local_30 / 100.0;
    if (local_40 < 9) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 9) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 8;
    }
    if (*piVar3 == 0) {
      fStack_34 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,*piVar3,&local_38);
      if (iVar4 == 1) {
        fStack_34 = 0.0;
      }
      else {
        fStack_34 = (float)(double)CONCAT44(fStack_34,local_38);
      }
    }
    fStack_34 = fStack_34 / 100.0;
    if (local_40 < 10) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 9;
    }
    iVar4 = *piVar3;
    if (iVar4 == 0) {
      fStack_18 = 0.0;
      goto LAB_0063cba6;
    }
  }
  else {
    if (iVar4 != 4) {
      if (iVar4 == 2) {
        if (local_40 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar3 = local_48;
          if (local_44 == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        else {
          if (local_44 < 2) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          piVar3 = local_48 + 1;
        }
        if (*piVar3 == 0) {
          param_3 = 0.0;
        }
        else {
          iVar4 = Tcl_GetDoubleFromObj(0,*piVar3,&local_1c);
          if (iVar4 == 1) {
            param_3 = 0.0;
          }
          else {
            param_3 = (float)(double)CONCAT44(fStack_18,local_1c);
          }
        }
        param_3 = param_3 / 100.0;
        fStack_18 = param_3;
        local_14 = param_3;
      }
      goto LAB_0063cba6;
    }
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 1;
    }
    pcVar6 = Tcl_GetDoubleFromObj_exref;
    if (*piVar3 == 0) {
      param_3 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,*piVar3,&local_1c);
      if (iVar4 == 1) {
        param_3 = 0.0;
      }
      else {
        param_3 = (float)(double)CONCAT44(fStack_18,local_1c);
      }
    }
    param_3 = param_3 / 100.0;
    if (local_40 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 2;
    }
    if (*piVar3 == 0) {
      local_14 = 0.0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,*piVar3,&local_1c);
      if (iVar4 == 1) {
        local_14 = 0.0;
      }
      else {
        local_14 = (float)(double)CONCAT44(fStack_18,local_1c);
      }
    }
    local_14 = local_14 / 100.0;
    if (local_40 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_48 + 3;
    }
    iVar4 = *piVar3;
    if (iVar4 == 0) {
      fStack_18 = 0.0;
      goto LAB_0063cba6;
    }
  }
  iVar4 = (*pcVar6)(0,iVar4,&local_1c);
  if (iVar4 == 1) {
    fStack_18 = 0.0;
  }
  else {
    fStack_18 = (float)(double)CONCAT44(fStack_18,local_1c) / 100.0;
  }
LAB_0063cba6:
  iVar4 = FUN_0044d010();
  *(float *)(iVar4 + 0x58) = local_20;
  *(float *)(iVar4 + 0x5c) = local_24;
  *(float *)(iVar4 + 0x60) = param_3;
  *(float *)(iVar4 + 100) = local_28;
  *(float *)(iVar4 + 0x68) = local_2c;
  *(float *)(iVar4 + 0x6c) = local_14;
  *(float *)(iVar4 + 0x70) = local_30;
  *(float *)(iVar4 + 0x74) = fStack_34;
  *(float *)(iVar4 + 0x78) = fStack_18;
  this = GammaManager::GetInstance();
  GammaManager::SetGammaBrightness(this,*(float *)(iVar4 + 0x60),*(float *)(iVar4 + 0x58));
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_48 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

