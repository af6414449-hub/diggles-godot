
undefined4
CTclGlobalMethods__LGTPSetFilter
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  undefined4 *puVar11;
  code *pcVar12;
  undefined8 uVar13;
  int local_60;
  char local_5c;
  int *local_58;
  int *local_54;
  undefined4 *local_50;
  uint local_4c;
  int local_48;
  int *local_2c;
  int local_28;
  int local_24;
  int *local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e575;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca71d8) &&
     (FUN_006cebf4(&DAT_00ca71d8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca71d8 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca71dc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclGlobalMethods::LGTPSetFilter()";
    *(int *)(&DAT_00773650 + iVar9) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca71d8);
  }
  iVar9 = DAT_00ca71dc;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca71dc * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar3 == 0) {
    uVar13 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = FUN_0058a820();
  if (param_3 == 2) {
    if (local_48 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_50;
      if (local_4c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_4c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_50 + 1;
    }
    piVar1 = (int *)*puVar11;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    iVar9 = 0;
    do {
      local_24 = iVar9;
      if (piVar1 == (int *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar4 = Tcl_ListObjLength(0,piVar1,&local_28);
        iVar6 = local_28;
        if (iVar4 != 0) {
          iVar6 = 0;
        }
      }
      if (iVar6 <= iVar9) {
        uVar8 = 0;
        goto LAB_0064fb8f;
      }
      if ((piVar1 == (int *)0x0) || (iVar9 = Tcl_ListObjIndex(0,piVar1,iVar9,&local_2c), iVar9 != 0)
         ) {
        piVar10 = (int *)0x0;
      }
      else {
        piVar10 = local_2c;
        if (local_2c != (int *)0x0) {
          *local_2c = *local_2c + 1;
        }
      }
      local_8._0_1_ = 4;
      if (piVar10 == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar10,0);
      }
      FUN_006b8fb0(ppuVar5);
      local_8 = CONCAT31(local_8._1_3_,5);
      local_18 = FUN_00583450(&local_20);
      if (local_18 == 0xffffffff) {
        bVar2 = true;
      }
      else {
        param_3 = 0;
        if (0 < *(int *)(iVar3 + 0x44)) {
          local_1c = local_18 * 0xc;
          pcVar12 = RaiseException_exref;
          do {
            local_14 = 0;
            while( true ) {
              if (*(uint *)(iVar3 + 0x3c) <= local_18) {
                (*pcVar12)(0xc000008c,1,0,0);
              }
              pcVar12 = RaiseException_exref;
              if (*(int *)(local_1c + 8 + *(int *)(iVar3 + 0x38)) <= (int)local_14)
              goto LAB_0064fb1c;
              if (*(uint *)(iVar3 + 0x44) <= param_3) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar9 = *(int *)(iVar3 + 0x40);
              if (*(uint *)(iVar3 + 0x3c) <= local_18) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar6 = *(int *)(iVar3 + 0x38) + local_1c;
              if (*(uint *)(iVar6 + 8) <= local_14) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              if (*(int *)(iVar9 + param_3 * 4) == *(int *)(*(int *)(iVar6 + 4) + local_14 * 4))
              break;
              local_14 = local_14 + 1;
            }
            uVar7 = *(uint *)(iVar3 + 0x44);
            if (uVar7 <= param_3) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              uVar7 = *(uint *)(iVar3 + 0x44);
              if (uVar7 <= param_3) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                uVar7 = *(uint *)(iVar3 + 0x44);
              }
            }
            if ((int)param_3 < (int)(uVar7 - 1)) {
              *(undefined4 *)(*(int *)(iVar3 + 0x40) + param_3 * 4) =
                   *(undefined4 *)(*(int *)(iVar3 + 0x40) + -4 + uVar7 * 4);
              uVar7 = *(uint *)(iVar3 + 0x44);
            }
            param_3 = param_3 - 1;
            *(uint *)(iVar3 + 0x44) = uVar7 - 1;
LAB_0064fb1c:
            param_3 = param_3 + 1;
          } while ((int)param_3 < *(int *)(iVar3 + 0x44));
        }
        bVar2 = false;
      }
      local_8._0_1_ = 6;
      if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
        TclFreeObj(piVar10);
      }
      if (bVar2) goto LAB_0064fb70;
      iVar9 = local_24 + 1;
    } while( true );
  }
  FUN_006bc8f0(1);
  uVar8 = 1;
LAB_0064fba4:
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_50 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_5c != '\0') && (local_60 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_60);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 9;
  if ((local_54 != (int *)0x0) && (*local_54 = *local_54 + -1, *local_54 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,10);
  if ((local_58 != (int *)0x0) && (*local_58 = *local_58 + -1, *local_58 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar8;
LAB_0064fb70:
  FUN_006bc6a0("invalid TemplateSet",0);
  uVar8 = 1;
LAB_0064fb8f:
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
  goto LAB_0064fba4;
}

