
undefined4
CTclGlobalMethods__SetViewPos(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  bool bVar8;
  float fVar9;
  float fVar10;
  double dVar11;
  double dVar12;
  int *piVar13;
  undefined8 uVar14;
  double local_ac;
  double local_a4;
  int *local_9c;
  int *local_98;
  int *local_94;
  int *local_90;
  int *local_8c;
  int *local_88;
  undefined4 *local_84;
  double local_70;
  double local_68;
  double local_60;
  undefined4 local_58;
  int *piStack_54;
  int *local_50;
  int *local_4c;
  int *local_48;
  int *local_44;
  float local_40;
  float local_3c;
  int local_38;
  float local_34;
  float local_30;
  int *local_2c;
  int *local_28;
  bool local_21;
  int *local_20;
  uint local_1c;
  int local_18;
  bool local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c49f;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d50) &&
     (FUN_006cebf4(&DAT_00ca6d50,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6d50 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6d54 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::SetViewPos()";
    *(int *)(&DAT_00773650 + iVar5) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d50);
  }
  iVar5 = DAT_00ca6d54;
  local_84 = &DAT_00ca6d54;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d54 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar4 == 0) {
    uVar14 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  iVar4 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if ((iVar4 != 7) && (iVar4 < 8)) {
    FUN_006bc8f0(6);
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
LAB_0062a0c5:
    FUN_004297b0(0);
    if (local_20 != (int *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  local_8._0_1_ = uVar2;
  if (local_18 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar6 = local_20;
    if (local_1c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar6 = local_20;
    }
  }
  else {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar6 = local_20 + 1;
  }
  piVar6 = (int *)*piVar6;
  if (piVar6 != (int *)0x0) {
    *piVar6 = *piVar6 + 1;
  }
  local_88 = piVar6;
  if (local_18 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar7 = local_20;
    if (local_1c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar7 = local_20;
    }
  }
  else {
    if (local_1c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar7 = local_20 + 2;
  }
  piVar7 = (int *)*piVar7;
  if (piVar7 != (int *)0x0) {
    *piVar7 = *piVar7 + 1;
  }
  local_8c = piVar7;
  if (local_18 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    local_90 = local_20;
    if (local_1c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_90 = local_20;
    }
  }
  else {
    if (local_1c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_90 = local_20 + 3;
  }
  local_90 = (int *)*local_90;
  if (local_90 != (int *)0x0) {
    *local_90 = *local_90 + 1;
  }
  local_50 = local_90;
  if (local_18 < 5) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    local_94 = local_20;
    if (local_1c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_94 = local_20;
    }
  }
  else {
    if (local_1c < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_94 = local_20 + 4;
  }
  local_94 = (int *)*local_94;
  if (local_94 != (int *)0x0) {
    *local_94 = *local_94 + 1;
  }
  local_4c = local_94;
  if (local_18 < 6) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    local_98 = local_20;
    if (local_1c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_98 = local_20;
    }
  }
  else {
    if (local_1c < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_98 = local_20 + 5;
  }
  local_98 = (int *)*local_98;
  if (local_98 != (int *)0x0) {
    *local_98 = *local_98 + 1;
  }
  local_48 = local_98;
  if (local_18 < 7) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    local_9c = local_20;
    if (local_1c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_9c = local_20;
    }
  }
  else {
    if (local_1c < 7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_9c = local_20 + 6;
  }
  local_9c = (int *)*local_9c;
  if (local_9c != (int *)0x0) {
    *local_9c = *local_9c + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,10);
  local_38 = *(int *)(DAT_00772400 + 0x5a4);
  local_44 = local_9c;
  if (piVar6 == (int *)0x0) {
    local_3c = 0.0;
  }
  else {
    iVar4 = Tcl_GetDoubleFromObj(0,piVar6,&local_68);
    if (iVar4 == 1) {
      local_3c = 0.0;
    }
    else {
      local_3c = (float)local_68;
    }
  }
  if (piVar7 == (int *)0x0) {
    local_40 = 0.0;
  }
  else {
    iVar4 = Tcl_GetDoubleFromObj(0,piVar7,&local_58);
    if (iVar4 == 1) {
      local_40 = 0.0;
    }
    else {
      local_40 = (float)(double)CONCAT44(piStack_54,local_58);
    }
  }
  if (local_50 == (int *)0x0) {
    local_28 = (int *)0x0;
  }
  else {
    iVar4 = Tcl_GetDoubleFromObj(0,local_50,&local_a4);
    if (iVar4 == 1) {
      local_28 = (int *)0x0;
    }
    else {
      local_28 = (int *)(float)local_a4;
    }
  }
  if (local_4c == (int *)0x0) {
    local_2c = (int *)0x0;
  }
  else {
    iVar4 = Tcl_GetDoubleFromObj(0,local_4c,&local_ac);
    if (iVar4 == 1) {
      local_2c = (int *)0x0;
    }
    else {
      local_2c = (int *)(float)local_ac;
    }
  }
  local_30 = 0.0;
  if (local_48 != (int *)0x0) {
    iVar4 = Tcl_GetDoubleFromObj(0,local_48,&local_70);
    if (iVar4 == 1) {
      local_30 = 0.0;
    }
    else {
      local_30 = (float)local_70;
    }
  }
  if (local_44 == (int *)0x0) {
    local_34 = 0.0;
  }
  else {
    iVar4 = Tcl_GetDoubleFromObj(0,local_44,&local_60);
    if (iVar4 == 1) {
      local_34 = 0.0;
    }
    else {
      local_34 = (float)local_60;
    }
  }
  piVar13 = (int *)6.0;
  if ((float)local_2c <= 6.0) {
    piVar13 = local_2c;
  }
  local_11 = false;
  fVar9 = 0.5;
  if (0.5 <= (float)piVar13) {
    fVar9 = (float)piVar13;
  }
  local_2c = (int *)0x3f333333;
  *(float *)(local_38 + 0x13c) = fVar9;
  if (*(char *)(DAT_00772400 + 0x8c) != '\0') {
    local_2c = (int *)0x3fe66666;
  }
  piVar13 = (int *)(local_34 * local_34 + local_30 * local_30);
  piStack_54 = piVar13;
  FUN_0040b7e0();
  if ((float)local_2c < (float)piVar13) {
    fVar9 = (float)piStack_54 + 0.0;
    FUN_0040b7e0();
    fVar10 = 0.0;
    if (fVar9 <= 0.0) {
      local_34 = 0.0;
    }
    else {
      fVar10 = local_30 / fVar9;
      local_34 = local_34 / fVar9;
    }
    local_30 = fVar10 * (float)local_2c;
    local_34 = local_34 * (float)local_2c;
  }
  dVar11 = (double)local_34;
  FUN_006f5ae0();
  dVar12 = (double)local_34;
  local_60 = dVar11;
  FUN_006f6ad0();
  local_68 = (14.0 - (double)(float)local_28) * 1.5;
  local_70 = local_68 / (local_60 / dVar12);
  dVar11 = (double)local_30;
  FUN_006f5ae0();
  dVar12 = (double)local_30;
  local_60 = dVar11;
  FUN_006f6ad0();
  local_68 = local_68 / (local_60 / dVar12);
  *(float *)(local_38 + 0x14c) = local_30;
  *(float *)(local_38 + 0x150) = local_34;
  if (7 < param_3) {
    if (local_18 < 8) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar13 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar13 = local_20;
      }
    }
    else {
      if (local_1c < 8) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar13 = local_20 + 7;
    }
    local_28 = (int *)*piVar13;
    if (local_28 == (int *)0x0) {
      local_11 = false;
    }
    else {
      *local_28 = *local_28 + 1;
      iVar4 = Tcl_GetBooleanFromObj(0,local_28,&piStack_54);
      local_11 = iVar4 != 1 && piStack_54 != (int *)0x0;
      *local_28 = *local_28 + -1;
      if (*local_28 < 1) {
        TclFreeObj(local_28);
      }
      if ((local_11 != false) && (8 < param_3)) {
        if (local_18 < 9) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar13 = local_20;
          if (local_1c == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar13 = local_20;
          }
        }
        else {
          if (local_1c < 9) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          piVar13 = local_20 + 8;
        }
        local_2c = (int *)*piVar13;
        if (local_2c != (int *)0x0) {
          *local_2c = *local_2c + 1;
          iVar4 = Tcl_GetBooleanFromObj(0,local_2c,&local_28);
          local_21 = iVar4 != 1 && local_28 != (int *)0x0;
          *local_2c = *local_2c + -1;
          if (*local_2c < 1) {
            TclFreeObj(local_2c);
          }
          iVar4 = DAT_00772400;
          if (local_21 != false) {
            *(undefined1 *)(DAT_00772400 + 0x8b) = 1;
            if (*(char *)(iVar4 + 0xa098) != '\0') {
              *(undefined1 *)(iVar4 + 0xa098) = 0;
            }
            *(undefined1 *)(local_38 + 0x148) = 1;
          }
        }
      }
    }
  }
  piVar13 = (int *)0x3f800000;
  if (9 < param_3) {
    if (local_18 < 10) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar13 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar13 = local_20;
      }
    }
    else {
      if (local_1c < 10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar13 = local_20 + 9;
    }
    piStack_54 = (int *)*piVar13;
    if (piStack_54 == (int *)0x0) {
      piVar13 = (int *)0x0;
    }
    else {
      *piStack_54 = *piStack_54 + 1;
      iVar4 = Tcl_GetDoubleFromObj(0,piStack_54,&local_60);
      if (iVar4 == 1) {
        local_28 = (int *)0x0;
      }
      else {
        local_28 = (int *)(float)local_60;
      }
      *piStack_54 = *piStack_54 + -1;
      piVar13 = local_28;
      if (*piStack_54 < 1) {
        TclFreeObj(piStack_54);
        piVar13 = local_28;
      }
    }
  }
  *(float *)(local_38 + 0x144) = (float)piVar13 + (float)piVar13;
  bVar8 = false;
  if (10 < param_3) {
    if (local_18 < 0xb) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar13 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar13 = local_20;
      }
    }
    else {
      if (local_1c < 0xb) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar13 = local_20 + 10;
    }
    if (*piVar13 == 0) {
      bVar8 = false;
    }
    else {
      iVar4 = Tcl_GetBooleanFromObj(0,*piVar13,&param_3);
      if (iVar4 == 1) {
        bVar8 = false;
      }
      else {
        bVar8 = param_3 != 0;
      }
    }
  }
  *(bool *)(local_38 + 0x140) = local_11;
  *(float *)(local_38 + 0x134) = local_3c - (float)(local_70 / 3.14159265359);
  *(float *)(local_38 + 0x138) = (float)(local_68 / 3.14159265359) + local_40;
  if (local_11 != false) {
    if (bVar8) {
      cVar3 = FUN_00463930();
      if (cVar3 == '\0') {
        FUN_006bc6a0("Invalid cameraset",0);
        if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 < 1)) {
          TclFreeObj(local_44);
        }
        if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 < 1)) {
          TclFreeObj(local_48);
        }
        if ((local_4c != (int *)0x0) && (*local_4c = *local_4c + -1, *local_4c < 1)) {
          TclFreeObj(local_4c);
        }
        if ((local_50 != (int *)0x0) && (*local_50 = *local_50 + -1, *local_50 < 1)) {
          TclFreeObj(local_50);
        }
        if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
          TclFreeObj(piVar7);
        }
        if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
          TclFreeObj(piVar6);
        }
        local_8._0_1_ = 0xb;
        FUN_004297b0(0);
        local_8 = CONCAT31(local_8._1_3_,0xc);
        goto LAB_0062a0c5;
      }
    }
    else {
      FUN_00463220();
      FUN_00463500();
      FUN_00463500();
    }
    iVar4 = DAT_00772400;
    *(undefined4 *)(local_38 + 0xf4) = *(undefined4 *)(local_38 + 0x154);
    *(undefined4 *)(local_38 + 0xf8) = *(undefined4 *)(local_38 + 0x158);
    *(undefined4 *)(local_38 + 0x10c) = *(undefined4 *)(local_38 + 0x160);
    *(undefined4 *)(local_38 + 0x110) = *(undefined4 *)(local_38 + 0x164);
    *(undefined4 *)(local_38 + 0x100) = *(undefined4 *)(local_38 + 0x134);
    *(undefined4 *)(local_38 + 0xfc) = *(undefined4 *)(local_38 + 0x15c);
    *(undefined4 *)(local_38 + 0x104) = *(undefined4 *)(local_38 + 0x138);
    *(undefined4 *)(local_38 + 0x118) = *(undefined4 *)(local_38 + 0x14c);
    *(undefined4 *)(local_38 + 0x114) = 0;
    *(undefined4 *)(local_38 + 0x108) = *(undefined4 *)(local_38 + 0x13c);
    *(undefined4 *)(local_38 + 0x11c) = *(undefined4 *)(local_38 + 0x150);
    *(undefined4 *)(local_38 + 0x120) = 0;
    *(float *)(local_38 + 0x130) = (float)*(double *)(iVar4 + 0xa088);
  }
  if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 < 1)) {
    TclFreeObj(local_44);
  }
  if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 < 1)) {
    TclFreeObj(local_48);
  }
  if ((local_4c != (int *)0x0) && (*local_4c = *local_4c + -1, *local_4c < 1)) {
    TclFreeObj(local_4c);
  }
  if ((local_50 != (int *)0x0) && (*local_50 = *local_50 + -1, *local_50 < 1)) {
    TclFreeObj(local_50);
  }
  if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
    TclFreeObj(piVar7);
  }
  if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
    TclFreeObj(piVar6);
  }
  local_8._0_1_ = 0xd;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xe);
  FUN_004297b0(0);
  if (local_20 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

