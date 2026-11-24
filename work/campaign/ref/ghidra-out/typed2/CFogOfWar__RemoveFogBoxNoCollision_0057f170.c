
void CFogOfWar__RemoveFogBoxNoCollision
               (int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  byte bVar1;
  uint uVar2;
  CMap *pCVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uchar *puVar9;
  uint *puVar10;
  int *piVar11;
  CMapCell *pCVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uchar *puVar16;
  undefined8 uVar17;
  int iVar18;
  int iVar19;
  undefined4 uVar20;
  CMapCell *local_24;
  CMapCell *local_20;
  int local_1c;
  int local_18;
  uint *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070619d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca5498) &&
     (FUN_006cebf4(&DAT_00ca5498,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca5498 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca549c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) =
         "CFogOfWar::RemoveFogBoxNoCollision(int iX0,int iY0,int iXSize,int iYSize,int iOwner)";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5498);
  }
  local_20 = (CMapCell *)(DAT_00ca549c * 0x40);
  uVar20 = *(undefined4 *)(&DAT_00773650 + (int)local_20);
  iVar4 = FUN_0043fcc0();
  pCVar12 = local_20;
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar20;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = *(int *)((int)&DAT_00773654 + (int)local_20);
  if (iVar4 == 0) {
    uVar17 = FUN_006bd180();
    iVar4 = *(int *)((int)&DAT_00773654 + (int)pCVar12);
    *(undefined8 *)((int)&DAT_00773658 + (int)pCVar12) = uVar17;
  }
  *(int *)((int)&DAT_00773654 + (int)pCVar12) = iVar4 + 1;
  iVar7 = DAT_00772400;
  uVar5 = param_2 + 4U & 0xfffffff8;
  local_8 = 0;
  uVar13 = param_1 + 4U & 0xfffffff8;
  iVar15 = uVar13 - param_3;
  iVar4 = uVar5 + param_4;
  param_4 = uVar5 - param_4;
  param_3 = param_3 + uVar13;
  local_1c = PTR_0077241c->x0_8 + 0x10;
  if (local_1c <= iVar15) {
    local_1c = iVar15;
  }
  iVar15 = PTR_0077241c->y0_8 + 0x10;
  if (iVar15 <= param_4) {
    iVar15 = param_4;
  }
  iVar6 = PTR_0077241c->x1_8 + -0x10;
  if (param_3 <= iVar6) {
    iVar6 = param_3;
  }
  local_18 = PTR_0077241c->y1_8 + -0x10;
  if (iVar4 <= local_18) {
    local_18 = iVar4;
  }
  if (*(char *)(DAT_00772400 + 0x8c) == '\0') {
    if (param_5 < 8) {
      piVar11 = (int *)(param_5 * 0x10 + DAT_00772400 + 0xa328);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar11 = (int *)(iVar7 + 0xa328);
    }
    iVar7 = (int)(iVar15 + (iVar15 >> 0x1f & 7U)) >> 3;
    iVar4 = piVar11[1];
    if (iVar7 <= piVar11[1]) {
      iVar4 = iVar7;
    }
    piVar11[1] = iVar4;
    iVar7 = (int)(local_1c + (local_1c >> 0x1f & 7U)) >> 3;
    iVar4 = *piVar11;
    if (iVar7 <= *piVar11) {
      iVar4 = iVar7;
    }
    *piVar11 = iVar4;
    iVar7 = (int)(local_18 + (local_18 >> 0x1f & 7U)) >> 3;
    iVar4 = piVar11[3];
    if (piVar11[3] <= iVar7) {
      iVar4 = iVar7;
    }
    piVar11[3] = iVar4;
    iVar7 = (int)(iVar6 + (iVar6 >> 0x1f & 7U)) >> 3;
    iVar4 = piVar11[2];
    if (piVar11[2] <= iVar7) {
      iVar4 = iVar7;
    }
    piVar11[2] = iVar4;
  }
  uVar5 = *local_14;
  if (iVar15 < local_18) {
    do {
      if (local_1c < iVar6) {
        iVar7 = (int)(iVar15 + (iVar15 >> 0x1f & 7U)) >> 3;
        iVar4 = local_1c;
        do {
          pCVar3 = PTR_0077241c;
          local_20 = (CMapCell *)((int)((iVar4 >> 0x1f & 7U) + iVar4) >> 3);
          local_24 = (CMapCell *)PTR_0077241c->cellX0;
          if (PTR_0077241c->cellX0 <= (int)local_20) {
            local_24 = local_20;
          }
          iVar14 = PTR_0077241c->cellY0;
          if (PTR_0077241c->cellY0 <= iVar7) {
            iVar14 = iVar7;
          }
          iVar8 = PTR_0077241c->cellY1 + -1;
          if (iVar14 < PTR_0077241c->cellY1) {
            iVar8 = iVar14;
          }
          pCVar12 = (CMapCell *)(PTR_0077241c->cellX1 + -1);
          if ((int)local_24 < PTR_0077241c->cellX1) {
            pCVar12 = local_24;
          }
          iVar14 = (int)(pCVar12->ownerIndex + iVar8 * PTR_0077241c->mapWidth + -0x34) %
                   PTR_0077241c->cellCountTotal;
          if ((iVar14 < 0) || (PTR_0077241c->cellCount <= iVar14)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_24 = pCVar3->cells;
          }
          else {
            local_24 = PTR_0077241c->cells + iVar14;
          }
          puVar16 = local_24->ownerIndex;
          if (param_5 < 8) {
            puVar9 = puVar16 + param_5;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar9 = puVar16;
          }
          bVar1 = *puVar9;
          if (bVar1 != 0xff) {
            if (bVar1 < 2) {
              if (bVar1 == 0) {
                FUN_0057dfc0(&local_24,local_20,iVar7,param_5);
              }
              if (param_5 < 8) {
                puVar10 = local_14 + param_5;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                puVar10 = local_14;
              }
              if ((int)(puVar10[3] * 8) <= iVar15) {
                if (param_5 < 8) {
                  puVar10 = local_14 + param_5 * 2;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar10 = local_14;
                }
                FUN_005813a0(1);
                uVar13 = puVar10[0xb];
                uVar2 = puVar10[0xc];
                *(CMapCell **)((uVar13 - 8) + uVar2 * 8) = local_20;
                *(int *)((uVar13 - 4) + uVar2 * 8) = iVar7;
              }
            }
            if ((uVar5 == param_5) && (bVar1 < 0xe3)) {
              uVar20 = 0x50;
              iVar14 = iVar4 + -8;
              iVar8 = iVar15 + 8;
              iVar18 = iVar15 + -8;
              iVar19 = iVar4 + 8;
              FUN_005a3dd0(iVar14,iVar18,iVar19,iVar8,0x50);
              FUN_005a3fd0(iVar14,iVar18,iVar19,iVar8,uVar20);
            }
            if (param_5 < 8) {
              puVar16 = puVar16 + param_5;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *puVar16 = 0xff;
          }
          iVar4 = iVar4 + 8;
        } while (iVar4 < iVar6);
      }
      iVar15 = iVar15 + 8;
    } while (iVar15 < local_18);
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

