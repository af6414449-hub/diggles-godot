
void FUN_0057e120(int param_1,int param_2,int param_3,int param_4,uint param_5,float param_6,
                 float param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  CHeightBlock **ppCVar9;
  int iVar10;
  CHeightBlock *pCVar11;
  uint *puVar12;
  int iVar13;
  CHeightBlock **ppCVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  undefined8 uVar19;
  int iVar20;
  undefined4 uVar21;
  int *local_2c;
  CHeightBlock **local_28;
  float local_24;
  float local_20;
  float local_1c;
  int local_18;
  uint *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070610d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca5480) &&
     (FUN_006cebf4(&DAT_00ca5480,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca5480 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca5484 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) =
         "void CFogOfWar::RemoveFog(const int iX2, const int iY2, int iRangeX, int iRangeY,const int iOwner)"
    ;
    *(int *)(&DAT_00773650 + iVar6) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca5480);
  }
  iVar6 = DAT_00ca5484;
  uVar21 = *(undefined4 *)(&DAT_00773650 + DAT_00ca5484 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar21;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar5 == 0) {
    uVar19 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar19;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar5 + 1;
  local_8 = 0;
  uVar1 = *local_14;
  if ((((PTR_0077241c->x0_8 <= param_3 + param_1) && (PTR_0077241c->y0_8 <= param_4 + param_2)) &&
      (param_1 - param_3 <= PTR_0077241c->x1_8)) && (param_2 - param_4 <= PTR_0077241c->y1_8)) {
    iVar10 = (int)((param_3 >> 0x1f & 7U) + param_3) >> 3;
    iVar6 = (int)(param_4 + (param_4 >> 0x1f & 7U)) >> 3;
    iVar5 = iVar6;
    if (iVar6 < iVar10) {
      iVar5 = iVar10;
    }
    local_20 = (float)iVar6 / (float)iVar10;
    local_1c = (float)(int)((double)iVar5 * 3.14159265359 + (double)iVar5 * 3.14159265359);
    iVar5 = (int)(param_1 + (param_1 >> 0x1f & 7U)) >> 3;
    local_18 = (int)(param_2 + (param_2 >> 0x1f & 7U)) >> 3;
    if (((0 < local_18) && (0 < iVar5)) && (*(char *)(DAT_00772400 + 0x8c) == '\0')) {
      piVar7 = (int *)FUN_0043d660(param_5);
      iVar13 = piVar7[1];
      if (local_18 - iVar6 <= piVar7[1]) {
        iVar13 = local_18 - iVar6;
      }
      piVar7[1] = iVar13;
      iVar13 = *piVar7;
      if (iVar5 - iVar10 <= *piVar7) {
        iVar13 = iVar5 - iVar10;
      }
      *piVar7 = iVar13;
      iVar13 = piVar7[3];
      if (piVar7[3] <= local_18 + iVar6) {
        iVar13 = local_18 + iVar6;
      }
      piVar7[3] = iVar13;
      iVar6 = piVar7[2];
      if (piVar7[2] <= iVar10 + iVar5) {
        iVar6 = iVar10 + iVar5;
      }
      piVar7[2] = iVar6;
    }
    fVar17 = (float)(int)local_1c;
    local_18 = (int)ROUND(fVar17 * param_6);
    iVar5 = (int)ROUND(fVar17 * param_7);
    DAT_00772dd8 = iVar5;
    if (local_18 <= iVar5) {
      local_1c = (float)param_1 * 0.125;
      local_24 = (float)param_2 * 0.125;
      do {
        fVar15 = ((float)local_18 / fVar17 + (float)local_18 / fVar17) * 3.1415927;
        fVar16 = fVar15;
        FUN_004089f0();
        FUN_004089d0();
        fVar15 = fVar15 * local_20;
        param_1 = 0;
        param_6 = 0.0;
        fVar4 = local_1c;
        fVar18 = local_24;
        if (0 < iVar10) {
          do {
            iVar13 = (int)(fVar4 + 0.5);
            iVar6 = (int)(fVar18 + 0.5);
            if (((PTR_0077241c->cellX0 <= iVar13) && (iVar13 < PTR_0077241c->cellX1)) &&
               ((PTR_0077241c->cellY0 <= iVar6 && (iVar6 < PTR_0077241c->cellY1)))) {
              piVar7 = (int *)FUN_00592f10(PTR_0077241c);
              iVar8 = *piVar7;
              local_28 = &PTR_0077241c->heightBlocks->data;
              local_2c = piVar7;
              if ((iVar8 < 0) || (PTR_0077241c->heightBlocks->count <= iVar8)) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                pCVar11 = *local_28;
              }
              else {
                pCVar11 = *local_28 + iVar8;
              }
              if (param_6 != 0.0) {
                if (param_1 == 3) break;
                iVar8 = param_1 + 1;
                if (param_1 == 0) {
                  iVar8 = param_1;
                }
                param_1 = iVar8;
                if ((0xe < (pCVar11->heights[0] & 0xf)) && (iVar8 == 0)) {
                  param_1 = 1;
                }
              }
              ppCVar14 = (CHeightBlock **)(piVar7 + 0xd);
              local_28 = ppCVar14;
              if (param_5 < 8) {
                ppCVar9 = (CHeightBlock **)((int)ppCVar14 + param_5);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                ppCVar9 = ppCVar14;
              }
              if (*(byte *)ppCVar9 < 2) {
                if (param_5 < 8) {
                  ppCVar9 = (CHeightBlock **)((int)ppCVar14 + param_5);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  ppCVar9 = ppCVar14;
                }
                if (*(byte *)ppCVar9 == 0) {
                  FUN_0057dfc0(&local_2c,iVar13,iVar6,param_5);
                }
                if (param_5 < 8) {
                  puVar12 = local_14 + param_5;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar12 = local_14;
                }
                if ((int)puVar12[3] <= iVar6) {
                  if (param_5 < 8) {
                    puVar12 = local_14 + param_5 * 2;
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    puVar12 = local_14;
                  }
                  FUN_005813a0(1);
                  uVar2 = puVar12[0xc];
                  uVar3 = puVar12[0xb];
                  *(int *)((uVar3 - 8) + uVar2 * 8) = iVar13;
                  *(int *)((uVar3 - 4) + uVar2 * 8) = iVar6;
                  ppCVar14 = local_28;
                }
              }
              if (param_5 < 8) {
                ppCVar9 = (CHeightBlock **)((int)ppCVar14 + param_5);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                ppCVar9 = ppCVar14;
              }
              if (*(byte *)ppCVar9 != 0xff) {
                if ((uVar1 == param_5) && (*(byte *)ppCVar9 < 0xe3)) {
                  uVar21 = 0x50;
                  iVar8 = iVar13 * 8 + -8;
                  iVar20 = iVar6 * 8 + 8;
                  iVar6 = iVar6 * 8 + -8;
                  iVar13 = iVar13 * 8 + 8;
                  FUN_005a3dd0(iVar8,iVar6,iVar13,iVar20,0x50);
                  FUN_005a3fd0(iVar8,iVar6,iVar13,iVar20,uVar21);
                }
                if (param_5 < 8) {
                  ppCVar14 = (CHeightBlock **)((int)ppCVar14 + param_5);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                *(byte *)ppCVar14 = 0xff;
              }
            }
            param_6 = (float)((int)param_6 + 1);
            fVar4 = fVar16 / 1.1 + fVar4;
            fVar18 = fVar18 + fVar15 / 1.1;
          } while ((int)param_6 < iVar10);
        }
        local_18 = local_18 + 1;
      } while (local_18 <= iVar5);
    }
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

