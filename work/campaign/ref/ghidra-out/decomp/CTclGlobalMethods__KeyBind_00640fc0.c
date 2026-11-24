
undefined4
CTclGlobalMethods__KeyBind(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined **ppuVar5;
  uint uVar6;
  undefined **ppuVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int iVar12;
  char *pcVar13;
  byte *pbVar14;
  undefined4 uVar15;
  int *piVar16;
  byte *pbVar17;
  uint uVar18;
  bool bVar19;
  undefined8 uVar20;
  int local_68;
  undefined4 *local_58;
  uint local_54;
  int local_50;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int local_28;
  int *local_24;
  uint local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d9ad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7068) &&
     (FUN_006cebf4(&DAT_00ca7068,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7068 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca706c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclGlobalMethods::KeyBind()";
    *(int *)(&DAT_00773650 + iVar9) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7068);
  }
  iVar9 = DAT_00ca706c;
  uVar15 = *(undefined4 *)(&DAT_00773650 + DAT_00ca706c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar15;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar2 == 0) {
    uVar20 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar20;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar16 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if ((int)piVar16 < 2) {
    FUN_006bc8f0(1);
    uVar15 = 1;
    goto LAB_0064129d;
  }
  if (local_50 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar11 = local_58;
    if (local_54 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_54 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar11 = local_58 + 1;
  }
  local_1c = (int *)*puVar11;
  if (local_1c != (int *)0x0) {
    *local_1c = *local_1c + 1;
  }
  local_8._0_1_ = 3;
  if (local_1c == (int *)0x0) {
    ppuVar7 = &PTR_0071ce50;
  }
  else {
    ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_1c,0);
  }
  pcVar13 = "keynames";
  do {
    bVar1 = *(byte *)ppuVar7;
    bVar19 = bVar1 < (byte)*pcVar13;
    if (bVar1 != *pcVar13) {
LAB_00641138:
      piVar8 = (int *)(-(uint)bVar19 | 1);
      goto LAB_0064113d;
    }
    if (bVar1 == 0) break;
    bVar1 = *(byte *)((int)ppuVar7 + 1);
    bVar19 = bVar1 < ((byte *)pcVar13)[1];
    if (bVar1 != ((byte *)pcVar13)[1]) goto LAB_00641138;
    ppuVar7 = (undefined **)((int)ppuVar7 + 2);
    pcVar13 = (char *)((byte *)pcVar13 + 2);
  } while (bVar1 != 0);
  piVar8 = (int *)0x0;
LAB_0064113d:
  if (piVar8 == (int *)0x0) {
    local_8._0_1_ = 4;
    local_24 = piVar8;
    local_34 = (int *)FUN_006ba810(0x19);
    local_34[1] = 0x14;
    local_34[2] = -1;
    *(undefined1 *)(local_34 + 3) = 0;
    *local_34 = 1;
    local_8._0_1_ = 5;
    iVar2 = 0;
    piVar16 = local_34;
    do {
      piVar8 = (int *)FUN_004e4cf0(&local_30,iVar2);
      local_8._0_1_ = 6;
      piVar3 = (int *)*piVar8;
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      local_34 = piVar3;
      if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 == 0)) {
        FUN_006ba940();
      }
      piVar3[2] = *(int *)(*piVar8 + 8);
      local_8._0_1_ = 7;
      if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 5;
      piVar16 = piVar3 + 3;
      iVar9 = piVar3[2];
      if (iVar9 == -1) {
        piVar8 = piVar16;
        do {
          iVar9 = *piVar8;
          piVar8 = (int *)((int)piVar8 + 1);
        } while ((char)iVar9 != '\0');
        iVar9 = (int)piVar8 - ((int)piVar3 + 0xd);
        piVar3[2] = iVar9;
      }
      if (0 < iVar9) {
        if (piVar16 == (int *)0x0) {
          piVar16 = (int *)0x0;
        }
        else {
          piVar16 = (int *)Tcl_NewStringObj(piVar16,0xffffffff);
          *piVar16 = *piVar16 + 1;
        }
        param_3 = piVar16;
        FUN_006bb930(&param_3);
        if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 < 1)) {
          TclFreeObj(piVar16);
        }
      }
      piVar8 = local_24;
      iVar2 = iVar2 + 1;
      piVar16 = piVar3;
    } while (iVar2 < 0x100);
    if (local_68 != 0) {
      if (local_24 == (int *)0x0) {
        Tcl_ResetResult(local_68);
      }
      else {
        Tcl_SetObjResult(local_68,local_24);
      }
    }
    local_8._0_1_ = 8;
    *piVar3 = *piVar3 + -1;
    if (*piVar3 == 0) {
      FUN_006ba940();
    }
    if (piVar8 != (int *)0x0) {
      *piVar8 = *piVar8 + -1;
      iVar2 = *piVar8;
joined_r0x0064173b:
      if (iVar2 < 1) {
        TclFreeObj(piVar8);
      }
    }
