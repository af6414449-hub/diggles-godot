
undefined4
CTclGlobalMethods__IRandom(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined8 uVar9;
  int local_34;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c415;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e10) &&
     (FUN_006cebf4(&DAT_00ca6e10,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6e10 == -1)) {
    iVar5 = DAT_00783650 * 0x40;
    DAT_00ca6e14 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar5) = "TCL:CTclGlobalMethods::IRandom()";
    *(int *)(&DAT_00773650 + iVar5) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e10);
  }
  iVar5 = DAT_00ca6e14;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e14 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar1;
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
  uVar8 = param_3;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004298b0(param_3,param_4);
  uVar3 = FUN_0049c670();
  if (uVar8 != 2) {
    if (uVar8 == 3) {
      if (local_1c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_20 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar7 = local_24 + 2;
      }
      piVar4 = (int *)*puVar7;
      if (piVar4 == (int *)0x0) {
        uVar6 = 0;
      }
      else {
        *piVar4 = *piVar4 + 1;
        iVar2 = Tcl_GetIntFromObj(0,piVar4,&param_3);
        *piVar4 = *piVar4 + -1;
        uVar6 = -(uint)(iVar2 != 1) & param_3;
        if (*piVar4 < 1) {
          TclFreeObj(piVar4);
        }
      }
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_24;
        if (local_20 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_20 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar7 = local_24 + 1;
      }
      piVar4 = (int *)*puVar7;
      if (piVar4 == (int *)0x0) {
        uVar8 = 0;
      }
      else {
        *piVar4 = *piVar4 + 1;
        iVar2 = Tcl_GetIntFromObj(0,piVar4,&param_3);
        *piVar4 = *piVar4 + -1;
        uVar8 = -(uint)(iVar2 != 1) & param_3;
        if (*piVar4 < 1) {
          TclFreeObj(piVar4);
        }
      }
      if (uVar6 == 0) {
        uVar6 = 0x7fffffff;
      }
      uVar8 = uVar8 + (int)(uVar3 & 0x7fffffff) % (int)(uVar6 - uVar8);
    }
    else {
      uVar8 = uVar3 & 0x7fff;
    }
    goto LAB_0062fa0b;
  }
  if (local_1c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_24;
    if (local_20 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_24 + 1;
  }
  piVar4 = (int *)*puVar7;
  if (piVar4 == (int *)0x0) {
LAB_0062f8d7:
    uVar8 = 0x7fffffff;
  }
  else {
    *piVar4 = *piVar4 + 1;
    iVar2 = Tcl_GetIntFromObj(0,piVar4,&param_3);
    *piVar4 = *piVar4 + -1;
    uVar8 = -(uint)(iVar2 != 1) & param_3;
    if (*piVar4 < 1) {
      TclFreeObj(piVar4);
    }
    if (uVar8 == 0) goto LAB_0062f8d7;
  }
  uVar8 = (uint)((longlong)(ulonglong)(uVar3 & 0x7fffffff) % (longlong)(int)uVar8);
LAB_0062fa0b:
  piVar4 = (int *)Tcl_NewIntObj(uVar8);
  *piVar4 = *piVar4 + 1;
  iVar2 = *piVar4;
  if (local_34 != 0) {
    Tcl_SetObjResult(local_34,piVar4);
    iVar2 = *piVar4;
  }
  *piVar4 = iVar2 + -1;
  if (iVar2 + -1 < 1) {
    TclFreeObj(piVar4);
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  if (local_24 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

