
void FUN_00506e20(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int *piVar5;
  int this;
  int iVar6;
  undefined4 extraout_ECX;
  int iVar7;
  int iVar8;
  float10 fVar9;
  undefined4 uVar10;
  undefined8 uVar12;
  int *local_78;
  int local_74;
  int local_70;
  double local_6c;
  int local_64;
  undefined8 local_60;
  int local_58;
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  double dVar11;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00700d6d;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  fVar1 = this->f_44;
  fVar2 = this->f_48;
  fVar3 = fVar1;
  if (fVar1 <= this->f_58) {
    fVar3 = this->f_58;
  }
  local_64 = this->i_14 - this->i_0c;
  local_60._4_4_ = fVar2;
  if (fVar3 <= fVar2) {
    local_60._4_4_ = fVar3;
  }
  iVar8 = this->i_18 - this->i_10;
  DAT_00772dd8 = (int)ROUND(((local_60._4_4_ - fVar1) * (float)local_64) / (fVar2 - fVar1));
  piVar5 = *(int **)(this + 0x54);
  iVar6 = DAT_00772dd8;
  if (DAT_00772dd8 == -1) {
    iVar6 = *piVar5;
  }
  iVar7 = iVar8;
  if (iVar8 == -1) {
    iVar7 = piVar5[1];
  }
  local_58 = DAT_00772dd8;
  local_14 = uVar4;
  FUN_004ff900(piVar5,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),iVar6,iVar7,0,0,0)
  ;
  piVar5 = *(int **)(this + 0x50);
  iVar6 = local_64;
  if (local_64 == -1) {
    iVar6 = *piVar5;
  }
  if (iVar8 == -1) {
    iVar8 = piVar5[1];
  }
  FUN_004ff900(piVar5,*(int *)(param_1 + 8) + local_58,*(undefined4 *)(param_1 + 0xc),iVar6,iVar8,
               local_58,0,0);
  FUN_004ef7b0();
  local_8 = 0;
  fVar1 = this->f_4c;
  if (fVar1 == -1.0) goto LAB_00507025;
  local_60._4_4_ = fVar1 * local_60._4_4_;
  local_6c = (double)(this->f_48 * fVar1);
  fVar9 = (float10)FUN_006f6da0(local_6c,uVar4);
  dVar11 = (double)fVar9;
  local_60 = (double)local_60._4_4_;
  local_6c = dVar11;
  fVar9 = (float10)FUN_006f6da0(local_60,dVar11);
  uVar10 = SUB84(dVar11,0);
  local_60 = (double)fVar9;
  FUN_0043ffe0(local_54,"%3.0f / %3.0f",local_60);
  uVar12 = CONCAT44(0x506fa7,uVar10);
  piVar5 = (int *)FUN_004ef240();
  if (local_70 == *piVar5) {
    if (local_74 == 0) goto LAB_00506fc5;
  }
  else {
    local_74 = 0;
    local_70 = *piVar5;
LAB_00506fc5:
    uVar12 = CONCAT44(local_78 + 3,0x506fd3);
    local_74 = FUN_004ef660();
  }
  FUN_004edf70(&local_60,local_54,uVar12);
  local_60._0_4_ = (local_64 - (int)local_60) / 2;
  local_60._4_4_ = 1.4013e-44;
  local_58 = -1;
  FUN_004fdff0(&local_60,local_54,&local_58,&local_78,1,extraout_ECX);
LAB_00507025:
  local_8 = 1;
  if ((local_78 != (int *)0x0) && (*local_78 = *local_78 + -1, *local_78 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

