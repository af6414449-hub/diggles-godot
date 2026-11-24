
void FUN_1003bc80(byte *param_1,int param_2,undefined4 param_3,int param_4,int param_5,int *param_6)

{
  int *piVar1;
  ushort *puVar2;
  float fVar3;
  byte bVar4;
  byte bVar5;
  undefined2 *puVar6;
  undefined2 uVar7;
  short sVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  byte *pbVar15;
  undefined4 uVar16;
  float *pfVar17;
  int in_ECX;
  byte *extraout_ECX;
  byte *extraout_ECX_00;
  byte *extraout_ECX_01;
  byte *extraout_ECX_02;
  int iVar18;
  int *in_EDX;
  short sVar19;
  byte *pbVar20;
  int iVar21;
  int iVar22;
  undefined4 *puVar23;
  float fVar24;
  float fVar25;
  int local_974;
  int local_96c;
  uint local_95c;
  uint local_958;
  uint local_950;
  byte local_949;
  int local_948 [53];
  int aiStack_874 [203];
  int local_548 [192];
  char local_248 [256];
  undefined4 local_148 [16];
  byte local_108 [256];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar18 = *(int *)(in_ECX + 0x74 + (uint)*param_1 * 4);
  local_974 = 0;
  puVar2 = (ushort *)(*(int *)(in_ECX + 0x1a0) + (uint)param_1[1] * 0x28);
  pbVar9 = (byte *)(iVar18 >> 1);
  iVar11 = *(int *)(in_ECX + 4);
  if (0 < iVar11) {
    do {
      iVar11 = *(int *)(puVar2 + 2);
      local_948[local_974] = 0;
      uVar10 = (uint)*(byte *)(*(byte *)(local_974 * 3 + 2 + iVar11) + 9 + (int)puVar2);
      if (*(short *)(in_ECX + 0x90 + uVar10 * 2) == 0) {
        *(undefined4 *)(in_ECX + 0x70) = 0x15;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      pbVar20 = (byte *)(uVar10 * 0x63c + *(int *)(in_ECX + 0x110));
      iVar11 = FUN_100392f0();
      if (iVar11 == 0) {
LAB_1003c3f8:
        local_948[local_974] = 1;
      }
      else {
        puVar6 = *(undefined2 **)(in_ECX + 0x3f0 + local_974 * 4);
        local_950 = 2;
        iVar11 = *(int *)(&DAT_10043f6c + (uint)pbVar20[0x634] * 4);
        FUN_10038070();
        uVar7 = FUN_100392f0();
        *puVar6 = uVar7;
        FUN_10038070();
        uVar7 = FUN_100392f0();
        puVar6[1] = uVar7;
        local_96c = 0;
        if (*pbVar20 != 0) {
          do {
            uVar12 = (uint)pbVar20[local_96c + 1];
            uVar10 = 0;
            local_958 = (uint)pbVar20[uVar12 + 0x21];
            bVar4 = pbVar20[uVar12 + 0x31];
            if (bVar4 != 0) {
              iVar21 = (uint)pbVar20[uVar12 + 0x41] * 0x830 + *(int *)(in_ECX + 0x88);
              if (*(int *)(in_ECX + 0x580) < 10) {
                if (*(int *)(in_ECX + 0x580) == 0) {
                  *(undefined4 *)(in_ECX + 0x57c) = 0;
                }
                do {
                  if (((*(int *)(in_ECX + 0x574) != 0) && (*(char *)(in_ECX + 0x56c) == '\0')) ||
                     ((*(char *)(in_ECX + 0x56c) == '\0' &&
                      ((*(int *)(in_ECX + 0x574) != 0 || (iVar13 = FUN_10039100(), iVar13 == 0))))))
                  break;
                  *(char *)(in_ECX + 0x56c) = *(char *)(in_ECX + 0x56c) + -1;
                  *(int *)(in_ECX + 0x584) = *(int *)(in_ECX + 0x584) + 1;
                  pbVar15 = *(byte **)(in_ECX + 0x2c);
                  if (pbVar15 == (byte *)0x0) {
                    piVar1 = *(int **)(in_ECX + 0x20);
                    iVar13 = (**(code **)(*piVar1 + 4))();
                    if (iVar13 == 0) {
                      local_949 = 0;
                      (**(code **)(*piVar1 + 8))(&local_949,1);
                      uVar10 = (uint)local_949;
                    }
                    else {
                      *(undefined4 *)(in_ECX + 0x6c) = 1;
                      uVar10 = 0;
                    }
                  }
                  else if (pbVar15 < *(byte **)(in_ECX + 0x34)) {
                    bVar5 = *pbVar15;
                    *(byte **)(in_ECX + 0x2c) = pbVar15 + 1;
                    uVar10 = (uint)bVar5;
                  }
                  else {
                    *(undefined4 *)(in_ECX + 0x6c) = 1;
                    uVar10 = 0;
                  }
                  *(int *)(in_ECX + 0x57c) =
                       *(int *)(in_ECX + 0x57c) +
                       (uVar10 << ((byte)*(int *)(in_ECX + 0x580) & 0x1f));
                  iVar13 = *(int *)(in_ECX + 0x580) + 8;
                  *(int *)(in_ECX + 0x580) = iVar13;
                } while (iVar13 < 0x19);
              }
              uVar10 = (uint)*(short *)(iVar21 + 0x24 + (*(uint *)(in_ECX + 0x57c) & 0x3ff) * 2);
              if ((int)uVar10 < 0) {
                uVar10 = FUN_100393d0();
              }
              else {
                bVar5 = *(byte *)(*(int *)(iVar21 + 8) + uVar10);
                piVar1 = (int *)(in_ECX + 0x580);
                *piVar1 = *piVar1 - (uint)bVar5;
                *(uint *)(in_ECX + 0x57c) = *(uint *)(in_ECX + 0x57c) >> (bVar5 & 0x1f);
                if (*piVar1 < 0) {
                  *(undefined4 *)(in_ECX + 0x580) = 0;
                  uVar10 = 0xffffffff;
                }
              }
              if (*(char *)(iVar21 + 0x17) != '\0') {
                uVar10 = *(uint *)(*(int *)(iVar21 + 0x828) + uVar10 * 4);
              }
            }
            if (local_958 != 0) {
              do {
                uVar14 = uVar10 & (1 << (bVar4 & 0x1f)) - 1U;
                uVar10 = (int)uVar10 >> (bVar4 & 0x1f);
                if (*(short *)(pbVar20 + (uVar14 + uVar12 * 8) * 2 + 0x52) < 0) {
                  uVar7 = 0;
                }
                else {
                  iVar21 = *(short *)(pbVar20 + (uVar14 + uVar12 * 8) * 2 + 0x52) * 0x830 +
                           *(int *)(in_ECX + 0x88);
                  if (*(int *)(in_ECX + 0x580) < 10) {
                    if (*(int *)(in_ECX + 0x580) == 0) {
                      *(undefined4 *)(in_ECX + 0x57c) = 0;
                    }
                    do {
                      if (((*(int *)(in_ECX + 0x574) != 0) && (*(char *)(in_ECX + 0x56c) == '\0'))
                         || ((*(char *)(in_ECX + 0x56c) == '\0' &&
                             ((*(int *)(in_ECX + 0x574) != 0 ||
                              (iVar13 = FUN_10039100(), iVar13 == 0)))))) break;
                      *(char *)(in_ECX + 0x56c) = *(char *)(in_ECX + 0x56c) + -1;
                      *(int *)(in_ECX + 0x584) = *(int *)(in_ECX + 0x584) + 1;
                      pbVar15 = *(byte **)(in_ECX + 0x2c);
                      if (pbVar15 == (byte *)0x0) {
                        piVar1 = *(int **)(in_ECX + 0x20);
                        iVar13 = (**(code **)(*piVar1 + 4))();
                        if (iVar13 == 0) {
                          local_949 = 0;
                          (**(code **)(*piVar1 + 8))(&local_949,1);
                          uVar14 = (uint)local_949;
                        }
                        else {
                          *(undefined4 *)(in_ECX + 0x6c) = 1;
                          uVar14 = 0;
                        }
                      }
                      else if (pbVar15 < *(byte **)(in_ECX + 0x34)) {
                        bVar5 = *pbVar15;
                        *(byte **)(in_ECX + 0x2c) = pbVar15 + 1;
                        uVar14 = (uint)bVar5;
                      }
                      else {
                        *(undefined4 *)(in_ECX + 0x6c) = 1;
                        uVar14 = 0;
                      }
                      *(int *)(in_ECX + 0x57c) =
                           *(int *)(in_ECX + 0x57c) +
                           (uVar14 << ((byte)*(int *)(in_ECX + 0x580) & 0x1f));
                      iVar13 = *(int *)(in_ECX + 0x580) + 8;
                      *(int *)(in_ECX + 0x580) = iVar13;
                    } while (iVar13 < 0x19);
                  }
                  iVar13 = (int)*(short *)(iVar21 + 0x24 + (*(uint *)(in_ECX + 0x57c) & 0x3ff) * 2);
                  if (iVar13 < 0) {
                    iVar13 = FUN_100393d0();
                  }
                  else {
                    bVar5 = *(byte *)(*(int *)(iVar21 + 8) + iVar13);
                    piVar1 = (int *)(in_ECX + 0x580);
                    *piVar1 = *piVar1 - (uint)bVar5;
                    *(uint *)(in_ECX + 0x57c) = *(uint *)(in_ECX + 0x57c) >> (bVar5 & 0x1f);
                    if (*piVar1 < 0) {
                      *(undefined4 *)(in_ECX + 0x580) = 0;
                      iVar13 = -1;
                    }
                  }
                  if (*(char *)(iVar21 + 0x17) != '\0') {
                    iVar13 = *(int *)(*(int *)(iVar21 + 0x828) + iVar13 * 4);
                  }
                  uVar7 = (undefined2)iVar13;
                }
                local_958 = local_958 - 1;
                iVar21 = local_950 + 1;
                puVar6[local_950] = uVar7;
                local_950 = iVar21;
              } while (local_958 != 0);
            }
            local_96c = local_96c + 1;
          } while (local_96c < (int)(uint)*pbVar20);
        }
        if (*(int *)(in_ECX + 0x580) == -1) goto LAB_1003c3f8;
        iVar21 = *(int *)(pbVar20 + 0x638);
        local_248[0] = '\x01';
        local_248[1] = '\x01';
        local_95c = 2;
        if (2 < iVar21) {
          pbVar15 = pbVar20 + 0x445;
          do {
            uVar10 = (uint)pbVar15[-1];
            uVar12 = (uint)*pbVar15;
            uVar14 = (int)(short)puVar6[uVar12] - (int)(short)puVar6[uVar10];
            iVar13 = (int)(((uVar14 ^ (int)uVar14 >> 0x1f) - ((int)uVar14 >> 0x1f)) *
                          ((uint)*(ushort *)(pbVar15 + -0x2ef) -
                          (uint)*(ushort *)(pbVar20 + uVar10 * 2 + 0x152))) /
                     (int)((uint)*(ushort *)(pbVar20 + uVar12 * 2 + 0x152) -
                          (uint)*(ushort *)(pbVar20 + uVar10 * 2 + 0x152));
            iVar21 = -iVar13;
            if (-1 < (int)uVar14) {
              iVar21 = iVar13;
            }
            iVar21 = (short)puVar6[uVar10] + iVar21;
            iVar22 = iVar11 - iVar21;
            uVar14 = (uint)(short)puVar6[local_95c];
            iVar13 = iVar21;
            if (iVar22 < iVar21) {
              iVar13 = iVar22;
            }
            sVar19 = (short)iVar21;
            if (uVar14 == 0) {
              if (0xff < local_95c) goto LAB_1003c71e;
              local_248[local_95c] = '\0';
              puVar6[local_95c] = sVar19;
            }
            else {
              local_248[uVar12] = '\x01';
              local_248[uVar10] = '\x01';
              local_248[local_95c] = '\x01';
              if ((int)uVar14 < iVar13 * 2) {
                if ((uVar14 & 1) == 0) {
                  puVar6[local_95c] = (short)((int)uVar14 >> 1) + sVar19;
                }
                else {
                  puVar6[local_95c] = sVar19 - (short)((int)(uVar14 + 1) >> 1);
                }
              }
              else {
                sVar8 = puVar6[local_95c];
                if (iVar22 <= iVar21) {
                  sVar8 = ((short)iVar22 - sVar8) + -1 + sVar19;
                }
                puVar6[local_95c] = sVar8;
              }
            }
            local_95c = local_95c + 1;
            pbVar15 = pbVar15 + 2;
            iVar21 = *(int *)(pbVar20 + 0x638);
          } while ((int)local_95c < iVar21);
        }
        iVar11 = 0;
        if (0 < iVar21) {
          do {
            if (local_248[iVar11] == '\0') {
              puVar6[iVar11] = 0xffff;
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 < *(int *)(pbVar20 + 0x638));
        }
      }
      iVar11 = *(int *)(in_ECX + 4);
      local_974 = local_974 + 1;
    } while (local_974 < iVar11);
  }
  memcpy(local_548,local_948,iVar11 << 2);
  uVar10 = (uint)*puVar2;
  pbVar20 = extraout_ECX;
  if (uVar10 != 0) {
    pbVar20 = (byte *)(*(int *)(puVar2 + 2) + 1);
    do {
      bVar4 = pbVar20[-1];
      if ((local_948[bVar4] == 0) || (local_948[*pbVar20] == 0)) {
        local_948[*pbVar20] = 0;
        local_948[bVar4] = 0;
      }
      pbVar20 = pbVar20 + 3;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  local_950 = 0;
  if ((char)puVar2[4] != '\0') {
    do {
      uVar10 = 0;
      iVar11 = 0;
      if (0 < *(int *)(in_ECX + 4)) {
        iVar21 = *(int *)(puVar2 + 2);
        iVar13 = 0;
        puVar23 = (undefined4 *)(in_ECX + 0x32c);
        do {
          if (*(byte *)(iVar21 + 2 + iVar13) == local_950) {
            if (local_948[iVar11] == 0) {
              if (0xff < uVar10) {
LAB_1003c71e:
                    /* WARNING: Subroutine does not return */
                ___report_rangecheckfailure();
              }
              uVar16 = *puVar23;
              local_949 = 0;
            }
            else {
              uVar16 = 0;
              local_949 = 1;
            }
            local_108[uVar10] = local_949;
            local_148[uVar10] = uVar16;
            uVar10 = uVar10 + 1;
          }
          iVar11 = iVar11 + 1;
          iVar13 = iVar13 + 3;
          puVar23 = puVar23 + 1;
        } while (iVar11 < *(int *)(in_ECX + 4));
      }
      FUN_10039ce0(uVar10,pbVar9,*(undefined1 *)((int)puVar2 + local_950 + 0x18),local_108);
      local_950 = local_950 + 1;
      pbVar20 = extraout_ECX_00;
    } while ((int)local_950 < (int)(uint)(byte)puVar2[4]);
  }
  iVar11 = *puVar2 - 1;
  if (-1 < iVar11) {
    iVar21 = iVar11 * 3;
    do {
      pfVar17 = *(float **)(in_ECX + 0x32c + (uint)*(byte *)(*(int *)(puVar2 + 2) + 1 + iVar21) * 4)
      ;
      pbVar20 = pbVar9;
      if (0 < (int)pbVar9) {
        iVar13 = *(int *)(in_ECX + 0x32c + (uint)*(byte *)(*(int *)(puVar2 + 2) + iVar21) * 4) -
                 (int)pfVar17;
        do {
          fVar25 = *(float *)(iVar13 + (int)pfVar17);
          fVar3 = *pfVar17;
          fVar24 = fVar25;
          if (fVar25 <= 0.0) {
            if (fVar3 <= 0.0) {
              fVar24 = fVar25 - fVar3;
            }
            else {
              fVar25 = fVar25 + fVar3;
            }
          }
          else if (fVar3 <= 0.0) {
            fVar24 = fVar25 + fVar3;
          }
          else {
            fVar25 = fVar25 - fVar3;
          }
          *(float *)(iVar13 + (int)pfVar17) = fVar24;
          *pfVar17 = fVar25;
          pfVar17 = pfVar17 + 1;
          pbVar20 = pbVar20 + -1;
        } while (pbVar20 != (byte *)0x0);
      }
      iVar21 = iVar21 + -3;
      iVar11 = iVar11 + -1;
    } while (-1 < iVar11);
  }
  iVar11 = *(int *)(in_ECX + 4);
  iVar21 = 0;
  if (0 < iVar11) {
    iVar13 = 0x32c;
    do {
      if (*(int *)((int)aiStack_874 + iVar13) == 0) {
        FUN_1003b7c0(iVar21,iVar18,*(undefined4 *)(in_ECX + iVar13),
                     *(undefined4 *)(in_ECX + 0xc4 + iVar13),pbVar20);
        pbVar20 = extraout_ECX_02;
      }
      else {
        memset(*(void **)(in_ECX + iVar13),0,(int)pbVar9 << 2);
        pbVar20 = extraout_ECX_01;
      }
      iVar11 = *(int *)(in_ECX + 4);
      iVar21 = iVar21 + 1;
      iVar13 = iVar13 + 4;
    } while (iVar21 < iVar11);
  }
  iVar21 = 0;
  if (0 < iVar11) {
    do {
      FUN_1003af80(in_ECX,*param_1);
      iVar21 = iVar21 + 1;
    } while (iVar21 < *(int *)(in_ECX + 4));
  }
  FUN_10039250();
  if (*(char *)(in_ECX + 0x56d) == '\0') {
    iVar18 = *(int *)(in_ECX + 0x590);
    if (iVar18 != 0) {
      if (iVar18 < param_4 - param_2) {
        param_2 = param_2 + iVar18;
        *param_6 = param_2;
        *(undefined4 *)(in_ECX + 0x590) = 0;
      }
      else {
        *(int *)(in_ECX + 0x590) = (iVar18 - param_4) + param_2;
        *param_6 = param_4;
        param_2 = param_4;
      }
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0x434) = 1;
    *(int *)(in_ECX + 0x430) = -(int)pbVar9;
    *(undefined1 *)(in_ECX + 0x56d) = 0;
    *(int *)(in_ECX + 0x590) = iVar18 - param_5;
  }
  if (*(int *)(in_ECX + 0x578) == *(int *)(in_ECX + 0x588)) {
    if (((*(int *)(in_ECX + 0x434) != 0) && ((*(byte *)(in_ECX + 0x56b) & 4) != 0)) &&
       (*(uint *)(in_ECX + 0x58c) < (uint)((*(int *)(in_ECX + 0x430) - param_2) + param_5))) {
      iVar18 = 0;
      if (*(uint *)(in_ECX + 0x430) <= *(uint *)(in_ECX + 0x58c)) {
        iVar18 = *(uint *)(in_ECX + 0x58c) - *(uint *)(in_ECX + 0x430);
      }
      iVar18 = iVar18 + param_2;
      *in_EDX = iVar18;
      if (param_5 < iVar18) {
        *in_EDX = param_5;
        iVar18 = param_5;
      }
      *(int *)(in_ECX + 0x430) = *(int *)(in_ECX + 0x430) + iVar18;
      goto LAB_1003c708;
    }
    *(undefined4 *)(in_ECX + 0x434) = 1;
    *(int *)(in_ECX + 0x430) = (*(int *)(in_ECX + 0x58c) - (int)pbVar9) + param_2;
  }
  if (*(int *)(in_ECX + 0x434) != 0) {
    *(int *)(in_ECX + 0x430) = *(int *)(in_ECX + 0x430) + (param_4 - param_2);
  }
  *in_EDX = param_5;
LAB_1003c708:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

