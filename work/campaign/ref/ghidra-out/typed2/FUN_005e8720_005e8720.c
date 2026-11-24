
uint FUN_005e8720(float *param_1)

{
  uint uVar1;
  CHeightBlockArray *pCVar2;
  CMap *pCVar3;
  byte bVar4;
  int iVar5;
  CMap *extraout_EAX;
  int *piVar6;
  CHeightBlock *pCVar7;
  float *in_ECX;
  float *in_EDX;
  char *pcVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  int local_30;
  float local_10;
  float local_c;
  float local_8;
  
  local_30 = (int)PTR_0077241c;
  if ((((PTR_0077241c->x0f + 12.0 <= *in_ECX) && (*in_ECX < PTR_0077241c->x1f - 12.0)) &&
      (PTR_0077241c->y0f + 12.0 <= in_ECX[1])) && (in_ECX[1] < PTR_0077241c->y1f - 12.0)) {
    DAT_00772dd8 = (uint)ROUND(*in_ECX);
    local_30 = *(undefined4 *)(DAT_00772400 + 100);
    iVar5 = FUN_00592f10(PTR_0077241c);
    pcVar8 = (char *)(iVar5 + 0x34);
    if ((CMap *)&DAT_00000007 < (uint)local_30) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_30 = (int)extraout_EAX;
    }
    else {
      pcVar8 = pcVar8 + local_30;
    }
    if (*pcVar8 != '\0') {
      fVar14 = (in_EDX[2] * 0.01) / 1.4 + in_ECX[2];
      fVar9 = (*in_EDX * 0.005) / 1.4 + *in_ECX;
      fVar15 = (*param_1 * 0.005) / 1.4 + *in_ECX;
      fVar12 = (param_1[2] * 0.01) / 1.4 + in_ECX[2];
      fVar13 = param_1[1] * 0.005 + in_ECX[1];
      DAT_00772dd8 = (uint)ROUND(fVar9 * 8.0);
      bVar4 = FUN_004093f0(PTR_0077241c);
      if (fVar14 <= (float)bVar4) {
        DAT_00772dd8 = (uint)ROUND(fVar9 * 8.0);
        bVar4 = FUN_004093f0(PTR_0077241c);
        if (fVar12 <= (float)bVar4) {
          DAT_00772dd8 = (uint)ROUND(fVar15 * 8.0);
          bVar4 = FUN_004093f0(PTR_0077241c);
          if (fVar14 <= (float)bVar4) {
            DAT_00772dd8 = (uint)ROUND(fVar15 * 8.0);
            bVar4 = FUN_004093f0(PTR_0077241c);
            if (fVar12 <= (float)bVar4) {
              local_8 = 0.0;
              local_10 = 0.0;
              local_30 = 0;
              local_c = 0.0;
              do {
                pCVar3 = PTR_0077241c;
                switch(local_30) {
                case 0:
                  local_10 = fVar13;
                  local_c = fVar9;
                  local_8 = fVar14;
                  break;
                case 1:
                  local_10 = fVar13;
                  local_c = fVar9;
                  local_8 = fVar12;
                  break;
                case 2:
                  local_10 = fVar13;
                  local_c = fVar15;
                  local_8 = fVar14;
                  break;
                case 3:
                  local_10 = fVar13;
                  local_c = fVar15;
                  local_8 = fVar12;
                }
                fVar10 = local_10 * 8.0;
                fVar11 = local_c * 8.0;
                DAT_00772dd8 = (int)ROUND(fVar11);
                piVar6 = (int *)FUN_00592f10(PTR_0077241c);
                pCVar2 = pCVar3->heightBlocks;
                iVar5 = *piVar6;
                if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  pCVar7 = pCVar2->data;
                }
                else {
                  pCVar7 = pCVar2->data + iVar5;
                }
                pCVar3 = PTR_0077241c;
                if ((float)pCVar7->heights[((int)ROUND(fVar10) & 7U) << 3 | (int)ROUND(fVar11) & 7U]
                    <= local_8) {
                  DAT_00772dd8 = (int)ROUND(fVar11);
                  piVar6 = (int *)FUN_00592f10(PTR_0077241c);
                  pCVar2 = pCVar3->heightBlocks;
                  iVar5 = *piVar6;
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
                              (int)ROUND(fVar11) & 7U] <= local_8) {
                    uVar1 = (uint)ROUND((local_c + 0.375) * 8.0);
                    DAT_00772dd8 = uVar1;
                    piVar6 = (int *)FUN_00592f10(PTR_0077241c);
                    pCVar2 = pCVar3->heightBlocks;
                    iVar5 = *piVar6;
                    if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      pCVar7 = pCVar2->data;
                    }
                    else {
                      pCVar7 = pCVar2->data + iVar5;
                    }
                    pCVar3 = PTR_0077241c;
                    if ((float)pCVar7->heights[((int)ROUND(fVar10) & 7U) << 3 | uVar1 & 7] <=
                        local_8) {
                      uVar1 = (uint)ROUND((local_c - 0.375) * 8.0);
                      DAT_00772dd8 = uVar1;
                      piVar6 = (int *)FUN_00592f10(PTR_0077241c);
                      pCVar2 = pCVar3->heightBlocks;
                      iVar5 = *piVar6;
                      if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        pCVar7 = pCVar2->data;
                      }
                      else {
                        pCVar7 = pCVar2->data + iVar5;
                      }
                      pCVar3 = PTR_0077241c;
                      if ((float)pCVar7->heights[((int)ROUND(fVar10) & 7U) << 3 | uVar1 & 7] <=
                          local_8) {
                        DAT_00772dd8 = (int)ROUND(fVar11);
                        piVar6 = (int *)FUN_00592f10(PTR_0077241c);
                        pCVar2 = pCVar3->heightBlocks;
                        iVar5 = *piVar6;
                        if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          pCVar7 = pCVar2->data;
                        }
                        else {
                          pCVar7 = pCVar2->data + iVar5;
                        }
                        pCVar3 = PTR_0077241c;
                        if ((float)pCVar7->heights
                                   [((int)ROUND(fVar10) & 7U) << 3 | (int)ROUND(fVar11) & 7U] <=
                            local_8 + 1.0) {
                          DAT_00772dd8 = (int)ROUND(fVar11);
                          piVar6 = (int *)FUN_00592f10(PTR_0077241c);
                          pCVar2 = pCVar3->heightBlocks;
                          iVar5 = *piVar6;
                          if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            pCVar7 = pCVar2->data;
                          }
                          else {
                            pCVar7 = pCVar2->data + iVar5;
                          }
                          if ((float)pCVar7->heights
                                     [((int)ROUND(fVar10) & 7U) << 3 | (int)ROUND(fVar11) & 7U] <=
                              local_8 - 1.0) {
                            return 1;
                          }
                        }
                      }
                    }
                  }
                }
                else {
                  DAT_00772dd8 = (int)ROUND(fVar11);
                  piVar6 = (int *)FUN_00592f10(PTR_0077241c);
                  pCVar2 = pCVar3->heightBlocks;
                  iVar5 = *piVar6;
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
                                        (int)ROUND(fVar11) & 7U]) {
                    uVar1 = (uint)ROUND((local_c + 0.375) * 8.0);
                    DAT_00772dd8 = uVar1;
                    piVar6 = (int *)FUN_00592f10(PTR_0077241c);
                    pCVar2 = pCVar3->heightBlocks;
                    iVar5 = *piVar6;
                    if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      pCVar7 = pCVar2->data;
                    }
                    else {
                      pCVar7 = pCVar2->data + iVar5;
                    }
                    pCVar3 = PTR_0077241c;
                    if (local_8 < (float)pCVar7->heights[((int)ROUND(fVar10) & 7U) << 3 | uVar1 & 7]
                       ) {
                      uVar1 = (uint)ROUND((local_c - 0.375) * 8.0);
                      DAT_00772dd8 = uVar1;
                      piVar6 = (int *)FUN_00592f10(PTR_0077241c);
                      pCVar2 = pCVar3->heightBlocks;
                      iVar5 = *piVar6;
                      if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        pCVar7 = pCVar2->data;
                      }
                      else {
                        pCVar7 = pCVar2->data + iVar5;
                      }
                      pCVar3 = PTR_0077241c;
                      if (local_8 < (float)pCVar7->heights
                                           [((int)ROUND(fVar10) & 7U) << 3 | uVar1 & 7]) {
                        DAT_00772dd8 = (int)ROUND(fVar11);
                        piVar6 = (int *)FUN_00592f10(PTR_0077241c);
                        pCVar2 = pCVar3->heightBlocks;
                        iVar5 = *piVar6;
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
                                   [((int)ROUND(fVar10) & 7U) << 3 | (int)ROUND(fVar11) & 7U]) {
                          DAT_00772dd8 = (int)ROUND(fVar11);
                          piVar6 = (int *)FUN_00592f10(PTR_0077241c);
                          pCVar2 = pCVar3->heightBlocks;
                          iVar5 = *piVar6;
                          if ((iVar5 < 0) || (pCVar2->count <= iVar5)) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            pCVar7 = pCVar2->data;
                          }
                          else {
                            pCVar7 = pCVar2->data + iVar5;
                          }
                          if (local_8 - 1.0 <
                              (float)pCVar7->heights
                                     [((int)ROUND(fVar10) & 7U) << 3 | (int)ROUND(fVar11) & 7U]) {
                            return 1;
                          }
                        }
                      }
                    }
                  }
                }
                local_30 = local_30 + 1;
              } while (local_30 < 4);
              goto LAB_005e925f;
            }
          }
        }
      }
      return 1;
    }
  }
LAB_005e925f:
  return local_30 & 0xffffff00;
}

