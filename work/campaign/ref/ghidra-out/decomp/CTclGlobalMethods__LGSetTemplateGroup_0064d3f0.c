
undefined4
CTclGlobalMethods__LGSetTemplateGroup
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined8 uVar10;
  int local_4c;
  char local_48;
  int *local_44;
  int *local_40;
  undefined4 *local_3c;
  uint local_38;
  int local_34;
  int *local_20;
  int local_1c;
  int *local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e225;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7188) &&
     (FUN_006cebf4(&DAT_00ca7188,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7188 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca718c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::LGSetTemplateGroup()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7188);
  }
  iVar6 = DAT_00ca718c;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca718c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar10 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar1 == (int *)0x3) {
    local_14 = FUN_0058a820();
    if (local_34 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_3c + 1;
    }
    piVar1 = (int *)*puVar8;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
      piVar9 = (int *)0x0;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
      piVar9 = piVar1;
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 4;
    uVar7 = FUN_00583450(&param_3);
    local_8 = CONCAT31(local_8._1_3_,5);
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
    if ((piVar9 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
    if (local_34 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_3c;
      if (local_38 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_38 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_3c + 2;
    }
    piVar1 = (int *)*puVar8;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    iVar3 = 0;
    while( true ) {
      if (piVar1 == (int *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar5 = Tcl_ListObjLength(0,piVar1,&local_1c);
        iVar6 = local_1c;
        if (iVar5 != 0) {
          iVar6 = 0;
        }
      }
      if (iVar6 <= iVar3) {
        uVar7 = 0;
        goto LAB_0064d6aa;
      }
      if ((piVar1 == (int *)0x0) || (iVar6 = Tcl_ListObjIndex(0,piVar1,iVar3,&local_20), iVar6 != 0)
         ) {
        piVar9 = (int *)0x0;
      }
      else {
        piVar9 = local_20;
        if (local_20 != (int *)0x0) {
          *local_20 = *local_20 + 1;
        }
      }
      local_8._0_1_ = 7;
      if (piVar9 == (int *)0x0) {
        ppuVar4 = &PTR_0071ce50;
      }
      else {
        ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar9,0);
      }
      FUN_006b8fb0(ppuVar4);
      local_8._0_1_ = 8;
      cVar2 = FUN_005834f0(uVar7,&local_18);
      param_3 = (int *)CONCAT13(cVar2 == '\0',param_3._0_3_);
      local_8 = CONCAT31(local_8._1_3_,9);
      if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
        FUN_006ba940();
      }
      if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
        TclFreeObj(piVar9);
      }
      if (param_3._3_1_ != '\0') break;
      iVar3 = iVar3 + 1;
    }
    uVar7 = 1;
LAB_0064d6aa:
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar7 = 1;
  }
  local_8._0_1_ = 10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_004297b0(0);
  if (local_3c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_48 != '\0') && (local_4c != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_4c);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 0xc;
  if ((local_40 != (int *)0x0) && (*local_40 = *local_40 + -1, *local_40 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0xd);
  if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar7;
}

