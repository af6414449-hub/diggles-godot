
void __thiscall FUN_00533ec0(ViWinBigInfo *this)

{
  uint uVar1;
  int iVar2;
  undefined4 *_Dst;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00702e96;
  local_10 = ExceptionList;
  uVar1 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar3 = this->i_24;
  if ((uVar3 & 3) != 0) {
    iVar2 = FUN_006ba810(0xa2,uVar1);
    local_8 = 0;
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00533250();
    }
    local_8 = 0xffffffff;
    this->i_44 = iVar2;
    uVar3 = *(uint *)(iVar2 + 0x24) | 1;
    if (uVar3 != *(uint *)(iVar2 + 0x24)) {
      *(uint *)(iVar2 + 0x24) = uVar3;
      FUN_00504ee0();
      iVar2 = this->i_44;
    }
    FUN_00504ce0(iVar2);
    uVar3 = this->i_24;
  }
  if ((uVar3 & 0xc) != 0) {
    iVar2 = FUN_006ba810(0xa9,uVar1);
    local_8 = 1;
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00533250();
    }
    local_8 = 0xffffffff;
    this->i_48 = iVar2;
    uVar3 = *(uint *)(iVar2 + 0x24) | 2;
    if (uVar3 != *(uint *)(iVar2 + 0x24)) {
      *(uint *)(iVar2 + 0x24) = uVar3;
      FUN_00504ee0();
      iVar2 = this->i_48;
    }
    FUN_00504ce0(iVar2);
  }
  _Dst = (undefined4 *)FUN_006ba810(0xae,uVar1);
  local_8 = 2;
  if (_Dst == (undefined4 *)0x0) {
    _Dst = (undefined4 *)0x0;
  }
  else {
    _memset(_Dst,0,0x44);
    FUN_005044d0();
    *_Dst = ViWinScrollField::ViWinViewPort::vftable;
  }
  local_8 = 0xffffffff;
  this->i_4c = (int)_Dst;
  FUN_00504ce0(_Dst);
  FUN_00533d10();
  if (this->i_50 != 0) {
    FUN_00504ce0(this->i_50);
    FUN_00533bb0();
  }
  ExceptionList = local_10;
  return;
}

