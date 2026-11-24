
undefined4
CTclGlobalMethods__EvtGenAttrib
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined **ppuVar12;
  byte *pbVar13;
  char *pcVar14;
  code *pcVar15;
  uint uVar16;
  bool bVar17;
  undefined8 uVar18;
  undefined1 local_a0 [12];
  undefined1 local_94 [12];
  undefined1 local_88 [28];
  double local_6c;
  double local_64;
  double local_5c;
  double local_54;
  int *local_4c;
  int *local_48;
  undefined4 local_44;
  undefined4 *local_40;
  byte *local_3c;
  int local_38;
  undefined **local_34;
  int *local_30;
  uint local_2c;
  int *local_28;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  int *local_18;
  undefined **local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d725;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7038) &&
     (FUN_006cebf4(&DAT_00ca7038,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar6 = DAT_00783650,
     DAT_00ca7038 == -1)) {
    iVar11 = DAT_00783650 * 0x40;
    DAT_00ca703c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar11) = "TCL:CTclGlobalMethods::EvtGenAttrib()";
    *(int *)(&DAT_00773650 + iVar11) = iVar6;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7038);
  }
  iVar11 = DAT_00ca703c;
  local_40 = &DAT_00ca703c;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca703c * 0x40);
  iVar6 = FUN_0043fcc0();
  *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar9;
  *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
  iVar6 = (&DAT_00773654)[iVar11 * 0x10];
  if (iVar6 == 0) {
    uVar18 = FUN_006bd180();
    iVar6 = (&DAT_00773654)[iVar11 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar11 * 0x10) = uVar18;
  }
  (&DAT_00773654)[iVar11 * 0x10] = iVar6 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004298b0(param_3,param_4);
  local_44 = 0;
  local_2c = 1;
  if (2 < param_3) {
    uVar8 = 2;
    do {
      uVar16 = local_2c;
      pcVar15 = RaiseException_exref;
      if (((int)local_2c < 0) || (local_1c <= (int)local_2c)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar10 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar10 = local_24;
        }
      }
      else {
        if (local_20 <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        pcVar15 = RaiseException_exref;
        puVar10 = local_24 + uVar16;
      }
      piVar3 = (int *)*puVar10;
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      local_48 = piVar3;
      if (((int)uVar8 < 0) || (local_1c <= (int)uVar8)) {
        (*pcVar15)(0xc000008c,1,0,0);
        puVar10 = local_24;
        if (local_20 == 0) {
          (*pcVar15)(0xc000008c,1,0,0);
          puVar10 = local_24;
        }
      }
      else {
        if (local_20 <= uVar8) {
          (*pcVar15)(0xc000008c,1,0,0);
        }
        puVar10 = local_24 + uVar8;
      }
      piVar4 = (int *)*puVar10;
      if (piVar4 != (int *)0x0) {
        *piVar4 = *piVar4 + 1;
      }
      local_8._0_1_ = 5;
      local_28 = piVar4;
      if (piVar3 == (int *)0x0) {
        local_14 = &PTR_0071ce50;
      }
      else {
        local_14 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
      }
      ppuVar12 = local_14;
      do {
        cVar1 = *(char *)ppuVar12;
        ppuVar12 = (undefined **)((int)ppuVar12 + 1);
      } while (cVar1 != '\0');
      local_18 = (int *)((int)ppuVar12 - (int)((int)local_14 + 1));
      iVar6 = (int)local_18 + 1;
      if (iVar6 < 4) {
        iVar6 = 4;
      }
      local_4c = (int *)FUN_006ba810(0x19);
      piVar5 = local_18;
      *(undefined1 *)(local_4c + 3) = 0;
      local_4c[1] = (iVar6 + 0xbU & 0xfffffff0) + 4;
      local_3c = (byte *)(local_4c + 3);
      local_4c[2] = -1;
      *local_4c = 0;
      local_30 = local_4c;
      FUN_006d2250(local_3c,local_14,(int)local_18 + 1);
      local_30[2] = (int)piVar5;
      *local_30 = *local_30 + 1;
      local_8._0_1_ = 6;
      if (piVar4 == (int *)0x0) {
        local_34 = &PTR_0071ce50;
      }
      else {
        local_34 = (undefined **)Tcl_GetStringFromObj(piVar4,0);
      }
      ppuVar12 = local_34;
      do {
        cVar1 = *(char *)ppuVar12;
        ppuVar12 = (undefined **)((int)ppuVar12 + 1);
      } while (cVar1 != '\0');
      local_38 = (int)ppuVar12 - (int)((int)local_34 + 1);
      iVar6 = local_38 + 1;
      if (iVar6 < 4) {
        iVar6 = 4;
      }
      local_18 = (int *)FUN_006ba810(0x19);
      iVar11 = local_38;
      *(undefined1 *)(local_18 + 3) = 0;
      local_18[1] = (iVar6 + 0xbU & 0xfffffff0) + 4;
      local_18[2] = -1;
      *local_18 = 0;
      local_14 = (undefined **)local_18;
      FUN_006d2250(local_18 + 3,local_34,local_38 + 1);
      local_14[2] = (undefined *)iVar11;
      *local_14 = (undefined *)((int)*local_14 + 1);
      iVar6 = DAT_00772400;
      pbVar13 = &DAT_0072fa80;
      local_8._0_1_ = 7;
      pbVar7 = local_3c;
      do {
        bVar2 = *pbVar7;
        bVar17 = bVar2 < *pbVar13;
        if (bVar2 != *pbVar13) {
LAB_0063ee47:
          uVar8 = -(uint)bVar17 | 1;
          goto LAB_0063ee4c;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar7[1];
        bVar17 = bVar2 < pbVar13[1];
        if (bVar2 != pbVar13[1]) goto LAB_0063ee47;
        pbVar7 = pbVar7 + 2;
        pbVar13 = pbVar13 + 2;
      } while (bVar2 != 0);
      uVar8 = 0;
LAB_0063ee4c:
      if (uVar8 == 0) {
        uVar9 = FUN_005ba5b0(&local_18);
        *(undefined4 *)(DAT_00772400 + 0xa134) = uVar9;
      }
      else {
        pcVar14 = "-object";
        pbVar7 = local_3c;
        do {
          bVar2 = *pbVar7;
          bVar17 = bVar2 < (byte)*pcVar14;
          if (bVar2 != *pcVar14) {
LAB_0063eea0:
            uVar8 = -(uint)bVar17 | 1;
            goto LAB_0063eea5;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar7[1];
          bVar17 = bVar2 < ((byte *)pcVar14)[1];
          if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_0063eea0;
          pbVar7 = pbVar7 + 2;
          pcVar14 = (char *)((byte *)pcVar14 + 2);
        } while (bVar2 != 0);
        uVar8 = 0;
LAB_0063eea5:
        if (uVar8 == 0) {
          piVar5 = *(int **)(DAT_00772400 + 0xa138);
          *(undefined ***)(DAT_00772400 + 0xa138) = local_14;
          *local_14 = (undefined *)((int)*local_14 + 1);
          if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
            FUN_006ba940();
          }
          *(undefined **)(*(int *)(iVar6 + 0xa138) + 8) = local_14[2];
        }
        else {
          pcVar14 = "-target";
          pbVar7 = local_3c;
          do {
            bVar2 = *pbVar7;
            bVar17 = bVar2 < (byte)*pcVar14;
            if (bVar2 != *pcVar14) {
LAB_0063ef10:
              uVar8 = -(uint)bVar17 | 1;
              goto LAB_0063ef15;
            }
            if (bVar2 == 0) break;
            bVar2 = pbVar7[1];
            bVar17 = bVar2 < ((byte *)pcVar14)[1];
            if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_0063ef10;
            pbVar7 = pbVar7 + 2;
            pcVar14 = (char *)((byte *)pcVar14 + 2);
          } while (bVar2 != 0);
          uVar8 = 0;
LAB_0063ef15:
          if (uVar8 == 0) {
            piVar5 = *(int **)(DAT_00772400 + 0xa13c);
            *(undefined ***)(DAT_00772400 + 0xa13c) = local_14;
            *local_14 = (undefined *)((int)*local_14 + 1);
            if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
              FUN_006ba940();
            }
            *(undefined **)(*(int *)(iVar6 + 0xa13c) + 8) = local_14[2];
          }
          else {
            pcVar14 = "-subject1";
            pbVar7 = local_3c;
            do {
              bVar2 = *pbVar7;
              bVar17 = bVar2 < (byte)*pcVar14;
              if (bVar2 != *pcVar14) {
LAB_0063ef80:
                uVar8 = -(uint)bVar17 | 1;
                goto LAB_0063ef85;
              }
              if (bVar2 == 0) break;
              bVar2 = pbVar7[1];
              bVar17 = bVar2 < ((byte *)pcVar14)[1];
              if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_0063ef80;
              pbVar7 = pbVar7 + 2;
              pcVar14 = (char *)((byte *)pcVar14 + 2);
            } while (bVar2 != 0);
            uVar8 = 0;
LAB_0063ef85:
            if (uVar8 == 0) {
              piVar5 = *(int **)(DAT_00772400 + 0xa140);
              *(undefined ***)(DAT_00772400 + 0xa140) = local_14;
              *local_14 = (undefined *)((int)*local_14 + 1);
              if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
                FUN_006ba940();
              }
              *(undefined **)(*(int *)(iVar6 + 0xa140) + 8) = local_14[2];
            }
            else {
              pcVar14 = "-subject2";
              pbVar7 = local_3c;
              do {
                bVar2 = *pbVar7;
                bVar17 = bVar2 < (byte)*pcVar14;
                if (bVar2 != *pcVar14) {
LAB_0063eff0:
                  uVar8 = -(uint)bVar17 | 1;
                  goto LAB_0063eff5;
                }
                if (bVar2 == 0) break;
                bVar2 = pbVar7[1];
                bVar17 = bVar2 < ((byte *)pcVar14)[1];
                if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_0063eff0;
                pbVar7 = pbVar7 + 2;
                pcVar14 = (char *)((byte *)pcVar14 + 2);
              } while (bVar2 != 0);
              uVar8 = 0;
LAB_0063eff5:
              if (uVar8 == 0) {
                piVar5 = *(int **)(DAT_00772400 + 0xa144);
                *(undefined ***)(DAT_00772400 + 0xa144) = local_14;
                *local_14 = (undefined *)((int)*local_14 + 1);
                if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
                  FUN_006ba940();
                }
                *(undefined **)(*(int *)(iVar6 + 0xa144) + 8) = local_14[2];
              }
              else {
                pcVar14 = "-subject3";
                pbVar7 = local_3c;
                do {
                  bVar2 = *pbVar7;
                  bVar17 = bVar2 < (byte)*pcVar14;
                  if (bVar2 != *pcVar14) {
LAB_0063f060:
                    uVar8 = -(uint)bVar17 | 1;
                    goto LAB_0063f065;
                  }
                  if (bVar2 == 0) break;
                  bVar2 = pbVar7[1];
                  bVar17 = bVar2 < ((byte *)pcVar14)[1];
                  if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_0063f060;
                  pbVar7 = pbVar7 + 2;
                  pcVar14 = (char *)((byte *)pcVar14 + 2);
                } while (bVar2 != 0);
                uVar8 = 0;
LAB_0063f065:
                if (uVar8 == 0) {
                  piVar5 = *(int **)(DAT_00772400 + 0xa148);
                  *(undefined ***)(DAT_00772400 + 0xa148) = local_14;
                  *local_14 = (undefined *)((int)*local_14 + 1);
                  if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
                    FUN_006ba940();
                  }
                  *(undefined **)(*(int *)(iVar6 + 0xa148) + 8) = local_14[2];
                }
                else {
                  pbVar13 = &DAT_0072faac;
                  pbVar7 = local_3c;
                  do {
                    bVar2 = *pbVar7;
                    bVar17 = bVar2 < *pbVar13;
                    if (bVar2 != *pbVar13) {
LAB_0063f0d0:
                      uVar8 = -(uint)bVar17 | 1;
                      goto LAB_0063f0d5;
                    }
                    if (bVar2 == 0) break;
                    bVar2 = pbVar7[1];
                    bVar17 = bVar2 < pbVar13[1];
                    if (bVar2 != pbVar13[1]) goto LAB_0063f0d0;
                    pbVar7 = pbVar7 + 2;
                    pbVar13 = pbVar13 + 2;
                  } while (bVar2 != 0);
                  uVar8 = 0;
LAB_0063f0d5:
                  if (uVar8 == 0) {
                    puVar10 = (undefined4 *)FUN_006bafe0(local_88);
                    *(undefined4 *)(iVar6 + 0xa160) = *puVar10;
                    *(undefined4 *)(iVar6 + 0xa164) = puVar10[1];
                    *(undefined4 *)(iVar6 + 0xa168) = puVar10[2];
                  }
                  else {
                    pbVar13 = &DAT_0072fab4;
                    pbVar7 = local_3c;
                    do {
                      bVar2 = *pbVar7;
                      bVar17 = bVar2 < *pbVar13;
                      if (bVar2 != *pbVar13) {
LAB_0063f134:
                        uVar8 = -(uint)bVar17 | 1;
                        goto LAB_0063f139;
                      }
                      if (bVar2 == 0) break;
                      bVar2 = pbVar7[1];
                      bVar17 = bVar2 < pbVar13[1];
                      if (bVar2 != pbVar13[1]) goto LAB_0063f134;
                      pbVar7 = pbVar7 + 2;
                      pbVar13 = pbVar13 + 2;
                    } while (bVar2 != 0);
                    uVar8 = 0;
LAB_0063f139:
                    if (uVar8 == 0) {
                      puVar10 = (undefined4 *)FUN_006bafe0(local_94);
                      *(undefined4 *)(iVar6 + 0xa16c) = *puVar10;
                      *(undefined4 *)(iVar6 + 0xa170) = puVar10[1];
                      *(undefined4 *)(iVar6 + 0xa174) = puVar10[2];
                    }
                    else {
                      pbVar13 = &DAT_0072fabc;
                      pbVar7 = local_3c;
                      do {
                        bVar2 = *pbVar7;
                        bVar17 = bVar2 < *pbVar13;
                        if (bVar2 != *pbVar13) {
LAB_0063f198:
                          uVar8 = -(uint)bVar17 | 1;
                          goto LAB_0063f19d;
                        }
                        if (bVar2 == 0) break;
                        bVar2 = pbVar7[1];
                        bVar17 = bVar2 < pbVar13[1];
                        if (bVar2 != pbVar13[1]) goto LAB_0063f198;
                        pbVar7 = pbVar7 + 2;
                        pbVar13 = pbVar13 + 2;
                      } while (bVar2 != 0);
                      uVar8 = 0;
LAB_0063f19d:
                      if (uVar8 == 0) {
                        puVar10 = (undefined4 *)FUN_006bafe0(local_a0);
                        *(undefined4 *)(iVar6 + 0xa178) = *puVar10;
                        *(undefined4 *)(iVar6 + 0xa17c) = puVar10[1];
                        *(undefined4 *)(iVar6 + 0xa180) = puVar10[2];
                      }
                      else {
                        pbVar13 = &DAT_0072fac4;
                        pbVar7 = local_3c;
                        do {
                          bVar2 = *pbVar7;
                          bVar17 = bVar2 < *pbVar13;
                          if (bVar2 != *pbVar13) {
LAB_0063f200:
                            uVar8 = -(uint)bVar17 | 1;
                            goto LAB_0063f205;
                          }
                          if (bVar2 == 0) break;
                          bVar2 = pbVar7[1];
                          bVar17 = bVar2 < pbVar13[1];
                          if (bVar2 != pbVar13[1]) goto LAB_0063f200;
                          pbVar7 = pbVar7 + 2;
                          pbVar13 = pbVar13 + 2;
                        } while (bVar2 != 0);
                        uVar8 = 0;
LAB_0063f205:
                        if (uVar8 == 0) {
                          if (piVar4 == (int *)0x0) {
                            *(undefined4 *)(DAT_00772400 + 0xa154) = 0;
                          }
                          else {
                            iVar6 = Tcl_GetDoubleFromObj(0,piVar4,&local_54);
                            if (iVar6 == 1) {
                              *(undefined4 *)(DAT_00772400 + 0xa154) = 0;
                            }
                            else {
                              *(float *)(DAT_00772400 + 0xa154) = (float)local_54;
                            }
                          }
                        }
                        else {
                          pbVar13 = &DAT_0072facc;
                          pbVar7 = local_3c;
                          do {
                            bVar2 = *pbVar7;
                            bVar17 = bVar2 < *pbVar13;
                            if (bVar2 != *pbVar13) {
LAB_0063f290:
                              uVar8 = -(uint)bVar17 | 1;
                              goto LAB_0063f295;
                            }
                            if (bVar2 == 0) break;
                            bVar2 = pbVar7[1];
                            bVar17 = bVar2 < pbVar13[1];
                            if (bVar2 != pbVar13[1]) goto LAB_0063f290;
                            pbVar7 = pbVar7 + 2;
                            pbVar13 = pbVar13 + 2;
                          } while (bVar2 != 0);
                          uVar8 = 0;
LAB_0063f295:
                          if (uVar8 == 0) {
                            if (piVar4 == (int *)0x0) {
                              *(undefined4 *)(DAT_00772400 + 0xa158) = 0;
                            }
                            else {
                              iVar6 = Tcl_GetDoubleFromObj(0,piVar4,&local_5c);
                              if (iVar6 == 1) {
                                *(undefined4 *)(DAT_00772400 + 0xa158) = 0;
                              }
                              else {
                                *(float *)(DAT_00772400 + 0xa158) = (float)local_5c;
                              }
                            }
                          }
                          else {
                            pbVar13 = &DAT_0072fad4;
                            pbVar7 = local_3c;
                            do {
                              bVar2 = *pbVar7;
                              bVar17 = bVar2 < *pbVar13;
                              if (bVar2 != *pbVar13) {
LAB_0063f320:
                                uVar8 = -(uint)bVar17 | 1;
                                goto LAB_0063f325;
                              }
                              if (bVar2 == 0) break;
                              bVar2 = pbVar7[1];
                              bVar17 = bVar2 < pbVar13[1];
                              if (bVar2 != pbVar13[1]) goto LAB_0063f320;
                              pbVar7 = pbVar7 + 2;
                              pbVar13 = pbVar13 + 2;
                            } while (bVar2 != 0);
                            uVar8 = 0;
LAB_0063f325:
                            if (uVar8 == 0) {
                              if (piVar4 == (int *)0x0) {
                                *(undefined4 *)(DAT_00772400 + 0xa15c) = 0;
                              }
                              else {
                                iVar6 = Tcl_GetDoubleFromObj(0,piVar4,&local_64);
                                if (iVar6 == 1) {
                                  *(undefined4 *)(DAT_00772400 + 0xa15c) = 0;
                                }
                                else {
                                  *(float *)(DAT_00772400 + 0xa15c) = (float)local_64;
                                }
                              }
                            }
                            else {
                              pcVar14 = "-delay";
                              pbVar7 = local_3c;
                              do {
                                bVar2 = *pbVar7;
                                bVar17 = bVar2 < (byte)*pcVar14;
                                if (bVar2 != *pcVar14) {
LAB_0063f3b0:
                                  uVar8 = -(uint)bVar17 | 1;
                                  goto LAB_0063f3b5;
                                }
                                if (bVar2 == 0) break;
                                bVar2 = pbVar7[1];
                                bVar17 = bVar2 < ((byte *)pcVar14)[1];
                                if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_0063f3b0;
                                pbVar7 = pbVar7 + 2;
                                pcVar14 = (char *)((byte *)pcVar14 + 2);
                              } while (bVar2 != 0);
                              uVar8 = 0;
LAB_0063f3b5:
                              if (uVar8 == 0) {
                                if (piVar4 == (int *)0x0) {
                                  *(undefined4 *)(DAT_00772400 + 0xa184) = 0;
                                }
                                else {
                                  iVar6 = Tcl_GetDoubleFromObj(0,piVar4,&local_6c);
                                  if (iVar6 == 1) {
                                    *(undefined4 *)(DAT_00772400 + 0xa184) = 0;
                                  }
                                  else {
                                    *(float *)(DAT_00772400 + 0xa184) = (float)local_6c;
                                  }
                                }
                              }
                              else {
                                pbVar13 = &DAT_0072fae4;
                                pbVar7 = local_3c;
                                do {
                                  bVar2 = *pbVar7;
                                  bVar17 = bVar2 < *pbVar13;
                                  if (bVar2 != *pbVar13) {
LAB_0063f440:
                                    uVar8 = -(uint)bVar17 | 1;
                                    goto LAB_0063f445;
                                  }
                                  if (bVar2 == 0) break;
                                  bVar2 = pbVar7[1];
                                  bVar17 = bVar2 < pbVar13[1];
                                  if (bVar2 != pbVar13[1]) goto LAB_0063f440;
                                  pbVar7 = pbVar7 + 2;
                                  pbVar13 = pbVar13 + 2;
                                } while (bVar2 != 0);
                                uVar8 = 0;
LAB_0063f445:
                                if (uVar8 == 0) {
                                  piVar5 = *(int **)(DAT_00772400 + 0xa14c);
                                  *(undefined ***)(DAT_00772400 + 0xa14c) = local_14;
                                  *local_14 = (undefined *)((int)*local_14 + 1);
                                  if ((piVar5 != (int *)0x0) &&
                                     (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
                                    FUN_006ba940();
                                  }
                                  *(undefined **)(*(int *)(iVar6 + 0xa14c) + 8) = local_14[2];
                                }
                                else {
                                  pbVar13 = &DAT_0072faec;
                                  pbVar7 = local_3c;
                                  do {
                                    bVar2 = *pbVar7;
                                    bVar17 = bVar2 < *pbVar13;
                                    if (bVar2 != *pbVar13) {
LAB_0063f4b0:
                                      uVar8 = -(uint)bVar17 | 1;
                                      goto LAB_0063f4b5;
                                    }
                                    if (bVar2 == 0) break;
                                    bVar2 = pbVar7[1];
                                    bVar17 = bVar2 < pbVar13[1];
                                    if (bVar2 != pbVar13[1]) goto LAB_0063f4b0;
                                    pbVar7 = pbVar7 + 2;
                                    pbVar13 = pbVar13 + 2;
                                  } while (bVar2 != 0);
                                  uVar8 = 0;
LAB_0063f4b5:
                                  if (uVar8 == 0) {
                                    piVar5 = *(int **)(DAT_00772400 + 0xa150);
                                    *(undefined ***)(DAT_00772400 + 0xa150) = local_14;
                                    *local_14 = (undefined *)((int)*local_14 + 1);
                                    if ((piVar5 != (int *)0x0) &&
                                       (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
                                      FUN_006ba940();
                                    }
                                    *(undefined **)(*(int *)(iVar6 + 0xa150) + 8) = local_14[2];
                                  }
                                  else {
                                    pbVar13 = &DAT_0072faf4;
                                    pbVar7 = local_3c;
                                    do {
                                      bVar2 = *pbVar7;
                                      bVar17 = bVar2 < *pbVar13;
                                      if (bVar2 != *pbVar13) {
LAB_0063f520:
                                        uVar8 = -(uint)bVar17 | 1;
                                        goto LAB_0063f525;
                                      }
                                      if (bVar2 == 0) break;
                                      bVar2 = pbVar7[1];
                                      bVar17 = bVar2 < pbVar13[1];
                                      if (bVar2 != pbVar13[1]) goto LAB_0063f520;
                                      pbVar7 = pbVar7 + 2;
                                      pbVar13 = pbVar13 + 2;
                                    } while (bVar2 != 0);
                                    uVar8 = 0;
LAB_0063f525:
                                    if (uVar8 == 0) {
                                      piVar5 = *(int **)(DAT_00772400 + 0xa18c);
                                      *(undefined ***)(DAT_00772400 + 0xa18c) = local_14;
                                      *local_14 = (undefined *)((int)*local_14 + 1);
                                      if ((piVar5 != (int *)0x0) &&
                                         (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
                                        FUN_006ba940();
                                      }
                                      *(undefined **)(*(int *)(iVar6 + 0xa18c) + 8) = local_14[2];
                                    }
                                    else {
                                      pcVar14 = "-cursor";
                                      pbVar7 = local_3c;
                                      do {
                                        bVar2 = *pbVar7;
                                        bVar17 = bVar2 < (byte)*pcVar14;
                                        if (bVar2 != *pcVar14) {
LAB_0063f584:
                                          uVar8 = -(uint)bVar17 | 1;
                                          goto LAB_0063f589;
                                        }
                                        if (bVar2 == 0) break;
                                        bVar2 = pbVar7[1];
                                        bVar17 = bVar2 < ((byte *)pcVar14)[1];
                                        if (bVar2 != ((byte *)pcVar14)[1]) goto LAB_0063f584;
                                        pbVar7 = pbVar7 + 2;
                                        pcVar14 = (char *)((byte *)pcVar14 + 2);
                                      } while (bVar2 != 0);
                                      uVar8 = 0;
LAB_0063f589:
                                      if (uVar8 != 0) {
                                        puVar10 = (undefined4 *)FUN_004295e0(local_2c);
                                        piVar5 = (int *)*puVar10;
                                        if (piVar5 != (int *)0x0) {
                                          *piVar5 = *piVar5 + 1;
                                        }
                                        FUN_006bc6a0("unknown parameter",piVar5);
                                        local_8._0_1_ = 8;
                                        *local_14 = (undefined *)((int)*local_14 + -1);
                                        if (*local_14 == (undefined *)0x0) {
                                          FUN_006ba940();
                                        }
                                        local_8 = CONCAT31(local_8._1_3_,9);
                                        *local_30 = *local_30 + -1;
                                        if (*local_30 == 0) {
                                          FUN_006ba940();
                                        }
                                        pcVar15 = TclFreeObj_exref;
                                        if ((piVar4 != (int *)0x0) &&
                                           (*piVar4 = *piVar4 + -1, pcVar15 = TclFreeObj_exref,
                                           *piVar4 < 1)) {
                                          TclFreeObj(piVar4);
                                        }
                                        if ((piVar3 != (int *)0x0) &&
                                           (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
                                          (*pcVar15)(piVar3);
                                        }
                                        uVar9 = 1;
                                        goto LAB_0063f60b;
                                      }
                                      FUN_006b91c0(&local_18);
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
        }
      }
      local_8._0_1_ = 10;
      *local_14 = (undefined *)((int)*local_14 + -1);
      if (*local_14 == (undefined *)0x0) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,0xb);
      *local_30 = *local_30 + -1;
      if (*local_30 == 0) {
        FUN_006ba940();
      }
      if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
        TclFreeObj(piVar4);
      }
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
        TclFreeObj(piVar3);
      }
      uVar16 = local_2c + 2;
      uVar8 = local_2c + 3;
      local_2c = uVar16;
    } while ((int)uVar8 < param_3);
  }
  uVar9 = 0;
LAB_0063f60b:
  local_8._0_1_ = 0xc;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

