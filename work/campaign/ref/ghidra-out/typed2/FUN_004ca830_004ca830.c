
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004ca830(CSceneRenderer *this)

{
  int *piVar1;
  byte bVar2;
  CHeightBlockArray *pCVar3;
  CSceneRenderer *pCVar4;
  undefined1 uVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  CHeightBlock **ppCVar11;
  CMapCell *pCVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  CMap *pCVar15;
  int iVar16;
  byte *pbVar17;
  int iVar18;
  CHeightBlock *pCVar19;
  int iVar20;
  uint uVar21;
  double dVar22;
  int in_stack_00000004;
  int in_stack_00000008;
  CMap **ppCVar23;
  char *pcVar24;
  int local_9c [3];
  float local_90 [3];
  int *local_84;
  CSceneRenderer *local_80;
  undefined8 local_7c;
  CMap *local_74;
  CMap *local_70;
  int *local_6c;
  int *local_68;
  CMap *local_64;
  char local_5d;
  uint local_5c;
  uint local_58;
  int *local_54;
  int *local_50;
  uint local_4c;
  int local_48;
  CMap *local_44;
  int local_40;
  CMap *local_3c;
  float local_38;
  float fStack_34;
  int iStack_30;
  int iStack_2c;
  int local_28;
  CMapCell *pCStack_24;
  int iStack_20;
  int iStack_1c;
  void *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006fead8;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_40 = in_stack_00000004;
  local_48 = in_stack_00000008;
  local_80 = this;
  local_50 = (int *)FUN_006ba810(0x477,local_14);
  local_7c = (double)CONCAT44(local_50,(undefined4)local_7c);
  local_8 = 0;
  if (local_50 == (int *)0x0) {
    local_50 = (int *)0x0;
  }
  else {
    local_84 = local_50 + 2;
    _eh_vector_constructor_iterator_(local_84,4,3,FUN_00453ef0,FUN_00406f00);
  }
  local_8 = 0xffffffff;
  piVar1 = local_50 + 2;
  *(undefined1 *)(local_50 + 5) = 1;
  puVar14 = (undefined4 *)*piVar1;
  *piVar1 = 0;
  if (puVar14 != (undefined4 *)0x0) {
    LOCK();
    iVar18 = puVar14[1] + -1;
    puVar14[1] = iVar18;
    UNLOCK();
    if (iVar18 == 0) {
      (**(code **)*puVar14)(1);
    }
  }
  puVar14 = (undefined4 *)local_50[3];
  local_50[3] = 0;
  if (puVar14 != (undefined4 *)0x0) {
    LOCK();
    iVar18 = puVar14[1] + -1;
    puVar14[1] = iVar18;
    UNLOCK();
    if (iVar18 == 0) {
      (**(code **)*puVar14)(1);
    }
  }
  puVar14 = (undefined4 *)local_50[4];
  local_50[4] = 0;
  if (puVar14 != (undefined4 *)0x0) {
    LOCK();
    iVar18 = puVar14[1] + -1;
    puVar14[1] = iVar18;
    UNLOCK();
    if (iVar18 == 0) {
      (**(code **)*puVar14)(1);
    }
  }
  pCVar15 = PTR_0077241c;
  *local_50 = in_stack_00000004;
  local_50[1] = local_48;
  uVar7 = *(uint *)this;
  local_4c = uVar7;
  local_44 = (CMap *)FUN_00592f10(pCVar15);
  local_74 = (CMap *)(uint)*(ushort *)((int)local_44 + 0x18);
  this->cornerRGBA[0] = (uint)*(byte *)((int)local_44 + 7) << 8;
  local_64 = local_74;
  if (uVar7 < 8) {
    pCVar15 = (CMap *)((int)local_44 + local_4c);
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar15 = local_44;
  }
  local_7c = 1.3;
  if (*(byte *)((int)pCVar15 + 0x34) - 1 < 0x7f) {
    this->cornerRGBA[4] = 0;
    uVar7 = 0;
  }
  else {
    uVar7 = *(byte *)((int)pCVar15 + 0x34) - 0x80;
    this->cornerRGBA[4] = uVar7;
    if (0 < (int)uVar7) {
      dVar22 = (double)(int)uVar7;
      uVar7 = 0x80;
      if ((int)(dVar22 * 1.3) < 0x80) {
        uVar7 = (int)(dVar22 * 1.3);
      }
      this->cornerRGBA[4] = uVar7;
    }
    uVar7 = uVar7 * 2;
    if ((0 < (int)uVar7) && (0xff < (int)uVar7)) {
      uVar7 = 0xff;
    }
  }
  pCVar15 = PTR_0077241c;
  iVar18 = 0xff - ((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f));
  if (iVar18 < 1) {
    iVar18 = 0;
  }
  iVar8 = local_40 + 1;
  this->cornerRGBA[8] = (uint)((float)iVar18 / 255.0);
  local_44 = (CMap *)FUN_00592f10(pCVar15);
  local_6c = (int *)(uint)*(ushort *)((int)local_44 + 0x18);
  this->cornerRGBA[1] = (uint)*(byte *)((int)local_44 + 7) << 8;
  local_68 = local_6c;
  if (local_4c < 8) {
    pCVar15 = (CMap *)((int)local_44 + local_4c);
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar15 = local_44;
  }
  if (*(byte *)((int)pCVar15 + 0x34) - 1 < 0x7f) {
    this->cornerRGBA[5] = 0;
    uVar7 = 0;
  }
  else {
    uVar7 = *(byte *)((int)pCVar15 + 0x34) - 0x80;
    this->cornerRGBA[5] = uVar7;
    if (0 < (int)uVar7) {
      dVar22 = (double)(int)uVar7;
      uVar7 = 0x80;
      if ((int)(dVar22 * local_7c) < 0x80) {
        uVar7 = (int)(dVar22 * local_7c);
      }
      this->cornerRGBA[5] = uVar7;
    }
    uVar7 = uVar7 * 2;
    if ((0 < (int)uVar7) && (0xff < (int)uVar7)) {
      uVar7 = 0xff;
    }
  }
  pCVar15 = PTR_0077241c;
  iVar18 = 0xff - ((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f));
  if (iVar18 < 1) {
    iVar18 = 0;
  }
  iVar9 = local_48 + 1;
  this->cornerRGBA[9] = (uint)((float)iVar18 / 255.0);
  local_44 = (CMap *)FUN_00592f10(pCVar15);
  local_5c = (uint)*(ushort *)((int)local_44 + 0x18);
  this->cornerRGBA[2] = (uint)*(byte *)((int)local_44 + 7) << 8;
  local_58 = local_5c;
  if (local_4c < 8) {
    pCVar15 = (CMap *)((int)local_44 + local_4c);
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar15 = local_44;
  }
  if (*(byte *)((int)pCVar15 + 0x34) - 1 < 0x7f) {
    this->cornerRGBA[6] = 0;
    uVar7 = 0;
  }
  else {
    uVar7 = *(byte *)((int)pCVar15 + 0x34) - 0x80;
    this->cornerRGBA[6] = uVar7;
    if (0 < (int)uVar7) {
      dVar22 = (double)(int)uVar7;
      uVar7 = 0x80;
      if ((int)(dVar22 * local_7c) < 0x80) {
        uVar7 = (int)(dVar22 * local_7c);
      }
      this->cornerRGBA[6] = uVar7;
    }
    uVar7 = uVar7 * 2;
    if ((0 < (int)uVar7) && (0xff < (int)uVar7)) {
      uVar7 = 0xff;
    }
  }
  pCVar15 = PTR_0077241c;
  iVar18 = 0xff - ((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f));
  if (iVar18 < 1) {
    iVar18 = 0;
  }
  this->cornerRGBA[10] = (uint)((float)iVar18 / 255.0);
  local_70 = (CMap *)FUN_00592f10(pCVar15);
  local_44 = (CMap *)(uint)(ushort)local_70->cellCount;
  this->cornerRGBA[3] = (uint)*(byte *)((int)&local_70->mapFlags0 + 3) << 8;
  local_3c = local_44;
  if (local_4c < 8) {
    pCVar15 = (CMap *)(&local_70->field_0x0 + local_4c);
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    pCVar15 = local_70;
  }
  uVar7 = (uint)(byte)pCVar15->mapFlags8;
  if (uVar7 - 1 < 0x7f) {
    this->cornerRGBA[7] = 0;
    uVar7 = 0;
    local_54 = (int *)0x0;
  }
  else {
    local_54 = (int *)(uVar7 - 0x80);
    this->cornerRGBA[7] = (uint)local_54;
    if (0 < (int)local_54) {
      dVar22 = (double)(int)local_54;
      local_54 = (int *)&DAT_00000080;
      if ((int)(dVar22 * local_7c) < 0x80) {
        local_54 = (int *)(int)(dVar22 * local_7c);
      }
      this->cornerRGBA[7] = (uint)local_54;
    }
    uVar7 = (int)local_54 * 2;
    if ((0 < (int)uVar7) && (0xff < (int)uVar7)) {
      uVar7 = 0xff;
    }
  }
  iVar18 = 0xff - ((uVar7 ^ (int)uVar7 >> 0x1f) - ((int)uVar7 >> 0x1f));
  if (iVar18 < 1) {
    iVar18 = 0;
  }
  this->cornerRGBA[0xb] = (uint)((float)iVar18 / 255.0);
  if ((((this->cornerRGBA[4] == 0xffffff80) && (this->cornerRGBA[6] == 0xffffff80)) &&
      (this->cornerRGBA[5] == 0xffffff80)) && (local_54 == (int *)0xffffff80)) {
    FUN_004c6b20(this);
    *(undefined1 *)(local_50 + 6) = 1;
    goto LAB_004cba15;
  }
  *(undefined1 *)(local_50 + 6) = 0;
  if ((((byte)local_44 & (byte)local_5c & (byte)local_6c & (byte)local_74 & 3) == 3) &&
     (this->flag1 != '\0')) goto LAB_004cba15;
  local_70 = (CMap *)((uint)local_64 & 3);
  local_54 = (int *)CONCAT31(local_54._1_3_,local_70 == (CMap *)0x3);
  pCVar15 = (CMap *)((uint)local_64 & 0xfffffffc);
  if (local_70 != (CMap *)0x3) {
    pCVar15 = local_64;
  }
  local_7c = (double)CONCAT44(pCVar15,(undefined4)local_7c);
  local_4c = (uint)local_68 & 3;
  local_5c = CONCAT31(local_5c._1_3_,local_4c == 3);
  local_84 = (int *)((uint)local_68 & 0xfffffffc);
  if (local_4c != 3) {
    local_84 = local_68;
  }
  local_68 = (int *)(local_58 & 3);
  local_6c = (int *)CONCAT31(local_6c._1_3_,local_68 == (int *)0x3);
  local_58 = (uint)local_3c & 3;
  local_74 = (CMap *)CONCAT31(local_74._1_3_,local_58 == 3);
  FUN_00592f10(PTR_0077241c);
  local_90[2] = 12.0;
  local_90[1] = (float)local_48 + 0.5;
  local_90[0] = (float)local_40 + 0.5;
  FUN_004c7d80(local_80);
  local_90[2] = 0.0;
  local_90[0] = 0.0;
  local_90[1] = 0.0;
  local_9c[0] = 0;
  local_9c[1] = 0;
  local_9c[2] = 0;
  local_3c = (CMap *)0x2;
  do {
    piVar10 = (int *)FUN_00592f10(PTR_0077241c);
    iVar18 = *piVar10;
    local_64 = (CMap *)&PTR_0077241c->heightBlocks->data;
    if ((iVar18 < 0) || (PTR_0077241c->heightBlocks->count <= iVar18)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar19 = *(CHeightBlock **)local_64;
    }
    else {
      pCVar19 = *(CHeightBlock **)local_64 + iVar18;
    }
    local_64 = (CMap *)(float)(pCVar19->cornerLevels & 0xf);
    if ((CMap *)0x2 < local_3c) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    FUN_004c4ae0(local_80);
    if (DAT_00768369 == '\0') {
      local_64 = (CMap *)&DAT_00000012;
      local_44 = (CMap *)&DAT_00000012;
      if (local_3c < (CMap *)0x3) {
        piVar10 = local_9c + (int)local_3c;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar10 = local_9c;
      }
      *piVar10 = 0;
    }
    else {
      if ((CMap *)0x2 < local_3c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_004c4c50(local_80);
      local_64 = local_44;
    }
    pCVar4 = local_80;
    local_3c = (CMap *)((int)&local_3c[-1].mapFlags5 + 3);
  } while (-1 < (int)local_3c);
  uVar7 = local_80->cornerRGBA[4];
  local_80->field_0x5 = 0;
  if (((((int)uVar7 < 0) || ((int)local_80->cornerRGBA[6] < 0)) ||
      ((int)local_80->cornerRGBA[5] < 0)) || ((int)local_80->cornerRGBA[7] < 0)) {
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  local_80->field_0x4 = uVar5;
  cVar6 = '\0';
  local_5d = '\0';
  local_80->cornerRGBA[0xc] = 0xff;
  local_80->cornerRGBA[0xd] = 0xff;
  local_80->cornerRGBA[0xe] = 0xff;
  local_80->cornerRGBA[0xf] = 0xff;
  if (local_80->flag1 != '\0') {
    piVar10 = (int *)FUN_00592f10(PTR_0077241c);
    iVar18 = *piVar10;
    ppCVar11 = &PTR_0077241c->heightBlocks->data;
    local_7c = (double)CONCAT44(ppCVar11,(undefined4)local_7c);
    if ((iVar18 < 0) || (PTR_0077241c->heightBlocks->count <= iVar18)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar19 = (CHeightBlock *)*local_7c._4_4_;
    }
    else {
      pCVar19 = *ppCVar11 + iVar18;
    }
    pCVar15 = local_64;
    if (local_70 == (CMap *)0x3) {
      if (local_4c == 3) {
        if (local_68 == (int *)0x3) {
          if (local_58 != 3) {
            uVar7 = (uint)pCVar19->heights[0x3f] - (uint)pCVar19->heights[0x24];
            uVar21 = (int)uVar7 >> 0x1f;
            iVar18 = (uVar7 ^ uVar21) - uVar21;
            goto joined_r0x004cb050;
          }
        }
        else if (local_58 == 3) {
          uVar7 = (uint)pCVar19->heights[0x38] - (uint)pCVar19->heights[0x24];
          uVar21 = (int)uVar7 >> 0x1f;
          iVar18 = (uVar7 ^ uVar21) - uVar21;
joined_r0x004cb050:
          if (3 < iVar18) goto LAB_004cb1bf;
        }
        goto LAB_004cb110;
      }
      if (((local_68 != (int *)0x3) || (local_58 != 3)) ||
         (uVar7 = (uint)pCVar19->heights[7] - (uint)pCVar19->heights[0x24],
         uVar21 = (int)uVar7 >> 0x1f, (int)((uVar7 ^ uVar21) - uVar21) < 4)) goto LAB_004cb110;
LAB_004cb1bf:
      FUN_004ca080(local_40,local_48,local_50,local_90,local_9c,pCVar15,local_54,local_5c,local_6c,
                   local_74);
      goto LAB_004cba15;
    }
    if (((local_4c == 3) && (local_68 == (int *)0x3)) && (local_58 == 3)) {
      uVar7 = (uint)pCVar19->heights[0] - (uint)pCVar19->heights[0x24];
      uVar21 = (int)uVar7 >> 0x1f;
      iVar18 = (uVar7 ^ uVar21) - uVar21;
      goto joined_r0x004cb050;
    }
LAB_004cb110:
    if ((pCVar4->field_0x4 == '\0') || (local_64 != (CMap *)&DAT_00000015)) {
      if (local_70 == (CMap *)0x3) goto LAB_004cb1e8;
LAB_004cb1f6:
      cVar6 = local_5d;
      if (local_4c == 3) {
LAB_004cb1fc:
        pCVar4->cornerRGBA[0xd] = 0;
        cVar6 = '\x01';
      }
LAB_004cb20d:
      if (local_68 == (int *)0x3) goto LAB_004cb213;
    }
    else {
      if (local_70 == (CMap *)0x3) {
        if (local_4c == 3) {
          if ((local_68 != (int *)0x3) && (local_58 != 3)) {
            bVar2 = pCVar19->heights[7];
LAB_004cb1a1:
            uVar7 = (uint)bVar2 - (uint)pCVar19->heights[0x24];
            uVar21 = (int)uVar7 >> 0x1f;
            if (3 < (int)((uVar7 ^ uVar21) - uVar21)) goto LAB_004cb1b1;
          }
        }
        else if ((local_68 == (int *)0x3) && (local_58 != 3)) {
          bVar2 = pCVar19->heights[0x3f];
          goto LAB_004cb1a1;
        }
LAB_004cb1e8:
        pCVar4->cornerRGBA[0xc] = 0;
        local_5d = '\x01';
        goto LAB_004cb1f6;
      }
      if (local_4c == 3) {
        if (((local_68 != (int *)0x3) && (local_58 == 3)) &&
           (uVar7 = (uint)pCVar19->heights[0x38] - (uint)pCVar19->heights[0x24],
           uVar21 = (int)uVar7 >> 0x1f, 3 < (int)((uVar7 ^ uVar21) - uVar21))) {
LAB_004cb1b1:
          pCVar15 = (CMap *)&DAT_00000015;
          goto LAB_004cb1bf;
        }
        goto LAB_004cb1fc;
      }
      cVar6 = local_5d;
      if (local_68 != (int *)0x3) goto LAB_004cb20d;
      if ((local_58 == 3) &&
         (uVar7 = (uint)pCVar19->heights[0] - (uint)pCVar19->heights[0x24],
         uVar21 = (int)uVar7 >> 0x1f, 3 < (int)((uVar7 ^ uVar21) - uVar21))) goto LAB_004cb1b1;
LAB_004cb213:
      pCVar4->cornerRGBA[0xe] = 0;
      cVar6 = '\x01';
    }
    if (local_58 == 3) {
      pCVar4->cornerRGBA[0xf] = 0;
      cVar6 = '\x01';
    }
  }
  if (((local_64 == (CMap *)&DAT_00000015) && (pCVar4->field_0x4 != '\0')) && (cVar6 == '\0')) {
    local_64 = (CMap *)0x16;
    pCVar4->field_0x5 = 1;
  }
  local_5c = 0;
  uVar7 = local_58;
  do {
    local_70 = PTR_0077241c;
    iVar18 = local_40;
    if (local_40 < PTR_0077241c->cellX0) {
      iVar18 = PTR_0077241c->cellX0;
    }
    iVar20 = PTR_0077241c->cellX1 + -1;
    if (iVar18 < PTR_0077241c->cellX1) {
      iVar20 = iVar18;
    }
    iVar18 = local_48;
    if (local_48 < PTR_0077241c->cellY0) {
      iVar18 = PTR_0077241c->cellY0;
    }
    iVar16 = PTR_0077241c->cellY1 + -1;
    if (iVar18 < PTR_0077241c->cellY1) {
      iVar16 = iVar18;
    }
    iVar18 = (iVar16 * PTR_0077241c->mapWidth + iVar20) % PTR_0077241c->cellCountTotal;
    if ((iVar18 < 0) || (PTR_0077241c->cellCount <= iVar18)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar12 = local_70->cells;
    }
    else {
      pCVar12 = PTR_0077241c->cells + iVar18;
    }
    iVar18 = pCVar12->heightBlockIndex;
    puVar13 = &PTR_0077241c->heightBlocks->field_0x18;
    local_7c._4_4_ = (undefined4 *)puVar13;
    if ((iVar18 < 0) || (*(int *)&PTR_0077241c->heightBlocks->field_0x1c <= iVar18)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      local_44 = (CMap *)*local_7c._4_4_;
    }
    else {
      local_44 = (CMap *)(*(int *)puVar13 + iVar18 * 0xc);
    }
    if (local_5c < 3) {
      local_44 = (CMap *)((int)local_44 + local_5c * 4);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_68 = *(int **)local_44;
    pCVar3 = PTR_0077241c->heightBlocks;
    local_6c = (int *)*local_68;
    local_44 = (CMap *)(pCVar3 + 1);
    iVar18 = local_68[5];
    local_54 = (int *)&pCVar3[1].field_0xc;
    if ((iVar18 < 0) || ((int)pCVar3[1].data <= iVar18)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar20 = *local_54;
      iVar18 = local_68[5];
      local_4c = *(uint *)(iVar20 + 4);
      if (-1 < iVar18) goto LAB_004cb396;
LAB_004cb3a0:
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar14 = (undefined4 *)*local_54;
    }
    else {
      iVar20 = *local_54;
      local_4c = *(uint *)(iVar20 + 4 + iVar18 * 8);
LAB_004cb396:
      if (local_54[1] <= iVar18) goto LAB_004cb3a0;
      puVar14 = (undefined4 *)(iVar20 + iVar18 * 8);
    }
    local_7c = (double)CONCAT44(*puVar14,(undefined4)local_7c);
    if (local_4c != 0) {
      ppCVar23 = &local_3c;
      pcVar24 = "GetBlock";
      FUN_0044d010(ppCVar23,"GetBlock");
      FUN_0044d570(ppCVar23,pcVar24);
      local_8 = 1;
      if (local_5c < 3) {
        piVar10 = piVar1 + local_5c;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar10 = piVar1;
      }
      puVar14 = (undefined4 *)*piVar10;
      *piVar10 = (int)local_3c;
      if (local_3c != (CMap *)0x0) {
        LOCK();
        local_3c->mapFlags0 = local_3c->mapFlags0 + 1;
        UNLOCK();
      }
      if (puVar14 != (undefined4 *)0x0) {
        LOCK();
        iVar18 = puVar14[1] + -1;
        puVar14[1] = iVar18;
        UNLOCK();
        if (iVar18 == 0) {
          (**(code **)*puVar14)(1);
        }
      }
      if (local_3c == (CMap *)0x0) {
        local_8 = 0xffffffff;
      }
      else {
        *(undefined1 *)(local_50 + 5) = 0;
        if (local_5c < 3) {
          piVar10 = local_9c + local_5c;
          local_3c->mapHeight8 = (int)local_90[local_5c];
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_3c->mapHeight8 = (int)local_90[0];
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar10 = local_9c;
        }
        local_3c->mapArea8 = *piVar10;
        local_3c->mapFlags3 = (int)local_64;
        local_3c->mapFlags2 = 4;
        local_3c->mapFlags1 = 0x14;
        local_3c->cells = (CMapCell *)0xff;
        local_3c->mapWidth8 = 0;
        local_3c->mapFlags8 = 0;
        local_3c->mapFlags7 = 0;
        local_3c->mapFlags6 = 0;
        *(undefined4 *)&local_3c->field_0x28 = 0;
        local_3c->heightBlocks = (CHeightBlockArray *)0x0;
        local_3c->ownerBlocks = (void *)0x0;
        local_3c->mapFlags4 = 0;
        local_3c->cellCount = 0;
        local_84 = (int *)FUN_006ba810(0x528);
        if (local_84 == (undefined4 *)0x0) {
          puVar14 = (undefined4 *)local_3c->mapWidth;
          local_3c->mapWidth = 0;
        }
        else {
          _DAT_0076a2f4 = _DAT_0076a2f4 + 1;
          local_84[1] = 0;
          *local_84 = (int)CVectorBuffer::vftable;
          local_84[7] = 0;
          *(undefined1 *)(local_84 + 0xc) = 0;
          *(undefined2 *)(local_84 + 2) = 0;
          local_84[3] = 0;
          local_84[10] = 0;
          local_84[9] = 0;
          local_84[0xb] = 0;
          local_84[8] = 0x1c2;
          local_84[5] = 0;
          *(undefined1 *)(local_84 + 6) = 0;
          local_84[4] = 0;
          local_84[0xd] = 0;
          puVar14 = (undefined4 *)local_3c->mapWidth;
          local_3c->mapWidth = (int)local_84;
          if (local_84 != (undefined4 *)0x0) {
            LOCK();
            local_84[1] = local_84[1] + 1;
            UNLOCK();
          }
        }
        if (puVar14 != (undefined4 *)0x0) {
          LOCK();
          iVar18 = puVar14[1] + -1;
          puVar14[1] = iVar18;
          UNLOCK();
          if (iVar18 == 0) {
            (**(code **)*puVar14)(1);
          }
        }
        *(int *)&local_80->field_0x1314 = *(int *)&local_80->field_0x1314 + (int)local_4c / 3;
        FUN_0045fd00(0x2c2,local_6c,0);
        if (((longlong)local_7c < 0) || (local_44->mapFlags0 <= (int)local_7c._4_4_)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_44 = *(CMap **)local_44;
        }
        else {
          local_44 = (CMap *)(*(int *)local_44 + (int)local_7c._4_4_ * 2);
        }
        iVar18 = local_3c->mapWidth;
        if ((*(int *)(iVar18 + 0x28) != 0) && (*(char *)(iVar18 + 9) == '\0')) {
          FUN_006ba940();
        }
        *(CMap **)(iVar18 + 0x28) = local_44;
        *(uint *)(iVar18 + 0x2c) = local_4c;
        *(undefined1 *)(iVar18 + 9) = 1;
        iVar18 = local_3c->mapWidth;
        *(int *)(iVar18 + 0x10) = *(int *)(iVar18 + 0x10) + 1;
        if ((0 < *(int *)(iVar18 + 0x10)) && (*(int **)(iVar18 + 0x14) != (int *)0x0)) {
          piVar10 = (int *)**(int **)(iVar18 + 0x14);
          if (piVar10 == (int *)0x0) {
            pCVar15 = (CMap *)0x0;
          }
          else {
            local_74 = (CMap *)0x0;
            uVar21 = (**(code **)(*piVar10 + 0x10))(0x1821,&local_74,0);
            pCVar15 = local_74;
            local_58 = uVar7;
            if (uVar7 != uVar21) {
              uVar7 = uVar21;
              local_58 = uVar21;
            }
          }
          *(CMap **)(iVar18 + 0xc) = pCVar15;
          *(undefined4 *)(iVar18 + 0x34) = 0;
        }
        local_44 = *(CMap **)(iVar18 + 0xc);
        local_84 = *(int **)(iVar18 + 0x24);
        iVar18 = local_40;
        if (local_40 < PTR_0077241c->cellX0) {
          iVar18 = PTR_0077241c->cellX0;
        }
        iVar20 = PTR_0077241c->cellX1 + -1;
        if (iVar18 < PTR_0077241c->cellX1) {
          iVar20 = iVar18;
        }
        iVar18 = local_48;
        if (local_48 < PTR_0077241c->cellY0) {
          iVar18 = PTR_0077241c->cellY0;
        }
        iVar16 = PTR_0077241c->cellY1 + -1;
        if (iVar18 < PTR_0077241c->cellY1) {
          iVar16 = iVar18;
        }
        iVar18 = (iVar16 * PTR_0077241c->mapWidth + iVar20) % PTR_0077241c->cellCountTotal;
        if ((iVar18 < 0) || (PTR_0077241c->cellCount <= iVar18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar18 = local_40;
        if (local_40 < PTR_0077241c->cellX0) {
          iVar18 = PTR_0077241c->cellX0;
        }
        local_7c = (double)CONCAT44(iVar18,(undefined4)local_7c);
        iVar20 = PTR_0077241c->cellY0;
        if (PTR_0077241c->cellY0 <= iVar9) {
          iVar20 = iVar9;
        }
        iVar16 = PTR_0077241c->cellY1 + -1;
        if (iVar20 < PTR_0077241c->cellY1) {
          iVar16 = iVar20;
        }
        iVar20 = PTR_0077241c->cellX1 + -1;
        if (iVar18 < PTR_0077241c->cellX1) {
          iVar20 = iVar18;
        }
        iVar18 = (iVar16 * PTR_0077241c->mapWidth + iVar20) % PTR_0077241c->cellCountTotal;
        if ((iVar18 < 0) || (PTR_0077241c->cellCount <= iVar18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar18 = PTR_0077241c->cellX0;
        if (PTR_0077241c->cellX0 <= iVar8) {
          iVar18 = iVar8;
        }
        iVar20 = PTR_0077241c->cellX1 + -1;
        if (iVar18 < PTR_0077241c->cellX1) {
          iVar20 = iVar18;
        }
        iVar18 = local_48;
        if (local_48 < PTR_0077241c->cellY0) {
          iVar18 = PTR_0077241c->cellY0;
        }
        iVar16 = PTR_0077241c->cellY1 + -1;
        if (iVar18 < PTR_0077241c->cellY1) {
          iVar16 = iVar18;
        }
        iVar18 = (iVar16 * PTR_0077241c->mapWidth + iVar20) % PTR_0077241c->cellCountTotal;
        if ((iVar18 < 0) || (PTR_0077241c->cellCount <= iVar18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar18 = PTR_0077241c->cellX0;
        if (PTR_0077241c->cellX0 <= iVar8) {
          iVar18 = iVar8;
        }
        iVar20 = PTR_0077241c->cellY0;
        if (PTR_0077241c->cellY0 <= iVar9) {
          iVar20 = iVar9;
        }
        local_7c = (double)CONCAT44(iVar18,(undefined4)local_7c);
        iVar16 = PTR_0077241c->cellY1 + -1;
        if (iVar20 < PTR_0077241c->cellY1) {
          iVar16 = iVar20;
        }
        iVar20 = PTR_0077241c->cellX1 + -1;
        if (iVar18 < PTR_0077241c->cellX1) {
          iVar20 = iVar18;
        }
        iVar18 = (iVar16 * PTR_0077241c->mapWidth + iVar20) % PTR_0077241c->cellCountTotal;
        if ((iVar18 < 0) || (PTR_0077241c->cellCount <= iVar18)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar10 = local_68;
        iVar18 = 0;
        if (0 < (int)local_6c) {
          local_70 = local_44;
          do {
            FUN_00462b40(iVar18,&local_38);
            if (iVar18 < piVar10[4]) {
              pbVar17 = (byte *)(piVar10[3] + iVar18);
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pbVar17 = (byte *)piVar10[3];
            }
            if (DAT_00b9bed4 <= (int)(uint)*pbVar17) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            FUN_004cc040(local_80);
            local_38 = local_38 + (float)local_40;
            fStack_34 = fStack_34 + (float)local_48;
            pCVar15 = local_70;
            if ((int)local_84 <= iVar18) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              pCVar15 = local_44;
            }
            local_70 = (CMap *)&local_70->heightBlocks;
            iVar18 = iVar18 + 1;
            *(float *)pCVar15 = local_38;
            pCVar15->mapFlags0 = (int)fStack_34;
            pCVar15->mapFlags1 = iStack_30;
            pCVar15->mapFlags2 = iStack_2c;
            pCVar15->mapFlags3 = local_28;
            pCVar15->cells = pCStack_24;
            pCVar15->cellCount = iStack_20;
            pCVar15->mapFlags4 = iStack_1c;
            pCVar15->ownerBlocks = local_18;
            uVar7 = local_58;
          } while (iVar18 < (int)local_6c);
        }
        iVar18 = local_3c->mapWidth;
        piVar10 = (int *)(iVar18 + 0x10);
        *piVar10 = *piVar10 + -1;
        if ((*piVar10 == 0) && (*(int **)(iVar18 + 0x14) != (int *)0x0)) {
          piVar10 = (int *)**(int **)(iVar18 + 0x14);
          if (piVar10 != (int *)0x0) {
            (**(code **)(*piVar10 + 0x18))();
          }
          *(undefined4 *)(iVar18 + 0xc) = 0;
        }
        local_8 = 0xffffffff;
        if (local_3c != (CMap *)0x0) {
          LOCK();
          iVar18 = local_3c->mapFlags0 + -1;
          local_3c->mapFlags0 = iVar18;
          UNLOCK();
          if ((iVar18 == 0) && (local_3c != (CMap *)0x0)) {
            (*(code *)**(undefined4 **)local_3c)(1);
          }
        }
      }
    }
    local_5c = local_5c + 1;
  } while ((int)local_5c < 3);
LAB_004cba15:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

