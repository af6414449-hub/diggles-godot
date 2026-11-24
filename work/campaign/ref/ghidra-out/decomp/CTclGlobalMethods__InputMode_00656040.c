
undefined4
CTclGlobalMethods__InputMode(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  undefined **ppuVar7;
  int *piVar8;
  uint uVar9;
  char *pcVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  code *pcVar13;
  bool bVar14;
  undefined8 uVar15;
  int local_30;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ccbd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7280) &&
     (FUN_006cebf4(&DAT_00ca7280,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7280 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7284 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclGlobalMethods::InputMode()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7280);
  }
  iVar4 = DAT_00ca7284;
  uVar2 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7284 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar2;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar15 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar15;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar4 = FUN_004ecd40();
  pcVar13 = TclFreeObj_exref;
  iVar3 = *(int *)(iVar4 + 0x438);
  if (param_3 == 2) {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar11 = local_20 + 1;
    }
    piVar8 = (int *)*puVar11;
    if (piVar8 == (int *)0x0) {
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      *piVar8 = *piVar8 + 1;
      pbVar12 = &DAT_00730a54;
      pbVar5 = (byte *)Tcl_GetStringFromObj(piVar8,0);
      do {
        bVar1 = *pbVar5;
        bVar14 = bVar1 < *pbVar12;
        if (bVar1 != *pbVar12) {
LAB_006561a2:
          uVar9 = -(uint)bVar14 | 1;
          goto LAB_006561a7;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar5[1];
        bVar14 = bVar1 < pbVar12[1];
        if (bVar1 != pbVar12[1]) goto LAB_006561a2;
        pbVar5 = pbVar5 + 2;
        pbVar12 = pbVar12 + 2;
      } while (bVar1 != 0);
      uVar9 = 0;
LAB_006561a7:
      iVar6 = 0;
      if (uVar9 != 0) {
        iVar6 = iVar3;
      }
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar8,0);
      iVar3 = iVar6;
      pcVar13 = TclFreeObj_exref;
    }
    pcVar10 = "console";
    do {
      bVar1 = *(byte *)ppuVar7;
      bVar14 = bVar1 < (byte)*pcVar10;
      if (bVar1 != *pcVar10) {
LAB_006561f0:
        uVar9 = -(uint)bVar14 | 1;
        goto LAB_006561f5;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar7 + 1);
      bVar14 = bVar1 < ((byte *)pcVar10)[1];
      if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_006561f0;
      ppuVar7 = (undefined **)((int)ppuVar7 + 2);
      pcVar10 = (char *)((byte *)pcVar10 + 2);
    } while (bVar1 != 0);
    uVar9 = 0;
LAB_006561f5:
    if (uVar9 == 0) {
      iVar3 = 1;
    }
    if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
      (*pcVar13)(piVar8);
    }
  }
  iVar6 = *(int *)(iVar4 + 0x438);
  if (iVar3 != *(int *)(iVar4 + 0x438)) {
    *(int *)(iVar4 + 0x438) = iVar3;
    iVar6 = iVar3;
  }
  if (iVar6 == 0) {
    pcVar10 = "pc";
  }
  else {
    if (iVar6 != 1) goto LAB_0065626e;
    pcVar10 = "console";
  }
  piVar8 = (int *)Tcl_NewStringObj(pcVar10,0xffffffff);
  *piVar8 = *piVar8 + 1;
  iVar3 = *piVar8;
  if (local_30 != 0) {
    Tcl_SetObjResult(local_30,piVar8);
    iVar3 = *piVar8;
  }
  *piVar8 = iVar3 + -1;
  if (iVar3 + -1 < 1) {
    (*pcVar13)(piVar8);
  }
LAB_0065626e:
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

