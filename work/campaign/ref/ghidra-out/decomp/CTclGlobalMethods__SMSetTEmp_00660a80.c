
undefined4
CTclGlobalMethods__SMSetTEmp(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined **ppuVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  code *pcVar10;
  int *piVar11;
  undefined8 uVar12;
  int local_74;
  char local_70;
  int *local_6c;
  int *local_68;
  undefined4 *local_64;
  uint local_60;
  int local_5c;
  uint local_4c;
  int *local_48;
  int *local_44;
  uint local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070f1e8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca73a0) &&
     (FUN_006cebf4(&DAT_00ca73a0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca73a0 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca73a4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::SMSetTEmp()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca73a0);
  }
  iVar4 = DAT_00ca73a4;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca73a4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar9;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar2 == 0) {
    uVar12 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar6 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar6 == (int *)0x2) {
    if (local_5c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_64;
      if (local_60 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_60 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_64 + 1;
    }
    local_14 = (int *)*puVar3;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    iVar2 = 0;
    while( true ) {
      local_1c = iVar2;
      if (local_14 == (int *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar7 = Tcl_ListObjLength(0,local_14,&local_20);
        iVar4 = local_20;
        if (iVar7 != 0) {
          iVar4 = 0;
        }
      }
      if (iVar4 <= iVar2) break;
      if ((local_14 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,local_14,iVar2,&local_24), iVar4 != 0)) {
        local_18 = (int *)0x0;
      }
      else {
        local_18 = local_24;
        if (local_24 != (int *)0x0) {
          *local_24 = *local_24 + 1;
        }
      }
      piVar6 = local_18;
      if ((local_18 == (int *)0x0) || (iVar4 = Tcl_ListObjIndex(0,local_18,0,&local_28), iVar4 != 0)
         ) {
        local_2c = (int *)0x0;
      }
      else {
        local_2c = local_28;
        if (local_28 != (int *)0x0) {
          *local_28 = *local_28 + 1;
        }
      }
      piVar11 = local_2c;
      local_8 = CONCAT31(local_8._1_3_,5);
      if (local_2c == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(local_2c,0);
      }
      FUN_006b8fb0(ppuVar5);
      pcVar10 = TclFreeObj_exref;
      if ((piVar11 != (int *)0x0) &&
         (*piVar11 = *piVar11 + -1, pcVar10 = TclFreeObj_exref, *piVar11 < 1)) {
        TclFreeObj(piVar11);
      }
      local_8._0_1_ = 8;
      if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
        (*pcVar10)(piVar6);
      }
      piVar1 = param_3;
      piVar6 = param_3 + 3;
      iVar4 = FUN_006cfeb0(piVar6,0x2f);
      piVar11 = piVar1;
      if ((iVar4 != 0) && (0 < (iVar4 - (int)piVar1) + -0xc)) {
        iVar7 = piVar1[2];
        if (iVar7 == -1) {
          do {
            iVar7 = *piVar6;
            piVar6 = (int *)((int)piVar6 + 1);
          } while ((char)iVar7 != '\0');
          iVar7 = (int)piVar6 - ((int)piVar1 + 0xd);
          piVar1[2] = iVar7;
        }
        piVar6 = (int *)FUN_006b9b20(&local_30,(iVar4 - (int)piVar1) + -0xb,iVar7);
        local_8._0_1_ = 9;
        piVar11 = (int *)*piVar6;
        if (piVar11 != (int *)0x0) {
          *piVar11 = *piVar11 + 1;
        }
        param_3 = piVar11;
        if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 == 0)) {
          FUN_006ba940();
        }
        piVar11[2] = *(int *)(*piVar6 + 8);
        local_8._0_1_ = 10;
        if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
          FUN_006ba940();
        }
        local_8._0_1_ = 8;
      }
      iVar4 = FUN_006cfeb0(piVar11 + 3,0x2e);
      piVar6 = piVar11;
      if ((iVar4 != 0) && (iVar4 = (iVar4 - (int)piVar11) + -0xc, 0 < iVar4)) {
        FUN_006b9b20(&local_34,0,iVar4);
        piVar6 = local_34;
        local_8._0_1_ = 0xb;
        param_3 = local_34;
        if (local_34 != (int *)0x0) {
          *local_34 = *local_34 + 1;
        }
        if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 == 0)) {
          FUN_006ba940();
        }
        local_8._0_1_ = 0xc;
        *piVar6 = *piVar6 + -1;
        if (*piVar6 == 0) {
          FUN_006ba940();
        }
        local_8._0_1_ = 8;
      }
      if ((local_14 == (int *)0x0) ||
         (iVar4 = Tcl_ListObjIndex(0,local_14,iVar2,&local_38), piVar11 = local_38, iVar4 != 0)) {
        piVar11 = (int *)0x0;
LAB_00660df7:
        local_18 = (int *)0x0;
      }
      else {
        if (local_38 == (int *)0x0) goto LAB_00660df7;
        *local_38 = *local_38 + 1;
        iVar4 = Tcl_ListObjIndex(0,local_38,1,&local_3c);
        if ((iVar4 != 0) || (local_2c = local_3c, local_3c == (int *)0x0)) goto LAB_00660df7;
        *local_3c = *local_3c + 1;
        iVar4 = Tcl_GetIntFromObj(0,local_3c,&local_40);
        local_18 = (int *)(-(uint)(iVar4 != 1) & local_40);
        *local_2c = *local_2c + -1;
        if (*local_2c < 1) {
          TclFreeObj(local_2c);
        }
      }
      if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
        TclFreeObj(piVar11);
      }
      if ((local_14 == (int *)0x0) ||
         (iVar2 = Tcl_ListObjIndex(0,local_14,iVar2,&local_44), piVar11 = local_44, iVar2 != 0)) {
        piVar11 = (int *)0x0;
LAB_00660e8a:
        uVar8 = 0;
      }
      else {
        if (local_44 == (int *)0x0) goto LAB_00660e8a;
        *local_44 = *local_44 + 1;
        iVar2 = Tcl_ListObjIndex(0,local_44,2,&local_48);
        if ((iVar2 != 0) || (local_2c = local_48, local_48 == (int *)0x0)) goto LAB_00660e8a;
        *local_48 = *local_48 + 1;
        iVar2 = Tcl_GetIntFromObj(0,local_48,&local_4c);
        *local_2c = *local_2c + -1;
        uVar8 = -(uint)(iVar2 != 1) & local_4c;
        if (*local_2c < 1) {
          TclFreeObj(local_2c);
        }
      }
      if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
        TclFreeObj(piVar11);
      }
      if (DAT_00772474 == 0) {
        iVar2 = FUN_006ba810(0x189);
        local_8._0_1_ = 0xd;
        if (iVar2 == 0) {
          DAT_00772474 = 0;
        }
        else {
          DAT_00772474 = FUN_005f7ec0();
        }
        local_8._0_1_ = 8;
      }
      FUN_005fa320(&param_3,local_18,uVar8);
      local_8 = CONCAT31(local_8._1_3_,0xe);
      if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
        FUN_006ba940();
      }
      iVar2 = local_1c + 1;
    }
    uVar9 = 0;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
      TclFreeObj(local_14);
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar9 = 1;
  }
  local_8._0_1_ = 0xf;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x10);
  FUN_004297b0(0);
  if (local_64 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_70 != '\0') && (local_74 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_74);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 0x11;
  if ((local_68 != (int *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0x12);
  if ((local_6c != (int *)0x0) && (*local_6c = *local_6c + -1, *local_6c == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

