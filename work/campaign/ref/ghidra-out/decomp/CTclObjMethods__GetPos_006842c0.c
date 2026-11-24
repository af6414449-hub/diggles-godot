
undefined4
CTclObjMethods__GetPos(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int local_30;
  undefined4 local_20;
  float local_1c;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007112e5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7748) {
    FUN_006cebf4(&DAT_00ca7748,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar1 = DAT_00783650;
    if (DAT_00ca7748 == -1) {
      iVar3 = DAT_00783650 * 0x40;
      DAT_00ca774c = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::GetPos()";
      *(int *)(&DAT_00773650 + iVar3) = iVar1;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca7748);
    }
  }
  iVar3 = DAT_00ca774c;
  local_14 = &DAT_00ca774c;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca774c * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar5;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar6 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar6;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar1 = FUN_005c71c0(param_4,2,1);
  if (iVar1 == 0) {
    uVar5 = 1;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0x39c);
    iVar3 = *(int *)(iVar1 + 0x3a0);
    if ((*(uint *)(iVar1 + 0x3d0) & 0x4000) != 0) {
      uVar2 = *(uint *)(DAT_00772400 + 0xa3d4);
      iVar3 = *(int *)(DAT_00772400 + 0xa3dc);
    }
    if ((uVar2 == 0xffffffff) || (iVar3 == -1)) {
      local_20 = *(undefined4 *)(iVar1 + 0xc);
      local_1c = *(float *)(iVar1 + 0x10);
      local_18 = *(undefined4 *)(iVar1 + 0x14);
    }
    else {
      piVar4 = (int *)(DAT_00772400 + 0x5c8);
      if (uVar2 < 0x100) {
        piVar4 = piVar4 + uVar2;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_1c = 0.0;
      if (*piVar4 != 0) {
        iVar3 = FUN_004059a0(iVar3);
        local_1c = *(float *)(iVar3 + 0x54) * 0.005;
      }
      local_20 = *(undefined4 *)(iVar1 + 0xc);
      local_1c = *(float *)(iVar1 + 0x10) + local_1c;
      local_18 = *(undefined4 *)(iVar1 + 0x14);
    }
    piVar4 = (int *)FUN_006badc0(&local_20);
    if (local_30 != 0) {
      if (*piVar4 == 0) {
        Tcl_ResetResult(local_30);
      }
      else {
        Tcl_SetObjResult(local_30,*piVar4);
      }
    }
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + -1;
      if (*local_14 < 1) {
        TclFreeObj(local_14);
      }
    }
    uVar5 = 0;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar5;
}

