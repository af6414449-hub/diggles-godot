
int FUN_004ca080(int param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5,
                undefined4 param_6,char param_7,char param_8,char param_9,char param_10)

{
  undefined1 *puVar1;
  ushort *puVar2;
  int iVar3;
  CHeightBlockArray *pCVar4;
  CMap *this;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  int iVar11;
  byte *pbVar12;
  undefined4 uVar13;
  CSceneRenderer *in_ECX;
  int iVar14;
  float *pfVar15;
  float *pfVar16;
  code *pcVar17;
  ushort *puVar18;
  uint uVar19;
  ushort *puVar20;
  undefined4 **ppuVar21;
  char *pcVar22;
  int local_30;
  uint local_28;
  int local_20;
  int local_1c;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fea9d;
  local_10 = ExceptionList;
  uVar5 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00592f10(PTR_0077241c);
  piVar6 = (int *)FUN_00592f10(PTR_0077241c);
  local_28 = 0;
  iVar3 = *piVar6;
  pcVar17 = RaiseException_exref;
  do {
    pCVar4 = PTR_0077241c->heightBlocks;
    if ((iVar3 < 0) || (*(int *)&pCVar4->field_0x1c <= iVar3)) {
      (*pcVar17)(0xc000008c,1,0,0,uVar5);
      piVar6 = *(int **)&pCVar4->field_0x18;
    }
    else {
      piVar6 = (int *)(*(int *)&pCVar4->field_0x18 + iVar3 * 0xc);
    }
    if (local_28 < 3) {
      piVar6 = piVar6 + local_28;
    }
    else {
      (*pcVar17)(0xc000008c,1,0,0,uVar5);
    }
    piVar6 = (int *)*piVar6;
    pCVar4 = PTR_0077241c->heightBlocks;
    iVar14 = *piVar6;
    iVar7 = piVar6[5];
    puVar1 = &pCVar4[1].field_0xc;
    if ((iVar7 < 0) || ((int)pCVar4[1].data <= iVar7)) {
      (*pcVar17)(0xc000008c,1,0,0);
      iVar11 = *(int *)puVar1;
      iVar7 = piVar6[5];
      local_1c = *(int *)(iVar11 + 4);
      if (-1 < iVar7) goto LAB_004ca174;
LAB_004ca17e:
      (*pcVar17)(0xc000008c,1,0,0);
      piVar8 = *(int **)puVar1;
    }
    else {
      iVar11 = *(int *)puVar1;
      local_1c = *(int *)(iVar11 + 4 + iVar7 * 8);
LAB_004ca174:
      if ((int)pCVar4[1].data <= iVar7) goto LAB_004ca17e;
      piVar8 = (int *)(iVar11 + iVar7 * 8);
    }
    iVar7 = *piVar8;
    if (local_1c != 0) {
      piVar8 = (int *)(param_3 + 8);
      if (local_28 < 3) {
        piVar9 = piVar8 + local_28;
      }
      else {
        (*pcVar17)(0xc000008c,1,0,0);
        piVar9 = piVar8;
      }
      puVar10 = (undefined4 *)*piVar9;
      *piVar9 = 0;
      if (puVar10 != (undefined4 *)0x0) {
        LOCK();
        iVar11 = puVar10[1] + -1;
        puVar10[1] = iVar11;
        UNLOCK();
        if (iVar11 == 0) {
          (**(code **)*puVar10)(1);
        }
      }
      ppuVar21 = &local_14;
      pcVar22 = "GetBlockHole";
      FUN_0044d010(ppuVar21,"GetBlockHole");
      FUN_0044d570(ppuVar21,pcVar22);
      local_8 = 0;
      if (local_14 == (undefined4 *)0x0) {
        local_8 = 0xffffffff;
      }
      else {
        if (local_28 < 3) {
          local_14[0xf] = param_4[local_28];
          puVar10 = param_5 + local_28;
        }
        else {
          (*pcVar17)(0xc000008c,1,0,0);
          local_14[0xf] = *param_4;
          (*pcVar17)(0xc000008c,1,0,0);
          puVar10 = param_5;
        }
        local_14[0x10] = *puVar10;
        local_14[4] = param_6;
        local_14[3] = 4;
        local_14[2] = 10;
        local_14[5] = 0xff;
        if ((local_14[4] == 0x15) && (in_ECX->field_0x4 != '\0')) {
          local_14[4] = 0x16;
          in_ECX->field_0x5 = 1;
        }
        local_14[0xe] = 0;
        local_14[0xd] = 0;
        local_14[0xc] = 0;
        local_14[0xb] = 0;
        local_14[10] = 0;
        local_14[9] = 0;
        local_14[8] = 0;
        local_14[7] = 0;
        local_14[6] = 0;
        iVar11 = FUN_006ba810(0x43f);
        if (iVar11 == 0) {
          puVar10 = (undefined4 *)local_14[0x11];
          local_14[0x11] = 0;
        }
        else {
          iVar11 = FUN_0045fae0();
          puVar10 = (undefined4 *)local_14[0x11];
          local_14[0x11] = iVar11;
          if (iVar11 != 0) {
            LOCK();
            *(int *)(iVar11 + 4) = *(int *)(iVar11 + 4) + 1;
            UNLOCK();
          }
        }
        if (puVar10 != (undefined4 *)0x0) {
          LOCK();
          iVar11 = puVar10[1] + -1;
          puVar10[1] = iVar11;
          UNLOCK();
          if (iVar11 == 0) {
            (**(code **)*puVar10)(1);
          }
        }
        this = PTR_0077241c;
        *(int *)&in_ECX->field_0x1314 = *(int *)&in_ECX->field_0x1314 + local_1c / 3;
        FUN_00592f10(this);
        FUN_00592f10(PTR_0077241c);
        FUN_00592f10(PTR_0077241c);
        FUN_00592f10(PTR_0077241c);
        uVar19 = 0;
        if (0 < iVar14) {
          local_20 = 0;
          do {
            if (uVar19 < 0x400) {
              pfVar16 = (float *)(local_20 + (int)in_ECX->vertBufA);
            }
            else {
              (*pcVar17)(0xc000008c,1,0,0);
              pfVar16 = in_ECX->vertBufA;
            }
            FUN_00462b40(uVar19,pfVar16);
            if ((int)uVar19 < piVar6[4]) {
              pbVar12 = (byte *)(piVar6[3] + uVar19);
            }
            else {
              (*pcVar17)(0xc000008c,1,0,0);
              pbVar12 = (byte *)piVar6[3];
            }
            if (DAT_00b9bed4 <= (int)(uint)*pbVar12) {
              (*pcVar17)(0xc000008c,1,0,0);
            }
            if (0x3ff < uVar19) {
              (*pcVar17)(0xc000008c,1,0,0);
            }
            FUN_004cc040(in_ECX);
            uVar19 = uVar19 + 1;
            local_20 = local_20 + 0x24;
          } while ((int)uVar19 < iVar14);
        }
        piVar9 = &in_ECX->vertCount;
        pfVar16 = in_ECX->vertBufA;
        uVar19 = 0;
        *piVar9 = *piVar6;
        puVar2 = in_ECX->idxBufA;
        if (0 < local_1c) {
          iVar14 = iVar7 * 2;
          do {
            iVar11 = iVar7 + uVar19;
            if ((iVar11 < 0) || (*(int *)&pCVar4[1].field_0x4 <= iVar11)) {
              (*pcVar17)(0xc000008c,1,0,0);
              puVar20 = *(ushort **)(pCVar4 + 1);
            }
            else {
              puVar20 = (ushort *)(*(int *)(pCVar4 + 1) + iVar14);
            }
            if (uVar19 < 0x1000) {
              puVar18 = puVar2 + uVar19;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              puVar18 = puVar2;
            }
            uVar19 = uVar19 + 1;
            iVar14 = iVar14 + 2;
            *puVar18 = *puVar20;
            pcVar17 = RaiseException_exref;
          } while ((int)uVar19 < local_1c);
        }
        piVar6 = &in_ECX->idxCount;
        *piVar6 = local_1c;
        if ((param_7 != '\0') && (param_8 != '\0')) {
          FUN_004c9010(1,1,pfVar16,piVar9,puVar2,piVar6);
        }
        if ((param_9 != '\0') && (param_10 != '\0')) {
          FUN_004c9010(1,0,pfVar16,piVar9,puVar2,piVar6);
        }
        if ((param_7 != '\0') && (param_9 != '\0')) {
          FUN_004c9010(0,1,pfVar16,piVar9,puVar2,piVar6);
        }
        if ((param_8 != '\0') && (param_10 != '\0')) {
          FUN_004c9010(0,0,pfVar16,piVar9,puVar2,piVar6);
        }
        if (param_7 == '\0') {
          if (param_8 == '\0') {
            if (param_9 != '\0') goto joined_r0x004ca60d;
            if (param_10 != '\0') goto LAB_004ca619;
          }
          else if (param_9 == '\0') {
joined_r0x004ca60d:
            if (param_10 == '\0') goto LAB_004ca619;
          }
        }
        else {
          if (((param_8 != '\0') || (param_9 != '\0')) || (param_10 != '\0')) goto LAB_004ca621;
LAB_004ca619:
          FUN_004c9d50(in_ECX);
        }
LAB_004ca621:
        iVar14 = *piVar9;
        if (0 < iVar14) {
          uVar19 = 0;
          local_30 = 0;
          do {
            if (uVar19 < 0x400) {
              pfVar15 = (float *)(local_30 + (int)pfVar16);
              *pfVar15 = *(float *)(local_30 + (int)pfVar16) + (float)param_1;
              pfVar15[1] = pfVar15[1] + (float)param_2;
              pfVar15[7] = pfVar15[5];
            }
            else {
              (*pcVar17)(0xc000008c,1,0,0);
              *pfVar16 = *pfVar16 + (float)param_1;
              (*pcVar17)(0xc000008c,1,0,0);
              in_ECX->vertBufA[1] = in_ECX->vertBufA[1] + (float)param_2;
              (*pcVar17)(0xc000008c,1,0,0);
              (*pcVar17)(0xc000008c,1,0,0);
              in_ECX->vertBufA[7] = in_ECX->vertBufA[5];
              (*pcVar17)(0xc000008c,1,0,0);
              (*pcVar17)(0xc000008c,1,0,0);
              pfVar15 = pfVar16;
            }
            uVar19 = uVar19 + 1;
            pfVar15[8] = pfVar15[6];
            local_30 = local_30 + 0x24;
            iVar14 = *piVar9;
          } while ((int)uVar19 < iVar14);
        }
        if ((iVar14 != 0) && (*piVar6 != 0)) {
          FUN_0045fd00(0x2c2,iVar14,pfVar16);
          iVar14 = *piVar6;
          iVar7 = local_14[0x11];
          if ((*(int *)(iVar7 + 0x28) != 0) && (*(char *)(iVar7 + 9) == '\0')) {
            FUN_006ba940();
          }
          iVar11 = iVar14 * 2;
          uVar13 = FUN_006ba810(0xb8);
          DAT_0076a2f0 = DAT_0076a2f0 + iVar11;
          *(int *)(iVar7 + 0x2c) = iVar14;
          *(undefined4 *)(iVar7 + 0x28) = uVar13;
          *(undefined1 *)(iVar7 + 9) = 0;
          if (puVar2 != (ushort *)0x0) {
            FUN_006d2250(uVar13,puVar2,iVar11);
          }
          if (local_28 < 3) {
            piVar8 = piVar8 + local_28;
          }
          else {
            (*pcVar17)(0xc000008c,1,0,0);
          }
          puVar10 = (undefined4 *)*piVar8;
          *piVar8 = (int)local_14;
          if (local_14 != (undefined4 *)0x0) {
            LOCK();
            local_14[1] = local_14[1] + 1;
            UNLOCK();
          }
          if (puVar10 != (undefined4 *)0x0) {
            LOCK();
            iVar14 = puVar10[1] + -1;
            puVar10[1] = iVar14;
            UNLOCK();
            if (iVar14 == 0) {
              (**(code **)*puVar10)(1);
            }
          }
        }
        local_8 = 0xffffffff;
        if (local_14 != (undefined4 *)0x0) {
          LOCK();
          iVar14 = local_14[1] + -1;
          local_14[1] = iVar14;
          UNLOCK();
          if ((iVar14 == 0) && (local_14 != (undefined4 *)0x0)) {
            (**(code **)*local_14)(1);
          }
        }
      }
    }
    local_28 = local_28 + 1;
    if (2 < (int)local_28) {
      ExceptionList = local_10;
      return param_3;
    }
  } while( true );
}

