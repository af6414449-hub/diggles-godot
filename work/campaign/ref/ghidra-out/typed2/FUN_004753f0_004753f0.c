
uint FUN_004753f0(float *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  float *in_EAX;
  uint uVar10;
  CMap *pCVar11;
  uint uVar12;
  double dVar13;
  int local_10;
  
  iVar9 = DAT_0076a338;
  uVar12 = 0;
  if (0 < *(int *)(DAT_0076a338 + 0x286c)) {
    local_10 = 0;
    pCVar11 = PTR_0077241c;
    do {
      if (*(uint *)(iVar9 + 0x286c) <= uVar12) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pCVar11 = PTR_0077241c;
      }
      in_EAX = (float *)(*(int *)(iVar9 + 0x2868) + local_10);
      fVar3 = *in_EAX;
      if ((((fVar3 < pCVar11->x0f + 0.0) || (pCVar11->x1f - 0.0 <= fVar3)) ||
          (fVar4 = in_EAX[1], fVar4 < pCVar11->y0f + 0.0)) || (pCVar11->y1f - 0.0 <= fVar4)) {
        uVar10 = *(uint *)(iVar9 + 0x286c);
        if (uVar10 <= uVar12) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar10 = *(uint *)(iVar9 + 0x286c);
          pCVar11 = PTR_0077241c;
          if (uVar10 <= uVar12) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar10 = *(uint *)(iVar9 + 0x286c);
            pCVar11 = PTR_0077241c;
          }
        }
        if ((int)uVar12 < (int)(uVar10 - 1)) {
          iVar5 = *(int *)(iVar9 + 0x2868);
          puVar2 = (undefined4 *)(uVar10 * 0x20 + -0x20 + iVar5);
          uVar6 = puVar2[1];
          uVar7 = puVar2[2];
          uVar8 = puVar2[3];
          puVar1 = (undefined4 *)(local_10 + iVar5);
          *puVar1 = *puVar2;
          puVar1[1] = uVar6;
          puVar1[2] = uVar7;
          puVar1[3] = uVar8;
          puVar1 = (undefined4 *)(uVar10 * 0x20 + -0x10 + iVar5);
          uVar6 = puVar1[1];
          uVar7 = puVar1[2];
          uVar8 = puVar1[3];
          puVar2 = (undefined4 *)(local_10 + 0x10 + iVar5);
          *puVar2 = *puVar1;
          puVar2[1] = uVar6;
          puVar2[2] = uVar7;
          puVar2[3] = uVar8;
          uVar10 = *(uint *)(iVar9 + 0x286c);
        }
        in_EAX = (float *)(uVar10 - 1);
        uVar12 = uVar12 - 1;
        *(float **)(iVar9 + 0x286c) = in_EAX;
        local_10 = local_10 + -0x20;
      }
      else {
        dVar13 = (double)((fVar4 - param_1[1]) * (fVar4 - param_1[1]) +
                         (fVar3 - *param_1) * (fVar3 - *param_1));
        if (dVar13 < 0.0) {
          __libm_sse2_sqrt_precise();
        }
        else {
          dVar13 = SQRT(dVar13);
        }
        if ((float)dVar13 < in_EAX[7]) {
          return CONCAT31((int3)((uint)in_EAX >> 8),1);
        }
      }
      uVar12 = uVar12 + 1;
      local_10 = local_10 + 0x20;
    } while ((int)uVar12 < *(int *)(iVar9 + 0x286c));
  }
  return (uint)in_EAX & 0xffffff00;
}

