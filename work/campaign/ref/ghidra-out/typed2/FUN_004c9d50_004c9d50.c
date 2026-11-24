
void __thiscall FUN_004c9d50(CSceneRenderer *this)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  ushort *puVar9;
  int iVar10;
  ushort *puVar11;
  float *pfVar12;
  int iVar13;
  uint uVar14;
  ushort *in_stack_00000004;
  undefined4 uVar15;
  float *local_2c;
  ushort *local_28;
  float *local_24;
  ushort *local_20;
  
  piVar1 = &this->vertCount;
  iVar10 = *piVar1;
  if (0 < iVar10) {
    iVar13 = 0;
    uVar14 = 0;
    do {
      if (uVar14 < 0x400) {
        pfVar8 = (float *)((int)this->vertBufA + iVar13);
        pfVar12 = (float *)((int)this->vertBufB + iVar13);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pfVar8 = this->vertBufA;
        pfVar12 = this->vertBufB;
      }
      fVar5 = pfVar8[1];
      fVar6 = pfVar8[2];
      fVar7 = pfVar8[3];
      uVar14 = uVar14 + 1;
      iVar13 = iVar13 + 0x24;
      *pfVar12 = *pfVar8;
      pfVar12[1] = fVar5;
      pfVar12[2] = fVar6;
      pfVar12[3] = fVar7;
      fVar5 = pfVar8[5];
      fVar6 = pfVar8[6];
      fVar7 = pfVar8[7];
      pfVar12[4] = pfVar8[4];
      pfVar12[5] = fVar5;
      pfVar12[6] = fVar6;
      pfVar12[7] = fVar7;
      pfVar12[8] = pfVar8[8];
      iVar10 = this->vertCount;
    } while ((int)uVar14 < iVar10);
  }
  piVar2 = &this->copiedVertCount;
  *piVar2 = iVar10;
  iVar10 = this->idxCount;
  piVar3 = &this->idxCount;
  if (0 < iVar10) {
    iVar13 = 0;
    uVar14 = 0;
    do {
      if (uVar14 < 0x1000) {
        puVar9 = (ushort *)((int)this->idxBufA + iVar13);
        puVar11 = (ushort *)((int)this->idxBufB + iVar13);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar9 = this->idxBufA;
        puVar11 = this->idxBufB;
      }
      uVar14 = uVar14 + 1;
      *puVar11 = *puVar9;
      iVar13 = iVar13 + 2;
      iVar10 = *piVar3;
    } while ((int)uVar14 < iVar10);
  }
  piVar4 = &this->copiedIdxCount;
  *piVar4 = iVar10;
  if ((in_stack_00000004 == (ushort *)0x0) || (in_stack_00000004 == (ushort *)0x1)) {
    FUN_004c9010(1,1,this->vertBufA,piVar1,this->idxBufA,piVar3);
    FUN_004c9010(1,0,this->vertBufB,piVar2,this->idxBufB,piVar4);
    if (in_stack_00000004 != (ushort *)0x1) goto LAB_004c9f3d;
  }
  else {
    FUN_004c9010(1,0,this->vertBufA,piVar1,this->idxBufA,piVar3);
    FUN_004c9010(1,1,this->vertBufB,piVar2,this->idxBufB,piVar4);
LAB_004c9f3d:
    if (in_stack_00000004 != (ushort *)0x3) {
      uVar15 = 1;
      goto LAB_004c9f58;
    }
  }
  uVar15 = 0;
LAB_004c9f58:
  local_20 = this->idxBufA;
  local_24 = this->vertBufA;
  local_28 = this->idxBufB;
  local_2c = this->vertBufB;
  FUN_004c9010(0,uVar15,this->vertBufB,piVar2,this->idxBufB,piVar4);
  uVar14 = 0;
  iVar10 = *piVar4;
  if (0 < iVar10) {
    do {
      if (uVar14 < 0x1000) {
        in_stack_00000004 = local_28 + uVar14;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        in_stack_00000004 = local_28;
      }
      if (*piVar3 + uVar14 < 0x1000) {
        puVar9 = local_20 + *piVar3 + uVar14;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar9 = local_20;
      }
      uVar14 = uVar14 + 1;
      *puVar9 = *in_stack_00000004 + (short)*piVar1;
      iVar10 = *piVar4;
    } while ((int)uVar14 < iVar10);
  }
  uVar14 = 0;
  *piVar3 = *piVar3 + iVar10;
  if (*piVar2 < 1) {
    *piVar1 = *piVar1 + *piVar2;
    return;
  }
  in_stack_00000004 = (ushort *)0x0;
  do {
    if (uVar14 < 0x400) {
      pfVar8 = (float *)((int)local_2c + (int)in_stack_00000004);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pfVar8 = local_2c;
    }
    if (*piVar1 + uVar14 < 0x400) {
      pfVar12 = local_24 + (*piVar1 + uVar14) * 9;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pfVar12 = local_24;
    }
    fVar5 = pfVar8[1];
    fVar6 = pfVar8[2];
    fVar7 = pfVar8[3];
    uVar14 = uVar14 + 1;
    *pfVar12 = *pfVar8;
    pfVar12[1] = fVar5;
    pfVar12[2] = fVar6;
    pfVar12[3] = fVar7;
    fVar5 = pfVar8[5];
    fVar6 = pfVar8[6];
    fVar7 = pfVar8[7];
    pfVar12[4] = pfVar8[4];
    pfVar12[5] = fVar5;
    pfVar12[6] = fVar6;
    pfVar12[7] = fVar7;
    pfVar12[8] = pfVar8[8];
    in_stack_00000004 = (ushort *)((int)in_stack_00000004 + 0x24);
  } while ((int)uVar14 < *piVar2);
  *piVar1 = *piVar1 + *piVar2;
  return;
}

