
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
FUN_0042eaf0(undefined4 *param_1,float *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int *param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  CMap *pCVar6;
  char cVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  float fVar16;
  CMapCell *pCVar17;
  undefined4 extraout_ECX;
  int iVar18;
  int iVar19;
  float fVar20;
  bool bVar21;
  float fVar22;
  float in_XMM3_Da;
  float fVar23;
  float local_58;
  float local_54;
  CMap *local_50;
  float *local_4c;
  uint local_48;
  uint local_44;
  float local_40;
  float local_3c;
  float local_38;
  uint local_34;
  int local_30;
  undefined4 local_2c;
  float local_28;
  int local_24;
  CMap *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fae66;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_2c = 0;
  local_28 = in_XMM3_Da;
  piVar8 = (int *)Tcl_NewListObj(0,0,DAT_0076700c ^ (uint)&stack0xfffffffc);
  *param_1 = piVar8;
  if (piVar8 != (int *)0x0) {
    *piVar8 = *piVar8 + 1;
  }
  local_2c = 1;
  iVar9 = (int)(*param_2 + local_28);
  iVar18 = (int)(*param_2 - local_28);
  iVar10 = PTR_0077241c->cellX0 + 10;
  iVar11 = PTR_0077241c->cellX1 + -10;
  iVar12 = PTR_0077241c->cellY0 + 10;
  local_4c = (float *)0x0;
  iVar15 = PTR_0077241c->cellY1 + -10;
  iVar19 = (int)(param_2[1] + local_28 * 0.3);
  if (iVar10 <= iVar18) {
    iVar10 = iVar18;
  }
  uVar13 = iVar10 << 3;
  iVar10 = (int)(param_2[1] - local_28 * 0.3);
  if (iVar12 <= iVar10) {
    iVar12 = iVar10;
  }
  local_14 = iVar12 * 8;
  if (iVar9 <= iVar11) {
    iVar11 = iVar9;
  }
  iVar11 = iVar11 << 3;
  if (iVar19 <= iVar15) {
    iVar15 = iVar19;
  }
  local_28 = (float)(iVar15 << 3);
  local_48 = 0;
  local_8 = 1;
  local_24 = iVar11;
  local_1c = uVar13;
  if ((int)local_14 <= (int)local_28) {
    do {
      local_18 = uVar13;
      if ((int)uVar13 <= iVar11) {
        local_30 = (int)local_14 >> 3;
        local_34 = (local_14 & 7) << 3;
        do {
          pCVar6 = PTR_0077241c;
          local_38 = (float)((int)local_18 >> 3);
          local_20 = PTR_0077241c;
          fVar20 = (float)PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= (int)local_38) {
            fVar20 = local_38;
          }
          iVar10 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= local_30) {
            iVar10 = local_30;
          }
          iVar15 = PTR_0077241c->cellY1 + -1;
          if (iVar10 < PTR_0077241c->cellY1) {
            iVar15 = iVar10;
          }
          fVar16 = (float)(PTR_0077241c->cellX1 + -1);
          if ((int)fVar20 < PTR_0077241c->cellX1) {
            fVar16 = fVar20;
          }
          iVar10 = (iVar15 * PTR_0077241c->mapWidth + (int)fVar16) % PTR_0077241c->cellCountTotal;
          if ((iVar10 < 0) || (PTR_0077241c->cellCount <= iVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar17 = pCVar6->cells;
          }
          else {
            pCVar17 = PTR_0077241c->cells + iVar10;
          }
          pCVar6 = PTR_0077241c;
          local_40 = (float)(local_18 & 7);
          if ((pCVar17->sampleFlags[(uint)local_40 | local_34] & 2) != 0) {
            local_3c = (float)(local_14 + 1);
            local_20 = PTR_0077241c;
            fVar20 = (float)PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= (int)local_38) {
              fVar20 = local_38;
            }
            iVar10 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= (int)local_3c >> 3) {
              iVar10 = (int)local_3c >> 3;
            }
            iVar15 = PTR_0077241c->cellY1 + -1;
            if (iVar10 < PTR_0077241c->cellY1) {
              iVar15 = iVar10;
            }
            fVar16 = (float)(PTR_0077241c->cellX1 + -1);
            if ((int)fVar20 < PTR_0077241c->cellX1) {
              fVar16 = fVar20;
            }
            iVar10 = (iVar15 * PTR_0077241c->mapWidth + (int)fVar16) % PTR_0077241c->cellCountTotal;
            if ((iVar10 < 0) || (PTR_0077241c->cellCount <= iVar10)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar17 = pCVar6->cells;
            }
            else {
              pCVar17 = PTR_0077241c->cells + iVar10;
            }
            if ((pCVar17->sampleFlags[((uint)local_3c & 7) << 3 | (uint)local_40] & 2) == 0) {
              local_54 = (float)(int)local_14 * 0.125;
              local_58 = (float)(int)local_18 * 0.125;
              local_20 = (CMap *)0x40000000;
              do {
                uVar13 = local_44;
                local_50 = local_20;
                if (((*(float *)((int)param_6 + 8) * 0.01 + (float)local_20 <= 13.0) &&
                    (cVar7 = FUN_005e76a0(param_4,*(undefined4 *)(local_44 + 0x14)), cVar7 == '\0'))
                   && (cVar7 = FUN_005e6be0(param_6,0xffffffff,0xffffffff,
                                            *(undefined4 *)(uVar13 + 0x14),extraout_ECX),
                      cVar7 == '\0')) {
                  local_40 = local_58 - *param_2;
                  local_3c = local_54 - param_2[1];
                  local_38 = (float)local_50 - param_2[2];
                  FUN_0042f8e0(1);
                  local_4c[local_48 * 3 + -3] = local_40;
                  local_4c[local_48 * 3 + -2] = local_3c;
                  local_4c[local_48 * 3 + -1] = local_38;
                }
                local_20 = (CMap *)((float)local_20 + 1.0);
              } while ((float)local_20 < 12.5);
            }
          }
          local_18 = local_18 + 0x10;
          uVar13 = local_1c;
          iVar11 = local_24;
        } while ((int)local_18 <= local_24);
      }
      local_14 = local_14 + 1;
    } while ((int)local_14 <= (int)local_28);
  }
  local_44 = local_48;
  if (1 < (int)local_48) {
    iVar10 = local_48 - 1;
    iVar15 = 0;
    param_6 = (int *)(iVar10 * 0xc);
    if (local_48 == 2) {
      fVar20 = local_4c[1];
      fVar16 = *local_4c;
      fVar2 = local_4c[2];
      fVar23 = local_4c[iVar10 * 3];
      if (fVar23 * fVar23 + (local_4c + 1)[iVar10 * 3] * (local_4c + 1)[iVar10 * 3] +
          (local_4c + 2)[iVar10 * 3] * (local_4c + 2)[iVar10 * 3] <
          fVar16 * fVar16 + fVar20 * fVar20 + fVar2 * fVar2) {
        *local_4c = fVar23;
        local_4c[1] = (local_4c + 1)[iVar10 * 3];
        local_4c[2] = (local_4c + 2)[iVar10 * 3];
        local_4c[iVar10 * 3] = fVar16;
        (local_4c + 1)[iVar10 * 3] = fVar20;
        (local_4c + 2)[iVar10 * 3] = fVar2;
      }
    }
    else {
      iVar11 = iVar10 / 2;
      fVar20 = local_4c[iVar11 * 3];
      fVar16 = local_4c[iVar11 * 3 + 1];
      fVar2 = local_4c[iVar11 * 3 + 2];
      local_4c[iVar11 * 3] = local_4c[iVar10 * 3];
      local_4c[iVar11 * 3 + 1] = (local_4c + 1)[iVar10 * 3];
      local_4c[iVar11 * 3 + 2] = (local_4c + 2)[iVar10 * 3];
      fVar23 = fVar20 * fVar20 + fVar16 * fVar16 + fVar2 * fVar2;
      local_4c[iVar10 * 3] = fVar20;
      (local_4c + 1)[iVar10 * 3] = fVar16;
      (local_4c + 2)[iVar10 * 3] = fVar2;
      piVar8 = param_6;
      iVar11 = iVar10;
      param_3 = iVar10;
      while( true ) {
        iVar12 = iVar15 * 3 + 2;
        fVar22 = local_4c[iVar15 * 3] * local_4c[iVar15 * 3] +
                 local_4c[iVar15 * 3 + 1] * local_4c[iVar15 * 3 + 1] +
                 local_4c[iVar12] * local_4c[iVar12];
        pfVar5 = local_4c + iVar12;
        for (; (fVar22 <= fVar23 && (iVar15 < iVar11)); iVar15 = iVar15 + 1) {
          fVar22 = pfVar5[3];
          fVar22 = pfVar5[1] * pfVar5[1] + pfVar5[2] * pfVar5[2] + fVar22 * fVar22;
          pfVar5 = pfVar5 + 3;
        }
        fVar22 = *(float *)((int)(local_4c + 2) + (int)piVar8);
        fVar22 = *(float *)((int)local_4c + (int)piVar8) * *(float *)((int)local_4c + (int)piVar8) +
                 *(float *)((int)(local_4c + 1) + (int)piVar8) *
                 *(float *)((int)(local_4c + 1) + (int)piVar8) + fVar22 * fVar22;
        pfVar5 = (float *)((int)(local_4c + 2) + (int)piVar8);
        while (fVar23 <= fVar22) {
          if (iVar11 <= iVar15) goto LAB_0042f120;
          iVar11 = iVar11 + -1;
          fVar22 = pfVar5[-3];
          fVar22 = pfVar5[-5] * pfVar5[-5] + pfVar5[-4] * pfVar5[-4] + fVar22 * fVar22;
          pfVar5 = pfVar5 + -3;
          param_3 = iVar11;
        }
        if (iVar11 <= iVar15) break;
        fVar22 = local_4c[iVar15 * 3];
        fVar3 = local_4c[iVar15 * 3 + 1];
        fVar4 = local_4c[iVar15 * 3 + 2];
        piVar8 = (int *)(iVar11 * 0xc);
        local_4c[iVar15 * 3] = local_4c[iVar11 * 3];
        local_4c[iVar15 * 3 + 1] = (local_4c + 1)[iVar11 * 3];
        local_4c[iVar15 * 3 + 2] = (local_4c + 2)[iVar11 * 3];
        local_4c[iVar11 * 3] = fVar22;
        (local_4c + 1)[iVar11 * 3] = fVar3;
        (local_4c + 2)[iVar11 * 3] = fVar4;
      }
LAB_0042f120:
      local_4c[iVar10 * 3] = local_4c[iVar11 * 3];
      (local_4c + 1)[iVar10 * 3] = local_4c[iVar11 * 3 + 1];
      (local_4c + 2)[iVar10 * 3] = local_4c[iVar11 * 3 + 2];
      local_4c[iVar11 * 3] = fVar20;
      local_4c[iVar11 * 3 + 1] = fVar16;
      local_4c[iVar11 * 3 + 2] = fVar2;
      FUN_0042f5c0(0,iVar15 + -1);
      FUN_0042f5c0(param_3 + 1,iVar10);
    }
    uVar13 = 0;
    iVar10 = 0;
    do {
      if (local_48 <= uVar13) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_58 = *param_2 + *(float *)(iVar10 + (int)local_4c);
      local_54 = *(float *)(iVar10 + 4 + (int)local_4c) + param_2[1];
      local_50 = (CMap *)(*(float *)(iVar10 + 8 + (int)local_4c) + param_2[2]);
      uVar14 = FUN_006badc0(&local_58);
      FUN_006bb930(uVar14);
      if (param_6 != (int *)0x0) {
        *param_6 = *param_6 + -1;
        if (*param_6 < 1) {
          TclFreeObj(param_6);
        }
        param_6 = (int *)0x0;
      }
      uVar13 = uVar13 + 1;
      iVar10 = iVar10 + 0xc;
    } while ((int)uVar13 < (int)local_44);
  }
  local_8 = 2;
  if ((int)local_48 < 0) {
    FUN_0042f8e0(-local_48);
  }
  else if (0 < (int)local_48) {
    local_48 = 0;
  }
  pfVar5 = local_4c;
  if (local_4c == (float *)0x0) {
    ExceptionList = local_10;
    return param_1;
  }
  if (DAT_00c3c824 == 0) {
    DAT_00c3c824 = 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  if (pfVar5 != (float *)0x0) {
    LOCK();
    _DAT_00c3c818 = _DAT_00c3c818 + 1;
    UNLOCK();
    pfVar1 = pfVar5 + -7;
    iVar10 = FUN_006ba730();
    if (iVar10 == 0) {
      fVar20 = pfVar5[-2];
      iVar10 = FUN_006ba730();
      if (iVar10 == 0) {
        if (pfVar5[-5] != 0.0) {
          *(float *)((int)pfVar5[-5] + 4) = pfVar5[-6];
        }
        if (pfVar5[-6] != 0.0) {
          *(float *)((int)pfVar5[-6] + 8) = pfVar5[-5];
        }
        if (pfVar1 == DAT_00c3c81c) {
          DAT_00c3c81c = (float *)pfVar5[-6];
        }
        _memset(pfVar5,-0x20202021,(size_t)fVar20);
        bVar21 = DAT_0077248f == '\0';
        *pfVar1 = -3.2263715e+19;
        pfVar5[-1] = -3.2263715e+19;
        *(undefined4 *)((int)fVar20 + 0x1c + (int)pfVar1) = 0xdfdfdfdf;
        if (((bVar21) || (DAT_00c1c788 == '\0')) ||
           ((pfVar1 < DAT_00c3c7cc || ((float *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= pfVar1)))) {
          FUN_006df631(pfVar1);
        }
        else {
          FUN_006b8c20();
        }
        goto LAB_0042f366;
      }
    }
    if (DAT_00c3c7d4 != (FILE *)0x0) {
      FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",pfVar5,iVar10);
      _fflush(DAT_00c3c7d4);
    }
    if (DAT_00c3c828 != '\0') {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
LAB_0042f366:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
  ExceptionList = local_10;
  return param_1;
}

