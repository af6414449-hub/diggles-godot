
void FUN_0053a270(int *param_1)

{
  undefined4 *puVar1;
  float *pfVar2;
  int iVar3;
  int this;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  float fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 local_54;
  int local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined1 local_24 [12];
  undefined1 local_18 [20];
  
  local_54 = 0x80ffffff;
  local_34 = -2.3509886e-38;
  local_50 = this;
  if (*(int *)(*param_1 + 8) != 0) {
    FUN_004ff430(*param_1 + 0xc,&local_34);
  }
  iVar3 = this->i_c0;
  if (iVar3 == -1) {
    iVar3 = this->i_c0;
  }
  uVar10 = this->i_bc;
  iVar5 = param_1[3];
  FUN_004ff900((undefined4 *)(this + 0xbc),param_1[2],iVar5,uVar10,iVar3,0,0,0);
  iVar3 = DAT_00772400;
  if (this->c_b0 == '\0') {
    this->i_8c = *(undefined4 *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154);
    this->i_90 = *(undefined4 *)(*(int *)(iVar3 + 0x5a4) + 0x158);
    this->i_94 = *(undefined4 *)(*(int *)(iVar3 + 0x5a4) + 0x160);
    this->i_98 = *(undefined4 *)(*(int *)(iVar3 + 0x5a4) + 0x164);
    this->i_9c = *(undefined4 *)(*(int *)(iVar3 + 0x5a4) + 0x15c);
  }
  puVar1 = (undefined4 *)FUN_0053a7b0(local_18);
  uVar11 = puVar1[1];
  uVar12 = puVar1[2];
  uVar13 = puVar1[3];
  this->i_a0 = *puVar1;
  this->i_a4 = uVar11;
  this->i_a8 = uVar12;
  this->i_ac = uVar13;
  uVar11 = this->i_a0;
  uVar12 = this->i_a4;
  uVar13 = this->i_a8;
  uVar14 = this->i_ac;
  iVar3 = this + 100;
  FUN_005a9090(extraout_ECX,iVar3,iVar5,uVar10,uVar11,uVar12,uVar13,uVar14);
  FUN_005a7e40(iVar3,iVar5,uVar10,uVar11,uVar12,uVar13,uVar14);
  local_30 = 0.0;
  local_2c = 0.0;
  local_28 = 0x41680000;
  pfVar2 = (float *)FUN_00479150(local_24,&local_30);
  iVar3 = this->i_a0;
  iVar6 = this->i_a8 - iVar3;
  iVar8 = this->i_ac - this->i_a4;
  local_30 = 0.0;
  local_28 = 0x41680000;
  local_38 = ((*pfVar2 - (float)iVar3) / (float)iVar6) * 138.0;
  local_3c = ((pfVar2[1] - (float)this->i_a4) / (float)iVar8) * 138.0;
  local_2c = (float)*(int *)(DAT_0076a338 + 0x2834);
  pfVar2 = (float *)FUN_00479150(local_18,&local_30);
  local_48 = ((*pfVar2 - (float)iVar3) / (float)iVar6) * 138.0;
  local_4c = ((pfVar2[1] - (float)*(int *)(local_50 + 0xa4)) / (float)iVar8) * 138.0;
  local_30 = (float)*(int *)(extraout_ECX_00 + 0x2830);
  local_28 = 0x41680000;
  local_2c = (float)*(int *)(extraout_ECX_00 + 0x2834);
  pfVar2 = (float *)FUN_00479150(local_24,&local_30);
  local_2c = 0.0;
  local_28 = 0x41680000;
  local_40 = ((*pfVar2 - (float)iVar3) / (float)iVar6) * 138.0;
  local_44 = ((pfVar2[1] - (float)*(int *)(local_50 + 0xa4)) / (float)iVar8) * 138.0;
  local_30 = (float)*(int *)(extraout_ECX_01 + 0x2830);
  pfVar2 = (float *)FUN_00479150(local_18,&local_30);
  iVar5 = local_50;
  local_54 = 0xbed7d7d7;
  local_34 = ((*pfVar2 - (float)iVar3) / (float)iVar6) * 138.0;
  fVar9 = ((pfVar2[1] - (float)*(int *)(local_50 + 0xa4)) / (float)iVar8) * 138.0;
  FUN_004ff250(local_4c,&local_54);
  local_54 = 0xbed7d7d7;
  FUN_004ff250(local_44,&local_54);
  local_54 = 0xbed7d7d7;
  FUN_004ff250(fVar9,&local_54);
  local_54 = 0xbed7d7d7;
  FUN_004ff250(local_3c,&local_54);
  uVar7 = 0;
  if (0 < *(int *)(iVar5 + 0x60)) {
    iVar6 = 0;
    iVar3 = iVar5;
    do {
      uVar4 = *(uint *)(iVar3 + 0x60);
      if (uVar4 <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar4 = *(uint *)(iVar3 + 0x60);
      }
      iVar5 = local_50;
      iVar3 = *(int *)(iVar3 + 0x5c);
      local_38 = (float)(iVar6 + iVar3);
      if (uVar4 <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = *(int *)(iVar5 + 0x5c);
      }
      local_34 = *(float *)(iVar6 + iVar3);
      local_38 = *(float *)((int)local_38 + 4);
      if (*(uint *)(iVar5 + 0x60) <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = *(int *)(iVar5 + 0x5c);
      }
      iVar3 = *(int *)(iVar6 + 8 + iVar3);
      if (iVar3 == -1) {
        iVar3 = *(int *)(iVar5 + 0xf4);
      }
      FUN_004ff900(iVar5 + 0xf4,param_1[2] + (int)local_34,param_1[3] + (int)local_38,iVar3,1,
                   local_34,((int)local_38 - *(int *)(iVar5 + 0xc0)) + 0x8a,3);
      uVar7 = uVar7 + 1;
      iVar6 = iVar6 + 0xc;
      iVar3 = iVar5;
    } while ((int)uVar7 < *(int *)(iVar5 + 0x60));
  }
  *(undefined4 *)(iVar5 + 0x44) = *(undefined4 *)(DAT_00772400 + 0x6c);
  return;
}

