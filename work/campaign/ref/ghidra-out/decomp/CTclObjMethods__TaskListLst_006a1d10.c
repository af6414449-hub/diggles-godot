
undefined4
CTclObjMethods__TaskListLst
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  int *piVar8;
  undefined8 uVar9;
  int local_44;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  int *local_20;
  int *local_1c;
  int local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071216d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_20 = (int *)0x0;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c28) &&
     (FUN_006cebf4(&DAT_00ca7c28,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7c28 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca7c2c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::TaskListLst()";
    *(int *)(&DAT_00773650 + iVar7) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c28);
  }
  iVar7 = DAT_00ca7c2c;
  uVar4 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c2c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar4;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  local_18 = FUN_005c71c0(param_4,3,1);
  if (local_18 != 0) {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_34 + 2;
    }
    piVar5 = (int *)*puVar6;
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar5 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
      piVar8 = (int *)0x0;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar5,0);
      piVar8 = piVar5;
    }
    FUN_006b8fb0(ppuVar3);
    local_8 = CONCAT31(local_8._1_3_,5);
    if ((piVar8 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
      TclFreeObj(piVar5);
    }
    iVar7 = 0;
    iVar2 = *(int *)(local_18 + 100);
    piVar5 = local_20;
    do {
      if (iVar7 < iVar2) {
        uVar4 = FUN_005cdd80(&local_20,iVar7);
        piVar5 = (int *)((uint)piVar5 | 1);
        cVar1 = FUN_006b97f0(uVar4);
        local_11 = '\x01';
        if (cVar1 != '\0') goto LAB_006a1ec4;
      }
      else {
LAB_006a1ec4:
        local_11 = '\0';
      }
      if (((uint)piVar5 & 1) != 0) {
        piVar5 = (int *)0x0;
        local_8._0_1_ = 6;
        if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,5);
      }
      if (local_11 == '\0') goto LAB_006a1ef5;
      iVar7 = iVar7 + 1;
    } while( true );
  }
  uVar4 = 1;
LAB_006a1f49:
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar4;
LAB_006a1ef5:
  if (iVar2 <= iVar7) {
    iVar7 = -1;
  }
  piVar5 = (int *)Tcl_NewIntObj(iVar7);
  *piVar5 = *piVar5 + 1;
  iVar2 = *piVar5;
  if (local_44 != 0) {
    Tcl_SetObjResult(local_44,piVar5);
    iVar2 = *piVar5;
  }
  *piVar5 = iVar2 + -1;
  if (iVar2 + -1 < 1) {
    TclFreeObj(piVar5);
  }
  uVar4 = 0;
  local_8._0_1_ = 7;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  goto LAB_006a1f49;
}

