
undefined4 __thiscall FUN_00414a50(CAct_Lore *this)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  undefined8 uVar12;
  uint local_2c;
  float local_28;
  uint local_24;
  float local_20;
  uint local_1c;
  uint local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9d7d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c3cab4) &&
     (FUN_006cebf4(&DAT_00c3cab4,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00c3cab4 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00c3cab8 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "LORE-SHUT";
    *(int *)(&DAT_00773650 + iVar8) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00c3cab4);
  }
  iVar8 = DAT_00c3cab8;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00c3cab8 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar2 == 0) {
    uVar12 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar2 + 1;
  local_8 = 0;
  uVar3 = FUN_00414e40();
  if (DAT_007735e4 <= uVar3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar2 = DAT_007735e0;
  if (this->i_28 < 1) {
    local_14 = *(float *)(DAT_007735e0 + 0xc + uVar3 * 0x18);
    local_20 = local_14;
  }
  else {
    uVar5 = this->i_28 - 1;
    if ((uint)this->i_28 <= uVar5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_20 = *(float *)(iVar2 + 0xc + uVar3 * 0x18);
    local_14 = local_20 - *(float *)(this->i_24 + 4 + uVar5 * 8);
  }
  local_28 = *(float *)(iVar2 + 0x10 + uVar3 * 0x18);
  local_18 = 0;
  if (1 < *(int *)(iVar2 + 8 + uVar3 * 0x18)) {
    local_24 = 1;
    local_1c = 0;
    do {
      uVar5 = *(uint *)(iVar2 + 8 + uVar3 * 0x18);
      if (uVar5 <= local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar5 = *(uint *)(iVar2 + 8 + uVar3 * 0x18);
      }
      iVar8 = *(int *)(iVar2 + 4 + uVar3 * 0x18);
      fVar9 = *(float *)(iVar8 + 8 + local_1c);
      fVar11 = *(float *)(iVar8 + local_1c);
      fVar10 = *(float *)(iVar8 + 4 + local_1c);
      if (uVar5 <= local_24) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar8 = *(int *)(iVar2 + 4 + uVar3 * 0x18);
      }
      fVar10 = fVar10 - *(float *)(local_1c + 0x24 + iVar8);
      fVar11 = fVar11 - *(float *)(local_1c + 0x20 + iVar8);
      fVar9 = fVar9 * 0.5 - *(float *)(local_1c + 0x28 + iVar8) * 0.5;
      fVar9 = fVar10 * fVar10 + fVar11 * fVar11 + fVar9 * fVar9;
      if (local_14 * local_14 < fVar9) break;
      FUN_0040b7e0();
      local_14 = local_14 - fVar9;
      local_28 = local_28 - fVar9;
      local_24 = local_24 + 1;
      local_18 = local_18 + 1;
      local_1c = local_1c + 0x20;
      local_20 = local_20 - fVar9;
    } while ((int)local_24 < *(int *)(iVar2 + 8 + uVar3 * 0x18));
  }
  piVar7 = (int *)(iVar2 + 4 + uVar3 * 0x18);
  if ((int)local_18 < *(int *)(iVar2 + 8 + uVar3 * 0x18)) {
    local_24 = local_18 << 5;
    iVar8 = 0;
    local_1c = 0;
    uVar5 = local_18;
    do {
      local_2c = piVar7[1];
      if (local_2c <= uVar5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        local_2c = *(uint *)(iVar2 + 8 + uVar3 * 0x18);
        piVar7 = (int *)(iVar2 + 4 + uVar3 * 0x18);
      }
      iVar6 = *piVar7;
      puVar4 = (undefined4 *)(local_24 + iVar6);
      piVar7 = (int *)(iVar2 + 4 + uVar3 * 0x18);
      if (local_2c <= local_1c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = *(int *)(iVar2 + 4 + uVar3 * 0x18);
        piVar7 = (int *)(iVar2 + 4 + uVar3 * 0x18);
      }
      *(undefined4 *)(iVar8 + iVar6) = *puVar4;
      local_24 = local_24 + 0x20;
      local_1c = local_1c + 1;
      *(undefined4 *)(iVar8 + 4 + iVar6) = puVar4[1];
      *(undefined4 *)(iVar8 + 8 + iVar6) = puVar4[2];
      *(undefined4 *)(iVar8 + 0xc + iVar6) = puVar4[3];
      *(undefined4 *)(iVar8 + 0x10 + iVar6) = puVar4[4];
      *(undefined4 *)(iVar8 + 0x14 + iVar6) = puVar4[5];
      *(undefined4 *)(iVar8 + 0x18 + iVar6) = puVar4[6];
      *(undefined4 *)(iVar8 + 0x1c + iVar6) = puVar4[7];
      iVar8 = iVar8 + 0x20;
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < *(int *)(iVar2 + 8 + uVar3 * 0x18));
  }
  *(float *)(iVar2 + 0xc + uVar3 * 0x18) = local_20;
  *(float *)(iVar2 + 0x10 + uVar3 * 0x18) = local_28;
  FUN_00415250(*(int *)(iVar2 + 8 + uVar3 * 0x18) - local_18);
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

