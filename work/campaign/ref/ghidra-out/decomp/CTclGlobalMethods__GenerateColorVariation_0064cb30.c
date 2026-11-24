
void CTclGlobalMethods__GenerateColorVariation
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  code *pcVar7;
  undefined8 uVar8;
  undefined1 local_24 [4];
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e12d;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7178) &&
     (FUN_006cebf4(&DAT_00ca7178,local_14), iVar4 = DAT_00783650, DAT_00ca7178 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca717c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::GenerateColorVariation()";
    *(int *)(&DAT_00773650 + iVar5) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7178);
  }
  iVar5 = DAT_00ca717c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca717c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar5 * 0x10];
  if (iVar4 == 0) {
    uVar8 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar5 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar5 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar5 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 6) {
    FUN_006bc8f0(5);
  }
  else {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_20;
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_20 + 1;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 != (int *)0x0) {
      iVar4 = *piVar2;
      *piVar2 = iVar4 + 1;
      if (iVar4 + 1 < 1) {
        TclFreeObj(piVar2);
      }
      Tcl_GetIntFromObj(0,piVar2,local_24);
    }
    if (local_18 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_20;
      }
    }
    else {
      if (local_1c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_20 + 2;
    }
    piVar3 = (int *)*puVar6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
      *piVar3 = *piVar3 + 1;
    }
    pcVar7 = TclFreeObj_exref;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, pcVar7 = TclFreeObj_exref, *piVar2 < 1))
    {
      TclFreeObj(piVar2);
    }
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + -1;
      if (*piVar3 < 1) {
        (*pcVar7)(piVar3);
      }
      Tcl_GetIntFromObj(0,piVar3,local_24);
    }
    if (local_18 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_20;
      }
    }
    else {
      if (local_1c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_20 + 3;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
      *piVar2 = *piVar2 + 1;
    }
    pcVar7 = TclFreeObj_exref;
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, pcVar7 = TclFreeObj_exref, *piVar3 < 1))
    {
      TclFreeObj(piVar3);
    }
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        (*pcVar7)(piVar2);
      }
      Tcl_GetIntFromObj(0,piVar2,local_24);
    }
    if (local_18 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_20;
      }
    }
    else {
      if (local_1c < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_20 + 4;
    }
    piVar3 = (int *)*puVar6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
      *piVar3 = *piVar3 + 1;
    }
    pcVar7 = TclFreeObj_exref;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, pcVar7 = TclFreeObj_exref, *piVar2 < 1))
    {
      TclFreeObj(piVar2);
    }
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + -1;
      if (*piVar3 < 1) {
        (*pcVar7)(piVar3);
      }
      Tcl_GetIntFromObj(0,piVar3,local_24);
    }
    if (local_18 < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar6 = local_20;
      }
    }
    else {
      if (local_1c < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_20 + 5;
    }
    piVar2 = (int *)*puVar6;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
      *piVar2 = *piVar2 + 1;
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      (*pcVar7)(piVar3);
    }
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        (*pcVar7)(piVar2);
      }
      Tcl_GetIntFromObj(0,piVar2,local_24);
      *piVar2 = *piVar2 + -1;
      if (*piVar2 < 1) {
        (*pcVar7)(piVar2);
      }
    }
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

