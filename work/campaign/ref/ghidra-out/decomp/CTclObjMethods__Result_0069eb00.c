
void CTclObjMethods__Result(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 in_ECX;
  int *in_XMM1_Da;
  undefined8 uVar5;
  int local_28;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711fad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7b98) {
    FUN_006cebf4(&DAT_00ca7b98,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca7b98 == -1) {
      iVar4 = DAT_00783650 * 0x40;
      DAT_00ca7b9c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::Result()";
      *(int *)(&DAT_00773650 + iVar4) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7b98);
    }
  }
  iVar4 = DAT_00ca7b9c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7b9c * 0x40);
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
  FUN_006bc170(in_ECX);
  piVar3 = (int *)FUN_006bad90();
  if (local_28 != 0) {
    if (*piVar3 == 0) {
      Tcl_ResetResult(local_28);
    }
    else {
      Tcl_SetObjResult(local_28,*piVar3);
    }
  }
  if (in_XMM1_Da != (int *)0x0) {
    *in_XMM1_Da = *in_XMM1_Da + -1;
    if (*in_XMM1_Da < 1) {
      TclFreeObj(in_XMM1_Da);
    }
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return;
}

