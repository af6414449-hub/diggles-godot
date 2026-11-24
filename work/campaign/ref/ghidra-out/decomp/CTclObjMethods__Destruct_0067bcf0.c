
undefined4
CTclObjMethods__Destruct
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00709d75;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7580) &&
     (FUN_006cebf4(&DAT_00ca7580,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7580 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7584 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::Destruct";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7580);
  }
  iVar3 = DAT_00ca7584;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7584 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar5 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar5;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = FUN_005c71c0(param_4,2,1);
  if (iVar1 == 0) {
    uVar4 = 1;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0x3d0);
    if ((uVar2 & 1) != 0) {
      *(undefined1 *)(iVar1 + 0x3b4) = 1;
      FUN_005ca8b0();
      uVar2 = *(uint *)(iVar1 + 0x3d0);
    }
    *(uint *)(iVar1 + 0x3d0) = uVar2 & 0xfffffffe;
    if (DAT_0076a33c == (undefined4 *)0x0) {
      DAT_0076a33c = (undefined4 *)FUN_006ba810(0x1e2);
      if (DAT_0076a33c == (undefined4 *)0x0) {
        DAT_0076a33c = (undefined4 *)0x0;
      }
      else {
        *DAT_0076a33c = 0;
        DAT_0076a33c[1] = 0;
      }
    }
    FUN_004845a0(iVar1);
    uVar4 = 0;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

