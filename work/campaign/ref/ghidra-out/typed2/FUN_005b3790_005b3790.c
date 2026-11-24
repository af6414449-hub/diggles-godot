
/* WARNING: Removing unreachable block (ram,0x005b3902) */

void FUN_005b3790(void)

{
  int iVar1;
  CMap *pCVar2;
  uint uVar3;
  int iVar4;
  int *in_ECX;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar4 = DAT_00772400;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070764d;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(DAT_00772400 + 0xa098) != '\0') {
    *(undefined1 *)(DAT_00772400 + 0xa098) = 0;
  }
  pCVar2 = PTR_0077241c;
  iVar1 = DAT_0076a338;
  *(undefined1 *)(iVar4 + 0x3d3) = 1;
  *(undefined1 *)(iVar1 + 0x2840) = 0;
  pCVar2->mapFlags = 0x100;
  *(undefined1 *)(iVar1 + 0x2839) = 1;
  local_14 = in_ECX;
  FUN_0055a060(uVar3);
  FUN_0055b510();
  if (DAT_00772dd0 == 0) {
    FUN_006bb140();
  }
  else {
    FUN_006bbb00(&local_14,in_ECX,extraout_ECX);
  }
  local_8 = 0;
  FUN_00479c10(0,1);
  iVar4 = DAT_00772400;
  *(undefined1 *)(DAT_00772400 + 0x8f) = 1;
  *(undefined1 *)(iVar4 + 0x8c) = 0;
  *(undefined1 *)(iVar4 + 0x598) = 0;
  if ((*(double *)(iVar4 + 0xa090) != 1.0) &&
     (*(undefined8 *)(iVar4 + 0xa090) = 0x3ff0000000000000, *(char *)(iVar4 + 0xa098) != '\0')) {
    *(undefined1 *)(iVar4 + 0xa098) = 1;
  }
  FUN_005f8080();
  FUN_005fa7c0();
  FUN_004d1090();
  FUN_004d1d90(0);
  FUN_0047de40(0);
  FUN_0054eb50(&local_14);
  FUN_00479c10(0,1);
  iVar4 = *(int *)(DAT_0076a338 + 0xfd);
  if (iVar4 < 0) {
    FUN_0047df80(-iVar4);
  }
  else if (0 < iVar4) {
    *(int *)(DAT_0076a338 + 0xfd) = *(int *)(DAT_0076a338 + 0xfd) - iVar4;
  }
  iVar4 = FUN_00501450();
  if (*(int *)(iVar4 + 0x81a8) != 0) {
    FUN_00504260(0);
  }
  *(undefined1 *)(DAT_00772400 + 0x8d) = 0;
  FUN_005b28d0();
  FUN_0054a900(extraout_ECX_00);
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
    TclFreeObj(local_14);
  }
  ExceptionList = local_10;
  return;
}

