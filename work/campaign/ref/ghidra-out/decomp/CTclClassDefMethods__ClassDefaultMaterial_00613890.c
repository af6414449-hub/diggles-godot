
undefined4
CTclClassDefMethods__ClassDefaultMaterial
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  undefined4 local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a795;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6b80) &&
     (FUN_006cebf4(&DAT_00ca6b80,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6b80 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6b84 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclClassDefMethods::ClassDefaultMaterial()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6b80);
  }
  iVar5 = DAT_00ca6b84;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6b84 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar8 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  iVar3 = DAT_00772440;
  local_8 = CONCAT31(local_8._1_3_,2);
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar7 = 1;
  }
  else if (param_3 < 2) {
    FUN_006bc8f0(1);
    uVar7 = 1;
  }
  else {
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_2c + 1;
    }
    piVar1 = (int *)*puVar6;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0045a470();
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar4);
    cVar2 = FUN_00444990(&local_14,&local_18);
    if (cVar2 == '\0') {
      local_18 = 0xffffffff;
    }
    *(undefined4 *)(*(int *)(iVar3 + 4) + 0x24) = local_18;
    local_8 = CONCAT31(local_8._1_3_,4);
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    iVar3 = *(int *)(iVar3 + 4);
    if (*(int *)(iVar3 + 0x24) == -1) {
      *(undefined4 *)(iVar3 + 0x24) = 0;
    }
    uVar7 = 0;
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_2c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

