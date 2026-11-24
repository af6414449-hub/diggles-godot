
undefined4
CTclGlobalMethods__SMMusicTheme
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined **ppuVar4;
  byte *pbVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 uVar12;
  bool bVar13;
  undefined8 uVar14;
  int **ppiVar15;
  int **ppiVar16;
  int local_3c;
  undefined4 *local_2c;
  uint local_28;
  int local_24;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ee0d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7308) &&
     (FUN_006cebf4(&DAT_00ca7308,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7308 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca730c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::SMMusicTheme()";
    *(int *)(&DAT_00773650 + iVar8) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7308);
  }
  iVar8 = DAT_00ca730c;
  uVar12 = *(undefined4 *)(&DAT_00773650 + DAT_00ca730c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar12;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar3 == 0) {
    uVar14 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 < 3) {
    FUN_006bc8f0(2);
    uVar12 = 1;
  }
  else {
    FUN_004298b0(param_3,param_4);
    if (local_24 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_2c + 1;
    }
    piVar2 = (int *)*puVar10;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    local_18 = piVar2;
    if (piVar2 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
      piVar7 = (int *)0x0;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
      piVar7 = piVar2;
    }
    FUN_006b8fb0(ppuVar4);
    if ((piVar7 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if (local_24 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_2c;
      if (local_28 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_28 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_2c + 2;
    }
    piVar2 = (int *)*puVar10;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8._0_1_ = 6;
    local_14 = piVar2;
    if (piVar2 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
      piVar7 = (int *)0x0;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
      piVar7 = piVar2;
    }
    FUN_006b8fb0(ppuVar4);
    local_8._0_1_ = 8;
    if ((piVar7 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    local_14 = (int *)FUN_006ba810(0x19);
    local_14[1] = 0x14;
    local_14[2] = -1;
    *local_14 = 0;
    *(undefined1 *)(local_14 + 3) = 0;
    local_14[3] = 0x68746f62;
    *(undefined1 *)(local_14 + 4) = 0;
    local_14[2] = 4;
    *local_14 = 1;
    local_8 = CONCAT31(local_8._1_3_,9);
    if (param_3 == 4) {
      if (local_24 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar10 = local_2c;
        if (local_28 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_28 < 4) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar10 = local_2c + 3;
      }
      piVar2 = (int *)*puVar10;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      local_8._0_1_ = 10;
      if (piVar2 == (int *)0x0) {
        ppuVar4 = &PTR_0071ce50;
        piVar7 = (int *)0x0;
      }
      else {
        ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
        piVar7 = piVar2;
      }
      FUN_006b9200(ppuVar4);
      local_8 = CONCAT31(local_8._1_3_,9);
      if ((piVar7 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj(piVar2);
      }
    }
    piVar2 = local_14;
    pbVar9 = (byte *)(local_14 + 3);
    pcVar11 = "marker";
    pbVar5 = pbVar9;
    do {
      bVar1 = *pbVar5;
      bVar13 = bVar1 < (byte)*pcVar11;
      if (bVar1 != *pcVar11) {
LAB_0065af90:
        uVar6 = -(uint)bVar13 | 1;
        goto LAB_0065af95;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar13 = bVar1 < ((byte *)pcVar11)[1];
      if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_0065af90;
      pbVar5 = pbVar5 + 2;
      pcVar11 = (char *)((byte *)pcVar11 + 2);
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_0065af95:
    if (uVar6 == 0) {
      uVar12 = 1;
    }
    else {
      pcVar11 = "instant";
      do {
        bVar1 = *pbVar9;
        bVar13 = bVar1 < (byte)*pcVar11;
        if (bVar1 != *pcVar11) {
LAB_0065afc3:
          uVar6 = -(uint)bVar13 | 1;
          goto LAB_0065afc8;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar9[1];
        bVar13 = bVar1 < ((byte *)pcVar11)[1];
        if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_0065afc3;
        pbVar9 = pbVar9 + 2;
        pcVar11 = (char *)((byte *)pcVar11 + 2);
      } while (bVar1 != 0);
      uVar6 = 0;
LAB_0065afc8:
      uVar12 = 0;
      if (uVar6 == 0) {
        uVar12 = 2;
      }
    }
    ppiVar16 = &local_18;
    ppiVar15 = &local_1c;
    FUN_005f8080(ppiVar15,ppiVar16,uVar12);
    iVar3 = FUN_005f8ad0(ppiVar15,ppiVar16,uVar12);
    if (iVar3 == -1) {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar10 = local_2c;
        if (local_28 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_28 < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar10 = local_2c + 1;
      }
      piVar7 = (int *)*puVar10;
      if (piVar7 != (int *)0x0) {
        *piVar7 = *piVar7 + 1;
      }
      FUN_006bc6a0("Music Theme redefinition",piVar7);
      uVar12 = 1;
    }
    else {
      piVar7 = (int *)Tcl_NewIntObj(iVar3);
      *piVar7 = *piVar7 + 1;
      iVar3 = *piVar7;
      if (local_3c != 0) {
        Tcl_SetObjResult(local_3c,piVar7);
        iVar3 = *piVar7;
      }
      *piVar7 = iVar3 + -1;
      if (iVar3 + -1 < 1) {
        TclFreeObj(piVar7);
      }
      uVar12 = 0;
    }
    local_8._0_1_ = 0xe;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0xf;
    if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0x10;
    if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0x11;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,0x12);
    FUN_004297b0(0);
    if (local_2c != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar12;
}

