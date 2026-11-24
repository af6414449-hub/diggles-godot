
void FUN_0057aaf0(float param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  CMapCell *pCVar5;
  int *piVar6;
  CHeightBlock **ppCVar7;
  CHeightBlock *pCVar8;
  float *in_ECX;
  int iVar9;
  int iVar10;
  int iVar11;
  CMap *this;
  CHeightBlock **ppCVar12;
  float local_14;
  
  iVar9 = (int)param_1;
  local_14 = 0.0;
  iVar3 = (int)param_2;
  this = PTR_0077241c;
  while( true ) {
    iVar10 = this->cellX0;
    if (this->cellX0 <= iVar9) {
      iVar10 = iVar9;
    }
    iVar11 = this->cellY0;
    if (this->cellY0 <= iVar3) {
      iVar11 = iVar3;
    }
    iVar4 = this->cellY1 + -1;
    if (iVar11 < this->cellY1) {
      iVar4 = iVar11;
    }
    iVar11 = this->cellX1 + -1;
    if (iVar10 < this->cellX1) {
      iVar11 = iVar10;
    }
    iVar10 = (iVar4 * this->mapWidth + iVar11) % this->cellCountTotal;
    if ((iVar10 < 0) || (this->cellCount <= iVar10)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar5 = this->cells;
      this = PTR_0077241c;
    }
    else {
      pCVar5 = this->cells + iVar10;
    }
    if (*(float *)&pCVar5->field_0x20 < 1.0) break;
    if (local_14 == 1.12104e-44) {
      *in_ECX = param_1;
      in_ECX[1] = (float)iVar3;
      in_ECX[2] = param_3;
      return;
    }
    iVar3 = iVar3 + -1;
    local_14 = (float)((int)local_14 + 1);
  }
  iVar10 = 0;
  while( true ) {
    iVar11 = this->cellX0;
    if (this->cellX0 <= iVar9) {
      iVar11 = iVar9;
    }
    iVar4 = this->cellX1 + -1;
    if (iVar11 < this->cellX1) {
      iVar4 = iVar11;
    }
    iVar11 = this->cellY0;
    if (this->cellY0 <= iVar3) {
      iVar11 = iVar3;
    }
    if (this->cellY1 <= iVar11) {
      iVar11 = this->cellY1 + -1;
    }
    iVar11 = (this->mapWidth * iVar11 + iVar4) % this->cellCountTotal;
    if ((iVar11 < 0) || (this->cellCount <= iVar11)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      pCVar5 = this->cells;
      this = PTR_0077241c;
    }
    else {
      pCVar5 = this->cells + iVar11;
    }
    if (*(float *)&pCVar5->field_0x20 != 0.0) break;
    if (iVar10 == 8) {
      *in_ECX = param_1;
      in_ECX[1] = (float)iVar3;
      in_ECX[2] = param_3;
      return;
    }
    iVar3 = iVar3 + 1;
    iVar10 = iVar10 + 1;
  }
  piVar6 = (int *)FUN_00592f10(this);
  fVar1 = 1.0;
  if ((float)piVar6[8] <= 1.0) {
    fVar1 = (float)piVar6[8];
  }
  iVar9 = *piVar6;
  ppCVar7 = &PTR_0077241c->heightBlocks->data;
  if ((iVar9 < 0) || (PTR_0077241c->heightBlocks->count <= iVar9)) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    iVar9 = *piVar6;
    local_14 = (float)(*(uint *)(*ppCVar7)->tail >> 0xe & 0xf) + 0.0;
    ppCVar12 = &PTR_0077241c->heightBlocks->data;
    if (-1 < iVar9) goto LAB_0057ad54;
  }
  else {
    ppCVar12 = &PTR_0077241c->heightBlocks->data;
    local_14 = (float)(*(uint *)(*ppCVar7)[iVar9].tail >> 0xe & 0xf) + 0.0;
LAB_0057ad54:
    if (iVar9 < (int)ppCVar12[1]) {
      pCVar8 = *ppCVar12 + iVar9;
      goto LAB_0057ad6f;
    }
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  pCVar8 = *ppCVar12;
LAB_0057ad6f:
  fVar2 = (float)(*(uint *)pCVar8->tail >> 10 & 0xf) + 0.0;
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[1] = (1.0 - ((fVar2 - local_14) * fVar1 + (8.0 - fVar2)) * 0.125) + (float)iVar3;
  return;
}

