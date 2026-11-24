
void FUN_005aae70(void)

{
  int iVar1;
  float fVar2;
  float in_XMM1_Da;
  float in_XMM2_Da;
  float fVar3;
  
  if ((((PTR_0077241c->cellX0 + 1 <= (int)in_XMM1_Da) &&
       ((int)in_XMM1_Da < PTR_0077241c->cellX1 + -1)) &&
      (PTR_0077241c->cellY0 + 1 <= (int)in_XMM2_Da)) &&
     ((int)in_XMM2_Da < PTR_0077241c->cellY1 + -1)) {
    fVar3 = in_XMM2_Da * 8.0;
    iVar1 = (int)(in_XMM1_Da * 8.0);
    FUN_004093f0(PTR_0077241c);
    FUN_004093f0(PTR_0077241c);
    fVar2 = ((float)((int)fVar3 + 1) - fVar3) + (float)iVar1;
    if (1.0 <= (in_XMM1_Da * 8.0 - (float)iVar1) + (fVar3 - (float)(int)fVar3)) {
      FUN_004093f0(PTR_0077241c);
      if ((float)(iVar1 + 1) == fVar2) {
        return;
      }
    }
    else {
      FUN_004093f0(PTR_0077241c);
      if (fVar2 == (float)iVar1) {
        return;
      }
    }
    return;
  }
  return;
}

