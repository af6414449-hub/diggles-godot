
undefined8 FUN_10027610(int param_1,int param_2)

{
  int *piVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *in_ECX;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  longlong lVar13;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  uVar8 = in_ECX[0x50c];
  if ((uVar8 & 1) == 0) {
    lVar13 = FUN_100274f0();
    if (lVar13 == 0) {
      return 0;
    }
    in_ECX[0x50c] = in_ECX[0x50c] | 1;
    uVar8 = in_ECX[0x50c];
  }
  if ((uVar8 & 2) == 0) {
    lVar13 = FUN_100274f0();
    if (lVar13 == 0) {
      return 0;
    }
    in_ECX[0x50c] = in_ECX[0x50c] | 2;
  }
  iVar5 = *in_ECX;
  dVar2 = *(double *)(&DAT_10047c80 + (iVar5 >> 0x1f) * -8);
  iVar6 = in_ECX[1];
  dVar3 = *(double *)(&DAT_10047c80 + (iVar6 >> 0x1f) * -8);
  local_14 = param_2;
  local_10 = param_1;
  if ((param_2 == 0) && (param_1 == 0)) {
    return 0;
  }
  iVar7 = in_ECX[2];
  local_1c = 0;
  local_18 = 0;
  while( true ) {
    piVar1 = in_ECX + iVar7 + 7;
    FUN_10027220(piVar1,iVar7);
    dVar4 = *(double *)(in_ECX + 0x50a);
    uVar8 = FUN_10041395();
    uVar11 = 0;
    *(double *)(in_ECX + 0x50a) =
         (dVar4 + ((double)iVar5 + dVar2) / ((double)iVar6 + dVar3)) -
         ((double)(int)uVar8 + *(double *)(&DAT_10047c80 + ((int)uVar8 >> 0x1f) * -8));
    if (uVar8 != 0) break;
LAB_100277e5:
    iVar7 = in_ECX[2];
    bVar12 = local_10 != 0;
    local_10 = local_10 + -1;
    local_14 = local_14 + -1 + (uint)bVar12;
    bVar12 = 0xfffffffe < local_18;
    local_18 = local_18 + 1;
    local_1c = local_1c + (uint)bVar12;
    if (((*(byte *)(in_ECX + 0x50c) & 3) == 0) || ((local_14 == 0 && (local_10 == 0)))) {
      return CONCAT44(local_1c,local_18);
    }
  }
LAB_10027771:
  uVar10 = 0;
  if (in_ECX[2] != 0) {
    piVar9 = in_ECX + 7;
    do {
      *piVar9 = *(int *)(((int)piVar1 - (int)(in_ECX + 7)) + (int)piVar9);
      uVar10 = uVar10 + 1;
      piVar9 = piVar9 + 1;
    } while (uVar10 < (uint)in_ECX[2]);
  }
  lVar13 = FUN_100274f0();
  if (lVar13 != 0) goto code_r0x100277a9;
  uVar8 = 0;
  if (in_ECX[2] != 0) {
    do {
      piVar1[uVar8] = 0;
      uVar8 = uVar8 + 1;
    } while (uVar8 < (uint)in_ECX[2]);
  }
  uVar8 = in_ECX[0x50c];
  if ((uVar8 & 2) == 0) {
    uVar8 = uVar8 & 0xfffffffe;
  }
  else {
    uVar8 = uVar8 & 0xfffffffd;
  }
  in_ECX[0x50c] = uVar8;
  goto LAB_100277e5;
code_r0x100277a9:
  uVar11 = uVar11 + 1;
  if (uVar8 <= uVar11) goto LAB_100277e5;
  goto LAB_10027771;
}

