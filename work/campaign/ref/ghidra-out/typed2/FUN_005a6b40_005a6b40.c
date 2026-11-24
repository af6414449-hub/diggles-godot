
void FUN_005a6b40(int *param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  byte *pbVar14;
  byte *pbVar15;
  undefined1 *puVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  byte local_c1;
  undefined1 local_b8;
  uint local_64;
  uint local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  iVar2 = PTR_0077241c->x0_8 + 0x18;
  iVar21 = *param_1;
  if (*param_1 <= iVar2) {
    iVar21 = iVar2;
  }
  iVar3 = PTR_0077241c->y0_8 + 0x10;
  iVar2 = param_1[1];
  if (param_1[1] <= iVar3) {
    iVar2 = iVar3;
  }
  iVar4 = PTR_0077241c->x1_8 + -0x18;
  iVar3 = param_1[2];
  if (iVar4 <= param_1[2]) {
    iVar3 = iVar4;
  }
  iVar5 = PTR_0077241c->y1_8 + -0x18;
  iVar4 = param_1[3];
  if (iVar5 <= param_1[3]) {
    iVar4 = iVar5;
  }
  if ((iVar21 < iVar3) && (iVar2 < iVar4)) {
    local_4c = iVar21 + -8;
    local_40 = iVar4 + 2;
    local_48 = iVar2 + -0x10;
    local_44 = iVar3 + 8;
    iVar5 = local_44 - local_4c;
    iVar22 = (local_40 - local_48) * iVar5;
    pbVar6 = (byte *)FUN_006ba810(0x405);
    FUN_00595e40(pbVar6,&local_4c);
    local_34 = iVar3 - iVar21;
    local_2c = (iVar4 - iVar2) * local_34;
    local_20 = iVar21;
    iStack_1c = iVar2;
    iStack_18 = iVar3;
    iStack_14 = iVar4;
    puVar7 = (undefined1 *)FUN_006ba810(0x40d);
    iVar4 = iVar4 - local_48;
    iVar8 = iVar2 - local_48;
    local_50 = 0xfffffc18;
    local_64 = 0xfffffc18;
    if (iVar8 < iVar4) {
      local_3c = iVar21 - local_4c;
      iVar3 = iVar3 - local_4c;
      do {
        if (local_3c < iVar3) {
          iVar17 = iVar8 * iVar5;
          local_28 = local_48 + iVar8;
          local_38 = local_28 - iVar2;
          uVar18 = iVar8 + 4U & 0xfffffff8;
          iVar20 = local_3c;
          do {
            local_30 = (local_4c + iVar20) - iVar21;
            uVar23 = iVar20 + 4U & 0xfffffff8;
            if ((uVar23 != local_64) || (uVar18 != local_50)) {
              iVar9 = FUN_00592f10(PTR_0077241c);
              local_c1 = ~(*(byte *)(iVar9 + 0x18) >> 7) & 1;
              local_64 = uVar23;
              local_50 = uVar18;
            }
            local_b8 = 0;
            if (local_c1 != 0) {
              iVar10 = (iVar8 + -8) * iVar5;
              iVar9 = iVar10 + iVar20;
              if ((iVar9 < 0) || (iVar22 <= iVar9)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pbVar15 = pbVar6;
              }
              else {
                pbVar15 = pbVar6 + iVar20 + iVar10;
              }
              if (*pbVar15 < 0xe) {
                iVar19 = (iVar8 + -0xf) * iVar5;
                iVar13 = iVar19 + iVar20;
                if ((iVar13 + -7 < 0) || (iVar22 <= iVar13 + -7)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pbVar15 = pbVar6;
                }
                else {
                  pbVar15 = pbVar6 + iVar20 + iVar19 + -7;
                }
                if (*pbVar15 < 0xe) {
                  if ((iVar13 + 7 < 0) || (iVar22 <= iVar13 + 7)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pbVar15 = pbVar6;
                  }
                  else {
                    pbVar15 = pbVar6 + iVar20 + iVar19 + 7;
                  }
                  if (*pbVar15 < 0xe) {
                    if ((iVar13 < 0) || (iVar22 <= iVar13)) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      pbVar15 = pbVar6;
                    }
                    else {
                      pbVar15 = pbVar6 + iVar20 + iVar19;
                    }
                    if (*pbVar15 < 0xe) {
                      iVar11 = (iVar8 + -1) * iVar5;
                      if ((iVar11 + iVar20 < 0) || (iVar22 <= iVar11 + iVar20)) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        pbVar15 = pbVar6;
                      }
                      else {
                        pbVar15 = pbVar6 + iVar20 + iVar11;
                      }
                      if (*pbVar15 < 0xe) {
                        if ((iVar9 + -7 < 0) || (iVar22 <= iVar9 + -7)) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          pbVar15 = pbVar6;
                        }
                        else {
                          pbVar15 = pbVar6 + iVar20 + iVar10 + -7;
                        }
                        if (*pbVar15 < 0xe) {
                          iVar12 = iVar10 + iVar20 + 7;
                          if ((iVar12 < 0) || (iVar22 <= iVar12)) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            pbVar15 = pbVar6;
                          }
                          else {
                            pbVar15 = pbVar6 + iVar20 + iVar10 + 7;
                          }
                          if (*pbVar15 < 0xe) {
                            iVar24 = (iVar8 + -3) * iVar5;
                            iVar12 = iVar24 + -4 + iVar20;
                            if ((iVar12 < 0) || (iVar22 <= iVar12)) {
                              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                              pbVar15 = pbVar6;
                            }
                            else {
                              pbVar15 = pbVar6 + iVar20 + iVar24 + -4;
                            }
                            if (*pbVar15 < 0xe) {
                              iVar12 = iVar24 + 4 + iVar20;
                              if ((iVar12 < 0) || (iVar22 <= iVar12)) {
                                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                pbVar15 = pbVar6;
                              }
                              else {
                                pbVar15 = pbVar6 + iVar20 + iVar24 + 4;
                              }
                              if (*pbVar15 < 0xe) {
                                iVar12 = (iVar8 + -5) * iVar5;
                                iVar24 = iVar12 + iVar20;
                                if ((iVar24 + -7 < 0) || (iVar22 <= iVar24 + -7)) {
                                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                  pbVar15 = pbVar6;
                                }
                                else {
                                  pbVar15 = pbVar6 + iVar20 + iVar12 + -7;
                                }
                                if (*pbVar15 < 0xe) {
                                  if ((iVar24 + 7 < 0) || (iVar22 <= iVar24 + 7)) {
                                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                    pbVar15 = pbVar6;
                                  }
                                  else {
                                    pbVar15 = pbVar6 + iVar20 + iVar12 + 7;
                                  }
                                  if (*pbVar15 < 0xe) {
                                    iVar25 = (iVar8 + -0xc) * iVar5;
                                    local_24 = iVar25 + iVar20;
                                    if ((local_24 + -7 < 0) || (iVar22 <= local_24 + -7)) {
                                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                      pbVar15 = pbVar6;
                                    }
                                    else {
                                      pbVar15 = pbVar6 + iVar20 + iVar25 + -7;
                                    }
                                    if (*pbVar15 < 0xe) {
                                      if ((local_24 + 7 < 0) || (iVar22 <= local_24 + 7)) {
                                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                        pbVar15 = pbVar6;
                                      }
                                      else {
                                        pbVar15 = pbVar6 + iVar20 + iVar25 + 7;
                                      }
                                      if (*pbVar15 < 0xe) {
                                        if ((iVar13 + -4 < 0) || (iVar22 <= iVar13 + -4)) {
                                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                          pbVar15 = pbVar6;
                                        }
                                        else {
                                          pbVar15 = pbVar6 + iVar20 + iVar19 + -4;
                                        }
                                        if (*pbVar15 < 0xe) {
                                          iVar13 = iVar19 + iVar20 + 4;
                                          if ((iVar13 < 0) || (iVar22 <= iVar13)) {
                                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                            pbVar15 = pbVar6;
                                          }
                                          else {
                                            pbVar15 = pbVar6 + iVar20 + iVar19 + 4;
                                          }
                                          if (*pbVar15 < 0xe) {
                                            if ((iVar25 + iVar20 < 0) || (iVar22 <= iVar25 + iVar20)
                                               ) {
                                              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                              pbVar15 = pbVar6;
                                            }
                                            else {
                                              pbVar15 = pbVar6 + iVar20 + iVar25;
                                            }
                                            if (*pbVar15 < 0xe) {
                                              iVar19 = (iVar8 + -4) * iVar5;
                                              iVar13 = iVar19 + iVar20;
                                              if ((iVar13 < 0) || (iVar22 <= iVar13)) {
                                                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                                pbVar15 = pbVar6;
                                              }
                                              else {
                                                pbVar15 = pbVar6 + iVar20 + iVar19;
                                              }
                                              if (*pbVar15 < 0xe) {
                                                if ((iVar9 + -4 < 0) || (iVar22 <= iVar9 + -4)) {
                                                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                                  pbVar15 = pbVar6;
                                                }
                                                else {
                                                  pbVar15 = pbVar6 + iVar20 + iVar10 + -4;
                                                }
                                                if (*pbVar15 < 0xe) {
                                                  iVar9 = iVar10 + iVar20 + 4;
                                                  if ((iVar9 < 0) || (iVar22 <= iVar9)) {
                                                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                                    pbVar15 = pbVar6;
                                                  }
                                                  else {
                                                    pbVar15 = pbVar6 + iVar20 + iVar10 + 4;
                                                  }
                                                  if (*pbVar15 < 0xe) {
                                                    iVar10 = (iVar8 + -0xd) * iVar5;
                                                    iVar9 = iVar10 + -3 + iVar20;
                                                    if ((iVar9 < 0) || (iVar22 <= iVar9)) {
                                                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0
                                                                    );
                                                      pbVar15 = pbVar6;
                                                    }
                                                    else {
                                                      pbVar15 = pbVar6 + iVar20 + iVar10 + -3;
                                                    }
                                                    if (*pbVar15 < 0xe) {
                                                      iVar9 = iVar10 + 3 + iVar20;
                                                      if ((iVar9 < 0) || (iVar22 <= iVar9)) {
                                                        RaiseException(0xc000008c,1,0,
                                                                       (ULONG_PTR *)0x0);
                                                        pbVar15 = pbVar6;
                                                      }
                                                      else {
                                                        pbVar15 = pbVar6 + iVar20 + iVar10 + 3;
                                                      }
                                                      if (*pbVar15 < 0xe) {
                                                        iVar10 = (iVar8 + -0xb) * iVar5;
                                                        iVar9 = iVar10 + iVar20;
                                                        if ((iVar9 + -5 < 0) ||
                                                           (iVar22 <= iVar9 + -5)) {
                                                          RaiseException(0xc000008c,1,0,
                                                                         (ULONG_PTR *)0x0);
                                                          pbVar15 = pbVar6;
                                                        }
                                                        else {
                                                          pbVar15 = pbVar6 + iVar20 + iVar10 + -5;
                                                        }
                                                        if (*pbVar15 < 0xe) {
                                                          if ((iVar9 + 5 < 0) ||
                                                             (iVar22 <= iVar9 + 5)) {
                                                            RaiseException(0xc000008c,1,0,
                                                                           (ULONG_PTR *)0x0);
                                                            pbVar15 = pbVar6;
                                                          }
                                                          else {
                                                            pbVar15 = pbVar6 + iVar20 + iVar10 + 5;
                                                          }
                                                          if (*pbVar15 < 0xe) {
                                                            iVar19 = (iVar8 + -10) * iVar5;
                                                            iVar13 = iVar19 + iVar20;
                                                            if ((iVar13 + -2 < 0) ||
                                                               (iVar22 <= iVar13 + -2)) {
                                                              RaiseException(0xc000008c,1,0,
                                                                             (ULONG_PTR *)0x0);
                                                              pbVar15 = pbVar6;
                                                            }
                                                            else {
                                                              pbVar15 = pbVar6 + iVar20 + iVar19 + 
                                                  -2;
                                                  }
                                                  if (*pbVar15 < 0xe) {
                                                    if ((iVar13 + 2 < 0) || (iVar22 <= iVar13 + 2))
                                                    {
                                                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0
                                                                    );
                                                      pbVar15 = pbVar6;
                                                    }
                                                    else {
                                                      pbVar15 = pbVar6 + iVar20 + iVar19 + 2;
                                                    }
                                                    if (*pbVar15 < 0xe) {
                                                      iVar25 = (iVar8 + -6) * iVar5;
                                                      iVar19 = iVar25 + -2 + iVar20;
                                                      if ((iVar19 < 0) || (iVar22 <= iVar19)) {
                                                        RaiseException(0xc000008c,1,0,
                                                                       (ULONG_PTR *)0x0);
                                                        pbVar15 = pbVar6;
                                                      }
                                                      else {
                                                        pbVar15 = pbVar6 + iVar20 + iVar25 + -2;
                                                      }
                                                      if (*pbVar15 < 0xe) {
                                                        iVar19 = iVar25 + 2 + iVar20;
                                                        if ((iVar19 < 0) || (iVar22 <= iVar19)) {
                                                          RaiseException(0xc000008c,1,0,
                                                                         (ULONG_PTR *)0x0);
                                                          pbVar15 = pbVar6;
                                                        }
                                                        else {
                                                          pbVar15 = pbVar6 + iVar20 + iVar25 + 2;
                                                        }
                                                        if (*pbVar15 < 0xe) {
                                                          if ((iVar24 + -5 < 0) ||
                                                             (iVar22 <= iVar24 + -5)) {
                                                            RaiseException(0xc000008c,1,0,
                                                                           (ULONG_PTR *)0x0);
                                                            pbVar15 = pbVar6;
                                                          }
                                                          else {
                                                            pbVar15 = pbVar6 + iVar20 + iVar12 + -5;
                                                          }
                                                          if (*pbVar15 < 0xe) {
                                                            if ((iVar24 + 5 < 0) ||
                                                               (iVar22 <= iVar24 + 5)) {
                                                              RaiseException(0xc000008c,1,0,
                                                                             (ULONG_PTR *)0x0);
                                                              pbVar15 = pbVar6;
                                                            }
                                                            else {
                                                              pbVar15 = pbVar6 + iVar20 + iVar12 + 5
                                                              ;
                                                            }
                                                            if (*pbVar15 < 0xe) {
                                                              iVar12 = (iVar8 + -2) * iVar5;
                                                              iVar19 = iVar12 + -2 + iVar20;
                                                              if ((iVar19 < 0) || (iVar22 <= iVar19)
                                                                 ) {
                                                                RaiseException(0xc000008c,1,0,
                                                                               (ULONG_PTR *)0x0);
                                                                pbVar15 = pbVar6;
                                                              }
                                                              else {
                                                                pbVar15 = pbVar6 + iVar20 + iVar12 +
                                                                                            -2;
                                                              }
                                                              if (*pbVar15 < 0xe) {
                                                                iVar19 = iVar12 + 2 + iVar20;
                                                                if ((iVar19 < 0) ||
                                                                   (iVar22 <= iVar19)) {
                                                                  RaiseException(0xc000008c,1,0,
                                                                                 (ULONG_PTR *)0x0);
                                                                  pbVar15 = pbVar6;
                                                                }
                                                                else {
                                                                  pbVar15 = pbVar6 + iVar20 + iVar12
                                                                                              + 2;
                                                                }
                                                                if (*pbVar15 < 0xe) {
                                                                  local_b8 = 1;
                                                                  if ((iVar11 + iVar20 < 0) ||
                                                                     (iVar22 <= iVar11 + iVar20)) {
                                                                    RaiseException(0xc000008c,1,0,
                                                                                   (ULONG_PTR *)0x0)
                                                                    ;
                                                                    pbVar15 = pbVar6;
                                                                  }
                                                                  else {
                                                                    pbVar15 = pbVar6 + iVar20 + 
                                                  iVar11;
                                                  }
                                                  if ((iVar17 + iVar20 < 0) ||
                                                     (iVar22 <= iVar17 + iVar20)) {
                                                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                                    pbVar14 = pbVar6;
                                                  }
                                                  else {
                                                    pbVar14 = pbVar6 + iVar20 + iVar17;
                                                  }
                                                  if (*pbVar15 + 2 < (uint)*pbVar14) {
                                                    if ((iVar9 < 0) || (iVar22 <= iVar9)) {
                                                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0
                                                                    );
                                                      pbVar15 = pbVar6;
                                                    }
                                                    else {
                                                      pbVar15 = pbVar6 + iVar20 + iVar10;
                                                    }
                                                    if ((iVar17 + iVar20 < 0) ||
                                                       (iVar22 <= iVar17 + iVar20)) {
                                                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0
                                                                    );
                                                      pbVar14 = pbVar6;
                                                    }
                                                    else {
                                                      pbVar14 = pbVar6 + iVar20 + iVar17;
                                                    }
                                                    if (*pbVar15 + 2 < (uint)*pbVar14) {
                                                      local_b8 = 3;
                                                      goto LAB_005a76eb;
                                                    }
                                                  }
                                                  iVar9 = (iVar8 + 1) * iVar5 + iVar20;
                                                  pbVar15 = (byte *)FUN_0041fad0(iVar9);
                                                  bVar1 = *pbVar15;
                                                  pbVar15 = (byte *)FUN_0041fad0(iVar20 + iVar17);
                                                  if (*pbVar15 + 2 < (uint)bVar1) {
                                                    pbVar15 = (byte *)FUN_0041fad0(iVar13);
                                                    bVar1 = *pbVar15;
                                                    pbVar15 = (byte *)FUN_0041fad0(iVar9);
                                                    local_b8 = 1;
                                                    if (bVar1 + 2 < (uint)*pbVar15) {
                                                      local_b8 = 3;
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
              }
            }
LAB_005a76eb:
            iVar9 = local_38 * local_34 + local_30;
            if ((iVar9 < 0) || (local_2c <= iVar9)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar16 = puVar7;
            }
            else {
              puVar16 = puVar7 + iVar9;
            }
            iVar20 = iVar20 + 1;
            *puVar16 = local_b8;
          } while (iVar20 < iVar3);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar4);
    }
    FUN_00596550(puVar7,&local_20);
    thunk_FUN_0060fc30(puVar7);
    thunk_FUN_0060fc30(0);
    thunk_FUN_0060fc30(pbVar6);
  }
  return;
}

