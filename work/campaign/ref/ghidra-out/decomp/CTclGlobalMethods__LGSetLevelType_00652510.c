
undefined4
CTclGlobalMethods__LGSetLevelType
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined **ppuVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  byte *pbVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  bool bVar13;
  undefined8 uVar14;
  undefined4 *local_28;
  uint local_24;
  int local_20;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d7c5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7228) &&
     (FUN_006cebf4(&DAT_00ca7228,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7228 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca722c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::LGSetLevelType()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7228);
  }
  iVar7 = DAT_00ca722c;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca722c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar10;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar3 == 0) {
    uVar14 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == 2) {
    iVar3 = FUN_0058a820();
    if (local_20 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_28;
      if (local_24 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_24 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_28 + 1;
    }
    piVar2 = (int *)*puVar11;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar2 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
    }
    FUN_006b8fb0(ppuVar4);
    pcVar8 = "default";
    pbVar12 = (byte *)(local_14 + 3);
    pbVar5 = pbVar12;
    do {
      bVar1 = *pbVar5;
      bVar13 = bVar1 < (byte)*pcVar8;
      if (bVar1 != *pcVar8) {
LAB_00652697:
        uVar6 = -(uint)bVar13 | 1;
        goto LAB_0065269c;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar13 = bVar1 < ((byte *)pcVar8)[1];
      if (bVar1 != ((byte *)pcVar8)[1]) goto LAB_00652697;
      pbVar5 = pbVar5 + 2;
      pcVar8 = (char *)((byte *)pcVar8 + 2);
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_0065269c:
    if (uVar6 == 0) {
      bVar13 = false;
      *(undefined4 *)(iVar3 + 0x7c) = 0;
    }
    else {
      pbVar9 = &DAT_0072a8dc;
      pbVar5 = pbVar12;
      do {
        bVar1 = *pbVar5;
        bVar13 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_006526d8:
          uVar6 = -(uint)bVar13 | 1;
          goto LAB_006526dd;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar13 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_006526d8;
        pbVar5 = pbVar5 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      uVar6 = 0;
LAB_006526dd:
      if (uVar6 == 0) {
        bVar13 = false;
        *(undefined4 *)(iVar3 + 0x7c) = 1;
      }
      else {
        pbVar5 = &DAT_0072a8e4;
        do {
          bVar1 = *pbVar12;
          bVar13 = bVar1 < *pbVar5;
          if (bVar1 != *pbVar5) {
LAB_00652714:
            uVar6 = -(uint)bVar13 | 1;
            goto LAB_00652719;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar12[1];
          bVar13 = bVar1 < pbVar5[1];
          if (bVar1 != pbVar5[1]) goto LAB_00652714;
          pbVar12 = pbVar12 + 2;
          pbVar5 = pbVar5 + 2;
        } while (bVar1 != 0);
        uVar6 = 0;
LAB_00652719:
        if (uVar6 == 0) {
          bVar13 = false;
          *(undefined4 *)(iVar3 + 0x7c) = 2;
        }
        else {
          bVar13 = true;
        }
      }
    }
    local_8._0_1_ = 4;
    if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,2);
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      TclFreeObj(piVar2);
    }
    if (bVar13) {
      FUN_006bc6a0("invalid leveltype",0);
      uVar10 = 1;
    }
    else {
      uVar10 = 0;
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar10 = 1;
  }
  local_8._0_1_ = 5;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_004297b0(0);
  if (local_28 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

