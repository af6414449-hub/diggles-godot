
undefined4
CTclObjMethods__AutoChooseGender
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  undefined8 uVar10;
  char *pcVar11;
  int local_40;
  char local_3c;
  int *local_38;
  int *local_34;
  int local_30;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710b5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca74f0) &&
     (FUN_006cebf4(&DAT_00ca74f0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar1 = DAT_00783650,
     DAT_00ca74f0 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca74f4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::AutoChooseGender()";
    *(int *)(&DAT_00773650 + iVar3) = iVar1;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca74f0);
  }
  iVar3 = DAT_00ca74f4;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca74f4 * 0x40);
  iVar1 = FUN_0043fcc0();
  *(undefined4 *)(iVar1 + *(int *)(iVar1 + 0x8000) * 4) = uVar6;
  *(int *)(iVar1 + 0x8000) = *(int *)(iVar1 + 0x8000) + 1;
  iVar1 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar1 == 0) {
    uVar10 = FUN_006bd180();
    iVar1 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar1 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar1 = FUN_005c71c0(param_4,2,1);
  if (iVar1 == 0) {
    uVar6 = 1;
  }
  else {
    iVar7 = 0;
    iVar3 = *(int *)(iVar1 + 0x36c);
    piVar4 = (int *)(DAT_0077244c + 0x488);
    uVar5 = 2;
    local_18 = 0;
    local_14 = 8;
    do {
      if (uVar5 < 0x2000) {
        piVar2 = (int *)(local_14 + (int)piVar4);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar2 = piVar4;
      }
      if (*piVar2 != 0) {
        if (uVar5 < 0x2000) {
          piVar2 = (int *)(local_14 + (int)piVar4);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar2 = piVar4;
        }
        piVar8 = (int *)(local_14 + (int)piVar4);
        iVar7 = local_18;
        if (*(int *)(*piVar2 + 0x36c) == iVar3) {
          piVar2 = piVar8;
          if (0x1fff < uVar5) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar2 = piVar4;
          }
          if (*(int *)(*piVar2 + 0xe8) != 1) {
            piVar2 = piVar8;
            if (0x1fff < uVar5) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar2 = piVar4;
            }
            if (*(int *)(*piVar2 + 0xe8) != 0xb) goto LAB_006769aa;
          }
          if (0x1fff < uVar5) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar8 = piVar4;
          }
          if ((*(uint *)(*piVar8 + 0x3d0) & 0x8000) == 0) {
            local_18 = local_18 + (*(uint *)(*piVar8 + 0x3d0) >> 0x10 & 1);
            iVar7 = local_18;
          }
          else {
            local_18 = local_18 + -1;
            iVar7 = local_18;
          }
        }
      }
LAB_006769aa:
      uVar5 = uVar5 + 1;
      local_14 = local_14 + 4;
    } while ((int)uVar5 < 0x2000);
    uVar9 = iVar7 >> 0x1f & 2;
    uVar5 = *(uint *)(iVar1 + 0x3d0) & 0xfffe7fff;
    *(uint *)(iVar1 + 0x3d0) = uVar5;
    if (uVar9 == 0) {
      *(uint *)(iVar1 + 0x3d0) = uVar5 | 0x8000;
      pcVar11 = "male";
    }
    else {
      if (1 < uVar9) {
        *(uint *)(iVar1 + 0x3d0) = uVar5 | 0x10000;
      }
      pcVar11 = "female";
    }
    *(uint *)(iVar1 + 0x3d8) = *(uint *)(iVar1 + 0x3d8) | 4;
    piVar4 = (int *)Tcl_NewStringObj(pcVar11,0xffffffff);
    *piVar4 = *piVar4 + 1;
    iVar1 = *piVar4;
    if (local_40 != 0) {
      Tcl_SetObjResult(local_40,piVar4);
      iVar1 = *piVar4;
    }
    *piVar4 = iVar1 + -1;
    if (iVar1 + -1 < 1) {
      TclFreeObj(piVar4);
    }
    uVar6 = 0;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_30 != 0) {
    FUN_006ba940();
  }
  if ((local_3c != '\0') && (local_40 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_40);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 5;
  if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

