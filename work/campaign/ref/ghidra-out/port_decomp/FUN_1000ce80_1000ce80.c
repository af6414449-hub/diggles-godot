
CPlayer * FUN_1000ce80(uint param_1)

{
  CPlayer *pCVar1;
  uint uVar2;
  CPlayer *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_10042210;
  local_10 = ExceptionList;
  uVar2 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 & 2) != 0) {
    pCVar1 = in_ECX + -4;
    _eh_vector_destructor_iterator_(in_ECX,0x24,*(uint *)(in_ECX + -4),CPlayer::~CPlayer);
    if ((param_1 & 1) != 0) {
      FUN_100402e2(pCVar1,*(int *)pCVar1 * 0x24 + 4,uVar2);
    }
    ExceptionList = local_10;
    return pCVar1;
  }
  CPlayer::~CPlayer(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_100402ac();
  }
  ExceptionList = local_10;
  return in_ECX;
}

