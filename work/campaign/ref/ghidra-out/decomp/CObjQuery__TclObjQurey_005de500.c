
undefined4
CObjQuery__TclObjQurey(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined **ppuVar7;
  byte *pbVar8;
  uint uVar9;
  int iVar10;
  undefined **ppuVar11;
  int *piVar12;
  float *pfVar13;
  undefined4 *puVar14;
  undefined4 extraout_ECX;
  char *pcVar15;
  byte *pbVar16;
  byte *pbVar17;
  undefined1 uVar18;
  uint uVar19;
  code *pcVar20;
  bool bVar21;
  float fVar22;
  double dVar23;
  undefined8 uVar24;
  undefined4 local_2b0;
  int local_270;
  undefined1 local_244 [12];
  undefined1 local_238 [12];
  int *local_22c;
  int local_228;
  undefined4 *local_218;
  double local_214;
  double local_20c;
  double local_204;
  double local_1fc;
  double local_1f4;
  double local_1ec;
  double local_1e4;
  int *local_1dc;
  int *local_1d8;
  int local_1d4;
  byte *local_1d0;
  int local_1cc;
  int *local_1c8;
  int *local_1c4;
  uint local_1c0;
  int *local_1bc;
  int *local_1b8;
  uint local_1b4;
  int *local_1b0;
  int *local_1ac;
  int *local_1a8;
  int *local_1a4;
  int *local_1a0;
  int *local_19c;
  int *local_198;
  int *local_194;
  int local_190;
  int *local_18c;
  int *local_188;
  int local_184;
  int *local_180;
  int *local_17c;
  undefined **local_178;
  int *local_174;
  int *local_170;
  int *local_16c;
  int *local_168;
  int *local_164;
  int *local_160;
  uint local_15c;
  undefined **local_158;
  int *local_154;
  int *local_150;
  int *local_14c;
  uint local_148;
  int *local_144;
  int *local_140;
  int *local_13c;
  int *local_138;
  int *local_134;
  undefined **local_130;
  int *local_12c;
  int *local_128;
  int *local_124;
  int *local_120;
  undefined **local_11c;
  int *local_118;
  int *local_114;
  int *local_110;
  uint local_10c;
  int *local_108;
  int *local_104;
  int *local_100;
  int *local_fc;
  int *local_f8;
  int *local_f4;
  undefined **local_f0;
  int local_ec;
  int *local_e8;
  int *local_e4;
  int *local_e0;
  int *local_dc;
  int *local_d8;
  int local_d4;
  float local_cc;
  undefined4 local_c8;
  int local_c4;
  uint local_c0;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  undefined1 local_a8;
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  uint local_98;
  int local_88;
  uint local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  int *local_5c;
  undefined4 *local_58;
  uint local_54;
  int local_50;
  undefined4 local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  undefined **local_18;
  byte *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00709188;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca66c0) &&
     (FUN_006cebf4(&DAT_00ca66c0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca66c0 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca66c4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CObjQuery::TclObjQurey()";
    *(int *)(&DAT_00773650 + iVar10) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca66c0);
  }
  iVar10 = DAT_00ca66c4;
  local_218 = &DAT_00ca66c4;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca66c4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar6;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar4 == 0) {
    uVar24 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar24;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar6 = param_4;
  local_8._0_1_ = 1;
  FUN_005e3100(&param_3,param_4,3);
  local_8._0_1_ = 2;
  piVar5 = (int *)FUN_005c71c0(uVar6,3,1);
  local_48 = piVar5;
  if (piVar5 == (int *)0x0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_004297b0(0);
    if (local_58 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  if (local_50 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar14 = local_58;
    if (local_54 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar14 = local_58;
    }
  }
  else {
    if (local_54 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar14 = local_58 + 2;
  }
  local_22c = (int *)*puVar14;
  if (local_22c != (int *)0x0) {
    *local_22c = *local_22c + 1;
  }
  local_5c = local_22c;
  FUN_005ddd60();
  local_8._0_1_ = 6;
  uVar6 = FUN_005de0c0(piVar5,extraout_ECX);
  FUN_005dde30(uVar6);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_0040b980(0);
  if (local_270 != 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 10;
  FUN_006ba940();
  local_8._0_1_ = 8;
  thunk_FUN_0060fc30(local_2b0);
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 0x14;
  local_2c[2] = -1;
  *(undefined1 *)(local_2c + 3) = 0;
  *local_2c = 1;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  local_68 = (float)piVar5[3];
  dVar23 = (double)(ulonglong)(uint)local_68;
  local_64 = (float)piVar5[4];
  local_60 = (float)piVar5[5];
  local_4c = 1;
  local_44 = (int *)0x0;
  pbVar8 = (byte *)0x0;
  uVar19 = local_98;
  local_38 = local_68;
  local_34 = local_60;
  local_30 = local_64;
  local_20 = local_2c;
LAB_005de774:
  local_98 = uVar19;
  piVar5 = local_5c;
  local_14 = pbVar8;
  if (local_5c == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar10 = Tcl_ListObjLength(0,local_5c,&local_1d4);
    iVar4 = local_1d4;
    if (iVar10 != 0) {
      iVar4 = 0;
    }
  }
  local_1d0 = pbVar8 + 2;
  if (iVar4 < (int)local_1d0) goto LAB_005e0bd3;
  if ((piVar5 == (int *)0x0) ||
     (iVar4 = Tcl_ListObjIndex(0,piVar5,pbVar8,&local_1d8), piVar12 = local_1d8, iVar4 != 0)) {
    piVar12 = (int *)0x0;
LAB_005de7ea:
    ppuVar7 = &PTR_0071ce50;
  }
  else {
    if (local_1d8 == (int *)0x0) goto LAB_005de7ea;
    *local_1d8 = *local_1d8 + 1;
    ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_1d8,0);
  }
  pcVar15 = "-type";
  do {
    bVar1 = *(byte *)ppuVar7;
    bVar21 = bVar1 < (byte)*pcVar15;
    if (bVar1 != *pcVar15) {
LAB_005de814:
      uVar19 = -(uint)bVar21 | 1;
      goto LAB_005de819;
    }
    if (bVar1 == 0) break;
    bVar1 = *(byte *)((int)ppuVar7 + 1);
    bVar21 = bVar1 < ((byte *)pcVar15)[1];
    if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005de814;
    ppuVar7 = (undefined **)((int)ppuVar7 + 2);
    pcVar15 = (char *)((byte *)pcVar15 + 2);
  } while (bVar1 != 0);
  uVar19 = 0;
LAB_005de819:
  if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
    TclFreeObj(piVar12);
  }
  pcVar20 = Tcl_ListObjIndex_exref;
  if (uVar19 == 0) {
    if ((piVar5 == (int *)0x0) ||
       (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_d8), iVar4 != 0)) {
      local_28 = (int *)0x0;
    }
    else {
      local_28 = local_d8;
      if (local_d8 != (int *)0x0) {
        *local_d8 = *local_d8 + 1;
      }
    }
    piVar5 = local_28;
    if ((local_28 != (int *)0x0) &&
       (iVar4 = Tcl_ListObjLength(0,local_28,&local_dc), piVar12 = local_dc, iVar4 == 0)) {
      while (0 < (int)piVar12) {
        local_24 = (int *)((int)piVar12 + -1);
        iVar4 = (*pcVar20)(0,piVar5,local_24,&local_e0);
        if (iVar4 == 0) {
          local_40 = local_e0;
          if (local_e0 != (int *)0x0) {
            *local_e0 = *local_e0 + 1;
          }
        }
        else {
          local_40 = (int *)0x0;
        }
        piVar12 = local_40;
        local_8._0_1_ = 0xd;
        if (local_40 == (int *)0x0) {
          local_18 = &PTR_0071ce50;
        }
        else {
          local_18 = (undefined **)Tcl_GetStringFromObj(local_40,0);
        }
        ppuVar7 = local_18;
        do {
          cVar3 = *(char *)ppuVar7;
          ppuVar7 = (undefined **)((int)ppuVar7 + 1);
        } while (cVar3 != '\0');
        local_3c = (float)((int)ppuVar7 - ((int)local_18 + 1));
        iVar4 = (int)local_3c + 1;
        if (iVar4 < 4) {
          iVar4 = 4;
        }
        local_1dc = (int *)FUN_006ba810(0x19);
        fVar22 = local_3c;
        *(undefined1 *)(local_1dc + 3) = 0;
        local_1dc[1] = (iVar4 + 0xbU & 0xfffffff0) + 4;
        local_14 = (byte *)(local_1dc + 3);
        local_1dc[2] = -1;
        *local_1dc = 0;
        local_1c = local_1dc;
        FUN_006d2250(local_14,local_18,(int)local_3c + 1);
        piVar2 = local_20;
        local_1c[2] = (int)fVar22;
        local_8._0_1_ = 0xe;
        *local_1c = *local_1c + 2;
        local_20 = local_1c;
        local_2c = local_1c;
        if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,0xf);
        *local_1c = *local_1c + -1;
        if (*local_1c == 0) {
          FUN_006ba940();
        }
        if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
          TclFreeObj(piVar12);
        }
        uVar19 = 0;
        pcVar15 = "gnome";
        pbVar8 = local_14;
        do {
          bVar1 = *pbVar8;
          bVar21 = bVar1 < (byte)*pcVar15;
          if (bVar1 != *pcVar15) {
LAB_005de9d2:
            uVar9 = -(uint)bVar21 | 1;
            goto LAB_005de9d7;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar8[1];
          bVar21 = bVar1 < ((byte *)pcVar15)[1];
          if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005de9d2;
          pbVar8 = pbVar8 + 2;
          pcVar15 = (char *)((byte *)pcVar15 + 2);
        } while (bVar1 != 0);
        uVar9 = 0;
LAB_005de9d7:
        if (uVar9 == 0) {
          uVar19 = 2;
        }
        else {
          pcVar15 = "monster";
          pbVar8 = local_14;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005dea10:
              uVar9 = -(uint)bVar21 | 1;
              goto LAB_005dea15;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005dea10;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar9 = 0;
LAB_005dea15:
          if (uVar9 == 0) {
            uVar19 = 4;
          }
          else {
            pbVar16 = &DAT_00727b60;
            pbVar8 = local_14;
            do {
              bVar1 = *pbVar8;
              bVar21 = bVar1 < *pbVar16;
              if (bVar1 != *pbVar16) {
LAB_005dea48:
                uVar9 = -(uint)bVar21 | 1;
                goto LAB_005dea4d;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar8[1];
              bVar21 = bVar1 < pbVar16[1];
              if (bVar1 != pbVar16[1]) goto LAB_005dea48;
              pbVar8 = pbVar8 + 2;
              pbVar16 = pbVar16 + 2;
            } while (bVar1 != 0);
            uVar9 = 0;
LAB_005dea4d:
            if (uVar9 == 0) {
              uVar19 = 0x1000;
            }
            else {
              pcVar15 = "production";
              pbVar8 = local_14;
              do {
                bVar1 = *pbVar8;
                bVar21 = bVar1 < (byte)*pcVar15;
                if (bVar1 != *pcVar15) {
LAB_005dea82:
                  uVar9 = -(uint)bVar21 | 1;
                  goto LAB_005dea87;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar8[1];
                bVar21 = bVar1 < ((byte *)pcVar15)[1];
                if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005dea82;
                pbVar8 = pbVar8 + 2;
                pcVar15 = (char *)((byte *)pcVar15 + 2);
              } while (bVar1 != 0);
              uVar9 = 0;
LAB_005dea87:
              if (uVar9 == 0) {
                uVar19 = 0x20;
              }
              else {
                pbVar16 = &DAT_0072bdb8;
                pbVar8 = local_14;
                do {
                  bVar1 = *pbVar8;
                  bVar21 = bVar1 < *pbVar16;
                  if (bVar1 != *pbVar16) {
LAB_005deac0:
                    uVar9 = -(uint)bVar21 | 1;
                    goto LAB_005deac5;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar8[1];
                  bVar21 = bVar1 < pbVar16[1];
                  if (bVar1 != pbVar16[1]) goto LAB_005deac0;
                  pbVar8 = pbVar8 + 2;
                  pbVar16 = pbVar16 + 2;
                } while (bVar1 != 0);
                uVar9 = 0;
LAB_005deac5:
                if (uVar9 == 0) {
                  uVar19 = 0x10;
                }
                else {
                  pcVar15 = "material";
                  pbVar8 = local_14;
                  do {
                    bVar1 = *pbVar8;
                    bVar21 = bVar1 < (byte)*pcVar15;
                    if (bVar1 != *pcVar15) {
LAB_005deaf8:
                      uVar9 = -(uint)bVar21 | 1;
                      goto LAB_005deafd;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar8[1];
                    bVar21 = bVar1 < ((byte *)pcVar15)[1];
                    if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005deaf8;
                    pbVar8 = pbVar8 + 2;
                    pcVar15 = (char *)((byte *)pcVar15 + 2);
                  } while (bVar1 != 0);
                  uVar9 = 0;
LAB_005deafd:
                  if (uVar9 == 0) {
                    uVar19 = 8;
                  }
                  else {
                    pcVar15 = "energy";
                    pbVar8 = local_14;
                    do {
                      bVar1 = *pbVar8;
                      bVar21 = bVar1 < (byte)*pcVar15;
                      if (bVar1 != *pcVar15) {
LAB_005deb30:
                        uVar9 = -(uint)bVar21 | 1;
                        goto LAB_005deb35;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = pbVar8[1];
                      bVar21 = bVar1 < ((byte *)pcVar15)[1];
                      if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005deb30;
                      pbVar8 = pbVar8 + 2;
                      pcVar15 = (char *)((byte *)pcVar15 + 2);
                    } while (bVar1 != 0);
                    uVar9 = 0;
LAB_005deb35:
                    if (uVar9 == 0) {
                      uVar19 = 0x40;
                    }
                    else {
                      pcVar15 = "protection";
                      pbVar8 = local_14;
                      do {
                        bVar1 = *pbVar8;
                        bVar21 = bVar1 < (byte)*pcVar15;
                        if (bVar1 != *pcVar15) {
LAB_005deb68:
                          uVar9 = -(uint)bVar21 | 1;
                          goto LAB_005deb6d;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = pbVar8[1];
                        bVar21 = bVar1 < ((byte *)pcVar15)[1];
                        if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005deb68;
                        pbVar8 = pbVar8 + 2;
                        pcVar15 = (char *)((byte *)pcVar15 + 2);
                      } while (bVar1 != 0);
                      uVar9 = 0;
LAB_005deb6d:
                      if (uVar9 == 0) {
                        uVar19 = 0x80;
                      }
                      else {
                        pcVar15 = "store";
                        pbVar8 = local_14;
                        do {
                          bVar1 = *pbVar8;
                          bVar21 = bVar1 < (byte)*pcVar15;
                          if (bVar1 != *pcVar15) {
LAB_005deba2:
                            uVar9 = -(uint)bVar21 | 1;
                            goto LAB_005deba7;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = pbVar8[1];
                          bVar21 = bVar1 < ((byte *)pcVar15)[1];
                          if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005deba2;
                          pbVar8 = pbVar8 + 2;
                          pcVar15 = (char *)((byte *)pcVar15 + 2);
                        } while (bVar1 != 0);
                        uVar9 = 0;
LAB_005deba7:
                        if (uVar9 == 0) {
                          uVar19 = 0x100;
                        }
                        else {
                          pcVar15 = "transport";
                          pbVar8 = local_14;
                          do {
                            bVar1 = *pbVar8;
                            bVar21 = bVar1 < (byte)*pcVar15;
                            if (bVar1 != *pcVar15) {
LAB_005debe0:
                              uVar9 = -(uint)bVar21 | 1;
                              goto LAB_005debe5;
                            }
                            if (bVar1 == 0) break;
                            bVar1 = pbVar8[1];
                            bVar21 = bVar1 < ((byte *)pcVar15)[1];
                            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005debe0;
                            pbVar8 = pbVar8 + 2;
                            pcVar15 = (char *)((byte *)pcVar15 + 2);
                          } while (bVar1 != 0);
                          uVar9 = 0;
LAB_005debe5:
                          if (uVar9 == 0) {
                            uVar19 = 0x200;
                          }
                          else {
                            pcVar15 = "elevator";
                            pbVar8 = local_14;
                            do {
                              bVar1 = *pbVar8;
                              bVar21 = bVar1 < (byte)*pcVar15;
                              if (bVar1 != *pcVar15) {
LAB_005dec20:
                                uVar9 = -(uint)bVar21 | 1;
                                goto LAB_005dec25;
                              }
                              if (bVar1 == 0) break;
                              bVar1 = pbVar8[1];
                              bVar21 = bVar1 < ((byte *)pcVar15)[1];
                              if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005dec20;
                              pbVar8 = pbVar8 + 2;
                              pcVar15 = (char *)((byte *)pcVar15 + 2);
                            } while (bVar1 != 0);
                            uVar9 = 0;
LAB_005dec25:
                            if (uVar9 == 0) {
                              uVar19 = 0x400;
                            }
                            else {
                              pbVar16 = &DAT_0072bde8;
                              pbVar8 = local_14;
                              do {
                                bVar1 = *pbVar8;
                                bVar21 = bVar1 < *pbVar16;
                                if (bVar1 != *pbVar16) {
LAB_005dec57:
                                  uVar9 = -(uint)bVar21 | 1;
                                  goto LAB_005dec5c;
                                }
                                if (bVar1 == 0) break;
                                bVar1 = pbVar8[1];
                                bVar21 = bVar1 < pbVar16[1];
                                if (bVar1 != pbVar16[1]) goto LAB_005dec57;
                                pbVar8 = pbVar8 + 2;
                                pbVar16 = pbVar16 + 2;
                              } while (bVar1 != 0);
                              uVar9 = 0;
LAB_005dec5c:
                              if (uVar9 == 0) {
                                uVar19 = 0x800;
                              }
                              else {
                                pbVar16 = &DAT_0072bdf0;
                                pbVar8 = local_14;
                                do {
                                  bVar1 = *pbVar8;
                                  bVar21 = bVar1 < *pbVar16;
                                  if (bVar1 != *pbVar16) {
LAB_005dec90:
                                    uVar9 = -(uint)bVar21 | 1;
                                    goto LAB_005dec95;
                                  }
                                  if (bVar1 == 0) break;
                                  bVar1 = pbVar8[1];
                                  bVar21 = bVar1 < pbVar16[1];
                                  if (bVar1 != pbVar16[1]) goto LAB_005dec90;
                                  pbVar8 = pbVar8 + 2;
                                  pbVar16 = pbVar16 + 2;
                                } while (bVar1 != 0);
                                uVar9 = 0;
LAB_005dec95:
                                if (uVar9 == 0) {
                                  uVar19 = 0xffffffff;
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
        if (local_c0 == 0xffffffff) {
          local_c0 = 0;
        }
        local_c0 = local_c0 | uVar19;
        pcVar20 = Tcl_ListObjIndex_exref;
        piVar12 = local_24;
      }
    }
LAB_005dfffb:
    local_8 = CONCAT31(local_8._1_3_,0xb);
    uVar18 = local_a8;
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
      TclFreeObj(piVar5);
      pbVar8 = local_1d0;
      uVar19 = local_98;
      goto LAB_005de774;
    }
  }
  else {
    if ((piVar5 == (int *)0x0) ||
       (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_e4), piVar12 = local_e4, iVar4 != 0)) {
      piVar12 = (int *)0x0;
LAB_005ded05:
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      if (local_e4 == (int *)0x0) goto LAB_005ded05;
      *local_e4 = *local_e4 + 1;
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_e4,0);
    }
    pcVar15 = "-owner";
    do {
      bVar1 = *(byte *)ppuVar7;
      bVar21 = bVar1 < (byte)*pcVar15;
      if (bVar1 != *pcVar15) {
LAB_005ded30:
        uVar19 = -(uint)bVar21 | 1;
        goto LAB_005ded35;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar7 + 1);
      bVar21 = bVar1 < ((byte *)pcVar15)[1];
      if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005ded30;
      ppuVar7 = (undefined **)((int)ppuVar7 + 2);
      pcVar15 = (char *)((byte *)pcVar15 + 2);
    } while (bVar1 != 0);
    uVar19 = 0;
LAB_005ded35:
    pcVar20 = TclFreeObj_exref;
    if ((piVar12 != (int *)0x0) &&
       (*piVar12 = *piVar12 + -1, pcVar20 = TclFreeObj_exref, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    if (uVar19 == 0) {
      if ((piVar5 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_e8), iVar4 != 0)) {
        local_24 = (int *)0x0;
      }
      else {
        local_24 = local_e8;
        if (local_e8 != (int *)0x0) {
          *local_e8 = *local_e8 + 1;
        }
      }
      piVar5 = local_24;
      if ((local_24 != (int *)0x0) &&
         (iVar10 = Tcl_ListObjLength(0,local_24,&local_ec), iVar4 = local_ec, iVar10 == 0)) {
        while (0 < iVar4) {
          local_1c = (int *)0x0;
          iVar4 = iVar4 + -1;
          iVar10 = Tcl_ListObjIndex(0,piVar5,iVar4,&local_f0);
          if (iVar10 == 0) {
            local_18 = local_f0;
            if (local_f0 != (undefined **)0x0) {
              *local_f0 = *local_f0 + 1;
            }
          }
          else {
            local_18 = (undefined **)0x0;
          }
          ppuVar7 = local_18;
          local_8 = CONCAT31(local_8._1_3_,0x11);
          FUN_005e2330(&local_1c);
          if (local_b8 == 0xffffffff) {
            local_b8 = 0;
          }
          local_b8 = local_b8 | (uint)local_1c;
          pcVar20 = TclFreeObj_exref;
          if ((ppuVar7 != (undefined **)0x0) &&
             (*ppuVar7 = *ppuVar7 + -1, pcVar20 = TclFreeObj_exref, (int)*ppuVar7 < 1)) {
            TclFreeObj(ppuVar7);
          }
        }
      }
      local_8 = CONCAT31(local_8._1_3_,0xb);
      uVar18 = local_a8;
      if ((piVar5 == (int *)0x0) || (*piVar5 = *piVar5 + -1, 0 < *piVar5)) goto LAB_005e0bc8;
      (*pcVar20)(piVar5);
      pbVar8 = local_1d0;
      uVar19 = local_98;
      goto LAB_005de774;
    }
    if ((piVar5 == (int *)0x0) ||
       (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_f4), piVar12 = local_f4, iVar4 != 0)) {
      piVar12 = (int *)0x0;
LAB_005deeba:
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      if (local_f4 == (int *)0x0) goto LAB_005deeba;
      *local_f4 = *local_f4 + 1;
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_f4,0);
    }
    pcVar15 = "-visibility";
    do {
      bVar1 = *(byte *)ppuVar7;
      bVar21 = bVar1 < (byte)*pcVar15;
      if (bVar1 != *pcVar15) {
LAB_005deee4:
        uVar19 = -(uint)bVar21 | 1;
        goto LAB_005deee9;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar7 + 1);
      bVar21 = bVar1 < ((byte *)pcVar15)[1];
      if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005deee4;
      ppuVar7 = (undefined **)((int)ppuVar7 + 2);
      pcVar15 = (char *)((byte *)pcVar15 + 2);
    } while (bVar1 != 0);
    uVar19 = 0;
LAB_005deee9:
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    pcVar20 = Tcl_ListObjIndex_exref;
    if (uVar19 == 0) {
      if ((piVar5 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_f8), iVar4 != 0)) {
        local_24 = (int *)0x0;
      }
      else {
        local_24 = local_f8;
        if (local_f8 != (int *)0x0) {
          *local_f8 = *local_f8 + 1;
        }
      }
      piVar5 = local_24;
      if ((local_24 != (int *)0x0) &&
         (iVar4 = Tcl_ListObjLength(0,local_24,&local_fc), piVar12 = local_fc, iVar4 == 0)) {
        while (0 < (int)piVar12) {
          local_1c = (int *)((int)piVar12 + -1);
          iVar4 = (*pcVar20)(0,piVar5,local_1c,&local_100);
          if (iVar4 == 0) {
            local_18 = (undefined **)local_100;
            if (local_100 != (int *)0x0) {
              *local_100 = *local_100 + 1;
            }
          }
          else {
            local_18 = (undefined **)0x0;
          }
          ppuVar7 = local_18;
          local_8._0_1_ = 0x13;
          if (local_18 == (undefined **)0x0) {
            ppuVar11 = &PTR_0071ce50;
          }
          else {
            ppuVar11 = (undefined **)Tcl_GetStringFromObj(local_18,0);
          }
          piVar12 = (int *)FUN_006b8fb0(ppuVar11);
          local_8._0_1_ = 0x14;
          local_2c = (int *)*piVar12;
          if (local_2c != (int *)0x0) {
            *local_2c = *local_2c + 1;
          }
          piVar2 = local_2c;
          if ((local_20 != (int *)0x0) &&
             (*local_20 = *local_20 + -1, piVar2 = local_2c, *local_20 == 0)) {
            local_20 = local_2c;
            FUN_006ba940();
            piVar2 = local_20;
          }
          local_20 = piVar2;
          local_20[2] = *(int *)(*piVar12 + 8);
          local_8 = CONCAT31(local_8._1_3_,0x15);
          if ((local_104 != (int *)0x0) && (*local_104 = *local_104 + -1, *local_104 == 0)) {
            FUN_006ba940();
          }
          if ((ppuVar7 != (undefined **)0x0) &&
             (*ppuVar7 = (undefined *)((int)*ppuVar7 + -1), (int)*ppuVar7 < 1)) {
            TclFreeObj(ppuVar7);
          }
          iVar4 = Tcl_ListObjIndex(0,piVar5,local_1c,&local_108);
          piVar12 = local_108;
          if ((iVar4 == 0) && (local_108 != (int *)0x0)) {
            *local_108 = *local_108 + 1;
            iVar4 = Tcl_GetIntFromObj(0,local_108,&local_10c);
            *piVar12 = *piVar12 + -1;
            local_14 = (byte *)(-(uint)(iVar4 != 1) & local_10c);
            if (*piVar12 < 1) {
              TclFreeObj(piVar12);
            }
          }
          else {
            local_14 = (byte *)0x0;
          }
          pcVar15 = "playervisible";
          local_18 = (undefined **)0x0;
          pbVar8 = (byte *)(local_20 + 3);
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df0c7:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df0cc;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df0c7;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df0cc:
          if (uVar19 == 0) {
            ppuVar7 = (undefined **)0x10000;
          }
          else {
            pcVar15 = "playerinvisible";
            pbVar8 = (byte *)(local_20 + 3);
            do {
              bVar1 = *pbVar8;
              bVar21 = bVar1 < (byte)*pcVar15;
              if (bVar1 != *pcVar15) {
LAB_005df102:
                uVar19 = -(uint)bVar21 | 1;
                goto LAB_005df107;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar8[1];
              bVar21 = bVar1 < ((byte *)pcVar15)[1];
              if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df102;
              pbVar8 = pbVar8 + 2;
              pcVar15 = (char *)((byte *)pcVar15 + 2);
            } while (bVar1 != 0);
            uVar19 = 0;
LAB_005df107:
            if (uVar19 == 0) {
              ppuVar7 = (undefined **)0x20000;
            }
            else {
              pcVar15 = "enemyvisible";
              pbVar8 = (byte *)(local_20 + 3);
              do {
                bVar1 = *pbVar8;
                bVar21 = bVar1 < (byte)*pcVar15;
                if (bVar1 != *pcVar15) {
LAB_005df140:
                  uVar19 = -(uint)bVar21 | 1;
                  goto LAB_005df145;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar8[1];
                bVar21 = bVar1 < ((byte *)pcVar15)[1];
                if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df140;
                pbVar8 = pbVar8 + 2;
                pcVar15 = (char *)((byte *)pcVar15 + 2);
              } while (bVar1 != 0);
              uVar19 = 0;
LAB_005df145:
              if (uVar19 == 0) {
                ppuVar7 = (undefined **)0x40000;
              }
              else {
                pcVar15 = "enemyinvisible";
                pbVar8 = (byte *)(local_20 + 3);
                do {
                  bVar1 = *pbVar8;
                  bVar21 = bVar1 < (byte)*pcVar15;
                  if (bVar1 != *pcVar15) {
LAB_005df180:
                    uVar19 = -(uint)bVar21 | 1;
                    goto LAB_005df185;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar8[1];
                  bVar21 = bVar1 < ((byte *)pcVar15)[1];
                  if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df180;
                  pbVar8 = pbVar8 + 2;
                  pcVar15 = (char *)((byte *)pcVar15 + 2);
                } while (bVar1 != 0);
                uVar19 = 0;
LAB_005df185:
                if (uVar19 == 0) {
                  ppuVar7 = (undefined **)0x80000;
                }
                else {
                  pbVar16 = &DAT_0072bdf0;
                  pbVar8 = (byte *)(local_20 + 3);
                  do {
                    bVar1 = *pbVar8;
                    bVar21 = bVar1 < *pbVar16;
                    if (bVar1 != *pbVar16) {
LAB_005df1c0:
                      uVar19 = -(uint)bVar21 | 1;
                      goto LAB_005df1c5;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = pbVar8[1];
                    bVar21 = bVar1 < pbVar16[1];
                    if (bVar1 != pbVar16[1]) goto LAB_005df1c0;
                    pbVar8 = pbVar8 + 2;
                    pbVar16 = pbVar16 + 2;
                  } while (bVar1 != 0);
                  uVar19 = 0;
LAB_005df1c5:
                  if (uVar19 == 0) {
                    ppuVar7 = (undefined **)0xffffffff;
                  }
                  else {
                    pbVar16 = &DAT_007295f0;
                    pbVar8 = (byte *)(local_20 + 3);
                    do {
                      bVar1 = *pbVar8;
                      bVar21 = bVar1 < *pbVar16;
                      if (bVar1 != *pbVar16) {
LAB_005df1f6:
                        uVar19 = -(uint)bVar21 | 1;
                        goto LAB_005df1fb;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = pbVar8[1];
                      bVar21 = bVar1 < pbVar16[1];
                      if (bVar1 != pbVar16[1]) goto LAB_005df1f6;
                      pbVar8 = pbVar8 + 2;
                      pbVar16 = pbVar16 + 2;
                    } while (bVar1 != 0);
                    uVar19 = 0;
LAB_005df1fb:
                    if (uVar19 == 0) {
                      ppuVar7 = (undefined **)(1 << ((byte)local_48[0xdb] & 0x1f));
                    }
                    else {
                      ppuVar7 = local_18;
                      if (local_14 < (byte *)0x8) {
                        iVar4 = local_20[2];
                        if (iVar4 == -1) {
                          piVar12 = local_20 + 3;
                          do {
                            iVar4 = *piVar12;
                            piVar12 = (int *)((int)piVar12 + 1);
                          } while ((char)iVar4 != '\0');
                          iVar4 = (int)piVar12 - ((int)local_20 + 0xd);
                          local_20[2] = iVar4;
                        }
                        if (iVar4 == 1) {
                          ppuVar7 = (undefined **)(1 << ((byte)local_14 & 0x1f));
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          if (local_b4 == 0xffffffff) {
            local_b4 = 0;
          }
          local_b4 = local_b4 | (uint)ppuVar7;
          pcVar20 = Tcl_ListObjIndex_exref;
          piVar12 = local_1c;
        }
      }
      goto LAB_005dfffb;
    }
    if ((piVar5 == (int *)0x0) ||
       (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_110), piVar12 = local_110, iVar4 != 0)) {
      piVar12 = (int *)0x0;
LAB_005df2a0:
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      if (local_110 == (int *)0x0) goto LAB_005df2a0;
      *local_110 = *local_110 + 1;
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_110,0);
    }
    pcVar15 = "-flagpos";
    do {
      bVar1 = *(byte *)ppuVar7;
      bVar21 = bVar1 < (byte)*pcVar15;
      if (bVar1 != *pcVar15) {
LAB_005df2d0:
        uVar19 = -(uint)bVar21 | 1;
        goto LAB_005df2d5;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar7 + 1);
      bVar21 = bVar1 < ((byte *)pcVar15)[1];
      if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df2d0;
      ppuVar7 = (undefined **)((int)ppuVar7 + 2);
      pcVar15 = (char *)((byte *)pcVar15 + 2);
    } while (bVar1 != 0);
    uVar19 = 0;
LAB_005df2d5:
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    pcVar20 = Tcl_ListObjIndex_exref;
    if (uVar19 == 0) {
      if ((piVar5 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_114), iVar4 != 0)) {
        local_24 = (int *)0x0;
      }
      else {
        local_24 = local_114;
        if (local_114 != (int *)0x0) {
          *local_114 = *local_114 + 1;
        }
      }
      piVar5 = local_24;
      if ((local_24 != (int *)0x0) &&
         (iVar4 = Tcl_ListObjLength(0,local_24,&local_118), piVar12 = local_118, iVar4 == 0)) {
        while (0 < (int)piVar12) {
          local_1c = (int *)((int)piVar12 + -1);
          iVar4 = (*pcVar20)(0,piVar5,local_1c,&local_11c);
          if (iVar4 == 0) {
            local_18 = local_11c;
            if (local_11c != (undefined **)0x0) {
              *local_11c = *local_11c + 1;
            }
          }
          else {
            local_18 = (undefined **)0x0;
          }
          ppuVar7 = local_18;
          local_8._0_1_ = 0x17;
          if (local_18 == (undefined **)0x0) {
            ppuVar11 = &PTR_0071ce50;
          }
          else {
            ppuVar11 = (undefined **)Tcl_GetStringFromObj(local_18,0);
          }
          piVar12 = (int *)FUN_006b8fb0(ppuVar11);
          local_8._0_1_ = 0x18;
          local_2c = (int *)*piVar12;
          if (local_2c != (int *)0x0) {
            *local_2c = *local_2c + 1;
          }
          piVar2 = local_2c;
          if ((local_20 != (int *)0x0) &&
             (*local_20 = *local_20 + -1, piVar2 = local_2c, *local_20 == 0)) {
            local_20 = local_2c;
            FUN_006ba940();
            piVar2 = local_20;
          }
          local_20 = piVar2;
          local_20[2] = *(int *)(*piVar12 + 8);
          local_8 = CONCAT31(local_8._1_3_,0x19);
          if ((local_120 != (int *)0x0) && (*local_120 = *local_120 + -1, *local_120 == 0)) {
            FUN_006ba940();
          }
          if ((ppuVar7 != (undefined **)0x0) && (*ppuVar7 = *ppuVar7 + -1, (int)*ppuVar7 < 1)) {
            TclFreeObj(ppuVar7);
          }
          pcVar15 = "boxed";
          pbVar16 = (byte *)(local_20 + 3);
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df440:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df445;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df440;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df445:
          pcVar20 = Tcl_ListObjIndex_exref;
          piVar12 = local_1c;
          if (uVar19 == 0) {
            uVar19 = 0x4000;
            goto LAB_005df6be;
          }
          pcVar15 = "visible";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df480:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df485;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df480;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df485:
          if (uVar19 == 0) {
            uVar19 = 1;
            goto LAB_005df6be;
          }
          pcVar15 = "contained";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df4c0:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df4c5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df4c0;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df4c5:
          if (uVar19 == 0) {
            uVar19 = 2;
            goto LAB_005df6be;
          }
          pcVar15 = "locked";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df500:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df505;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df500;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df505:
          if (uVar19 == 0) {
            uVar19 = 4;
            goto LAB_005df6be;
          }
          pcVar15 = "selectable";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df540:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df545;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df540;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df545:
          if (uVar19 == 0) {
            uVar19 = 0x200;
            goto LAB_005df6be;
          }
          pcVar15 = "hoverable";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df580:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df585;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df580;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df585:
          if (uVar19 == 0) {
            uVar19 = 0x400;
            goto LAB_005df6be;
          }
          pcVar15 = "storable";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df5c0:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df5c5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df5c0;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df5c5:
          if (uVar19 == 0) {
            uVar19 = 8;
            goto LAB_005df6be;
          }
          pbVar17 = &DAT_0072be9c;
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < *pbVar17;
            if (bVar1 != *pbVar17) {
LAB_005df600:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df605;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < pbVar17[1];
            if (bVar1 != pbVar17[1]) goto LAB_005df600;
            pbVar8 = pbVar8 + 2;
            pbVar17 = pbVar17 + 2;
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df605:
          if (uVar19 == 0) {
            uVar19 = 0x8000;
            goto LAB_005df6be;
          }
          pcVar15 = "female";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df640:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df645;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df640;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df645:
          if (uVar19 == 0) {
            uVar19 = 0x10000;
            goto LAB_005df6be;
          }
          pcVar15 = "build";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df677:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df67c;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df677;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df67c:
          if (uVar19 == 0) {
            uVar19 = 0x400000;
            goto LAB_005df6be;
          }
          pcVar15 = "instore";
          do {
            bVar1 = *pbVar16;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df6b0:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df6b5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar16[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df6b0;
            pbVar16 = pbVar16 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df6b5:
          if (uVar19 == 0) {
            uVar19 = 0x4000000;
LAB_005df6be:
            local_b0 = local_b0 | uVar19;
          }
        }
      }
      goto LAB_005dfffb;
    }
    if ((piVar5 == (int *)0x0) ||
       (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_124), piVar12 = local_124, iVar4 != 0)) {
      piVar12 = (int *)0x0;
LAB_005df713:
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      if (local_124 == (int *)0x0) goto LAB_005df713;
      *local_124 = *local_124 + 1;
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_124,0);
    }
    pcVar15 = "-flagneg";
    do {
      bVar1 = *(byte *)ppuVar7;
      bVar21 = bVar1 < (byte)*pcVar15;
      if (bVar1 != *pcVar15) {
LAB_005df740:
        uVar19 = -(uint)bVar21 | 1;
        goto LAB_005df745;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar7 + 1);
      bVar21 = bVar1 < ((byte *)pcVar15)[1];
      if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df740;
      ppuVar7 = (undefined **)((int)ppuVar7 + 2);
      pcVar15 = (char *)((byte *)pcVar15 + 2);
    } while (bVar1 != 0);
    uVar19 = 0;
LAB_005df745:
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    pcVar20 = Tcl_ListObjIndex_exref;
    if (uVar19 == 0) {
      if ((piVar5 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_128), iVar4 != 0)) {
        local_24 = (int *)0x0;
      }
      else {
        local_24 = local_128;
        if (local_128 != (int *)0x0) {
          *local_128 = *local_128 + 1;
        }
      }
      piVar5 = local_24;
      if ((local_24 != (int *)0x0) &&
         (iVar4 = Tcl_ListObjLength(0,local_24,&local_12c), piVar12 = local_12c, iVar4 == 0)) {
        while (0 < (int)piVar12) {
          local_1c = (int *)((int)piVar12 + -1);
          iVar4 = (*pcVar20)(0,piVar5,local_1c,&local_130);
          if (iVar4 == 0) {
            local_18 = local_130;
            if (local_130 != (undefined **)0x0) {
              *local_130 = *local_130 + 1;
            }
          }
          else {
            local_18 = (undefined **)0x0;
          }
          ppuVar7 = local_18;
          local_8._0_1_ = 0x1b;
          if (local_18 == (undefined **)0x0) {
            ppuVar11 = &PTR_0071ce50;
          }
          else {
            ppuVar11 = (undefined **)Tcl_GetStringFromObj(local_18,0);
          }
          piVar12 = (int *)FUN_006b8fb0(ppuVar11);
          local_8._0_1_ = 0x1c;
          local_2c = (int *)*piVar12;
          if (local_2c != (int *)0x0) {
            *local_2c = *local_2c + 1;
          }
          piVar2 = local_2c;
          if ((local_20 != (int *)0x0) &&
             (*local_20 = *local_20 + -1, piVar2 = local_2c, *local_20 == 0)) {
            local_20 = local_2c;
            FUN_006ba940();
            piVar2 = local_20;
          }
          local_20 = piVar2;
          local_20[2] = *(int *)(*piVar12 + 8);
          local_8 = CONCAT31(local_8._1_3_,0x1d);
          if ((local_134 != (int *)0x0) && (*local_134 = *local_134 + -1, *local_134 == 0)) {
            FUN_006ba940();
          }
          if ((ppuVar7 != (undefined **)0x0) && (*ppuVar7 = *ppuVar7 + -1, (int)*ppuVar7 < 1)) {
            TclFreeObj(ppuVar7);
          }
          pcVar15 = "boxed";
          pbVar16 = (byte *)(local_20 + 3);
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df8b0:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df8b5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df8b0;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df8b5:
          pcVar20 = Tcl_ListObjIndex_exref;
          piVar12 = local_1c;
          if (uVar19 == 0) {
            uVar19 = 0x4000;
            goto LAB_005dfb2e;
          }
          pcVar15 = "visible";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df8f0:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df8f5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df8f0;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df8f5:
          if (uVar19 == 0) {
            uVar19 = 1;
            goto LAB_005dfb2e;
          }
          pcVar15 = "contained";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df930:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df935;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df930;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df935:
          if (uVar19 == 0) {
            uVar19 = 2;
            goto LAB_005dfb2e;
          }
          pcVar15 = "selectable";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df970:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df975;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df970;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df975:
          if (uVar19 == 0) {
            uVar19 = 0x200;
            goto LAB_005dfb2e;
          }
          pcVar15 = "hoverable";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df9b0:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df9b5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df9b0;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df9b5:
          if (uVar19 == 0) {
            uVar19 = 0x400;
            goto LAB_005dfb2e;
          }
          pcVar15 = "locked";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005df9f0:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005df9f5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005df9f0;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005df9f5:
          if (uVar19 == 0) {
            uVar19 = 4;
            goto LAB_005dfb2e;
          }
          pcVar15 = "storable";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005dfa30:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005dfa35;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005dfa30;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005dfa35:
          if (uVar19 == 0) {
            uVar19 = 8;
            goto LAB_005dfb2e;
          }
          pbVar17 = &DAT_0072be9c;
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < *pbVar17;
            if (bVar1 != *pbVar17) {
LAB_005dfa70:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005dfa75;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < pbVar17[1];
            if (bVar1 != pbVar17[1]) goto LAB_005dfa70;
            pbVar8 = pbVar8 + 2;
            pbVar17 = pbVar17 + 2;
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005dfa75:
          if (uVar19 == 0) {
            uVar19 = 0x8000;
            goto LAB_005dfb2e;
          }
          pcVar15 = "female";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005dfab0:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005dfab5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005dfab0;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005dfab5:
          if (uVar19 == 0) {
            uVar19 = 0x10000;
            goto LAB_005dfb2e;
          }
          pcVar15 = "build";
          pbVar8 = pbVar16;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005dfae7:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005dfaec;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005dfae7;
            pbVar8 = pbVar8 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005dfaec:
          if (uVar19 == 0) {
            uVar19 = 0x400000;
            goto LAB_005dfb2e;
          }
          pcVar15 = "instore";
          do {
            bVar1 = *pbVar16;
            bVar21 = bVar1 < (byte)*pcVar15;
            if (bVar1 != *pcVar15) {
LAB_005dfb20:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005dfb25;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar16[1];
            bVar21 = bVar1 < ((byte *)pcVar15)[1];
            if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005dfb20;
            pbVar16 = pbVar16 + 2;
            pcVar15 = (char *)((byte *)pcVar15 + 2);
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005dfb25:
          if (uVar19 == 0) {
            uVar19 = 0x4000000;
LAB_005dfb2e:
            local_ac = local_ac | uVar19;
          }
        }
      }
      goto LAB_005dfffb;
    }
    if ((piVar5 == (int *)0x0) ||
       (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_138), piVar12 = local_138, iVar4 != 0)) {
      piVar12 = (int *)0x0;
LAB_005dfb83:
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      if (local_138 == (int *)0x0) goto LAB_005dfb83;
      *local_138 = *local_138 + 1;
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_138,0);
    }
    pcVar15 = "-sorting";
    do {
      bVar1 = *(byte *)ppuVar7;
      bVar21 = bVar1 < (byte)*pcVar15;
      if (bVar1 != *pcVar15) {
LAB_005dfbb0:
        uVar19 = -(uint)bVar21 | 1;
        goto LAB_005dfbb5;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar7 + 1);
      bVar21 = bVar1 < ((byte *)pcVar15)[1];
      if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005dfbb0;
      ppuVar7 = (undefined **)((int)ppuVar7 + 2);
      pcVar15 = (char *)((byte *)pcVar15 + 2);
    } while (bVar1 != 0);
    uVar19 = 0;
LAB_005dfbb5:
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    if (uVar19 == 0) {
      if ((piVar5 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_13c), iVar4 != 0)) {
        local_24 = (int *)0x0;
      }
      else {
        local_24 = local_13c;
        if (local_13c != (int *)0x0) {
          *local_13c = *local_13c + 1;
        }
      }
      piVar5 = local_24;
      local_8._0_1_ = 0x1e;
      if (local_24 == (int *)0x0) {
        ppuVar7 = &PTR_0071ce50;
      }
      else {
        ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_24,0);
      }
      FUN_006b9200(ppuVar7);
      local_4c = 1;
      pbVar17 = &DAT_0072becc;
      pbVar8 = (byte *)(local_2c + 3);
      pbVar16 = pbVar8;
      do {
        bVar1 = *pbVar16;
        bVar21 = bVar1 < *pbVar17;
        if (bVar1 != *pbVar17) {
LAB_005dfc60:
          uVar19 = -(uint)bVar21 | 1;
          goto LAB_005dfc65;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar16[1];
        bVar21 = bVar1 < pbVar17[1];
        if (bVar1 != pbVar17[1]) goto LAB_005dfc60;
        pbVar16 = pbVar16 + 2;
        pbVar17 = pbVar17 + 2;
      } while (bVar1 != 0);
      uVar19 = 0;
LAB_005dfc65:
      if (uVar19 != 0) {
        pbVar17 = &DAT_0072bed0;
        pbVar16 = pbVar8;
        do {
          bVar1 = *pbVar16;
          bVar21 = bVar1 < *pbVar17;
          if (bVar1 != *pbVar17) {
LAB_005dfc90:
            uVar19 = -(uint)bVar21 | 1;
            goto LAB_005dfc95;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar16[1];
          bVar21 = bVar1 < pbVar17[1];
          if (bVar1 != pbVar17[1]) goto LAB_005dfc90;
          pbVar16 = pbVar16 + 2;
          pbVar17 = pbVar17 + 2;
        } while (bVar1 != 0);
        uVar19 = 0;
LAB_005dfc95:
        if (uVar19 == 0) {
          local_4c = 2;
        }
        else {
          pbVar16 = &DAT_00722ca4;
          do {
            bVar1 = *pbVar8;
            bVar21 = bVar1 < *pbVar16;
            if (bVar1 != *pbVar16) {
LAB_005dfcc7:
              uVar19 = -(uint)bVar21 | 1;
              goto LAB_005dfccc;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar8[1];
            bVar21 = bVar1 < pbVar16[1];
            if (bVar1 != pbVar16[1]) goto LAB_005dfcc7;
            pbVar8 = pbVar8 + 2;
            pbVar16 = pbVar16 + 2;
          } while (bVar1 != 0);
          uVar19 = 0;
LAB_005dfccc:
          if (uVar19 == 0) {
            local_4c = 0;
          }
        }
      }
      local_8 = CONCAT31(local_8._1_3_,0xb);
      local_20 = local_2c;
joined_r0x005e036b:
      uVar18 = local_a8;
      if (piVar5 == (int *)0x0) goto LAB_005e0bc8;
LAB_005e0a9b:
      *piVar5 = *piVar5 + -1;
      uVar18 = local_a8;
      if (0 < *piVar5) goto LAB_005e0bc8;
      TclFreeObj(piVar5);
      pbVar8 = local_1d0;
      uVar19 = local_98;
      goto LAB_005de774;
    }
    if ((piVar5 == (int *)0x0) ||
       (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_140), piVar12 = local_140, iVar4 != 0)) {
      piVar12 = (int *)0x0;
LAB_005dfd20:
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      if (local_140 == (int *)0x0) goto LAB_005dfd20;
      *local_140 = *local_140 + 1;
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_140,0);
    }
    pcVar15 = "-alloc";
    do {
      bVar1 = *(byte *)ppuVar7;
      bVar21 = bVar1 < (byte)*pcVar15;
      if (bVar1 != *pcVar15) {
LAB_005dfd50:
        uVar19 = -(uint)bVar21 | 1;
        goto LAB_005dfd55;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar7 + 1);
      bVar21 = bVar1 < ((byte *)pcVar15)[1];
      if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005dfd50;
      ppuVar7 = (undefined **)((int)ppuVar7 + 2);
      pcVar15 = (char *)((byte *)pcVar15 + 2);
    } while (bVar1 != 0);
    uVar19 = 0;
LAB_005dfd55:
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    if (uVar19 == 0) {
      if ((piVar5 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_144), piVar5 = local_144, iVar4 != 0
         )) {
        piVar5 = (int *)0x0;
      }
      else if (local_144 != (int *)0x0) {
        *local_144 = *local_144 + 1;
        iVar4 = Tcl_GetIntFromObj(0,local_144,&local_148);
        local_a4 = -(uint)(iVar4 != 1) & local_148;
        goto joined_r0x005e036b;
      }
      local_a4 = 0;
      goto joined_r0x005e036b;
    }
    if ((piVar5 == (int *)0x0) ||
       (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_14c), piVar12 = local_14c, iVar4 != 0)) {
      piVar12 = (int *)0x0;
LAB_005dfe08:
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      if (local_14c == (int *)0x0) goto LAB_005dfe08;
      *local_14c = *local_14c + 1;
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_14c,0);
    }
    pcVar15 = "-class";
    do {
      bVar1 = *(byte *)ppuVar7;
      bVar21 = bVar1 < (byte)*pcVar15;
      if (bVar1 != *pcVar15) {
LAB_005dfe32:
        uVar19 = -(uint)bVar21 | 1;
        goto LAB_005dfe37;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar7 + 1);
      bVar21 = bVar1 < ((byte *)pcVar15)[1];
      if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005dfe32;
      ppuVar7 = (undefined **)((int)ppuVar7 + 2);
      pcVar15 = (char *)((byte *)pcVar15 + 2);
    } while (bVar1 != 0);
    uVar19 = 0;
LAB_005dfe37:
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    pcVar20 = Tcl_ListObjIndex_exref;
    if (uVar19 == 0) {
      if ((piVar5 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_150), iVar4 != 0)) {
        local_24 = (int *)0x0;
      }
      else {
        local_24 = local_150;
        if (local_150 != (int *)0x0) {
          *local_150 = *local_150 + 1;
        }
      }
      piVar5 = local_24;
      if (((local_24 != (int *)0x0) &&
          (iVar4 = Tcl_ListObjLength(0,local_24,&local_154), iVar4 == 0)) &&
         (piVar12 = local_154, 0 < (int)local_154)) {
        do {
          local_1c = (int *)((int)piVar12 + -1);
          iVar4 = (*pcVar20)(0,piVar5,local_1c,&local_158);
          if (iVar4 == 0) {
            local_18 = local_158;
            if (local_158 != (undefined **)0x0) {
              *local_158 = *local_158 + 1;
            }
          }
          else {
            local_18 = (undefined **)0x0;
          }
          ppuVar7 = local_18;
          local_8._0_1_ = 0x20;
          if (local_18 == (undefined **)0x0) {
            ppuVar11 = &PTR_0071ce50;
          }
          else {
            ppuVar11 = (undefined **)Tcl_GetStringFromObj(local_18,0);
          }
          FUN_006b9200(ppuVar11);
          local_8 = CONCAT31(local_8._1_3_,0x1f);
          if ((ppuVar7 != (undefined **)0x0) && (*ppuVar7 = *ppuVar7 + -1, (int)*ppuVar7 < 1)) {
            TclFreeObj(ppuVar7);
          }
          iVar4 = DAT_00772478;
          cVar3 = FUN_006037d0(&local_2c,&local_15c);
          uVar19 = local_15c;
          if (cVar3 == '\0') {
LAB_005dff84:
            uVar19 = local_84;
            if ((local_84 + 0x10 & 0xfffffff0) != (local_84 + 0xf & 0xfffffff0)) {
              local_88 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                      ,0x9b);
              uVar19 = local_84;
            }
            local_84 = uVar19 + 1;
            if (local_84 <= uVar19) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(undefined4 *)(local_88 + uVar19 * 4) = 0xfffffffe;
          }
          else {
            if (*(uint *)(iVar4 + 0x801c) <= local_15c) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar4 = *(int *)(*(int *)(iVar4 + 0x8018) + uVar19 * 4);
            if (iVar4 == 0) goto LAB_005dff84;
            FUN_005de040(*(undefined4 *)(iVar4 + 8));
          }
          piVar12 = local_1c;
          pcVar20 = Tcl_ListObjIndex_exref;
        } while (0 < (int)local_1c);
        local_20 = local_2c;
      }
      goto LAB_005dfffb;
    }
    if ((piVar5 == (int *)0x0) ||
       (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_160), piVar12 = local_160, iVar4 != 0)) {
      piVar12 = (int *)0x0;
LAB_005e0060:
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      if (local_160 == (int *)0x0) goto LAB_005e0060;
      *local_160 = *local_160 + 1;
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_160,0);
    }
    pcVar15 = "-range";
    do {
      bVar1 = *(byte *)ppuVar7;
      bVar21 = bVar1 < (byte)*pcVar15;
      if (bVar1 != *pcVar15) {
LAB_005e0090:
        uVar19 = -(uint)bVar21 | 1;
        goto LAB_005e0095;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar7 + 1);
      bVar21 = bVar1 < ((byte *)pcVar15)[1];
      if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005e0090;
      ppuVar7 = (undefined **)((int)ppuVar7 + 2);
      pcVar15 = (char *)((byte *)pcVar15 + 2);
    } while (bVar1 != 0);
    uVar19 = 0;
LAB_005e0095:
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    if (uVar19 == 0) {
      uVar18 = local_a8;
      if (((piVar5 != (int *)0x0) &&
          (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_164), piVar5 = local_164,
          uVar18 = local_a8, iVar4 == 0)) && (local_164 != (int *)0x0)) {
        *local_164 = *local_164 + 1;
        iVar4 = Tcl_GetDoubleFromObj(0,local_164,&local_1e4);
        if (iVar4 == 1) {
          dVar23 = 0.0;
        }
        else {
          dVar23 = (double)(ulonglong)(uint)(float)local_1e4;
        }
        *piVar5 = *piVar5 + -1;
        local_18 = SUB84(dVar23,0);
        if (*piVar5 < 1) {
          TclFreeObj(piVar5);
        }
        uVar18 = local_a8;
        if ((float)local_18 <= 0.0) goto LAB_005e0bc8;
        local_7c = local_30 - (float)local_18;
        local_78 = local_34 - (float)local_18;
        local_80 = local_38 - (float)local_18;
        local_a0 = 1;
        local_70 = (float)local_18 + local_30;
        local_74 = (float)local_18 + local_38;
        dVar23 = (double)(ulonglong)(uint)local_74;
        local_6c = (float)local_18 + local_34;
        local_cc = (float)local_18 * (float)local_18;
        pbVar8 = local_1d0;
        uVar19 = local_98;
        goto LAB_005de774;
      }
    }
    else {
      if ((piVar5 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_168), piVar12 = local_168, iVar4 != 0))
      {
        piVar12 = (int *)0x0;
LAB_005e01e7:
        ppuVar7 = &PTR_0071ce50;
      }
      else {
        if (local_168 == (int *)0x0) goto LAB_005e01e7;
        *local_168 = *local_168 + 1;
        ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_168,0);
      }
      pbVar8 = &DAT_0072bee8;
      do {
        bVar1 = *(byte *)ppuVar7;
        bVar21 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_005e0211:
          uVar19 = -(uint)bVar21 | 1;
          goto LAB_005e0216;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar7 + 1);
        bVar21 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_005e0211;
        ppuVar7 = (undefined **)((int)ppuVar7 + 2);
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      uVar19 = 0;
LAB_005e0216:
      if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
        TclFreeObj(piVar12);
      }
      if (uVar19 == 0) {
        if ((piVar5 == (int *)0x0) ||
           (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_16c), piVar5 = local_16c,
           iVar4 != 0)) {
          piVar5 = (int *)0x0;
        }
        else if (local_16c != (int *)0x0) {
          *local_16c = *local_16c + 1;
          iVar4 = Tcl_ListObjIndex(0,local_16c,0,&local_170);
          if (((iVar4 == 0) && (iVar4 = Tcl_ListObjIndex(0,piVar5,1,&local_174), iVar4 == 0)) &&
             (iVar4 = Tcl_ListObjIndex(0,piVar5,2,&local_178), iVar4 == 0)) {
            local_28 = local_170;
            if (local_170 != (int *)0x0) {
              *local_170 = *local_170 + 1;
            }
            local_1c = local_174;
            if (local_174 != (int *)0x0) {
              *local_174 = *local_174 + 1;
            }
            local_18 = local_178;
            if (local_178 != (undefined **)0x0) {
              *local_178 = *local_178 + 1;
            }
            FUN_006baf40();
            local_38 = (float)dVar23;
            dVar23 = (double)CONCAT44((int)((ulonglong)dVar23 >> 0x20),local_38);
            FUN_006baf40();
            local_30 = (float)dVar23;
            dVar23 = (double)CONCAT44((int)((ulonglong)dVar23 >> 0x20),local_30);
            FUN_006baf40();
            local_34 = (float)dVar23;
            dVar23 = (double)CONCAT44((int)((ulonglong)dVar23 >> 0x20),local_34);
            FUN_006bad60();
            FUN_006bad60();
            FUN_006bad60();
            local_68 = local_38;
            local_60 = local_34;
            local_64 = local_30;
            goto joined_r0x005e036b;
          }
        }
        local_34 = 0.0;
        local_30 = 0.0;
        local_38 = 0.0;
        local_68 = local_38;
        local_60 = local_34;
        local_64 = local_30;
        goto joined_r0x005e036b;
      }
      if ((piVar5 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_17c), piVar12 = local_17c, iVar4 != 0))
      {
        piVar12 = (int *)0x0;
LAB_005e03af:
        ppuVar7 = &PTR_0071ce50;
      }
      else {
        if (local_17c == (int *)0x0) goto LAB_005e03af;
        *local_17c = *local_17c + 1;
        ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_17c,0);
      }
      pcVar15 = "-boundingbox";
      do {
        bVar1 = *(byte *)ppuVar7;
        bVar21 = bVar1 < (byte)*pcVar15;
        if (bVar1 != *pcVar15) {
LAB_005e03e0:
          uVar19 = -(uint)bVar21 | 1;
          goto LAB_005e03e5;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar7 + 1);
        bVar21 = bVar1 < ((byte *)pcVar15)[1];
        if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005e03e0;
        ppuVar7 = (undefined **)((int)ppuVar7 + 2);
        pcVar15 = (char *)((byte *)pcVar15 + 2);
      } while (bVar1 != 0);
      uVar19 = 0;
LAB_005e03e5:
      if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
        TclFreeObj(piVar12);
      }
      if (uVar19 == 0) {
        uVar18 = local_a8;
        if (((piVar5 == (int *)0x0) ||
            (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_180), piVar5 = local_180,
            uVar18 = local_a8, iVar4 != 0)) || (local_180 == (int *)0x0)) goto LAB_005e0bc8;
        *local_180 = *local_180 + 1;
        iVar4 = Tcl_ListObjLength(0,local_180,&local_184);
        if ((iVar4 == 0) && (local_184 == 2)) {
          iVar4 = Tcl_ListObjIndex(0,piVar5,0,&local_188);
          if (iVar4 == 0) {
            local_18 = (undefined **)local_188;
            if (local_188 != (int *)0x0) {
              *local_188 = *local_188 + 1;
            }
          }
          else {
            local_18 = (undefined **)0x0;
          }
          ppuVar7 = local_18;
          pfVar13 = (float *)FUN_006bafe0(local_238);
          local_3c = *pfVar13;
          local_28 = (int *)pfVar13[1];
          local_40 = (int *)pfVar13[2];
          if ((ppuVar7 != (undefined **)0x0) &&
             (*ppuVar7 = (undefined *)((int)*ppuVar7 + -1), (int)*ppuVar7 < 1)) {
            TclFreeObj(ppuVar7);
          }
          iVar4 = Tcl_ListObjIndex(0,piVar5,1,&local_18c);
          if (iVar4 == 0) {
            local_18 = (undefined **)local_18c;
            if (local_18c != (int *)0x0) {
              *local_18c = *local_18c + 1;
            }
          }
          else {
            local_18 = (undefined **)0x0;
          }
          ppuVar7 = local_18;
          puVar14 = (undefined4 *)FUN_006bafe0(local_244);
          local_1c = (int *)*puVar14;
          local_24 = (int *)puVar14[1];
          local_18 = (undefined **)puVar14[2];
          if ((ppuVar7 != (undefined **)0x0) &&
             (*ppuVar7 = (undefined *)((int)*ppuVar7 + -1), (int)*ppuVar7 < 1)) {
            TclFreeObj(ppuVar7);
          }
          local_70 = (float)local_24 + local_30;
          local_7c = local_30 + (float)local_28;
          fVar22 = local_34 + (float)local_40;
          local_80 = local_3c + local_38;
          local_74 = (float)local_1c + local_38;
          local_78 = fVar22;
          local_6c = (float)local_18 + local_34;
LAB_005e089d:
          dVar23 = (double)(ulonglong)(uint)fVar22;
          local_a0 = 3;
        }
        else {
          iVar4 = Tcl_ListObjLength(0,piVar5,&local_190);
          if ((iVar4 == 0) && (local_190 == 6)) {
            iVar4 = Tcl_ListObjIndex(0,piVar5,0,&local_194);
            piVar12 = local_194;
            if ((iVar4 == 0) && (local_194 != (int *)0x0)) {
              *local_194 = *local_194 + 1;
              iVar4 = Tcl_GetDoubleFromObj(0,local_194,&local_1ec);
              if (iVar4 == 1) {
                local_1c = (int *)0x0;
              }
              else {
                local_1c = (int *)(float)local_1ec;
              }
              *piVar12 = *piVar12 + -1;
              pcVar20 = TclFreeObj_exref;
              if (*piVar12 < 1) {
                TclFreeObj(piVar12);
              }
            }
            else {
              local_1c = (int *)0x0;
              pcVar20 = TclFreeObj_exref;
            }
            iVar4 = Tcl_ListObjIndex(0,piVar5,1,&local_198);
            piVar12 = local_198;
            if ((iVar4 == 0) && (local_198 != (int *)0x0)) {
              *local_198 = *local_198 + 1;
              iVar4 = Tcl_GetDoubleFromObj(0,local_198,&local_1f4);
              if (iVar4 == 1) {
                local_40 = (int *)0x0;
              }
              else {
                local_40 = (int *)(float)local_1f4;
              }
              *piVar12 = *piVar12 + -1;
              if (*piVar12 < 1) {
                (*pcVar20)(piVar12);
              }
            }
            else {
              local_40 = (int *)0x0;
            }
            iVar4 = Tcl_ListObjIndex(0,piVar5,2,&local_19c);
            piVar12 = local_19c;
            if ((iVar4 == 0) && (local_19c != (int *)0x0)) {
              *local_19c = *local_19c + 1;
              iVar4 = Tcl_GetDoubleFromObj(0,local_19c,&local_1fc);
              if (iVar4 == 1) {
                local_28 = (int *)0x0;
              }
              else {
                local_28 = (int *)(float)local_1fc;
              }
              *piVar12 = *piVar12 + -1;
              if (*piVar12 < 1) {
                (*pcVar20)(piVar12);
              }
            }
            else {
              local_28 = (int *)0x0;
            }
            iVar4 = Tcl_ListObjIndex(0,piVar5,3,&local_1a0);
            piVar12 = local_1a0;
            if ((iVar4 == 0) && (local_1a0 != (int *)0x0)) {
              *local_1a0 = *local_1a0 + 1;
              iVar4 = Tcl_GetDoubleFromObj(0,local_1a0,&local_204);
              if (iVar4 == 1) {
                local_18 = (undefined **)0x0;
              }
              else {
                local_18 = (undefined **)(float)local_204;
              }
              *piVar12 = *piVar12 + -1;
              if (*piVar12 < 1) {
                (*pcVar20)(piVar12);
              }
            }
            else {
              local_18 = (undefined **)0x0;
            }
            iVar4 = Tcl_ListObjIndex(0,piVar5,4,&local_1a4);
            piVar12 = local_1a4;
            if ((iVar4 == 0) && (local_1a4 != (int *)0x0)) {
              *local_1a4 = *local_1a4 + 1;
              iVar4 = Tcl_GetDoubleFromObj(0,local_1a4,&local_20c);
              if (iVar4 == 1) {
                local_3c = 0.0;
              }
              else {
                local_3c = (float)local_20c;
              }
              *piVar12 = *piVar12 + -1;
              if (*piVar12 < 1) {
                (*pcVar20)(piVar12);
              }
            }
            else {
              local_3c = 0.0;
            }
            iVar4 = Tcl_ListObjIndex(0,piVar5,5,&local_1a8);
            piVar12 = local_1a8;
            if ((iVar4 == 0) && (local_1a8 != (int *)0x0)) {
              *local_1a8 = *local_1a8 + 1;
              iVar4 = Tcl_GetDoubleFromObj(0,local_1a8,&local_214);
              if (iVar4 == 1) {
                local_14 = (byte *)0x0;
              }
              else {
                local_14 = (byte *)(float)local_214;
              }
              *piVar12 = *piVar12 + -1;
              pbVar8 = local_14;
              if (*piVar12 < 1) {
                (*pcVar20)(piVar12);
                pbVar8 = local_14;
              }
            }
            else {
              pbVar8 = (byte *)0x0;
            }
            local_78 = (float)local_28 + local_34;
            local_70 = local_3c + local_30;
            fVar22 = (float)pbVar8 + local_34;
            local_7c = (float)local_40 + local_30;
            local_80 = (float)local_1c + local_38;
            local_74 = (float)local_18 + local_38;
            local_6c = fVar22;
            goto LAB_005e089d;
          }
        }
        *piVar5 = *piVar5 + -1;
        uVar18 = local_a8;
        if (0 < *piVar5) goto LAB_005e0bc8;
        TclFreeObj(piVar5);
        pbVar8 = local_1d0;
        uVar19 = local_98;
        goto LAB_005de774;
      }
      if ((piVar5 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_1ac), piVar12 = local_1ac, iVar4 != 0))
      {
        piVar12 = (int *)0x0;
LAB_005e0908:
        ppuVar7 = &PTR_0071ce50;
      }
      else {
        if (local_1ac == (int *)0x0) goto LAB_005e0908;
        *local_1ac = *local_1ac + 1;
        ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_1ac,0);
      }
      pcVar15 = "-limit";
      do {
        bVar1 = *(byte *)ppuVar7;
        bVar21 = bVar1 < (byte)*pcVar15;
        if (bVar1 != *pcVar15) {
LAB_005e0932:
          uVar19 = -(uint)bVar21 | 1;
          goto LAB_005e0937;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar7 + 1);
        bVar21 = bVar1 < ((byte *)pcVar15)[1];
        if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005e0932;
        ppuVar7 = (undefined **)((int)ppuVar7 + 2);
        pcVar15 = (char *)((byte *)pcVar15 + 2);
      } while (bVar1 != 0);
      uVar19 = 0;
LAB_005e0937:
      if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
        TclFreeObj(piVar12);
      }
      if (uVar19 == 0) {
        uVar18 = local_a8;
        if (((piVar5 != (int *)0x0) &&
            (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_1b0), piVar5 = local_1b0,
            uVar18 = local_a8, iVar4 == 0)) && (local_1b0 != (int *)0x0)) {
          *local_1b0 = *local_1b0 + 1;
          iVar4 = Tcl_GetIntFromObj(0,local_1b0,&local_1b4);
          *piVar5 = *piVar5 + -1;
          uVar19 = -(uint)(iVar4 != 1) & local_1b4;
          if (*piVar5 < 1) {
            TclFreeObj(piVar5);
          }
          pbVar8 = local_1d0;
          uVar18 = local_a8;
          if ((int)uVar19 < 1) goto LAB_005e0bc8;
          goto LAB_005de774;
        }
      }
      else {
        if ((piVar5 == (int *)0x0) ||
           (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_1b8), piVar12 = local_1b8, iVar4 != 0)
           ) {
          piVar12 = (int *)0x0;
LAB_005e0a08:
          ppuVar7 = &PTR_0071ce50;
        }
        else {
          if (local_1b8 == (int *)0x0) goto LAB_005e0a08;
          *local_1b8 = *local_1b8 + 1;
          ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_1b8,0);
        }
        pcVar15 = "-cloaked";
        do {
          bVar1 = *(byte *)ppuVar7;
          bVar21 = bVar1 < (byte)*pcVar15;
          if (bVar1 != *pcVar15) {
LAB_005e0a32:
            uVar19 = -(uint)bVar21 | 1;
            goto LAB_005e0a37;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar7 + 1);
          bVar21 = bVar1 < ((byte *)pcVar15)[1];
          if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005e0a32;
          ppuVar7 = (undefined **)((int)ppuVar7 + 2);
          pcVar15 = (char *)((byte *)pcVar15 + 2);
        } while (bVar1 != 0);
        uVar19 = 0;
LAB_005e0a37:
        if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
          TclFreeObj(piVar12);
        }
        if (uVar19 == 0) {
          if (((piVar5 == (int *)0x0) ||
              (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_1bc), piVar5 = local_1bc,
              iVar4 != 0)) || (local_1bc == (int *)0x0)) {
            local_44 = (int *)0x0;
            pbVar8 = local_1d0;
            uVar19 = local_98;
            goto LAB_005de774;
          }
          *local_1bc = *local_1bc + 1;
          iVar4 = Tcl_GetIntFromObj(0,local_1bc,&local_1c0);
          local_44 = (int *)(-(uint)(iVar4 != 1) & local_1c0);
          goto LAB_005e0a9b;
        }
        if ((piVar5 == (int *)0x0) ||
           (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14,&local_1c4), piVar12 = local_1c4, iVar4 != 0)
           ) {
          piVar12 = (int *)0x0;
LAB_005e0b06:
          ppuVar7 = &PTR_0071ce50;
        }
        else {
          if (local_1c4 == (int *)0x0) goto LAB_005e0b06;
          *local_1c4 = *local_1c4 + 1;
          ppuVar7 = (undefined **)Tcl_GetStringFromObj(local_1c4,0);
        }
        pcVar15 = "-water";
        do {
          bVar1 = *(byte *)ppuVar7;
          bVar21 = bVar1 < (byte)*pcVar15;
          if (bVar1 != *pcVar15) {
LAB_005e0b30:
            uVar19 = -(uint)bVar21 | 1;
            goto LAB_005e0b35;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar7 + 1);
          bVar21 = bVar1 < ((byte *)pcVar15)[1];
          if (bVar1 != ((byte *)pcVar15)[1]) goto LAB_005e0b30;
          ppuVar7 = (undefined **)((int)ppuVar7 + 2);
          pcVar15 = (char *)((byte *)pcVar15 + 2);
        } while (bVar1 != 0);
        uVar19 = 0;
LAB_005e0b35:
        if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
          TclFreeObj(piVar12);
        }
        uVar18 = local_a8;
        if (uVar19 == 0) {
          if (((piVar5 != (int *)0x0) &&
              (iVar4 = Tcl_ListObjIndex(0,piVar5,local_14 + 1,&local_1c8), piVar5 = local_1c8,
              iVar4 == 0)) && (local_1c8 != (int *)0x0)) {
            *local_1c8 = *local_1c8 + 1;
            iVar4 = Tcl_GetBooleanFromObj(0,local_1c8,&local_1cc);
            uVar18 = iVar4 != 1 && local_1cc != 0;
            *piVar5 = *piVar5 + -1;
            if (0 < *piVar5) goto LAB_005e0bc8;
            TclFreeObj(piVar5);
            pbVar8 = local_1d0;
            local_a8 = uVar18;
            uVar19 = local_98;
            goto LAB_005de774;
          }
          uVar18 = 0;
        }
      }
    }
  }
