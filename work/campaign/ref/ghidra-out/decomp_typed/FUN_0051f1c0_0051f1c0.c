
void FUN_0051f1c0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int this;
  int extraout_ECX;
  uint uVar4;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  piVar1 = (int *)FUN_006ba810(0x19);
  piVar1[1] = 0x14;
  piVar1[2] = -1;
  *piVar1 = 0;
  *(undefined1 *)(piVar1 + 3) = 0;
  piVar1[3] = 0x66726570;
  piVar1[4] = 0x616d726f;
  piVar1[5] = 0x65636e;
  piVar1[2] = 0xb;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  FUN_0050e8e0();
  piVar1 = (int *)FUN_006ba810(0x19);
  piVar1[1] = 4;
  piVar1[2] = -1;
  *piVar1 = 0;
  *(undefined1 *)(piVar1 + 3) = 0;
  *(undefined2 *)(piVar1 + 3) = 0x4657;
  *(undefined1 *)((int)piVar1 + 0xe) = 0;
  piVar1[2] = 2;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_18 = 0x14;
  local_14 = 0x14;
  local_10 = 5;
  local_c = 0x19;
  uVar2 = FUN_00526f80(&local_18);
  this->i_60 = uVar2;
  piVar1 = (int *)FUN_006ba810(0x19);
  piVar1[1] = 4;
  piVar1[2] = -1;
  *piVar1 = 0;
  *(undefined1 *)(piVar1 + 3) = 0;
  *(undefined2 *)(piVar1 + 3) = 0x544d;
  *(undefined1 *)((int)piVar1 + 0xe) = 0;
  piVar1[2] = 2;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_10 = 0x14;
  local_c = 0x14;
  local_18 = 0x19;
  local_14 = 0x19;
  uVar2 = FUN_00526f80(&local_10);
  this->i_64 = uVar2;
  piVar1 = (int *)FUN_006ba810(0x19);
  piVar1[1] = 4;
  piVar1[2] = -1;
  *piVar1 = 0;
  *(undefined1 *)(piVar1 + 3) = 0;
  *(undefined2 *)(piVar1 + 3) = 0x4941;
  *(undefined1 *)((int)piVar1 + 0xe) = 0;
  piVar1[2] = 2;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_10 = 0x14;
  local_c = 0x14;
  local_18 = 0x2d;
  local_14 = 0x19;
  uVar2 = FUN_00526f80(&local_10);
  this->i_68 = uVar2;
  piVar1 = (int *)FUN_006ba810(0x19);
  piVar1[1] = 4;
  piVar1[2] = -1;
  *piVar1 = 0;
  *(undefined1 *)(piVar1 + 3) = 0;
  *(undefined2 *)(piVar1 + 3) = 0x4d42;
  *(undefined1 *)((int)piVar1 + 0xe) = 0;
  piVar1[2] = 2;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_10 = 0x14;
  local_c = 0x14;
  local_18 = 0x41;
  local_14 = 0x19;
  uVar2 = FUN_00526f80(&local_10);
  this->i_6c = uVar2;
  piVar1 = (int *)FUN_006ba810(0x19);
  piVar1[1] = 4;
  piVar1[2] = -1;
  *piVar1 = 0;
  *(undefined1 *)(piVar1 + 3) = 0;
  *(undefined2 *)(piVar1 + 3) = 0x474c;
  *(undefined1 *)((int)piVar1 + 0xe) = 0;
  piVar1[2] = 2;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_10 = 0x14;
  local_c = 0x14;
  local_18 = 0x55;
  local_14 = 0x19;
  uVar2 = FUN_00526f80(&local_10);
  this->i_70 = uVar2;
  piVar1 = (int *)FUN_006ba810(0x19);
  piVar1[1] = 4;
  piVar1[2] = -1;
  *piVar1 = 0;
  *(undefined2 *)(piVar1 + 3) = 0x54;
  piVar1[2] = 1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_10 = 0x14;
  local_c = 0x14;
  local_18 = 0x69;
  local_14 = 0x19;
  uVar2 = FUN_00526f80(&local_10);
  iVar3 = this->i_60;
  this->i_74 = uVar2;
  uVar4 = *(uint *)(iVar3 + 0x24) | 2;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  iVar3 = this->i_64;
  uVar4 = *(uint *)(iVar3 + 0x24) | 2;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  iVar3 = this->i_68;
  uVar4 = *(uint *)(iVar3 + 0x24) | 2;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  iVar3 = this->i_6c;
  uVar4 = *(uint *)(iVar3 + 0x24) | 2;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  iVar3 = this->i_70;
  uVar4 = *(uint *)(iVar3 + 0x24) | 2;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  iVar3 = this->i_74;
  uVar4 = *(uint *)(iVar3 + 0x24) | 2;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  local_10 = 0x82;
  local_c = 0x14;
  local_18 = 10;
  local_14 = 0x2d;
  iVar3 = FUN_0054cd20(&local_10,"objcnt: 1234");
  this->i_44 = iVar3;
  uVar4 = *(uint *)(iVar3 + 0x24) | 0x10;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  local_10 = 0x82;
  local_c = 0x14;
  local_18 = 10;
  local_14 = 0x3c;
  iVar3 = FUN_0054cd20(&local_10,"polycnt: S:4321 O:5678 A: 9999");
  this->i_48 = iVar3;
  uVar4 = *(uint *)(iVar3 + 0x24) | 0x10;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  local_10 = 0x82;
  local_c = 0x14;
  local_18 = 10;
  local_14 = 0x4b;
  iVar3 = FUN_0054cd20(&local_10,"fps: 75.000");
  this->i_4c = iVar3;
  uVar4 = *(uint *)(iVar3 + 0x24) | 0x10;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  local_10 = 0x82;
  local_c = 0x14;
  local_18 = 10;
  local_14 = 0x5a;
  iVar3 = FUN_0054cd20(&local_10,"rjcnt: 75.0");
  this->i_50 = iVar3;
  uVar4 = *(uint *)(iVar3 + 0x24) | 0x10;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  local_10 = 0x82;
  local_c = 0x14;
  local_18 = 10;
  local_14 = 0x69;
  iVar3 = FUN_0054cd20(&local_10,"objfactor:");
  this->i_54 = iVar3;
  uVar4 = *(uint *)(iVar3 + 0x24) | 0x10;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  local_10 = 0x82;
  local_c = 0x14;
  local_18 = 10;
  local_14 = 0x78;
  iVar3 = FUN_0054cd20(&local_10,&DAT_00727044);
  this->i_58 = iVar3;
  uVar4 = *(uint *)(iVar3 + 0x24) | 0x10;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  local_10 = 0x82;
  local_c = 0x14;
  local_18 = 10;
  local_14 = 0x87;
  iVar3 = FUN_0054cd20(&local_10,"psrc:");
  this->i_5c = iVar3;
  uVar4 = *(uint *)(iVar3 + 0x24) | 0x10;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
    iVar3 = extraout_ECX;
  }
  if (*(char *)(DAT_00772400 + 0x590) != '\0') {
    piVar1 = (int *)FUN_006ba810(0x19,iVar3);
    piVar1[1] = 4;
    piVar1[2] = -1;
    *piVar1 = 0;
    *(undefined2 *)(piVar1 + 3) = 0x46;
    piVar1[2] = 1;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_10 = 0x14;
    local_c = 0x14;
    local_18 = 0x8c;
    local_14 = 0x69;
    iVar3 = FUN_00526f80(&local_10);
    this->i_78 = iVar3;
    uVar4 = *(uint *)(iVar3 + 0x24) | 2;
    if (uVar4 != *(uint *)(iVar3 + 0x24)) {
      *(uint *)(iVar3 + 0x24) = uVar4;
      FUN_00504ee0();
    }
  }
  this->c_80 = 0;
  local_18 = 0xfff00a0a;
  *(undefined4 *)(this->i_54 + 0x48) = 0xfff00a0a;
  FUN_00505ed0();
  return;
}

