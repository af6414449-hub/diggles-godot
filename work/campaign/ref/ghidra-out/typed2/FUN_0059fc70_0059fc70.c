
uint * FUN_0059fc70(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  CMap *this;
  int iVar4;
  byte bVar5;
  int local_8;
  
  this = PTR_0077241c;
  uVar1 = *param_2;
  uVar2 = param_2[1];
  *param_1 = uVar1;
  param_1[1] = uVar2;
  iVar4 = FUN_00592f10(this);
  bVar5 = *(byte *)(((uVar2 & 7) << 3 | uVar1 & 7) + 0x3c + iVar4);
  local_8 = 3;
  if ((bVar5 & 0xf) == 0) {
    bVar3 = false;
    bVar5 = bVar5 & 0xe;
    while (bVar5 == 0) {
      local_8 = local_8 + -1;
      if (local_8 < 1) {
        *param_1 = *param_2;
        param_1[1] = param_2[1];
        if (bVar3) {
          return param_1;
        }
        bVar3 = true;
        local_8 = 5;
        param_1[1] = param_1[1] + 1;
      }
      param_1[1] = param_1[1] - 1;
      uVar1 = param_1[1];
      uVar2 = *param_1;
      iVar4 = FUN_00592f10(PTR_0077241c);
      bVar5 = *(byte *)(((uVar1 & 7) << 3 | uVar2 & 7) + 0x3c + iVar4) & bVar3;
    }
  }
  else if ((bVar5 & 2) == 0) {
    while ((bVar5 & 8) == 0) {
      local_8 = local_8 + -1;
      if (local_8 < 1) {
        *param_1 = *param_2;
        param_1[1] = param_2[1];
        return param_1;
      }
      param_1[1] = param_1[1] + 1;
      uVar1 = param_1[1];
      uVar2 = *param_1;
      iVar4 = FUN_00592f10(PTR_0077241c);
      bVar5 = *(byte *)(((uVar1 & 7) << 3 | uVar2 & 7) + 0x3c + iVar4);
      if ((bVar5 & 2) != 0) {
        return param_1;
      }
    }
  }
  return param_1;
}

