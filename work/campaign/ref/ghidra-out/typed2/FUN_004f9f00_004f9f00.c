
void FUN_004f9f00(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 uVar8;
  uint uVar9;
  BOOL BVar10;
  int *piVar11;
  void *pvVar12;
  int iVar13;
  int in_ECX;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  undefined4 extraout_ECX_02;
  int *piVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  int **ppiVar17;
  undefined1 local_30 [8];
  float local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007005dd;
  local_10 = ExceptionList;
  uVar9 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pvVar12 = *(void **)(in_ECX + 0x1a0);
  iVar13 = in_ECX;
  local_14 = in_ECX;
  if ((pvVar12 != (void *)0x0) &&
     (((BVar10 = IsBadReadPtr(pvVar12,0x10), iVar13 = extraout_ECX, BVar10 != 0 ||
       (*(int *)((int)pvVar12 + 8) != 0x616e4f62)) ||
      ((DAT_00768398 != '\0' && (*(int *)((int)pvVar12 + 0xdc) == 0)))))) {
    *(undefined4 *)(in_ECX + 0x1a0) = 0;
  }
  pvVar12 = *(void **)(in_ECX + 0x1a8);
  if ((pvVar12 != (void *)0x0) &&
     (((BVar10 = IsBadReadPtr(pvVar12,0x10), iVar13 = extraout_ECX_00, BVar10 != 0 ||
       (*(int *)((int)pvVar12 + 8) != 0x616e4f62)) ||
      ((DAT_00768398 != '\0' && (*(int *)((int)pvVar12 + 0xdc) == 0)))))) {
    *(undefined4 *)(in_ECX + 0x1a8) = 0;
  }
  pvVar12 = *(void **)(in_ECX + 0x1a4);
  if ((pvVar12 != (void *)0x0) &&
     (((BVar10 = IsBadReadPtr(pvVar12,0x10), iVar13 = extraout_ECX_01, BVar10 != 0 ||
       (*(int *)((int)pvVar12 + 8) != 0x616e4f62)) ||
      ((DAT_00768398 != '\0' && (*(int *)((int)pvVar12 + 0xdc) == 0)))))) {
    *(undefined4 *)(in_ECX + 0x1a4) = 0;
  }
  if (120.0 < *(double *)(DAT_00772400 + 0xa088) - *(double *)(in_ECX + 0x68)) {
    piVar11 = (int *)FUN_006ba810(0x19,iVar13,uVar9);
    in_ECX = local_14;
    piVar11[1] = 0x14;
    piVar11[2] = -1;
    *piVar11 = 0;
    *(undefined1 *)(piVar11 + 3) = 0;
    piVar11[3] = 0x6f747561;
    piVar11[4] = 0x65766173;
    *(undefined1 *)(piVar11 + 5) = 0;
    piVar11[2] = 8;
    if (piVar11 != (int *)0x0) {
      *piVar11 = *piVar11 + 1;
    }
    FUN_004fbc90(piVar11);
  }
  if ((**(uint **)(in_ECX + 0x44) >> 2 & 1) != 0) {
    **(uint **)(in_ECX + 0x44) = 0;
    iVar13 = DAT_00772400;
    if ((*(int *)(DAT_00772400 + 0xa0c8) == 1) && (0 < *(int *)(DAT_00772400 + 0xa0c8))) {
      if (*(int *)(DAT_00772400 + 0xa0c8) == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar15 = (undefined4 *)(DAT_0077244c + 0x488);
      if (**(uint **)(iVar13 + 0xa0c4) < 0x2000) {
        pvVar12 = (void *)puVar15[**(uint **)(iVar13 + 0xa0c4)];
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pvVar12 = (void *)*puVar15;
      }
    }
    else {
      pvVar12 = (void *)0x0;
    }
    *(void **)(in_ECX + 0x1a0) = pvVar12;
    if (pvVar12 != (void *)0x0) {
      IsBadReadPtr(pvVar12,0x10);
    }
    FUN_004f06d0();
  }
  if ((*(char *)(DAT_00772400 + 0x8a) != '\0') && (*(int *)(in_ECX + 0x15d) == 0)) {
    FUN_004f4f10();
    FUN_004f5180();
    FUN_004f53d0();
    uVar16 = extraout_ECX_02;
    FUN_006b8fb0(&PTR_0071ce50);
    FUN_004f5780(uVar16);
  }
  pvVar12 = *(void **)(in_ECX + 0x1a8);
  if ((((pvVar12 != (void *)0x0) && (BVar10 = IsBadReadPtr(pvVar12,0x10), BVar10 == 0)) &&
      (*(int *)((int)pvVar12 + 8) == 0x616e4f62)) &&
     ((DAT_00768398 == '\0' || (*(int *)((int)pvVar12 + 0xdc) != 0)))) {
    local_20 = *(int **)(*(int *)(in_ECX + 0x1b0) + 0xbc);
    DAT_00772dd8 = (int)ROUND((float)local_20);
    iVar13 = DAT_00772dd8;
    if (DAT_00772dd8 < 0) {
      iVar13 = 0;
    }
    if (0xf < iVar13) {
      iVar13 = 0xf;
    }
    FUN_0055a600(local_30,iVar13);
    local_28 = *(float *)(*(int *)(in_ECX + 0x1b0) + 0xbc);
    if (local_28 <= -32.0001) {
      *(undefined4 *)(*(int *)(in_ECX + 0x1b0) + 0xbc) = 0x41600000;
      local_28 = 14.0;
    }
    FUN_006b8fb0(&DAT_0071ccb8);
    local_24 = *(int *)(in_ECX + 0x1a8);
    local_8 = 0;
    if (local_24 != 0) {
      piVar11 = *(int **)(*(int *)(local_24 + 0xd4) + 0xc);
      if (piVar11 != (int *)0x0) {
        *piVar11 = *piVar11 + 1;
      }
      FUN_004f4e30(piVar11);
      local_18 = (int *)FUN_006ba810(0x19);
      local_18[1] = 0x14;
      local_18[2] = -1;
      *(undefined1 *)(local_18 + 3) = 0;
      *local_18 = 1;
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_004fc880(&local_20,&local_18);
      piVar11 = local_18;
      if (local_18 + 3 == (int *)0x0) {
        piVar14 = (int *)0x0;
      }
      else {
        piVar14 = (int *)Tcl_NewStringObj(local_18 + 3,0xffffffff);
        *piVar14 = *piVar14 + 1;
      }
      ppiVar17 = &local_1c;
      local_8 = CONCAT31(local_8._1_3_,2);
      local_1c = piVar14;
      FUN_005c9cc0(ppiVar17);
      FUN_00555a00(ppiVar17);
      if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
        TclFreeObj(piVar14);
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      in_ECX = local_14;
      if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 == 0)) {
        FUN_006ba940();
        in_ECX = local_14;
      }
    }
    local_8 = 4;
    if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
    FUN_004f9ad0(local_30);
  }
  pvVar12 = *(void **)(in_ECX + 0x1a0);
  if ((((pvVar12 == (void *)0x0) || (BVar10 = IsBadReadPtr(pvVar12,0x10), BVar10 != 0)) ||
      (*(int *)((int)pvVar12 + 8) != 0x616e4f62)) ||
     ((DAT_00768398 != '\0' && (*(int *)((int)pvVar12 + 0xdc) == 0)))) {
    uVar8 = 0;
  }
  else {
    iVar13 = *(int *)(in_ECX + 0x1a0);
    *(undefined4 *)(in_ECX + 0x1d0) = *(undefined4 *)(iVar13 + 0xc);
    *(undefined4 *)(in_ECX + 0x1d4) = *(undefined4 *)(iVar13 + 0x10);
    *(undefined4 *)(in_ECX + 0x1d8) = *(undefined4 *)(iVar13 + 0x14);
    *(undefined4 *)(in_ECX + 0x1dc) = *(undefined4 *)(iVar13 + 0x40);
    *(undefined4 *)(in_ECX + 0x1e0) = *(undefined4 *)(iVar13 + 0x44);
    *(undefined4 *)(in_ECX + 0x1e4) = *(undefined4 *)(iVar13 + 0x48);
    uVar8 = 1;
  }
  *(undefined1 *)(in_ECX + 0x1cc) = uVar8;
  iVar7 = DAT_00772400;
  fVar1 = *(float *)(in_ECX + 0x198);
  fVar2 = *(float *)(in_ECX + 0x194);
  iVar13 = PTR_0077241c->cellY1;
  iVar4 = PTR_0077241c->cellX1;
  iVar5 = PTR_0077241c->cellY0;
  iVar6 = PTR_0077241c->cellX0;
  DAT_00772dd8 = (int)ROUND(*(float *)(in_ECX + 0x194));
  fVar3 = *(float *)(in_ECX + 0x198);
  *(int *)(DAT_00772400 + 0xa328) = DAT_00772dd8 + -8;
  *(int *)(iVar7 + 0xa32c) = (int)ROUND(fVar1) + -8;
  *(int *)(iVar7 + 0xa330) = ((iVar4 - iVar6) - (int)fVar2) + 8;
  *(int *)(iVar7 + 0xa334) = ((iVar13 - iVar5) - (int)fVar3) + 8;
  ExceptionList = local_10;
  return;
}

