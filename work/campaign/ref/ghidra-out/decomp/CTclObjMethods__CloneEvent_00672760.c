
undefined4
CTclObjMethods__CloneEvent(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  int *piVar6;
  undefined **ppuVar7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  void *pvVar11;
  BOOL BVar12;
  undefined4 *puVar13;
  char *pcVar14;
  byte *pbVar15;
  undefined3 uVar16;
  byte *pbVar17;
  code *pcVar18;
  uint uVar19;
  undefined4 uVar20;
  uint uVar21;
  bool bVar22;
  undefined8 uVar23;
  undefined4 *puVar24;
  undefined1 local_b4 [12];
  undefined1 local_a8 [12];
  undefined1 local_9c [12];
  double local_90;
  double local_88;
  double local_80;
  double local_78;
  int *local_70;
  undefined4 *local_6c;
  int local_68;
  double local_58;
  int *local_50;
  undefined4 *local_4c;
  int *local_48;
  uint local_44;
  uint local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  uint local_30;
  int *local_2c;
  int local_28;
  int *local_24;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007107d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7488) &&
     (FUN_006cebf4(&DAT_00ca7488,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca7488 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca748c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclObjMethods::CloneEvent()";
    *(int *)(&DAT_00773650 + iVar8) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7488);
  }
  iVar8 = DAT_00ca748c;
  local_6c = &DAT_00ca748c;
  uVar20 = *(undefined4 *)(&DAT_00773650 + DAT_00ca748c * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar20;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar5 == 0) {
    uVar23 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar23;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar5 = FUN_005c71c0(param_4,3,1);
  if (iVar5 == 0) {
    uVar20 = 1;
  }
  else {
    piVar6 = (int *)FUN_006ba810(0x19);
    piVar9 = piVar6 + 3;
    piVar6[2] = -1;
    *piVar6 = 0;
    *(undefined1 *)piVar9 = 0;
    piVar6[1] = 0x14;
    *piVar9 = 0x73696874;
    *(undefined1 *)(piVar6 + 4) = 0;
    piVar6[2] = 4;
    *piVar6 = 1;
    if (local_68 == 0) {
      local_28 = local_68;
      iVar8 = 1;
    }
    else {
      local_28 = Tcl_GetAssocData(local_68,piVar9,0);
      iVar8 = *piVar6;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    *piVar6 = iVar8 + -1;
    if (iVar8 + -1 == 0) {
      FUN_006ba940();
    }
    if (local_18 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar13 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar13 = local_20;
      }
    }
    else {
      if (local_1c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar13 = local_20 + 2;
    }
    piVar9 = (int *)*puVar13;
    if (piVar9 != (int *)0x0) {
      *piVar9 = *piVar9 + 1;
    }
    local_8._0_1_ = 4;
    local_70 = piVar9;
    local_48 = piVar9;
    if (piVar9 == (int *)0x0) {
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar9,0);
    }
    FUN_006b8fb0(ppuVar7);
    iVar8 = FUN_005ba5b0(&local_2c);
    local_8._0_1_ = 5;
    if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (iVar8 == -1) {
      if (local_18 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar13 = local_20;
        if (local_1c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar13 = local_20;
        }
      }
      else {
        if (local_1c < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar13 = local_20 + 2;
      }
      piVar6 = (int *)*puVar13;
      if (piVar6 != (int *)0x0) {
        *piVar6 = *piVar6 + 1;
      }
      FUN_006bc6a0("unregistered event",piVar6);
      uVar20 = 1;
      pcVar18 = TclFreeObj_exref;
    }
    else {
      local_4c = (undefined4 *)0x0;
      local_34 = 0;
      local_30 = 0;
      local_8 = CONCAT31(local_8._1_3_,7);
      local_58 = 0.0;
      local_40 = 3;
      piVar9 = (int *)FUN_005ba0d0(&local_38);
      puVar13 = (undefined4 *)*piVar9;
      if (puVar13 != (undefined4 *)0x0) {
        LOCK();
        puVar13[1] = puVar13[1] + 1;
        UNLOCK();
      }
      local_4c = puVar13;
      local_14 = puVar13;
      if (local_38 != (int *)0x0) {
        LOCK();
        iVar3 = local_38[1] + -1;
        local_38[1] = iVar3;
        UNLOCK();
        if ((iVar3 == 0) && (local_38 != (int *)0x0)) {
          (**(code **)*local_38)(1);
        }
      }
      puVar13[2] = iVar8;
      puVar13[3] = iVar5;
      if (4 < param_3) {
        uVar19 = 4;
        uVar21 = 3;
        do {
          if (((int)uVar21 < 0) || (local_18 <= (int)uVar21)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar13 = local_20;
            if (local_1c == 0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar13 = local_20;
            }
          }
          else {
            if (local_1c <= uVar21) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar13 = local_20 + uVar21;
          }
          piVar9 = (int *)*puVar13;
          if (piVar9 != (int *)0x0) {
            *piVar9 = *piVar9 + 1;
          }
          local_50 = piVar9;
          local_38 = piVar9;
          if (((int)uVar19 < 0) || (local_18 <= (int)uVar19)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar13 = local_20;
            if (local_1c == 0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar13 = local_20;
            }
          }
          else {
            if (local_1c <= uVar19) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar13 = local_20 + uVar19;
          }
          piVar6 = (int *)*puVar13;
          if (piVar6 != (int *)0x0) {
            *piVar6 = *piVar6 + 1;
          }
          local_8._0_1_ = 9;
          local_3c = piVar6;
          if (piVar9 == (int *)0x0) {
            ppuVar7 = &PTR_0071ce50;
          }
          else {
            ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar9,0);
          }
          FUN_006b8fb0(ppuVar7);
          local_8._0_1_ = 10;
          if (piVar6 == (int *)0x0) {
            ppuVar7 = &PTR_0071ce50;
          }
          else {
            ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar6,0);
          }
          FUN_006b8fb0(ppuVar7);
          piVar9 = local_24;
          local_8._0_1_ = 0xb;
          uVar4 = (undefined1)local_8;
          local_8._0_1_ = 0xb;
          pcVar14 = "target";
          pbVar17 = (byte *)(local_2c + 3);
          pbVar10 = pbVar17;
          do {
            bVar1 = *pbVar10;
            bVar22 = bVar1 < (byte)*pcVar14;
            if (bVar1 != *pcVar14) {
LAB_00672b90:
              uVar19 = -(uint)bVar22 | 1;
              goto LAB_00672b95;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar10[1];
            bVar22 = bVar1 < ((byte *)pcVar14)[1];
            if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_00672b90;
            pbVar10 = pbVar10 + 2;
            pcVar14 = (char *)((byte *)pcVar14 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_00672b95:
          if (uVar19 == 0) {
            pvVar11 = (void *)FUN_006055d0(param_2,local_28,&local_24);
            if ((((pvVar11 == (void *)0x0) || (BVar12 = IsBadReadPtr(pvVar11,0x10), BVar12 != 0)) ||
                (*(int *)((int)pvVar11 + 8) != 0x616e4f62)) ||
               ((DAT_00768398 != '\0' && (*(int *)((int)pvVar11 + 0xdc) == 0)))) {
LAB_00673340:
              local_8._0_1_ = 0x12;
              if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
                FUN_006ba940();
              }
              local_8 = CONCAT31(local_8._1_3_,0x13);
              if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
                FUN_006ba940();
              }
              pcVar18 = TclFreeObj_exref;
              if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
                TclFreeObj(piVar6);
              }
              if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 < 1)) {
                TclFreeObj(local_38);
              }
              uVar20 = 1;
              puVar13 = local_14;
              goto LAB_00673284;
            }
            local_44 = FUN_0042f510();
            if (local_30 <= local_44) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(void **)(local_34 + local_44 * 4) = pvVar11;
          }
          else {
            pcVar14 = "-subject1";
            pbVar10 = pbVar17;
            do {
              bVar1 = *pbVar10;
              bVar22 = bVar1 < (byte)*pcVar14;
              if (bVar1 != *pcVar14) {
LAB_00672c47:
                uVar19 = -(uint)bVar22 | 1;
                goto LAB_00672c4c;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar10[1];
              bVar22 = bVar1 < ((byte *)pcVar14)[1];
              if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_00672c47;
              pbVar10 = pbVar10 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar1 != 0);
            uVar19 = 0;
LAB_00672c4c:
            if (uVar19 == 0) {
              pvVar11 = (void *)FUN_006055d0(param_2,local_28,&local_24);
              if (((pvVar11 == (void *)0x0) || (BVar12 = IsBadReadPtr(pvVar11,0x10), BVar12 != 0))
                 || ((*(int *)((int)pvVar11 + 8) != 0x616e4f62 ||
                     ((DAT_00768398 != '\0' && (*(int *)((int)pvVar11 + 0xdc) == 0))))))
              goto LAB_00673340;
              local_14[4] = pvVar11;
            }
            else {
              pcVar14 = "-subject2";
              pbVar10 = pbVar17;
              do {
                bVar1 = *pbVar10;
                bVar22 = bVar1 < (byte)*pcVar14;
                if (bVar1 != *pcVar14) {
LAB_00672cd3:
                  uVar19 = -(uint)bVar22 | 1;
                  goto LAB_00672cd8;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar10[1];
                bVar22 = bVar1 < ((byte *)pcVar14)[1];
                if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_00672cd3;
                pbVar10 = pbVar10 + 2;
                pcVar14 = (char *)((byte *)pcVar14 + 2);
              } while (bVar1 != 0);
              uVar19 = 0;
LAB_00672cd8:
              if (uVar19 == 0) {
                pvVar11 = (void *)FUN_006055d0(param_2,local_28,&local_24);
                if ((((pvVar11 == (void *)0x0) || (BVar12 = IsBadReadPtr(pvVar11,0x10), BVar12 != 0)
                     ) || (*(int *)((int)pvVar11 + 8) != 0x616e4f62)) ||
                   ((DAT_00768398 != '\0' && (*(int *)((int)pvVar11 + 0xdc) == 0))))
                goto LAB_00673340;
                local_14[5] = pvVar11;
              }
              else {
                pcVar14 = "-subject3";
                pbVar10 = pbVar17;
                do {
                  bVar1 = *pbVar10;
                  bVar22 = bVar1 < (byte)*pcVar14;
                  if (bVar1 != *pcVar14) {
LAB_00672d60:
                    uVar19 = -(uint)bVar22 | 1;
                    goto LAB_00672d65;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar10[1];
                  bVar22 = bVar1 < ((byte *)pcVar14)[1];
                  if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_00672d60;
                  pbVar10 = pbVar10 + 2;
                  pcVar14 = (char *)((byte *)pcVar14 + 2);
                } while (bVar1 != 0);
                uVar19 = 0;
LAB_00672d65:
                if (uVar19 == 0) {
                  pvVar11 = (void *)FUN_006055d0(param_2,local_28,&local_24);
                  if (((pvVar11 == (void *)0x0) ||
                      (BVar12 = IsBadReadPtr(pvVar11,0x10), BVar12 != 0)) ||
                     ((*(int *)((int)pvVar11 + 8) != 0x616e4f62 ||
                      ((DAT_00768398 != '\0' && (*(int *)((int)pvVar11 + 0xdc) == 0))))))
                  goto LAB_00673340;
                  local_14[6] = pvVar11;
                }
                else {
                  pbVar15 = &DAT_0072faac;
                  pbVar10 = pbVar17;
                  do {
                    bVar1 = *pbVar10;
                    bVar22 = bVar1 < *pbVar15;
                    if (bVar1 != *pbVar15) {
LAB_00672df0:
                      uVar19 = -(uint)bVar22 | 1;
                      goto LAB_00672df5;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar10[1];
                    bVar22 = bVar1 < pbVar15[1];
                    if (bVar1 != pbVar15[1]) goto LAB_00672df0;
                    pbVar10 = pbVar10 + 2;
                    pbVar15 = pbVar15 + 2;
                  } while (bVar1 != 0);
                  uVar19 = 0;
LAB_00672df5:
                  if (uVar19 == 0) {
                    puVar13 = (undefined4 *)FUN_006bafe0(local_9c);
                    local_14[10] = *puVar13;
                    local_14[0xb] = puVar13[1];
                    local_14[0xc] = puVar13[2];
                  }
                  else {
                    pbVar15 = &DAT_0072fab4;
                    pbVar10 = pbVar17;
                    do {
                      bVar1 = *pbVar10;
                      bVar22 = bVar1 < *pbVar15;
                      if (bVar1 != *pbVar15) {
LAB_00672e50:
                        uVar19 = -(uint)bVar22 | 1;
                        goto LAB_00672e55;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = pbVar10[1];
                      bVar22 = bVar1 < pbVar15[1];
                      if (bVar1 != pbVar15[1]) goto LAB_00672e50;
                      pbVar10 = pbVar10 + 2;
                      pbVar15 = pbVar15 + 2;
                    } while (bVar1 != 0);
                    uVar19 = 0;
LAB_00672e55:
                    if (uVar19 == 0) {
                      puVar13 = (undefined4 *)FUN_006bafe0(local_a8);
                      local_14[0xd] = *puVar13;
                      local_14[0xe] = puVar13[1];
                      local_14[0xf] = puVar13[2];
                    }
                    else {
                      pbVar15 = &DAT_0072fabc;
                      pbVar10 = pbVar17;
                      do {
                        bVar1 = *pbVar10;
                        bVar22 = bVar1 < *pbVar15;
                        if (bVar1 != *pbVar15) {
LAB_00672eb0:
                          uVar19 = -(uint)bVar22 | 1;
                          goto LAB_00672eb5;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = pbVar10[1];
                        bVar22 = bVar1 < pbVar15[1];
                        if (bVar1 != pbVar15[1]) goto LAB_00672eb0;
                        pbVar10 = pbVar10 + 2;
                        pbVar15 = pbVar15 + 2;
                      } while (bVar1 != 0);
                      uVar19 = 0;
LAB_00672eb5:
                      if (uVar19 == 0) {
                        puVar13 = (undefined4 *)FUN_006bafe0(local_b4);
                        local_14[0x10] = *puVar13;
                        local_14[0x11] = puVar13[1];
                        local_14[0x12] = puVar13[2];
                      }
                      else {
                        pbVar15 = &DAT_0072fac4;
                        pbVar10 = pbVar17;
                        do {
                          bVar1 = *pbVar10;
                          bVar22 = bVar1 < *pbVar15;
                          if (bVar1 != *pbVar15) {
LAB_00672f10:
                            uVar19 = -(uint)bVar22 | 1;
                            goto LAB_00672f15;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = pbVar10[1];
                          bVar22 = bVar1 < pbVar15[1];
                          if (bVar1 != pbVar15[1]) goto LAB_00672f10;
                          pbVar10 = pbVar10 + 2;
                          pbVar15 = pbVar15 + 2;
                        } while (bVar1 != 0);
                        uVar19 = 0;
LAB_00672f15:
                        if (uVar19 == 0) {
                          if (piVar6 == (int *)0x0) {
                            local_14[0x15] = 0;
                          }
                          else {
                            iVar5 = Tcl_GetDoubleFromObj(0,piVar6,&local_78);
                            if (iVar5 == 1) {
                              local_14[0x15] = 0;
                            }
                            else {
                              local_14[0x15] = (float)local_78;
                            }
                          }
                        }
                        else {
                          pbVar15 = &DAT_0072facc;
                          pbVar10 = pbVar17;
                          do {
                            bVar1 = *pbVar10;
                            bVar22 = bVar1 < *pbVar15;
                            if (bVar1 != *pbVar15) {
LAB_00672f90:
                              uVar19 = -(uint)bVar22 | 1;
                              goto LAB_00672f95;
                            }
                            if (bVar1 == 0) break;
                            bVar1 = pbVar10[1];
                            bVar22 = bVar1 < pbVar15[1];
                            if (bVar1 != pbVar15[1]) goto LAB_00672f90;
                            pbVar10 = pbVar10 + 2;
                            pbVar15 = pbVar15 + 2;
                          } while (bVar1 != 0);
                          uVar19 = 0;
LAB_00672f95:
                          if (uVar19 == 0) {
                            if (piVar6 == (int *)0x0) {
                              local_14[0x16] = 0;
                            }
                            else {
                              iVar5 = Tcl_GetDoubleFromObj(0,piVar6,&local_80);
                              if (iVar5 == 1) {
                                local_14[0x16] = 0;
                              }
                              else {
                                local_14[0x16] = (float)local_80;
                              }
                            }
                          }
                          else {
                            pbVar15 = &DAT_0072fad4;
                            pbVar10 = pbVar17;
                            do {
                              bVar1 = *pbVar10;
                              bVar22 = bVar1 < *pbVar15;
                              if (bVar1 != *pbVar15) {
LAB_00673010:
                                uVar19 = -(uint)bVar22 | 1;
                                goto LAB_00673015;
                              }
                              if (bVar1 == 0) break;
                              bVar1 = pbVar10[1];
                              bVar22 = bVar1 < pbVar15[1];
                              if (bVar1 != pbVar15[1]) goto LAB_00673010;
                              pbVar10 = pbVar10 + 2;
                              pbVar15 = pbVar15 + 2;
                            } while (bVar1 != 0);
                            uVar19 = 0;
LAB_00673015:
                            if (uVar19 == 0) {
                              if (piVar6 == (int *)0x0) {
                                local_14[0x17] = 0;
                              }
                              else {
                                iVar5 = Tcl_GetDoubleFromObj(0,piVar6,&local_88);
                                if (iVar5 == 1) {
                                  local_14[0x17] = 0;
                                }
                                else {
                                  local_14[0x17] = (float)local_88;
                                }
                              }
                            }
                            else {
                              pcVar14 = "-delay";
                              pbVar10 = pbVar17;
                              do {
                                bVar1 = *pbVar10;
                                bVar22 = bVar1 < (byte)*pcVar14;
                                if (bVar1 != *pcVar14) {
LAB_00673095:
                                  uVar19 = -(uint)bVar22 | 1;
                                  goto LAB_0067309a;
                                }
                                if (bVar1 == 0) break;
                                bVar1 = pbVar10[1];
                                bVar22 = bVar1 < ((byte *)pcVar14)[1];
                                if (bVar1 != ((byte *)pcVar14)[1]) goto LAB_00673095;
                                pbVar10 = pbVar10 + 2;
                                pcVar14 = (char *)((byte *)pcVar14 + 2);
                              } while (bVar1 != 0);
                              uVar19 = 0;
LAB_0067309a:
                              if (uVar19 == 0) {
                                if (piVar6 == (int *)0x0) {
                                  local_58 = 0.0;
                                }
                                else {
                                  iVar5 = Tcl_GetDoubleFromObj(0,piVar6,&local_90);
                                  if (iVar5 == 1) {
                                    local_58 = 0.0;
                                  }
                                  else {
                                    local_58 = (double)(float)local_90;
                                  }
                                }
                              }
                              else {
                                pbVar15 = &DAT_0072fae4;
                                pbVar10 = pbVar17;
                                do {
                                  bVar1 = *pbVar10;
                                  bVar22 = bVar1 < *pbVar15;
                                  if (bVar1 != *pbVar15) {
LAB_00673120:
                                    uVar19 = -(uint)bVar22 | 1;
                                    goto LAB_00673125;
                                  }
                                  if (bVar1 == 0) break;
                                  bVar1 = pbVar10[1];
                                  bVar22 = bVar1 < pbVar15[1];
                                  if (bVar1 != pbVar15[1]) goto LAB_00673120;
                                  pbVar10 = pbVar10 + 2;
                                  pbVar15 = pbVar15 + 2;
                                } while (bVar1 != 0);
                                uVar19 = 0;
LAB_00673125:
                                if (uVar19 == 0) {
                                  piVar2 = (int *)local_14[0x13];
                                  local_14[0x13] = local_24;
                                  if (local_24 != (int *)0x0) {
                                    *local_24 = *local_24 + 1;
                                  }
                                  if ((piVar2 != (int *)0x0) &&
                                     (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
                                    FUN_006ba940();
                                  }
                                  *(int *)(local_14[0x13] + 8) = piVar9[2];
                                }
                                else {
                                  pbVar10 = &DAT_0072faec;
                                  do {
                                    bVar1 = *pbVar17;
                                    uVar16 = (undefined3)((uint)pbVar15 >> 8);
                                    pbVar15 = (byte *)CONCAT31(uVar16,bVar1);
                                    bVar22 = bVar1 < *pbVar10;
                                    if (bVar1 != *pbVar10) {
LAB_00673180:
                                      uVar19 = -(uint)bVar22 | 1;
                                      goto LAB_00673185;
                                    }
                                    if (bVar1 == 0) break;
                                    bVar1 = pbVar17[1];
                                    pbVar15 = (byte *)CONCAT31(uVar16,bVar1);
                                    bVar22 = bVar1 < pbVar10[1];
                                    if (bVar1 != pbVar10[1]) goto LAB_00673180;
                                    pbVar17 = pbVar17 + 2;
                                    pbVar10 = pbVar10 + 2;
                                  } while (bVar1 != 0);
                                  uVar19 = 0;
LAB_00673185:
                                  if (uVar19 != 0) {
                                    local_8._0_1_ = uVar4;
                                    uVar20 = FUN_004295e0(local_40);
                                    FUN_006b8f90(uVar20);
                                    FUN_006bc6a0("unknown parameter",pbVar15);
                                    goto LAB_00673340;
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
          local_8._0_1_ = 0x15;
          if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
            FUN_006ba940();
          }
          local_8 = CONCAT31(local_8._1_3_,0x16);
          if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
            FUN_006ba940();
          }
          if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
            TclFreeObj(piVar6);
          }
          local_8 = CONCAT31(local_8._1_3_,7);
          if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 < 1)) {
            TclFreeObj(local_38);
          }
          uVar21 = local_40 + 2;
          uVar19 = local_40 + 3;
          puVar13 = local_14;
          local_40 = uVar21;
        } while ((int)uVar19 < param_3);
      }
      *(double *)(puVar13 + 8) = *(double *)(puVar13 + 8) + local_58;
      if (local_30 == 0) {
        uVar20 = FUN_0042f510();
        piVar9 = (int *)FUN_0040b900(uVar20);
        *piVar9 = local_28;
      }
      uVar19 = 0;
      if (0 < (int)local_30) {
        do {
          LOCK();
          puVar13[1] = puVar13[1] + 1;
          UNLOCK();
          puVar24 = puVar13;
          if (local_30 <= uVar19) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          FUN_005ba940(puVar24);
          uVar19 = uVar19 + 1;
        } while ((int)uVar19 < (int)local_30);
      }
      uVar20 = 0;
      pcVar18 = TclFreeObj_exref;
LAB_00673284:
      local_8 = CONCAT31(local_8._1_3_,0x17);
      FUN_0042fbb0(0);
      if (local_34 != 0) {
        FUN_006ba940();
      }
      LOCK();
      iVar5 = puVar13[1] + -1;
      puVar13[1] = iVar5;
      UNLOCK();
      piVar9 = local_48;
      if (iVar5 == 0) {
        (**(code **)*puVar13)(1);
        piVar9 = local_48;
      }
    }
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
      (*pcVar18)(piVar9);
    }
  }
  local_8._0_1_ = 0x18;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x19);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar20;
}

