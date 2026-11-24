
undefined4 CTclGlobalMethods__GetIngameLoading(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined8 uVar5;
  int local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c32d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca72d0) {
    FUN_006cebf4(&DAT_00ca72d0,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca72d0 == -1) {
      iVar4 = DAT_00783650 * 0x40;
      DAT_00ca72d4 = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::GetIngameLoading()";
      *(int *)(&DAT_00773650 + iVar4) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca72d0);
    }
  }
  iVar4 = DAT_00ca72d4;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca72d4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar5 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar3 = (int *)Tcl_NewBooleanObj(*(undefined1 *)(DAT_0077244c + 0x43c));
  *piVar3 = *piVar3 + 1;
  iVar2 = *piVar3;
  if (local_24 != 0) {
    Tcl_SetObjResult(local_24,piVar3);
    iVar2 = *piVar3;
  }
  *piVar3 = iVar2 + -1;
  if (iVar2 + -1 < 1) {
    TclFreeObj(piVar3);
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

