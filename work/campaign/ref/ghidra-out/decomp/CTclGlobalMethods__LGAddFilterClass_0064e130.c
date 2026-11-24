
undefined4
CTclGlobalMethods__LGAddFilterClass
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined **ppuVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  int *piVar13;
  undefined4 uVar14;
  bool bVar15;
  undefined8 uVar16;
  int local_50;
  char local_4c;
  int *local_48;
  int *local_44;
  undefined4 *local_40;
  uint local_3c;
  int local_38;
  int *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e365;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca71a0) &&
     (FUN_006cebf4(&DAT_00ca71a0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar6 = DAT_00783650,
     DAT_00ca71a0 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca71a4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CTclGlobalMethods::LGAddFilterClass()";
    *(int *)(&DAT_00773650 + iVar10) = iVar6;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca71a0);
  }
  iVar10 = DAT_00ca71a4;
  uVar14 = *(undefined4 *)(&DAT_00773650 + DAT_00ca71a4 * 0x40);
  iVar6 = FUN_0043fcc0();
  *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar14;
  *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
  iVar6 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar6 == 0) {
    uVar16 = FUN_006bd180();
    iVar6 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar16;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar6 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
    if (local_38 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar12 = local_40;
      if (local_3c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_3c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar12 = local_40 + 1;
    }
    piVar2 = (int *)*puVar12;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    iVar6 = FUN_0058a820();
    iVar10 = 0;
    while( true ) {
      local_1c = iVar10;
      if (piVar2 == (int *)0x0) {
        iVar9 = 0;
      }
      else {
        iVar7 = Tcl_ListObjLength(0,piVar2,&local_20);
        iVar9 = local_20;
        if (iVar7 != 0) {
          iVar9 = 0;
        }
      }
      if (iVar9 <= iVar10) break;
      if ((piVar2 == (int *)0x0) ||
         (iVar10 = Tcl_ListObjIndex(0,piVar2,iVar10,&local_24), iVar10 != 0)) {
        piVar13 = (int *)0x0;
      }
      else {
        piVar13 = local_24;
        if (local_24 != (int *)0x0) {
          *local_24 = *local_24 + 1;
        }
      }
      local_8._0_1_ = 4;
      if (piVar13 == (int *)0x0) {
        ppuVar8 = &PTR_0071ce50;
      }
      else {
        ppuVar8 = (undefined **)Tcl_GetStringFromObj(piVar13,0);
      }
      FUN_006b8fb0(ppuVar8);
      piVar4 = local_14;
      local_18 = iVar6 + 0x19c;
      local_8 = CONCAT31(local_8._1_3_,5);
      uVar11 = 0;
      if (0 < *(int *)(iVar6 + 0x1a0)) {
        bVar15 = *(int *)(iVar6 + 0x1a0) != 0;
        do {
          if (!bVar15) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          cVar5 = FUN_006b97f0(&local_14);
          if (cVar5 != '\0') goto LAB_0064e391;
          uVar11 = uVar11 + 1;
          bVar15 = uVar11 < *(uint *)(local_18 + 4);
        } while ((int)uVar11 < (int)*(uint *)(local_18 + 4));
      }
      FUN_00444ca0(1);
      uVar11 = *(uint *)(iVar6 + 0x1a0) - 1;
      if (*(uint *)(iVar6 + 0x1a0) <= uVar11) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar3 = *(int **)(*(int *)(iVar6 + 0x19c) + uVar11 * 4);
      piVar1 = (int *)(*(int *)(iVar6 + 0x19c) + uVar11 * 4);
      *piVar1 = (int)piVar4;
      if (piVar4 != (int *)0x0) {
        *piVar4 = *piVar4 + 1;
      }
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
        FUN_006ba940();
      }
      *(int *)(*piVar1 + 8) = piVar4[2];
LAB_0064e391:
      local_8 = CONCAT31(local_8._1_3_,6);
      if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 == 0)) {
        FUN_006ba940();
      }
      if ((piVar13 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 < 1)) {
        TclFreeObj(piVar13);
      }
      iVar10 = local_1c + 1;
    }
    uVar14 = 0;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar14 = 1;
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_40 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_4c != '\0') && (local_50 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_50);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 9;
  if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,10);
  if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar14;
}

