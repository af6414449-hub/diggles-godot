
uint FUN_005bf200(void)

{
  uint uVar1;
  int iVar2;
  float *in_ECX;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)(*in_ECX * 8.0);
  uVar1 = PTR_0077241c->x0_8 + 2;
  uVar4 = (uint)(in_ECX[1] * 8.0);
  if (((((int)uVar1 <= (int)uVar3) && (uVar1 = PTR_0077241c->x1_8 - 2, (int)uVar3 < (int)uVar1)) &&
      (uVar1 = PTR_0077241c->y0_8 + 2, (int)uVar1 <= (int)uVar4)) &&
     (uVar1 = PTR_0077241c->y1_8 - 2, (int)uVar4 < (int)uVar1)) {
    uVar3 = uVar3 & 7;
    iVar2 = FUN_00592f10(PTR_0077241c);
    uVar1 = iVar2 + 0x3c;
    if ((*(byte *)(((uVar4 + 1 & 7) << 3 | uVar3) + uVar1) & 2) == 0) {
      iVar2 = FUN_00592f10(PTR_0077241c);
      uVar1 = iVar2 + 0x3c;
      if ((*(byte *)(((uVar4 & 7) << 3 | uVar3) + uVar1) & 2) == 0) {
        iVar2 = FUN_00592f10(PTR_0077241c);
        uVar1 = iVar2 + 0x3c;
        if ((*(byte *)(((uVar4 - 1 & 7) << 3 | uVar3) + uVar1) & 2) == 0) {
          return CONCAT31((int3)(uVar1 >> 8),1);
        }
      }
    }
  }
  return uVar1 & 0xffffff00;
}

