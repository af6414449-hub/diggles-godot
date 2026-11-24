
undefined4
CTclGlobalMethods__LGTPMapFilter
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  undefined8 uVar11;
  int local_54;
  char local_50;
  int *local_4c;
  int *local_48;
  undefined4 *local_44;
  uint local_40;
  int local_3c;
  int *local_2c;
  int *local_24;
  int local_20;
  int *local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e5d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca71e0) &&
     (FUN_006cebf4(&DAT_00ca71e0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca71e0 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca71e4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CTclGlobalMethods::LGTPMapFilter()";
    *(int *)(&DAT_00773650 + iVar10) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca71e0);
  }
  iVar10 = DAT_00ca71e4;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca71e4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar9;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar2 == 0) {
    uVar11 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
    if (local_3c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_44;
      if (local_40 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_40 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_44 + 1;
    }
    piVar8 = (int *)*puVar7;
    if (piVar8 != (int *)0x0) {
      *piVar8 = *piVar8 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    local_1c = piVar8;
    iVar2 = FUN_0058a820();
    iVar10 = 0;
    do {
      local_18 = iVar10;
      if (piVar8 == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar3 = Tcl_ListObjLength(0,piVar8,&local_20);
        iVar5 = local_20;
        if (iVar3 != 0) {
          iVar5 = 0;
        }
      }
      if (iVar5 <= iVar10) {
        uVar9 = 0;
        goto LAB_0064ff48;
      }
      if ((piVar8 == (int *)0x0) ||
         (iVar10 = Tcl_ListObjIndex(0,piVar8,iVar10,&local_24), iVar10 != 0)) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = local_24;
        if (local_24 != (int *)0x0) {
          *local_24 = *local_24 + 1;
        }
      }
      local_8._0_1_ = 4;
      if (piVar8 == (int *)0x0) {
        ppuVar4 = &PTR_0071ce50;
      }
      else {
        ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar8,0);
      }
      FUN_006b8fb0(ppuVar4);
      local_8 = CONCAT31(local_8._1_3_,5);
      if (local_2c != (int *)0x0) {
        *local_2c = *local_2c + 1;
      }
      iVar10 = FUN_00582fc0(local_2c);
      local_14 = iVar10;
      if (iVar10 == -1) {
        bVar1 = true;
      }
      else {
        uVar6 = 0;
        if (0 < *(int *)(iVar2 + 0x44)) {
          do {
            if (*(uint *)(iVar2 + 0x44) <= uVar6) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar10 = local_14;
            }
            if (iVar10 == *(int *)(*(int *)(iVar2 + 0x40) + uVar6 * 4)) {
              FUN_005649f0(uVar6);
              break;
            }
            uVar6 = uVar6 + 1;
          } while ((int)uVar6 < *(int *)(iVar2 + 0x44));
        }
        bVar1 = false;
      }
      local_8._0_1_ = 6;
      if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
        TclFreeObj(piVar8);
      }
      if (bVar1) goto LAB_0064ff26;
      iVar10 = local_18 + 1;
      piVar8 = local_1c;
    } while( true );
  }
  FUN_006bc8f0(1);
  uVar9 = 1;
LAB_0064ff5d:
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_44 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_50 != '\0') && (local_54 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_54);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 9;
  if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,10);
  if ((local_4c != (int *)0x0) && (*local_4c = *local_4c + -1, *local_4c == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
LAB_0064ff26:
  FUN_006bc6a0("invalid Template",0);
  uVar9 = 1;
  piVar8 = local_1c;
LAB_0064ff48:
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
    TclFreeObj(piVar8);
  }
  goto LAB_0064ff5d;
}

