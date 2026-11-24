
undefined4
CTclGlobalMethods__Set_EventEnabled
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  byte *pbVar9;
  code *pcVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  int *local_20;
  int *local_1c;
  byte *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c925;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6de0) &&
     (FUN_006cebf4(&DAT_00ca6de0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6de0 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6de4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::Set_EventEnabled()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6de0);
  }
  iVar7 = DAT_00ca6de4;
  uVar11 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6de4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar11;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar3 == 0) {
    uVar12 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 4) {
    FUN_006bc8f0(3);
    uVar11 = 1;
    goto LAB_0062e609;
  }
  if (local_2c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_34;
    if (local_30 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_34 + 1;
  }
  piVar1 = (int *)*puVar4;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  if (local_2c < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_34;
    if (local_30 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_30 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_34 + 2;
  }
  piVar2 = (int *)*puVar4;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_20 = piVar2;
  if (local_2c < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar4 = local_34;
    if (local_30 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_30 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar4 = local_34 + 3;
  }
  local_1c = (int *)*puVar4;
  if (local_1c != (int *)0x0) {
    *local_1c = *local_1c + 1;
  }
  local_8._0_1_ = 5;
  local_14 = local_1c;
  if (piVar1 == (int *)0x0) {
    ppuVar5 = &PTR_0071ce50;
  }
  else {
    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  FUN_006b8fb0(ppuVar5);
  uVar6 = FUN_005ba5b0(&local_18);
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((local_18 != (byte *)0x0) && (*(int *)local_18 = *(int *)local_18 + -1, *(int *)local_18 == 0)
     ) {
    FUN_006ba940();
  }
  if (uVar6 == 0xffffffff) {
LAB_0062e5d9:
    pcVar10 = TclFreeObj_exref;
    if (local_14 != (int *)0x0) goto LAB_0062e56c;
  }
  else {
    if (piVar2 == (int *)0x0) {
      local_18 = (byte *)0x0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_1c);
      local_18 = (byte *)(-(uint)(iVar3 != 1) & (uint)local_1c);
    }
    if (((local_14 == (int *)0x0) ||
        (iVar3 = Tcl_GetBooleanFromObj(0,local_14,&local_20), iVar3 == 1)) ||
       (local_20 == (int *)0x0)) {
      if (uVar6 < 0x81) {
        bVar8 = (byte)local_18;
        local_18 = (byte *)(DAT_00772400 + 0x97dc);
        if (uVar6 < 0x80) {
          pbVar9 = local_18 + uVar6;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pbVar9 = local_18;
        }
        *pbVar9 = ~('\x01' << (bVar8 & 0x1f)) & *pbVar9;
      }
      goto LAB_0062e5d9;
    }
    if (uVar6 < 0x81) {
      bVar8 = (byte)local_18;
      local_18 = (byte *)(DAT_00772400 + 0x97dc);
      if (uVar6 < 0x80) {
        pbVar9 = local_18 + uVar6;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        pbVar9 = local_18;
      }
      *pbVar9 = *pbVar9 | '\x01' << (bVar8 & 0x1f);
    }
LAB_0062e56c:
    *local_14 = *local_14 + -1;
    pcVar10 = TclFreeObj_exref;
    if (*local_14 < 1) {
      TclFreeObj(local_14);
    }
  }
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    (*pcVar10)(piVar2);
  }
  uVar11 = 0;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar10)(piVar1);
  }
LAB_0062e609:
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar11;
}

