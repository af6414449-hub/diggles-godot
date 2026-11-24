
float * FUN_00423f20(float param_1,float param_2,float param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  float *in_ECX;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  if ((((param_1 < PTR_0077241c->x0f + 1.0) || (PTR_0077241c->x1f - 1.0 <= param_1)) ||
      (param_2 < PTR_0077241c->y0f + 1.0)) || (PTR_0077241c->y1f - 1.0 <= param_2)) {
    *in_ECX = param_1;
    in_ECX[1] = param_2;
    in_ECX[2] = param_3;
    return in_ECX;
  }
  uVar1 = (uint)ROUND(param_2 * 8.0);
  uVar2 = (uint)ROUND(param_1 * 8.0);
  DAT_00772dd8 = uVar2;
  iVar5 = FUN_00592f10(PTR_0077241c);
  uVar8 = uVar2 & 7;
  iVar9 = 2;
  bVar3 = *(byte *)(((uVar1 & 7) << 3 | uVar8) + 0x3c + iVar5);
  uVar4 = uVar1;
  if ((bVar3 & 0xf) == 0) {
    bVar6 = 0xe;
    bVar3 = bVar3 & 0xe;
    uVar7 = uVar1;
    while (bVar3 == 0) {
      iVar9 = iVar9 + -1;
      if (iVar9 < 1) {
        uVar7 = uVar1;
        if ((bVar6 & 1) != 0) break;
        bVar6 = bVar6 | 1;
        uVar7 = uVar1 + 1;
        iVar9 = 5;
      }
      uVar7 = uVar7 - 1;
      iVar5 = FUN_00592f10(PTR_0077241c);
      bVar3 = *(byte *)(((uVar7 & 7) << 3 | uVar8) + 0x3c + iVar5) & bVar6;
    }
  }
  else {
    while (((uVar7 = uVar4, (bVar3 & 2) == 0 && ((bVar3 & 8) == 0)) &&
           (iVar9 = iVar9 + -1, uVar7 = uVar1, 0 < iVar9))) {
      iVar5 = FUN_00592f10(PTR_0077241c);
      bVar3 = *(byte *)(((uVar4 + 1 & 7) << 3 | uVar8) + 0x3c + iVar5);
      uVar4 = uVar4 + 1;
    }
  }
  *in_ECX = (float)(int)uVar2 * 0.125;
  in_ECX[1] = (float)(int)uVar7 * 0.125;
  in_ECX[2] = param_3;
  return in_ECX;
}

