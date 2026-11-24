
void FUN_00580610(CMapCell *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  CMap *pCVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uchar *puVar9;
  uint uVar10;
  int in_ECX;
  int *extraout_ECX;
  CMapCell *pCVar11;
  CMapCell *pCVar12;
  uint uVar13;
  int iVar14;
  uchar *puVar15;
  code *pcVar16;
  int iVar17;
  undefined4 uVar18;
  int *local_34;
  CMapCell *local_2c;
  CMapCell *local_24;
  int local_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  
  pcVar16 = RaiseException_exref;
  local_24 = (CMapCell *)(PTR_0077241c->cellY1 + -2);
  if ((int)param_1 < (int)local_24) {
    local_24 = param_1;
  }
  local_34 = (int *)(in_ECX + 0xc);
  if (param_2 < 8) {
    piVar6 = local_34 + param_2;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar6 = local_34;
  }
  *piVar6 = (int)local_24;
  iVar7 = PTR_0077241c->cellY0 + 5;
  while( true ) {
    if (param_2 < 8) {
      piVar6 = local_34 + param_2;
    }
    else {
      (*pcVar16)(0xc000008c,1,0,0);
      piVar6 = local_34;
    }
    if (*piVar6 <= iVar7) break;
    pCVar11 = (CMapCell *)PTR_0077241c->cellX0;
    if ((int)pCVar11 < PTR_0077241c->cellX1 + -2) {
      do {
        pCVar5 = PTR_0077241c;
        local_24 = (CMapCell *)PTR_0077241c->cellX0;
        if (PTR_0077241c->cellX0 <= (int)pCVar11) {
          local_24 = pCVar11;
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
          local_24 = pCVar5->cells;
        }
        else {
          local_24 = PTR_0077241c->cells + iVar14;
        }
        puVar15 = local_24->ownerIndex;
        if (param_2 < 8) {
          puVar9 = puVar15 + param_2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar9 = puVar15;
        }
        if (*puVar9 == '\0') {
          FUN_0057dfc0(&local_24,pCVar11,iVar7,param_2);
        }
        if (param_2 < 8) {
          puVar15 = puVar15 + param_2;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        pCVar5 = PTR_0077241c;
        *puVar15 = 0xff;
        pCVar11 = (CMapCell *)((int)&pCVar11->heightBlockIndex + 1);
        pcVar16 = RaiseException_exref;
      } while ((int)pCVar11 < pCVar5->cellX1 + -2);
    }
    iVar7 = iVar7 + 1;
  }
  if (param_2 == *(uint *)(DAT_00772400 + 100)) {
    if (param_2 < 8) {
      local_34 = local_34 + param_2;
    }
    else {
      (*pcVar16)(0xc000008c,1,0,0);
      piVar6 = extraout_ECX;
    }
    uVar18 = 0x50;
    iVar14 = PTR_0077241c->x0_8;
    iVar7 = *local_34 * 8 + 0x10;
    iVar8 = PTR_0077241c->y0_8;
    iVar17 = PTR_0077241c->x1_8;
    local_20 = iVar14;
    iStack_1c = iVar8;
    iStack_18 = iVar17;
    iStack_14 = iVar7;
    FUN_005a3dd0(piVar6,iVar14,iVar8,iVar17,iVar7,0x50);
    FUN_005a3fd0(iVar14,iVar8,iVar17,iVar7,uVar18);
  }
  uVar10 = 0;
  pCVar11 = (CMapCell *)(in_ECX + 0x2c);
  do {
    while( true ) {
      if (param_2 < 8) {
        pCVar12 = (CMapCell *)(pCVar11->ownerIndex + param_2 * 8 + -0x34);
      }
      else {
        (*pcVar16)(0xc000008c,1,0,0);
        pCVar12 = pCVar11;
      }
      iVar7._0_2_ = pCVar12->objectIndex;
      iVar7._2_1_ = pCVar12->field_0x6;
      iVar7._3_1_ = pCVar12->light;
      if (iVar7 <= (int)uVar10) {
        return;
      }
      if (param_2 < 8) {
        local_2c = (CMapCell *)(pCVar11->ownerIndex + param_2 * 8 + -0x34);
        pCVar12 = local_2c;
      }
      else {
        (*pcVar16)(0xc000008c,1,0,0);
        local_2c = (CMapCell *)(pCVar11->ownerIndex + param_2 * 8 + -0x34);
        pCVar12 = pCVar11;
      }
      uVar1._0_2_ = pCVar12->objectIndex;
      uVar1._2_1_ = pCVar12->field_0x6;
      uVar1._3_1_ = pCVar12->light;
      if (uVar1 <= uVar10) {
        (*pcVar16)(0xc000008c,1,0,0);
      }
      iVar7 = uVar10 * 8;
      if (PTR_0077241c->cellX0 + 2 <= *(int *)(iVar7 + pCVar12->heightBlockIndex)) break;
LAB_00580ac1:
      uVar10 = uVar10 + 1;
    }
    pCVar12 = local_2c;
    if (7 < param_2) {
      (*pcVar16)(0xc000008c,1,0,0);
      pCVar12 = pCVar11;
    }
    uVar2._0_2_ = pCVar12->objectIndex;
    uVar2._2_1_ = pCVar12->field_0x6;
    uVar2._3_1_ = pCVar12->light;
    local_24 = pCVar12;
    if (uVar2 <= uVar10) {
      (*pcVar16)(0xc000008c,1,0,0);
    }
    if (PTR_0077241c->cellX1 + -2 <= *(int *)(iVar7 + local_24->heightBlockIndex))
    goto LAB_00580ac1;
    if (7 < param_2) {
      (*pcVar16)(0xc000008c,1,0,0);
      local_2c = pCVar11;
    }
    uVar3._0_2_ = local_2c->objectIndex;
    uVar3._2_1_ = local_2c->field_0x6;
    uVar3._3_1_ = local_2c->light;
    if (uVar3 <= uVar10) {
      (*pcVar16)(0xc000008c,1,0,0);
    }
    if (*(int *)(iVar7 + 4 + local_2c->heightBlockIndex) < PTR_0077241c->cellY0 + 5)
    goto LAB_00580ac1;
    if (param_2 < 8) {
      local_24 = (CMapCell *)(pCVar11->ownerIndex + param_2 * 8 + -0x34);
    }
    else {
      (*pcVar16)(0xc000008c,1,0,0);
      local_24 = pCVar11;
    }
    uVar4._0_2_ = local_24->objectIndex;
    uVar4._2_1_ = local_24->field_0x6;
    uVar4._3_1_ = local_24->light;
    if (uVar4 <= uVar10) {
      (*pcVar16)(0xc000008c,1,0,0);
    }
    local_24 = (CMapCell *)(local_24->heightBlockIndex + iVar7);
    if (param_2 < 8) {
      iVar14 = in_ECX + param_2 * 4;
    }
    else {
      (*pcVar16)(0xc000008c,1,0,0);
      iVar14 = in_ECX;
    }
    iVar8._0_2_ = local_24->objectIndex;
    iVar8._2_1_ = local_24->field_0x6;
    iVar8._3_1_ = local_24->light;
    if (*(int *)(iVar14 + 0xc) <= iVar8) goto LAB_00580ac1;
    if (param_2 < 8) {
      pCVar12 = (CMapCell *)(pCVar11->ownerIndex + param_2 * 8 + -0x34);
    }
    else {
      (*pcVar16)(0xc000008c,1,0,0);
      pCVar12 = pCVar11;
    }
    uVar13._0_2_ = pCVar12->objectIndex;
    uVar13._2_1_ = pCVar12->field_0x6;
    uVar13._3_1_ = pCVar12->light;
    if (uVar13 <= uVar10) {
      (*pcVar16)(0xc000008c,1,0,0);
      uVar13._0_2_ = pCVar12->objectIndex;
      uVar13._2_1_ = pCVar12->field_0x6;
      uVar13._3_1_ = pCVar12->light;
      if (uVar13 <= uVar10) {
        (*pcVar16)(0xc000008c,1,0,0);
        uVar13._0_2_ = pCVar12->objectIndex;
        uVar13._2_1_ = pCVar12->field_0x6;
        uVar13._3_1_ = pCVar12->light;
      }
    }
    if ((int)uVar10 < (int)(uVar13 - 1)) {
      iVar14 = pCVar12->heightBlockIndex;
      uVar18 = *(undefined4 *)(iVar14 + -4 + uVar13 * 8);
      *(undefined4 *)(iVar14 + iVar7) = *(undefined4 *)(iVar14 + -8 + uVar13 * 8);
      *(undefined4 *)(iVar14 + 4 + iVar7) = uVar18;
      uVar13._0_2_ = pCVar12->objectIndex;
      uVar13._2_1_ = pCVar12->field_0x6;
      uVar13._3_1_ = pCVar12->light;
    }
    *(uint *)&pCVar12->objectIndex = uVar13 - 1;
  } while( true );
}

