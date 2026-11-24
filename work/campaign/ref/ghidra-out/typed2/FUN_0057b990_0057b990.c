
void FUN_0057b990(int *param_1)

{
  float fVar1;
  CHeightBlockArray *pCVar2;
  CMap *pCVar3;
  CMapCell *pCVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int in_ECX;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  CHeightBlock *pCVar14;
  CHeightBlock **ppCVar15;
  code *pcVar16;
  int iVar17;
  bool bVar18;
  float fVar19;
  byte local_6a;
  byte local_69;
  uint local_68;
  int local_64;
  float local_5c;
  
  pcVar16 = RaiseException_exref;
  iVar9 = param_1[1];
  if (iVar9 < param_1[3]) {
    do {
      iVar5 = *param_1;
      if (iVar5 < param_1[2]) {
        do {
          pCVar3 = PTR_0077241c;
          iVar12 = PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= iVar5) {
            iVar12 = iVar5;
          }
          iVar7 = PTR_0077241c->cellX1 + -1;
          if (iVar12 < PTR_0077241c->cellX1) {
            iVar7 = iVar12;
          }
          iVar12 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar9) {
            iVar12 = iVar9;
          }
          if (PTR_0077241c->cellY1 <= iVar12) {
            iVar12 = PTR_0077241c->cellY1 + -1;
          }
          iVar12 = (PTR_0077241c->mapWidth * iVar12 + iVar7) % PTR_0077241c->cellCountTotal;
          if ((iVar12 < 0) || (PTR_0077241c->cellCount <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar4 = pCVar3->cells;
          }
          else {
            pCVar4 = PTR_0077241c->cells + iVar12;
          }
          pCVar4->field_0x10 = 0;
          iVar5 = iVar5 + 1;
        } while (iVar5 < param_1[2]);
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < param_1[3]);
  }
  local_68 = 0;
  if (0 < *(int *)(in_ECX + 0xd)) {
    bVar18 = *(int *)(in_ECX + 0xd) != 0;
    local_64 = 0;
    do {
      if (!bVar18) {
        (*pcVar16)(0xc000008c,1,0,0);
      }
      uVar10 = *(uint *)(local_64 + *(int *)(in_ECX + 9));
      piVar6 = (int *)(DAT_0077244c + 0x488);
      if (uVar10 < 0x2000) {
        piVar6 = piVar6 + uVar10;
      }
      else {
        (*pcVar16)(0xc000008c,1,0,0);
      }
      iVar9 = *piVar6;
      if (iVar9 == 0) {
        uVar10 = *(uint *)(in_ECX + 0xd);
        if (uVar10 <= local_68) {
          (*pcVar16)(0xc000008c,1,0,0);
          uVar10 = *(uint *)(in_ECX + 0xd);
          if (uVar10 <= local_68) {
            (*pcVar16)(0xc000008c,1,0,0);
            uVar10 = *(uint *)(in_ECX + 0xd);
          }
        }
        if ((int)local_68 < (int)(uVar10 - 1)) {
          iVar9 = local_64 + *(int *)(in_ECX + 9);
          FUN_006d1b90(iVar9,iVar9 + 0x2c,(uVar10 - local_68) * 0x2c + -0x2c);
          uVar10 = *(uint *)(in_ECX + 0xd);
        }
        *(uint *)(in_ECX + 0xd) = uVar10 - 1;
        local_68 = local_68 - 1;
        local_64 = local_64 + -0x2c;
      }
      else {
        bVar18 = true;
        if (*(int *)(iVar9 + 0x3ec) != 0) {
          iVar5 = *(int *)(*(int *)(iVar9 + 0x3ec) + 0xc);
          if ((iVar5 == 0) || (*(int *)(iVar5 + 0x34) != 3)) {
            bVar18 = false;
          }
          else {
            bVar18 = true;
          }
        }
        if (((*(uint *)(iVar9 + 0x3d0) & 0x4000) == 0) && (bVar18)) {
          fVar19 = *(float *)(iVar9 + 0xc);
          fVar1 = *(float *)(iVar9 + 0x10);
          uVar10 = *(uint *)(in_ECX + 0xd);
          if (uVar10 <= local_68) {
            (*pcVar16)(0xc000008c,1,0,0);
            uVar10 = *(uint *)(in_ECX + 0xd);
          }
          fVar19 = fVar19 + 0.5;
          iVar9 = *(int *)(in_ECX + 9);
          iVar5 = *(int *)(local_64 + 0x14 + iVar9) + (int)fVar19;
          if (uVar10 <= local_68) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar9 = *(int *)(in_ECX + 9);
            uVar10 = *(uint *)(in_ECX + 0xd);
          }
          iVar12 = *(int *)(local_64 + 0x18 + iVar9) + (int)fVar1;
          if (uVar10 <= local_68) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar9 = *(int *)(in_ECX + 9);
            uVar10 = *(uint *)(in_ECX + 0xd);
          }
          iVar7 = *(int *)(local_64 + 0x1c + iVar9) + (int)fVar19;
          if (uVar10 <= local_68) {
            (*pcVar16)(0xc000008c,1,0,0);
            iVar9 = *(int *)(in_ECX + 9);
          }
          iVar9 = *(int *)(local_64 + 0x20 + iVar9) + (int)fVar1;
          if ((((param_1[1] < iVar9) && (iVar12 < param_1[3])) && (*param_1 < iVar7)) &&
             (iVar5 < param_1[2])) {
            iVar17 = *param_1;
            if (*param_1 < iVar5) {
              iVar17 = iVar5;
            }
            iVar5 = param_1[2];
            if (iVar7 < param_1[2]) {
              iVar5 = iVar7;
            }
            iVar7 = param_1[1];
            if (param_1[1] < iVar12) {
              iVar7 = iVar12;
            }
            iVar12 = param_1[3];
            if (iVar9 < param_1[3]) {
              iVar12 = iVar9;
            }
            for (; iVar9 = iVar17, pCVar3 = PTR_0077241c, iVar7 < iVar12; iVar7 = iVar7 + 1) {
              for (; PTR_0077241c = pCVar3, iVar9 < iVar5; iVar9 = iVar9 + 1) {
                iVar13 = pCVar3->cellX0;
                if (pCVar3->cellX0 <= iVar9) {
                  iVar13 = iVar9;
                }
                iVar11 = pCVar3->cellY0;
                if (pCVar3->cellY0 <= iVar7) {
                  iVar11 = iVar7;
                }
                iVar8 = pCVar3->cellY1 + -1;
                if (iVar11 < pCVar3->cellY1) {
                  iVar8 = iVar11;
                }
                iVar11 = pCVar3->cellX1 + -1;
                if (iVar13 < pCVar3->cellX1) {
                  iVar11 = iVar13;
                }
                iVar13 = (iVar8 * pCVar3->mapWidth + iVar11) % pCVar3->cellCountTotal;
                if ((iVar13 < 0) || (pCVar3->cellCount <= iVar13)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar4 = pCVar3->cells;
                }
                else {
                  pCVar4 = pCVar3->cells + iVar13;
                }
                iVar13 = pCVar4->heightBlockIndex;
                pCVar2 = PTR_0077241c->heightBlocks;
                if ((iVar13 < 0) || (pCVar2->count <= iVar13)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar13 = pCVar4->heightBlockIndex;
                  local_6a = pCVar2->data->heights[0];
                  ppCVar15 = &PTR_0077241c->heightBlocks->data;
                  if (-1 < iVar13) goto LAB_0057bdcd;
LAB_0057bdec:
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar13 = pCVar4->heightBlockIndex;
                  local_69 = (*ppCVar15)->heights[7];
                  ppCVar15 = &PTR_0077241c->heightBlocks->data;
                  if (-1 < iVar13) goto LAB_0057be17;
LAB_0057be23:
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar14 = *ppCVar15;
                }
                else {
                  local_6a = pCVar2->data[iVar13].heights[0];
                  ppCVar15 = &PTR_0077241c->heightBlocks->data;
LAB_0057bdcd:
                  if ((int)ppCVar15[1] <= iVar13) goto LAB_0057bdec;
                  local_69 = (*ppCVar15)[iVar13].heights[7];
                  ppCVar15 = &PTR_0077241c->heightBlocks->data;
LAB_0057be17:
                  if ((int)ppCVar15[1] <= iVar13) goto LAB_0057be23;
                  pCVar14 = *ppCVar15 + iVar13;
                }
                local_5c = 1.0 - (float)(pCVar4->field_0x10 & 0xf) / 15.0;
                fVar19 = 1.0 - (float)((byte)pCVar4->field_0x10 >> 4) / 15.0;
                if ((10 < local_6a) && (10 < pCVar14->heights[0x38])) {
                  if (*(uint *)(in_ECX + 0xd) <= local_68) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  local_5c = local_5c * *(float *)(local_64 + 0x24 + *(int *)(in_ECX + 9));
                }
                if ((10 < local_6a) && (10 < local_69)) {
                  if (*(uint *)(in_ECX + 0xd) <= local_68) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  fVar19 = fVar19 * *(float *)(local_64 + 0x28 + *(int *)(in_ECX + 9));
                }
                pCVar4->field_0x10 =
                     (char)(int)((1.0 - fVar19) * 15.0) << 4 | (byte)(int)((1.0 - local_5c) * 15.0);
                pCVar3 = PTR_0077241c;
              }
              pcVar16 = RaiseException_exref;
            }
          }
        }
      }
      local_68 = local_68 + 1;
      local_64 = local_64 + 0x2c;
      bVar18 = local_68 < *(uint *)(in_ECX + 0xd);
    } while ((int)local_68 < (int)*(uint *)(in_ECX + 0xd));
  }
  return;
}

