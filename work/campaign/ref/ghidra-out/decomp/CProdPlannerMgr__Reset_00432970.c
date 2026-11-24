
void CProdPlannerMgr__Reset(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9d4d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c6718c) {
    FUN_006cebf4(&DAT_00c6718c,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00c6718c == -1) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00c67190 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) = "CProdPlannerMgr::Reset()";
      *(int *)(&DAT_00773650 + iVar3) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00c6718c);
    }
  }
  iVar3 = DAT_00c67190;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00c67190 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar4 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar4;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  iVar2 = 8;
  do {
    FUN_004335a0();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

