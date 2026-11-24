
void __thiscall FUN_00506500(ViWinAutoPopup *this)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int **ppiStack_44;
  char *pcStack_40;
  uint uStack_3c;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00700d3d;
  local_10 = ExceptionList;
  uStack_3c = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcStack_40 = (char *)0x19;
  ppiStack_44 = (int **)0x50653b;
  local_1c = (int *)FUN_006ba810();
  local_1c[1] = 0x14;
  local_1c[2] = -1;
  *local_1c = 0;
  *(undefined1 *)(local_1c + 3) = 0;
  local_1c[3] = 0x74786554;
  *(undefined1 *)(local_1c + 4) = 0;
  local_1c[2] = 4;
  *local_1c = 1;
  pcStack_40 = (char *)0x0;
  ppiStack_44 = (int **)0x74786554;
  local_8 = 0;
  local_24 = 10;
  local_20 = 10;
  local_2c = 0x8c;
  local_28 = 0x14;
  local_18 = local_1c;
  uVar3 = FUN_004435d0(&ppiStack_44,"Main Menu");
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Go to main menu";
  *(undefined4 *)(iVar4 + 8) = 1;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 1;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x50660b;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 2;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = "j";
    FUN_006ba940();
  }
  pcStack_40 = (char *)0x0;
  local_8._0_1_ = 0;
  local_20 = 0x1e;
  uVar3 = FUN_004435d0(&ppiStack_44,"Options");
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Game options";
  *(undefined4 *)(iVar4 + 8) = 2;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 3;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x5066a2;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 4;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = "j";
    FUN_006ba940();
  }
  pcStack_40 = (char *)0x0;
  local_8._0_1_ = 0;
  local_20 = 0x32;
  uVar3 = FUN_004435d0(&ppiStack_44,"Load game");
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Load saved game";
  *(undefined4 *)(iVar4 + 8) = 3;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 5;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x506739;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 6;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = "j";
    FUN_006ba940();
  }
  pcStack_40 = (char *)0x0;
  local_8._0_1_ = 0;
  local_20 = 0x46;
  uVar3 = FUN_004435d0(&ppiStack_44,"Save game");
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Save current game";
  *(undefined4 *)(iVar4 + 8) = 4;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 7;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x5067d0;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 8;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = "j";
    FUN_006ba940();
  }
  pcStack_40 = (char *)0x0;
  local_8._0_1_ = 0;
  local_20 = 0x5a;
  uVar3 = FUN_004435d0(&ppiStack_44,"Quicksave");
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Quicksave current game";
  *(undefined4 *)(iVar4 + 8) = 5;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 9;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x506867;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 10;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = "j";
    FUN_006ba940();
  }
  pcStack_40 = (char *)0x0;
  local_8._0_1_ = 0;
  local_20 = 0x73;
  uVar3 = FUN_004435d0(&ppiStack_44,"Gnomes");
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Show gnome stats";
  *(undefined4 *)(iVar4 + 8) = 10;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 0xb;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x5068fe;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 0xc;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = "j";
    FUN_006ba940();
  }
  pcStack_40 = (char *)0x0;
  local_8._0_1_ = 0;
  local_20 = 0x87;
  uVar3 = FUN_004435d0(&ppiStack_44,"Techtree");
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Show technologies";
  *(undefined4 *)(iVar4 + 8) = 0xb;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 0xd;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x506995;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 0xe;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = "j";
    FUN_006ba940();
  }
  pcStack_40 = (char *)0x0;
  local_8._0_1_ = 0;
  local_20 = 0x9b;
  uVar3 = FUN_004435d0(&ppiStack_44,"Production");
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Show production sites";
  *(undefined4 *)(iVar4 + 8) = 0xc;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 0xf;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x506a2c;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 0x10;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = "j";
    FUN_006ba940();
  }
  pcStack_40 = (char *)0x0;
  local_8._0_1_ = 0;
  local_20 = 0xaf;
  uVar3 = FUN_004435d0(&ppiStack_44,"Pedigree");
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Show gnome pedigree";
  *(undefined4 *)(iVar4 + 8) = 0xd;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 0x11;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x506ac3;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 0x12;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = "j";
    FUN_006ba940();
  }
  pcStack_40 = (char *)0x0;
  local_8._0_1_ = 0;
  local_20 = 0xc3;
  uVar3 = FUN_004435d0(&ppiStack_44,"Questlog");
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Show questlog";
  *(undefined4 *)(iVar4 + 8) = 0xe;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 0x13;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x506b5a;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 0x14;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = "j";
    FUN_006ba940();
  }
  pcStack_40 = (char *)0x0;
  local_8._0_1_ = 0;
  local_20 = 0xdc;
  uVar3 = FUN_004435d0(&ppiStack_44,&DAT_00725c74);
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Show online help";
  *(undefined4 *)(iVar4 + 8) = 0x14;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 0x15;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x506bf1;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 0x16;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = "j";
    FUN_006ba940();
  }
  pcStack_40 = (char *)0x0;
  local_8._0_1_ = 0;
  local_20 = 0xfa;
  uVar3 = FUN_004435d0(&ppiStack_44,&DAT_00725c90);
  FUN_00443730(uVar3);
  iVar4 = FUN_00518ed0(&local_2c);
  ppiStack_44 = &local_14;
  pcStack_40 = "Quit game";
  *(undefined4 *)(iVar4 + 8) = 100;
  uVar3 = FUN_004435d0();
  piVar5 = (int *)FUN_00443730(uVar3);
  local_8._0_1_ = 0x17;
  piVar1 = (int *)*piVar5;
  piVar2 = *(int **)(iVar4 + 0x30);
  *(int **)(iVar4 + 0x30) = piVar1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
    pcStack_40 = (char *)0x506c88;
    FUN_006ba940();
  }
  *(undefined4 *)(*(int *)(iVar4 + 0x30) + 8) = *(undefined4 *)(*piVar5 + 8);
  local_8._0_1_ = 0x18;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    pcStack_40 = (char *)0x506ca8;
    FUN_006ba940();
  }
  pcStack_40 = (char *)&local_2c;
  local_8 = (uint)local_8._1_3_ << 8;
  local_2c = 0xa0;
  local_28 = 0x113;
  ppiStack_44 = (int **)0x506cc5;
  FUN_00504ba0();
  local_8 = 0x19;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    pcStack_40 = (char *)0x506cd9;
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return;
}

