
void FUN_004750b0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int in_ECX;
  int iVar11;
  float *pfVar12;
  byte *pbVar13;
  uint uVar14;
  bool bVar15;
  double dVar16;
  float fVar17;
  float fVar18;
  int local_28;
  float local_24;
  
  iVar11 = DAT_00772400;
  local_24 = 3.4028235e+38;
  uVar14 = 0;
  *(undefined1 *)(in_ECX + 0x2850) = 0;
  *(undefined4 *)(in_ECX + 0x2854) = 0;
  *(undefined4 *)(in_ECX + 0x2858) = 0;
  *(undefined4 *)(in_ECX + 0x285c) = 0;
  *(undefined4 *)(in_ECX + 0x2860) = 0;
  iVar9 = *(int *)(iVar11 + 0x5a4);
  fVar3 = *(float *)(iVar9 + 0x154);
  fVar4 = *(float *)(iVar9 + 0x158);
  uVar5 = *(uint *)(iVar11 + 100);
  if (0 < *(int *)(in_ECX + 0x286c)) {
    bVar15 = *(int *)(in_ECX + 0x286c) != 0;
    local_28 = 0;
    do {
      if (!bVar15) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      pfVar12 = (float *)(*(int *)(in_ECX + 0x2868) + local_28);
      fVar18 = *pfVar12;
      if ((((fVar18 < PTR_0077241c->x0f + 0.0) || (PTR_0077241c->x1f - 0.0 <= fVar18)) ||
          (fVar17 = pfVar12[1], fVar17 < PTR_0077241c->y0f + 0.0)) ||
         (PTR_0077241c->y1f - 0.0 <= fVar17)) {
        uVar10 = *(uint *)(in_ECX + 0x286c);
        if (uVar10 <= uVar14) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar10 = *(uint *)(in_ECX + 0x286c);
          if (uVar10 <= uVar14) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar10 = *(uint *)(in_ECX + 0x286c);
          }
        }
        if ((int)uVar14 < (int)(uVar10 - 1)) {
          iVar9 = *(int *)(in_ECX + 0x2868);
          puVar2 = (undefined4 *)(uVar10 * 0x20 + -0x20 + iVar9);
          uVar6 = puVar2[1];
          uVar7 = puVar2[2];
          uVar8 = puVar2[3];
          puVar1 = (undefined4 *)(local_28 + iVar9);
          *puVar1 = *puVar2;
          puVar1[1] = uVar6;
          puVar1[2] = uVar7;
          puVar1[3] = uVar8;
          puVar1 = (undefined4 *)(uVar10 * 0x20 + -0x10 + iVar9);
          uVar6 = puVar1[1];
          uVar7 = puVar1[2];
          uVar8 = puVar1[3];
          puVar2 = (undefined4 *)(local_28 + 0x10 + iVar9);
          *puVar2 = *puVar1;
          puVar2[1] = uVar6;
          puVar2[2] = uVar7;
          puVar2[3] = uVar8;
          uVar10 = *(uint *)(in_ECX + 0x286c);
        }
        uVar14 = uVar14 - 1;
        *(uint *)(in_ECX + 0x286c) = uVar10 - 1;
        local_28 = local_28 + -0x20;
      }
      else {
        fVar17 = fVar17 - fVar4;
        fVar18 = fVar18 - fVar3;
        dVar16 = (double)(fVar17 * fVar17 + fVar18 * fVar18);
        if (dVar16 < 0.0) {
          __libm_sse2_sqrt_precise();
        }
        else {
          dVar16 = SQRT(dVar16);
        }
        fVar18 = (float)dVar16;
        if ((fVar18 < pfVar12[7]) && (fVar18 < local_24)) {
          *(float *)(in_ECX + 0x2854) = pfVar12[3];
          *(float *)(in_ECX + 0x2858) = pfVar12[4];
          *(float *)(in_ECX + 0x285c) = pfVar12[5];
          *(float *)(in_ECX + 0x2860) = pfVar12[6];
          DAT_00772dd8 = (int)ROUND(*pfVar12);
          iVar9 = FUN_00592f10(PTR_0077241c);
          pbVar13 = (byte *)(iVar9 + 0x34);
          if (uVar5 < 8) {
            pbVar13 = pbVar13 + uVar5;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          if (*pbVar13 - 1 < 0x7f) {
            iVar9 = 0;
          }
          else {
            iVar11 = *pbVar13 - 0x80;
            iVar9 = iVar11;
            if (0 < iVar11) {
              iVar9 = 0x80;
              if ((int)((double)iVar11 * 1.3) < 0x80) {
                iVar9 = (int)((double)iVar11 * 1.3);
              }
            }
          }
          uVar10 = iVar9 * 2;
          if ((0 < (int)uVar10) && (0xff < (int)uVar10)) {
            uVar10 = 0xff;
          }
          iVar9 = 0xff - ((uVar10 ^ (int)uVar10 >> 0x1f) - ((int)uVar10 >> 0x1f));
          if (iVar9 < 1) {
            iVar9 = 0;
          }
          *(float *)(in_ECX + 0x2864) = (float)iVar9 / 255.0;
          local_24 = fVar18;
          if (*(char *)(in_ECX + 0x38f0) != '\0') {
            *(undefined1 *)(in_ECX + 0x2850) = 1;
          }
        }
      }
      uVar14 = uVar14 + 1;
      local_28 = local_28 + 0x20;
      bVar15 = uVar14 < *(uint *)(in_ECX + 0x286c);
    } while ((int)uVar14 < (int)*(uint *)(in_ECX + 0x286c));
  }
  return;
}

