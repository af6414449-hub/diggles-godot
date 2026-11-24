
undefined4
CTclGlobalMethods__New(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined **ppuVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  code *pcVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  int local_78;
  undefined1 local_68 [12];
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 *local_44;
  uint local_40;
  int local_3c;
  int *local_34;
  int *local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070be05;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6cb8) &&
     (FUN_006cebf4(&DAT_00ca6cb8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6cb8 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca6cbc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CTclGlobalMethods::New()";
    *(int *)(&DAT_00773650 + iVar10) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6cb8);
  }
  iVar10 = DAT_00ca6cbc;
  local_2c = &DAT_00ca6cbc;
  uVar6 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6cbc * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar6;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar2 == 0) {
    uVar12 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar3 = (int *)FUN_006ba810(0x19);
  piVar9 = piVar3 + 3;
  piVar3[2] = -1;
  *piVar3 = 0;
  *(undefined1 *)piVar9 = 0;
  piVar3[1] = 0x14;
  *piVar9 = 0x73696874;
  *(undefined1 *)(piVar3 + 4) = 0;
  piVar3[2] = 4;
  *piVar3 = 1;
  if (local_78 == 0) {
    iVar10 = 0;
    iVar2 = 1;
  }
  else {
    iVar10 = Tcl_GetAssocData(local_78,piVar9,0);
    iVar2 = *piVar3;
  }
  local_8._0_1_ = 3;
  *piVar3 = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 2;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (iVar10 == 0) {
    FUN_006bc0d0();
    local_8._0_1_ = 4;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,5);
    FUN_004297b0(0);
    if (local_44 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  local_8._0_1_ = uVar1;
  if (param_3 < 2) {
    FUN_006bc8f0(1);
    FUN_006bc0d0();
    local_8._0_1_ = 6;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_004297b0(0);
    if (local_44 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  local_28 = DAT_0077244c;
  local_14 = (int *)FUN_006ba810(0x19);
  local_14[1] = 0x14;
  local_14[2] = -1;
  *(undefined1 *)(local_14 + 3) = 0;
  *local_14 = 1;
  local_8._0_1_ = 8;
  piVar3 = (int *)FUN_006ba810(0x19);
  piVar3[1] = 0x14;
  piVar3[2] = -1;
  *(undefined1 *)(piVar3 + 3) = 0;
  *piVar3 = 1;
  local_8 = CONCAT31(local_8._1_3_,9);
  local_30 = piVar3;
  local_34 = (int *)FUN_006ba810(0x19);
  local_34[1] = 0x14;
  local_34[2] = -1;
  *(undefined1 *)(local_34 + 3) = 0;
  *local_34 = 1;
  piVar9 = (int *)0x0;
  local_24 = (int *)0x0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_1c = local_34;
  if (2 < param_3) {
    puVar4 = (undefined4 *)FUN_004295e0(2);
    piVar9 = (int *)*puVar4;
    local_24 = piVar9;
    if (piVar9 != (int *)0x0) {
      *piVar9 = *piVar9 + 1;
      *piVar9 = *piVar9 + 1;
      if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
        TclFreeObj(piVar9);
      }
    }
  }
  if (3 < param_3) {
    puVar4 = (undefined4 *)FUN_004295e0(3);
    piVar8 = (int *)*puVar4;
    if (piVar8 != (int *)0x0) {
      *piVar8 = *piVar8 + 1;
    }
    local_20 = piVar8;
    puVar4 = (undefined4 *)FUN_006bafe0(local_68);
    local_50 = *puVar4;
    local_4c = puVar4[1];
    local_48 = puVar4[2];
    if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
      TclFreeObj(piVar8);
    }
  }
  if (4 < param_3) {
    puVar4 = (undefined4 *)FUN_004295e0(4);
    piVar8 = (int *)*puVar4;
    if (piVar8 != (int *)0x0) {
      *piVar8 = *piVar8 + 1;
    }
    local_20 = piVar8;
    puVar4 = (undefined4 *)FUN_006bafe0(local_68);
    local_5c = *puVar4;
    local_58 = puVar4[1];
    local_54 = puVar4[2];
    if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
      TclFreeObj(piVar8);
    }
  }
  if (local_3c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    if (local_40 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_44 = local_44 + 1;
  }
  piVar8 = (int *)*local_44;
  if (piVar8 != (int *)0x0) {
    *piVar8 = *piVar8 + 1;
  }
  local_8._0_1_ = 0xc;
  local_20 = piVar8;
  if (piVar8 == (int *)0x0) {
    ppuVar5 = &PTR_0071ce50;
  }
  else {
    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar8,0);
  }
  local_18 = piVar8;
  FUN_006b9200(ppuVar5);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  pcVar11 = TclFreeObj_exref;
  if ((local_18 != (int *)0x0) && (*piVar8 = *piVar8 + -1, pcVar11 = TclFreeObj_exref, *piVar8 < 1))
  {
    TclFreeObj(piVar8);
  }
  local_18 = (int *)FUN_00601f90(&local_14);
  if (local_18 == (int *)0x0) {
    if (*(char *)(DAT_00772400 + 0x590) == '\0') {
      if (*(char *)(DAT_00772400 + 0x91) == '\0') {
        puVar4 = (undefined4 *)FUN_004295e0(1);
        piVar8 = (int *)*puVar4;
        if (piVar8 != (int *)0x0) {
          *piVar8 = *piVar8 + 1;
        }
        FUN_006bc6a0("unknown class",piVar8);
        if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
          (*pcVar11)(piVar9);
        }
        local_8._0_1_ = 0x13;
        *local_1c = *local_1c + -1;
        if (*local_1c == 0) {
          FUN_006ba940();
        }
        local_8._0_1_ = 0x14;
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,0x15);
LAB_00624410:
        if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
          FUN_006ba940();
        }
        FUN_006bc0d0();
        FUN_00429650();
        FUN_0043fd30();
        ExceptionList = local_10;
        return 1;
      }
      local_18 = (int *)Tcl_NewIntObj(0xffffffff);
      *local_18 = *local_18 + 1;
      FUN_006bc670(&local_18);
      FUN_006bad60();
      if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
        (*pcVar11)(piVar9);
      }
      local_8._0_1_ = 0x10;
      *local_1c = *local_1c + -1;
      if (*local_1c == 0) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0x11;
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,0x12);
    }
    else {
      if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
        (*pcVar11)(piVar9);
      }
      local_8._0_1_ = 0xd;
      *local_1c = *local_1c + -1;
      if (*local_1c == 0) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0xe;
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,0xf);
    }
  }
  else if (*(char *)(DAT_00772400 + 0x91) == '\0') {
    iVar2 = *(int *)(DAT_00772400 + 0xa3f8);
    local_20 = (int *)0x2;
    if (-1 < iVar2) {
      iVar10 = DAT_00768388;
      if (*(char *)(DAT_00772400 + 0x590) != '\0') {
        iVar10 = 2;
      }
      if (iVar10 < 2 - iVar2) {
        if (iVar2 == 0) {
          uVar6 = FUN_005d7450(1,local_18[2],&local_50,&local_5c,0);
        }
        else if (iVar2 == 1) {
          uVar6 = FUN_005d7450(1,local_18[2],&local_50,&local_5c,1);
        }
        else {
          uVar6 = 0xffffffff;
        }
        local_18 = (int *)Tcl_NewIntObj(uVar6);
        *local_18 = *local_18 + 1;
        FUN_006bc670(&local_18);
        FUN_006bad60();
        if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
          (*pcVar11)(piVar9);
        }
        local_8._0_1_ = 0x19;
        *local_1c = *local_1c + -1;
        if (*local_1c == 0) {
          FUN_006ba940();
        }
        local_8._0_1_ = 0x1a;
        *piVar3 = *piVar3 + -1;
        if (*piVar3 == 0) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,0x1b);
        goto LAB_006247f7;
      }
    }
    if (piVar9 != (int *)0x0) {
      *piVar9 = *piVar9 + 1;
    }
    iVar2 = FUN_00601df0(0,local_28,piVar9,&local_50,&local_5c);
    if (iVar2 == 0) {
      puVar4 = (undefined4 *)FUN_004295e0(1);
      piVar8 = (int *)*puVar4;
      if (piVar8 != (int *)0x0) {
        *piVar8 = *piVar8 + 1;
      }
      FUN_006bc6a0("can\'t create",piVar8);
      if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
        TclFreeObj(piVar9);
      }
      local_8._0_1_ = 0x1c;
      *local_1c = *local_1c + -1;
      if (*local_1c == 0) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0x1d;
      *piVar3 = *piVar3 + -1;
      if (*piVar3 == 0) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,0x1e);
      goto LAB_00624410;
    }
    if (*(int *)(iVar2 + 0x39c) == -1) {
      iVar10 = local_18[8];
      uVar13 = 0;
      uVar6 = FUN_00602a10(iVar2);
      uVar7 = FUN_006028e0(iVar2);
      FUN_005cdae0(uVar7,uVar6,uVar13,iVar10);
      FUN_004d9d10();
      uVar6 = FUN_006028e0(iVar2);
      *(undefined4 *)(iVar2 + 0x39c) = uVar6;
      iVar10 = FUN_00602a10(iVar2);
      uVar6 = 0;
      *(int *)(iVar2 + 0x3a8) = iVar10;
      if ((*(int *)(iVar2 + 0x39c) != -1) && (iVar10 != -1)) {
        piVar8 = (int *)FUN_0040b550(*(int *)(iVar2 + 0x39c));
        if (*piVar8 == 0) {
          uVar6 = 0;
        }
        else {
          iVar10 = FUN_00405960(*(undefined4 *)(iVar2 + 0x3a8));
          local_28 = (undefined4 *)(iVar10 + 8);
          if (*(int *)(iVar10 + 0xc) < 1) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar6 = *(undefined4 *)*local_28;
        }
      }
      *(undefined4 *)(iVar2 + 0x3a0) = uVar6;
    }
    FUN_005cd7e0(&local_50);
    FUN_005cd840(&local_5c);
    if ((*(byte *)(iVar2 + 0x3d0) & 0x10) != 0) {
      iVar10 = iVar2;
      FUN_005ebc90(iVar2);
      FUN_005eb470(iVar10);
    }
    piVar8 = *(int **)(DAT_00772400 + 0xa3f8);
    if (*(int **)(DAT_00772400 + 0xa3f8) == (int *)0xffffffff) {
      piVar8 = local_20;
    }
    *(int **)(iVar2 + 0x2a8) = piVar8;
    iVar2 = FUN_005caf90();
    if (iVar2 == 0) {
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)Tcl_NewStringObj(iVar2,0xffffffff);
      *piVar8 = *piVar8 + 1;
    }
    local_20 = piVar8;
    FUN_006bc670(&local_20);
    pcVar11 = TclFreeObj_exref;
    if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, pcVar11 = TclFreeObj_exref, *piVar8 < 1))
    {
      TclFreeObj(piVar8);
    }
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
      (*pcVar11)(piVar9);
    }
    local_8._0_1_ = 0x1f;
    *local_1c = *local_1c + -1;
    if (*local_1c == 0) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0x20;
    *piVar3 = *piVar3 + -1;
    if (*piVar3 == 0) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,0x21);
  }
  else {
    local_20 = (int *)CONCAT31(local_20._1_3_,local_18[0x328] == 0);
    uVar6 = FUN_005d7450(local_20,local_18[2],&local_50,&local_5c,
                         *(undefined4 *)(DAT_00772400 + 0xa3f8));
    local_18 = (int *)Tcl_NewIntObj(uVar6);
    *local_18 = *local_18 + 1;
    FUN_006bc670(&local_18);
    FUN_006bad60();
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
      (*pcVar11)(piVar9);
    }
    local_8._0_1_ = 0x16;
    *local_1c = *local_1c + -1;
    if (*local_1c == 0) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0x17;
    *piVar3 = *piVar3 + -1;
    if (*piVar3 == 0) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,0x18);
  }
LAB_006247f7:
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_00429650();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

