
uint FUN_10021c00(int param_1)

{
  char cVar1;
  byte bVar2;
  undefined2 uVar3;
  int *in_ECX;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  int in_EDX;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  byte *pbVar11;
  uint local_1c;
  uint local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  uVar10 = 0;
  local_10 = 0;
  bVar2 = *(byte *)(param_1 + 1);
  local_8 = ((*(byte *)(param_1 + 3) & 0xc0) != 0xc0) + 1;
  iVar4 = ((bVar2 >> 4 & 1) + (bVar2 >> 3 & 1)) * 3 + (*(byte *)(param_1 + 2) >> 2 & 3);
  iVar4 = iVar4 - (uint)(iVar4 != 0);
  if ((bVar2 & 8) == 0) {
    local_1c = FUN_100214f0();
    local_1c = local_1c >> (sbyte)local_8;
  }
  else {
    local_8 = local_8 * 2;
    local_1c = FUN_100214f0();
    uVar10 = FUN_100214f0();
  }
  pcVar9 = (char *)(in_EDX + 0xb);
  do {
    uVar5 = in_ECX[1];
    local_c = uVar10 << 4;
    if ((*(byte *)(param_1 + 3) & 0xc0) != 0xc0) {
      local_c = uVar10;
    }
    pbVar11 = (byte *)(((int)uVar5 >> 3) + *in_ECX);
    in_ECX[1] = uVar5 + 0xc;
    if (in_ECX[2] < (int)(uVar5 + 0xc)) {
      uVar10 = 0;
    }
    else {
      uVar8 = 0xff >> (sbyte)(uVar5 & 7) & (uint)*pbVar11;
      uVar10 = 0;
      iVar6 = (uVar5 & 7) + 4;
      do {
        pbVar11 = pbVar11 + 1;
        uVar10 = uVar10 | uVar8 << ((byte)iVar6 & 0x1f);
        iVar6 = iVar6 + -8;
        uVar8 = (uint)*pbVar11;
      } while (0 < iVar6);
      uVar10 = *pbVar11 >> (-(char)iVar6 & 0x1fU) | uVar10;
    }
    local_10 = local_10 + (uVar10 & 0xffff);
    *(short *)(pcVar9 + -7) = (short)uVar10;
    uVar10 = in_ECX[1];
    pbVar11 = (byte *)(((int)uVar10 >> 3) + *in_ECX);
    in_ECX[1] = uVar10 + 9;
    if (in_ECX[2] < (int)(uVar10 + 9)) {
      uVar7 = 0;
    }
    else {
      uVar8 = 0xff >> (sbyte)(uVar10 & 7) & (uint)*pbVar11;
      uVar5 = 0;
      iVar6 = (uVar10 & 7) + 1;
      do {
        pbVar11 = pbVar11 + 1;
        uVar5 = uVar5 | uVar8 << ((byte)iVar6 & 0x1f);
        iVar6 = iVar6 + -8;
        uVar8 = (uint)*pbVar11;
      } while (0 < iVar6);
      uVar7 = (ushort)(*pbVar11 >> (-(char)iVar6 & 0x1fU)) | (ushort)uVar5;
    }
    *(ushort *)(pcVar9 + -5) = uVar7;
    if (0x120 < uVar7) {
      return 0xffffffff;
    }
    uVar10 = in_ECX[1];
    pbVar11 = (byte *)(((int)uVar10 >> 3) + *in_ECX);
    uVar5 = uVar10 & 7;
    in_ECX[1] = uVar10 + 8;
    if (in_ECX[2] < (int)(uVar10 + 8)) {
      bVar2 = 0;
    }
    else {
      uVar8 = 0xff >> (sbyte)uVar5 & (uint)*pbVar11;
      uVar10 = 0;
      bVar2 = 0;
      if (uVar5 != 0) {
        do {
          pbVar11 = pbVar11 + 1;
          uVar10 = uVar10 | uVar8 << ((byte)uVar5 & 0x1f);
          bVar2 = (byte)uVar10;
          uVar5 = uVar5 - 8;
          uVar8 = (uint)*pbVar11;
        } while (0 < (int)uVar5);
      }
      bVar2 = (byte)(uVar8 >> (-(char)uVar5 & 0x1fU)) | bVar2;
    }
    pcVar9[-1] = bVar2;
    uVar3 = FUN_100214f0();
    *(undefined2 *)(pcVar9 + -3) = uVar3;
    pcVar9[2] = '\x16';
    pcVar9[3] = '\0';
    *(undefined **)(pcVar9 + -0xb) = &DAT_10047548 + iVar4 * 0x17;
    uVar10 = in_ECX[1];
    pbVar11 = (byte *)(((int)uVar10 >> 3) + *in_ECX);
    in_ECX[1] = uVar10 + 1;
    if (in_ECX[2] < (int)(uVar10 + 1)) {
LAB_10021f10:
      pcVar9[0] = '\0';
      pcVar9[1] = '\0';
      local_14 = FUN_100214f0();
      cVar1 = FUN_100214f0();
      pcVar9[7] = cVar1;
      cVar1 = FUN_100214f0();
      pcVar9[8] = cVar1;
      pcVar9[9] = -1;
    }
    else {
      uVar8 = 0xff >> (sbyte)(uVar10 & 7) & (uint)*pbVar11;
      uVar5 = 0;
      for (iVar6 = (uVar10 & 7) - 7; 0 < iVar6; iVar6 = iVar6 + -8) {
        pbVar11 = pbVar11 + 1;
        uVar5 = uVar5 | uVar8 << ((byte)iVar6 & 0x1f);
        uVar8 = (uint)*pbVar11;
      }
      if (uVar8 >> (-(byte)iVar6 & 0x1f) == 0 && uVar5 == 0) goto LAB_10021f10;
      cVar1 = FUN_100214f0();
      *pcVar9 = cVar1;
      if (cVar1 == '\0') {
        return 0xffffffff;
      }
      cVar1 = FUN_100214f0();
      pcVar9[1] = cVar1;
      pcVar9[7] = '\a';
      pcVar9[8] = -1;
      if (*pcVar9 == '\x02') {
        local_c = local_c & 0xf0f;
        if (cVar1 == '\0') {
          pcVar9[7] = '\b';
          *(undefined **)(pcVar9 + -0xb) = &DAT_10045bd0 + iVar4 * 0x28;
          pcVar9[2] = '\0';
          pcVar9[3] = '\'';
        }
        else {
          *(undefined **)(pcVar9 + -0xb) = &DAT_10046ef0 + iVar4 * 0x28;
          bVar2 = *(byte *)(param_1 + 1);
          pcVar9[3] = '\x1e';
          pcVar9[2] = ((bVar2 & 8) != 0) * '\x02' + '\x06';
        }
      }
      iVar6 = FUN_100214f0();
      local_14 = iVar6 << 5;
      cVar1 = FUN_100214f0();
      pcVar9[10] = cVar1;
      cVar1 = FUN_100214f0();
      pcVar9[0xb] = cVar1;
      cVar1 = FUN_100214f0();
      pcVar9[0xc] = cVar1;
    }
    pcVar9[4] = (char)(local_14 >> 10);
    pcVar9[6] = (byte)local_14 & 0x1f;
    pcVar9[5] = (byte)(local_14 >> 5) & 0x1f;
    if ((*(byte *)(param_1 + 1) & 8) == 0) {
      cVar1 = '\x01' - (*(ushort *)(pcVar9 + -3) < 500);
    }
    else {
      cVar1 = FUN_100214f0();
    }
    pcVar9[0xd] = cVar1;
    uVar10 = in_ECX[1];
    pbVar11 = (byte *)(((int)uVar10 >> 3) + *in_ECX);
    in_ECX[1] = uVar10 + 1;
    if (in_ECX[2] < (int)(uVar10 + 1)) {
      bVar2 = 0;
    }
    else {
      uVar8 = 0xff >> (sbyte)(uVar10 & 7) & (uint)*pbVar11;
      uVar5 = 0;
      bVar2 = 0;
      for (iVar6 = (uVar10 & 7) - 7; 0 < iVar6; iVar6 = iVar6 + -8) {
        pbVar11 = pbVar11 + 1;
        uVar5 = uVar5 | uVar8 << ((byte)iVar6 & 0x1f);
        bVar2 = (byte)uVar5;
        uVar8 = (uint)*pbVar11;
      }
      bVar2 = (byte)(uVar8 >> (-(byte)iVar6 & 0x1f)) | bVar2;
    }
    pcVar9[0xe] = bVar2;
    uVar5 = 0;
    bVar2 = 0;
    uVar10 = in_ECX[1];
    pbVar11 = (byte *)(((int)uVar10 >> 3) + *in_ECX);
    in_ECX[1] = uVar10 + 1;
    if (in_ECX[2] < (int)(uVar10 + 1)) {
      bVar2 = 0;
    }
    else {
      uVar8 = 0xff >> (sbyte)(uVar10 & 7) & (uint)*pbVar11;
      for (iVar6 = (uVar10 & 7) - 7; 0 < iVar6; iVar6 = iVar6 + -8) {
        pbVar11 = pbVar11 + 1;
        uVar5 = uVar5 | uVar8 << ((byte)iVar6 & 0x1f);
        bVar2 = (byte)uVar5;
        uVar8 = (uint)*pbVar11;
      }
      bVar2 = (byte)(uVar8 >> (-(byte)iVar6 & 0x1f)) | bVar2;
    }
    pcVar9[0xf] = bVar2;
    uVar10 = local_c << 4;
    pcVar9[0x10] = (byte)(local_c >> 0xc) & 0xf;
    pcVar9 = pcVar9 + 0x1c;
    local_8 = local_8 + -1;
    if (local_8 == 0) {
      if ((int)(in_ECX[2] + local_1c * 8) < in_ECX[1] + local_10) {
        return 0xffffffff;
      }
      return local_1c;
    }
  } while( true );
}

