
void __thiscall FUN_0050ea70(ViWinDragBar *this)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int in_stack_00000004;
  int *piVar5;
  undefined4 *in_stack_ffffffc8;
  undefined4 in_stack_ffffffcc;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  uVar4 = this->i_24;
  if ((uVar4 & 1) == 0) {
    local_24 = *(undefined4 *)(*(int *)(in_stack_00000004 + 4) + 4);
    if (this->c_44 == '\0') {
      puVar1 = (undefined4 *)FUN_004fe390(&local_20,0x28);
      local_24 = *puVar1;
    }
    uVar2 = FUN_004fe390(&local_20,0x28);
    local_18 = *(int *)(in_stack_00000004 + 8);
    local_10 = (this->i_14 - this->i_0c) + local_18;
    local_14 = *(int *)(in_stack_00000004 + 0xc);
    local_c = (this->i_18 - this->i_10) + local_14;
    FUN_004ff430(&local_18,uVar2);
    local_10 = this->i_14 - this->i_0c;
    local_c = this->i_18 - this->i_10;
    in_stack_ffffffc8 = &local_24;
    in_stack_ffffffcc = 1;
    local_18 = 0;
    local_14 = 0;
    FUN_004fdd70(&local_18,in_stack_ffffffc8,1);
    uVar4 = this->i_24;
  }
  iVar3 = 10;
  if ((uVar4 & 2) != 0) {
    iVar3 = this->i_20 + 0xc;
    piVar5 = &local_20;
    FUN_004efa10(piVar5,iVar3);
    FUN_004edf70(piVar5,iVar3,in_stack_ffffffc8,in_stack_ffffffcc);
    iVar3 = ((this->i_14 - local_20) - this->i_0c) / 2;
  }
  local_20 = *(int *)(in_stack_00000004 + 8) + iVar3;
  local_1c = *(int *)(in_stack_00000004 + 0xc) + 0xe;
  FUN_005002c0(&local_20,this->i_20 + 0xc,*(int *)(in_stack_00000004 + 4) + 4,
               in_stack_00000004 + 0x10,0,local_20);
  return;
}

