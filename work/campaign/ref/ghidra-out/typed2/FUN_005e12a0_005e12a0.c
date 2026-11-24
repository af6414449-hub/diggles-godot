
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e12a0(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  size_t sVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined4 uVar11;
  int iVar12;
  undefined4 *in_ECX;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  void *pvVar18;
  undefined4 *puVar19;
  bool bVar20;
  float fVar21;
  int *local_78;
  int local_74;
  int local_70;
  uint local_34;
  float local_2c;
  void *local_28;
  void *local_1c;
  undefined1 *puStack_18;
  uint local_14;
  
  iVar12 = DAT_0077244c;
  puStack_18 = &LAB_007091dd;
  local_1c = ExceptionList;
  uVar5 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_74 = 0;
  in_ECX[1] = *(undefined4 *)(DAT_00772400 + 100);
  local_70 = 0;
  local_78 = (int *)0x0;
  piVar1 = in_ECX + 3;
  local_14 = 0;
  if ((void *)*piVar1 != (void *)0x0) {
    _memset((void *)*piVar1,0,in_ECX[4] << 2);
  }
  fVar21 = 3.4028235e+38;
  *in_ECX = 0xffffffff;
  local_28 = (void *)0x0;
  local_2c = 3.4028235e+38;
  if (in_ECX[0xd] == 0) {
LAB_005e13c1:
    bVar20 = false;
  }
  else {
    in_ECX[0x1d] = ((float)in_ECX[0x17] + (float)in_ECX[0x1a]) * 0.5;
    in_ECX[0x1b] = ((float)in_ECX[0x15] + (float)in_ECX[0x18]) * 0.5;
    in_ECX[0x1c] = ((float)in_ECX[0x16] + (float)in_ECX[0x19]) * 0.5;
    fVar21 = 256.0;
    if (256.0 <= ((float)in_ECX[0x19] - (float)in_ECX[0x16]) *
                 ((float)in_ECX[0x19] - (float)in_ECX[0x16]) +
                 ((float)in_ECX[0x18] - (float)in_ECX[0x15]) *
                 ((float)in_ECX[0x18] - (float)in_ECX[0x15])) goto LAB_005e13c1;
    bVar20 = true;
  }
  iVar15 = iVar12 + 0x84b0;
  if ((in_ECX[5] != 2) || (bVar20)) {
    if (in_ECX[0xd] == 0) goto LAB_005e13df;
    PStdUtils::ClearPtrWatcher();
    DAT_00772dd8 = (int)ROUND((float)in_ECX[0x19] + 0.9999);
    uVar14 = (int)ROUND((float)in_ECX[0x18] + 0.9999) + 7U & 0xfffffff8;
    uVar17 = DAT_00772dd8 + 7U & 0xfffffff8;
    uVar13 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= (int)((int)(float)in_ECX[0x15] & 0xfffffff8U)) {
      uVar13 = (int)(float)in_ECX[0x15] & 0xfffffff8U;
    }
    uVar7 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= (int)((int)(float)in_ECX[0x16] & 0xfffffff8U)) {
      uVar7 = (int)(float)in_ECX[0x16] & 0xfffffff8U;
    }
    uVar16 = PTR_0077241c->cellX1;
    if ((int)uVar14 <= PTR_0077241c->cellX1) {
      uVar16 = uVar14;
    }
    uVar14 = PTR_0077241c->cellY1;
    if ((int)uVar17 <= PTR_0077241c->cellY1) {
      uVar14 = uVar17;
    }
    pvVar18 = local_28;
    for (; (int)uVar7 <= (int)(uVar14 - 1); uVar7 = uVar7 + 8) {
      local_28 = pvVar18;
      if ((int)uVar13 <= (int)(uVar16 - 1)) {
        uVar17 = uVar13;
        do {
          iVar15 = *(int *)(iVar12 + 0x849c) * ((int)(((int)uVar7 >> 0x1f & 7U) + uVar7) >> 3) +
                   ((int)(uVar17 + ((int)uVar17 >> 0x1f & 7U)) >> 3);
          if (*(int *)(iVar12 + 0x84ac) == 0) {
            if (*(int *)(iVar12 + 0x84a8) < 1) {
LAB_005e1500:
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar15 = *(int *)(iVar12 + 0x84a4);
          }
          else {
            if (iVar15 < 0) {
              iVar15 = 0;
            }
            iVar15 = iVar15 % *(int *)(iVar12 + 0x84ac);
            if ((iVar15 < 0) || (*(int *)(iVar12 + 0x84a8) <= iVar15)) goto LAB_005e1500;
            iVar15 = iVar15 * 0x20 + *(int *)(iVar12 + 0x84a4);
          }
          iVar8 = *(int *)(iVar15 + 0xc);
          local_34 = 0;
          if (0 < iVar8) {
            do {
              if (*(uint *)(iVar15 + 0xc) <= local_34) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              pvVar18 = *(void **)(*(int *)(iVar15 + 8) + local_34 * 4);
              iVar9 = FUN_005e0e50(pvVar18);
              if (iVar9 != 0) goto switchD_005e1580_default;
              fVar21 = *(float *)((int)pvVar18 + 0xc);
              fVar2 = *(float *)((int)pvVar18 + 0x10);
              fVar3 = *(float *)((int)pvVar18 + 0x14);
              switch(in_ECX[0xd]) {
              case 0:
switchD_005e1580_caseD_0:
                fVar21 = (fVar2 - (float)in_ECX[0x1c]) * (fVar2 - (float)in_ECX[0x1c]) +
                         (fVar21 - (float)in_ECX[0x1b]) * (fVar21 - (float)in_ECX[0x1b]) +
                         (fVar3 - (float)in_ECX[0x1d]) * (fVar3 - (float)in_ECX[0x1d]);
                goto LAB_005e16a6;
              case 1:
                fVar21 = (fVar2 - (float)in_ECX[0x1c]) * (fVar2 - (float)in_ECX[0x1c]) +
                         (fVar21 - (float)in_ECX[0x1b]) * (fVar21 - (float)in_ECX[0x1b]) +
                         (fVar3 - (float)in_ECX[0x1d]) * (fVar3 - (float)in_ECX[0x1d]);
                goto LAB_005e15da;
              case 2:
                fVar21 = (fVar2 - (float)in_ECX[0x1c]) * (fVar2 - (float)in_ECX[0x1c]) +
                         (fVar21 - (float)in_ECX[0x1b]) * (fVar21 - (float)in_ECX[0x1b]);
LAB_005e15da:
                if (fVar21 <= (float)in_ECX[2]) {
LAB_005e16a6:
                  if (0.0 <= fVar21) {
                    if (in_ECX[0xf] == 1) {
                      if (in_ECX[0xe] == 1) {
                        if (local_28 == (void *)0x0) {
LAB_005e16f8:
                          local_2c = fVar21;
                          local_28 = pvVar18;
                        }
                        else if (fVar21 < local_2c) {
                          local_2c = fVar21;
                          local_28 = pvVar18;
                        }
                      }
                      else {
                        if (in_ECX[0xe] != 2) {
                          thunk_FUN_0060fc30(*piVar1);
                          in_ECX[4] = 1;
                          puVar19 = (undefined4 *)FUN_006ba810(0x5e);
                          *piVar1 = (int)puVar19;
                          if ((int)in_ECX[4] < 1) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            puVar19 = (undefined4 *)*piVar1;
                          }
                          *puVar19 = pvVar18;
                          goto LAB_005e21b0;
                        }
                        if ((local_28 == (void *)0x0) || (local_2c < fVar21)) goto LAB_005e16f8;
                      }
                    }
                    else {
                      bVar20 = PStdUtils::AddPtrToWatcher(pvVar18);
                      if (bVar20) {
                        if (local_74 <= local_70) {
                          if (local_78 == (int *)0x0) {
                            local_78 = (int *)FUN_006ba810(0x7a);
                            local_74 = 0x20;
                            local_70 = 0;
                          }
                          else {
                            local_74 = local_74 + 0x20;
                            iVar9 = local_74 * 8;
                            if (DAT_00c3c824 == 0) {
                              DAT_00c3c824 = 1;
                              InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                            }
                            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                            local_14._0_1_ = 2;
                            if (local_78 == (int *)0x0) {
                              local_78 = (int *)FUN_006ba810(0x80);
                            }
                            else {
                              if (iVar9 == 0) {
                                if (DAT_00c3c824 == 0) {
                                  DAT_00c3c824 = 1;
                                  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                                }
                                EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                                local_14 = CONCAT31(local_14._1_3_,3);
                                LOCK();
                                _DAT_00c3c818 = _DAT_00c3c818 + 1;
                                UNLOCK();
                                piVar10 = local_78 + -7;
                                iVar9 = FUN_006ba730();
                                if (iVar9 == 0) {
                                  sVar4 = local_78[-2];
                                  iVar9 = FUN_006ba730();
                                  if (iVar9 != 0) goto LAB_005e1822;
                                  if (local_78[-5] != 0) {
                                    *(int *)(local_78[-5] + 4) = local_78[-6];
                                  }
                                  if (local_78[-6] != 0) {
                                    *(int *)(local_78[-6] + 8) = local_78[-5];
                                  }
                                  if (piVar10 == DAT_00c3c81c) {
                                    DAT_00c3c81c = (int *)local_78[-6];
                                  }
                                  _memset(local_78,-0x20202021,sVar4);
                                  bVar20 = DAT_0077248f == '\0';
                                  *piVar10 = -0x20202021;
                                  local_78[-1] = -0x20202021;
                                  *(undefined4 *)(sVar4 + 0x1c + (int)piVar10) = 0xdfdfdfdf;
                                  if ((((bVar20) || (DAT_00c1c788 == '\0')) ||
                                      (piVar10 < DAT_00c3c7cc)) ||
                                     ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar10)) {
                                    FUN_006df631(piVar10);
                                  }
                                  else {
                                    FUN_006b8c20();
                                  }
                                }
                                else {
LAB_005e1822:
                                  if (DAT_00c3c7d4 != (FILE *)0x0) {
                                    FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_78,
                                                 iVar9);
                                    _fflush(DAT_00c3c7d4);
                                  }
                                  if (DAT_00c3c828 != '\0') {
                                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                  }
                                }
                                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                                local_14 = local_14 & 0xffffff00;
                                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                                local_78 = (int *)0x0;
                                goto LAB_005e1a5b;
                              }
                              LOCK();
                              _DAT_00c3c82c = _DAT_00c3c82c + 1;
                              UNLOCK();
                              piVar10 = local_78 + -7;
                              iVar6 = FUN_006ba730();
                              if ((iVar6 != 0) || (iVar6 = FUN_006ba730(), iVar6 != 0)) {
                                if (DAT_00c3c7d4 != (FILE *)0x0) {
                                  FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_78,iVar6
                                              );
                                  _fflush(DAT_00c3c7d4);
                                }
                                if (DAT_00c3c828 != '\0') {
                                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                }
LAB_005e196b:
                                local_14 = (uint)local_14._1_3_ << 8;
                                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                                local_78 = (int *)0x0;
                                goto LAB_005e1a5b;
                              }
                              if (((DAT_0077248f == '\0') || (DAT_00c1c788 == '\0')) ||
                                 ((piVar10 < DAT_00c3c7cc ||
                                  ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar10)))) {
                                local_78 = (int *)FUN_006df8de(piVar10,iVar9 + 0x20);
                                if (local_78 == (int *)0x0) {
                                  FUN_0043ffe0(&DAT_00772cc0,
                                               "Reallocating %d bytes at 0x%08lx failed.",
                                               iVar9 + 0x20,piVar10);
                                  MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
                                  goto LAB_005e1a04;
                                }
                              }
                              else {
                                local_78 = (int *)FUN_006b8a90();
LAB_005e1a04:
                                if (local_78 == (int *)0x0) goto LAB_005e196b;
                              }
                              if (piVar10 == DAT_00c3c81c) {
                                DAT_00c3c81c = local_78;
                              }
                              local_78[5] = iVar9;
                              if (local_78[1] != 0) {
                                *(int **)(local_78[1] + 8) = local_78;
                              }
                              if (local_78[2] != 0) {
                                *(int **)(local_78[2] + 4) = local_78;
                              }
                              local_78[local_74 * 2 + 7] = -0x54e0033;
                              local_78 = local_78 + 7;
                            }
                            local_14 = (uint)local_14._1_3_ << 8;
                            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                          }
                        }
LAB_005e1a5b:
                        local_78[local_70 * 2] = (int)pvVar18;
                        local_78[local_70 * 2 + 1] = (int)fVar21;
                        local_70 = local_70 + 1;
                      }
                    }
                  }
                }
                break;
              case 3:
                if ((((float)in_ECX[0x15] <= fVar21) && ((float)in_ECX[0x16] <= fVar2)) &&
                   (((float)in_ECX[0x17] <= fVar3 &&
                    ((fVar21 <= (float)in_ECX[0x18] && (fVar2 <= (float)in_ECX[0x19])))))) {
                  bVar20 = (float)in_ECX[0x1a] < fVar3;
LAB_005e1678:
                  if (!bVar20) goto switchD_005e1580_caseD_0;
                }
                break;
              case 4:
                if ((((float)in_ECX[0x15] <= fVar21) && ((float)in_ECX[0x16] <= fVar2)) &&
                   (fVar21 <= (float)in_ECX[0x18])) {
                  bVar20 = (float)in_ECX[0x19] < fVar2;
                  goto LAB_005e1678;
                }
              }
switchD_005e1580_default:
              local_34 = local_34 + 1;
            } while ((int)local_34 < iVar8);
          }
          uVar17 = uVar17 + 8;
        } while ((int)uVar17 <= (int)(uVar16 - 1));
      }
      pvVar18 = local_28;
    }
    iVar12 = in_ECX[0xf];
    if (iVar12 != 1) goto LAB_005e1fea;
    if (pvVar18 != (void *)0x0) {
LAB_005e1ac5:
      thunk_FUN_0060fc30(*piVar1,uVar5);
      in_ECX[4] = 1;
      puVar19 = (undefined4 *)FUN_006ba810(0x5e);
      *piVar1 = (int)puVar19;
      local_28 = pvVar18;
      if ((int)in_ECX[4] < 1) goto LAB_005e1af5;
      goto LAB_005e1b08;
    }
  }
  else {
    iVar15 = iVar12 + 0x84d2;
LAB_005e13df:
    uVar13 = 0xffffffff;
LAB_005e1b69:
    uVar13 = uVar13 + 1;
    if ((int)uVar13 < (int)*(uint *)(iVar15 + 5)) {
      if (*(uint *)(iVar15 + 5) <= uVar13) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar14 = *(uint *)(*(int *)(iVar15 + 1) + uVar13 * 4);
      if (1 < (int)uVar14) {
        puVar19 = (undefined4 *)(iVar12 + 0x488);
        if (uVar14 < 0x2000) {
          puVar19 = puVar19 + uVar14;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        pvVar18 = (void *)*puVar19;
        if (((pvVar18 != (void *)0x0) && (iVar8 = FUN_005e0e50(pvVar18), iVar8 == 0)) &&
           (FUN_005e1180(pvVar18), 0.0 <= fVar21)) {
          if (in_ECX[0xf] != 1) {
            if (local_74 <= local_70) {
              if (local_78 == (int *)0x0) {
                local_78 = (int *)FUN_006ba810(0x7a);
                local_74 = 0x20;
                local_70 = 1;
                *local_78 = (int)pvVar18;
                local_78[1] = (int)fVar21;
                goto LAB_005e1b69;
              }
              local_74 = local_74 + 0x20;
              iVar8 = local_74 * 8;
              if (DAT_00c3c824 == 0) {
                DAT_00c3c824 = 1;
                InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
              }
              EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
              local_14._0_1_ = 6;
              if (local_78 == (int *)0x0) {
                local_78 = (int *)FUN_006ba810(0x80);
              }
              else {
                if (iVar8 == 0) {
                  if (DAT_00c3c824 == 0) {
                    DAT_00c3c824 = 1;
                    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                  }
                  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                  local_14 = CONCAT31(local_14._1_3_,7);
                  LOCK();
                  _DAT_00c3c818 = _DAT_00c3c818 + 1;
                  UNLOCK();
                  piVar10 = local_78 + -7;
                  iVar8 = FUN_006ba730();
                  if (iVar8 == 0) {
                    sVar4 = local_78[-2];
                    iVar8 = FUN_006ba730();
                    if (iVar8 != 0) goto LAB_005e1d59;
                    if (local_78[-5] != 0) {
                      *(int *)(local_78[-5] + 4) = local_78[-6];
                    }
                    if (local_78[-6] != 0) {
                      *(int *)(local_78[-6] + 8) = local_78[-5];
                    }
                    if (piVar10 == DAT_00c3c81c) {
                      DAT_00c3c81c = (int *)local_78[-6];
                    }
                    _memset(local_78,-0x20202021,sVar4);
                    bVar20 = DAT_0077248f == '\0';
                    *piVar10 = -0x20202021;
                    local_78[-1] = -0x20202021;
                    *(undefined4 *)(sVar4 + 0x1c + (int)piVar10) = 0xdfdfdfdf;
                    if (((bVar20) || (DAT_00c1c788 == '\0')) ||
                       ((piVar10 < DAT_00c3c7cc ||
                        ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar10)))) {
                      FUN_006df631(piVar10);
                    }
                    else {
                      FUN_006b8c20();
                    }
                  }
                  else {
LAB_005e1d59:
                    if (DAT_00c3c7d4 != (FILE *)0x0) {
                      FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_78,iVar8);
                      _fflush(DAT_00c3c7d4);
                    }
                    if (DAT_00c3c828 != '\0') {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                  }
                  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                  local_14 = local_14 & 0xffffff00;
                  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                  local_78 = (int *)0x0;
                  goto LAB_005e1fa6;
                }
                LOCK();
                _DAT_00c3c82c = _DAT_00c3c82c + 1;
                UNLOCK();
                piVar10 = local_78 + -7;
                iVar9 = FUN_006ba730();
                if ((iVar9 != 0) || (iVar9 = FUN_006ba730(), iVar9 != 0)) {
                  if (DAT_00c3c7d4 != (FILE *)0x0) {
                    FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_78,iVar9);
                    _fflush(DAT_00c3c7d4);
                  }
                  if (DAT_00c3c828 != '\0') {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
LAB_005e1ea6:
                  local_14 = (uint)local_14._1_3_ << 8;
                  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
                  local_78 = (int *)0x0;
                  goto LAB_005e1fa6;
                }
                if ((((DAT_0077248f == '\0') || (DAT_00c1c788 == '\0')) || (piVar10 < DAT_00c3c7cc))
                   || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar10)) {
                  piVar10 = (int *)FUN_006df8de(piVar10,iVar8 + 0x20);
                  if (piVar10 == (int *)0x0) {
                    FUN_0043ffe0(&DAT_00772cc0,"Reallocating %d bytes at 0x%08lx failed.",
                                 iVar8 + 0x20,local_78 + -7);
                    MessageBoxA((HWND)0x0,&DAT_00772cc0,"Memory Error!",0x10);
                    goto LAB_005e1f47;
                  }
                }
                else {
                  piVar10 = (int *)FUN_006b8a90();
LAB_005e1f47:
                  if (piVar10 == (int *)0x0) goto LAB_005e1ea6;
                }
                piVar10[5] = iVar8;
                if (local_78 + -7 == DAT_00c3c81c) {
                  DAT_00c3c81c = piVar10;
                }
                if (piVar10[1] != 0) {
                  *(int **)(piVar10[1] + 8) = piVar10;
                }
                if (piVar10[2] != 0) {
                  *(int **)(piVar10[2] + 4) = piVar10;
                }
                piVar10[local_74 * 2 + 7] = -0x54e0033;
                local_78 = piVar10 + 7;
              }
              local_14 = (uint)local_14._1_3_ << 8;
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
            }
LAB_005e1fa6:
            local_78[local_70 * 2] = (int)pvVar18;
            local_78[local_70 * 2 + 1] = (int)fVar21;
            local_70 = local_70 + 1;
            goto LAB_005e1b69;
          }
          if (in_ECX[0xe] == 1) {
            if ((local_28 != (void *)0x0) && (local_2c <= fVar21)) goto LAB_005e1b69;
          }
          else {
            if (in_ECX[0xe] != 2) goto LAB_005e1ac5;
            if ((local_28 != (void *)0x0) && (fVar21 <= local_2c)) goto LAB_005e1b69;
          }
          local_2c = fVar21;
          local_28 = pvVar18;
        }
      }
      goto LAB_005e1b69;
    }
    iVar12 = in_ECX[0xf];
    if (iVar12 == 1) {
      if (local_28 != (void *)0x0) {
        FUN_005e2f10(1);
        if ((int)in_ECX[4] < 1) {
LAB_005e1af5:
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar19 = (undefined4 *)*piVar1;
LAB_005e1b08:
        *puVar19 = local_28;
      }
    }
    else {
LAB_005e1fea:
      iVar15 = local_70;
      if (iVar12 <= local_70) {
        iVar15 = iVar12;
      }
      if (iVar15 == 0) {
        if ((void *)*piVar1 != (void *)0x0) {
          _memset((void *)*piVar1,0,in_ECX[4] << 2);
        }
      }
      else {
        thunk_FUN_0060fc30(in_ECX[3],uVar5);
        in_ECX[4] = iVar15;
        uVar11 = FUN_006ba810(0x5e);
        in_ECX[3] = uVar11;
        if (in_ECX[0xe] == 0) {
          iVar12 = 0;
          if (0 < iVar15) {
            do {
              if (local_70 <= iVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar8 = iVar12 * 2;
              if (iVar12 < (int)in_ECX[4]) {
                piVar10 = (int *)(*piVar1 + iVar12 * 4);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar10 = (int *)*piVar1;
              }
              iVar12 = iVar12 + 1;
              *piVar10 = local_78[iVar8];
            } while (iVar12 < iVar15);
          }
        }
        else {
          FUN_005e2f60(0,local_70 + -1);
          if (in_ECX[0xe] == 1) {
            iVar12 = 0;
            if (0 < iVar15) {
              do {
                if (local_70 <= iVar12) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                iVar8 = iVar12 * 2;
                if (iVar12 < (int)in_ECX[4]) {
                  piVar10 = (int *)(*piVar1 + iVar12 * 4);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar10 = (int *)*piVar1;
                }
                iVar12 = iVar12 + 1;
                *piVar10 = local_78[iVar8];
              } while (iVar12 < iVar15);
            }
          }
          else {
            iVar12 = 0;
            if (0 < iVar15) {
              iVar9 = local_70 << 3;
              iVar8 = local_70;
              do {
                iVar8 = iVar8 + -1;
                if ((iVar8 < 0) || (local_70 <= iVar8)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                if (iVar12 < (int)in_ECX[4]) {
                  puVar19 = (undefined4 *)(*piVar1 + iVar12 * 4);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar19 = (undefined4 *)*piVar1;
                }
                iVar12 = iVar12 + 1;
                *puVar19 = *(undefined4 *)((int)local_78 + iVar9 + -8);
                iVar9 = iVar9 + -8;
              } while (iVar12 < iVar15);
            }
          }
        }
      }
    }
  }
LAB_005e21b0:
  local_14 = 10;
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  if (local_78 != (int *)0x0) {
    LOCK();
    _DAT_00c3c818 = _DAT_00c3c818 + 1;
    UNLOCK();
    piVar1 = local_78 + -7;
    iVar12 = FUN_006ba730();
    if (iVar12 == 0) {
      sVar4 = local_78[-2];
      iVar12 = FUN_006ba730();
      if (iVar12 == 0) {
        if (local_78[-5] != 0) {
          *(int *)(local_78[-5] + 4) = local_78[-6];
        }
        if (local_78[-6] != 0) {
          *(int *)(local_78[-6] + 8) = local_78[-5];
        }
        if (piVar1 == DAT_00c3c81c) {
          DAT_00c3c81c = (int *)local_78[-6];
        }
        _memset(local_78,-0x20202021,sVar4);
        bVar20 = DAT_0077248f == '\0';
        *piVar1 = -0x20202021;
        local_78[-1] = -0x20202021;
        *(undefined4 *)(sVar4 + 0x1c + (int)piVar1) = 0xdfdfdfdf;
        if (((bVar20) || (DAT_00c1c788 == '\0')) ||
           ((piVar1 < DAT_00c3c7cc || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar1)))) {
          FUN_006df631(piVar1);
        }
        else {
          FUN_006b8c20();
        }
        goto LAB_005e22ef;
      }
    }
    if (DAT_00c3c7d4 != (FILE *)0x0) {
      FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_78,iVar12);
      _fflush(DAT_00c3c7d4);
    }
    if (DAT_00c3c828 != '\0') {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
LAB_005e22ef:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  ExceptionList = local_1c;
  return;
}

