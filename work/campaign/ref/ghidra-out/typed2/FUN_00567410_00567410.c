
/* WARNING: Removing unreachable block (ram,0x0056779d) */
/* WARNING: Removing unreachable block (ram,0x0056757a) */
/* WARNING: Removing unreachable block (ram,0x00567587) */
/* WARNING: Removing unreachable block (ram,0x0056758b) */
/* WARNING: Removing unreachable block (ram,0x005675a1) */
/* WARNING: Removing unreachable block (ram,0x005675bb) */
/* WARNING: Removing unreachable block (ram,0x005675c7) */
/* WARNING: Removing unreachable block (ram,0x005675d3) */
/* WARNING: Removing unreachable block (ram,0x005675df) */
/* WARNING: Removing unreachable block (ram,0x005675e5) */
/* WARNING: Removing unreachable block (ram,0x005675e9) */
/* WARNING: Removing unreachable block (ram,0x005675f1) */
/* WARNING: Removing unreachable block (ram,0x005675f5) */
/* WARNING: Removing unreachable block (ram,0x005675fd) */
/* WARNING: Removing unreachable block (ram,0x00567601) */
/* WARNING: Removing unreachable block (ram,0x00567609) */
/* WARNING: Removing unreachable block (ram,0x0056760d) */
/* WARNING: Removing unreachable block (ram,0x00567625) */
/* WARNING: Removing unreachable block (ram,0x00567735) */
/* WARNING: Removing unreachable block (ram,0x0056773e) */
/* WARNING: Removing unreachable block (ram,0x00567631) */
/* WARNING: Removing unreachable block (ram,0x00567655) */
/* WARNING: Removing unreachable block (ram,0x0056766c) */
/* WARNING: Removing unreachable block (ram,0x00567690) */
/* WARNING: Removing unreachable block (ram,0x005676a7) */
/* WARNING: Removing unreachable block (ram,0x005676cb) */
/* WARNING: Removing unreachable block (ram,0x005676e2) */
/* WARNING: Removing unreachable block (ram,0x00567709) */
/* WARNING: Removing unreachable block (ram,0x00567720) */
/* WARNING: Removing unreachable block (ram,0x00567741) */
/* WARNING: Removing unreachable block (ram,0x0056774c) */
/* WARNING: Removing unreachable block (ram,0x00567582) */
/* WARNING: Removing unreachable block (ram,0x005677b3) */
/* WARNING: Removing unreachable block (ram,0x005677bc) */
/* WARNING: Removing unreachable block (ram,0x005677d1) */
/* WARNING: Removing unreachable block (ram,0x005677f3) */
/* WARNING: Removing unreachable block (ram,0x0056780e) */
/* WARNING: Removing unreachable block (ram,0x00567818) */
/* WARNING: Removing unreachable block (ram,0x00567833) */
/* WARNING: Removing unreachable block (ram,0x00567840) */
/* WARNING: Removing unreachable block (ram,0x00567861) */
/* WARNING: Removing unreachable block (ram,0x00567868) */
/* WARNING: Removing unreachable block (ram,0x0056786e) */
/* WARNING: Removing unreachable block (ram,0x00567875) */
/* WARNING: Removing unreachable block (ram,0x0056787b) */
/* WARNING: Removing unreachable block (ram,0x00567883) */
/* WARNING: Removing unreachable block (ram,0x0056788b) */
/* WARNING: Removing unreachable block (ram,0x005678bb) */
/* WARNING: Removing unreachable block (ram,0x005678c4) */
/* WARNING: Removing unreachable block (ram,0x005678ce) */
/* WARNING: Removing unreachable block (ram,0x005678d9) */
/* WARNING: Removing unreachable block (ram,0x005678f0) */
/* WARNING: Removing unreachable block (ram,0x005678f9) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00567410(float *param_1)

{
  CMap *pCVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  CMapCell *pCVar10;
  byte bVar11;
  int in_ECX;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  undefined4 uVar20;
  int local_44;
  int local_38;
  int local_28;
  CMap *local_24;
  void *local_1c;
  undefined1 *puStack_18;
  undefined4 local_14;
  
  local_14 = 0xffffffff;
  puStack_18 = &LAB_00705bfd;
  local_1c = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffff0;
  ExceptionList = &local_1c;
  local_24 = PTR_0077241c;
  iVar3 = (int)*param_1;
  iVar15 = (int)param_1[1];
  if ((((PTR_0077241c->cellX0 <= iVar3) && (iVar3 < PTR_0077241c->cellX1)) &&
      (PTR_0077241c->cellY0 <= iVar15)) && (iVar15 < PTR_0077241c->cellY1)) {
    iVar4 = FUN_00592f10(PTR_0077241c);
    if ((*(uint *)(iVar4 + 8) >> ((byte)(*(int *)(in_ECX + 0x11c) << 2) & 0x1f) & 8) != 0) {
      iVar4 = iVar3;
      iVar5 = iVar15;
      FUN_0058a820(iVar3,iVar15);
      FUN_0058ec00(iVar4,iVar5);
      FUN_00592f10(PTR_0077241c);
      local_14 = 0;
      FUN_0041fb80(1);
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar5 = iVar3 << 3;
      iVar6 = iVar15 << 3;
      iVar4 = iVar15 * 8;
      iVar7 = iVar3 << 3;
      uVar20 = 0x40;
      iRamfffffff8 = iVar3;
      iRamfffffffc = iVar15;
      FUN_005a3dd0(iVar15,iVar5,iVar4,iVar7,iVar6,0x40);
      FUN_005a3fd0(iVar5,iVar4,iVar7,iVar6,uVar20);
      ExceptionList = local_1c;
      return;
    }
    local_24 = PTR_0077241c;
  }
  PTR_0077241c = local_24;
  if (*(int *)(in_ECX + 0xa4) + 2 < *(int *)(in_ECX + 0xa0)) {
    *(float *)(in_ECX + 0xa8) = *param_1;
    *(float *)(in_ECX + 0xac) = param_1[1];
    *(float *)(in_ECX + 0xb0) = param_1[2];
  }
  fVar19 = *param_1;
  fVar18 = fVar19 - *(float *)(in_ECX + 0xa8);
  fVar17 = param_1[2] - *(float *)(in_ECX + 0xb0);
  fVar16 = param_1[1] - *(float *)(in_ECX + 0xac);
  fVar16 = fVar16 * fVar16 + fVar18 * fVar18 + fVar17 * fVar17;
  FUN_0040b7e0(uVar2);
  local_44 = 0;
  iVar4 = (int)fVar16 + 1;
  if (-1 < iVar4) {
    iVar5 = iVar3 * 8 + -0x20;
    iVar6 = iVar15 * 8 + 0x20;
    iVar15 = iVar15 * 8 + -0x20;
    iVar3 = iVar3 * 8 + 0x20;
    while( true ) {
      fVar19 = (float)local_44 / (float)iVar4;
      iVar12 = (int)(*(float *)(in_ECX + 0xa8) * (1.0 - fVar19) + *param_1 * fVar19);
      iVar8 = (int)(param_1[1] * fVar19 + (1.0 - fVar19) * *(float *)(in_ECX + 0xac));
      iVar7 = local_24->cellX0;
      iVar13 = local_24->cellY0;
      local_38 = iVar7;
      if (iVar7 <= iVar12) {
        local_38 = iVar12;
      }
      iVar14 = local_24->cellX1;
      local_28 = iVar13;
      if (iVar13 <= iVar8) {
        local_28 = iVar8;
      }
      if (iVar14 <= local_38) {
        local_38 = iVar14 + -1;
      }
      iVar9 = local_24->cellY1;
      if (iVar9 <= local_28) {
        local_28 = iVar9 + -1;
      }
      if (iVar7 <= iVar12 + 2) {
        iVar7 = iVar12 + 2;
      }
      if (iVar13 <= iVar8 + 2) {
        iVar13 = iVar8 + 2;
      }
      if (iVar14 <= iVar7) {
        iVar7 = iVar14 + -1;
      }
      pCVar1 = local_24;
      if (iVar9 <= iVar13) {
        iVar13 = iVar9 + -1;
      }
      for (; iVar8 = local_38, local_28 < iVar13; local_28 = local_28 + 1) {
        for (; iVar8 < iVar7; iVar8 = iVar8 + 1) {
          iVar12 = pCVar1->cellX0;
          if (pCVar1->cellX0 <= iVar8) {
            iVar12 = iVar8;
          }
          iVar14 = local_24->cellY0;
          if (local_24->cellY0 <= local_28) {
            iVar14 = local_28;
          }
          iVar9 = local_24->cellY1 + -1;
          if (iVar14 < local_24->cellY1) {
            iVar9 = iVar14;
          }
          iVar14 = pCVar1->cellX1 + -1;
          if (iVar12 < pCVar1->cellX1) {
            iVar14 = iVar12;
          }
          iVar12 = (iVar9 * local_24->mapWidth + iVar14) % local_24->cellCountTotal;
          if ((iVar12 < 0) || (local_24->cellCount <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar10 = local_24->cells;
            local_24 = PTR_0077241c;
          }
          else {
            pCVar10 = local_24->cells + iVar12;
          }
          uVar2 = pCVar10->digMarks;
          bVar11 = (byte)(*(int *)(in_ECX + 0x11c) << 2);
          if ((uVar2 >> (bVar11 & 0x1f) & 8) == 0) {
            iVar12 = local_24->cellX0;
            if (local_24->cellX0 <= iVar8) {
              iVar12 = iVar8;
            }
            iVar14 = local_24->cellY0;
            if (local_24->cellY0 <= local_28) {
              iVar14 = local_28;
            }
            iVar9 = local_24->cellY1 + -1;
            if (iVar14 < local_24->cellY1) {
              iVar9 = iVar14;
            }
            iVar14 = local_24->cellX1 + -1;
            if (iVar12 < local_24->cellX1) {
              iVar14 = iVar12;
            }
            iVar12 = (iVar9 * local_24->mapWidth + iVar14) % local_24->cellCountTotal;
            if ((iVar12 < 0) || (local_24->cellCount <= iVar12)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar10 = local_24->cells;
              local_24 = PTR_0077241c;
            }
            else {
              pCVar10 = local_24->cells + iVar12;
            }
            pCVar10->digMarks = uVar2 & ~(0xf << (bVar11 & 0x1f));
          }
          pCVar1 = local_24;
        }
      }
      uVar20 = 0x40;
      iVar7 = iVar5;
      iVar13 = iVar15;
      iVar8 = iVar3;
      iVar12 = iVar6;
      FUN_005a3dd0(local_28,iVar5,iVar15,iVar3,iVar6,0x40);
      FUN_005a3fd0(iVar7,iVar13,iVar8,iVar12,uVar20);
      local_44 = local_44 + 1;
      if (iVar4 < local_44) break;
      local_24 = PTR_0077241c;
    }
    fVar19 = *param_1;
  }
  *(float *)(in_ECX + 0xa8) = fVar19;
  *(float *)(in_ECX + 0xac) = param_1[1];
  *(float *)(in_ECX + 0xb0) = param_1[2];
  *(undefined4 *)(in_ECX + 0xa4) = *(undefined4 *)(in_ECX + 0xa0);
  ExceptionList = local_1c;
  return;
}

