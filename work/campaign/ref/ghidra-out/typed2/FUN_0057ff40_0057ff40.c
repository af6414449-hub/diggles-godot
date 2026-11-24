
undefined1 FUN_0057ff40(float param_1,float param_2,undefined4 param_3,float param_4,float param_5)

{
  undefined4 uVar1;
  CHeightBlockArray *pCVar2;
  CMap *pCVar3;
  int iVar4;
  int *piVar5;
  CHeightBlock *pCVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined1 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined8 uVar15;
  
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca54b8) &&
     (FUN_006cebf4(&DAT_00ca54b8), iVar4 = DAT_00783650, DAT_00ca54b8 == -1)) {
    iVar11 = DAT_00783650 * 0x40;
    DAT_00ca54bc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar11) =
         "bool CFogOfWar::Visible(const CVec3D vPos1,const CVec3D vPos2)";
    *(int *)(&DAT_00773650 + iVar11) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54b8);
  }
  iVar11 = DAT_00ca54bc;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca54bc * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar11 * 0x10];
  if (iVar4 == 0) {
    uVar15 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar11 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar11 * 0x10) = uVar15;
  }
  (&DAT_00773654)[iVar11 * 0x10] = iVar4 + 1;
  iVar11 = (int)(param_1 * 8.0);
  iVar14 = (int)(param_2 * 8.0);
  iVar4 = (int)(param_4 * 8.0);
  iVar13 = (int)(param_5 * 8.0);
  if ((iVar4 != iVar11) || (iVar13 != iVar14)) {
    uVar8 = iVar14 - iVar13 >> 0x1f;
    uVar9 = iVar11 - iVar4 >> 0x1f;
    if ((int)((iVar14 - iVar13 ^ uVar8) - uVar8) < (int)((iVar11 - iVar4 ^ uVar9) - uVar9)) {
      iVar7 = iVar14;
      if (iVar11 <= iVar4) {
        iVar7 = iVar13;
      }
      iVar12 = 0;
      iVar13 = iVar11;
      if (iVar11 <= iVar4) {
        iVar13 = iVar4;
      }
      iVar13 = iVar13 - iVar11;
      if (0 < iVar13) {
        do {
          pCVar3 = PTR_0077241c;
          DAT_00772dd8 = (int)ROUND(((float)iVar12 / (float)iVar13) * (float)(iVar7 - iVar14));
          uVar8 = iVar14 + DAT_00772dd8;
          piVar5 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar2 = pCVar3->heightBlocks;
          iVar4 = *piVar5;
          if ((iVar4 < 0) || (pCVar2->count <= iVar4)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar6 = pCVar2->data;
          }
          else {
            pCVar6 = pCVar2->data + iVar4;
          }
          if (0xd < pCVar6->heights[(uVar8 & 7) << 3 | iVar11 + iVar12 & 7U]) goto LAB_00580202;
          iVar12 = iVar12 + 1;
        } while (iVar12 < iVar13);
      }
    }
    else {
      iVar7 = iVar11;
      if (iVar14 <= iVar13) {
        iVar7 = iVar4;
      }
      iVar12 = 0;
      iVar4 = iVar14;
      if (iVar14 <= iVar13) {
        iVar4 = iVar13;
      }
      iVar4 = iVar4 - iVar14;
      if (0 < iVar4) {
        do {
          pCVar3 = PTR_0077241c;
          DAT_00772dd8 = (int)ROUND(((float)iVar12 / (float)iVar4) * (float)(iVar7 - iVar11));
          uVar8 = DAT_00772dd8 + iVar11;
          piVar5 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar2 = pCVar3->heightBlocks;
          iVar13 = *piVar5;
          if ((iVar13 < 0) || (pCVar2->count <= iVar13)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar6 = pCVar2->data;
          }
          else {
            pCVar6 = pCVar2->data + iVar13;
          }
          if (0xd < pCVar6->heights[(iVar14 + iVar12 & 7U) << 3 | uVar8 & 7]) goto LAB_00580202;
          iVar12 = iVar12 + 1;
        } while (iVar12 < iVar4);
      }
    }
  }
  uVar10 = 1;
LAB_00580101:
  FUN_0043fd30();
  return uVar10;
LAB_00580202:
  uVar10 = 0;
  goto LAB_00580101;
}

