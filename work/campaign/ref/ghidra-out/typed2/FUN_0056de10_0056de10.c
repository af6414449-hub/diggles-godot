
void FUN_0056de10(int *param_1)

{
  int iVar1;
  CMap *pCVar2;
  int iVar3;
  int iVar4;
  
  pCVar2 = PTR_0077241c;
  iVar1 = PTR_0077241c->cellX0;
  iVar3 = *param_1;
  if (*param_1 < iVar1) {
    *param_1 = iVar1;
    iVar3 = iVar1;
  }
  iVar1 = pCVar2->cellY0;
  iVar4 = param_1[1];
  if (param_1[1] < iVar1) {
    param_1[1] = iVar1;
    iVar4 = iVar1;
  }
  if (pCVar2->cellX1 <= iVar3) {
    *param_1 = pCVar2->cellX1 + -1;
  }
  if (pCVar2->cellY1 <= iVar4) {
    param_1[1] = pCVar2->cellY1 + -1;
  }
  return;
}

