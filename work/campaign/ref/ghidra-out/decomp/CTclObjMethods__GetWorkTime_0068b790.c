
/* WARNING: Removing unreachable block (ram,0x0068bbee) */
/* WARNING: Removing unreachable block (ram,0x0068bbff) */

undefined4
CTclObjMethods__GetWorkTime(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined **ppuVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  code *pcVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int *piVar11;
  undefined8 uVar12;
  char *pcVar13;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  undefined8 local_1c;
  int *piStack_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711785;
  local_10 = ExceptionList;
  uVar2 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7868) &&
     (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00ca7868 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca786c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::GetWorkTime()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar7 = DAT_00ca786c;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca786c * 0x40);
  iVar3 = FUN_0043fcc0(uVar2);
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar10;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar3 == 0) {
    uVar12 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_005c71c0(param_4,1);
  if (iVar3 == 0) {
    uVar10 = 1;
    goto LAB_0068bc0b;
  }
  if (param_3 != 3) {
    FUN_006bad90();
    FUN_006bb930();
    if ((piStack_18 != (int *)0x0) && (*piStack_18 = *piStack_18 + -1, *piStack_18 < 1)) {
      TclFreeObj();
    }
    FUN_006bad90();
    FUN_006bb930();
    if ((piStack_18 != (int *)0x0) && (*piStack_18 = *piStack_18 + -1, *piStack_18 < 1)) {
      TclFreeObj();
    }
    if (local_40 == 0) {
      uVar10 = 0;
    }
    else {
      Tcl_ResetResult();
      uVar10 = 0;
    }
    goto LAB_0068bc0b;
  }
  if (local_28 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar9 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar9 = local_30 + 2;
  }
  piVar1 = (int *)*puVar9;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  piVar11 = (int *)((float)*(double *)(DAT_00772400 + 0xa088) / 150.0);
  FUN_006f6da0((double)((float)piVar11 / 12.0));
  if (piVar1 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
  }
  else {
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1);
  }
  iVar3 = __stricmp((char *)ppuVar4,"start");
  if (iVar3 == 0) {
    piVar5 = (int *)FUN_006bad90();
    if (local_40 != 0) {
      if (*piVar5 == 0) {
        Tcl_ResetResult();
      }
      else {
        Tcl_SetObjResult(local_40,*piVar5);
      }
    }
    if ((piVar11 == (int *)0x0) ||
       (*piVar11 = *piVar11 + -1, pcVar8 = TclFreeObj_exref, 0 < *piVar11)) goto LAB_0068bb26;
    TclFreeObj();
    uVar10 = 0;
  }
  else {
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1);
    }
    iVar3 = __stricmp((char *)ppuVar4,"nextstart");
    if (iVar3 != 0) {
      if (piVar1 == (int *)0x0) {
        ppuVar4 = &PTR_0071ce50;
      }
      else {
        ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1);
      }
      iVar3 = __stricmp((char *)ppuVar4,"laststart");
      if (iVar3 != 0) {
        pcVar13 = "duration";
        pcVar6 = (char *)FUN_006bafc0();
        iVar3 = __stricmp(pcVar6,pcVar13);
        if (iVar3 != 0) {
          pcVar13 = "end";
          pcVar6 = (char *)FUN_006bafc0();
          iVar3 = __stricmp(pcVar6,pcVar13);
          if (iVar3 != 0) {
            pcVar13 = "nextend";
            pcVar6 = (char *)FUN_006bafc0();
            iVar3 = __stricmp(pcVar6,pcVar13);
            if (iVar3 != 0) {
              pcVar13 = "lastend";
              pcVar6 = (char *)FUN_006bafc0();
              iVar3 = __stricmp(pcVar6,pcVar13);
              if (iVar3 != 0) {
                if (piVar1 != (int *)0x0) {
                  *piVar1 = *piVar1 + 1;
                }
                FUN_006bc6a0("use either \'start\' or \'duration\'",piVar1);
                uVar10 = 1;
                pcVar8 = TclFreeObj_exref;
                goto LAB_0068bb4d;
              }
            }
          }
        }
      }
    }
    FUN_006bad90();
    FUN_006bc670();
    FUN_006bad60();
LAB_0068bb26:
    uVar10 = 0;
    pcVar8 = TclFreeObj_exref;
  }
LAB_0068bb4d:
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    (*pcVar8)();
  }
LAB_0068bc0b:
  local_8._0_1_ = 4;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0();
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

