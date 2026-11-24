
/* WARNING: Removing unreachable block (ram,0x00474e35) */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall CDisplay__DrawObjects(CDisplay *this)

{
  double *pdVar1;
  double *pdVar2;
  char ***pppcVar3;
  char ***pppcVar4;
  char ***pppcVar5;
  float *pfVar6;
  bool bVar7;
  undefined4 uVar8;
  CDisplay *pCVar9;
  char cVar10;
  undefined1 uVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  undefined4 *puVar15;
  int iVar16;
  float **ppfVar17;
  float ***pppfVar18;
  float ***extraout_EDX;
  code *pcVar19;
  int *piVar20;
  float ***pppfVar21;
  float **ppfVar22;
  uint uVar23;
  char ***pppcVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  char ***pppcVar28;
  float fVar29;
  char ***pppcVar30;
  char ***pppcStack_e4;
  float ***pppfStack_e0;
  char ****ppppcStack_dc;
  char ****ppppcStack_d8;
  uint uStack_d4;
  uint local_a8;
  char **local_a4;
  uint local_a0;
  uint local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  uint local_88;
  uint *local_84;
  char **local_80;
  float local_7c;
  int local_78;
  float **local_74;
  undefined4 local_70;
  undefined1 local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float **local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  float local_44;
  undefined4 local_40;
  int *local_3c;
  int local_38;
  float **local_34;
  float **local_30;
  float local_2c;
  CDisplay *local_28;
  float local_24;
  float ***local_20;
  float ***local_1c;
  code *local_18;
  float ***local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006fd9ce;
  local_10 = ExceptionList;
  uStack_d4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ppfVar22 = (float **)0x0;
  _DAT_00767978 = 1 - _DAT_00767978;
  local_58 = (float **)0x0;
  local_8 = 1;
  local_38 = *(int *)(DAT_00772400 + 100);
  ppppcStack_d8 = (char ****)0x473d22;
  local_28 = this;
  local_78 = FUN_005b78b0();
  local_60 = 0.0;
  local_64 = 0.0;
  local_68 = 0.0;
  local_90 = 0;
  local_94 = 0;
  local_98 = 0;
  local_18 = RaiseException_exref;
  if ((*(char *)(DAT_0077241c + 0x29) != '\0') && (DAT_0076a32a != '\0')) {
    uVar23 = 0;
    ppfVar17 = ppfVar22;
    do {
      pppfVar18 = DAT_0076a324 + 0xa4d;
      if (uVar23 < 0x100) {
        pppfVar18 = pppfVar18 + uVar23;
      }
      else {
        ppppcStack_d8 = (char ****)0x0;
        ppppcStack_dc = (char ****)0x0;
        pppfStack_e0 = (float ***)0x1;
        pppcStack_e4 = (char ***)0xc000008c;
        (*local_18)();
      }
      ppfVar22 = *pppfVar18;
      if (ppfVar22 != (float **)0x0) {
        LOCK();
        ppfVar22[1] = (float *)((int)ppfVar22[1] + 1);
        UNLOCK();
      }
      local_58 = ppfVar22;
      if (ppfVar17 != (float **)0x0) {
        LOCK();
        pfVar6 = (float *)((int)ppfVar17[1] + -1);
        ppfVar17[1] = pfVar6;
        UNLOCK();
        if (pfVar6 == (float *)0x0) {
          ppppcStack_d8 = (char ****)0x1;
          ppppcStack_dc = (char ****)0x473dbc;
          (*(code *)**ppfVar17)();
        }
      }
      if (ppfVar22 != (float **)0x0) {
        ppppcStack_d8 = (char ****)0x473dc5;
        iVar12 = FUN_0044d010();
        ppfVar22[0x5b] = (float *)0x0;
        ppfVar22[0x46] = (float *)(iVar12 + 0x7c);
        iVar12 = DAT_00772400;
        ppfVar22[0x5c] = (float *)0x0;
        ppfVar22[4] = *(float **)(iVar12 + 100);
        iVar12 = DAT_0076a338;
        ppfVar22[6] = (float *)0xffffffff;
        ppfVar22[7] = (float *)0xffffffff;
        ppfVar22[5] = *(float **)(iVar12 + 0x38e4);
      }
      uVar23 = uVar23 + 1;
      ppfVar17 = ppfVar22;
      this = local_28;
    } while ((int)uVar23 < 0x100);
  }
  pcVar19 = local_18;
  iVar12 = DAT_0077241c;
  pdVar1 = (double *)(DAT_00772400 + 0xa0b8);
  pdVar2 = (double *)(DAT_00772400 + 0xa0b0);
  *(undefined4 *)(DAT_00772400 + 0xa324) = 0;
  local_3c = (int *)ThreadLocalStoragePointer;
  fVar25 = (float)(*pdVar1 - *pdVar2) * 10.0;
  fVar26 = 0.0;
  if (0.0 <= fVar25) {
    fVar26 = fVar25;
  }
  fVar25 = 1.0;
  if (fVar26 <= 1.0) {
    fVar25 = fVar26;
  }
  if ((*(char *)(iVar12 + 0x29) != '\0') && (DAT_0076a32a != '\0')) {
                    /* WARNING: Load size is inaccurate */
    if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c8ad20) {
      ppppcStack_d8 = (char ****)&DAT_00c8ad20;
      ppppcStack_dc = (char ****)0x474e6d;
      FUN_006cebf4();
      iVar12 = DAT_00783650;
      if (DAT_00c8ad20 == -1) {
        iVar14 = DAT_00783650 * 0x40;
        ppppcStack_d8 = (char ****)&DAT_00c8ad20;
        _DAT_00c8ad24 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar14) = "CDisplay::DrawObjects() DummyRenderjobs";
        *(int *)(&DAT_00773650 + iVar14) = iVar12;
        DAT_00783650 = DAT_00783650 + 1;
        ppppcStack_dc = (char ****)0x474eae;
        FUN_006cebaa();
      }
    }
    ppppcStack_d8 = (char ****)&DAT_00c8ad24;
    ppppcStack_dc = (char ****)0x473ead;
    FUN_00405af0();
    _DAT_00c3c984 = _DAT_00c3c984 + 1;
    local_4c = 0.0;
    local_48 = 0;
    local_44 = this->f_19c48;
    fVar26 = this->f_19c54;
    fVar29 = this->f_19c3c;
    if (this->f_19c3c <= local_44) {
      fVar29 = local_44;
    }
    fVar27 = fVar26;
    if (fVar26 <= this->f_19c60) {
      fVar27 = this->f_19c60;
    }
    if (fVar29 <= fVar27) {
      fVar29 = fVar27;
    }
    pppcVar3 = *(char ****)&this->field_0x19c38;
    pppcVar4 = *(char ****)&this->field_0x19c44;
    local_1c = (float ***)pppcVar4;
    if ((float)pppcVar4 < (float)pppcVar3) {
      local_1c = (float ***)pppcVar3;
    }
    pppcVar5 = *(char ****)&this->field_0x19c50;
    pppcVar24 = *(char ****)&this->field_0x19c5c;
    pppcVar30 = pppcVar24;
    if ((float)pppcVar24 < (float)pppcVar5) {
      pppcVar30 = pppcVar5;
    }
    if ((float)local_1c <= (float)pppcVar30) {
      pppcVar30 = pppcVar24;
      if ((float)pppcVar24 < (float)pppcVar5) {
        pppcVar30 = pppcVar5;
      }
    }
    else {
      pppcVar30 = pppcVar4;
      if ((float)pppcVar4 < (float)pppcVar3) {
        pppcVar30 = pppcVar3;
      }
    }
    fVar27 = this->f_19c3c;
    if (local_44 <= this->f_19c3c) {
      fVar27 = local_44;
    }
    if (this->f_19c60 <= fVar26) {
      fVar26 = this->f_19c60;
    }
    if (fVar26 <= fVar27) {
      fVar27 = fVar26;
    }
    local_1c = (float ***)pppcVar4;
    if ((float)pppcVar3 < (float)pppcVar4) {
      local_1c = (float ***)pppcVar3;
    }
    pppcVar28 = pppcVar24;
    if ((float)pppcVar5 < (float)pppcVar24) {
      pppcVar28 = pppcVar5;
    }
    if ((float)pppcVar28 <= (float)local_1c) {
      if ((float)pppcVar5 < (float)pppcVar24) {
        pppcVar24 = pppcVar5;
      }
    }
    else {
      pppcVar24 = pppcVar3;
      if ((float)pppcVar4 <= (float)pppcVar3) {
        pppcVar24 = pppcVar4;
      }
    }
    ppppcStack_d8 = (char ****)0x8;
    local_a4 = (char **)((int)fVar27 - 0x24U & 0xfffffff8);
    local_9c = (int)fVar29 + 0x2bU & 0xfffffff8;
    local_a8 = (int)(float)pppcVar24 - 0x24U & 0xfffffff8;
    local_a0 = (int)(float)pppcVar30 + 0x2bU & 0xfffffff8;
    ppppcStack_dc = (char ****)&local_a8;
    pppfStack_e0 = (float ***)0x474015;
    FUN_0047e7b0();
    local_44 = (float)(local_9c & 0xfffffff8);
    local_1c = (float ***)((int)local_a4 + 7 & 0xfffffff8);
    puVar13 = (uint *)(local_a8 + 7 & 0xfffffff8);
    local_88 = local_a0 & 0xfffffff8;
    ppppcStack_d8 = (char ****)0x474059;
    FUN_0040ba00();
    local_8._0_1_ = 8;
    uVar23 = local_88;
    ppppcStack_d8 = (char ****)extraout_EDX;
    if ((int)extraout_EDX < (int)local_44) {
      do {
        local_84 = puVar13;
        if ((int)puVar13 < (int)uVar23) {
          do {
            pppfStack_e0 = &local_30;
            pppcStack_e4 = (char ***)0x47409a;
            ppppcStack_dc = (char ****)local_84;
            FUN_005647a0();
            local_5c = local_2c;
            local_7c = 0.0;
            if (0 < (int)local_2c) {
              local_80 = (char **)local_30;
              ppfVar17 = ppfVar22;
              do {
                fVar26 = local_7c;
                if ((uint)local_5c <= (uint)local_7c) {
                  ppppcStack_d8 = (char ****)0x0;
                  ppppcStack_dc = (char ****)0x0;
                  pppfStack_e0 = (float ***)0x1;
                  pppcStack_e4 = (char ***)0xc000008c;
                  (*pcVar19)();
                }
                pppfVar18 = (float ***)local_80[(int)fVar26];
                if (((int)pppfVar18 < 0) || (*(int *)(local_78 + 0xc00c) <= (int)pppfVar18)) {
                  ppppcStack_d8 = (char ****)0x0;
                  ppppcStack_dc = (char ****)0x0;
                  pppfStack_e0 = (float ***)0x1;
                  pppcStack_e4 = (char ***)0xc000008c;
                  (*pcVar19)();
                  iVar12 = *(int *)(local_78 + 0xc008);
                }
                else {
                  iVar12 = (int)pppfVar18 * 0xd8 + *(int *)(local_78 + 0xc008);
                }
                pCVar9 = local_28;
                local_24 = 300.0 / *(float *)&local_28->field_0x2814;
                DAT_00772dd8 = (int)ROUND(local_24);
                *(int *)(iVar12 + 0x58) = *(int *)(iVar12 + 0x58) + 1;
                ppfVar22 = ppfVar17;
                if (*(int *)(iVar12 + 0x74) == local_38) {
                  ppppcStack_d8 = (char ****)(iVar12 + 0xbc);
                  ppppcStack_dc = (char ****)(iVar12 + 200);
                  pppfStack_e0 = (float ***)(iVar12 + 0x9c);
                  pppcStack_e4 = (char ***)(iVar12 + 0x40);
                  cVar10 = FUN_00472e80();
                  if (cVar10 != '\0') {
                    if ((*(char *)(iVar12 + 0x54) != '\0') && (pCVar9[1].field_0x2b4 != '\0')) {
                      *(undefined1 *)(iVar12 + 0x55) = 1;
                    }
                    if (*(char *)(iVar12 + 0x55) == '\0') {
                      if ((((*(int *)(iVar12 + 0x74) == local_38) &&
                           (uVar23 = *(uint *)(iVar12 + 0x78), uVar23 != 0xffffffff)) &&
                          (iVar14 = *(int *)(iVar12 + 0x7c), iVar14 != -1)) &&
                         (*(char *)(iVar12 + 0x84) != '\0')) {
                        piVar20 = (int *)(DAT_00772400 + 0x5c8);
                        if (uVar23 < 0x100) {
                          piVar20 = piVar20 + uVar23;
                        }
                        else {
                          ppppcStack_d8 = (char ****)0x0;
                          ppppcStack_dc = (char ****)0x0;
                          pppfStack_e0 = (float ***)0x1;
                          pppcStack_e4 = (char ***)0xc000008c;
                          (*local_18)();
                          iVar14 = *(int *)(iVar12 + 0x7c);
                        }
                        iVar16 = *piVar20;
                        if ((iVar14 < 0) || (*(int *)(iVar16 + 0x38) <= iVar14)) {
                          ppppcStack_d8 = (char ****)0x0;
                          ppppcStack_dc = (char ****)0x0;
                          pppfStack_e0 = (float ***)0x1;
                          pppcStack_e4 = (char ***)0xc000008c;
                          (*local_18)();
                          iVar14 = *(int *)(iVar16 + 0x34);
                        }
                        else {
                          iVar14 = iVar14 * 0xe8 + *(int *)(iVar16 + 0x34);
                        }
                        if (*(int *)(iVar14 + 0xdc) != -1) {
                          *(undefined1 *)(iVar12 + 0x55) = 1;
                        }
                      }
                      iVar14 = local_38;
                      if (*(char *)(iVar12 + 0x55) != '\0') goto LAB_004742ce;
                    }
                    else {
LAB_004742ce:
                      iVar14 = local_38;
                      ppppcStack_d8 = (char ****)(iVar12 + 0x4c);
                      ppppcStack_dc = (char ****)0x4742d7;
                      FUN_00453f00();
                      if ((*(char *)(iVar12 + 0x84) == '\0') && (*(char *)(iVar12 + 0x85) == '\0'))
                      {
                        *(undefined1 *)(iVar12 + 0x55) = 0;
                      }
                    }
                    if (*(int *)(iVar12 + 0x74) == iVar14) {
                      uVar23 = *(uint *)(iVar12 + 0x78);
                      if (((uVar23 != 0xffffffff) && (*(int *)(iVar12 + 0x50) == 0)) &&
                         (local_24 = *(float *)(iVar12 + 0x7c), local_24 != -NAN)) {
                        pppfVar21 = DAT_0076a324 + 0xa4d;
                        if (uVar23 < 0x100) {
                          pppfVar21 = pppfVar21 + uVar23;
                        }
                        else {
                          ppppcStack_d8 = (char ****)0x0;
                          ppppcStack_dc = (char ****)0x0;
                          pppfStack_e0 = (float ***)0x1;
                          pppcStack_e4 = (char ***)0xc000008c;
                          (*local_18)();
                        }
                        ppfVar22 = *pppfVar21;
                        if (ppfVar22 != (float **)0x0) {
                          LOCK();
                          ppfVar22[1] = (float *)((int)ppfVar22[1] + 1);
                          UNLOCK();
                        }
                        local_58 = ppfVar22;
                        if (ppfVar17 != (float **)0x0) {
                          LOCK();
                          pfVar6 = (float *)((int)ppfVar17[1] + -1);
                          ppfVar17[1] = pfVar6;
                          UNLOCK();
                          if (pfVar6 == (float *)0x0) {
                            ppppcStack_d8 = (char ****)0x1;
                            ppppcStack_dc = (char ****)0x474365;
                            (*(code *)**ppfVar17)();
                          }
                        }
                        if (ppfVar22 != (float **)0x0) {
                          local_20 = (float ***)0x0;
                          if (pppfVar18 < (float ***)0x3001) {
                            ppppcStack_dc = (char ****)0x474386;
                            ppppcStack_d8 = (char ****)pppfVar18;
                            FUN_005b78b0();
                            ppppcStack_dc = (char ****)0x474391;
                            iVar14 = FUN_0047dae0();
                            ppppcStack_d8 = *(char *****)(iVar14 + 0x68);
                          }
                          else {
                            ppppcStack_d8 = (char ****)0xffffffff;
                          }
                          ppppcStack_dc = (char ****)0x4743ab;
                          cVar10 = FUN_005e35a0();
                          local_68 = *(float *)(iVar12 + 0x40);
                          if (cVar10 != '\0') {
                            local_20 = (float ***)&DAT_000000d2;
                          }
                          local_64 = *(float *)(iVar12 + 0x44);
                          fVar26 = *(float *)(iVar12 + 0x48);
                          if (*(char *)(iVar12 + 0x85) != '\0') {
                            local_68 = local_68 + fVar25 * *(float *)(iVar12 + 0x90);
                            local_64 = local_64 + *(float *)(iVar12 + 0x94) * fVar25;
                            fVar26 = fVar26 + *(float *)(iVar12 + 0x98) * fVar25;
                          }
                          local_60 = fVar26 * 0.5 + 7.0;
                          local_98 = *(undefined4 *)(iVar12 + 0x9c);
                          local_94 = *(undefined4 *)(iVar12 + 0xa0);
                          local_90 = *(undefined4 *)(iVar12 + 0xa4);
                          iVar14 = *(int *)(iVar12 + 0xac);
                          if (iVar14 < 0x80) {
                            iVar16 = iVar14 * 4 + -0x100;
                            if (iVar16 < 0) {
                              iVar16 = 0;
                            }
                            local_40 = CONCAT31(local_40._1_3_,(char)iVar16);
                          }
                          else {
                            local_40 = CONCAT31(local_40._1_3_,0xff);
                          }
                          local_54 = CONCAT31(local_54._1_3_,(char)iVar14);
                          if (*(int *)(*local_3c + 4) < DAT_00c8ad28) {
                            ppppcStack_d8 = (char ****)&DAT_00c8ad28;
                            ppppcStack_dc = (char ****)0x474ec0;
                            FUN_006cebf4();
                            iVar14 = DAT_00783650;
                            if (DAT_00c8ad28 == -1) {
                              iVar16 = DAT_00783650 * 0x40;
                              ppppcStack_d8 = (char ****)&DAT_00c8ad28;
                              _DAT_00c8ad2c = DAT_00783650;
                              *(char **)(&DAT_0077368c + iVar16) =
                                   "CDisplay::DrawObjects() DummyRenderjobs Rendering";
                              *(int *)(&DAT_00773650 + iVar16) = iVar14;
                              DAT_00783650 = DAT_00783650 + 1;
                              ppppcStack_dc = (char ****)0x474f01;
                              FUN_006cebaa();
                            }
                          }
                          ppppcStack_d8 = (char ****)&DAT_00c8ad2c;
                          ppppcStack_dc = (char ****)0x4744b6;
                          FUN_00405af0();
                          local_8 = CONCAT31(local_8._1_3_,9);
                          if (*(char *)(DAT_00772400 + 0x590) == '\0') {
LAB_004744c9:
                            pppcStack_e4 = (char ***)(uint)*(byte *)(iVar12 + 0x84);
                            ppppcStack_d8 = (char ****)0x0;
                            ppppcStack_dc = (char ****)0xffffffff;
                            pppfStack_e0 = *(float ****)(iVar12 + 0x88);
                            uVar11 = FUN_00486790(iVar12 + 0x4c,local_24,
                                                  *(undefined4 *)(iVar12 + 0x8c),&local_68,&local_98
                                                  ,local_20,0,0,local_40,local_54,iVar12 + 0x5c);
                          }
                          else {
                            if (pppfVar18 != *(float ****)(DAT_00772400 + 0xa0c0)) {
                              if ((*(char *)(DAT_00772400 + 0xa3e3) != '\0') &&
                                 (uVar23 = *(uint *)(iVar12 + 0x68), uVar23 != 0xffffffff)) {
                                piVar20 = (int *)(DAT_0077244c + 0x488);
                                if (uVar23 < 0x2000) {
                                  piVar20 = piVar20 + uVar23;
                                }
                                else {
                                  ppppcStack_d8 = (char ****)0x0;
                                  ppppcStack_dc = (char ****)0x0;
                                  pppfStack_e0 = (float ***)0x1;
                                  pppcStack_e4 = (char ***)0xc000008c;
                                  (*local_18)();
                                }
                                if (*piVar20 != 0) {
                                  piVar20 = (int *)(DAT_0077244c + 0x488);
                                  if (*(uint *)(iVar12 + 0x68) < 0x2000) {
                                    piVar20 = piVar20 + *(uint *)(iVar12 + 0x68);
                                  }
                                  else {
                                    ppppcStack_d8 = (char ****)0x0;
                                    ppppcStack_dc = (char ****)0x0;
                                    pppfStack_e0 = (float ***)0x1;
                                    pppcStack_e4 = (char ***)0xc000008c;
                                    (*local_18)();
                                  }
                                  if ((*(byte *)(*piVar20 + 0x3d0) & 0x10) != 0) goto LAB_00474624;
                                }
                              }
                              if ((*(char *)(DAT_00772400 + 0xa3e4) != '\0') &&
                                 (uVar23 = *(uint *)(iVar12 + 0x68), uVar23 != 0xffffffff)) {
                                piVar20 = (int *)(DAT_0077244c + 0x488);
                                if (uVar23 < 0x2000) {
                                  piVar20 = piVar20 + uVar23;
                                }
                                else {
                                  ppppcStack_d8 = (char ****)0x0;
                                  ppppcStack_dc = (char ****)0x0;
                                  pppfStack_e0 = (float ***)0x1;
                                  pppcStack_e4 = (char ***)0xc000008c;
                                  (*local_18)();
                                }
                                if (*piVar20 != 0) {
                                  piVar20 = (int *)(DAT_0077244c + 0x488);
                                  if (*(uint *)(iVar12 + 0x68) < 0x2000) {
                                    piVar20 = piVar20 + *(uint *)(iVar12 + 0x68);
                                  }
                                  else {
                                    ppppcStack_d8 = (char ****)0x0;
                                    ppppcStack_dc = (char ****)0x0;
                                    pppfStack_e0 = (float ***)0x1;
                                    pppcStack_e4 = (char ***)0xc000008c;
                                    (*local_18)();
                                  }
                                  if ((*(uint *)(*piVar20 + 0x3d0) & 0x80000) != 0)
                                  goto LAB_00474624;
                                }
                              }
                              goto LAB_004744c9;
                            }
LAB_00474624:
                            pppcStack_e4 = (char ***)(uint)*(byte *)(iVar12 + 0x84);
                            ppppcStack_d8 = (char ****)0x0;
                            ppppcStack_dc = (char ****)0xffffffff;
                            pppfStack_e0 = *(float ****)(iVar12 + 0x88);
                            uVar11 = FUN_004877b0(iVar12 + 0x4c,local_24,
                                                  *(undefined4 *)(iVar12 + 0x8c),&local_68,&local_98
                                                  ,local_20,0,0,local_40,local_54,iVar12 + 0x5c);
                          }
                          local_8._0_1_ = 8;
                          *(undefined1 *)(iVar12 + 0xd4) = uVar11;
                          ppppcStack_d8 = (char ****)0x474687;
                          FUN_0043fd30();
                        }
                      }
                      if (*(char *)(iVar12 + 0xd4) != '\0') {
                        ppppcStack_d8 = (char ****)(iVar12 + 0x4c);
                        *(undefined4 *)(iVar12 + 0x58) = 0;
                        ppppcStack_dc = (char ****)0x4746a0;
                        FUN_0044d010();
                        ppppcStack_dc = (char ****)0x4746a7;
                        FUN_0044d760();
                        *(int *)(DAT_00772400 + 0xa324) = *(int *)(DAT_00772400 + 0xa324) + 1;
                      }
                    }
                  }
                }
                if (0x31 < *(int *)(iVar12 + 0x58)) {
                  ppppcStack_d8 = (char ****)(iVar12 + 0x4c);
                  ppppcStack_dc = (char ****)0x4746c1;
                  FUN_00453f00();
                }
                local_7c = (float)((int)local_7c + 1);
                pcVar19 = local_18;
                ppfVar17 = ppfVar22;
              } while ((int)local_7c < (int)local_5c);
            }
            local_84 = local_84 + 2;
            uVar23 = local_88;
            ppppcStack_d8 = (char ****)local_1c;
            pcVar19 = local_18;
          } while ((int)local_84 < (int)local_88);
        }
        ppppcStack_d8 = (char ****)((float ***)ppppcStack_d8 + 2);
        pcVar19 = local_18;
        local_1c = (float ***)ppppcStack_d8;
      } while ((int)ppppcStack_d8 < (int)local_44);
    }
    ppppcStack_d8 = (char ****)0x474709;
    FUN_0047c270();
    ppppcStack_d8 = (char ****)0x474710;
    FUN_0047c4c0();
    ppppcStack_d8 = (char ****)0x0;
    local_8 = CONCAT31(local_8._1_3_,10);
    ppppcStack_dc = (char ****)0x47471e;
    FUN_0040b980();
    if (local_30 != (float **)0x0) {
      ppppcStack_d8 = (char ****)0x47472a;
      FUN_006ba940();
    }
    ppppcStack_d8 = (char ****)0x0;
    local_8 = CONCAT31(local_8._1_3_,0xb);
    ppppcStack_dc = (char ****)0x474738;
    FUN_0047e280();
    if (local_4c != 0.0) {
      ppppcStack_d8 = (char ****)0x474744;
      FUN_006ba940();
    }
    ppppcStack_d8 = (char ****)0x474757;
    FUN_0043fd30();
  }
  local_74 = (float **)0x0;
  local_70 = 0;
  local_6c = 0;
  piVar20 = (int *)*local_3c;
  local_3c = piVar20;
  if (*(int *)((int)piVar20 + 4) < DAT_00c8ad30) {
    ppppcStack_d8 = (char ****)&DAT_00c8ad30;
    ppppcStack_dc = (char ****)0x474f13;
    FUN_006cebf4();
    iVar12 = DAT_00783650;
    if (DAT_00c8ad30 == -1) {
      iVar14 = DAT_00783650 * 0x40;
      ppppcStack_d8 = (char ****)&DAT_00c8ad30;
      _DAT_00c8ad34 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar14) = "CDisplay::DrawObjects() AlphaObjs";
      *(int *)(&DAT_00773650 + iVar14) = iVar12;
      DAT_00783650 = DAT_00783650 + 1;
      ppppcStack_dc = (char ****)0x474f54;
      FUN_006cebaa();
    }
  }
  ppppcStack_d8 = (char ****)&DAT_00c8ad34;
  ppppcStack_dc = (char ****)0x4747a3;
  FUN_00405af0();
  pCVar9 = local_28;
  local_8 = CONCAT31(local_8._1_3_,0xf);
  ppppcStack_d8 = (char ****)0x4747b1;
  FUN_0046aa40();
  ppppcStack_d8 = (char ****)0x4747b6;
  iVar12 = FUN_004ecd40();
  pCVar9->field_0xf0 = *(undefined1 *)(iVar12 + 0x11a);
  ppppcStack_d8 = (char ****)0x4747c9;
  FUN_0046b450();
  ppppcStack_d8 = (char ****)0x4747dc;
  FUN_0043fd30();
  if (*(int *)((int)piVar20 + 4) < DAT_00c8ad38) {
    ppppcStack_d8 = (char ****)&DAT_00c8ad38;
    ppppcStack_dc = (char ****)0x474f66;
    FUN_006cebf4();
    iVar12 = DAT_00783650;
    if (DAT_00c8ad38 == -1) {
      iVar14 = DAT_00783650 * 0x40;
      ppppcStack_d8 = (char ****)&DAT_00c8ad38;
      _DAT_00c8ad3c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar14) = "CDisplay::DrawObjects() SelHoverGlow";
      *(int *)(&DAT_00773650 + iVar14) = iVar12;
      DAT_00783650 = DAT_00783650 + 1;
      ppppcStack_dc = (char ****)0x474fa7;
      FUN_006cebaa();
    }
  }
  ppppcStack_d8 = (char ****)&DAT_00c8ad3c;
  ppppcStack_dc = (char ****)0x4747fa;
  FUN_00405af0();
  local_8._0_1_ = 0x10;
  local_2c = 0.0;
  local_30 = (float **)(DAT_00772400 + 0xa0c4);
  if ((*(char *)(DAT_00772400 + 0x590) == '\0') && (*(char *)(DAT_00772400 + 0x8c) == '\0')) {
    ppppcStack_d8 = (char ****)&local_1c;
    bVar7 = false;
    ppppcStack_dc = (char ****)&local_2c;
    pppfStack_e0 = (float ***)0x47483c;
    FUN_005e3700();
    ppppcStack_d8 = (char ****)local_1c;
    while (local_1c = (float ***)ppppcStack_d8, ppppcStack_d8 != (char ****)0xffffffff) {
      ppppcStack_dc = (char ****)0x47484a;
      pppfStack_e0 = (float ***)FUN_0055aa20();
      if (pppfStack_e0 != (float ***)0xffffffff) {
        ppfVar17 = (float **)0xffffffff;
        if ((pppfStack_e0 == (float ***)*(char ****)(DAT_00772400 + 0xa0c0)) &&
           (*(int *)(DAT_00772400 + 0xa0d0) == -1)) {
          bVar7 = true;
          ppfVar17 = DAT_0076a324[0x1179];
          if (ppfVar17 == (float **)0x0) goto LAB_00474889;
        }
        ppppcStack_dc = (char ****)((uint)ppfVar17 | 0xff000000);
        pppcStack_e4 = (char ***)0x474889;
        ppppcStack_d8 = ppppcStack_dc;
        FUN_004716f0();
      }
LAB_00474889:
      ppppcStack_d8 = (char ****)&local_1c;
      ppppcStack_dc = (char ****)&local_2c;
      pppfStack_e0 = (float ***)0x474899;
      FUN_005e3700();
      ppppcStack_d8 = (char ****)local_1c;
    }
    pppfVar18 = *(float ****)(DAT_00772400 + 0xa0c0);
    if ((((pppfVar18 != (float ***)0xffffffff) && (!bVar7)) &&
        (*(int *)(DAT_00772400 + 0xa0d0) == -1)) && (DAT_0076a324[0x1179] != (float **)0x0)) {
      ppppcStack_dc = (char ****)((uint)DAT_0076a324[0x1179] | 0xff000000);
      pppcStack_e4 = (char ***)0x4748da;
      pppfStack_e0 = pppfVar18;
      ppppcStack_d8 = (char ****)pppfVar18;
      FUN_004716f0();
    }
  }
  local_8 = CONCAT31(local_8._1_3_,0xd);
  ppppcStack_d8 = (char ****)0x4748f1;
  FUN_0043fd30();
  if ((*(char *)(DAT_0077241c + 0x29) != '\0') && (DAT_0076a32a != '\0')) {
    uVar23 = 0;
    ppfVar17 = ppfVar22;
    do {
      pppfVar18 = DAT_0076a324 + 0xa4d;
      if (uVar23 < 0x100) {
        pppfVar18 = pppfVar18 + uVar23;
      }
      else {
        ppppcStack_d8 = (char ****)0x0;
        ppppcStack_dc = (char ****)0x0;
        pppfStack_e0 = (float ***)0x1;
        pppcStack_e4 = (char ***)0xc000008c;
        (*local_18)();
      }
      ppfVar22 = *pppfVar18;
      if (ppfVar22 != (float **)0x0) {
        LOCK();
        ppfVar22[1] = (float *)((int)ppfVar22[1] + 1);
        UNLOCK();
      }
      local_58 = ppfVar22;
      if (ppfVar17 != (float **)0x0) {
        LOCK();
        pfVar6 = (float *)((int)ppfVar17[1] + -1);
        ppfVar17[1] = pfVar6;
        UNLOCK();
        if (pfVar6 == (float *)0x0) {
          ppppcStack_d8 = (char ****)0x1;
          ppppcStack_dc = (char ****)0x47495a;
          (*(code *)**ppfVar17)();
        }
      }
      if (ppfVar22 != (float **)0x0) {
        ppppcStack_d8 = (char ****)0x474963;
        FUN_0044d010();
      }
      uVar23 = uVar23 + 1;
      ppfVar17 = ppfVar22;
      piVar20 = local_3c;
    } while ((int)uVar23 < 0x100);
  }
  DAT_0076a320 = DAT_0076a320 + 0.1;
  if ((*(char *)(DAT_0077241c + 0x29) != '\0') && (DAT_0076a32a != '\0')) {
    if (*(int *)((int)piVar20 + 4) < DAT_00c8ad40) {
      ppppcStack_d8 = (char ****)&DAT_00c8ad40;
      ppppcStack_dc = (char ****)0x474fb9;
      FUN_006cebf4();
      iVar12 = DAT_00783650;
      if (DAT_00c8ad40 == -1) {
        iVar14 = DAT_00783650 * 0x40;
        ppppcStack_d8 = (char ****)&DAT_00c8ad40;
        _DAT_00c8ad44 = DAT_00783650;
        *(char **)(&DAT_0077368c + iVar14) = "CDisplay::DrawObjects() Particles";
        *(int *)(&DAT_00773650 + iVar14) = iVar12;
        DAT_00783650 = DAT_00783650 + 1;
        ppppcStack_dc = (char ****)0x474ffa;
        FUN_006cebaa();
      }
    }
    ppppcStack_d8 = (char ****)&DAT_00c8ad44;
    ppppcStack_dc = (char ****)0x4749b9;
    FUN_00405af0();
    local_8._0_1_ = 0x11;
    if (DAT_00768379 != '\0') {
      ppppcStack_d8 = (char ****)0x4749cb;
      iVar12 = FUN_0044d010();
      ppppcStack_d8 = (char ****)(iVar12 + 0x7c);
      ppppcStack_dc = (char ****)0x4749d4;
      FUN_00492250();
      ppppcStack_dc = (char ****)0x4749db;
      FUN_00498590();
    }
    local_8 = CONCAT31(local_8._1_3_,0xd);
    ppppcStack_d8 = (char ****)0x4749f2;
    FUN_0043fd30();
  }
  ppppcStack_dc = (char ****)&local_20;
  ppppcStack_d8 = (char ****)0x723f30;
  pppfStack_e0 = (float ***)0x474a00;
  FUN_0044d010();
  pppfStack_e0 = (float ***)0x474a07;
  FUN_0044d570();
  if (local_20 != (float ***)0x0) {
    local_20[2] = (float **)0x1d;
    local_14 = (float ***)&ppppcStack_d8;
    *(undefined1 *)((int)local_20 + 0x55) = 1;
    ppppcStack_d8 = (char ****)local_20;
    if (local_20 != (float ***)0x0) {
      LOCK();
      local_20[1] = (float **)((int)local_20[1] + 1);
      UNLOCK();
    }
    local_8._0_1_ = 0x13;
    ppppcStack_dc = (char ****)0x474a3b;
    FUN_0044d010();
    local_8 = CONCAT31(local_8._1_3_,0x12);
    ppppcStack_dc = (char ****)0x474a46;
    FUN_0044d6e0();
  }
  local_8 = CONCAT31(local_8._1_3_,0xd);
  if (local_20 != (float ***)0x0) {
    LOCK();
    ppfVar17 = (float **)((int)local_20[1] + -1);
    local_20[1] = ppfVar17;
    UNLOCK();
    if (ppfVar17 == (float **)0x0) {
      ppppcStack_d8 = (char ****)0x1;
      ppppcStack_dc = (char ****)0x474a61;
      (*(code *)**local_20)();
    }
  }
  ppppcStack_d8 = (char ****)0x474a66;
  FUN_0044d010();
  ppppcStack_dc = (char ****)0x474a6c;
  FUN_004d2000();
  ppppcStack_dc = (char ****)0x474a73;
  FUN_004d2050();
  if (*(int *)((int)piVar20 + 4) < DAT_00c8ad48) {
    ppppcStack_d8 = (char ****)&DAT_00c8ad48;
    ppppcStack_dc = (char ****)0x47500c;
    FUN_006cebf4();
    iVar12 = DAT_00783650;
    if (DAT_00c8ad48 == -1) {
      iVar14 = DAT_00783650 * 0x40;
      ppppcStack_d8 = (char ****)&DAT_00c8ad48;
      _DAT_00c8ad4c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar14) = "CDisplay::DrawObjects() Specials";
      *(int *)(&DAT_00773650 + iVar14) = iVar12;
      DAT_00783650 = DAT_00783650 + 1;
      ppppcStack_dc = (char ****)0x47504d;
      FUN_006cebaa();
    }
  }
  ppppcStack_d8 = (char ****)&DAT_00c8ad4c;
  ppppcStack_dc = (char ****)0x474a91;
  FUN_00405af0();
  local_8._0_1_ = 0x14;
  ppppcStack_d8 = (char ****)0x474a9f;
  FUN_0046a210();
  ppppcStack_d8 = (char ****)0x474aa6;
  FUN_00472190();
  ppppcStack_d8 = (char ****)0x474aad;
  FUN_00471ae0();
  ppppcStack_d8 = (char ****)0x474ab4;
  FUN_00469fc0();
  ppppcStack_d8 = (char ****)0x474abb;
  FUN_004695b0();
  ppppcStack_d8 = (char ****)0x474ac0;
  FUN_00466af0();
  ppppcStack_d8 = (char ****)0x474ac7;
  FUN_0047b290();
  ppppcStack_d8 = (char ****)0x474ace;
  FUN_00471600();
  local_8 = CONCAT31(local_8._1_3_,0xd);
  ppppcStack_d8 = (char ****)0x474ae5;
  FUN_0043fd30();
  ppppcStack_d8 = (char ****)0x474aea;
  iVar12 = FUN_0044d010();
  ppppcStack_d8 = (char ****)(iVar12 + 0x7c);
  ppppcStack_dc = (char ****)0x474aff;
  FUN_00486000();
  iVar12 = DAT_00772400;
  local_48 = 0x40000000;
  local_4c = 0.0 - (float)*(int *)(DAT_00772400 + 0x1cc);
  local_50 = 0.0 - (float)*(int *)(DAT_00772400 + 0x1c8);
  ppppcStack_d8 = (char ****)0x474b42;
  FUN_00410a20();
  ppppcStack_d8 = (char ****)&local_34;
  local_30 = (float **)(float)*(int *)(iVar12 + 0x1cc);
  ppppcStack_dc = (char ****)&local_a4;
  local_2c = 15.006;
  local_34 = (float **)(float)*(int *)(iVar12 + 0x1c8);
  pppfStack_e0 = (float ***)0x474b7f;
  puVar15 = (undefined4 *)FUN_00479150();
  local_34 = (float **)*puVar15;
  local_30 = (float **)puVar15[1];
  local_2c = (float)puVar15[2];
  ppppcStack_d8 = (char ****)0x474ba1;
  iVar12 = FUN_00463e90();
  local_14 = (float ***)0xffff;
  if (DAT_0076a328 != '\0') {
    local_14 = (float ***)0x5294;
  }
  if (((DAT_0076a324[0x1168] == (float **)0x0) || (DAT_0076a328 == '\0')) ||
     (*(char *)(DAT_00772400 + 0x590) != '\0')) goto LAB_00474de4;
  if (*(int *)((int)local_3c + 4) < DAT_00c8ad50) {
    ppppcStack_d8 = (char ****)&DAT_00c8ad50;
    ppppcStack_dc = (char ****)0x47505f;
    FUN_006cebf4();
    iVar14 = DAT_00783650;
    if (DAT_00c8ad50 == -1) {
      iVar16 = DAT_00783650 * 0x40;
      ppppcStack_d8 = (char ****)&DAT_00c8ad50;
      _DAT_00c8ad54 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar16) = "CDisplay::DrawObjects() Mouse";
      *(int *)(&DAT_00773650 + iVar16) = iVar14;
      DAT_00783650 = DAT_00783650 + 1;
      ppppcStack_dc = (char ****)0x4750a0;
      FUN_006cebaa();
    }
  }
  ppppcStack_d8 = (char ****)&DAT_00c8ad54;
  ppppcStack_dc = (char ****)0x474c08;
  FUN_00405af0();
  local_8 = CONCAT31(local_8._1_3_,0x15);
  cVar10 = '\0';
  ppppcStack_d8 = (char ****)0x474c13;
  iVar14 = FUN_00501450();
  if (*(int *)(iVar14 + 0x8198) != 0) {
    ppppcStack_d8 = (char ****)0x474c21;
    iVar14 = FUN_00501450();
    ppppcStack_d8 = (char ****)0x474c2e;
    cVar10 = (**(code **)(**(int **)(iVar14 + 0x8198) + 0x30))();
  }
  uVar8 = local_48;
  fVar25 = local_4c;
  fVar26 = local_50;
  iVar14 = DAT_00772400;
  pppfVar18 = DAT_0076a324;
  if ((*(int *)(DAT_00772400 + 0xa0c0) == -1) && (cVar10 == '\0')) {
    ppfVar17 = DAT_0076a324[0x116d] + 4;
    if (0xff < (int)ppfVar17) {
      ppfVar17 = (float **)0xff;
    }
  }
  else {
    ppfVar17 = DAT_0076a324[0x116d] + -4;
    if ((int)ppfVar17 < 0xb4) {
      ppfVar17 = (float **)0xb4;
    }
  }
  DAT_0076a324[0x116d] = ppfVar17;
  if (iVar12 != -1) {
    ppppcStack_d8 = (char ****)pppfVar18;
    ppppcStack_dc = (char ****)0xff;
    local_50 = 1.3207964;
    pppfStack_e0 = (float ***)0x3e99999a;
    pppcStack_e4 = (char ***)0x3fc00000;
    local_4c = 0.0;
    local_48 = 0;
    FUN_00488270(&local_74,iVar12,pppfVar18,&local_34,&local_50,*(float *)(iVar14 + 0x360) * 0.66,
                 local_14,fVar26,fVar25,uVar8);
    ppppcStack_d8 = (char ****)&local_74;
    ppppcStack_dc = (char ****)0x474d0e;
    FUN_0044d010();
    ppppcStack_dc = (char ****)0x474d15;
    FUN_0044d760();
    pppfVar18 = DAT_0076a324;
  }
  if (*(char *)((int)pppfVar18 + 0x45ca) != '\0') {
    ppfVar17 = pppfVar18[0x1176];
    if (ppfVar17 == (float **)0x0) {
      ppppcStack_d8 = (char ****)0x0;
      local_8._0_1_ = 0x16;
LAB_00474dbd:
      local_14 = (float ***)&pppcStack_e4;
      ppppcStack_dc = (char ****)0x416f3333;
      pppcStack_e4 = (char ***)pppfVar18[0x1173];
      pppfStack_e0 = (float ***)pppfVar18[0x1174];
      FUN_00566460();
      local_8 = CONCAT31(local_8._1_3_,0x15);
      FUN_0056d0b0();
    }
    else if (ppfVar17 == (float **)0x1) {
      local_14 = (float ***)&pppfStack_e0;
      ppppcStack_d8 = (char ****)0x416f3333;
      local_8._0_1_ = 0x17;
      pppcStack_e4 = (char ***)0x474d92;
      pppfStack_e0 = (float ***)pppfVar18[0x1173];
      ppppcStack_dc = (char ****)pppfVar18[0x1174];
      FUN_00566460();
      local_8 = CONCAT31(local_8._1_3_,0x15);
      pppcStack_e4 = (char ***)0x474d9d;
      FUN_0056c530();
    }
    else if (ppfVar17 == (float **)0x3) {
      ppppcStack_d8 = (char ****)0x1;
      local_8._0_1_ = 0x18;
      goto LAB_00474dbd;
    }
  }
  local_8 = CONCAT31(local_8._1_3_,0xd);
  ppppcStack_d8 = (char ****)0x474de4;
  FUN_0043fd30();
LAB_00474de4:
  ppppcStack_d8 = (char ****)0x474de9;
  FUN_0044d010();
  DAT_0076a320 = DAT_0076a320 + 0.1;
  local_8 = CONCAT31(local_8._1_3_,0x19);
  ppppcStack_dc = (char ****)0x474e0e;
  FUN_00453f00();
  if (local_74 != (float **)0x0) {
    ppppcStack_d8 = (char ****)0x474e1a;
    FUN_006ba940();
  }
  ppppcStack_d8 = (char ****)0x0;
  local_8 = CONCAT31(local_8._1_3_,0x1a);
  ppppcStack_dc = (char ****)0x474e2b;
  FUN_0047e280();
  if (ppfVar22 != (float **)0x0) {
    LOCK();
    ppfVar17 = ppfVar22 + 1;
    pfVar6 = *ppfVar17;
    *ppfVar17 = (float *)((int)*ppfVar17 + -1);
    UNLOCK();
    if (pfVar6 == (float *)0x1) {
      ppppcStack_d8 = (char ****)0x1;
      ppppcStack_dc = (char ****)0x474e51;
      (*(code *)**ppfVar22)();
    }
  }
  ExceptionList = local_10;
  return;
}

