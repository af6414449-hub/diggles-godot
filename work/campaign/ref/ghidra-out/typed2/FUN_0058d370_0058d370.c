
undefined1 * FUN_0058d370(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  CHeightBlockArray *pCVar5;
  CMap *pCVar6;
  undefined1 uVar7;
  char cVar8;
  uint uVar9;
  int *piVar10;
  CMapCell *pCVar11;
  int *piVar12;
  int *piVar13;
  CHeightBlock *pCVar14;
  int iVar15;
  int *piVar16;
  int in_ECX;
  uint uVar17;
  int iVar18;
  uint *puVar19;
  undefined4 *puVar20;
  undefined4 *puVar21;
  undefined1 auStackY_100 [132];
  undefined4 uStackY_7c;
  int **ppiStackY_78;
  char *pcStackY_74;
  undefined8 uStackY_70;
  int *local_20;
  int local_1c;
  int *local_18;
  byte local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8._0_1_ = 0xff;
  local_8._1_3_ = 0xffffff;
  puStack_c = &LAB_007066c5;
  local_10 = ExceptionList;
  if (*(int *)(in_ECX + 0xc) == 0) {
    return auStackY_100;
  }
  uVar17 = *(int *)(DAT_00772400 + 0x6c) % *(int *)(in_ECX + 0xc);
  ExceptionList = &local_10;
  local_1c = in_ECX;
  if (*(uint *)(in_ECX + 0xc) <= uVar17) {
    uStackY_70 = (double)CONCAT44(0x58d3ce,(undefined4)uStackY_70);
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  puVar19 = (uint *)(*(int *)(in_ECX + 8) + uVar17 * 0x8c);
  DAT_00772dd8 = (int)ROUND((float)puVar19[1]);
  uVar9 = PTR_0077241c->cellX0 + 0x10;
  if (((((int)uVar9 <= DAT_00772dd8) &&
       (uVar9 = PTR_0077241c->cellX1 - 0x10, DAT_00772dd8 < (int)uVar9)) &&
      (uVar9 = PTR_0077241c->cellY0 + 0x10, (int)uVar9 <= (int)ROUND((float)puVar19[2]))) &&
     (uVar9 = PTR_0077241c->cellY1 - 0x10, (int)ROUND((float)puVar19[2]) < (int)uVar9)) {
    fVar1 = (float)puVar19[0x15];
    fVar2 = (float)puVar19[0x14];
    fVar3 = (float)puVar19[9];
    DAT_00772dd8 = (int)ROUND((float)puVar19[8]);
    pCVar6 = PTR_0077241c;
    for (local_20 = (int *)(DAT_00772dd8 + -2); piVar12 = (int *)((int)ROUND(fVar3) + -2),
        (int)local_20 < (int)ROUND(fVar2) + 2; local_20 = (int *)((int)local_20 + 1)) {
      while (local_18 = piVar12, (int)local_18 < (int)ROUND(fVar1) + 2) {
        piVar12 = (int *)pCVar6->cellX0;
        if (pCVar6->cellX0 <= (int)local_20) {
          piVar12 = local_20;
        }
        piVar13 = (int *)pCVar6->cellY0;
        if (pCVar6->cellY0 <= (int)local_18) {
          piVar13 = local_18;
        }
        piVar10 = (int *)(pCVar6->cellY1 + -1);
        if ((int)piVar13 < pCVar6->cellY1) {
          piVar10 = piVar13;
        }
        piVar13 = (int *)(pCVar6->cellX1 + -1);
        if ((int)piVar12 < pCVar6->cellX1) {
          piVar13 = piVar12;
        }
        iVar18 = (int)((int)piVar10 * pCVar6->mapWidth + (int)piVar13) % pCVar6->cellCountTotal;
        PTR_0077241c = pCVar6;
        if ((iVar18 < 0) || (pCVar6->cellCount <= iVar18)) {
          uStackY_70 = (double)CONCAT44(0x58d564,(undefined4)uStackY_70);
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar11 = pCVar6->cells;
        }
        else {
          pCVar11 = pCVar6->cells + iVar18;
        }
        uVar9 = pCVar11->digMarks >> ((byte)(puVar19[0x22] << 2) & 0x1f) & 0xf;
        if (uVar9 != 0) goto LAB_0058e0ec;
        pCVar6 = PTR_0077241c;
        piVar12 = (int *)((int)local_18 + 1);
      }
    }
    DAT_00772dd8 = (int)ROUND((float)puVar19[2] * 8.0);
    PTR_0077241c = pCVar6;
    uVar7 = (undefined1)local_8;
    if (((pCVar6->x0_8 + 0x10 <= (int)ROUND((float)puVar19[1] * 8.0)) &&
        ((int)ROUND((float)puVar19[1] * 8.0) < pCVar6->x1_8 + -0x10)) &&
       ((pCVar6->y0_8 + 0x10 <= DAT_00772dd8 && (DAT_00772dd8 < pCVar6->y1_8 + -0x10)))) {
      fVar1 = (float)puVar19[0x14];
      fVar2 = (float)puVar19[0x15];
      fVar3 = (float)puVar19[0x16];
      DAT_00772dd8 = (int)ROUND(fVar3);
      piVar12 = (int *)FUN_00592f10(pCVar6);
      pCVar5 = pCVar6->heightBlocks;
      iVar18 = *piVar12;
      if ((iVar18 < 0) || (pCVar5->count <= iVar18)) {
        uStackY_70 = (double)CONCAT44(0x58d6dd,(undefined4)uStackY_70);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar14 = pCVar5->data;
      }
      else {
        pCVar14 = pCVar5->data + iVar18;
      }
      pCVar6 = PTR_0077241c;
      fVar4 = (float)puVar19[0x17];
      piVar13 = (int *)(uint)((int)(uint)pCVar14->heights
                                         [((int)ROUND(fVar2 * 8.0) & 7U) << 3 |
                                          (int)ROUND(fVar1 * 8.0) & 7U] <= (int)ROUND(fVar3));
      local_11 = 10 < pCVar14->heights
                      [((int)ROUND(fVar2 * 8.0) & 7U) << 3 | (int)ROUND(fVar1 * 8.0) & 7U];
      fVar1 = (float)puVar19[0x18];
      fVar2 = (float)puVar19[0x19];
      DAT_00772dd8 = (int)ROUND(fVar2);
      piVar12 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar5 = pCVar6->heightBlocks;
      iVar18 = *piVar12;
      if ((iVar18 < 0) || (pCVar5->count <= iVar18)) {
        uStackY_70 = (double)CONCAT44(0x58d7ac,(undefined4)uStackY_70);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar14 = pCVar5->data;
      }
      else {
        pCVar14 = pCVar5->data + iVar18;
      }
      pCVar6 = PTR_0077241c;
      fVar3 = (float)puVar19[0x1a];
      piVar12 = (int *)((int)piVar13 + 1);
      if ((int)ROUND(fVar2) <
          (int)(uint)pCVar14->heights
                     [((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar4 * 8.0) & 7U]) {
        piVar12 = piVar13;
      }
      local_20 = (int *)0x0;
      if (10 < pCVar14->heights[((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar4 * 8.0) & 7U])
      {
        local_20 = (int *)(uint)local_11;
      }
      fVar1 = (float)puVar19[0x1b];
      fVar2 = (float)puVar19[0x1c];
      DAT_00772dd8 = (int)ROUND(fVar2);
      piVar13 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar5 = pCVar6->heightBlocks;
      iVar18 = *piVar13;
      if ((iVar18 < 0) || (pCVar5->count <= iVar18)) {
        uStackY_70 = (double)CONCAT44(0x58d887,(undefined4)uStackY_70);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar14 = pCVar5->data;
      }
      else {
        pCVar14 = pCVar5->data + iVar18;
      }
      pCVar6 = PTR_0077241c;
      fVar4 = (float)puVar19[0x1d];
      piVar13 = (int *)((int)piVar12 + 1);
      if ((int)ROUND(fVar2) <
          (int)(uint)pCVar14->heights
                     [((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar3 * 8.0) & 7U]) {
        piVar13 = piVar12;
      }
      piVar12 = (int *)((uint)local_20 & 0xff);
      local_20 = (int *)0x0;
      if (10 < pCVar14->heights[((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar3 * 8.0) & 7U])
      {
        local_20 = piVar12;
      }
      fVar1 = (float)puVar19[0x1e];
      fVar2 = (float)puVar19[0x1f];
      DAT_00772dd8 = (int)ROUND(fVar2);
      piVar12 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar5 = pCVar6->heightBlocks;
      iVar18 = *piVar12;
      if ((iVar18 < 0) || (pCVar5->count <= iVar18)) {
        uStackY_70 = (double)CONCAT44(0x58d964,(undefined4)uStackY_70);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar14 = pCVar5->data;
      }
      else {
        pCVar14 = pCVar5->data + iVar18;
      }
      pCVar6 = PTR_0077241c;
      fVar3 = (float)puVar19[8];
      piVar12 = (int *)((int)piVar13 + 1);
      if ((int)ROUND(fVar2) <
          (int)(uint)pCVar14->heights
                     [((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar4 * 8.0) & 7U]) {
        piVar12 = piVar13;
      }
      piVar13 = (int *)((uint)local_20 & 0xff);
      local_20 = (int *)0x0;
      if (10 < pCVar14->heights[((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar4 * 8.0) & 7U])
      {
        local_20 = piVar13;
      }
      fVar1 = (float)puVar19[9];
      fVar2 = (float)puVar19[10];
      DAT_00772dd8 = (int)ROUND(fVar2);
      piVar13 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar5 = pCVar6->heightBlocks;
      iVar18 = *piVar13;
      if ((iVar18 < 0) || (pCVar5->count <= iVar18)) {
        uStackY_70 = (double)CONCAT44(0x58da41,(undefined4)uStackY_70);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar14 = pCVar5->data;
      }
      else {
        pCVar14 = pCVar5->data + iVar18;
      }
      pCVar6 = PTR_0077241c;
      fVar4 = (float)puVar19[0xb];
      piVar13 = (int *)((int)piVar12 + 1);
      if ((int)ROUND(fVar2) <
          (int)(uint)pCVar14->heights
                     [((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar3 * 8.0) & 7U]) {
        piVar13 = piVar12;
      }
      piVar12 = (int *)((uint)local_20 & 0xff);
      local_20 = (int *)0x0;
      if (10 < pCVar14->heights[((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar3 * 8.0) & 7U])
      {
        local_20 = piVar12;
      }
      fVar1 = (float)puVar19[0xc];
      fVar2 = (float)puVar19[0xd];
      DAT_00772dd8 = (int)ROUND(fVar2);
      piVar12 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar5 = pCVar6->heightBlocks;
      iVar18 = *piVar12;
      if ((iVar18 < 0) || (pCVar5->count <= iVar18)) {
        uStackY_70 = (double)CONCAT44(0x58db1e,(undefined4)uStackY_70);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar14 = pCVar5->data;
      }
      else {
        pCVar14 = pCVar5->data + iVar18;
      }
      pCVar6 = PTR_0077241c;
      fVar3 = (float)puVar19[0xe];
      piVar12 = (int *)((int)piVar13 + 1);
      if ((int)ROUND(fVar2) <
          (int)(uint)pCVar14->heights
                     [((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar4 * 8.0) & 7U]) {
        piVar12 = piVar13;
      }
      piVar13 = (int *)((uint)local_20 & 0xff);
      local_20 = (int *)0x0;
      if (10 < pCVar14->heights[((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar4 * 8.0) & 7U])
      {
        local_20 = piVar13;
      }
      fVar1 = (float)puVar19[0xf];
      fVar2 = (float)puVar19[0x10];
      DAT_00772dd8 = (int)ROUND(fVar2);
      piVar13 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar5 = pCVar6->heightBlocks;
      iVar18 = *piVar13;
      if ((iVar18 < 0) || (pCVar5->count <= iVar18)) {
        uStackY_70 = (double)CONCAT44(0x58dbfb,(undefined4)uStackY_70);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar14 = pCVar5->data;
      }
      else {
        pCVar14 = pCVar5->data + iVar18;
      }
      pCVar6 = PTR_0077241c;
      fVar4 = (float)puVar19[0x11];
      piVar13 = (int *)((int)piVar12 + 1);
      if ((int)ROUND(fVar2) <
          (int)(uint)pCVar14->heights
                     [((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar3 * 8.0) & 7U]) {
        piVar13 = piVar12;
      }
      piVar12 = (int *)((uint)local_20 & 0xff);
      local_20 = (int *)0x0;
      if (10 < pCVar14->heights[((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar3 * 8.0) & 7U])
      {
        local_20 = piVar12;
      }
      fVar1 = (float)puVar19[0x12];
      fVar2 = (float)puVar19[0x13];
      DAT_00772dd8 = (int)ROUND(fVar2);
      piVar12 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar5 = pCVar6->heightBlocks;
      iVar18 = *piVar12;
      if ((iVar18 < 0) || (pCVar5->count <= iVar18)) {
        uStackY_70 = (double)CONCAT44(0x58dcd8,(undefined4)uStackY_70);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar14 = pCVar5->data;
      }
      else {
        pCVar14 = pCVar5->data + iVar18;
      }
      piVar12 = (int *)((int)piVar13 + 1);
      if ((int)ROUND(fVar2) <
          (int)(uint)pCVar14->heights
                     [((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar4 * 8.0) & 7U]) {
        piVar12 = piVar13;
      }
      cVar8 = '\0';
      if (10 < pCVar14->heights[((int)ROUND(fVar1 * 8.0) & 7U) << 3 | (int)ROUND(fVar4 * 8.0) & 7U])
      {
        cVar8 = (char)local_20;
      }
      uVar7 = (undefined1)local_8;
      if (((piVar12 < (int *)0x3) || (piVar12 == (int *)0x8)) || (cVar8 == '\0')) {
        if (*(uint *)(DAT_00772478 + 0x801c) <= *puVar19) {
          uStackY_70 = (double)CONCAT44(0x58e082,(undefined4)uStackY_70);
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar7 = (undefined1)local_8;
        }
      }
      else {
        uVar9 = puVar19[7];
        iVar18 = DAT_00768388;
        if (*(char *)(DAT_00772400 + 0x590) != '\0') {
          iVar18 = 2;
        }
        if (iVar18 < (int)(2 - uVar9)) {
          if (uVar9 == 0) {
            uStackY_70 = 2.12487318037415e-314;
            FUN_005d7450();
            uVar7 = (undefined1)local_8;
          }
          else if (uVar9 == 1) {
            uStackY_70 = 2.12487316258779e-314;
            FUN_005d7450();
            uVar7 = (undefined1)local_8;
          }
        }
        else {
          if (*(uint *)(DAT_00772478 + 0x801c) <= *puVar19) {
            uStackY_70 = (double)CONCAT44(0x58ddc1,(undefined4)uStackY_70);
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uStackY_70 = 2.87743140446038e-317;
          iVar18 = FUN_00601df0();
          uVar7 = (undefined1)local_8;
          if (iVar18 != 0) {
            *(undefined4 *)(iVar18 + 0x3d0) = 0x20000081;
            *(uint *)(iVar18 + 0x39c) = puVar19[0x20];
            FUN_0040b550();
            iVar15 = FUN_00405960();
            if (*(int *)(iVar15 + 0xc) < 1) {
              uStackY_70 = (double)CONCAT44(0x58de51,(undefined4)uStackY_70);
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(undefined4 *)(iVar18 + 0x3a0) = **(undefined4 **)(iVar15 + 8);
            *(uint *)(iVar18 + 0x3a8) = puVar19[0x21];
            uStackY_70 = (double)CONCAT44(0x58de81,(undefined4)uStackY_70);
            FUN_005cdae0();
            *(uint *)(iVar18 + 0x2a8) = puVar19[7];
            FUN_005cd7e0();
            FUN_005cd840();
            FUN_006b8fb0();
            local_8 = 0;
            FUN_00405e10();
            local_8._0_1_ = 3;
            if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 2;
            uVar7 = (undefined1)local_8;
            local_8._0_1_ = 2;
            if (local_18 != (int *)0x0) {
              FUN_006b8f50();
              local_8._0_1_ = 4;
              ppiStackY_78 = &local_20;
              uStackY_70 = (double)(float)puVar19[1];
              pcStackY_74 = "{%f %f %f} 0.8";
              uStackY_7c = 0x58df59;
              FUN_006b9040();
              FUN_006b8f50();
              local_8 = CONCAT31(local_8._1_3_,5);
              uStackY_70 = (double)CONCAT44(0x58df7e,(undefined4)uStackY_70);
              FUN_006b9040();
              piVar10 = local_18;
              piVar12 = local_20;
              if (local_20 != (int *)0xfffffff4) {
                piVar16 = (int *)Tcl_NewStringObj();
                *piVar16 = *piVar16 + 1;
              }
              if (piVar13 + 3 != (int *)0x0) {
                uStackY_70 = (double)CONCAT44(0x58dfca,(undefined4)uStackY_70);
                piVar16 = (int *)Tcl_NewStringObj();
                *piVar16 = *piVar16 + 1;
                uStackY_70 = (double)CONCAT44(piVar13 + 3,0x58dfeb);
                piVar16 = (int *)Tcl_NewStringObj();
                *piVar16 = *piVar16 + 1;
              }
              uStackY_70 = (double)CONCAT44(*(undefined4 *)(DAT_0077244c + 0xc0),0x58e00e);
              cVar8 = (**(code **)(*piVar10 + 8))();
              if (cVar8 != '\0') {
                FUN_00409280();
              }
              local_8._0_1_ = 6;
              if ((piVar13 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 == 0)) {
                FUN_006ba940();
              }
              local_8._0_1_ = 7;
              if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 == 0)) {
                FUN_006ba940();
              }
              uVar7 = (undefined1)local_8;
              if (local_18 != (int *)0x0) {
                LOCK();
                iVar18 = local_18[1] + -1;
                local_18[1] = iVar18;
                UNLOCK();
                if ((iVar18 == 0) && (local_18 != (int *)0x0)) {
                  (**(code **)*local_18)();
                  uVar7 = (undefined1)local_8;
                }
              }
            }
          }
        }
      }
    }
    local_8._0_1_ = uVar7;
    uVar9 = *(uint *)(local_1c + 0xc);
    if (uVar9 <= uVar17) {
      uStackY_70 = (double)CONCAT44(0x58e0a2,(undefined4)uStackY_70);
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      uVar9 = *(uint *)(local_1c + 0xc);
      if (uVar9 <= uVar17) {
        uStackY_70 = (double)CONCAT44(0x58e0b6,(undefined4)uStackY_70);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar9 = *(uint *)(local_1c + 0xc);
      }
    }
    if ((int)uVar17 < (int)(uVar9 - 1)) {
      puVar20 = (undefined4 *)(*(int *)(local_1c + 8) + -0x8c + uVar9 * 0x8c);
      puVar21 = (undefined4 *)(uVar17 * 0x8c + *(int *)(local_1c + 8));
      for (iVar18 = 0x23; iVar18 != 0; iVar18 = iVar18 + -1) {
        *puVar21 = *puVar20;
        puVar20 = puVar20 + 1;
        puVar21 = puVar21 + 1;
      }
      uVar9 = *(uint *)(local_1c + 0xc);
    }
    uVar9 = uVar9 - 1;
    *(uint *)(local_1c + 0xc) = uVar9;
  }
LAB_0058e0ec:
  ExceptionList = local_10;
  return (undefined1 *)CONCAT31((int3)(uVar9 >> 8),1);
}

