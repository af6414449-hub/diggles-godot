
uint FUN_005ab130(void)

{
  uint uVar1;
  float in_XMM1_Da;
  float in_XMM2_Da;
  
  uVar1 = PTR_0077241c->cellX0 + 1;
  if (((((int)uVar1 <= (int)in_XMM1_Da) &&
       (uVar1 = PTR_0077241c->cellX1 - 1, (int)in_XMM1_Da < (int)uVar1)) &&
      (uVar1 = PTR_0077241c->cellY0 + 1, (int)uVar1 <= (int)in_XMM2_Da)) &&
     (uVar1 = PTR_0077241c->cellY1 - 1, (int)in_XMM2_Da < (int)uVar1)) {
    if (1.0 <= (in_XMM2_Da * 8.0 - (float)(int)(in_XMM2_Da * 8.0)) +
               (in_XMM1_Da * 8.0 - (float)(int)(in_XMM1_Da * 8.0))) {
      FUN_004093f0(PTR_0077241c);
    }
    else {
      FUN_004093f0(PTR_0077241c);
    }
    uVar1 = FUN_004093f0(PTR_0077241c);
    return uVar1 & 0xff;
  }
  return uVar1;
}

