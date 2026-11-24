
void FUN_00578c80(void)

{
  int *piVar1;
  CMap *pCVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int *piVar6;
  CMapCell *pCVar7;
  int iVar8;
  int iVar9;
  CMapCell *pCVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int in_ECX;
  CMapCell *pCVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  float fVar18;
  float fVar19;
  undefined4 uVar20;
  
  piVar1 = (int *)(in_ECX + 0xc84);
  uVar17 = 0;
  while( true ) {
    if (*(uint *)(in_ECX + 0xc6c) < 2) {
      piVar6 = piVar1 + *(uint *)(in_ECX + 0xc6c) * 2;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar6 = piVar1;
    }
    if (piVar6[1] <= (int)uVar17) break;
    if (*(uint *)(in_ECX + 0xc6c) < 2) {
      piVar6 = piVar1 + *(uint *)(in_ECX + 0xc6c) * 2;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar6 = piVar1;
    }
    if ((uint)piVar6[1] <= uVar17) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar15 = *(int *)(*piVar6 + uVar17 * 8);
    if (*(uint *)(in_ECX + 0xc6c) < 2) {
      piVar6 = piVar1 + *(uint *)(in_ECX + 0xc6c) * 2;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar6 = piVar1;
    }
    if ((uint)piVar6[1] <= uVar17) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    pCVar2 = PTR_0077241c;
    iVar5 = *(int *)(*piVar6 + 4 + uVar17 * 8);
    iVar16 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= iVar15) {
      iVar16 = iVar15;
    }
    iVar15 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= iVar5) {
      iVar15 = iVar5;
    }
    iVar5 = PTR_0077241c->cellY1 + -1;
    if (iVar15 < PTR_0077241c->cellY1) {
      iVar5 = iVar15;
    }
    iVar15 = PTR_0077241c->cellX1 + -1;
    if (iVar16 < PTR_0077241c->cellX1) {
      iVar15 = iVar16;
    }
    iVar15 = (iVar5 * PTR_0077241c->mapWidth + iVar15) % PTR_0077241c->cellCountTotal;
    if ((iVar15 < 0) || (PTR_0077241c->cellCount <= iVar15)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar7 = pCVar2->cells;
    }
    else {
      pCVar7 = PTR_0077241c->cells + iVar15;
    }
    uVar17 = uVar17 + 1;
    pCVar7->field_0x1a = pCVar7->field_0x1b;
    *(undefined4 *)&pCVar7->field_0x1c = *(undefined4 *)&pCVar7->field_0x20;
    *(undefined4 *)&pCVar7->field_0x24 = *(undefined4 *)&pCVar7->field_0x28;
    *(undefined4 *)&pCVar7->field_0x2c = *(undefined4 *)&pCVar7->field_0x30;
    *(undefined4 *)&pCVar7->field_0x28 = 0;
  }
  uVar17 = 0;
  do {
    if (*(uint *)(in_ECX + 0xc6c) < 2) {
      piVar6 = piVar1 + *(uint *)(in_ECX + 0xc6c) * 2;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar6 = piVar1;
    }
    if (piVar6[1] <= (int)uVar17) {
      return;
    }
    if (*(uint *)(in_ECX + 0xc6c) < 2) {
      piVar6 = piVar1 + *(uint *)(in_ECX + 0xc6c) * 2;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar6 = piVar1;
    }
    if ((uint)piVar6[1] <= uVar17) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar15 = *(int *)(*piVar6 + uVar17 * 8);
    if (*(uint *)(in_ECX + 0xc6c) < 2) {
      piVar6 = piVar1 + *(uint *)(in_ECX + 0xc6c) * 2;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar6 = piVar1;
    }
    if ((uint)piVar6[1] <= uVar17) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    pCVar2 = PTR_0077241c;
    iVar5 = *(int *)(*piVar6 + 4 + uVar17 * 8);
    if ((((iVar15 < PTR_0077241c->cellX0 + 2) || (PTR_0077241c->cellX1 + -2 <= iVar15)) ||
        (iVar5 < PTR_0077241c->cellY0 + 2)) || (PTR_0077241c->cellY1 + -2 <= iVar5))
    goto LAB_00579176;
    iVar16 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= iVar15) {
      iVar16 = iVar15;
    }
    iVar8 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= iVar5) {
      iVar8 = iVar5;
    }
    iVar11 = PTR_0077241c->cellY1 + -1;
    if (iVar8 < PTR_0077241c->cellY1) {
      iVar11 = iVar8;
    }
    iVar8 = PTR_0077241c->cellX1 + -1;
    if (iVar16 < PTR_0077241c->cellX1) {
      iVar8 = iVar16;
    }
    iVar16 = (iVar11 * PTR_0077241c->mapWidth + iVar8) % PTR_0077241c->cellCountTotal;
    if ((iVar16 < 0) || (PTR_0077241c->cellCount <= iVar16)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar7 = pCVar2->cells;
    }
    else {
      pCVar7 = PTR_0077241c->cells + iVar16;
    }
    pCVar2 = PTR_0077241c;
    iVar8 = iVar5 + -1;
    iVar16 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= iVar15) {
      iVar16 = iVar15;
    }
    iVar11 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= iVar8) {
      iVar11 = iVar8;
    }
    iVar9 = PTR_0077241c->cellY1 + -1;
    if (iVar11 < PTR_0077241c->cellY1) {
      iVar9 = iVar11;
    }
    iVar11 = PTR_0077241c->cellX1 + -1;
    if (iVar16 < PTR_0077241c->cellX1) {
      iVar11 = iVar16;
    }
    iVar16 = (iVar9 * PTR_0077241c->mapWidth + iVar11) % PTR_0077241c->cellCountTotal;
    if ((iVar16 < 0) || (PTR_0077241c->cellCount <= iVar16)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar10 = pCVar2->cells;
    }
    else {
      pCVar10 = PTR_0077241c->cells + iVar16;
    }
    pCVar2 = PTR_0077241c;
    iVar11 = iVar15 + -1;
    iVar16 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= iVar11) {
      iVar16 = iVar11;
    }
    iVar9 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= iVar5) {
      iVar9 = iVar5;
    }
    iVar12 = PTR_0077241c->cellY1 + -1;
    if (iVar9 < PTR_0077241c->cellY1) {
      iVar12 = iVar9;
    }
    iVar9 = PTR_0077241c->cellX1 + -1;
    if (iVar16 < PTR_0077241c->cellX1) {
      iVar9 = iVar16;
    }
    iVar16 = (iVar12 * PTR_0077241c->mapWidth + iVar9) % PTR_0077241c->cellCountTotal;
    if ((iVar16 < 0) || (PTR_0077241c->cellCount <= iVar16)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar14 = pCVar2->cells;
    }
    else {
      pCVar14 = PTR_0077241c->cells + iVar16;
    }
    fVar19 = *(float *)&pCVar14->field_0x24 + *(float *)&pCVar7->field_0x24;
    bVar3 = pCVar7->field_0x1a;
    fVar18 = *(float *)&pCVar10->field_0x2c + *(float *)&pCVar7->field_0x2c;
    if ((bVar3 & 7) == 0) {
      uVar13 = CONCAT11(bVar3,pCVar10->field_0x1a) & 0xffffff07;
      uVar4 = (ushort)uVar13;
      if ((pCVar10->field_0x1a & 7) == 0) {
        bVar3 = (byte)(uVar13 >> 8);
        if ((pCVar14->field_0x1a & 7) == 0) goto LAB_00579083;
        uVar4 = (ushort)CONCAT31((int3)(uVar13 >> 8),pCVar14->field_0x1a) & 0xff07;
      }
      bVar3 = (byte)uVar4 | (byte)(uVar4 >> 8);
      pCVar7->field_0x1a = bVar3;
    }
LAB_00579083:
    switch(bVar3 & 7) {
    case 1:
      FUN_00577e00(iVar15,iVar5,iVar15,iVar8,fVar18,1);
      uVar20 = 1;
      goto LAB_00579141;
    case 2:
      FUN_005783c0(iVar15,iVar5,iVar15,iVar8,fVar18);
      FUN_005780e0(iVar15,iVar5,iVar11,iVar5,fVar19);
      break;
    case 3:
      FUN_005789b0(iVar15,iVar5,iVar15,iVar8,fVar18);
      FUN_005786e0(iVar15,iVar5,iVar11,iVar5,fVar19);
      break;
    case 4:
      FUN_00577e00(iVar15,iVar5,iVar15,iVar8,fVar18,4);
      uVar20 = 4;
LAB_00579141:
      FUN_00577b20(iVar15,iVar5,iVar11,iVar5,fVar19,uVar20);
    }
    *(float *)&pCVar7->field_0x28 = fVar19;
    *(float *)&pCVar7->field_0x30 = fVar18;
LAB_00579176:
    uVar17 = uVar17 + 1;
  } while( true );
}

