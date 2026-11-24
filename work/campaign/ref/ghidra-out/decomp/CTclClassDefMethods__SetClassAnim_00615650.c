
undefined4
CTclClassDefMethods__SetClassAnim
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined **ppuVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  code *pcVar8;
  undefined8 uVar9;
  undefined4 local_48;
  undefined4 *local_44;
  uint local_40;
  int local_3c;
  undefined1 local_38 [4];
  int *local_34;
  int *local_30;
  undefined4 *local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070a945;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6bc8) &&
     (FUN_006cebf4(&DAT_00ca6bc8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6bc8 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6bcc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclClassDefMethods::SetClassAnim()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6bc8);
  }
  iVar5 = DAT_00ca6bcc;
  local_2c = &DAT_00ca6bcc;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6bcc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar2 == 0) {
    uVar9 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_28 = DAT_00772440;
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar6 = 1;
  }
  else if (param_3 < 3) {
    FUN_006bc8f0(2);
    uVar6 = 1;
  }
  else {
    if (local_3c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_40 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_44 + 1;
    }
    local_30 = (int *)*puVar3;
    if (local_30 != (int *)0x0) {
      *local_30 = *local_30 + 1;
    }
    local_18 = local_30;
    if (local_3c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_40 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_44 + 2;
    }
    piVar1 = (int *)*puVar3;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    piVar7 = (int *)0x0;
    local_1c = (int *)0x0;
    local_8 = CONCAT31(local_8._1_3_,5);
    local_34 = piVar1;
    if (param_3 == 4) {
      puVar3 = (undefined4 *)FUN_004295e0(3);
      piVar7 = (int *)*puVar3;
      local_1c = piVar7;
      if (piVar7 != (int *)0x0) {
        *piVar7 = *piVar7 + 1;
        *piVar7 = *piVar7 + 1;
        if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
          TclFreeObj(piVar7);
        }
      }
    }
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 6;
    FUN_00460fc0(&local_14,&local_24,local_38,&local_20);
    local_8._0_1_ = 7;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 5;
    if (local_18 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(local_18,0);
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 8;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
    }
    FUN_006026e0(&local_14,CONCAT44(local_20,local_24),local_48,piVar7);
    local_8._0_1_ = 9;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    if (local_24 == -1) {
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("unknown anim",piVar1);
      uVar6 = 1;
    }
    else {
      uVar6 = 0;
    }
    pcVar8 = TclFreeObj_exref;
    if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, pcVar8 = TclFreeObj_exref, *piVar7 < 1))
    {
      TclFreeObj(piVar7);
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar8)(piVar1);
    }
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
      (*pcVar8)(local_18);
    }
  }
  local_8._0_1_ = 10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_004297b0(0);
  if (local_44 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

