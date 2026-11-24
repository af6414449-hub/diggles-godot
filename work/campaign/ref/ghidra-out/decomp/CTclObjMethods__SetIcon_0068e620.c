
undefined4
CTclObjMethods__SetIcon(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined4 extraout_ECX;
  uint uVar6;
  code *pcVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  int local_4c;
  char local_48;
  int *local_44;
  int *local_40;
  undefined4 *local_3c;
  uint local_38;
  int local_34;
  int *local_20;
  int *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007118dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca78f8) &&
     (FUN_006cebf4(&DAT_00ca78f8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca78f8 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca78fc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::SetIcon()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca78f8);
  }
  iVar3 = DAT_00ca78fc;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca78fc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar8;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar10 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar10;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar2 = FUN_005c71c0(param_4,2,1);
  if (iVar2 == 0) {
    uVar8 = 1;
  }
  else {
    FUN_005dc6a0(extraout_ECX);
    local_14 = 2;
    pcVar7 = TclFreeObj_exref;
    if (2 < param_3) {
      do {
        uVar6 = local_14;
        if ((int)local_14 < local_34) {
          if (local_38 <= local_14) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar9 = local_3c + uVar6;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar9 = local_3c;
          if (local_38 == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        piVar1 = (int *)*puVar9;
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
          iVar3 = Tcl_ListObjLength(0,piVar1,&local_18);
          if ((iVar3 == 0) && (iVar3 = 0, uVar6 = local_14, 0 < local_18)) {
            do {
              iVar4 = Tcl_ListObjIndex(0,piVar1,iVar3,&local_1c);
              if (iVar4 == 0) {
                local_20 = local_1c;
                if (local_1c != (int *)0x0) {
                  *local_1c = *local_1c + 1;
                }
              }
              else {
                local_20 = (int *)0x0;
              }
              local_8 = CONCAT31(local_8._1_3_,4);
              if (local_20 == (int *)0x0) {
                ppuVar5 = &PTR_0071ce50;
              }
              else {
                ppuVar5 = (undefined **)Tcl_GetStringFromObj(local_20,0);
              }
              FUN_005dc780(iVar2,ppuVar5);
              pcVar7 = TclFreeObj_exref;
              if ((local_20 != (int *)0x0) &&
                 (*local_20 = *local_20 + -1, pcVar7 = TclFreeObj_exref, *local_20 < 1)) {
                TclFreeObj(local_20);
              }
              iVar3 = iVar3 + 1;
              uVar6 = local_14;
            } while (iVar3 < local_18);
          }
          *piVar1 = *piVar1 + -1;
          if (*piVar1 < 1) {
            (*pcVar7)(piVar1);
          }
        }
        local_14 = uVar6 + 1;
      } while ((int)local_14 < param_3);
    }
    uVar8 = 0;
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
  local_8._0_1_ = 6;
  if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_3c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

