
void FUN_0050f630(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int this;
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
  piVar1[3] = 0x646e6946;
  *(undefined2 *)(piVar1 + 4) = 0x7265;
  *(undefined1 *)((int)piVar1 + 0x12) = 0;
  piVar1[2] = 6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  FUN_0050e8e0();
  local_18 = 0xe1;
  local_14 = 0x88;
  local_10 = 10;
  local_c = 0x1e;
  uVar2 = FUN_00517d80(&local_18);
  this->i_44 = uVar2;
  piVar1 = (int *)FUN_006ba810(0x19);
  piVar1[1] = 4;
  piVar1[2] = -1;
  *piVar1 = 0;
  *(undefined2 *)(piVar1 + 3) = 0x43;
  piVar1[2] = 1;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_10 = 0x15;
  local_c = 0x15;
  local_18 = 0xbd;
  local_14 = 0xae;
  iVar3 = FUN_00526f80(&local_10);
  this->i_48 = iVar3;
  uVar4 = *(uint *)(iVar3 + 0x24) | 2;
  if (uVar4 != *(uint *)(iVar3 + 0x24)) {
    *(uint *)(iVar3 + 0x24) = uVar4;
    FUN_00504ee0();
  }
  FUN_0050f2d0();
  return;
}

