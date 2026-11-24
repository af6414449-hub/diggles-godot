
undefined4
CTclGlobalMethods__GetExpAttrib
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  uint uVar2;
  undefined3 uVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  code *pcVar11;
  uint uVar12;
  int *piVar13;
  int *piVar14;
  bool bVar15;
  undefined8 uVar16;
  int local_58;
  undefined4 *local_48;
  uint local_44;
  int local_40;
  int local_3c;
  uint local_38;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  uint local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070dc2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_24 = (int *)0x0;
  local_14 = (int *)0x0;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca70c0) &&
     (FUN_006cebf4(&DAT_00ca70c0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca70c0 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca70c4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::GetExpAttrib()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca70c0);
  }
  iVar7 = DAT_00ca70c4;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca70c4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar9;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar16 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar16;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar5 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if (2 < (int)piVar5) {
    FUN_006bc8f0(1);
    uVar9 = 1;
    goto LAB_00645356;
  }
  local_1c = 2;
  piVar13 = (int *)0x0;
  if (1 < (int)piVar5) {
    local_1c = 0;
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_48 + 1;
    }
    piVar5 = (int *)*puVar10;
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
      iVar4 = Tcl_GetBooleanFromObj(0,piVar5,&param_3);
      bVar15 = param_3 != (int *)0x0;
      *piVar5 = *piVar5 + -1;
      if (*piVar5 < 1) {
        TclFreeObj(piVar5);
      }
      local_1c = (uint)(iVar4 != 1 && bVar15);
      piVar13 = local_14;
    }
  }
  pcVar11 = RaiseException_exref;
  piVar5 = (int *)FUN_005da0f0();
  local_18 = piVar5;
  FUN_0040ba00();
  local_8 = CONCAT31(local_8._1_3_,3);
  param_3 = (int *)0x0;
  piVar14 = local_20;
  if (0 < *piVar5) {
    do {
      if (local_1c == 0) {
        if ((int *)0x1ff < param_3) {
          (*pcVar11)(0xc000008c,1,0,0);
        }
        FUN_006b9b20(&local_30,0,4);
        piVar5 = local_30;
        local_8 = CONCAT31(local_8._1_3_,4);
        local_24 = (int *)((uint)local_14 | 5);
        pbVar8 = &DAT_00721330;
        pbVar6 = (byte *)(local_30 + 3);
        do {
          bVar1 = *pbVar6;
          bVar15 = bVar1 < *pbVar8;
          if (bVar1 != *pbVar8) {
LAB_00645186:
            uVar12 = -(uint)bVar15 | 1;
            goto LAB_0064518b;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar6[1];
          bVar15 = bVar1 < pbVar8[1];
          if (bVar1 != pbVar8[1]) goto LAB_00645186;
          pbVar6 = pbVar6 + 2;
          pbVar8 = pbVar8 + 2;
        } while (bVar1 != 0);
        uVar12 = 0;
LAB_0064518b:
        local_14 = local_24;
        if (uVar12 == 0) {
          if ((int *)0x1ff < param_3) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          FUN_006b9b20(&local_20,0,6);
          pbVar8 = &DAT_00721338;
          local_14 = (int *)((uint)local_14 | 10);
          pbVar6 = (byte *)(local_20 + 3);
          do {
            bVar1 = *pbVar6;
            bVar15 = bVar1 < *pbVar8;
            if (bVar1 != *pbVar8) {
LAB_006451f0:
              uVar12 = -(uint)bVar15 | 1;
              goto LAB_006451f5;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar6[1];
            bVar15 = bVar1 < pbVar8[1];
            if (bVar1 != pbVar8[1]) goto LAB_006451f0;
            pbVar6 = pbVar6 + 2;
            pbVar8 = pbVar8 + 2;
          } while (bVar1 != 0);
          uVar12 = 0;
LAB_006451f5:
          piVar14 = local_20;
          if (uVar12 == 0) goto LAB_006451fd;
          bVar15 = true;
        }
        else {
LAB_006451fd:
          bVar15 = false;
        }
        if (((uint)local_14 & 2) != 0) {
          local_24 = (int *)((uint)local_14 & 0xfffffffd);
          local_8 = 5;
          local_14 = local_24;
          if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 == 0)) {
            FUN_006ba940();
          }
        }
        local_8 = 3;
        if (((uint)local_14 & 1) != 0) {
          local_14 = (int *)((uint)local_14 & 0xfffffffe);
          local_8._1_3_ = 0;
          uVar3 = local_8._1_3_;
          local_8._0_1_ = 6;
          local_8._1_3_ = 0;
          if ((piVar5 != (int *)0x0) &&
             (*piVar5 = *piVar5 + -1, uVar3 = local_8._1_3_, *piVar5 == 0)) {
            FUN_006ba940();
            uVar3 = local_8._1_3_;
          }
          local_8._1_3_ = uVar3;
          local_8 = CONCAT31(local_8._1_3_,3);
        }
        piVar5 = local_18;
        if (bVar15) {
LAB_00645038:
          uVar12 = FUN_0040b580();
          if (local_38 <= uVar12) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          goto LAB_00645058;
        }
      }
      else if (local_1c == 1) {
        if ((int *)0x1ff < param_3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_006b9b20(&local_2c,0,6);
        local_14 = (int *)((uint)piVar13 | 0x10);
        pbVar8 = &DAT_00721338;
        pbVar6 = (byte *)(local_2c + 3);
        do {
          bVar1 = *pbVar6;
          bVar15 = bVar1 < *pbVar8;
          if (bVar1 != *pbVar8) {
LAB_006450c7:
            uVar12 = -(uint)bVar15 | 1;
            goto LAB_006450cc;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar6[1];
          bVar15 = bVar1 < pbVar8[1];
          if (bVar1 != pbVar8[1]) goto LAB_006450c7;
          pbVar6 = pbVar6 + 2;
          pbVar8 = pbVar8 + 2;
        } while (bVar1 != 0);
        uVar12 = 0;
LAB_006450cc:
        local_8._0_1_ = 7;
        if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        piVar5 = local_18;
        if (uVar12 != 0) goto LAB_00645260;
        uVar12 = FUN_0040b580();
        if (local_38 <= uVar12) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          *(int **)(local_3c + uVar12 * 4) = param_3;
          piVar5 = local_18;
          goto LAB_00645260;
        }
LAB_00645058:
        *(int **)(local_3c + uVar12 * 4) = param_3;
        piVar5 = local_18;
      }
      else if (local_1c == 2) {
        if ((int *)0x1ff < param_3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        FUN_006b9b20(&local_28,0,4);
        local_14 = (int *)((uint)piVar13 | 0x20);
        pbVar8 = &DAT_00721330;
        pbVar6 = (byte *)(local_28 + 3);
        do {
          bVar1 = *pbVar6;
          bVar15 = bVar1 < *pbVar8;
          if (bVar1 != *pbVar8) {
LAB_00645015:
            uVar12 = -(uint)bVar15 | 1;
            goto LAB_0064501a;
          }
          if (bVar1 == 0) break;
          bVar1 = pbVar6[1];
          bVar15 = bVar1 < pbVar8[1];
          if (bVar1 != pbVar8[1]) goto LAB_00645015;
          pbVar6 = pbVar6 + 2;
          pbVar8 = pbVar8 + 2;
        } while (bVar1 != 0);
        uVar12 = 0;
LAB_0064501a:
        local_8._0_1_ = 8;
        if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
          FUN_006ba940();
        }
        local_8 = CONCAT31(local_8._1_3_,3);
        piVar5 = local_18;
        if (uVar12 != 0) goto LAB_00645260;
        goto LAB_00645038;
      }
LAB_00645260:
      param_3 = (int *)((int)param_3 + 1);
      piVar13 = local_14;
      pcVar11 = RaiseException_exref;
    } while ((int)param_3 < *piVar5);
  }
  uVar12 = 0;
  local_24 = (int *)0x0;
  if (0 < (int)local_38) {
    do {
      if (local_38 <= uVar12) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar2 = *(uint *)(local_3c + uVar12 * 4);
      if (uVar2 < 0x200) {
        piVar13 = piVar5 + 1 + uVar2;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar13 = piVar5 + 1;
      }
      if (*piVar13 + 0xc == 0) {
        piVar13 = (int *)0x0;
      }
      else {
        piVar13 = (int *)Tcl_NewStringObj(*piVar13 + 0xc,0xffffffff);
        *piVar13 = *piVar13 + 1;
      }
      param_3 = piVar13;
      FUN_006bb930(&param_3);
      if ((piVar13 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 < 1)) {
        TclFreeObj(piVar13);
      }
      uVar12 = uVar12 + 1;
    } while ((int)uVar12 < (int)local_38);
  }
  piVar5 = local_24;
  if (local_58 == 0) {
LAB_00645325:
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
      TclFreeObj(piVar5);
    }
  }
  else {
    if (local_24 != (int *)0x0) {
      Tcl_SetObjResult(local_58,local_24);
      goto LAB_00645325;
    }
    Tcl_ResetResult(local_58);
  }
  local_8._0_1_ = 9;
  FUN_0040b980(0);
  uVar9 = 0;
  if (local_3c != 0) {
    FUN_006ba940();
  }
LAB_00645356:
  local_8._0_1_ = 10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_004297b0(0);
  if (local_48 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

