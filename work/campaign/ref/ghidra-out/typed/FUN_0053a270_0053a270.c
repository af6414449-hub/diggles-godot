
void __thiscall FUN_0053a270(ViWinSmallMap *this)

{
  int *piVar1;
  float *pfVar2;
  undefined4 extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  uint uVar3;
  ViWinSmallMap *pVVar4;
  ViWinSmallMap *pVVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  int *in_stack_00000004;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 local_54;
  ViWinSmallMap *local_50;
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
  if (*(int *)(*in_stack_00000004 + 8) != 0) {
    FUN_004ff430(*in_stack_00000004 + 0xc,&local_34);
  }
  iVar9 = this->i_c0;
  if (iVar9 == -1) {
    iVar9 = this->i_c0;
  }
  iVar6 = this->i_bc;
  iVar8 = in_stack_00000004[3];
  FUN_004ff900(&this->i_bc,in_stack_00000004[2],iVar8,iVar6,iVar9,0,0,0);
  iVar9 = DAT_00772400;
  if (this->c_b0 == '\0') {
    this->i_8c = *(int *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154);
    this->i_90 = *(int *)(*(int *)(iVar9 + 0x5a4) + 0x158);
    this->i_94 = *(int *)(*(int *)(iVar9 + 0x5a4) + 0x160);
    this->i_98 = *(int *)(*(int *)(iVar9 + 0x5a4) + 0x164);
    this->i_9c = *(int *)(*(int *)(iVar9 + 0x5a4) + 0x15c);
  }
  piVar1 = (int *)FUN_0053a7b0(local_18);
  iVar9 = piVar1[1];
  iVar11 = piVar1[2];
  iVar12 = piVar1[3];
  this->i_a0 = *piVar1;
  this->i_a4 = iVar9;
  this->i_a8 = iVar11;
  this->i_ac = iVar12;
  iVar9 = this->i_a0;
  iVar11 = this->i_a4;
  iVar12 = this->i_a8;
  iVar13 = this->i_ac;
  piVar1 = &this->i_64;
  FUN_005a9090(extraout_ECX,piVar1,iVar8,iVar6,iVar9,iVar11,iVar12,iVar13);
  FUN_005a7e40(piVar1,iVar8,iVar6,iVar9,iVar11,iVar12,iVar13);
  local_30 = 0.0;
  local_2c = 0.0;
  local_28 = 0x41680000;
  pfVar2 = (float *)FUN_00479150(local_24,&local_30);
  iVar9 = this->i_a0;
  iVar6 = this->i_a8 - iVar9;
  iVar8 = this->i_ac - this->i_a4;
  local_30 = 0.0;
  local_28 = 0x41680000;
  local_38 = ((*pfVar2 - (float)iVar9) / (float)iVar6) * 138.0;
  local_3c = ((pfVar2[1] - (float)this->i_a4) / (float)iVar8) * 138.0;
  local_2c = (float)*(int *)(DAT_0076a338 + 0x2834);
  pfVar2 = (float *)FUN_00479150(local_18,&local_30);
  local_48 = ((*pfVar2 - (float)iVar9) / (float)iVar6) * 138.0;
  local_4c = ((pfVar2[1] - (float)local_50->i_a4) / (float)iVar8) * 138.0;
  local_30 = (float)*(int *)(extraout_ECX_00 + 0x2830);
  local_28 = 0x41680000;
  local_2c = (float)*(int *)(extraout_ECX_00 + 0x2834);
  pfVar2 = (float *)FUN_00479150(local_24,&local_30);
  local_2c = 0.0;
  local_28 = 0x41680000;
  local_40 = ((*pfVar2 - (float)iVar9) / (float)iVar6) * 138.0;
  local_44 = ((pfVar2[1] - (float)local_50->i_a4) / (float)iVar8) * 138.0;
  local_30 = (float)*(int *)(extraout_ECX_01 + 0x2830);
  pfVar2 = (float *)FUN_00479150(local_18,&local_30);
  pVVar5 = local_50;
  local_54 = 0xbed7d7d7;
  local_34 = ((*pfVar2 - (float)iVar9) / (float)iVar6) * 138.0;
  fVar10 = ((pfVar2[1] - (float)local_50->i_a4) / (float)iVar8) * 138.0;
  FUN_004ff250(local_4c,&local_54);
  local_54 = 0xbed7d7d7;
  FUN_004ff250(local_44,&local_54);
  local_54 = 0xbed7d7d7;
  FUN_004ff250(fVar10,&local_54);
  local_54 = 0xbed7d7d7;
  FUN_004ff250(local_3c,&local_54);
  uVar7 = 0;
  if (0 < pVVar5->i_60) {
    iVar9 = 0;
    pVVar4 = pVVar5;
    do {
      uVar3 = pVVar4->i_60;
      if (uVar3 <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        uVar3 = pVVar4->i_60;
      }
      pVVar5 = local_50;
      iVar6 = *(int *)&pVVar4->field_0x5c;
      local_38 = (float)(iVar9 + iVar6);
      if (uVar3 <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = *(int *)&pVVar5->field_0x5c;
      }
      local_34 = *(float *)(iVar9 + iVar6);
      local_38 = *(float *)((int)local_38 + 4);
      if ((uint)pVVar5->i_60 <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar6 = *(int *)&pVVar5->field_0x5c;
      }
      iVar6 = *(int *)(iVar9 + 8 + iVar6);
      if (iVar6 == -1) {
        iVar6 = pVVar5->i_f4;
      }
      FUN_004ff900(&pVVar5->i_f4,in_stack_00000004[2] + (int)local_34,
                   in_stack_00000004[3] + (int)local_38,iVar6,1,local_34,
                   ((int)local_38 - pVVar5->i_c0) + 0x8a,3);
      uVar7 = uVar7 + 1;
      iVar9 = iVar9 + 0xc;
      pVVar4 = pVVar5;
    } while ((int)uVar7 < pVVar5->i_60);
  }
  pVVar5->i_44 = *(int *)(DAT_00772400 + 0x6c);
  return;
}

