
/* WARNING: Removing unreachable block (ram,0x0054035f) */

void FUN_005401f0(undefined4 param_1)

{
  CMap *pCVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  undefined4 extraout_ECX;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pCVar1 = PTR_0077241c;
  iVar3 = DAT_0076a338;
  local_8 = 0xffffffff;
  puStack_c = &LAB_007036dd;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined1 *)(in_ECX + 0x17) = 0;
  *(undefined1 *)(iVar3 + 0x2840) = 0;
  pCVar1->mapFlags = 0x100;
  *(undefined1 *)(iVar3 + 0x2839) = 1;
  local_14 = in_ECX;
  FUN_0055a060(uVar2);
  FUN_0055b510();
  if (DAT_00772dd0 == 0) {
    FUN_006bb140();
  }
  else {
    FUN_006bbb00(&local_14,param_1,extraout_ECX);
  }
  local_8 = 0;
  FUN_00479c10(0,1);
  iVar3 = DAT_00772400;
  *(undefined1 *)(DAT_00772400 + 0x8f) = 1;
  *(undefined1 *)(iVar3 + 0x8c) = 0;
  *(undefined1 *)(iVar3 + 0x598) = 0;
  if ((*(double *)(iVar3 + 0xa090) != 1.0) &&
     (*(undefined8 *)(iVar3 + 0xa090) = 0x3ff0000000000000, *(char *)(iVar3 + 0xa098) != '\0')) {
    *(undefined1 *)(iVar3 + 0xa098) = 1;
  }
  FUN_004d1090();
  FUN_004d1d90(0);
  FUN_0047de40(0);
  FUN_005f8080();
  FUN_005fa7c0();
  FUN_005b28d0();
  FUN_005b24c0();
  FUN_0054eb50(&local_14);
  FUN_00479c10(0,1);
  iVar3 = *(int *)(DAT_0076a338 + 0xfd);
  if (iVar3 < 0) {
    FUN_0047df80(-iVar3);
  }
  else if (0 < iVar3) {
    *(int *)(DAT_0076a338 + 0xfd) = *(int *)(DAT_0076a338 + 0xfd) - iVar3;
  }
  *(undefined1 *)((int)in_ECX + 0x2d) = 1;
  iVar3 = FUN_00501450();
  if ((*(int **)(iVar3 + 0x81a0) != (int *)0x0) && (*(int **)(iVar3 + 0x81a0) == in_ECX)) {
    iVar3 = FUN_00501450();
    *(undefined4 *)(iVar3 + 0x81a0) = 0;
  }
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
    TclFreeObj(local_14);
  }
  ExceptionList = local_10;
  return;
}

