
void FUN_0050dca0(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int this;
  int iVar4;
  int local_20;
  int *local_1c;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00701437;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_18 = 10;
  local_14 = (int *)0x0;
  local_1c = (int *)FUN_006ba810(10,DAT_0076700c ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (local_1c == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00507b40();
  }
  local_8 = 0xffffffff;
  FUN_00507d40("data/gui/icons/BuddelnG");
  FUN_00504a70(&local_18);
  FUN_00504ce0(uVar3);
  this->i_44 = uVar3;
  uVar3 = FUN_004435d0(&local_1c,"Tunnel");
  local_14 = (int *)FUN_00443730(uVar3);
  local_8 = 1;
  iVar4 = this->i_44;
  piVar1 = (int *)*local_14;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*local_14 + 8);
  local_8 = 2;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  local_18 = 0x46;
  local_14 = (int *)0x0;
  local_1c = (int *)FUN_006ba810(10);
  local_8 = 3;
  if (local_1c == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00507b40();
  }
  local_8 = 0xffffffff;
  FUN_00507d40("data/gui/icons/BuddelnH0");
  FUN_00504a70(&local_18);
  FUN_00504ce0(uVar3);
  this->i_48 = uVar3;
  uVar3 = FUN_004435d0(&local_14,&DAT_007263d4);
  local_1c = (int *)FUN_00443730(uVar3);
  local_8 = 4;
  iVar4 = this->i_48;
  piVar1 = (int *)*local_1c;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*local_1c + 8);
  local_8 = 5;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  local_18 = 0x82;
  local_14 = (int *)0x0;
  local_1c = (int *)FUN_006ba810(10);
  local_8 = 6;
  if (local_1c == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00507b40();
  }
  local_8 = 0xffffffff;
  FUN_00507d40("data/gui/icons/BuddelnH1");
  FUN_00504a70(&local_18);
  FUN_00504ce0(uVar3);
  this->i_4c = uVar3;
  uVar3 = FUN_004435d0(&local_14,"Small");
  local_1c = (int *)FUN_00443730(uVar3);
  local_8 = 7;
  iVar4 = this->i_4c;
  piVar1 = (int *)*local_1c;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*local_1c + 8);
  local_8 = 8;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  local_18 = 0xbe;
  local_14 = (int *)0x0;
  local_1c = (int *)FUN_006ba810(10);
  local_8 = 9;
  if (local_1c == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00507b40();
  }
  local_8 = 0xffffffff;
  FUN_00507d40("data/gui/icons/BuddelnH2");
  FUN_00504a70(&local_18);
  FUN_00504ce0(uVar3);
  this->i_50 = uVar3;
  uVar3 = FUN_004435d0(&local_14,"Medium");
  local_1c = (int *)FUN_00443730(uVar3);
  local_8 = 10;
  iVar4 = this->i_50;
  piVar1 = (int *)*local_1c;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*local_1c + 8);
  local_8 = 0xb;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  local_18 = 0xfa;
  local_14 = (int *)0x0;
  local_1c = (int *)FUN_006ba810(10);
  local_8 = 0xc;
  if (local_1c == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00507b40();
  }
  local_8 = 0xffffffff;
  FUN_00507d40("data/gui/icons/BuddelnH3");
  FUN_00504a70(&local_18);
  FUN_00504ce0(uVar3);
  this->i_54 = uVar3;
  uVar3 = FUN_004435d0(&local_14,&DAT_00726440);
  local_1c = (int *)FUN_00443730(uVar3);
  local_8 = 0xd;
  iVar4 = this->i_54;
  piVar1 = (int *)*local_1c;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*local_1c + 8);
  local_8 = 0xe;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  local_18 = 0x14a;
  local_14 = (int *)0x0;
  local_1c = (int *)FUN_006ba810(10);
  local_8 = 0xf;
  if (local_1c == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00507b40();
  }
  local_8 = 0xffffffff;
  FUN_00507d40("data/gui/icons/BuddelnUndo");
  FUN_00504a70(&local_18);
  FUN_00504ce0(uVar3);
  this->i_58 = uVar3;
  uVar3 = FUN_004435d0(&local_14,&DAT_00726464);
  local_1c = (int *)FUN_00443730(uVar3);
  local_8 = 0x10;
  iVar4 = this->i_58;
  piVar1 = (int *)*local_1c;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*local_1c + 8);
  local_8 = 0x11;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  iVar4 = 0;
  local_1c = (int *)0x0;
  do {
    local_20 = iVar4;
    FUN_00504a70(&local_20);
    iVar4 = iVar4 + 0x28;
  } while (iVar4 < 0xf0);
  iVar4 = FUN_00501450();
  local_20 = 0xc3;
  local_1c = (int *)((*(int *)(*(int *)(iVar4 + 0x8194) + 0x18) -
                     *(int *)(*(int *)(iVar4 + 0x8194) + 0x10)) + -0x41);
  FUN_00504a70(&local_20);
  local_20 = 0xf0;
  local_1c = (int *)0x28;
  FUN_00504ba0(&local_20);
  ExceptionList = local_10;
  return;
}

