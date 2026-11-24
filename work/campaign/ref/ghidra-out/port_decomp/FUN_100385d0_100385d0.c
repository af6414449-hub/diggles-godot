
undefined4 FUN_100385d0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  int in_EDX;
  code *pcVar8;
  float *pfVar9;
  uint uVar10;
  int iVar11;
  float *pfVar12;
  double dVar13;
  double dVar14;
  int local_44;
  int local_2c;
  float *local_18;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  pcVar8 = malloc_exref;
  iVar2 = param_1 >> 2;
  iVar4 = param_1 >> 1;
  iVar3 = param_1 >> 3;
  uVar10 = iVar4 * 4 + 7U & 0xfffffff8;
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar10;
  if (*(int *)(in_ECX + 0x5c) == 0) {
    if (uVar10 == 0) goto LAB_1003865f;
    pvVar5 = malloc(uVar10);
    pcVar8 = malloc_exref;
  }
  else {
    iVar11 = *(int *)(in_ECX + 100);
    iVar6 = iVar11 + uVar10;
    if (*(int *)(in_ECX + 0x68) < iVar6) {
LAB_1003865f:
      pvVar5 = (void *)0x0;
    }
    else {
      *(int *)(in_ECX + 100) = iVar6;
      pvVar5 = (void *)(*(int *)(in_ECX + 0x5c) + iVar11);
    }
  }
  *(void **)(in_ECX + 0x438 + in_EDX * 4) = pvVar5;
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar10;
  if (*(int *)(in_ECX + 0x5c) == 0) {
    if (uVar10 == 0) goto LAB_10038697;
    iVar6 = (*pcVar8)(uVar10);
  }
  else {
    iVar6 = *(int *)(in_ECX + 100);
    iVar11 = uVar10 + iVar6;
    if (*(int *)(in_ECX + 0x68) < iVar11) {
LAB_10038697:
      iVar6 = 0;
    }
    else {
      *(int *)(in_ECX + 100) = iVar11;
      iVar6 = *(int *)(in_ECX + 0x5c) + iVar6;
    }
  }
  *(int *)(in_ECX + 0x440 + in_EDX * 4) = iVar6;
  uVar10 = iVar2 * 4 + 7U & 0xfffffff8;
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar10;
  if (*(int *)(in_ECX + 0x5c) == 0) {
    if (uVar10 != 0) {
      pfVar12 = (float *)malloc(uVar10);
      goto LAB_100386df;
    }
  }
  else {
    iVar6 = *(int *)(in_ECX + 100);
    iVar11 = uVar10 + iVar6;
    if (iVar11 <= *(int *)(in_ECX + 0x68)) {
      *(int *)(in_ECX + 100) = iVar11;
      pfVar12 = (float *)(*(int *)(in_ECX + 0x5c) + iVar6);
      goto LAB_100386df;
    }
  }
  pfVar12 = (float *)0x0;
LAB_100386df:
  pfVar9 = *(float **)(in_ECX + 0x438 + in_EDX * 4);
  *(float **)(in_ECX + 0x448 + in_EDX * 4) = pfVar12;
  if (((pfVar9 != (float *)0x0) && (iVar6 = *(int *)(in_ECX + 0x440 + in_EDX * 4), iVar6 != 0)) &&
     (pfVar12 != (float *)0x0)) {
    if (0 < iVar2) {
      local_18 = (float *)(iVar6 + 4);
      iVar11 = 0;
      iVar6 = (int)pfVar9 - iVar6;
      local_2c = 1;
      do {
        dVar13 = (double)(((float)iVar11 * 3.1415927) / (float)param_1);
        dVar14 = dVar13;
        libm_sse2_cos_precise();
        *pfVar9 = (float)dVar14;
        libm_sse2_sin_precise();
        *(float *)(iVar6 + (int)local_18) = (float)-dVar13;
        dVar13 = (double)((((float)local_2c * 3.1415927) / (float)param_1) * 0.5);
        dVar14 = dVar13;
        libm_sse2_cos_precise();
        local_18[-1] = (float)dVar14 * 0.5;
        libm_sse2_sin_precise();
        pfVar9 = pfVar9 + 2;
        local_2c = local_2c + 2;
        iVar11 = iVar11 + 4;
        *local_18 = (float)dVar13 * 0.5;
        local_18 = local_18 + 2;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if (0 < iVar3) {
      iVar2 = 2;
      local_44 = iVar3;
      do {
        dVar13 = (double)(((float)iVar2 * 3.1415927) / (float)param_1);
        dVar14 = dVar13;
        libm_sse2_cos_precise();
        *pfVar12 = (float)dVar14;
        libm_sse2_sin_precise();
        iVar2 = iVar2 + 4;
        local_44 = local_44 + -1;
        pfVar12[1] = (float)-dVar13;
        pfVar12 = pfVar12 + 2;
      } while (local_44 != 0);
    }
    iVar2 = FUN_10037f70();
    *(int *)(in_ECX + 0x450 + in_EDX * 4) = iVar2;
    if (iVar2 != 0) {
      iVar6 = 0;
      if (0 < iVar4) {
        do {
          dVar14 = (((double)iVar6 + 0.5) / (double)iVar4) * 0.5 * 3.1415927410125732;
          libm_sse2_sin_precise();
          dVar14 = (double)((float)dVar14 * (float)dVar14) * 1.5707963705062866;
          libm_sse2_sin_precise();
          *(float *)(iVar2 + iVar6 * 4) = (float)dVar14;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar4);
      }
      iVar2 = FUN_10037f70();
      *(int *)(in_ECX + 0x458 + in_EDX * 4) = iVar2;
      if (iVar2 != 0) {
        cVar1 = FUN_10038070();
        uVar10 = 0;
        if (0 < iVar3) {
          do {
            uVar7 = (uVar10 >> 1 ^ uVar10 * 2) & 0x55555555 ^ uVar10 * 2;
            uVar7 = (uVar7 >> 2 ^ uVar7 * 4) & 0x33333333 ^ uVar7 * 4;
            uVar7 = (uVar7 >> 4 ^ uVar7 << 4) & 0xf0f0f0f ^ uVar7 << 4;
            uVar7 = (uVar7 >> 8 ^ uVar7 << 8) & 0xff00ff ^ uVar7 << 8;
            *(short *)(iVar2 + uVar10 * 2) =
                 (short)(((uVar7 << 0x10 | uVar7 >> 0x10) >> (0x23U - (cVar1 + -1) & 0x1f)) << 2);
            uVar10 = uVar10 + 1;
          } while ((int)uVar10 < iVar3);
        }
        return 1;
      }
    }
  }
  *(undefined4 *)(in_ECX + 0x70) = 3;
  return 0;
}

