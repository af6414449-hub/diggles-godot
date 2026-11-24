
undefined4
CTclGlobalMethods__LGGetLevel
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  code *pcVar10;
  bool bVar11;
  undefined8 uVar12;
  int local_5c;
  int local_4c;
  uint local_3c;
  uint local_38;
  int *local_34;
  int local_30;
  uint *local_2c;
  int *local_28;
  int *local_24;
  uint local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e87d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7240) &&
     (FUN_006cebf4(&DAT_00ca7240,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7240 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca7244 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::LGGetLevel()";
    *(int *)(&DAT_00773650 + iVar6) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7240);
  }
  iVar6 = DAT_00ca7244;
  uVar5 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7244 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar5;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar2 == 0) {
    uVar12 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_18 = (int *)0x0;
  local_8 = CONCAT31(local_8._1_3_,3);
  iVar2 = FUN_0058a820();
  local_20 = 0;
  local_30 = FUN_005f8080();
  local_14 = 0;
  pcVar10 = RaiseException_exref;
  while (iVar6 = local_14, (int)local_20 < (int)*(uint *)(iVar2 + 0x188)) {
    if (*(uint *)(iVar2 + 0x188) <= local_20) {
      (*pcVar10)(0xc000008c,1,0,0);
    }
    uVar9 = *(uint *)(*(int *)(iVar2 + 0x184) + iVar6);
    if (*(uint *)(iVar2 + 0x1a8) <= uVar9) {
      (*pcVar10)(0xc000008c,1,0,0);
    }
    if (*(char *)(uVar9 * 0x54 + 0x41 + *(int *)(iVar2 + 0x1a4)) != '\0') {
      if (*(uint *)(iVar2 + 0x188) <= local_20) {
        (*pcVar10)(0xc000008c,1,0,0);
      }
      uVar9 = *(uint *)(*(int *)(iVar2 + 0x184) + local_14);
      if (*(uint *)(iVar2 + 0x1a8) <= uVar9) {
        (*pcVar10)(0xc000008c,1,0,0);
      }
      piVar1 = (int *)(uVar9 * 0x54 + 0x50 + *(int *)(iVar2 + 0x1a4));
      *piVar1 = *piVar1 + 1;
    }
    uVar9 = local_20;
    local_14 = local_14 + 0x10;
    uVar3 = local_20 + 1;
    bVar11 = *(uint *)(iVar2 + 0x188) <= local_20;
    local_20 = uVar3;
    if (bVar11) {
      (*pcVar10)(0xc000008c,1,0,0);
    }
    local_2c = (uint *)(uVar9 * 0x10 + *(int *)(iVar2 + 0x184));
    if (local_2c == (uint *)0x0) break;
    uVar9 = *local_2c;
    if (*(uint *)(iVar2 + 0x1a8) <= uVar9) {
      (*pcVar10)(0xc000008c,1,0,0);
    }
    piVar1 = *(int **)(uVar9 * 0x54 + *(int *)(iVar2 + 0x1a4));
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    piVar4 = piVar1 + 3;
    local_8._0_1_ = 5;
    local_28 = piVar1;
    if (piVar4 != (int *)0x0) {
      piVar4 = (int *)Tcl_NewStringObj(piVar4,0xffffffff);
      *piVar4 = *piVar4 + 1;
    }
    local_24 = piVar4;
    piVar4 = (int *)Tcl_NewListObj(0,0);
    local_1c = piVar4;
    if (piVar4 == (int *)0x0) {
LAB_00652f71:
      if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 < 1)) {
        TclFreeObj(local_24);
      }
    }
    else {
      iVar6 = *piVar4;
      *piVar4 = iVar6 + 1;
      if (1 < iVar6 + 1) {
        *piVar4 = iVar6;
        if (iVar6 < 1) {
          TclFreeObj(piVar4);
        }
        piVar4 = (int *)Tcl_DuplicateObj(piVar4);
        *piVar4 = *piVar4 + 1;
      }
      local_1c = piVar4;
      if (local_24 != (int *)0x0) {
        if (*local_24 < 2) {
          Tcl_ListObjAppendElement(0,piVar4,local_24);
        }
        else {
          uVar5 = Tcl_DuplicateObj();
          Tcl_ListObjAppendElement(0,piVar4,uVar5);
        }
        goto LAB_00652f71;
      }
    }
    local_24 = (int *)Tcl_NewIntObj(local_2c[1]);
    *local_24 = *local_24 + 1;
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)Tcl_NewListObj(0,0);
      local_1c = piVar4;
      if (piVar4 != (int *)0x0) {
        *piVar4 = *piVar4 + 1;
        goto LAB_00652fb7;
      }
    }
    else {
LAB_00652fb7:
      if (1 < *piVar4) {
        *piVar4 = *piVar4 + -1;
        piVar4 = (int *)Tcl_DuplicateObj(piVar4);
        *piVar4 = *piVar4 + 1;
        local_1c = piVar4;
      }
      if (*local_24 < 2) {
        Tcl_ListObjAppendElement(0,piVar4,local_24);
      }
      else {
        uVar5 = Tcl_DuplicateObj();
        Tcl_ListObjAppendElement(0,piVar4,uVar5);
      }
    }
    *local_24 = *local_24 + -1;
    if (*local_24 < 1) {
      TclFreeObj(local_24);
    }
    local_24 = (int *)Tcl_NewIntObj(local_2c[2]);
    *local_24 = *local_24 + 1;
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)Tcl_NewListObj(0,0);
      local_1c = piVar4;
      if (piVar4 != (int *)0x0) {
        *piVar4 = *piVar4 + 1;
        goto LAB_0065303e;
      }
    }
    else {
LAB_0065303e:
      if (1 < *piVar4) {
        *piVar4 = *piVar4 + -1;
        piVar4 = (int *)Tcl_DuplicateObj(piVar4);
        *piVar4 = *piVar4 + 1;
        local_1c = piVar4;
      }
      if (*local_24 < 2) {
        Tcl_ListObjAppendElement(0,piVar4,local_24);
      }
      else {
        uVar5 = Tcl_DuplicateObj();
        Tcl_ListObjAppendElement(0,piVar4,uVar5);
      }
    }
    *local_24 = *local_24 + -1;
    if (*local_24 < 1) {
      TclFreeObj(local_24);
    }
    if (local_18 == (int *)0x0) {
      local_18 = (int *)Tcl_NewListObj(0,0);
      if (local_18 != (int *)0x0) {
        *local_18 = *local_18 + 1;
        goto LAB_006530b2;
      }
    }
    else {
LAB_006530b2:
      if (1 < *local_18) {
        *local_18 = *local_18 + -1;
        local_18 = (int *)Tcl_DuplicateObj(local_18);
        *local_18 = *local_18 + 1;
      }
      if (piVar4 != (int *)0x0) {
        if (*piVar4 < 2) {
          Tcl_ListObjAppendElement(0,local_18,piVar4);
        }
        else {
          uVar5 = Tcl_DuplicateObj();
          Tcl_ListObjAppendElement(0,local_18,uVar5);
        }
      }
    }
    iVar6 = FUN_006cfeb0(piVar1 + 3,0x2f);
    piVar7 = piVar1;
    if ((iVar6 != 0) && (0 < (iVar6 - (int)piVar1) + -0xc)) {
      iVar8 = piVar1[2];
      if (iVar8 == -1) {
        piVar7 = piVar1 + 3;
        local_24 = (int *)((int)piVar1 + 0xd);
        do {
          iVar8 = *piVar7;
          piVar7 = (int *)((int)piVar7 + 1);
        } while ((char)iVar8 != '\0');
        iVar8 = (int)piVar7 - (int)local_24;
        piVar1[2] = iVar8;
      }
      local_24 = (int *)FUN_006b9b20(&local_34,(iVar6 - (int)piVar1) + -0xb,iVar8);
      local_8._0_1_ = 6;
      piVar7 = (int *)*local_24;
      if (piVar7 != (int *)0x0) {
        *piVar7 = *piVar7 + 1;
      }
      local_28 = piVar7;
      if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
        FUN_006ba940();
      }
      piVar7[2] = *(int *)(*local_24 + 8);
      local_8._0_1_ = 7;
      if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 5;
    }
    FUN_00583bd0(&local_28,&local_3c,&local_38);
    uVar9 = local_38 & 0x80000003;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xfffffffc) + 1;
    }
    uVar3 = local_3c & 0x80000003;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
    }
    FUN_005fa510((int)(local_2c[1] + ((int)local_2c[1] >> 0x1f & 3U)) >> 2,
                 (int)(local_2c[2] + ((int)local_2c[2] >> 0x1f & 3U)) >> 2,
                 (uint)(uVar3 != 0) + ((int)(local_3c + ((int)local_3c >> 0x1f & 3U)) >> 2),
                 (uint)(uVar9 != 0) + ((int)(local_38 + ((int)local_38 >> 0x1f & 3U)) >> 2));
    *(undefined4 *)(local_30 + 0x98) = 0;
    local_8._0_1_ = 8;
    if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 == 0)) {
      FUN_006ba940();
    }
    pcVar10 = RaiseException_exref;
    local_8 = CONCAT31(local_8._1_3_,3);
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
  }
  FUN_0058a310();
  piVar1 = local_18;
  if (local_5c == 0) {
    if (local_18 == (int *)0x0) goto LAB_006532a1;
  }
  else {
    if (local_18 == (int *)0x0) {
      Tcl_ResetResult(local_5c);
      goto LAB_006532a1;
    }
    Tcl_SetObjResult(local_5c,local_18);
  }
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 1) {
    TclFreeObj(piVar1);
  }
LAB_006532a1:
  local_8._0_1_ = 9;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_004297b0(0);
  if (local_4c != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

