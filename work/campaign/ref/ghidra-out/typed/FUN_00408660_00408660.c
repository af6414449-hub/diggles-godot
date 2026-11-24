
undefined4 __thiscall FUN_00408660(CAct_Anim *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  iVar3 = this->i_0c;
  if ((((iVar3 != 0) && (*(int *)(iVar3 + 0x3a0) != -1)) &&
      (uVar1 = *(uint *)(iVar3 + 0x39c), uVar1 != 0xffffffff)) &&
     ((uVar1 < 0x100 && (iVar2 = *(int *)(DAT_00772400 + 0x5c8 + uVar1 * 4), iVar2 != 0)))) {
    iVar3 = FUN_004059a0(*(int *)(iVar3 + 0x3a0));
    iVar3 = *(int *)(iVar3 + 0xd8);
    if (iVar3 < *(int *)(iVar2 + 0xac)) {
      FUN_00408920(iVar3);
      FUN_00408a10();
      iVar3 = FUN_00408920(iVar3);
      if (*(float *)(iVar3 + 0xc) * *(float *)(iVar3 + 0xc) +
          *(float *)(iVar3 + 8) * *(float *)(iVar3 + 8) +
          *(float *)(iVar3 + 0x10) * *(float *)(iVar3 + 0x10) +
          local_24 * local_24 + local_28 * local_28 + local_20 * local_20 != 0.0) {
        iVar3 = this->i_0c;
        local_30 = *(undefined4 *)(iVar3 + 0x44);
        fVar6 = *(float *)(iVar3 + 0x40);
        local_2c = *(undefined4 *)(iVar3 + 0x48);
        local_34 = fVar6;
        FUN_004089d0();
        fVar5 = *(float *)(iVar3 + 0x40);
        local_c = fVar6;
        FUN_004089f0();
        fVar6 = *(float *)(iVar3 + 0x44);
        local_18 = local_24 * fVar5 + local_20 * local_c;
        local_8 = local_20 * fVar5 - local_24 * local_c;
        FUN_004089d0();
        fVar5 = *(float *)(iVar3 + 0x44);
        local_c = fVar6;
        FUN_004089f0();
        local_14 = fVar5 * local_28 - local_8 * local_c;
        fVar6 = *(float *)(iVar3 + 0x48);
        local_10 = fVar5;
        FUN_004089d0();
        fVar5 = *(float *)(iVar3 + 0x48);
        local_1c = fVar6;
        FUN_004089f0();
        fVar6 = (local_8 * local_10 + local_c * local_28) * 0.005;
        local_28 = (local_14 * fVar5 + local_18 * local_1c) * 0.005 + *(float *)(iVar3 + 0xc);
        local_20 = fVar6 + fVar6 + *(float *)(iVar3 + 0x14);
        local_24 = (local_18 * fVar5 - local_14 * local_1c) * 0.005 + *(float *)(iVar3 + 0x10);
        FUN_005cd7e0(&local_28);
        uVar4 = FUN_005e6060(&local_34);
        FUN_005cd840(uVar4);
      }
    }
  }
  this->i_0c = 0;
  return 1;
}

