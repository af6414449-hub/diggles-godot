
undefined4
CTclObjMethods__SetSelectable
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711175;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca76a8) &&
     (FUN_006cebf4(&DAT_00ca76a8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca76a8 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca76ac = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::SetSelectable()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca76a8);
  }
  iVar7 = DAT_00ca76ac;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca76ac * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar3 = FUN_005c71c0(param_4,3,1);
  local_18 = iVar3;
  if (iVar3 == 0) {
    uVar8 = 1;
    goto LAB_006813fc;
  }
  if (local_24 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_2c;
    if (local_28 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_2c + 2;
  }
  piVar2 = (int *)*puVar6;
  if (piVar2 == (int *)0x0) {
    iVar7 = FUN_004313c0();
    uVar5 = *(uint *)(local_18 + 0xdc);
LAB_006813c4:
    iVar7 = iVar7 + 4;
    if (uVar5 < 0x2000) {
      iVar7 = iVar7 + uVar5 * 0xc;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *(uint *)(iVar7 + 4) = *(uint *)(iVar7 + 4) & 0xfffffffd;
    uVar8 = 0;
    if (piVar2 == (int *)0x0) goto LAB_006813fc;
  }
  else {
    *piVar2 = *piVar2 + 1;
    local_14 = FUN_004313c0();
    iVar4 = Tcl_GetBooleanFromObj(0,piVar2,&local_1c);
    iVar7 = local_14;
    if (iVar4 == 1) {
      uVar5 = *(uint *)(iVar3 + 0xdc);
      goto LAB_006813c4;
    }
    uVar5 = *(uint *)(local_18 + 0xdc);
    if (local_1c == 0) goto LAB_006813c4;
    if (uVar5 < 0x2000) {
      puVar1 = (uint *)(local_14 + 8 + uVar5 * 0xc);
      *puVar1 = *puVar1 | 2;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      *(uint *)(iVar7 + 8) = *(uint *)(iVar7 + 8) | 2;
    }
  }
  uVar8 = 0;
  *piVar2 = *piVar2 + -1;
  if (*piVar2 < 1) {
    TclFreeObj(piVar2);
  }
LAB_006813fc:
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

