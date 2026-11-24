
bool CAct_Lore__SetLorePos(void)

{
  float *pfVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  int this;
  code *pcVar9;
  float fVar10;
  undefined8 uVar11;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined1 *local_44;
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  undefined4 *local_38;
  int local_34;
  uint local_30;
  undefined4 local_2c;
  int local_28;
  float local_24;
  float local_20;
  uint local_1c;
  float local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9d23;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c3caa4) &&
     (FUN_006cebf4(&DAT_00c3caa4,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00c3caa4 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00c3caa8 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "CAct_Lore::SetLorePos()";
    *(int *)(&DAT_00773650 + iVar8) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00c3caa4);
  }
  iVar8 = DAT_00c3caa8;
  local_38 = &DAT_00c3caa8;
  uVar3 = *(undefined4 *)(&DAT_00773650 + DAT_00c3caa8 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar3;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar5 == 0) {
    uVar11 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar5 + 1;
  local_8 = 0;
  uVar6 = FUN_00414e40();
  pcVar9 = RaiseException_exref;
  local_30 = uVar6;
  if (DAT_007735e4 <= uVar6) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  iVar5 = this->i_0c;
  local_34 = uVar6 * 0x18;
  local_28 = local_34 + DAT_007735e0;
  local_20 = -1.0;
  local_24 = 1000.0;
  local_18 = *(float *)(local_28 + 0x14);
  local_50 = *(float *)(iVar5 + 0xc);
  local_4c = *(float *)(iVar5 + 0x10);
  local_48 = *(float *)(iVar5 + 0x14);
  local_5c = *(undefined4 *)(iVar5 + 0x40);
  local_58 = *(undefined4 *)(iVar5 + 0x44);
  local_54 = *(undefined4 *)(iVar5 + 0x48);
  local_2c = *(undefined4 *)(local_28 + 0xc);
  local_11 = CAct_Lore__GetPosRotSpeed(local_28,&local_50,&local_5c,&local_18,&local_20,&local_24);
  iVar5 = this->i_0c;
  if ((((*(float *)(iVar5 + 0xc) != local_50) || (*(float *)(iVar5 + 0x10) != local_4c)) ||
      (*(float *)(iVar5 + 0x14) != local_48)) &&
     (FUN_005cd8e0(&local_50), *(int *)(iVar5 + 0x238) == 0)) {
    FUN_005ebc90(iVar5);
    FUN_005eb470(iVar5);
  }
  FUN_005cd840(&local_5c);
  local_1c = 0;
  if (0 < this->i_28) {
    do {
      uVar4 = local_1c;
      uVar6 = this->i_28;
      if (uVar6 <= local_1c) {
        (*pcVar9)(0xc000008c,1,0,0);
        uVar6 = this->i_28;
      }
      iVar5 = this->i_24;
      iVar8 = *(int *)(iVar5 + uVar4 * 8);
      local_50 = *(float *)(iVar8 + 0xc);
      local_4c = *(float *)(iVar8 + 0x10);
      local_48 = *(float *)(iVar8 + 0x14);
      if (uVar6 <= uVar4) {
        (*pcVar9)(0xc000008c,1,0,0);
        iVar5 = this->i_24;
        uVar6 = this->i_28;
      }
      iVar5 = *(int *)(iVar5 + uVar4 * 8);
      local_5c = *(undefined4 *)(iVar5 + 0x40);
      local_58 = *(undefined4 *)(iVar5 + 0x44);
      local_54 = *(undefined4 *)(iVar5 + 0x48);
      if (uVar6 <= uVar4) {
        (*pcVar9)(0xc000008c,1,0,0);
      }
      CAct_Lore__GetPosRotSpeed(local_28,&local_50,&local_5c,&local_18,local_40,local_3c);
      if (this->i_28 <= uVar4) {
        (*pcVar9)(0xc000008c,1,0,0);
      }
      iVar5 = *(int *)(this->i_24 + uVar4 * 8);
      if ((((*(float *)(iVar5 + 0xc) != local_50) || (*(float *)(iVar5 + 0x10) != local_4c)) ||
          (*(float *)(iVar5 + 0x14) != local_48)) &&
         (FUN_005cd8e0(&local_50), *(int *)(iVar5 + 0x238) == 0)) {
        FUN_005ebc90(iVar5);
        FUN_005eb470(iVar5);
      }
      if (this->i_28 <= uVar4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar5 = *(int *)(this->i_24 + uVar4 * 8);
      *(undefined4 *)(iVar5 + 0x40) = local_5c;
      *(undefined4 *)(iVar5 + 0x44) = local_58;
      *(undefined4 *)(iVar5 + 0x48) = local_54;
      if ((10000.0 <= *(float *)(iVar5 + 0x40)) || (*(float *)(iVar5 + 0x40) <= -10000.0)) {
        *(undefined4 *)(iVar5 + 0x40) = 0;
      }
      if ((10000.0 <= *(float *)(iVar5 + 0x44)) || (*(float *)(iVar5 + 0x44) <= -10000.0)) {
        *(undefined4 *)(iVar5 + 0x44) = 0;
      }
      if ((10000.0 <= *(float *)(iVar5 + 0x48)) || (*(float *)(iVar5 + 0x48) <= -10000.0)) {
        *(undefined4 *)(iVar5 + 0x48) = 0;
      }
      *(uint *)(iVar5 + 0x3d8) = *(uint *)(iVar5 + 0x3d8) | 2;
      *(undefined1 *)(iVar5 + 0x402) = 1;
      if (*(int *)(iVar5 + 0x238) == 0) {
        if (DAT_00772468 == (undefined1 *)0x0) {
          puVar7 = (undefined1 *)FUN_006ba810(0x2f6);
          local_44 = puVar7;
          if (puVar7 == (undefined1 *)0x0) {
            DAT_00772468 = (undefined1 *)0x0;
          }
          else {
            *(undefined4 *)(puVar7 + 1) = 0;
            *(undefined4 *)(puVar7 + 5) = 0;
            local_8 = CONCAT31(local_8._1_3_,2);
            *puVar7 = 1;
            FUN_005ebb00();
            DAT_00772468 = puVar7;
          }
          local_8 = local_8 & 0xffffff00;
        }
        FUN_005eb470(iVar5);
      }
      local_1c = local_1c + 1;
      pcVar9 = RaiseException_exref;
    } while ((int)local_1c < this->i_28);
  }
  uVar6 = local_30;
  if (local_11 != '\0') {
    local_18 = local_18 - this->f_20 * 0.1;
    if (DAT_007735e4 <= local_30) {
      (*pcVar9)(0xc000008c,1,0,0);
    }
    iVar5 = local_34;
    pfVar1 = (float *)(local_34 + 0x14 + DAT_007735e0);
    if (*pfVar1 <= local_20 && local_20 != *pfVar1) {
      local_18 = local_20;
    }
    if (DAT_007735e4 <= uVar6) {
      (*pcVar9)(0xc000008c,1,0,0);
    }
    fVar10 = local_18;
    if (local_24 < *(float *)(iVar5 + 0x14 + DAT_007735e0)) {
      fVar10 = local_24;
    }
    fVar2 = *(float *)(local_28 + 0x10);
    *(float *)(local_28 + 0x14) = fVar10;
    fVar10 = fVar10 * 0.1 + *(float *)(local_28 + 0xc);
    *(float *)(local_28 + 0xc) = fVar10;
    FUN_0043fd30();
    ExceptionList = local_10;
    return fVar10 < fVar2;
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return false;
}

