
undefined4
CTclObjMethods__TimerEvent(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  int *piVar6;
  undefined **ppuVar7;
  byte *pbVar8;
  uint uVar9;
  void *pvVar10;
  BOOL BVar11;
  undefined4 *puVar12;
  int iVar13;
  char *pcVar14;
  byte *pbVar15;
  byte *pbVar16;
  uint uVar17;
  code *pcVar18;
  undefined4 uVar19;
  uint uVar20;
  bool bVar21;
  undefined8 uVar22;
  double dVar23;
  undefined4 *puVar24;
  undefined1 local_cc [12];
  undefined1 local_c0 [12];
  undefined1 local_b4 [12];
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  double local_88;
  int *local_80;
  undefined4 *local_7c;
  int local_78;
  double local_68;
  double local_60;
  int *local_58;
  uint local_54;
  undefined4 *local_50;
  int *local_4c;
  int local_48;
  int *local_44;
  uint local_40;
  int *local_3c;
  uint local_38;
  int *local_34;
  uint local_30;
  int local_2c;
  int *local_28;
  int *local_24;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712028;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7be8) &&
     (FUN_006cebf4(&DAT_00ca7be8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca7be8 == -1)) {
    iVar13 = DAT_00783650 * 0x40;
    DAT_00ca7bec = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar13) = "TCL:CTclObjMethods::TimerEvent()";
    *(int *)(&DAT_00773650 + iVar13) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7be8);
  }
  iVar13 = DAT_00ca7bec;
  local_7c = &DAT_00ca7bec;
  uVar19 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7bec * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar19;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar13 * 0x10];
  if (iVar5 == 0) {
    uVar22 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar13 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar13 * 0x10) = uVar22;
  }
  (&DAT_00773654)[iVar13 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_48 = FUN_005c71c0();
  if (local_48 == 0) {
    uVar19 = 1;
  }
  else {
    piVar6 = (int *)FUN_006ba810(0x19);
    piVar6[2] = -1;
    *piVar6 = 0;
    *(undefined1 *)(piVar6 + 3) = 0;
    piVar6[1] = 0x14;
    piVar6[3] = 0x73696874;
    *(undefined1 *)(piVar6 + 4) = 0;
    piVar6[2] = 4;
    *piVar6 = 1;
    if (local_78 == 0) {
      local_2c = local_78;
      iVar5 = 1;
    }
    else {
      local_2c = Tcl_GetAssocData();
      iVar5 = *piVar6;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar6 = iVar5 + -1;
    if (iVar5 + -1 == 0) {
      FUN_006ba940();
    }
    if (local_18 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar12 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar12 = local_20;
      }
    }
    else {
      if (local_1c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar12 = local_20 + 2;
    }
    piVar6 = (int *)*puVar12;
    if (piVar6 != (int *)0x0) {
      *piVar6 = *piVar6 + 1;
    }
    local_8._0_1_ = 4;
    local_80 = piVar6;
    local_4c = piVar6;
    if (piVar6 == (int *)0x0) {
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar6,0);
    }
    FUN_006b8fb0(ppuVar7);
    iVar5 = FUN_005ba5b0(&local_28);
    local_8._0_1_ = 5;
    if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (iVar5 == -1) {
      if (local_18 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar12 = local_20;
        if (local_1c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar12 = local_20;
        }
      }
      else {
        if (local_1c < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar12 = local_20 + 2;
      }
      piVar2 = (int *)*puVar12;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      FUN_006bc6a0("unregistered event",piVar2);
      uVar19 = 1;
    }
    else {
      local_50 = (undefined4 *)0x0;
      local_8._0_1_ = 6;
      local_38 = 3;
      local_40 = 1;
      local_68 = *(double *)(DAT_00772400 + 0xa088);
      local_60 = 0.0;
      local_28 = (int *)0x0;
      local_30 = FUN_006ba810(0xd8);
      local_8._0_1_ = 7;
      if (local_30 == 0) {
        local_14 = (undefined4 *)0x0;
      }
      else {
        local_14 = (undefined4 *)FUN_005b9d30();
      }
      local_8 = CONCAT31(local_8._1_3_,6);
      if (local_14 != (undefined4 *)0x0) {
        LOCK();
        local_14[1] = local_14[1] + 1;
        UNLOCK();
      }
      local_14[2] = iVar5;
      local_14[3] = local_48;
      puVar12 = local_14;
      uVar9 = 1;
      local_50 = local_14;
      if (4 < param_3) {
        uVar17 = 4;
        uVar20 = 3;
        do {
          if (((int)uVar20 < 0) || (local_18 <= (int)uVar20)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar12 = local_20;
            if (local_1c == 0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar12 = local_20;
            }
          }
          else {
            if (local_1c <= uVar20) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar12 = local_20 + uVar20;
          }
          piVar6 = (int *)*puVar12;
          if (piVar6 != (int *)0x0) {
            *piVar6 = *piVar6 + 1;
          }
          local_58 = piVar6;
          local_44 = piVar6;
          if (((int)uVar17 < 0) || (local_18 <= (int)uVar17)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar12 = local_20;
            if (local_1c == 0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar12 = local_20;
            }
          }
          else {
            if (local_1c <= uVar17) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar12 = local_20 + uVar17;
          }
          piVar2 = (int *)*puVar12;
          if (piVar2 != (int *)0x0) {
            *piVar2 = *piVar2 + 1;
          }
          local_8._0_1_ = 9;
          local_34 = piVar2;
          if (piVar6 == (int *)0x0) {
            ppuVar7 = &PTR_0071ce50;
          }
          else {
            ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar6,0);
          }
          FUN_006b8fb0(ppuVar7);
          local_8._0_1_ = 10;
          if (piVar2 == (int *)0x0) {
            ppuVar7 = &PTR_0071ce50;
          }
          else {
            ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
          }
          FUN_006b8fb0(ppuVar7);
          puVar12 = local_14;
          piVar6 = local_24;
          local_8._0_1_ = 0xb;
          uVar4 = (undefined1)local_8;
          local_8._0_1_ = 0xb;
          pcVar14 = "-attime";
          pbVar16 = (byte *)(local_3c + 3);
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar14;
            if (bVar1 != *pcVar14) {
LAB_006a0330:
              uVar9 = -(uint)bVar21 | 1;
              goto LAB_006a0335;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar14)[1];
            if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_006a0330;
            pbVar8 = pbVar8 + 2;
            pcVar14 = (char *)((byte *)pcVar14 + 2);
          } while (bVar1 != 0);
          uVar9 = 0;
LAB_006a0335:
          if (uVar9 == 0) {
            if (piVar2 == (int *)0x0) {
              local_68 = 0.0;
            }
            else {
              iVar5 = Tcl_GetDoubleFromObj();
              puVar12 = local_14;
              if (iVar5 == 1) {
                local_68 = 0.0;
              }
              else {
                local_68 = (double)(float)local_88;
              }
            }
          }
          else {
            pcVar14 = "-interval";
            pbVar8 = pbVar16;
            do {
              bVar1 = *pbVar8;
              bVar21 = bVar1 < (byte)*pcVar14;
              if (bVar1 != *pcVar14) {
LAB_006a03c1:
                uVar9 = -(uint)bVar21 | 1;
                goto LAB_006a03c6;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar8[1];
              bVar21 = bVar1 < ((byte *)pcVar14)[1];
              if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_006a03c1;
              pbVar8 = pbVar8 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar1 != 0);
            uVar9 = 0;
LAB_006a03c6:
            if (uVar9 == 0) {
              if (piVar2 == (int *)0x0) {
                local_60 = 0.0;
              }
              else {
                iVar5 = Tcl_GetDoubleFromObj();
                puVar12 = local_14;
                if (iVar5 == 1) {
                  local_60 = 0.0;
                }
                else {
                  local_60 = (double)(float)local_90;
                }
              }
            }
            else {
              pcVar14 = "-repeat";
              pbVar8 = pbVar16;
              do {
                bVar1 = *pbVar8;
                bVar21 = bVar1 < (byte)*pcVar14;
                if (bVar1 != *pcVar14) {
LAB_006a0450:
                  uVar9 = -(uint)bVar21 | 1;
                  goto LAB_006a0455;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar8[1];
                bVar21 = bVar1 < ((byte *)pcVar14)[1];
                if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_006a0450;
                pbVar8 = pbVar8 + 2;
                pcVar14 = (char *)((byte *)pcVar14 + 2);
              } while (bVar1 != 0);
              uVar9 = 0;
LAB_006a0455:
              if (uVar9 == 0) {
                if (piVar2 == (int *)0x0) {
                  local_40 = 0;
                }
                else {
                  iVar5 = Tcl_GetIntFromObj();
                  local_40 = -(uint)(iVar5 != 1) & local_54;
                  puVar12 = local_14;
                }
              }
              else {
                pcVar14 = "-userid";
                pbVar8 = pbVar16;
                do {
                  bVar1 = *pbVar8;
                  bVar21 = bVar1 < (byte)*pcVar14;
                  if (bVar1 != *pcVar14) {
LAB_006a04b2:
                    uVar9 = -(uint)bVar21 | 1;
                    goto LAB_006a04b7;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar8[1];
                  bVar21 = bVar1 < ((byte *)pcVar14)[1];
                  if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_006a04b2;
                  pbVar8 = pbVar8 + 2;
                  pcVar14 = (char *)((byte *)pcVar14 + 2);
                } while (bVar1 != 0);
                uVar9 = 0;
LAB_006a04b7:
                if (uVar9 == 0) {
                  if (piVar2 == (int *)0x0) {
                    local_28 = (int *)0x0;
                  }
                  else {
                    iVar5 = Tcl_GetIntFromObj();
                    local_28 = (int *)(-(uint)(iVar5 != 1) & local_30);
                    puVar12 = local_14;
                  }
                }
                else {
                  pcVar14 = "-subject1";
                  pbVar8 = pbVar16;
                  do {
                    bVar1 = *pbVar8;
                    bVar21 = bVar1 < (byte)*pcVar14;
                    if (bVar1 != *pcVar14) {
LAB_006a0514:
                      uVar9 = -(uint)bVar21 | 1;
                      goto LAB_006a0519;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar8[1];
                    bVar21 = bVar1 < ((byte *)pcVar14)[1];
                    if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_006a0514;
                    pbVar8 = pbVar8 + 2;
                    pcVar14 = (char *)((byte *)pcVar14 + 2);
                  } while (bVar1 != 0);
                  uVar9 = 0;
LAB_006a0519:
                  if (uVar9 == 0) {
                    pvVar10 = (void *)FUN_006055d0();
                    if ((((pvVar10 == (void *)0x0) ||
                         (BVar11 = IsBadReadPtr(pvVar10,0x10), BVar11 != 0)) ||
                        (*(int *)((int)pvVar10 + 8) != 0x616e4f62)) ||
                       ((DAT_00768398 != '\0' && (*(int *)((int)pvVar10 + 0xdc) == 0)))) {
LAB_006a0b26:
                      local_8._0_1_ = 0x12;
                      if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0))
                      {
                        FUN_006ba940();
                      }
                      local_8 = CONCAT31(local_8._1_3_,0x13);
                      if ((local_3c != (int *)0x0) && (*local_3c = *local_3c + -1, *local_3c == 0))
                      {
                        FUN_006ba940();
                      }
                      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
                        TclFreeObj(piVar2);
                      }
                      if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 < 1)) {
                        TclFreeObj(local_44);
                      }
                      uVar19 = 1;
                      puVar12 = local_14;
                      goto LAB_006a0a7c;
                    }
                    local_14[4] = pvVar10;
                    puVar12 = local_14;
                  }
                  else {
                    pcVar14 = "-subject2";
                    pbVar8 = pbVar16;
                    do {
                      bVar1 = *pbVar8;
                      bVar21 = bVar1 < (byte)*pcVar14;
                      if (bVar1 != *pcVar14) {
LAB_006a05a2:
                        uVar9 = -(uint)bVar21 | 1;
                        goto LAB_006a05a7;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = pbVar8[1];
                      bVar21 = bVar1 < ((byte *)pcVar14)[1];
                      if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_006a05a2;
                      pbVar8 = pbVar8 + 2;
                      pcVar14 = (char *)((byte *)pcVar14 + 2);
                    } while (bVar1 != 0);
                    uVar9 = 0;
LAB_006a05a7:
                    if (uVar9 == 0) {
                      pvVar10 = (void *)FUN_006055d0();
                      if (((pvVar10 == (void *)0x0) ||
                          (BVar11 = IsBadReadPtr(pvVar10,0x10), BVar11 != 0)) ||
                         ((*(int *)((int)pvVar10 + 8) != 0x616e4f62 ||
                          ((DAT_00768398 != '\0' && (*(int *)((int)pvVar10 + 0xdc) == 0))))))
                      goto LAB_006a0b26;
                      local_14[5] = pvVar10;
                      puVar12 = local_14;
                    }
                    else {
                      pcVar14 = "-subject3";
                      pbVar8 = pbVar16;
                      do {
                        bVar1 = *pbVar8;
                        bVar21 = bVar1 < (byte)*pcVar14;
                        if (bVar1 != *pcVar14) {
LAB_006a0630:
                          uVar9 = -(uint)bVar21 | 1;
                          goto LAB_006a0635;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = pbVar8[1];
                        bVar21 = bVar1 < ((byte *)pcVar14)[1];
                        if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_006a0630;
                        pbVar8 = pbVar8 + 2;
                        pcVar14 = (char *)((byte *)pcVar14 + 2);
                      } while (bVar1 != 0);
                      uVar9 = 0;
LAB_006a0635:
                      if (uVar9 == 0) {
                        pvVar10 = (void *)FUN_006055d0();
                        if ((((pvVar10 == (void *)0x0) ||
                             (BVar11 = IsBadReadPtr(pvVar10,0x10), BVar11 != 0)) ||
                            (*(int *)((int)pvVar10 + 8) != 0x616e4f62)) ||
                           ((DAT_00768398 != '\0' && (*(int *)((int)pvVar10 + 0xdc) == 0))))
                        goto LAB_006a0b26;
                        local_14[6] = pvVar10;
                        puVar12 = local_14;
                      }
                      else {
                        pbVar15 = &DAT_0072faac;
                        pbVar8 = pbVar16;
                        do {
                          bVar1 = *pbVar8;
                          bVar21 = bVar1 < *pbVar15;
                          if (bVar1 != *pbVar15) {
LAB_006a06c0:
                            uVar9 = -(uint)bVar21 | 1;
                            goto LAB_006a06c5;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = pbVar8[1];
                          bVar21 = bVar1 < pbVar15[1];
                          if (bVar1 != pbVar15[1]) goto LAB_006a06c0;
                          pbVar8 = pbVar8 + 2;
                          pbVar15 = pbVar15 + 2;
                        } while (bVar1 != 0);
                        uVar9 = 0;
LAB_006a06c5:
                        if (uVar9 == 0) {
                          puVar12 = (undefined4 *)FUN_006bafe0(local_b4);
                          local_14[10] = *puVar12;
                          local_14[0xb] = puVar12[1];
                          local_14[0xc] = puVar12[2];
                          puVar12 = local_14;
                        }
                        else {
                          pbVar15 = &DAT_0072fab4;
                          pbVar8 = pbVar16;
                          do {
                            bVar1 = *pbVar8;
                            bVar21 = bVar1 < *pbVar15;
                            if (bVar1 != *pbVar15) {
LAB_006a0718:
                              uVar9 = -(uint)bVar21 | 1;
                              goto LAB_006a071d;
                            }
                            if (bVar1 == 0) break;
                            bVar1 = pbVar8[1];
                            bVar21 = bVar1 < pbVar15[1];
                            if (bVar1 != pbVar15[1]) goto LAB_006a0718;
                            pbVar8 = pbVar8 + 2;
                            pbVar15 = pbVar15 + 2;
                          } while (bVar1 != 0);
                          uVar9 = 0;
LAB_006a071d:
                          if (uVar9 == 0) {
                            puVar12 = (undefined4 *)FUN_006bafe0(local_c0);
                            local_14[0xd] = *puVar12;
                            local_14[0xe] = puVar12[1];
                            local_14[0xf] = puVar12[2];
                            puVar12 = local_14;
                          }
                          else {
                            pbVar15 = &DAT_0072fabc;
                            pbVar8 = pbVar16;
                            do {
                              bVar1 = *pbVar8;
                              bVar21 = bVar1 < *pbVar15;
                              if (bVar1 != *pbVar15) {
LAB_006a0770:
                                uVar9 = -(uint)bVar21 | 1;
                                goto LAB_006a0775;
                              }
                              if (bVar1 == 0) break;
                              bVar1 = pbVar8[1];
                              bVar21 = bVar1 < pbVar15[1];
                              if (bVar1 != pbVar15[1]) goto LAB_006a0770;
                              pbVar8 = pbVar8 + 2;
                              pbVar15 = pbVar15 + 2;
                            } while (bVar1 != 0);
                            uVar9 = 0;
LAB_006a0775:
                            if (uVar9 == 0) {
                              puVar12 = (undefined4 *)FUN_006bafe0(local_cc);
                              local_14[0x10] = *puVar12;
                              local_14[0x11] = puVar12[1];
                              local_14[0x12] = puVar12[2];
                              puVar12 = local_14;
                            }
                            else {
                              pbVar15 = &DAT_0072fac4;
                              pbVar8 = pbVar16;
                              do {
                                bVar1 = *pbVar8;
                                bVar21 = bVar1 < *pbVar15;
                                if (bVar1 != *pbVar15) {
LAB_006a07c8:
                                  uVar9 = -(uint)bVar21 | 1;
                                  goto LAB_006a07cd;
                                }
                                if (bVar1 == 0) break;
                                bVar1 = pbVar8[1];
                                bVar21 = bVar1 < pbVar15[1];
                                if (bVar1 != pbVar15[1]) goto LAB_006a07c8;
                                pbVar8 = pbVar8 + 2;
                                pbVar15 = pbVar15 + 2;
                              } while (bVar1 != 0);
                              uVar9 = 0;
LAB_006a07cd:
                              if (uVar9 == 0) {
                                if (piVar2 == (int *)0x0) {
                                  local_14[0x15] = 0;
                                }
                                else {
                                  iVar5 = Tcl_GetDoubleFromObj();
                                  puVar12 = local_14;
                                  if (iVar5 == 1) {
                                    local_14[0x15] = 0;
                                  }
                                  else {
                                    local_14[0x15] = (float)local_98;
                                  }
                                }
                              }
                              else {
                                pbVar15 = &DAT_0072facc;
                                pbVar8 = pbVar16;
                                do {
                                  bVar1 = *pbVar8;
                                  bVar21 = bVar1 < *pbVar15;
                                  if (bVar1 != *pbVar15) {
LAB_006a0850:
                                    uVar9 = -(uint)bVar21 | 1;
                                    goto LAB_006a0855;
                                  }
                                  if (bVar1 == 0) break;
                                  bVar1 = pbVar8[1];
                                  bVar21 = bVar1 < pbVar15[1];
                                  if (bVar1 != pbVar15[1]) goto LAB_006a0850;
                                  pbVar8 = pbVar8 + 2;
                                  pbVar15 = pbVar15 + 2;
                                } while (bVar1 != 0);
                                uVar9 = 0;
LAB_006a0855:
                                if (uVar9 == 0) {
                                  if (piVar2 == (int *)0x0) {
                                    local_14[0x16] = 0;
                                  }
                                  else {
                                    iVar5 = Tcl_GetDoubleFromObj();
                                    puVar12 = local_14;
                                    if (iVar5 == 1) {
                                      local_14[0x16] = 0;
                                    }
                                    else {
                                      local_14[0x16] = (float)local_a0;
                                    }
                                  }
                                }
                                else {
                                  pbVar15 = &DAT_0072fad4;
                                  pbVar8 = pbVar16;
                                  do {
                                    bVar1 = *pbVar8;
                                    bVar21 = bVar1 < *pbVar15;
                                    if (bVar1 != *pbVar15) {
LAB_006a08d5:
                                      uVar9 = -(uint)bVar21 | 1;
                                      goto LAB_006a08da;
                                    }
                                    if (bVar1 == 0) break;
                                    bVar1 = pbVar8[1];
                                    bVar21 = bVar1 < pbVar15[1];
                                    if (bVar1 != pbVar15[1]) goto LAB_006a08d5;
                                    pbVar8 = pbVar8 + 2;
                                    pbVar15 = pbVar15 + 2;
                                  } while (bVar1 != 0);
                                  uVar9 = 0;
LAB_006a08da:
                                  if (uVar9 == 0) {
                                    if (piVar2 == (int *)0x0) {
                                      local_14[0x17] = 0;
                                    }
                                    else {
                                      iVar5 = Tcl_GetDoubleFromObj();
                                      puVar12 = local_14;
                                      if (iVar5 == 1) {
                                        local_14[0x17] = 0;
                                      }
                                      else {
                                        local_14[0x17] = (float)local_a8;
                                      }
                                    }
                                  }
                                  else {
                                    pbVar15 = &DAT_0072fae4;
                                    pbVar8 = pbVar16;
                                    do {
                                      bVar1 = *pbVar8;
                                      bVar21 = bVar1 < *pbVar15;
                                      if (bVar1 != *pbVar15) {
LAB_006a0960:
                                        uVar9 = -(uint)bVar21 | 1;
                                        goto LAB_006a0965;
                                      }
                                      if (bVar1 == 0) break;
                                      bVar1 = pbVar8[1];
                                      bVar21 = bVar1 < pbVar15[1];
                                      if (bVar1 != pbVar15[1]) goto LAB_006a0960;
                                      pbVar8 = pbVar8 + 2;
                                      pbVar15 = pbVar15 + 2;
                                    } while (bVar1 != 0);
                                    uVar9 = 0;
LAB_006a0965:
                                    if (uVar9 == 0) {
                                      piVar3 = (int *)local_14[0x13];
                                      local_14[0x13] = local_24;
                                      if (local_24 != (int *)0x0) {
                                        *local_24 = *local_24 + 1;
                                      }
                                      if ((piVar3 != (int *)0x0) &&
                                         (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
                                        FUN_006ba940();
                                      }
                                      *(int *)(puVar12[0x13] + 8) = piVar6[2];
                                    }
                                    else {
                                      pbVar8 = &DAT_0072faec;
                                      do {
                                        bVar1 = *pbVar16;
                                        bVar21 = bVar1 < *pbVar8;
                                        if (bVar1 != *pbVar8) {
LAB_006a09b6:
                                          uVar9 = -(uint)bVar21 | 1;
                                          goto LAB_006a09bb;
                                        }
                                        if (bVar1 == 0) break;
                                        bVar1 = pbVar16[1];
                                        bVar21 = bVar1 < pbVar8[1];
                                        if (bVar1 != pbVar8[1]) goto LAB_006a09b6;
                                        pbVar16 = pbVar16 + 2;
                                        pbVar8 = pbVar8 + 2;
                                      } while (bVar1 != 0);
                                      uVar9 = 0;
LAB_006a09bb:
                                      if (uVar9 != 0) {
                                        local_8._0_1_ = uVar4;
                                        puVar12 = (undefined4 *)FUN_004295e0(local_38);
                                        piVar6 = (int *)*puVar12;
                                        if (piVar6 != (int *)0x0) {
                                          *piVar6 = *piVar6 + 1;
                                        }
                                        FUN_006bc6a0("unknown parameter",piVar6);
                                        goto LAB_006a0b26;
                                      }
                                      FUN_006b91c0(&local_24);
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          local_8._0_1_ = 0x14;
          if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
            FUN_006ba940();
          }
          local_8 = CONCAT31(local_8._1_3_,0x15);
          if ((local_3c != (int *)0x0) && (*local_3c = *local_3c + -1, *local_3c == 0)) {
            FUN_006ba940();
          }
          pcVar18 = TclFreeObj_exref;
          if ((piVar2 != (int *)0x0) &&
             (*piVar2 = *piVar2 + -1, pcVar18 = TclFreeObj_exref, *piVar2 < 1)) {
            TclFreeObj(piVar2);
          }
          local_8 = CONCAT31(local_8._1_3_,6);
          if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 < 1)) {
            (*pcVar18)(local_44);
          }
          uVar20 = local_38 + 2;
          uVar17 = local_38 + 3;
          uVar9 = local_40;
          local_38 = uVar20;
        } while ((int)uVar17 < param_3);
      }
      LOCK();
      puVar12[1] = puVar12[1] + 1;
      UNLOCK();
      iVar5 = local_48;
      piVar6 = local_28;
      dVar23 = local_60;
      puVar24 = puVar12;
      FUN_00605f00(local_48,local_28,local_60,uVar9,puVar12);
      FUN_00605f40(iVar5,piVar6,dVar23,uVar9,puVar24);
      uVar19 = 0;
LAB_006a0a7c:
      LOCK();
      iVar5 = puVar12[1] + -1;
      puVar12[1] = iVar5;
      UNLOCK();
      piVar6 = local_4c;
      if (iVar5 == 0) {
        (**(code **)*puVar12)(1);
        piVar6 = local_4c;
      }
    }
    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
      TclFreeObj(piVar6);
    }
  }
  local_8._0_1_ = 0x16;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x17);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar19;
}

