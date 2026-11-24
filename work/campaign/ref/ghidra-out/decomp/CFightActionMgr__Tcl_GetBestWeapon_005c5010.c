
undefined4
CFightActionMgr__Tcl_GetBestWeapon
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  float fVar11;
  float fVar12;
  undefined8 uVar13;
  char *pcVar14;
  int local_78;
  undefined4 *local_68;
  uint local_64;
  int local_60;
  int local_5c;
  float local_58;
  int *local_50;
  float local_4c;
  int *local_48;
  float local_44;
  int *local_40;
  int *local_3c;
  undefined4 local_38;
  float local_34;
  int *local_30;
  float local_2c;
  int *local_28;
  float local_24;
  int *local_20;
  float local_1c;
  int local_18;
  bool local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00708175;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6608) &&
     (FUN_006cebf4(&DAT_00ca6608,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6608 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca660c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CFightActionMgr::Tcl_GetBestWeapon()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6608);
  }
  iVar3 = DAT_00ca660c;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca660c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar4;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar13 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_18 = FUN_005c71c0(param_4,2,1);
  if (local_18 == 0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_004297b0(0);
    if (local_68 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  local_11 = false;
  if (param_3 == 3) {
    if (local_60 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_68;
      if (local_64 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_64 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_68 + 2;
    }
    piVar7 = (int *)*puVar6;
    if (piVar7 == (int *)0x0) {
      local_11 = false;
    }
    else {
      *piVar7 = *piVar7 + 1;
      iVar2 = Tcl_GetBooleanFromObj(0,piVar7,&local_48);
      local_11 = iVar2 != 1 && local_48 != (int *)0x0;
      *piVar7 = *piVar7 + -1;
      if (*piVar7 < 1) {
        TclFreeObj(piVar7);
      }
    }
  }
  local_38 = 0xffffffff;
  local_48 = (int *)0xffffffff;
  FUN_0040ba00();
  local_8 = CONCAT31(local_8._1_3_,5);
  iVar2 = FUN_005bbb20();
  piVar7 = (int *)0x0;
  local_20 = (int *)0x0;
  iVar3 = FUN_005cf210();
  if (0 < iVar3) {
    do {
      local_3c = (int *)FUN_005cef70(piVar7);
      if ((local_3c != (int *)0x0) && (uVar8 = 0, piVar7 = local_20, 0 < *(int *)(iVar2 + 0xc))) {
        local_24 = 0.0;
        do {
          if (*(uint *)(iVar2 + 0xc) <= uVar8) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          cVar1 = FUN_006b97f0(local_3c[0x35] + 0xc);
          if (cVar1 != '\0') {
            if (*(uint *)(iVar2 + 0xc) <= uVar8) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar3 = *(int *)(iVar2 + 8);
            if (*(char *)(iVar3 + 4 + (int)local_24) != '\0') {
              if (*(uint *)(iVar2 + 0xc) <= uVar8) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar3 = *(int *)(iVar2 + 8);
              }
              if (local_11 == 1.0 < *(float *)(iVar3 + 8 + (int)local_24)) {
                local_44 = (float)FUN_0040b580();
                if ((uint)local_58 <= (uint)local_44) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                *(uint *)(local_5c + (int)local_44 * 4) = (int)local_20 << 0x10 | uVar8;
                piVar7 = local_20;
                break;
              }
            }
          }
          uVar8 = uVar8 + 1;
          local_24 = (float)((int)local_24 + 0x40);
          piVar7 = local_20;
        } while ((int)uVar8 < *(int *)(iVar2 + 0xc));
      }
      piVar7 = (int *)((int)piVar7 + 1);
      local_20 = piVar7;
      iVar3 = FUN_005cf210();
    } while ((int)piVar7 < iVar3);
  }
  piVar7 = (int *)0xffffffff;
  local_20 = (int *)0xffffffff;
  local_28 = (int *)0xffffffff;
  local_2c = 0.0;
  local_34 = 0.0;
  if ((int)local_58 < 1) {
    local_2c = 0.0;
LAB_005c5620:
    FUN_0040b980(0);
    if (local_11 == false) goto LAB_005c5634;
  }
  else {
    do {
      fVar11 = 0.1;
      local_1c = 0.1;
      if ((uint)local_58 <= (uint)local_34) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar8 = *(uint *)(local_5c + (int)local_34 * 4);
      piVar7 = (int *)(uVar8 & 0xffff);
      local_30 = piVar7;
      if ((uint)local_58 <= (uint)local_34) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar8 = *(uint *)(local_5c + (int)local_34 * 4);
      }
      local_40 = (int *)((int)uVar8 >> 0x10);
      if (*(int **)(iVar2 + 0xc) <= piVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_24 = (float)((int)piVar7 * 0x40);
      switch(*(undefined4 *)(*(int *)(iVar2 + 8) + 0x28 + (int)local_24)) {
      case 1:
        pcVar14 = "exp_F_Kungfu";
        break;
      case 2:
        pcVar14 = "exp_F_Sword";
        break;
      case 3:
        pcVar14 = "exp_F_Twohanded";
        break;
      case 4:
        pcVar14 = "exp_F_Ballistic";
        break;
      case 5:
        pcVar14 = "exp_F_Defense";
        break;
      default:
        goto switchD_005c53a7_default;
      }
      FUN_005dae40(pcVar14);
      local_1c = fVar11;
switchD_005c53a7_default:
      if (*(int **)(iVar2 + 0xc) <= piVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar3 = *(int *)(iVar2 + 8);
      fVar11 = local_1c;
      if (*(float *)(iVar3 + 0x14 + (int)local_24) <= local_1c) {
        piVar5 = *(int **)(iVar2 + 0xc);
        local_3c = (int *)0x3f800000;
        if (piVar5 <= piVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar3 = *(int *)(iVar2 + 8);
          piVar5 = *(int **)(iVar2 + 0xc);
        }
        if (-1 < *(int *)(iVar3 + 0x30 + (int)local_24)) {
          if (piVar5 <= piVar7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(iVar2 + 8);
          }
          if (*(uint *)(iVar2 + 0x1c) <= *(uint *)(iVar3 + 0x30 + (int)local_24)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          cVar1 = FUN_005c4310(local_18);
          piVar7 = local_30;
          if (cVar1 != '\0') {
            piVar7 = *(int **)(iVar2 + 0xc);
            if (piVar7 <= local_30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar7 = *(int **)(iVar2 + 0xc);
            }
            iVar3 = *(int *)(iVar2 + 8);
            local_44 = (float)((int)local_24 + iVar3);
            if (piVar7 <= local_30) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar3 = *(int *)(iVar2 + 8);
            }
            uVar8 = *(uint *)(iVar3 + 0x30 + (int)local_24);
            if (*(uint *)(iVar2 + 0x1c) <= uVar8) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar3 = uVar8 * 0x10 + *(int *)(iVar2 + 0x18);
            local_44 = *(float *)((int)local_44 + 0x34);
            if ((uint)*(float *)(iVar3 + 0xc) <= (uint)local_44) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            local_3c = *(int **)(*(int *)(iVar3 + 8) + (int)local_44 * 4);
            piVar7 = local_30;
          }
        }
        if (*(int **)(iVar2 + 0xc) <= piVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        fVar11 = *(float *)((int)local_24 + 0xc + *(int *)(iVar2 + 8)) * (float)local_3c;
        FUN_0040b7e0();
        if (local_2c < fVar11) {
          local_20 = local_40;
          local_2c = fVar11;
          local_28 = piVar7;
        }
      }
      piVar5 = local_20;
      local_34 = (float)((int)local_34 + 1);
      local_3c = local_28;
    } while ((int)local_34 < (int)local_58);
    piVar7 = local_28;
    local_20 = piVar5;
    if (local_20 == (int *)0xffffffff) goto LAB_005c5620;
    FUN_005dae40("exp_F_Kungfu");
    if (fVar11 <= 0.005) {
      fVar11 = 0.005;
    }
    local_44 = fVar11;
    if (*(int *)(iVar2 + 0xc) == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    fVar11 = *(float *)(*(int *)(iVar2 + 8) + 0xc);
    FUN_0040b7e0();
    if ((fVar11 * local_44 <= local_2c) || (local_11 != false)) {
      iVar3 = FUN_005cef70(piVar5);
      local_38 = *(undefined4 *)(iVar3 + 0xdc);
      piVar7 = local_3c;
      local_20 = piVar5;
      goto LAB_005c5620;
    }
    local_38 = 0xffffffff;
    FUN_0040b980(0);
    piVar7 = local_3c;
    local_20 = piVar5;
LAB_005c5634:
    if (piVar7 != (int *)0xffffffff) {
      if (*(int **)(iVar2 + 0xc) <= piVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*(int *)((int)piVar7 * 0x40 + 0x28 + *(int *)(iVar2 + 8)) != 3) {
        piVar7 = (int *)0x0;
        local_28 = (int *)0x0;
        iVar3 = FUN_005cf210();
        if (0 < iVar3) {
          do {
            local_44 = (float)FUN_005cef70(piVar7);
            if ((local_44 != 0.0) && (uVar8 = 0, piVar7 = local_28, 0 < *(int *)(iVar2 + 0xc))) {
              bVar10 = *(int *)(iVar2 + 0xc) != 0;
              local_34 = 0.0;
              do {
                if (!bVar10) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                cVar1 = FUN_006b97f0(*(int *)((int)local_44 + 0xd4) + 0xc);
                if (cVar1 != '\0') {
                  if (*(uint *)(iVar2 + 0xc) <= uVar8) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  if (*(char *)(*(int *)(iVar2 + 8) + 4 + (int)local_34) == '\0') {
                    FUN_0040b930(1);
                    if ((uint)local_58 <= (int)local_58 - 1U) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    *(uint *)(local_5c + -4 + (int)local_58 * 4) = (int)local_28 << 0x10 | uVar8;
                    piVar7 = local_28;
                    break;
                  }
                }
                uVar8 = uVar8 + 1;
                local_34 = (float)((int)local_34 + 0x40);
                bVar10 = uVar8 < *(uint *)(iVar2 + 0xc);
                piVar7 = local_28;
              } while ((int)uVar8 < (int)*(uint *)(iVar2 + 0xc));
            }
            piVar7 = (int *)((int)piVar7 + 1);
            local_28 = piVar7;
            iVar3 = FUN_005cf210();
          } while ((int)piVar7 < iVar3);
        }
      }
    }
  }
  fVar12 = 0.0;
  fVar11 = -NAN;
  local_3c = (int *)0x0;
  local_24 = -NAN;
  FUN_005dae40("exp_F_Defense");
  local_34 = 0.0;
  local_4c = fVar12;
  if (0 < (int)local_58) {
    bVar10 = local_58 != 0.0;
    do {
      if (!bVar10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar8 = *(uint *)(local_5c + (int)local_34 * 4);
      local_1c = (float)(uVar8 & 0xffff);
      if ((uint)local_58 <= (uint)local_34) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar8 = *(uint *)(local_5c + (int)local_34 * 4);
      }
      local_50 = (int *)((int)uVar8 >> 0x10);
      if ((uint)*(float *)(iVar2 + 0xc) <= (uint)local_1c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar3 = *(int *)(iVar2 + 8);
      local_28 = (int *)((int)local_1c * 0x40);
      if (*(float *)(iVar3 + 0x14 + (int)local_28) <= local_4c) {
        local_30 = (int *)0x3f800000;
        piVar7 = local_30;
        if ((fVar11 != -NAN) && (piVar7 = local_3c, (float)local_3c == 0.0)) {
          fVar12 = *(float *)(iVar2 + 0xc);
          if ((uint)fVar12 <= (uint)fVar11) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(iVar2 + 8);
            fVar12 = *(float *)(iVar2 + 0xc);
          }
          iVar9 = (int)fVar11 * 0x40;
          piVar7 = local_30;
          if (-1 < *(int *)(iVar3 + 0x30 + iVar9)) {
            local_40 = (int *)iVar9;
            if ((uint)fVar12 <= (uint)local_24) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar3 = *(int *)(iVar2 + 8);
            }
            if (*(uint *)(iVar2 + 0x1c) <= *(uint *)(iVar3 + 0x30 + iVar9)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            cVar1 = FUN_005c4310(local_18);
            piVar7 = local_30;
            if (cVar1 != '\0') {
              fVar11 = *(float *)(iVar2 + 0xc);
              if ((uint)fVar11 <= (uint)local_24) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                fVar11 = *(float *)(iVar2 + 0xc);
              }
              iVar3 = *(int *)(iVar2 + 8);
              local_44 = (float)((int)local_40 + iVar3);
              if ((uint)fVar11 <= (uint)local_24) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar3 = *(int *)(iVar2 + 8);
              }
              uVar8 = *(uint *)(iVar3 + 0x30 + (int)local_40);
              if (*(uint *)(iVar2 + 0x1c) <= uVar8) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar3 = uVar8 * 0x10 + *(int *)(iVar2 + 0x18);
              local_44 = *(float *)((int)local_44 + 0x34);
              if ((uint)*(float *)(iVar3 + 0xc) <= (uint)local_44) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              piVar7 = *(int **)(*(int *)(iVar3 + 8) + (int)local_44 * 4);
            }
          }
        }
        local_30 = piVar7;
        fVar11 = *(float *)(iVar2 + 0xc);
        local_40 = (int *)0x3f800000;
        if ((uint)fVar11 <= (uint)local_1c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          fVar11 = *(float *)(iVar2 + 0xc);
        }
        iVar3 = *(int *)(iVar2 + 8);
        if (-1 < *(int *)(iVar3 + 0x30 + (int)local_28)) {
          if ((uint)fVar11 <= (uint)local_1c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar3 = *(int *)(iVar2 + 8);
          }
          if (*(uint *)(iVar2 + 0x1c) <= *(uint *)(iVar3 + 0x30 + (int)local_28)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          cVar1 = FUN_005c4310(local_18);
          if (cVar1 != '\0') {
            fVar11 = *(float *)(iVar2 + 0xc);
            if ((uint)fVar11 <= (uint)local_1c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              fVar11 = *(float *)(iVar2 + 0xc);
            }
            iVar3 = *(int *)(iVar2 + 8);
            local_44 = (float)((int)local_28 + iVar3);
            if ((uint)fVar11 <= (uint)local_1c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar3 = *(int *)(iVar2 + 8);
            }
            uVar8 = *(uint *)(iVar3 + 0x30 + (int)local_28);
            if (*(uint *)(iVar2 + 0x1c) <= uVar8) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar3 = uVar8 * 0x10 + *(int *)(iVar2 + 0x18);
            local_44 = *(float *)((int)local_44 + 0x34);
            if (*(uint *)(iVar3 + 0xc) <= (uint)local_44) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            local_40 = *(int **)(*(int *)(iVar3 + 8) + (int)local_44 * 4);
          }
        }
        fVar11 = local_24;
        local_44 = 0.0;
        if (local_24 != -NAN) {
          if ((uint)*(float *)(iVar2 + 0xc) <= (uint)local_24) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          local_44 = *(float *)((int)fVar11 * 0x40 + 0xc + *(int *)(iVar2 + 8));
        }
        if ((uint)*(float *)(iVar2 + 0xc) <= (uint)local_1c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        if (local_44 * (float)local_30 <
            *(float *)(*(int *)(iVar2 + 8) + 0xc + (int)local_28) * (float)local_40) {
          local_20 = local_50;
          local_24 = local_1c;
          local_3c = local_40;
          fVar11 = local_1c;
        }
      }
      local_34 = (float)((int)local_34 + 1);
      bVar10 = (uint)local_34 < (uint)local_58;
    } while ((int)local_34 < (int)local_58);
    if (fVar11 != -NAN) {
      iVar2 = FUN_005cef70(local_20);
      local_48 = *(int **)(iVar2 + 0xdc);
    }
  }
  local_28 = (int *)0x0;
  piVar7 = (int *)Tcl_NewIntObj(local_38);
  *piVar7 = *piVar7 + 1;
  local_50 = piVar7;
  FUN_006bb930(&local_50);
  *piVar7 = *piVar7 + -1;
  if (*piVar7 < 1) {
    TclFreeObj(piVar7);
  }
  piVar7 = (int *)Tcl_NewIntObj(local_48);
  *piVar7 = *piVar7 + 1;
  local_50 = piVar7;
  FUN_006bb930(&local_50);
  *piVar7 = *piVar7 + -1;
  if (*piVar7 < 1) {
    TclFreeObj(piVar7);
  }
  uVar4 = FUN_006bad90();
  FUN_006bb930(uVar4);
  if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 < 1)) {
    TclFreeObj(local_48);
  }
  uVar4 = FUN_006bad90();
  FUN_006bb930(uVar4);
  if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 < 1)) {
    TclFreeObj(local_48);
  }
  piVar7 = local_28;
  if (local_78 != 0) {
    if (local_28 == (int *)0x0) {
      Tcl_ResetResult(local_78);
      goto LAB_005c5bae;
    }
    Tcl_SetObjResult(local_78,local_28);
  }
  if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
    TclFreeObj(piVar7);
  }
LAB_005c5bae:
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_0040b980(0);
  if (local_5c != 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_68 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

