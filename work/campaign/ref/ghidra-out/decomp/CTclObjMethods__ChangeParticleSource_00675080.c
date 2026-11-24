
undefined4
CTclObjMethods__ChangeParticleSource
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  uint uVar10;
  float fVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined1 local_a8 [12];
  double local_9c;
  double local_94;
  int *local_8c;
  int *local_88;
  int *local_84;
  undefined4 *local_80;
  undefined4 local_6c;
  int *piStack_68;
  int *local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  int *local_50;
  int *local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  uint local_3c;
  uint local_38;
  float local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  bool local_21;
  int local_20;
  undefined4 *local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007109db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca74c0) &&
     (FUN_006cebf4(&DAT_00ca74c0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca74c0 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca74c4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclObjMethods::ChangeParticleSource()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca74c0);
  }
  iVar5 = DAT_00ca74c4;
  local_80 = &DAT_00ca74c4;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca74c4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar4;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar12 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_20 = FUN_005c71c0(param_4,9,1);
  if (local_20 == 0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
    goto LAB_0067516a;
  }
  if (local_14 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_1c;
    if (local_18 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_1c;
    }
  }
  else {
    if (local_18 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_1c + 2;
  }
  piVar8 = (int *)*puVar9;
  if (piVar8 == (int *)0x0) {
    uVar10 = 0;
    local_38 = 0;
  }
  else {
    *piVar8 = *piVar8 + 1;
    iVar3 = Tcl_GetIntFromObj(0,piVar8,&local_2c);
    *piVar8 = *piVar8 + -1;
    uVar10 = -(uint)(iVar3 != 1) & (uint)local_2c;
    local_38 = uVar10;
    if (*piVar8 < 1) {
      TclFreeObj(piVar8);
    }
  }
  piVar8 = *(int **)(local_20 + 0x2b0);
  if (piVar8 == (int *)0x0) {
LAB_00675266:
    FUN_005d86f0(uVar10);
  }
  else {
    if (uVar10 < 0x20) {
      piVar8 = piVar8 + uVar10;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*piVar8 == -1) goto LAB_00675266;
  }
  if (local_14 < 5) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_1c;
    if (local_18 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_1c;
    }
  }
  else {
    if (local_18 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_1c + 4;
  }
  piVar8 = (int *)*puVar9;
  local_30 = piVar8;
  if (piVar8 == (int *)0x0) {
    FUN_006bafe0(&local_5c);
  }
  else {
    *piVar8 = *piVar8 + 1;
    FUN_006bafe0(&local_5c);
    *piVar8 = *piVar8 + -1;
    if (*piVar8 < 1) {
      TclFreeObj(piVar8);
    }
  }
  if (*(int *)(local_20 + 0x2b0) != 0) {
    puVar9 = (undefined4 *)(*(int *)(local_20 + 0x2b0) + 0x80);
    if (uVar10 < 0x20) {
      puVar9 = puVar9 + uVar10 * 3;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *puVar9 = local_5c;
    puVar9[1] = local_58;
    puVar9[2] = uStack_54;
  }
  uVar10 = 0xffffffff;
  if (9 < param_3) {
    if (local_14 < 10) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_1c;
      if (local_18 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar9 = local_1c;
      }
    }
    else {
      if (local_18 < 10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_1c + 9;
    }
    piVar8 = (int *)*puVar9;
    if (piVar8 == (int *)0x0) {
      uVar10 = 0;
    }
    else {
      *piVar8 = *piVar8 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar8,&local_2c);
      *piVar8 = *piVar8 + -1;
      uVar10 = -(uint)(iVar3 != 1) & (uint)local_2c;
      if (*piVar8 < 1) {
        TclFreeObj(piVar8);
      }
      if (((int)uVar10 < -1) || (0x1f < (int)uVar10)) {
        if (local_14 < 10) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar9 = local_1c;
          if (local_18 == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar9 = local_1c;
          }
        }
        else {
          if (local_18 < 10) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar9 = local_1c + 9;
        }
        piVar8 = (int *)*puVar9;
        if (piVar8 != (int *)0x0) {
          *piVar8 = *piVar8 + 1;
        }
        FUN_006bc6a0("invalid link ID: %s",piVar8);
        local_8._0_1_ = 5;
        FUN_004297b0(0);
        local_8 = CONCAT31(local_8._1_3_,6);
LAB_0067516a:
        FUN_004297b0(0);
        if (local_1c != (undefined4 *)0x0) {
          FUN_006ba940();
        }
        FUN_006bc0d0();
        FUN_0043fd30();
        ExceptionList = local_10;
        return 1;
      }
    }
  }
  FUN_005d8990(local_38,uVar10);
  local_30 = (int *)0x0;
  local_34 = 0.0;
  if (10 < param_3) {
    if (local_14 < 0xb) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_1c;
      if (local_18 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar9 = local_1c;
      }
    }
    else {
      if (local_18 < 0xb) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_1c + 10;
    }
    piVar8 = (int *)*puVar9;
    if (piVar8 == (int *)0x0) {
      local_34 = 0.0;
    }
    else {
      *piVar8 = *piVar8 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar8,&local_6c);
      if (iVar3 == 1) {
        local_34 = 0.0;
      }
      else {
        local_34 = (float)(double)CONCAT44(piStack_68,local_6c);
      }
      *piVar8 = *piVar8 + -1;
      if (*piVar8 < 1) {
        TclFreeObj(piVar8);
      }
    }
  }
  local_48 = 0xffffffff;
  local_44 = 0xffffffff;
  if (0xb < param_3) {
    if (local_14 < 0xc) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_1c;
      if (local_18 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar9 = local_1c;
      }
    }
    else {
      if (local_18 < 0xc) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_1c + 0xb;
    }
    piVar8 = (int *)*puVar9;
    if (piVar8 != (int *)0x0) {
      *piVar8 = *piVar8 + 1;
      iVar3 = Tcl_GetBooleanFromObj(0,piVar8,&local_2c);
      local_21 = iVar3 != 1 && local_2c != (int *)0x0;
      *piVar8 = *piVar8 + -1;
      if (*piVar8 < 1) {
        TclFreeObj(piVar8);
      }
      if ((local_21 != false) && (local_48 = *(undefined4 *)(local_20 + 0xdc), 0xc < param_3)) {
        puVar9 = (undefined4 *)FUN_004295e0(0xc);
        local_28 = (int *)*puVar9;
        if (local_28 != (int *)0x0) {
          *local_28 = *local_28 + 1;
        }
        local_44 = FUN_006baee0();
        FUN_006bad60();
      }
    }
  }
  uVar2 = local_38;
  FUN_005d8990(local_38,uVar10);
  if (local_14 < 5) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_1c;
    if (local_18 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_1c;
    }
  }
  else {
    if (local_18 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_1c + 4;
  }
  piVar8 = (int *)*puVar9;
  local_28 = piVar8;
  if (piVar8 == (int *)0x0) {
    uVar4 = FUN_006bafe0(&local_5c);
    FUN_005d8930(uVar2,uVar4);
  }
  else {
    *piVar8 = *piVar8 + 1;
    uVar4 = FUN_006bafe0(&local_5c);
    FUN_005d8930(uVar2,uVar4);
    *piVar8 = *piVar8 + -1;
    if (*piVar8 < 1) {
      TclFreeObj(piVar8);
    }
  }
  if (local_14 < 9) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_1c;
    if (local_18 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_1c;
    }
  }
  else {
    if (local_18 < 9) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_1c + 8;
  }
  local_84 = (int *)*puVar9;
  if (local_84 != (int *)0x0) {
    *local_84 = *local_84 + 1;
  }
  local_2c = local_84;
  if (local_14 < 8) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_1c;
    if (local_18 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_1c;
    }
  }
  else {
    if (local_18 < 8) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_1c + 7;
  }
  local_88 = (int *)*puVar9;
  if (local_88 != (int *)0x0) {
    *local_88 = *local_88 + 1;
  }
  local_4c = local_88;
  if (local_14 < 7) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_1c;
    if (local_18 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_1c;
    }
  }
  else {
    if (local_18 < 7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_1c + 6;
  }
  piVar8 = (int *)*puVar9;
  if (piVar8 != (int *)0x0) {
    *piVar8 = *piVar8 + 1;
  }
  local_8c = piVar8;
  if (local_14 < 6) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_1c;
    if (local_18 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_1c;
    }
  }
  else {
    if (local_18 < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_1c + 5;
  }
  local_64 = (int *)*puVar9;
  if (local_64 != (int *)0x0) {
    *local_64 = *local_64 + 1;
  }
  local_50 = local_64;
  if (local_14 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_1c;
    if (local_18 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_1c;
    }
  }
  else {
    if (local_18 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_1c + 3;
  }
  piVar1 = (int *)*puVar9;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,0xb);
  piStack_68 = piVar1;
  if (local_2c == (int *)0x0) {
    local_3c = local_3c & 0xffffff00;
  }
  else {
    iVar3 = Tcl_GetBooleanFromObj(0,local_2c,&local_60);
    if (iVar3 == 1) {
      local_3c = (uint)local_3c._1_3_ << 8;
    }
    else {
      local_3c = CONCAT31(local_3c._1_3_,local_60 != 0);
    }
  }
  if (local_4c == (int *)0x0) {
    local_40 = 0.0;
  }
  else {
    iVar3 = Tcl_GetDoubleFromObj(0,local_4c,&local_94);
    if (iVar3 == 1) {
      local_40 = 0.0;
    }
    else {
      local_40 = (float)local_94;
    }
  }
  fVar11 = 0.0;
  if (piVar8 != (int *)0x0) {
    iVar3 = Tcl_GetDoubleFromObj(0,piVar8,&local_9c);
    if (iVar3 == 1) {
      fVar11 = 0.0;
    }
    else {
      fVar11 = (float)local_9c;
    }
  }
  local_28 = (int *)fVar11;
  if (piVar1 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    iVar3 = Tcl_GetDoubleFromObj(0,piVar1,&local_58);
    piVar7 = piVar1;
    if (iVar3 == 1) {
      local_30 = (int *)0x0;
    }
    else {
      local_30 = (int *)(float)(double)CONCAT44(uStack_54,local_58);
    }
  }
  iVar3 = (int)local_40;
  uVar13 = 0;
  fVar11 = local_34 * local_34;
  iVar5 = (int)(float)local_28;
  uVar10 = local_3c;
  uVar4 = local_48;
  uVar14 = local_44;
  uVar6 = FUN_006bafe0(local_a8);
  FUN_005d8830(local_38,(int)(float)local_30,local_20 + 0xc,uVar6,iVar5,iVar3,uVar10,fVar11,uVar4,
               uVar13,uVar14);
  if ((piVar7 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  if ((local_50 != (int *)0x0) && (*local_50 = *local_50 + -1, *local_50 < 1)) {
    TclFreeObj(local_50);
  }
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
    TclFreeObj(piVar8);
  }
  if ((local_4c != (int *)0x0) && (*local_4c = *local_4c + -1, *local_4c < 1)) {
    TclFreeObj(local_4c);
  }
  local_8._0_1_ = 2;
  if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c < 1)) {
    TclFreeObj(local_2c);
  }
  FUN_005d89e0();
  local_8._0_1_ = 0xc;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  FUN_004297b0(0);
  if (local_1c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

