
undefined4
CTclGlobalMethods__Poke(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  BOOL BVar4;
  int iVar5;
  undefined4 uVar6;
  byte *lp;
  undefined8 uVar7;
  int *local_24;
  uint local_20;
  int local_1c;
  byte local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a7dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c18) &&
     (FUN_006cebf4(&DAT_00ca6c18,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6c18 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6c1c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::Poke()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c18);
  }
  iVar5 = DAT_00ca6c1c;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c1c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (uVar1 == 3) {
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar3 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = local_24 + 1;
    }
    if (*piVar3 == 0) {
      lp = (byte *)0x0;
    }
    else {
      iVar2 = Tcl_GetIntFromObj(0,*piVar3,&param_3);
      lp = (byte *)(-(uint)(iVar2 != 1) & param_3);
    }
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
      local_14[0] = 0;
    }
    else {
      iVar2 = Tcl_GetIntFromObj(0,*piVar3,local_14);
      local_14[0] = -(iVar2 != 1) & local_14[0];
    }
    BVar4 = IsBadWritePtr(lp,4);
    if (BVar4 == 0) {
      *lp = local_14[0];
      uVar6 = 0;
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar3 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_20 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar3 = local_24 + 1;
      }
      piVar3 = (int *)*piVar3;
      if (piVar3 != (int *)0x0) {
        *piVar3 = *piVar3 + 1;
      }
      FUN_006bc6a0("access violation at",piVar3);
      uVar6 = 1;
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar6 = 1;
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
  return uVar6;
}

