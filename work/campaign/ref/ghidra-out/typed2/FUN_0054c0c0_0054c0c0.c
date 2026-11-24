
void __thiscall FUN_0054c0c0(ViWinTechTree *this)

{
  undefined1 *puVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int **ppiVar6;
  uint uVar7;
  int **local_3c;
  uint uStack_38;
  int *local_28;
  undefined4 local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070437b;
  local_10 = ExceptionList;
  uStack_38 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_3c = (int **)0x19;
  piVar4 = (int *)FUN_006ba810();
  piVar4[1] = 0x14;
  piVar4[2] = -1;
  *piVar4 = 0;
  *(undefined1 *)(piVar4 + 3) = 0;
  piVar4[3] = 0x68636554;
  piVar4[4] = 0x65657274;
  *(undefined1 *)(piVar4 + 5) = 0;
  piVar4[2] = 8;
  *piVar4 = 1;
  local_3c = &local_14;
  local_8 = 0;
  puVar1 = &this->field_0x20;
  local_14 = piVar4;
  cVar3 = FUN_006b97f0();
  if (cVar3 == '\0') {
    piVar2 = *(int **)puVar1;
    *(int **)puVar1 = piVar4;
    *piVar4 = *piVar4 + 1;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
      local_3c = (int **)0x54c16a;
      FUN_006ba940();
    }
    *(int *)(*(int *)puVar1 + 8) = piVar4[2];
    local_3c = (int **)0x54c179;
    FUN_00504ee0();
  }
  local_8 = 1;
  *piVar4 = *piVar4 + -1;
  if (*piVar4 == 0) {
    local_3c = (int **)0x54c18c;
    FUN_006ba940();
  }
  local_8 = 0xffffffff;
  local_3c = (int **)FUN_006ba810(0x19);
  local_3c[1] = (int *)0x14;
  local_3c[2] = (int *)0xffffffff;
  *local_3c = (int *)0x0;
  *(undefined1 *)(local_3c + 3) = 0;
  local_3c[3] = (int *)0x68636554;
  local_3c[4] = (int *)0x65727420;
  *(undefined2 *)(local_3c + 5) = 0x65;
  local_3c[2] = (int *)0x9;
  if (local_3c != (int **)0x0) {
    *local_3c = (int *)((int)*local_3c + 1);
  }
  iVar5 = FUN_0050e8e0();
  this->i_58 = iVar5;
  uVar7 = *(uint *)(iVar5 + 0x24) | 1;
  if (uVar7 != *(uint *)(iVar5 + 0x24)) {
    *(uint *)(iVar5 + 0x24) = uVar7;
    local_3c = (int **)0x54c212;
    FUN_00504ee0();
    iVar5 = this->i_58;
  }
  uVar7 = *(uint *)(iVar5 + 0x24) | 2;
  if (uVar7 != *(uint *)(iVar5 + 0x24)) {
    *(uint *)(iVar5 + 0x24) = uVar7;
    local_3c = (int **)0x54c228;
    FUN_00504ee0();
  }
  local_18 = (int *)((this->i_14 - this->i_0c) + 0x3c);
  local_14 = (int *)0x12;
  local_3c = &local_18;
  FUN_00504ba0();
  local_3c = &local_18;
  local_18 = (int *)0xffffffe2;
  local_14 = (int *)0xffffffe4;
  FUN_00504a70();
  local_3c = (int **)0x12a;
  piVar4 = (int *)FUN_006ba810();
  local_8 = 2;
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    local_3c = (int **)0x54c28f;
    local_14 = piVar4;
    FUN_005044d0();
    *piVar4 = (int)ViWinTechTree::VIWinTTBackground::vftable;
    piVar4[0x11] = 0;
  }
  local_8 = 0xffffffff;
  local_3c = &local_18;
  piVar4[0x11] = (int)this;
  local_18 = (int *)0x3e8;
  local_14 = (int *)0x3e8;
  FUN_00504ba0();
  local_3c = &local_18;
  *(int **)&this->field_0x4c = piVar4;
  local_18 = (int *)0x5;
  local_14 = (int *)0x5;
  FUN_00504a70();
  local_14 = (int *)&local_3c;
  local_3c = (int **)FUN_006ba810(0x19);
  local_3c[1] = (int *)0x14;
  local_3c[2] = (int *)0xffffffff;
  *local_3c = (int *)0x0;
  *(undefined1 *)(local_3c + 3) = 0;
  local_3c[3] = (int *)0x65756546;
  local_3c[4] = (int *)0x65747372;
  local_3c[5] = (int *)0x656c6c;
  local_3c[2] = (int *)0xb;
  if (local_3c != (int **)0x0) {
    *local_3c = (int *)((int)*local_3c + 1);
  }
  local_8 = 3;
  if (DAT_0076a280 == (undefined4 *)0x0) {
    DAT_0076a280 = (undefined4 *)FUN_006ba810(0x76);
    if (DAT_0076a280 == (undefined4 *)0x0) {
      DAT_0076a280 = (undefined4 *)0x0;
    }
    else {
      *DAT_0076a280 = 0;
      DAT_0076a280[1] = 0;
    }
  }
  local_8 = 0xffffffff;
  iVar5 = FUN_0043e410();
  if (iVar5 != 0) {
    local_3c = (int **)0x0;
    iVar5 = FUN_0054bca0(0,iVar5);
    this->i_48 = iVar5;
    local_3c = (int **)0x54c39e;
    FUN_0054bc50();
  }
  local_3c = &local_28;
  FUN_0054b240();
  local_3c = &local_28;
  FUN_00504ba0();
  local_1c = (this->i_18 - this->i_10) + -0x46;
  piVar4 = *(int **)&this->field_0x4c;
  local_20 = (int *)((this->i_14 - this->i_0c) + -10);
  local_3c = (int **)0x2b;
  local_28 = (int *)0x5;
  local_24 = 0x32;
  local_14 = (int *)FUN_006ba810();
  local_8 = 4;
  if (local_14 == (int *)0x0) {
    ppiVar6 = (int **)0x0;
  }
  else {
    local_3c = (int **)0x54c408;
    ppiVar6 = (int **)FUN_00533b10();
  }
  local_3c = &local_20;
  local_8 = 0xffffffff;
  FUN_00504ba0();
  local_3c = &local_28;
  FUN_00504a70();
  ppiVar6[0x14] = piVar4;
  local_3c = ppiVar6;
  FUN_00504ce0();
  this->i_50 = (int)ppiVar6;
  ExceptionList = local_10;
  return;
}