LAB_00641283:
    uVar15 = 0;
  }
  else {
    if (local_1c == (int *)0x0) {
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_1c,0);
    }
    pcVar13 = "current";
    do {
      bVar1 = *(byte *)ppuVar7;
      bVar19 = bVar1 < (byte)*pcVar13;
      if (bVar1 != *pcVar13) {
LAB_00641332:
        uVar10 = -(uint)bVar19 | 1;
        goto LAB_00641337;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar7 + 1);
      bVar19 = bVar1 < ((byte *)pcVar13)[1];
      if (bVar1 != ((byte *)pcVar13)[1]) goto LAB_00641332;
      ppuVar7 = (undefined **)((int)ppuVar7 + 2);
      pcVar13 = (char *)((byte *)pcVar13 + 2);
    } while (bVar1 != 0);
    uVar10 = 0;
LAB_00641337:
    if (uVar10 == 0) {
      piVar8 = (int *)0x0;
      local_18 = (int *)0x0;
      local_8 = CONCAT31(local_8._1_3_,9);
      piVar16 = *(int **)(DAT_00772400 + 0x14c);
      local_44 = piVar16;
      FUN_006b8f50();
      if (piVar16 == (int *)0x0) {
        param_3 = (int *)Tcl_NewListObj(0,0);
        if (param_3 != (int *)0x0) {
          *param_3 = *param_3 + 1;
        }
        FUN_006baea0(&param_3);
        FUN_006bad60();
        piVar3 = local_14;
        piVar8 = local_18;
      }
      else {
        local_20 = 0;
        piVar3 = local_14;
        if (0 < (int)piVar16) {
          local_28 = 0;
          do {
            iVar9 = local_28;
            iVar2 = DAT_00772400;
            if (*(uint *)(DAT_00772400 + 0x14c) <= local_20) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar11 = (undefined4 *)(*(int *)(iVar2 + 0x148) + iVar9);
            uVar10 = puVar11[1];
            uVar15 = *puVar11;
            param_3 = (int *)CONCAT13(*(undefined1 *)(puVar11 + 2),param_3._0_3_);
            local_40 = (int *)puVar11[3];
            if (local_40 != (int *)0x0) {
              *local_40 = *local_40 + 1;
            }
            local_8._0_1_ = 0xb;
            piVar8 = (int *)FUN_004e4cf0(&local_34,uVar15);
            local_8._0_1_ = 0xc;
            piVar16 = (int *)*piVar8;
            if (piVar16 != (int *)0x0) {
              *piVar16 = *piVar16 + 1;
            }
            local_14 = piVar16;
            if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
              FUN_006ba940();
            }
            piVar16[2] = *(int *)(*piVar8 + 8);
            local_8._0_1_ = 0xd;
            if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 0xb;
            piVar8 = piVar16;
            if ((uVar10 & 1) != 0) {
              piVar3 = (int *)FUN_006b9500(" shift");
              local_8._0_1_ = 0xe;
              piVar8 = (int *)*piVar3;
              if (piVar8 != (int *)0x0) {
                *piVar8 = *piVar8 + 1;
              }
              local_14 = piVar8;
              if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 == 0)) {
                FUN_006ba940();
              }
              piVar8[2] = *(int *)(*piVar3 + 8);
              local_8._0_1_ = 0xf;
              if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
                FUN_006ba940();
              }
            }
            local_8._0_1_ = 0xb;
            piVar16 = piVar8;
            if ((uVar10 & 2) != 0) {
              piVar3 = (int *)FUN_006b9500(&DAT_0072fc08);
              local_8._0_1_ = 0x10;
              piVar16 = (int *)*piVar3;
              if (piVar16 != (int *)0x0) {
                *piVar16 = *piVar16 + 1;
              }
              local_14 = piVar16;
              if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 == 0)) {
                FUN_006ba940();
              }
              piVar16[2] = *(int *)(*piVar3 + 8);
              local_8._0_1_ = 0x11;
              if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
                FUN_006ba940();
              }
            }
            local_8._0_1_ = 0xb;
            piVar8 = piVar16;
            if ((uVar10 & 4) != 0) {
              piVar3 = (int *)FUN_006b9500(" ctrl");
              local_8._0_1_ = 0x12;
              piVar8 = (int *)*piVar3;
              if (piVar8 != (int *)0x0) {
                *piVar8 = *piVar8 + 1;
              }
              local_14 = piVar8;
              if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 == 0)) {
                FUN_006ba940();
              }
              piVar8[2] = *(int *)(*piVar3 + 8);
              local_8._0_1_ = 0x13;
              if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
                FUN_006ba940();
              }
            }
            local_8._0_1_ = 0xb;
            piVar3 = piVar8;
            if (param_3._3_1_ == '\0') {
              piVar16 = (int *)FUN_006b9500(" down");
              local_8._0_1_ = 0x14;
              piVar3 = (int *)*piVar16;
              if (piVar3 != (int *)0x0) {
                *piVar3 = *piVar3 + 1;
              }
              local_14 = piVar3;
              if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 == 0)) {
                FUN_006ba940();
              }
              piVar3[2] = *(int *)(*piVar16 + 8);
              local_8._0_1_ = 0x15;
              if ((local_3c != (int *)0x0) && (*local_3c = *local_3c + -1, *local_3c == 0)) {
                FUN_006ba940();
              }
            }
            param_3 = (int *)0x0;
            if (piVar3 + 3 == (int *)0x0) {
              piVar16 = (int *)0x0;
            }
            else {
              piVar16 = (int *)Tcl_NewStringObj(piVar3 + 3,0xffffffff);
              *piVar16 = *piVar16 + 1;
            }
            local_24 = piVar16;
            FUN_006bb930(&local_24);
            if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 < 1)) {
              TclFreeObj(piVar16);
            }
            piVar16 = local_40;
            if (local_40 + 3 == (int *)0x0) {
              piVar8 = (int *)0x0;
            }
            else {
              piVar8 = (int *)Tcl_NewStringObj(local_40 + 3,0xffffffff);
              *piVar8 = *piVar8 + 1;
            }
            local_24 = piVar8;
            FUN_006bb930(&local_24);
            if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
              TclFreeObj(piVar8);
            }
            piVar8 = param_3;
            if (local_18 == (int *)0x0) {
              local_18 = (int *)Tcl_NewListObj(0,0);
              if (local_18 != (int *)0x0) {
                *local_18 = *local_18 + 1;
                goto LAB_0064167f;
              }
LAB_006416c5:
              if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
                TclFreeObj(piVar8);
              }
            }
            else {
LAB_0064167f:
              if (1 < *local_18) {
                *local_18 = *local_18 + -1;
                local_18 = (int *)Tcl_DuplicateObj(local_18);
                *local_18 = *local_18 + 1;
              }
              if (piVar8 != (int *)0x0) {
                if (*piVar8 < 2) {
                  Tcl_ListObjAppendElement(0,local_18,piVar8);
                }
                else {
                  uVar15 = Tcl_DuplicateObj();
                  Tcl_ListObjAppendElement(0,local_18,uVar15);
                }
                goto LAB_006416c5;
              }
            }
            local_8 = CONCAT31(local_8._1_3_,0x16);
            if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 == 0)) {
              FUN_006ba940();
            }
            local_20 = local_20 + 1;
            local_28 = local_28 + 0x10;
            piVar8 = local_18;
          } while ((int)local_20 < (int)local_44);
        }
      }
      if (local_68 != 0) {
        if (piVar8 == (int *)0x0) {
          Tcl_ResetResult(local_68);
        }
        else {
          Tcl_SetObjResult(local_68,piVar8);
        }
      }
      local_8._0_1_ = 0x17;
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
        FUN_006ba940();
      }
      if (piVar8 != (int *)0x0) {
        *piVar8 = *piVar8 + -1;
        iVar2 = *piVar8;
        goto joined_r0x0064173b;
      }
      goto LAB_00641283;
    }
    if (local_1c == (int *)0x0) {
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_1c,0);
    }
    pbVar14 = &DAT_0072e630;
    do {
      bVar1 = *(byte *)ppuVar7;
      bVar19 = bVar1 < *pbVar14;
      if (bVar1 != *pbVar14) {
LAB_00641784:
        uVar10 = -(uint)bVar19 | 1;
        goto LAB_00641789;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar7 + 1);
      bVar19 = bVar1 < pbVar14[1];
      if (bVar1 != pbVar14[1]) goto LAB_00641784;
      ppuVar7 = (undefined **)((int)ppuVar7 + 2);
      pbVar14 = pbVar14 + 2;
    } while (bVar1 != 0);
    uVar10 = 0;
