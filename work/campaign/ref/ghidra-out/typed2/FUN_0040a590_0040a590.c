
void FUN_0040a590(float param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6)

{
  CHeightBlockArray *pCVar1;
  int iVar2;
  CMap *pCVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  uint uVar6;
  CHeightBlock *pCVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  double dVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float local_28;
  
  fVar13 = param_4 - param_1;
  fVar14 = param_6 - param_3;
  *(undefined1 *)(in_ECX + 0x54) = 1;
  if (*(int *)(in_ECX + 0x20) == 1) {
    fVar9 = param_5 - param_2;
    fVar10 = fVar14 * fVar14 + fVar9 * fVar9 + fVar13 * fVar13;
    FUN_0040b7e0();
    fVar12 = 0.0;
    if (fVar10 <= 0.0) {
      fVar14 = 0.0;
      fVar9 = 0.0;
    }
    else {
      fVar14 = fVar14 / fVar10;
      fVar9 = fVar9 / fVar10;
      fVar12 = fVar13 / fVar10;
    }
    fVar12 = fVar12 * 0.125;
    fVar9 = fVar9 * 0.125;
    fVar14 = fVar14 * 0.125;
    param_1 = fVar12 * 8.0 + param_1;
    param_2 = fVar9 * 8.0 + param_2;
    param_3 = fVar14 * 8.0 + param_3;
    fVar13 = (param_5 - param_2) * (param_5 - param_2) + (param_4 - param_1) * (param_4 - param_1) +
             (param_6 - param_3) * (param_6 - param_3);
    FUN_0040b7e0();
    fVar10 = fVar9 * fVar9 + fVar12 * fVar12 + fVar14 * fVar14;
    FUN_0040b7e0();
    iVar4 = (int)ROUND(fVar13 / fVar10);
    DAT_00772dd8 = iVar4;
    if (iVar4 != 0) {
      do {
        pCVar3 = PTR_0077241c;
        param_1 = param_1 + fVar12;
        param_2 = param_2 + fVar9;
        param_3 = param_3 + fVar14;
        iVar4 = iVar4 + -1;
        if (*(char *)(in_ECX + 0x55) == '\0') {
          uVar8 = (uint)(param_2 * 8.0);
          uVar6 = (uint)(param_1 * 8.0);
          if ((((int)uVar6 < PTR_0077241c->x0_8 + 0x21) ||
              (PTR_0077241c->x1_8 + -0x21 <= (int)uVar6)) ||
             (((int)uVar8 < PTR_0077241c->y0_8 + 0x21 || (PTR_0077241c->y1_8 + -0x21 <= (int)uVar8))
             )) goto LAB_0040abac;
          piVar5 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar1 = pCVar3->heightBlocks;
          iVar2 = *piVar5;
          if ((iVar2 < 0) || (pCVar1->count <= iVar2)) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar7 = pCVar1->data;
          }
          else {
            pCVar7 = pCVar1->data + iVar2;
          }
          if ((int)param_3 < (int)(uint)pCVar7->heights[(uVar8 & 7) << 3 | uVar6 & 7])
          goto LAB_0040abac;
        }
        if (iVar4 == 0) {
          return;
        }
      } while( true );
    }
  }
  else {
    fVar10 = param_5 - param_2;
    fVar9 = fVar10 * fVar10 + fVar13 * fVar13 + fVar14 * fVar14;
    FUN_0040b7e0();
    if (fVar9 <= 0.0) {
      fVar14 = 0.0;
      fVar10 = 0.0;
      fVar13 = 0.0;
    }
    else {
      fVar14 = fVar14 / fVar9;
      fVar10 = fVar10 / fVar9;
      fVar13 = fVar13 / fVar9;
    }
    fVar13 = fVar13 * 0.125;
    fVar10 = fVar10 * 0.125;
    fVar14 = fVar14 * 0.125;
    param_1 = fVar13 * 8.0 + param_1;
    param_2 = fVar10 * 8.0 + param_2;
    param_3 = fVar14 * 8.0 + param_3;
    fVar9 = (param_5 - param_2) * (param_5 - param_2) + (param_4 - param_1) * (param_4 - param_1) +
            (param_6 - param_3) * (param_6 - param_3);
    FUN_0040b7e0();
    fVar12 = fVar10 * fVar10 + fVar13 * fVar13 + fVar14 * fVar14;
    FUN_0040b7e0();
    iVar4 = (int)ROUND(fVar9 / fVar12);
    fVar9 = (float)iVar4;
    param_5 = param_5 - param_2;
    local_28 = 0.5;
    DAT_00772dd8 = iVar4;
    if (param_5 < -0.8) {
      if (param_5 <= -2.0) {
        param_5 = -2.0;
      }
      local_28 = (1.0 / -param_5) * 0.4;
    }
    do {
      do {
        if (iVar4 == 0) {
          return;
        }
        iVar4 = iVar4 + -1;
        dVar11 = (double)((float)iVar4 * (3.1415927 / fVar9));
        FUN_006f6ad0();
        pCVar3 = PTR_0077241c;
        param_1 = fVar13 + param_1;
        param_2 = fVar10 + param_2;
        param_3 = fVar14 + param_3;
      } while (*(char *)(in_ECX + 0x55) != '\0');
      uVar8 = (uint)((param_2 + -((float)dVar11 * local_28)) * 8.0);
      uVar6 = (uint)((param_1 + 0.0) * 8.0);
      if (((((int)uVar6 < PTR_0077241c->x0_8 + 0x21) || (PTR_0077241c->x1_8 + -0x21 <= (int)uVar6))
          || ((int)uVar8 < PTR_0077241c->y0_8 + 0x21)) || (PTR_0077241c->y1_8 + -0x21 <= (int)uVar8)
         ) break;
      piVar5 = (int *)FUN_00592f10(PTR_0077241c);
      pCVar1 = pCVar3->heightBlocks;
      iVar2 = *piVar5;
      if ((iVar2 < 0) || (pCVar1->count <= iVar2)) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar7 = pCVar1->data;
      }
      else {
        pCVar7 = pCVar1->data + iVar2;
      }
    } while ((int)(uint)pCVar7->heights[(uVar8 & 7) << 3 | uVar6 & 7] <= (int)(param_3 + 0.0));
LAB_0040abac:
    *(undefined1 *)(in_ECX + 0x54) = 0;
  }
  return;
}

