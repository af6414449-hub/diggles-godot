
undefined4
CTclObjMethods__ObjFindNextNearest
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  void *lp;
  char cVar1;
  int iVar2;
  int iVar3;
  undefined **ppuVar4;
  int iVar5;
  int *piVar6;
  BOOL BVar7;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  undefined4 uVar11;
  code *pcVar12;
  undefined4 *puVar13;
  float fVar14;
  int *piVar15;
  double dVar16;
  ulonglong uVar17;
  float fVar18;
  undefined8 uVar19;
  int local_8c;
  char local_88;
  int *local_84;
  int *local_80;
  undefined4 *local_7c;
  uint local_78;
  int local_74;
  double local_70;
  int *local_68;
  undefined4 *local_64;
  undefined8 local_60;
  int *local_58;
  int *local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  int *local_44;
  int *local_40;
  int local_3c;
  int *local_38;
  int local_34;
  int *local_30;
  uint local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00712210;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7c40) &&
     (FUN_006cebf4(&DAT_00ca7c40,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7c40 == -1)) {
    iVar3 = DAT_00783650 * 0x40;
    DAT_00ca7c44 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar3) = "TCL:CTclObjMethods::ObjFindNextNearest()";
    *(int *)(&DAT_00773650 + iVar3) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7c40);
  }
  iVar3 = DAT_00ca7c44;
  local_64 = &DAT_00ca7c44;
  uVar11 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7c44 * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar11;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar3 * 0x10];
  if (iVar2 == 0) {
    uVar19 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar3 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar3 * 0x10) = uVar19;
  }
  (&DAT_00773654)[iVar3 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_1c = FUN_005c71c0(param_4,3,1);
  if (local_1c == 0) {
    uVar11 = 1;
  }
  else {
    if (local_74 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar13 = local_7c;
      if (local_78 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_78 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar13 = local_7c + 2;
    }
    piVar10 = (int *)*puVar13;
    if (piVar10 != (int *)0x0) {
      *piVar10 = *piVar10 + 1;
    }
    dVar16 = 1.7976931348623157e+308;
    local_68 = piVar10;
    local_54 = piVar10;
    if (param_3 == 4) {
      if (local_74 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar13 = local_7c;
        if (local_78 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_78 < 4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar13 = local_7c + 3;
      }
      piVar8 = (int *)*puVar13;
      if (piVar8 == (int *)0x0) {
        dVar16 = 0.0;
      }
      else {
        *piVar8 = *piVar8 + 1;
        iVar2 = Tcl_GetDoubleFromObj(0,piVar8,&local_70);
        if (iVar2 == 1) {
          fVar14 = 0.0;
        }
        else {
          fVar14 = (float)local_70;
        }
        *piVar8 = *piVar8 + -1;
        local_60 = (double)fVar14;
        dVar16 = local_60;
        if (*piVar8 < 1) {
          TclFreeObj(piVar8);
          dVar16 = local_60;
        }
      }
    }
    local_44 = (int *)(float)dVar16;
    local_28 = (int *)0x0;
    piVar9 = (int *)0x0;
    local_48 = *(undefined4 *)(local_1c + 0x36c);
    piVar8 = (int *)0xffffffff;
    local_38 = local_44;
    while( true ) {
      local_58 = local_38;
      local_60 = (double)CONCAT44(local_38,(undefined4)local_60);
      local_24 = piVar9;
      local_20 = piVar8;
      if (piVar10 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar3 = Tcl_ListObjLength(0,piVar10,&local_3c);
        iVar2 = local_3c;
        if (iVar3 != 0) {
          iVar2 = 0;
        }
      }
      if (iVar2 <= (int)piVar9) {
        if (local_20 == (int *)0xffffffff) {
          piVar8 = (int *)Tcl_NewIntObj(0);
          *piVar8 = *piVar8 + 1;
          iVar2 = *piVar8;
          if (local_8c != 0) {
            Tcl_SetObjResult(local_8c,piVar8);
            iVar2 = *piVar8;
          }
          *piVar8 = iVar2 + -1;
          if (iVar2 + -1 < 1) {
            TclFreeObj(piVar8);
          }
          uVar11 = 0;
          pcVar12 = TclFreeObj_exref;
          goto LAB_006a30ee;
        }
        puVar13 = (undefined4 *)(DAT_0077244c + 0x488);
        if (local_20 < (int *)0x2000) {
          puVar13 = puVar13 + (int)local_20;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        lp = (void *)*puVar13;
        if ((((lp == (void *)0x0) || (BVar7 = IsBadReadPtr(lp,0x10), BVar7 != 0)) ||
            (*(int *)((int)lp + 8) != 0x616e4f62)) ||
           ((DAT_00768398 != '\0' && (*(int *)((int)lp + 0xdc) == 0)))) goto LAB_006a30e3;
        local_24 = (int *)0x0;
        if ((int *)0x1fff < local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar2 = FUN_005caf90();
        if (iVar2 == 0) {
          piVar8 = (int *)0x0;
        }
        else {
          piVar8 = (int *)Tcl_NewStringObj(iVar2,0xffffffff);
          *piVar8 = *piVar8 + 1;
        }
        local_38 = piVar8;
        FUN_006bb930(&local_38);
        if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
          TclFreeObj(piVar8);
        }
        if ((piVar10 == (int *)0x0) ||
           (iVar2 = Tcl_ListObjIndex(0,piVar10,local_28,(int)&local_60 + 4), iVar2 != 0)) {
          local_38 = (int *)0x0;
        }
        else {
          local_38 = local_60._4_4_;
          if (local_60._4_4_ != (int *)0x0) {
            *local_60._4_4_ = *local_60._4_4_ + 1;
          }
        }
        piVar8 = local_38;
        FUN_006bb930(&local_38);
        if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
          TclFreeObj(piVar8);
        }
        piVar8 = local_24;
        if (local_8c != 0) {
          if (local_24 == (int *)0x0) {
            Tcl_ResetResult(local_8c);
            uVar11 = 0;
            pcVar12 = TclFreeObj_exref;
            goto LAB_006a30ee;
          }
          Tcl_SetObjResult(local_8c,local_24);
        }
        uVar11 = 0;
        pcVar12 = TclFreeObj_exref;
        if ((piVar8 != (int *)0x0) &&
           (*piVar8 = *piVar8 + -1, pcVar12 = TclFreeObj_exref, *piVar8 < 1)) {
          TclFreeObj(piVar8);
        }
        goto LAB_006a30ee;
      }
      if ((piVar10 == (int *)0x0) ||
         (iVar2 = Tcl_ListObjIndex(0,piVar10,piVar9,&local_40), iVar2 != 0)) {
        local_18 = (int *)0x0;
      }
      else {
        local_18 = local_40;
        if (local_40 != (int *)0x0) {
          *local_40 = *local_40 + 1;
        }
      }
      piVar8 = local_18;
      local_8 = CONCAT31(local_8._1_3_,4);
      if (local_18 == (int *)0x0) {
        ppuVar4 = &PTR_0071ce50;
      }
      else {
        ppuVar4 = (undefined **)Tcl_GetStringFromObj(local_18,0);
      }
      FUN_006b8fb0(ppuVar4);
      iVar2 = DAT_00772478;
      cVar1 = FUN_006037d0(&local_30,&local_2c);
      if (cVar1 == '\0') {
        iVar2 = 0;
      }
      else {
        if (*(uint *)(iVar2 + 0x801c) <= local_2c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar2 = *(int *)(*(int *)(iVar2 + 0x8018) + local_2c * 4);
      }
      local_8._0_1_ = 5;
      piVar9 = local_30;
      local_34 = iVar2;
      if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
        FUN_006ba940();
        piVar9 = extraout_ECX;
      }
      local_8 = CONCAT31(local_8._1_3_,3);
      if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
        TclFreeObj(piVar8);
        piVar9 = extraout_ECX_00;
      }
      iVar3 = local_34;
      if (iVar2 == 0) break;
      piVar8 = (int *)0xffffffff;
      piVar10 = (int *)0x0;
      local_18 = (int *)0xffffffff;
      local_4c = *(float *)(local_1c + 0xc);
      local_50 = *(float *)(local_1c + 0x10);
      uVar17 = ZEXT48(local_44);
      local_14 = local_44;
      do {
        piVar9 = (int *)(DAT_0077244c + 0x488);
        if (piVar10 < (int *)0x2000) {
          piVar9 = piVar9 + (int)piVar10;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          uVar17 = ZEXT48(local_14);
          piVar8 = local_18;
        }
        iVar2 = *piVar9;
        piVar9 = local_18;
        piVar15 = local_14;
        if ((((iVar2 != 0) && (iVar2 != local_1c)) && (*(int *)(iVar2 + 0xd4) == iVar3)) &&
           (((byte)*(undefined4 *)(iVar2 + 0x3d0) & 5) == 1)) {
          iVar5 = FUN_005cb3a0(local_48);
          if (0 < iVar5) {
            fVar14 = *(float *)(iVar2 + 0x10) - local_50;
            fVar18 = *(float *)(iVar2 + 0xc) - local_4c;
            uVar17 = (ulonglong)(uint)(fVar14 * fVar14 + fVar18 * fVar18);
            FUN_0040b7e0();
            piVar8 = piVar10;
            piVar9 = piVar10;
            piVar15 = (int *)uVar17;
            if ((float)(int *)uVar17 < (float)local_14) goto LAB_006a3054;
          }
          uVar17 = ZEXT48(local_14);
          piVar8 = local_18;
          piVar9 = local_18;
          piVar15 = local_14;
        }
LAB_006a3054:
        local_14 = piVar15;
        local_18 = piVar9;
        piVar10 = (int *)((int)piVar10 + 1);
      } while ((int)piVar10 < 0x2000);
      piVar15 = (int *)uVar17;
      if ((float)piVar15 < (float)local_38) {
        local_38 = piVar15;
      }
      piVar6 = local_24;
      if ((float)local_58 <= (float)piVar15) {
        piVar6 = local_28;
      }
      piVar9 = (int *)((int)local_24 + 1);
      piVar10 = local_54;
      local_28 = piVar6;
      if ((float)local_60._4_4_ <= (float)piVar15) {
        piVar8 = local_20;
      }
    }
    if ((piVar10 == (int *)0x0) ||
       (iVar2 = Tcl_ListObjIndex(0,piVar10,local_24,(int)&local_60 + 4,piVar9), iVar2 != 0)) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = local_60._4_4_;
      if (local_60._4_4_ != (int *)0x0) {
        *local_60._4_4_ = *local_60._4_4_ + 1;
      }
    }
    FUN_006bc6a0("unknown class",piVar8);
LAB_006a30e3:
    uVar11 = 1;
    pcVar12 = TclFreeObj_exref;
LAB_006a30ee:
    if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
      (*pcVar12)(piVar10);
    }
  }
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_7c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_88 != '\0') && (local_8c != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_8c);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 8;
  if ((local_80 != (int *)0x0) && (*local_80 = *local_80 + -1, *local_80 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,9);
  if ((local_84 != (int *)0x0) && (*local_84 = *local_84 + -1, *local_84 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar11;
}

