
undefined4
CTclGlobalMethods__ClassInfo(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  undefined8 uVar8;
  int local_30;
  int *local_20;
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
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e70) &&
     (FUN_006cebf4(&DAT_00ca6e70,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca6e70 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6e74 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::ClassInfo()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e70);
  }
  iVar3 = DAT_00ca6e74;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e74 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar8 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar5 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)uVar5 < 2) {
    FUN_006bc8f0(1);
    uVar4 = 1;
    goto LAB_00631ec4;
  }
  if (local_18 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    piVar2 = local_20;
    if (local_1c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar2 = local_20 + 1;
  }
  if ((*piVar2 == 0) || (iVar1 = Tcl_GetIntFromObj(0,*piVar2,&param_3), iVar1 == 1)) {
    uVar5 = 0;
LAB_00631e17:
    iVar1 = DAT_00772478;
    if (*(uint *)(DAT_00772478 + 0x801c) <= uVar5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar1 = *(int *)(*(int *)(iVar1 + 0x8018) + uVar5 * 4);
    if (iVar1 == 0) {
      piVar2 = (int *)Tcl_NewStringObj(&PTR_0071ce50,0xffffffff);
      *piVar2 = *piVar2 + 1;
      iVar1 = *piVar2;
      if (local_30 == 0) goto LAB_00631e0b;
      Tcl_SetObjResult(local_30,piVar2);
      iVar1 = *piVar2 + -1;
      *piVar2 = iVar1;
      bVar7 = iVar1 < 0;
      bVar6 = iVar1 == 0;
      goto LAB_00631eb6;
    }
    iVar1 = *(int *)(iVar1 + 0xc) + 0xc;
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)Tcl_NewStringObj(iVar1,0xffffffff);
      *piVar2 = *piVar2 + 1;
    }
    if (local_30 == 0) {
      if (piVar2 != (int *)0x0) {
LAB_00631eb1:
        *piVar2 = *piVar2 + -1;
        bVar7 = *piVar2 < 0;
        bVar6 = *piVar2 == 0;
        goto LAB_00631eb6;
      }
    }
    else {
      if (piVar2 != (int *)0x0) {
        Tcl_SetObjResult(local_30,piVar2);
        goto LAB_00631eb1;
      }
      Tcl_ResetResult(local_30);
    }
  }
  else {
    uVar5 = param_3;
    if (-1 < (int)param_3) goto LAB_00631e17;
    piVar2 = (int *)Tcl_NewStringObj(&PTR_0071ce50,0xffffffff);
    *piVar2 = *piVar2 + 1;
    iVar1 = *piVar2;
    if (local_30 != 0) {
      Tcl_SetObjResult(local_30,piVar2);
      iVar1 = *piVar2;
    }
LAB_00631e0b:
    iVar1 = iVar1 + -1;
    *piVar2 = iVar1;
    bVar7 = iVar1 < 0;
    bVar6 = iVar1 == 0;
LAB_00631eb6:
    if (bVar6 || bVar7) {
      TclFreeObj(piVar2);
    }
  }
  uVar4 = 0;
LAB_00631ec4:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

