
void FUN_0054df60(void)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  int in_ECX;
  char *pcVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  double dVar11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070467d;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (*(char *)(DAT_00772400 + 0x59d) == '\0') {
    return;
  }
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x24) == 0) goto LAB_0054e09c;
  iVar8 = *(int *)(in_ECX + 0x40);
  pcVar7 = "waitmap";
  bVar10 = false;
  pbVar5 = (byte *)(iVar8 + 0xc);
  do {
    bVar1 = *pbVar5;
    bVar9 = bVar1 < (byte)*pcVar7;
    if (bVar1 != *pcVar7) {
LAB_0054dfd6:
      uVar6 = -(uint)bVar9 | 1;
      goto LAB_0054dfdb;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar9 = bVar1 < ((byte *)pcVar7)[1];
    if (bVar1 != ((byte *)pcVar7)[1]) goto LAB_0054dfd6;
    pbVar5 = pbVar5 + 2;
    pcVar7 = (char *)((byte *)pcVar7 + 2);
  } while (bVar1 != 0);
  uVar6 = 0;
LAB_0054dfdb:
  if ((uVar6 == 0) && ((char)PTR_0077241c->mapFlags != '\0')) {
    bVar10 = true;
    FUN_0054efe0();
    iVar8 = *(int *)(in_ECX + 0x40);
  }
  pcVar7 = "waitplayer";
  pbVar5 = (byte *)(iVar8 + 0xc);
  do {
    bVar1 = *pbVar5;
    bVar9 = bVar1 < (byte)*pcVar7;
    if (bVar1 != *pcVar7) {
LAB_0054e030:
      uVar6 = -(uint)bVar9 | 1;
      goto LAB_0054e035;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar9 = bVar1 < ((byte *)pcVar7)[1];
    if (bVar1 != ((byte *)pcVar7)[1]) goto LAB_0054e030;
    pbVar5 = pbVar5 + 2;
    pcVar7 = (char *)((byte *)pcVar7 + 2);
  } while (bVar1 != 0);
  uVar6 = 0;
LAB_0054e035:
  if (uVar6 == 0) {
    dVar11 = 1.0;
    if ((*(double *)(in_ECX + 0x48) <= 1.0) || (*(char *)(DAT_00772400 + 0x3d7) != '\0')) {
      FUN_0054efe0();
    }
    else {
      FUN_0043e3c0(uVar4);
      if (dVar11 < *(double *)(in_ECX + 0x50)) goto LAB_0054e07c;
      FUN_0054efe0();
    }
LAB_0054e082:
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + -1;
    FUN_006b9200(&PTR_0071ce50);
  }
  else {
LAB_0054e07c:
    if (bVar10) goto LAB_0054e082;
  }
  if (*(int *)(in_ECX + 0x24) != 0) {
    ExceptionList = local_10;
    return;
  }
LAB_0054e09c:
  bVar10 = *(int *)(in_ECX + 0x38) != 0;
  if (bVar10) {
    if (!bVar10) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar2 = (int *)**(undefined4 **)(in_ECX + 0x34);
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8 = 0;
    FUN_005112c0(0);
    piVar3 = *(int **)(in_ECX + 0x1c);
    *(int **)(in_ECX + 0x1c) = piVar2;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*(int *)(in_ECX + 0x1c) + 8) = piVar2[2];
    if (*(char *)(in_ECX + 0x10) != '\0') {
      *piVar2 = *piVar2 + 1;
      FUN_0054dc90(piVar2);
      FUN_0054ddf0();
    }
    FUN_0054ec50();
    local_8 = 1;
    *piVar2 = *piVar2 + -1;
    if (*piVar2 == 0) {
      FUN_006ba940();
    }
  }
  ExceptionList = local_10;
  return;
}

