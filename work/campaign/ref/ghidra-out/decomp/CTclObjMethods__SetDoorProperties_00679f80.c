
undefined4
CTclObjMethods__SetDoorProperties
          (undefined4 param_1,undefined4 param_2,undefined **param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined **ppuVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int *piVar13;
  int *piVar14;
  byte *pbVar15;
  bool bVar16;
  undefined8 uVar17;
  int local_40;
  int *local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710e5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7558) &&
     (FUN_006cebf4(&DAT_00ca7558,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca7558 == -1)) {
    iVar11 = DAT_00783650 * 0x40;
    DAT_00ca755c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar11) = "TCL:CTclObjMethods::SetDoorProperties()";
    *(int *)(&DAT_00773650 + iVar11) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7558);
  }
  iVar11 = DAT_00ca755c;
  uVar12 = *(undefined4 *)(&DAT_00773650 + DAT_00ca755c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar12;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar11 * 0x10];
  if (iVar2 == 0) {
    uVar17 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar11 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar11 * 0x10) = uVar17;
  }
  (&DAT_00773654)[iVar11 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if ((param_3 != (undefined **)0x3) && (param_3 != (undefined **)0x4)) {
    FUN_006bc8f0(2);
    uVar12 = 1;
    goto LAB_0067a396;
  }
  local_14 = FUN_005c71c0(param_4,2,1);
  if (local_14 == 0) {
    uVar12 = 1;
    goto LAB_0067a396;
  }
  if ((*(int *)(local_14 + 0x3ec) != 0) && (*(int *)(*(int *)(local_14 + 0x3ec) + 0xc) != 0)) {
    puVar3 = (undefined4 *)FUN_004295e0(2);
    piVar13 = (int *)*puVar3;
    if (piVar13 != (int *)0x0) {
      *piVar13 = *piVar13 + 1;
    }
    local_8._0_1_ = 3;
    if (piVar13 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
      piVar14 = (int *)0x0;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar13,0);
      piVar14 = piVar13;
    }
    FUN_006b8fb0(ppuVar4);
    local_8 = CONCAT31(local_8._1_3_,5);
    if ((piVar14 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 < 1)) {
      TclFreeObj(piVar13);
    }
    piVar13 = local_18;
    pcVar9 = "closed";
    pbVar15 = (byte *)(local_18 + 3);
    pbVar5 = pbVar15;
    do {
      bVar1 = *pbVar5;
      bVar16 = bVar1 < (byte)*pcVar9;
      if (bVar1 != *pcVar9) {
LAB_0067a117:
        uVar6 = -(uint)bVar16 | 1;
        goto LAB_0067a11c;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar16 = bVar1 < ((byte *)pcVar9)[1];
      if (bVar1 != ((byte *)pcVar9)[1]) goto LAB_0067a117;
      pbVar5 = pbVar5 + 2;
      pcVar9 = (char *)((byte *)pcVar9 + 2);
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_0067a11c:
    pcVar9 = "openforplayer";
    uVar6 = (uint)(uVar6 == 0);
    pbVar5 = pbVar15;
    do {
      bVar1 = *pbVar5;
      bVar16 = bVar1 < (byte)*pcVar9;
      if (bVar1 != *pcVar9) {
LAB_0067a150:
        uVar7 = -(uint)bVar16 | 1;
        goto LAB_0067a155;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar16 = bVar1 < ((byte *)pcVar9)[1];
      if (bVar1 != ((byte *)pcVar9)[1]) goto LAB_0067a150;
      pbVar5 = pbVar5 + 2;
      pcVar9 = (char *)((byte *)pcVar9 + 2);
    } while (bVar1 != 0);
    uVar7 = 0;
LAB_0067a155:
    if (uVar7 == 0) {
      uVar6 = 2;
    }
    pcVar9 = "openforfriends";
    pbVar5 = pbVar15;
    do {
      bVar1 = *pbVar5;
      bVar16 = bVar1 < (byte)*pcVar9;
      if (bVar1 != *pcVar9) {
LAB_0067a186:
        uVar7 = -(uint)bVar16 | 1;
        goto LAB_0067a18b;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar16 = bVar1 < ((byte *)pcVar9)[1];
      if (bVar1 != ((byte *)pcVar9)[1]) goto LAB_0067a186;
      pbVar5 = pbVar5 + 2;
      pcVar9 = (char *)((byte *)pcVar9 + 2);
    } while (bVar1 != 0);
    uVar7 = 0;
LAB_0067a18b:
    if (uVar7 == 0) {
      uVar6 = 3;
    }
    pcVar9 = "openforclasses";
    pbVar5 = pbVar15;
    do {
      bVar1 = *pbVar5;
      bVar16 = bVar1 < (byte)*pcVar9;
      if (bVar1 != *pcVar9) {
LAB_0067a1c0:
        uVar7 = -(uint)bVar16 | 1;
        goto LAB_0067a1c5;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar16 = bVar1 < ((byte *)pcVar9)[1];
      if (bVar1 != ((byte *)pcVar9)[1]) goto LAB_0067a1c0;
      pbVar5 = pbVar5 + 2;
      pcVar9 = (char *)((byte *)pcVar9 + 2);
    } while (bVar1 != 0);
    uVar7 = 0;
LAB_0067a1c5:
    pcVar9 = "openforall";
    if (uVar7 == 0) {
      uVar6 = 4;
    }
    do {
      bVar1 = *pbVar15;
      bVar16 = bVar1 < (byte)*pcVar9;
      if (bVar1 != *pcVar9) {
LAB_0067a1f4:
        uVar7 = -(uint)bVar16 | 1;
        goto LAB_0067a1f9;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar15[1];
      bVar16 = bVar1 < ((byte *)pcVar9)[1];
      if (bVar1 != ((byte *)pcVar9)[1]) goto LAB_0067a1f4;
      pbVar15 = pbVar15 + 2;
      pcVar9 = (char *)((byte *)pcVar9 + 2);
    } while (bVar1 != 0);
    uVar7 = 0;
LAB_0067a1f9:
    if (uVar7 == 0) {
      uVar6 = 5;
    }
    iVar2 = *(int *)(*(int *)(local_14 + 0x3ec) + 0xc);
    iVar11 = *(int *)(iVar2 + 0x18);
    *(uint *)(iVar2 + 0x18) = uVar6;
    if ((*(int *)(iVar2 + 0x28) == 0) && (uVar6 != 0)) {
      *(undefined4 *)(iVar2 + 4) = 3;
    }
    if (iVar11 == 1) {
      if (uVar6 != 1) {
LAB_0067a236:
        *(undefined1 *)(iVar2 + 0x1c) = 1;
        FUN_0060ceb0();
      }
    }
    else if (uVar6 == 1) goto LAB_0067a236;
    iVar2 = local_14;
    if (param_3 == (undefined **)0x4) {
      FUN_00444ea0(0);
      puVar3 = (undefined4 *)FUN_004295e0(3);
      piVar14 = (int *)*puVar3;
      if (piVar14 != (int *)0x0) {
        *piVar14 = *piVar14 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,6);
      iVar11 = 0;
      while( true ) {
        local_20 = iVar11;
        if (piVar14 == (int *)0x0) {
          iVar10 = 0;
        }
        else {
          iVar8 = Tcl_ListObjLength(0,piVar14,&local_24);
          iVar10 = local_24;
          if (iVar8 != 0) {
            iVar10 = 0;
          }
        }
        if (iVar10 <= iVar11) break;
        iVar2 = *(int *)(*(int *)(iVar2 + 0x3ec) + 0xc);
        FUN_00444ca0(1);
        local_1c = *(int *)(iVar2 + 0x30) - 1;
        if ((piVar14 == (int *)0x0) ||
           (iVar2 = Tcl_ListObjIndex(0,piVar14,iVar11,&local_28), iVar2 != 0)) {
          piVar13 = (int *)0x0;
        }
        else {
          piVar13 = local_28;
          if (local_28 != (int *)0x0) {
            *local_28 = *local_28 + 1;
          }
        }
        local_8 = CONCAT31(local_8._1_3_,7);
        if (piVar13 == (int *)0x0) {
          param_3 = &PTR_0071ce50;
        }
        else {
          param_3 = (undefined **)Tcl_GetStringFromObj(piVar13,0);
        }
        if (*(uint *)(*(int *)(*(int *)(local_14 + 0x3ec) + 0xc) + 0x30) <= local_1c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_006b9200(param_3);
        local_8 = CONCAT31(local_8._1_3_,6);
        if ((piVar13 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 < 1)) {
          TclFreeObj(piVar13);
        }
        iVar11 = local_20 + 1;
        iVar2 = local_14;
      }
      piVar13 = local_18;
      if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
        TclFreeObj(piVar14);
        piVar13 = local_18;
      }
    }
    local_8._0_1_ = 8;
    if ((piVar13 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 == 0)) {
      FUN_006ba940();
    }
  }
  uVar12 = 0;
LAB_0067a396:
  local_8._0_1_ = 9;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_004297b0(0);
  if (local_40 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar12;
}

