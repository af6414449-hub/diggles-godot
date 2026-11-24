
undefined4
CTclGlobalMethods__LoadDone(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c80) &&
     (FUN_006cebf4(&DAT_00ca6c80), iVar3 = DAT_00783650, DAT_00ca6c80 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6c84 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::LoadDone()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c80);
  }
  iVar4 = DAT_00ca6c84;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c84 * 0x40);
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
  if (param_3 < 2) {
    DAT_00767974 = 1;
  }
  else {
    piVar2 = *(int **)(param_4 + 4);
    if (piVar2 == (int *)0x0) {
      DAT_00767974 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetBooleanFromObj(0,piVar2,&param_3);
      DAT_00767974 = iVar3 != 1 && param_3 != 0;
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
  }
  FUN_0043fd30();
  return 0;
}

