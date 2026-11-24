
undefined4
CTclGlobalMethods__DigMark(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  undefined4 uVar8;
  code *pcVar9;
  int *piVar10;
  undefined8 uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  int *local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int *local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ec55;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca72b8) &&
     (FUN_006cebf4(&DAT_00ca72b8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca72b8 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca72bc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::DigMark()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca72b8);
  }
  iVar4 = DAT_00ca72bc;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca72bc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar8;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar11 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar1 < 5) {
    FUN_006bc8f0(4);
    uVar8 = 1;
    goto LAB_00658b8d;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  if (local_38 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar3 = local_40;
    if (local_3c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_3c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar3 = local_40 + 1;
  }
  piVar1 = (int *)*puVar3;
  if (piVar1 == (int *)0x0) {
    local_14 = 0;
  }
  else {
    *piVar1 = *piVar1 + 1;
    *piVar1 = *piVar1 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 1) {
      TclFreeObj(piVar1);
    }
    iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_24);
    local_14 = -(uint)(iVar2 != 1) & local_24;
  }
  if (local_38 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar3 = local_40;
    if (local_3c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_3c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar3 = local_40 + 2;
  }
  piVar10 = (int *)*puVar3;
  if (piVar10 != (int *)0x0) {
    *piVar10 = *piVar10 + 1;
    *piVar10 = *piVar10 + 1;
  }
  pcVar9 = TclFreeObj_exref;
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, pcVar9 = TclFreeObj_exref, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  if (piVar10 == (int *)0x0) {
    local_18 = 0;
  }
  else {
    *piVar10 = *piVar10 + -1;
    if (*piVar10 < 1) {
      (*pcVar9)(piVar10);
    }
    iVar2 = Tcl_GetIntFromObj(0,piVar10,&local_28);
    local_18 = -(uint)(iVar2 != 1) & local_28;
  }
  if (local_38 < 4) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar3 = local_40;
    if (local_3c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_3c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar3 = local_40 + 3;
  }
  piVar1 = (int *)*puVar3;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
    *piVar1 = *piVar1 + 1;
  }
  pcVar9 = TclFreeObj_exref;
  local_30 = piVar1;
  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, pcVar9 = TclFreeObj_exref, *piVar10 < 1)
     ) {
    TclFreeObj(piVar10);
  }
  if (piVar1 == (int *)0x0) {
    local_20 = 0;
  }
  else {
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 1) {
      (*pcVar9)(piVar1);
    }
    iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_2c);
    local_20 = -(uint)(iVar2 != 1) & local_2c;
  }
  if (local_38 < 5) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar3 = local_40;
    if (local_3c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_3c < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar3 = local_40 + 4;
  }
  piVar1 = (int *)*puVar3;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
    *piVar1 = *piVar1 + 1;
  }
  local_1c = piVar1;
  if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 < 1)) {
    TclFreeObj(local_30);
  }
  piVar10 = piVar1;
  if (piVar1 == (int *)0x0) {
LAB_00658a04:
    piVar7 = (int *)0x0;
LAB_00658a06:
    if (5 < (int)param_3) {
      puVar3 = (undefined4 *)FUN_004295e0(5);
      piVar10 = (int *)*puVar3;
      if (piVar10 != (int *)0x0) {
        *piVar10 = *piVar10 + 1;
        *piVar10 = *piVar10 + 1;
      }
      pcVar9 = TclFreeObj_exref;
      param_3 = piVar10;
      local_1c = piVar10;
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, pcVar9 = TclFreeObj_exref, *piVar1 < 1)
         ) {
        TclFreeObj(piVar1);
      }
      if (param_3 == (int *)0x0) {
        uVar6 = 0;
      }
      else {
        *param_3 = *param_3 + -1;
        if (*param_3 < 1) {
          (*pcVar9)(param_3);
        }
        iVar2 = Tcl_GetIntFromObj(0,param_3,&param_3);
        uVar6 = -(uint)(iVar2 != 1) & (uint)param_3;
      }
      goto LAB_00658a8e;
    }
    FUN_006bc8f0(5);
    uVar8 = 1;
  }
  else {
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 1) {
      TclFreeObj(piVar1);
    }
    iVar2 = Tcl_GetIntFromObj(0,piVar1,&local_30);
    if (iVar2 == 1) goto LAB_00658a04;
    uVar6 = 0;
    piVar7 = local_30;
    if (local_30 == (int *)0x0) goto LAB_00658a06;
LAB_00658a8e:
    if ((((PTR_0077241c->cellX0 + 1 <= (int)local_18) && ((int)local_18 < PTR_0077241c->cellX1 + -1)
         ) && (PTR_0077241c->cellY0 + 1 <= (int)local_20)) &&
       (((int)local_20 < PTR_0077241c->cellY1 + -1 && (local_14 < 7)))) {
      if (piVar7 == (int *)0x0) {
        uVar5 = 0;
        if (0 < (int)uVar6) {
          uVar5 = uVar6;
        }
        uVar6 = 3;
        if ((int)uVar5 < 3) {
          uVar6 = uVar5;
        }
        uVar5 = local_18;
        uVar12 = local_20;
        uVar13 = local_14;
        FUN_00566460(local_18,local_20,uVar6,local_14);
        FUN_005671a0(uVar5,uVar12,uVar6,uVar13);
      }
      else if (piVar7 == (int *)0x1) {
        uVar6 = local_18;
        uVar5 = local_20;
        uVar12 = local_18;
        uVar13 = local_14;
        FUN_00566460(local_18,local_20,local_18,local_14);
        FUN_005672d0(uVar6,uVar5,uVar12,uVar13);
      }
      else {
        if (piVar7 != (int *)0x2) {
          uVar8 = 1;
          goto LAB_00658b76;
        }
        FUN_00566460();
        iVar2 = FUN_00592f10(PTR_0077241c);
        iVar4 = local_14 << 2;
        uVar6 = *(uint *)(iVar2 + 8);
        iVar2 = FUN_00592f10(PTR_0077241c);
        *(uint *)(iVar2 + 8) = uVar6 & ~(0xf << ((byte)iVar4 & 0x1f));
      }
    }
    uVar8 = 0;
  }
LAB_00658b76:
  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
    TclFreeObj(piVar10);
  }
LAB_00658b8d:
  local_8._0_1_ = 4;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,5);
  FUN_004297b0(0);
  if (local_40 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
}

