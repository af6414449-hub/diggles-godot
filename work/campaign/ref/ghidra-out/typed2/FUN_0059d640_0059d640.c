
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 *
FUN_0059d640(undefined4 *param_1,CMap *param_2,CMapCell *param_3,CMap *param_4,CMapCell *param_5,
            int *param_6,CMap *param_7,CMap *param_8,int *param_9)

{
  int iVar1;
  int iVar2;
  uchar *puVar3;
  CMapCell *pCVar4;
  CMap *pCVar5;
  char cVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  CMap *pCVar12;
  int *in_ECX;
  CMapCell *pCVar13;
  CMap *pCVar14;
  uint uVar15;
  undefined4 *puVar16;
  uint uVar17;
  int iVar18;
  code *pcVar19;
  bool bVar20;
  float fVar21;
  undefined8 uVar22;
  longlong lVar23;
  uint local_60;
  int *local_5c;
  int *local_58;
  CMap *local_54;
  int local_50;
  int *local_4c;
  undefined1 local_48 [4];
  CMap *local_44;
  CMap *local_40;
  CMap *local_3c;
  CMap *local_38;
  CMap *local_34;
  CMap *local_30;
  CMap *local_2c;
  CMap *local_28;
  undefined4 *local_24;
  int *local_20;
  CMap *local_1c;
  CMap *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00706c1d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  local_20 = in_ECX;
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca54f0) &&
     (FUN_006cebf4(&DAT_00ca54f0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar18 = DAT_00783650,
     DAT_00ca54f0 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca54f4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) =
         "CPathPtr CMapPathfinder::Calc1(CKPoint pnt1,CKPoint pnt2,int iOwner, bool bLines,bool bCanClimb)"
    ;
    *(int *)(&DAT_00773650 + iVar7) = iVar18;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca54f0);
  }
  local_40 = (CMap *)(DAT_00ca54f4 * 0x40);
  iVar18 = local_40[0x9897].mapFlagsB;
  iVar7 = FUN_0043fcc0();
  pCVar14 = local_40;
  *(int *)(iVar7 + *(int *)(iVar7 + 0x8000) * 4) = iVar18;
  *(int *)(iVar7 + 0x8000) = *(int *)(iVar7 + 0x8000) + 1;
  iVar18 = local_40[0x9897].mapFlagsC;
  if (iVar18 == 0) {
    uVar22 = FUN_006bd180();
    iVar18 = pCVar14[0x9897].mapFlagsC;
    pCVar14[0x9897].mapFlagsD = (int)uVar22;
    pCVar14[0x9897].mapFlagsE = (int)((ulonglong)uVar22 >> 0x20);
  }
  pCVar14[0x9897].mapFlagsC = iVar18 + 1;
  lVar23 = CONCAT44(DAT_00b836b4,DAT_00b836b0);
  local_8 = 1;
  if (DAT_00b836b0 == 0 && DAT_00b836b4 == 0) {
    lVar23 = FUN_006bd180();
  }
  __alldiv(lVar23 - CONCAT44(_DAT_00b836bc,_DAT_00b836b8),DAT_00b836c8,DAT_00b836cc);
  FUN_006f5260();
  FUN_006f514b();
  FUN_00449180();
  FUN_0043e3c0();
  if ((((((char)PTR_0077241c->mapFlags == '\0') || ((int)param_2 < PTR_0077241c->x0_8 + 0x28)) ||
       (PTR_0077241c->x1_8 + -0x28 <= (int)param_2)) ||
      (((int)param_3 < PTR_0077241c->y0_8 + 0x28 || (PTR_0077241c->y1_8 + -0x28 <= (int)param_3))))
     || (cVar6 = FUN_0040b8a0(&param_4,0x28), cVar6 != '\0')) {
LAB_0059fba5:
    *param_1 = 0;
    goto LAB_0059fbae;
  }
  if (*in_ECX == 0) {
    FUN_0059a560();
  }
  cVar6 = FUN_0059d600();
  if (cVar6 == '\0') {
    iVar18 = 1;
    do {
      local_40 = param_2;
      iVar7 = FUN_00592f10(PTR_0077241c);
      if ((*(char *)(iVar7 + 6) != -1) &&
         ((*(byte *)((((uint)(param_3->ownerIndex + iVar18 + -0x34) & 7) << 3 | (uint)local_40 & 7)
                     + 0x3c + iVar7) & 1) != 0)) {
        param_3 = (CMapCell *)(param_3->ownerIndex + iVar18 + -0x34);
        break;
      }
      local_40 = (CMap *)((int)&param_2->field_0x0 + iVar18);
      iVar7 = FUN_00592f10(PTR_0077241c);
      if ((*(char *)(iVar7 + 6) != -1) &&
         ((*(byte *)((((uint)param_3 & 7) << 3 | (uint)local_40 & 7) + 0x3c + iVar7) & 1) != 0)) {
        param_2 = (CMap *)((int)&param_2->field_0x0 + iVar18);
        break;
      }
      local_40 = (CMap *)((int)param_2 - iVar18);
      iVar7 = FUN_00592f10(PTR_0077241c);
      if ((*(char *)(iVar7 + 6) != -1) &&
         ((*(byte *)((((uint)param_3 & 7) << 3 | (uint)local_40 & 7) + 0x3c + iVar7) & 1) != 0)) {
        param_2 = (CMap *)((int)param_2 - iVar18);
        break;
      }
      local_40 = param_2;
      iVar7 = FUN_00592f10(PTR_0077241c);
      if ((*(char *)(iVar7 + 6) != -1) &&
         ((*(byte *)((((int)param_3 - iVar18 & 7U) << 3 | (uint)local_40 & 7) + 0x3c + iVar7) & 1)
          != 0)) {
        param_3 = (CMapCell *)((int)param_3 - iVar18);
        break;
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 < 0x21);
  }
  iVar18 = FUN_00592f10(PTR_0077241c);
  local_2c = param_4;
  if ((*(char *)(iVar18 + 6) == -1) ||
     ((*(byte *)((((uint)param_5 & 7) << 3 | (uint)param_4 & 7) + 0x3c + iVar18) & 1) == 0)) {
    iVar18 = 1;
    do {
      puVar3 = param_5->ownerIndex;
      local_2c = param_4;
      iVar7 = FUN_00592f10(PTR_0077241c);
      if ((*(char *)(iVar7 + 6) != -1) &&
         ((*(byte *)((((uint)(puVar3 + iVar18 + -0x34) & 7) << 3 | (uint)local_2c & 7) + 0x3c +
                    iVar7) & 1) != 0)) {
        param_5 = (CMapCell *)(param_5->ownerIndex + iVar18 + -0x34);
        break;
      }
      local_3c = (CMap *)((int)(iVar18 + (iVar18 >> 0x1f & 3U)) >> 2);
      uVar17 = (int)param_5 - (int)local_3c;
      local_40 = param_4;
      iVar7 = FUN_00592f10(PTR_0077241c);
      pCVar13 = param_5;
      if ((*(char *)(iVar7 + 6) != -1) &&
         (pCVar14 = local_3c,
         (*(byte *)(((uVar17 & 7) << 3 | (uint)local_40 & 7) + 0x3c + iVar7) & 1) != 0)) {
LAB_0059dbd7:
        param_5 = (CMapCell *)((int)param_5 - (int)pCVar14);
        break;
      }
      iVar7 = iVar18;
      if (iVar18 < 0) {
        iVar7 = iVar18 + 1;
      }
      local_28 = (CMap *)(iVar7 >> 1);
      local_40 = (CMap *)((int)&local_28->field_0x0 + (int)&param_4->field_0x0);
      iVar7 = FUN_00592f10(PTR_0077241c);
      pCVar4 = param_5;
      if ((*(char *)(iVar7 + 6) != -1) &&
         ((*(byte *)((((uint)pCVar13 & 7) << 3 | (uint)local_40 & 7) + 0x3c + iVar7) & 1) != 0)) {
        param_4 = (CMap *)((int)&local_28->field_0x0 + (int)&param_4->field_0x0);
        break;
      }
      local_40 = (CMap *)((int)param_4 - (int)local_28);
      iVar7 = FUN_00592f10(PTR_0077241c);
      if ((*(char *)(iVar7 + 6) != -1) &&
         ((*(byte *)((((uint)pCVar4 & 7) << 3 | (uint)local_40 & 7) + 0x3c + iVar7) & 1) != 0)) {
        param_4 = (CMap *)((int)param_4 - (int)local_28);
        break;
      }
      pCVar14 = local_28 + -1;
      puVar3 = param_5->ownerIndex;
      local_24 = (undefined4 *)(iVar18 / 3);
      local_40 = (CMap *)((int)&param_4->field_0x0 + (int)local_24);
      iVar7 = FUN_00592f10(PTR_0077241c);
      if ((*(char *)(iVar7 + 6) != -1) &&
         ((*(byte *)((((uint)(puVar3 + (int)&pCVar14->x0_8) & 7) << 3 | (uint)local_40 & 7) + 0x3c +
                    iVar7) & 1) != 0)) {
        param_4 = (CMap *)((int)&param_4->field_0x0 + (int)local_24);
        param_5 = (CMapCell *)
                  (((CMapCell *)(param_5->ownerIndex + -0x34))->ownerIndex + (int)&local_28[-1].x0_8
                  );
        break;
      }
      pCVar14 = local_28 + -1;
      puVar3 = param_5->ownerIndex;
      local_40 = (CMap *)((int)param_4 - (int)local_24);
      iVar7 = FUN_00592f10(PTR_0077241c);
      if ((*(char *)(iVar7 + 6) != -1) &&
         ((*(byte *)((((uint)(puVar3 + (int)&pCVar14->x0_8) & 7) << 3 | (uint)local_40 & 7) + 0x3c +
                    iVar7) & 1) != 0)) {
        param_4 = (CMap *)((int)param_4 - (int)local_24);
        param_5 = (CMapCell *)
                  (((CMapCell *)(param_5->ownerIndex + -0x34))->ownerIndex + (int)&local_28[-1].x0_8
                  );
        break;
      }
      local_30 = (CMap *)(iVar18 / 5);
      uVar17 = (int)param_5 - (int)local_30;
      local_40 = (CMap *)((int)&param_4->field_0x0 + (int)local_24);
      iVar7 = FUN_00592f10(PTR_0077241c);
      if ((*(char *)(iVar7 + 6) != -1) &&
         ((*(byte *)(((uVar17 & 7) << 3 | (uint)local_40 & 7) + 0x3c + iVar7) & 1) != 0)) {
        param_4 = (CMap *)((int)&param_4->field_0x0 + (int)local_24);
        pCVar14 = local_30;
        goto LAB_0059dbd7;
      }
      uVar17 = (int)param_5 - (int)local_30;
      local_40 = (CMap *)((int)param_4 - (int)local_24);
      iVar7 = FUN_00592f10(PTR_0077241c);
      if ((*(char *)(iVar7 + 6) != -1) &&
         ((*(byte *)(((uVar17 & 7) << 3 | (uint)local_40 & 7) + 0x3c + iVar7) & 1) != 0)) {
        param_4 = (CMap *)((int)param_4 - (int)local_24);
        pCVar14 = local_30;
        goto LAB_0059dbd7;
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 < 0xd);
    iVar18 = FUN_00592f10(PTR_0077241c);
    if ((*(char *)(iVar18 + 6) == -1) ||
       ((*(byte *)((((uint)param_5 & 7) << 3 | (uint)param_4 & 7) + 0x3c + iVar18) & 1) == 0))
    goto LAB_0059fba5;
  }
  while( true ) {
    pCVar14 = PTR_0077241c;
    local_40 = (CMap *)((int)&param_3->heightBlockIndex + 1);
    local_3c = param_2;
    local_30 = PTR_0077241c;
    iVar18 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= (int)param_2 >> 3) {
      iVar18 = (int)param_2 >> 3;
    }
    iVar7 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= (int)local_40 >> 3) {
      iVar7 = (int)local_40 >> 3;
    }
    iVar9 = PTR_0077241c->cellY1 + -1;
    if (iVar7 < PTR_0077241c->cellY1) {
      iVar9 = iVar7;
    }
    iVar7 = PTR_0077241c->cellX1 + -1;
    if (iVar18 < PTR_0077241c->cellX1) {
      iVar7 = iVar18;
    }
    iVar18 = (iVar9 * PTR_0077241c->mapWidth + iVar7) % PTR_0077241c->cellCountTotal;
    if ((iVar18 < 0) || (PTR_0077241c->cellCount <= iVar18)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar13 = pCVar14->cells;
    }
    else {
      pCVar13 = PTR_0077241c->cells + iVar18;
    }
    if ((pCVar13->sampleFlags[((uint)local_40 & 7) << 3 | (uint)local_3c & 7] & 2) == 0) break;
    param_3 = (CMapCell *)((int)&param_3->heightBlockIndex + 1);
  }
  while( true ) {
    pCVar14 = PTR_0077241c;
    pcVar19 = RaiseException_exref;
    local_40 = (CMap *)((int)&param_5->heightBlockIndex + 1);
    local_3c = param_4;
    local_30 = PTR_0077241c;
    iVar18 = PTR_0077241c->cellX0;
    if (PTR_0077241c->cellX0 <= (int)param_4 >> 3) {
      iVar18 = (int)param_4 >> 3;
    }
    iVar7 = PTR_0077241c->cellY0;
    if (PTR_0077241c->cellY0 <= (int)local_40 >> 3) {
      iVar7 = (int)local_40 >> 3;
    }
    iVar9 = PTR_0077241c->cellY1 + -1;
    if (iVar7 < PTR_0077241c->cellY1) {
      iVar9 = iVar7;
    }
    iVar7 = PTR_0077241c->cellX1 + -1;
    if (iVar18 < PTR_0077241c->cellX1) {
      iVar7 = iVar18;
    }
    iVar18 = (iVar9 * PTR_0077241c->mapWidth + iVar7) % PTR_0077241c->cellCountTotal;
    if ((iVar18 < 0) || (PTR_0077241c->cellCount <= iVar18)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar13 = pCVar14->cells;
    }
    else {
      pCVar13 = PTR_0077241c->cells + iVar18;
    }
    if ((pCVar13->sampleFlags[((uint)local_40 & 7) << 3 | (uint)local_3c & 7] & 2) == 0) break;
    param_5 = (CMapCell *)((int)&param_5->heightBlockIndex + 1);
  }
  local_3c = (CMap *)0x0;
  local_20[4] = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((param_4 == param_2) && (param_5 == param_3)) {
    param_8 = (CMap *)FUN_006ba810(0x37c);
    if (param_8 == (CMap *)0x0) {
      pCVar14 = (CMap *)0x0;
    }
    else {
      param_8->mapFlags0 = 0;
      *(undefined ***)param_8 = CPath::vftable;
      param_8->mapFlags1 = 0;
      param_8->mapFlags2 = 0;
      param_8->mapFlags3 = 0;
      param_8->cells = (CMapCell *)0x0;
      param_8->cellCount = 0;
      param_8->mapFlags4 = 0;
      LOCK();
      param_8->mapFlags0 = param_8->mapFlags0 + 1;
      UNLOCK();
      pCVar14 = param_8;
    }
    piVar11 = &pCVar14->mapFlags0;
    pCVar14->ownerBlocks = (void *)0x0;
    pCVar14->mapFlags3 = (int)param_2;
    pCVar14->cells = param_3;
    pCVar14->heightBlocks = (CHeightBlockArray *)0x0;
    pCVar14->cellCount = (int)param_2;
    pCVar14->mapFlags4 = (int)param_3;
    *param_1 = pCVar14;
    LOCK();
    *piVar11 = *piVar11 + 1;
    UNLOCK();
    LOCK();
    iVar18 = *piVar11;
    *piVar11 = iVar18 + -1;
    UNLOCK();
    if (iVar18 + -1 == 0) {
      (*(code *)**(undefined4 **)pCVar14)(1);
    }
    goto LAB_0059fbae;
  }
  pCVar14 = (CMap *)((int)((int)&param_2->field_0x0 + ((int)param_2 >> 0x1f & 7U)) >> 3);
  local_18 = (CMap *)((int)(param_3->ownerIndex + (((int)param_3 >> 0x1f & 7U) - 0x34)) >> 3);
  local_2c = (CMap *)((int)((int)&param_4->field_0x0 + ((int)param_4 >> 0x1f & 7U)) >> 3);
  local_30 = (CMap *)((int)(param_5->ownerIndex + (((int)param_5 >> 0x1f & 7U) - 0x34)) >> 3);
  local_1c = (CMap *)FUN_006ba810(0x38c);
  if (local_1c == (CMap *)0x0) {
    local_1c = (CMap *)0x0;
  }
  else {
    local_1c->mapFlags0 = 0;
    *(undefined ***)local_1c = CPath::vftable;
    local_1c->mapFlags1 = 0;
    local_1c->mapFlags2 = 0;
    local_1c->mapFlags3 = 0;
    local_1c->cells = (CMapCell *)0x0;
    local_1c->cellCount = 0;
    local_1c->mapFlags4 = 0;
  }
  if (local_1c != (CMap *)0x0) {
    LOCK();
    local_1c->mapFlags0 = local_1c->mapFlags0 + 1;
    UNLOCK();
  }
  local_1c->mapFlags3 = (int)param_2;
  local_1c->cells = param_3;
  local_11 = '\0';
  local_3c = local_1c;
  if ((local_2c == pCVar14) && (local_30 == local_18)) {
    local_11 = '\x01';
    iVar18 = FUN_00592f10(PTR_0077241c);
    pCVar14 = local_1c;
    local_1c->ownerBlocks = (void *)(uint)*(byte *)(iVar18 + 6);
    uVar17 = local_1c->mapFlags2;
    if ((uVar17 + 0x40 & 0xffffffc0) != (uVar17 + 0x3f & 0xffffffc0)) {
      iVar18 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                            0x9b);
      uVar17 = pCVar14->mapFlags2;
      pCVar14->mapFlags1 = iVar18;
    }
    pCVar14->mapFlags2 = uVar17 + 1;
    param_8 = (CMap *)uVar17;
    if (uVar17 + 1 <= uVar17) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar18 = pCVar14->mapFlags1;
    *(CMap **)(iVar18 + (int)param_8 * 8) = param_2;
    *(CMapCell **)(iVar18 + 4 + (int)param_8 * 8) = param_3;
    pCVar12 = (CMap *)pCVar14->mapFlags2;
    if (((uint)&pCVar12->mapArea8 & 0xffffffc0) !=
        ((uint)((int)&pCVar12->mapHeight8 + 3U) & 0xffffffc0)) {
      iVar18 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                            0x9b);
      pCVar12 = (CMap *)pCVar14->mapFlags2;
      pCVar14->mapFlags1 = iVar18;
    }
    pCVar14->mapFlags2 = (int)&pCVar12->field_0x1;
    param_8 = pCVar12;
    if (&pCVar12->field_0x1 <= pCVar12) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar18 = pCVar14->mapFlags1;
    *(CMap **)(iVar18 + (int)param_8 * 8) = param_4;
    *(CMapCell **)(iVar18 + 4 + (int)param_8 * 8) = param_5;
    pCVar14->heightBlocks = (CHeightBlockArray *)0x2;
    pCVar14->cellCount = (int)param_4;
    pCVar14->mapFlags4 = (int)param_5;
    goto LAB_0059e00f;
  }
  if ((char)param_8 == '\0') {
    if (&DAT_00000007 < param_6) {
      cVar6 = FUN_0059ab90(pCVar14,local_18,local_2c,local_30,param_9);
      goto LAB_0059e099;
    }
    cVar6 = FUN_0059bf90(pCVar14,local_18,local_2c,local_30,param_6,param_9);
    param_8 = (CMap *)CONCAT13(1,param_8._0_3_);
  }
  else if (&DAT_00000007 < param_6) {
    cVar6 = FUN_0059b670(pCVar14,local_18,local_2c,local_30,param_9);
LAB_0059e099:
    param_8 = (CMap *)((uint)param_8 & 0xffffff);
  }
  else {
    cVar6 = FUN_0059ca30(pCVar14,local_18,local_2c,local_30,param_6,param_9);
    param_8 = (CMap *)CONCAT13(1,param_8._0_3_);
  }
  if (cVar6 != '\0') {
    local_11 = '\x01';
    iVar18 = (int)((int)&pCVar14->field_0x0 + (int)local_18 * DAT_00b9bf20) % DAT_00b9bf28;
    if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar11 = DAT_00b9bf18;
    }
    else {
      piVar11 = DAT_00b9bf18 + iVar18;
    }
    local_1c->ownerBlocks = (void *)*piVar11;
    param_6 = &local_1c->mapFlags1;
    local_24 = (undefined4 *)FUN_00416630();
    if ((undefined4 *)param_6[1] <= local_24) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar18 = *param_6;
    *(CMap **)(iVar18 + (int)local_24 * 8) = param_2;
    *(CMapCell **)(iVar18 + 4 + (int)local_24 * 8) = param_3;
    local_1c->heightBlocks = (CHeightBlockArray *)0x1;
    iVar18 = (int)((int)&pCVar14->field_0x0 + (int)local_18 * DAT_00b9bf20) % DAT_00b9bf28;
    if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      param_9 = DAT_00b9bf18;
    }
    else {
      param_9 = DAT_00b9bf18 + iVar18;
    }
    param_9 = (int *)*param_9;
    bVar20 = param_8._3_1_ == '\0';
    local_28 = local_18;
    param_8 = pCVar14;
    if (bVar20) {
      do {
        if ((pCVar14 == local_2c) && (local_18 == local_30)) goto LAB_0059e891;
        local_38 = (CMap *)&local_18->field_0x1;
        iVar18 = (int)((int)&pCVar14->field_0x0 + (int)local_38 * DAT_00b9bf20) % DAT_00b9bf28;
        if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar11 = DAT_00b9bf18;
        }
        else {
          piVar11 = DAT_00b9bf18 + iVar18;
        }
        if ((*piVar11 < (int)param_9) &&
           (cVar6 = FUN_0059aad0(pCVar14,local_18,pCVar14,local_38), cVar6 != '\0')) {
          local_28 = local_38;
          iVar18 = (int)((int)&pCVar14->field_0x0 + (int)local_38 * DAT_00b9bf20) % DAT_00b9bf28;
          if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
            param_8 = pCVar14;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            param_9 = DAT_00b9bf18;
          }
          else {
            param_9 = DAT_00b9bf18 + iVar18;
            param_8 = pCVar14;
          }
          param_9 = (int *)*param_9;
        }
        iVar18 = (int)(&pCVar14->field_0x1 + (int)local_18 * DAT_00b9bf20) % DAT_00b9bf28;
        if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar11 = DAT_00b9bf18;
        }
        else {
          piVar11 = DAT_00b9bf18 + iVar18;
        }
        if ((*piVar11 < (int)param_9) &&
           (cVar6 = FUN_0059aad0(pCVar14,local_18,&pCVar14->field_0x1,local_18), cVar6 != '\0')) {
          param_8 = (CMap *)&pCVar14->field_0x1;
          local_28 = local_18;
          iVar18 = (int)(&pCVar14->field_0x1 + (int)local_18 * DAT_00b9bf20) % DAT_00b9bf28;
          if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            param_9 = DAT_00b9bf18;
          }
          else {
            param_9 = DAT_00b9bf18 + iVar18;
          }
          param_9 = (int *)*param_9;
        }
        iVar18 = (int)((int)local_18 * DAT_00b9bf20 + -1 + (int)pCVar14) % DAT_00b9bf28;
        if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar11 = DAT_00b9bf18;
        }
        else {
          piVar11 = DAT_00b9bf18 + iVar18;
        }
        if ((*piVar11 < (int)param_9) &&
           (cVar6 = FUN_0059aad0(pCVar14,local_18,(undefined1 *)((int)&pCVar14[-1].mapFlags5 + 3),
                                 local_18), cVar6 != '\0')) {
          param_8 = (CMap *)((int)&pCVar14[-1].mapFlags5 + 3);
          local_28 = local_18;
          iVar18 = (int)((int)local_18 * DAT_00b9bf20 + -1 + (int)pCVar14) % DAT_00b9bf28;
          if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            param_9 = DAT_00b9bf18;
          }
          else {
            param_9 = DAT_00b9bf18 + iVar18;
          }
          param_9 = (int *)*param_9;
        }
        local_38 = (CMap *)((int)&local_18[-1].mapFlags5 + 3);
        iVar18 = (int)((int)&pCVar14->field_0x0 + (int)local_38 * DAT_00b9bf20) % DAT_00b9bf28;
        if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar11 = DAT_00b9bf18;
        }
        else {
          piVar11 = DAT_00b9bf18 + iVar18;
        }
        if ((*piVar11 < (int)param_9) &&
           (cVar6 = FUN_0059aad0(pCVar14,local_18,pCVar14,local_38), cVar6 != '\0')) {
          local_28 = local_38;
          iVar18 = (int)((int)&pCVar14->field_0x0 + (int)local_38 * DAT_00b9bf20) % DAT_00b9bf28;
          if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
            param_8 = pCVar14;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            param_9 = (int *)*DAT_00b9bf18;
          }
          else {
            param_9 = (int *)DAT_00b9bf18[iVar18];
            param_8 = pCVar14;
          }
