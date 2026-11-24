
undefined4 CTclObjMethods__SetPosBottom(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined4 *local_44;
  uint local_40;
  int local_3c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071126d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7708) &&
     (FUN_006cebf4(), iVar4 = DAT_00783650, DAT_00ca7708 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca770c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclObjMethods::SetPosBottom()";
    *(int *)(&DAT_00773650 + iVar6) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar6 = DAT_00ca770c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca770c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar7;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar4 == 0) {
    uVar8 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_004298b0();
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar4 = FUN_005c71c0();
  if (iVar4 == 0) {
    uVar7 = 1;
  }
  else {
    if (param_3 == 3) {
      if (local_3c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_44;
        if (local_40 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_40 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_44 + 2;
      }
      piVar1 = (int *)*puVar5;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_006bafe0(&stack0xffffffa0);
      FUN_005cb600();
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        TclFreeObj();
      }
    }
    else {
      if (local_3c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_44;
        if (local_40 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_40 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_44 + 2;
      }
      piVar1 = (int *)*puVar5;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      if (local_3c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_44;
        if (local_40 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_40 < 4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar5 = local_44 + 3;
      }
      piVar2 = (int *)*puVar5;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      if (piVar1 != (int *)0x0) {
        Tcl_GetDoubleFromObj();
      }
      if (piVar2 != (int *)0x0) {
        Tcl_GetDoubleFromObj();
      }
      if (param_3 == 5) {
        puVar5 = (undefined4 *)FUN_004295e0();
        piVar3 = (int *)*puVar5;
        if (piVar3 != (int *)0x0) {
          *piVar3 = *piVar3 + 1;
          Tcl_GetDoubleFromObj();
          *piVar3 = *piVar3 + -1;
          if (*piVar3 < 1) {
            TclFreeObj();
          }
        }
      }
      FUN_005cb600();
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj();
      }
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
        TclFreeObj();
      }
    }
    uVar7 = 0;
  }
  local_8._0_1_ = 5;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0();
  if (local_44 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

