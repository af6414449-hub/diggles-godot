
void FUN_10022250(undefined4 param_1,int param_2,int param_3,int param_4)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  int iVar7;
  sbyte sVar8;
  byte bVar9;
  int in_ECX;
  int iVar10;
  uint uVar11;
  undefined *puVar12;
  byte *pbVar13;
  uint uVar14;
  float fVar15;
  float fVar16;
  int local_40;
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  byte local_30 [11];
  char local_25;
  char local_24;
  char local_23;
  char local_22;
  char local_21;
  char local_20;
  char local_1f;
  char local_1e;
  char local_1d;
  char local_1c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  iVar10 = 0;
  uVar14 = (uint)*(byte *)(param_2 + 0x1b);
  if (*(char *)(param_2 + 0xe) != '\0') {
    iVar10 = 0x1c;
  }
  iVar7 = 0;
  if (*(char *)(param_2 + 0xd) == '\0') {
    iVar7 = 0x1c;
  }
  bVar6 = *(char *)(param_2 + 0x19) + 1;
  puVar12 = &UNK_100470a0 + iVar10 + iVar7;
  if ((*(byte *)(in_ECX + 1) & 8) == 0) {
    if (((*(byte *)(in_ECX + 3) & 0x10) == 0) || (param_4 == 0)) {
      local_40 = 0;
      sVar8 = 0;
    }
    else {
      local_40 = 0xc;
      sVar8 = 1;
    }
    pbVar13 = &DAT_10045bb1 + local_40;
    uVar14 = (uint)(*(ushort *)(param_2 + 8) >> sVar8);
    do {
      uVar11 = (uint)pbVar13[2];
      local_31 = (byte)((int)uVar14 % (int)uVar11);
      iVar10 = pbVar13[1] * uVar11;
      local_32 = (byte)(((int)uVar14 / (int)uVar11) % (int)(uint)pbVar13[1]);
      iVar7 = (uint)*pbVar13 * iVar10;
      local_33 = (byte)(((int)uVar14 / iVar10) % (int)(uint)*pbVar13);
      pbVar1 = pbVar13 + -1;
      pbVar13 = pbVar13 + 4;
      local_40 = local_40 + 4;
      local_34 = (byte)(((int)uVar14 / iVar7) % (int)(uint)*pbVar1);
      uVar14 = uVar14 - (uint)*pbVar1 * iVar7;
    } while (-1 < (int)uVar14);
    uVar14 = 0xfffffff0;
    puVar12 = puVar12 + local_40;
  }
  else {
    local_34 = (byte)(&DAT_100476f0)[*(ushort *)(param_2 + 8)] >> 2;
    local_32 = (&DAT_100476f0)[*(ushort *)(param_2 + 8)] & 3;
    local_33 = local_34;
    local_31 = local_32;
  }
  FUN_10022080(&local_34,puVar12,param_1,uVar14);
  bVar2 = *(byte *)(param_2 + 0xe);
  if (bVar2 == 0) {
    if (*(char *)(param_2 + 0x18) != '\0') {
      local_25 = local_25 + '\x01';
      local_24 = local_24 + '\x01';
      local_23 = local_23 + '\x01';
      local_22 = local_22 + '\x01';
      local_21 = local_21 + '\x02';
      local_20 = local_20 + '\x02';
      local_1f = local_1f + '\x03';
      local_1e = local_1e + '\x03';
      local_1d = local_1d + '\x03';
      local_1c = local_1c + '\x02';
    }
  }
  else {
    bVar9 = 3 - bVar6;
    if (bVar2 != 0) {
      cVar3 = *(char *)(param_2 + 0x15);
      cVar4 = *(char *)(param_2 + 0x16);
      cVar5 = *(char *)(param_2 + 0x17);
      iVar10 = (bVar2 - 1) / 3 + 1;
      pbVar13 = local_30 + *(byte *)(param_2 + 0xd) + 1;
      do {
        pbVar13[-1] = pbVar13[-1] + (cVar3 << (bVar9 & 0x1f));
        *pbVar13 = *pbVar13 + (cVar4 << (bVar9 & 0x1f));
        pbVar13[1] = pbVar13[1] + (cVar5 << (bVar9 & 0x1f));
        iVar10 = iVar10 + -1;
        pbVar13 = pbVar13 + 3;
      } while (iVar10 != 0);
    }
  }
  iVar10 = 0;
  fVar16 = 2048.0;
  if ((*(byte *)(in_ECX + 3) & 0xe0) == 0x60) {
    iVar10 = 2;
  }
  uVar14 = (iVar10 - (uint)*(byte *)(param_2 + 10)) + 0x102;
  do {
    uVar11 = 0x78;
    if ((int)uVar14 < 0x78) {
      uVar11 = uVar14;
    }
    uVar14 = uVar14 - uVar11;
    fVar16 = fVar16 * (float)(0x40000000 >> ((byte)((int)uVar11 >> 2) & 0x1f)) *
                      (float)(&DAT_10045890)[uVar11 & 3];
  } while (0 < (int)uVar14);
  iVar10 = 0;
  if ((uint)bVar2 + (uint)*(byte *)(param_2 + 0xd) != 0) {
    do {
      uVar14 = (uint)local_30[iVar10] << (bVar6 & 0x1f);
      fVar15 = fVar16;
      do {
        uVar11 = 0x78;
        if ((int)uVar14 < 0x78) {
          uVar11 = uVar14;
        }
        uVar14 = uVar14 - uVar11;
        fVar15 = fVar15 * (float)(0x40000000 >> ((byte)((int)uVar11 >> 2) & 0x1f)) *
                          (float)(&DAT_10045890)[uVar11 & 3];
      } while (0 < (int)uVar14);
      *(float *)(param_3 + iVar10 * 4) = fVar15;
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)((uint)*(byte *)(param_2 + 0xe) + (uint)*(byte *)(param_2 + 0xd)));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

