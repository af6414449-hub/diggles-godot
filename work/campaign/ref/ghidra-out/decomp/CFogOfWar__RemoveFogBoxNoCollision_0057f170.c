
void CFogOfWar__RemoveFogBoxNoCollision
               (int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  uint *puVar9;
  int *piVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  byte *pbVar14;
  undefined8 uVar15;
  int iVar16;
  int iVar17;
  undefined4 uVar18;
  int local_24;
  int local_20;
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
     (FUN_006cebf4(&DAT_00ca5498,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca5498 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca549c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) =
         "CFogOfWar::RemoveFogBoxNoCollision(int iX0,int iY0,int iXSize,int iYSize,int iOwner)";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5498);
  }
  local_20 = DAT_00ca549c * 0x40;
  uVar18 = *(undefined4 *)(&DAT_00773650 + local_20);
  iVar3 = FUN_0043fcc0();
  iVar6 = local_20;
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar18;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = *(int *)((int)&DAT_00773654 + local_20);
  if (iVar3 == 0) {
    uVar15 = FUN_006bd180();
    iVar3 = *(int *)((int)&DAT_00773654 + iVar6);
    *(undefined8 *)((int)&DAT_00773658 + iVar6) = uVar15;
  }
  *(int *)((int)&DAT_00773654 + iVar6) = iVar3 + 1;
  iVar6 = DAT_00772400;
  uVar4 = param_2 + 4U & 0xfffffff8;
  local_8 = 0;
  uVar11 = param_1 + 4U & 0xfffffff8;
  iVar13 = uVar11 - param_3;
  iVar3 = uVar4 + param_4;
  param_4 = uVar4 - param_4;
  param_3 = param_3 + uVar11;
  local_1c = *(int *)(DAT_0077241c + 0x94) + 0x10;
  if (local_1c <= iVar13) {
    local_1c = iVar13;
  }
  iVar13 = *(int *)(DAT_0077241c + 0x98) + 0x10;
  if (iVar13 <= param_4) {
    iVar13 = param_4;
  }
  iVar5 = *(int *)(DAT_0077241c + 0x9c) + -0x10;
  if (param_3 <= iVar5) {
    iVar5 = param_3;
  }
  local_18 = *(int *)(DAT_0077241c + 0xa0) + -0x10;
  if (iVar3 <= local_18) {
    local_18 = iVar3;
  }
  if (*(char *)(DAT_00772400 + 0x8c) == '\0') {
    if (param_5 < 8) {
      piVar10 = (int *)(param_5 * 0x10 + DAT_00772400 + 0xa328);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar10 = (int *)(iVar6 + 0xa328);
    }
    iVar6 = (int)(iVar13 + (iVar13 >> 0x1f & 7U)) >> 3;
    iVar3 = piVar10[1];
    if (iVar6 <= piVar10[1]) {
      iVar3 = iVar6;
    }
    piVar10[1] = iVar3;
    iVar6 = (int)(local_1c + (local_1c >> 0x1f & 7U)) >> 3;
    iVar3 = *piVar10;
    if (iVar6 <= *piVar10) {
      iVar3 = iVar6;
    }
    *piVar10 = iVar3;
    iVar6 = (int)(local_18 + (local_18 >> 0x1f & 7U)) >> 3;
    iVar3 = piVar10[3];
    if (piVar10[3] <= iVar6) {
      iVar3 = iVar6;
    }
    piVar10[3] = iVar3;
    iVar6 = (int)(iVar5 + (iVar5 >> 0x1f & 7U)) >> 3;
    iVar3 = piVar10[2];
    if (piVar10[2] <= iVar6) {
      iVar3 = iVar6;
    }
    piVar10[2] = iVar3;
  }
  uVar4 = *local_14;
  if (iVar13 < local_18) {
    do {
      if (local_1c < iVar5) {
        iVar6 = (int)(iVar13 + (iVar13 >> 0x1f & 7U)) >> 3;
        iVar3 = local_1c;
        do {
          iVar16 = DAT_0077241c;
          local_20 = (int)((iVar3 >> 0x1f & 7U) + iVar3) >> 3;
          local_24 = *(int *)(DAT_0077241c + 0x84);
          if (*(int *)(DAT_0077241c + 0x84) <= local_20) {
            local_24 = local_20;
          }
          iVar12 = *(int *)(DAT_0077241c + 0x88);
          if (*(int *)(DAT_0077241c + 0x88) <= iVar6) {
            iVar12 = iVar6;
          }
          iVar7 = *(int *)(DAT_0077241c + 0x90) + -1;
          if (iVar12 < *(int *)(DAT_0077241c + 0x90)) {
            iVar7 = iVar12;
          }
          iVar12 = *(int *)(DAT_0077241c + 0x8c) + -1;
          if (local_24 < *(int *)(DAT_0077241c + 0x8c)) {
            iVar12 = local_24;
          }
          iVar12 = (iVar7 * *(int *)(DAT_0077241c + 0x44) + iVar12) % *(int *)(DAT_0077241c + 0x4c);
          if ((iVar12 < 0) || (*(int *)(DAT_0077241c + 0x18) <= iVar12)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_24 = *(int *)(iVar16 + 0x14);
          }
          else {
            local_24 = iVar12 * 0x7c + *(int *)(DAT_0077241c + 0x14);
          }
          pbVar14 = (byte *)(local_24 + 0x34);
          if (param_5 < 8) {
            pbVar8 = pbVar14 + param_5;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pbVar8 = pbVar14;
          }
          bVar1 = *pbVar8;
          if (bVar1 != 0xff) {
            if (bVar1 < 2) {
              if (bVar1 == 0) {
                FUN_0057dfc0(&local_24,local_20,iVar6,param_5);
              }
              if (param_5 < 8) {
                puVar9 = local_14 + param_5;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                puVar9 = local_14;
              }
              if ((int)(puVar9[3] * 8) <= iVar13) {
                if (param_5 < 8) {
                  puVar9 = local_14 + param_5 * 2;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar9 = local_14;
                }
                FUN_005813a0(1);
                uVar11 = puVar9[0xb];
                uVar2 = puVar9[0xc];
                *(int *)((uVar11 - 8) + uVar2 * 8) = local_20;
                *(int *)((uVar11 - 4) + uVar2 * 8) = iVar6;
              }
            }
            if ((uVar4 == param_5) && (bVar1 < 0xe3)) {
              uVar18 = 0x50;
              iVar16 = iVar3 + -8;
              iVar12 = iVar13 + 8;
              iVar7 = iVar13 + -8;
              iVar17 = iVar3 + 8;
              FUN_005a3dd0(iVar16,iVar7,iVar17,iVar12,0x50);
              FUN_005a3fd0(iVar16,iVar7,iVar17,iVar12,uVar18);
            }
            if (param_5 < 8) {
              pbVar14 = pbVar14 + param_5;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *pbVar14 = 0xff;
          }
          iVar3 = iVar3 + 8;
        } while (iVar3 < iVar5);
      }
      iVar13 = iVar13 + 8;
    } while (iVar13 < local_18);
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

