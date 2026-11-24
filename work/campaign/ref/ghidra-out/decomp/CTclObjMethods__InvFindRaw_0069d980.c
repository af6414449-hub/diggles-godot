
undefined4
CTclObjMethods__InvFindRaw
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  code *pcVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined8 uVar12;
  int local_40;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711ee5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7b60) &&
     (FUN_006cebf4(&DAT_00ca7b60,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7b60 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca7b64 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclObjMethods::InvFindRaw()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7b60);
  }
  iVar6 = DAT_00ca7b64;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7b64 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar10;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar12 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  iVar3 = FUN_005c71c0(param_4,3,1);
  local_18 = iVar3;
  FUN_004298b0(param_3,param_4);
  if (iVar3 == 0) {
    uVar10 = 1;
  }
  else {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_30 + 2;
    }
    piVar1 = (int *)*puVar7;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (piVar1 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
    }
    FUN_006b8fb0(ppuVar4);
    iVar3 = DAT_00772478;
    cVar2 = FUN_006037d0(&local_1c,&local_14);
    if (cVar2 == '\0') {
      local_14 = 0;
    }
    else {
      if (*(uint *)(iVar3 + 0x801c) <= local_14) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_14 = *(uint *)(*(int *)(iVar3 + 0x8018) + local_14 * 4);
    }
    local_8._0_1_ = 4;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (local_14 == 0) {
      if (local_28 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_30;
        if (local_2c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_2c < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar7 = local_30 + 2;
      }
      piVar5 = (int *)*puVar7;
      if (piVar5 != (int *)0x0) {
        *piVar5 = *piVar5 + 1;
      }
      FUN_006bc6a0("unknown class",piVar5);
      uVar10 = 1;
      pcVar9 = TclFreeObj_exref;
    }
    else {
      uVar11 = 0;
      piVar5 = *(int **)(local_18 + 0x5c);
      uVar8 = local_14;
      local_1c = piVar5;
      if (0 < (int)piVar5) {
        do {
          if ((int)uVar11 < (int)*(uint *)(local_18 + 0x5c)) {
            if (*(uint *)(local_18 + 0x5c) <= uVar11) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              uVar8 = local_14;
              piVar5 = local_1c;
            }
            iVar3 = *(int *)(*(int *)(local_18 + 0x58) + uVar11 * 4);
          }
          else {
            iVar3 = 0;
          }
          if (*(uint *)(iVar3 + 0xd4) == uVar8) goto LAB_0069dbef;
          uVar11 = uVar11 + 1;
        } while ((int)uVar11 < (int)piVar5);
      }
      uVar11 = 0xffffffff;
LAB_0069dbef:
      piVar5 = (int *)Tcl_NewIntObj(uVar11);
      *piVar5 = *piVar5 + 1;
      iVar3 = *piVar5;
      if (local_40 != 0) {
        Tcl_SetObjResult(local_40,piVar5);
        iVar3 = *piVar5;
      }
      pcVar9 = TclFreeObj_exref;
      *piVar5 = iVar3 + -1;
      if (iVar3 + -1 < 1) {
        TclFreeObj(piVar5);
      }
      uVar10 = 0;
    }
    if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
      (*pcVar9)(piVar1);
    }
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

