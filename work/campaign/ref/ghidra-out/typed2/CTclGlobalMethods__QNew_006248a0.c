
undefined4
CTclGlobalMethods__QNew(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  code *pcVar11;
  undefined8 uVar12;
  undefined4 uVar13;
  int local_84;
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
  int *local_28;
  int *local_24;
  int local_20;
  int *local_1c;
  int *local_18 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070be7d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6cc0) &&
     (FUN_006cebf4(&DAT_00ca6cc0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6cc0 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca6cc4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CTclGlobalMethods::QNew()";
    *(int *)(&DAT_00773650 + iVar10) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6cc0);
  }
  iVar10 = DAT_00ca6cc4;
  local_2c = &DAT_00ca6cc4;
  uVar8 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6cc4 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar8;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar3 == 0) {
    uVar12 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar4 = (int *)FUN_006ba810(0x19);
  piVar5 = piVar4 + 3;
  piVar4[2] = -1;
  *piVar4 = 0;
  *(undefined1 *)piVar5 = 0;
  piVar4[1] = 0x14;
  *piVar5 = 0x73696874;
  *(undefined1 *)(piVar4 + 4) = 0;
  piVar4[2] = 4;
  *piVar4 = 1;
  if (local_84 == 0) {
    iVar10 = 0;
    iVar3 = 1;
  }
  else {
    iVar10 = Tcl_GetAssocData(local_84,piVar5,0);
    iVar3 = *piVar4;
  }
  local_8._0_1_ = 3;
  *piVar4 = iVar3 + -1;
  if (iVar3 + -1 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 2;
  uVar2 = (undefined1)local_8;
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
  local_8._0_1_ = uVar2;
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
  FUN_006b8fb0(&DAT_0072e95c);
  local_8._0_1_ = 8;
  iVar3 = FUN_006055d0(local_84,iVar10,&local_1c);
  local_8._0_1_ = 9;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 2;
  *(int *)(iVar10 + 0xd0) = iVar3;
  local_20 = iVar10;
  if (iVar3 != 0) {
    local_20 = iVar3;
  }
  local_1c = (int *)FUN_006ba810(0x19);
  local_1c[1] = 0x14;
  local_1c[2] = -1;
  *(undefined1 *)(local_1c + 3) = 0;
  *local_1c = 1;
  local_8._0_1_ = 10;
  piVar5 = (int *)FUN_006ba810(0x19);
  piVar5[1] = 0x14;
  piVar5[2] = -1;
  *(undefined1 *)(piVar5 + 3) = 0;
  *piVar5 = 1;
  local_8 = CONCAT31(local_8._1_3_,0xb);
  local_30 = piVar5;
  piVar4 = (int *)FUN_006ba810(0x19);
  piVar4[1] = 0x14;
  piVar4[2] = -1;
  *(undefined1 *)(piVar4 + 3) = 0;
  *piVar4 = 1;
  local_34 = piVar4;
  local_28 = piVar4;
  if (local_3c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_44;
    if (local_40 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_44;
    }
  }
  else {
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_44 + 1;
  }
  piVar7 = (int *)*puVar6;
  if (piVar7 != (int *)0x0) {
    *piVar7 = *piVar7 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,0xd);
  local_24 = piVar7;
  if (piVar7 == (int *)0x0) {
    FUN_006b9200(&PTR_0071ce50);
  }
  else {
    uVar8 = Tcl_GetStringFromObj(piVar7,0);
    FUN_006b9200(uVar8);
    *piVar7 = *piVar7 + -1;
    if (*piVar7 < 1) {
      TclFreeObj(piVar7);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,0xe);
  if (param_3 == 3) {
    puVar6 = (undefined4 *)FUN_004295e0(2);
    piVar7 = (int *)*puVar6;
    local_24 = piVar7;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
    }
  }
  else {
    piVar7 = (int *)Tcl_NewStringObj(&PTR_0071ce50,0xffffffff);
    iVar3 = *piVar7;
    *piVar7 = iVar3 + 1;
    local_24 = piVar7;
    if (iVar3 + 1 < 1) {
      TclFreeObj(piVar7);
    }
  }
  local_18[0] = (int *)FUN_00601f90(&local_1c);
  if (local_18[0] != (int *)0x0) {
    local_50 = *(undefined4 *)(DAT_00772400 + 0x350);
    local_4c = *(undefined4 *)(DAT_00772400 + 0x354);
    local_48 = *(undefined4 *)(DAT_00772400 + 0x358);
    FUN_00595770(PTR_0077241c);
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_5c = 0;
    local_58 = 0;
    local_54 = 0;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
    }
    iVar3 = FUN_00601df0(0,local_20,piVar7,&local_5c,&local_50);
    local_20 = iVar3;
    if (iVar3 != 0) {
      if (*(int *)(iVar3 + 0x39c) == -1) {
        iVar10 = local_18[0][8];
        uVar13 = 0;
        uVar8 = FUN_00602a10(iVar3);
        uVar9 = FUN_006028e0(iVar3);
        FUN_005cdae0(uVar9,uVar8,uVar13,iVar10);
        FUN_004d9d10();
        uVar8 = FUN_006028e0(iVar3);
        *(undefined4 *)(iVar3 + 0x39c) = uVar8;
        iVar10 = FUN_00602a10(iVar3);
        uVar8 = 0;
        *(int *)(iVar3 + 0x3a8) = iVar10;
        if ((*(int *)(iVar3 + 0x39c) != -1) && (iVar10 != -1)) {
          piVar4 = (int *)FUN_0040b550(*(int *)(iVar3 + 0x39c));
          if (*piVar4 == 0) {
            uVar8 = 0;
          }
          else {
            iVar10 = FUN_00405960(*(undefined4 *)(iVar3 + 0x3a8));
            local_18[0] = (int *)(iVar10 + 8);
            if (*(int *)(iVar10 + 0xc) < 1) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            uVar8 = *(undefined4 *)*local_18[0];
          }
        }
        *(undefined4 *)(iVar3 + 0x3a0) = uVar8;
      }
      *(undefined4 *)(iVar3 + 0x36c) = *(undefined4 *)(DAT_00772400 + 100);
      uVar8 = FUN_00424120();
      FUN_005cd7e0(uVar8);
      *(undefined4 *)(iVar3 + 0x2a8) = 2;
      iVar3 = FUN_005caf90();
      if (iVar3 == 0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)Tcl_NewStringObj(iVar3,0xffffffff);
        *piVar4 = *piVar4 + 1;
      }
      local_18[0] = piVar4;
      FUN_006bc670(local_18);
      pcVar11 = TclFreeObj_exref;
      if ((piVar4 != (int *)0x0) &&
         (*piVar4 = *piVar4 + -1, pcVar11 = TclFreeObj_exref, *piVar4 < 1)) {
        TclFreeObj(piVar4);
      }
      if ((*(byte *)(local_20 + 0x3d0) & 0x10) != 0) {
        iVar3 = local_20;
        FUN_005ebc90(local_20);
        FUN_005eb470(iVar3);
      }
      if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
        (*pcVar11)(piVar7);
      }
      local_8._0_1_ = 0x17;
      *local_28 = *local_28 + -1;
      if (*local_28 == 0) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0x18;
      *piVar5 = *piVar5 + -1;
      if (*piVar5 == 0) {
        FUN_006ba940();
      }
      local_8 = CONCAT31(local_8._1_3_,0x19);
      if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
        FUN_006ba940();
      }
      FUN_006bc0d0();
      FUN_00429650();
      FUN_0043fd30();
      ExceptionList = local_10;
      return 0;
    }
    puVar6 = (undefined4 *)FUN_004295e0(1);
    piVar1 = (int *)*puVar6;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("can\'t create",piVar1);
    if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
      TclFreeObj(piVar7);
    }
    local_8._0_1_ = 0x14;
    *piVar4 = *piVar4 + -1;
    if (*piVar4 == 0) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0x15;
    *piVar5 = *piVar5 + -1;
    if (*piVar5 == 0) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,0x16);
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_00429650();
    FUN_0043fd30();
    ExceptionList = local_10;
    return 1;
  }
  puVar6 = (undefined4 *)FUN_004295e0(1);
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  FUN_006bc6a0("unknown class",piVar1);
  if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
    TclFreeObj(piVar7);
  }
  local_8._0_1_ = 0xf;
  *piVar4 = *piVar4 + -1;
  if (*piVar4 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x10;
  *piVar5 = *piVar5 + -1;
  if (*piVar5 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 0x11;
  if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  local_8._0_1_ = 0x12;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x13);
  FUN_004297b0(0);
  if (local_44 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

