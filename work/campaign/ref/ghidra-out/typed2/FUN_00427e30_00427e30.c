
void __thiscall FUN_00427e30(int this)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = DAT_00772400;
  if (*(char *)(this + 0x21) == '\0') {
    return;
  }
  uVar1 = *(uint *)(this + 0x4c);
  if (uVar1 == 0xffffffff) {
    fVar8 = *(float *)(this + 0x60) * 0.95;
    *(float *)(this + 0x5c) =
         *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x160) * 0.05 + *(float *)(this + 0x5c) * 0.95;
    fVar7 = *(float *)(*(int *)(iVar3 + 0x5a4) + 0x164) * 0.05;
  }
  else {
    piVar5 = (int *)(DAT_0077244c + 0x488);
    if (uVar1 < 0x2000) {
      piVar5 = piVar5 + uVar1;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar3 = *piVar5;
    if (iVar3 == 0) {
      *(undefined4 *)(this + 0x4c) = 0xffffffff;
      goto LAB_00427fc6;
    }
    fVar7 = (*(float *)(this + 0x50) - *(float *)(iVar3 + 0xc)) * 0.2;
    fVar8 = -(*(float *)(this + 0x54) - *(float *)(iVar3 + 0x10)) * 0.2;
    if (0.0 <= fVar7) {
      if (0.0 < fVar7) {
        fVar7 = 2.5 - fVar7;
      }
    }
    else {
      fVar7 = fVar7 - 2.5;
    }
    fVar10 = -1.7;
    if (-1.7 <= fVar8) {
      fVar10 = fVar8;
    }
    fVar8 = 1.7;
    if (fVar10 <= 1.7) {
      fVar8 = fVar10;
    }
    fVar10 = -3.0;
    if (-3.0 <= fVar7) {
      fVar10 = fVar7;
    }
    *(float *)(this + 0x5c) = fVar8 * 0.02 + *(float *)(this + 0x5c) * 0.98;
    fVar7 = 3.0;
    if (fVar10 <= 3.0) {
      fVar7 = fVar10;
    }
    fVar8 = *(float *)(this + 0x60) * 0.98;
    fVar7 = fVar7 * 0.02;
  }
  *(float *)(this + 0x60) = fVar7 + fVar8;
LAB_00427fc6:
  switch(*(undefined4 *)(this + 0x74)) {
  case 1:
    local_14 = *(float *)(this + 0x68);
    local_10 = *(float *)(this + 0x6c);
    local_c = *(float *)(this + 0x70);
    if (local_14 < 0.0) {
      local_14 = local_14 + (float)*(int *)(DAT_0076a338 + 0x2830);
    }
    if (local_10 < 0.0) {
      local_10 = local_10 + (float)*(int *)(DAT_0076a338 + 0x2834);
    }
    if (local_c < 0.0) {
      local_c = local_c * -1.0;
      local_14 = local_14 * ((float)*(int *)(DAT_0076a338 + 0x2830) / 800.0);
      local_10 = local_10 * ((float)*(int *)(DAT_0076a338 + 0x2834) / 600.0);
    }
    FUN_00479150(&stack0xffffffd8,&local_14);
    FUN_00428b80();
    break;
  case 2:
    fVar8 = *(float *)(this + 0x50) - *(float *)(this + 0x68);
    fVar10 = *(float *)(this + 0x54) - *(float *)(this + 0x6c);
    fVar7 = *(float *)(this + 0x58) - *(float *)(this + 0x70);
    if (0.040000003 <= fVar10 * fVar10 + fVar8 * fVar8 + fVar7 * fVar7) {
      FUN_00428b80();
    }
    else {
      *(undefined4 *)(this + 0x74) = 0;
      FUN_004279f0();
    }
    break;
  case 3:
    cVar2 = FUN_00428a70();
    if (cVar2 == '\0') {
      *(undefined4 *)(this + 0x74) = 0;
      FUN_004279f0();
      FUN_00427610(this);
      *(undefined1 *)(this + 0x21) = 0;
    }
    FUN_00428b80();
    break;
  case 4:
    if (*(float *)(this + 0x54) < *(float *)(this + 0x6c) - 3.0) {
      fVar7 = *(float *)(this + 0x6c);
      if (*(float *)(this + 0x54) < fVar7) {
        *(undefined4 *)(this + 0x14) = 0;
        *(undefined4 *)(this + 0x18) = 0x3d4ccccd;
        *(undefined4 *)(this + 0x1c) = 0;
        fVar8 = *(float *)(this + 0x54) + 0.05;
        fVar10 = *(float *)(this + 0x50) + 0.0;
        fVar9 = *(float *)(this + 0x58) + 0.0;
        if (fVar7 < fVar8) {
          fVar10 = *(float *)(this + 0x68);
          fVar9 = *(float *)(this + 0x70);
          fVar8 = fVar7;
        }
        iVar6 = *(int *)(this + 0x30) + -1;
        iVar3 = 0x19;
        if (iVar6 < 0x19) {
          iVar3 = iVar6;
        }
        *(int *)(this + 0x3c) = iVar3;
        *(float *)(this + 0x50) = fVar10;
        *(float *)(this + 0x54) = fVar8;
        *(float *)(this + 0x58) = fVar9;
      }
    }
    else {
      iVar6 = *(int *)(this + 0x30) + -1;
      *(undefined4 *)(this + 0x74) = 0;
      iVar3 = 0x1a;
      if (iVar6 < 0x1a) {
        iVar3 = iVar6;
      }
      *(int *)(this + 0x3c) = iVar3;
      FUN_004279f0();
    }
    break;
  case 5:
    fVar10 = *(float *)(this + 0x54) - *(float *)(this + 0x6c);
    fVar8 = *(float *)(this + 0x50) - *(float *)(this + 0x68);
    fVar7 = *(float *)(this + 0x58) - *(float *)(this + 0x70);
    if (0.0625 <= fVar10 * fVar10 + fVar8 * fVar8 + fVar7 * fVar7) {
      *(float *)(this + 0x50) = *(float *)(this + 0x50) + *(float *)(this + 0x14);
      *(float *)(this + 0x54) = *(float *)(this + 0x18) + *(float *)(this + 0x54);
      *(float *)(this + 0x58) = *(float *)(this + 0x1c) + *(float *)(this + 0x58);
      if (ABS(*(float *)(this + 0x14)) * 1.5 <= ABS(*(float *)(this + 0x18))) {
        iVar3 = (0.0 < *(float *)(this + 0x18)) + 1;
      }
      else {
        iVar3 = (0.0 < *(float *)(this + 0x14)) + 3;
      }
      iVar6 = *(int *)(this + 0x30) + -1;
      if (iVar3 <= iVar6) {
        iVar6 = iVar3;
      }
      *(int *)(this + 0x3c) = iVar6;
    }
    else {
      iVar3 = *(int *)(this + 0x30) + -1;
      *(undefined4 *)(this + 0x74) = 0;
      if (-1 < iVar3) {
        iVar3 = 0;
      }
      *(int *)(this + 0x3c) = iVar3;
      FUN_004279f0();
    }
  }
  iVar3 = DAT_00772400;
  if (*(char *)(this + 0x20) != '\0') {
    *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154) =
         *(float *)(this + 0x50) * 0.02 + *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154) * 0.98;
    *(float *)(*(int *)(iVar3 + 0x5a4) + 0x158) =
         *(float *)(this + 0x54) * 0.02 + *(float *)(*(int *)(iVar3 + 0x5a4) + 0x158) * 0.98;
    *(float *)(*(int *)(iVar3 + 0x5a4) + 0x160) = *(float *)(*(int *)(iVar3 + 0x5a4) + 0x160) * 0.9;
    *(float *)(*(int *)(iVar3 + 0x5a4) + 0x164) = *(float *)(*(int *)(iVar3 + 0x5a4) + 0x164) * 0.9;
  }
  FUN_00427a70();
  if ((*(int *)(this + 0x38) != -1) && (iVar3 = *(int *)(this + 4), iVar3 != -1)) {
    if (*(uint *)(this + 0x40) < 0x100) {
      iVar6 = *(int *)(DAT_00772400 + 0x5c8 + *(uint *)(this + 0x40) * 4);
    }
    else {
      iVar6 = 0;
    }
    if ((iVar3 < 0) || (*(int *)(iVar6 + 0x50) <= iVar3)) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      iVar3 = *(int *)(iVar6 + 0x4c);
    }
    else {
      iVar3 = *(int *)(iVar6 + 0x4c) + iVar3 * 0x3c;
    }
    fVar7 = *(float *)(this + 0x48) + 0.05;
    *(float *)(this + 0x48) = fVar7;
    if (0.99 <= fVar7) {
      *(int *)(this + 8) = *(int *)(this + 8) + 1;
      *(undefined4 *)(this + 0x48) = 0;
    }
    iVar6 = *(int *)(this + 8);
    if (*(int *)(iVar3 + 4) <= *(int *)(this + 8)) {
      iVar6 = *(int *)(iVar3 + 4);
    }
    *(int *)(this + 8) = iVar6;
    if (iVar6 < *(int *)(iVar3 + 4)) {
      puVar4 = (undefined4 *)FUN_00405920();
      *(undefined4 *)(this + 0x44) = *puVar4;
      *(bool *)(this + 0x7d) = *(int *)(this + 8) < *(int *)(iVar3 + 4) + -1;
      if (*(int *)(this + 0x38) != 0) {
        return;
      }
      DAT_00c3c960 = DAT_00c3c960 + 0.05;
      fVar7 = DAT_00c3c960 * 0.12;
      local_8 = DAT_00c3c960;
      FUN_004089d0();
      *(float *)(this + 0x50) = fVar7 * 0.0002 + *(float *)(this + 0x50);
      fVar7 = local_8 * 0.31 + 0.1;
      FUN_004089d0();
      *(float *)(this + 0x54) = fVar7 * 0.0008 + *(float *)(this + 0x54);
      return;
    }
    *(undefined4 *)(this + 0x48) = 0;
  }
  FUN_00428630();
  return;
}

