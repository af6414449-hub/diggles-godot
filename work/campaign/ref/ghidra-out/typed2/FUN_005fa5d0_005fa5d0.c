
undefined4 FUN_005fa5d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  param_1 = param_1 - ((int)(PTR_0077241c->originX + (PTR_0077241c->originX >> 0x1f & 3U)) >> 2);
  param_2 = param_2 - ((int)(PTR_0077241c->originY + (PTR_0077241c->originY >> 0x1f & 3U)) >> 2);
  if ((((-1 < param_1) && (param_1 < *(int *)(in_ECX + 0x7c))) && (-1 < param_2)) &&
     (param_2 < *(int *)(in_ECX + 0x80))) {
    puVar1 = (undefined4 *)FUN_00405920(*(int *)(in_ECX + 0x7c) * param_2 + param_1);
    return *puVar1;
  }
  return 1;
}

