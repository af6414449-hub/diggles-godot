
undefined4 FUN_005e76a0(int param_1,undefined4 param_2)

{
  uint uVar1;
  CHeightBlockArray *pCVar2;
  CMap *pCVar3;
  byte bVar4;
  int iVar5;
  char *pcVar6;
  CHeightBlock *pCVar7;
  float *in_ECX;
  uint in_EDX;
  int *piVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  int local_34;
  float local_10;
  float local_c;
  float local_8;
  
  if ((in_EDX != 0xffffffff) && (param_1 != -1)) {
    piVar8 = (int *)(DAT_00772400 + 0x5c8);
    if (in_EDX < 0x100) {
      piVar8 = piVar8 + in_EDX;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*piVar8 != 0) {
      iVar5 = FUN_004059a0(param_1);
      if ((((PTR_0077241c->x0f + 12.0 <= *in_ECX) && (*in_ECX < PTR_0077241c->x1f - 12.0)) &&
          (PTR_0077241c->y0f + 12.0 <= in_ECX[1])) && (in_ECX[1] < PTR_0077241c->y1f - 12.0)) {
        DAT_00772dd8 = (uint)ROUND(*in_ECX);
        FUN_00592f10(PTR_0077241c);
        pcVar6 = (char *)FUN_00423700(param_2);
        if (*pcVar6 != '\0') {
          fVar15 = *(float *)(iVar5 + 0x4c) * 0.01 * 0.95;
          fVar9 = *in_ECX;
          fVar12 = *(float *)(iVar5 + 0x50) * 0.005;
          fVar11 = *(float *)(iVar5 + 0x44) * 0.005;
          fVar13 = *(float *)(iVar5 + 0x58) * 0.01;
          fVar10 = in_ECX[2];
          fVar16 = fVar15 * 0.4 + fVar10;
          fVar19 = fVar11 * 0.4 + fVar9;
          fVar17 = fVar12 * 0.4 + fVar9;
          fVar18 = fVar13 + fVar10;
          fVar14 = *(float *)(iVar5 + 0x54) * 0.005 + in_ECX[1];
          fVar13 = fVar13 * 0.4 + fVar10;
          fVar11 = fVar11 + fVar9;
          fVar15 = fVar15 + fVar10;
          fVar12 = fVar12 + fVar9;
          DAT_00772dd8 = (uint)ROUND(fVar19 * 8.0);
          bVar4 = FUN_004093f0(PTR_0077241c);
          if ((float)bVar4 <= fVar16) {
            DAT_00772dd8 = (uint)ROUND(fVar19 * 8.0);
            bVar4 = FUN_004093f0(PTR_0077241c);
            if ((float)bVar4 <= fVar13) {
              DAT_00772dd8 = (uint)ROUND(fVar17 * 8.0);
              bVar4 = FUN_004093f0(PTR_0077241c);
              if ((float)bVar4 <= fVar16) {
                DAT_00772dd8 = (uint)ROUND(fVar17 * 8.0);
                bVar4 = FUN_004093f0(PTR_0077241c);
                if ((float)bVar4 <= fVar13) {
                  DAT_00772dd8 = (uint)ROUND((fVar19 + fVar17) * 0.5 * 8.0);
                  bVar4 = FUN_004093f0(PTR_0077241c);
                  if ((float)bVar4 <= (fVar16 + fVar16) * 0.5) {
                    DAT_00772dd8 = (uint)ROUND((fVar19 + fVar11) * 0.5 * 8.0);
                    fVar9 = (fVar16 + fVar15) * 0.5;
                    bVar4 = FUN_004093f0(PTR_0077241c);
                    if ((float)bVar4 <= fVar9) {
                      DAT_00772dd8 = (uint)ROUND((fVar17 + fVar12) * 0.5 * 8.0);
                      bVar4 = FUN_004093f0(PTR_0077241c);
                      if ((float)bVar4 <= fVar9) {
                        local_8 = 0.0;
                        local_10 = 0.0;
                        local_34 = 0;
                        local_c = 0.0;
                        do {
                          pCVar3 = PTR_0077241c;
                          switch(local_34) {
                          case 0:
                            local_10 = fVar14;
                            local_c = fVar11;
                            local_8 = fVar15;
                            break;
                          case 1:
                            local_10 = fVar14;
                            local_c = fVar11;
                            local_8 = fVar18;
                            break;
                          case 2:
                            local_10 = fVar14;
                            local_c = fVar12;
                            local_8 = fVar15;
                            break;
                          case 3:
                            local_10 = fVar14;
                            local_c = fVar12;
                            local_8 = fVar18;
                          }
                          fVar9 = local_10 * 8.0;
                          fVar10 = local_c * 8.0;
                          DAT_00772dd8 = (int)ROUND(fVar10);
                          piVar8 = (int *)FUN_00592f10(PTR_0077241c);
                          pCVar2 = pCVar3->heightBlocks;
                          iVar5 = *piVar8;
                          if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            pCVar7 = pCVar2->data;
                          }
                          else {
                            pCVar7 = pCVar2->data + iVar5;
                          }
                          pCVar3 = PTR_0077241c;
                          if ((float)pCVar7->heights
                                     [((int)ROUND(fVar9) & 7U) << 3 | (int)ROUND(fVar10) & 7U] <=
                              local_8) {
                            DAT_00772dd8 = (int)ROUND(fVar10);
                            piVar8 = (int *)FUN_00592f10(PTR_0077241c);
                            pCVar2 = pCVar3->heightBlocks;
                            iVar5 = *piVar8;
                            if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                              pCVar7 = pCVar2->data;
                            }
                            else {
                              pCVar7 = pCVar2->data + iVar5;
                            }
                            pCVar3 = PTR_0077241c;
                            if ((float)pCVar7->heights
                                       [((int)ROUND((local_10 + 0.25) * 8.0) & 7U) << 3 |
                                        (int)ROUND(fVar10) & 7U] <= local_8) {
                              uVar1 = (uint)ROUND((local_c + 0.375) * 8.0);
                              DAT_00772dd8 = uVar1;
                              piVar8 = (int *)FUN_00592f10(PTR_0077241c);
                              pCVar2 = pCVar3->heightBlocks;
                              iVar5 = *piVar8;
                              if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                pCVar7 = pCVar2->data;
                              }
                              else {
                                pCVar7 = pCVar2->data + iVar5;
                              }
                              pCVar3 = PTR_0077241c;
                              if ((float)pCVar7->heights[((int)ROUND(fVar9) & 7U) << 3 | uVar1 & 7]
                                  <= local_8) {
                                uVar1 = (uint)ROUND((local_c - 0.375) * 8.0);
                                DAT_00772dd8 = uVar1;
                                piVar8 = (int *)FUN_00592f10(PTR_0077241c);
                                pCVar2 = pCVar3->heightBlocks;
                                iVar5 = *piVar8;
                                if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                  pCVar7 = pCVar2->data;
                                }
                                else {
                                  pCVar7 = pCVar2->data + iVar5;
                                }
                                pCVar3 = PTR_0077241c;
                                if ((float)pCVar7->heights
                                           [((int)ROUND(fVar9) & 7U) << 3 | uVar1 & 7] <= local_8) {
                                  DAT_00772dd8 = (int)ROUND(fVar10);
                                  piVar8 = (int *)FUN_00592f10(PTR_0077241c);
                                  pCVar2 = pCVar3->heightBlocks;
                                  iVar5 = *piVar8;
                                  if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                    pCVar7 = pCVar2->data;
                                  }
                                  else {
                                    pCVar7 = pCVar2->data + iVar5;
                                  }
                                  pCVar3 = PTR_0077241c;
                                  if ((float)pCVar7->heights
                                             [((int)ROUND(fVar9) & 7U) << 3 |
                                              (int)ROUND(fVar10) & 7U] <= local_8 + 1.0) {
                                    DAT_00772dd8 = (int)ROUND(fVar10);
                                    piVar8 = (int *)FUN_00592f10(PTR_0077241c);
                                    pCVar2 = pCVar3->heightBlocks;
                                    iVar5 = *piVar8;
                                    if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                      pCVar7 = pCVar2->data;
                                    }
                                    else {
                                      pCVar7 = pCVar2->data + iVar5;
                                    }
                                    if ((float)pCVar7->heights
                                               [((int)ROUND(fVar9) & 7U) << 3 |
                                                (int)ROUND(fVar10) & 7U] <= local_8 - 1.0) {
                                      return 1;
                                    }
                                  }
                                }
                              }
                            }
                          }
                          else {
                            DAT_00772dd8 = (int)ROUND(fVar10);
                            piVar8 = (int *)FUN_00592f10(PTR_0077241c);
                            pCVar2 = pCVar3->heightBlocks;
                            iVar5 = *piVar8;
                            if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                              pCVar7 = pCVar2->data;
                            }
                            else {
                              pCVar7 = pCVar2->data + iVar5;
                            }
                            pCVar3 = PTR_0077241c;
                            if (local_8 < (float)pCVar7->heights
                                                 [((int)ROUND((local_10 - 0.375) * 8.0) & 7U) << 3 |
                                                  (int)ROUND(fVar10) & 7U]) {
                              uVar1 = (uint)ROUND((local_c + 0.375) * 8.0);
                              DAT_00772dd8 = uVar1;
                              piVar8 = (int *)FUN_00592f10(PTR_0077241c);
                              pCVar2 = pCVar3->heightBlocks;
                              iVar5 = *piVar8;
                              if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                pCVar7 = pCVar2->data;
                              }
                              else {
                                pCVar7 = pCVar2->data + iVar5;
                              }
                              pCVar3 = PTR_0077241c;
                              if (local_8 < (float)pCVar7->heights
                                                   [((int)ROUND(fVar9) & 7U) << 3 | uVar1 & 7]) {
                                uVar1 = (uint)ROUND((local_c - 0.375) * 8.0);
                                DAT_00772dd8 = uVar1;
                                piVar8 = (int *)FUN_00592f10(PTR_0077241c);
                                pCVar2 = pCVar3->heightBlocks;
                                iVar5 = *piVar8;
                                if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                  pCVar7 = pCVar2->data;
                                }
                                else {
                                  pCVar7 = pCVar2->data + iVar5;
                                }
                                pCVar3 = PTR_0077241c;
                                if (local_8 < (float)pCVar7->heights
                                                     [((int)ROUND(fVar9) & 7U) << 3 | uVar1 & 7]) {
                                  DAT_00772dd8 = (int)ROUND(fVar10);
                                  piVar8 = (int *)FUN_00592f10(PTR_0077241c);
                                  pCVar2 = pCVar3->heightBlocks;
                                  iVar5 = *piVar8;
                                  if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                    pCVar7 = pCVar2->data;
                                  }
                                  else {
                                    pCVar7 = pCVar2->data + iVar5;
                                  }
                                  pCVar3 = PTR_0077241c;
                                  if (local_8 + 1.0 <
                                      (float)pCVar7->heights
                                             [((int)ROUND(fVar9) & 7U) << 3 |
                                              (int)ROUND(fVar10) & 7U]) {
                                    DAT_00772dd8 = (int)ROUND(fVar10);
                                    piVar8 = (int *)FUN_00592f10(PTR_0077241c);
                                    pCVar2 = pCVar3->heightBlocks;
                                    iVar5 = *piVar8;
                                    if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                      pCVar7 = pCVar2->data;
                                    }
                                    else {
                                      pCVar7 = pCVar2->data + iVar5;
                                    }
                                    if (local_8 - 1.0 <
                                        (float)pCVar7->heights
                                               [((int)ROUND(fVar9) & 7U) << 3 |
                                                (int)ROUND(fVar10) & 7U]) {
                                      return 1;
                                    }
                                  }
                                }
                              }
                            }
                          }
                          local_34 = local_34 + 1;
                          if (3 < local_34) {
                            return 0;
                          }
                        } while( true );
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
  return 1;
}