LAB_00641789:
    if (uVar10 == 0) {
      if ((int)piVar16 < 4) {
        FUN_006bc8f0(3);
        uVar15 = 1;
      }
      else {
        local_18 = (int *)0x0;
        local_20 = 1;
        local_30 = (int *)CONCAT31(local_30._1_3_,1);
        puVar11 = (undefined4 *)FUN_004295e0(2);
        piVar16 = (int *)*puVar11;
        if (piVar16 != (int *)0x0) {
          *piVar16 = *piVar16 + 1;
        }
        local_8._0_1_ = 0x18;
        uVar15 = extraout_ECX;
        local_2c = piVar16;
        local_14 = piVar16;
        uVar4 = FUN_006bafc0(extraout_ECX);
        FUN_006b8fb0(uVar4);
        local_34 = (int *)FUN_004e4d90(uVar15);
        if (local_34 == (int *)0xffffffff) {
          if (piVar16 != (int *)0x0) {
            *piVar16 = *piVar16 + 1;
          }
          FUN_006bc6a0("invalid key code",piVar16);
          uVar15 = 1;
        }
        else {
          FUN_004e4cf0(&local_44,local_34);
          iVar2 = (int)param_3 + -1;
          local_28 = 3;
          if (iVar2 < 4) {
LAB_00641979:
            pcVar13 = (char *)FUN_006bafc0();
            iVar9 = _tolower((int)*pcVar13);
            if (((iVar9 != 0x66) || (iVar9 = _isdigit((int)pcVar13[1]), iVar9 == 0)) ||
               (iVar9 = _isdigit((int)pcVar13[2]), iVar9 != 0)) goto LAB_006419ba;
          }
          else {
            piVar8 = (int *)0x0;
            do {
              puVar11 = (undefined4 *)FUN_004295e0(local_28);
              piVar16 = (int *)*puVar11;
              if (piVar16 == (int *)0x0) {
                ppuVar7 = &PTR_0071ce50;
              }
              else {
                *piVar16 = *piVar16 + 1;
                ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar16,0);
                *piVar16 = *piVar16 + -1;
                if (*piVar16 < 1) {
                  TclFreeObj(piVar16);
                }
              }
              pcVar13 = "shift";
              ppuVar5 = ppuVar7;
              do {
                bVar1 = *(byte *)ppuVar5;
                bVar19 = bVar1 < (byte)*pcVar13;
                if (bVar1 != *pcVar13) {
LAB_006418a0:
                  uVar10 = -(uint)bVar19 | 1;
                  goto LAB_006418a5;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar5 + 1);
                bVar19 = bVar1 < ((byte *)pcVar13)[1];
                if (bVar1 != ((byte *)pcVar13)[1]) goto LAB_006418a0;
                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                pcVar13 = (char *)((byte *)pcVar13 + 2);
              } while (bVar1 != 0);
              uVar10 = 0;
LAB_006418a5:
              if (uVar10 == 0) {
                piVar8 = (int *)((uint)piVar8 | 1);
              }
              pbVar14 = &DAT_0072fc3c;
              ppuVar5 = ppuVar7;
              do {
                bVar1 = *(byte *)ppuVar5;
                bVar19 = bVar1 < *pbVar14;
                if (bVar1 != *pbVar14) {
LAB_006418d3:
                  uVar10 = -(uint)bVar19 | 1;
                  goto LAB_006418d8;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar5 + 1);
                bVar19 = bVar1 < pbVar14[1];
                if (bVar1 != pbVar14[1]) goto LAB_006418d3;
                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                pbVar14 = pbVar14 + 2;
              } while (bVar1 != 0);
              uVar10 = 0;
LAB_006418d8:
              pbVar14 = &DAT_0072fc44;
              ppuVar5 = ppuVar7;
              piVar16 = (int *)((uint)piVar8 | 4);
              if (uVar10 != 0) {
                piVar16 = piVar8;
              }
              do {
                bVar1 = *(byte *)ppuVar5;
                bVar19 = bVar1 < *pbVar14;
                if (bVar1 != *pbVar14) {
LAB_00641910:
                  uVar10 = -(uint)bVar19 | 1;
                  goto LAB_00641915;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar5 + 1);
                bVar19 = bVar1 < pbVar14[1];
                if (bVar1 != pbVar14[1]) goto LAB_00641910;
                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                pbVar14 = pbVar14 + 2;
              } while (bVar1 != 0);
              uVar10 = 0;
LAB_00641915:
              pbVar14 = &DAT_0072fc48;
              piVar8 = (int *)((uint)piVar16 | 2);
              if (uVar10 != 0) {
                piVar8 = piVar16;
              }
              do {
                bVar1 = *(byte *)ppuVar7;
                bVar19 = bVar1 < *pbVar14;
                if (bVar1 != *pbVar14) {
LAB_00641944:
                  uVar10 = -(uint)bVar19 | 1;
                  goto LAB_00641949;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar7 + 1);
                bVar19 = bVar1 < pbVar14[1];
                if (bVar1 != pbVar14[1]) goto LAB_00641944;
                ppuVar7 = (undefined **)((int)ppuVar7 + 2);
                pbVar14 = pbVar14 + 2;
              } while (bVar1 != 0);
              uVar10 = 0;
LAB_00641949:
              local_20 = local_20 & 0xff;
              if (uVar10 == 0) {
                local_20 = 0;
              }
              local_28 = local_28 + 1;
              local_30 = (int *)CONCAT31(local_30._1_3_,(char)local_20);
              iVar2 = (int)param_3 + -1;
            } while (local_28 < iVar2);
            piVar16 = local_14;
            local_18 = piVar8;
            if (piVar8 == (int *)0x0) goto LAB_00641979;
LAB_006419ba:
            puVar11 = (undefined4 *)FUN_004295e0(iVar2);
            piVar8 = (int *)*puVar11;
            if (piVar8 != (int *)0x0) {
              *piVar8 = *piVar8 + 1;
            }
            local_8._0_1_ = 0x1b;
            local_40 = piVar8;
            if (piVar8 == (int *)0x0) {
              ppuVar7 = &PTR_0071ce50;
            }
            else {
              ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar8,0);
            }
            FUN_006b8fb0(ppuVar7);
            iVar2 = DAT_00772400;
            piVar3 = (int *)(DAT_00772400 + 0x148);
            local_8 = CONCAT31(local_8._1_3_,0x1c);
            param_3 = (int *)FUN_004e4b90(local_34,local_18,local_30);
            if (param_3 == (int *)0xffffffff) {
              FUN_004e4f40(1);
              param_3 = (int *)((int)*(int **)(iVar2 + 0x14c) - 1);
              if (*(int **)(iVar2 + 0x14c) <= param_3) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              local_30 = (int *)((int)param_3 * 0x10);
              *(int **)((int)local_30 + *piVar3) = local_34;
              if (*(int **)(iVar2 + 0x14c) <= param_3) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              piVar16 = local_14;
              *(int **)((int)local_30 + *piVar3 + 4) = local_18;
              if (*(int **)(iVar2 + 0x14c) <= param_3) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              *(char *)((int)local_30 + *piVar3 + 8) = (char)local_20;
            }
            if (*(int **)(iVar2 + 0x14c) <= param_3) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar2 = *piVar3 + (int)param_3 * 0x10;
            piVar3 = *(int **)(iVar2 + 0xc);
            *(int **)(iVar2 + 0xc) = local_24;
            if (local_24 != (int *)0x0) {
              *local_24 = *local_24 + 1;
            }
            if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
              FUN_006ba940();
            }
            *(int *)(*(int *)(iVar2 + 0xc) + 8) = local_24[2];
            local_8._0_1_ = 0x1d;
            if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
              FUN_006ba940();
            }
            if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
              TclFreeObj(piVar8);
            }
          }
          local_8._0_1_ = 0x1e;
          uVar15 = 0;
          if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 == 0)) {
            FUN_006ba940();
          }
        }
        if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 < 1)) {
          TclFreeObj(piVar16);
        }
      }
    }
    else {
      if (local_1c == (int *)0x0) {
        ppuVar7 = &PTR_0071ce50;
      }
      else {
        ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_1c,0);
      }
      pbVar14 = &DAT_0072e624;
      do {
        bVar1 = *(byte *)ppuVar7;
        bVar19 = bVar1 < *pbVar14;
        if (bVar1 != *pbVar14) {
LAB_00641b90:
          uVar10 = -(uint)bVar19 | 1;
          goto LAB_00641b95;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar7 + 1);
        bVar19 = bVar1 < pbVar14[1];
        if (bVar1 != pbVar14[1]) goto LAB_00641b90;
        ppuVar7 = (undefined **)((int)ppuVar7 + 2);
        pbVar14 = pbVar14 + 2;
      } while (bVar1 != 0);
      uVar10 = 0;
