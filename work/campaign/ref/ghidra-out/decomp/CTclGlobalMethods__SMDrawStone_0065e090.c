
undefined4
CTclGlobalMethods__SMDrawStone(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  undefined **ppuVar9;
  undefined4 uVar10;
  uint uVar11;
  int *piVar12;
  bool bVar13;
  float fVar14;
  undefined8 uVar15;
  char *pcVar16;
  int *piVar17;
  double local_164;
  undefined4 *local_15c;
  double local_158;
  double local_150;
  double local_148;
  undefined4 local_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  int local_130;
  int iStack_12c;
  int iStack_128;
  int iStack_124;
  undefined4 local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  uint local_110;
  uint uStack_10c;
  byte *pbStack_108;
  byte *pbStack_104;
  undefined4 local_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 local_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 local_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  uint local_c0;
  uint uStack_bc;
  uint uStack_b8;
  uint uStack_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  uint local_a0;
  uint local_9c;
  int *local_98;
  int *local_94;
  uint local_90;
  int *local_8c;
  uint local_88;
  int *local_84;
  uint local_80;
  int *local_7c;
  uint local_78;
  int *local_74;
  uint local_70;
  int *local_6c;
  int *local_68;
  int *local_64;
  int local_60;
  int *local_5c;
  uint local_58;
  int local_54;
  char local_50;
  int *local_4c;
  int *local_48;
  int local_44;
  undefined4 *local_40;
  byte *local_3c;
  int local_38;
  uint local_34;
  byte *local_30;
  byte *local_2c;
  uint local_28;
  uint local_24;
  byte *local_20;
  byte *local_1c;
  byte *local_18;
  byte *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f033;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7358) &&
     (FUN_006cebf4(&DAT_00ca7358,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7358 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca735c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::SMDrawStone()";
    *(int *)(&DAT_00773650 + iVar8) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7358);
  }
  iVar8 = DAT_00ca735c;
  local_15c = &DAT_00ca735c;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca735c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar10;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar2 == 0) {
    uVar15 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar15;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  if (param_3 < 2) {
    FUN_006bc8f0(1);
    uVar10 = 1;
  }
  else {
    FUN_004298b0(param_3,param_4);
    local_8 = CONCAT31(local_8._1_3_,2);
    iVar2 = FUN_005f8080();
    local_18 = (byte *)0x1;
    local_44 = iVar2;
    do {
      if (((int)local_18 < 0) || (local_38 <= (int)local_18)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar4 = local_40;
        if (local_3c == (byte *)0x0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar4 = local_40;
        }
      }
      else {
        if (local_3c <= local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar4 = local_40 + (int)local_18;
      }
      piVar17 = (int *)*puVar4;
      if (piVar17 == (int *)0x0) {
LAB_0065e367:
        pbVar7 = local_18;
        if (((int)local_18 < 0) || (local_38 <= (int)local_18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar4 = local_40;
          if (local_3c == (byte *)0x0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar4 = local_40;
          }
        }
        else {
          if (local_3c <= local_18) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar4 = local_40 + (int)pbVar7;
        }
        piVar17 = (int *)*puVar4;
        if (piVar17 != (int *)0x0) {
          *piVar17 = *piVar17 + 1;
          local_1c = (byte *)0x731068;
          pbVar3 = (byte *)Tcl_GetStringFromObj(piVar17,0);
          pbVar7 = local_1c;
          do {
            bVar1 = *pbVar3;
            bVar13 = bVar1 < *pbVar7;
            if (bVar1 != *pbVar7) {
LAB_0065e400:
              local_24 = -(uint)bVar13 | 1;
              goto LAB_0065e405;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar13 = bVar1 < pbVar7[1];
            if (bVar1 != pbVar7[1]) goto LAB_0065e400;
            pbVar3 = pbVar3 + 2;
            pbVar7 = pbVar7 + 2;
          } while (bVar1 != 0);
          local_24 = 0;
LAB_0065e405:
          *piVar17 = *piVar17 + -1;
          if (*piVar17 < 1) {
            TclFreeObj(piVar17);
          }
          if (local_24 == 0) {
            local_20 = (byte *)0x10;
            local_14 = (byte *)(*(int *)(iVar2 + 0x7c) * 2 + -0x14);
            pbVar7 = local_18;
            if (0 < (int)local_14) {
              local_b0 = 0;
              uStack_a4 = 0;
              uStack_ac = 0;
              uStack_a8 = 0;
              local_f0 = 0;
              uStack_e4 = 0;
              uStack_ec = 0;
              uStack_e8 = 0;
              do {
                iVar8 = *(int *)(iVar2 + 0x7c) * 4;
                pbVar3 = local_20 + 6;
                FUN_005fc9d0(iVar8 - (int)local_14,local_20,iVar8,pbVar3,8,0,0x3f800000,local_b0,
                             uStack_ac,uStack_a8,uStack_a4);
                pbVar7 = local_20;
                FUN_005fc9d0(0,local_20,local_14,pbVar3,4,0,0x3f800000,local_f0,uStack_ec,uStack_e8,
                             uStack_e4);
                local_20 = pbVar7 + 4;
                local_14 = local_14 + -8;
                pbVar7 = local_18;
              } while (0 < (int)local_14);
            }
            goto LAB_0065e351;
          }
        }
        puVar4 = (undefined4 *)FUN_004295e0(local_18);
        piVar17 = (int *)*puVar4;
        if (piVar17 == (int *)0x0) {
LAB_0065e7c4:
          puVar4 = (undefined4 *)FUN_004295e0(local_18);
          piVar17 = (int *)*puVar4;
          if (piVar17 != (int *)0x0) {
            *piVar17 = *piVar17 + 1;
            local_1c = (byte *)0x731088;
            pbVar3 = (byte *)Tcl_GetStringFromObj(piVar17,0);
            pbVar7 = local_1c;
            do {
              bVar1 = *pbVar3;
              bVar13 = bVar1 < *pbVar7;
              if (bVar1 != *pbVar7) {
LAB_0065e811:
                local_2c = (byte *)(-(uint)bVar13 | 1);
                goto LAB_0065e816;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar3[1];
              bVar13 = bVar1 < pbVar7[1];
              if (bVar1 != pbVar7[1]) goto LAB_0065e811;
              pbVar3 = pbVar3 + 2;
              pbVar7 = pbVar7 + 2;
            } while (bVar1 != 0);
            local_2c = (byte *)0x0;
LAB_0065e816:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
            if (local_2c == (byte *)0x0) {
              uVar11 = *(uint *)(iVar2 + 0x54);
              pbVar7 = local_18;
              if (uVar11 != 0xffffffff) {
                ppuVar9 = &PTR_0071ce50;
                pbVar3 = (byte *)(*(int *)(iVar2 + 0x50) + 0xc);
                do {
                  bVar1 = *pbVar3;
                  bVar13 = bVar1 < *(byte *)ppuVar9;
                  if (bVar1 != *(byte *)ppuVar9) {
LAB_0065e870:
                    uVar5 = -(uint)bVar13 | 1;
                    goto LAB_0065e875;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar3[1];
                  bVar13 = bVar1 < *(byte *)((int)ppuVar9 + 1);
                  if (bVar1 != *(byte *)((int)ppuVar9 + 1)) goto LAB_0065e870;
                  pbVar3 = pbVar3 + 2;
                  ppuVar9 = (undefined **)((int)ppuVar9 + 2);
                } while (bVar1 != 0);
                uVar5 = 0;
LAB_0065e875:
                if (uVar5 != 0) {
                  if (*(uint *)(iVar2 + 0xc) <= uVar11) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  iVar8 = *(int *)(iVar2 + 8);
                  pbVar7 = local_18;
                  if (*(char *)(uVar11 * 100 + 0x40 + iVar8) != '\0') {
                    local_1c = *(byte **)(iVar2 + 0x54);
                    pbVar7 = *(byte **)(iVar2 + 0xc);
                    local_14 = local_1c;
                    if (pbVar7 <= local_1c) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      local_14 = *(byte **)(iVar2 + 0x54);
                      iVar8 = *(int *)(iVar2 + 8);
                      pbVar7 = *(byte **)(iVar2 + 0xc);
                    }
                    local_34 = *(int *)((int)local_1c * 100 + 0x48 + iVar8) +
                               *(int *)(iVar2 + 0x40) * 4;
                    local_20 = local_14;
                    if (pbVar7 <= local_14) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      local_20 = *(byte **)(iVar2 + 0x54);
                      iVar8 = *(int *)(iVar2 + 8);
                      pbVar7 = *(byte **)(iVar2 + 0xc);
                    }
                    local_24 = *(int *)((int)local_14 * 100 + 0x4c + iVar8) +
                               *(int *)(iVar2 + 0x44) * 4;
                    local_2c = local_20;
                    if (pbVar7 <= local_20) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      local_2c = *(byte **)(iVar2 + 0x54);
                      iVar8 = *(int *)(iVar2 + 8);
                      pbVar7 = *(byte **)(iVar2 + 0xc);
                    }
                    local_30 = *(byte **)((int)local_20 * 100 + 0x30 + iVar8);
                    local_14 = local_2c;
                    if (pbVar7 <= local_2c) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      local_14 = *(byte **)(iVar2 + 0x54);
                      iVar8 = *(int *)(iVar2 + 8);
                      pbVar7 = *(byte **)(iVar2 + 0xc);
                    }
                    local_2c = *(byte **)((int)local_2c * 100 + 0x34 + iVar8);
                    if (pbVar7 <= local_14) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      iVar8 = *(int *)(iVar2 + 8);
                    }
                    local_28 = *(uint *)((int)local_14 * 100 + 0x5c + iVar8);
                    pbVar7 = local_2c;
                    if (local_28 != 0xffffffff) {
                      uVar11 = *(uint *)(iVar2 + 0x54);
                      if (*(uint *)(iVar2 + 0xc) <= uVar11) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        iVar8 = *(int *)(iVar2 + 8);
                      }
                      uVar11 = *(uint *)(uVar11 * 100 + 0x3c + iVar8);
                      pbVar7 = local_2c;
                      if (uVar11 != 0xffffffff) {
                        if (*(uint *)(iVar2 + 0x14) <= uVar11) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        }
                        local_14 = (byte *)(uVar11 * 0x28);
                        local_1c = local_14 + *(int *)(iVar2 + 0x10);
                        if (*(uint *)(local_1c + 8) <= local_28) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        }
                        local_20 = (byte *)(local_28 * 0x18);
                        local_34 = local_34 + *(int *)(local_20 + *(int *)(local_1c + 4) + 4);
                        if (*(uint *)(iVar2 + 0x14) <= uVar11) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        }
                        local_1c = local_14 + *(int *)(iVar2 + 0x10);
                        if (*(uint *)(local_1c + 8) <= local_28) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        }
                        local_24 = local_24 + *(int *)(local_20 + *(int *)(local_1c + 4) + 8);
                        if (*(uint *)(iVar2 + 0x14) <= uVar11) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        }
                        local_1c = local_14 + *(int *)(iVar2 + 0x10);
                        if (*(uint *)(local_1c + 8) <= local_28) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        }
                        local_30 = *(byte **)(local_20 + *(int *)(local_1c + 4) + 0xc);
                        if (*(uint *)(iVar2 + 0x14) <= uVar11) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        }
                        pbVar7 = local_14;
                        iVar8 = *(int *)(iVar2 + 0x10);
                        if (*(uint *)(local_14 + iVar8 + 8) <= local_28) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        }
                        pbVar7 = *(byte **)(local_20 + *(int *)(pbVar7 + iVar8 + 4) + 0x10);
                      }
                    }
                    uStack_10c = local_24;
                    local_110 = local_34;
                    pbStack_104 = pbVar7 + local_24;
                    pbStack_108 = local_30 + local_34;
                    FUN_005fc9d0(0,local_24,*(int *)(iVar2 + 0x7c) << 2,pbStack_104,3,0,0x40000000,
                                 local_34,local_24,pbStack_108,pbStack_104);
                    pbVar7 = local_18;
                  }
                }
              }
              goto LAB_0065e351;
            }
          }
          puVar4 = (undefined4 *)FUN_004295e0(local_18);
          piVar17 = (int *)*puVar4;
          if (piVar17 != (int *)0x0) {
            *piVar17 = *piVar17 + 1;
            local_1c = &DAT_00731094;
            pbVar3 = (byte *)Tcl_GetStringFromObj(piVar17,0);
            pbVar7 = local_1c;
            do {
              bVar1 = *pbVar3;
              bVar13 = bVar1 < *pbVar7;
              if (bVar1 != *pbVar7) {
LAB_0065ebc0:
                local_30 = (byte *)(-(uint)bVar13 | 1);
                goto LAB_0065ebc5;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar3[1];
              bVar13 = bVar1 < pbVar7[1];
              if (bVar1 != pbVar7[1]) goto LAB_0065ebc0;
              pbVar3 = pbVar3 + 2;
              pbVar7 = pbVar7 + 2;
            } while (bVar1 != 0);
            local_30 = (byte *)0x0;
LAB_0065ebc5:
            *piVar17 = *piVar17 + -1;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
            if (local_30 == (byte *)0x0) {
              uVar11 = *(uint *)(iVar2 + 0x54);
              pbVar7 = local_18;
              if (uVar11 != 0xffffffff) {
                if (*(uint *)(iVar2 + 0xc) <= uVar11) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                local_24 = *(uint *)(uVar11 * 100 + 0x3c + *(int *)(iVar2 + 8));
                pbVar7 = local_18;
                if (local_24 != 0xffffffff) {
                  local_28 = 0;
                  local_20 = (byte *)(local_24 * 0x28);
                  local_14 = (byte *)0x0;
                  while( true ) {
                    if (*(uint *)(iVar2 + 0x14) <= local_24) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    iVar8 = *(int *)(iVar2 + 0x10);
                    pbVar7 = local_18;
                    if (*(int *)(local_20 + iVar8 + 0x10) <= (int)local_28) break;
                    if (*(uint *)(iVar2 + 0x14) <= local_24) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      iVar8 = *(int *)(iVar2 + 0x10);
                    }
                    if (*(uint *)(local_20 + iVar8 + 0x10) <= local_28) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    pbVar7 = local_14 + *(int *)(local_20 + iVar8 + 0xc);
                    local_130 = *(int *)pbVar7;
                    iStack_12c = *(int *)(pbVar7 + 4);
                    iStack_128 = *(int *)(pbVar7 + 8);
                    iStack_124 = *(int *)(pbVar7 + 0xc);
                    if (*(uint *)(iVar2 + 0x14) <= local_24) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    pbVar7 = local_20;
                    local_1c = *(byte **)(iVar2 + 0x10);
                    if (*(uint *)(local_20 + (int)local_1c + 0x10) <= local_28) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    pbVar3 = *(byte **)(iVar2 + 0x54);
                    local_1c = *(byte **)(local_14 + *(int *)(pbVar7 + (int)local_1c + 0xc) + 0x10);
                    local_30 = pbVar3;
                    if (*(byte **)(iVar2 + 0xc) <= pbVar3) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      local_30 = *(byte **)(iVar2 + 0x54);
                    }
                    iVar8 = *(int *)(iVar2 + 8);
                    local_2c = (byte *)(*(int *)((int)pbVar3 * 100 + 0x48 + iVar8) +
                                       *(int *)(iVar2 + 0x40) * 4);
                    if (*(byte **)(iVar2 + 0xc) <= local_30) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      iVar8 = *(int *)(iVar2 + 8);
                    }
                    local_120 = 0;
                    uStack_114 = 0;
                    uStack_11c = 0;
                    uStack_118 = 0;
                    iVar8 = *(int *)((int)local_30 * 100 + 0x4c + iVar8) +
                            *(int *)(iVar2 + 0x44) * 4;
                    FUN_005fc9d0(local_2c + local_130,iStack_12c + iVar8,local_2c + iStack_128 + 2,
                                 iStack_124 + 2 + iVar8,0,local_1c,0x40200000,0,0,0,0);
                    local_28 = local_28 + 1;
                    local_14 = local_14 + 0x14;
                  }
                }
              }
              goto LAB_0065e351;
            }
          }
          puVar4 = (undefined4 *)FUN_004295e0(local_18);
          piVar17 = (int *)*puVar4;
          if (piVar17 == (int *)0x0) {
LAB_0065f300:
            puVar4 = (undefined4 *)FUN_004295e0(local_18);
            piVar17 = (int *)*puVar4;
            if (piVar17 != (int *)0x0) {
              *piVar17 = *piVar17 + 1;
            }
            pcVar16 = "invalid param";
            goto LAB_0065f31d;
          }
          *piVar17 = *piVar17 + 1;
          pcVar16 = "-matlist";
          pbVar7 = (byte *)Tcl_GetStringFromObj(piVar17,0);
          do {
            bVar1 = *pbVar7;
            bVar13 = bVar1 < (byte)*pcVar16;
            if (bVar1 != *pcVar16) {
LAB_0065ee20:
              uVar11 = -(uint)bVar13 | 1;
              goto LAB_0065ee25;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar7[1];
            bVar13 = bVar1 < ((byte *)pcVar16)[1];
            if (bVar1 != ((byte *)pcVar16)[1]) goto LAB_0065ee20;
            pbVar7 = pbVar7 + 2;
            pcVar16 = (char *)((byte *)pcVar16 + 2);
          } while (bVar1 != 0);
          uVar11 = 0;
LAB_0065ee25:
          *piVar17 = *piVar17 + -1;
          if (*piVar17 < 1) {
            TclFreeObj(piVar17);
          }
          pbVar7 = local_18;
          if (uVar11 != 0) goto LAB_0065f300;
          local_1c = local_18 + 3;
          if (param_3 <= (int)local_1c) goto LAB_0065f2c7;
          puVar4 = (undefined4 *)FUN_004295e0(local_18 + 1);
          piVar17 = (int *)*puVar4;
          if (piVar17 == (int *)0x0) {
            local_20 = (byte *)0x0;
          }
          else {
            *piVar17 = *piVar17 + 1;
            iVar2 = Tcl_GetIntFromObj(0,piVar17,&local_a0);
            *piVar17 = *piVar17 + -1;
            local_20 = (byte *)(-(uint)(iVar2 != 1) & local_a0);
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          puVar4 = (undefined4 *)FUN_004295e0(pbVar7 + 2);
          piVar17 = (int *)*puVar4;
          if (piVar17 == (int *)0x0) {
            local_34 = 0;
          }
          else {
            *piVar17 = *piVar17 + 1;
            iVar2 = Tcl_GetIntFromObj(0,piVar17,&local_58);
            *piVar17 = *piVar17 + -1;
            local_34 = -(uint)(iVar2 != 1) & local_58;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          puVar4 = (undefined4 *)FUN_004295e0(local_1c);
          piVar17 = (int *)*puVar4;
          if (piVar17 != (int *)0x0) {
            *piVar17 = *piVar17 + 1;
          }
          local_8 = CONCAT31(local_8._1_3_,3);
          local_98 = piVar17;
          local_94 = piVar17;
          if ((piVar17 == (int *)0x0) ||
             (iVar2 = Tcl_ListObjIndex(0,piVar17,0,&local_5c), piVar12 = local_5c, iVar2 != 0)) {
            piVar12 = (int *)0x0;
LAB_0065ef76:
            ppuVar9 = &PTR_0071ce50;
            pbVar7 = &DAT_00730e24;
            do {
              bVar1 = *(byte *)ppuVar9;
              bVar13 = bVar1 < *pbVar7;
              if (bVar1 != *pbVar7) {
LAB_0065efa5:
                local_14 = (byte *)(-(uint)bVar13 | 1);
                goto LAB_0065efad;
              }
              if (bVar1 == 0) break;
              bVar1 = *(byte *)((int)ppuVar9 + 1);
              bVar13 = bVar1 < pbVar7[1];
              if (bVar1 != pbVar7[1]) goto LAB_0065efa5;
              ppuVar9 = (undefined **)((int)ppuVar9 + 2);
              pbVar7 = pbVar7 + 2;
            } while (bVar1 != 0);
            local_14 = (byte *)0x0;
LAB_0065efad:
            if (piVar12 != (int *)0x0) goto LAB_0065efb1;
          }
          else {
            if (local_5c == (int *)0x0) goto LAB_0065ef76;
            *local_5c = *local_5c + 1;
            local_30 = &DAT_00730e24;
            pbVar3 = (byte *)Tcl_GetStringFromObj(local_5c,0);
            pbVar7 = local_30;
            do {
              bVar1 = *pbVar3;
              bVar13 = bVar1 < *pbVar7;
              if (bVar1 != *pbVar7) {
LAB_0065ef6a:
                local_14 = (byte *)(-(uint)bVar13 | 1);
                goto LAB_0065efb1;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar3[1];
              bVar13 = bVar1 < pbVar7[1];
              if (bVar1 != pbVar7[1]) goto LAB_0065ef6a;
              pbVar3 = pbVar3 + 2;
              pbVar7 = pbVar7 + 2;
            } while (bVar1 != 0);
            local_14 = (byte *)0x0;
LAB_0065efb1:
            *piVar12 = *piVar12 + -1;
            if (*piVar12 < 1) {
              TclFreeObj(piVar12);
            }
          }
          if (local_14 == (byte *)0x0) {
            local_28 = 1;
            iVar2 = local_44;
            while( true ) {
              if (piVar17 == (int *)0x0) {
                iVar8 = 0;
              }
              else {
                iVar6 = Tcl_ListObjLength(0,piVar17,&local_60);
                iVar8 = local_60;
                if (iVar6 != 0) {
                  iVar8 = 0;
                }
              }
              if (iVar8 <= (int)local_28) break;
              if ((piVar17 == (int *)0x0) ||
                 (iVar2 = Tcl_ListObjIndex(0,piVar17,local_28,&local_64), iVar2 != 0)) {
                local_68 = (int *)0x0;
              }
              else {
                local_68 = local_64;
                if (local_64 != (int *)0x0) {
                  *local_64 = *local_64 + 1;
                }
              }
              piVar17 = local_68;
              local_8 = CONCAT31(local_8._1_3_,4);
              if (((local_68 == (int *)0x0) ||
                  (iVar2 = Tcl_ListObjIndex(0,local_68,0,&local_6c), piVar12 = local_6c, iVar2 != 0)
                  ) || (local_6c == (int *)0x0)) {
                local_2c = (byte *)0x0;
              }
              else {
                *local_6c = *local_6c + 1;
                iVar2 = Tcl_GetIntFromObj(0,local_6c,&local_70);
                *piVar12 = *piVar12 + -1;
                local_2c = (byte *)(-(uint)(iVar2 != 1) & local_70);
                if (*piVar12 < 1) {
                  TclFreeObj(piVar12);
                }
              }
              if (((piVar17 == (int *)0x0) ||
                  (iVar2 = Tcl_ListObjIndex(0,piVar17,1,&local_74), piVar12 = local_74, iVar2 != 0))
                 || (local_74 == (int *)0x0)) {
                local_14 = (byte *)0x0;
              }
              else {
                *local_74 = *local_74 + 1;
                iVar2 = Tcl_GetIntFromObj(0,local_74,&local_78);
                *piVar12 = *piVar12 + -1;
                local_14 = (byte *)(-(uint)(iVar2 != 1) & local_78);
                if (*piVar12 < 1) {
                  TclFreeObj(piVar12);
                }
              }
              if (((piVar17 == (int *)0x0) ||
                  (iVar2 = Tcl_ListObjIndex(0,piVar17,2,&local_7c), piVar12 = local_7c, iVar2 != 0))
                 || (local_7c == (int *)0x0)) {
                local_24 = 0;
              }
              else {
                *local_7c = *local_7c + 1;
                iVar2 = Tcl_GetIntFromObj(0,local_7c,&local_80);
                *piVar12 = *piVar12 + -1;
                local_24 = -(uint)(iVar2 != 1) & local_80;
                if (*piVar12 < 1) {
                  TclFreeObj(piVar12);
                }
              }
              if (((piVar17 == (int *)0x0) ||
                  (iVar2 = Tcl_ListObjIndex(0,piVar17,3,&local_84), piVar12 = local_84, iVar2 != 0))
                 || (local_84 == (int *)0x0)) {
                local_18 = (byte *)0x0;
              }
              else {
                *local_84 = *local_84 + 1;
                iVar2 = Tcl_GetIntFromObj(0,local_84,&local_88);
                *piVar12 = *piVar12 + -1;
                local_18 = (byte *)(-(uint)(iVar2 != 1) & local_88);
                if (*piVar12 < 1) {
                  TclFreeObj(piVar12);
                }
              }
              if (((piVar17 == (int *)0x0) ||
                  (iVar2 = Tcl_ListObjIndex(0,piVar17,4,&local_8c), piVar12 = local_8c, iVar2 != 0))
                 || (local_8c == (int *)0x0)) {
                pbVar7 = (byte *)0x0;
              }
              else {
                *local_8c = *local_8c + 1;
                iVar2 = Tcl_GetIntFromObj(0,local_8c,&local_90);
                *piVar12 = *piVar12 + -1;
                local_30 = (byte *)(-(uint)(iVar2 != 1) & local_90);
                pbVar7 = local_30;
                if (*piVar12 < 1) {
                  TclFreeObj(piVar12);
                  pbVar7 = local_30;
                }
              }
              iVar2 = local_44;
              local_140 = 0;
              uStack_134 = 0;
              uStack_13c = 0;
              uStack_138 = 0;
              FUN_005fc9d0(local_14 + (int)local_20,local_34 + local_24,
                           local_18 + (int)local_14 + (int)(local_20 + 2),
                           pbVar7 + local_34 + 2 + local_24,0,local_2c,0x40200000,0,0,0,0);
              if ((piVar17 != (int *)0x0) && (*piVar17 = *piVar17 + -1, *piVar17 < 1)) {
                TclFreeObj(piVar17);
              }
              local_28 = local_28 + 1;
              piVar17 = local_94;
            }
            local_8 = CONCAT31(local_8._1_3_,2);
            pbVar7 = local_1c;
            if ((piVar17 != (int *)0x0) && (*piVar17 = *piVar17 + -1, *piVar17 < 1)) {
              TclFreeObj(piVar17);
              pbVar7 = local_1c;
            }
            goto LAB_0065e351;
          }
          if (piVar17 != (int *)0x0) {
            *piVar17 = *piVar17 + 1;
          }
          FUN_006bc6a0("invalid matlist",piVar17);
          FUN_006bad60();
        }
        else {
          *piVar17 = *piVar17 + 1;
          local_1c = (byte *)0x730ac0;
          pbVar3 = (byte *)Tcl_GetStringFromObj(piVar17,0);
          pbVar7 = local_1c;
          do {
            bVar1 = *pbVar3;
            bVar13 = bVar1 < *pbVar7;
            if (bVar1 != *pbVar7) {
LAB_0065e560:
              local_24 = -(uint)bVar13 | 1;
              goto LAB_0065e565;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar13 = bVar1 < pbVar7[1];
            if (bVar1 != pbVar7[1]) goto LAB_0065e560;
            pbVar3 = pbVar3 + 2;
            pbVar7 = pbVar7 + 2;
          } while (bVar1 != 0);
          local_24 = 0;
LAB_0065e565:
          *piVar17 = *piVar17 + -1;
          if (*piVar17 < 1) {
            TclFreeObj(piVar17);
          }
          if (local_24 != 0) goto LAB_0065e7c4;
          local_2c = local_18 + 5;
          if ((int)local_2c < param_3) {
            puVar4 = (undefined4 *)FUN_004295e0(local_18 + 1);
            piVar17 = (int *)*puVar4;
            if (piVar17 == (int *)0x0) {
              local_28 = 0;
            }
            else {
              *piVar17 = *piVar17 + 1;
              iVar8 = Tcl_GetDoubleFromObj(0,piVar17,&local_164);
              if (iVar8 == 1) {
                fVar14 = 0.0;
              }
              else {
                fVar14 = (float)local_164;
              }
              *piVar17 = *piVar17 + -1;
              local_28 = (uint)fVar14;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
              }
            }
            puVar4 = (undefined4 *)FUN_004295e0(local_18 + 2);
            piVar17 = (int *)*puVar4;
            if (piVar17 == (int *)0x0) {
              local_20 = (byte *)0x0;
            }
            else {
              *piVar17 = *piVar17 + 1;
              iVar8 = Tcl_GetDoubleFromObj(0,piVar17,&local_148);
              if (iVar8 == 1) {
                fVar14 = 0.0;
              }
              else {
                fVar14 = (float)local_148;
              }
              *piVar17 = *piVar17 + -1;
              local_20 = (byte *)(int)fVar14;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
              }
            }
            puVar4 = (undefined4 *)FUN_004295e0(local_18 + 3);
            piVar17 = (int *)*puVar4;
            if (piVar17 == (int *)0x0) {
              local_14 = (byte *)0x0;
            }
            else {
              *piVar17 = *piVar17 + 1;
              iVar8 = Tcl_GetDoubleFromObj(0,piVar17,&local_150);
              if (iVar8 == 1) {
                fVar14 = 0.0;
              }
              else {
                fVar14 = (float)local_150;
              }
              *piVar17 = *piVar17 + -1;
              local_14 = (byte *)(int)fVar14;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
              }
            }
            puVar4 = (undefined4 *)FUN_004295e0(local_18 + 4);
            piVar17 = (int *)*puVar4;
            if (piVar17 == (int *)0x0) {
              local_34 = 0;
            }
            else {
              *piVar17 = *piVar17 + 1;
              iVar8 = Tcl_GetDoubleFromObj(0,piVar17,&local_158);
              if (iVar8 == 1) {
                fVar14 = 0.0;
              }
              else {
                fVar14 = (float)local_158;
              }
              *piVar17 = *piVar17 + -1;
              local_34 = (uint)fVar14;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
              }
            }
            puVar4 = (undefined4 *)FUN_004295e0(local_2c);
            piVar17 = (int *)*puVar4;
            if (piVar17 == (int *)0x0) {
              uVar11 = 0;
            }
            else {
              *piVar17 = *piVar17 + 1;
              iVar8 = Tcl_GetIntFromObj(0,piVar17,&local_9c);
              *piVar17 = *piVar17 + -1;
              local_24 = -(uint)(iVar8 != 1) & local_9c;
              uVar11 = local_24;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
                uVar11 = local_24;
              }
            }
            local_100 = 0;
            uStack_f4 = 0;
            uStack_fc = 0;
            uStack_f8 = 0;
            FUN_005fc9d0(local_28,local_20,local_14,local_34,uVar11,0,0x40200000,0,0,0,0);
            pbVar7 = local_2c;
            goto LAB_0065e351;
          }
