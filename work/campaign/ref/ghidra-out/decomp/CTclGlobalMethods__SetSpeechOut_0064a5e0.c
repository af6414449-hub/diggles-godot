
void CTclGlobalMethods__SetSpeechOut
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  int *piVar15;
  float fVar16;
  undefined8 uVar17;
  int local_b4;
  char local_b0;
  int *local_ac;
  int *local_a8;
  int *local_a4;
  uint local_a0;
  int *local_9c;
  uint local_98;
  int *local_94;
  uint local_90;
  int *local_8c;
  int *local_88;
  int *local_84;
  double local_80;
  int local_78;
  int *local_74;
  int *local_70;
  undefined4 *local_6c;
  uint local_68;
  int local_64;
  int *local_60;
  int *local_5c;
  uint *local_58;
  uint *local_54;
  undefined4 local_50;
  int *local_4c;
  byte local_45;
  uint local_44 [4];
  uint local_34 [4];
  uint local_24 [4];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070dfc1;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7128) &&
     (FUN_006cebf4(&DAT_00ca7128,local_14), iVar3 = DAT_00783650, DAT_00ca7128 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    DAT_00ca712c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "TCL:CTclGlobalMethods::SetSpeechOut()";
    *(int *)(&DAT_00773650 + iVar12) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7128);
  }
  iVar12 = DAT_00ca712c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca712c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar12 * 0x10];
  if (iVar3 == 0) {
    uVar17 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar12 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar17;
  }
  (&DAT_00773654)[iVar12 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 3) {
    FUN_006bc8f0(2);
  }
  else {
    if ((DAT_007683bd != '\0') || (local_45 = 0, *(char *)(DAT_00772400 + 0x599) == '\0')) {
      local_45 = 1;
    }
    if (param_3 == 4) {
      if (local_64 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar14 = local_6c;
        if (local_68 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar14 = local_6c;
        }
      }
      else {
        if (local_68 < 4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar14 = local_6c + 3;
      }
      piVar15 = (int *)*puVar14;
      if (piVar15 != (int *)0x0) {
        *piVar15 = *piVar15 + 1;
        iVar3 = Tcl_GetBooleanFromObj(0,piVar15,&local_54);
        local_45 = local_45 | (iVar3 != 1 && local_54 != (uint *)0x0);
        *piVar15 = *piVar15 + -1;
        if (*piVar15 < 1) {
          TclFreeObj(piVar15);
        }
      }
    }
    if (local_64 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar14 = local_6c;
      if (local_68 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar14 = local_6c;
      }
    }
    else {
      if (local_68 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar14 = local_6c + 1;
    }
    piVar15 = (int *)*puVar14;
    if (piVar15 == (int *)0x0) {
      local_80 = 0.0;
    }
    else {
      *piVar15 = *piVar15 + 1;
      iVar3 = Tcl_GetDoubleFromObj(0,piVar15,&local_80);
      if (iVar3 == 1) {
        fVar16 = 0.0;
      }
      else {
        fVar16 = (float)local_80;
      }
      *piVar15 = *piVar15 + -1;
      local_80 = (double)fVar16;
      if (*piVar15 < 1) {
        TclFreeObj(piVar15);
      }
    }
    if (local_64 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar14 = local_6c;
      if (local_68 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar14 = local_6c;
      }
    }
    else {
      if (local_68 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar14 = local_6c + 2;
    }
    piVar15 = (int *)*puVar14;
    if (piVar15 != (int *)0x0) {
      *piVar15 = *piVar15 + 1;
    }
    local_8._0_1_ = 3;
    local_74 = piVar15;
    if (piVar15 == (int *)0x0) {
      local_50 = (uint *)0x0;
    }
    else {
      iVar3 = Tcl_ListObjLength(0,piVar15,&local_54);
      local_50 = local_54;
      if (iVar3 != 0) {
        local_50 = (uint *)0x0;
      }
    }
    local_70 = (int *)FUN_006ba810(0x19);
    local_70[1] = 4;
    *(undefined1 *)(local_70 + 3) = 0;
    local_70[2] = 0;
    *local_70 = 1;
    puVar10 = (uint *)0x0;
    local_8._0_1_ = 4;
    local_54 = (uint *)0x0;
    local_58 = (uint *)0x0;
    if (0 < (int)local_50) {
      do {
        if (0 < (int)puVar10) {
          local_4c = (int *)local_70[2];
          if (local_4c == (int *)0xffffffff) {
            local_4c = local_70 + 3;
            do {
              iVar3 = *local_4c;
              local_4c = (int *)((int)local_4c + 1);
            } while ((char)iVar3 != '\0');
            local_4c = (int *)((int)local_4c - ((int)local_70 + 0xd));
            local_70[2] = (int)local_4c;
          }
          iVar3 = (int)local_4c + 1;
          local_70 = (int *)FUN_006b8df0(local_70,(int)local_4c + 2);
          *(undefined2 *)((int)local_4c + 0xc + (int)local_70) = 10;
          local_70[2] = iVar3;
          puVar10 = local_58;
        }
        local_4c = (int *)((int)puVar10 / 2);
        if ((piVar15 == (int *)0x0) ||
           (iVar3 = Tcl_ListObjIndex(0,piVar15,puVar10,&local_84), iVar3 != 0)) {
          local_88 = (int *)0x0;
        }
        else {
          local_88 = local_84;
          if (local_84 != (int *)0x0) {
            *local_84 = *local_84 + 1;
          }
        }
        piVar15 = local_88;
        if ((local_88 == (int *)0x0) ||
           (iVar3 = Tcl_ListObjIndex(0,local_88,0,&local_8c), piVar5 = local_8c, iVar3 != 0)) {
          piVar5 = (int *)0x0;
LAB_0064a9b0:
          uVar11 = 0;
        }
        else {
          if (local_8c == (int *)0x0) goto LAB_0064a9b0;
          *local_8c = *local_8c + 1;
          iVar3 = Tcl_GetIntFromObj(0,local_8c,&local_90);
          uVar11 = -(uint)(iVar3 != 1) & local_90;
        }
        if (local_4c < 4) {
          puVar10 = local_24 + (int)local_4c;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar10 = local_24;
        }
        *puVar10 = uVar11;
        if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
          TclFreeObj(piVar5);
        }
        if ((piVar15 == (int *)0x0) ||
           (iVar3 = Tcl_ListObjIndex(0,piVar15,1,&local_94), piVar5 = local_94, iVar3 != 0)) {
          piVar5 = (int *)0x0;
LAB_0064aa38:
          uVar11 = 0;
        }
        else {
          if (local_94 == (int *)0x0) goto LAB_0064aa38;
          *local_94 = *local_94 + 1;
          iVar3 = Tcl_GetIntFromObj(0,local_94,&local_98);
          uVar11 = -(uint)(iVar3 != 1) & local_98;
        }
        if (local_4c < 4) {
          puVar10 = local_34 + (int)local_4c;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar10 = local_34;
        }
        *puVar10 = uVar11;
        if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
          TclFreeObj(piVar5);
        }
        if ((piVar15 == (int *)0x0) ||
           (iVar3 = Tcl_ListObjIndex(0,piVar15,2,&local_9c), piVar5 = local_9c, iVar3 != 0)) {
          piVar5 = (int *)0x0;
LAB_0064aac0:
          uVar11 = 0;
        }
        else {
          if (local_9c == (int *)0x0) goto LAB_0064aac0;
          *local_9c = *local_9c + 1;
          iVar3 = Tcl_GetIntFromObj(0,local_9c,&local_a0);
          uVar11 = -(uint)(iVar3 != 1) & local_a0;
        }
        if (local_4c < 4) {
          puVar10 = local_44 + (int)local_4c;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar10 = local_44;
        }
        *puVar10 = uVar11;
        if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
          TclFreeObj(piVar5);
        }
        if ((local_74 == (int *)0x0) ||
           (iVar3 = Tcl_ListObjIndex(0,local_74,(int)local_58 + 1,&local_a4), iVar3 != 0)) {
          local_4c = (int *)0x0;
        }
        else {
          local_4c = local_a4;
          if (local_a4 != (int *)0x0) {
            *local_a4 = *local_a4 + 1;
          }
        }
        piVar5 = local_4c;
        local_8._0_1_ = 6;
        if (local_4c == (int *)0x0) {
          ppuVar4 = &PTR_0071ce50;
        }
        else {
          ppuVar4 = (undefined **)Tcl_GetStringFromObj(local_4c,0);
        }
        FUN_006b8fb0(ppuVar4);
        local_8 = CONCAT31(local_8._1_3_,8);
        if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
          TclFreeObj(piVar5);
        }
        piVar5 = local_5c;
        iVar3 = local_5c[2];
        if (iVar3 == -1) {
          piVar6 = local_5c + 3;
          do {
            iVar3 = *piVar6;
            piVar6 = (int *)((int)piVar6 + 1);
          } while ((char)iVar3 != '\0');
          iVar3 = (int)piVar6 - ((int)local_5c + 0xd);
          local_5c[2] = iVar3;
        }
        if ((((iVar3 < 1) || (iVar3 = FUN_006d0190(local_5c + 3,0x3a), iVar3 == 0)) ||
            (puVar10 = (uint *)((iVar3 - (int)piVar5) + -0xc), (int)puVar10 < 1)) &&
           (local_4c = (int *)((int)local_54 + 1), puVar10 = local_54, 0 < (int)local_4c)) {
          iVar3 = piVar5[2];
          piVar6 = piVar5 + 3;
          do {
            if (iVar3 == -1) {
              iVar3 = (int)piVar6 + 1;
              do {
                iVar12 = *piVar6;
                piVar6 = (int *)((int)piVar6 + 1);
              } while ((char)iVar12 != '\0');
              iVar3 = (int)piVar6 - iVar3;
              piVar5[2] = iVar3;
            }
            iVar12 = iVar3;
            if (0 < iVar3) {
              iVar12 = 0;
            }
            local_60 = (int *)(iVar3 + 1);
            local_78 = iVar12;
            piVar5 = (int *)FUN_006b8df0(piVar5,iVar3 + 3);
            puVar13 = (undefined1 *)(iVar12 + 0xc + (int)piVar5);
            local_5c = piVar5;
            FUN_006d1b90(local_78 + 0xd + (int)piVar5,puVar13,(int)local_60 - local_78);
            piVar6 = piVar5 + 3;
            *puVar13 = 0x20;
            piVar5[2] = -1;
            piVar8 = piVar6;
            do {
              iVar3 = *piVar8;
              piVar8 = (int *)((int)piVar8 + 1);
            } while ((char)iVar3 != '\0');
            iVar3 = (int)piVar8 - ((int)piVar5 + 0xd);
            local_4c = (int *)((int)local_4c + -1);
            piVar5[2] = iVar3;
            puVar10 = local_54;
          } while (local_4c != (int *)0x0);
        }
        local_54 = puVar10;
        FUN_006b9290(&local_5c);
        puVar10 = (uint *)((int)local_58 + 2);
        local_8._0_1_ = 9;
        *piVar5 = *piVar5 + -1;
        local_58 = puVar10;
        if (*piVar5 == 0) {
          FUN_006ba940();
        }
        local_8._0_1_ = 4;
        if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 < 1)) {
          TclFreeObj(piVar15);
        }
        piVar15 = local_74;
      } while ((int)puVar10 < (int)local_50);
    }
    piVar5 = local_70;
    piVar6 = local_70;
    local_4c = local_70;
    if (local_45 == 0) {
      piVar6 = (int *)FUN_006ba810(0x19);
      piVar6[1] = 4;
      *(undefined1 *)(piVar6 + 3) = 0;
      piVar6[2] = 0;
      local_8._0_1_ = 10;
      *piVar6 = 2;
      local_70 = piVar6;
      local_60 = piVar6;
      local_4c = piVar6;
      if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0xb;
      *piVar6 = *piVar6 + -1;
      if (*piVar6 == 0) {
        FUN_006ba940();
      }
    }
    local_78 = (int)local_50 / 2;
    local_5c = (int *)0x0;
    if (0 < local_78) {
      local_50 = (uint *)CONCAT13(0xa0,(undefined3)local_50);
      do {
        if (local_5c < (int *)0x4) {
          puVar10 = local_24 + (int)local_5c;
          local_54 = local_34 + (int)local_5c;
          local_58 = local_44 + (int)local_5c;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar10 = local_24;
          local_54 = local_34;
          local_58 = local_44;
        }
        uVar11 = *puVar10;
        iVar3 = FUN_00501450();
        local_60 = local_5c;
        if ((int *)0x3 < local_5c) {
          local_60 = (int *)0x3;
        }
        if ((int)uVar11 < 0) {
          uVar11 = 0;
        }
        if (0xff < (int)uVar11) {
          uVar11 = 0xff;
        }
        uVar7 = *local_54;
        if ((int)uVar7 < 0) {
          uVar7 = 0;
        }
        puVar14 = (undefined4 *)(*(int *)(*(int *)(iVar3 + 0x8194) + 0x110) + 0x58);
        if (0xff < (int)uVar7) {
          uVar7 = 0xff;
        }
        uVar9 = *local_58;
        if ((int)uVar9 < 0) {
          uVar9 = 0;
        }
        if (0xff < (int)uVar9) {
          uVar9 = 0xff;
        }
        local_50 = (uint *)CONCAT31(CONCAT21(CONCAT11(local_50._3_1_,(char)uVar11),(char)uVar7),
                                    (char)uVar9);
        if (local_60 < (int *)0x4) {
          puVar14 = puVar14 + (int)local_60;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *puVar14 = local_50;
        local_5c = (int *)((int)local_5c + 1);
        piVar6 = local_4c;
        piVar15 = local_74;
      } while ((int)local_5c < local_78);
    }
    if (piVar6 != (int *)0x0) {
      *piVar6 = *piVar6 + 1;
    }
    local_60 = piVar6;
    iVar3 = FUN_00501450();
    iVar3 = *(int *)(*(int *)(iVar3 + 0x8194) + 0x110);
    local_8 = CONCAT31(local_8._1_3_,0xc);
    *(double *)(iVar3 + 0x50) = *(double *)(DAT_00772400 + 0xa088) + local_80;
    cVar2 = FUN_006b97f0(&local_60);
    if (cVar2 == '\0') {
      piVar5 = *(int **)(iVar3 + 0x20);
      *(int **)(iVar3 + 0x20) = piVar6;
      if (piVar6 != (int *)0x0) {
        *piVar6 = *piVar6 + 1;
      }
      if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 == 0)) {
        FUN_006ba940();
      }
      *(int *)(*(int *)(iVar3 + 0x20) + 8) = piVar6[2];
      FUN_00504ee0();
    }
    if (*(char *)(iVar3 + 0x1c) != '\x01') {
      *(undefined1 *)(iVar3 + 0x1c) = 1;
      FUN_00504ee0();
    }
    local_8._0_1_ = 0xd;
    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 4;
    FUN_00501450();
    FUN_00505ed0();
    local_8 = CONCAT31(local_8._1_3_,0xe);
    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 == 0)) {
      FUN_006ba940();
    }
    if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 < 1)) {
      TclFreeObj(piVar15);
    }
  }
  if ((local_b0 != '\0') && (local_b4 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_b4);
  }
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 0xf;
  if ((local_a8 != (int *)0x0) && (*local_a8 = *local_a8 + -1, *local_a8 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x10;
  if ((local_ac != (int *)0x0) && (*local_ac = *local_ac + -1, *local_ac == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x11;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x12);
  FUN_004297b0(0);
  if (local_6c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

