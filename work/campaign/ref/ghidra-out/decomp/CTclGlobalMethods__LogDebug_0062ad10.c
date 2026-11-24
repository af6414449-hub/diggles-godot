
undefined4
CTclGlobalMethods__LogDebug(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined **ppuVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 *puVar9;
  bool bVar10;
  undefined8 uVar11;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c4cd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d60) &&
     (FUN_006cebf4(&DAT_00ca6d60,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6d60 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6d64 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::LogDebug()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d60);
  }
  iVar7 = DAT_00ca6d64;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d64 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar2;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar11 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  if (param_3 == 2) {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar9 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_20 + 1;
    }
    piVar3 = (int *)*puVar9;
    if (piVar3 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      *piVar3 = *piVar3 + 1;
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
    }
    pbVar8 = &DAT_00724a84;
    do {
      bVar1 = *(byte *)ppuVar5;
      bVar10 = bVar1 < *pbVar8;
      if (bVar1 != *pbVar8) {
LAB_0062ae51:
        uVar6 = -(uint)bVar10 | 1;
        goto LAB_0062ae56;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar5 + 1);
      bVar10 = bVar1 < pbVar8[1];
      if (bVar1 != pbVar8[1]) goto LAB_0062ae51;
      ppuVar5 = (undefined **)((int)ppuVar5 + 2);
      pbVar8 = pbVar8 + 2;
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_0062ae56:
    if (uVar6 == 0) {
      DAT_0077240a = 0;
    }
    else {
      if (piVar3 == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
      }
      pbVar8 = (byte *)&DAT_0072891c;
      do {
        bVar1 = *(byte *)ppuVar5;
        bVar10 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_0062aea0:
          uVar6 = -(uint)bVar10 | 1;
          goto LAB_0062aea5;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar5 + 1);
        bVar10 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_0062aea0;
        ppuVar5 = (undefined **)((int)ppuVar5 + 2);
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      uVar6 = 0;
LAB_0062aea5:
      if (uVar6 == 0) {
        DAT_0077240a = 1;
      }
    }
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
    }
  }
  local_8._0_1_ = 1;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

