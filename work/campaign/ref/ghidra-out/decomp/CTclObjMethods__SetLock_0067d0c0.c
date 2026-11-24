
undefined4
CTclObjMethods__SetLock(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007110f5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca75b8) &&
     (FUN_006cebf4(&DAT_00ca75b8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca75b8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca75bc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::SetLock()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca75b8);
  }
  iVar4 = DAT_00ca75bc;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca75bc * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar7 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar3 = FUN_005c71c0(param_4,3,1);
  if (iVar3 != 0) {
    if (local_1c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_24 + 2;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 == (int *)0x0) {
      *(uint *)(iVar3 + 0x3d0) = *(uint *)(iVar3 + 0x3d0) & 0xfffffffb;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar4 = Tcl_GetBooleanFromObj(0,piVar2,&local_14);
      if (iVar4 == 1) {
        *(uint *)(iVar3 + 0x3d0) = *(uint *)(iVar3 + 0x3d0) & 0xfffffffb;
      }
      else {
        uVar5 = *(uint *)(iVar3 + 0x3d0) | 4;
        if (local_14 == 0) {
          uVar5 = *(uint *)(iVar3 + 0x3d0) & 0xfffffffb;
        }
        *(uint *)(iVar3 + 0x3d0) = uVar5;
      }
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

