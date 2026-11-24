
void FUN_005992b0(char *param_1,FILE *param_2,CGameThread *param_3)

{
  CGameThread *pCVar1;
  CMap *pCVar2;
  byte bVar3;
  uint uVar4;
  FILE *pFVar5;
  int *piVar6;
  byte *_DstBuf;
  int iVar7;
  byte *_DstBuf_00;
  void *_DstBuf_01;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  uint uVar11;
  int *piVar12;
  byte *pbVar13;
  undefined1 *puVar14;
  CMapCell *pCVar15;
  int iVar16;
  ushort uVar17;
  undefined4 extraout_ECX;
  int iVar18;
  FILE *pFVar19;
  CMap *pCVar20;
  byte bVar21;
  byte bVar25;
  CGameThread *pCVar22;
  int iVar23;
  CMap *pCVar24;
  code *pcVar26;
  size_t _Size;
  undefined4 uVar27;
  int local_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  CMap *local_60;
  FILE *local_5c;
  uint local_58;
  CGameThread *local_54;
  int local_50;
  FILE *local_4c;
  byte *local_48;
  CGameThread *local_44;
  FILE *local_40;
  CGameThread *local_3c;
  int local_38;
  undefined1 *local_34;
  int local_30;
  byte local_29;
  CGameThread *local_28;
  CGameThread *local_24;
  byte local_1d;
  CMap *local_1c;
  FILE *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00706b77;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar4;
  pFVar5 = _fopen(param_1,"rb");
  local_4c = pFVar5;
  if (pFVar5 != (FILE *)0x0) {
    *(undefined1 *)&PTR_0077241c->mapFlags = 0;
    _fread(&local_18,4,1,pFVar5);
    _fread(&local_30,4,1,pFVar5);
    if (*(char *)(DAT_00772400 + 0x590) == '\0') {
      local_3c = param_3;
      local_40 = param_2;
    }
    else {
      local_40 = (FILE *)(int)*(float *)(DAT_00772374 + 0x194);
      local_3c = (CGameThread *)(int)*(float *)(DAT_00772374 + 0x198);
      piVar6 = (int *)Tcl_NewStringObj("log \"map done\"",0xffffffff,extraout_ECX,uVar4);
      *piVar6 = *piVar6 + 1;
      CGameThread__CreateMap(local_3c);
    }
    local_8 = 4;
    _DstBuf = (byte *)FUN_006ba810(0x10c);
    local_38 = local_30 * (int)local_18;
    piVar6 = (int *)FUN_006ba810(0x10d);
    iVar18 = local_30 * (int)local_18;
    iVar7 = FUN_006ba810(0x10e);
    _DstBuf_00 = (byte *)FUN_006ba810(0x10f);
    pFVar5 = local_4c;
    local_5c = (FILE *)(local_30 * (int)local_18);
    _fread(_DstBuf,(size_t)local_5c,1,local_4c);
    _fread(piVar6,local_30 * (int)local_18,4,pFVar5);
    _fread(&local_60,4,1,pFVar5);
    thunk_FUN_0060fc30(0);
    _DstBuf_01 = (void *)FUN_006ba810(0x5e);
    pFVar5 = local_4c;
    _fread(_DstBuf_01,(size_t)local_60,2,local_4c);
    _fread(_DstBuf_00,local_30 * (int)local_18,1,pFVar5);
    _fclose(pFVar5);
    iVar8 = (int)local_3c - PTR_0077241c->cellY0;
    iVar9 = 0;
    if (iVar8 < 1) {
      iVar9 = iVar8;
    }
    pCVar22 = (CGameThread *)-iVar9;
    local_4c = (FILE *)(PTR_0077241c->cellX1 - (int)local_40);
    if ((int)local_18 < (int)local_4c) {
      local_4c = local_18;
    }
    local_50 = PTR_0077241c->cellY1 - (int)local_3c;
    if (local_30 < local_50) {
      local_50 = local_30;
    }
    local_44 = pCVar22;
    if (((int)pCVar22 < (int)local_4c) && (pCVar1 = pCVar22, (int)pCVar22 < local_50)) {
      do {
        local_24 = pCVar1;
        local_28 = pCVar22;
        iVar9 = FUN_00592f10(PTR_0077241c);
        local_1d = *(byte *)(iVar9 + 0x18);
        puVar10 = &local_28->field_0x0 + (int)local_24 * (int)local_18;
        if (((int)puVar10 < 0) || (local_38 <= (int)puVar10)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pbVar13 = _DstBuf;
        }
        else {
          pbVar13 = _DstBuf + (int)puVar10;
        }
        local_1c = (CMap *)(*pbVar13 & 0x7f);
        puVar10 = &local_28->field_0x0 + (int)local_24 * (int)local_18;
        if (((int)puVar10 < 0) || (local_38 <= (int)puVar10)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pbVar13 = _DstBuf;
        }
        else {
          pbVar13 = _DstBuf + (int)puVar10;
        }
        local_34 = (undefined1 *)(*pbVar13 & 0x80);
        bVar3 = (byte)local_34;
        pbVar13 = _DstBuf;
        switch(local_1c) {
        case (CMap *)0x0:
          puVar14 = &local_28->field_0x0 + (int)local_24 * (int)local_18;
          if (((int)puVar14 < 0) || (local_38 <= (int)puVar14)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar10 = local_34;
          }
          else {
            puVar10 = local_34;
            pbVar13 = _DstBuf + (int)puVar14;
          }
          break;
        case (CMap *)0x1:
          puVar10 = &local_28->field_0x0 + (int)local_24 * (int)local_18;
          if (((int)puVar10 < 0) || (local_38 <= (int)puVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            *_DstBuf = (local_1d & 3) + 1 | (byte)local_34;
            local_48 = _DstBuf;
          }
          else {
            _DstBuf[(int)puVar10] = (local_1d & 3) + 1 | bVar3;
            local_48 = _DstBuf + (int)puVar10;
          }
          goto switchD_0059963a_default;
        case (CMap *)0x2:
          puVar14 = &local_28->field_0x0 + (int)local_24 * (int)local_18;
          if (((int)puVar14 < 0) || (local_38 <= (int)puVar14)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar10 = (undefined1 *)(uint)(byte)((byte)local_34 | 3);
          }
          else {
            puVar10 = (undefined1 *)(uint)(bVar3 | 3);
            pbVar13 = _DstBuf + (int)puVar14;
          }
          break;
        case (CMap *)0x3:
          puVar14 = &local_28->field_0x0 + (int)local_24 * (int)local_18;
          if (((int)puVar14 < 0) || (local_38 <= (int)puVar14)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar10 = (undefined1 *)(uint)(byte)((byte)local_34 | 2);
          }
          else {
            puVar10 = (undefined1 *)(uint)(bVar3 | 2);
            pbVar13 = _DstBuf + (int)puVar14;
          }
          break;
        case (CMap *)0x4:
          puVar14 = &local_28->field_0x0 + (int)local_24 * (int)local_18;
          if (((int)puVar14 < 0) || (local_38 <= (int)puVar14)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar10 = (undefined1 *)(uint)(byte)((byte)local_34 | 1);
          }
          else {
            puVar10 = (undefined1 *)(uint)(bVar3 | 1);
            pbVar13 = _DstBuf + (int)puVar14;
          }
          break;
        case (CMap *)0x5:
          puVar10 = &local_28->field_0x0 + (int)local_24 * (int)local_18;
          if (((int)puVar10 < 0) || (local_38 <= (int)puVar10)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          else {
            pbVar13 = _DstBuf + (int)puVar10;
          }
          puVar10 = (undefined1 *)(uint)(byte)((byte)local_34 | 4);
          break;
        default:
          goto switchD_0059963a_default;
        }
        *pbVar13 = (byte)puVar10;
switchD_0059963a_default:
        pCVar22 = (CGameThread *)&local_28->field_0x1;
        pCVar1 = local_24;
      } while (((int)&local_28->field_0x1 < (int)local_4c) ||
              (pCVar22 = local_44, pCVar1 = (CGameThread *)&local_24->field_0x1,
              (int)&local_24->field_0x1 < local_50));
      local_34 = &local_3c->field_0x0 + (int)&local_44->field_0x0;
      iVar9 = 1 - (int)local_3c;
      local_54 = local_44;
      do {
        local_24 = (CGameThread *)(&local_44->field_0x0 + (int)&local_40->_ptr);
        iVar8 = 1 - (int)local_40;
        local_28 = local_44;
        pcVar26 = RaiseException_exref;
        do {
          puVar10 = &local_28->field_0x0 + (int)local_54 * (int)local_18;
          if (((int)puVar10 < 0) || (local_38 <= (int)puVar10)) {
            (*pcVar26)(0xc000008c,1,0,0);
            pbVar13 = _DstBuf;
          }
          else {
            pbVar13 = _DstBuf + (int)puVar10;
          }
          bVar3 = *pbVar13;
          uVar17 = (ushort)(bVar3 & 0x7f);
          local_1c = (CMap *)(local_34 + iVar9);
          local_48 = (byte *)(CONCAT31(local_48._1_3_,bVar3) & 0xffffff7f);
          bVar21 = bVar3 & 0x7f;
          if ((int)local_1c < local_50) {
            puVar10 = &local_28->field_0x0 + (int)local_1c * (int)local_18;
            if (((int)puVar10 < 0) || (local_38 <= (int)puVar10)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              uVar17 = CONCAT11(*_DstBuf,(byte)local_48) & 0x7fff;
              bVar21 = (byte)(uVar17 >> 8);
            }
            else {
              uVar17 = CONCAT11(_DstBuf[(int)puVar10],bVar3) & 0x7f7f;
              bVar21 = (byte)(uVar17 >> 8);
            }
          }
          local_1d = bVar21;
          pcVar26 = RaiseException_exref;
          bVar3 = (byte)uVar17;
          bVar21 = bVar3;
          bVar25 = bVar3;
          if ((int)((int)local_24 + iVar8) < (int)local_4c) {
            puVar10 = &local_28->field_0x1 + (int)local_54 * (int)local_18;
            if (((int)puVar10 < 0) || (local_38 <= (int)puVar10)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar13 = _DstBuf;
            }
            else {
              pbVar13 = _DstBuf + (int)puVar10;
            }
            local_29 = *pbVar13 & 0x7f;
            bVar3 = (byte)local_48;
            bVar21 = local_29;
            bVar25 = (byte)local_48;
            if ((int)local_1c < local_50) {
              puVar10 = &local_28->field_0x1 + (int)local_1c * (int)local_18;
              if (((int)puVar10 < 0) || (local_38 <= (int)puVar10)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                bVar3 = (byte)local_48;
                bVar21 = local_29;
                bVar25 = *_DstBuf & 0x7f;
              }
              else {
                bVar21 = *pbVar13 & 0x7f;
                bVar25 = puVar10[(int)_DstBuf] & 0x7f;
              }
            }
          }
          if ((((bVar3 != 0) || (local_1d != 0)) || (bVar21 != 0)) || (bVar25 != 0)) {
            uVar4 = (uint)local_1d;
            if ((byte)local_48 != '\0') {
              uVar4 = CONCAT11(local_1d,bVar3) & 0xff;
            }
            uVar11 = (uint)bVar21;
            if (uVar4 != 0) {
              uVar11 = uVar4;
            }
            local_1c = (CMap *)(uint)bVar25;
            if (uVar11 != 0) {
              local_1c = (CMap *)uVar11;
            }
            puVar10 = &local_28->field_0x0 + (int)local_54 * (int)local_18;
            if (((int)puVar10 < 0) || (local_38 <= (int)puVar10)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar13 = _DstBuf;
            }
            else {
              pbVar13 = _DstBuf + (int)puVar10;
            }
            pCVar2 = PTR_0077241c;
            pcVar26 = RaiseException_exref;
            uVar4 = *pbVar13 & 0x80;
            local_58 = uVar4;
            if (local_1c == (CMap *)0x4) {
              local_1c = PTR_0077241c;
              pCVar22 = (CGameThread *)PTR_0077241c->cellX0;
              if (PTR_0077241c->cellX0 <= (int)local_24) {
                pCVar22 = local_24;
              }
              puVar10 = (undefined1 *)PTR_0077241c->cellY0;
              if (PTR_0077241c->cellY0 <= (int)local_34) {
                puVar10 = local_34;
              }
              puVar14 = (undefined1 *)(PTR_0077241c->cellY1 - 1);
              if ((int)puVar10 < PTR_0077241c->cellY1) {
                puVar14 = puVar10;
              }
              puVar10 = (undefined1 *)(PTR_0077241c->cellX1 + -1);
              if ((int)pCVar22 < PTR_0077241c->cellX1) {
                puVar10 = (undefined1 *)pCVar22;
              }
              iVar23 = (int)(puVar10 + (int)puVar14 * PTR_0077241c->mapWidth) %
                       PTR_0077241c->cellCountTotal;
              if ((iVar23 < 0) || (PTR_0077241c->cellCount <= iVar23)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar2->cells->material = (ushort)local_58 | 3;
              }
              else {
                PTR_0077241c->cells[iVar23].material = (ushort)uVar4 | 3;
              }
            }
            else {
              iVar23 = _rand();
              pCVar2 = PTR_0077241c;
              pcVar26 = RaiseException_exref;
              local_58 = (iVar23 % 6) * 0x100 + ((int)local_1c - 1U | uVar4);
              local_1c = PTR_0077241c;
              pCVar22 = (CGameThread *)PTR_0077241c->cellX0;
              if (PTR_0077241c->cellX0 <= (int)local_24) {
                pCVar22 = local_24;
              }
              puVar10 = (undefined1 *)PTR_0077241c->cellY0;
              if (PTR_0077241c->cellY0 <= (int)local_34) {
                puVar10 = local_34;
              }
              puVar14 = (undefined1 *)(PTR_0077241c->cellY1 - 1);
              if ((int)puVar10 < PTR_0077241c->cellY1) {
                puVar14 = puVar10;
              }
              puVar10 = (undefined1 *)(PTR_0077241c->cellX1 + -1);
              if ((int)pCVar22 < PTR_0077241c->cellX1) {
                puVar10 = (undefined1 *)pCVar22;
              }
              iVar23 = (int)(puVar10 + (int)puVar14 * PTR_0077241c->mapWidth) %
                       PTR_0077241c->cellCountTotal;
              if ((iVar23 < 0) || (PTR_0077241c->cellCount <= iVar23)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar15 = pCVar2->cells;
              }
              else {
                pCVar15 = PTR_0077241c->cells + iVar23;
              }
              pCVar15->material = (ushort)local_58;
            }
            puVar10 = &local_28->field_0x0 + (int)local_54 * (int)local_18;
            if (((int)puVar10 < 0) || (iVar18 <= (int)puVar10)) {
              (*pcVar26)(0xc000008c,1,0,0);
              piVar12 = piVar6;
            }
            else {
              piVar12 = piVar6 + (int)puVar10;
            }
            pCVar2 = PTR_0077241c;
            local_58 = *piVar12;
            local_1c = PTR_0077241c;
            pCVar22 = (CGameThread *)PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= (int)local_24) {
              pCVar22 = local_24;
            }
            puVar10 = (undefined1 *)PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= (int)local_34) {
              puVar10 = local_34;
            }
            puVar14 = (undefined1 *)(PTR_0077241c->cellY1 - 1);
            if ((int)puVar10 < PTR_0077241c->cellY1) {
              puVar14 = puVar10;
            }
            puVar10 = (undefined1 *)(PTR_0077241c->cellX1 + -1);
            if ((int)pCVar22 < PTR_0077241c->cellX1) {
              puVar10 = (undefined1 *)pCVar22;
            }
            iVar23 = (int)(puVar10 + (int)puVar14 * PTR_0077241c->mapWidth) %
                     PTR_0077241c->cellCountTotal;
            if ((iVar23 < 0) || (PTR_0077241c->cellCount <= iVar23)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar15 = pCVar2->cells;
            }
            else {
              pCVar15 = PTR_0077241c->cells + iVar23;
            }
            pCVar15->heightBlockIndex = local_58;
            puVar10 = &local_28->field_0x0 + (int)local_54 * (int)local_18;
            if (((int)puVar10 < 0) || ((int)local_5c <= (int)puVar10)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar13 = _DstBuf_00;
            }
            else {
              pbVar13 = _DstBuf_00 + (int)puVar10;
            }
            pCVar2 = PTR_0077241c;
            pcVar26 = RaiseException_exref;
            local_29 = *pbVar13;
            local_1c = PTR_0077241c;
            pCVar22 = (CGameThread *)PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= (int)local_24) {
              pCVar22 = local_24;
            }
            puVar10 = (undefined1 *)PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= (int)local_34) {
              puVar10 = local_34;
            }
            puVar14 = (undefined1 *)(PTR_0077241c->cellY1 - 1);
            if ((int)puVar10 < PTR_0077241c->cellY1) {
              puVar14 = puVar10;
            }
            puVar10 = (undefined1 *)(PTR_0077241c->cellX1 + -1);
            if ((int)pCVar22 < PTR_0077241c->cellX1) {
              puVar10 = (undefined1 *)pCVar22;
            }
            iVar23 = (int)(puVar10 + (int)puVar14 * PTR_0077241c->mapWidth) %
                     PTR_0077241c->cellCountTotal;
            if ((iVar23 < 0) || (PTR_0077241c->cellCount <= iVar23)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar15 = pCVar2->cells;
            }
            else {
              pCVar15 = PTR_0077241c->cells + iVar23;
            }
            pCVar15->light = local_29;
          }
          local_24 = (CGameThread *)((int)local_24 + 1);
          local_28 = (CGameThread *)&local_28->field_0x1;
        } while ((int)local_28 < (int)local_4c);
        local_34 = local_34 + 1;
        local_54 = (CGameThread *)&local_54->field_0x1;
      } while ((int)local_54 < local_50);
      if (DAT_00772414 == 0) {
        local_5c = (FILE *)FUN_006ba810(0xd03);
        local_8._0_1_ = 5;
        if (local_5c == (FILE *)0x0) {
          DAT_00772414 = 0;
        }
        else {
          DAT_00772414 = FUN_00581470();
        }
        local_8 = CONCAT31(local_8._1_3_,4);
      }
      iVar9 = (int)&local_40->_ptr + (int)&local_18->_ptr;
      local_5c = (FILE *)PTR_0077241c->cellX0;
      if (PTR_0077241c->cellX0 <= (int)local_40) {
        local_5c = local_40;
      }
      local_44 = (CGameThread *)PTR_0077241c->cellY0;
      iVar8 = PTR_0077241c->cellX1;
      if (iVar9 <= PTR_0077241c->cellX1) {
        iVar8 = iVar9;
      }
      pbVar13 = (byte *)PTR_0077241c->cellY1;
      if ((int)(&local_3c->field_0x0 + local_30) <= PTR_0077241c->cellY1) {
        pbVar13 = &local_3c->field_0x0 + local_30;
      }
      if ((int)local_44 <= (int)local_3c) {
        local_44 = local_3c;
      }
      local_50 = iVar8;
      local_48 = pbVar13;
      if ((int)local_44 < (int)pbVar13) {
        do {
          pFVar5 = local_5c;
          if ((int)local_5c < iVar8) {
            do {
              local_1c = PTR_0077241c;
              pFVar19 = (FILE *)PTR_0077241c->cellX0;
              if (PTR_0077241c->cellX0 <= (int)pFVar5) {
                pFVar19 = pFVar5;
              }
              local_4c = (FILE *)(PTR_0077241c->cellX1 + -1);
              if ((int)pFVar19 < PTR_0077241c->cellX1) {
                local_4c = pFVar19;
              }
              pCVar22 = (CGameThread *)PTR_0077241c->cellY0;
              if (PTR_0077241c->cellY0 <= (int)local_44) {
                pCVar22 = local_44;
              }
              if (PTR_0077241c->cellY1 <= (int)pCVar22) {
                pCVar22 = (CGameThread *)(PTR_0077241c->cellY1 + -1);
              }
              iVar9 = (int)((int)&local_4c->_ptr + PTR_0077241c->mapWidth * (int)pCVar22) %
                      PTR_0077241c->cellCountTotal;
              if ((iVar9 < 0) || (PTR_0077241c->cellCount <= iVar9)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar15 = local_1c->cells;
              }
              else {
                pCVar15 = PTR_0077241c->cells + iVar9;
              }
              pCVar15->flags = pCVar15->flags | 1;
              pFVar5 = (FILE *)((int)&pFVar5->_ptr + 1);
              iVar8 = local_50;
              pbVar13 = local_48;
            } while ((int)pFVar5 < local_50);
          }
          local_44 = (CGameThread *)&local_44->field_0x1;
        } while ((int)local_44 < (int)pbVar13);
      }
    }
    pCVar20 = (CMap *)0x0;
    pCVar2 = local_1c;
    if (0 < (int)local_60) {
      pCVar20 = (CMap *)0x0;
      local_1c = (CMap *)0;
      pCVar24 = local_60;
      do {
        uVar17 = *(ushort *)((int)_DstBuf_01 + (int)local_1c * 2);
        local_1c = (CMap *)((int)local_1c + 1);
        _Size = (size_t)(uVar17 >> 2);
        if (_Size == 0) {
          _Size = 0x4000;
LAB_00599da8:
          _memset(&pCVar20->field_0x0 + iVar7,uVar17 & 3,_Size);
          pCVar20 = (CMap *)(&pCVar20->field_0x0 + _Size);
          pCVar24 = local_60;
        }
        else if (_Size != 0) goto LAB_00599da8;
        pCVar2 = pCVar20;
      } while ((int)local_1c < (int)pCVar24);
    }
    local_1c = pCVar2;
    local_5c = (FILE *)PTR_0077241c->cellX0;
    local_60 = pCVar20;
    if (((((int)local_5c <= (int)local_40) && ((int)local_40 < PTR_0077241c->cellX1)) &&
        (PTR_0077241c->cellY0 <= (int)local_3c)) && ((int)local_3c < PTR_0077241c->cellY1)) {
      iStack_68 = (int)&local_18->_ptr + (int)&local_40->_ptr;
      puVar10 = &local_3c->field_0x0 + local_30;
      if ((((int)local_5c <= iStack_68) && (iStack_68 < PTR_0077241c->cellX1)) &&
         ((PTR_0077241c->cellY0 <= (int)puVar10 && ((int)puVar10 < PTR_0077241c->cellY1)))) {
        local_70 = (int)local_40 << 3;
        iStack_64 = (int)puVar10 * 8;
        iStack_6c = (int)local_3c << 3;
        iStack_68 = iStack_68 * 8;
        FUN_00596550(iVar7,&local_70);
      }
    }
    iVar23 = (int)(&local_3c->field_0x0 + local_30) * 8;
    iVar9 = (int)local_3c * 8;
    iVar8 = (int)local_40 * 8;
    iVar16 = ((int)&local_40->_ptr + (int)&local_18->_ptr) * 8;
    uVar27 = 0x40000;
    iVar18 = iVar8;
    local_70 = iVar8;
    iStack_6c = iVar9;
    iStack_68 = iVar16;
    iStack_64 = iVar23;
    FUN_005a3dd0(iVar8,iVar9,iVar16,iVar23,0x40000);
    FUN_005a3fd0(iVar18,iVar9,iVar16,iVar23,uVar27);
    iVar9 = iVar8 + -8;
    uVar27 = 0x400;
    iVar18 = (int)(&local_3c->field_0x0 + local_30) * 8 + 8;
    iVar23 = (int)local_3c * 8 + -8;
    iVar16 = ((int)&local_40->_ptr + (int)&local_18->_ptr) * 8 + 8;
    local_70 = iVar9;
    iStack_6c = iVar23;
    iStack_68 = iVar16;
    iStack_64 = iVar18;
    FUN_005a3dd0(iVar9,iVar23,iVar16,iVar18,0x400);
    FUN_005a3fd0(iVar9,iVar23,iVar16,iVar18,uVar27);
    iVar23 = ((int)&local_40->_ptr + (int)&local_18->_ptr) * 8;
    iVar18 = (int)local_3c * 8;
    iVar9 = (int)(&local_3c->field_0x0 + local_30) * 8;
    if (DAT_007683d8 + 3 < iVar9) {
      iVar9 = DAT_007683d8 + 2;
    }
    local_70 = iVar8;
    iStack_6c = iVar18;
    iStack_68 = iVar23;
    iStack_64 = iVar9;
    if (iVar18 < iVar9) {
      uVar27 = 8;
      FUN_005a3dd0(iVar8,iVar18,iVar23,iVar9,8);
      FUN_005a3fd0(iVar8,iVar18,iVar23,iVar9,uVar27);
    }
    *(undefined1 *)(DAT_00772400 + 0x97) = 1;
    *(undefined1 *)&PTR_0077241c->mapFlags = 1;
    thunk_FUN_0060fc30(_DstBuf_00);
    thunk_FUN_0060fc30(_DstBuf_01);
    thunk_FUN_0060fc30(iVar7);
    thunk_FUN_0060fc30(piVar6);
    thunk_FUN_0060fc30(_DstBuf);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

