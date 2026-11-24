
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046b450(void)

{
  CHeightBlockArray *pCVar1;
  char cVar2;
  byte bVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  CMap *pCVar7;
  float *pfVar8;
  int iVar9;
  char *pcVar10;
  CHeightBlock *pCVar11;
  byte bVar12;
  int in_ECX;
  CMap *pCVar13;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  float fVar14;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  CMap *this;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  char cVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  undefined4 *puVar19;
  bool bVar20;
  CMap *pCVar21;
  float fVar22;
  undefined8 uVar23;
  undefined4 uVar24;
  undefined8 *puVar25;
  undefined1 local_224 [20];
  undefined4 local_210;
  undefined4 local_200;
  undefined4 local_1e4;
  float local_1c4;
  float local_1c0;
  float local_1bc;
  float local_1b8;
  float local_1b4;
  float local_1b0;
  float local_1a0;
  float local_19c;
  float local_198;
  float local_190;
  float local_18c;
  float local_188;
  float local_180;
  float local_17c;
  float local_178;
  float local_170;
  float local_16c;
  float local_168;
  undefined1 local_15c [12];
  undefined1 local_150 [12];
  float local_144;
  float local_140;
  float fStack_13c;
  CMap *local_138;
  float local_134;
  float fStack_130;
  float local_12c;
  float local_128;
  float fStack_124;
  float local_120;
  undefined4 local_11c;
  undefined4 local_118;
  float local_114;
  undefined8 local_110;
  CMap *local_108;
  undefined8 local_104;
  CMap *local_fc;
  undefined8 local_f8;
  float local_f0;
  undefined8 local_ec;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  CMap *pCStack_d0;
  CMap *local_cc;
  float local_c8;
  float fStack_c4;
  CMap *local_c0;
  float local_bc;
  CMap *pCStack_b8;
  CMap *local_b4;
  undefined8 local_b0;
  CMap *pCStack_a8;
  float local_98;
  undefined1 local_94 [4];
  int local_90;
  CMap *local_8c;
  CMap *local_88;
  undefined4 local_84;
  undefined4 local_80;
  CMap *local_7c;
  CMap *local_78;
  CMap *local_74;
  undefined8 local_70;
  float local_68;
  float local_58;
  CMap *local_54;
  CMap *local_50;
  int local_4c;
  CMap *local_48;
  float local_44;
  float local_40;
  CMap *local_3c;
  int *local_38;
  byte local_31;
  CMap *local_30;
  byte local_2a;
  byte local_29;
  int local_28;
  CMap *local_24;
  undefined1 *puStack_20;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  puStack_20 = &stack0xfffffffc;
  local_14 = 0xffffffff;
  puStack_18 = &LAB_006fd7d0;
  local_1c = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  if (*(char *)(DAT_00772400 + 0x8c) != '\0') {
    *(undefined1 *)(in_ECX + 0xcc) = 0;
    return;
  }
  local_78 = (CMap *)(in_ECX + 0xdc);
  local_31 = 0;
  ExceptionList = &local_1c;
  *(undefined4 *)(in_ECX + 0xe4) = 0;
  *(undefined4 *)(in_ECX + 0xe0) = 0;
  *(float *)local_78 = 0.0;
  iVar6 = *(int *)(in_ECX + 0xc0);
  *(undefined2 *)(in_ECX + 0xcc) = 0;
  local_4c = in_ECX;
  if (iVar6 == 8) {
    local_30 = (CMap *)0x1;
    local_2a = 1;
    puStack_20 = &stack0xfffffffc;
    FUN_0046aec0(&local_e0);
    local_3c = *(CMap **)(in_ECX + 0xb8);
    local_50 = *(CMap **)(in_ECX + 0xbc);
    if ((local_3c == (CMap *)0xffffffff) || (local_50 == (CMap *)0xffffffff)) goto LAB_00470b22;
    local_29 = *(byte *)(in_ECX + 0xf0);
    local_b0 = NAN;
    local_44 = 8.0;
    local_98 = 0.125;
    local_144 = 0.8;
    local_58 = 0.005;
    local_70 = 4.0;
    local_24 = (CMap *)0x40800000;
    local_8c = (CMap *)0x3c23d70a;
LAB_0046b5b7:
    if (local_29 == 0) {
      pCVar7 = PTR_0077241c;
      if ((((PTR_0077241c->x0f + (float)local_24 <= local_e0) &&
           (local_e0 < PTR_0077241c->x1f - (float)local_24)) &&
          (PTR_0077241c->y0f + (float)local_24 <= local_dc)) &&
         (local_dc < PTR_0077241c->y1f - (float)local_24)) {
        local_38 = (int *)local_e0;
        DAT_00772dd8 = (CMap *)(int)ROUND(local_e0);
        iVar6 = FUN_00592f10(PTR_0077241c);
        pCVar7 = (CMap *)(CONCAT31((int3)((uint)iVar6 >> 8),*(undefined1 *)(iVar6 + 0x18)) &
                         0xffffff03);
        if ((char)pCVar7 != '\x03') {
          local_40 = 2.8026e-45;
          do {
            local_38 = (int *)(local_e0 * local_44);
            DAT_00772dd8 = (CMap *)(int)ROUND((float)local_38);
            uVar17 = (int)ROUND(local_dc * local_44) + (int)local_40;
            uVar16 = (uint)DAT_00772dd8 & 7;
            iVar6 = FUN_00592f10(PTR_0077241c);
            bVar3 = *(byte *)(((uVar17 & 7) << 3 | uVar16) + iVar6 + 0x3c);
            pCVar7 = (CMap *)CONCAT31((int3)((uint)(iVar6 + 0x3c) >> 8),bVar3);
            if ((bVar3 & 2) != 0) {
              local_38 = (int *)(local_e0 * local_44);
              DAT_00772dd8 = (CMap *)(int)ROUND((float)local_38);
              uVar17 = (int)local_40 + (int)ROUND(local_dc * local_44) + 1;
              uVar16 = (uint)DAT_00772dd8 & 7;
              iVar6 = FUN_00592f10(PTR_0077241c);
              bVar3 = *(byte *)(((uVar17 & 7) << 3 | uVar16) + iVar6 + 0x3c);
              pCVar7 = (CMap *)CONCAT31((int3)((uint)(iVar6 + 0x3c) >> 8),bVar3);
              if ((bVar3 & 2) == 0) break;
            }
            local_40 = (float)((int)local_40 + 1);
          } while ((int)local_40 < 0x10);
          in_ECX = local_4c;
          if (local_40 != 2.24208e-44) {
            piVar18 = (int *)(DAT_00772400 + 0x5c8);
            local_dc = ((float)(int)local_40 * local_98 + local_dc) - local_144;
            if (local_3c < 0x100) {
              piVar18 = piVar18 + (int)local_3c;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            pCVar21 = local_50;
            local_38 = (int *)(*piVar18 + 0x34);
            if (((int)local_50 < 0) || (*(int *)(*piVar18 + 0x38) <= (int)local_50)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *local_38;
            }
            else {
              iVar6 = *local_38 + (int)local_50 * 0xe8;
            }
            local_40 = (float)((int)pCVar21 * 0xe8);
            local_54 = (CMap *)(*(float *)(iVar6 + 0x44) * local_58 + local_e0);
            local_38 = (int *)(DAT_00772400 + 0x5c8);
            if (local_3c < 0x100) {
              local_38 = local_38 + (int)local_3c;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar6 = *local_38;
            local_38 = (int *)(iVar6 + 0x34);
            if (((int)pCVar21 < 0) || (*(int *)(iVar6 + 0x38) <= (int)pCVar21)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *local_38;
            }
            else {
              iVar6 = *local_38 + (int)local_40;
            }
            local_38 = (int *)(DAT_00772400 + 0x5c8);
            local_88 = (CMap *)(*(float *)(iVar6 + 0x48) * local_58 + local_dc);
            if (local_3c < 0x100) {
              local_38 = local_38 + (int)local_3c;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar6 = *local_38;
            local_38 = (int *)(iVar6 + 0x34);
            if (((int)pCVar21 < 0) || (*(int *)(iVar6 + 0x38) <= (int)pCVar21)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *local_38;
            }
            else {
              iVar6 = *local_38 + (int)local_40;
            }
            local_38 = (int *)(DAT_00772400 + 0x5c8);
            local_48 = (CMap *)(*(float *)(iVar6 + 0x50) * local_58 + local_e0);
            if (local_3c < 0x100) {
              local_38 = local_38 + (int)local_3c;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar6 = *local_38;
            local_38 = (int *)(iVar6 + 0x34);
            if (((int)pCVar21 < 0) || (*(int *)(iVar6 + 0x38) <= (int)pCVar21)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *local_38;
            }
            else {
              iVar6 = *local_38 + (int)local_40;
            }
            pCVar7 = PTR_0077241c;
            local_88 = (CMap *)((float)local_88 * local_44);
            local_74 = (CMap *)(*(float *)(iVar6 + 0x54) * local_58 + local_dc);
            local_78 = (CMap *)(int)ROUND((float)local_88);
            local_54 = (CMap *)((float)local_54 * local_44);
            DAT_00772dd8 = (CMap *)(int)ROUND((float)local_54);
            local_38 = (int *)DAT_00772dd8;
            piVar18 = (int *)FUN_00592f10(PTR_0077241c);
            pCVar1 = pCVar7->heightBlocks;
            iVar6 = *piVar18;
            if ((iVar6 < 0) || (pCVar1->count <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar11 = pCVar1->data;
            }
            else {
              pCVar11 = pCVar1->data + iVar6;
            }
            pCVar7 = PTR_0077241c;
            local_74 = (CMap *)((float)local_74 * local_44);
            local_7c = (CMap *)(uint)pCVar11->heights
                                     [((uint)local_78 & 7) << 3 | (uint)local_38 & 7];
            local_38 = (int *)(int)ROUND((float)local_74);
            DAT_00772dd8 = (CMap *)(int)ROUND((float)local_54);
            local_78 = DAT_00772dd8;
            piVar18 = (int *)FUN_00592f10(PTR_0077241c);
            pCVar1 = pCVar7->heightBlocks;
            iVar6 = *piVar18;
            if ((iVar6 < 0) || (pCVar1->count <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar11 = pCVar1->data;
            }
            else {
              pCVar11 = pCVar1->data + iVar6;
            }
            pCVar7 = PTR_0077241c;
            local_54 = (CMap *)(uint)pCVar11->heights
                                     [((uint)local_38 & 7) << 3 | (uint)local_78 & 7];
            local_38 = (int *)(int)ROUND((float)local_88);
            local_48 = (CMap *)((float)local_48 * local_44);
            DAT_00772dd8 = (CMap *)(int)ROUND((float)local_48);
            local_78 = DAT_00772dd8;
            piVar18 = (int *)FUN_00592f10(PTR_0077241c);
            pCVar1 = pCVar7->heightBlocks;
            iVar6 = *piVar18;
            if ((iVar6 < 0) || (pCVar1->count <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar11 = pCVar1->data;
            }
            else {
              pCVar11 = pCVar1->data + iVar6;
            }
            pCVar7 = PTR_0077241c;
            local_88 = (CMap *)(uint)pCVar11->heights
                                     [((uint)local_38 & 7) << 3 | (uint)local_78 & 7];
            local_38 = (int *)(int)ROUND((float)local_74);
            local_78 = local_48;
            DAT_00772dd8 = (CMap *)(int)ROUND((float)local_48);
            local_48 = DAT_00772dd8;
            piVar18 = (int *)FUN_00592f10(PTR_0077241c);
            iVar6 = *piVar18;
            local_78 = (CMap *)&pCVar7->heightBlocks->data;
            if ((iVar6 < 0) || (pCVar7->heightBlocks->count <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar11 = *(CHeightBlock **)local_78;
            }
            else {
              pCVar11 = *(CHeightBlock **)local_78 + iVar6;
            }
            pCVar7 = local_7c;
            in_ECX = local_4c;
            if (((local_7c == local_54) && (local_7c == local_88)) &&
               (local_7c ==
                (CMap *)(uint)pCVar11->heights[((uint)local_38 & 7) << 3 | (uint)local_48 & 7])) {
              local_78 = (CMap *)(float)(int)local_7c;
              if ((double)CONCAT44((uint)((ulonglong)(double)(local_d8 - (float)local_78) >> 0x20) &
                                   (uint)local_b0._4_4_,
                                   SUB84((double)(local_d8 - (float)local_78),0) &
                                   (uint)(float)local_b0) < local_70) {
                local_7c = (CMap *)(DAT_00772400 + 0x5c8);
                if (local_3c < 0x100) {
                  local_7c = (CMap *)((int)local_7c + local_3c * 4);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                iVar6 = *(int *)local_7c;
                local_7c = (CMap *)(iVar6 + 0x34);
                if (((int)pCVar21 < 0) || (*(int *)(iVar6 + 0x38) <= (int)pCVar21)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar6 = *(int *)local_7c;
                }
                else {
                  iVar6 = *(int *)local_7c + (int)local_40;
                }
                local_7c = (CMap *)(DAT_00772400 + 0x5c8);
                local_d8 = (float)local_78 - *(float *)(iVar6 + 0x4c) * (float)local_8c;
                if (local_3c < 0x100) {
                  local_7c = (CMap *)((int)local_7c + local_3c * 4);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                iVar6 = *(int *)local_7c;
                local_7c = (CMap *)(iVar6 + 0x34);
                if (((int)pCVar21 < 0) || (*(int *)(iVar6 + 0x38) <= (int)pCVar21)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  local_48 = *(CMap **)local_7c;
                }
                else {
                  local_48 = (CMap *)(*(int *)local_7c + (int)local_40);
                }
                local_7c = (CMap *)(DAT_00772400 + 0x5c8);
                if (local_3c < 0x100) {
                  local_7c = (CMap *)((int)local_7c + local_3c * 4);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                iVar6 = *(int *)local_7c;
                local_7c = (CMap *)(iVar6 + 0x34);
                if (((int)pCVar21 < 0) || (*(int *)(iVar6 + 0x38) <= (int)pCVar21)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                pCVar7 = (CMap *)FUN_005e8440(&local_48->mapFlags9);
                in_ECX = local_4c;
                if ((char)pCVar7 == '\0') goto LAB_0046bde4;
              }
            }
          }
        }
      }
LAB_0046c0d1:
      local_30 = (CMap *)CONCAT31((int3)((uint)pCVar7 >> 8),1);
      local_29 = 1;
      local_2a = 1;
      pfVar8 = (float *)FUN_0046aec0(&local_d4);
      local_e0 = *pfVar8;
      local_dc = pfVar8[1];
      local_d8 = pfVar8[2];
      goto LAB_0046b5b7;
    }
    local_3c = *(CMap **)(in_ECX + 0xc4);
    pCVar21 = *(CMap **)(in_ECX + 200);
    local_50 = pCVar21;
    uVar23 = FUN_0046b190(&local_e0,&local_2a);
    uVar5 = (undefined4)uVar23;
    uVar16 = CONCAT31((int3)((ulonglong)uVar23 >> 0x28),local_2a);
    local_30 = (CMap *)uVar16;
    if (local_2a != 0) {
      uVar5 = FUN_005e76a0(pCVar21,*(undefined4 *)(DAT_00772400 + 100),uVar4);
      if ((char)uVar5 == '\0') {
LAB_0046bde4:
        if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
          local_48 = (CMap *)0xffffffff;
        }
        else {
          local_48 = (CMap *)**(undefined4 **)(DAT_00772400 + 0xa0c4);
        }
        local_7c = (CMap *)(DAT_00772400 + 0x5c8);
        if (local_3c < 0x100) {
          local_7c = (CMap *)((int)local_7c + local_3c * 4);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar6 = *(int *)local_7c;
        local_7c = (CMap *)(iVar6 + 0x34);
        if (((int)pCVar21 < 0) || (*(int *)(iVar6 + 0x38) <= (int)pCVar21)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_74 = *(CMap **)local_7c;
        }
        else {
          local_74 = (CMap *)(*(int *)local_7c + (int)pCVar21 * 0xe8);
        }
        local_40 = (float)((int)pCVar21 * 0xe8);
        local_7c = (CMap *)(DAT_00772400 + 0x5c8);
        if (local_3c < 0x100) {
          local_7c = (CMap *)((int)local_7c + local_3c * 4);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar6 = *(int *)local_7c;
        local_7c = (CMap *)(iVar6 + 0x34);
        if (((int)pCVar21 < 0) || (*(int *)(iVar6 + 0x38) <= (int)pCVar21)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        uVar5 = FUN_005e7000(&local_74->mapFlags9,*(undefined4 *)(in_ECX + 0xe8),local_48,
                             *(undefined4 *)(DAT_00772400 + 100));
        if ((char)uVar5 == '\0') {
          local_7c = (CMap *)(DAT_00772400 + 0x5c8);
          if (local_3c < 0x100) {
            local_7c = (CMap *)((int)local_7c + local_3c * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar6 = *(int *)local_7c;
          local_7c = (CMap *)(iVar6 + 0x34);
          if (((int)pCVar21 < 0) || (*(int *)(iVar6 + 0x38) <= (int)pCVar21)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_48 = *(CMap **)local_7c;
          }
          else {
            local_48 = (CMap *)(*(int *)local_7c + (int)local_40);
          }
          local_7c = (CMap *)(DAT_00772400 + 0x5c8);
          if (local_3c < 0x100) {
            local_7c = (CMap *)((int)local_7c + local_3c * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar6 = *(int *)local_7c;
          local_7c = (CMap *)(iVar6 + 0x34);
          if (((int)pCVar21 < 0) || (*(int *)(iVar6 + 0x38) <= (int)pCVar21)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar5 = FUN_005e7400(&local_48->mapFlags9,*(undefined4 *)(in_ECX + 0xe8));
          uVar16 = (uint)local_30 & 0xff;
          if ((char)uVar5 != '\0') {
            uVar16 = 0;
          }
        }
        else {
          uVar16 = 0;
        }
      }
      else {
        uVar16 = 0;
      }
    }
    cVar2 = (char)uVar16;
    pCVar13 = local_3c;
    if (local_29 == 0) {
      pCVar7 = (CMap *)CONCAT31((int3)((uint)uVar5 >> 8),local_29);
      if (cVar2 != '\0') goto LAB_0046c01f;
      goto LAB_0046c0d1;
    }
    if ((cVar2 == '\0') && (*(char *)(in_ECX + 0xf0) == '\0')) {
      pCVar21 = *(CMap **)(in_ECX + 0xbc);
      pCVar13 = (CMap *)*(uint *)(in_ECX + 0xb8);
    }
LAB_0046c01f:
    *(char *)(in_ECX + 0xcc) = cVar2;
    *(byte *)(in_ECX + 0xcd) = local_29;
    *(float *)(in_ECX + 0xd0) = local_e0;
    *(float *)(in_ECX + 0xd4) = local_dc;
    *(float *)(in_ECX + 0xd8) = local_d8;
    local_80 = 0;
    local_7c = (CMap *)0x0;
    local_d8 = local_d8 * 0.5 + 7.0;
    local_70 = 0.0;
    local_68 = (float)((uint)local_68 & 0xffffff00);
    local_14._0_1_ = 1;
    local_14._1_3_ = 0;
    local_24 = (CMap *)(DAT_0076a324 + 0x2934);
    if (*(char *)(in_ECX + 0xcc) == '\0') {
      if (0xff < pCVar13) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar5 = 0;
    }
    else {
      local_31 = 1;
      if (pCVar13 < 0x100) {
        uVar5 = 1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar5 = 1;
      }
    }
    FUN_00487430(&local_70,pCVar21,&local_e0,&local_e0,in_ECX + 0xdc,&local_80,uVar5);
    puVar25 = &local_70;
    FUN_0044d010(puVar25);
    FUN_0044d760(puVar25);
    local_14 = CONCAT31(local_14._1_3_,2);
    FUN_00453f00(extraout_ECX);
    iVar6 = (int)(void *)local_70;
    if ((void *)local_70 == (void *)0x0) goto LAB_00470b22;
    if (DAT_00c3c824 == 0) {
      DAT_00c3c824 = 1;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    LOCK();
    _DAT_00c3c818 = _DAT_00c3c818 + 1;
    UNLOCK();
    puVar19 = (undefined4 *)(iVar6 + -0x1c);
    iVar9 = FUN_006ba730();
    if (iVar9 == 0) {
      local_24 = *(CMap **)(iVar6 + -8);
      local_8c = (CMap *)((int)local_24 + 0x1cU + (int)puVar19);
      iVar9 = FUN_006ba730();
      if (iVar9 != 0) goto LAB_0046c21e;
      if (*(int *)(iVar6 + -0x14) != 0) {
        *(undefined4 *)(*(int *)(iVar6 + -0x14) + 4) = *(undefined4 *)(iVar6 + -0x18);
      }
      if (*(int *)(iVar6 + -0x18) != 0) {
        *(undefined4 *)(*(int *)(iVar6 + -0x18) + 8) = *(undefined4 *)(iVar6 + -0x14);
      }
      if (puVar19 == DAT_00c3c81c) {
        DAT_00c3c81c = *(undefined4 **)(iVar6 + -0x18);
      }
      _memset((void *)local_70,-0x20202021,(size_t)local_24);
      bVar20 = DAT_0077248f == '\0';
      *puVar19 = 0xdfdfdfdf;
      *(undefined4 *)(iVar6 + -4) = 0xdfdfdfdf;
      *(undefined4 *)local_8c = 0xdfdfdfdf;
      if ((((bVar20) || (DAT_00c1c788 == '\0')) || (puVar19 < DAT_00c3c7cc)) ||
         ((undefined4 *)(DAT_00c3c7d0 + (int)DAT_00c3c7cc) <= puVar19)) {
        FUN_006df631(puVar19);
      }
      else {
        FUN_006b8c20();
      }
    }
    else {
LAB_0046c21e:
      if (DAT_00c3c7d4 != (FILE *)0x0) {
        FUN_00405ab0(DAT_00c3c7d4,"Mem error at %08lx:%s\n",(void *)local_70,iVar9);
        _fflush(DAT_00c3c7d4);
      }
      if (DAT_00c3c828 != '\0') {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00c3c78c);
    goto LAB_00470b22;
  }
  if (iVar6 == 9) {
    local_29 = 1;
    puStack_20 = &stack0xfffffffc;
    FUN_0046aec0(&local_84);
    FUN_0046b190(&local_84,&local_29);
    local_40 = *(float *)(in_ECX + 0xb8);
    iVar6 = *(int *)(in_ECX + 0xbc);
    if ((local_40 == -NAN) || (iVar6 == -1)) goto LAB_00470b22;
    local_2a = *(byte *)(in_ECX + 0xf0);
    fVar14 = local_40;
    bVar3 = local_29;
    if (local_29 != 0) {
      local_70._0_4_ = (void *)0xffffffff;
      local_70._4_4_ = (CMap *)0x7fffffff;
      local_70 = NAN;
      local_8c = (CMap *)0x41500000;
      local_b0 = 1.0;
      do {
        if (local_2a == 0) {
          if ((double)CONCAT44((uint)((ulonglong)(double)((float)local_7c - (float)local_8c) >> 0x20
                                     ) & (uint)local_70._4_4_,
                               SUB84((double)((float)local_7c - (float)local_8c),0) &
                               (uint)(void *)local_70) <= local_b0) {
            local_7c = (CMap *)0x41500000;
            goto LAB_0046c3c4;
          }
        }
        else {
          local_40 = *(float *)(in_ECX + 0xc4);
          iVar6 = *(int *)(in_ECX + 200);
LAB_0046c3c4:
          bVar3 = local_29;
          if (local_29 != 0) {
            if (local_2a == 0) {
              local_24 = (CMap *)(DAT_00772400 + 0x5c8);
              if ((uint)local_40 < 0x100) {
                local_24 = (CMap *)((int)local_24 + local_40 * 4);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar9 = *(int *)local_24;
              local_24 = (CMap *)(iVar9 + 0x34);
              if ((iVar6 < 0) || (*(int *)(iVar9 + 0x38) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                local_30 = *(CMap **)local_24;
              }
              else {
                local_30 = (CMap *)(*(int *)local_24 + iVar6 * 0xe8);
              }
              local_50 = (CMap *)(iVar6 * 0xe8);
              local_24 = (CMap *)(DAT_00772400 + 0x5c8);
              if ((uint)local_40 < 0x100) {
                local_24 = (CMap *)((int)local_24 + local_40 * 4);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar9 = *(int *)local_24;
              local_24 = (CMap *)(iVar9 + 0x34);
              if ((iVar6 < 0) || (*(int *)(iVar9 + 0x38) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              cVar2 = FUN_005e8720(&local_30->mapFlags9);
              if (cVar2 != '\0') goto LAB_0046c702;
LAB_0046c4dd:
              if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
                local_50 = (CMap *)0xffffffff;
              }
              else {
                local_50 = (CMap *)**(undefined4 **)(DAT_00772400 + 0xa0c4);
              }
              local_24 = (CMap *)(DAT_00772400 + 0x5c8);
              if ((uint)local_40 < 0x100) {
                local_24 = (CMap *)((int)local_24 + local_40 * 4);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar9 = *(int *)local_24;
              local_24 = (CMap *)(iVar9 + 0x34);
              if ((iVar6 < 0) || (*(int *)(iVar9 + 0x38) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                local_30 = *(CMap **)local_24;
              }
              else {
                local_30 = (CMap *)(*(int *)local_24 + iVar6 * 0xe8);
              }
              local_58 = (float)(iVar6 * 0xe8);
              local_24 = (CMap *)(DAT_00772400 + 0x5c8);
              if ((uint)local_40 < 0x100) {
                local_24 = (CMap *)((int)local_24 + local_40 * 4);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar9 = *(int *)local_24;
              local_24 = (CMap *)(iVar9 + 0x34);
              if ((iVar6 < 0) || (*(int *)(iVar9 + 0x38) <= iVar6)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              cVar2 = FUN_005e7000(&local_30->mapFlags9,*(undefined4 *)(in_ECX + 0xe8),local_50,
                                   *(undefined4 *)(DAT_00772400 + 100));
              if (cVar2 == '\0') {
                local_24 = (CMap *)(DAT_00772400 + 0x5c8);
                if ((uint)local_40 < 0x100) {
                  local_24 = (CMap *)((int)local_24 + local_40 * 4);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                iVar9 = *(int *)local_24;
                local_24 = (CMap *)(iVar9 + 0x34);
                if ((iVar6 < 0) || (*(int *)(iVar9 + 0x38) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  local_50 = *(CMap **)local_24;
                }
                else {
                  local_50 = (CMap *)(*(int *)local_24 + (int)local_58);
                }
                local_24 = (CMap *)(DAT_00772400 + 0x5c8);
                if ((uint)local_40 < 0x100) {
                  local_24 = (CMap *)((int)local_24 + local_40 * 4);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                iVar9 = *(int *)local_24;
                local_24 = (CMap *)(iVar9 + 0x34);
                if ((iVar6 < 0) || (*(int *)(iVar9 + 0x38) <= iVar6)) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                cVar2 = FUN_005e7400(&local_50->mapFlags9,*(undefined4 *)(in_ECX + 0xe8));
                bVar3 = local_29;
                if (cVar2 == '\0') goto LAB_0046c6fa;
              }
            }
            else {
              cVar2 = FUN_005e76a0(iVar6,*(undefined4 *)(DAT_00772400 + 100));
              if (cVar2 == '\0') goto LAB_0046c4dd;
            }
            bVar3 = 0;
          }
LAB_0046c6fa:
          fVar14 = local_40;
          if (local_2a != 0) {
            if ((bVar3 == 0) && (*(char *)(in_ECX + 0xf0) == '\0')) {
              iVar6 = *(int *)(in_ECX + 0xbc);
              fVar14 = *(float *)(in_ECX + 0xb8);
            }
            break;
          }
          if (bVar3 != 0) break;
        }
LAB_0046c702:
        local_2a = 1;
        local_29 = 1;
        FUN_0046aec0(&local_d4);
        FUN_0046b190(&local_d4,&local_29);
      } while( true );
    }
    *(byte *)(in_ECX + 0xcc) = bVar3;
    *(byte *)(in_ECX + 0xcd) = local_2a;
    *(undefined4 *)(in_ECX + 0xd0) = local_84;
    *(undefined4 *)(in_ECX + 0xd4) = local_80;
    *(CMap **)(in_ECX + 0xd8) = local_7c;
    local_28 = 0;
    local_24 = (CMap *)0x0;
    local_7c = (CMap *)((float)local_7c * 0.5 + 7.0);
    local_70 = 0.0;
    local_68 = (float)((uint)local_68 & 0xffffff00);
    local_14 = 5;
    bVar20 = *(char *)(in_ECX + 0xcc) == '\0';
    if (bVar20) {
      FUN_0040b550(fVar14);
    }
    else {
      local_31 = 1;
      FUN_0040b550(fVar14);
    }
    FUN_00487430(&local_70,iVar6,&local_84,&local_84,in_ECX + 0xdc,&local_28,!bVar20);
    puVar25 = &local_70;
    FUN_0044d010(puVar25);
    FUN_0044d760(puVar25);
    local_14 = CONCAT31(local_14._1_3_,6);
    FUN_00453f00(extraout_ECX_00);
    if ((void *)local_70 != (void *)0x0) {
      FUN_006ba940();
    }
    local_14 = 7;
    goto LAB_00470b0c;
  }
  if (iVar6 == 2) {
    local_29 = 1;
    puStack_20 = &stack0xfffffffc;
    FUN_0046aec0(&local_11c);
    FUN_0046b190(&local_11c,&local_29);
    local_3c = *(CMap **)(in_ECX + 0xb8);
    iVar6 = *(int *)(in_ECX + 0xbc);
    if ((local_3c == (CMap *)0xffffffff) || (iVar6 == -1)) goto LAB_00470b22;
    local_2a = *(byte *)(in_ECX + 0xf0);
    bVar3 = local_29;
    if (local_29 != 0) {
      local_8c = (CMap *)0x3c23d70a;
      local_74 = (CMap *)0x41500000;
      local_7c = (CMap *)0xc2c80000;
      do {
        local_48 = local_7c;
        if (local_2a == 0) {
          local_24 = (CMap *)(DAT_00772400 + 0x5c8);
          if (local_3c < (CMap *)0x100) {
            local_24 = (CMap *)((int)local_24 + local_3c * 4);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar9 = *(int *)local_24;
          local_24 = (CMap *)(iVar9 + 0x34);
          if ((iVar6 < 0) || (*(int *)(iVar9 + 0x38) <= iVar6)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            fVar14 = *(float *)local_24;
          }
          else {
            fVar14 = (float)(iVar6 * 0xe8 + (int)*(float *)local_24);
          }
          local_48 = (CMap *)(*(float *)((int)fVar14 + 0x58) * (float)local_8c + local_114);
          if ((float)local_48 < (float)local_74) goto LAB_0046c98a;
          bVar3 = 0;
        }
        else {
          local_3c = *(CMap **)(in_ECX + 0xc4);
          iVar6 = *(int *)(in_ECX + 200);
LAB_0046c98a:
          cVar2 = FUN_005e76a0(iVar6,*(undefined4 *)(DAT_00772400 + 100));
          if (cVar2 == '\0') {
            if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
              local_50 = (CMap *)0xffffffff;
            }
            else {
              local_50 = (CMap *)**(undefined4 **)(DAT_00772400 + 0xa0c4);
            }
            local_24 = (CMap *)(DAT_00772400 + 0x5c8);
            if (local_3c < (CMap *)0x100) {
              local_24 = (CMap *)((int)local_24 + local_3c * 4);
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar9 = *(int *)local_24;
            local_24 = (CMap *)(iVar9 + 0x34);
            if ((iVar6 < 0) || (*(int *)(iVar9 + 0x38) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_30 = *(CMap **)local_24;
            }
            else {
              local_30 = (CMap *)(*(int *)local_24 + iVar6 * 0xe8);
            }
            local_58 = (float)(iVar6 * 0xe8);
            local_24 = (CMap *)(DAT_00772400 + 0x5c8);
            if (local_3c < (CMap *)0x100) {
              local_24 = (CMap *)((int)local_24 + local_3c * 4);
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar9 = *(int *)local_24;
            local_24 = (CMap *)(iVar9 + 0x34);
            if ((iVar6 < 0) || (*(int *)(iVar9 + 0x38) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            cVar2 = FUN_005e7000(&local_30->mapFlags9,*(undefined4 *)(in_ECX + 0xe8),local_50,
                                 *(undefined4 *)(DAT_00772400 + 100));
            if (cVar2 != '\0') goto LAB_0046cbc5;
            local_24 = (CMap *)(DAT_00772400 + 0x5c8);
            if (local_3c < (CMap *)0x100) {
              local_24 = (CMap *)((int)local_24 + local_3c * 4);
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar9 = *(int *)local_24;
            local_24 = (CMap *)(iVar9 + 0x34);
            if ((iVar6 < 0) || (*(int *)(iVar9 + 0x38) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              local_50 = *(CMap **)local_24;
            }
            else {
              local_50 = (CMap *)(*(int *)local_24 + (int)local_58);
            }
            local_24 = (CMap *)(DAT_00772400 + 0x5c8);
            if (local_3c < (CMap *)0x100) {
              local_24 = (CMap *)((int)local_24 + local_3c * 4);
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar9 = *(int *)local_24;
            local_24 = (CMap *)(iVar9 + 0x34);
            if ((iVar6 < 0) || (*(int *)(iVar9 + 0x38) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            cVar2 = FUN_005e7400(&local_50->mapFlags9,*(undefined4 *)(in_ECX + 0xe8));
            bVar3 = local_29;
            if (cVar2 != '\0') goto LAB_0046cbc5;
          }
          else {
LAB_0046cbc5:
            bVar3 = 0;
          }
          if (local_2a != 0) goto LAB_0046cbfb;
          if (bVar3 != 0) break;
        }
        if ((float)local_48 < (float)local_74) goto LAB_0046cbfb;
        local_2a = 1;
        local_29 = 1;
      } while( true );
    }
    goto LAB_0046cc1b;
  }
  if (iVar6 == 1) {
    local_2a = 1;
    puStack_20 = &stack0xfffffffc;
    FUN_0046aec0(&local_bc);
    FUN_0046b190(&local_bc,&local_2a);
    local_58 = *(float *)(in_ECX + 0xb8);
    iVar6 = *(int *)(in_ECX + 0xbc);
    if ((local_58 == -NAN) || (iVar6 == -1)) goto LAB_00470b22;
    local_44 = (float)iVar6;
    FUN_0040b550(local_58);
    iVar9 = FUN_004059a0(iVar6);
    fVar14 = local_58;
    pCStack_b8 = (CMap *)((float)pCStack_b8 - *(float *)(iVar9 + 0x54) * 0.005);
    bVar3 = local_2a;
    if (local_2a != 0) {
      cVar2 = FUN_005e76a0(iVar6,*(undefined4 *)(DAT_00772400 + 100));
      if (cVar2 == '\0') {
        local_24 = *(CMap **)(DAT_00772400 + 100);
        local_8c = (CMap *)FUN_005e3650(0);
        local_7c = *(CMap **)(in_ECX + 0xe8);
        FUN_0040b550(fVar14);
        FUN_0040b550(fVar14);
        pCVar7 = local_7c;
        pCVar21 = local_8c;
        pCVar13 = local_24;
        iVar6 = FUN_004059a0(local_44);
        iVar6 = iVar6 + 0x50;
        FUN_004059a0(local_44);
        cVar2 = FUN_005e7000(iVar6,pCVar7,pCVar21,pCVar13);
        fVar14 = local_58;
        in_ECX = local_4c;
        if (cVar2 == '\0') {
          local_24 = *(CMap **)(local_4c + 0xe8);
          FUN_0040b550(local_58);
          FUN_0040b550(fVar14);
          pCVar7 = local_24;
          iVar6 = FUN_004059a0(local_44);
          iVar6 = iVar6 + 0x50;
          FUN_004059a0(local_44);
          cVar2 = FUN_005e7400(iVar6,pCVar7);
          in_ECX = local_4c;
          bVar3 = local_2a;
          if (cVar2 == '\0') goto LAB_0046cfba;
        }
      }
      bVar3 = 0;
    }
LAB_0046cfba:
    *(byte *)(in_ECX + 0xcc) = bVar3;
    *(undefined1 *)(in_ECX + 0xcd) = 0;
    *(float *)(in_ECX + 0xd0) = local_bc;
    *(CMap **)(in_ECX + 0xd4) = pCStack_b8;
    *(CMap **)(in_ECX + 0xd8) = local_b4;
    local_28 = 0;
    local_24 = (CMap *)0x0;
    local_b4 = (CMap *)((float)local_b4 * 0.5 + 7.0);
    local_70 = 0.0;
    local_68 = (float)((uint)local_68 & 0xffffff00);
    local_14 = 0xd;
    bVar20 = *(char *)(in_ECX + 0xcc) == '\0';
    if (bVar20) {
      FUN_0040b550(local_58);
    }
    else {
      local_31 = 1;
      FUN_0040b550(local_58);
    }
    FUN_00487430(&local_70,local_44,&local_bc,&local_bc,in_ECX + 0xdc,&local_28,!bVar20);
    puVar25 = &local_70;
    FUN_0044d010(puVar25);
    FUN_0044d760(puVar25);
    local_14 = CONCAT31(local_14._1_3_,0xe);
    FUN_00453f00(extraout_ECX_02);
    if ((void *)local_70 != (void *)0x0) {
      FUN_006ba940();
    }
    local_14 = 0xf;
    goto LAB_00470b0c;
  }
  if (iVar6 == 3) {
    local_58 = *(float *)(in_ECX + 0xbc);
    local_48 = *(CMap **)(in_ECX + 0xb8);
    puStack_20 = &stack0xfffffffc;
    FUN_0055a600(&local_f8,0xf);
    local_8c = (CMap *)0x40000000;
    local_88 = (CMap *)0x3f000000;
    local_40 = 8.0;
    local_24 = (CMap *)(local_f8._4_4_ * 8.0);
    DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
    local_74 = (CMap *)0x3e000000;
    local_3c = (CMap *)0x40800000;
    local_f8 = CONCAT44((float)(int)DAT_00772dd8 * 0.125,
                        (float)(int)ROUND((float)(CMap *)local_f8 * 2.0 + 0.5) * 0.5);
    uVar4 = *(uint *)(DAT_00772400 + 100);
    cVar2 = FUN_00407eb0(&local_f8);
    if (cVar2 == '\0') {
      local_24 = (CMap *)local_f8;
      DAT_00772dd8 = (CMap *)(int)ROUND((float)(CMap *)local_f8);
      uVar16 = uVar4;
      FUN_00592f10(PTR_0077241c);
      pcVar10 = (char *)FUN_00423700(uVar16);
      if (*pcVar10 == '\0') {
        local_24 = (CMap *)local_f8;
        DAT_00772dd8 = (CMap *)(int)ROUND((float)(CMap *)local_f8);
        uVar16 = uVar4;
        FUN_00592f10(PTR_0077241c);
        pcVar10 = (char *)FUN_00423700(uVar16);
        if (*pcVar10 == '\0') {
          local_24 = (CMap *)local_f8;
          DAT_00772dd8 = (CMap *)(int)ROUND((float)(CMap *)local_f8);
          uVar16 = uVar4;
          FUN_00592f10(PTR_0077241c);
          pcVar10 = (char *)FUN_00423700(uVar16);
          if (*pcVar10 == '\0') {
            local_24 = (CMap *)local_f8;
            DAT_00772dd8 = (CMap *)(int)ROUND((float)(CMap *)local_f8);
            uVar16 = uVar4;
            FUN_00592f10(PTR_0077241c);
            pcVar10 = (char *)FUN_00423700(uVar16);
            if (*pcVar10 == '\0') goto LAB_0046da4a;
          }
        }
      }
      fVar14 = ((float)(CMap *)local_f8 - (float)local_88) * (float)local_88;
      FUN_004295a0();
      local_50 = (CMap *)(fVar14 + fVar14 + 1.5);
      local_70 = (double)CONCAT44(local_70._4_4_,local_50);
      fVar14 = local_f8._4_4_;
      FUN_004295a0();
      local_24 = (CMap *)(fVar14 + 1.5);
      local_68 = 15.0;
      local_70 = (double)CONCAT44(local_24,(void *)local_70);
      fVar14 = (((float)local_50 - 1.5) + (float)local_8c) * 0.25;
      FUN_004295a0();
      if ((*(char *)(in_ECX + 0xf0) == '\0') && ((float)local_50 == fVar14 * (float)local_3c + 1.5))
      {
        pCVar7 = (CMap *)0x3f800000;
        local_30 = (CMap *)0x0;
        local_50 = (CMap *)0x3f800000;
        pCVar21 = local_24;
        do {
          if ((float)local_3c <= (float)pCVar21) {
            local_24 = (CMap *)((float)(void *)local_70 * local_40 - (float)local_3c);
            DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
            cVar2 = FUN_004093f0(PTR_0077241c);
            if (cVar2 == '\x0f') {
              local_24 = (CMap *)((float)(void *)local_70 * local_40 - (float)local_3c);
              DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
              cVar2 = FUN_004093f0(PTR_0077241c);
              if (cVar2 == '\v') {
                local_24 = (CMap *)((float)(void *)local_70 * local_40 + (float)local_3c);
                DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
                cVar2 = FUN_004093f0(PTR_0077241c);
                if (cVar2 == '\x0f') {
                  local_24 = (CMap *)((float)(void *)local_70 * local_40 + (float)local_3c);
                  DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
                  cVar2 = FUN_004093f0(PTR_0077241c);
                  if (cVar2 == '\v') {
                    local_24 = (CMap *)(void *)local_70;
                    DAT_00772dd8 = (CMap *)(int)ROUND((float)(void *)local_70);
                    fVar14 = (float)(void *)local_70;
                    iVar6 = FUN_00592f10(PTR_0077241c);
                    local_24 = (CMap *)(iVar6 + 0x34);
                    if (uVar4 < 8) {
                      local_24 = (CMap *)((int)local_24 + uVar4);
                    }
                    else {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    if (*(char *)local_24 == '\0') {
                      local_24 = (CMap *)(void *)local_70;
                      DAT_00772dd8 = (CMap *)(int)ROUND((float)(void *)local_70);
                      fVar14 = (float)(void *)local_70;
                      iVar6 = FUN_00592f10(PTR_0077241c);
                      local_24 = (CMap *)(iVar6 + 0x34);
                      if (uVar4 < 8) {
                        local_24 = (CMap *)((int)local_24 + uVar4);
                      }
                      else {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      if (*(char *)local_24 == '\0') {
                        local_24 = (CMap *)(void *)local_70;
                        DAT_00772dd8 = (CMap *)(int)ROUND((float)(void *)local_70);
                        fVar14 = (float)(void *)local_70;
                        iVar6 = FUN_00592f10(PTR_0077241c);
                        local_24 = (CMap *)(iVar6 + 0x34);
                        if (uVar4 < 8) {
                          local_24 = (CMap *)((int)local_24 + uVar4);
                        }
                        else {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        }
                        if (*(char *)local_24 == '\0') {
                          local_24 = (CMap *)(void *)local_70;
                          DAT_00772dd8 = (CMap *)(int)ROUND((float)(void *)local_70);
                          fVar14 = (float)(void *)local_70;
                          iVar6 = FUN_00592f10(PTR_0077241c);
                          local_24 = (CMap *)(iVar6 + 0x34);
                          if (uVar4 < 8) {
                            pCVar7 = (CMap *)((int)&local_24->field_0x0 + uVar4);
                          }
                          else {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            pCVar7 = local_24;
                          }
                          if (*(char *)pCVar7 == '\0') goto LAB_0046d6fa;
                        }
                      }
                    }
                    pCVar7 = local_48;
                    if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
                      local_50 = (CMap *)0xffffffff;
                    }
                    else {
                      local_50 = (CMap *)**(undefined4 **)(DAT_00772400 + 0xa0c4);
                    }
                    local_24 = *(CMap **)(DAT_00772400 + 100);
                    local_8c = *(CMap **)(in_ECX + 0xe8);
                    FUN_0040b550(local_48);
                    FUN_0040b550(pCVar7);
                    pCVar7 = local_8c;
                    pCVar21 = local_50;
                    pCVar13 = local_24;
                    iVar6 = FUN_004059a0(local_58);
                    iVar6 = iVar6 + 0x50;
                    FUN_004059a0(local_58);
                    cVar2 = FUN_005e7000(iVar6,pCVar7,pCVar21,pCVar13);
                    pCVar7 = local_48;
                    in_ECX = local_4c;
                    if (cVar2 == '\0') {
                      local_24 = *(CMap **)(local_4c + 0xe8);
                      FUN_0040b550(local_48);
                      FUN_0040b550(pCVar7);
                      pCVar7 = local_24;
                      iVar6 = FUN_004059a0(local_58);
                      iVar6 = iVar6 + 0x50;
                      FUN_004059a0(local_58);
                      cVar2 = FUN_005e7400(iVar6,pCVar7);
                      in_ECX = local_4c;
                      if ((cVar2 == '\0') && (FUN_006096d0(), 3.0 <= fVar14)) {
                        cVar2 = '\x01';
                        local_f8 = local_70;
                        local_f0 = local_68;
                        goto LAB_0046da4c;
                      }
                    }
                    break;
                  }
                }
              }
            }
LAB_0046d6fa:
            pCVar7 = local_50;
            pCVar21 = local_70._4_4_;
          }
          if ((CMap *)0x1 < local_30) {
            if ((float)pCVar21 < (float)local_3c) break;
            local_24 = (CMap *)((float)(void *)local_70 * local_40 - (float)local_3c);
            DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
            cVar2 = FUN_004093f0(PTR_0077241c);
            if (cVar2 == '\x0f') {
              local_24 = (CMap *)((float)(void *)local_70 * local_40 + (float)local_3c);
              DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
              cVar2 = FUN_004093f0(PTR_0077241c);
              if (cVar2 == '\x0f') break;
            }
            pCVar7 = local_50;
            pCVar21 = local_70._4_4_;
          }
          pCVar21 = (CMap *)((float)pCVar21 - (float)pCVar7);
          local_30 = (CMap *)&local_30->field_0x1;
          local_70 = (double)CONCAT44(pCVar21,(void *)local_70);
        } while ((int)local_30 < 0x40);
      }
      local_58 = *(float *)(in_ECX + 200);
      local_48 = *(CMap **)(in_ECX + 0xc4);
      FUN_0046aec0(&local_128);
      local_30 = (CMap *)0x10;
      do {
        pCVar7 = PTR_0077241c;
        fVar14 = fStack_124 * local_40;
        DAT_00772dd8 = (CMap *)(int)ROUND(local_128 * local_40);
        local_24 = DAT_00772dd8;
        piVar18 = (int *)FUN_00592f10(PTR_0077241c);
        pCVar1 = pCVar7->heightBlocks;
        iVar6 = *piVar18;
        if ((iVar6 < 0) || (pCVar1->count <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar11 = pCVar1->data;
        }
        else {
          pCVar11 = pCVar1->data + iVar6;
        }
        if ((float)pCVar11->heights[((int)ROUND(fVar14) & 7U) << 3 | (uint)local_24 & 7] <=
            local_120) {
          if (local_30 != (CMap *)0x0) {
            local_30 = (CMap *)0x10;
            goto LAB_0046db60;
          }
          break;
        }
        local_30 = (CMap *)((int)&local_30[-1].mapFlags5 + 3);
        fStack_124 = fStack_124 - (float)local_74;
      } while (local_30 != (CMap *)0x0);
      goto LAB_0046da3b;
    }
    goto LAB_0046da4a;
  }
  if (iVar6 == 4) {
    local_54 = *(CMap **)(in_ECX + 0xbc);
    local_88 = *(CMap **)(in_ECX + 0xb8);
    puStack_20 = &stack0xfffffffc;
    FUN_0055a600(&local_ec,0xf);
    local_38 = (int *)0x3f000000;
    local_24 = (CMap *)((float)(int)ROUND((float)(CMap *)local_ec * 2.0 + 0.5) * 0.5);
    local_44 = 8.0;
    pCVar7 = (CMap *)(local_ec._4_4_ * 8.0);
    DAT_00772dd8 = (CMap *)(int)ROUND((float)pCVar7);
    local_98 = 0.125;
    fVar14 = (float)(int)DAT_00772dd8 * 0.125;
    local_ec = CONCAT44(fVar14,local_24);
    uVar4 = *(uint *)(DAT_00772400 + 100);
    if (((PTR_0077241c->x0f + 4.0 <= (float)local_24) && ((float)local_24 < PTR_0077241c->x1f - 4.0)
        ) && ((PTR_0077241c->y0f + 4.0 <= fVar14 && (fVar14 < PTR_0077241c->y1f - 4.0)))) {
      DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
      uVar16 = uVar4;
      FUN_00592f10(PTR_0077241c);
      pcVar10 = (char *)FUN_00423700(uVar16);
      if (*pcVar10 == '\0') {
        local_24 = (CMap *)local_ec;
        DAT_00772dd8 = (CMap *)(int)ROUND((float)(CMap *)local_ec);
        uVar16 = uVar4;
        FUN_00592f10(PTR_0077241c);
        pcVar10 = (char *)FUN_00423700(uVar16);
        if (*pcVar10 == '\0') {
          local_24 = (CMap *)local_ec;
          DAT_00772dd8 = (CMap *)(int)ROUND((float)(CMap *)local_ec);
          uVar16 = uVar4;
          FUN_00592f10(PTR_0077241c);
          pcVar10 = (char *)FUN_00423700(uVar16);
          if (*pcVar10 == '\0') {
            local_24 = (CMap *)local_ec;
            DAT_00772dd8 = (CMap *)(int)ROUND((float)(CMap *)local_ec);
            uVar16 = uVar4;
            FUN_00592f10(PTR_0077241c);
            pcVar10 = (char *)FUN_00423700(uVar16);
            pCVar7 = local_24;
            if (*pcVar10 == '\0') goto LAB_0046e930;
          }
        }
      }
      fVar14 = ((float)(CMap *)local_ec - (float)local_38) * (float)local_38;
      FUN_004295a0();
      local_d4 = fVar14 + fVar14 + 1.5;
      fVar14 = local_ec._4_4_;
      local_40 = local_d4;
      FUN_004295a0();
      pCStack_d0 = (CMap *)(fVar14 - 1.5);
      local_cc = (CMap *)0x41300000;
      fVar14 = ((local_40 - 1.5) + 2.0) * 0.25;
      local_3c = pCStack_d0;
      FUN_004295a0();
      if ((*(char *)(in_ECX + 0xf0) == '\0') && (local_40 == fVar14 * 4.0 + 1.5)) {
        local_58 = 0.0;
        do {
          local_74 = local_3c;
          local_50 = local_3c;
          local_48 = local_3c;
          if ((float)local_3c < (float)(PTR_0077241c->cellY1 + -4)) {
            local_30 = (CMap *)(local_40 * local_44);
            local_8c = (CMap *)((float)local_30 - 4.0);
            DAT_00772dd8 = (CMap *)(int)ROUND((float)local_8c);
            local_24 = local_8c;
            cVar2 = FUN_004093f0(PTR_0077241c);
            if (cVar2 == '\v') {
              local_24 = local_8c;
              DAT_00772dd8 = (CMap *)(int)ROUND((float)local_8c);
              bVar3 = FUN_004093f0(PTR_0077241c);
              if (0xc < bVar3) {
                local_30 = (CMap *)((float)local_30 + 4.0);
                DAT_00772dd8 = (CMap *)(int)ROUND((float)local_30);
                local_24 = local_30;
                cVar2 = FUN_004093f0(PTR_0077241c);
                if (cVar2 == '\v') {
                  local_24 = local_30;
                  DAT_00772dd8 = (CMap *)(int)ROUND((float)local_30);
                  bVar3 = FUN_004093f0(PTR_0077241c);
                  if (0xc < bVar3) {
                    local_24 = (CMap *)local_40;
                    DAT_00772dd8 = (CMap *)(int)ROUND(local_40);
                    iVar6 = FUN_00592f10(PTR_0077241c);
                    local_24 = (CMap *)(iVar6 + 0x34);
                    if (uVar4 < 8) {
                      pCVar7 = (CMap *)((int)&local_24->field_0x0 + uVar4);
                    }
                    else {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      pCVar7 = local_24;
                    }
                    if (*(char *)pCVar7 == '\0') {
                      local_24 = (CMap *)local_40;
                      DAT_00772dd8 = (CMap *)(int)ROUND(local_40);
                      iVar6 = FUN_00592f10(PTR_0077241c);
                      local_24 = (CMap *)(iVar6 + 0x34);
                      if (uVar4 < 8) {
                        pCVar7 = (CMap *)((int)&local_24->field_0x0 + uVar4);
                      }
                      else {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        pCVar7 = local_24;
                      }
                      if (*(char *)pCVar7 == '\0') {
                        local_24 = (CMap *)local_40;
                        DAT_00772dd8 = (CMap *)(int)ROUND(local_40);
                        iVar6 = FUN_00592f10(PTR_0077241c);
                        local_24 = (CMap *)(iVar6 + 0x34);
                        if (uVar4 < 8) {
                          pCVar7 = (CMap *)((int)&local_24->field_0x0 + uVar4);
                        }
                        else {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          pCVar7 = local_24;
                        }
                        if (*(char *)pCVar7 == '\0') {
                          local_24 = (CMap *)local_40;
                          DAT_00772dd8 = (CMap *)(int)ROUND(local_40);
                          iVar6 = FUN_00592f10(PTR_0077241c);
                          local_24 = (CMap *)(iVar6 + 0x34);
                          if (uVar4 < 8) {
                            pCVar7 = (CMap *)((int)&local_24->field_0x0 + uVar4);
                          }
                          else {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            pCVar7 = local_24;
                          }
                          if (*(char *)pCVar7 == '\0') goto LAB_0046e598;
                        }
                      }
                    }
                    if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
                      local_50 = (CMap *)0xffffffff;
                    }
                    else {
                      puVar19 = (undefined4 *)FUN_0040b900(0);
                      local_50 = (CMap *)*puVar19;
                    }
                    pCVar7 = local_88;
                    local_24 = *(CMap **)(DAT_00772400 + 100);
                    local_8c = *(CMap **)(in_ECX + 0xe8);
                    FUN_0040b550(local_88);
                    FUN_0040b550(pCVar7);
                    pCVar7 = local_8c;
                    pCVar21 = local_50;
                    pCVar13 = local_24;
                    iVar6 = FUN_004059a0(local_54);
                    iVar6 = iVar6 + 0x50;
                    FUN_004059a0(local_54);
                    cVar2 = FUN_005e7000(iVar6,pCVar7,pCVar21,pCVar13);
                    pCVar7 = local_88;
                    in_ECX = local_4c;
                    if (cVar2 == '\0') {
                      local_24 = *(CMap **)(local_4c + 0xe8);
                      FUN_0040b550(local_88);
                      FUN_0040b550(pCVar7);
                      pCVar7 = local_24;
                      iVar6 = FUN_004059a0(local_54);
                      iVar6 = iVar6 + 0x50;
                      FUN_004059a0(local_54);
                      cVar2 = FUN_005e7400(iVar6,pCVar7);
                      in_ECX = local_4c;
                      if (cVar2 == '\0') {
                        FUN_0060b1b0();
                        iVar6 = FUN_0060b560();
                        if (iVar6 != 0) {
                          cVar2 = '\x01';
                          local_ec = CONCAT44(local_3c,local_40);
                          local_e4 = 11.0;
                          goto LAB_0046e932;
                        }
                      }
                    }
                    break;
                  }
                }
              }
            }
          }
LAB_0046e598:
          if (1 < (uint)local_58) {
            if ((float)(PTR_0077241c->cellY1 + -4) <= (float)local_3c) break;
            local_8c = (CMap *)((float)local_3c * local_44);
            local_7c = (CMap *)(local_40 * local_44);
            local_24 = (CMap *)((float)local_7c - 4.0);
            DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
            cVar2 = FUN_004093f0(PTR_0077241c);
            if (cVar2 == '\x0f') {
              local_24 = (CMap *)((float)local_7c + 4.0);
              DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
              cVar2 = FUN_004093f0(PTR_0077241c);
              if (cVar2 == '\x0f') break;
            }
          }
          pCStack_d0 = (CMap *)((float)local_3c + 1.0);
          local_58 = (float)((int)local_58 + 1);
          local_74 = pCStack_d0;
          local_50 = pCStack_d0;
          local_3c = pCStack_d0;
        } while ((int)local_58 < 0x40);
      }
      local_54 = *(CMap **)(in_ECX + 200);
      local_48 = *(CMap **)(in_ECX + 0xc4);
      FUN_0046aec0(&local_134);
      local_30 = (CMap *)0x10;
      do {
        pCVar7 = PTR_0077241c;
        fVar14 = fStack_130 * local_44;
        DAT_00772dd8 = (CMap *)(int)ROUND(local_134 * local_44);
        local_24 = DAT_00772dd8;
        piVar18 = (int *)FUN_00592f10(PTR_0077241c);
        pCVar1 = pCVar7->heightBlocks;
        iVar6 = *piVar18;
        if ((iVar6 < 0) || (pCVar1->count <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar11 = pCVar1->data;
        }
        else {
          pCVar11 = pCVar1->data + iVar6;
        }
        if ((float)pCVar11->heights[((int)ROUND(fVar14) & 7U) << 3 | (uint)local_24 & 7] <=
            local_12c) {
          if (local_30 != (CMap *)0x0) {
            local_30 = (CMap *)0x10;
            goto LAB_0046e9f0;
          }
          break;
        }
        local_30 = (CMap *)((int)&local_30[-1].mapFlags5 + 3);
        fStack_130 = fStack_130 - local_98;
      } while (local_30 != (CMap *)0x0);
      goto LAB_0046e921;
    }
    goto LAB_0046e930;
  }
  if (iVar6 != 5) {
    if (iVar6 != 6) {
      if (iVar6 != 7) goto LAB_00470b22;
      FUN_0046aec0(&local_b0);
      pCVar7 = PTR_0077241c;
      iVar6 = DAT_00772400;
      *(undefined4 *)(in_ECX + 0xec) = 0xffffffff;
      local_30 = *(CMap **)(iVar6 + 100);
      fVar14 = (float)local_b0;
      if (((float)local_b0 < pCVar7->x0f + 4.0) || (pCVar7->x1f - 4.0 <= (float)local_b0)) {
LAB_00470189:
      }
      else if ((pCVar7->y0f + 4.0 <= local_b0._4_4_) && (local_b0._4_4_ < pCVar7->y1f - 4.0)) {
        iVar6 = FUN_00592f10(pCVar7);
        pcVar10 = (char *)(iVar6 + 0x34);
        if ((CMap *)&DAT_00000007 < local_30) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        else {
          pcVar10 = pcVar10 + (int)local_30;
        }
        if (*pcVar10 == '\0') {
          pCVar7 = local_30;
          FUN_00592f10(PTR_0077241c);
          pcVar10 = (char *)FUN_00423700(pCVar7);
          pCVar7 = local_30;
          if (*pcVar10 == '\0') {
            pCVar21 = local_30;
            FUN_00592f10(PTR_0077241c);
            pcVar10 = (char *)FUN_00423700(pCVar21);
            if (*pcVar10 == '\0') {
              FUN_00592f10(PTR_0077241c);
              pcVar10 = (char *)FUN_00423700(pCVar7);
              if (*pcVar10 == '\0') {
                fVar14 = (float)local_b0;
                goto LAB_00470189;
              }
            }
          }
        }
        local_b4 = (CMap *)0x0;
        pCStack_b8 = (CMap *)0x0;
        local_cc = (CMap *)0x0;
        pCStack_d0 = (CMap *)0x0;
        local_d4 = 0.0;
        local_50 = (CMap *)0xc47a0000;
        FUN_005ddd60();
        local_14 = 0x20;
        piVar18 = (int *)FUN_00407340(*(undefined4 *)(in_ECX + 0xe8));
        local_1c4 = (float)local_b0 - 10.0;
        local_1b8 = (float)local_b0 + 10.0;
        local_1c0 = local_b0._4_4_ - 10.0;
        local_1e4 = 2;
        local_1bc = (float)pCStack_a8 - 10.0;
        local_1b4 = local_b0._4_4_ + 10.0;
        local_1b0 = (float)pCStack_a8 + 10.0;
        local_210 = 0x42c80000;
        local_200 = *(undefined4 *)(*(int *)(*(int *)(*piVar18 + 0xd4) + 0xce4) + 8);
        piVar18 = (int *)FUN_00407340(*(undefined4 *)(in_ECX + 0xe8));
        local_98 = *(float *)(*(int *)(*piVar18 + 0xd4) + 0xce8);
        local_98 = local_98 * local_98;
        cVar2 = FUN_005de450(&local_48);
        if (cVar2 == '\0') {
LAB_0047076e:
          local_54 = *(CMap **)(in_ECX + 0xbc);
          local_48 = *(CMap **)(in_ECX + 0xb8);
          FUN_0046aec0(&local_c8);
          local_30 = (CMap *)0x10;
          do {
            pCVar7 = PTR_0077241c;
            fVar14 = fStack_c4 * 8.0;
            DAT_00772dd8 = (CMap *)(int)ROUND(local_c8 * 8.0);
            local_24 = DAT_00772dd8;
            piVar18 = (int *)FUN_00592f10(PTR_0077241c);
            pCVar1 = pCVar7->heightBlocks;
            iVar6 = *piVar18;
            if ((iVar6 < 0) || (pCVar1->count <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar11 = pCVar1->data;
            }
            else {
              pCVar11 = pCVar1->data + iVar6;
            }
            if ((float)pCVar11->heights[((int)ROUND(fVar14) & 7U) << 3 | (uint)local_24 & 7] <=
                (float)local_c0) {
              if (local_30 != (CMap *)0x0) {
                iVar6 = 0x10;
                goto LAB_004708d0;
              }
              break;
            }
            local_30 = (CMap *)((int)&local_30[-1].mapFlags5 + 3);
            fStack_c4 = fStack_c4 - 0.125;
          } while (local_30 != (CMap *)0x0);
          goto LAB_00470873;
        }
        local_88 = local_b4;
        local_74 = pCStack_b8;
        do {
          uVar4 = local_48[4].originX8;
          local_24 = (CMap *)local_48[4].originY8;
          if ((uVar4 != 0xffffffff) && (local_24 != (CMap *)0xffffffff)) {
            if (0xff < uVar4) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar6 = FUN_004059a0(local_24);
            local_38 = *(int **)(iVar6 + 0x5c);
            local_24 = (CMap *)(DAT_00772400 + 0x5c8);
            if (0xff < uVar4) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            FUN_00408920(local_38);
            pfVar8 = (float *)FUN_00408a10();
            local_8c = (CMap *)(pfVar8[1] * 0.005);
            local_30 = (CMap *)(*pfVar8 * 0.005);
            local_7c = (CMap *)(pfVar8[2] * 0.005);
            local_24 = (CMap *)(DAT_00772400 + 0x5c8);
            if (0xff < uVar4) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar6 = FUN_00408920(local_38);
            local_bc = *(float *)(iVar6 + 8);
            pCStack_b8 = *(CMap **)(iVar6 + 0xc);
            local_b4 = *(CMap **)(iVar6 + 0x10);
            _memset(&local_1a0,0,0x40);
            pCVar7 = local_48;
            piVar18 = &local_48->mapArea8;
            FUN_0047ec30(piVar18);
            local_24 = (CMap *)((float)local_8c * local_190 + local_1a0 * (float)local_30 +
                                (float)local_7c * local_180 + local_170 + (float)pCVar7->mapFlags2);
            fVar14 = (float)local_30 * local_198 + (float)local_8c * local_188 +
                     (float)local_7c * local_178 + local_168;
            local_8c = (CMap *)((float)pCVar7->mapFlags3 +
                               (float)local_30 * local_19c + (float)local_8c * local_18c +
                               (float)local_7c * local_17c + local_16c);
            local_30 = (CMap *)(fVar14 + fVar14 + (float)pCVar7->cells);
            pfVar8 = (float *)FUN_005e6060(piVar18);
            local_bc = *pfVar8;
            pCStack_b8 = (CMap *)pfVar8[1];
            local_b4 = (CMap *)pfVar8[2];
            fVar14 = ((float)local_30 - (float)pCStack_a8) * 0.5;
            fVar14 = ((float)local_8c - local_b0._4_4_) * ((float)local_8c - local_b0._4_4_) +
                     ((float)local_24 - (float)local_b0) * ((float)local_24 - (float)local_b0) +
                     fVar14 * fVar14;
            in_ECX = local_4c;
            if (fVar14 < local_98) {
              *(CMapCell **)(local_4c + 0xec) = pCVar7[1].cells;
              local_50 = local_24;
              local_74 = local_8c;
              local_88 = local_30;
              local_d4 = local_bc;
              pCStack_d0 = pCStack_b8;
              local_cc = local_b4;
              local_98 = fVar14;
            }
          }
          cVar2 = FUN_005de450(&local_48);
        } while (cVar2 != '\0');
        if ((float)local_50 == -1000.0) goto LAB_0047076e;
        local_2a = 1;
        local_b0 = (double)CONCAT44(local_74,local_50);
        local_29 = 0;
        pCStack_a8 = local_88;
        *(float *)local_78 = local_d4;
        local_78->mapFlags0 = (int)pCStack_d0;
        local_78->mapFlags1 = (int)local_cc;
        goto LAB_00470887;
      }
      bVar3 = 0;
      fVar22 = local_b0._4_4_;
      bVar12 = 0;
      goto LAB_00470195;
    }
    local_58 = *(float *)(in_ECX + 0xbc);
    local_98 = *(float *)(in_ECX + 0xb8);
    puStack_20 = &stack0xfffffffc;
    FUN_0055a600(&local_104,0xf);
    local_88 = (CMap *)0x3f000000;
    local_44 = (float)(int)ROUND((float)local_104 * 2.0 + 0.5) * 0.5;
    local_50 = (CMap *)0x41000000;
    local_24 = (CMap *)((float)local_104._4_4_ * 8.0);
    DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
    local_74 = (CMap *)0x3e000000;
    fVar14 = (float)(int)DAT_00772dd8 * 0.125;
    local_104 = CONCAT44(fVar14,local_44);
    local_30 = *(CMap **)(DAT_00772400 + 100);
    if (((local_44 < PTR_0077241c->x0f + 4.0) || (PTR_0077241c->x1f - 4.0 <= local_44)) ||
       ((fVar14 < PTR_0077241c->y0f + 4.0 || (PTR_0077241c->y1f - 4.0 <= fVar14))))
    goto LAB_0046fea9;
    iVar6 = FUN_00592f10(PTR_0077241c);
    pcVar10 = (char *)(iVar6 + 0x34);
    if ((CMap *)&DAT_00000007 < local_30) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    else {
      pcVar10 = pcVar10 + (int)local_30;
    }
    if (*pcVar10 == '\0') {
      pCVar7 = local_30;
      FUN_00592f10(PTR_0077241c);
      pcVar10 = (char *)FUN_00423700(pCVar7);
      pCVar7 = local_30;
      if (*pcVar10 == '\0') {
        pCVar21 = local_30;
        FUN_00592f10(PTR_0077241c);
        pcVar10 = (char *)FUN_00423700(pCVar21);
        if (*pcVar10 == '\0') {
          FUN_00592f10(PTR_0077241c);
          pcVar10 = (char *)FUN_00423700(pCVar7);
          if (*pcVar10 == '\0') {
            local_44 = (float)local_104;
            goto LAB_0046fea9;
          }
        }
      }
    }
    local_29 = 1;
    fVar14 = (float)local_104;
    FUN_004295a0();
    local_bc = fVar14 + (float)local_88;
    local_b4 = (CMap *)0x4161999a;
    pCStack_b8 = local_104._4_4_;
    pfVar8 = (float *)FUN_00424120();
    local_d4 = *pfVar8;
    pCStack_d0 = (CMap *)pfVar8[1];
    if (pfVar8[2] != 14.1) {
      local_29 = 0;
    }
    local_cc = (CMap *)0x41700000;
    local_78 = pCStack_d0;
    local_44 = local_d4;
    if (local_29 != 0) {
      iVar6 = (int)(float)pCStack_d0;
      local_54 = (CMap *)(int)local_d4;
      cVar2 = FUN_0047eca0(local_54,iVar6 + 1,4);
      if (((cVar2 == '\0') && (iVar9 = FUN_00592f10(this), (*(byte *)(iVar9 + 0x18) & 3) != 0)) &&
         (iVar9 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar9 + 0x18) & 3) != 3)) {
        local_38 = (int *)(iVar6 + 2);
        iVar6 = FUN_00592f10(PTR_0077241c);
        if (((*(byte *)(iVar6 + 0x18) & 3) != 0) &&
           (iVar6 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar6 + 0x18) & 3) != 3)) {
          local_24 = (CMap *)&local_54->field_0x1;
          iVar6 = FUN_00592f10(PTR_0077241c);
          if (((*(byte *)(iVar6 + 0x18) & 3) != 0) &&
             (((iVar6 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar6 + 0x18) & 3) != 3 &&
               (iVar6 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar6 + 0x18) & 3) != 0)) &&
              (iVar6 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar6 + 0x18) & 3) != 3))))
          goto LAB_0046fa17;
        }
      }
      local_29 = 0;
    }
LAB_0046fa17:
    FUN_0046aec0(&local_bc);
    pCVar7 = (CMap *)(uint)local_29;
    if ((float)local_b4 < 13.0) {
      pCVar7 = (CMap *)0x0;
    }
    local_7c = (CMap *)0x0;
    if (*(char *)(in_ECX + 0xf0) == '\0') {
      local_7c = pCVar7;
    }
    if ((char)local_7c == '\0') {
LAB_0046fb9a:
      iVar6 = local_4c;
      local_54 = *(CMap **)(local_4c + 200);
      local_48 = *(CMap **)(local_4c + 0xc4);
      FUN_0046aec0(&local_c8);
      local_30 = (CMap *)0x10;
      do {
        pCVar7 = PTR_0077241c;
        local_8c = (CMap *)(int)ROUND(fStack_c4 * (float)local_50);
        DAT_00772dd8 = (CMap *)(int)ROUND(local_c8 * (float)local_50);
        local_24 = DAT_00772dd8;
        piVar18 = (int *)FUN_00592f10(PTR_0077241c);
        pCVar1 = pCVar7->heightBlocks;
        iVar9 = *piVar18;
        if ((iVar9 < 0) || (pCVar1->count <= iVar9)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar11 = pCVar1->data;
        }
        else {
          pCVar11 = pCVar1->data + iVar9;
        }
        if ((float)pCVar11->heights[((uint)local_8c & 7) << 3 | (uint)local_24 & 7] <=
            (float)local_c0) {
          if (local_30 != (CMap *)0x0) {
            iVar9 = 0x10;
            goto LAB_0046fcd0;
          }
          break;
        }
        local_30 = (CMap *)((int)&local_30[-1].mapFlags5 + 3);
        fStack_c4 = fStack_c4 - (float)local_74;
      } while (local_30 != (CMap *)0x0);
      goto LAB_0046fc9a;
    }
    if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
      local_38 = (int *)0xffffffff;
    }
    else {
      pfVar8 = (float *)FUN_0040b900(0);
      local_38 = (int *)*pfVar8;
    }
    fVar14 = local_98;
    local_24 = *(CMap **)(DAT_00772400 + 100);
    local_8c = *(CMap **)(in_ECX + 0xe8);
    FUN_0040b550(local_98);
    FUN_0040b550(fVar14);
    pCVar7 = local_8c;
    piVar18 = local_38;
    pCVar21 = local_24;
    iVar6 = FUN_004059a0(local_58);
    iVar6 = iVar6 + 0x50;
    FUN_004059a0(local_58);
    cVar2 = FUN_005e7000(iVar6,pCVar7,piVar18,pCVar21);
    fVar14 = local_98;
    if (cVar2 != '\0') goto LAB_0046fb9a;
    local_24 = *(CMap **)(local_4c + 0xe8);
    FUN_0040b550(local_98);
    FUN_0040b550(fVar14);
    pCVar7 = local_24;
    iVar6 = FUN_004059a0(local_58);
    iVar6 = iVar6 + 0x50;
    FUN_004059a0(local_58);
    cVar2 = FUN_005e7400(iVar6,pCVar7);
    if ((cVar2 != '\0') || ((char)local_7c == '\0')) goto LAB_0046fb9a;
    cVar15 = '\x01';
    local_104 = CONCAT44(local_78,local_44);
    local_fc = (CMap *)0x41700000;
    in_ECX = local_4c;
    local_c8 = local_44;
    goto LAB_0046feab;
  }
  local_54 = *(CMap **)(in_ECX + 0xbc);
  local_98 = *(float *)(in_ECX + 0xb8);
  puStack_20 = &stack0xfffffffc;
  FUN_0055a600(&local_110,0xf);
  local_74 = (CMap *)0x3f000000;
  local_24 = (CMap *)((float)(int)ROUND((float)(CMap *)local_110 * 2.0 + 0.5) * 0.5);
  local_50 = (CMap *)0x41000000;
  pCVar7 = (CMap *)(local_110._4_4_ * 8.0);
  DAT_00772dd8 = (CMap *)(int)ROUND((float)pCVar7);
  local_88 = (CMap *)0x3e000000;
  fVar14 = (float)(int)DAT_00772dd8 * 0.125;
  local_110 = CONCAT44(fVar14,local_24);
  local_30 = *(CMap **)(DAT_00772400 + 100);
  iVar6 = in_ECX;
  if ((((float)local_24 < PTR_0077241c->x0f + 4.0) ||
      (iVar6 = in_ECX, PTR_0077241c->x1f - 4.0 <= (float)local_24)) ||
     ((iVar6 = in_ECX, fVar14 < PTR_0077241c->y0f + 4.0 ||
      (iVar6 = in_ECX, PTR_0077241c->y1f - 4.0 <= fVar14)))) goto LAB_0046f30d;
  DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
  iVar6 = FUN_00592f10(PTR_0077241c);
  pcVar10 = (char *)(iVar6 + 0x34);
  if ((CMap *)&DAT_00000007 < local_30) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  else {
    pcVar10 = pcVar10 + (int)local_30;
  }
  if (*pcVar10 == '\0') {
    local_24 = (CMap *)local_110;
    DAT_00772dd8 = (CMap *)(int)ROUND((float)(CMap *)local_110);
    pCVar7 = local_30;
    FUN_00592f10(PTR_0077241c);
    pcVar10 = (char *)FUN_00423700(pCVar7);
    pCVar7 = local_30;
    if (*pcVar10 == '\0') {
      local_24 = (CMap *)local_110;
      DAT_00772dd8 = (CMap *)(int)ROUND((float)(CMap *)local_110);
      pCVar21 = local_30;
      FUN_00592f10(PTR_0077241c);
      pcVar10 = (char *)FUN_00423700(pCVar21);
      if (*pcVar10 == '\0') {
        local_24 = (CMap *)local_110;
        DAT_00772dd8 = (CMap *)(int)ROUND((float)(CMap *)local_110);
        FUN_00592f10(PTR_0077241c);
        pcVar10 = (char *)FUN_00423700(pCVar7);
        iVar6 = in_ECX;
        pCVar7 = local_24;
        if (*pcVar10 == '\0') goto LAB_0046f30d;
      }
    }
  }
  fVar14 = (float)(CMap *)local_110 + (float)local_74;
  FUN_004295a0();
  fVar22 = (local_110._4_4_ - (float)local_74) * (float)local_74;
  local_d4 = fVar14;
  FUN_004295a0();
  local_cc = (CMap *)0x41700000;
  local_2a = 1;
  pCStack_d0 = (CMap *)(fVar22 + fVar22 + 2.5);
  FUN_0046aec0(&local_bc);
  pCVar7 = (CMap *)(uint)local_2a;
  if ((float)local_b4 < 13.0) {
    pCVar7 = (CMap *)0x0;
  }
  local_7c = (CMap *)0x0;
  if (*(char *)(in_ECX + 0xf0) == '\0') {
    local_7c = pCVar7;
  }
  if ((char)local_7c == '\0') {
LAB_0046f1fb:
    iVar6 = local_4c;
    local_54 = *(CMap **)(local_4c + 200);
    local_48 = *(CMap **)(local_4c + 0xc4);
    FUN_0046aec0(&local_140);
    local_30 = (CMap *)0x10;
    do {
      pCVar7 = PTR_0077241c;
      local_8c = (CMap *)(int)ROUND(fStack_13c * (float)local_50);
      DAT_00772dd8 = (CMap *)(int)ROUND(local_140 * (float)local_50);
      local_24 = DAT_00772dd8;
      piVar18 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar1 = pCVar7->heightBlocks;
      iVar9 = *piVar18;
      if ((iVar9 < 0) || (pCVar1->count <= iVar9)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar11 = pCVar1->data;
      }
      else {
        pCVar11 = pCVar1->data + iVar9;
      }
      if ((float)pCVar11->heights[((uint)local_8c & 7) << 3 | (uint)local_24 & 7] <=
          (float)local_138) {
        if (local_30 != (CMap *)0x0) {
          iVar9 = 0x10;
          goto LAB_0046f390;
        }
        break;
      }
      local_30 = (CMap *)((int)&local_30[-1].mapFlags5 + 3);
      fStack_13c = fStack_13c - (float)local_88;
    } while (local_30 != (CMap *)0x0);
    goto LAB_0046f2fe;
  }
  if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
    local_38 = (int *)0xffffffff;
  }
  else {
    pfVar8 = (float *)FUN_0040b900(0);
    local_38 = (int *)*pfVar8;
  }
  fVar14 = local_98;
  local_24 = *(CMap **)(DAT_00772400 + 100);
  local_8c = *(CMap **)(in_ECX + 0xe8);
  FUN_0040b550(local_98);
  FUN_0040b550(fVar14);
  pCVar7 = local_8c;
  piVar18 = local_38;
  pCVar21 = local_24;
  iVar6 = FUN_004059a0(local_54);
  iVar6 = iVar6 + 0x50;
  FUN_004059a0(local_54);
  cVar2 = FUN_005e7000(iVar6,pCVar7,piVar18,pCVar21);
  fVar14 = local_98;
  if (cVar2 != '\0') goto LAB_0046f1fb;
  local_24 = *(CMap **)(local_4c + 0xe8);
  FUN_0040b550(local_98);
  FUN_0040b550(fVar14);
  pCVar7 = local_24;
  iVar6 = FUN_004059a0(local_54);
  iVar6 = iVar6 + 0x50;
  FUN_004059a0(local_54);
  cVar2 = FUN_005e7400(iVar6,pCVar7);
  if (((cVar2 != '\0') || (cVar2 = FUN_0060c590(), cVar2 == '\0')) || ((char)local_7c == '\0'))
  goto LAB_0046f1fb;
  local_110 = CONCAT44(pCStack_d0,local_d4);
  cVar15 = '\x01';
  local_108 = local_cc;
  goto LAB_0046f30f;
LAB_0046cbfb:
  if ((bVar3 == 0) && (*(char *)(in_ECX + 0xf0) == '\0')) {
    local_3c = *(CMap **)(in_ECX + 0xb8);
    iVar6 = *(int *)(in_ECX + 0xbc);
  }
LAB_0046cc1b:
  *(byte *)(in_ECX + 0xcc) = bVar3;
  *(byte *)(in_ECX + 0xcd) = local_2a;
  *(undefined4 *)(in_ECX + 0xd0) = local_11c;
  *(undefined4 *)(in_ECX + 0xd4) = local_118;
  *(float *)(in_ECX + 0xd8) = local_114;
  local_90 = 0;
  local_8c = (CMap *)0x0;
  local_114 = local_114 * 0.5 + 7.0;
  local_70 = 0.0;
  local_68 = (float)((uint)local_68 & 0xffffff00);
  local_14 = 9;
  if (*(char *)(in_ECX + 0xcc) == '\0') {
    FUN_0040b550(local_3c);
    uVar5 = 0;
  }
  else {
    local_31 = 1;
    if ((local_2a == 0) && (*(int *)(in_ECX + 0xe8) != -1)) {
      piVar18 = (int *)FUN_00407340(*(int *)(in_ECX + 0xe8));
      if ((*piVar18 != 0) &&
         (((iVar9 = *(int *)(*piVar18 + 0x3e0), iVar9 != 0 && (*(float *)(iVar9 + 0x130) != 0.0)) &&
          (iVar9 = *(int *)(iVar9 + 300), iVar9 != 0)))) {
        uVar24 = 0;
        uVar5 = *(undefined4 *)(DAT_00772400 + 100);
        fVar14 = local_114;
        FUN_005b9330(local_11c,local_118,local_114,uVar5,iVar9,0);
        cVar2 = FUN_005b93d0(local_11c,local_118,fVar14,uVar5,iVar9,uVar24);
        if (cVar2 == '\0') {
          FUN_0040b550(local_3c);
          uVar5 = 3;
          goto LAB_0046cd9a;
        }
      }
    }
    FUN_0040b550(local_3c);
    uVar5 = 1;
  }
LAB_0046cd9a:
  FUN_00487430(&local_70,iVar6,&local_11c,&local_11c,in_ECX + 0xdc,&local_90,uVar5);
  puVar25 = &local_70;
  FUN_0044d010(puVar25);
  FUN_0044d760(puVar25);
  local_14 = CONCAT31(local_14._1_3_,10);
  FUN_00453f00(extraout_ECX_01);
  if ((void *)local_70 != (void *)0x0) {
    FUN_006ba940();
  }
  local_14 = 0xb;
  FUN_0047e280(0);
  iVar6 = local_90;
  goto LAB_00470b19;
  while( true ) {
    local_30 = (CMap *)((int)&local_30[-1].mapFlags5 + 3);
    fStack_124 = fStack_124 + (float)local_74;
    if (local_30 == (CMap *)0x0) break;
LAB_0046db60:
    pCVar7 = PTR_0077241c;
    fVar14 = fStack_124 * local_40;
    DAT_00772dd8 = (CMap *)(int)ROUND(local_128 * local_40);
    local_24 = DAT_00772dd8;
    piVar18 = (int *)FUN_00592f10(PTR_0077241c);
    pCVar1 = pCVar7->heightBlocks;
    iVar6 = *piVar18;
    if ((iVar6 < 0) || (pCVar1->count <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar11 = pCVar1->data;
    }
    else {
      pCVar11 = pCVar1->data + iVar6;
    }
    if (local_120 < (float)pCVar11->heights[((int)ROUND(fVar14) & 7U) << 3 | (uint)local_24 & 7]) {
      if (local_30 != (CMap *)0x0) {
        local_24 = *(CMap **)(DAT_00772400 + 100);
        local_8c = (CMap *)FUN_005e3650(0);
        pCVar7 = local_48;
        local_7c = *(CMap **)(local_4c + 0xe8);
        FUN_0040b550(local_48);
        FUN_0040b550(pCVar7);
        pCVar7 = local_7c;
        pCVar21 = local_8c;
        pCVar13 = local_24;
        iVar6 = FUN_004059a0(local_58);
        iVar6 = iVar6 + 0x50;
        FUN_004059a0(local_58);
        cVar2 = FUN_005e7000(iVar6,pCVar7,pCVar21,pCVar13);
        pCVar7 = local_48;
        in_ECX = local_4c;
        if (cVar2 != '\0') goto LAB_0046da4a;
        local_24 = *(CMap **)(local_4c + 0xe8);
        FUN_0040b550(local_48);
        FUN_0040b550(pCVar7);
        pCVar7 = local_24;
        iVar6 = FUN_004059a0(local_58);
        fVar14 = local_58;
        iVar6 = iVar6 + 0x50;
        FUN_004059a0(local_58);
        cVar2 = FUN_005e7400(iVar6,pCVar7);
        in_ECX = local_4c;
        if ((cVar2 != '\0') ||
           (cVar2 = FUN_005e76a0(fVar14,*(undefined4 *)(DAT_00772400 + 100)), in_ECX = local_4c,
           cVar2 != '\0')) goto LAB_0046da4a;
        local_f8 = CONCAT44(fStack_124,local_128);
        local_f0 = local_120;
        cVar2 = '\x01';
        cVar15 = '\x01';
        goto LAB_0046da4e;
      }
      break;
    }
  }
LAB_0046da3b:
  FUN_0046aec0(local_94);
  in_ECX = local_4c;
LAB_0046da4a:
  cVar2 = '\0';
LAB_0046da4c:
  cVar15 = '\0';
LAB_0046da4e:
  *(char *)(in_ECX + 0xcc) = cVar2;
  *(char *)(in_ECX + 0xcd) = cVar15;
  *(CMap **)(in_ECX + 0xd0) = (CMap *)local_f8;
  *(float *)(in_ECX + 0xd4) = local_f8._4_4_;
  *(float *)(in_ECX + 0xd8) = local_f0;
  if (cVar2 == '\0') {
    if (*(char *)(in_ECX + 0xf0) != '\0') goto LAB_0046ddd6;
    local_44 = *(float *)(in_ECX + 0xbc);
    iVar6 = *(int *)(in_ECX + 0xb8);
  }
  else if (cVar15 == '\0') {
    if ((((*(int *)(in_ECX + 0xe8) != -1) &&
         (piVar18 = (int *)FUN_00407340(*(int *)(in_ECX + 0xe8)), *piVar18 != 0)) &&
        (piVar18 = (int *)FUN_00407340(*(undefined4 *)(in_ECX + 0xe8)),
        *(int *)(*piVar18 + 0x3ec) != 0)) &&
       (piVar18 = (int *)FUN_00407340(*(undefined4 *)(in_ECX + 0xe8)),
       *(int *)(*(int *)(*piVar18 + 0x3ec) + 4) != 0)) {
      FUN_00407340(*(undefined4 *)(in_ECX + 0xe8));
    }
    FUN_006096d0();
    FUN_00470b60(&local_f8,1);
    local_44 = *(float *)(in_ECX + 0xbc);
    iVar6 = *(int *)(in_ECX + 0xb8);
  }
  else {
LAB_0046ddd6:
    iVar6 = *(int *)(in_ECX + 0xc4);
    local_44 = *(float *)(in_ECX + 200);
  }
  if (((local_44 == -NAN) || (iVar6 == -1)) || (piVar18 = (int *)FUN_0040b550(iVar6), *piVar18 == 0)
     ) goto LAB_00470b22;
  local_28 = 0;
  local_24 = (CMap *)0x0;
  local_f0 = local_f0 * (float)local_88 + 7.0;
  local_70 = 0.0;
  local_68 = (float)((uint)local_68 & 0xffffff00);
  local_14 = 0x11;
  bVar20 = *(char *)(in_ECX + 0xcc) == '\0';
  if (bVar20) {
    FUN_0040b550(iVar6);
  }
  else {
    local_31 = 1;
    FUN_0040b550(iVar6);
  }
  FUN_00487430(&local_70,local_44,&local_f8,&local_f8,in_ECX + 0xdc,&local_28,!bVar20);
  puVar25 = &local_70;
  FUN_0044d010(puVar25);
  FUN_0044d760(puVar25);
  local_14 = CONCAT31(local_14._1_3_,0x12);
  FUN_00453f00(extraout_ECX_03);
  if ((void *)local_70 != (void *)0x0) {
    FUN_006ba940();
  }
  local_14 = 0x13;
  goto LAB_00470b0c;
  while( true ) {
    local_30 = (CMap *)((int)&local_30[-1].mapFlags5 + 3);
    fStack_130 = fStack_130 + local_98;
    if (local_30 == (CMap *)0x0) break;
LAB_0046e9f0:
    pCVar7 = PTR_0077241c;
    fVar14 = fStack_130 * local_44;
    DAT_00772dd8 = (CMap *)(int)ROUND(local_134 * local_44);
    local_24 = DAT_00772dd8;
    piVar18 = (int *)FUN_00592f10(PTR_0077241c);
    pCVar1 = pCVar7->heightBlocks;
    iVar6 = *piVar18;
    if ((iVar6 < 0) || (pCVar1->count <= iVar6)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar11 = pCVar1->data;
    }
    else {
      pCVar11 = pCVar1->data + iVar6;
    }
    if (local_12c < (float)pCVar11->heights[((int)ROUND(fVar14) & 7U) << 3 | (uint)local_24 & 7]) {
      if (local_30 != (CMap *)0x0) {
        local_24 = *(CMap **)(DAT_00772400 + 100);
        local_8c = (CMap *)FUN_005e3650(0);
        pCVar7 = local_48;
        local_7c = *(CMap **)(local_4c + 0xe8);
        FUN_0040b550(local_48);
        FUN_0040b550(pCVar7);
        pCVar7 = local_7c;
        pCVar21 = local_8c;
        pCVar13 = local_24;
        iVar6 = FUN_004059a0(local_54);
        iVar6 = iVar6 + 0x50;
        FUN_004059a0(local_54);
        cVar2 = FUN_005e7000(iVar6,pCVar7,pCVar21,pCVar13);
        pCVar21 = local_48;
        in_ECX = local_4c;
        pCVar7 = local_24;
        if (cVar2 != '\0') goto LAB_0046e930;
        local_24 = *(CMap **)(local_4c + 0xe8);
        FUN_0040b550(local_48);
        FUN_0040b550(pCVar21);
        pCVar7 = local_24;
        iVar6 = FUN_004059a0(local_54);
        pCVar21 = local_54;
        iVar6 = iVar6 + 0x50;
        FUN_004059a0(local_54);
        cVar2 = FUN_005e7400(iVar6,pCVar7);
        in_ECX = local_4c;
        pCVar7 = local_24;
        if ((cVar2 != '\0') ||
           (cVar2 = FUN_005e76a0(pCVar21,*(undefined4 *)(DAT_00772400 + 100)), in_ECX = local_4c,
           pCVar7 = local_24, cVar2 != '\0')) goto LAB_0046e930;
        local_ec = CONCAT44(fStack_130,local_134);
        local_e4 = local_12c;
        cVar2 = '\x01';
        cVar15 = '\x01';
        goto LAB_0046e934;
      }
      break;
    }
  }
LAB_0046e921:
  FUN_0046aec0(local_224);
  in_ECX = local_4c;
  pCVar7 = local_24;
LAB_0046e930:
  local_24 = pCVar7;
  cVar2 = '\0';
LAB_0046e932:
  cVar15 = '\0';
LAB_0046e934:
  *(char *)(in_ECX + 0xcc) = cVar2;
  *(char *)(in_ECX + 0xcd) = cVar15;
  *(CMap **)(in_ECX + 0xd0) = (CMap *)local_ec;
  *(float *)(in_ECX + 0xd4) = local_ec._4_4_;
  *(float *)(in_ECX + 0xd8) = local_e4;
  if (cVar2 == '\0') {
    if (*(char *)(in_ECX + 0xf0) != '\0') goto LAB_0046ec66;
    FUN_00407340(*(undefined4 *)(in_ECX + 0xe8));
    FUN_0060b1b0();
    iVar6 = FUN_0060b5d0();
    local_44 = *(float *)(iVar6 + 0xc);
    iVar6 = *(int *)(iVar6 + 4);
  }
  else if (cVar15 == '\0') {
    FUN_00407340(*(undefined4 *)(in_ECX + 0xe8));
    FUN_0060b1b0();
    iVar6 = FUN_0060b5d0();
    local_31 = 1;
    local_44 = *(float *)(iVar6 + 0xc);
    iVar6 = *(int *)(iVar6 + 4);
  }
  else {
LAB_0046ec66:
    iVar6 = *(int *)(in_ECX + 0xc4);
    local_44 = *(float *)(in_ECX + 200);
  }
  if (((local_44 == -NAN) || (iVar6 == -1)) || (piVar18 = (int *)FUN_0040b550(iVar6), *piVar18 == 0)
     ) goto LAB_00470b22;
  local_28 = 0;
  local_24 = (CMap *)0x0;
  local_e4 = local_e4 * (float)local_38 + 7.0;
  local_70 = 0.0;
  local_68 = (float)((uint)local_68 & 0xffffff00);
  local_14 = 0x15;
  bVar20 = *(char *)(in_ECX + 0xcc) == '\0';
  if (bVar20) {
    FUN_0040b550(iVar6);
  }
  else {
    local_31 = 1;
    FUN_0040b550(iVar6);
  }
  FUN_00487430(&local_70,local_44,&local_ec,&local_ec,in_ECX + 0xdc,&local_28,!bVar20);
  puVar25 = &local_70;
  FUN_0044d010(puVar25);
  FUN_0044d760(puVar25);
  local_14 = CONCAT31(local_14._1_3_,0x16);
  FUN_00453f00(extraout_ECX_04);
  if ((void *)local_70 != (void *)0x0) {
    FUN_006ba940();
  }
  local_14 = 0x17;
  goto LAB_00470b0c;
  while( true ) {
    fStack_c4 = fStack_c4 + 0.125;
    iVar6 = iVar6 + -1;
    if (iVar6 == 0) break;
LAB_004708d0:
    local_24 = (CMap *)(local_c8 * 8.0);
    DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
    bVar3 = FUN_004093f0(PTR_0077241c);
    if ((float)local_c0 < (float)bVar3) {
      if (iVar6 != 0) {
        local_24 = *(CMap **)(DAT_00772400 + 100);
        local_8c = (CMap *)FUN_005e3650(0);
        pCVar7 = local_48;
        local_7c = *(CMap **)(local_4c + 0xe8);
        FUN_0040b550(local_48);
        FUN_0040b550(pCVar7);
        pCVar7 = local_7c;
        pCVar21 = local_8c;
        pCVar13 = local_24;
        iVar6 = FUN_004059a0(local_54);
        iVar6 = iVar6 + 0x50;
        FUN_004059a0(local_54);
        cVar2 = FUN_005e7000(iVar6,pCVar7,pCVar21,pCVar13);
        pCVar7 = local_48;
        if (cVar2 != '\0') goto LAB_0047087f;
        local_24 = *(CMap **)(local_4c + 0xe8);
        FUN_0040b550(local_48);
        FUN_0040b550(pCVar7);
        pCVar21 = local_24;
        iVar6 = FUN_004059a0(local_54);
        pCVar7 = local_54;
        iVar6 = iVar6 + 0x50;
        FUN_004059a0(local_54);
        cVar2 = FUN_005e7400(iVar6,pCVar21);
        if ((cVar2 != '\0') ||
           (cVar2 = FUN_005e76a0(pCVar7,*(undefined4 *)(DAT_00772400 + 100)), cVar2 != '\0'))
        goto LAB_0047087f;
        local_b0 = (double)CONCAT44(fStack_c4,local_c8);
        pCStack_a8 = local_c0;
        local_2a = 1;
        local_29 = 1;
        goto LAB_00470887;
      }
      break;
    }
  }
LAB_00470873:
  FUN_0046aec0(local_15c);
LAB_0047087f:
  local_2a = 0;
  local_29 = 0;
LAB_00470887:
  local_14 = 0xffffffff;
  FUN_005ddfc0();
  in_ECX = local_4c;
  bVar3 = local_2a;
  fVar14 = (float)local_b0;
  fVar22 = local_b0._4_4_;
  bVar12 = local_29;
LAB_00470195:
  *(byte *)(in_ECX + 0xcc) = bVar3;
  *(undefined1 *)(in_ECX + 0xcd) = 0;
  *(float *)(in_ECX + 0xd0) = fVar14;
  *(float *)(in_ECX + 0xd4) = fVar22;
  *(CMap **)(in_ECX + 0xd8) = pCStack_a8;
  local_38 = *(int **)(in_ECX + 0xbc);
  iVar6 = *(int *)(in_ECX + 0xb8);
  if (bVar3 != 0) {
    local_31 = bVar12 ^ 1;
  }
  if (((local_38 == (int *)0xffffffff) || (iVar6 == -1)) ||
     (piVar18 = (int *)FUN_0040b550(iVar6), *piVar18 == 0)) goto LAB_00470b22;
  local_28 = 0;
  local_24 = (CMap *)0x0;
  pCStack_a8 = (CMap *)((float)pCStack_a8 * 0.5 + 7.0);
  local_70 = 0.0;
  local_68 = (float)((uint)local_68 & 0xffffff00);
  local_14 = 0x22;
  bVar20 = *(char *)(in_ECX + 0xcc) == '\0';
  if (bVar20) {
    FUN_0040b550(iVar6);
  }
  else {
    local_31 = 1;
    FUN_0040b550(iVar6);
  }
  FUN_00487430(&local_70,local_38,&local_b0,&local_b0,in_ECX + 0xdc,&local_28,!bVar20);
  puVar25 = &local_70;
  FUN_0044d010(puVar25);
  FUN_0044d760(puVar25);
  local_14 = CONCAT31(local_14._1_3_,0x23);
  FUN_00453f00(extraout_ECX_07);
  if ((void *)local_70 != (void *)0x0) {
    FUN_006ba940();
  }
  local_14 = 0x24;
  goto LAB_00470b0c;
  while( true ) {
    fStack_c4 = fStack_c4 + (float)local_74;
    iVar9 = iVar9 + -1;
    if (iVar9 == 0) break;
LAB_0046fcd0:
    local_24 = (CMap *)(local_c8 * (float)local_50);
    DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
    bVar3 = FUN_004093f0(PTR_0077241c);
    if ((float)local_c0 < (float)bVar3) {
      if (iVar9 != 0) {
        local_24 = *(CMap **)(DAT_00772400 + 100);
        local_8c = (CMap *)FUN_005e3650(0);
        pCVar7 = local_48;
        local_7c = *(CMap **)(iVar6 + 0xe8);
        FUN_0040b550(local_48);
        FUN_0040b550(pCVar7);
        pCVar7 = local_7c;
        pCVar21 = local_8c;
        pCVar13 = local_24;
        iVar6 = FUN_004059a0(local_54);
        iVar6 = iVar6 + 0x50;
        FUN_004059a0(local_54);
        cVar2 = FUN_005e7000(iVar6,pCVar7,pCVar21,pCVar13);
        pCVar7 = local_48;
        if (cVar2 != '\0') goto LAB_0046fca6;
        local_24 = *(CMap **)(local_4c + 0xe8);
        FUN_0040b550(local_48);
        FUN_0040b550(pCVar7);
        pCVar21 = local_24;
        iVar6 = FUN_004059a0(local_54);
        pCVar7 = local_54;
        iVar6 = iVar6 + 0x50;
        FUN_004059a0(local_54);
        cVar2 = FUN_005e7400(iVar6,pCVar21);
        if ((cVar2 != '\0') ||
           (cVar2 = FUN_005e76a0(pCVar7,*(undefined4 *)(DAT_00772400 + 100)), cVar2 != '\0'))
        goto LAB_0046fca6;
        local_104 = CONCAT44(fStack_c4,local_c8);
        cVar15 = '\x01';
        cVar2 = '\x01';
        local_fc = local_c0;
        in_ECX = local_4c;
        goto LAB_0046fead;
      }
      break;
    }
  }
LAB_0046fc9a:
  FUN_0046aec0(local_15c);
LAB_0046fca6:
  in_ECX = local_4c;
  local_44 = (float)local_104;
LAB_0046fea9:
  local_c8 = local_44;
  cVar15 = '\0';
LAB_0046feab:
  cVar2 = '\0';
LAB_0046fead:
  *(char *)(in_ECX + 0xcc) = cVar15;
  *(char *)(in_ECX + 0xcd) = cVar2;
  *(float *)(in_ECX + 0xd0) = local_c8;
  *(CMap **)(in_ECX + 0xd4) = local_104._4_4_;
  *(CMap **)(in_ECX + 0xd8) = local_fc;
  if (cVar15 == '\0') {
    if (*(char *)(in_ECX + 0xf0) != '\0') goto LAB_0046ff12;
    local_44 = *(float *)(in_ECX + 0xbc);
    iVar6 = *(int *)(in_ECX + 0xb8);
  }
  else if (cVar2 == '\0') {
    local_44 = *(float *)(in_ECX + 0xbc);
    iVar6 = *(int *)(in_ECX + 0xb8);
    local_31 = 1;
  }
  else {
LAB_0046ff12:
    iVar6 = *(int *)(in_ECX + 0xc4);
    local_44 = *(float *)(in_ECX + 200);
  }
  if (((local_44 == -NAN) || (iVar6 == -1)) || (piVar18 = (int *)FUN_0040b550(iVar6), *piVar18 == 0)
     ) goto LAB_00470b22;
  local_28 = 0;
  local_24 = (CMap *)0x0;
  local_fc = (CMap *)((float)local_fc * (float)local_88 + 7.0);
  local_70 = 0.0;
  local_68 = (float)((uint)local_68 & 0xffffff00);
  local_14 = 0x1d;
  bVar20 = *(char *)(in_ECX + 0xcc) == '\0';
  if (bVar20) {
    FUN_0040b550(iVar6);
  }
  else {
    local_31 = 1;
    FUN_0040b550(iVar6);
  }
  FUN_00487430(&local_70,local_44,&local_104,&local_104,in_ECX + 0xdc,&local_28,!bVar20);
  puVar25 = &local_70;
  FUN_0044d010(puVar25);
  FUN_0044d760(puVar25);
  local_14 = CONCAT31(local_14._1_3_,0x1e);
  FUN_00453f00(extraout_ECX_06);
  if ((void *)local_70 != (void *)0x0) {
    FUN_006ba940();
  }
  local_14 = 0x1f;
  goto LAB_00470b0c;
  while( true ) {
    fStack_13c = fStack_13c + (float)local_88;
    iVar9 = iVar9 + -1;
    if (iVar9 == 0) break;
LAB_0046f390:
    local_24 = (CMap *)(local_140 * (float)local_50);
    DAT_00772dd8 = (CMap *)(int)ROUND((float)local_24);
    bVar3 = FUN_004093f0(PTR_0077241c);
    if ((float)local_138 < (float)bVar3) {
      if (iVar9 != 0) {
        local_24 = *(CMap **)(DAT_00772400 + 100);
        local_8c = (CMap *)FUN_005e3650(0);
        pCVar7 = local_48;
        local_7c = *(CMap **)(iVar6 + 0xe8);
        FUN_0040b550(local_48);
        FUN_0040b550(pCVar7);
        pCVar7 = local_7c;
        pCVar21 = local_8c;
        pCVar13 = local_24;
        iVar6 = FUN_004059a0(local_54);
        iVar6 = iVar6 + 0x50;
        FUN_004059a0(local_54);
        cVar2 = FUN_005e7000(iVar6,pCVar7,pCVar21,pCVar13);
        pCVar21 = local_48;
        iVar6 = local_4c;
        pCVar7 = local_24;
        if (cVar2 != '\0') goto LAB_0046f30d;
        local_24 = *(CMap **)(local_4c + 0xe8);
        FUN_0040b550(local_48);
        FUN_0040b550(pCVar21);
        pCVar7 = local_24;
        iVar6 = FUN_004059a0(local_54);
        pCVar21 = local_54;
        iVar6 = iVar6 + 0x50;
        FUN_004059a0(local_54);
        cVar2 = FUN_005e7400(iVar6,pCVar7);
        iVar6 = local_4c;
        pCVar7 = local_24;
        if ((cVar2 != '\0') ||
           (cVar2 = FUN_005e76a0(pCVar21,*(undefined4 *)(DAT_00772400 + 100)), iVar6 = local_4c,
           pCVar7 = local_24, cVar2 != '\0')) goto LAB_0046f30d;
        local_110 = CONCAT44(fStack_13c,local_140);
        local_108 = local_138;
        cVar15 = '\x01';
        cVar2 = '\x01';
        in_ECX = local_4c;
        goto LAB_0046f311;
      }
      break;
    }
  }
LAB_0046f2fe:
  FUN_0046aec0(local_150);
  iVar6 = local_4c;
  pCVar7 = local_24;
LAB_0046f30d:
  local_24 = pCVar7;
  local_4c = iVar6;
  cVar15 = '\0';
LAB_0046f30f:
  cVar2 = '\0';
  in_ECX = local_4c;
LAB_0046f311:
  *(char *)(in_ECX + 0xcc) = cVar15;
  *(char *)(in_ECX + 0xcd) = cVar2;
  *(CMap **)(in_ECX + 0xd0) = (CMap *)local_110;
  *(float *)(in_ECX + 0xd4) = local_110._4_4_;
  *(CMap **)(in_ECX + 0xd8) = local_108;
  if (cVar15 == '\0') {
    if (*(char *)(in_ECX + 0xf0) != '\0') goto LAB_0046f576;
    local_44 = *(float *)(in_ECX + 0xbc);
    iVar6 = *(int *)(in_ECX + 0xb8);
  }
  else if (cVar2 == '\0') {
    local_44 = *(float *)(in_ECX + 0xbc);
    iVar6 = *(int *)(in_ECX + 0xb8);
    local_31 = 1;
  }
  else {
LAB_0046f576:
    iVar6 = *(int *)(in_ECX + 0xc4);
    local_44 = *(float *)(in_ECX + 200);
  }
  if (((local_44 == -NAN) || (iVar6 == -1)) || (piVar18 = (int *)FUN_0040b550(iVar6), *piVar18 == 0)
     ) goto LAB_00470b22;
  local_28 = 0;
  local_24 = (CMap *)0x0;
  local_108 = (CMap *)((float)local_108 * (float)local_74 + 7.0);
  local_70 = 0.0;
  local_68 = (float)((uint)local_68 & 0xffffff00);
  local_14 = 0x19;
  bVar20 = *(char *)(in_ECX + 0xcc) == '\0';
  if (bVar20) {
    FUN_0040b550(iVar6);
  }
  else {
    local_31 = 1;
    FUN_0040b550(iVar6);
  }
  FUN_00487430(&local_70,local_44,&local_110,&local_110,in_ECX + 0xdc,&local_28,!bVar20);
  puVar25 = &local_70;
  FUN_0044d010(puVar25);
  FUN_0044d760(puVar25);
  local_14 = CONCAT31(local_14._1_3_,0x1a);
  FUN_00453f00(extraout_ECX_05);
  if ((void *)local_70 != (void *)0x0) {
    FUN_006ba940();
  }
  local_14 = 0x1b;
LAB_00470b0c:
  FUN_0047e280(0);
  iVar6 = local_28;
LAB_00470b19:
  if (iVar6 != 0) {
    FUN_006ba940();
  }
LAB_00470b22:
  iVar6 = DAT_00772400;
  *(byte *)(DAT_00772400 + 0xa3e2) = local_31;
  *(undefined1 *)(iVar6 + 0xa3e1) = *(undefined1 *)(in_ECX + 0xcd);
  ExceptionList = local_1c;
  return;
}

