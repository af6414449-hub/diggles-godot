
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a7e40(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 int param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  byte bVar11;
  uint in_ECX;
  uint uVar12;
  int *piVar13;
  int iVar14;
  CHeightBlock *pCVar15;
  CMap *pCVar16;
  int iVar17;
  int *piVar18;
  CMapCell *pCVar19;
  uint uVar20;
  bool bVar21;
  float fVar22;
  float fVar23;
  undefined4 *puVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  int *local_60;
  int *local_5c;
  int local_58;
  undefined4 local_54;
  uint local_50;
  int local_4c;
  undefined4 *local_48;
  int local_44;
  int *local_40;
  uint local_3c;
  CMap *local_38;
  int *local_34;
  CHeightBlock **local_30;
  uint local_2c;
  int *local_28;
  uint local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_00706ded;
  local_1c = ExceptionList;
  local_24 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_40 = param_1;
  local_50 = in_ECX;
  puVar3 = &stack0xfffffffc;
  if (PTR_0077241c == (CMap *)0x0) goto LAB_005a8a84;
  puVar3 = &stack0xfffffffc;
  if ((*(int *)(in_ECX + 0x28) == 0) &&
     (FUN_005a7c90(local_24), puVar3 = puStack_20, *(int *)(in_ECX + 0x28) == 0)) {
    _memset((void *)param_1[5],0,param_1[4] * param_1[1] * *param_1);
    puVar3 = puStack_20;
    goto LAB_005a8a84;
  }
  puStack_20 = puVar3;
  puVar3 = puStack_20;
  if ((((PTR_0077241c != (CMap *)0x0) && ((char)PTR_0077241c->mapFlags == '\0')) ||
      (param_6 < param_4)) || (param_7 < param_5)) goto LAB_005a8a84;
  local_5c = (int *)0x0;
  local_58 = 0;
  local_54 = 1;
  local_14 = 0;
  FUN_006c2080(PTR_0077241c->cellX0,PTR_0077241c->cellY0,PTR_0077241c->cellX1,PTR_0077241c->cellY1);
  FUN_006c2d00();
  if (&local_5c != (int **)(in_ECX + 0x5c)) {
    FUN_0049c5f0(*(undefined4 *)(in_ECX + 0x60));
    FUN_006d2250(local_5c,*(int **)(in_ECX + 0x5c),*(int *)(in_ECX + 0x60) << 4);
  }
  local_54 = *(undefined4 *)(in_ECX + 100);
  FUN_006c2080(param_4,param_5,param_6,param_7);
  FUN_006c2d00();
  FUN_006c1c30(param_4,param_5,param_6,param_7);
  local_60 = local_5c;
  piVar9 = (int *)0;
  local_28 = local_5c;
  while (iVar17 = local_58, (int)piVar9 < local_58) {
    local_34 = (int *)((int)piVar9 + 1);
    iVar8 = *local_28;
    local_44 = local_28[1];
    iVar2 = local_28[2];
    local_48 = (undefined4 *)local_28[3];
    local_28 = local_28 + 4;
    iVar17 = PTR_0077241c->cellX1;
    iVar10 = PTR_0077241c->cellX0;
    uVar12 = *(uint *)(DAT_00772400 + 100);
    piVar9 = local_34;
    local_3c = uVar12;
    if (local_44 < (int)local_48) {
      do {
        local_4c = iVar8;
        if (iVar8 < iVar2) {
          bVar11 = (byte)uVar12;
          do {
            pCVar16 = PTR_0077241c;
            local_38 = PTR_0077241c;
            iVar14 = PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= local_4c) {
              iVar14 = local_4c;
            }
            iVar6 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= local_44) {
              iVar6 = local_44;
            }
            iVar5 = PTR_0077241c->cellY1 + -1;
            if (iVar6 < PTR_0077241c->cellY1) {
              iVar5 = iVar6;
            }
            iVar6 = PTR_0077241c->cellX1 + -1;
            if (iVar14 < PTR_0077241c->cellX1) {
              iVar6 = iVar14;
            }
            iVar14 = (iVar5 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
            if ((iVar14 < 0) || (PTR_0077241c->cellCount <= iVar14)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar19 = pCVar16->cells;
            }
            else {
              pCVar19 = PTR_0077241c->cells + iVar14;
            }
            local_38 = (CMap *)pCVar19;
            if (local_3c < 8) {
              pCVar19 = (CMapCell *)(pCVar19->ownerIndex + (local_3c - 0x34));
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            uVar12 = (uint)pCVar19->ownerIndex[0];
            if (uVar12 == 0) {
              uVar12 = 0;
              uVar20 = 0;
              local_2c = 0;
            }
            else {
              uVar20 = 0x80;
              if (0x80 < uVar12) {
                uVar20 = uVar12;
              }
              iVar6 = (int)((float)(int)(uVar20 - 0x80) * 1.3);
              iVar14 = 0x80;
              if (iVar6 < 0x80) {
                iVar14 = iVar6;
              }
              fVar22 = (float)iVar14;
              local_2c = (uint)ROUND(fVar22 * 0.99 * 0.6);
              iVar14 = *(int *)&local_38->field_0x0;
              local_30 = &PTR_0077241c->heightBlocks->data;
              if ((iVar14 < 0) || (PTR_0077241c->heightBlocks->count <= iVar14)) {
                DAT_00772dd8 = (int *)local_2c;
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar15 = *local_30;
              }
              else {
                pCVar15 = *local_30 + iVar14;
              }
              local_30 = (CHeightBlock **)((float)((uint)pCVar15->heights[0] << 4) * 0.4);
              uVar12 = (int)ROUND(fVar22 * 0.3 * 0.6) + (int)ROUND((float)local_30);
              uVar20 = (int)ROUND(fVar22 * 0.42 * 0.6) + (int)ROUND((float)local_30);
              DAT_00772dd8 = (int *)(int)ROUND((float)local_30);
              local_2c = local_2c + (int)DAT_00772dd8;
            }
            uVar7 = local_2c;
            if ((0xf << (bVar11 & 0x1f) & local_38->mapFlags1) != 0) {
              if ((local_38->mapFlags1 & 8 << ((byte)local_3c & 0x1f)) == 0) {
                uVar12 = uVar12 + 0x38;
                uVar20 = uVar20 + 0x57;
                local_30 = (CHeightBlock **)0x422c0831;
                DAT_00772dd8 = (int *)0x2b;
                uVar7 = local_2c + 0x2b;
              }
              else {
                uVar12 = uVar12 + 0x23;
                uVar20 = uVar20 + 0x24;
                local_30 = (CHeightBlock **)0x43020c4a;
                DAT_00772dd8 = (int *)0x82;
                uVar7 = local_2c + 0x82;
              }
            }
            if (0xff < (int)uVar12) {
              uVar12 = 0xff;
            }
            if (0xff < (int)uVar20) {
              uVar20 = 0xff;
            }
            if (0xff < (int)uVar7) {
              uVar7 = 0xff;
            }
            iVar14 = ((local_44 - *(int *)(local_50 + 0x58)) * (iVar17 - iVar10) -
                     *(int *)(local_50 + 0x54)) + local_4c;
            local_4c = local_4c + 1;
            *(uint *)(*(int *)(local_50 + 0x28) + iVar14 * 4) =
                 ((uVar12 | 0xffffcf00) << 8 | uVar20) << 8 | uVar7;
            uVar12 = local_3c;
          } while (local_4c < iVar2);
        }
        local_44 = local_44 + 1;
        piVar9 = local_34;
      } while (local_44 < (int)local_48);
    }
  }
  piVar9 = (int *)(local_50 + 0x40);
  local_28 = piVar9;
  cVar4 = FUN_005a9160(piVar9);
  piVar18 = local_40;
  if ((cVar4 != '\0') || (iVar17 != 0)) {
    *(undefined1 *)(local_50 + 0x50) = 1;
  }
  iVar17 = *(int *)(local_50 + 0x3c);
  if ((iVar17 == 0) || (*(char *)(local_50 + 0x50) != '\0')) {
    if (((*(int *)(local_50 + 0x28) != 0) &&
        (((local_40[6] == *(int *)(local_50 + 0x2c) && (local_40[7] == *(int *)(local_50 + 0x30)))
         && (local_40[8] == *(int *)(local_50 + 0x34))))) &&
       (local_40[9] == *(int *)(local_50 + 0x38))) {
      FUN_006c1b50(local_40,(float)(param_6 - param_4),(float)(param_7 - param_5),piVar9);
      iVar17 = *(int *)(local_50 + 0x3c);
    }
    if (iVar17 == 0) {
      iVar17 = FUN_006ba810(0xcc);
      *(int *)(local_50 + 0x3c) = iVar17;
    }
    FUN_006d2250(iVar17,piVar18[5],piVar18[4] * piVar18[2]);
    *(undefined1 *)(local_50 + 0x50) = 0;
    *(int *)(local_50 + 0x40) = param_4;
    *(int *)(local_50 + 0x44) = param_5;
    *(int *)(local_50 + 0x48) = param_6;
    *(int *)(local_50 + 0x4c) = param_7;
  }
  else {
    FUN_006d2250(local_40[5],iVar17,local_40[4] * local_40[2]);
    param_4 = *local_28;
    param_5 = local_28[1];
    param_6 = local_28[2];
    param_7 = local_28[3];
  }
  local_38 = (CMap *)FUN_005b78b0();
  local_50 = *(uint *)(DAT_00772400 + 100);
  local_3c = 0xffffffff;
  pCVar16 = local_38;
  while( true ) {
    local_3c = local_3c + 1;
    if ((int)*(uint *)(((CMapCell *)((int)pCVar16 + 0xbfd0))->sampleFlags + 9) <= (int)local_3c)
    break;
    if (*(uint *)(((CMapCell *)((int)pCVar16 + 0xbfd0))->sampleFlags + 9) <= local_3c) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar16 = local_38;
    }
    iVar17 = *(int *)(*(int *)(((CMapCell *)((int)pCVar16 + 0xbfd0))->sampleFlags + 5) +
                     local_3c * 4);
    if ((iVar17 < 0) || (*(int *)((CMapCell *)((int)pCVar16 + 0xbfd0))->sampleFlags <= iVar17)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_44 = *(int *)(((CMapCell *)((int)local_38 + 0xbfd0))->ownerIndex + 4);
      pCVar16 = local_38;
    }
    else {
      local_44 = iVar17 * 0xd8 + *(int *)(((CMapCell *)((int)pCVar16 + 0xbfd0))->ownerIndex + 4);
    }
    if (((*(uint *)(local_44 + 0x74) == local_50) && (*(int *)(local_44 + 0x6c) != 0)) &&
       ((((iVar17 = *(int *)(*(int *)(local_44 + 0x6c) + 0x54), iVar17 == 3 ||
          (((iVar17 == 1 || (iVar17 == 5)) || (iVar17 == 9)))) ||
         ((((iVar17 == 6 || (iVar17 == 0xb)) || (iVar17 == 2)) || ((iVar17 == 7 || (iVar17 == 10))))
         )) || (iVar17 == 8)))) {
      local_48 = *(undefined4 **)(local_44 + 0xa8);
      if (iVar17 == 3) {
        local_2c = 0xcf00b2eb;
      }
      else if (local_48 == (undefined4 *)0xffffffff) {
        local_2c = 0xcfdf0029;
        if (iVar17 != 2) {
          local_2c = 0xcfee9c00;
        }
      }
      else {
        local_28 = (int *)(DAT_00772400 + 0xa420);
        if (local_50 < 8) {
          local_34 = local_28 + local_50 * 0xd;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_34 = local_28;
        }
        if (&DAT_00000007 < local_48) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        else {
          local_34 = local_34 + (int)local_48;
        }
        switch(local_34[5]) {
        case 0:
          local_2c = 0xcf70f448;
          if (iVar17 == 1) {
            local_2c = 0xcfc0ffd6;
          }
          break;
        case 1:
          local_2c = 0xcff9f400;
          break;
        case 3:
          local_2c = 0xcfee9c00;
          break;
        case 4:
          local_2c = 0xcfdf0029;
        }
      }
      iVar17 = local_44;
      fVar22 = 0.0;
      puVar24 = (undefined4 *)0x0;
      fVar25 = 0.0;
      fVar26 = 0.0;
      fVar27 = *(float *)(local_44 + 0x40) + 0.5;
      fVar28 = *(float *)(local_44 + 0x44) + 0.5;
      uVar12 = *(uint *)(local_44 + 0x78);
      if ((((uVar12 != 0xffffffff) && (iVar10 = *(int *)(local_44 + 0x7c), -1 < iVar10)) &&
          (uVar12 < 0x100)) &&
         ((local_34 = *(int **)(DAT_00772400 + 0x5c8 + uVar12 * 4), local_34 != (int *)0x0 &&
          (iVar10 < *(int *)((int)local_34 + 0x3c))))) {
        if (iVar10 < *(int *)((int)local_34 + 0x38)) {
          iVar17 = iVar10 * 0xe8 + *(int *)((int)local_34 + 0x34);
          iVar8 = *(int *)((int)local_34 + 0x34);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar10 = *(int *)(iVar17 + 0x7c);
          iVar17 = *(int *)((int)local_34 + 0x34);
          iVar8 = iVar17;
        }
        local_28 = (int *)(*(float *)(iVar17 + 0x44) * 0.005);
        local_48 = (undefined4 *)(*(float *)(iVar17 + 0x48) * 0.005);
        if ((iVar10 < 0) || (*(int *)((int)local_34 + 0x38) <= iVar10)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *(int *)((int)local_34 + 0x34);
        }
        else {
          iVar8 = iVar10 * 0xe8 + iVar8;
        }
        fVar25 = *(float *)(iVar8 + 0x50) * 0.005;
        fVar26 = *(float *)(iVar8 + 0x54) * 0.005;
        puVar24 = local_48;
        fVar22 = (float)local_28;
      }
      iVar17 = (int)ROUND((((fVar22 + fVar27) - (float)param_4) * (float)*local_40) /
                          (float)(param_6 - param_4));
      fVar23 = fVar22 + 0.4;
      if (fVar22 + 0.4 <= fVar25) {
        fVar23 = fVar25;
      }
      iVar10 = (int)ROUND((((fVar23 + fVar27) - (float)param_4) * (float)*local_40) /
                          (float)(param_6 - param_4));
      piVar9 = (int *)(int)ROUND(((((float)puVar24 + fVar28) - (float)param_5) * (float)local_40[1])
                                 / (float)(param_7 - param_5));
      fVar22 = (float)puVar24 + 0.4;
      if ((float)puVar24 + 0.4 <= fVar26) {
        fVar22 = fVar26;
      }
      DAT_00772dd8 = (int *)(int)ROUND((((fVar22 + fVar28) - (float)param_5) * (float)local_40[1]) /
                                       (float)(param_7 - param_5));
      iVar8 = iVar10 + 1;
      if (iVar17 != iVar10) {
        iVar8 = iVar10;
      }
      piVar18 = (int *)((int)DAT_00772dd8 + 1);
      if (piVar9 != DAT_00772dd8) {
        piVar18 = DAT_00772dd8;
      }
      iVar10 = 0;
      if (-1 < iVar17) {
        iVar10 = iVar17;
      }
      local_34 = (int *)*local_40;
      local_4c = (int)local_34;
      if (iVar10 <= (int)local_34) {
        local_4c = iVar10;
      }
      iVar17 = 0;
      if (-1 < iVar8) {
        iVar17 = iVar8;
      }
      if (iVar17 <= (int)local_34) {
        local_34 = (int *)iVar17;
      }
      piVar1 = (int *)local_40[1];
      piVar13 = (int *)0x0;
      if (-1 < (int)piVar9) {
        piVar13 = piVar9;
      }
      piVar9 = (int *)0x0;
      if (-1 < (int)piVar18) {
        piVar9 = piVar18;
      }
      local_28 = piVar1;
      if ((int)piVar9 <= (int)piVar1) {
        local_28 = piVar9;
      }
      if ((int)piVar13 <= (int)piVar1) {
        piVar1 = piVar13;
      }
      for (; pCVar16 = local_38, iVar17 = local_4c, (int)piVar1 < (int)local_28;
          piVar1 = (int *)((int)piVar1 + 1)) {
        for (; iVar17 < (int)local_34; iVar17 = iVar17 + 1) {
          iVar10 = *local_40 * (int)piVar1 + iVar17;
          if (*(int *)(local_40[5] + iVar10 * 4) != -0x303f002a) {
            *(uint *)(local_40[5] + iVar10 * 4) = local_2c;
          }
        }
      }
    }
  }
  local_14 = 1;
  if ((local_58 < 0) && ((local_58 + 0x7fU & 0xffffff80) != 0)) {
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    if (local_5c == (int *)0x0) {
      local_60 = (int *)FUN_006ba810(0x9b);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    else {
      if (DAT_00c3c824 == 0) {
        DAT_00c3c824 = 1;
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      piVar9 = local_5c;
      LOCK();
      _DAT_00c3c818 = _DAT_00c3c818 + 1;
      UNLOCK();
      piVar18 = local_5c + -7;
      iVar17 = FUN_006ba730();
      if (iVar17 == 0) {
        local_28 = (int *)piVar9[-2];
        local_48 = (undefined4 *)((int)(local_28 + 7) + (int)piVar18);
        iVar17 = FUN_006ba730();
        if (iVar17 != 0) goto LAB_005a8989;
        if (piVar9[-5] != 0) {
          *(int *)(piVar9[-5] + 4) = piVar9[-6];
        }
        if (piVar9[-6] != 0) {
          *(int *)(piVar9[-6] + 8) = piVar9[-5];
        }
        if (piVar18 == DAT_00c3c81c) {
          DAT_00c3c81c = (int *)piVar9[-6];
        }
        _memset(local_5c,-0x20202021,(size_t)local_28);
        bVar21 = DAT_0077248f == '\0';
        *piVar18 = -0x20202021;
        piVar9[-1] = -0x20202021;
        *local_48 = 0xdfdfdfdf;
        if (((bVar21) || (DAT_00c1c788 == '\0')) ||
           ((piVar18 < DAT_00c3c7cc || ((int *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= piVar18)))) {
          FUN_006df631(piVar18);
        }
        else {
          FUN_006b8c20();
        }
      }
      else {
LAB_005a8989:
        if (DAT_00c3c7d4 != (FILE *)0x0) {
          FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",local_5c,iVar17);
          _fflush(DAT_00c3c7d4);
        }
        if (DAT_00c3c828 != '\0') {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
      local_60 = (int *)0x0;
    }
  }
  puVar3 = puStack_20;
  if (local_60 != (int *)0x0) {
    FUN_006ba940();
    puVar3 = puStack_20;
  }
LAB_005a8a84:
  puStack_20 = puVar3;
  ExceptionList = local_1c;
  __security_check_cookie(local_24 ^ (uint)&stack0xfffffff0);
  return;
}

