
undefined4 FUN_00566a60(int *param_1,int *param_2,int *param_3,byte param_4)

{
  byte bVar1;
  CHeightBlockArray *pCVar2;
  CMap *pCVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  int iVar10;
  CHeightBlock **ppCVar11;
  int *piVar12;
  int iVar13;
  CHeightBlock *pCVar14;
  byte *pbVar15;
  int iVar16;
  int in_ECX;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  code *pcVar21;
  code *pcVar22;
  int iVar23;
  CMapCell *pCVar24;
  CMapCell *pCVar25;
  undefined1 local_5;
  
  uVar5 = 0xf << ((byte)(*(int *)(in_ECX + 0x11c) << 2) & 0x1f);
  local_5 = 1;
  iVar16 = param_1[1];
  pcVar22 = RaiseException_exref;
  if (param_2[1] <= iVar16) {
    return CONCAT31((int3)((uint)iVar16 >> 8),1);
  }
  do {
    iVar17 = *param_1;
    pcVar21 = pcVar22;
    if (iVar17 < *param_2) {
      do {
        iVar18 = iVar17 - *param_1;
        iVar23 = iVar16 - param_1[1];
        if (*(uint *)(in_ECX + 0xdc) < 4) {
          iVar13 = in_ECX + *(uint *)(in_ECX + 0xdc) * 0x28;
        }
        else {
          (*pcVar21)(0xc000008c,1,0,0);
          iVar13 = in_ECX;
        }
        iVar6 = iVar23 * 0x20 + iVar18;
        iVar7 = iVar6 * 4;
        bVar1 = *(byte *)(iVar7 + *(int *)(iVar13 + 0x14));
        pcVar22 = pcVar21;
        if (bVar1 == 4) goto LAB_00567160;
        iVar13 = 0;
        if ((bVar1 & 3) != 0) {
          iVar13 = (bVar1 & 3) * 4 + -1;
        }
        if (*param_3 != 0) {
          iVar8 = iVar23 * 0x22 + 0x23 + iVar18;
          if ((iVar8 < 0) || (param_3[1] <= iVar8)) {
            (*pcVar21)(0xc000008c,1,0,0);
            puVar9 = (undefined1 *)*param_3;
          }
          else {
            puVar9 = (undefined1 *)(iVar8 + *param_3);
          }
          *puVar9 = 1;
        }
        pCVar3 = PTR_0077241c;
        pcVar22 = RaiseException_exref;
        if ((((iVar17 < PTR_0077241c->cellX0 + 1) || (PTR_0077241c->cellX1 + -1 <= iVar17)) ||
            (iVar16 < PTR_0077241c->cellY0 + 1)) || (PTR_0077241c->cellY1 + -1 <= iVar16)) {
          iVar13 = *param_3;
          pcVar22 = pcVar21;
joined_r0x0056712e:
          local_5 = 0;
          if (iVar13 != 0) {
LAB_00567137:
            local_5 = 0;
            iVar18 = iVar23 * 0x22 + 0x23 + iVar18;
            if ((iVar18 < 0) || (param_3[1] <= iVar18)) {
              (*pcVar22)(0xc000008c,1,0,0);
              pbVar15 = (byte *)*param_3;
            }
            else {
              pbVar15 = (byte *)(iVar18 + iVar13);
            }
            *pbVar15 = *pbVar15 | param_4;
          }
        }
        else {
          iVar8 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar17) {
            iVar8 = iVar17;
          }
          iVar10 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar16) {
            iVar10 = iVar16;
          }
          iVar19 = PTR_0077241c->cellY1 + -1;
          if (iVar10 < PTR_0077241c->cellY1) {
            iVar19 = iVar10;
          }
          iVar10 = PTR_0077241c->cellX1 + -1;
          if (iVar8 < PTR_0077241c->cellX1) {
            iVar10 = iVar8;
          }
          iVar8 = (iVar10 + iVar19 * PTR_0077241c->mapWidth) % PTR_0077241c->cellCountTotal;
          if ((iVar8 < 0) || (PTR_0077241c->cellCount <= iVar8)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar24 = pCVar3->cells;
          }
          else {
            pCVar24 = PTR_0077241c->cells + iVar8;
          }
          iVar8 = pCVar24->heightBlockIndex;
          ppCVar11 = &PTR_0077241c->heightBlocks->data;
          if ((iVar8 < 0) || (PTR_0077241c->heightBlocks->count <= iVar8)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar14 = *ppCVar11;
          }
          else {
            pCVar14 = *ppCVar11 + iVar8;
          }
          uVar4 = pCVar24->material & 3;
          if ((uVar4 == 3) || (uVar4 == 0)) {
LAB_00566ca5:
            iVar13 = *param_3;
            goto joined_r0x0056712e;
          }
          if (param_2[1] + -2 <= iVar16) {
            if (pCVar14->heights[0] < 0xc) {
              if (*(uint *)(in_ECX + 0x11c) < 8) {
                pCVar25 = (CMapCell *)(pCVar24->ownerIndex + (*(uint *)(in_ECX + 0x11c) - 0x34));
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar25 = pCVar24;
              }
              if (pCVar25->ownerIndex[0] != '\0') goto LAB_00566cc1;
            }
            goto LAB_00566ca5;
          }
LAB_00566cc1:
          pCVar3 = PTR_0077241c;
          piVar12 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar2 = pCVar3->heightBlocks;
          iVar8 = *piVar12;
          if ((iVar8 < 0) || (pCVar2->count <= iVar8)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar14 = pCVar2->data;
          }
          else {
            pCVar14 = pCVar2->data + iVar8;
          }
          if ((int)(uint)pCVar14->heights[0] < iVar13) {
            iVar13 = *param_3;
            goto joined_r0x0056712e;
          }
          uVar20 = pCVar24->digMarks >> ((byte)(*(int *)(in_ECX + 0x11c) << 2) & 0x1f);
          if (uVar20 == 0) {
            iVar8 = 0xf;
          }
          else if ((uVar20 & 8) == 0) {
            iVar8 = 0xb;
          }
          else {
            iVar8 = 0;
            if ((uVar20 & 3) != 0) {
              iVar8 = (uVar20 & 3) * 4 + -1;
            }
          }
          if (iVar8 < iVar13) {
            iVar13 = *param_3;
joined_r0x00566e19:
            local_5 = 0;
            if (iVar13 == 0) goto LAB_00567160;
            goto LAB_00567137;
          }
          if (iVar16 == param_2[1] + -1) {
            piVar12 = (int *)FUN_00592f10(PTR_0077241c);
            iVar13 = *piVar12;
            pCVar2 = PTR_0077241c->heightBlocks;
            if ((iVar13 < 0) || (pCVar2->count <= iVar13)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar14 = pCVar2->data;
            }
            else {
              pCVar14 = pCVar2->data + iVar13;
            }
            if (10 < pCVar14->heights[0]) {
              piVar12 = (int *)FUN_00592f10(PTR_0077241c);
              iVar13 = *piVar12;
              pCVar2 = PTR_0077241c->heightBlocks;
              if ((iVar13 < 0) || (pCVar2->count <= iVar13)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar14 = pCVar2->data;
              }
              else {
                pCVar14 = pCVar2->data + iVar13;
              }
              if (10 < pCVar14->heights[0]) goto LAB_00566e30;
            }
            iVar13 = *param_3;
            goto joined_r0x00566e19;
          }
LAB_00566e30:
          if (bVar1 == 3) goto LAB_00567160;
          if (*(uint *)(in_ECX + 0xdc) < 4) {
            iVar13 = in_ECX + *(uint *)(in_ECX + 0xdc) * 0x28;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar13 = in_ECX;
          }
          pCVar3 = PTR_0077241c;
          if (*(char *)(*(int *)(iVar13 + 0x14) + -0x80 + iVar6 * 4) == '\x04') {
            piVar12 = (int *)FUN_00592f10(PTR_0077241c);
            pCVar2 = pCVar3->heightBlocks;
            iVar13 = *piVar12;
            if ((iVar13 < 0) || (pCVar2->count <= iVar13)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar14 = pCVar2->data;
            }
            else {
              pCVar14 = pCVar2->data + iVar13;
            }
            if ((pCVar14->heights[0] != '\x0f') ||
               (iVar13 = FUN_00592f10(PTR_0077241c), (*(uint *)(iVar13 + 8) & uVar5) != 0)) {
              iVar13 = *param_3;
              goto joined_r0x0056712e;
            }
          }
          if (*(uint *)(in_ECX + 0xdc) < 4) {
            iVar13 = in_ECX + *(uint *)(in_ECX + 0xdc) * 0x28;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar13 = in_ECX;
          }
          pCVar3 = PTR_0077241c;
          if (*(char *)(*(int *)(iVar13 + 0x14) + -4 + iVar7) == '\x04') {
            piVar12 = (int *)FUN_00592f10(PTR_0077241c);
            pCVar2 = pCVar3->heightBlocks;
            iVar13 = *piVar12;
            if ((iVar13 < 0) || (pCVar2->count <= iVar13)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar14 = pCVar2->data;
            }
            else {
              pCVar14 = pCVar2->data + iVar13;
            }
            if ((pCVar14->heights[0] == '\x0f') &&
               (iVar13 = FUN_00592f10(PTR_0077241c), pCVar3 = PTR_0077241c,
               (*(uint *)(iVar13 + 8) & uVar5) == 0)) {
              piVar12 = (int *)FUN_00592f10(PTR_0077241c);
              pCVar2 = pCVar3->heightBlocks;
              iVar13 = *piVar12;
              if ((iVar13 < 0) || (pCVar2->count <= iVar13)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar14 = pCVar2->data;
              }
              else {
                pCVar14 = pCVar2->data + iVar13;
              }
              if ((pCVar14->heights[0] == '\x0f') &&
                 (iVar13 = FUN_00592f10(PTR_0077241c), (*(uint *)(iVar13 + 8) & uVar5) == 0))
              goto LAB_00567010;
            }
            iVar13 = *param_3;
            goto joined_r0x0056712e;
          }
LAB_00567010:
          if (*(uint *)(in_ECX + 0xdc) < 4) {
            iVar13 = in_ECX + *(uint *)(in_ECX + 0xdc) * 0x28;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar13 = in_ECX;
          }
          pCVar3 = PTR_0077241c;
          if (*(char *)(*(int *)(iVar13 + 0x14) + 4 + iVar7) == '\x04') {
            piVar12 = (int *)FUN_00592f10(PTR_0077241c);
            pCVar2 = pCVar3->heightBlocks;
            iVar13 = *piVar12;
            if ((iVar13 < 0) || (pCVar2->count <= iVar13)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar14 = pCVar2->data;
            }
            else {
              pCVar14 = pCVar2->data + iVar13;
            }
            if ((pCVar14->heights[0] == '\x0f') &&
               (iVar13 = FUN_00592f10(PTR_0077241c), pCVar3 = PTR_0077241c,
               (*(uint *)(iVar13 + 8) & uVar5) == 0)) {
              piVar12 = (int *)FUN_00592f10(PTR_0077241c);
              pCVar2 = pCVar3->heightBlocks;
              iVar13 = *piVar12;
              if ((iVar13 < 0) || (pCVar2->count <= iVar13)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar14 = pCVar2->data;
              }
              else {
                pCVar14 = pCVar2->data + iVar13;
              }
              if ((pCVar14->heights[0] == '\x0f') &&
                 (iVar13 = FUN_00592f10(PTR_0077241c), (*(uint *)(iVar13 + 8) & uVar5) == 0))
              goto LAB_00567160;
            }
            iVar13 = *param_3;
            goto joined_r0x0056712e;
          }
        }
LAB_00567160:
        iVar17 = iVar17 + 1;
        pcVar21 = pcVar22;
      } while (iVar17 < *param_2);
    }
    iVar16 = iVar16 + 1;
    if (param_2[1] <= iVar16) {
      return CONCAT31((int3)((uint)iVar16 >> 8),local_5);
    }
  } while( true );
}

