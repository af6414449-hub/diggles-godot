
uint FUN_004097b0(float param_1,float param_2,float param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = PTR_0077241c->x0_8 + 0x21;
  if (((((int)uVar1 <= (int)(param_1 * 8.0)) &&
       (uVar1 = PTR_0077241c->x1_8 - 0x21, (int)(param_1 * 8.0) < (int)uVar1)) &&
      (uVar1 = PTR_0077241c->y0_8 + 0x21, (int)uVar1 <= (int)(param_2 * 8.0))) &&
     (uVar1 = PTR_0077241c->y1_8 - 0x21, (int)(param_2 * 8.0) < (int)uVar1)) {
    uVar2 = FUN_004093f0(PTR_0077241c);
    uVar1 = (uint)param_3;
    if ((int)(uVar2 & 0xff) <= (int)uVar1) {
      return CONCAT31((int3)(uVar1 >> 8),1);
    }
  }
  return uVar1 & 0xffffff00;
}

