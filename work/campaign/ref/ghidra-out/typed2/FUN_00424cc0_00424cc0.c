
CMap * __thiscall FUN_00424cc0(CMap *this)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_006fa9ab;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  this->mapFlags4 = 0;
  this->cellCount = 0;
  this->cells = (CMapCell *)0x0;
  *(undefined4 *)&this->field_0x28 = 0;
  this->mapFlags6 = 0;
  this->mapFlags7 = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  this->mapFlagsB = 0;
  this->mapFlagsA = 0;
  this->mapFlags9 = 0;
  this->mapFlagsE = 0;
  this->mapFlagsD = 0;
  this->mapFlagsC = 0;
  this->scanlineTotal = 0;
  this->mapFlagsG = 0;
  this->mapFlagsF = 0;
  *(undefined1 *)&this->originX8 = 0;
  this->cellCountTotal = -1;
  this->heightBlocks = (CHeightBlockArray *)0xffffffff;
  piVar2 = (int *)FUN_006ba810(0x19,uVar1);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x65666c65;
  *(undefined1 *)(piVar2 + 4) = 0;
  piVar2[2] = 4;
  *piVar2 = 1;
  local_20 = piVar2;
  iVar3 = FUN_00460f20(&local_20);
  this->mapArea8 = iVar3;
  local_8._0_1_ = 2;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  this->mapWidth = -1;
  this->mapFlagsB = 0;
  this->mapFlagsA = 0;
  this->mapFlags9 = 0;
  this->mapWidth8 = -1;
  this->mapHeight8 = -1;
  this->mapFlags2 = -1;
  this->mapFlags3 = -1;
  this->scanlineTotal = 0;
  this->mapFlagsG = 0;
  this->mapFlagsF = 0;
  *(undefined2 *)&this->ownerBlocks = 0;
  this->originX = 0;
  this->originY = 0;
  this->mapHeight = 0;
  *(undefined1 *)((int)&this->originX8 + 1) = 0;
  local_2c = (int *)FUN_006ba810(0x19,uVar1);
  local_2c[1] = 4;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[2] = 0;
  *local_2c = 1;
  local_8._0_1_ = 3;
  local_20 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x6e617473;
  piVar2[4] = 0x696e6164;
  *(undefined2 *)(piVar2 + 5) = 0x6d;
  piVar2[2] = 9;
  *piVar2 = 1;
  local_8._0_1_ = 4;
  local_1c = piVar2;
  local_28 = (int *)FUN_006ba810(0x19);
  local_28[1] = 4;
  *(undefined1 *)(local_28 + 3) = 0;
  local_28[2] = 0;
  *local_28 = 1;
  local_8._0_1_ = 5;
  local_18 = local_28;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 0x14;
  local_24[2] = -1;
  *local_24 = 0;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[3] = 0x6e617473;
  local_24[4] = 0x64726164;
  *(undefined1 *)(local_24 + 5) = 0;
  local_24[2] = 8;
  *local_24 = 1;
  local_8._0_1_ = 6;
  local_14 = local_24;
  FUN_004277f0(&local_14,&local_18,&local_1c,&local_20,0);
  local_8._0_1_ = 7;
  *local_24 = *local_24 + -1;
  if (*local_24 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 8;
  *local_28 = *local_28 + -1;
  if (*local_28 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 9;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 10;
  *local_2c = *local_2c + -1;
  if (*local_2c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 0x24;
  local_2c[2] = -1;
  *local_2c = 0;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[3] = 0x65696c66;
  local_2c[4] = 0x5f6e6567;
  local_2c[5] = 0x68636f68;
  local_2c[6] = 0x726f6e5f;
  local_2c[7] = 0x6e655f6d;
  *(undefined2 *)(local_2c + 8) = 100;
  local_2c[2] = 0x15;
  *local_2c = 1;
  local_8._0_1_ = 0xb;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x24;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x65696c66;
  piVar2[4] = 0x5f6e6567;
  piVar2[5] = 0x68636f68;
  piVar2[6] = 0x726f6e5f;
  piVar2[7] = 0x6f6c5f6d;
  *(undefined2 *)(piVar2 + 8) = 0x706f;
  *(undefined1 *)((int)piVar2 + 0x22) = 0;
  piVar2[2] = 0x16;
  *piVar2 = 1;
  local_8._0_1_ = 0xc;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 0x24;
  local_24[2] = -1;
  *local_24 = 0;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[3] = 0x65696c66;
  local_24[4] = 0x5f6e6567;
  local_24[5] = 0x68636f68;
  local_24[6] = 0x726f6e5f;
  local_24[7] = 0x74735f6d;
  local_24[8] = 0x747261;
  local_24[2] = 0x17;
  *local_24 = 1;
  local_8._0_1_ = 0xd;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x65766f6d;
  *(undefined2 *)(local_20 + 4) = 0x755f;
  *(undefined1 *)((int)local_20 + 0x12) = 0;
  local_20[2] = 6;
  *local_20 = 1;
  local_8._0_1_ = 0xe;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,0);
  local_8._0_1_ = 0xf;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x10;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x11;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x12;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 4;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[2] = 0;
  *local_2c = 1;
  local_8._0_1_ = 0x13;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x6e617473;
  piVar2[4] = 0x696e6164;
  *(undefined2 *)(piVar2 + 5) = 0x6d;
  piVar2[2] = 9;
  *piVar2 = 1;
  local_8._0_1_ = 0x14;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 4;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[2] = 0;
  *local_24 = 1;
  local_8._0_1_ = 0x15;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x65766f6d;
  *(undefined2 *)(local_20 + 4) = 0x645f;
  *(undefined1 *)((int)local_20 + 0x12) = 0;
  local_20[2] = 6;
  *local_20 = 1;
  local_8._0_1_ = 0x16;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,0);
  local_8._0_1_ = 0x17;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x18;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x19;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x1a;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x24;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x65696c66;
  piVar2[4] = 0x5f6e6567;
  piVar2[5] = 0x6b6e696c;
  piVar2[6] = 0x6f6e5f73;
  piVar2[7] = 0x655f6d72;
  *(undefined2 *)(piVar2 + 8) = 0x646e;
  *(undefined1 *)((int)piVar2 + 0x22) = 0;
  piVar2[2] = 0x16;
  *piVar2 = 1;
  local_8._0_1_ = 0x1b;
  local_2c = piVar2;
  local_28 = (int *)FUN_006ba810(0x19);
  local_28[1] = 0x24;
  local_28[2] = -1;
  *local_28 = 0;
  *(undefined1 *)(local_28 + 3) = 0;
  local_28[3] = 0x65696c66;
  local_28[4] = 0x5f6e6567;
  local_28[5] = 0x6b6e696c;
  local_28[6] = 0x6f6e5f73;
  local_28[7] = 0x6c5f6d72;
  local_28[8] = 0x706f6f;
  local_28[2] = 0x17;
  *local_28 = 1;
  local_8._0_1_ = 0x1c;
  local_14 = local_28;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 0x24;
  local_24[2] = -1;
  *local_24 = 0;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[3] = 0x65696c66;
  local_24[4] = 0x5f6e6567;
  local_24[5] = 0x6b6e696c;
  local_24[6] = 0x6f6e5f73;
  local_24[7] = 0x735f6d72;
  local_24[8] = 0x74726174;
  *(undefined1 *)(local_24 + 9) = 0;
  local_24[2] = 0x18;
  *local_24 = 1;
  local_8._0_1_ = 0x1d;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x65766f6d;
  *(undefined2 *)(local_20 + 4) = 0x6c5f;
  *(undefined1 *)((int)local_20 + 0x12) = 0;
  local_20[2] = 6;
  *local_20 = 1;
  local_8._0_1_ = 0x1e;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,0);
  local_8._0_1_ = 0x1f;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x20;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x21;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x22;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 0x24;
  local_2c[2] = -1;
  *local_2c = 0;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[3] = 0x65696c66;
  local_2c[4] = 0x5f6e6567;
  local_2c[5] = 0x68636572;
  local_2c[6] = 0x6e5f7374;
  local_2c[7] = 0x5f6d726f;
  local_2c[8] = 0x646e65;
  local_2c[2] = 0x17;
  *local_2c = 1;
  local_8._0_1_ = 0x23;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x24;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x65696c66;
  piVar2[4] = 0x5f6e6567;
  piVar2[5] = 0x68636572;
  piVar2[6] = 0x6e5f7374;
  piVar2[7] = 0x5f6d726f;
  piVar2[8] = 0x706f6f6c;
  *(undefined1 *)(piVar2 + 9) = 0;
  piVar2[2] = 0x18;
  *piVar2 = 1;
  local_8._0_1_ = 0x24;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 0x24;
  local_24[2] = -1;
  *local_24 = 0;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[3] = 0x65696c66;
  local_24[4] = 0x5f6e6567;
  local_24[5] = 0x68636572;
  local_24[6] = 0x6e5f7374;
  local_24[7] = 0x5f6d726f;
  local_24[8] = 0x72617473;
  *(undefined2 *)(local_24 + 9) = 0x74;
  local_24[2] = 0x19;
  *local_24 = 1;
  local_8._0_1_ = 0x25;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x65766f6d;
  *(undefined2 *)(local_20 + 4) = 0x725f;
  *(undefined1 *)((int)local_20 + 0x12) = 0;
  local_20[2] = 6;
  *local_20 = 1;
  local_8._0_1_ = 0x26;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,0);
  local_8._0_1_ = 0x27;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x28;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x29;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x2a;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 0x24;
  local_2c[2] = -1;
  *local_2c = 0;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[3] = 0x65696c66;
  local_2c[4] = 0x5f6e6567;
  local_2c[5] = 0x68636f68;
  local_2c[6] = 0x6863735f;
  local_2c[7] = 0x6c6c656e;
  local_2c[8] = 0x646e655f;
  *(undefined1 *)(local_2c + 9) = 0;
  local_2c[2] = 0x18;
  *local_2c = 1;
  local_8._0_1_ = 0x2b;
  local_14 = local_2c;
  local_28 = (int *)FUN_006ba810(0x19);
  local_28[1] = 0x24;
  local_28[2] = -1;
  *local_28 = 0;
  *(undefined1 *)(local_28 + 3) = 0;
  local_28[3] = 0x65696c66;
  local_28[4] = 0x5f6e6567;
  local_28[5] = 0x68636f68;
  local_28[6] = 0x6863735f;
  local_28[7] = 0x6c6c656e;
  local_28[8] = 0x6f6f6c5f;
  *(undefined2 *)(local_28 + 9) = 0x70;
  local_28[2] = 0x19;
  *local_28 = 1;
  local_8._0_1_ = 0x2c;
  local_18 = local_28;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x24;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x65696c66;
  piVar2[4] = 0x5f6e6567;
  piVar2[5] = 0x68636f68;
  piVar2[6] = 0x6863735f;
  piVar2[7] = 0x6c6c656e;
  piVar2[8] = 0x6174735f;
  *(undefined2 *)(piVar2 + 9) = 0x7472;
  *(undefined1 *)((int)piVar2 + 0x26) = 0;
  piVar2[2] = 0x1a;
  *piVar2 = 1;
  local_8._0_1_ = 0x2d;
  local_24 = piVar2;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[3] = 0x65766f6d;
  local_20[4] = 0x66755f;
  local_20[2] = 7;
  *local_20 = 1;
  local_8._0_1_ = 0x2e;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,0);
  local_8._0_1_ = 0x2f;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x30;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x31;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x32;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x686d7572;
  piVar2[4] = 0x676e6561;
  piVar2[5] = 0x655f6e65;
  *(undefined2 *)(piVar2 + 6) = 0x646e;
  *(undefined1 *)((int)piVar2 + 0x1a) = 0;
  piVar2[2] = 0xe;
  *piVar2 = 1;
  local_8._0_1_ = 0x33;
  local_2c = piVar2;
  local_28 = (int *)FUN_006ba810(0x19);
  local_28[1] = 0x14;
  local_28[2] = -1;
  *local_28 = 0;
  *(undefined1 *)(local_28 + 3) = 0;
  local_28[3] = 0x686d7572;
  local_28[4] = 0x676e6561;
  local_28[5] = 0x6c5f6e65;
  local_28[6] = 0x706f6f;
  local_28[2] = 0xf;
  *local_28 = 1;
  local_8._0_1_ = 0x34;
  local_14 = local_28;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 0x14;
  local_24[2] = -1;
  *local_24 = 0;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[3] = 0x686d7572;
  local_24[4] = 0x676e6561;
  local_24[5] = 0x735f6e65;
  local_24[6] = 0x74726174;
  *(undefined1 *)(local_24 + 7) = 0;
  local_24[2] = 0x10;
  *local_24 = 1;
  local_8._0_1_ = 0x35;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x656c6469;
  *(undefined1 *)(local_20 + 4) = 0;
  local_20[2] = 4;
  *local_20 = 1;
  local_8._0_1_ = 0x36;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,0);
  local_8._0_1_ = 0x37;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x38;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x39;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x3a;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 0x14;
  local_2c[2] = -1;
  *local_2c = 0;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[3] = 0x6c686373;
  local_2c[4] = 0x6e656661;
  local_2c[5] = 0x646e655f;
  *(undefined1 *)(local_2c + 6) = 0;
  local_2c[2] = 0xc;
  *local_2c = 1;
  local_8._0_1_ = 0x3b;
  local_14 = local_2c;
  local_28 = (int *)FUN_006ba810(0x19);
  local_28[1] = 0x14;
  local_28[2] = -1;
  *local_28 = 0;
  *(undefined1 *)(local_28 + 3) = 0;
  local_28[3] = 0x6c686373;
  local_28[4] = 0x6e656661;
  local_28[5] = 0x6f6f6c5f;
  *(undefined2 *)(local_28 + 6) = 0x70;
  local_28[2] = 0xd;
  *local_28 = 1;
  local_8._0_1_ = 0x3c;
  local_18 = local_28;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x6c686373;
  piVar2[4] = 0x6e656661;
  piVar2[5] = 0x6174735f;
  *(undefined2 *)(piVar2 + 6) = 0x7472;
  *(undefined1 *)((int)piVar2 + 0x1a) = 0;
  piVar2[2] = 0xe;
  *piVar2 = 1;
  local_8._0_1_ = 0x3d;
  local_24 = piVar2;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x65656c73;
  *(undefined2 *)(local_20 + 4) = 0x70;
  local_20[2] = 5;
  *local_20 = 1;
  local_8._0_1_ = 0x3e;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,0);
  local_8._0_1_ = 0x3f;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x40;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x41;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x42;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 4;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[2] = 0;
  *local_2c = 1;
  local_8._0_1_ = 0x43;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x656c6261;
  piVar2[4] = 0x6e656e68;
  *(undefined1 *)(piVar2 + 5) = 0;
  piVar2[2] = 8;
  *piVar2 = 1;
  local_8._0_1_ = 0x44;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 4;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[2] = 0;
  *local_24 = 1;
  local_8._0_1_ = 0x45;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x656c6261;
  local_20[4] = 0x6e656e68;
  *(undefined1 *)(local_20 + 5) = 0;
  local_20[2] = 8;
  *local_20 = 1;
  local_8._0_1_ = 0x46;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,1);
  local_8._0_1_ = 0x47;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x48;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x49;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x4a;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 4;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[2] = 0;
  *local_2c = 1;
  local_8._0_1_ = 0x4b;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x65666e61;
  piVar2[4] = 0x6e726575;
  *(undefined1 *)(piVar2 + 5) = 0;
  piVar2[2] = 8;
  *piVar2 = 1;
  local_8._0_1_ = 0x4c;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 4;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[2] = 0;
  *local_24 = 1;
  local_8._0_1_ = 0x4d;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x65666e61;
  local_20[4] = 0x6e726575;
  *(undefined1 *)(local_20 + 5) = 0;
  local_20[2] = 8;
  *local_20 = 1;
  local_8._0_1_ = 0x4e;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,1);
  local_8._0_1_ = 0x4f;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x50;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x51;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x52;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 4;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[2] = 0;
  *local_2c = 1;
  local_8._0_1_ = 0x53;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x66667561;
  piVar2[4] = 0x6564726f;
  *(undefined2 *)(piVar2 + 5) = 0x6e72;
  *(undefined1 *)((int)piVar2 + 0x16) = 0;
  piVar2[2] = 10;
  *piVar2 = 1;
  local_8._0_1_ = 0x54;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 4;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[2] = 0;
  *local_24 = 1;
  local_8._0_1_ = 0x55;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x66667561;
  local_20[4] = 0x6564726f;
  *(undefined2 *)(local_20 + 5) = 0x6e72;
  *(undefined1 *)((int)local_20 + 0x16) = 0;
  local_20[2] = 10;
  *local_20 = 1;
  local_8._0_1_ = 0x56;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,1);
  local_8._0_1_ = 0x57;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x58;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x59;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x5a;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 4;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[2] = 0;
  *local_2c = 1;
  local_8._0_1_ = 0x5b;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x656c6562;
  piVar2[4] = 0x67696469;
  *(undefined2 *)(piVar2 + 5) = 0x6e65;
  *(undefined1 *)((int)piVar2 + 0x16) = 0;
  piVar2[2] = 10;
  *piVar2 = 1;
  local_8._0_1_ = 0x5c;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 4;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[2] = 0;
  *local_24 = 1;
  local_8._0_1_ = 0x5d;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x656c6562;
  local_20[4] = 0x67696469;
  *(undefined2 *)(local_20 + 5) = 0x6e65;
  *(undefined1 *)((int)local_20 + 0x16) = 0;
  local_20[2] = 10;
  *local_20 = 1;
  local_8._0_1_ = 0x5e;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,1);
  local_8._0_1_ = 0x5f;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x60;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x61;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x62;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 4;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[2] = 0;
  *local_2c = 1;
  local_8._0_1_ = 99;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x68657264;
  piVar2[4] = 0x6c5f6e65;
  piVar2[5] = 0x736b6e69;
  piVar2[6] = 0x6730395f;
  piVar2[7] = 0x646172;
  piVar2[2] = 0x13;
  *piVar2 = 1;
  local_8._0_1_ = 100;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 4;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[2] = 0;
  *local_24 = 1;
  local_8._0_1_ = 0x65;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x68657264;
  local_20[4] = 0x6c5f6e65;
  local_20[5] = 0x736b6e69;
  local_20[6] = 0x6730395f;
  local_20[7] = 0x646172;
  local_20[2] = 0x13;
  *local_20 = 1;
  local_8._0_1_ = 0x66;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,1);
  local_8._0_1_ = 0x67;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x68;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x69;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x6a;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 4;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[2] = 0;
  *local_2c = 1;
  local_8._0_1_ = 0x6b;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x24;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x68657264;
  piVar2[4] = 0x725f6e65;
  piVar2[5] = 0x74686365;
  piVar2[6] = 0x30395f73;
  piVar2[7] = 0x64617267;
  *(undefined1 *)(piVar2 + 8) = 0;
  piVar2[2] = 0x14;
  *piVar2 = 1;
  local_8._0_1_ = 0x6c;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 4;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[2] = 0;
  *local_24 = 1;
  local_8._0_1_ = 0x6d;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x24;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x68657264;
  local_20[4] = 0x725f6e65;
  local_20[5] = 0x74686365;
  local_20[6] = 0x30395f73;
  local_20[7] = 0x64617267;
  *(undefined1 *)(local_20 + 8) = 0;
  local_20[2] = 0x14;
  *local_20 = 1;
  local_8._0_1_ = 0x6e;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,1);
  local_8._0_1_ = 0x6f;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x70;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x71;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x72;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 4;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[2] = 0;
  *local_2c = 1;
  local_8._0_1_ = 0x73;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x6b637567;
  piVar2[4] = 0x6c5f6e65;
  piVar2[5] = 0x736b6e69;
  *(undefined1 *)(piVar2 + 6) = 0;
  piVar2[2] = 0xc;
  *piVar2 = 1;
  local_8._0_1_ = 0x74;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 4;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[2] = 0;
  *local_24 = 1;
  local_8._0_1_ = 0x75;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x6b637567;
  local_20[4] = 0x6c5f6e65;
  local_20[5] = 0x736b6e69;
  *(undefined1 *)(local_20 + 6) = 0;
  local_20[2] = 0xc;
  *local_20 = 1;
  local_8._0_1_ = 0x76;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,1);
  local_8._0_1_ = 0x77;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x78;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x79;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x7a;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 4;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[2] = 0;
  *local_2c = 1;
  local_8._0_1_ = 0x7b;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[2] = -1;
  *piVar2 = 0;
  *(undefined1 *)(piVar2 + 3) = 0;
  piVar2[3] = 0x6b637567;
  piVar2[4] = 0x725f6e65;
  piVar2[5] = 0x74686365;
  *(undefined2 *)(piVar2 + 6) = 0x73;
  piVar2[2] = 0xd;
  *piVar2 = 1;
  local_8._0_1_ = 0x7c;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 4;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[2] = 0;
  *local_24 = 1;
  local_8._0_1_ = 0x7d;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[2] = -1;
  *local_20 = 0;
  *(undefined1 *)(local_20 + 3) = 0;
  local_20[3] = 0x6b637567;
  local_20[4] = 0x725f6e65;
  local_20[5] = 0x74686365;
  *(undefined2 *)(local_20 + 6) = 0x73;
  local_20[2] = 0xd;
  *local_20 = 1;
  local_8._0_1_ = 0x7e;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,1);
  local_8._0_1_ = 0x7f;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x80;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x81;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x82;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  local_2c = (int *)FUN_006ba810(0x19);
  local_2c[1] = 4;
  *(undefined1 *)(local_2c + 3) = 0;
  local_2c[2] = 0;
  *local_2c = 1;
  local_8._0_1_ = 0x83;
  local_14 = local_2c;
  piVar2 = (int *)FUN_006ba810(0x19);
  piVar2[1] = 0x14;
  piVar2[3] = 0x6863696b;
  piVar2[4] = 0x6e7265;
  piVar2[2] = 7;
  *piVar2 = 1;
  local_8._0_1_ = 0x84;
  local_28 = piVar2;
  local_24 = (int *)FUN_006ba810(0x19);
  local_24[1] = 4;
  *(undefined1 *)(local_24 + 3) = 0;
  local_24[2] = 0;
  *local_24 = 1;
  local_8._0_1_ = 0x85;
  local_18 = local_24;
  local_20 = (int *)FUN_006ba810(0x19);
  local_20[1] = 0x14;
  local_20[3] = 0x6863696b;
  local_20[4] = 0x6e7265;
  local_20[2] = 7;
  *local_20 = 1;
  local_8._0_1_ = 0x86;
  local_1c = local_20;
  FUN_004277f0(&local_20,&local_24,&local_28,&local_2c,1);
  local_8._0_1_ = 0x87;
  *local_1c = *local_1c + -1;
  if (*local_1c == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x88;
  *local_18 = *local_18 + -1;
  if (*local_18 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x89;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x8a;
  *local_14 = *local_14 + -1;
  if (*local_14 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0x8b;
  FUN_006b8fb0("koketieren");
  local_8._0_1_ = 0x8c;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0x8d;
  FUN_006b8fb0("koketieren");
  local_8._0_1_ = 0x8e;
  FUN_004277f0(&local_14,&local_18,&local_1c,&local_20,1);
  local_8._0_1_ = 0x8f;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x90;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x91;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x92;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0x93;
  FUN_006b8fb0("pirouette");
  local_8._0_1_ = 0x94;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0x95;
  FUN_006b8fb0("pirouette");
  local_8._0_1_ = 0x96;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0x97;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x98;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x99;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x9a;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0x9b;
  FUN_006b8fb0("radschlagen");
  local_8._0_1_ = 0x9c;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0x9d;
  FUN_006b8fb0("radschlagen");
  local_8._0_1_ = 0x9e;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0x9f;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xa0;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xa1;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xa2;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xa3;
  FUN_006b8fb0("salto");
  local_8._0_1_ = 0xa4;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xa5;
  FUN_006b8fb0("salto");
  local_8._0_1_ = 0xa6;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0xa7;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xa8;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xa9;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xaa;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xab;
  FUN_006b8fb0("schmollen");
  local_8._0_1_ = 0xac;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xad;
  FUN_006b8fb0("schmollen");
  local_8._0_1_ = 0xae;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0xaf;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xb0;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xb1;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xb2;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xb3;
  FUN_006b8fb0("verzweifeln");
  local_8._0_1_ = 0xb4;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xb5;
  FUN_006b8fb0("verzweifeln");
  local_8._0_1_ = 0xb6;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0xb7;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xb8;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xb9;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xba;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xbb;
  FUN_006b8fb0("warnen");
  local_8._0_1_ = 0xbc;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xbd;
  FUN_006b8fb0("warnen");
  local_8._0_1_ = 0xbe;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0xbf;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xc0;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xc1;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xc2;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xc3;
  FUN_006b8fb0("zustimmen");
  local_8._0_1_ = 0xc4;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xc5;
  FUN_006b8fb0("zustimmen");
  local_8._0_1_ = 0xc6;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 199;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 200;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xc9;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xca;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xcb;
  FUN_006b8fb0("abstuerzen_fall");
  local_8._0_1_ = 0xcc;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xcd;
  FUN_006b8fb0("abstuerzen_fall");
  local_8._0_1_ = 0xce;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0xcf;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xd0;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xd1;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xd2;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xd3;
  FUN_006b8fb0("standanim");
  local_8._0_1_ = 0xd4;
  FUN_006b8fb0("abstuerzen_aufprall");
  local_8._0_1_ = 0xd5;
  FUN_006b8fb0("abstuerzen_aufprall");
  local_8._0_1_ = 0xd6;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0xd7;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xd8;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xd9;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xda;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xdb;
  FUN_006b8fb0("zeigen_rechts");
  local_8._0_1_ = 0xdc;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xdd;
  FUN_006b8fb0("zeigen_rechts");
  local_8._0_1_ = 0xde;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0xdf;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xe0;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xe1;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xe2;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xe3;
  FUN_006b8fb0("zeigen_links");
  local_8._0_1_ = 0xe4;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xe5;
  FUN_006b8fb0("zeigen_links");
  local_8._0_1_ = 0xe6;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0xe7;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xe8;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xe9;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xea;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xeb;
  FUN_006b8fb0("reden_a");
  local_8._0_1_ = 0xec;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xed;
  FUN_006b8fb0("reden_a");
  local_8._0_1_ = 0xee;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0xef;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xf0;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xf1;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xf2;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xf3;
  FUN_006b8fb0("reden_b");
  local_8._0_1_ = 0xf4;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xf5;
  FUN_006b8fb0("reden_b");
  local_8._0_1_ = 0xf6;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0xf7;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xf8;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xf9;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0xfa;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xfb;
  FUN_006b8fb0("kopf_schuetteln");
  local_8._0_1_ = 0xfc;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xfd;
  FUN_006b8fb0("kopf_schuetteln");
  local_8._0_1_ = 0xfe;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8 = CONCAT31(local_8._1_3_,0xff);
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0x100;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8 = 0x101;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0x102;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8 = 0x103;
  FUN_006b8fb0("kusshand");
  local_8._0_1_ = 4;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 5;
  FUN_006b8fb0("kusshand");
  local_8._0_1_ = 6;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 7;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 8;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,9);
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0x10a;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = 1;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8 = 0x10b;
  FUN_006b8fb0("meckern");
  local_8._0_1_ = 0xc;
  FUN_006b8fb0(&PTR_0071ce50);
  local_8._0_1_ = 0xd;
  FUN_006b8fb0("meckern");
  local_8._0_1_ = 0xe;
  FUN_004277f0(&local_20,&local_1c,&local_18,&local_14,1);
  local_8._0_1_ = 0xf;
  if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x10;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0x11);
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8 = 0x112;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  local_8 = 1;
  FUN_00428630();
  ExceptionList = local_10;
  return this;
}

