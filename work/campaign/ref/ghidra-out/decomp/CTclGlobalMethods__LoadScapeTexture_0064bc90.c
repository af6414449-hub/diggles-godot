
undefined4
CTclGlobalMethods__LoadScapeTexture
          (undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  undefined **ppuVar10;
  int iVar11;
  undefined4 *puVar12;
  code *pcVar13;
  undefined4 uVar14;
  undefined8 uVar15;
  int local_6c;
  char local_68;
  int *local_64;
  int *local_60;
  undefined4 *local_5c;
  uint local_58;
  int local_54;
  int *local_44;
  int *local_40;
  int *local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  int *local_18;
  undefined **local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070e06d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7158) &&
     (FUN_006cebf4(&DAT_00ca7158,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar7 = DAT_00783650,
     DAT_00ca7158 == -1)) {
    iVar11 = DAT_00783650 * 0x40;
    DAT_00ca715c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar11) = "TCL:CTclGlobalMethods::LoadScapeTexture()";
    *(int *)(&DAT_00773650 + iVar11) = iVar7;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7158);
  }
  iVar11 = DAT_00ca715c;
  uVar14 = *(undefined4 *)(&DAT_00773650 + DAT_00ca715c * 0x40);
  iVar7 = FUN_0043fcc0();
  *(undefined4 *)(iVar7 + *(int *)(iVar7 + 0x8000) * 4) = uVar14;
  *(int *)(iVar7 + 0x8000) = *(int *)(iVar7 + 0x8000) + 1;
  iVar7 = (&DAT_00773654)[iVar11 * 0x10];
  if (iVar7 == 0) {
    uVar15 = FUN_006bd180();
    iVar7 = (&DAT_00773654)[iVar11 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar11 * 0x10) = uVar15;
  }
  (&DAT_00773654)[iVar11 * 0x10] = iVar7 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar3 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (uVar3 == 4) {
    if (local_54 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar12 = local_5c;
      if (local_58 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_58 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar12 = local_5c + 1;
    }
    piVar2 = (int *)*puVar12;
    if (piVar2 == (int *)0x0) {
      local_20 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar7 = Tcl_GetIntFromObj(0,piVar2,&param_3);
      *piVar2 = *piVar2 + -1;
      local_20 = -(uint)(iVar7 != 1) & param_3;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_54 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar12 = local_5c;
      if (local_58 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_58 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar12 = local_5c + 2;
    }
    piVar2 = (int *)*puVar12;
    if (piVar2 == (int *)0x0) {
      local_1c = 0;
      pcVar9 = TclFreeObj_exref;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar7 = Tcl_GetIntFromObj(0,piVar2,&param_3);
      pcVar9 = TclFreeObj_exref;
      *piVar2 = *piVar2 + -1;
      local_1c = -(uint)(iVar7 != 1) & param_3;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_54 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar12 = local_5c;
      if (local_58 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_58 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar12 = local_5c + 3;
    }
    piVar2 = (int *)*puVar12;
    pcVar13 = Tcl_ListObjLength_exref;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
      pcVar13 = Tcl_ListObjLength_exref;
      Tcl_ListObjLength(0,piVar2,&param_3);
    }
    param_3 = 0;
    while( true ) {
      if (piVar2 == (int *)0x0) {
        iVar7 = 0;
      }
      else {
        iVar7 = (*pcVar13)(0,piVar2,&local_28);
        if ((iVar7 == 0) && (0x10 < local_28)) {
          iVar7 = 0x10;
        }
        else {
          iVar11 = (*pcVar13)(0,piVar2,&local_2c);
          iVar7 = local_2c;
          if (iVar11 != 0) {
            iVar7 = 0;
          }
        }
      }
      pcVar13 = Tcl_ListObjIndex_exref;
      if (iVar7 <= (int)param_3) break;
      if ((piVar2 == (int *)0x0) ||
         (iVar7 = Tcl_ListObjIndex(0,piVar2,param_3,&local_30), iVar7 != 0)) {
        local_34 = (int *)0x0;
      }
      else {
        local_34 = local_30;
        if (local_30 != (int *)0x0) {
          *local_30 = *local_30 + 1;
        }
      }
      piVar5 = local_34;
      iVar7 = 0;
      while( true ) {
        local_24 = iVar7;
        if (piVar5 == (int *)0x0) {
          iVar11 = 0;
        }
        else {
          iVar8 = Tcl_ListObjLength(0,piVar5,&local_38);
          iVar11 = local_38;
          if (iVar8 != 0) {
            iVar11 = 0;
          }
        }
        pcVar9 = TclFreeObj_exref;
        if (iVar11 <= iVar7) break;
        if ((piVar5 == (int *)0x0) || (iVar7 = (*pcVar13)(0,piVar5,iVar7,&local_3c), iVar7 != 0)) {
          local_40 = (int *)0x0;
        }
        else {
          local_40 = local_3c;
          if (local_3c != (int *)0x0) {
            *local_3c = *local_3c + 1;
          }
        }
        piVar4 = local_40;
        local_8._0_1_ = 5;
        if (local_40 == (int *)0x0) {
          local_14 = &PTR_0071ce50;
        }
        else {
          local_14 = (undefined **)Tcl_GetStringFromObj(local_40,0);
        }
        ppuVar10 = local_14;
        do {
          cVar1 = *(char *)ppuVar10;
          ppuVar10 = (undefined **)((int)ppuVar10 + 1);
        } while (cVar1 != '\0');
        iVar11 = (int)ppuVar10 - (int)((int)local_14 + 1);
        iVar7 = iVar11 + 1;
        if (iVar7 < 4) {
          iVar7 = 4;
        }
        local_44 = (int *)((iVar7 + 0xbU & 0xfffffff0) + 4);
        local_18 = (int *)FUN_006ba810(0x19);
        local_18[1] = (int)local_44;
        local_18[2] = -1;
        *local_18 = 0;
        *(undefined1 *)(local_18 + 3) = 0;
        local_44 = local_18;
        FUN_006d2250(local_18 + 3,local_14,iVar11 + 1);
        piVar6 = local_18;
        local_18[2] = iVar11;
        *local_18 = *local_18 + 1;
        local_8._0_1_ = 6;
        FUN_004ce0c0(local_20,local_1c,param_3,&local_44);
        local_8 = CONCAT31(local_8._1_3_,7);
        *piVar6 = *piVar6 + -1;
        if (*piVar6 == 0) {
          FUN_006ba940();
        }
        if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
          TclFreeObj(piVar4);
        }
        iVar7 = local_24 + 1;
        pcVar13 = Tcl_ListObjIndex_exref;
      }
      if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
        TclFreeObj(piVar5);
      }
      param_3 = param_3 + 1;
      pcVar13 = Tcl_ListObjLength_exref;
    }
    uVar14 = 0;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      (*pcVar9)(piVar2);
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar14 = 1;
  }
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,9);
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
  local_8._0_1_ = 10;
  if ((local_60 != (int *)0x0) && (*local_60 = *local_60 + -1, *local_60 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0xb);
  if ((local_64 != (int *)0x0) && (*local_64 = *local_64 + -1, *local_64 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar14;
}

