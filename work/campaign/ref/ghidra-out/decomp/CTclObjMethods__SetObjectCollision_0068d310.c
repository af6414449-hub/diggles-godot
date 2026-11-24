
undefined4
CTclObjMethods__SetObjectCollision
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
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
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca78b8) &&
     (FUN_006cebf4(&DAT_00ca78b8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca78b8 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca78bc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::SetObjectCollision()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca78b8);
  }
  iVar3 = DAT_00ca78bc;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca78bc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar7 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar7;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar2 = FUN_005c71c0(param_4,3,1);
  if (iVar2 == 0) {
    uVar6 = 1;
  }
  else {
    if (local_1c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_24 + 2;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 == (int *)0x0) {
      *(uint *)(iVar2 + 0x3d0) = *(uint *)(iVar2 + 0x3d0) & 0xffefffff;
    }
    else {
      *piVar1 = *piVar1 + 1;
      iVar3 = Tcl_GetBooleanFromObj(0,piVar1,&local_14);
      if (iVar3 == 1) {
        *(uint *)(iVar2 + 0x3d0) = *(uint *)(iVar2 + 0x3d0) & 0xffefffff;
      }
      else {
        uVar4 = *(uint *)(iVar2 + 0x3d0) | 0x100000;
        if (local_14 == 0) {
          uVar4 = *(uint *)(iVar2 + 0x3d0) & 0xffefffff;
        }
        *(uint *)(iVar2 + 0x3d0) = uVar4;
      }
      *piVar1 = *piVar1 + -1;
      uVar6 = 0;
      if (0 < *piVar1) goto LAB_0068d494;
      TclFreeObj(piVar1);
    }
    uVar6 = 0;
  }
LAB_0068d494:
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

