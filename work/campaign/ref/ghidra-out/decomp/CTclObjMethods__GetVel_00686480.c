
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4
CTclObjMethods__GetVel(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int local_24;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00709d75;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca77a8) &&
     (FUN_006cebf4(&DAT_00ca77a8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca77a8 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca77ac = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::GetVel()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca77a8);
  }
  iVar3 = DAT_00ca77ac;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca77ac * 0x40);
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
    piVar2 = (int *)FUN_006badc0(iVar1 + 0x34);
    if (local_24 != 0) {
      if (*piVar2 == 0) {
        Tcl_ResetResult(local_24);
      }
      else {
        Tcl_SetObjResult(local_24,*piVar2);
      }
    }
    DAT_00ca77ac = DAT_00ca77ac + -1;
    if (DAT_00ca77ac < 1) {
      TclFreeObj(&DAT_00ca77ac);
    }
    uVar4 = 0;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

