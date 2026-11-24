
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00598f10(void)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  CMapCell *pCVar4;
  int iVar5;
  CMap *pCVar6;
  int iVar7;
  uint uVar8;
  code *pcVar9;
  bool bVar10;
  bool bVar11;
  uint *local_18;
  int local_10;
  uint local_c;
  CMap *local_8;
  
  local_8 = PTR_0077241c;
  iVar5 = PTR_0077241c->cellY0;
  pCVar6 = PTR_0077241c;
  pcVar9 = RaiseException_exref;
  if (iVar5 < PTR_0077241c->cellY1) {
    do {
      local_10 = pCVar6->cellX0;
      if (local_10 < pCVar6->cellX1) {
        do {
          if (0x26f < (int)DAT_00768350) {
            if (DAT_00768350 == 0x271) {
              FUN_004454d0(0x1105);
            }
            local_c = 0;
            local_8 = (CMap *)&DAT_00767990;
            do {
              local_18 = (uint *)local_8;
              if (0x26f < local_c) {
                (*pcVar9)(0xc000008c,1,0,0);
                local_18 = &DAT_00767990;
              }
              if (local_c + 1 < 0x270) {
                puVar2 = (uint *)((int)local_8 + 4);
              }
              else {
                (*pcVar9)(0xc000008c,1,0,0);
                puVar2 = &DAT_00767990;
              }
              uVar8 = (*puVar2 ^ *local_18) & 0x7fffffff ^ *local_18;
              if (local_c + 0x18d < 0x270) {
                local_18 = (uint *)((int)local_8 + 0x634);
              }
              else {
                (*pcVar9)(0xc000008c,1,0,0);
                local_18 = &DAT_00767990;
              }
              pCVar6 = local_8;
              if (0x26f < local_c) {
                (*pcVar9)(0xc000008c,1,0,0);
                pCVar6 = (CMap *)&DAT_00767990;
              }
              local_8 = (CMap *)((int)local_8 + 4);
              *(uint *)pCVar6 = uVar8 >> 1 ^ *(uint *)(&DAT_00724484 + (uVar8 & 1) * 4) ^ *local_18;
              local_c = local_c + 1;
            } while ((int)local_c < 0xe3);
            local_c = 0xe3;
            bVar10 = true;
            bVar11 = false;
            local_8 = (CMap *)&DAT_00767d1c;
            do {
              local_18 = (uint *)local_8;
              if (!bVar10 && !bVar11) {
                (*pcVar9)(0xc000008c,1,0,0);
                local_18 = &DAT_00767990;
              }
              if (local_c + 1 < 0x270) {
                puVar2 = (uint *)((int)local_8 + 4);
              }
              else {
                (*pcVar9)(0xc000008c,1,0,0);
                puVar2 = &DAT_00767990;
              }
              uVar8 = (*puVar2 ^ *local_18) & 0x7fffffff ^ *local_18;
              if (local_c - 0xe3 < 0x270) {
                local_18 = (uint *)((int)local_8 + -0x38c);
              }
              else {
                (*pcVar9)(0xc000008c,1,0,0);
                local_18 = &DAT_00767990;
              }
              pCVar6 = local_8;
              if (0x26f < local_c) {
                (*pcVar9)(0xc000008c,1,0,0);
                pCVar6 = (CMap *)&DAT_00767990;
              }
              local_8 = (CMap *)((int)local_8 + 4);
              *(uint *)pCVar6 = uVar8 >> 1 ^ *(uint *)(&DAT_00724484 + (uVar8 & 1) * 4) ^ *local_18;
              local_c = local_c + 1;
              bVar10 = local_c < 0x26f;
              bVar11 = local_c == 0x26f;
            } while ((int)local_c < 0x26f);
            uVar8 = (DAT_0076834c ^ DAT_00767990) & 0x7fffffff ^ DAT_0076834c;
            local_8 = PTR_0077241c;
            DAT_0076834c = uVar8 >> 1 ^ *(uint *)(&DAT_00724484 + (uVar8 & 1) * 4) ^ _DAT_00767fc0;
            DAT_00768350 = 0;
            pCVar6 = PTR_0077241c;
          }
          if (DAT_00768350 < 0x270) {
            puVar2 = &DAT_00767990 + DAT_00768350;
            DAT_00768350 = DAT_00768350 + 1;
          }
          else {
            DAT_00768350 = DAT_00768350 + 1;
            (*pcVar9)(0xc000008c,1,0,0);
            puVar2 = &DAT_00767990;
            local_8 = PTR_0077241c;
            pCVar6 = PTR_0077241c;
          }
          pcVar9 = RaiseException_exref;
          uVar8 = *puVar2 ^ *puVar2 >> 0xb;
          uVar8 = uVar8 ^ (uVar8 & 0xff3a58ad) << 7;
          uVar8 = uVar8 ^ (uVar8 & 0xffffdf8c) << 0xf;
          iVar7 = pCVar6->cellX0;
          if (pCVar6->cellX0 <= local_10) {
            iVar7 = local_10;
          }
          iVar3 = local_8->cellY0;
          if (local_8->cellY0 <= iVar5) {
            iVar3 = iVar5;
          }
          iVar1 = local_8->cellY1 + -1;
          if (iVar3 < local_8->cellY1) {
            iVar1 = iVar3;
          }
          iVar3 = pCVar6->cellX1 + -1;
          if (iVar7 < pCVar6->cellX1) {
            iVar3 = iVar7;
          }
          iVar7 = (iVar1 * local_8->mapWidth + iVar3) % local_8->cellCountTotal;
          if ((iVar7 < 0) || (local_8->cellCount <= iVar7)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar4 = local_8->cells;
            local_8 = PTR_0077241c;
          }
          else {
            pCVar4 = local_8->cells + iVar7;
          }
          pCVar4->material = (ushort)((uVar8 >> 0x12 ^ uVar8) << 8) | 2;
          local_10 = local_10 + 1;
          pCVar6 = local_8;
        } while (local_10 < local_8->cellX1);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < pCVar6->cellY1);
  }
  return;
}

