
void FUN_100216f0(float *param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  int in_ECX;
  byte bVar7;
  int *in_EDX;
  byte *pbVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  undefined *puVar12;
  undefined1 *puVar13;
  uint uVar14;
  undefined *puVar15;
  byte *pbVar16;
  uint uVar17;
  float fVar18;
  int local_14;
  float *local_10;
  int local_c;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  bVar7 = *(byte *)(in_ECX + 3) >> 6;
  if (bVar7 == 3) {
    bVar9 = 0;
  }
  else if (bVar7 == 1) {
    bVar9 = (*(byte *)(in_ECX + 3) >> 2 & 0xc) + 4;
  }
  else {
    bVar9 = 0x20;
  }
  bVar1 = *(byte *)(in_ECX + 1);
  if ((bVar1 & 6) == 6) {
    puVar12 = &DAT_10045ba8;
    bVar7 = 0x20;
    goto LAB_100217e5;
  }
  if ((bVar1 & 8) == 0) {
    puVar12 = &DAT_100474c0;
  }
  else {
    bVar2 = *(byte *)(in_ECX + 2);
    uVar6 = (uint)(byte)(&DAT_10046de9)
                        [(uint)(bVar2 >> 4) + ((bVar1 >> 3 & 1) * 3 + (bVar1 >> 1 & 3)) * 0xf] * 2;
    if (bVar7 != 3) {
      uVar6 = (uint)(byte)(&DAT_10046de9)
                          [(uint)(bVar2 >> 4) + ((bVar1 >> 3 & 1) * 3 + (bVar1 >> 1 & 3)) * 0xf];
    }
    if (uVar6 != 0) {
      puVar12 = &DAT_100458a0;
      if (uVar6 < 0x38) {
        puVar12 = &DAT_10045bc8;
        bVar7 = ((bVar2 & 0xc) == 8) * '\x04' + 8;
        goto LAB_100217e5;
      }
      bVar7 = 0x1b;
      if (uVar6 < 0x60) goto LAB_100217e5;
    }
    puVar12 = &DAT_100458a0;
    bVar7 = 0x1b;
    if ((bVar2 & 0xc) == 4) goto LAB_100217e5;
  }
  bVar7 = 0x1e;
LAB_100217e5:
  puVar15 = &DAT_10047600;
  *(byte *)(param_1 + 0xc0) = bVar7;
  if (bVar7 < bVar9) {
    bVar9 = bVar7;
  }
  iVar10 = 0;
  puVar12 = puVar12 + 1;
  *(byte *)((int)param_1 + 0x301) = bVar9;
  local_10 = (float *)((int)param_1 + 0x303);
  local_14 = 0;
  do {
    if (iVar10 == local_14) {
      local_14 = local_14 + (uint)(byte)puVar12[1];
      puVar15 = &DAT_10047600 + (byte)puVar12[-1];
      puVar12 = puVar12 + 3;
    }
    iVar5 = FUN_100214f0();
    uVar4 = puVar15[iVar5];
    *(undefined1 *)((int)local_10 + -1) = uVar4;
    bVar7 = *(byte *)((int)param_1 + 0x301);
    if (iVar10 < (int)(uint)bVar7) {
      iVar5 = FUN_100214f0();
      uVar4 = puVar15[iVar5];
      bVar7 = *(byte *)((int)param_1 + 0x301);
    }
    if (bVar7 == 0) {
      uVar4 = 0;
    }
    iVar10 = iVar10 + 1;
    *(undefined1 *)local_10 = uVar4;
    local_10 = (float *)((int)local_10 + 2);
    bVar7 = *(byte *)(param_1 + 0xc0);
  } while (iVar10 < (int)(uint)bVar7);
  if (bVar7 != 0) {
    puVar13 = (undefined1 *)((int)param_1 + 0x342);
    do {
      if (puVar13[-0x40] == '\0') {
        uVar4 = 6;
      }
      else if ((*(byte *)(in_ECX + 1) & 6) == 6) {
        uVar4 = 2;
      }
      else {
        uVar4 = FUN_100214f0();
      }
      *puVar13 = uVar4;
      puVar13 = puVar13 + 1;
      bVar7 = *(byte *)(param_1 + 0xc0);
    } while ((int)(puVar13 + (-0x342 - (int)param_1)) < (int)((uint)bVar7 * 2));
  }
  pbVar16 = (byte *)((int)param_1 + 0x302);
  local_c = 0;
  local_10 = param_1;
  if (bVar7 != 0) {
    do {
      bVar9 = *pbVar16;
      fVar18 = 0.0;
      pbVar16 = pbVar16 + 1;
      if (bVar9 == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = (0x13 >> (*(byte *)((int)param_1 + local_c + 0x342) & 0x1f) & 3U) + 4;
      }
      uVar11 = 4;
      do {
        if ((uVar6 & uVar11) != 0) {
          uVar17 = 0;
          uVar3 = in_EDX[1];
          pbVar8 = (byte *)(((int)uVar3 >> 3) + *in_EDX);
          in_EDX[1] = uVar3 + 6;
          if (in_EDX[2] < (int)(uVar3 + 6)) {
            uVar17 = 0;
          }
          else {
            uVar14 = 0xff >> (sbyte)(uVar3 & 7) & (uint)*pbVar8;
            for (iVar10 = (uVar3 & 7) - 2; 0 < iVar10; iVar10 = iVar10 + -8) {
              pbVar8 = pbVar8 + 1;
              uVar17 = uVar17 | uVar14 << ((byte)iVar10 & 0x1f);
              uVar14 = (uint)*pbVar8;
            }
            uVar17 = uVar14 >> (-(byte)iVar10 & 0x1f) | uVar17;
          }
          fVar18 = (float)(0x200000 >> ((byte)((int)uVar17 / 3) & 0x1f)) *
                   *(float *)(&DAT_10045ad0 +
                             (uVar17 + (((uint)bVar9 - (int)uVar17 / 3) + -2) * 3) * 4);
        }
        *local_10 = fVar18;
        local_10 = local_10 + 1;
        uVar11 = (int)uVar11 >> 1;
      } while (uVar11 != 0);
      local_c = local_c + 1;
    } while (local_c < (int)((uint)bVar7 * 2));
    bVar7 = *(byte *)(param_1 + 0xc0);
  }
  uVar6 = (uint)*(byte *)((int)param_1 + 0x301);
  if (uVar6 < bVar7) {
    puVar13 = (undefined1 *)(uVar6 * 2 + 0x303 + (int)param_1);
    do {
      *puVar13 = 0;
      puVar13 = puVar13 + 2;
      uVar6 = uVar6 + 1;
    } while ((int)uVar6 < (int)(uint)*(byte *)(param_1 + 0xc0));
  }
  return;
}

