
void __thiscall FUN_004c6b20(CSceneRenderer *this)

{
  void **ppvVar1;
  void **ppvVar2;
  CHeightBlockArray *pCVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  short sVar7;
  char cVar8;
  void *pvVar9;
  int iVar10;
  char *pcVar11;
  int *piVar12;
  CHeightBlock *pCVar13;
  int iVar14;
  char cVar15;
  char cVar16;
  uint uVar17;
  uint uVar18;
  int in_stack_00000004;
  int in_stack_00000008;
  uint in_stack_0000000c;
  uint local_18;
  float local_14;
  uint local_10;
  uint local_c;
  
  pvVar9 = PTR_0077241c->ownerBlocks;
  if (in_stack_0000000c < 8) {
    pvVar9 = (void *)((int)pvVar9 + in_stack_0000000c * 4);
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  if (in_stack_00000008 < *(int *)((int)pvVar9 + 0xc) + -1) {
    return;
  }
  iVar14 = PTR_0077241c->heightBlocks->currentBlock;
  iVar10 = FUN_00592f10(PTR_0077241c);
  pcVar11 = (char *)(iVar10 + 0x34);
  if (in_stack_0000000c < 8) {
    pcVar11 = pcVar11 + in_stack_0000000c;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  if (*pcVar11 == '\0') {
    iVar10 = FUN_00592f10(PTR_0077241c);
    pcVar11 = (char *)(iVar10 + 0x34);
    if (in_stack_0000000c < 8) {
      pcVar11 = pcVar11 + in_stack_0000000c;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*pcVar11 != '\0') goto LAB_004c6be3;
LAB_004c6c01:
    cVar8 = '\0';
  }
  else {
LAB_004c6be3:
    piVar12 = (int *)FUN_00592f10(PTR_0077241c);
    cVar8 = '\x01';
    if (*piVar12 == iVar14) goto LAB_004c6c01;
  }
  iVar10 = FUN_00592f10(PTR_0077241c);
  pcVar11 = (char *)(iVar10 + 0x34);
  if (in_stack_0000000c < 8) {
    pcVar11 = pcVar11 + in_stack_0000000c;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  if (*pcVar11 == '\0') {
    iVar10 = FUN_00592f10(PTR_0077241c);
    pcVar11 = (char *)(iVar10 + 0x34);
    if (in_stack_0000000c < 8) {
      pcVar11 = pcVar11 + in_stack_0000000c;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*pcVar11 != '\0') goto LAB_004c6c75;
LAB_004c6c93:
    bVar4 = false;
  }
  else {
LAB_004c6c75:
    piVar12 = (int *)FUN_00592f10(PTR_0077241c);
    bVar4 = true;
    if (*piVar12 == iVar14) goto LAB_004c6c93;
  }
  iVar10 = FUN_00592f10(PTR_0077241c);
  pcVar11 = (char *)(iVar10 + 0x34);
  if (in_stack_0000000c < 8) {
    pcVar11 = pcVar11 + in_stack_0000000c;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  if (*pcVar11 == '\0') {
    iVar10 = FUN_00592f10(PTR_0077241c);
    pcVar11 = (char *)(iVar10 + 0x34);
    if (in_stack_0000000c < 8) {
      pcVar11 = pcVar11 + in_stack_0000000c;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*pcVar11 != '\0') goto LAB_004c6d11;
LAB_004c6d37:
    bVar5 = false;
  }
  else {
LAB_004c6d11:
    piVar12 = (int *)FUN_00592f10(PTR_0077241c);
    if (*piVar12 == iVar14) goto LAB_004c6d37;
    bVar5 = true;
  }
  iVar10 = FUN_00592f10(PTR_0077241c);
  pcVar11 = (char *)(iVar10 + 0x34);
  if (in_stack_0000000c < 8) {
    pcVar11 = pcVar11 + in_stack_0000000c;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  if (*pcVar11 == '\0') {
    iVar10 = FUN_00592f10(PTR_0077241c);
    pcVar11 = (char *)(iVar10 + 0x34);
    if (in_stack_0000000c < 8) {
      pcVar11 = pcVar11 + in_stack_0000000c;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*pcVar11 != '\0') goto LAB_004c6db0;
  }
  else {
LAB_004c6db0:
    piVar12 = (int *)FUN_00592f10(PTR_0077241c);
    if (*piVar12 != iVar14) {
      bVar6 = true;
      goto LAB_004c6dd8;
    }
  }
  bVar6 = false;
LAB_004c6dd8:
  cVar15 = cVar8 + '\x01';
  if (!bVar4) {
    cVar15 = cVar8;
  }
  cVar16 = cVar15 + '\x01';
  if (!bVar5) {
    cVar16 = cVar15;
  }
  cVar15 = cVar16 + '\x01';
  if (!bVar6) {
    cVar15 = cVar16;
  }
  if (cVar15 != '\0') {
    local_10 = this->wallIndexCount;
    local_18 = this->wallVertexCount;
    piVar12 = (int *)FUN_00592f10(PTR_0077241c);
    iVar14 = *piVar12;
    pCVar3 = PTR_0077241c->heightBlocks;
    if ((iVar14 < 0) || (pCVar3->count <= iVar14)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar13 = pCVar3->data;
    }
    else {
      pCVar13 = pCVar3->data + iVar14;
    }
    local_14 = (float)(pCVar13->cornerLevels & 0xf) * 0.5 + 7.0;
    iVar14 = FUN_00592f10(PTR_0077241c);
    if (((((*(byte *)(iVar14 + 0x18) & 3) == 3) ||
         (iVar14 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar14 + 0x18) & 3) == 3)) ||
        (iVar14 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar14 + 0x18) & 3) == 3)) ||
       (iVar14 = FUN_00592f10(PTR_0077241c), (*(byte *)(iVar14 + 0x18) & 3) == 3)) {
      local_14 = -14.0;
    }
    ppvVar1 = &this->wallIndices;
    local_c = local_18;
    if (cVar8 != '\0') {
      FUN_004ce630(this->wallVertexCount + 4);
      FUN_004ce760(this->wallIndexCount + 6);
      if ((uint)this->wallVertexCount <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar14 = local_18 * 0x1c;
      *(float *)(iVar14 + (int)this->wallVertices) = (float)in_stack_00000004;
      if ((uint)this->wallVertexCount <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + iVar14 + 4) = (float)in_stack_00000008;
      if ((uint)this->wallVertexCount <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar17 = local_18 + 1;
      *(undefined4 *)((int)this->wallVertices + iVar14 + 8) = 0x41680000;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar17 * 0x1c) = (float)in_stack_00000004;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar17 * 0x1c + 4) = (float)(in_stack_00000008 + 1);
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)((int)this->wallVertices + uVar17 * 0x1c + 8) = 0x41680000;
      uVar17 = local_18 + 2;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar17 * 0x1c) = (float)in_stack_00000004;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar17 * 0x1c + 4) = (float)(in_stack_00000008 + 1);
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar18 = local_18 + 3;
      *(float *)((int)this->wallVertices + uVar17 * 0x1c + 8) = local_14;
      if ((uint)this->wallVertexCount <= uVar18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar18 * 0x1c) = (float)in_stack_00000004;
      if ((uint)this->wallVertexCount <= uVar18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar18 * 0x1c + 4) = (float)in_stack_00000008;
      if ((uint)this->wallVertexCount <= uVar18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      ppvVar2 = &this->wallIndices;
      *(float *)((int)this->wallVertices + uVar18 * 0x1c + 8) = local_14;
      if ((uint)this->wallIndexCount <= local_10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      sVar7 = (short)local_18;
      *(short *)((int)*ppvVar2 + local_10 * 2) = sVar7;
      if ((uint)this->wallIndexCount <= local_10 + 1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar2 + local_10 * 2 + 2) = sVar7 + 1;
      if ((uint)this->wallIndexCount <= local_10 + 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar2 + local_10 * 2 + 4) = sVar7 + 2;
      if ((uint)this->wallIndexCount <= local_10 + 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar2 + local_10 * 2 + 6) = sVar7;
      if ((uint)this->wallIndexCount <= local_10 + 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar2 + local_10 * 2 + 8) = sVar7 + 2;
      if ((uint)this->wallIndexCount <= local_10 + 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar2 + local_10 * 2 + 10) = sVar7 + 3;
      local_10 = local_10 + 6;
      local_c = local_18 + 4;
    }
    if (bVar4) {
      FUN_004ce630(this->wallVertexCount + 4);
      FUN_004ce760(this->wallIndexCount + 6);
      if ((uint)this->wallVertexCount <= local_c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar14 = local_c * 0x1c;
      *(float *)(iVar14 + (int)this->wallVertices) = (float)in_stack_00000004;
      if ((uint)this->wallVertexCount <= local_c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)(iVar14 + 4 + (int)this->wallVertices) = (float)in_stack_00000008;
      if ((uint)this->wallVertexCount <= local_c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)(iVar14 + 8 + (int)this->wallVertices) = local_14;
      uVar17 = local_c + 1;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar17 * 0x1c) = (float)(in_stack_00000004 + 1);
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar17 * 0x1c + 4) = (float)in_stack_00000008;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar17 * 0x1c + 8) = local_14;
      uVar17 = local_c + 2;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar17 * 0x1c) = (float)(in_stack_00000004 + 1);
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar17 * 0x1c + 4) = (float)in_stack_00000008;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar18 = local_c + 3;
      *(undefined4 *)((int)this->wallVertices + uVar17 * 0x1c + 8) = 0x41680000;
      if ((uint)this->wallVertexCount <= uVar18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar18 * 0x1c) = (float)in_stack_00000004;
      if ((uint)this->wallVertexCount <= uVar18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)this->wallVertices + uVar18 * 0x1c + 4) = (float)in_stack_00000008;
      if ((uint)this->wallVertexCount <= uVar18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      ppvVar2 = &this->wallIndices;
      *(undefined4 *)((int)this->wallVertices + uVar18 * 0x1c + 8) = 0x41680000;
      if ((uint)this->wallIndexCount <= local_10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      sVar7 = (short)local_c;
      *(short *)((int)*ppvVar2 + local_10 * 2) = sVar7;
      if ((uint)this->wallIndexCount <= local_10 + 1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar2 + local_10 * 2 + 2) = sVar7 + 1;
      if ((uint)this->wallIndexCount <= local_10 + 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar2 + local_10 * 2 + 4) = sVar7 + 2;
      if ((uint)this->wallIndexCount <= local_10 + 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar2 + local_10 * 2 + 6) = sVar7;
      if ((uint)this->wallIndexCount <= local_10 + 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar2 + local_10 * 2 + 8) = sVar7 + 2;
      if ((uint)this->wallIndexCount <= local_10 + 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar2 + local_10 * 2 + 10) = sVar7 + 3;
      local_c = local_c + 4;
      local_10 = local_10 + 6;
    }
    if (bVar6) {
      ppvVar2 = &this->wallVertices;
      FUN_004ce630(this->wallVertexCount + 4);
      FUN_004ce760(this->wallIndexCount + 6);
      if ((uint)this->wallVertexCount <= local_c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar10 = in_stack_00000004 + 1;
      iVar14 = local_c * 0x1c;
      *(float *)(iVar14 + (int)*ppvVar2) = (float)iVar10;
      if ((uint)this->wallVertexCount <= local_c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + iVar14 + 4) = (float)in_stack_00000008;
      if ((uint)this->wallVertexCount <= local_c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar17 = local_c + 1;
      *(float *)((int)*ppvVar2 + iVar14 + 8) = local_14;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + uVar17 * 0x1c) = (float)iVar10;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + uVar17 * 0x1c + 4) = (float)(in_stack_00000008 + 1);
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + uVar17 * 0x1c + 8) = local_14;
      uVar17 = local_c + 2;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + uVar17 * 0x1c) = (float)iVar10;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + uVar17 * 0x1c + 4) = (float)(in_stack_00000008 + 1);
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)((int)*ppvVar2 + uVar17 * 0x1c + 8) = 0x41680000;
      if ((uint)this->wallVertexCount <= local_c + 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar17 = local_c + 3;
      *(float *)((int)*ppvVar2 + (local_c + 3) * 0x1c) = (float)iVar10;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + uVar17 * 0x1c + 4) = (float)in_stack_00000008;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)((int)*ppvVar2 + uVar17 * 0x1c + 8) = 0x41680000;
      if ((uint)this->wallIndexCount <= local_10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      sVar7 = (short)local_c;
      *(short *)((int)*ppvVar1 + local_10 * 2) = sVar7;
      if ((uint)this->wallIndexCount <= local_10 + 1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar1 + local_10 * 2 + 2) = sVar7 + 1;
      if ((uint)this->wallIndexCount <= local_10 + 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar1 + local_10 * 2 + 4) = sVar7 + 2;
      if ((uint)this->wallIndexCount <= local_10 + 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar1 + local_10 * 2 + 6) = sVar7;
      if ((uint)this->wallIndexCount <= local_10 + 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar1 + local_10 * 2 + 8) = sVar7 + 2;
      if ((uint)this->wallIndexCount <= local_10 + 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar1 + local_10 * 2 + 10) = sVar7 + 3;
      local_c = local_c + 4;
      local_10 = local_10 + 6;
    }
    if (bVar5) {
      ppvVar2 = &this->wallVertices;
      FUN_004ce630(this->wallVertexCount + 4);
      FUN_004ce760(this->wallIndexCount + 6);
      if ((uint)this->wallVertexCount <= local_c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar14 = local_c * 0x1c;
      *(float *)(iVar14 + (int)*ppvVar2) = (float)in_stack_00000004;
      if ((uint)this->wallVertexCount <= local_c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar10 = in_stack_00000008 + 1;
      *(float *)(iVar14 + 4 + (int)*ppvVar2) = (float)iVar10;
      if ((uint)this->wallVertexCount <= local_c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)((int)*ppvVar2 + iVar14 + 8) = 0x41680000;
      uVar17 = local_c + 1;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + uVar17 * 0x1c) = (float)(in_stack_00000004 + 1);
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + uVar17 * 0x1c + 4) = (float)iVar10;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(undefined4 *)((int)*ppvVar2 + uVar17 * 0x1c + 8) = 0x41680000;
      uVar17 = local_c + 2;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + uVar17 * 0x1c) = (float)(in_stack_00000004 + 1);
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + uVar17 * 0x1c + 4) = (float)iVar10;
      if ((uint)this->wallVertexCount <= uVar17) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + uVar17 * 0x1c + 8) = local_14;
      if ((uint)this->wallVertexCount <= local_c + 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + (local_c + 3) * 0x1c) = (float)in_stack_00000004;
      if ((uint)this->wallVertexCount <= local_c + 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + (local_c + 3) * 0x1c + 4) = (float)iVar10;
      if ((uint)this->wallVertexCount <= local_c + 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)((int)*ppvVar2 + (local_c + 3) * 0x1c + 8) = local_14;
      if ((uint)this->wallIndexCount <= local_10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      sVar7 = (short)local_c;
      *(short *)((int)*ppvVar1 + local_10 * 2) = sVar7;
      if ((uint)this->wallIndexCount <= local_10 + 1) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar1 + local_10 * 2 + 2) = sVar7 + 1;
      if ((uint)this->wallIndexCount <= local_10 + 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar1 + local_10 * 2 + 4) = sVar7 + 2;
      if ((uint)this->wallIndexCount <= local_10 + 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar1 + local_10 * 2 + 6) = sVar7;
      if ((uint)this->wallIndexCount <= local_10 + 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar1 + local_10 * 2 + 8) = sVar7 + 2;
      if ((uint)this->wallIndexCount <= local_10 + 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(short *)((int)*ppvVar1 + (local_10 + 5) * 2) = sVar7 + 3;
      local_c = local_c + 4;
    }
    if ((int)local_18 < (int)local_c) {
      iVar14 = local_18 * 0x1c;
      do {
        if ((uint)this->wallVertexCount <= local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *(undefined4 *)(iVar14 + 0xc + (int)this->wallVertices) = 0;
        if ((uint)this->wallVertexCount <= local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *(undefined4 *)(iVar14 + 0x10 + (int)this->wallVertices) = 0;
        if ((uint)this->wallVertexCount <= local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *(undefined4 *)(iVar14 + 0x14 + (int)this->wallVertices) = 0;
        if ((uint)this->wallVertexCount <= local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *(undefined4 *)(iVar14 + 0x18 + (int)this->wallVertices) = 0;
        iVar14 = iVar14 + 0x1c;
        local_18 = local_18 + 1;
      } while ((int)local_18 < (int)local_c);
    }
  }
  return;
}

