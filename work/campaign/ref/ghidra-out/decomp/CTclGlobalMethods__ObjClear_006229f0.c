
undefined4 CTclGlobalMethods__ObjClear(void)

{
  undefined4 uVar1;
  int iVar2;
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
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c70) &&
     (FUN_006cebf4(&DAT_00ca6c70,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6c70 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6c74 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::ObjClear()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c70);
  }
  iVar4 = DAT_00ca6c74;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c74 * 0x40);
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
  if (DAT_0076a338 != 0) {
    *(undefined1 *)(DAT_0076a338 + 0x2839) = 1;
  }
  FUN_005d2920();
  iVar2 = DAT_0077244c;
  iVar4 = 0;
  if (0 < *(int *)(DAT_0077244c + 0x84ac)) {
    do {
      if (*(int *)(iVar2 + 0x84ac) == 0) {
        if (*(int *)(iVar2 + 0x84a8) < 1) {
LAB_00622ad2:
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        iVar3 = iVar4;
        if (iVar4 < 0) {
          iVar3 = 0;
        }
        iVar3 = iVar3 % *(int *)(iVar2 + 0x84ac);
        if ((iVar3 < 0) || (*(int *)(iVar2 + 0x84a8) <= iVar3)) goto LAB_00622ad2;
      }
      FUN_00564a60(0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(iVar2 + 0x84ac));
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

