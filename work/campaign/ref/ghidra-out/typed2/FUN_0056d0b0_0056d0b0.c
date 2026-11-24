
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056d0b0(float param_1,float param_2,undefined4 param_3,char param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  float *pfVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  int in_ECX;
  float *pfVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  byte *pbVar14;
  code *pcVar15;
  int iVar16;
  byte *pbVar17;
  uint uVar18;
  float fVar19;
  undefined4 **ppuVar20;
  char *pcVar21;
  int local_70;
  float *local_6c;
  float *local_68;
  float *local_64;
  int local_60;
  int local_5c;
  float *local_58;
  byte *local_54;
  uint local_50;
  int local_4c;
  int local_48;
  int local_44;
  byte *local_40;
  byte *local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24;
  float *local_20;
  int local_1c;
  float *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00705d55;
  local_10 = ExceptionList;
  if (param_1 == -1000.0) {
    pfVar10 = (float *)(int)*(float *)(in_ECX + 0xf0);
    local_48 = (uint)local_48._1_3_ << 8;
    pfVar4 = (float *)(int)*(float *)(in_ECX + 0xe4);
    iVar11 = (int)*(float *)(in_ECX + 0xe8);
    local_20 = pfVar4;
    if ((int)pfVar10 <= (int)pfVar4) {
      local_20 = pfVar10;
    }
    iVar13 = (int)*(float *)(in_ECX + 0xf4);
    iVar16 = iVar11;
    if (iVar13 <= iVar11) {
      iVar16 = iVar13;
    }
    if ((int)pfVar4 <= (int)pfVar10) {
      pfVar4 = pfVar10;
    }
    if (iVar11 <= iVar13) {
      iVar11 = iVar13;
    }
  }
  else {
    if ((*(int *)(in_ECX + 0xe0) != 0) && (param_4 == '\0')) {
      return;
    }
    iVar16 = (int)param_2;
    local_48 = CONCAT31(local_48._1_3_,1);
    pfVar4 = (float *)(int)param_1;
    iVar11 = iVar16;
    local_20 = pfVar4;
  }
  local_24 = iVar11 + 2;
  local_54 = (byte *)((int)pfVar4 + 2);
  local_5c = iVar16 + -1;
  local_60 = (int)local_20 - 1;
  local_28 = (int)pfVar4 + (3 - local_60);
  local_70 = (iVar11 + 3) - local_5c;
  if ((0 < (int)local_28) && (0 < local_70)) {
    iVar13 = local_70 * local_28;
    local_8 = 0;
    ExceptionList = &local_10;
    local_44 = in_ECX;
    local_2c = iVar13;
    pbVar5 = (byte *)FUN_006ba810(0x5a4,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar11 = 0;
    if (0 < iVar13) {
      do {
        pbVar5[iVar11] = 0;
        iVar11 = iVar11 + 1;
      } while (iVar11 < iVar13);
    }
    pcVar15 = RaiseException_exref;
    if (iVar16 < local_24) {
      uVar18 = ((iVar16 - local_5c) * local_28 - local_60) + (int)local_20;
      local_24 = local_24 - iVar16;
      pbVar17 = local_54;
      pfVar4 = local_20;
      do {
        iVar11 = local_2c;
        local_50 = uVar18;
        if ((int)pfVar4 < (int)pbVar17) {
          local_58 = (float *)((int)pbVar17 - (int)local_20);
          do {
            if (((int)uVar18 < 0) || (iVar11 <= (int)uVar18)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar17 = pbVar5;
            }
            else {
              pbVar17 = pbVar5 + uVar18;
            }
            uVar18 = uVar18 + 1;
            *pbVar17 = 1;
            local_58 = (float *)((int)local_58 + -1);
          } while (local_58 != (float *)0x0);
          local_58 = (float *)0x0;
          pbVar17 = local_54;
          pfVar4 = local_20;
        }
        uVar18 = local_50 + local_28;
        local_24 = local_24 + -1;
      } while (local_24 != 0);
      local_24 = 0;
      in_ECX = local_44;
      local_50 = uVar18;
    }
    local_70 = local_70 + -1;
    *(undefined4 *)(in_ECX + 0x108) = 0;
    *(undefined4 *)(in_ECX + 0x118) = 0;
    if (0 < local_70) {
      local_38 = 0;
      local_6c = (float *)(local_28 - 1);
      local_3c = pbVar5 + local_28;
      local_58 = (float *)~local_28;
      iVar11 = local_28 - (int)pbVar5;
      local_24 = local_5c;
      local_40 = pbVar5;
      do {
        if (0 < (int)local_6c) {
          pbVar17 = local_3c + (1 - (int)pbVar5);
          local_1c = local_60;
          local_54 = local_40 + iVar11;
          local_4c = local_38 - (int)local_54;
          local_64 = (float *)((int)local_20 + (int)local_58);
          local_68 = (float *)local_38;
          do {
            if (((int)local_68 < 0) || (local_2c <= (int)local_68)) {
              (*pcVar15)(0xc000008c,1,0,0);
              pbVar14 = (byte *)((int)local_58 + (int)pbVar17);
              pbVar6 = pbVar5;
            }
            else {
              pbVar14 = (byte *)((int)local_58 + (int)pbVar17);
              pbVar6 = pbVar14 + (int)local_40;
            }
            local_34 = (uint)*pbVar6;
            if (((int)(pbVar17 + local_4c) < 0) || (local_2c <= (int)(pbVar17 + local_4c))) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar6 = pbVar5;
            }
            else {
              pbVar6 = pbVar14 + 1 + (int)local_40;
            }
            local_30 = (uint)*pbVar6;
            if (((int)local_54 < 0) || (local_2c <= (int)local_54)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar6 = pbVar5;
            }
            else {
              pbVar6 = local_3c + (int)pbVar14;
            }
            pcVar15 = RaiseException_exref;
            local_18 = (float *)(uint)*pbVar6;
            if (((int)pbVar17 < 0) || (local_2c <= (int)pbVar17)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar14 = pbVar5;
            }
            else {
              pbVar14 = pbVar14 + 1 + (int)local_3c;
            }
            local_50 = (uint)*pbVar14;
            uVar18 = local_50;
            if (((((param_4 == '\0') && (PTR_0077241c->cellX0 <= local_1c)) &&
                 (local_1c < PTR_0077241c->cellX1)) &&
                ((PTR_0077241c->cellY0 <= local_24 && (local_24 < PTR_0077241c->cellY1)))) &&
               ((char)local_48 == '\0')) {
              cVar3 = FUN_00566870(local_1c,local_24,local_34);
              if (cVar3 == '\0') {
                local_34 = local_34 | 8;
              }
              cVar3 = FUN_00566870((byte *)((int)local_64 + (int)pbVar17),local_24,local_30);
              if (cVar3 == '\0') {
                local_30 = local_30 | 8;
              }
              cVar3 = FUN_00566870(local_1c,local_24 + 1,local_18);
              if (cVar3 == '\0') {
                local_18 = (float *)((uint)local_18 | 8);
              }
              cVar3 = FUN_00566870((byte *)((int)local_64 + (int)pbVar17),local_24 + 1,local_50);
              uVar18 = local_50;
              if (cVar3 == '\0') {
                uVar18 = local_50 | 8;
              }
            }
            FUN_0056ae30(local_1c,local_24,local_34,local_30,local_18,uVar18,local_48);
            pbVar17 = pbVar17 + 1;
            local_54 = local_54 + 1;
            local_68 = (float *)((int)local_68 + 1);
            local_1c = local_1c + 1;
          } while ((int)((int)local_58 + (int)pbVar17) < (int)local_6c);
        }
        local_24 = local_24 + 1;
        local_38 = local_38 + local_28;
        local_58 = (float *)((int)local_58 - local_28);
        local_3c = local_3c + local_28;
        local_40 = local_40 + local_28;
        local_70 = local_70 + -1;
      } while (local_70 != 0);
      if (*(int *)(local_44 + 0x108) != 0) {
        ppuVar20 = &local_14;
        pcVar21 = "DigMark 4";
        FUN_0044d010(ppuVar20,"DigMark 4");
        FUN_0044d570(ppuVar20,pcVar21);
        local_8 = CONCAT31(local_8._1_3_,1);
        if (local_14 != (undefined4 *)0x0) {
          local_14[3] = 4;
          local_14[2] = 0x27;
          local_14[4] = 1;
          if ((char)local_48 == '\0') {
            local_14[5] = 0x32;
          }
          else {
            uVar12 = 0x69;
            if (param_4 == '\0') {
              uVar12 = 0x50;
            }
            local_14[5] = uVar12;
          }
          local_14[0xf] = *(undefined4 *)(DAT_0076a338 + 0xac);
          local_14[0xe] = 0;
          local_14[0xd] = 0;
          local_14[0xc] = 0;
          local_14[0xb] = 0;
          local_14[10] = 0;
          local_14[9] = 0;
          local_14[8] = 0;
          local_14[7] = 0;
          local_14[6] = 0;
          puVar7 = (undefined4 *)FUN_006ba810(0x609);
          if (puVar7 == (undefined4 *)0x0) {
            puVar7 = (undefined4 *)0x0;
          }
          else {
            _DAT_0076a2f4 = _DAT_0076a2f4 + 1;
            puVar7[1] = 0;
            *puVar7 = CVectorBuffer::vftable;
            puVar7[7] = 0;
            *(undefined1 *)(puVar7 + 0xc) = 0;
            *(undefined2 *)(puVar7 + 2) = 0;
            puVar7[3] = 0;
            puVar7[10] = 0;
            puVar7[9] = 0;
            puVar7[0xb] = 0;
            puVar7[8] = 0x1c2;
            puVar7[5] = 0;
            *(undefined1 *)(puVar7 + 6) = 0;
            puVar7[4] = 0;
            puVar7[0xd] = 0;
          }
          puVar1 = (undefined4 *)local_14[0x11];
          local_14[0x11] = puVar7;
          if (puVar7 != (undefined4 *)0x0) {
            LOCK();
            puVar7[1] = puVar7[1] + 1;
            UNLOCK();
          }
          if (puVar1 != (undefined4 *)0x0) {
            LOCK();
            iVar11 = puVar1[1] + -1;
            puVar1[1] = iVar11;
            UNLOCK();
            if (iVar11 == 0) {
              (**(code **)*puVar1)(1);
            }
          }
          FUN_0045fd00(0x1c2,*(undefined4 *)(local_44 + 0x108),0);
          iVar11 = *(int *)(local_44 + 0x10c);
          local_70 = *(int *)(local_44 + 0x118);
          iVar16 = local_14[0x11];
          if ((*(int *)(iVar16 + 0x28) != 0) && (*(char *)(iVar16 + 9) == '\0')) {
            FUN_006ba940();
          }
          uVar12 = FUN_006ba810(0xb8);
          *(int *)(iVar16 + 0x2c) = local_70;
          *(undefined4 *)(iVar16 + 0x28) = uVar12;
          *(undefined1 *)(iVar16 + 9) = 0;
          DAT_0076a2f0 = DAT_0076a2f0 + local_70 * 2;
          if (iVar11 != 0) {
            FUN_006d2250(uVar12,iVar11,local_70 * 2);
          }
          iVar11 = local_14[0x11];
          *(int *)(iVar11 + 0x10) = *(int *)(iVar11 + 0x10) + 1;
          if ((0 < *(int *)(iVar11 + 0x10)) && (*(int **)(iVar11 + 0x14) != (int *)0x0)) {
            piVar2 = (int *)**(int **)(iVar11 + 0x14);
            if (piVar2 == (int *)0x0) {
              iVar16 = 0;
            }
            else {
              local_70 = 0;
              (**(code **)(*piVar2 + 0x10))(0x1821,&local_70,0);
              iVar16 = local_70;
            }
            *(int *)(iVar11 + 0xc) = iVar16;
            *(undefined4 *)(iVar11 + 0x34) = 0;
          }
          local_20 = *(float **)(iVar11 + 0xc);
          local_1c = *(int *)(iVar11 + 0x24);
          iVar11 = 0;
          if (0 < *(int *)(local_44 + 0x108)) {
            local_24 = 0;
            local_18 = local_20;
            do {
              if ((iVar11 < 0) || (*(int *)(local_44 + 0x100) <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                pfVar4 = *(float **)(local_44 + 0xfc);
                pfVar10 = pfVar4;
              }
              else {
                pfVar4 = (float *)(local_24 + (int)*(float **)(local_44 + 0xfc));
                pfVar10 = *(float **)(local_44 + 0xfc);
              }
              fVar19 = *pfVar4;
              if ((iVar11 < 0) || (*(int *)(local_44 + 0x100) <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                iVar16 = *(int *)(local_44 + 0xfc);
              }
              else {
                iVar16 = local_24 + (int)pfVar10;
              }
              iVar16 = (((int)(*(float *)(iVar16 + 4) + 0.5) - local_5c) * local_28 - local_60) +
                       (int)(fVar19 + 0.5);
              if ((iVar16 < 0) || (local_2c <= iVar16)) {
                (*pcVar15)(0xc000008c,1,0,0);
              }
              iVar16 = *(int *)(DAT_00772400 + 0x6c);
              if ((iVar11 < 0) || (*(int *)(local_44 + 0x100) <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                local_58 = *(float **)(local_44 + 0xfc);
                local_6c = local_58;
              }
              else {
                local_58 = *(float **)(local_44 + 0xfc);
                local_6c = (float *)(local_24 + (int)local_58);
              }
              if ((iVar11 < 0) || (*(int *)(local_44 + 0x100) <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                pfVar4 = *(float **)(local_44 + 0xfc);
                local_58 = pfVar4;
              }
              else {
                pfVar4 = (float *)((int)local_58 + local_24);
              }
              local_54 = (byte *)((float)iVar16 * 0.25);
              fVar19 = pfVar4[1] * 3.0 + *local_6c * 3.0 + (float)local_54;
              FUN_004089d0();
              if (param_4 == '\0') {
                if ((iVar11 < 0) || (*(int *)(local_44 + 0x100) <= iVar11)) {
                  (*pcVar15)(0xc000008c,1,0,0);
                  iVar16 = *(int *)(local_44 + 0xfc);
                }
                else {
                  iVar16 = (int)local_58 + local_24;
                }
                fVar19 = (fVar19 * 7.0 + 135.0) * 0.015625;
                if (*(int *)(iVar16 + 0xc) == 1) {
                  local_58 = (float *)0xaf;
                  uVar18 = 0;
                  if (0 < (int)ROUND(fVar19 * 122.88)) {
                    uVar18 = (int)ROUND(fVar19 * 122.88);
                  }
                  uVar8 = 0xff;
                  if ((int)uVar18 < 0xff) {
                    uVar8 = uVar18;
                  }
                  pfVar4 = (float *)0x0;
                  if (0 < (int)ROUND(fVar19 * 26.112)) {
                    pfVar4 = (float *)(int)ROUND(fVar19 * 26.112);
                  }
                  local_6c = (float *)0xff;
                  if ((int)pfVar4 < 0xff) {
                    local_6c = pfVar4;
                  }
                  DAT_00772dd8 = (uint)ROUND(fVar19 * 12.032);
                  uVar18 = 0;
                  if (0 < (int)DAT_00772dd8) {
                    uVar18 = DAT_00772dd8;
                  }
                  uVar9 = 0xff;
                  if ((int)uVar18 < 0xff) {
                    uVar9 = uVar18;
                  }
                  if ((iVar11 < 0) || (pfVar4 = local_18, local_1c <= iVar11)) {
                    (*pcVar15)(0xc000008c,1,0,0);
                    pfVar4 = local_20;
                  }
                  local_58 = (float *)((((int)local_58 << 8 | uVar8) << 8 | (uint)local_6c) << 8 |
                                      uVar9);
                  pfVar4[4] = (float)local_58;
                  if ((iVar11 < 0) || (pfVar4 = local_18, local_1c <= iVar11)) {
                    (*pcVar15)(0xc000008c,1,0,0);
                    pfVar4 = local_20;
                  }
                }
                else {
                  local_58 = (float *)0x33;
                  uVar18 = 0;
                  if (0 < (int)ROUND(fVar19 * 56.064)) {
                    uVar18 = (int)ROUND(fVar19 * 56.064);
                  }
                  uVar8 = 0xff;
                  if ((int)uVar18 < 0xff) {
                    uVar8 = uVar18;
                  }
                  pfVar4 = (float *)0x0;
                  if (0 < (int)ROUND(fVar19 * 87.04)) {
                    pfVar4 = (float *)(int)ROUND(fVar19 * 87.04);
                  }
                  local_6c = (float *)0xff;
                  if ((int)pfVar4 < 0xff) {
                    local_6c = pfVar4;
                  }
                  DAT_00772dd8 = (uint)ROUND(fVar19 * 43.008);
                  uVar18 = 0;
                  if (0 < (int)DAT_00772dd8) {
                    uVar18 = DAT_00772dd8;
                  }
                  uVar9 = 0xff;
                  if ((int)uVar18 < 0xff) {
                    uVar9 = uVar18;
                  }
                  if ((iVar11 < 0) || (pfVar4 = local_18, local_1c <= iVar11)) {
                    (*pcVar15)(0xc000008c,1,0,0);
                    pfVar4 = local_20;
                  }
                  local_58 = (float *)((((int)local_58 << 8 | uVar8) << 8 | (uint)local_6c) << 8 |
                                      uVar9);
                  pfVar4[4] = (float)local_58;
                  if ((iVar11 < 0) || (pfVar4 = local_18, local_1c <= iVar11)) {
                    (*pcVar15)(0xc000008c,1,0,0);
                    local_20[3] = (float)local_58;
                    goto LAB_0056db78;
                  }
                }
                pfVar4[3] = (float)local_58;
              }
              else {
                if ((iVar11 < 0) || (pfVar4 = local_18, local_1c <= iVar11)) {
                  (*pcVar15)(0xc000008c,1,0,0);
                  pfVar4 = local_20;
                }
                pfVar4[4] = -2.9691304e+38;
                if ((iVar11 < 0) || (pfVar4 = local_18, local_1c <= iVar11)) {
                  (*pcVar15)(0xc000008c,1,0,0);
                  pfVar4 = local_20;
                }
                pfVar4[3] = -2.9691304e+38;
              }
LAB_0056db78:
              if ((iVar11 < 0) || (*(int *)(local_44 + 0x100) <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                pfVar4 = *(float **)(local_44 + 0xfc);
                local_68 = pfVar4;
              }
              else {
                pfVar4 = *(float **)(local_44 + 0xfc);
                local_68 = (float *)(local_24 + (int)pfVar4);
              }
              if ((iVar11 < 0) || (*(int *)(local_44 + 0x100) <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                local_6c = *(float **)(local_44 + 0xfc);
              }
              else {
                local_6c = (float *)((int)pfVar4 + local_24);
              }
              if ((iVar11 < 0) || (pfVar4 = local_18, local_1c <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                pfVar4 = local_20;
              }
              fVar19 = *(float *)((int)local_6c + 4) + (float)local_54;
              local_64 = pfVar4;
              FUN_004089d0();
              *local_64 = fVar19 * 0.06 + *local_68;
              if ((iVar11 < 0) || (*(int *)(local_44 + 0x100) <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                iVar16 = *(int *)(local_44 + 0xfc);
                local_68 = (float *)iVar16;
              }
              else {
                iVar16 = *(int *)(local_44 + 0xfc);
                local_68 = (float *)(local_24 + iVar16);
              }
              if ((iVar11 < 0) || (*(int *)(local_44 + 0x100) <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                local_6c = *(float **)(local_44 + 0xfc);
              }
              else {
                local_6c = (float *)(iVar16 + local_24);
              }
              if ((iVar11 < 0) || (pfVar4 = local_18, local_1c <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                pfVar4 = local_20;
              }
              fVar19 = *local_6c + (float)local_54;
              local_64 = pfVar4;
              FUN_004089d0();
              local_64[1] = fVar19 * 0.06 + *(float *)((int)local_68 + 4);
              if ((iVar11 < 0) || (pfVar4 = local_18, local_1c <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                pfVar4 = local_20;
              }
              pfVar4[2] = 15.0;
              if ((iVar11 < 0) || (pfVar4 = local_18, local_1c <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                pfVar4 = local_20;
              }
              pfVar4[5] = 0.024;
              if ((iVar11 < 0) || (pfVar4 = local_18, local_1c <= iVar11)) {
                (*pcVar15)(0xc000008c,1,0,0);
                pfVar4 = local_20;
              }
              iVar11 = iVar11 + 1;
              local_24 = local_24 + 0x10;
              pfVar4[6] = 0.487;
              local_18 = local_18 + 7;
            } while (iVar11 < *(int *)(local_44 + 0x108));
          }
          iVar11 = local_14[0x11];
          piVar2 = (int *)(iVar11 + 0x10);
          *piVar2 = *piVar2 + -1;
          if ((*piVar2 == 0) && (*(int **)(iVar11 + 0x14) != (int *)0x0)) {
            piVar2 = (int *)**(int **)(iVar11 + 0x14);
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 0x18))();
            }
            *(undefined4 *)(iVar11 + 0xc) = 0;
          }
          puVar7 = local_14;
          if (local_14 != (undefined4 *)0x0) {
            LOCK();
            local_14[1] = local_14[1] + 1;
            UNLOCK();
          }
          local_8._0_1_ = 2;
          FUN_0044d010();
          local_8 = CONCAT31(local_8._1_3_,3);
          if (puVar7 != (undefined4 *)0x0) {
            LOCK();
            puVar7[1] = puVar7[1] + 1;
            UNLOCK();
          }
          FUN_00450720(puVar7);
          if (puVar7 != (undefined4 *)0x0) {
            LOCK();
            iVar11 = puVar7[1] + -1;
            puVar7[1] = iVar11;
            UNLOCK();
            if (iVar11 == 0) {
              (**(code **)*puVar7)(1);
            }
          }
          if (local_14 != (undefined4 *)0x0) {
            LOCK();
            piVar2 = local_14 + 1;
            iVar11 = *piVar2;
            *piVar2 = *piVar2 + -1;
            UNLOCK();
            if ((iVar11 == 1) && (local_14 != (undefined4 *)0x0)) {
              (**(code **)*local_14)(1);
            }
          }
        }
      }
    }
    thunk_FUN_0060fc30(pbVar5);
  }
  ExceptionList = local_10;
  return;
}

