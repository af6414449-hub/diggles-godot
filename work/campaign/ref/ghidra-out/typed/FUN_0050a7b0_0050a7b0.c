
void __thiscall FUN_0050a7b0(ViWinClock *this)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070129e;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004fef30("data/gui/buttons/Uhr_Normal.tga");
  FUN_004fef30("data/gui/buttons/Uhr_Gehov.tga");
  local_18 = this->i_ac;
  local_14 = (int *)(this->i_b0 + 0x32);
  FUN_00504ba0(&local_18);
  local_18 = 0;
  local_14 = (int *)0x0;
  local_1c = (int *)FUN_006ba810(10,uVar3);
  local_8 = 0;
  if (local_1c == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_00507b40();
  }
  local_8 = 0xffffffff;
  FUN_00507d40("data/gui/buttons/UhrButtonTag");
  FUN_00504a70(&local_18);
  FUN_00504ce0(iVar4);
  this->i_70 = iVar4;
  if (*(char *)(iVar4 + 0x1c) != '\0') {
    FUN_00504ee0();
    *(undefined1 *)(iVar4 + 0x1c) = 0;
  }
  uVar5 = FUN_004435d0(&local_14,"Work start");
  piVar6 = (int *)FUN_00443730(uVar5);
  local_8 = 1;
  iVar4 = this->i_70;
  piVar1 = (int *)*piVar6;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar6 + 8);
  local_8 = 2;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  local_18 = 0;
  local_14 = (int *)0x0;
  local_1c = (int *)FUN_006ba810(10);
  local_8 = 3;
  if (local_1c == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_00507b40();
  }
  local_8 = 0xffffffff;
  FUN_00507d40("data/gui/buttons/UhrButtonNacht");
  FUN_00504a70(&local_18);
  FUN_00504ce0(iVar4);
  this->i_74 = iVar4;
  FUN_00505ed0();
  uVar5 = FUN_004435d0(&local_14,"Work end");
  piVar6 = (int *)FUN_00443730(uVar5);
  local_8 = 4;
  iVar4 = this->i_74;
  piVar1 = (int *)*piVar6;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar6 + 8);
  local_8 = 5;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  iVar4 = this->i_74;
  if (*(char *)(iVar4 + 0x1c) != '\0') {
    FUN_00504ee0();
    *(undefined1 *)(iVar4 + 0x1c) = 0;
  }
  local_18 = 0;
  local_14 = (int *)0x64;
  local_1c = (int *)FUN_006ba810(10);
  local_8 = 6;
  if (local_1c == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_00507b40();
  }
  local_8 = 0xffffffff;
  FUN_00507d40("data/gui/icons/AutoProd_On");
  FUN_00504a70(&local_18);
  FUN_00504ce0(iVar4);
  this->i_e8 = iVar4;
  uVar5 = FUN_004435d0(&local_1c,"Automatic schedule");
  piVar6 = (int *)FUN_00443730(uVar5);
  local_8 = 7;
  iVar4 = this->i_e8;
  piVar1 = (int *)*piVar6;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar6 + 8);
  local_8 = 8;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  iVar4 = this->i_70;
  this->c_a8 = '\x01';
  if (*(char *)(iVar4 + 0x1c) != '\0') {
    FUN_00504ee0();
    *(undefined1 *)(iVar4 + 0x1c) = 0;
  }
  FUN_00505e90(1000000,0,1,1);
  ExceptionList = local_10;
  return;
}

