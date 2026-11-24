
CMap * FUN_00472190(void)

{
  float fVar1;
  float fVar2;
  CHeightBlockArray *pCVar3;
  undefined4 *puVar4;
  int *piVar5;
  CHeightBlock *pCVar6;
  int iVar7;
  CMap *pCVar8;
  uint uVar9;
  CMap *pCVar10;
  undefined4 uVar11;
  float *pfVar12;
  uint uVar13;
  float *pfVar14;
  float *pfVar15;
  code *pcVar16;
  undefined4 *puVar17;
  int iVar18;
  float fVar19;
  undefined4 **ppuVar20;
  char *pcVar21;
  float local_70;
  float local_6c;
  float local_64;
  float local_60;
  float local_5c;
  undefined4 *local_58;
  float local_54;
  float local_50;
  undefined4 *local_4c;
  undefined4 *local_48;
  int local_44;
  float local_40;
  int local_3c;
  float local_38;
  float local_34;
  int local_30;
  float local_2c;
  float local_28;
  CMap *local_24;
  float local_20;
  uint local_1c;
  float local_18;
  float *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fd8dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pCVar10 = DAT_00772400;
  if (((char)DAT_00772400[7].cellCount == '\0') && (DAT_00768371 != '\0')) {
    local_24 = (CMap *)FUN_00592d70(DAT_0076700c ^ (uint)&stack0xfffffffc);
    local_1c = 0;
    local_44 = DAT_00772400->mapFlagsE;
    pcVar16 = RaiseException_exref;
    do {
      uVar13 = local_1c;
      pCVar8 = local_24;
      if (local_1c < 0x800) {
        pCVar10 = (CMap *)((int)&local_24->field_0x0 + local_1c * 9 * 4);
      }
      else {
        (*pcVar16)(0xc000008c,1,0,0);
        pCVar10 = pCVar8;
      }
      local_40 = (float)pCVar10->mapFlags4;
      if (uVar13 < 0x800) {
        pCVar10 = (CMap *)((int)&pCVar8->field_0x0 + uVar13 * 9 * 4);
      }
      else {
        (*pcVar16)(0xc000008c,1,0,0);
        pCVar10 = pCVar8;
      }
      if ((0.0 < (float)pCVar10->cellCount) && (0.0 < local_40)) {
        if (uVar13 < 0x800) {
          pCVar10 = (CMap *)((int)&pCVar8->field_0x0 + uVar13 * 9 * 4);
        }
        else {
          (*pcVar16)(0xc000008c,1,0,0);
          pCVar10 = pCVar8;
        }
        fVar1 = *(float *)pCVar10;
        fVar2 = (float)pCVar10->mapFlags0;
        fVar19 = (float)pCVar10->mapFlags1 * 0.5 + 7.0;
        local_34 = *(float *)(local_30 + 0x2770) * fVar2 + *(float *)(local_30 + 0x2760) * fVar1 +
                   *(float *)(local_30 + 0x2780) * fVar19 + *(float *)(local_30 + 0x2790);
        local_38 = (*(float *)(local_30 + 0x2764) * fVar2 + fVar1 * *(float *)(local_30 + 0x2754) +
                    *(float *)(local_30 + 0x2774) * fVar19 + *(float *)(local_30 + 0x2784)) /
                   local_34;
        local_34 = (*(float *)(local_30 + 0x2768) * fVar2 + *(float *)(local_30 + 0x2758) * fVar1 +
                    *(float *)(local_30 + 0x2778) * fVar19 + *(float *)(local_30 + 0x2788)) /
                   local_34;
        pCVar10 = PTR_0077241c;
        if (((((PTR_0077241c->x0f + 32.0 <= fVar1) && (fVar1 < PTR_0077241c->x1f - 32.0)) &&
             (PTR_0077241c->y0f + 32.0 <= fVar2)) &&
            ((fVar2 < PTR_0077241c->y1f - 32.0 && (-130.0 < local_38)))) &&
           ((-130.0 < local_34 &&
            ((local_38 < (float)*(int *)(local_30 + 0x2830) + 130.0 &&
             (local_34 < (float)*(int *)(local_30 + 0x2834) + 130.0)))))) {
          local_3c = FUN_005ab220(local_44);
          local_28 = 0.0;
          if (1 < local_3c) {
            local_14 = (float *)0x3f800000;
            local_20 = 16.0;
            if (uVar13 < 0x800) {
              pCVar10 = (CMap *)((int)&pCVar8->field_0x0 + uVar13 * 9 * 4);
            }
            else {
              (*pcVar16)(0xc000008c,1,0,0);
              pCVar10 = pCVar8;
            }
            local_18 = (float)pCVar10->mapFlags1 * 0.5 + 7.0 + 1.0;
            if (local_18 < 16.0) {
              local_64 = local_38;
              local_60 = local_34;
              do {
                local_5c = local_20;
                FUN_00479150(&local_70,&local_64);
                pCVar10 = PTR_0077241c;
                if ((0.125 <= local_70) && (0.125 <= local_6c)) {
                  local_28 = local_6c * 8.0;
                  fVar1 = ROUND(local_28);
                  local_2c = local_70 * 8.0;
                  DAT_00772dd8 = (float)(int)ROUND(local_2c);
                  local_40 = DAT_00772dd8;
                  piVar5 = (int *)FUN_00592f10(PTR_0077241c);
                  pCVar3 = pCVar10->heightBlocks;
                  iVar7 = *piVar5;
                  if ((iVar7 < 0) || (pCVar3->count <= iVar7)) {
                    (*pcVar16)(0xc000008c,1,0,0);
                    pCVar6 = pCVar3->data;
                  }
                  else {
                    pCVar6 = pCVar3->data + iVar7;
                  }
                  pCVar10 = PTR_0077241c;
                  if (local_18 < (float)pCVar6->heights[((int)fVar1 & 7U) << 3 | (uint)local_40 & 7]
                     ) {
                    local_14 = (float *)((float)local_14 - 0.2);
                  }
                  fVar1 = ROUND(local_28);
                  DAT_00772dd8 = (float)(int)ROUND(local_2c);
                  local_40 = (float)((int)DAT_00772dd8 - 1);
                  piVar5 = (int *)FUN_00592f10(PTR_0077241c);
                  pCVar3 = pCVar10->heightBlocks;
                  iVar7 = *piVar5;
                  if ((iVar7 < 0) || (pCVar3->count <= iVar7)) {
                    (*pcVar16)(0xc000008c,1,0,0);
                    pCVar6 = pCVar3->data;
                  }
                  else {
                    pCVar6 = pCVar3->data + iVar7;
                  }
                  pCVar10 = PTR_0077241c;
                  if (local_18 < (float)pCVar6->heights[((int)fVar1 & 7U) << 3 | (uint)local_40 & 7]
                     ) {
                    local_14 = (float *)((float)local_14 - 0.2);
                  }
                  fVar1 = ROUND(local_28);
                  DAT_00772dd8 = (float)(int)ROUND(local_2c);
                  local_40 = (float)((int)DAT_00772dd8 + 1);
                  piVar5 = (int *)FUN_00592f10(PTR_0077241c);
                  pCVar3 = pCVar10->heightBlocks;
                  iVar7 = *piVar5;
                  if ((iVar7 < 0) || (pCVar3->count <= iVar7)) {
                    (*pcVar16)(0xc000008c,1,0,0);
                    pCVar6 = pCVar3->data;
                  }
                  else {
                    pCVar6 = pCVar3->data + iVar7;
                  }
                  pCVar10 = PTR_0077241c;
                  if (local_18 < (float)pCVar6->heights[((int)fVar1 & 7U) << 3 | (uint)local_40 & 7]
                     ) {
                    local_14 = (float *)((float)local_14 - 0.2);
                  }
                  fVar1 = ROUND(local_28);
                  DAT_00772dd8 = (float)(int)ROUND(local_2c);
                  local_40 = DAT_00772dd8;
                  piVar5 = (int *)FUN_00592f10(PTR_0077241c);
                  pCVar3 = pCVar10->heightBlocks;
                  iVar7 = *piVar5;
                  if ((iVar7 < 0) || (pCVar3->count <= iVar7)) {
                    (*pcVar16)(0xc000008c,1,0,0);
                    pCVar6 = pCVar3->data;
                  }
                  else {
                    pCVar6 = pCVar3->data + iVar7;
                  }
                  pCVar10 = PTR_0077241c;
                  if (local_18 <
                      (float)pCVar6->heights[((int)fVar1 - 1U & 7) << 3 | (uint)local_40 & 7]) {
                    local_14 = (float *)((float)local_14 - 0.2);
                  }
                  fVar1 = ROUND(local_28);
                  DAT_00772dd8 = (float)(int)ROUND(local_2c);
                  local_40 = DAT_00772dd8;
                  piVar5 = (int *)FUN_00592f10(PTR_0077241c);
                  pCVar3 = pCVar10->heightBlocks;
                  iVar7 = *piVar5;
                  if ((iVar7 < 0) || (pCVar3->count <= iVar7)) {
                    (*pcVar16)(0xc000008c,1,0,0);
                    pCVar6 = pCVar3->data;
                  }
                  else {
                    pCVar6 = pCVar3->data + iVar7;
                  }
                  if (local_18 <
                      (float)pCVar6->heights[((int)fVar1 + 1U & 7) << 3 | (uint)local_40 & 7]) {
                    local_14 = (float *)((float)local_14 - 0.2);
                  }
                  if ((float)local_14 <= 0.0) {
                    local_20 = -16.0;
                  }
                }
                local_20 = local_20 - 1.0;
                uVar13 = local_1c;
                pCVar8 = local_24;
              } while (local_18 < local_20);
            }
            iVar7 = 0;
            if (-1 < local_3c + -0x80) {
              iVar7 = local_3c + -0x80;
            }
            local_28 = (float)iVar7 * (float)local_14 * 0.0078125 * 0.5;
          }
          iVar7 = _rand();
          local_2c = ((float)(iVar7 % 10) / 100.0) / *(float *)(local_30 + 0x2814) + 1.0;
          pCVar10 = (CMap *)(iVar7 / 10);
          if (0.0 < local_28) {
            if (uVar13 < 0x800) {
              pCVar8 = (CMap *)((int)&pCVar8->field_0x0 + uVar13 * 9 * 4);
            }
            else {
              (*pcVar16)(0xc000008c,1,0,0);
            }
            iVar7 = pCVar8->mapFlags2;
            if (uVar13 < 0x800) {
              pCVar10 = (CMap *)((int)&local_24->field_0x0 + uVar13 * 9 * 4);
            }
            else {
              (*pcVar16)(0xc000008c,1,0,0);
              pCVar10 = local_24;
            }
            iVar18 = pCVar10->mapFlags3;
            if (local_1c < 0x800) {
              pCVar10 = (CMap *)((int)&local_24->field_0x0 + local_1c * 9 * 4);
            }
            else {
              (*pcVar16)(0xc000008c,1,0,0);
              pCVar10 = local_24;
            }
            iVar7 = (int)((float)(iVar7 << 3) * local_2c);
            if (0xff < iVar7) {
              iVar7 = 0xff;
            }
            local_48 = (undefined4 *)0x0;
            if (iVar7 < 0) {
              iVar7 = 0;
            }
            uVar13 = (uint)((float)(iVar18 << 3) * local_2c);
            if (0xff < (int)uVar13) {
              uVar13 = 0xff;
            }
            if ((int)uVar13 < 0) {
              uVar13 = 0;
            }
            uVar9 = (uint)((float)((int)pCVar10->cells << 3) * local_2c);
            if (0xff < (int)uVar9) {
              uVar9 = 0xff;
            }
            if ((int)uVar9 < 0) {
              uVar9 = 0;
            }
            local_18 = (float)((iVar7 << 8 | uVar13) << 8 | uVar9);
            ppuVar20 = &local_4c;
            local_8 = 0;
            pcVar21 = "Flares";
            FUN_0044d010(ppuVar20,"Flares");
            pCVar10 = (CMap *)FUN_0044d570(ppuVar20,pcVar21);
            puVar17 = *(undefined4 **)pCVar10;
            if (puVar17 != (undefined4 *)0x0) {
              LOCK();
              puVar17[1] = puVar17[1] + 1;
              UNLOCK();
            }
            local_58 = puVar17;
            local_48 = puVar17;
            if (local_4c != (undefined4 *)0x0) {
              LOCK();
              piVar5 = local_4c + 1;
              iVar7 = *piVar5;
              pCVar10 = (CMap *)*piVar5;
              *piVar5 = iVar7 + -1;
              UNLOCK();
              if ((iVar7 + -1 == 0) && (local_4c != (undefined4 *)0x0)) {
                pCVar10 = (CMap *)(**(code **)*local_4c)(1);
              }
            }
            if (puVar17 != (undefined4 *)0x0) {
              puVar17[3] = 4;
              puVar17[2] = 0x50;
              puVar17[4] = 5;
              local_40 = local_28 * 155.0;
              DAT_00772dd8 = (float)(int)ROUND(local_40);
              puVar17[5] = DAT_00772dd8;
              puVar17[0xf] = *(undefined4 *)(DAT_0076a324 + 0x45f4);
              puVar17[0xe] = 0;
              puVar17[0xd] = 0;
              puVar17[0xc] = 0;
              puVar17[0xb] = 0;
              puVar17[10] = 0;
              puVar17[9] = 0;
              puVar17[8] = 0;
              puVar17[7] = 0;
              puVar17[6] = 0;
              local_54 = (float)FUN_006ba810(0x115c);
              if (local_54 == 0.0) {
                iVar7 = 0;
              }
              else {
                iVar7 = FUN_0045fae0();
              }
              puVar4 = (undefined4 *)puVar17[0x11];
              puVar17[0x11] = iVar7;
              if (iVar7 != 0) {
                LOCK();
                *(int *)(iVar7 + 4) = *(int *)(iVar7 + 4) + 1;
                UNLOCK();
              }
              if (puVar4 != (undefined4 *)0x0) {
                LOCK();
                iVar7 = puVar4[1] + -1;
                puVar4[1] = iVar7;
                UNLOCK();
                if (iVar7 == 0) {
                  (**(code **)*puVar4)(1);
                }
              }
              FUN_0045fd00(0x1c4,4,0);
              iVar7 = puVar17[0x11];
              if ((*(int *)(iVar7 + 0x28) != 0) && (*(char *)(iVar7 + 9) == '\0')) {
                FUN_006ba940();
              }
              uVar11 = FUN_006ba810(0xb8);
              DAT_0076a2f0 = DAT_0076a2f0 + 0xc;
              *(undefined4 *)(iVar7 + 0x28) = uVar11;
              *(undefined4 *)(iVar7 + 0x2c) = 6;
              *(undefined1 *)(iVar7 + 9) = 0;
              **(undefined2 **)(puVar17[0x11] + 0x28) = 0;
              *(undefined2 *)(*(int *)(puVar17[0x11] + 0x28) + 2) = 1;
              *(undefined2 *)(*(int *)(puVar17[0x11] + 0x28) + 4) = 2;
              *(undefined2 *)(*(int *)(puVar17[0x11] + 0x28) + 6) = 1;
              *(undefined2 *)(*(int *)(puVar17[0x11] + 0x28) + 8) = 3;
              *(undefined2 *)(*(int *)(puVar17[0x11] + 0x28) + 10) = 2;
              iVar7 = *(int *)(puVar17[0x11] + 0x24);
              pfVar12 = (float *)FUN_0045feb0();
              iVar18 = 0;
              local_3c = 0;
              local_40 = 1.35926e-43;
              local_14 = pfVar12;
              do {
                local_28 = 0.0;
                pfVar15 = pfVar12 + iVar18 * 8;
                local_20 = 1.4013e-45;
                local_50 = ((float)local_3c - 0.5) * 356.0 * local_2c + local_34;
                local_54 = (float)(int)local_40 * 0.00390625;
                do {
                  if ((iVar18 < 0) || (pfVar14 = pfVar15, iVar7 <= iVar18)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar12 = local_14;
                    pfVar14 = local_14;
                  }
                  *pfVar14 = ((float)(int)local_28 - 0.5) * 356.0 * local_2c + local_38;
                  if ((iVar18 < 0) || (pfVar14 = pfVar15, iVar7 <= iVar18)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar12 = local_14;
                    pfVar14 = local_14;
                  }
                  pfVar14[1] = local_50;
                  if ((iVar18 < 0) || (pfVar14 = pfVar15, iVar7 <= iVar18)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar12 = local_14;
                    pfVar14 = local_14;
                  }
                  pfVar14[2] = 0.74999;
                  if ((iVar18 < 0) || (pfVar14 = pfVar15, iVar7 <= iVar18)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar12 = local_14;
                    pfVar14 = local_14;
                  }
                  pfVar14[3] = 1.3333511;
                  if ((iVar18 < 0) || (pfVar14 = pfVar15, iVar7 <= iVar18)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar12 = local_14;
                    pfVar14 = local_14;
                  }
                  pfVar14[6] = (float)(int)local_20 * 0.00390625;
                  if ((iVar18 < 0) || (pfVar14 = pfVar15, iVar7 <= iVar18)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar12 = local_14;
                    pfVar14 = local_14;
                  }
                  pfVar14[7] = local_54;
                  if ((iVar18 < 0) || (pfVar14 = pfVar15, iVar7 <= iVar18)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar12 = local_14;
                    pfVar14 = local_14;
                  }
                  pfVar14[4] = local_18;
                  if ((iVar18 < 0) || (pfVar14 = pfVar15, iVar7 <= iVar18)) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    pfVar12 = local_14;
                    pfVar14 = local_14;
                  }
                  puVar17 = local_58;
                  iVar18 = iVar18 + 1;
                  pfVar14[5] = local_18;
                  pfVar15 = pfVar15 + 8;
                  local_20 = (float)((int)local_20 + 0x57);
                  local_28 = (float)((int)local_28 + 1);
                } while ((int)local_20 < 0xaf);
                local_40 = (float)((int)local_40 + 0x57);
                local_3c = local_3c + 1;
              } while ((int)local_40 < 0x10f);
              iVar7 = local_58[0x11];
              piVar5 = (int *)(iVar7 + 0x10);
              *piVar5 = *piVar5 + -1;
              if ((*piVar5 == 0) && (*(int **)(iVar7 + 0x14) != (int *)0x0)) {
                piVar5 = (int *)**(int **)(iVar7 + 0x14);
                if (piVar5 != (int *)0x0) {
                  (**(code **)(*piVar5 + 0x18))();
                }
                *(undefined4 *)(iVar7 + 0xc) = 0;
              }
              piVar5 = puVar17 + 1;
              LOCK();
              *piVar5 = *piVar5 + 1;
              UNLOCK();
              local_8._0_1_ = 1;
              local_58 = puVar17;
              FUN_0044d010();
              local_8 = CONCAT31(local_8._1_3_,2);
              LOCK();
              *piVar5 = *piVar5 + 1;
              UNLOCK();
              FUN_00450720(puVar17);
              LOCK();
              iVar7 = *piVar5;
              pCVar10 = (CMap *)*piVar5;
              *piVar5 = iVar7 + -1;
              UNLOCK();
              pcVar16 = RaiseException_exref;
              if (iVar7 + -1 == 0) {
                pCVar10 = (CMap *)(**(code **)*puVar17)(1);
                pcVar16 = RaiseException_exref;
              }
            }
            local_8 = 0xffffffff;
            uVar13 = local_1c;
            if (puVar17 != (undefined4 *)0x0) {
              LOCK();
              piVar5 = puVar17 + 1;
              iVar7 = *piVar5;
              pCVar10 = (CMap *)*piVar5;
              *piVar5 = iVar7 + -1;
              UNLOCK();
              if (iVar7 + -1 == 0) {
                pCVar10 = (CMap *)(**(code **)*puVar17)(1);
                uVar13 = local_1c;
              }
            }
          }
        }
      }
      local_1c = uVar13 + 1;
    } while ((int)local_1c < 0x800);
  }
  ExceptionList = local_10;
  return pCVar10;
}

