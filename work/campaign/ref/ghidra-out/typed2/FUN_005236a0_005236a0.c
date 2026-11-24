
ViWinProduction * __thiscall FUN_005236a0(ViWinProduction *this)

{
  int iVar1;
  ViWinProduction *pVVar2;
  int in_stack_00000004;
  
  iVar1 = FUN_00501450();
  if ((this->i_28 & *(uint *)(iVar1 + 0x101f8)) == 0) {
    return (ViWinProduction *)0x0;
  }
  pVVar2 = (ViWinProduction *)FUN_00505dd0((ViWin *)this);
  if (((this->i_2036c == 0) && (0x1e < in_stack_00000004)) && (pVVar2 == this)) {
    pVVar2 = (ViWinProduction *)0x0;
  }
  return pVVar2;
}

