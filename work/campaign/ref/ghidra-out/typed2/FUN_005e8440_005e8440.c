
undefined4 FUN_005e8440(float *param_1)

{
  float fVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  float *in_ECX;
  float *in_EDX;
  char *pcVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  if ((((PTR_0077241c->x0f + 12.0 <= *in_ECX) && (*in_ECX < PTR_0077241c->x1f - 12.0)) &&
      (PTR_0077241c->y0f + 12.0 <= in_ECX[1])) && (in_ECX[1] < PTR_0077241c->y1f - 12.0)) {
    DAT_00772dd8 = (int)ROUND(*in_ECX);
    uVar2 = *(uint *)(DAT_00772400 + 100);
    iVar4 = FUN_00592f10(PTR_0077241c);
    pcVar5 = (char *)(iVar4 + 0x34);
    if (uVar2 < 8) {
      pcVar5 = pcVar5 + uVar2;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*pcVar5 != '\0') {
      fVar7 = (in_EDX[2] * 0.01) / 1.4 + in_ECX[2];
      fVar6 = *param_1;
      fVar1 = *in_ECX;
      fVar8 = ((*in_EDX * 0.005) / 1.4 + *in_ECX) * 8.0;
      DAT_00772dd8 = (int)ROUND(fVar8);
      bVar3 = FUN_004093f0(PTR_0077241c);
      if ((float)bVar3 <= fVar7) {
        DAT_00772dd8 = (int)ROUND(fVar8);
        bVar3 = FUN_004093f0(PTR_0077241c);
        if ((float)bVar3 <= fVar7) {
          fVar6 = ((fVar6 * 0.005) / 1.4 + fVar1) * 8.0;
          DAT_00772dd8 = (int)ROUND(fVar6);
          bVar3 = FUN_004093f0(PTR_0077241c);
          if ((float)bVar3 <= fVar7) {
            DAT_00772dd8 = (int)ROUND(fVar6);
            bVar3 = FUN_004093f0(PTR_0077241c);
            if ((float)bVar3 <= fVar7) {
              return 0;
            }
          }
        }
      }
    }
  }
  return 1;
}

