
undefined4
CTclGlobalMethods__LOr(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  code *pcVar10;
  int *piVar11;
  int *piVar12;
  bool bVar13;
  undefined8 uVar14;
  int local_58;
  char local_54;
  int *local_50;
  int *local_4c;
  undefined4 *local_48;
  uint local_44;
  int local_40;
  int *local_38;
  int *local_34;
  int local_30;
  int *local_2c;
  int local_28;
  uint local_24;
  int local_20;
  undefined **local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ed25;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca72f0) &&
     (FUN_006cebf4(&DAT_00ca72f0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca72f0 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca72f4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::LOr()";
    *(int *)(&DAT_00773650 + iVar8) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca72f0);
  }
  iVar8 = DAT_00ca72f4;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca72f4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar9;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar2 == 0) {
    uVar14 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 < 3) {
    FUN_006bc8f0(2);
    uVar9 = 1;
    goto LAB_0065a265;
  }
  FUN_004298b0(param_3,param_4);
  piVar12 = (int *)0x0;
  local_24 = 1;
  pcVar10 = TclFreeObj_exref;
  do {
    uVar7 = local_24;
    if ((int)local_24 < local_40) {
      if (local_44 <= local_24) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_48 + uVar7;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    local_18 = (int *)*puVar3;
    if (local_18 != (int *)0x0) {
      *local_18 = *local_18 + 1;
    }
    iVar2 = 0;
LAB_00659ffa:
    local_14 = iVar2;
    if (local_18 == (int *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar4 = Tcl_ListObjLength(0,local_18,&local_28);
      iVar8 = local_28;
      if (iVar4 != 0) {
        iVar8 = 0;
      }
    }
    if (iVar2 < iVar8) {
      if (((local_18 == (int *)0x0) ||
          (iVar2 = Tcl_ListObjIndex(0,local_18,iVar2,&local_2c), piVar11 = local_2c, iVar2 != 0)) ||
         (local_2c == (int *)0x0)) {
        local_1c = &PTR_0071ce50;
      }
      else {
        *local_2c = *local_2c + 1;
        local_1c = (undefined **)Tcl_GetStringFromObj(local_2c,0);
        *piVar11 = *piVar11 + -1;
        if (*piVar11 < 1) {
          TclFreeObj(piVar11);
        }
      }
      iVar2 = 0;
      while( true ) {
        local_20 = iVar2;
        if (piVar12 == (int *)0x0) {
          iVar8 = 0;
        }
        else {
          iVar4 = Tcl_ListObjLength(0,piVar12,&local_30);
          iVar8 = local_30;
          if (iVar4 != 0) {
            iVar8 = 0;
          }
        }
        if (iVar8 <= iVar2) break;
        if (((piVar12 == (int *)0x0) ||
            (iVar2 = Tcl_ListObjIndex(0,piVar12,iVar2,&local_34), piVar11 = local_34, iVar2 != 0))
           || (local_34 == (int *)0x0)) {
          ppuVar5 = &PTR_0071ce50;
          ppuVar6 = local_1c;
        }
        else {
          *local_34 = *local_34 + 1;
          ppuVar5 = (undefined **)Tcl_GetStringFromObj(local_34,0);
          *piVar11 = *piVar11 + -1;
          ppuVar6 = local_1c;
          if (*piVar11 < 1) {
            TclFreeObj(piVar11);
            ppuVar6 = local_1c;
          }
        }
        do {
          bVar1 = *(byte *)ppuVar6;
          bVar13 = bVar1 < *(byte *)ppuVar5;
          if (bVar1 != *(byte *)ppuVar5) {
LAB_0065a110:
            uVar7 = -(uint)bVar13 | 1;
            goto LAB_0065a115;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar6 + 1);
          bVar13 = bVar1 < *(byte *)((int)ppuVar5 + 1);
          if (bVar1 != *(byte *)((int)ppuVar5 + 1)) goto LAB_0065a110;
          ppuVar5 = (undefined **)((int)ppuVar5 + 2);
          ppuVar6 = (undefined **)((int)ppuVar6 + 2);
        } while (bVar1 != 0);
        uVar7 = 0;
LAB_0065a115:
        if (uVar7 == 0) goto LAB_0065a1a5;
        iVar2 = local_20 + 1;
      }
      if (local_18 == (int *)0x0) {
        piVar11 = (int *)0x0;
      }
      else {
        iVar2 = Tcl_ListObjIndex(0,local_18,local_14,&local_38);
        if (iVar2 == 0) {
          piVar11 = local_38;
          if (local_38 != (int *)0x0) {
            *local_38 = *local_38 + 1;
          }
        }
        else {
          piVar11 = (int *)0x0;
        }
      }
      if (piVar12 == (int *)0x0) {
        piVar12 = (int *)Tcl_NewListObj(0,0);
        if (piVar12 != (int *)0x0) {
          *piVar12 = *piVar12 + 1;
          goto LAB_0065a16c;
        }
        if (piVar11 != (int *)0x0) goto LAB_0065a1c3;
      }
      else {
LAB_0065a16c:
        if (1 < *piVar12) {
          *piVar12 = *piVar12 + -1;
          piVar12 = (int *)Tcl_DuplicateObj(piVar12);
          *piVar12 = *piVar12 + 1;
        }
        if (piVar11 != (int *)0x0) {
          if (*piVar11 < 2) {
            Tcl_ListObjAppendElement(0,piVar12,piVar11);
          }
          else {
            uVar9 = Tcl_DuplicateObj();
            Tcl_ListObjAppendElement(0,piVar12,uVar9);
          }
LAB_0065a1c3:
          *piVar11 = *piVar11 + -1;
          pcVar10 = TclFreeObj_exref;
          if (*piVar11 < 1) {
            TclFreeObj(piVar11);
            iVar2 = local_14 + 1;
            goto LAB_00659ffa;
          }
        }
      }
LAB_0065a1a5:
      iVar2 = local_14 + 1;
      pcVar10 = TclFreeObj_exref;
      goto LAB_00659ffa;
    }
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
      (*pcVar10)(local_18);
    }
    local_24 = local_24 + 1;
  } while ((int)local_24 < param_3);
  if (local_58 == 0) {
    if (piVar12 != (int *)0x0) goto LAB_0065a22e;
  }
  else if (piVar12 == (int *)0x0) {
    Tcl_ResetResult(local_58);
  }
  else {
    Tcl_SetObjResult(local_58,piVar12);
LAB_0065a22e:
    *piVar12 = *piVar12 + -1;
    if (*piVar12 < 1) {
      (*pcVar10)(piVar12);
    }
  }
  local_8._0_1_ = 2;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_004297b0(0);
  uVar9 = 0;
  if (local_48 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
LAB_0065a265:
  if ((local_54 != '\0') && (local_58 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_58);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 4;
  if ((local_4c != (int *)0x0) && (*local_4c = *local_4c + -1, *local_4c == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  if ((local_50 != (int *)0x0) && (*local_50 = *local_50 + -1, *local_50 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

