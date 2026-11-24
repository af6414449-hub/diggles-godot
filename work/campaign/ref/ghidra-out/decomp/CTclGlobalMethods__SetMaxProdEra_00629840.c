
undefined4
CTclGlobalMethods__SetMaxProdEra
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  int local_38;
  int *local_28;
  uint local_24;
  int local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c3dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d40) &&
     (FUN_006cebf4(&DAT_00ca6d40,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca6d40 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca6d44 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclGlobalMethods::SetMaxProdEra()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d40);
  }
  iVar3 = DAT_00ca6d44;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d44 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
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
  uVar5 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (uVar5 == 3) {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar2 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar2 = local_28 + 1;
    }
    if (*piVar2 == 0) {
      uVar5 = 0;
    }
    else {
      iVar1 = Tcl_GetIntFromObj(0,*piVar2,&param_3);
      uVar5 = -(uint)(iVar1 != 1) & param_3;
    }
    if (local_20 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar2 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar2 = local_28 + 2;
    }
    if (*piVar2 == 0) {
      local_14 = 0;
    }
    else {
      iVar1 = Tcl_GetIntFromObj(0,*piVar2,&local_14);
      local_14 = -(uint)(iVar1 != 1) & local_14;
    }
    iVar1 = DAT_00772400;
    if (uVar5 < 9) {
      if ((int)uVar5 < 8) {
        *(uint *)(DAT_00772400 + 0x9c + uVar5 * 4) = local_14;
        puVar6 = (undefined4 *)(iVar1 + (uVar5 + 0x27) * 4);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        iVar3 = DAT_00772400;
        *(uint *)(iVar1 + 0x9c) = local_14;
        puVar6 = (undefined4 *)(iVar3 + 0x9c);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar2 = (int *)Tcl_NewIntObj(*puVar6);
      *piVar2 = *piVar2 + 1;
      iVar1 = *piVar2;
      if (local_38 != 0) {
        Tcl_SetObjResult(local_38,piVar2);
        iVar1 = *piVar2;
      }
      *piVar2 = iVar1 + -1;
      if (iVar1 + -1 < 1) {
        TclFreeObj(piVar2);
      }
      uVar4 = 0;
      goto LAB_00629ad2;
    }
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar2 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar2 = local_28 + 1;
    }
    piVar2 = (int *)*piVar2;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    FUN_006bc6a0("invalid player",piVar2);
  }
  else {
    FUN_006bc8f0(2);
  }
  uVar4 = 1;
LAB_00629ad2:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_28 != (int *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

