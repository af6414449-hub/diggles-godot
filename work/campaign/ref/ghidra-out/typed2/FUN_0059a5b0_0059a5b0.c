
void FUN_0059a5b0(uint *param_1,uint *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  
  if (((((int)*param_2 < PTR_0077241c->x0_8 + 8) || (PTR_0077241c->x1_8 + -8 <= (int)*param_2)) ||
      (uVar6 = param_2[1], (int)uVar6 < PTR_0077241c->y0_8 + 8)) ||
     (PTR_0077241c->y1_8 + -8 <= (int)uVar6)) {
    uVar6 = param_2[1];
    *param_1 = *param_2;
    param_1[1] = uVar6;
    return;
  }
  uVar5 = *param_2;
  iVar2 = FUN_00592f10(PTR_0077241c);
  bVar4 = *(byte *)(((uVar6 & 7) << 3 | uVar5 & 7) + 0x3c + iVar2);
  if ((bVar4 & 0xf) == 0) {
    iVar2 = 3;
    bVar1 = false;
    if ((bVar4 & 0xe) == 0) {
      do {
        iVar2 = iVar2 + -1;
        if (iVar2 < 1) {
          uVar5 = *param_2;
          uVar6 = param_2[1];
          if (bVar1) break;
          bVar1 = true;
          iVar2 = 5;
          uVar6 = uVar6 + 1;
        }
        uVar6 = uVar6 - 1;
        iVar3 = FUN_00592f10(PTR_0077241c);
        if ((*(byte *)(((uVar6 & 7) << 3 | uVar5 & 7) + 0x3c + iVar3) & bVar1) != 0) {
          *param_1 = uVar5;
          param_1[1] = uVar6;
          return;
        }
      } while( true );
    }
  }
  else {
    iVar2 = 3;
    if ((bVar4 & 2) == 0) {
      while ((bVar4 & 8) == 0) {
        iVar2 = iVar2 + -1;
        if (iVar2 < 1) {
          uVar5 = *param_2;
          uVar6 = param_2[1];
          break;
        }
        uVar6 = uVar6 + 1;
        iVar3 = FUN_00592f10(PTR_0077241c);
        bVar4 = *(byte *)(((uVar6 & 7) << 3 | uVar5 & 7) + 0x3c + iVar3);
        if ((bVar4 & 2) != 0) {
          *param_1 = uVar5;
          param_1[1] = uVar6;
          return;
        }
      }
    }
  }
  *param_1 = uVar5;
  param_1[1] = uVar6;
  return;
}