LAB_0065f2c7:
          pcVar16 = "invalid nr of arguments";
          piVar17 = (int *)0x0;
LAB_0065f31d:
          FUN_006bc6a0(pcVar16,piVar17);
        }
        uVar10 = 1;
        goto LAB_0065f32a;
      }
      *piVar17 = *piVar17 + 1;
      local_1c = (byte *)0x731060;
      pbVar3 = (byte *)Tcl_GetStringFromObj(piVar17,0);
      pbVar7 = local_1c;
      do {
        bVar1 = *pbVar3;
        bVar13 = bVar1 < *pbVar7;
        if (bVar1 != *pbVar7) {
LAB_0065e210:
          local_24 = -(uint)bVar13 | 1;
          goto LAB_0065e215;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar13 = bVar1 < pbVar7[1];
        if (bVar1 != pbVar7[1]) goto LAB_0065e210;
        pbVar3 = pbVar3 + 2;
        pbVar7 = pbVar7 + 2;
      } while (bVar1 != 0);
      local_24 = 0;
LAB_0065e215:
      *piVar17 = *piVar17 + -1;
      if (*piVar17 < 1) {
        TclFreeObj(piVar17);
      }
      if (local_24 != 0) goto LAB_0065e367;
      local_c0 = local_24;
      uStack_bc = local_24;
      uStack_b8 = local_24;
      uStack_b4 = local_24;
      FUN_005fc9d0(0,0,*(int *)(iVar2 + 0x7c) << 2,0x20,1,0,0x40200000,0,0,0,0);
      local_d0 = 0;
      uStack_c4 = 0;
      uStack_cc = 0;
      uStack_c8 = 0;
      FUN_005fc9d0(0,0,0x20,*(int *)(iVar2 + 0x80) * 4 + 4,4,0,0x3f800000,0,0,0,0);
      local_e0 = 0;
      uStack_d4 = 0;
      uStack_dc = 0;
      uStack_d8 = 0;
      iVar8 = *(int *)(iVar2 + 0x7c) * 4;
      FUN_005fc9d0(iVar8 + -0x20,0,iVar8,*(int *)(iVar2 + 0x80) * 4 + 4,8,0,0x3f800000,0,0,0,0);
      FUN_005fa510(0,0,*(undefined4 *)(iVar2 + 0x7c),9);
      pbVar7 = local_18;
LAB_0065e351:
      local_18 = pbVar7 + 1;
    } while ((int)(pbVar7 + 2) <= param_3);
    uVar10 = 0;
LAB_0065f32a:
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8._0_1_ = 6;
    FUN_004297b0(0);
    if (local_40 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  if ((local_50 != '\0') && (local_54 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_54);
  }
  local_54 = 0;
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 7;
  if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,8);
  if ((local_4c != (int *)0x0) && (*local_4c = *local_4c + -1, *local_4c == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

