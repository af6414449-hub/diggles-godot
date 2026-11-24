
void __thiscall FUN_00505c00(ViWin *this)

{
  int iVar1;
  uint uVar2;
  int *in_stack_00000004;
  undefined4 local_14;
  uint local_c [2];
  
  iVar1 = FUN_00501450();
  if ((this->i_28 & *(uint *)(iVar1 + 0x101f8)) != 0) {
    local_c[0] = _rand();
    local_c[0] = local_c[0] & 0xff;
    uVar2 = _rand();
    iVar1 = _rand();
    local_14 = (uVar2 & 0xff) << 8;
    local_14._0_3_ = CONCAT12((char)iVar1,(undefined2)local_14);
    local_14 = CONCAT13(0xff,(int3)CONCAT31((uint3)local_14 >> 8,(char)local_c[0]));
    local_c[0] = local_14;
    if (*(int *)(*in_stack_00000004 + 8) != 0) {
      FUN_004ff430(*in_stack_00000004 + 0xc,local_c);
    }
    local_c[0] = 0xffffffff;
    FUN_004ff250((float)(this->i_18 + -1 + (in_stack_00000004[3] - this->i_10)),local_c);
    local_c[0] = 0xffffffff;
    FUN_004ff250((float)(this->i_18 + -1 + (in_stack_00000004[3] - this->i_10)),local_c);
  }
  return;
}

