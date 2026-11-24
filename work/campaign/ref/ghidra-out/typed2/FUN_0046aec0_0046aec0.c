
void FUN_0046aec0(float *param_1)

{
  float fVar1;
  int iVar2;
  char *pcVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  
  fVar5 = *(float *)(DAT_00772400 + 0x28c);
  fVar4 = *(float *)(DAT_00772400 + 0x288);
  uVar6 = *(uint *)(DAT_00772400 + 100);
  fVar1 = *(float *)(DAT_00772400 + 0x284);
  if ((((fVar1 < PTR_0077241c->x0f + 4.0) || (PTR_0077241c->x1f - 4.0 <= fVar1)) ||
      (fVar4 < PTR_0077241c->y0f + 4.0)) || (PTR_0077241c->y1f - 4.0 <= fVar4)) {
    param_1[1] = fVar4;
    param_1[2] = fVar5;
    *param_1 = fVar1;
    return;
  }
  DAT_00772dd8 = (int)ROUND(fVar1);
  iVar2 = FUN_00592f10(PTR_0077241c);
  pcVar3 = (char *)(iVar2 + 0x34);
  if (uVar6 < 8) {
    pcVar3 = pcVar3 + uVar6;
  }
  else {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
  }
  if (*pcVar3 == '\0') {
    DAT_00772dd8 = (int)ROUND(fVar1);
    iVar2 = FUN_00592f10(PTR_0077241c);
    pcVar3 = (char *)(iVar2 + 0x34);
    if (uVar6 < 8) {
      pcVar3 = pcVar3 + uVar6;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    if (*pcVar3 == '\0') {
      DAT_00772dd8 = (int)ROUND(fVar1);
      iVar2 = FUN_00592f10(PTR_0077241c);
      pcVar3 = (char *)(iVar2 + 0x34);
      if (uVar6 < 8) {
        pcVar3 = pcVar3 + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*pcVar3 == '\0') {
        DAT_00772dd8 = (int)ROUND(fVar1);
        FUN_00592f10(PTR_0077241c);
        pcVar3 = (char *)FUN_00423700(uVar6);
        if (*pcVar3 == '\0') goto LAB_0046b0fb;
      }
    }
  }
  fVar5 = *(float *)(DAT_00772400 + 0x358);
  fVar4 = *(float *)(DAT_00772400 + 0x354);
  fVar1 = *(float *)(DAT_00772400 + 0x350);
LAB_0046b0fb:
  DAT_00772dd8 = (int)ROUND(fVar4 * 8.0);
  fVar4 = (float)DAT_00772dd8;
  param_1[2] = fVar5;
  *param_1 = (float)(int)ROUND(fVar1 + fVar1 + 0.5) * 0.5;
  param_1[1] = fVar4 * 0.125;
  return;
}

