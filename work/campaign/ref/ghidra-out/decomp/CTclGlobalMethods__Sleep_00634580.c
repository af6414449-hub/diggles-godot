
undefined4
CTclGlobalMethods__Sleep(undefined4 param_1,undefined4 param_2,DWORD param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  DWORD DVar7;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070b7cd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6ed0) &&
     (FUN_006cebf4(&DAT_00ca6ed0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6ed0 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6ed4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::Sleep()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6ed0);
  }
  iVar3 = DAT_00ca6ed4;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6ed4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar6 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  DVar7 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)DVar7 < 2) {
    FUN_006bc8f0(1);
    uVar5 = 1;
  }
  else {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar4 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar4 = local_20 + 1;
    }
    piVar1 = (int *)*puVar4;
    if (piVar1 == (int *)0x0) {
      Sleep(0);
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar2 = Tcl_GetIntFromObj(0,piVar1,&param_3);
      DVar7 = param_3;
      if (iVar2 == 1) {
        DVar7 = 0;
      }
      Sleep(DVar7);
      *piVar1 = *piVar1 + -1;
      uVar5 = 0;
      if (0 < *piVar1) goto LAB_006346ea;
      TclFreeObj(piVar1);
    }
    uVar5 = 0;
  }
LAB_006346ea:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

