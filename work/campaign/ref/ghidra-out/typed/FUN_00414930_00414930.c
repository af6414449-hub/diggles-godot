
undefined1 __thiscall FUN_00414930(CAct_Lore *this)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_006f9d4d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00c3caac) {
    FUN_006cebf4(&DAT_00c3caac,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar3 = DAT_00783650;
    if (DAT_00c3caac == -1) {
      iVar4 = DAT_00783650 * 0x40;
      DAT_00c3cab0 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar4) = "LORE-TICK";
      *(int *)(&DAT_00773650 + iVar4) = iVar3;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00c3caac);
    }
  }
  iVar4 = DAT_00c3cab0;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00c3cab0 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar5 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  uVar2 = CAct_Lore__SetLorePos(this);
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar2;
}

