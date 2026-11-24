
undefined4
CTclGlobalMethods__GetOwnerAttribList
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined8 uVar8;
  int local_44;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  int *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c835;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6dc0) &&
     (FUN_006cebf4(&DAT_00ca6dc0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6dc0 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca6dc4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::GetOwnerAttribList()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6dc0);
  }
  iVar4 = DAT_00ca6dc4;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6dc4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar8 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar8;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)param_3 < 2) {
    FUN_006bc8f0(1);
    uVar6 = 1;
    goto LAB_0062d5d8;
  }
  if (local_2c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_34;
    if (local_30 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_34 + 1;
  }
  piVar1 = (int *)*puVar5;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (piVar1 == (int *)0x0) {
    param_3 = (int *)0x0;
LAB_0062d480:
    piVar3 = (int *)FUN_005da0f0();
    iVar2 = 0;
    local_18 = (int *)0x0;
    if (0 < *piVar3) {
      local_14 = DAT_0077244c + 0x84e4;
      uVar7 = (int)param_3 + 1;
      do {
        if (8 < uVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        uVar6 = FUN_006bad90();
        FUN_006bb930(uVar6);
        if (param_3 != (int *)0x0) {
          *param_3 = *param_3 + -1;
          if (*param_3 < 1) {
            TclFreeObj(param_3);
          }
          param_3 = (int *)0x0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *piVar3);
    }
    piVar3 = local_18;
    if (local_44 == 0) {
LAB_0062d547:
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
        TclFreeObj(piVar3);
      }
    }
    else {
      if (local_18 != (int *)0x0) {
        Tcl_SetObjResult(local_44,local_18);
        goto LAB_0062d547;
      }
      Tcl_ResetResult(local_44);
    }
    uVar6 = 0;
    if (piVar1 == (int *)0x0) goto LAB_0062d5d8;
  }
  else {
    iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_1c);
    if (iVar2 == 1) {
      param_3 = (int *)0x0;
      goto LAB_0062d480;
    }
    param_3 = local_1c;
    if ((-2 < (int)local_1c) && ((int)local_1c < 8)) goto LAB_0062d480;
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_34 + 1;
    }
    piVar3 = (int *)*puVar5;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    FUN_006bc6a0("invalid owner id",piVar3);
    uVar6 = 1;
  }
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 1) {
    TclFreeObj(piVar1);
  }
LAB_0062d5d8:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar6;
}

