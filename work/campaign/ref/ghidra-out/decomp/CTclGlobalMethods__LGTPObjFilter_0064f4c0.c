
undefined4
CTclGlobalMethods__LGTPObjFilter
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined **ppuVar6;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *piVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  int *piVar11;
  int local_48;
  char local_44;
  int *local_40;
  int *local_3c;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e3f5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca71d0) &&
     (FUN_006cebf4(&DAT_00ca71d0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca71d0 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca71d4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::LGTPObjFilter()";
    *(int *)(&DAT_00773650 + iVar5) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca71d0);
  }
  iVar5 = DAT_00ca71d4;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca71d4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar3 == 0) {
    uVar10 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar1 == (int *)0x2) {
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_38;
      if (local_34 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_34 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_38 + 1;
    }
    piVar1 = (int *)*puVar9;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0058a820();
    iVar3 = 0;
    while( true ) {
      if (piVar1 == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar4 = Tcl_ListObjLength(0,piVar1,&local_18);
        iVar5 = local_18;
        if (iVar4 != 0) {
          iVar5 = 0;
        }
      }
      if (iVar5 <= iVar3) {
        uVar8 = 0;
        goto LAB_0064f70f;
      }
      if ((piVar1 == (int *)0x0) || (iVar5 = Tcl_ListObjIndex(0,piVar1,iVar3,&local_1c), iVar5 != 0)
         ) {
        piVar11 = (int *)0x0;
      }
      else {
        piVar11 = local_1c;
        if (local_1c != (int *)0x0) {
          *local_1c = *local_1c + 1;
        }
      }
      local_8._0_1_ = 4;
      if (piVar11 == (int *)0x0) {
        ppuVar6 = &PTR_0071ce50;
      }
      else {
        ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar11,0);
      }
      FUN_006b8fb0(ppuVar6);
      local_8._0_1_ = 5;
      cVar2 = FUN_00583990(&local_14);
      param_3 = (int *)CONCAT13(cVar2 == '\0',param_3._0_3_);
      local_8._0_1_ = 6;
      piVar7 = local_14;
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
        piVar7 = extraout_ECX;
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
        TclFreeObj(piVar11);
        piVar7 = extraout_ECX_00;
      }
      if (param_3._3_1_ != '\0') break;
      iVar3 = iVar3 + 1;
    }
    if ((piVar1 == (int *)0x0) ||
       (iVar3 = Tcl_ListObjIndex(0,piVar1,iVar3,&param_3,piVar7), iVar3 != 0)) {
      piVar11 = (int *)0x0;
    }
    else {
      piVar11 = param_3;
      if (param_3 != (int *)0x0) {
        *param_3 = *param_3 + 1;
      }
    }
    FUN_006bc6a0("invalid objfilter",piVar11);
    uVar8 = 1;
LAB_0064f70f:
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      TclFreeObj(piVar1);
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar8 = 1;
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_44 != '\0') && (local_48 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_48);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 9;
  if ((local_3c != (int *)0x0) && (*local_3c = *local_3c + -1, *local_3c == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,10);
  if ((local_40 != (int *)0x0) && (*local_40 = *local_40 + -1, *local_40 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

