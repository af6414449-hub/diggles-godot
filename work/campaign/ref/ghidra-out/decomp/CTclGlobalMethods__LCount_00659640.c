
/* WARNING: Removing unreachable block (ram,0x0065986f) */

undefined4
CTclGlobalMethods__LCount(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  bool bVar11;
  undefined8 uVar12;
  int local_40;
  char local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  uint local_2c;
  int local_28;
  int *local_20;
  int local_1c;
  int local_18;
  undefined **local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ece5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca72e0) &&
     (FUN_006cebf4(&DAT_00ca72e0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca72e0 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca72e4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::LCount()";
    *(int *)(&DAT_00773650 + iVar8) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca72e0);
  }
  iVar8 = DAT_00ca72e4;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca72e4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar9;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar2 == 0) {
    uVar12 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 3) {
    FUN_004298b0(3,param_4);
    if (local_28 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar10 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar10 = local_30 + 1;
    }
    piVar10 = (int *)*piVar10;
    if (piVar10 != (int *)0x0) {
      *piVar10 = *piVar10 + 1;
    }
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar7 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar7 = local_30 + 2;
    }
    if (*piVar7 == 0) {
      local_14 = &PTR_0071ce50;
    }
    else {
      local_14 = (undefined **)Tcl_GetStringFromObj(*piVar7,0);
    }
    iVar8 = 0;
    iVar2 = 0;
LAB_006597c8:
    iVar3 = iVar2;
    local_18 = iVar8;
    if (piVar10 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar4 = Tcl_ListObjLength(0,piVar10,&local_1c);
      iVar2 = local_1c;
      if (iVar4 != 0) {
        iVar2 = 0;
      }
    }
    if (iVar8 < iVar2) {
      if (((piVar10 == (int *)0x0) ||
          (iVar2 = Tcl_ListObjIndex(0,piVar10,iVar8,&local_20), piVar7 = local_20, iVar2 != 0)) ||
         (local_20 == (int *)0x0)) {
        ppuVar5 = &PTR_0071ce50;
        ppuVar6 = local_14;
      }
      else {
        *local_20 = *local_20 + 1;
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(local_20,0);
        *piVar7 = *piVar7 + -1;
        ppuVar6 = local_14;
        if (*piVar7 < 1) {
          TclFreeObj(piVar7);
          ppuVar6 = local_14;
        }
      }
      do {
        bVar1 = *(byte *)ppuVar5;
        bVar11 = bVar1 < *(byte *)ppuVar6;
        if (bVar1 != *(byte *)ppuVar6) {
LAB_00659877:
          iVar8 = local_18 + 1;
          iVar2 = iVar3 + 1;
          if ((-(uint)bVar11 | 1) != 0) {
            iVar2 = iVar3;
          }
          goto LAB_006597c8;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar5 + 1);
        bVar11 = bVar1 < *(byte *)((int)ppuVar6 + 1);
        if (bVar1 != *(byte *)((int)ppuVar6 + 1)) goto LAB_00659877;
        ppuVar5 = (undefined **)((int)ppuVar5 + 2);
        ppuVar6 = (undefined **)((int)ppuVar6 + 2);
      } while (bVar1 != 0);
      iVar8 = local_18 + 1;
      iVar2 = iVar3 + 1;
      goto LAB_006597c8;
    }
    piVar7 = (int *)Tcl_NewIntObj(iVar3);
    *piVar7 = *piVar7 + 1;
    iVar2 = *piVar7;
    if (local_40 != 0) {
      Tcl_SetObjResult(local_40,piVar7);
      iVar2 = *piVar7;
    }
    *piVar7 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj(piVar7);
    }
    uVar9 = 0;
    if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
      TclFreeObj(piVar10);
    }
    local_8._0_1_ = 2;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004297b0(0);
    if (local_30 != (int *)0x0) {
      FUN_006ba940();
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar9 = 1;
  }
  if ((local_3c != '\0') && (local_40 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_40);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 4;
  if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

