
undefined4
CTclObjMethods__ProdGnomeGetPreferredWorkplace
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  bool bVar6;
  bool bVar7;
  undefined8 uVar8;
  int local_34;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710b1d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7ca8) &&
     (FUN_006cebf4(&DAT_00ca7ca8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca7ca8 == -1)) {
    iVar2 = DAT_00783650 * 0x40;
    DAT_00ca7cac = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar2) = "TCL:CTclObjMethods::ProdGnomeGetPreferredWorkplace()";
    *(int *)(&DAT_00773650 + iVar2) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7ca8);
  }
  iVar2 = DAT_00ca7cac;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7cac * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar4;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar2 * 0x10];
  if (iVar1 == 0) {
    uVar8 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar2 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar2 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar2 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,2,1);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x3e4) != 0) {
      iVar1 = FUN_005ece50();
      if (iVar1 == 0) {
        piVar5 = (int *)Tcl_NewIntObj(0);
        *piVar5 = *piVar5 + 1;
        iVar1 = *piVar5;
        if (local_34 != 0) {
          Tcl_SetObjResult(local_34,piVar5);
          iVar1 = *piVar5;
        }
        iVar1 = iVar1 + -1;
        *piVar5 = iVar1;
        bVar7 = iVar1 < 0;
        bVar6 = iVar1 == 0;
LAB_006a862b:
        if (bVar6 || bVar7) {
          TclFreeObj(piVar5);
        }
      }
      else {
        iVar1 = FUN_005caf90();
        if (iVar1 == 0) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = (int *)Tcl_NewStringObj(iVar1,0xffffffff);
          *piVar5 = *piVar5 + 1;
        }
        if (local_34 != 0) {
          if (piVar5 == (int *)0x0) {
            Tcl_ResetResult(local_34);
            uVar4 = 0;
            goto LAB_006a854b;
          }
          Tcl_SetObjResult(local_34,piVar5);
          *piVar5 = *piVar5 + -1;
          bVar7 = *piVar5 < 0;
          bVar6 = *piVar5 == 0;
          goto LAB_006a862b;
        }
        if (piVar5 != (int *)0x0) {
          *piVar5 = *piVar5 + -1;
          bVar7 = *piVar5 < 0;
          bVar6 = *piVar5 == 0;
          goto LAB_006a862b;
        }
      }
      uVar4 = 0;
      goto LAB_006a854b;
    }
    if (local_1c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_24;
      if (local_20 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_20 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_24 + 1;
    }
    piVar5 = (int *)*puVar3;
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
    }
    FUN_006bc6a0("no gnome",piVar5);
  }
  uVar4 = 1;
LAB_006a854b:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
}

