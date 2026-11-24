
undefined4
CTclClassDefMethods__Obj_Exit(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a51d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6b20) &&
     (FUN_006cebf4(&DAT_00ca6b20,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6b20 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6b24 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclClassDefMethods::Obj_Exit()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6b20);
  }
  iVar3 = DAT_00ca6b24;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6b24 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar4;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar6 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar4 = 1;
  }
  else if (param_3 < 2) {
    FUN_006bc8f0(1);
    uVar4 = 1;
  }
  else {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_24 + 1;
    }
    piVar1 = (int *)*puVar5;
    local_14 = piVar1;
    if (piVar1 == (int *)0x0) {
      FUN_0042fce0(&local_14);
    }
    else {
      *piVar1 = *piVar1 + 1;
      FUN_0042fce0(&local_14);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 < 1) {
        TclFreeObj(piVar1);
      }
    }
    uVar4 = 0;
  }
  FUN_006bc0d0();
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

