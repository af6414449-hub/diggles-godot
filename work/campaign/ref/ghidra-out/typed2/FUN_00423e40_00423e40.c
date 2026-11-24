
uint * FUN_00423e40(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *in_ECX;
  uint *in_EDX;
  int iVar4;
  
  if ((((PTR_0077241c->x0_8 <= (int)*in_EDX) && ((int)*in_EDX < PTR_0077241c->x1_8)) &&
      (PTR_0077241c->y0_8 <= (int)in_EDX[1])) && ((int)(in_EDX[1] + param_1) < PTR_0077241c->y1_8))
  {
    iVar4 = 0;
    if (0 < param_1) {
      do {
        uVar1 = in_EDX[1];
        uVar2 = *in_EDX;
        iVar3 = FUN_00592f10(PTR_0077241c);
        if ((*(byte *)(((uVar1 + iVar4 & 7) << 3 | uVar2 & 7) + 0x3c + iVar3) & 2) != 0) {
          *in_ECX = *in_EDX;
          in_ECX[1] = in_EDX[1] + iVar4;
          return in_ECX;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_1);
    }
    uVar1 = in_EDX[1];
    *in_ECX = *in_EDX;
    in_ECX[1] = uVar1;
    return in_ECX;
  }
  uVar1 = in_EDX[1];
  *in_ECX = *in_EDX;
  in_ECX[1] = uVar1;
  return in_ECX;
}

