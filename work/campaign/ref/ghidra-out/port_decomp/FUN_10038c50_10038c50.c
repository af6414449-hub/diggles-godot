
undefined4 FUN_10038c50(void)

{
  byte *pbVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int in_ECX;
  char *pcVar13;
  int iVar14;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if ((*(char *)(in_ECX + 0x56d) != '\0') && (*(char *)(in_ECX + 0x3c) == '\0')) {
    if (*(int *)(in_ECX + 0x2c) == 0) {
      iVar4 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x14))();
      iVar4 = iVar4 - *(int *)(in_ECX + 0x24);
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x30);
    }
    *(int *)(in_ECX + 0x44) = iVar4 + -4;
  }
  cVar2 = FUN_10038a40();
  if (cVar2 != '\0') {
    *(undefined4 *)(in_ECX + 0x70) = 0x1f;
    return 0;
  }
  uVar3 = FUN_10038a40();
  *(undefined1 *)(in_ECX + 0x56b) = uVar3;
  uVar5 = FUN_10038a40();
  uVar6 = FUN_10038a40();
  uVar7 = FUN_10038a40();
  iVar4 = FUN_10038a40();
  iVar4 = iVar4 * 0x1000000 + (uVar5 & 0xff) + (uVar6 & 0xff) * 0x100 + (uVar7 & 0xff) * 0x10000;
  uVar5 = FUN_10038a40();
  uVar6 = FUN_10038a40();
  uVar7 = FUN_10038a40();
  iVar8 = FUN_10038a40();
  FUN_10038a40();
  FUN_10038a40();
  FUN_10038a40();
  FUN_10038a40();
  uVar9 = FUN_10038a40();
  uVar10 = FUN_10038a40();
  uVar11 = FUN_10038a40();
  iVar12 = FUN_10038a40();
  *(uint *)(in_ECX + 0x464) =
       iVar12 * 0x1000000 + (uVar9 & 0xff) + (uVar10 & 0xff) * 0x100 + (uVar11 & 0xff) * 0x10000;
  FUN_10038a40();
  FUN_10038a40();
  FUN_10038a40();
  FUN_10038a40();
  uVar9 = FUN_10038a40();
  *(uint *)(in_ECX + 0x468) = uVar9 & 0xff;
  iVar12 = FUN_10038b20(uVar9 & 0xff);
  if (iVar12 == 0) {
    *(undefined4 *)(in_ECX + 0x70) = 10;
    return 0;
  }
  *(undefined4 *)(in_ECX + 0x588) = 0xfffffffe;
  if (((iVar4 != -1) ||
      (iVar8 * 0x1000000 + (uVar5 & 0xff) + (uVar6 & 0xff) * 0x100 + (uVar7 & 0xff) * 0x10000 != -1)
      ) && (iVar8 = *(int *)(in_ECX + 0x468) + -1, -1 < iVar8)) {
    pcVar13 = (char *)(in_ECX + 0x46c + iVar8);
    do {
      if (*pcVar13 != -1) {
        *(int *)(in_ECX + 0x588) = iVar8;
        *(int *)(in_ECX + 0x58c) = iVar4;
        break;
      }
      pcVar13 = pcVar13 + -1;
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
  }
  if (*(char *)(in_ECX + 0x56d) != '\0') {
    iVar8 = *(int *)(in_ECX + 0x468);
    iVar14 = 0;
    iVar12 = 0;
    if (0 < iVar8) {
      do {
        pbVar1 = (byte *)(in_ECX + 0x46c + iVar12);
        iVar12 = iVar12 + 1;
        iVar14 = iVar14 + (uint)*pbVar1;
      } while (iVar12 < iVar8);
    }
    *(int *)(in_ECX + 0x48) = *(int *)(in_ECX + 0x44) + 0x1b + iVar8 + iVar14;
    *(int *)(in_ECX + 0x4c) = iVar4;
  }
  *(undefined4 *)(in_ECX + 0x570) = 0;
  return 1;
}