LAB_0059e7b6:
          if (local_18 == local_28) goto LAB_0059e8cf;
        }
        else if (pCVar14 == param_8) goto LAB_0059e7b6;
        local_18 = local_28;
        local_34 = param_8;
        iVar18 = FUN_00592f10(PTR_0077241c);
        local_24 = (undefined4 *)param_6[1];
        local_38 = (CMap *)((uint)(local_24 + 0x10) & 0xffffffc0);
        if (local_38 != (CMap *)((int)local_24 + 0x3fU & 0xffffffc0)) {
          iVar7 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                               ,0x9b);
          local_24 = (undefined4 *)param_6[1];
          *param_6 = iVar7;
        }
        param_6[1] = (int)((int)local_24 + 1U);
        if ((undefined4 *)((int)local_24 + 1U) <= local_24) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *(uint *)(*param_6 + (int)local_24 * 8) = (*(byte *)(iVar18 + 0x12) & 7) + (int)param_8 * 8;
        if ((undefined4 *)param_6[1] <= local_24) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *(uint *)(*param_6 + 4 + (int)local_24 * 8) =
             (*(byte *)(iVar18 + 0x12) >> 3 & 7) + (int)local_28 * 8;
        local_1c->heightBlocks = (CHeightBlockArray *)&local_1c->heightBlocks->field_0x1;
        pCVar14 = local_34;
      } while( true );
    }
    do {
      if ((pCVar14 == local_2c) && (local_18 == local_30)) goto LAB_0059e891;
      local_34 = (CMap *)&local_18->field_0x1;
      iVar18 = (int)((int)&pCVar14->field_0x0 + (int)local_34 * DAT_00b9bf20) % DAT_00b9bf28;
      if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar11 = DAT_00b9bf18;
      }
      else {
        piVar11 = DAT_00b9bf18 + iVar18;
      }
      if ((*piVar11 < (int)param_9) &&
         (cVar6 = FUN_0059aa20(pCVar14,local_18,pCVar14,local_34,local_18), cVar6 != '\0')) {
        local_28 = local_34;
        iVar18 = (int)((int)&pCVar14->field_0x0 + (int)local_34 * DAT_00b9bf20) % DAT_00b9bf28;
        if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
          param_8 = pCVar14;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          param_9 = DAT_00b9bf18;
        }
        else {
          param_9 = DAT_00b9bf18 + iVar18;
          param_8 = pCVar14;
        }
        param_9 = (int *)*param_9;
      }
      iVar18 = (int)(&pCVar14->field_0x1 + (int)local_18 * DAT_00b9bf20) % DAT_00b9bf28;
      if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar11 = DAT_00b9bf18;
      }
      else {
        piVar11 = DAT_00b9bf18 + iVar18;
      }
      if ((*piVar11 < (int)param_9) &&
         (cVar6 = FUN_0059aa20(pCVar14,local_18,&pCVar14->field_0x1,local_18,local_18),
         cVar6 != '\0')) {
        param_8 = (CMap *)&pCVar14->field_0x1;
        local_28 = local_18;
        iVar18 = (int)(&pCVar14->field_0x1 + (int)local_18 * DAT_00b9bf20) % DAT_00b9bf28;
        if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          param_9 = DAT_00b9bf18;
        }
        else {
          param_9 = DAT_00b9bf18 + iVar18;
        }
        param_9 = (int *)*param_9;
      }
      iVar18 = (int)((int)local_18 * DAT_00b9bf20 + -1 + (int)pCVar14) % DAT_00b9bf28;
      if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar11 = DAT_00b9bf18;
      }
      else {
        piVar11 = DAT_00b9bf18 + iVar18;
      }
      if ((*piVar11 < (int)param_9) &&
         (cVar6 = FUN_0059aa20(pCVar14,local_18,(undefined1 *)((int)&pCVar14[-1].mapFlags5 + 3),
                               local_18,local_18), cVar6 != '\0')) {
        param_8 = (CMap *)((int)&pCVar14[-1].mapFlags5 + 3);
        local_28 = local_18;
        iVar18 = (int)((int)local_18 * DAT_00b9bf20 + -1 + (int)pCVar14) % DAT_00b9bf28;
        if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          param_9 = DAT_00b9bf18;
        }
        else {
          param_9 = DAT_00b9bf18 + iVar18;
        }
        param_9 = (int *)*param_9;
      }
      local_34 = (CMap *)((int)&local_18[-1].mapFlags5 + 3);
      iVar18 = (int)((int)&pCVar14->field_0x0 + (int)local_34 * DAT_00b9bf20) % DAT_00b9bf28;
      if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar11 = DAT_00b9bf18;
      }
      else {
        piVar11 = DAT_00b9bf18 + iVar18;
      }
      if ((*piVar11 < (int)param_9) &&
         (cVar6 = FUN_0059aa20(pCVar14,local_18,pCVar14,local_34,local_18), cVar6 != '\0')) {
        local_28 = local_34;
        iVar18 = (int)((int)&pCVar14->field_0x0 + (int)local_34 * DAT_00b9bf20) % DAT_00b9bf28;
        if ((iVar18 < 0) || (DAT_00b9bf1c <= iVar18)) {
          param_8 = pCVar14;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          param_9 = (int *)*DAT_00b9bf18;
        }
        else {
          param_9 = (int *)DAT_00b9bf18[iVar18];
          param_8 = pCVar14;
        }
LAB_0059e431:
        if (local_18 == local_28) goto LAB_0059e978;
      }
      else if (pCVar14 == param_8) goto LAB_0059e431;
      local_18 = local_28;
      local_34 = param_8;
      iVar18 = FUN_00592f10(PTR_0077241c);
      local_24 = (undefined4 *)param_6[1];
      local_38 = (CMap *)((uint)(local_24 + 0x10) & 0xffffffc0);
      if (local_38 != (CMap *)((int)local_24 + 0x3fU & 0xffffffc0)) {
        iVar7 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                             0x9b);
        local_24 = (undefined4 *)param_6[1];
        *param_6 = iVar7;
      }
      param_6[1] = (int)((int)local_24 + 1U);
      if ((undefined4 *)((int)local_24 + 1U) <= local_24) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(uint *)(*param_6 + (int)local_24 * 8) = (*(byte *)(iVar18 + 0x12) & 7) + (int)param_8 * 8;
      if ((undefined4 *)param_6[1] <= local_24) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(uint *)(*param_6 + 4 + (int)local_24 * 8) =
           (*(byte *)(iVar18 + 0x12) >> 3 & 7) + (int)local_28 * 8;
      local_1c->heightBlocks = (CHeightBlockArray *)&local_1c->heightBlocks->field_0x1;
      pCVar14 = local_34;
    } while( true );
  }
  goto LAB_0059e00f;
