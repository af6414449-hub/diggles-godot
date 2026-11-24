
undefined4
CTclGlobalMethods__ClassList
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  code *pcVar7;
  int *piVar8;
  undefined8 uVar9;
  int local_4c;
  char local_48;
  int *local_44;
  int *local_40;
  int local_3c;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ca95;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e00) &&
     (FUN_006cebf4(&DAT_00ca6e00,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6e00 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6e04 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::ClassList()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e00);
  }
  iVar6 = DAT_00ca6e04;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e04 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar5;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  iVar6 = DAT_00772478;
  piVar8 = (int *)0x0;
  local_1c = 0;
  iVar3 = *(int *)(DAT_00772478 + 0x801c);
  pcVar7 = TclFreeObj_exref;
  if (0 < iVar3) {
    do {
      local_8._0_1_ = 2;
      piVar4 = (int *)FUN_006ba810(0x19);
      piVar4[1] = 0x14;
      piVar4[2] = -1;
      *(undefined1 *)(piVar4 + 3) = 0;
      *piVar4 = 1;
      local_8 = CONCAT31(local_8._1_3_,3);
      if (*(uint *)(iVar6 + 0x801c) <= local_1c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar1 = *(int *)(*(int *)(iVar6 + 0x8018) + local_1c * 4);
      piVar2 = *(int **)(iVar1 + 0xc);
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      *piVar4 = *piVar4 + -1;
      if (*piVar4 == 0) {
        FUN_006ba940();
      }
      piVar2[2] = *(int *)(*(int *)(iVar1 + 0xc) + 8);
      piVar4 = piVar2 + 3;
      if (piVar4 != (int *)0x0) {
        piVar4 = (int *)Tcl_NewStringObj(piVar4,0xffffffff);
        *piVar4 = *piVar4 + 1;
      }
      if (piVar8 == (int *)0x0) {
        piVar8 = (int *)Tcl_NewListObj(0,0);
        if (piVar8 != (int *)0x0) {
          *piVar8 = *piVar8 + 1;
          goto LAB_0062f183;
        }
LAB_0062f1c7:
        pcVar7 = TclFreeObj_exref;
        if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
          TclFreeObj(piVar4);
        }
      }
      else {
LAB_0062f183:
        if (1 < *piVar8) {
          *piVar8 = *piVar8 + -1;
          piVar8 = (int *)Tcl_DuplicateObj(piVar8);
          *piVar8 = *piVar8 + 1;
        }
        pcVar7 = TclFreeObj_exref;
        if (piVar4 != (int *)0x0) {
          if (*piVar4 < 2) {
            Tcl_ListObjAppendElement(0,piVar8,piVar4);
          }
          else {
            uVar5 = Tcl_DuplicateObj();
            Tcl_ListObjAppendElement(0,piVar8,uVar5);
          }
          goto LAB_0062f1c7;
        }
      }
      local_8._0_1_ = 4;
      *piVar2 = *piVar2 + -1;
      if (*piVar2 == 0) {
        FUN_006ba940();
      }
      local_1c = local_1c + 1;
    } while ((int)local_1c < iVar3);
  }
  local_8._0_1_ = 2;
  FUN_006bc170(param_2);
  if (local_4c != 0) {
    if (piVar8 == (int *)0x0) {
      Tcl_ResetResult(local_4c);
    }
    else {
      Tcl_SetObjResult(local_4c,piVar8);
    }
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
  local_8._0_1_ = 5;
  if ((local_40 != (int *)0x0) && (*local_40 = *local_40 + -1, *local_40 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 == 0)) {
    FUN_006ba940();
  }
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
    (*pcVar7)(piVar8);
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_3c != 0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

