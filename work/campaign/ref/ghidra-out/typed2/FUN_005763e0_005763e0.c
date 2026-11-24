
void __thiscall FUN_005763e0(int this)

{
  uint uVar1;
  void *_Dst;
  CMap *pCVar2;
  byte bVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  CHeightBlock **ppCVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  CHeightBlock *pCVar13;
  int iVar14;
  int iVar15;
  code *pcVar16;
  CMapCell *pCVar17;
  char *pcVar18;
  int iVar19;
  uint uVar20;
  float fVar21;
  int local_4c;
  int local_44;
  int local_38;
  int local_34;
  int local_2c;
  int *local_24;
  int *local_20;
  int *local_14;
  int local_c;
  
  iVar15 = (*(int *)(this + 0x1c) - *(int *)(this + 0x14)) *
           (*(int *)(this + 0x20) - *(int *)(this + 0x18));
  thunk_FUN_0060fc30(*(undefined4 *)(this + 0x24));
  *(int *)(this + 0x28) = iVar15;
  pvVar4 = (void *)FUN_006ba810(0x5e);
  _Dst = pvVar4;
  if (pvVar4 == (void *)0x0) {
    pvVar4 = (void *)0x0;
  }
  else {
    for (; iVar15 != 0; iVar15 = iVar15 + -1) {
      _memset(_Dst,0,0x40);
      *(undefined1 *)((int)_Dst + 0x30) = 1;
      _Dst = (void *)((int)_Dst + 0x40);
    }
  }
  pcVar16 = RaiseException_exref;
  *(void **)(this + 0x24) = pvVar4;
  iVar15 = DAT_00772400;
  *(undefined1 *)(this + 0xcac) = 1;
  uVar1 = *(uint *)(iVar15 + 100);
  iVar5 = *(int *)(this + 0x1c) - *(int *)(this + 0x14);
  local_4c = *(int *)(this + 0x20) - *(int *)(this + 0x18);
  iVar15 = *(int *)(this + 0x18) + 1;
  if (iVar15 < *(int *)(this + 0x20) + -1) {
    do {
      iVar9 = *(int *)(this + 0x14) + 1;
      if (iVar9 < *(int *)(this + 0x1c) + -1) {
        do {
          iVar7 = *(int *)(this + 0x18);
          iVar6 = ((iVar15 - iVar7) * iVar5 - *(int *)(this + 0x14)) + iVar9;
          if ((iVar6 < 0) || (*(int *)(this + 0x28) <= iVar6)) {
            (*pcVar16)(0xc000008c,1,0,0);
            local_20 = *(int **)(this + 0x24);
            iVar7 = *(int *)(this + 0x18);
            local_14 = local_20;
          }
          else {
            local_20 = *(int **)(this + 0x24);
            local_14 = local_20 + iVar6 * 0x10;
          }
          iVar6 = (((iVar15 - iVar7) + -1) * iVar5 - *(int *)(this + 0x14)) + iVar9;
          if ((iVar6 < 0) || (*(int *)(this + 0x28) <= iVar6)) {
            (*pcVar16)(0xc000008c,1,0,0);
            local_24 = *(int **)(this + 0x24);
            iVar7 = *(int *)(this + 0x18);
            local_20 = local_24;
          }
          else {
            local_24 = local_20 + iVar6 * 0x10;
          }
          iVar7 = ((iVar15 - iVar7) * iVar5 - *(int *)(this + 0x14)) + -1 + iVar9;
          if ((iVar7 < 0) || (*(int *)(this + 0x28) <= iVar7)) {
            (*pcVar16)(0xc000008c,1,0,0);
            local_20 = *(int **)(this + 0x24);
          }
          else {
            local_20 = local_20 + iVar7 * 0x10;
          }
          pCVar2 = PTR_0077241c;
          iVar7 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar9) {
            iVar7 = iVar9;
          }
          iVar6 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar15) {
            iVar6 = iVar15;
          }
          iVar12 = PTR_0077241c->cellY1 + -1;
          if (iVar6 < PTR_0077241c->cellY1) {
            iVar12 = iVar6;
          }
          iVar6 = PTR_0077241c->cellX1 + -1;
          if (iVar7 < PTR_0077241c->cellX1) {
            iVar6 = iVar7;
          }
          iVar7 = (iVar12 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
          if ((iVar7 < 0) || (PTR_0077241c->cellCount <= iVar7)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar17 = pCVar2->cells;
          }
          else {
            pCVar17 = PTR_0077241c->cells + iVar7;
          }
          *local_14 = iVar9;
          local_14[1] = iVar15;
          *(byte *)(local_14 + 2) = pCVar17->field_0x1b & 7;
          local_14[3] = *(int *)&pCVar17->field_0x20;
          local_14[4] = *(int *)&pCVar17->field_0x28;
          local_14[5] = *(int *)&pCVar17->field_0x30;
          local_14[7] = *(int *)&pCVar17->field_0x20;
          pCVar2 = PTR_0077241c;
          fVar21 = 1.0;
          if (*(float *)&pCVar17->field_0x20 <= 1.0) {
            fVar21 = *(float *)&pCVar17->field_0x20;
          }
          local_14[6] = (int)fVar21;
          iVar7 = pCVar17->heightBlockIndex;
          ppCVar8 = &pCVar2->heightBlocks->data;
          if ((iVar7 < 0) || (pCVar2->heightBlocks->count <= iVar7)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar13 = *ppCVar8;
          }
          else {
            pCVar13 = *ppCVar8 + iVar7;
          }
          *(ushort *)(local_14 + 8) = *(ushort *)pCVar13->tail & 0x3ff;
          *(byte *)((int)local_14 + 0x23) = (byte)(*(uint *)pCVar13->tail >> 10) & 0xf;
          *(byte *)(local_14 + 9) = (byte)(*(uint *)pCVar13->tail >> 0xe) & 0xf;
          bVar3 = pCVar17->field_0x10;
          if (1.0 - (float)(bVar3 >> 4) / 15.0 <= 0.05) {
            *(byte *)((int)local_14 + 0x22) = *(byte *)((int)local_14 + 0x22) | 1;
            *(byte *)((int)local_24 + 0x22) = *(byte *)((int)local_24 + 0x22) | 4;
          }
          if (1.0 - (float)(bVar3 & 0xf) / 15.0 <= 0.05) {
            *(byte *)((int)local_14 + 0x22) = *(byte *)((int)local_14 + 0x22) | 8;
            *(byte *)((int)local_20 + 0x22) = *(byte *)((int)local_20 + 0x22) | 2;
          }
          uVar20 = *(uint *)pCVar13->tail;
          if ((uVar20 & 0x1fc0000) == 0) {
            *(byte *)((int)local_14 + 0x22) = *(byte *)((int)local_14 + 0x22) | 1;
            *(byte *)((int)local_24 + 0x22) = *(byte *)((int)local_24 + 0x22) | 4;
            uVar20 = *(uint *)pCVar13->tail;
          }
          if (uVar20 < 0x2000000) {
            *(byte *)((int)local_14 + 0x22) = *(byte *)((int)local_14 + 0x22) | 8;
            *(byte *)((int)local_20 + 0x22) = *(byte *)((int)local_20 + 0x22) | 2;
          }
          pCVar2 = PTR_0077241c;
          local_14[4] = (int)((float)local_14[4] / (float)*(ushort *)(local_14 + 8));
          local_14[5] = (int)((float)local_14[5] / (float)*(ushort *)(local_14 + 8));
          local_14[0xd] = pCVar13->cornerLevels & 0xf;
          iVar7 = pCVar2->cellX0;
          if (pCVar2->cellX0 <= iVar9) {
            iVar7 = iVar9;
          }
          iVar6 = pCVar2->cellY0;
          if (pCVar2->cellY0 <= iVar15) {
            iVar6 = iVar15;
          }
          iVar12 = pCVar2->cellY1 + -1;
          if (iVar6 < pCVar2->cellY1) {
            iVar12 = iVar6;
          }
          iVar6 = pCVar2->cellX1 + -1;
          if (iVar7 < pCVar2->cellX1) {
            iVar6 = iVar7;
          }
          iVar7 = (iVar12 * pCVar2->mapWidth + iVar6) % pCVar2->cellCountTotal;
          if ((iVar7 < 0) || (pCVar2->cellCount <= iVar7)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar17 = pCVar2->cells;
          }
          else {
            pCVar17 = pCVar2->cells + iVar7;
          }
          if (uVar1 < 8) {
            pCVar17 = (CMapCell *)(pCVar17->ownerIndex + (uVar1 - 0x34));
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          pCVar2 = PTR_0077241c;
          if (pCVar17->ownerIndex[0] == '\0') {
            iVar7 = PTR_0077241c->cellX0;
            if (PTR_0077241c->cellX0 <= iVar9) {
              iVar7 = iVar9;
            }
            iVar6 = PTR_0077241c->cellY0;
            if (PTR_0077241c->cellY0 <= iVar15 + 1) {
              iVar6 = iVar15 + 1;
            }
            iVar12 = PTR_0077241c->cellY1 + -1;
            if (iVar6 < PTR_0077241c->cellY1) {
              iVar12 = iVar6;
            }
            iVar6 = PTR_0077241c->cellX1 + -1;
            if (iVar7 < PTR_0077241c->cellX1) {
              iVar6 = iVar7;
            }
            iVar7 = (iVar12 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
            if ((iVar7 < 0) || (PTR_0077241c->cellCount <= iVar7)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar17 = pCVar2->cells;
            }
            else {
              pCVar17 = PTR_0077241c->cells + iVar7;
            }
            if (uVar1 < 8) {
              pCVar17 = (CMapCell *)(pCVar17->ownerIndex + (uVar1 - 0x34));
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            pCVar2 = PTR_0077241c;
            if (pCVar17->ownerIndex[0] == '\0') {
              iVar7 = PTR_0077241c->cellX0;
              if (PTR_0077241c->cellX0 <= iVar9 + 1) {
                iVar7 = iVar9 + 1;
              }
              iVar6 = PTR_0077241c->cellY0;
              if (PTR_0077241c->cellY0 <= iVar15) {
                iVar6 = iVar15;
              }
              iVar12 = PTR_0077241c->cellY1 + -1;
              if (iVar6 < PTR_0077241c->cellY1) {
                iVar12 = iVar6;
              }
              iVar6 = PTR_0077241c->cellX1 + -1;
              if (iVar7 < PTR_0077241c->cellX1) {
                iVar6 = iVar7;
              }
              iVar7 = (iVar12 * PTR_0077241c->mapWidth + iVar6) % PTR_0077241c->cellCountTotal;
              if ((iVar7 < 0) || (PTR_0077241c->cellCount <= iVar7)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar17 = pCVar2->cells;
              }
              else {
                pCVar17 = PTR_0077241c->cells + iVar7;
              }
              if (uVar1 < 8) {
                pCVar17 = (CMapCell *)(pCVar17->ownerIndex + (uVar1 - 0x34));
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if (pCVar17->ownerIndex[0] == '\0') {
                iVar7 = FUN_00592f10(PTR_0077241c);
                pcVar18 = (char *)(iVar7 + 0x34);
                if (uVar1 < 8) {
                  pcVar18 = pcVar18 + uVar1;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                if (*pcVar18 == '\0') {
                  *(undefined1 *)(local_14 + 0xe) = 1;
                }
              }
            }
          }
          if ((*(byte *)(local_14 + 2) & 7) != 0) {
            *(undefined1 *)(this + 0xcac) = 0;
          }
          iVar9 = iVar9 + 1;
          pcVar16 = RaiseException_exref;
        } while (iVar9 < *(int *)(this + 0x1c) + -1);
      }
      iVar15 = iVar15 + 1;
    } while (iVar15 < *(int *)(this + 0x20) + -1);
  }
  if (((*(char *)(this + 0xcac) == '\0') && (*(char *)(this + 0xcb5) == '\0')) &&
     (1 < local_4c + -1)) {
    local_2c = 1;
    local_34 = 0x40;
    iVar15 = iVar5 + 1;
    iVar9 = iVar5 * 0x40;
    local_38 = iVar9 + 0x40;
    iVar7 = iVar5 * 0x80 + 0x40;
    local_4c = local_4c + -2;
    do {
      if (1 < iVar5 + -1) {
        iVar14 = iVar15 + iVar5;
        local_14 = (int *)local_34;
        local_20 = (int *)local_38;
        local_44 = iVar5 + -2;
        iVar6 = iVar15;
        iVar12 = local_2c;
        local_c = iVar7;
        do {
          if ((iVar6 < 0) || (*(int *)(this + 0x28) <= iVar6)) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar11 = *(int *)(this + 0x24);
            iVar19 = iVar11;
          }
          else {
            iVar11 = *(int *)(this + 0x24);
            iVar19 = (int)local_20 + iVar11;
          }
          if ((iVar12 < 0) || (*(int *)(this + 0x28) <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar11 = *(int *)(this + 0x24);
            iVar10 = iVar11;
          }
          else {
            iVar10 = (int)local_14 + iVar11;
          }
          if ((iVar14 < 0) || (*(int *)(this + 0x28) <= iVar14)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar11 = *(int *)(this + 0x24);
          }
          else {
            iVar11 = local_c + iVar11;
          }
          fVar21 = *(float *)(iVar19 + 0x18);
          if ((fVar21 < 0.01) && ((*(byte *)(iVar19 + 0x22) & 4) != 0)) {
            *(undefined4 *)(iVar19 + 0x18) = 0;
            fVar21 = 0.0;
            *(undefined4 *)(iVar19 + 0xc) = 0;
            *(undefined4 *)(iVar19 + 0x1c) = 0;
            *(undefined4 *)(iVar19 + 0x28) = 0;
          }
          if ((((1.0 <= fVar21) || (1.0 <= *(float *)(iVar11 + 0x18))) ||
              ((*(byte *)(iVar19 + 0x22) & 4) != 0)) || (fVar21 <= 0.0)) goto LAB_00576c18;
          if ((ABS(*(float *)(iVar19 + 0x14)) < 0.5) || (*(float *)(iVar10 + 0xc) == 0.0)) {
            if (*(short *)(iVar11 + 0x20) == 0) {
LAB_00576c18:
              if (1.0 <= fVar21) goto LAB_00576c1d;
              goto LAB_00576c35;
            }
            fVar21 = *(float *)(iVar11 + 0x18) + fVar21;
            *(float *)(iVar11 + 0x18) = fVar21;
            if (1.0 < fVar21) {
              *(float *)(iVar19 + 0x18) = fVar21 - 1.0;
              *(undefined4 *)(iVar11 + 0x18) = 0x3f800000;
              fVar21 = *(float *)(iVar19 + 0x18);
              *(float *)(iVar19 + 0x1c) = fVar21;
              goto LAB_00576c18;
            }
            *(undefined4 *)(iVar19 + 0x18) = 0;
            *(undefined4 *)(iVar19 + 0x1c) = 0;
LAB_00576b90:
            bVar3 = 0;
          }
          else {
            *(undefined4 *)(iVar19 + 0x18) = 0x3f800000;
            fVar21 = 1.0;
LAB_00576c1d:
            if ((*(float *)(iVar10 + 0x18) != 0.0) || (*(short *)(iVar10 + 0x20) == 0)) {
LAB_00576c35:
              if ((1.0 <= fVar21) || ((fVar21 <= 0.0 || (*(short *)(iVar19 + 0x20) == 0))))
              goto LAB_00576b90;
            }
            bVar3 = 1;
          }
          iVar14 = iVar14 + 1;
          local_20 = (int *)((int)local_20 + 0x40);
          iVar12 = iVar12 + 1;
          local_14 = (int *)((int)local_14 + 0x40);
          local_c = local_c + 0x40;
          *(byte *)(iVar19 + 0x30) = bVar3;
          *(uint *)(iVar19 + 0x3c) = (uint)bVar3;
          iVar6 = iVar6 + 1;
          local_44 = local_44 + -1;
          pcVar16 = RaiseException_exref;
        } while (local_44 != 0);
      }
      iVar7 = iVar7 + iVar9;
      local_2c = local_2c + iVar5;
      iVar15 = iVar15 + iVar5;
      local_34 = local_34 + iVar9;
      local_38 = local_38 + iVar9;
      local_4c = local_4c + -1;
      pcVar16 = RaiseException_exref;
    } while (local_4c != 0);
  }
  return;
}