LAB_0059e8cf:
  iVar18 = 0;
  if (0 < local_20[4]) {
    do {
      if ((iVar18 < 0) || (local_20[1] <= iVar18)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar14 = (CMap *)*local_20;
        param_8 = pCVar14;
      }
      else {
        pCVar14 = (CMap *)*local_20;
        param_8 = (CMap *)((int)&pCVar14->field_0x0 + iVar18 * 2 * 4);
      }
      if ((iVar18 < 0) || (local_20[1] <= iVar18)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar11 = (int *)*local_20;
      }
      else {
        piVar11 = (int *)((int)&pCVar14->field_0x0 + iVar18 * 2 * 4);
      }
      iVar7 = (piVar11[1] * DAT_00b9bf20 + *(int *)param_8) % DAT_00b9bf28;
      if ((iVar7 < 0) || (DAT_00b9bf1c <= iVar7)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar11 = DAT_00b9bf18;
      }
      else {
        piVar11 = DAT_00b9bf18 + iVar7;
      }
      *piVar11 = 0x7fffffff;
      iVar18 = iVar18 + 1;
    } while (iVar18 < local_20[4]);
  }
LAB_0059e978:
  *param_1 = 0;
  LOCK();
  iVar18 = local_1c->mapFlags0 + -1;
  local_1c->mapFlags0 = iVar18;
  UNLOCK();
  if (iVar18 == 0) {
    (*(code *)**(undefined4 **)local_1c)(1);
  }
  goto LAB_0059fbae;
