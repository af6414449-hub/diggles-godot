
uint FUN_0040b8a0(int *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = PTR_0077241c->x0_8 + param_2;
  if (((int)uVar1 <= *param_1) && (uVar1 = PTR_0077241c->x1_8 - param_2, *param_1 < (int)uVar1)) {
    uVar1 = PTR_0077241c->y0_8 + param_2;
    if (((int)uVar1 <= param_1[1]) &&
       (uVar1 = PTR_0077241c->y1_8 - param_2, param_1[1] < (int)uVar1)) {
      return uVar1 & 0xffffff00;
    }
  }
  return CONCAT31((int3)(uVar1 >> 8),1);
}

