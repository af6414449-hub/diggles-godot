
undefined4
CTclGlobalMethods__SetIngameLoading
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  int local_30;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ccbd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca72c8) &&
     (FUN_006cebf4(&DAT_00ca72c8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca72c8 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca72cc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::SetIngameLoading()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca72c8);
  }
  iVar3 = DAT_00ca72cc;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca72cc * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar5;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar7 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  iVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (iVar1 == 2) {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_20 + 1;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 == (int *)0x0) {
      bVar4 = false;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar1 = Tcl_GetBooleanFromObj(0,piVar2,&param_3);
      bVar4 = iVar1 != 1 && param_3 != 0;
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    iVar3 = DAT_0077244c;
    iVar1 = DAT_00772400;
    if ((bool)*(char *)(DAT_00772400 + 0x91) != bVar4) {
      if (bVar4 == false) {
        *(undefined1 *)(DAT_0077244c + 0x43c) = 1;
        *(undefined4 *)(iVar3 + 0x438) = 0;
      }
      *(bool *)(iVar1 + 0x91) = bVar4;
    }
    piVar2 = (int *)Tcl_NewBooleanObj(bVar4);
    *piVar2 = *piVar2 + 1;
    iVar1 = *piVar2;
    if (local_30 != 0) {
      Tcl_SetObjResult(local_30,piVar2);
      iVar1 = *piVar2;
    }
    *piVar2 = iVar1 + -1;
    if (iVar1 + -1 < 1) {
      TclFreeObj(piVar2);
    }
    uVar5 = 0;
  }
  else {
    FUN_006bc8f0(1);
    uVar5 = 1;
  }
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

