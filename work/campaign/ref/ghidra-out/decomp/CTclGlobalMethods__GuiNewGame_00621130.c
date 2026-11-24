
undefined4
CTclGlobalMethods__GuiNewGame(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070b9f5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c48) &&
     (FUN_006cebf4(&DAT_00ca6c48,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6c48 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6c4c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::GuiNewGame()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c48);
  }
  iVar4 = DAT_00ca6c4c;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c4c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar7 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  iVar2 = param_3;
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  if (iVar2 == 2) {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_20 + 1;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
      iVar3 = Tcl_GetBooleanFromObj(0,piVar1,&param_3);
      bVar6 = param_3 != 0;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
      iVar4 = DAT_00772400;
      if (iVar3 != 1 && bVar6) {
        DAT_0076a328 = 1;
        *(undefined1 *)(DAT_00772400 + 0x8f) = 0;
        *(undefined1 *)(iVar4 + 0x88) = 1;
        *(undefined1 *)(iVar4 + 0x8b) = 0;
      }
    }
  }
  FUN_004e4550();
  uVar8 = 0;
  FUN_00501450(0);
  FUN_00504260(uVar8);
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

