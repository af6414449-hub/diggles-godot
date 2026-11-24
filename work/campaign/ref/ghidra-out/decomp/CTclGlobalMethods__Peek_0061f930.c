
undefined4
CTclGlobalMethods__Peek(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  BOOL BVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  char *lp;
  undefined8 uVar7;
  int local_30;
  int *local_20;
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
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c20) &&
     (FUN_006cebf4(&DAT_00ca6c20,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6c20 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6c24 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::Peek()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c20);
  }
  iVar5 = DAT_00ca6c24;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c24 * 0x40);
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
  if (uVar1 == 2) {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar4 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar4 = local_20 + 1;
    }
    if (*piVar4 == 0) {
      lp = (char *)0x0;
    }
    else {
      iVar2 = Tcl_GetIntFromObj(0,*piVar4,&param_3);
      lp = (char *)(-(uint)(iVar2 != 1) & param_3);
    }
    BVar3 = IsBadReadPtr(lp,4);
    if (BVar3 == 0) {
      piVar4 = (int *)Tcl_NewIntObj((int)*lp);
      *piVar4 = *piVar4 + 1;
      iVar2 = *piVar4;
      if (local_30 != 0) {
        Tcl_SetObjResult(local_30,piVar4);
        iVar2 = *piVar4;
      }
      *piVar4 = iVar2 + -1;
      if (iVar2 + -1 < 1) {
        TclFreeObj(piVar4);
      }
      uVar6 = 0;
    }
    else {
      if (local_18 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar4 = local_20;
        if (local_1c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_1c < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar4 = local_20 + 1;
      }
      piVar4 = (int *)*piVar4;
      if (piVar4 != (int *)0x0) {
        *piVar4 = *piVar4 + 1;
      }
      FUN_006bc6a0("access violation at",piVar4);
      uVar6 = 1;
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar6 = 1;
  }
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
  return uVar6;
}

