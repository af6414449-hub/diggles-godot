
/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */

void FUN_10039ce0(int param_1,uint param_2,int param_3,int param_4)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  int in_ECX;
  int iVar9;
  int *piVar10;
  int *in_EDX;
  uint uVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  float fVar17;
  float fVar18;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_4c;
  int local_44;
  int *local_38;
  int local_34;
  int *local_30;
  float *local_2c;
  uint local_28;
  uint *local_24;
  int local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int local_10;
  byte local_9;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  sVar2 = *(short *)(in_ECX + 0x118 + param_3 * 2);
  local_14 = param_3 * 3;
  local_10 = *(int *)(in_ECX + 0x198);
  iVar3 = *(int *)((uint)*(byte *)(local_10 + 0xd + param_3 * 0x18) * 0x830 +
                  *(int *)(in_ECX + 0x88));
  uVar7 = param_2 * 2;
  if (sVar2 != 2) {
    uVar7 = param_2;
  }
  uVar4 = *(uint *)(local_10 + param_3 * 0x18);
  uVar11 = uVar7;
  if (uVar4 < uVar7) {
    uVar11 = uVar4;
  }
  if (*(uint *)(local_10 + 4 + param_3 * 0x18) < uVar7) {
    uVar7 = *(uint *)(local_10 + 4 + param_3 * 0x18);
  }
  local_24 = (uint *)(local_10 + 8 + param_3 * 0x18);
  uVar7 = (uVar7 - uVar11) / *local_24;
  iVar14 = *(int *)(in_ECX + 4);
  iVar5 = *(int *)(in_ECX + 0x68);
  if (*(int *)(in_ECX + 0x5c) == 0) {
    local_38 = (int *)&stack0xffffff88;
  }
  else {
    iVar9 = iVar5 - (iVar14 * (uVar7 * 4 + 4) + 7 & 0xfffffff8);
    if (iVar9 < *(int *)(in_ECX + 100)) {
      local_38 = (int *)0x0;
    }
    else {
      local_38 = (int *)(*(int *)(in_ECX + 0x5c) + iVar9);
      *(int *)(in_ECX + 0x68) = iVar9;
    }
  }
  iVar9 = 0;
  piVar10 = local_38 + iVar14;
  local_28 = uVar7;
  if (0 < iVar14) {
    do {
      local_38[iVar9] = (int)piVar10;
      iVar9 = iVar9 + 1;
      piVar10 = piVar10 + uVar7;
    } while (iVar9 < iVar14);
  }
  iVar14 = 0;
  if (0 < param_1) {
    do {
      if (*(char *)(iVar14 + param_4) == '\0') {
        memset((void *)in_EDX[iVar14],0,param_2 * 4);
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 < param_1);
  }
  if ((sVar2 == 2) && (param_1 != 1)) {
    iVar14 = 0;
    if (0 < param_1) {
      do {
        if (*(char *)(iVar14 + param_4) == '\0') goto LAB_10039e4a;
        iVar14 = iVar14 + 1;
      } while (iVar14 < param_1);
    }
    if (iVar14 != param_1) {
LAB_10039e4a:
      local_18 = 0;
      do {
        iVar14 = 0;
        if (param_1 == 2) {
          if (0 < (int)local_28) {
            local_20 = 0;
            do {
              uVar7 = *local_24 * iVar14 + *(int *)(local_10 + local_14 * 8);
              local_30 = (int *)(uVar7 & 1);
              local_2c = (float *)((int)uVar7 >> 1);
              if (local_18 == 0) {
                iVar9 = (uint)*(byte *)(local_10 + 0xd + local_14 * 8) * 0x830 +
                        *(int *)(in_ECX + 0x88);
                if (*(int *)(in_ECX + 0x580) < 10) {
                  if (*(int *)(in_ECX + 0x580) == 0) {
                    *(undefined4 *)(in_ECX + 0x57c) = 0;
                  }
                  do {
                    if (*(int *)(in_ECX + 0x574) == 0) {
                      if (*(char *)(in_ECX + 0x56c) == '\0') {
                        iVar12 = FUN_10039100();
                        bVar16 = iVar12 == 0;
                        goto LAB_10039efd;
                      }
                    }
                    else {
                      bVar16 = *(char *)(in_ECX + 0x56c) == '\0';
LAB_10039efd:
                      if (bVar16) break;
                    }
                    *(char *)(in_ECX + 0x56c) = *(char *)(in_ECX + 0x56c) + -1;
                    *(int *)(in_ECX + 0x584) = *(int *)(in_ECX + 0x584) + 1;
                    pbVar6 = *(byte **)(in_ECX + 0x2c);
                    if (pbVar6 == (byte *)0x0) {
                      piVar10 = *(int **)(in_ECX + 0x20);
                      iVar12 = (**(code **)(*piVar10 + 4))();
                      if (iVar12 == 0) {
                        local_9 = 0;
                        (**(code **)(*piVar10 + 8))(&local_9,1);
                        uVar7 = (uint)local_9;
                      }
                      else {
                        *(undefined4 *)(in_ECX + 0x6c) = 1;
                        uVar7 = 0;
                      }
                    }
                    else if (pbVar6 < *(byte **)(in_ECX + 0x34)) {
                      bVar1 = *pbVar6;
                      *(byte **)(in_ECX + 0x2c) = pbVar6 + 1;
                      uVar7 = (uint)bVar1;
                    }
                    else {
                      *(undefined4 *)(in_ECX + 0x6c) = 1;
                      uVar7 = 0;
                    }
                    *(int *)(in_ECX + 0x57c) =
                         *(int *)(in_ECX + 0x57c) +
                         (uVar7 << ((byte)*(int *)(in_ECX + 0x580) & 0x1f));
                    iVar12 = *(int *)(in_ECX + 0x580) + 8;
                    *(int *)(in_ECX + 0x580) = iVar12;
                  } while (iVar12 < 0x19);
                }
                iVar12 = (int)*(short *)(iVar9 + 0x24 + (*(uint *)(in_ECX + 0x57c) & 0x3ff) * 2);
                if (iVar12 < 0) {
                  iVar12 = FUN_100393d0();
                }
                else {
                  bVar1 = *(byte *)(*(int *)(iVar9 + 8) + iVar12);
                  piVar10 = (int *)(in_ECX + 0x580);
                  *piVar10 = *piVar10 - (uint)bVar1;
                  *(uint *)(in_ECX + 0x57c) = *(uint *)(in_ECX + 0x57c) >> (bVar1 & 0x1f);
                  if (*piVar10 < 0) {
                    *(undefined4 *)(in_ECX + 0x580) = 0;
                    iVar12 = -1;
                  }
                }
                if (*(char *)(iVar9 + 0x17) != '\0') {
                  iVar12 = *(int *)(*(int *)(iVar9 + 0x828) + iVar12 * 4);
                }
                if (iVar12 == -1) goto LAB_1003a6d6;
                *(undefined4 *)(local_20 + *local_38) =
                     *(undefined4 *)(*(int *)(local_10 + 0x10 + local_14 * 8) + iVar12 * 4);
              }
              iVar9 = 0;
              if (0 < iVar3) {
                do {
                  if ((int)local_28 <= iVar14) break;
                  if (*(short *)(*(int *)(local_10 + 0x14 + local_14 * 8) +
                                (local_18 +
                                (uint)*(byte *)(*(int *)(local_20 + *local_38) + iVar9) * 8) * 2) <
                      0) {
                    uVar7 = *local_24 * iVar14 + *(int *)(local_10 + local_14 * 8) + *local_24;
                    local_30 = (int *)(uVar7 & 1);
                    local_2c = (float *)((int)uVar7 >> 1);
                  }
                  else {
                    iVar12 = FUN_10039a20(in_EDX,2,&local_30,&local_2c,param_2,*local_24);
                    if (iVar12 == 0) goto LAB_1003a6d6;
                  }
                  iVar9 = iVar9 + 1;
                  iVar14 = iVar14 + 1;
                } while (iVar9 < iVar3);
              }
              local_20 = local_20 + 4;
            } while (iVar14 < (int)local_28);
          }
        }
        else if ((2 < param_1) && (0 < (int)local_28)) {
          local_1c = (int *)0x0;
          do {
            iVar9 = *local_24 * iVar14 + *(int *)(local_10 + local_14 * 8);
            local_2c = (float *)(iVar9 / param_1);
            local_30 = (int *)(iVar9 % param_1);
            if (local_18 == 0) {
              iVar9 = (uint)*(byte *)(local_10 + 0xd + local_14 * 8) * 0x830 +
                      *(int *)(in_ECX + 0x88);
              if (*(int *)(in_ECX + 0x580) < 10) {
                if (*(int *)(in_ECX + 0x580) == 0) {
                  *(undefined4 *)(in_ECX + 0x57c) = 0;
                }
                do {
                  if (*(int *)(in_ECX + 0x574) == 0) {
                    if (*(char *)(in_ECX + 0x56c) == '\0') {
                      iVar12 = FUN_10039100();
                      bVar16 = iVar12 == 0;
                      goto LAB_1003a14d;
                    }
                  }
                  else {
                    bVar16 = *(char *)(in_ECX + 0x56c) == '\0';
LAB_1003a14d:
                    if (bVar16) break;
                  }
                  *(char *)(in_ECX + 0x56c) = *(char *)(in_ECX + 0x56c) + -1;
                  *(int *)(in_ECX + 0x584) = *(int *)(in_ECX + 0x584) + 1;
                  pbVar6 = *(byte **)(in_ECX + 0x2c);
                  if (pbVar6 == (byte *)0x0) {
                    piVar10 = *(int **)(in_ECX + 0x20);
                    iVar12 = (**(code **)(*piVar10 + 4))();
                    if (iVar12 == 0) {
                      local_9 = 0;
                      (**(code **)(*piVar10 + 8))(&local_9,1);
                      uVar7 = (uint)local_9;
                    }
                    else {
                      *(undefined4 *)(in_ECX + 0x6c) = 1;
                      uVar7 = 0;
                    }
                  }
                  else if (pbVar6 < *(byte **)(in_ECX + 0x34)) {
                    bVar1 = *pbVar6;
                    *(byte **)(in_ECX + 0x2c) = pbVar6 + 1;
                    uVar7 = (uint)bVar1;
                  }
                  else {
                    *(undefined4 *)(in_ECX + 0x6c) = 1;
                    uVar7 = 0;
                  }
                  *(int *)(in_ECX + 0x57c) =
                       *(int *)(in_ECX + 0x57c) + (uVar7 << ((byte)*(int *)(in_ECX + 0x580) & 0x1f))
                  ;
                  iVar12 = *(int *)(in_ECX + 0x580) + 8;
                  *(int *)(in_ECX + 0x580) = iVar12;
                } while (iVar12 < 0x19);
              }
              iVar12 = (int)*(short *)(iVar9 + 0x24 + (*(uint *)(in_ECX + 0x57c) & 0x3ff) * 2);
              if (iVar12 < 0) {
                iVar12 = FUN_100393d0();
              }
              else {
                bVar1 = *(byte *)(*(int *)(iVar9 + 8) + iVar12);
                piVar10 = (int *)(in_ECX + 0x580);
                *piVar10 = *piVar10 - (uint)bVar1;
                *(uint *)(in_ECX + 0x57c) = *(uint *)(in_ECX + 0x57c) >> (bVar1 & 0x1f);
                if (*piVar10 < 0) {
                  *(undefined4 *)(in_ECX + 0x580) = 0;
                  iVar12 = -1;
                }
              }
              if (*(char *)(iVar9 + 0x17) != '\0') {
                iVar12 = *(int *)(*(int *)(iVar9 + 0x828) + iVar12 * 4);
              }
              if (iVar12 == -1) goto LAB_1003a6d6;
              *(undefined4 *)((int)local_1c + *local_38) =
                   *(undefined4 *)(*(int *)(local_10 + 0x10 + local_14 * 8) + iVar12 * 4);
            }
            iVar9 = 0;
            if (0 < iVar3) {
              do {
                if ((int)local_28 <= iVar14) break;
                if (*(short *)(*(int *)(local_10 + 0x14 + local_14 * 8) +
                              (local_18 +
                              (uint)*(byte *)(*(int *)((int)local_1c + *local_38) + iVar9) * 8) * 2)
                    < 0) {
                  iVar12 = *local_24 + *local_24 * iVar14 + *(int *)(local_10 + local_14 * 8);
                  local_2c = (float *)(iVar12 / param_1);
                  local_30 = (int *)(iVar12 % param_1);
                }
                else {
                  iVar12 = FUN_10039a20(in_EDX,param_1,&local_30,&local_2c,param_2,*local_24);
                  if (iVar12 == 0) goto LAB_1003a6d6;
                }
                iVar9 = iVar9 + 1;
                iVar14 = iVar14 + 1;
              } while (iVar9 < iVar3);
            }
            local_1c = local_1c + 1;
          } while (iVar14 < (int)local_28);
        }
        local_18 = local_18 + 1;
      } while (local_18 < 8);
    }
  }
  else {
    local_34 = 0;
    uVar7 = local_28;
    do {
      iVar14 = 0;
      local_58 = 0;
      if (0 < (int)uVar7) {
        local_18 = 0;
        do {
          if ((local_34 == 0) && (local_1c = (int *)0x0, 0 < param_1)) {
            do {
              if (*(char *)((int)local_1c + param_4) == '\0') {
                iVar14 = (uint)*(byte *)(local_10 + 0xd + local_14 * 8) * 0x830 +
                         *(int *)(in_ECX + 0x88);
                if (*(int *)(in_ECX + 0x580) < 10) {
                  if (*(int *)(in_ECX + 0x580) == 0) {
                    *(undefined4 *)(in_ECX + 0x57c) = 0;
                  }
                  do {
                    if (*(int *)(in_ECX + 0x574) == 0) {
                      if (*(char *)(in_ECX + 0x56c) == '\0') {
                        iVar9 = FUN_10039100();
                        bVar16 = iVar9 == 0;
                        goto LAB_1003a3bd;
                      }
                    }
                    else {
                      bVar16 = *(char *)(in_ECX + 0x56c) == '\0';
LAB_1003a3bd:
                      if (bVar16) break;
                    }
                    *(char *)(in_ECX + 0x56c) = *(char *)(in_ECX + 0x56c) + -1;
                    *(int *)(in_ECX + 0x584) = *(int *)(in_ECX + 0x584) + 1;
                    pbVar6 = *(byte **)(in_ECX + 0x2c);
                    if (pbVar6 == (byte *)0x0) {
                      piVar10 = *(int **)(in_ECX + 0x20);
                      iVar9 = (**(code **)(*piVar10 + 4))();
                      if (iVar9 == 0) {
                        local_9 = 0;
                        (**(code **)(*piVar10 + 8))(&local_9,1);
                        uVar7 = (uint)local_9;
                      }
                      else {
                        *(undefined4 *)(in_ECX + 0x6c) = 1;
                        uVar7 = 0;
                      }
                    }
                    else if (pbVar6 < *(byte **)(in_ECX + 0x34)) {
                      bVar1 = *pbVar6;
                      *(byte **)(in_ECX + 0x2c) = pbVar6 + 1;
                      uVar7 = (uint)bVar1;
                    }
                    else {
                      *(undefined4 *)(in_ECX + 0x6c) = 1;
                      uVar7 = 0;
                    }
                    *(int *)(in_ECX + 0x57c) =
                         *(int *)(in_ECX + 0x57c) +
                         (uVar7 << ((byte)*(int *)(in_ECX + 0x580) & 0x1f));
                    iVar9 = *(int *)(in_ECX + 0x580) + 8;
                    *(int *)(in_ECX + 0x580) = iVar9;
                  } while (iVar9 < 0x19);
                }
                iVar9 = (int)*(short *)(iVar14 + 0x24 + (*(uint *)(in_ECX + 0x57c) & 0x3ff) * 2);
                if (iVar9 < 0) {
                  iVar9 = FUN_100393d0();
                }
                else {
                  bVar1 = *(byte *)(*(int *)(iVar14 + 8) + iVar9);
                  piVar10 = (int *)(in_ECX + 0x580);
                  *piVar10 = *piVar10 - (uint)bVar1;
                  *(uint *)(in_ECX + 0x57c) = *(uint *)(in_ECX + 0x57c) >> (bVar1 & 0x1f);
                  if (*piVar10 < 0) {
                    *(undefined4 *)(in_ECX + 0x580) = 0;
                    iVar9 = -1;
                  }
                }
                if (*(char *)(iVar14 + 0x17) != '\0') {
                  iVar9 = *(int *)(*(int *)(iVar14 + 0x828) + iVar9 * 4);
                }
                if (iVar9 == -1) goto LAB_1003a6d6;
                *(undefined4 *)(local_18 + local_38[(int)local_1c]) =
                     *(undefined4 *)(*(int *)(local_10 + 0x10 + local_14 * 8) + iVar9 * 4);
              }
              local_1c = (int *)((int)local_1c + 1);
              uVar7 = local_28;
              iVar14 = local_58;
            } while ((int)local_1c < param_1);
          }
          local_20 = 0;
          if (0 < iVar3) {
            do {
              if ((int)uVar7 <= iVar14) break;
              local_4c = 0;
              iVar9 = local_20;
              if (0 < param_1) {
                local_1c = in_EDX;
                do {
                  if ((*(char *)(local_4c + param_4) == '\0') &&
                     (iVar14 = (int)*(short *)(*(int *)(local_10 + 0x14 + local_14 * 8) +
                                              (local_34 +
                                              (uint)*(byte *)(*(int *)(*(int *)(((int)local_38 -
                                                                                (int)in_EDX) +
                                                                               (int)local_1c) +
                                                                      local_18) + iVar9) * 8) * 2),
                     iVar9 = local_20, -1 < iVar14)) {
                    iVar12 = *local_1c;
                    uVar7 = *local_24;
                    local_30 = (int *)(iVar14 * 0x830 + *(int *)(in_ECX + 0x88));
                    iVar14 = uVar7 * local_58 + *(int *)(local_10 + local_14 * 8);
                    if (sVar2 == 0) {
                      local_64 = 0;
                      iVar8 = (int)uVar7 / *local_30;
                      if (0 < iVar8) {
                        iVar15 = uVar7 - iVar14;
                        local_2c = (float *)(iVar12 + iVar14 * 4);
                        do {
                          iVar14 = FUN_10039630();
                          fVar18 = 0.0;
                          if (iVar14 < 0) goto LAB_1003a6d6;
                          local_60 = 0;
                          iVar9 = *local_30;
                          iVar12 = iVar9;
                          if (iVar15 <= iVar9) {
                            iVar12 = iVar15;
                          }
                          if (0 < iVar12) {
                            local_5c = iVar9 * iVar14 * 4;
                            pfVar13 = local_2c;
                            do {
                              fVar17 = *(float *)(local_30[7] + local_5c) + fVar18;
                              *pfVar13 = *pfVar13 + fVar17;
                              if (*(char *)((int)local_30 + 0x16) != '\0') {
                                fVar18 = fVar17;
                              }
                              local_5c = local_5c + 4;
                              local_60 = local_60 + 1;
                              pfVar13 = pfVar13 + iVar8;
                            } while (local_60 < iVar12);
                          }
                          iVar15 = iVar15 + -1;
                          local_2c = local_2c + 1;
                          local_64 = local_64 + 1;
                          iVar9 = local_20;
                        } while (local_64 < iVar8);
                      }
                    }
                    else {
                      local_44 = 0;
                      if (0 < (int)uVar7) {
                        do {
                          iVar9 = FUN_100397b0(iVar12 + iVar14 * 4,uVar7 - local_44);
                          if (iVar9 == 0) goto LAB_1003a6d6;
                          local_44 = local_44 + *local_30;
                          iVar14 = iVar14 + *local_30;
                          iVar9 = local_20;
                        } while (local_44 < (int)uVar7);
                      }
                    }
                  }
                  local_4c = local_4c + 1;
                  local_1c = local_1c + 1;
                  iVar14 = local_58;
                } while (local_4c < param_1);
              }
              local_20 = iVar9 + 1;
              iVar14 = iVar14 + 1;
              uVar7 = local_28;
              local_58 = iVar14;
            } while (local_20 < iVar3);
          }
          local_18 = local_18 + 4;
        } while (iVar14 < (int)uVar7);
      }
      local_34 = local_34 + 1;
    } while (local_34 < 8);
  }
LAB_1003a6d6:
  *(int *)(in_ECX + 0x68) = iVar5;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

