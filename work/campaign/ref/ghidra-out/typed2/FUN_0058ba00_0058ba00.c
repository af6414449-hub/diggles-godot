
void FUN_0058ba00(int param_1,int param_2,byte param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  CMap *pCVar3;
  byte bVar4;
  void *pvVar5;
  void *pvVar6;
  uint uVar7;
  uint uVar8;
  CMapCell *pCVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined1 *puVar14;
  BOOL BVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int in_ECX;
  int *piVar19;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int iVar20;
  void *pvVar21;
  int iVar22;
  code *pcVar23;
  code *pcVar24;
  bool bVar25;
  int local_34;
  int *local_30;
  uint local_2c;
  int local_28;
  int local_24;
  int *local_20;
  void *local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  bVar4 = param_3;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00706631;
  local_10 = ExceptionList;
  uVar8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_18 = 0;
  if (*(int *)(in_ECX + 0x34) < 1) {
    return;
  }
  piVar19 = (int *)(in_ECX + 0x30);
  local_1c = (void *)0x0;
  pcVar23 = RaiseException_exref;
  ExceptionList = &local_10;
  local_20 = piVar19;
  local_14 = in_ECX;
  do {
    pvVar21 = local_1c;
    if ((uint)piVar19[1] <= local_18) {
      (*pcVar23)(0xc000008c,1,0,0,uVar8);
      piVar19 = local_20;
    }
    _param_3 = *piVar19;
    pcVar24 = pcVar23;
    if (*(int *)((int)pvVar21 + _param_3) <= param_1) {
      if ((uint)piVar19[1] <= local_18) {
        (*pcVar23)(0xc000008c,1,0,0,uVar8);
        _param_3 = *(int *)(local_14 + 0x30);
      }
      pvVar5 = local_1c;
      piVar19 = local_20;
      if (param_1 <= *(int *)((int)pvVar21 + _param_3 + 8)) {
        if (*(uint *)(local_14 + 0x34) <= local_18) {
          (*pcVar23)(0xc000008c,1,0,0,uVar8);
          _param_3 = *(int *)(local_14 + 0x30);
        }
        pvVar6 = local_1c;
        piVar19 = local_20;
        pvVar21 = pvVar5;
        if (*(int *)((int)pvVar5 + _param_3 + 4) <= param_2) {
          if (*(uint *)(local_14 + 0x34) <= local_18) {
            (*pcVar23)(0xc000008c,1,0,0,uVar8);
            _param_3 = *(int *)(local_14 + 0x30);
          }
          pvVar5 = local_1c;
          piVar19 = local_20;
          pvVar21 = pvVar6;
          if (param_2 <= *(int *)((int)pvVar6 + _param_3 + 0xc)) {
            if (*(uint *)(local_14 + 0x34) <= local_18) {
              (*pcVar23)(0xc000008c,1,0,0);
              _param_3 = *(int *)(local_14 + 0x30);
            }
            local_28 = *(int *)((int)pvVar5 + _param_3);
            piVar19 = local_20;
            while( true ) {
              pvVar21 = local_1c;
              if ((uint)piVar19[1] <= local_18) {
                (*pcVar23)(0xc000008c,1,0,0);
                _param_3 = *local_20;
                piVar19 = local_20;
              }
              uVar7 = local_18;
              if (*(int *)((int)pvVar21 + _param_3 + 8) <= local_28) break;
              if ((uint)piVar19[1] <= local_18) {
                (*pcVar23)(0xc000008c,1,0,0);
                _param_3 = *local_20;
                piVar19 = local_20;
              }
              local_24 = *(int *)((int)pvVar21 + _param_3 + 4);
              while( true ) {
                if ((uint)piVar19[1] <= local_18) {
                  (*pcVar23)(0xc000008c,1,0,0);
                  piVar19 = local_20;
                }
                pCVar3 = PTR_0077241c;
                pcVar24 = RaiseException_exref;
                _param_3 = *piVar19;
                if (*(int *)((int)pvVar21 + _param_3 + 0xc) <= local_24) break;
                iVar20 = PTR_0077241c->cellX0;
                if (PTR_0077241c->cellX0 <= local_28) {
                  iVar20 = local_28;
                }
                iVar22 = PTR_0077241c->cellY0;
                if (PTR_0077241c->cellY0 <= local_24) {
                  iVar22 = local_24;
                }
                iVar11 = PTR_0077241c->cellY1 + -1;
                if (iVar22 < PTR_0077241c->cellY1) {
                  iVar11 = iVar22;
                }
                iVar22 = PTR_0077241c->cellX1 + -1;
                if (iVar20 < PTR_0077241c->cellX1) {
                  iVar22 = iVar20;
                }
                iVar20 = (iVar11 * PTR_0077241c->mapWidth + iVar22) % PTR_0077241c->cellCountTotal;
                if ((iVar20 < 0) || (PTR_0077241c->cellCount <= iVar20)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar9 = pCVar3->cells;
                }
                else {
                  pCVar9 = PTR_0077241c->cells + iVar20;
                }
                piVar19 = local_20;
                pvVar21 = local_1c;
                if ((pCVar9->digMarks >> ((bVar4 & 7) << 2) & 0xf) != 0) goto LAB_0058bc5d;
                local_24 = local_24 + 1;
                pcVar23 = pcVar24;
              }
              local_28 = local_28 + 1;
            }
            if ((uint)piVar19[1] <= local_18) {
              (*pcVar23)(0xc000008c,1,0,0);
              _param_3 = *(int *)(local_14 + 0x30);
            }
            iVar22 = uVar7 * 0x14;
            iVar10 = (int)(*(int *)(_param_3 + iVar22) + (*(int *)(_param_3 + iVar22) >> 0x1f & 7U))
                     >> 3;
            iVar20 = *(int *)(_param_3 + 8 + iVar22) + 7;
            iVar11 = (int)(iVar20 + (iVar20 >> 0x1f & 7U)) >> 3;
            iVar20 = *(int *)(_param_3 + 4 + iVar22);
            local_28 = (int)(iVar20 + (iVar20 >> 0x1f & 7U)) >> 3;
            iVar20 = *(int *)(_param_3 + 0xc + iVar22) + 7;
            local_34 = iVar11;
            do {
              local_24 = iVar22;
              if ((int)(iVar20 + (iVar20 >> 0x1f & 7U)) >> 3 <= local_28) {
                uVar8 = *(uint *)(local_14 + 0x34);
                if (uVar8 <= local_18) {
                  (*pcVar23)(0xc000008c,1,0,0);
                  uVar8 = *(uint *)(local_14 + 0x34);
                }
                iVar11 = *(int *)(local_14 + 0x30);
                iVar20 = iVar11 + iVar22;
                if (uVar8 <= local_18) {
                  (*pcVar23)(0xc000008c,1,0,0);
                  iVar11 = *(int *)(local_14 + 0x30);
                  uVar8 = *(uint *)(local_14 + 0x34);
                }
                iVar20 = (*(int *)(iVar22 + iVar11) + *(int *)(iVar20 + 8)) / 2 + 1;
                if (uVar8 <= local_18) {
                  (*pcVar23)(0xc000008c,1,0,0);
                  iVar11 = *(int *)(local_14 + 0x30);
                  uVar8 = *(uint *)(local_14 + 0x34);
                }
                iVar10 = iVar22 + iVar11;
                if (uVar8 <= local_18) {
                  (*pcVar23)(0xc000008c,1,0,0);
                  iVar11 = *(int *)(local_14 + 0x30);
                }
                local_34 = -1;
                local_30 = (int *)((*(int *)(iVar22 + 0xc + iVar11) + *(int *)(iVar10 + 4)) / 2);
                if (DAT_00772474 == 0) {
                  iVar11 = FUN_006ba810(0x189);
                  local_8 = 3;
                  if (iVar11 == 0) {
                    DAT_00772474 = 0;
                  }
                  else {
                    DAT_00772474 = FUN_005f7ec0();
                  }
                  local_8 = 0xffffffff;
                }
                iVar11 = FUN_005fcdf0(param_2);
                if (iVar11 < 0) {
                  _param_3 = 0;
                }
                else {
                  if (DAT_00772474 == 0) {
                    iVar11 = FUN_006ba810(0x189);
                    local_8 = 4;
                    if (iVar11 == 0) {
                      DAT_00772474 = 0;
                    }
                    else {
                      DAT_00772474 = FUN_005f7ec0();
                    }
                    local_8 = 0xffffffff;
                  }
                  _param_3 = FUN_005fcdf0(param_2);
                }
                if (*(uint *)(local_14 + 0x34) <= local_18) {
                  (*pcVar23)(0xc000008c,1,0,0);
                }
                uVar16 = FUN_0058e9c0(_param_3,2,
                                      *(undefined4 *)(*(int *)(local_14 + 0x30) + 0x10 + iVar22),
                                      &local_34);
                if (*(uint *)(local_14 + 0x34) <= local_18) {
                  (*pcVar23)(0xc000008c,1,0,0);
                }
                uVar17 = FUN_0058e9c0(_param_3,1,
                                      *(undefined4 *)(*(int *)(local_14 + 0x30) + 0x10 + iVar22),
                                      &local_34);
                if (*(uint *)(local_14 + 0x34) <= local_18) {
                  (*pcVar23)(0xc000008c,1,0,0);
                }
                uVar18 = FUN_0058e9c0(_param_3,0,
                                      *(undefined4 *)(*(int *)(local_14 + 0x30) + 0x10 + iVar22),
                                      &local_34);
                FUN_0058c450(uVar16,(float)iVar20,(float)(int)local_30,0x41700000);
                FUN_0058c450(uVar17,(float)iVar20,(float)(int)local_30,0x41700000);
                FUN_0058c450(uVar18,(float)iVar20,(float)(int)local_30,0x41700000);
                FUN_0058f2a0(local_18);
                ExceptionList = local_10;
                return;
              }
              iVar22 = iVar10;
              if (iVar10 < iVar11) {
                do {
                  piVar19 = DAT_0077244c;
                  local_30 = DAT_0077244c;
                  iVar11 = DAT_0077244c[0x2127] * local_28 + iVar22;
                  local_2c = DAT_0077244c[0x212b];
                  if (local_2c == 0) {
                    if (DAT_0077244c[0x212a] < 1) {
                      (*pcVar23)(0xc000008c,1,0,0);
                    }
LAB_0058bd91:
                    iVar11 = piVar19[0x2129];
                  }
                  else {
                    if (iVar11 < 0) {
                      iVar11 = 0;
                    }
                    iVar11 = iVar11 % (int)local_2c;
                    if ((iVar11 < 0) || (DAT_0077244c[0x212a] <= iVar11)) {
                      (*pcVar23)(0xc000008c,1,0,0);
                      piVar19 = local_30;
                      goto LAB_0058bd91;
                    }
                    iVar11 = iVar11 * 0x20 + DAT_0077244c[0x2129];
                  }
                  uVar8 = 0;
                  if (0 < *(int *)(iVar11 + 0x1c)) {
                    bVar25 = *(int *)(iVar11 + 0x1c) != 0;
                    local_1c = (void *)0x0;
                    do {
                      if (!bVar25) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      iVar12 = *(int *)(iVar11 + 0x18);
                      if ((float)*(int *)(_param_3 + local_24) <= *(float *)((int)local_1c + iVar12)
                         ) {
                        if (*(uint *)(iVar11 + 0x1c) <= uVar8) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          iVar12 = *(int *)(iVar11 + 0x18);
                        }
                        if (*(float *)((int)local_1c + iVar12) <=
                            (float)*(int *)(_param_3 + 8 + local_24)) {
                          if (*(uint *)(iVar11 + 0x1c) <= uVar8) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            iVar12 = *(int *)(iVar11 + 0x18);
                          }
                          if ((float)*(int *)(_param_3 + 4 + local_24) <=
                              *(float *)((int)local_1c + iVar12 + 4)) {
                            if (*(uint *)(iVar11 + 0x1c) <= uVar8) {
                              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                              iVar12 = *(int *)(iVar11 + 0x18);
                            }
                            if (*(float *)((int)local_1c + iVar12 + 4) <=
                                (float)*(int *)(_param_3 + 0xc + local_24)) {
                              if (*(uint *)(iVar11 + 0x1c) <= uVar8) {
                                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                iVar12 = *(int *)(iVar11 + 0x18);
                              }
                              local_2c = *(uint *)((int)local_1c + iVar12 + 0x28);
                              local_30 = DAT_00772478;
                              if ((uint)DAT_00772478[0x2007] <= local_2c) {
                                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                              }
                              iVar12 = *(int *)(local_30[0x2006] + local_2c * 4);
                              if ((iVar12 != 0) && (*(char *)(iVar12 + 0xcc2) != '\0')) {
                                if (*(uint *)(iVar11 + 0x1c) <= uVar8) {
                                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                }
                                FUN_005d53f0();
                                uVar16 = extraout_ECX;
                                if ((*(uint *)(iVar11 + 0x1c) <= uVar8) &&
                                   (RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0),
                                   uVar16 = extraout_ECX_00, *(uint *)(iVar11 + 0x1c) <= uVar8)) {
                                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                  uVar16 = extraout_ECX_01;
                                }
                                local_30 = *(int **)(*(int *)(iVar11 + 0x18) + 0x20 + (int)local_1c)
                                ;
                                if (local_30 != (int *)0x0) {
                                  local_8 = 0;
                                  FUN_00453f00(uVar16);
                                  if (*local_30 != 0) {
                                    FUN_006ba940();
                                  }
                                  local_8 = 0xffffffff;
                                  FUN_006cecd8(local_30,9);
                                }
                                iVar12 = *(int *)(iVar11 + 0x1c);
                                if ((int)uVar8 < iVar12 + -1) {
                                  iVar13 = *(int *)(iVar11 + 0x1c) * 0x34;
                                  iVar12 = *(int *)(iVar11 + 0x18);
                                  puVar2 = (undefined4 *)(iVar13 + -0x34 + iVar12);
                                  uVar16 = puVar2[1];
                                  uVar17 = puVar2[2];
                                  uVar18 = puVar2[3];
                                  puVar1 = (undefined4 *)((int)local_1c + iVar12);
                                  *puVar1 = *puVar2;
                                  puVar1[1] = uVar16;
                                  puVar1[2] = uVar17;
                                  puVar1[3] = uVar18;
                                  puVar1 = (undefined4 *)(iVar13 + -0x24 + iVar12);
                                  uVar16 = puVar1[1];
                                  uVar17 = puVar1[2];
                                  uVar18 = puVar1[3];
                                  puVar2 = (undefined4 *)((int)local_1c + iVar12 + 0x10);
                                  *puVar2 = *puVar1;
                                  puVar2[1] = uVar16;
                                  puVar2[2] = uVar17;
                                  puVar2[3] = uVar18;
                                  puVar1 = (undefined4 *)(iVar13 + -0x14 + iVar12);
                                  uVar16 = puVar1[1];
                                  uVar17 = puVar1[2];
                                  uVar18 = puVar1[3];
                                  puVar2 = (undefined4 *)((int)local_1c + iVar12 + 0x20);
                                  *puVar2 = *puVar1;
                                  puVar2[1] = uVar16;
                                  puVar2[2] = uVar17;
                                  puVar2[3] = uVar18;
                                  *(undefined4 *)((int)local_1c + iVar12 + 0x30) =
                                       *(undefined4 *)(iVar13 + -4 + iVar12);
                                  iVar12 = *(int *)(iVar11 + 0x1c);
                                }
                                uVar8 = uVar8 - 1;
                                *(int *)(iVar11 + 0x1c) = iVar12 + -1;
                                local_1c = (void *)((int)local_1c + -0x34);
                              }
                            }
                          }
                        }
                      }
                      uVar8 = uVar8 + 1;
                      local_1c = (void *)((int)local_1c + 0x34);
                      bVar25 = uVar8 < *(uint *)(iVar11 + 0x1c);
                    } while ((int)uVar8 < (int)*(uint *)(iVar11 + 0x1c));
                  }
                  local_30 = (int *)0x0;
                  if (0 < *(int *)(iVar11 + 0xc)) {
                    do {
                      if (*(uint *)(iVar11 + 0xc) <= local_30) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      local_1c = *(void **)(*(int *)(iVar11 + 8) + (int)local_30 * 4);
                      if ((((((float)*(int *)(_param_3 + local_24) <=
                              *(float *)((int)local_1c + 0xc)) &&
                            (*(float *)((int)local_1c + 0xc) <=
                             (float)*(int *)(_param_3 + 8 + local_24))) &&
                           ((float)*(int *)(_param_3 + 4 + local_24) <=
                            *(float *)((int)local_1c + 0x10))) &&
                          ((*(float *)((int)local_1c + 0x10) <=
                            (float)*(int *)(_param_3 + 0xc + local_24) &&
                           (*(int *)((int)local_1c + 0xd4) != 0)))) &&
                         (*(char *)(*(int *)((int)local_1c + 0xd4) + 0xcc2) != '\0')) {
                        if (DAT_00772468 == (undefined1 *)0x0) {
                          puVar14 = (undefined1 *)FUN_006ba810(0x2f6);
                          if (puVar14 == (undefined1 *)0x0) {
                            puVar14 = (undefined1 *)0x0;
                          }
                          else {
                            *(undefined4 *)(puVar14 + 1) = 0;
                            *(undefined4 *)(puVar14 + 5) = 0;
                            local_8 = 2;
                            *puVar14 = 1;
                            FUN_005ebb00();
                          }
                          local_8 = 0xffffffff;
                          DAT_00772468 = puVar14;
                        }
                        FUN_005eae80(local_1c);
                        local_2c = DAT_0077247c;
                        BVar15 = IsBadReadPtr(local_1c,0x10);
                        if ((((BVar15 == 0) && (*(int *)((int)local_1c + 8) == 0x616e4f62)) &&
                            ((DAT_00768398 == '\0' || (*(int *)((int)local_1c + 0xdc) != 0)))) &&
                           (*(char *)((int)local_1c + 0x404) == '\0')) {
                          *(undefined1 *)((int)local_1c + 0x404) = 1;
                          uVar8 = FUN_0042f510();
                          if (*(uint *)(local_2c + 0x410) <= uVar8) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          }
                          *(void **)(*(int *)(local_2c + 0x40c) + uVar8 * 4) = local_1c;
                        }
                      }
                      local_30 = (int *)((int)local_30 + 1);
                    } while ((int)local_30 < *(int *)(iVar11 + 0xc));
                  }
                  iVar22 = iVar22 + 1;
                  iVar11 = local_34;
                  pcVar23 = RaiseException_exref;
                } while (iVar22 < local_34);
              }
              local_28 = local_28 + 1;
              iVar22 = local_24;
            } while( true );
          }
        }
      }
    }
LAB_0058bc5d:
    local_1c = (void *)((int)pvVar21 + 0x14);
    local_18 = local_18 + 1;
    pcVar23 = pcVar24;
    if (*(int *)(local_14 + 0x34) <= (int)local_18) {
      ExceptionList = local_10;
      return;
    }
  } while( true );
}

