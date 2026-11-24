
void __thiscall FUN_00527100(ViWinTextButton *this)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar4;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  int iVar5;
  int *in_stack_00000004;
  undefined4 uVar6;
  int *piVar7;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  int local_40 [3];
  int local_34;
  int *local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007026ad;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = *(int *)(in_stack_00000004[1] + 8);
  if (*(int *)(*in_stack_00000004 + 8) != 0) {
    FUN_004ff430(*in_stack_00000004 + 0xc,&local_1c);
  }
  uVar6 = 0x527157;
  FUN_004ef7b0(&this[1].field_0x4);
  local_8 = 0;
  local_40[2] = (this->i_14 - this->i_0c) + -3;
  local_48 = (this->i_14 - this->i_0c) + -1;
  local_34 = (this->i_18 - this->i_10) + -3;
  local_40[0] = 2;
  local_44 = (this->i_18 - this->i_10) + -1;
  iVar3 = this->i_20;
  local_40[1] = 2;
  local_50 = 0;
  local_4c = 0;
  piVar7 = (int *)0x5271b7;
  local_1c = local_40[2];
  local_14 = local_34;
  piVar2 = (int *)FUN_004ef240(uVar1);
  if (local_28 == *piVar2) {
    if (local_2c != 0) goto LAB_005271e6;
  }
  else {
    local_2c = 0;
    local_28 = *piVar2;
  }
  piVar7 = local_30 + 3;
  uVar6 = 0x5271e3;
  local_2c = FUN_004ef660(piVar7);
LAB_005271e6:
  FUN_004edf70(&local_24,iVar3 + 0xc,uVar6,piVar7);
  piVar2 = in_stack_00000004;
  local_24 = ((this->i_14 - this->i_0c) - local_24) / 2;
  local_20 = ((this->i_18 - this->i_10) + local_20) / 2 + -3;
  local_18 = local_24;
  if (this->i_48 == 0) {
    if ((this->c_24 & 2U) == 0) {
      FUN_004fdf00(local_40,in_stack_00000004[1] + 8);
      FUN_004fdd70(local_40,piVar2[1] + 8,0);
      FUN_004fdff0(&local_24,this->i_20 + 0xc,piVar2[1] + 0x18,&local_30,1,extraout_ECX_00);
      iVar3 = piVar2[1] + 0x18;
    }
    else {
      FUN_004fdf00(local_40,in_stack_00000004[1] + 8);
      FUN_004fdd70(local_40,piVar2[1] + 8,0);
      FUN_004fdff0(&local_24,this->i_20 + 0xc,piVar2[1] + 0x18,&local_30,1,extraout_ECX);
      iVar3 = piVar2[1] + 8;
    }
    FUN_004fdd70(&local_50,iVar3,1);
  }
  iVar3 = this->i_48;
  iVar4 = 2;
  local_40[1] = 2;
  iVar5 = local_1c;
  if (iVar3 == 1) {
    FUN_004fdd70(&local_50,piVar2[1] + 0x10,1);
    local_34 = local_14 + -1;
    local_20 = local_20 + -1;
    iVar5 = local_1c + -1;
    local_24 = local_18 + -1;
    local_40[0] = 1;
    local_40[1] = 1;
    in_stack_00000004 = *(int **)(piVar2[1] + 0x10);
    local_40[2] = iVar5;
    local_18 = local_24;
    local_14 = local_34;
    FUN_004fdf00(local_40,&stack0x00000004);
    FUN_004fdd70(local_40,&stack0x00000004,0);
    FUN_004fdff0(&local_24,this->i_20 + 0xc,piVar2[1] + 0x20,&local_30,1,extraout_ECX_01);
    iVar3 = this->i_48;
    iVar4 = 1;
    local_40[1] = 1;
  }
  if ((iVar3 == 2) || (iVar3 == 3)) {
    local_20 = local_20 + 1;
    local_40[0] = 2;
    iVar5 = iVar5 + (2 - iVar4);
    local_40[1] = 2;
    local_24 = local_18 + 1;
    local_34 = local_14 + (2 - iVar4);
    local_40[2] = iVar5;
    local_18 = local_24;
    local_14 = local_34;
    FUN_004fdf00(local_40,piVar2[1] + 0xc);
    FUN_004fdff0(&local_24,this->i_20 + 0xc,piVar2[1] + 0x1c,&local_30,1,extraout_ECX_02);
    FUN_004fdd70(&local_50,piVar2[1] + 0xc,1);
    iVar3 = this->i_48;
    iVar4 = 2;
    local_40[1] = 2;
  }
  local_40[0] = iVar4;
  if (iVar3 == 5) {
    local_20 = local_20 + 1;
    local_40[0] = 2;
    local_40[2] = iVar5 + (2 - iVar4);
    local_40[1] = 2;
    local_34 = local_14 + (2 - iVar4);
    local_24 = local_18 + 1;
    FUN_004fdf00(local_40,piVar2[1] + 0x14);
    FUN_004fdff0(&local_24,this->i_20 + 0xc,piVar2[1] + 0x24,&local_30,1,extraout_ECX_03);
    FUN_004fdd70(&local_50,piVar2[1] + 0x14,1);
  }
  if (this->i_48 == 4) {
    FUN_004fdf00(local_40,piVar2[1] + 0x14);
    FUN_004fdff0(&local_24,this->i_20 + 0xc,piVar2[1] + 0x24,&local_30,1,extraout_ECX_04);
    FUN_004fdd70(&local_50,piVar2[1] + 0x14,1);
  }
  local_8 = 1;
  if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

