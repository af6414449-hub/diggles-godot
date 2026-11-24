
undefined4
CTclGlobalMethods__SMCreateMap(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *_Dst;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  int local_20;
  uint local_1c;
  uint local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c7ad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7360) &&
     (FUN_006cebf4(&DAT_00ca7360,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7360 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7364 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::SMCreateMap()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7360);
  }
  iVar4 = DAT_00ca7364;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7364 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar6;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 3) {
    FUN_004298b0(3,param_4);
    if (local_30 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_34 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_38 + 2;
    }
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_34 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_38 + 1;
    }
    piVar2 = (int *)*puVar7;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    if (piVar1 == (int *)0x0) {
      local_18 = 0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,piVar1,&local_1c);
      local_18 = -(uint)(iVar3 != 1) & local_1c;
    }
    if (piVar2 == (int *)0x0) {
      param_3 = 0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_20);
      if (iVar3 == 1) {
        param_3 = 0;
      }
      else {
        param_3 = local_20;
      }
    }
    local_14 = piVar2;
    iVar3 = FUN_005f8080();
    iVar5 = (int)((param_3 >> 0x1f & 3U) + param_3) >> 2;
    *(int *)(iVar3 + 0x7c) = iVar5;
    iVar4 = (int)(local_18 + ((int)local_18 >> 0x1f & 3U)) >> 2;
    local_18 = iVar5 * iVar4;
    *(int *)(iVar3 + 0x80) = iVar4;
    _Dst = (void *)FUN_006ba810(0x3bb);
    thunk_FUN_0060fc30(*(undefined4 *)(iVar3 + 0x30));
    *(void **)(iVar3 + 0x30) = _Dst;
    *(uint *)(iVar3 + 0x34) = local_18;
    if (_Dst != (void *)0x0) {
      _memset(_Dst,0,local_18 << 2);
    }
    if ((local_14 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    uVar6 = 0;
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
    FUN_004297b0(0);
    if (local_38 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar6 = 1;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

