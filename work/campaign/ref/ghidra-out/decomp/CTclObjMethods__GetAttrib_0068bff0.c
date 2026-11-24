
undefined4
CTclObjMethods__GetAttrib
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  undefined3 uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  int *extraout_EDX;
  undefined4 uVar9;
  uint uVar10;
  bool bVar11;
  int *piVar12;
  int *piVar13;
  undefined8 uVar14;
  int local_58;
  int local_48;
  int local_3c;
  uint local_38;
  int *local_2c;
  uint local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007117ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_28 = 0;
  local_14 = 0;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7878) &&
     (FUN_006cebf4(&DAT_00ca7878,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7878 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca787c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclObjMethods::GetAttrib()";
    *(int *)(&DAT_00773650 + iVar7) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7878);
  }
  iVar7 = DAT_00ca787c;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca787c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar9;
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
  local_8._0_1_ = 2;
  iVar3 = FUN_005c71c0(param_4,2,1);
  if (iVar3 == 0) {
    uVar9 = 1;
    goto LAB_0068c3fa;
  }
  local_20 = (int *)FUN_005da0f0();
  FUN_0040ba00();
  local_8 = CONCAT31(local_8._1_3_,3);
  local_18 = 0;
  if (0 < *extraout_EDX) {
    local_1c = extraout_EDX + 1;
    piVar13 = local_24;
    do {
      if (0x1ff < local_18) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_006b9b20(&local_2c,0,4);
      uVar6 = local_14;
      piVar12 = local_2c;
      local_8 = CONCAT31(local_8._1_3_,4);
      local_28 = local_14 | 5;
      pbVar8 = &DAT_00721330;
      pbVar4 = (byte *)(local_2c + 3);
      do {
        bVar1 = *pbVar4;
        bVar11 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_0068c170:
          uVar5 = -(uint)bVar11 | 1;
          goto LAB_0068c175;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar4[1];
        bVar11 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_0068c170;
        pbVar4 = pbVar4 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      uVar5 = 0;
LAB_0068c175:
      local_14 = local_28;
      if (uVar5 == 0) {
        if (0x1ff < local_18) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_006b9b20(&local_24,0,6);
        local_14 = uVar6 | 0xf;
        pbVar8 = &DAT_00721338;
        pbVar4 = (byte *)(local_24 + 3);
        do {
          bVar1 = *pbVar4;
          bVar11 = bVar1 < *pbVar8;
          if (bVar1 != *pbVar8) {
LAB_0068c1e0:
            uVar6 = -(uint)bVar11 | 1;
            goto LAB_0068c1e5;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar11 = bVar1 < pbVar8[1];
          if (bVar1 != pbVar8[1]) goto LAB_0068c1e0;
          pbVar4 = pbVar4 + 2;
          pbVar8 = pbVar8 + 2;
        } while (bVar1 != 0);
        uVar6 = 0;
LAB_0068c1e5:
        piVar13 = local_24;
        if (uVar6 == 0) goto LAB_0068c1ed;
        bVar11 = true;
      }
      else {
LAB_0068c1ed:
        bVar11 = false;
      }
      if ((local_14 & 2) != 0) {
        local_28 = local_14 & 0xfffffffd;
        local_8 = 5;
        local_14 = local_28;
        if ((piVar13 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 == 0)) {
          FUN_006ba940();
        }
      }
      local_8 = 3;
      if ((local_14 & 1) != 0) {
        local_14 = local_14 & 0xfffffffe;
        local_8._1_3_ = 0;
        uVar2 = local_8._1_3_;
        local_8._0_1_ = 6;
        local_8._1_3_ = 0;
        if ((piVar12 != (int *)0x0) &&
           (*piVar12 = *piVar12 + -1, uVar2 = local_8._1_3_, *piVar12 == 0)) {
          FUN_006ba940();
          uVar2 = local_8._1_3_;
        }
        local_8._1_3_ = uVar2;
        local_8 = CONCAT31(local_8._1_3_,3);
      }
      if (bVar11) {
        FUN_0040b930(1);
        if (local_38 <= local_38 - 1) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        *(uint *)(local_3c + (local_38 - 1) * 4) = local_18;
      }
      local_18 = local_18 + 1;
    } while ((int)local_18 < *local_20);
  }
  piVar13 = (int *)0x0;
  uVar6 = 0xffffffff;
  local_1c = (int *)0x0;
  uVar10 = 0;
  uVar5 = uVar6;
  if (0 < (int)local_38) {
    do {
      local_2c = piVar13;
      if (local_38 <= uVar10) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar13 = local_1c;
      }
      uVar6 = *(uint *)(local_3c + uVar10 * 4);
      if (*(int *)(iVar3 + 0x21c) == 0) {
        if (uVar6 < 0x200) {
          iVar7 = FUN_005da0f0();
          piVar12 = *(int **)(iVar7 + 0x1804 + uVar6 * 4);
          piVar13 = local_1c;
        }
        else {
LAB_0068c30d:
          piVar12 = (int *)0x0;
        }
      }
      else {
        if (0x1ff < uVar6) goto LAB_0068c30d;
        piVar12 = *(int **)(*(int *)(iVar3 + 0x21c) + uVar6 * 4);
      }
      if ((float)piVar13 < (float)piVar12) {
        piVar13 = piVar12;
        local_1c = piVar12;
      }
      uVar6 = uVar10;
      if ((float)piVar12 <= (float)local_2c) {
        uVar6 = uVar5;
      }
      uVar10 = uVar10 + 1;
      uVar5 = uVar6;
    } while ((int)uVar10 < (int)local_38);
  }
  piVar13 = (int *)0x0;
  if (uVar6 != 0xffffffff) {
    if (local_38 <= uVar6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar6 = *(uint *)(local_3c + uVar6 * 4);
    if (uVar6 < 0x200) {
      piVar13 = local_20 + uVar6;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar13 = local_20;
    }
    if (piVar13[1] + 0xc == 0) {
      piVar13 = (int *)0x0;
    }
    else {
      piVar13 = (int *)Tcl_NewStringObj(piVar13[1] + 0xc,0xffffffff);
      iVar3 = *piVar13;
      *piVar13 = iVar3 + 1;
      if (iVar3 + 1 < 1) {
        TclFreeObj(piVar13);
      }
    }
  }
  if (local_58 == 0) {
    if (piVar13 != (int *)0x0) goto LAB_0068c3d1;
  }
  else if (piVar13 == (int *)0x0) {
    Tcl_ResetResult(local_58);
  }
  else {
    Tcl_SetObjResult(local_58,piVar13);
LAB_0068c3d1:
    *piVar13 = *piVar13 + -1;
    if (*piVar13 < 1) {
      TclFreeObj(piVar13);
    }
  }
  local_8._0_1_ = 7;
  FUN_0040b980(0);
  uVar9 = 0;
  if (local_3c != 0) {
    FUN_006ba940();
  }
LAB_0068c3fa:
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_004297b0(0);
  if (local_48 != 0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

