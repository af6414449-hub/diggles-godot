
CMapCell * __thiscall FUN_00592f10(CMap *this)

{
  int iVar1;
  int iVar2;
  int in_stack_00000004;
  int in_stack_00000008;
  
  if (in_stack_00000004 < this->cellX0) {
    in_stack_00000004 = this->cellX0;
  }
  iVar2 = this->cellX1 + -1;
  if (in_stack_00000004 < this->cellX1) {
    iVar2 = in_stack_00000004;
  }
  if (in_stack_00000008 < this->cellY0) {
    in_stack_00000008 = this->cellY0;
  }
  iVar1 = this->cellY1 + -1;
  if (in_stack_00000008 < this->cellY1) {
    iVar1 = in_stack_00000008;
  }
  iVar2 = (iVar1 * this->mapWidth + iVar2) % this->cellCountTotal;
  if ((-1 < iVar2) && (iVar2 < this->cellCount)) {
    return this->cells + iVar2;
  }
  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  return this->cells;
}

