
undefined4
CTclGlobalMethods__IsDigMarked(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  float fVar11;
  undefined8 uVar12;
  int local_68;
  char local_64;
  int *local_60;
  int *local_5c;
  undefined4 *local_58;
  uint local_54;
  int local_50;
  double local_4c;
  double local_44;
  double local_3c;
  double local_34;
  undefined4 *local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e6ad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7208) &&
     (FUN_006cebf4(&DAT_00ca7208,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7208 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca720c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::IsDigMarked()";
    *(int *)(&DAT_00773650 + iVar4) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7208);
  }
  iVar4 = DAT_00ca720c;
  local_2c = &DAT_00ca720c;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca720c * 0x40);
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
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 5) {
    if (local_50 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_58 + 1;
    }
    piVar5 = (int *)*puVar10;
    if (piVar5 == (int *)0x0) {
      local_14 = 0;
    }
    else {
      *piVar5 = *piVar5 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar5,&local_34);
      fVar11 = 0.0;
      if (iVar2 != 1) {
        fVar11 = (float)local_34;
      }
      *piVar5 = *piVar5 + -1;
      local_14 = (int)fVar11;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
    }
    if (local_50 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_58 + 2;
    }
    piVar5 = (int *)*puVar10;
    if (piVar5 == (int *)0x0) {
      local_1c = 0;
    }
    else {
      *piVar5 = *piVar5 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar5,&local_3c);
      if (iVar2 == 1) {
        fVar11 = 0.0;
      }
      else {
        fVar11 = (float)local_3c;
      }
      *piVar5 = *piVar5 + -1;
      local_1c = (int)fVar11;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
    }
    if (local_50 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_58 + 3;
    }
    piVar5 = (int *)*puVar10;
    if (piVar5 == (int *)0x0) {
      local_20 = 0;
    }
    else {
      *piVar5 = *piVar5 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar5,&local_44);
      if (iVar2 == 1) {
        fVar11 = 0.0;
      }
      else {
        fVar11 = (float)local_44;
      }
      *piVar5 = *piVar5 + -1;
      local_20 = (int)fVar11;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
    }
    if (local_50 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_58;
      if (local_54 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_54 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_58 + 4;
    }
    piVar5 = (int *)*puVar10;
    if (piVar5 == (int *)0x0) {
      local_18 = 0;
    }
    else {
      *piVar5 = *piVar5 + 1;
      iVar2 = Tcl_GetDoubleFromObj(0,piVar5,&local_4c);
      if (iVar2 == 1) {
        fVar11 = 0.0;
      }
      else {
        fVar11 = (float)local_4c;
      }
      *piVar5 = *piVar5 + -1;
      local_18 = (int)fVar11;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
    }
    uVar8 = 0;
    local_28 = *(undefined4 *)(DAT_00772400 + 100);
    iVar2 = local_18;
    iVar4 = local_1c;
    uVar1 = 0;
    if (local_14 < local_20) {
      do {
        uVar8 = uVar1;
        iVar7 = iVar4;
        local_24 = iVar4;
        if (iVar4 < iVar2) {
          do {
            iVar2 = DAT_0077241c;
            iVar7 = *(int *)(DAT_0077241c + 0x84);
            if (*(int *)(DAT_0077241c + 0x84) <= local_14) {
              iVar7 = local_14;
            }
            iVar6 = *(int *)(DAT_0077241c + 0x88);
            if (*(int *)(DAT_0077241c + 0x88) <= iVar4) {
              iVar6 = iVar4;
            }
            iVar3 = *(int *)(DAT_0077241c + 0x90) + -1;
            if (iVar6 < *(int *)(DAT_0077241c + 0x90)) {
              iVar3 = iVar6;
            }
            iVar6 = *(int *)(DAT_0077241c + 0x8c) + -1;
            if (iVar7 < *(int *)(DAT_0077241c + 0x8c)) {
              iVar6 = iVar7;
            }
            iVar7 = (iVar3 * *(int *)(DAT_0077241c + 0x44) + iVar6) % *(int *)(DAT_0077241c + 0x4c);
            local_24 = iVar4;
            if ((iVar7 < 0) || (*(int *)(DAT_0077241c + 0x18) <= iVar7)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar4 = *(int *)(iVar2 + 0x14);
            }
            else {
              iVar4 = iVar7 * 0x7c + *(int *)(DAT_0077241c + 0x14);
            }
            iVar2 = local_18;
            iVar7 = local_1c;
            if ((*(uint *)(iVar4 + 8) >> ((char)local_28 * '\x04' & 0x1fU) & 0xf) != 0) {
              uVar8 = 1;
              break;
            }
            iVar4 = local_24 + 1;
            local_24 = iVar4;
          } while (iVar4 < local_18);
        }
        local_14 = local_14 + 1;
        iVar4 = iVar7;
        uVar1 = uVar8;
      } while (local_14 < local_20);
    }
    piVar5 = (int *)Tcl_NewBooleanObj(uVar8);
    *piVar5 = *piVar5 + 1;
    iVar2 = *piVar5;
    if (local_68 != 0) {
      Tcl_SetObjResult(local_68,piVar5);
      iVar2 = *piVar5;
    }
    *piVar5 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj(piVar5);
    }
    uVar9 = 0;
  }
  else {
    FUN_006bc8f0(4);
    uVar9 = 1;
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_58 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_64 != '\0') && (local_68 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_68);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 5;
  if ((local_5c != (int *)0x0) && (*local_5c = *local_5c + -1, *local_5c == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,6);
  if ((local_60 != (int *)0x0) && (*local_60 = *local_60 + -1, *local_60 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

