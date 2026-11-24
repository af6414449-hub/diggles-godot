
void CFogOfWar__RemoveFogLine
               (int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  byte *pbVar6;
  uint *puVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  byte *pbVar16;
  undefined8 uVar17;
  undefined4 uVar18;
  int *local_2c;
  int local_28;
  int local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070616d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca5490) &&
     (FUN_006cebf4(&DAT_00ca5490,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca5490 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca5494 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) =
         "CFogOfWar::RemoveFogLine(int iX0,int iY0,int iY1,int iXSize,int iYSize,int iOwner)";
    *(int *)(&DAT_00773650 + iVar8) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5490);
  }
  iVar8 = DAT_00ca5494;
  uVar18 = *(undefined4 *)(&DAT_00773650 + DAT_00ca5494 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar18;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar3 == 0) {
    uVar17 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar17;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar3 + 1;
  local_20 = param_1 - param_4;
  local_8 = 0;
  iVar3 = *(int *)(DAT_0077241c + 0x94) + 0x20;
  if (((((iVar3 <= (int)local_20) &&
        (local_28 = *(int *)(DAT_0077241c + 0x9c) + -0x20, (int)local_20 < local_28)) &&
       (local_24 = *(int *)(DAT_0077241c + 0x98) + 0x20, local_24 <= param_2)) &&
      ((iVar8 = *(int *)(DAT_0077241c + 0xa0) + -0x20, param_2 < iVar8 &&
       (local_1c = param_1 + param_4, iVar3 <= local_1c)))) &&
     ((local_1c < local_28 && ((local_24 <= param_3 && (param_3 < iVar8)))))) {
    piVar9 = (int *)(DAT_00772400 + 0xa328);
    if (param_6 < 8) {
      piVar9 = (int *)(param_6 * 0x10 + DAT_00772400 + 0xa328);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*(char *)(DAT_00772400 + 0x8c) == '\0') {
      iVar8 = (int)((param_2 - param_5) + (param_2 - param_5 >> 0x1f & 7U)) >> 3;
      iVar3 = piVar9[1];
      if (iVar8 <= piVar9[1]) {
        iVar3 = iVar8;
      }
      piVar9[1] = iVar3;
      iVar8 = (int)(local_20 + ((int)local_20 >> 0x1f & 7U)) >> 3;
      iVar3 = *piVar9;
      if (iVar8 <= *piVar9) {
        iVar3 = iVar8;
      }
      *piVar9 = iVar3;
      iVar8 = (int)(param_3 + param_5 + (param_3 + param_5 >> 0x1f & 7U)) >> 3;
      iVar3 = piVar9[3];
      if (piVar9[3] <= iVar8) {
        iVar3 = iVar8;
      }
      piVar9[3] = iVar3;
      iVar8 = (int)(local_1c + (local_1c >> 0x1f & 7U)) >> 3;
      iVar3 = piVar9[2];
      if (piVar9[2] <= iVar8) {
        iVar3 = iVar8;
      }
      piVar9[2] = iVar3;
    }
    uVar14 = param_3 + 4U & 0xfffffff8;
    local_20 = *local_14;
    uVar10 = param_1 + 4U & 0xfffffff8;
    uVar4 = param_2 + 4U & 0xfffffff8;
    local_18 = uVar10;
    if ((int)uVar4 < (int)uVar14) {
      local_28 = uVar10 + param_4;
      local_24 = uVar10 - param_4;
      do {
        param_2 = 0;
        uVar13 = uVar10;
        if ((int)uVar10 < local_28) {
          iVar3 = (int)(uVar4 + ((int)uVar4 >> 0x1f & 7U)) >> 3;
          do {
            iVar8 = DAT_0077241c;
            local_1c = (int)(((int)uVar10 >> 0x1f & 7U) + uVar10) >> 3;
            iVar15 = *(int *)(DAT_0077241c + 0x84);
            if (*(int *)(DAT_0077241c + 0x84) <= local_1c) {
              iVar15 = local_1c;
            }
            iVar12 = *(int *)(DAT_0077241c + 0x88);
            if (*(int *)(DAT_0077241c + 0x88) <= iVar3) {
              iVar12 = iVar3;
            }
            iVar11 = *(int *)(DAT_0077241c + 0x90) + -1;
            if (iVar12 < *(int *)(DAT_0077241c + 0x90)) {
              iVar11 = iVar12;
            }
            iVar12 = *(int *)(DAT_0077241c + 0x8c) + -1;
            if (iVar15 < *(int *)(DAT_0077241c + 0x8c)) {
              iVar12 = iVar15;
            }
            iVar15 = (iVar11 * *(int *)(DAT_0077241c + 0x44) + iVar12) %
                     *(int *)(DAT_0077241c + 0x4c);
            if ((iVar15 < 0) || (*(int *)(DAT_0077241c + 0x18) <= iVar15)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar9 = *(int **)(iVar8 + 0x14);
            }
            else {
              piVar9 = (int *)(iVar15 * 0x7c + *(int *)(DAT_0077241c + 0x14));
            }
            iVar8 = *piVar9;
            piVar5 = (int *)(*(int *)(DAT_0077241c + 0x24) + 0x10);
            local_2c = piVar9;
            if ((iVar8 < 0) || (*(int *)(*(int *)(DAT_0077241c + 0x24) + 0x14) <= iVar8)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar16 = (byte *)*piVar5;
            }
            else {
              pbVar16 = (byte *)(iVar8 * 0x59 + *piVar5);
            }
            if (param_2 == 0) {
              if (0xe < (*pbVar16 & 0xf)) {
                param_2 = 1;
              }
            }
            else {
              uVar13 = local_18;
              if (param_2 == 3) break;
              param_2 = param_2 + 1;
            }
            pbVar16 = (byte *)(piVar9 + 0xd);
            if (param_6 < 8) {
              pbVar6 = pbVar16 + param_6;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar6 = pbVar16;
            }
            bVar1 = *pbVar6;
            if (bVar1 != 0xff) {
              if (bVar1 < 2) {
                if (bVar1 == 0) {
                  FUN_0057dfc0(&local_2c,local_1c,iVar3,param_6);
                }
                if (param_6 < 8) {
                  puVar7 = local_14 + param_6;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar7 = local_14;
                }
                if ((int)(puVar7[3] * 8) <= (int)uVar4) {
                  if (param_6 < 8) {
                    puVar7 = local_14 + param_6 * 2;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    puVar7 = local_14;
                  }
                  FUN_005813a0(1);
                  uVar13 = puVar7[0xb];
                  uVar2 = puVar7[0xc];
                  *(int *)((uVar13 - 8) + uVar2 * 8) = local_1c;
                  *(int *)((uVar13 - 4) + uVar2 * 8) = iVar3;
                }
              }
              if ((local_20 == param_6) && (bVar1 < 0xe3)) {
                iVar11 = uVar10 + 8;
                uVar18 = 0x50;
                iVar8 = uVar10 - 8;
                iVar15 = uVar4 + 8;
                iVar12 = uVar4 - 8;
                FUN_005a3dd0(iVar8,iVar12,iVar11,iVar15,0x50);
                FUN_005a3fd0(iVar8,iVar12,iVar11,iVar15,uVar18);
              }
              if (param_6 < 8) {
                pbVar16 = pbVar16 + param_6;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              *pbVar16 = 0xff;
            }
            uVar10 = uVar10 + 8;
            uVar13 = local_18;
          } while ((int)uVar10 < local_28);
        }
        param_2 = 0;
        uVar10 = uVar13;
        if (local_24 < (int)uVar13) {
          iVar3 = (int)(uVar4 + ((int)uVar4 >> 0x1f & 7U)) >> 3;
          do {
            iVar8 = DAT_0077241c;
            local_1c = (int)(((int)uVar13 >> 0x1f & 7U) + uVar13) >> 3;
            iVar15 = *(int *)(DAT_0077241c + 0x84);
            if (*(int *)(DAT_0077241c + 0x84) <= local_1c) {
              iVar15 = local_1c;
            }
            iVar12 = *(int *)(DAT_0077241c + 0x88);
            if (*(int *)(DAT_0077241c + 0x88) <= iVar3) {
              iVar12 = iVar3;
            }
            iVar11 = *(int *)(DAT_0077241c + 0x90) + -1;
            if (iVar12 < *(int *)(DAT_0077241c + 0x90)) {
              iVar11 = iVar12;
            }
            iVar12 = *(int *)(DAT_0077241c + 0x8c) + -1;
            if (iVar15 < *(int *)(DAT_0077241c + 0x8c)) {
              iVar12 = iVar15;
            }
            iVar15 = (iVar11 * *(int *)(DAT_0077241c + 0x44) + iVar12) %
                     *(int *)(DAT_0077241c + 0x4c);
            if ((iVar15 < 0) || (*(int *)(DAT_0077241c + 0x18) <= iVar15)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar9 = *(int **)(iVar8 + 0x14);
            }
            else {
              piVar9 = (int *)(iVar15 * 0x7c + *(int *)(DAT_0077241c + 0x14));
            }
            iVar8 = *piVar9;
            piVar5 = (int *)(*(int *)(DAT_0077241c + 0x24) + 0x10);
            local_2c = piVar9;
            if ((iVar8 < 0) || (*(int *)(*(int *)(DAT_0077241c + 0x24) + 0x14) <= iVar8)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar16 = (byte *)*piVar5;
            }
            else {
              pbVar16 = (byte *)(iVar8 * 0x59 + *piVar5);
            }
            if (param_2 == 0) {
              if (0xe < (*pbVar16 & 0xf)) {
                param_2 = 1;
              }
            }
            else {
              uVar10 = local_18;
              if (param_2 == 3) break;
              param_2 = param_2 + 1;
            }
            pbVar16 = (byte *)(piVar9 + 0xd);
            if (param_6 < 8) {
              pbVar6 = pbVar16 + param_6;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar6 = pbVar16;
            }
            bVar1 = *pbVar6;
            if (bVar1 != 0xff) {
              if (bVar1 < 2) {
                if (bVar1 == 0) {
                  FUN_0057dfc0(&local_2c,local_1c,iVar3,param_6);
                }
                if (param_6 < 8) {
                  puVar7 = local_14 + param_6;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar7 = local_14;
                }
                if ((int)(puVar7[3] * 8) <= (int)uVar4) {
                  if (param_6 < 8) {
                    puVar7 = local_14 + param_6 * 2;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    puVar7 = local_14;
                  }
                  FUN_005813a0(1);
                  uVar10 = puVar7[0xb];
                  uVar2 = puVar7[0xc];
                  *(int *)((uVar10 - 8) + uVar2 * 8) = local_1c;
                  *(int *)((uVar10 - 4) + uVar2 * 8) = iVar3;
                }
              }
              if ((local_20 == param_6) && (bVar1 < 0xe3)) {
                iVar11 = uVar13 + 8;
                uVar18 = 0x50;
                iVar8 = uVar13 - 8;
                iVar15 = uVar4 + 8;
                iVar12 = uVar4 - 8;
                FUN_005a3dd0(iVar8,iVar12,iVar11,iVar15,0x50);
                FUN_005a3fd0(iVar8,iVar12,iVar11,iVar15,uVar18);
              }
              if (param_6 < 8) {
                pbVar16 = pbVar16 + param_6;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              *pbVar16 = 0xff;
            }
            uVar13 = uVar13 - 8;
            uVar10 = local_18;
          } while (local_24 < (int)uVar13);
        }
        uVar4 = uVar4 + 8;
      } while ((int)uVar4 < (int)uVar14);
    }
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

