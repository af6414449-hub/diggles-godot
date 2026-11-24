
undefined4
CTclObjMethods__SetProdPack
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined8 uVar6;
  int local_34;
  int *local_24;
  uint local_20;
  int local_1c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a9ed;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7980) &&
     (FUN_006cebf4(&DAT_00ca7980,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7980 == -1)) {
    iVar2 = DAT_00783650 * 0x40;
    DAT_00ca7984 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar2) = "TCL:CTclObjMethods::SetProdPack()";
    *(int *)(&DAT_00773650 + iVar2) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7980);
  }
  iVar2 = DAT_00ca7984;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7984 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar2 * 0x10];
  if (iVar1 == 0) {
    uVar6 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar2 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar2 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar2 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,3,1);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x3e0) == 0)) {
    uVar4 = 1;
  }
  else {
    if (local_1c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_24 + 2;
    }
    if (*piVar3 == 0) {
      bVar5 = false;
    }
    else {
      iVar2 = Tcl_GetBooleanFromObj(0,*piVar3,&local_14);
      if (iVar2 == 1) {
        bVar5 = false;
      }
      else {
        bVar5 = local_14 != 0;
      }
    }
    *(bool *)(*(int *)(iVar1 + 0x3e0) + 0x29) = bVar5;
    piVar3 = (int *)Tcl_NewBooleanObj(*(undefined1 *)(*(int *)(iVar1 + 0x3e0) + 0x29));
    *piVar3 = *piVar3 + 1;
    iVar1 = *piVar3;
    if (local_34 != 0) {
      Tcl_SetObjResult(local_34,piVar3);
      iVar1 = *piVar3;
    }
    *piVar3 = iVar1 + -1;
    if (iVar1 + -1 < 1) {
      TclFreeObj(piVar3);
    }
    uVar4 = 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

