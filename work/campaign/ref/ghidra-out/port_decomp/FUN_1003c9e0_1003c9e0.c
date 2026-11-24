
undefined4 FUN_1003c9e0(void)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  bool bVar7;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar2 = *(int *)(in_ECX + 0x570);
  bVar7 = true;
  pbVar3 = *(byte **)(in_ECX + 0x2c);
  if (iVar2 != -1) {
    bVar7 = iVar2 == *(int *)(in_ECX + 0x468);
    if (iVar2 < *(int *)(in_ECX + 0x468)) {
      pbVar5 = (byte *)(in_ECX + 0x46c + iVar2);
      do {
        pbVar3 = pbVar3 + *pbVar5;
        if (*pbVar5 != 0xff) goto LAB_1003ca3e;
        iVar2 = iVar2 + 1;
        pbVar5 = pbVar5 + 1;
        bVar7 = iVar2 == *(int *)(in_ECX + 0x468);
      } while (iVar2 < *(int *)(in_ECX + 0x468));
    }
    if (bVar7) {
      iVar2 = -1;
    }
LAB_1003ca3e:
    if (*(byte **)(in_ECX + 0x34) < pbVar3) goto LAB_1003cb01;
    bVar7 = false;
    if (iVar2 != -1) {
      return 1;
    }
  }
  pbVar5 = *(byte **)(in_ECX + 0x34);
  while (pbVar3 + 0x1a < pbVar5) {
    if ((*(int *)pbVar3 != s_OggSvorbis_100501b8._0_4_) || (pbVar3[4] != 0)) {
LAB_1003ca8e:
      *(undefined4 *)(in_ECX + 0x70) = 0x15;
      return 0;
    }
    if (bVar7) {
      if ((*(int *)(in_ECX + 0x3ec) != 0) && ((pbVar3[5] & 1) != 0)) goto LAB_1003ca8e;
    }
    else if ((pbVar3[5] & 1) == 0) goto LAB_1003ca8e;
    uVar6 = (uint)pbVar3[0x1a];
    pbVar4 = pbVar3 + uVar6 + 0x1b;
    if (pbVar5 < pbVar4) break;
    uVar1 = 0;
    if (uVar6 != 0) {
      do {
        pbVar4 = pbVar4 + pbVar3[uVar1 + 0x1b];
        if (pbVar3[uVar1 + 0x1b] != 0xff) goto LAB_1003cadb;
        uVar1 = uVar1 + 1;
      } while ((int)uVar1 < (int)uVar6);
    }
    if (uVar1 == uVar6) {
      uVar1 = 0xffffffff;
    }
LAB_1003cadb:
    if (pbVar5 < pbVar4) break;
    bVar7 = false;
    pbVar3 = pbVar4;
    if (uVar1 != 0xffffffff) {
      return 1;
    }
  }
LAB_1003cb01:
  *(undefined4 *)(in_ECX + 0x70) = 1;
  return 0;
}

