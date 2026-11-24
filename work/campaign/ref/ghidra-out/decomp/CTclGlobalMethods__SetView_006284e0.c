
undefined4
CTclGlobalMethods__SetView(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int *piVar10;
  code *pcVar11;
  float fVar12;
  int *piVar13;
  undefined8 uVar14;
  int *local_58;
  uint local_54;
  int local_50;
  undefined4 local_38;
  int *piStack_34;
  int *local_30;
  undefined4 local_2c;
  int *piStack_28;
  undefined4 local_24;
  int *piStack_20;
  float local_1c;
  int local_18;
  char local_13;
  bool local_12;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c2f5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d20) &&
     (FUN_006cebf4(&DAT_00ca6d20,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6d20 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6d24 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::SetView()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d20);
  }
  iVar7 = DAT_00ca6d24;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d24 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar8;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar14 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  iVar4 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((iVar4 != 4) && (iVar4 < 6)) {
    FUN_006bc8f0(3);
    uVar8 = 1;
    goto LAB_00628d35;
  }
  if (local_50 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar9 = local_58;
    if (local_54 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_54 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar9 = local_58 + 1;
  }
  piVar9 = (int *)*piVar9;
  if (piVar9 != (int *)0x0) {
    *piVar9 = *piVar9 + 1;
  }
  if (local_50 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar10 = local_58;
    if (local_54 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_54 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar10 = local_58 + 2;
  }
  piVar10 = (int *)*piVar10;
  if (piVar10 != (int *)0x0) {
    *piVar10 = *piVar10 + 1;
  }
  if (local_50 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar5 = local_58;
    if (local_54 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_54 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar5 = local_58 + 3;
  }
  piVar5 = (int *)*piVar5;
  if (piVar5 != (int *)0x0) {
    *piVar5 = *piVar5 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  local_18 = *(int *)(DAT_00772400 + 0x5a4);
  if (piVar9 == (int *)0x0) {
    fVar12 = 0.0;
  }
  else {
    iVar4 = Tcl_GetDoubleFromObj(0,piVar9,&local_38);
    if (iVar4 == 1) {
      fVar12 = 0.0;
    }
    else {
      fVar12 = (float)(double)CONCAT44(piStack_34,local_38);
    }
  }
  *(float *)(local_18 + 0x134) = fVar12;
  if (piVar10 == (int *)0x0) {
    fVar12 = 0.0;
  }
  else {
    iVar4 = Tcl_GetDoubleFromObj(0,piVar10,&local_38);
    if (iVar4 == 1) {
      fVar12 = 0.0;
    }
    else {
      fVar12 = (float)(double)CONCAT44(piStack_34,local_38);
    }
  }
  *(float *)(local_18 + 0x138) = fVar12;
  if (piVar5 == (int *)0x0) {
    fVar12 = 0.0;
  }
  else {
    iVar4 = Tcl_GetDoubleFromObj(0,piVar5,&local_38);
    if (iVar4 == 1) {
      fVar12 = 0.0;
    }
    else {
      fVar12 = (float)(double)CONCAT44(piStack_34,local_38);
    }
  }
  local_11 = '\0';
  *(float *)(local_18 + 0x13c) = fVar12;
  local_12 = false;
  local_1c = 1.0;
  if (5 < param_3) {
    if (local_50 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piStack_34 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piStack_34 = local_58 + 4;
    }
    piStack_34 = (int *)*piStack_34;
    if (piStack_34 != (int *)0x0) {
      *piStack_34 = *piStack_34 + 1;
    }
    if (local_50 < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_30 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_30 = local_58 + 5;
    }
    local_30 = (int *)*local_30;
    if (local_30 != (int *)0x0) {
      *local_30 = *local_30 + 1;
    }
    if (piStack_34 == (int *)0x0) {
      piStack_20 = (int *)0x0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,piStack_34,&local_2c);
      if (iVar4 == 1) {
        piStack_20 = (int *)0x0;
      }
      else {
        piStack_20 = (int *)(float)(double)CONCAT44(piStack_28,local_2c);
      }
    }
    if (local_30 == (int *)0x0) {
      piVar13 = (int *)0x0;
    }
    else {
      iVar4 = Tcl_GetDoubleFromObj(0,local_30,&local_2c);
      if (iVar4 == 1) {
        piVar13 = (int *)0x0;
      }
      else {
        piVar13 = (int *)(float)(double)CONCAT44(piStack_28,local_2c);
      }
    }
    piVar2 = piStack_20;
    fVar12 = (float)piVar13 * (float)piVar13 + (float)piStack_20 * (float)piStack_20;
    piStack_28 = piVar13;
    FUN_0040b7e0();
    piVar1 = piStack_28;
    if (1.8 < fVar12) {
      FUN_00410a20();
      piStack_20 = (int *)((float)piVar2 * 1.8);
      piVar1 = (int *)((float)piVar13 * 1.8);
    }
    *(int **)(local_18 + 0x14c) = piStack_20;
    *(int **)(local_18 + 0x150) = piVar1;
    if (6 < param_3) {
      if (local_50 < 7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar13 = local_58;
        if (local_54 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_54 < 7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar13 = local_58 + 6;
      }
      piStack_20 = (int *)*piVar13;
      if (piStack_20 == (int *)0x0) {
        local_12 = false;
      }
      else {
        *piStack_20 = *piStack_20 + 1;
        iVar4 = Tcl_GetBooleanFromObj(0,piStack_20,&piStack_28);
        local_12 = iVar4 != 1 && piStack_28 != (int *)0x0;
        *piStack_20 = *piStack_20 + -1;
        if (*piStack_20 < 1) {
          TclFreeObj(piStack_20);
        }
        if ((local_12 != false) && (7 < param_3)) {
          puVar6 = (undefined4 *)FUN_004295e0(7);
          piStack_28 = (int *)*puVar6;
          piStack_20 = piStack_28;
          if (piStack_28 == (int *)0x0) {
            cVar3 = FUN_006baf10();
          }
          else {
            *piStack_28 = *piStack_28 + 1;
            local_13 = FUN_006baf10();
            *piStack_20 = *piStack_20 + -1;
            cVar3 = local_13;
            if (*piStack_20 < 1) {
              TclFreeObj(piStack_20);
              cVar3 = local_13;
            }
          }
          iVar4 = DAT_00772400;
          if (cVar3 != '\0') {
            *(undefined1 *)(DAT_00772400 + 0x8b) = 1;
            if (*(char *)(iVar4 + 0xa098) != '\0') {
              *(undefined1 *)(iVar4 + 0xa098) = 0;
            }
            *(undefined1 *)(local_18 + 0x148) = 1;
          }
        }
      }
    }
    if (8 < param_3) {
      if (local_50 < 9) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar13 = local_58;
        if (local_54 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_54 < 9) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar13 = local_58 + 8;
      }
      piStack_28 = (int *)*piVar13;
      if (piStack_28 == (int *)0x0) {
        local_1c = 0.0;
      }
      else {
        *piStack_28 = *piStack_28 + 1;
        iVar4 = Tcl_GetDoubleFromObj(0,piStack_28,&local_24);
        if (iVar4 == 1) {
          local_1c = 0.0;
        }
        else {
          local_1c = (float)(double)CONCAT44(piStack_20,local_24);
        }
        *piStack_28 = *piStack_28 + -1;
        if (*piStack_28 < 1) {
          TclFreeObj(piStack_28);
        }
      }
    }
    if (9 < param_3) {
      if (local_50 < 10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar13 = local_58;
        if (local_54 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_54 < 10) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar13 = local_58 + 9;
      }
      if (*piVar13 == 0) {
        local_11 = '\0';
      }
      else {
        iVar4 = Tcl_GetBooleanFromObj(0,*piVar13,&param_3);
        if (iVar4 == 1) {
          local_11 = '\0';
        }
        else {
          local_11 = param_3 != 0;
        }
      }
    }
    if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 < 1)) {
      TclFreeObj(local_30);
    }
    if ((piStack_34 != (int *)0x0) && (*piStack_34 = *piStack_34 + -1, *piStack_34 < 1)) {
      TclFreeObj(piStack_34);
    }
  }
  iVar4 = local_18;
  *(bool *)(local_18 + 0x140) = local_12;
  *(float *)(local_18 + 0x144) = local_1c + local_1c;
  if (local_12 == false) {
LAB_00628cc1:
    uVar8 = 0;
  }
  else {
    if (local_11 == '\0') {
      FUN_00463220();
      FUN_00463500();
      FUN_00463500();
LAB_00628bf4:
      iVar7 = DAT_00772400;
      *(undefined4 *)(iVar4 + 0xf4) = *(undefined4 *)(iVar4 + 0x154);
      *(undefined4 *)(iVar4 + 0xf8) = *(undefined4 *)(iVar4 + 0x158);
      *(undefined4 *)(iVar4 + 0x10c) = *(undefined4 *)(iVar4 + 0x160);
      *(undefined4 *)(iVar4 + 0x110) = *(undefined4 *)(iVar4 + 0x164);
      *(undefined4 *)(iVar4 + 0x100) = *(undefined4 *)(iVar4 + 0x134);
      *(undefined4 *)(iVar4 + 0xfc) = *(undefined4 *)(iVar4 + 0x15c);
      *(undefined4 *)(iVar4 + 0x104) = *(undefined4 *)(iVar4 + 0x138);
      *(undefined4 *)(iVar4 + 0x118) = *(undefined4 *)(iVar4 + 0x14c);
      *(undefined4 *)(iVar4 + 0x114) = 0;
      *(undefined4 *)(iVar4 + 0x108) = *(undefined4 *)(iVar4 + 0x13c);
      *(undefined4 *)(iVar4 + 0x11c) = *(undefined4 *)(iVar4 + 0x150);
      *(undefined4 *)(iVar4 + 0x120) = 0;
      *(float *)(iVar4 + 0x130) = (float)*(double *)(iVar7 + 0xa088);
      goto LAB_00628cc1;
    }
    cVar3 = FUN_00463930();
    if (cVar3 == '\0') goto LAB_00628bf4;
    FUN_006bc6a0("Invalid cameraset",0);
    uVar8 = 1;
  }
  if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
    TclFreeObj(piVar5);
  }
  pcVar11 = TclFreeObj_exref;
  if ((piVar10 != (int *)0x0) &&
     (*piVar10 = *piVar10 + -1, pcVar11 = TclFreeObj_exref, *piVar10 < 1)) {
    TclFreeObj(piVar10);
  }
  if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
    (*pcVar11)(piVar9);
  }
LAB_00628d35:
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_58 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

