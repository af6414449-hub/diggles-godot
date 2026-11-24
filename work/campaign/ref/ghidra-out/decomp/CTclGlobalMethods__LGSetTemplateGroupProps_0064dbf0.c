
undefined4
CTclGlobalMethods__LGSetTemplateGroupProps
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined **ppuVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  code *pcVar11;
  undefined8 uVar12;
  int local_6c;
  char local_68;
  int *local_64;
  int *local_60;
  undefined4 *local_5c;
  uint local_58;
  int local_54;
  uint local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int local_20;
  int local_1c;
  uint local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e30d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7198) &&
     (FUN_006cebf4(&DAT_00ca7198,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7198 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca719c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::LGSetTemplateGroupProps()";
    *(int *)(&DAT_00773650 + iVar8) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7198);
  }
  iVar8 = DAT_00ca719c;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca719c * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar10;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar4 == 0) {
    uVar12 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_1c = FUN_0058a820();
  if ((param_3 & 1) == 0) {
    local_30 = 2;
    if (2 < (int)param_3) {
      do {
        uVar7 = local_30 + 1;
        if (((int)uVar7 < 0) || (local_54 <= (int)uVar7)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar5 = local_5c;
          if (local_58 == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        else {
          if (local_58 <= uVar7) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar5 = local_5c + local_30 + 1;
        }
        piVar1 = (int *)*puVar5;
        if (piVar1 != (int *)0x0) {
          *piVar1 = *piVar1 + 1;
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        if (piVar1 == (int *)0x0) {
          ppuVar6 = &PTR_0071ce50;
        }
        else {
          ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
        }
        FUN_006b8fb0(ppuVar6);
        if (((int)local_30 < 0) || (local_54 <= (int)local_30)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar5 = local_5c;
          if (local_58 == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        else {
          if (local_58 <= local_30) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar5 = local_5c + local_30;
        }
        piVar2 = (int *)*puVar5;
        if (piVar2 != (int *)0x0) {
          *piVar2 = *piVar2 + 1;
        }
        local_8 = CONCAT31(local_8._1_3_,5);
        if (piVar2 == (int *)0x0) {
          ppuVar6 = &PTR_0071ce50;
        }
        else {
          ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
        }
        FUN_006b8fb0(ppuVar6);
        if (local_54 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar5 = local_5c;
          if (local_58 == 0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        else {
          if (local_58 < 2) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar5 = local_5c + 1;
        }
        piVar3 = (int *)*puVar5;
        if (piVar3 != (int *)0x0) {
          *piVar3 = *piVar3 + 1;
        }
        local_8._0_1_ = 7;
        if (piVar3 == (int *)0x0) {
          ppuVar6 = &PTR_0071ce50;
        }
        else {
          ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
        }
        FUN_006b8fb0(ppuVar6);
        local_8 = CONCAT31(local_8._1_3_,8);
        uVar7 = FUN_00583450(&local_24);
        iVar4 = local_1c;
        if (uVar7 == 0xffffffff) {
          local_11 = '\x01';
          local_20 = -1;
        }
        else {
          local_18 = 0;
          local_20 = uVar7 * 0xc;
          while( true ) {
            if (*(uint *)(iVar4 + 0x3c) <= uVar7) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            iVar8 = *(int *)(iVar4 + 0x38);
            if (*(int *)(iVar8 + 8 + local_20) <= (int)local_18) break;
            if (*(uint *)(iVar4 + 0x3c) <= uVar7) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar8 = *(int *)(iVar4 + 0x38);
            }
            piVar9 = (int *)(local_20 + 4 + iVar8);
            if ((uint)piVar9[1] <= local_18) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            FUN_005832c0(*(undefined4 *)(*piVar9 + local_18 * 4),&local_28,&local_2c);
            local_18 = local_18 + 1;
          }
          local_11 = '\0';
        }
        local_8 = CONCAT31(local_8._1_3_,9);
        if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
          FUN_006ba940();
        }
        pcVar11 = TclFreeObj_exref;
        if ((piVar3 != (int *)0x0) &&
           (*piVar3 = *piVar3 + -1, pcVar11 = TclFreeObj_exref, *piVar3 < 1)) {
          TclFreeObj(piVar3);
        }
        local_8 = CONCAT31(local_8._1_3_,10);
        if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
          FUN_006ba940();
        }
        if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
          (*pcVar11)(piVar2);
        }
        local_8._0_1_ = 0xb;
        if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,2);
        if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
          (*pcVar11)(piVar1);
        }
        if (local_11 != '\0') {
          if (local_54 < 2) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            puVar5 = local_5c;
            if (local_58 == 0) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
          }
          else {
            if (local_58 < 2) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            puVar5 = local_5c + 1;
          }
          piVar1 = (int *)*puVar5;
          if (piVar1 != (int *)0x0) {
            *piVar1 = *piVar1 + 1;
          }
          FUN_006bc6a0("invalid template group",piVar1);
          uVar10 = 1;
          goto LAB_0064dfbb;
        }
        local_30 = local_30 + 2;
      } while ((int)local_30 < (int)param_3);
    }
    uVar10 = 0;
  }
  else {
    FUN_006bc6a0("invalid paramstring",0);
    uVar10 = 1;
  }
LAB_0064dfbb:
  local_8._0_1_ = 0xc;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  FUN_004297b0(0);
  if (local_5c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_68 != '\0') && (local_6c != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_6c);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 0xe;
  if ((local_60 != (int *)0x0) && (*local_60 = *local_60 + -1, *local_60 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0xf);
  if ((local_64 != (int *)0x0) && (*local_64 = *local_64 + -1, *local_64 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

