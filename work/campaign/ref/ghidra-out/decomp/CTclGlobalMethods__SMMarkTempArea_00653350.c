
undefined4
CTclGlobalMethods__SMMarkTempArea
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined **ppuVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  uint local_20;
  uint local_1c;
  int *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e8d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7248) &&
     (FUN_006cebf4(&DAT_00ca7248,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7248 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca724c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::SMMarkTempArea()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7248);
  }
  iVar5 = DAT_00ca724c;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca724c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar10;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar11 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar4 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if (piVar4 == (int *)&DAT_00000004) {
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_30 + 1;
    }
    piVar4 = (int *)*puVar8;
    if (piVar4 == (int *)0x0) {
      local_20 = 0;
    }
    else {
      *piVar4 = *piVar4 + 1;
      iVar2 = Tcl_GetIntFromObj(0,piVar4,&param_3);
      *piVar4 = *piVar4 + -1;
      local_20 = -(uint)(iVar2 != 1) & (uint)param_3;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_30 + 2;
    }
    piVar4 = (int *)*puVar8;
    if (piVar4 == (int *)0x0) {
      local_1c = 0;
    }
    else {
      *piVar4 = *piVar4 + 1;
      iVar2 = Tcl_GetIntFromObj(0,piVar4,&param_3);
      *piVar4 = *piVar4 + -1;
      local_1c = -(uint)(iVar2 != 1) & (uint)param_3;
      if (*piVar4 < 1) {
        TclFreeObj(piVar4);
      }
    }
    if (local_28 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_30 + 3;
    }
    piVar4 = (int *)*puVar8;
    if (piVar4 != (int *)0x0) {
      *piVar4 = *piVar4 + 1;
    }
    local_8._0_1_ = 3;
    local_18 = piVar4;
    if (piVar4 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
      piVar9 = (int *)0x0;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar4,0);
      piVar9 = piVar4;
    }
    FUN_006b8fb0(ppuVar3);
    local_8._0_1_ = 5;
    if ((piVar9 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    piVar1 = param_3;
    piVar4 = param_3 + 3;
    iVar2 = FUN_006cfeb0(piVar4,0x2f);
    piVar9 = piVar1;
    if ((iVar2 != 0) && (0 < (iVar2 - (int)piVar1) + -0xc)) {
      iVar5 = piVar1[2];
      if (iVar5 == -1) {
        do {
          iVar5 = *piVar4;
          piVar4 = (int *)((int)piVar4 + 1);
        } while ((char)iVar5 != '\0');
        iVar5 = (int)piVar4 - (int)((int)piVar1 + 0xd);
        piVar1[2] = iVar5;
      }
      piVar4 = (int *)FUN_006b9b20(&local_18,(iVar2 - (int)piVar1) + -0xb,iVar5);
      local_8._0_1_ = 6;
      piVar9 = (int *)*piVar4;
      if (piVar9 != (int *)0x0) {
        *piVar9 = *piVar9 + 1;
      }
      param_3 = piVar9;
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
        FUN_006ba940();
      }
      piVar9[2] = *(int *)(*piVar4 + 8);
      local_8._0_1_ = 7;
      if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 5;
    }
    iVar2 = piVar9[2];
    if (iVar2 == -1) {
      piVar4 = piVar9 + 3;
      do {
        iVar2 = *piVar4;
        piVar4 = (int *)((int)piVar4 + 1);
      } while ((char)iVar2 != '\0');
      iVar2 = (int)piVar4 - (int)((int)piVar9 + 0xd);
      piVar9[2] = iVar2;
    }
    piVar4 = (int *)FUN_006b8df0(piVar9,iVar2 + 5);
    *(undefined4 *)(iVar2 + 0xc + (int)piVar4) = 0x6c63742e;
    *(undefined1 *)(iVar2 + 0x10 + (int)piVar4) = 0;
    piVar4[2] = iVar2 + 4;
    param_3 = piVar4;
    FUN_0058a820();
    local_18 = (int *)0x0;
    local_14 = 0;
    FUN_00583bd0(&param_3,&local_18,&local_14);
    FUN_005f8080();
    uVar6 = local_14 & 0x80000003;
    if ((int)uVar6 < 0) {
      uVar6 = (uVar6 - 1 | 0xfffffffc) + 1;
    }
    uVar7 = (uint)local_18 & 0x80000003;
    if ((int)uVar7 < 0) {
      uVar7 = (uVar7 - 1 | 0xfffffffc) + 1;
    }
    FUN_005fa510((int)(local_20 + ((int)local_20 >> 0x1f & 3U)) >> 2,
                 (int)(local_1c + ((int)local_1c >> 0x1f & 3U)) >> 2,
                 (uint)(uVar7 != 0) + ((int)((int)local_18 + ((int)local_18 >> 0x1f & 3U)) >> 2),
                 (uint)(uVar6 != 0) + ((int)(local_14 + ((int)local_14 >> 0x1f & 3U)) >> 2));
    uVar10 = 0;
    local_8._0_1_ = 8;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      FUN_006ba940();
    }
  }
  else {
    FUN_006bc8f0(3);
    uVar10 = 1;
  }
  local_8._0_1_ = 9;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

