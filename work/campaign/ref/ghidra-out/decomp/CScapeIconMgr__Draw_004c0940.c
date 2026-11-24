
void CScapeIconMgr__Draw(void)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  float *pfVar5;
  undefined4 *puVar6;
  float *pfVar7;
  int *piVar8;
  int iVar9;
  undefined4 *in_ECX;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  code *pcVar13;
  float fVar14;
  float fVar15;
  undefined8 uVar16;
  undefined4 **ppuVar17;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 *local_50;
  undefined4 *local_4c;
  int *local_48;
  int *local_44;
  byte *local_40;
  float *local_3c;
  float *local_38;
  float local_34;
  uint local_30;
  float local_2c;
  float local_28;
  float local_24;
  uint local_20;
  float local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fe6bd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_18 = in_ECX;
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c8aea4) &&
     (FUN_006cebf4(&DAT_00c8aea4,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00c8aea4 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00c8aea8 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "CScapeIconMgr::Draw()";
    *(int *)(&DAT_00773650 + iVar9) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00c8aea4);
  }
  iVar9 = DAT_00c8aea8;
  local_50 = &DAT_00c8aea8;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00c8aea8 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar3 == 0) {
    uVar16 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar16;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004c2820();
  piVar11 = in_ECX + 0xe;
  local_30 = *(uint *)(DAT_00772400 + 100);
  local_20 = 0;
  iVar3 = DAT_0077241c;
  pcVar13 = RaiseException_exref;
  do {
    uVar12 = local_20;
    if (local_20 < 0x80) {
      piVar8 = piVar11 + local_20 * 8;
    }
    else {
      (*pcVar13)(0xc000008c,1,0,0);
      piVar8 = piVar11;
      iVar3 = DAT_0077241c;
    }
    if (piVar8[1] != -1) {
      if (uVar12 < 0x80) {
        piVar8 = piVar11 + uVar12 * 8;
      }
      else {
        (*pcVar13)(0xc000008c,1,0,0);
        piVar8 = piVar11;
        iVar3 = DAT_0077241c;
      }
      local_34 = *(float *)(*piVar8 + 0xc);
      local_3c = *(float **)(*piVar8 + 0x10);
      if ((((*(float *)(iVar3 + 0xa4) + 1.0 <= local_34) &&
           (local_34 < *(float *)(iVar3 + 0xac) - 1.0)) &&
          (*(float *)(iVar3 + 0xa8) + 1.0 <= (float)local_3c)) &&
         ((float)local_3c < *(float *)(iVar3 + 0xb0) - 1.0)) {
        local_2c = (float)(int)(float)local_3c;
        local_38 = (float *)(int)local_34;
        iVar3 = FUN_00592f10(local_38,local_2c);
        local_40 = (byte *)(iVar3 + 0x34);
        if (local_30 < 8) {
          pbVar4 = local_40 + local_30;
        }
        else {
          (*pcVar13)(0xc000008c,1,0,0);
          pbVar4 = local_40;
        }
        if (*pbVar4 < 0x81) {
          local_3c = (float *)(int)((float)local_3c + 1.0);
          iVar3 = FUN_00592f10(local_38,local_3c);
          local_40 = (byte *)(iVar3 + 0x34);
          if (local_30 < 8) {
            pbVar4 = local_40 + local_30;
          }
          else {
            (*pcVar13)(0xc000008c,1,0,0);
            pbVar4 = local_40;
          }
          if (*pbVar4 < 0x81) {
            local_38 = (float *)(int)(local_34 + 1.0);
            iVar3 = FUN_00592f10(local_38,local_2c);
            local_40 = (byte *)(iVar3 + 0x34);
            if (local_30 < 8) {
              pbVar4 = local_40 + local_30;
            }
            else {
              (*pcVar13)(0xc000008c,1,0,0);
              pbVar4 = local_40;
            }
            if (*pbVar4 < 0x81) {
              iVar3 = FUN_00592f10(local_38,local_3c);
              local_40 = (byte *)(iVar3 + 0x34);
              if (local_30 < 8) {
                pbVar4 = local_40 + local_30;
              }
              else {
                (*pcVar13)(0xc000008c,1,0,0);
                pbVar4 = local_40;
              }
              iVar3 = DAT_0077241c;
              if (*pbVar4 < 0x81) goto LAB_004c15ad;
            }
          }
        }
        pfVar5 = (float *)FUN_006ba810(0x19);
        pfVar5[1] = 2.8026e-44;
        pfVar5[2] = -NAN;
        *(undefined1 *)(pfVar5 + 3) = 0;
        *pfVar5 = 1.4013e-45;
        local_8._0_1_ = 1;
        local_3c = pfVar5;
        local_38 = pfVar5;
        if (uVar12 < 0x80) {
          piVar8 = piVar11 + uVar12 * 8;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar8 = piVar11;
        }
        if (piVar8[1] == 5) {
          if (uVar12 < 0x80) {
            piVar8 = piVar11 + uVar12 * 8;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar8 = piVar11;
          }
          if (piVar8[2] < (int)local_18[0xd]) goto LAB_004c0c7d;
        }
        else {
LAB_004c0c7d:
          if (uVar12 < 0x80) {
            piVar8 = piVar11 + uVar12 * 8;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar8 = piVar11;
          }
          if (piVar8[1] == 5) {
            if (uVar12 < 0x80) {
              piVar8 = piVar11 + uVar12 * 8;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar8 = piVar11;
            }
            local_40 = (byte *)piVar8[2];
            if ((uint)local_18[0xd] <= local_40) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            local_40 = (byte *)(*(int *)(local_18[0xc] + (int)local_40 * 8) + 0xc);
            if (uVar12 < 0x80) {
              iVar3 = *(int *)(piVar11[uVar12 * 8] + 0xd8);
              piVar8 = piVar11 + uVar12 * 8;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar3 = *(int *)(*piVar11 + 0xd8);
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar8 = piVar11;
              uVar12 = local_20;
            }
            local_40 = (byte *)FUN_006b90d0(&local_44,"ScapeIcon Type %d Obj %s ClassText %s",
                                            piVar8[1],iVar3 + 0xc,local_40);
            local_8._0_1_ = 2;
            pfVar5 = *(float **)local_40;
            if (pfVar5 != (float *)0x0) {
              *pfVar5 = (float)((int)*pfVar5 + 1);
            }
            *local_38 = (float)((int)*local_38 + -1);
            local_3c = pfVar5;
            if (*local_38 == 0.0) {
              FUN_006ba940();
            }
            pfVar5[2] = *(float *)(*(int *)local_40 + 8);
            local_8 = CONCAT31(local_8._1_3_,3);
            piVar8 = local_44;
          }
          else {
            if (uVar12 < 0x80) {
              iVar3 = *(int *)(piVar11[uVar12 * 8] + 0xd8);
              piVar8 = piVar11 + uVar12 * 8;
              piVar10 = piVar11 + uVar12 * 8;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar3 = *(int *)(*piVar11 + 0xd8);
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar8 = piVar11;
              piVar10 = piVar11;
              uVar12 = local_20;
            }
            local_40 = (byte *)FUN_006b90d0(&local_48,"ScapeIcon Type %d Obj %s ClassText %d",
                                            piVar10[1],iVar3 + 0xc,piVar8[2]);
            local_8._0_1_ = 4;
            pfVar5 = *(float **)local_40;
            if (pfVar5 != (float *)0x0) {
              *pfVar5 = (float)((int)*pfVar5 + 1);
            }
            *local_38 = (float)((int)*local_38 + -1);
            local_3c = pfVar5;
            if (*local_38 == 0.0) {
              FUN_006ba940();
            }
            pfVar5[2] = *(float *)(*(int *)local_40 + 8);
            local_8 = CONCAT31(local_8._1_3_,5);
            piVar8 = local_48;
          }
          if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 == 0)) {
            FUN_006ba940();
          }
          pfVar7 = pfVar5 + 3;
          local_8._0_1_ = 1;
          ppuVar17 = &local_14;
          FUN_0044d010(ppuVar17,pfVar7);
          FUN_0044d570(ppuVar17,pfVar7);
          local_8._0_1_ = 6;
          if (local_14 != (undefined4 *)0x0) {
            local_14[3] = 4;
            local_14[2] = 0x1a;
            local_14[4] = 0xf;
            local_14[5] = 0xff;
            if (uVar12 < 0x80) {
              piVar8 = piVar11 + uVar12 * 8;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar8 = piVar11;
            }
            if (piVar8[1] == 5) {
              if (uVar12 < 0x80) {
                piVar8 = piVar11 + uVar12 * 8;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar8 = piVar11;
              }
              local_40 = (byte *)piVar8[2];
              if ((uint)local_18[0xd] <= local_40) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              pbVar4 = local_40;
              local_40 = (byte *)0x0;
              local_14[0xf] = *(undefined4 *)(local_18[0xc] + 4 + (int)pbVar4 * 8);
            }
            else {
              if (uVar12 < 0x80) {
                piVar8 = piVar11 + uVar12 * 8;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar8 = piVar11;
              }
              if ((uint)piVar8[1] < 6) {
                puVar6 = local_18 + piVar8[1];
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                puVar6 = local_18;
              }
              local_14[0xf] = *puVar6;
              if (uVar12 < 0x80) {
                piVar8 = piVar11 + uVar12 * 8;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar8 = piVar11;
              }
              local_40 = (byte *)piVar8[2];
            }
            local_14[0xe] = 0;
            local_14[0xd] = 0;
            local_14[0xc] = 0;
            local_14[0xb] = 0;
            local_14[10] = 0;
            local_14[9] = 0;
            local_14[8] = 0;
            local_14[7] = 0;
            local_14[6] = 0;
            local_4c = (undefined4 *)FUN_006ba810(0xcc);
            if (local_4c == (undefined4 *)0x0) {
              puVar6 = (undefined4 *)local_14[0x11];
              local_14[0x11] = 0;
            }
            else {
              iVar3 = FUN_0045fae0();
              puVar6 = (undefined4 *)local_14[0x11];
              local_14[0x11] = iVar3;
              if (iVar3 != 0) {
                LOCK();
                *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
                UNLOCK();
              }
            }
            if (puVar6 != (undefined4 *)0x0) {
              LOCK();
              iVar3 = puVar6[1] + -1;
              puVar6[1] = iVar3;
              UNLOCK();
              if (iVar3 == 0) {
                (**(code **)*puVar6)(1);
              }
            }
            FUN_0045fd00(0x1c4,4,0);
            local_38 = (float *)local_14[0x11];
            if ((local_38[10] != 0.0) && (*(char *)((int)local_38 + 9) == '\0')) {
              FUN_006ba940();
            }
            local_38[10] = (float)&DAT_00767968;
            local_38[0xb] = 8.40779e-45;
            *(undefined1 *)((int)local_38 + 9) = 1;
            if (uVar12 < 0x80) {
              local_1c = (float)piVar11[uVar12 * 8 + 4];
              local_28 = (float)piVar11[uVar12 * 8 + 5];
              local_2c = (float)piVar11[uVar12 * 8 + 6];
              piVar8 = piVar11 + uVar12 * 8;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_1c = (float)in_ECX[0x12];
              local_28 = (float)in_ECX[0x13];
              local_2c = (float)in_ECX[0x14];
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar8 = piVar11;
            }
            if (*piVar8 != 0) {
              if (uVar12 < 0x80) {
                piVar8 = piVar11 + uVar12 * 8;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar8 = piVar11;
              }
              if (*(int *)(*piVar8 + 0x39c) != -1) {
                if (uVar12 < 0x80) {
                  piVar8 = piVar11 + uVar12 * 8;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar8 = piVar11;
                }
                if ((*(uint *)(*piVar8 + 0x3d0) & 0x4000) == 0) {
                  if (uVar12 < 0x80) {
                    piVar8 = piVar11 + uVar12 * 8;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar8 = piVar11;
                  }
                  local_38 = (float *)(DAT_00772400 + 0x5c8);
                  if (*(uint *)(*piVar8 + 0x39c) < 0x100) {
                    pfVar7 = local_38 + *(uint *)(*piVar8 + 0x39c);
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar7 = local_38;
                  }
                  local_24 = *pfVar7;
                  if (local_24 != 0.0) {
                    if (uVar12 < 0x80) {
                      piVar8 = piVar11 + uVar12 * 8;
                    }
                    else {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      piVar8 = piVar11;
                    }
                    if (*(int *)(*piVar8 + 0x3a0) < *(int *)((int)local_24 + 0x3c)) {
                      if (uVar12 < 0x80) {
                        piVar8 = piVar11 + uVar12 * 8;
                      }
                      else {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        piVar8 = piVar11;
                      }
                      if (-1 < *(int *)(*piVar8 + 0x3a0)) {
                        if (uVar12 < 0x80) {
                          piVar8 = piVar11 + uVar12 * 8;
                        }
                        else {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          piVar8 = piVar11;
                        }
                        iVar3 = *(int *)(*piVar8 + 0x3a0);
                        if ((iVar3 < 0) || (*(int *)((int)local_24 + 0x38) <= iVar3)) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          iVar3 = *(int *)((int)local_24 + 0x34);
                        }
                        else {
                          iVar3 = iVar3 * 0xe8 + *(int *)((int)local_24 + 0x34);
                        }
                        local_38 = *(float **)(iVar3 + 0x48);
                        local_34 = *(float *)(iVar3 + 0x44);
                        local_4c = *(undefined4 **)(iVar3 + 0x4c);
                        if (uVar12 < 0x80) {
                          piVar8 = piVar11 + uVar12 * 8;
                        }
                        else {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          piVar8 = piVar11;
                        }
                        iVar3 = *(int *)(*piVar8 + 0x3a0);
                        if ((iVar3 < 0) || (*(int *)((int)local_24 + 0x38) <= iVar3)) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          iVar3 = *(int *)((int)local_24 + 0x34);
                        }
                        else {
                          iVar3 = iVar3 * 0xe8 + *(int *)((int)local_24 + 0x34);
                        }
                        local_24 = (*(float *)(iVar3 + 0x58) + (float)local_4c) * 0.5;
                        local_34 = (local_34 + *(float *)(iVar3 + 0x50)) * 0.5;
                        if (uVar12 < 0x80) {
                          piVar8 = piVar11 + uVar12 * 8;
                        }
                        else {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          piVar8 = piVar11;
                        }
                        iVar3 = *piVar8;
                        puVar6 = *(undefined4 **)(iVar3 + 0x44);
                        FUN_004089d0();
                        fVar14 = *(float *)(iVar3 + 0x44);
                        local_4c = puVar6;
                        FUN_004089f0();
                        fVar15 = local_24 * fVar14 + local_34 * (float)local_4c;
                        local_38 = (float *)((float)local_38 * 0.005 + local_28);
                        local_1c = local_1c +
                                   (fVar14 * local_34 - local_24 * (float)local_4c) * 0.005;
                        local_24 = (fVar15 + fVar15) * 0.005 + local_2c;
                        if (local_20 < 0x80) {
                          piVar8 = piVar11 + local_20 * 8;
                        }
                        else {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          piVar8 = piVar11;
                        }
                        iVar3 = *piVar8;
                        local_1c = local_1c + *(float *)(iVar3 + 0xc);
                        local_28 = *(float *)(iVar3 + 0x10) + (float)local_38;
                        local_2c = *(float *)(iVar3 + 0x14) + local_24;
                      }
                    }
                  }
                }
                else {
                  if (uVar12 < 0x80) {
                    piVar8 = piVar11 + uVar12 * 8;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar8 = piVar11;
                  }
                  iVar3 = *piVar8;
                  local_1c = *(float *)(iVar3 + 0xc) + 0.0;
                  local_28 = *(float *)(iVar3 + 0x10) - 0.25;
                  local_2c = *(float *)(iVar3 + 0x14) + 0.7;
                }
              }
            }
            uVar1 = *(undefined4 *)(local_14[0x11] + 0x24);
            local_58 = FUN_0045feb0();
            uVar12 = local_20;
            local_54 = uVar1;
            if (local_20 < 0x80) {
              piVar8 = piVar11 + local_20 * 8;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar8 = piVar11;
            }
            iVar3 = piVar8[7];
            pbVar4 = local_40;
            if (uVar12 < 0x80) {
              piVar8 = piVar11 + uVar12 * 8;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar8 = piVar11;
            }
            cVar2 = FUN_004c0180(&local_58,local_1c,local_28,local_2c,piVar8[1],pbVar4,iVar3);
            puVar6 = local_14;
            if (cVar2 != '\0') {
              local_4c = local_14;
              if (local_14 != (undefined4 *)0x0) {
                LOCK();
                local_14[1] = local_14[1] + 1;
                UNLOCK();
              }
              local_8._0_1_ = 7;
              FUN_0044d010();
              local_8._0_1_ = 8;
              if (puVar6 != (undefined4 *)0x0) {
                LOCK();
                puVar6[1] = puVar6[1] + 1;
                UNLOCK();
              }
              FUN_00450720(puVar6);
              local_8._0_1_ = 6;
              if (puVar6 != (undefined4 *)0x0) {
                LOCK();
                iVar3 = puVar6[1] + -1;
                puVar6[1] = iVar3;
                UNLOCK();
                if (iVar3 == 0) {
                  (**(code **)*puVar6)(1);
                }
              }
            }
            iVar3 = local_14[0x11];
            piVar8 = (int *)(iVar3 + 0x10);
            *piVar8 = *piVar8 + -1;
            if ((*piVar8 == 0) && (*(int **)(iVar3 + 0x14) != (int *)0x0)) {
              piVar8 = (int *)**(int **)(iVar3 + 0x14);
              if (piVar8 != (int *)0x0) {
                (**(code **)(*piVar8 + 0x18))();
              }
              *(undefined4 *)(iVar3 + 0xc) = 0;
            }
            if (local_14 != (undefined4 *)0x0) {
              LOCK();
              iVar3 = local_14[1] + -1;
              local_14[1] = iVar3;
              UNLOCK();
              if ((iVar3 == 0) && (local_14 != (undefined4 *)0x0)) {
                (**(code **)*local_14)(1);
              }
            }
          }
        }
        local_8._0_1_ = 9;
        if ((pfVar5 != (float *)0x0) && (*pfVar5 = (float)((int)*pfVar5 + -1), *pfVar5 == 0.0)) {
          FUN_006ba940();
        }
        local_8 = (uint)local_8._1_3_ << 8;
        iVar3 = DAT_0077241c;
        uVar12 = local_20;
        pcVar13 = RaiseException_exref;
      }
    }
LAB_004c15ad:
    local_20 = uVar12 + 1;
    if (0x7f < (int)local_20) {
      FUN_0043fd30();
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

