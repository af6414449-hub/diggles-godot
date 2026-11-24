
undefined4
CTclObjMethods__SetEvent(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  byte *pbVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  undefined **ppuVar6;
  byte *pbVar7;
  void *pvVar8;
  BOOL BVar9;
  byte *pbVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  char *pcVar14;
  undefined3 uVar15;
  byte *pbVar16;
  uint uVar17;
  code *pcVar18;
  undefined4 uVar19;
  uint uVar20;
  bool bVar21;
  undefined8 uVar22;
  undefined4 *puVar23;
  undefined1 local_b8 [12];
  undefined1 local_ac [12];
  undefined1 local_a0 [12];
  double local_94;
  double local_8c;
  double local_84;
  double local_7c;
  int *local_74;
  undefined4 *local_70;
  double local_6c;
  int *local_64;
  undefined4 *local_60;
  int local_5c;
  int *local_4c;
  int local_48;
  int *local_44;
  uint local_40;
  byte *local_3c;
  int *local_38;
  int local_34;
  int local_30;
  uint local_2c;
  int *local_28;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007115f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca77d0) &&
     (FUN_006cebf4(&DAT_00ca77d0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca77d0 == -1)) {
    iVar13 = DAT_00783650 * 0x40;
    DAT_00ca77d4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar13) = "TCL:CTclObjMethods::SetEvent()";
    *(int *)(&DAT_00773650 + iVar13) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca77d0);
  }
  iVar13 = DAT_00ca77d4;
  local_70 = &DAT_00ca77d4;
  uVar19 = *(undefined4 *)(&DAT_00773650 + DAT_00ca77d4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar19;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar13 * 0x10];
  if (iVar4 == 0) {
    uVar22 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar13 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar13 * 0x10) = uVar22;
  }
  (&DAT_00773654)[iVar13 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_48 = FUN_005c71c0(param_4,3,1);
  if (local_48 == 0) {
    uVar19 = 1;
  }
  else {
    piVar5 = (int *)FUN_006ba810(0x19);
    piVar12 = piVar5 + 3;
    piVar5[2] = -1;
    *piVar5 = 0;
    *(undefined1 *)piVar12 = 0;
    piVar5[1] = 0x14;
    *piVar12 = 0x73696874;
    *(undefined1 *)(piVar5 + 4) = 0;
    piVar5[2] = 4;
    *piVar5 = 1;
    if (local_5c == 0) {
      local_34 = local_5c;
      iVar4 = 1;
    }
    else {
      local_34 = Tcl_GetAssocData(local_5c,piVar12,0);
      iVar4 = *piVar5;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar5 = iVar4 + -1;
    if (iVar4 + -1 == 0) {
      FUN_006ba940();
    }
    if (local_1c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar11 = local_24;
      }
    }
    else {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_24 + 2;
    }
    piVar12 = (int *)*puVar11;
    if (piVar12 != (int *)0x0) {
      *piVar12 = *piVar12 + 1;
    }
    local_8._0_1_ = 4;
    local_74 = piVar12;
    local_4c = piVar12;
    if (piVar12 == (int *)0x0) {
      ppuVar6 = &PTR_0071ce50;
    }
    else {
      ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
    }
    FUN_006b8fb0(ppuVar6);
    iVar4 = FUN_005ba5b0(&local_38);
    local_8._0_1_ = 5;
    if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (iVar4 == -1) {
      if (local_1c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar11 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar11 = local_24;
        }
      }
      else {
        if (local_20 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar11 = local_24 + 2;
      }
      piVar5 = (int *)*puVar11;
      if (piVar5 != (int *)0x0) {
        *piVar5 = *piVar5 + 1;
      }
      FUN_006bc6a0("unregistered event",piVar5);
      uVar19 = 1;
    }
    else {
      local_60 = (undefined4 *)0x0;
      local_30 = 0;
      local_2c = 0;
      local_8._0_1_ = 7;
      local_6c = 0.0;
      local_40 = 3;
      local_18 = FUN_006ba810(0x635);
      local_8._0_1_ = 8;
      if (local_18 == 0) {
        local_14 = (undefined4 *)0x0;
      }
      else {
        local_14 = (undefined4 *)FUN_005b9d30();
      }
      local_8 = CONCAT31(local_8._1_3_,7);
      if (local_14 != (undefined4 *)0x0) {
        LOCK();
        local_14[1] = local_14[1] + 1;
        UNLOCK();
      }
      local_14[0x15] = 0;
      local_14[0x16] = 0;
      local_14[0x17] = 0;
      local_14[2] = iVar4;
      local_14[3] = local_48;
      puVar11 = local_14;
      local_60 = local_14;
      if (4 < param_3) {
        uVar17 = 4;
        uVar20 = 3;
        do {
          if (((int)uVar20 < 0) || (local_1c <= (int)uVar20)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar11 = local_24;
            if (local_20 == 0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar11 = local_24;
            }
          }
          else {
            if (local_20 <= uVar20) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar11 = local_24 + uVar20;
          }
          piVar12 = (int *)*puVar11;
          if (piVar12 != (int *)0x0) {
            *piVar12 = *piVar12 + 1;
          }
          local_64 = piVar12;
          local_44 = piVar12;
          if (((int)uVar17 < 0) || (local_1c <= (int)uVar17)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar11 = local_24;
            if (local_20 == 0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar11 = local_24;
            }
          }
          else {
            if (local_20 <= uVar17) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar11 = local_24 + uVar17;
          }
          pbVar2 = (byte *)*puVar11;
          if (pbVar2 != (byte *)0x0) {
            *(int *)pbVar2 = *(int *)pbVar2 + 1;
          }
          local_8._0_1_ = 10;
          local_3c = pbVar2;
          if (piVar12 == (int *)0x0) {
            ppuVar6 = &PTR_0071ce50;
          }
          else {
            ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
          }
          FUN_006b8fb0(ppuVar6);
          local_8._0_1_ = 0xb;
          if (pbVar2 == (byte *)0x0) {
            ppuVar6 = &PTR_0071ce50;
          }
          else {
            ppuVar6 = (undefined **)Tcl_GetStringFromObj(pbVar2,0);
          }
          FUN_006b8fb0(ppuVar6);
          puVar11 = local_14;
          piVar12 = local_28;
          local_8._0_1_ = 0xc;
          uVar3 = (undefined1)local_8;
          local_8._0_1_ = 0xc;
          pcVar14 = "-target";
          pbVar16 = (byte *)(local_38 + 3);
          pbVar7 = pbVar16;
          do {
            bVar1 = *pbVar7;
            bVar21 = bVar1 < (byte)*pcVar14;
            if (bVar1 != *pcVar14) {
LAB_00687900:
              uVar17 = -(uint)bVar21 | 1;
              goto LAB_00687905;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar7[1];
            bVar21 = bVar1 < ((byte *)pcVar14)[1];
            if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_00687900;
            pbVar7 = pbVar7 + 2;
            pcVar14 = (char *)((byte *)pcVar14 + 2);
          } while (bVar1 != 0);
          uVar17 = 0;
LAB_00687905:
          pbVar7 = pbVar2;
          if (uVar17 == 0) {
            pvVar8 = (void *)FUN_006055d0(param_2,local_34,&local_28);
            if ((((pvVar8 == (void *)0x0) || (BVar9 = IsBadReadPtr(pvVar8,0x10), BVar9 != 0)) ||
                (*(int *)((int)pvVar8 + 8) != 0x616e4f62)) ||
               ((DAT_00768398 != '\0' && (*(int *)((int)pvVar8 + 0xdc) == 0)))) {
              if (pbVar2 != (byte *)0x0) {
                *(int *)pbVar2 = *(int *)pbVar2 + 1;
              }
              pcVar14 = "target invalid";
LAB_00688080:
              FUN_006bc6a0(pcVar14,pbVar7);
              local_8._0_1_ = 0x13;
              if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
                FUN_006ba940();
              }
              local_8 = CONCAT31(local_8._1_3_,0x14);
              if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
                FUN_006ba940();
              }
              if ((pbVar2 != (byte *)0x0) &&
                 (*(int *)pbVar2 = *(int *)pbVar2 + -1, *(int *)pbVar2 < 1)) {
                TclFreeObj(pbVar2);
              }
              if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 < 1)) {
                TclFreeObj(local_44);
              }
              uVar19 = 1;
              puVar11 = local_14;
              goto LAB_00688122;
            }
            local_18 = FUN_0042f510();
            if (local_2c <= local_18) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(void **)(local_30 + local_18 * 4) = pvVar8;
            puVar11 = local_14;
          }
          else {
            pcVar14 = "-subject1";
            pbVar10 = pbVar16;
            do {
              bVar1 = *pbVar10;
              bVar21 = bVar1 < (byte)*pcVar14;
              if (bVar1 != *pcVar14) {
LAB_006879c0:
                uVar17 = -(uint)bVar21 | 1;
                goto LAB_006879c5;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar10[1];
              bVar21 = bVar1 < ((byte *)pcVar14)[1];
              if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_006879c0;
              pbVar10 = pbVar10 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar1 != 0);
            uVar17 = 0;
LAB_006879c5:
            if (uVar17 == 0) {
              pvVar8 = (void *)FUN_006055d0(param_2,local_34,&local_28);
              if (((pvVar8 == (void *)0x0) || (BVar9 = IsBadReadPtr(pvVar8,0x10), BVar9 != 0)) ||
                 ((*(int *)((int)pvVar8 + 8) != 0x616e4f62 ||
                  ((DAT_00768398 != '\0' && (*(int *)((int)pvVar8 + 0xdc) == 0)))))) {
                if (pbVar2 != (byte *)0x0) {
                  *(int *)pbVar2 = *(int *)pbVar2 + 1;
                }
                pcVar14 = "subject1 invalid";
                goto LAB_00688080;
              }
              local_14[4] = pvVar8;
              puVar11 = local_14;
            }
            else {
              pcVar14 = "-subject2";
              pbVar10 = pbVar16;
              do {
                bVar1 = *pbVar10;
                bVar21 = bVar1 < (byte)*pcVar14;
                if (bVar1 != *pcVar14) {
LAB_00687a50:
                  uVar17 = -(uint)bVar21 | 1;
                  goto LAB_00687a55;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar10[1];
                bVar21 = bVar1 < ((byte *)pcVar14)[1];
                if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_00687a50;
                pbVar10 = pbVar10 + 2;
                pcVar14 = (char *)((byte *)pcVar14 + 2);
              } while (bVar1 != 0);
              uVar17 = 0;
LAB_00687a55:
              if (uVar17 == 0) {
                pvVar8 = (void *)FUN_006055d0(param_2,local_34,&local_28);
                if ((((pvVar8 == (void *)0x0) || (BVar9 = IsBadReadPtr(pvVar8,0x10), BVar9 != 0)) ||
                    (*(int *)((int)pvVar8 + 8) != 0x616e4f62)) ||
                   ((DAT_00768398 != '\0' && (*(int *)((int)pvVar8 + 0xdc) == 0)))) {
                  if (pbVar2 != (byte *)0x0) {
                    *(int *)pbVar2 = *(int *)pbVar2 + 1;
                  }
                  pcVar14 = "subject2 invalid";
                  goto LAB_00688080;
                }
                local_14[5] = pvVar8;
                puVar11 = local_14;
              }
              else {
                pcVar14 = "-subject3";
                pbVar10 = pbVar16;
                do {
                  bVar1 = *pbVar10;
                  bVar21 = bVar1 < (byte)*pcVar14;
                  if (bVar1 != *pcVar14) {
LAB_00687ae0:
                    uVar17 = -(uint)bVar21 | 1;
                    goto LAB_00687ae5;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar10[1];
                  bVar21 = bVar1 < ((byte *)pcVar14)[1];
                  if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_00687ae0;
                  pbVar10 = pbVar10 + 2;
                  pcVar14 = (char *)((byte *)pcVar14 + 2);
                } while (bVar1 != 0);
                uVar17 = 0;
LAB_00687ae5:
                if (uVar17 == 0) {
                  pvVar8 = (void *)FUN_006055d0(param_2,local_34,&local_28);
                  if (((pvVar8 == (void *)0x0) || (BVar9 = IsBadReadPtr(pvVar8,0x10), BVar9 != 0))
                     || ((*(int *)((int)pvVar8 + 8) != 0x616e4f62 ||
                         ((DAT_00768398 != '\0' && (*(int *)((int)pvVar8 + 0xdc) == 0)))))) {
                    if (pbVar2 != (byte *)0x0) {
                      *(int *)pbVar2 = *(int *)pbVar2 + 1;
                    }
                    pcVar14 = "subject3 invalid";
                    goto LAB_00688080;
                  }
                  local_14[6] = pvVar8;
                  puVar11 = local_14;
                }
                else {
                  pbVar10 = &DAT_0072faac;
                  pbVar7 = pbVar16;
                  do {
                    bVar1 = *pbVar7;
                    bVar21 = bVar1 < *pbVar10;
                    if (bVar1 != *pbVar10) {
LAB_00687b70:
                      uVar17 = -(uint)bVar21 | 1;
                      goto LAB_00687b75;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar7[1];
                    bVar21 = bVar1 < pbVar10[1];
                    if (bVar1 != pbVar10[1]) goto LAB_00687b70;
                    pbVar7 = pbVar7 + 2;
                    pbVar10 = pbVar10 + 2;
                  } while (bVar1 != 0);
                  uVar17 = 0;
LAB_00687b75:
                  if (uVar17 == 0) {
                    puVar11 = (undefined4 *)FUN_006bafe0(local_a0);
                    local_14[10] = *puVar11;
                    local_14[0xb] = puVar11[1];
                    local_14[0xc] = puVar11[2];
                    puVar11 = local_14;
                  }
                  else {
                    pbVar10 = &DAT_0072fab4;
                    pbVar7 = pbVar16;
                    do {
                      bVar1 = *pbVar7;
                      bVar21 = bVar1 < *pbVar10;
                      if (bVar1 != *pbVar10) {
LAB_00687bc8:
                        uVar17 = -(uint)bVar21 | 1;
                        goto LAB_00687bcd;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = pbVar7[1];
                      bVar21 = bVar1 < pbVar10[1];
                      if (bVar1 != pbVar10[1]) goto LAB_00687bc8;
                      pbVar7 = pbVar7 + 2;
                      pbVar10 = pbVar10 + 2;
                    } while (bVar1 != 0);
                    uVar17 = 0;
LAB_00687bcd:
                    if (uVar17 == 0) {
                      puVar11 = (undefined4 *)FUN_006bafe0(local_ac);
                      local_14[0xd] = *puVar11;
                      local_14[0xe] = puVar11[1];
                      local_14[0xf] = puVar11[2];
                      puVar11 = local_14;
                    }
                    else {
                      pbVar10 = &DAT_0072fabc;
                      pbVar7 = pbVar16;
                      do {
                        bVar1 = *pbVar7;
                        bVar21 = bVar1 < *pbVar10;
                        if (bVar1 != *pbVar10) {
LAB_00687c20:
                          uVar17 = -(uint)bVar21 | 1;
                          goto LAB_00687c25;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = pbVar7[1];
                        bVar21 = bVar1 < pbVar10[1];
                        if (bVar1 != pbVar10[1]) goto LAB_00687c20;
                        pbVar7 = pbVar7 + 2;
                        pbVar10 = pbVar10 + 2;
                      } while (bVar1 != 0);
                      uVar17 = 0;
LAB_00687c25:
                      if (uVar17 == 0) {
                        puVar11 = (undefined4 *)FUN_006bafe0(local_b8);
                        local_14[0x10] = *puVar11;
                        local_14[0x11] = puVar11[1];
                        local_14[0x12] = puVar11[2];
                        puVar11 = local_14;
                      }
                      else {
                        pbVar10 = &DAT_0072fac4;
                        pbVar7 = pbVar16;
                        do {
                          bVar1 = *pbVar7;
                          bVar21 = bVar1 < *pbVar10;
                          if (bVar1 != *pbVar10) {
LAB_00687c78:
                            uVar17 = -(uint)bVar21 | 1;
                            goto LAB_00687c7d;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = pbVar7[1];
                          bVar21 = bVar1 < pbVar10[1];
                          if (bVar1 != pbVar10[1]) goto LAB_00687c78;
                          pbVar7 = pbVar7 + 2;
                          pbVar10 = pbVar10 + 2;
                        } while (bVar1 != 0);
                        uVar17 = 0;
LAB_00687c7d:
                        if (uVar17 == 0) {
                          if (pbVar2 == (byte *)0x0) {
                            local_14[0x15] = 0;
                          }
                          else {
                            iVar4 = Tcl_GetDoubleFromObj(0,pbVar2,&local_7c);
                            puVar11 = local_14;
                            if (iVar4 == 1) {
                              local_14[0x15] = 0;
                            }
                            else {
                              local_14[0x15] = (float)local_7c;
                            }
                          }
                        }
                        else {
                          pbVar10 = &DAT_0072facc;
                          pbVar7 = pbVar16;
                          do {
                            bVar1 = *pbVar7;
                            bVar21 = bVar1 < *pbVar10;
                            if (bVar1 != *pbVar10) {
LAB_00687cf7:
                              uVar17 = -(uint)bVar21 | 1;
                              goto LAB_00687cfc;
                            }
                            if (bVar1 == 0) break;
                            bVar1 = pbVar7[1];
                            bVar21 = bVar1 < pbVar10[1];
                            if (bVar1 != pbVar10[1]) goto LAB_00687cf7;
                            pbVar7 = pbVar7 + 2;
                            pbVar10 = pbVar10 + 2;
                          } while (bVar1 != 0);
                          uVar17 = 0;
LAB_00687cfc:
                          if (uVar17 == 0) {
                            if (pbVar2 == (byte *)0x0) {
                              local_14[0x16] = 0;
                            }
                            else {
                              iVar4 = Tcl_GetDoubleFromObj(0,pbVar2,&local_84);
                              puVar11 = local_14;
                              if (iVar4 == 1) {
                                local_14[0x16] = 0;
                              }
                              else {
                                local_14[0x16] = (float)local_84;
                              }
                            }
                          }
                          else {
                            pbVar10 = &DAT_0072fad4;
                            pbVar7 = pbVar16;
                            do {
                              bVar1 = *pbVar7;
                              bVar21 = bVar1 < *pbVar10;
                              if (bVar1 != *pbVar10) {
LAB_00687d76:
                                uVar17 = -(uint)bVar21 | 1;
                                goto LAB_00687d7b;
                              }
                              if (bVar1 == 0) break;
                              bVar1 = pbVar7[1];
                              bVar21 = bVar1 < pbVar10[1];
                              if (bVar1 != pbVar10[1]) goto LAB_00687d76;
                              pbVar7 = pbVar7 + 2;
                              pbVar10 = pbVar10 + 2;
                            } while (bVar1 != 0);
                            uVar17 = 0;
LAB_00687d7b:
                            if (uVar17 == 0) {
                              if (pbVar2 == (byte *)0x0) {
                                local_14[0x17] = 0;
                              }
                              else {
                                iVar4 = Tcl_GetDoubleFromObj(0,pbVar2,&local_8c);
                                puVar11 = local_14;
                                if (iVar4 == 1) {
                                  local_14[0x17] = 0;
                                }
                                else {
                                  local_14[0x17] = (float)local_8c;
                                }
                              }
                            }
                            else {
                              pcVar14 = "-delay";
                              pbVar7 = pbVar16;
                              do {
                                bVar1 = *pbVar7;
                                bVar21 = bVar1 < (byte)*pcVar14;
                                if (bVar1 != *pcVar14) {
LAB_00687e00:
                                  uVar17 = -(uint)bVar21 | 1;
                                  goto LAB_00687e05;
                                }
                                if (bVar1 == 0) break;
                                bVar1 = pbVar7[1];
                                bVar21 = bVar1 < ((byte *)pcVar14)[1];
                                if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_00687e00;
                                pbVar7 = pbVar7 + 2;
                                pcVar14 = (char *)((byte *)pcVar14 + 2);
                              } while (bVar1 != 0);
                              uVar17 = 0;
LAB_00687e05:
                              if (uVar17 == 0) {
                                if (pbVar2 == (byte *)0x0) {
                                  local_6c = 0.0;
                                }
                                else {
                                  iVar4 = Tcl_GetDoubleFromObj(0,pbVar2,&local_94);
                                  puVar11 = local_14;
                                  if (iVar4 == 1) {
                                    local_6c = 0.0;
                                  }
                                  else {
                                    local_6c = (double)(float)local_94;
                                  }
                                }
                              }
                              else {
                                pbVar7 = &DAT_0072fae4;
                                pbVar10 = pbVar16;
                                do {
                                  bVar1 = *pbVar10;
                                  bVar21 = bVar1 < *pbVar7;
                                  if (bVar1 != *pbVar7) {
LAB_00687e90:
                                    uVar17 = -(uint)bVar21 | 1;
                                    goto LAB_00687e95;
                                  }
                                  if (bVar1 == 0) break;
                                  bVar1 = pbVar10[1];
                                  bVar21 = bVar1 < pbVar7[1];
                                  if (bVar1 != pbVar7[1]) goto LAB_00687e90;
                                  pbVar10 = pbVar10 + 2;
                                  pbVar7 = pbVar7 + 2;
                                } while (bVar1 != 0);
                                uVar17 = 0;
LAB_00687e95:
                                if (uVar17 == 0) {
                                  piVar5 = (int *)local_14[0x13];
                                  local_14[0x13] = local_28;
                                  if (local_28 != (int *)0x0) {
                                    *local_28 = *local_28 + 1;
                                  }
                                  if ((piVar5 != (int *)0x0) &&
                                     (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
                                    FUN_006ba940();
                                  }
                                  *(int *)(puVar11[0x13] + 8) = piVar12[2];
                                }
                                else {
                                  pbVar10 = &DAT_0072faec;
                                  do {
                                    bVar1 = *pbVar16;
                                    uVar15 = (undefined3)((uint)pbVar7 >> 8);
                                    pbVar7 = (byte *)CONCAT31(uVar15,bVar1);
                                    bVar21 = bVar1 < *pbVar10;
                                    if (bVar1 != *pbVar10) {
LAB_00687ee6:
                                      uVar17 = -(uint)bVar21 | 1;
                                      goto LAB_00687eeb;
                                    }
                                    if (bVar1 == 0) break;
                                    bVar1 = pbVar16[1];
                                    pbVar7 = (byte *)CONCAT31(uVar15,bVar1);
                                    bVar21 = bVar1 < pbVar10[1];
                                    if (bVar1 != pbVar10[1]) goto LAB_00687ee6;
                                    pbVar16 = pbVar16 + 2;
                                    pbVar10 = pbVar10 + 2;
                                  } while (bVar1 != 0);
                                  uVar17 = 0;
LAB_00687eeb:
                                  if (uVar17 != 0) {
                                    local_8._0_1_ = uVar3;
                                    uVar19 = FUN_004295e0(local_40);
                                    FUN_006b8f90(uVar19);
                                    pcVar14 = "unknown parameter";
                                    goto LAB_00688080;
                                  }
                                  FUN_006b91c0(&local_28);
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
          local_8._0_1_ = 0x16;
          if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 == 0)) {
            FUN_006ba940();
          }
          local_8 = CONCAT31(local_8._1_3_,0x17);
          if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
            FUN_006ba940();
          }
          pcVar18 = TclFreeObj_exref;
          if ((pbVar2 != (byte *)0x0) &&
             (*(int *)pbVar2 = *(int *)pbVar2 + -1, pcVar18 = TclFreeObj_exref, *(int *)pbVar2 < 1))
          {
            TclFreeObj(pbVar2);
          }
          local_8 = CONCAT31(local_8._1_3_,7);
          if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 < 1)) {
            (*pcVar18)(local_44);
          }
          uVar20 = local_40 + 2;
          uVar17 = local_40 + 3;
          local_40 = uVar20;
        } while ((int)uVar17 < param_3);
      }
      *(double *)(puVar11 + 8) = *(double *)(puVar11 + 8) + local_6c;
      if (local_2c == 0) {
        uVar19 = FUN_0042f510();
        piVar12 = (int *)FUN_0040b900(uVar19);
        *piVar12 = local_34;
      }
      uVar17 = 0;
      if (0 < (int)local_2c) {
        do {
          if (local_2c <= uVar17) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          if (*(int *)(*(int *)(local_30 + uVar17 * 4) + 0x378) == *(int *)(DAT_00772400 + 100)) {
            LOCK();
            puVar11[1] = puVar11[1] + 1;
            UNLOCK();
            puVar23 = puVar11;
            if (local_2c <= uVar17) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            FUN_005ba940(puVar23);
          }
          else {
            if (local_2c <= uVar17) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            FUN_006abed0();
            FUN_006ac120(*(undefined4 *)(local_48 + 0xdc),
                         *(undefined4 *)(*(int *)(local_30 + uVar17 * 4) + 0xdc),puVar11);
          }
          uVar17 = uVar17 + 1;
        } while ((int)uVar17 < (int)local_2c);
      }
      uVar19 = 0;
LAB_00688122:
      local_8 = CONCAT31(local_8._1_3_,0x18);
      FUN_0042fbb0(0);
      if (local_30 != 0) {
        FUN_006ba940();
      }
      LOCK();
      iVar4 = puVar11[1] + -1;
      puVar11[1] = iVar4;
      UNLOCK();
      piVar12 = local_4c;
      if (iVar4 == 0) {
        (**(code **)*puVar11)(1);
        piVar12 = local_4c;
      }
    }
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
  }
  local_8._0_1_ = 0x19;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x1a);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar19;
}

