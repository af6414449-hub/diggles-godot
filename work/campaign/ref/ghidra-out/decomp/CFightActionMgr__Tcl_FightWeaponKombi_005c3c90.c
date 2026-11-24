
undefined4
CFightActionMgr__Tcl_FightWeaponKombi
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined **ppuVar5;
  int iVar6;
  uint uVar7;
  uint extraout_ECX;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  bool bVar12;
  undefined8 uVar13;
  int *piVar14;
  int local_74;
  char local_70;
  int *local_6c;
  int *local_68;
  undefined4 *local_64;
  uint local_60;
  int local_5c;
  double local_58;
  int *local_50;
  int *local_4c;
  undefined4 *local_48;
  uint local_44;
  int *local_40;
  int local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  uint local_2c;
  uint local_28;
  int *local_24;
  uint local_20;
  int *local_1c;
  int local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070807d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca65f0) &&
     (FUN_006cebf4(&DAT_00ca65f0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca65f0 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca65f4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CFightActionMgr::Tcl_FightWeaponKombi()";
    *(int *)(&DAT_00773650 + iVar10) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca65f0);
  }
  iVar10 = DAT_00ca65f4;
  local_48 = &DAT_00ca65f4;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca65f4 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar9;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar2 == 0) {
    uVar13 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar13;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar11 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (piVar11 == (int *)0x3) {
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
    piVar11 = (int *)*puVar3;
    if (piVar11 != (int *)0x0) {
      *piVar11 = *piVar11 + 1;
    }
    local_4c = piVar11;
    local_30 = piVar11;
    if (local_5c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar3 = local_64;
      if (local_60 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_60 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar3 = local_64 + 2;
    }
    local_50 = (int *)*puVar3;
    if (local_50 != (int *)0x0) {
      *local_50 = *local_50 + 1;
    }
    local_14 = 2.0;
    local_24 = local_50;
    iVar2 = FUN_005bbb20();
    local_20 = 0xffffffff;
    iVar10 = 0;
    while( true ) {
      local_18 = iVar10;
      if (piVar11 == (int *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar4 = Tcl_ListObjLength(0,piVar11,&local_34);
        iVar6 = local_34;
        if (iVar4 != 0) {
          iVar6 = 0;
        }
      }
      if (iVar6 <= iVar10) {
        uVar9 = 0;
        goto LAB_005c41d7;
      }
      if ((piVar11 == (int *)0x0) ||
         (iVar10 = Tcl_ListObjIndex(0,piVar11,iVar10,&local_38), iVar10 != 0)) {
        param_3 = (int *)0x0;
      }
      else {
        param_3 = local_38;
        if (local_38 != (int *)0x0) {
          *local_38 = *local_38 + 1;
        }
      }
      piVar14 = param_3;
      local_8._0_1_ = 5;
      if (param_3 == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(param_3,0);
      }
      FUN_006b8fb0(ppuVar5);
      local_8 = CONCAT31(local_8._1_3_,7);
      if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
        TclFreeObj(piVar14);
      }
      iVar10 = DAT_00772478;
      cVar1 = FUN_006037d0(&local_1c,&local_28);
      uVar8 = extraout_ECX;
      if (cVar1 == '\0') break;
      if (*(uint *)(iVar10 + 0x801c) <= local_28) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      param_3 = *(int **)(*(int *)(iVar10 + 0x8018) + local_28 * 4);
      uVar8 = local_28;
      if (param_3 == (int *)0x0) break;
      if (local_24 == (int *)0x0) {
        iVar10 = 0;
      }
      else {
        iVar6 = Tcl_ListObjLength(0,local_24,&local_3c);
        iVar10 = local_3c;
        if (iVar6 != 0) {
          iVar10 = 0;
        }
      }
      if (local_18 < iVar10) {
        if (((local_24 == (int *)0x0) ||
            (iVar10 = Tcl_ListObjIndex(0,local_24,local_18,&local_40), piVar11 = local_40,
            iVar10 != 0)) || (local_40 == (int *)0x0)) {
          local_14 = 0.0;
        }
        else {
          *local_40 = *local_40 + 1;
          iVar10 = Tcl_GetDoubleFromObj(0,local_40,&local_58);
          if (iVar10 == 1) {
            local_14 = 0.0;
          }
          else {
            local_14 = (float)local_58;
          }
          *piVar11 = *piVar11 + -1;
          if (*piVar11 < 1) {
            TclFreeObj(piVar11);
          }
        }
      }
      local_44 = param_3[2];
      if (local_20 == 0xffffffff) {
        FUN_005c65d0(1);
        local_20 = *(int *)(iVar2 + 0x1c) - 1;
      }
      uVar8 = local_20;
      if (*(uint *)(iVar2 + 0x1c) <= local_20) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      param_3 = *(int **)(iVar2 + 0x18);
      local_2c = *(uint *)((int)param_3 + 4 + uVar8 * 0x10);
      uVar7 = local_2c + 0x10 & 0xfffffff0;
      if (uVar7 != (local_2c + 0xf & 0xfffffff0)) {
        local_2c = uVar7;
        uVar9 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                             0x9b);
        local_2c = *(uint *)((int)param_3 + 4 + uVar8 * 0x10);
        *(undefined4 *)((int)param_3 + uVar8 * 0x10) = uVar9;
      }
      *(uint *)((int)param_3 + 4 + uVar8 * 0x10) = local_2c + 1;
      if (local_2c + 1 <= local_2c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar11 = local_30;
      *(uint *)(*(int *)((int)param_3 + uVar8 * 0x10) + local_2c * 4) = local_44;
      uVar7 = *(uint *)((int)param_3 + 0xc + uVar8 * 0x10);
      local_2c = uVar7 + 0x10 & 0xfffffff0;
      if (local_2c != (uVar7 + 0xf & 0xfffffff0)) {
        uVar9 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h",
                             0x9b);
        uVar7 = *(uint *)((int)param_3 + 0xc + uVar8 * 0x10);
        *(undefined4 *)((int)param_3 + 8 + uVar8 * 0x10) = uVar9;
      }
      *(uint *)((int)param_3 + 0xc + uVar8 * 0x10) = uVar7 + 1;
      local_44 = uVar7;
      if (uVar7 + 1 <= uVar7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      *(float *)(*(int *)((int)param_3 + 8 + uVar8 * 0x10) + local_44 * 4) = local_14;
      uVar7 = 0;
      param_3 = (int *)(*(int *)((int)param_3 + 4 + uVar8 * 0x10) + -1);
      if (0 < *(int *)(iVar2 + 0xc)) {
        iVar10 = 0;
        bVar12 = *(int *)(iVar2 + 0xc) != 0;
        do {
          if (!bVar12) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          cVar1 = FUN_006b97f0(&local_1c);
          if (cVar1 != '\0') {
            if (*(uint *)(iVar2 + 0xc) <= uVar7) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(uint *)(iVar10 + 0x30 + *(int *)(iVar2 + 8)) = local_20;
            if (*(uint *)(iVar2 + 0xc) <= uVar7) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(int **)(iVar10 + 0x34 + *(int *)(iVar2 + 8)) = param_3;
          }
          uVar7 = uVar7 + 1;
          iVar10 = iVar10 + 0x40;
          bVar12 = uVar7 < *(uint *)(iVar2 + 0xc);
          piVar11 = local_30;
        } while ((int)uVar7 < (int)*(uint *)(iVar2 + 0xc));
      }
      local_8 = CONCAT31(local_8._1_3_,9);
      if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
        FUN_006ba940();
      }
      iVar10 = local_18 + 1;
    }
    if ((piVar11 == (int *)0x0) ||
       (iVar2 = Tcl_ListObjIndex(0,piVar11,local_18,&param_3,uVar8), iVar2 != 0)) {
      piVar14 = (int *)0x0;
    }
    else {
      piVar14 = param_3;
      if (param_3 != (int *)0x0) {
        *param_3 = *param_3 + 1;
      }
    }
    FUN_006bc6a0("unknown class",piVar14);
    local_8 = CONCAT31(local_8._1_3_,8);
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    uVar9 = 1;
LAB_005c41d7:
    if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 < 1)) {
      TclFreeObj(local_24);
    }
    if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 < 1)) {
      TclFreeObj(piVar11);
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar9 = 1;
  }
  local_8._0_1_ = 10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xb);
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
  local_8._0_1_ = 0xc;
  if ((local_68 != (int *)0x0) && (*local_68 = *local_68 + -1, *local_68 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0xd);
  if ((local_6c != (int *)0x0) && (*local_6c = *local_6c + -1, *local_6c == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

