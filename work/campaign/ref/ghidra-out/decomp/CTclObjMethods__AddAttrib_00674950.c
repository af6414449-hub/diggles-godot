
undefined4
CTclObjMethods__AddAttrib
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int *piVar6;
  undefined **ppuVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  byte *pbVar11;
  char *pcVar12;
  int *extraout_EDX;
  undefined4 uVar13;
  undefined4 *puVar14;
  bool bVar15;
  float fVar16;
  float fVar17;
  ulonglong uVar18;
  undefined8 uVar19;
  int local_64;
  undefined4 *local_54;
  uint local_50;
  int local_4c;
  int local_48;
  uint local_44;
  undefined4 local_34;
  int *piStack_30;
  int local_2c;
  int *local_28;
  int *local_24;
  float local_20;
  int *local_1c;
  int *local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00710965;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = 0.0;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca74b8) &&
     (FUN_006cebf4(&DAT_00ca74b8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca74b8 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca74bc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CTclObjMethods::AddAttrib()";
    *(int *)(&DAT_00773650 + iVar10) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca74b8);
  }
  iVar10 = DAT_00ca74bc;
  uVar13 = *(undefined4 *)(&DAT_00773650 + DAT_00ca74bc * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar13;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar3 == 0) {
    uVar19 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar19;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_2c = FUN_005c71c0(param_4,4,1);
  if (local_2c == 0) {
    uVar13 = 1;
  }
  else {
    if (local_4c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar14 = local_54;
      if (local_50 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_50 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar14 = local_54 + 2;
    }
    piVar8 = (int *)*puVar14;
    if (piVar8 != (int *)0x0) {
      *piVar8 = *piVar8 + 1;
    }
    local_18 = piVar8;
    if (local_4c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar14 = local_54;
      if (local_50 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_50 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar14 = local_54 + 3;
    }
    piVar6 = (int *)*puVar14;
    if (piVar6 != (int *)0x0) {
      *piVar6 = *piVar6 + 1;
    }
    local_8._0_1_ = 4;
    local_1c = piVar6;
    local_24 = (int *)FUN_005da0f0();
    FUN_0040ba00();
    local_8 = CONCAT31(local_8._1_3_,5);
    local_20 = 0.0;
    if (0 < *extraout_EDX) {
      do {
        fVar17 = local_20;
        if (0x1ff < (uint)local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_006b9b20(&piStack_30,0,4);
        piVar8 = piStack_30;
        pbVar11 = &DAT_00721330;
        local_14 = (float)((uint)local_14 | 3);
        pbVar4 = (byte *)(piStack_30 + 3);
        do {
          bVar1 = *pbVar4;
          bVar15 = bVar1 < *pbVar11;
          if (bVar1 != *pbVar11) {
LAB_00674b70:
            uVar5 = -(uint)bVar15 | 1;
            goto LAB_00674b75;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar15 = bVar1 < pbVar11[1];
          if (bVar1 != pbVar11[1]) goto LAB_00674b70;
          pbVar4 = pbVar4 + 2;
          pbVar11 = pbVar11 + 2;
        } while (bVar1 != 0);
        uVar5 = 0;
LAB_00674b75:
        if (uVar5 == 0) {
          if ((uint)fVar17 < 0x200) {
            piVar6 = extraout_EDX + 1 + (int)fVar17;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar6 = extraout_EDX + 1;
          }
          pcVar12 = "exp_Kampf";
          pbVar4 = (byte *)(*piVar6 + 0xc);
          do {
            bVar1 = *pbVar4;
            bVar15 = bVar1 < (byte)*pcVar12;
            if (bVar1 != *pcVar12) {
LAB_00674bc3:
              uVar5 = -(uint)bVar15 | 1;
              goto LAB_00674bc8;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar4[1];
            bVar15 = bVar1 < ((byte *)pcVar12)[1];
            if (bVar1 != ((byte *)pcVar12)[1]) goto LAB_00674bc3;
            pbVar4 = pbVar4 + 2;
            pcVar12 = (char *)((byte *)pcVar12 + 2);
          } while (bVar1 != 0);
          uVar5 = 0;
LAB_00674bc8:
          if (uVar5 == 0) goto LAB_00674bd0;
          bVar15 = true;
        }
        else {
LAB_00674bd0:
          bVar15 = false;
        }
        local_14 = (float)((uint)local_14 & 0xfffffffe);
        local_8._0_1_ = 6;
        if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 == 0)) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,5);
        if (bVar15) {
          FUN_0040b930(1);
          if (local_44 <= local_44 - 1) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          *(float *)(local_48 + (local_44 - 1) * 4) = local_20;
        }
        local_20 = (float)((int)local_20 + 1);
        piVar6 = local_1c;
        piVar8 = local_18;
      } while ((int)local_20 < *local_24);
    }
    fVar16 = 0.0;
    local_14 = 0.0;
    fVar17 = fVar16;
    if (piVar6 != (int *)0x0) {
      iVar3 = Tcl_GetDoubleFromObj(0,piVar6,&local_34);
      if (iVar3 == 1) {
        local_20 = 0.0;
        fVar17 = local_20;
      }
      else {
        fVar16 = (float)(double)CONCAT44(piStack_30,local_34);
        fVar17 = fVar16;
      }
    }
    local_20 = fVar17;
    if (piVar8 == (int *)0x0) {
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar8,0);
    }
    local_28 = (int *)(local_2c + 0x21c);
    FUN_005daff0(ppuVar7);
    FUN_005dae40("atr_ExpMax");
    uVar18 = 0;
    piStack_30 = (int *)0x0;
    local_20 = fVar16;
    if (0 < (int)local_44) {
      uVar5 = 0;
      bVar15 = local_44 != 0;
      do {
        if (!bVar15) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        uVar2 = *(uint *)(local_48 + uVar5 * 4);
        if (*(int *)(local_2c + 0x21c) == 0) {
          if (uVar2 < 0x200) {
            iVar3 = FUN_005da0f0();
            fVar17 = *(float *)(iVar3 + 0x1804 + uVar2 * 4);
          }
          else {
LAB_00674d1f:
            fVar17 = 0.0;
          }
        }
        else {
          if (0x1ff < uVar2) goto LAB_00674d1f;
          fVar17 = *(float *)(*(int *)(local_2c + 0x21c) + uVar2 * 4);
        }
        piStack_30 = (int *)(fVar17 + (float)piStack_30);
        uVar18 = ZEXT48(piStack_30);
        uVar5 = uVar5 + 1;
        bVar15 = uVar5 < local_44;
        piVar6 = local_1c;
        piVar8 = local_18;
      } while ((int)uVar5 < (int)local_44);
    }
    piVar9 = local_28;
    fVar17 = (float)uVar18;
    if (((local_20 < fVar17) && (0.0 <= local_20)) && (0.0 < fVar17)) {
      local_20 = local_20 / fVar17;
      uVar5 = 0;
      if (0 < (int)local_44) {
        bVar15 = local_44 != 0;
        do {
          if (!bVar15) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          piStack_30 = *(int **)(local_48 + uVar5 * 4);
          if (*piVar9 == 0) {
            if (piStack_30 < (int *)0x200) {
              iVar3 = FUN_005da0f0();
              uVar18 = (ulonglong)*(uint *)(iVar3 + 0x1804 + (int)piStack_30 * 4);
              goto LAB_00674dcd;
            }
          }
          else {
            uVar18 = 0;
            if (piStack_30 < (int *)0x200) {
              uVar18 = (ulonglong)*(uint *)(*piVar9 + (int)piStack_30 * 4);
            }
LAB_00674dcd:
            if (0.0 < (float)uVar18) {
              piStack_30 = (int *)((float)uVar18 * local_20);
              if (local_44 <= uVar5) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              uVar18 = ZEXT48(piStack_30);
              FUN_005daeb0(*(undefined4 *)(local_48 + uVar5 * 4));
            }
          }
          uVar5 = uVar5 + 1;
          bVar15 = uVar5 < local_44;
          piVar6 = local_1c;
          piVar8 = local_18;
        } while ((int)uVar5 < (int)local_44);
      }
    }
    if (0 < *local_24) {
      piVar9 = local_24 + 1;
      iVar3 = 0;
      local_20 = 0.0;
      do {
        if (0x1ff < (uint)local_20) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_006b9b20(&piStack_30,0,6);
        pbVar11 = &DAT_00721338;
        pbVar4 = (byte *)(piStack_30 + 3);
        do {
          bVar1 = *pbVar4;
          bVar15 = bVar1 < *pbVar11;
          if (bVar1 != *pbVar11) {
LAB_00674e87:
            uVar5 = -(uint)bVar15 | 1;
            goto LAB_00674e8c;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar4[1];
          bVar15 = bVar1 < pbVar11[1];
          if (bVar1 != pbVar11[1]) goto LAB_00674e87;
          pbVar4 = pbVar4 + 2;
          pbVar11 = pbVar11 + 2;
        } while (bVar1 != 0);
        uVar5 = 0;
LAB_00674e8c:
        local_8._0_1_ = 7;
        if ((piStack_30 != (int *)0x0) && (*piStack_30 = *piStack_30 + -1, *piStack_30 == 0)) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,5);
        if (uVar5 == 0) {
          if ((uint)local_20 < 0x200) {
            piVar8 = (int *)((int)piVar9 + iVar3);
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar8 = piVar9;
          }
          FUN_005dae40(*piVar8 + 0xc);
          local_14 = local_14 + (float)uVar18;
        }
        iVar3 = iVar3 + 4;
        local_20 = (float)((int)local_20 + 1);
        piVar6 = local_1c;
        piVar8 = local_18;
      } while ((int)local_20 < *local_24);
    }
    FUN_005daf50("atr_Kampf");
    FUN_005daf50("exp_Kampf");
    if (piVar8 == (int *)0x0) {
      ppuVar7 = &PTR_0071ce50;
    }
    else {
      ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar8,0);
    }
    FUN_005dae40(ppuVar7);
    piVar9 = (int *)FUN_006bad90();
    if (local_64 != 0) {
      if (*piVar9 == 0) {
        Tcl_ResetResult(local_64);
      }
      else {
        Tcl_SetObjResult(local_64,*piVar9);
      }
    }
    if ((piStack_30 != (int *)0x0) && (*piStack_30 = *piStack_30 + -1, *piStack_30 < 1)) {
      TclFreeObj(piStack_30);
    }
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_0040b980(0);
    if (local_48 != 0) {
      FUN_006ba940();
    }
    if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
      TclFreeObj(piVar6);
    }
    if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
      TclFreeObj(piVar8);
    }
    uVar13 = 0;
  }
  local_8._0_1_ = 9;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,10);
  FUN_004297b0(0);
  if (local_54 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar13;
}