LAB_0059e891:
  puVar16 = local_24;
  if ((undefined4 *)param_6[1] <= local_24) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar18 = *param_6;
  *(CMap **)(iVar18 + (int)puVar16 * 8) = param_4;
  *(CMapCell **)(iVar18 + 4 + (int)puVar16 * 8) = param_5;
  local_1c->cellCount = (int)param_4;
  local_1c->mapFlags4 = (int)param_5;
LAB_0059e00f:
  iVar18 = 0;
  if (0 < local_20[4]) {
    do {
      if ((iVar18 < 0) || (local_20[1] <= iVar18)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar14 = (CMap *)*local_20;
        param_8 = pCVar14;
      }
      else {
        pCVar14 = (CMap *)*local_20;
        param_8 = (CMap *)((int)&pCVar14->field_0x0 + iVar18 * 2 * 4);
      }
      if ((iVar18 < 0) || (local_20[1] <= iVar18)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar11 = (int *)*local_20;
      }
      else {
        piVar11 = (int *)((int)&pCVar14->field_0x0 + iVar18 * 2 * 4);
      }
      iVar7 = (piVar11[1] * DAT_00b9bf20 + *(int *)param_8) % DAT_00b9bf28;
      if ((iVar7 < 0) || (DAT_00b9bf1c <= iVar7)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar11 = DAT_00b9bf18;
      }
      else {
        piVar11 = DAT_00b9bf18 + iVar7;
      }
      *piVar11 = 0x7fffffff;
      iVar18 = iVar18 + 1;
    } while (iVar18 < local_20[4]);
  }
  if (local_11 == '\0') {
    *param_1 = 0;
    if (local_1c != (CMap *)0x0) {
      LOCK();
      iVar18 = local_1c->mapFlags0 + -1;
      local_1c->mapFlags0 = iVar18;
      UNLOCK();
      if (iVar18 == 0) {
        (*(code *)**(undefined4 **)local_1c)(1);
      }
    }
  }
  else {
    local_24 = (undefined4 *)FUN_006ba810(0x45a);
    if (local_24 == (undefined4 *)0x0) {
      local_24 = (undefined4 *)0x0;
    }
    else {
      local_24[1] = 0;
      *local_24 = CPath::vftable;
      local_24[2] = 0;
      local_24[3] = 0;
      local_24[4] = 0;
      local_24[5] = 0;
      local_24[6] = 0;
      local_24[7] = 0;
    }
    if (local_24 != (undefined4 *)0x0) {
      LOCK();
      local_24[1] = local_24[1] + 1;
      UNLOCK();
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    param_6 = (int *)0x0;
    local_24[4] = local_1c->mapFlags3;
    local_24[5] = local_1c->cells;
    local_24[6] = local_1c->cellCount;
    local_24[7] = local_1c->mapFlags4;
    local_24[8] = local_1c->ownerBlocks;
    local_24[9] = 0;
    if (local_1c->mapFlags2 != 1 && -1 < local_1c->mapFlags2 + -1) {
      do {
        puVar16 = local_24;
        if ((uint)local_1c->mapFlags2 <= param_6) {
          (*pcVar19)(0xc000008c,1,0,0);
        }
        param_8 = (CMap *)((int)param_6 * 8);
        FUN_0059a5b0(&local_60,local_1c->mapFlags1 + (int)param_8);
        param_6 = (int *)((int)param_6 + 1);
        if ((uint)local_1c->mapFlags2 <= param_6) {
          (*pcVar19)(0xc000008c,1,0,0);
        }
        FUN_0059a5b0(&local_58,local_1c->mapFlags1 + (int)param_8 + 8);
        uVar17 = puVar16[3];
        if ((uVar17 + 0x40 & 0xffffffc0) != (uVar17 + 0x3f & 0xffffffc0)) {
          uVar8 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                               ,0x9b);
          puVar16[2] = uVar8;
          uVar17 = puVar16[3];
        }
        param_8 = (CMap *)uVar17;
        puVar16[3] = (int)param_8 + 1U;
        if ((int)param_8 + 1U <= param_8) {
          (*pcVar19)(0xc000008c,1,0,0);
        }
        pCVar14 = PTR_0077241c;
        iVar18 = puVar16[2];
        *(uint *)(iVar18 + (int)param_8 * 8) = local_60;
        *(int **)(iVar18 + 4 + (int)param_8 * 8) = local_5c;
        param_8 = pCVar14;
        iVar18 = pCVar14->cellX0;
        if (pCVar14->cellX0 <= (int)local_60 >> 3) {
          iVar18 = (int)local_60 >> 3;
        }
        iVar7 = pCVar14->cellY0;
        if (pCVar14->cellY0 <= (int)local_5c >> 3) {
          iVar7 = (int)local_5c >> 3;
        }
        iVar9 = pCVar14->cellY1 + -1;
        if (iVar7 < pCVar14->cellY1) {
          iVar9 = iVar7;
        }
        iVar7 = pCVar14->cellX1 + -1;
        if (iVar18 < pCVar14->cellX1) {
          iVar7 = iVar18;
        }
        iVar18 = (iVar9 * pCVar14->mapWidth + iVar7) % pCVar14->cellCountTotal;
        if ((iVar18 < 0) || (pCVar14->cellCount <= iVar18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar13 = pCVar14->cells;
          pCVar14 = PTR_0077241c;
        }
        else {
          pCVar13 = pCVar14->cells + iVar18;
        }
        param_8 = pCVar14;
        if ((pCVar13->sampleFlags[((uint)local_5c & 7) << 3 | local_60 & 7] & 10) != 0) {
          param_9 = local_58;
          local_40 = local_54;
          iVar18 = pCVar14->cellX0;
          if (pCVar14->cellX0 <= (int)local_58 >> 3) {
            iVar18 = (int)local_58 >> 3;
          }
          iVar7 = pCVar14->cellY0;
          if (pCVar14->cellY0 <= (int)local_54 >> 3) {
            iVar7 = (int)local_54 >> 3;
          }
          iVar9 = pCVar14->cellY1 + -1;
          if (iVar7 < pCVar14->cellY1) {
            iVar9 = iVar7;
          }
          iVar7 = pCVar14->cellX1 + -1;
          if (iVar18 < pCVar14->cellX1) {
            iVar7 = iVar18;
          }
          iVar18 = (iVar9 * pCVar14->mapWidth + iVar7) % pCVar14->cellCountTotal;
          if ((iVar18 < 0) || (pCVar14->cellCount <= iVar18)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar13 = pCVar14->cells;
          }
          else {
            pCVar13 = pCVar14->cells + iVar18;
          }
          puVar16 = local_24;
          if ((pCVar13->sampleFlags[((uint)local_40 & 7) << 3 | (uint)param_9 & 7] & 10) != 0) {
            uVar17 = (int)(local_60 - (int)param_9) >> 0x1f;
            uVar15 = (int)local_5c - (int)local_40 >> 0x1f;
            if ((float)(int)(((int)local_5c - (int)local_40 ^ uVar15) - uVar15) * 1.5 <=
                (float)(int)((local_60 - (int)param_9 ^ uVar17) - uVar17)) {
              iVar18 = (int)param_9 - local_60;
              param_9 = (int *)(float)((int)local_40 - (int)local_5c);
              param_8 = (CMap *)(float)iVar18;
              fVar21 = (float)param_9 * (float)param_9 + (float)param_8 * (float)param_8 + 0.0;
              FUN_0040b7e0();
              puVar16 = local_24;
              param_8 = (CMap *)((float)param_8 / fVar21);
              param_9 = (int *)((float)param_9 / fVar21);
              local_2c = (CMap *)(fVar21 - 2.0);
              local_38 = (CMap *)0x40000000;
              if (2.0 <= (float)local_2c) {
                do {
                  local_50 = (int)ROUND((float)local_38 * (float)param_8) + local_60;
                  local_40 = (CMap *)((float)local_38 * (float)param_9);
                  DAT_00772dd8 = (int)ROUND((float)local_40);
                  local_4c = (int *)((int)local_5c + DAT_00772dd8);
                  puVar10 = (undefined4 *)FUN_0059a5b0(local_48,&local_50);
                  local_34 = (CMap *)*puVar10;
                  local_30 = (CMap *)puVar10[1];
                  pCVar14 = (CMap *)puVar16[3];
                  if (((uint)&pCVar14->mapArea8 & 0xffffffc0) !=
                      ((uint)((int)&pCVar14->mapHeight8 + 3U) & 0xffffffc0)) {
                    uVar8 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                         ,0x9b);
                    pCVar14 = (CMap *)puVar16[3];
                    puVar16[2] = uVar8;
                  }
                  puVar16[3] = &pCVar14->field_0x1;
                  local_40 = pCVar14;
                  if (&pCVar14->field_0x1 <= pCVar14) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  iVar18 = puVar16[2];
                  local_38 = (CMap *)((float)local_38 + 2.0);
                  *(CMap **)(iVar18 + (int)local_40 * 8) = local_34;
                  *(CMap **)(iVar18 + 4 + (int)local_40 * 8) = local_30;
                } while ((float)local_38 <= (float)local_2c);
              }
            }
            else {
              param_8 = (CMap *)((int)((int)param_9 + local_60) / 2);
              param_9 = (int *)((int)((int)&local_40->field_0x0 + (int)local_5c) / 2);
              uVar17 = local_24[3];
              if ((uVar17 + 0x40 & 0xffffffc0) != (uVar17 + 0x3f & 0xffffffc0)) {
                uVar8 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                     ,0x9b);
                uVar17 = puVar16[3];
                puVar16[2] = uVar8;
              }
              puVar16[3] = uVar17 + 1;
              if (uVar17 + 1 <= uVar17) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar18 = local_24[2];
              *(CMap **)(iVar18 + uVar17 * 8) = param_8;
              *(int **)(iVar18 + 4 + uVar17 * 8) = param_9;
            }
          }
        }
        pcVar19 = RaiseException_exref;
      } while ((int)param_6 < local_1c->mapFlags2 + -1);
    }
    puVar16 = local_24;
    param_9 = local_24 + 2;
    param_8 = (CMap *)FUN_00416630();
    if ((uint)local_1c->mapFlags2 <= param_6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_38 = (CMap *)local_1c->mapFlags1;
    if ((uint)puVar16[3] <= param_8) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar10 = local_24;
    iVar18 = puVar16[2];
    local_3c = (CMap *)0x0;
    *(undefined4 *)(iVar18 + (int)param_8 * 8) = *(undefined4 *)((int)local_38 + (int)param_6 * 8);
    *(undefined4 *)(iVar18 + 4 + (int)param_8 * 8) =
         *(undefined4 *)((int)local_38 + 4 + (int)param_6 * 8);
    local_24[9] = local_24[3];
    LOCK();
    iVar18 = local_1c->mapFlags0 + -1;
    local_1c->mapFlags0 = iVar18;
    UNLOCK();
    if (iVar18 == 0) {
      (*(code *)**(undefined4 **)local_1c)(1);
    }
    local_44 = (CMap *)0x0;
    local_8 = CONCAT31(local_8._1_3_,4);
    if ((char)param_7 == '\0') {
      piVar11 = puVar10 + 1;
      *param_1 = puVar10;
      LOCK();
      *piVar11 = *piVar11 + 1;
      UNLOCK();
      LOCK();
      iVar18 = *piVar11;
      *piVar11 = *piVar11 + -1;
      UNLOCK();
      if (iVar18 == 1) {
        (**(code **)*puVar10)(1);
      }
      FUN_0043fd30();
      ExceptionList = local_10;
      return param_1;
    }
    local_30 = (CMap *)FUN_006ba810(0x4ef);
    if (local_30 == (CMap *)0x0) {
      local_30 = (CMap *)0x0;
    }
    else {
      local_30->mapFlags0 = 0;
      *(undefined ***)local_30 = CPath::vftable;
      local_30->mapFlags1 = 0;
      local_30->mapFlags2 = 0;
      local_30->mapFlags3 = 0;
      local_30->cells = (CMapCell *)0x0;
      local_30->cellCount = 0;
      local_30->mapFlags4 = 0;
    }
    pCVar14 = local_30;
    if (local_30 != (CMap *)0x0) {
      LOCK();
      local_30->mapFlags0 = local_30->mapFlags0 + 1;
      UNLOCK();
    }
    local_30->mapFlags3 = puVar10[4];
    local_30->cells = (CMapCell *)puVar10[5];
    local_30->cellCount = puVar10[6];
    local_30->mapFlags4 = puVar10[7];
    piVar11 = &local_30->mapFlags1;
    local_30->ownerBlocks = (void *)puVar10[8];
    param_8 = (CMap *)piVar11;
    local_44 = local_30;
    param_7 = (CMap *)FUN_00416630();
    if ((uint)param_9[1] <= param_7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    param_6 = (int *)((int)param_7 * 8);
    puVar16 = (undefined4 *)(*param_9 + (int)param_7 * 8);
    bVar20 = (uint)pCVar14->mapFlags2 <= param_7;
    param_7 = (CMap *)puVar16;
    if (bVar20) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar16 = (undefined4 *)(*piVar11 + (int)param_6);
    *puVar16 = *(undefined4 *)param_7;
    puVar16[1] = *(undefined4 *)((int)param_7 + 4);
    pCVar14 = (CMap *)FUN_00416630();
    param_7 = pCVar14;
    if ((CMap *)param_9[1] <= pCVar14) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    param_6 = (int *)((int)pCVar14 * 8);
    local_38 = (CMap *)(*param_9 + (int)param_6);
    if ((CMap *)param_8->mapFlags0 <= pCVar14) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar16 = (undefined4 *)(*(int *)param_8 + (int)pCVar14 * 8);
    *puVar16 = *(undefined4 *)local_38;
    puVar16[1] = *(undefined4 *)((int)local_38 + 4);
    local_30->heightBlocks = (CHeightBlockArray *)0x2;
    pCVar12 = (CMap *)param_8->mapFlags0;
    if (pCVar12 <= pCVar14) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar12 = (CMap *)param_8->mapFlags0;
    }
    local_1c = *(CMap **)param_8;
    local_34 = (CMap *)((int)&local_1c->field_0x0 + (int)pCVar14 * 2 * 4);
    local_18 = (CMap *)((int)&pCVar14[-1].mapFlags5 + 3);
    if (pCVar12 <= local_18) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
      pCVar12 = (CMap *)param_8->mapFlags0;
    }
    pCVar14 = param_7;
    local_2c = (CMap *)((int)&local_1c->field_0x0 + (int)local_18 * 2 * 4);
    if (pCVar12 <= param_7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
      pCVar12 = (CMap *)param_8->mapFlags0;
    }
    local_28 = (CMap *)((int)&local_1c->field_0x0 + (int)pCVar14 * 2 * 4);
    if (pCVar12 <= local_18) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
      pCVar12 = (CMap *)param_8->mapFlags0;
    }
    pCVar14 = param_7;
    local_20 = (int *)((int)&local_1c->field_0x0 + (int)local_18 * 2 * 4);
    if (pCVar12 <= param_7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
      pCVar12 = (CMap *)param_8->mapFlags0;
    }
    local_40 = (CMap *)((int)&local_1c->field_0x0 + (int)pCVar14 * 2 * 4);
    if (pCVar12 <= local_18) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
      pCVar12 = (CMap *)param_8->mapFlags0;
    }
    pCVar14 = param_7;
    local_38 = (CMap *)((int)&local_1c->field_0x0 + (int)local_18 * 2 * 4);
    if (pCVar12 <= param_7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
      pCVar12 = (CMap *)param_8->mapFlags0;
    }
    pCVar5 = local_1c;
    if (pCVar12 <= local_18) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
    }
    local_34 = (CMap *)(((&pCVar5->mapFlags0)[(int)pCVar14 * 2] -
                        (&local_1c->mapFlags0)[(int)local_18 * 2]) *
                        (*(int *)((int)local_40 + 4) - *(int *)((int)local_38 + 4)) +
                       (*(int *)local_34 - *(int *)local_2c) * (*(int *)local_28 - *local_20));
    pCVar14 = (CMap *)param_8->mapFlags0;
    if (pCVar14 <= param_7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
      pCVar14 = (CMap *)param_8->mapFlags0;
    }
    local_38 = (CMap *)((int)param_6 + (int)local_1c);
    if (local_18 < pCVar14) {
      pCVar12 = *(CMap **)param_8;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar12 = *(CMap **)param_8;
      pCVar14 = (CMap *)param_8->mapFlags0;
      local_1c = pCVar12;
    }
    local_2c = (CMap *)((int)&pCVar12->field_0x0 + (int)local_18 * 2 * 4);
    if (pCVar14 <= param_7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
      pCVar14 = (CMap *)param_8->mapFlags0;
    }
    local_40 = (CMap *)((int)param_6 + (int)local_1c);
    if (pCVar14 <= local_18) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
    }
    pCVar14 = (CMap *)param_8->mapFlags0;
    local_40 = (CMap *)((float)((*(int *)local_40 - *(int *)(*(int *)param_8 + (int)local_18 * 8)) *
                               (*(int *)local_38 - *(int *)local_2c)) / (float)(int)local_34);
    if (pCVar14 <= param_7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
      pCVar14 = (CMap *)param_8->mapFlags0;
    }
    local_2c = (CMap *)((int)param_6 + (int)local_1c);
    if (local_18 < pCVar14) {
      pCVar12 = *(CMap **)param_8;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar12 = *(CMap **)param_8;
      pCVar14 = (CMap *)param_8->mapFlags0;
      local_1c = pCVar12;
    }
    local_28 = (CMap *)((int)&pCVar12->field_0x0 + (int)local_18 * 2 * 4);
    if (pCVar14 <= param_7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_1c = *(CMap **)param_8;
      pCVar14 = (CMap *)param_8->mapFlags0;
    }
    local_38 = (CMap *)((int)param_6 + (int)local_1c);
    if (pCVar14 <= local_18) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_20 = (int *)0x2;
    local_28 = (CMap *)((float)((local_38->mapFlags0 -
                                *(int *)(*(int *)param_8 + 4 + (int)local_18 * 8)) *
                               (local_2c->mapFlags0 - *(int *)((int)local_28 + 4))) /
                       (float)(int)local_34);
    piVar11 = param_9;
    if (2 < (int)local_24[3]) {
      do {
        if ((int *)piVar11[1] <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        pCVar14 = param_7;
        local_1c = (CMap *)((int)local_20 * 8);
        local_54 = (CMap *)((int)&local_1c->field_0x0 + *piVar11);
        if ((CMap *)param_8->mapFlags0 <= param_7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_5c = (int *)(*(int *)param_8 + (int)pCVar14 * 8);
        if ((int *)param_9[1] <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_4c = (int *)((int)&local_1c->field_0x0 + *param_9);
        if ((CMap *)param_8->mapFlags0 <= pCVar14) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_2c = (CMap *)(*(int *)param_8 + (int)pCVar14 * 8);
        if ((int *)param_9[1] <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_18 = (CMap *)((int)&local_1c->field_0x0 + *param_9);
        if ((CMap *)param_8->mapFlags0 <= pCVar14) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_34 = (CMap *)(*(int *)param_8 + (int)pCVar14 * 8);
        if ((int *)param_9[1] <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_38 = (CMap *)((int)&local_1c->field_0x0 + *param_9);
        if ((CMap *)param_8->mapFlags0 <= pCVar14) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar18 = (*(int *)((int)local_38 + 4) - *(int *)(*(int *)param_8 + 4 + (int)param_6)) *
                 (local_18->mapFlags0 - local_34->mapFlags0) +
                 (*local_4c - *(int *)local_2c) * (*(int *)local_54 - *local_5c);
        if ((int *)param_9[1] <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_54 = (CMap *)((int)&local_1c->field_0x0 + *param_9);
        if ((CMap *)param_8->mapFlags0 <= param_7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_4c = (int *)(*(int *)param_8 + (int)param_6);
        if ((int *)param_9[1] <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_5c = (int *)((int)&local_1c->field_0x0 + *param_9);
        if ((CMap *)param_8->mapFlags0 <= param_7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_38 = (CMap *)((float)((*local_5c - *(int *)((int)param_6 + *(int *)param_8)) *
                                   (*(int *)local_54 - *local_4c)) / (float)iVar18);
        if ((int *)param_9[1] <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_54 = (CMap *)((int)&local_1c->field_0x0 + *param_9);
        if ((CMap *)param_8->mapFlags0 <= param_7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_4c = (int *)(*(int *)param_8 + (int)param_6);
        if ((int *)param_9[1] <= local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_5c = (int *)((int)&local_1c->field_0x0 + *param_9);
        if ((CMap *)param_8->mapFlags0 <= param_7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar11 = param_9;
        pCVar14 = param_8;
        fVar21 = (float)((*(int *)((int)local_5c + 4) - *(int *)(*(int *)param_8 + 4 + (int)param_6)
                         ) * (local_54->mapFlags0 - *(int *)((int)local_4c + 4))) / (float)iVar18;
        if ((((float)local_40 == (float)local_38) && ((float)local_28 == fVar21)) ||
           ((-(float)local_40 == (float)local_38 && (-(float)local_28 == fVar21)))) {
          if ((int *)param_9[1] <= local_20) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          local_38 = (CMap *)((int)&local_1c->field_0x0 + *piVar11);
          if ((CMap *)param_8->mapFlags0 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar18 = *(int *)param_8;
          *(int *)(iVar18 + (int)param_6) = *(int *)local_38;
          ((int *)(iVar18 + (int)param_6))[1] = local_38->mapFlags0;
        }
        else {
          FUN_004126f0(1);
          param_7 = (CMap *)(pCVar14->mapFlags0 + -1);
          if ((int *)param_9[1] <= local_20) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          param_6 = (int *)((int)&local_1c->field_0x0 + *param_9);
          if ((CMap *)pCVar14->mapFlags0 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar18 = *(int *)pCVar14;
          piVar11 = (int *)((int)param_7 * 8);
          *(undefined4 *)(iVar18 + (int)piVar11) = *param_6;
          ((undefined4 *)(iVar18 + (int)piVar11))[1] = param_6[1];
          local_18 = (CMap *)pCVar14->mapFlags0;
          param_6 = piVar11;
          if (local_18 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_18 = (CMap *)pCVar14->mapFlags0;
          }
          pCVar12 = param_8;
          local_28 = *(CMap **)pCVar14;
          local_34 = (CMap *)((int)param_6 + (int)local_28);
          local_1c = (CMap *)((int)&param_7[-1].mapFlags5 + 3);
          if (local_18 <= local_1c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_28 = *(CMap **)pCVar12;
            local_18 = (CMap *)pCVar12->mapFlags0;
          }
          pCVar14 = param_8;
          local_2c = (CMap *)((int)local_28 + (int)((int)&param_7[-1].mapFlags5 + 3) * 8);
          if (local_18 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_28 = *(CMap **)pCVar14;
            local_18 = (CMap *)pCVar14->mapFlags0;
          }
          local_40 = (CMap *)((int)param_6 + (int)local_28);
          if (local_18 <= local_1c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_28 = *(CMap **)pCVar14;
            local_18 = (CMap *)pCVar14->mapFlags0;
          }
          local_38 = (CMap *)((int)local_28 + (int)local_1c * 8);
          if (local_18 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_28 = *(CMap **)pCVar14;
            local_18 = (CMap *)pCVar14->mapFlags0;
          }
          local_54 = (CMap *)((int)param_6 + (int)local_28);
          if (local_18 <= local_1c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_28 = *(CMap **)pCVar14;
            local_18 = (CMap *)pCVar14->mapFlags0;
          }
          local_4c = (int *)((int)local_28 + (int)local_1c * 8);
          if (local_18 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_28 = *(CMap **)pCVar14;
            local_18 = (CMap *)pCVar14->mapFlags0;
          }
          local_5c = (int *)((int)param_6 + (int)local_28);
          if (local_18 <= local_1c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_28 = *(CMap **)pCVar14;
            local_18 = (CMap *)pCVar14->mapFlags0;
          }
          local_5c = (int *)((*(int *)((int)local_5c + 4) -
                             *(int *)((int)local_28 + 4 + (int)local_1c * 8)) *
                            (*(int *)((int)local_54 + 4) - *(int *)((int)local_4c + 4)));
          iVar18 = (int)local_5c +
                   (*(int *)local_40 - *(int *)local_38) * (*(int *)local_34 - *(int *)local_2c);
          pCVar12 = local_28;
          pCVar14 = local_18;
          if (local_18 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar12 = (CMap *)*(int *)param_8;
            pCVar14 = (CMap *)param_8->mapFlags0;
          }
          local_54 = (CMap *)((int)param_6 + (int)pCVar12);
          if (pCVar14 <= local_1c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar12 = *(CMap **)param_8;
            pCVar14 = (CMap *)param_8->mapFlags0;
          }
          local_4c = (int *)((int)pCVar12 + (int)local_1c * 8);
          if (pCVar14 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar12 = *(CMap **)param_8;
            pCVar14 = (CMap *)param_8->mapFlags0;
          }
          local_5c = (int *)((int)param_6 + (int)pCVar12);
          if (pCVar14 <= local_1c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar12 = *(CMap **)param_8;
          }
          local_40 = (CMap *)((float)((*local_5c - *(int *)((int)pCVar12 + (int)local_1c * 8)) *
                                     (*(int *)local_54 - *local_4c)) / (float)iVar18);
          if ((CMap *)param_8->mapFlags0 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar7 = *(int *)param_8;
          local_54 = (CMap *)((int)param_6 + iVar7);
          if ((CMap *)param_8->mapFlags0 <= local_1c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar7 = *(int *)param_8;
          }
          local_4c = (int *)(iVar7 + (int)local_1c * 8);
          if ((CMap *)param_8->mapFlags0 <= param_7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar7 = *(int *)param_8;
          }
          local_5c = (int *)((int)param_6 + iVar7);
          if ((CMap *)param_8->mapFlags0 <= local_1c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar7 = *(int *)param_8;
          }
          iVar9 = *(int *)((int)local_5c + 4);
          iVar7 = *(int *)(iVar7 + 4 + (int)local_1c * 8);
          iVar1 = local_54->mapFlags0;
          iVar2 = *(int *)((int)local_4c + 4);
          local_30->heightBlocks = (CHeightBlockArray *)&local_30->heightBlocks->field_0x1;
          local_28 = (CMap *)((float)((iVar9 - iVar7) * (iVar1 - iVar2)) / (float)iVar18);
          piVar11 = param_9;
        }
        local_20 = (int *)((int)local_20 + 1);
      } while ((int)local_20 < (int)local_24[3]);
    }
    LOCK();
    iVar18 = local_24[1] + -1;
    local_24[1] = iVar18;
    UNLOCK();
    if (iVar18 == 0) {
      (**(code **)*local_24)(1);
    }
    FUN_00449180();
    FUN_0043e3c0();
    piVar11 = &local_30->mapFlags0;
    *param_1 = local_30;
    LOCK();
    *piVar11 = *piVar11 + 1;
    UNLOCK();
    LOCK();
    iVar18 = *piVar11;
    *piVar11 = *piVar11 + -1;
    UNLOCK();
    if (iVar18 == 1) {
      (*(code *)**(undefined4 **)local_30)(1);
    }
  }
LAB_0059fbae:
  FUN_0043fd30();
  ExceptionList = local_10;
  return param_1;
}