LAB_00641b95:
      if (uVar10 == 0) {
        if ((int)piVar16 < 4) {
          FUN_006bc8f0(3);
          uVar15 = 1;
        }
        else {
          local_34 = (int *)CONCAT31(local_34._1_3_,1);
          uVar10 = 0;
          puVar11 = (undefined4 *)FUN_004295e0(2);
          piVar16 = (int *)*puVar11;
          if (piVar16 != (int *)0x0) {
            *piVar16 = *piVar16 + 1;
          }
          local_8._0_1_ = 0x1f;
          uVar15 = extraout_ECX_00;
          local_2c = piVar16;
          uVar4 = FUN_006bafc0(extraout_ECX_00);
          FUN_006b8fb0(uVar4);
          local_44 = (int *)FUN_004e4d90(uVar15);
          if (local_44 == (int *)0xffffffff) {
            if (piVar16 != (int *)0x0) {
              *piVar16 = *piVar16 + 1;
            }
            FUN_006bc6a0("invalid key code",piVar16);
            uVar15 = 1;
            FUN_006bad60();
          }
          else {
            FUN_004e4cf0(&local_40,local_44);
            local_8 = CONCAT31(local_8._1_3_,0x20);
            local_30 = (int *)0x3;
            do {
              puVar11 = (undefined4 *)FUN_004295e0(local_30);
              piVar16 = (int *)*puVar11;
              if (piVar16 == (int *)0x0) {
                ppuVar7 = &PTR_0071ce50;
              }
              else {
                *piVar16 = *piVar16 + 1;
                ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar16,0);
                *piVar16 = *piVar16 + -1;
                if (*piVar16 < 1) {
                  TclFreeObj(piVar16);
                }
              }
              pcVar13 = "shift";
              ppuVar5 = ppuVar7;
              do {
                bVar1 = *(byte *)ppuVar5;
                bVar19 = bVar1 < (byte)*pcVar13;
                if (bVar1 != *pcVar13) {
LAB_00641c93:
                  uVar6 = -(uint)bVar19 | 1;
                  goto LAB_00641c98;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar5 + 1);
                bVar19 = bVar1 < ((byte *)pcVar13)[1];
                if (bVar1 != ((byte *)pcVar13)[1]) goto LAB_00641c93;
                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                pcVar13 = (char *)((byte *)pcVar13 + 2);
              } while (bVar1 != 0);
              uVar6 = 0;
LAB_00641c98:
              if (uVar6 == 0) {
                uVar10 = uVar10 | 1;
              }
              pbVar14 = &DAT_0072fc3c;
              ppuVar5 = ppuVar7;
              do {
                bVar1 = *(byte *)ppuVar5;
                bVar19 = bVar1 < *pbVar14;
                if (bVar1 != *pbVar14) {
LAB_00641cc6:
                  uVar6 = -(uint)bVar19 | 1;
                  goto LAB_00641ccb;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar5 + 1);
                bVar19 = bVar1 < pbVar14[1];
                if (bVar1 != pbVar14[1]) goto LAB_00641cc6;
                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                pbVar14 = pbVar14 + 2;
              } while (bVar1 != 0);
              uVar6 = 0;
LAB_00641ccb:
              pbVar14 = &DAT_0072fc44;
              ppuVar5 = ppuVar7;
              uVar18 = uVar10 | 4;
              if (uVar6 != 0) {
                uVar18 = uVar10;
              }
              do {
                bVar1 = *(byte *)ppuVar5;
                bVar19 = bVar1 < *pbVar14;
                if (bVar1 != *pbVar14) {
LAB_00641d00:
                  uVar6 = -(uint)bVar19 | 1;
                  goto LAB_00641d05;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar5 + 1);
                bVar19 = bVar1 < pbVar14[1];
                if (bVar1 != pbVar14[1]) goto LAB_00641d00;
                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                pbVar14 = pbVar14 + 2;
              } while (bVar1 != 0);
              uVar6 = 0;
LAB_00641d05:
              pbVar14 = &DAT_0072fc48;
              uVar10 = uVar18 | 2;
              if (uVar6 != 0) {
                uVar10 = uVar18;
              }
              do {
                bVar1 = *(byte *)ppuVar7;
                bVar19 = bVar1 < *pbVar14;
                if (bVar1 != *pbVar14) {
LAB_00641d34:
                  uVar6 = -(uint)bVar19 | 1;
                  goto LAB_00641d39;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar7 + 1);
                bVar19 = bVar1 < pbVar14[1];
                if (bVar1 != pbVar14[1]) goto LAB_00641d34;
                ppuVar7 = (undefined **)((int)ppuVar7 + 2);
                pbVar14 = pbVar14 + 2;
              } while (bVar1 != 0);
              uVar6 = 0;
LAB_00641d39:
              local_34 = (int *)((uint)local_34 & 0xff);
              if (uVar6 == 0) {
                local_34 = (int *)0x0;
              }
              local_30 = (int *)((int)local_30 + 1);
            } while ((int)local_30 < (int)param_3);
            FUN_004e4c40(&param_3,local_44,uVar10,CONCAT31((int3)(uVar6 >> 8),(char)local_34));
            piVar16 = param_3;
            if (param_3 + 3 == (int *)0x0) {
              piVar8 = (int *)0x0;
            }
            else {
              piVar8 = (int *)Tcl_NewStringObj(param_3 + 3,0xffffffff);
              *piVar8 = *piVar8 + 1;
            }
            param_3 = piVar8;
            FUN_006bc670(&param_3);
            if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
              TclFreeObj(piVar8);
            }
            uVar15 = 0;
            local_8._0_1_ = 0x21;
            if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 0x22;
            if ((local_40 != (int *)0x0) && (*local_40 = *local_40 + -1, *local_40 == 0)) {
              FUN_006ba940();
            }
            FUN_006bad60();
          }
        }
      }
      else {
        pbVar17 = &DAT_0072fc50;
        pbVar14 = (byte *)FUN_006bafc0();
        do {
          bVar1 = *pbVar14;
          bVar19 = bVar1 < *pbVar17;
          if (bVar1 != *pbVar17) {
LAB_00641e20:
            uVar10 = -(uint)bVar19 | 1;
            goto LAB_00641e25;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar14[1];
          bVar19 = bVar1 < pbVar17[1];
          if (bVar1 != pbVar17[1]) goto LAB_00641e20;
          pbVar14 = pbVar14 + 2;
          pbVar17 = pbVar17 + 2;
        } while (bVar1 != 0);
        uVar10 = 0;
LAB_00641e25:
        if (uVar10 != 0) goto LAB_00641283;
        if ((int)piVar16 < 4) {
          FUN_006bc8f0(3);
          uVar15 = 1;
        }
        else {
          local_34 = (int *)CONCAT31(local_34._1_3_,1);
          uVar10 = 0;
          puVar11 = (undefined4 *)FUN_004295e0(2);
          piVar16 = (int *)*puVar11;
          if (piVar16 != (int *)0x0) {
            *piVar16 = *piVar16 + 1;
          }
          local_8._0_1_ = 0x23;
          uVar15 = extraout_ECX_01;
          local_2c = piVar16;
          uVar4 = FUN_006bafc0(extraout_ECX_01);
          FUN_006b8fb0(uVar4);
          local_44 = (int *)FUN_004e4d90(uVar15);
          if (local_44 == (int *)0xffffffff) {
            if (piVar16 != (int *)0x0) {
              *piVar16 = *piVar16 + 1;
            }
            FUN_006bc6a0("invalid key code",piVar16);
            uVar15 = 1;
            FUN_006bad60();
          }
          else {
            FUN_004e4cf0(&local_40,local_44);
            local_30 = (int *)0x3;
            do {
              puVar11 = (undefined4 *)FUN_004295e0(local_30);
              piVar16 = (int *)*puVar11;
              if (piVar16 == (int *)0x0) {
                ppuVar7 = &PTR_0071ce50;
              }
              else {
                *piVar16 = *piVar16 + 1;
                ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar16,0);
                *piVar16 = *piVar16 + -1;
                if (*piVar16 < 1) {
                  TclFreeObj(piVar16);
                }
              }
              iVar2 = DAT_00772400;
              pcVar13 = "shift";
              ppuVar5 = ppuVar7;
              do {
                bVar1 = *(byte *)ppuVar5;
                bVar19 = bVar1 < (byte)*pcVar13;
                if (bVar1 != *pcVar13) {
LAB_00641f20:
                  uVar6 = -(uint)bVar19 | 1;
                  goto LAB_00641f25;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar5 + 1);
                bVar19 = bVar1 < ((byte *)pcVar13)[1];
                if (bVar1 != ((byte *)pcVar13)[1]) goto LAB_00641f20;
                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                pcVar13 = (char *)((byte *)pcVar13 + 2);
              } while (bVar1 != 0);
              uVar6 = 0;
LAB_00641f25:
              if (uVar6 == 0) {
                uVar10 = uVar10 | 1;
              }
              pbVar14 = &DAT_0072fc3c;
              ppuVar5 = ppuVar7;
              do {
                bVar1 = *(byte *)ppuVar5;
                bVar19 = bVar1 < *pbVar14;
                if (bVar1 != *pbVar14) {
LAB_00641f53:
                  uVar6 = -(uint)bVar19 | 1;
                  goto LAB_00641f58;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar5 + 1);
                bVar19 = bVar1 < pbVar14[1];
                if (bVar1 != pbVar14[1]) goto LAB_00641f53;
                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                pbVar14 = pbVar14 + 2;
              } while (bVar1 != 0);
              uVar6 = 0;
LAB_00641f58:
              pbVar14 = &DAT_0072fc44;
              ppuVar5 = ppuVar7;
              uVar18 = uVar10 | 4;
              if (uVar6 != 0) {
                uVar18 = uVar10;
              }
              do {
                bVar1 = *(byte *)ppuVar5;
                bVar19 = bVar1 < *pbVar14;
                if (bVar1 != *pbVar14) {
LAB_00641f90:
                  uVar6 = -(uint)bVar19 | 1;
                  goto LAB_00641f95;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar5 + 1);
                bVar19 = bVar1 < pbVar14[1];
                if (bVar1 != pbVar14[1]) goto LAB_00641f90;
                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                pbVar14 = pbVar14 + 2;
              } while (bVar1 != 0);
              uVar6 = 0;
LAB_00641f95:
              pbVar14 = &DAT_0072fc48;
              uVar10 = uVar18 | 2;
              if (uVar6 != 0) {
                uVar10 = uVar18;
              }
              do {
                bVar1 = *(byte *)ppuVar7;
                bVar19 = bVar1 < *pbVar14;
                if (bVar1 != *pbVar14) {
LAB_00641fc4:
                  uVar6 = -(uint)bVar19 | 1;
                  goto LAB_00641fc9;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar7 + 1);
                bVar19 = bVar1 < pbVar14[1];
                if (bVar1 != pbVar14[1]) goto LAB_00641fc4;
                ppuVar7 = (undefined **)((int)ppuVar7 + 2);
                pbVar14 = pbVar14 + 2;
              } while (bVar1 != 0);
              uVar6 = 0;
LAB_00641fc9:
              local_34 = (int *)((uint)local_34 & 0xff);
              if (uVar6 == 0) {
                local_34 = (int *)0x0;
              }
              local_30 = (int *)((int)local_30 + 1);
            } while ((int)local_30 < (int)param_3);
            piVar8 = (int *)(DAT_00772400 + 0x148);
            piVar16 = local_44;
            if (0x200 < (int)local_44) {
              piVar16 = (int *)((int)local_44 >> 0x10);
            }
            uVar10 = FUN_004e4b90(piVar16,uVar10,local_34);
            if (uVar10 != 0xffffffff) {
              if ((*(uint *)(iVar2 + 0x14c) <= uVar10) &&
                 (RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0),
                 *(uint *)(iVar2 + 0x14c) <= uVar10)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              local_8._0_1_ = 0x25;
              piVar16 = *(int **)(*piVar8 + 0xc + uVar10 * 0x10);
              if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 == 0)) {
                FUN_006ba940();
              }
              iVar9 = *(int *)(iVar2 + 0x14c);
              if ((int)uVar10 < iVar9 + -1) {
                iVar12 = *piVar8 + uVar10 * 0x10;
                FUN_006d1b90(iVar12,iVar12 + 0x10,(iVar9 - uVar10) * 0x10 + -0x10);
                iVar9 = *(int *)(iVar2 + 0x14c);
              }
              *(int *)(iVar2 + 0x14c) = iVar9 + -1;
            }
            uVar15 = 0;
            local_8._0_1_ = 0x26;
            if ((local_40 != (int *)0x0) && (*local_40 = *local_40 + -1, *local_40 == 0)) {
              FUN_006ba940();
            }
            FUN_006bad60();
          }
        }
      }
    }
  }
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c < 1)) {
    TclFreeObj(local_1c);
  }
LAB_0064129d:
  local_8._0_1_ = 0x27;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x28);
  FUN_004297b0(0);
  if (local_58 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar15;
}