LAB_005e0bc8:
  local_a8 = uVar18;
  pbVar8 = local_1d0;
  uVar19 = local_98;
  goto LAB_005de774;
LAB_005e0bd3:
  if (local_44 == (int *)0x0) {
    local_ac = local_ac | 0x8000000;
  }
  local_9c = local_4c;
  local_44 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,0x21);
  bVar21 = false;
  while( true ) {
    if (local_d4 == -2) {
      FUN_005e12a0();
    }
    local_d4 = local_d4 + 1;
    if (local_c4 <= local_d4) break;
    if ((local_d4 < 0) || (local_c4 <= local_d4)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar4 = FUN_005caf90();
    if (iVar4 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)Tcl_NewStringObj(iVar4,0xffffffff);
      *piVar5 = *piVar5 + 1;
    }
    local_48 = piVar5;
    FUN_006bb930(&local_48);
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
      TclFreeObj(piVar5);
    }
    bVar21 = true;
  }
  piVar5 = local_44;
  if (!bVar21) {
    piVar5 = (int *)Tcl_NewIntObj(0);
    *piVar5 = *piVar5 + 2;
    if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 < 1)) {
      TclFreeObj(local_44);
    }
    *piVar5 = *piVar5 + -1;
    if (*piVar5 < 1) {
      TclFreeObj(piVar5);
    }
  }
  if (local_228 != 0) {
    if (piVar5 == (int *)0x0) {
      Tcl_ResetResult(local_228);
      pcVar20 = TclFreeObj_exref;
      goto LAB_005e0d05;
    }
    Tcl_SetObjResult(local_228,piVar5);
  }
  pcVar20 = TclFreeObj_exref;
  if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, pcVar20 = TclFreeObj_exref, *piVar5 < 1)) {
    TclFreeObj(piVar5);
  }
LAB_005e0d05:
  local_8._0_1_ = 0x22;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0x23);
  FUN_0040b980(0);
  if (local_88 != 0) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0x24);
  FUN_006ba940();
  thunk_FUN_0060fc30(local_c8);
  if ((local_5c != (int *)0x0) && (*local_5c = *local_5c + -1, *local_5c < 1)) {
    (*pcVar20)(local_5c);
  }
  local_8._0_1_ = 0x25;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x26);
  FUN_004297b0(0);
  if (local_58 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

