
void FUN_0054c450(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int this;
  int *piVar6;
  int *local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  undefined1 local_14;
  undefined2 local_13;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007043b5;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_24 = this->i_14 - this->i_0c;
  local_20 = this->i_18 - this->i_10;
  local_13 = 0;
  local_14 = 0;
  local_11 = 0xd2;
  local_2c = 0;
  local_28 = 0;
  FUN_004fdf00(&local_2c,&local_14);
  if (this->i_54 == 0) {
    local_1c = 0x32;
    local_18 = (int *)0x32;
    uVar4 = FUN_00507ab0("data/gui/icons/xoverlay_Crossout",uVar3);
    this->i_54 = uVar4;
  }
  local_1c = (this->i_14 - this->i_0c) + -0x3c;
  local_18 = (int *)&DAT_00000005;
  FUN_00504a70(&local_1c);
  FUN_00505ed0();
  uVar4 = FUN_004435d0(&local_18,"Techtree");
  FUN_00443730(uVar4);
  local_8 = 0;
  uVar4 = 0x54c533;
  FUN_004ef860(&DAT_00725a00);
  piVar2 = local_18;
  local_8 = CONCAT31(local_8._1_3_,1);
  piVar1 = local_18 + 3;
  piVar6 = (int *)0x54c542;
  piVar5 = (int *)FUN_004ef240();
  if (local_30 == *piVar5) {
    if (local_34 != 0) goto LAB_0054c571;
  }
  else {
    local_34 = 0;
    local_30 = *piVar5;
  }
  piVar6 = local_38 + 3;
  uVar4 = 0x54c56e;
  local_34 = FUN_004ef660(piVar6);
LAB_0054c571:
  FUN_004edf70(&local_24,piVar1,uVar4,piVar6);
  local_20 = local_20 + 5;
  local_13 = 0xffff;
  local_24 = (this->i_14 - this->i_0c) / 2 - local_24 / 2;
  local_14 = 0xff;
  local_11 = 0xff;
  FUN_004fdff0(&local_24,piVar2 + 3,&local_14,&local_38,1,local_24);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
    FUN_006ba940();
  }
  local_8 = 3;
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

