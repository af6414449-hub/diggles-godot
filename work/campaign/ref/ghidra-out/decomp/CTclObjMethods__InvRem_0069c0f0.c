
undefined4
CTclObjMethods__InvRem(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  BOOL BVar8;
  int iVar9;
  undefined8 uVar10;
  undefined1 local_44 [12];
  undefined4 *local_38;
  uint local_34;
  int local_30;
  undefined4 *local_2c;
  int local_28;
  int *local_24;
  int *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711e45;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7b18) &&
     (FUN_006cebf4(&DAT_00ca7b18,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7b18 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca7b1c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclObjMethods::InvRem()";
    *(int *)(&DAT_00773650 + iVar9) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7b18);
  }
  iVar9 = DAT_00ca7b1c;
  local_2c = &DAT_00ca7b1c;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7b1c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar2;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar4 == 0) {
    uVar10 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  iVar4 = FUN_005c71c0(param_4,3,1);
  if (iVar4 == 0) {
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_004297b0(0);
    if (local_38 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    goto LAB_0069c1eb;
  }
  if (local_30 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_38;
    if (local_34 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_38;
    }
  }
  else {
    if (local_34 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_38 + 2;
  }
  piVar3 = (int *)*puVar5;
  if (piVar3 != (int *)0x0) {
    *piVar3 = *piVar3 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  local_14 = *(undefined4 *)(iVar4 + 0xc);
  local_18 = *(undefined4 *)(iVar4 + 0x10);
  local_1c = *(undefined4 *)(iVar4 + 0x14);
  local_24 = piVar3;
  if (param_3 == 4) {
    if (local_30 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_38;
      }
    }
    else {
      if (local_34 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_38 + 3;
    }
    piVar6 = (int *)*puVar5;
    local_20 = piVar6;
    if (piVar6 == (int *)0x0) {
      puVar5 = (undefined4 *)FUN_006bafe0(local_44);
      local_14 = *puVar5;
      local_18 = puVar5[1];
      local_1c = puVar5[2];
    }
    else {
      *piVar6 = *piVar6 + 1;
      puVar5 = (undefined4 *)FUN_006bafe0(local_44);
      local_14 = *puVar5;
      local_18 = puVar5[1];
      local_1c = puVar5[2];
      *piVar6 = *piVar6 + -1;
      if (*piVar6 < 1) {
        TclFreeObj(piVar6);
      }
    }
  }
  local_20 = (int *)FUN_005c8310(param_2,&local_24);
  if (local_20 != (int *)0x0) {
    iVar9 = 0;
    local_28 = FUN_005cf210();
    if (0 < local_28) {
      do {
        piVar6 = (int *)FUN_005cef70(iVar9);
        if (piVar6 == local_20) goto LAB_0069c3cf;
        iVar9 = iVar9 + 1;
      } while (iVar9 < local_28);
    }
  }
  if (piVar3 == (int *)0x0) {
    iVar9 = 0;
LAB_0069c3cf:
    iVar7 = FUN_005cf210();
    if (iVar9 < iVar7) {
      local_20 = (int *)FUN_005cef70(iVar9);
      if ((((local_20 == (int *)0x0) || (BVar8 = IsBadReadPtr(local_20,0x10), BVar8 != 0)) ||
          (local_20[2] != 0x616e4f62)) || ((DAT_00768398 != '\0' && (local_20[0x37] == 0)))) {
        if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
          TclFreeObj(piVar3);
        }
        FUN_00429650();
LAB_0069c1eb:
        FUN_006bc0d0();
        FUN_0043fd30();
        ExceptionList = local_10;
        return 1;
      }
      FUN_005cec30(iVar9);
      piVar6 = local_20;
      if (*(int *)(*(int *)(iVar4 + 0xd4) + 0x54) != 5) {
        FUN_0046a960(local_20[0x37]);
      }
      puVar1 = (uint *)(piVar6 + 0xf4);
      *puVar1 = *puVar1 | 1;
      FUN_005cb600(local_14,local_18,local_1c);
      iVar4 = FUN_00501450();
      if (*(int *)(*(int *)(iVar4 + 0x8194) + 0x128) == piVar6[0x37]) {
        FUN_00501450();
        FUN_00531280();
      }
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
        TclFreeObj(piVar3);
      }
      FUN_00429650();
      goto LAB_0069c521;
    }
  }
  else {
    iVar9 = Tcl_GetIntFromObj(0,piVar3,&local_28);
    if (iVar9 == 1) {
      iVar9 = 0;
      goto LAB_0069c3cf;
    }
    iVar9 = local_28;
    if (-1 < local_28) goto LAB_0069c3cf;
  }
  if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
    TclFreeObj(piVar3);
  }
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
LAB_0069c521:
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

