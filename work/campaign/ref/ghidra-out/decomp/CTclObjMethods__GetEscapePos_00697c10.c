
undefined4 CTclObjMethods__GetEscapePos(undefined4 param_1,undefined4 param_2,float param_3)

{
  undefined4 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  uint uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  undefined1 *puVar15;
  float fVar16;
  undefined8 uVar17;
  undefined4 **ppuVar18;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  undefined1 *puStack_180;
  float fStack_17c;
  undefined1 *puStack_178;
  int local_108;
  int local_dc;
  int *local_d0;
  int local_cc;
  int local_90;
  int local_50;
  undefined4 *local_40;
  int local_3c;
  undefined4 local_38;
  undefined1 *puStack_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  undefined1 *local_20;
  undefined4 *local_1c;
  uint local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711c13;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7a68) &&
     (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00ca7a68 == -1)) {
    iVar4 = DAT_00783650 * 0x40;
    DAT_00ca7a6c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar4) = "TCL:CTclObjMethods::GetEscapePos()";
    *(int *)(&DAT_00773650 + iVar4) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar4 = DAT_00ca7a6c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7a6c * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar4 * 0x10];
  if (iVar3 == 0) {
    uVar17 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar4 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar4 * 0x10) = uVar17;
  }
  (&DAT_00773654)[iVar4 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0();
  local_8._0_1_ = 2;
  uVar2 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if ((int)param_3 < 4) {
    FUN_006bc8f0();
    local_8._0_1_ = 3;
    FUN_004297b0();
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  else {
    local_8._0_1_ = uVar2;
    iVar3 = FUN_005c71c0();
    if (iVar3 != 0) {
      if (local_14 < 3) {
        puStack_178 = (undefined1 *)0x697de5;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_1c;
        if (local_18 == 0) {
          puStack_178 = (undefined1 *)0x697df8;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar8 = local_1c;
        }
      }
      else {
        if (local_18 < 3) {
          puStack_178 = (undefined1 *)0x697e10;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar8 = local_1c + 2;
      }
      piVar5 = (int *)*puVar8;
      if (piVar5 == (int *)0x0) {
        local_30 = 0.0;
      }
      else {
        *piVar5 = *piVar5 + 1;
        iVar4 = Tcl_GetDoubleFromObj();
        local_30 = 0.0;
        if (iVar4 != 1) {
          local_30 = (float)(double)CONCAT44(puStack_34,local_38);
        }
        *piVar5 = *piVar5 + -1;
        if (*piVar5 < 1) {
          TclFreeObj();
        }
      }
      param_3 = 0.0;
      if (local_14 < 4) {
        puStack_178 = (undefined1 *)0x697e7c;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_1c;
        if (local_18 == 0) {
          puStack_178 = (undefined1 *)0x697e8f;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar8 = local_1c;
        }
      }
      else {
        if (local_18 < 4) {
          puStack_178 = (undefined1 *)0x697ea7;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar8 = local_1c + 3;
      }
      piVar5 = (int *)*puVar8;
      if (piVar5 == (int *)0x0) {
        local_2c = 0.0;
      }
      else {
        *piVar5 = *piVar5 + 1;
        iVar4 = Tcl_GetDoubleFromObj();
        if (iVar4 == 1) {
          local_2c = 0.0;
        }
        else {
          local_2c = (float)(double)CONCAT44(puStack_34,local_38);
        }
        *piVar5 = *piVar5 + -1;
        if (*piVar5 < 1) {
          TclFreeObj();
        }
      }
      local_24 = 0.0;
      local_28 = 0.0;
      local_20 = (undefined1 *)0x0;
      iVar4 = FUN_005ddd60();
      local_8._0_1_ = 7;
      uVar9 = *(uint *)(iVar4 + 0x14);
      *(undefined4 *)(iVar4 + 0x34) = 1;
      if (uVar9 == 0xffffffff) {
        uVar9 = 0;
      }
      *(uint *)(iVar4 + 0x14) = uVar9 | 2;
      fVar12 = *(float *)(iVar3 + 0x10);
      fVar14 = *(float *)(iVar3 + 0x14);
      *(float *)(iVar4 + 0x54) = *(float *)(iVar3 + 0xc) - local_30;
      *(float *)(iVar4 + 0x58) = fVar12 - local_30;
      *(float *)(iVar4 + 0x5c) = fVar14 - local_30;
      fVar12 = *(float *)(iVar3 + 0xc);
      fVar14 = *(float *)(iVar3 + 0x10);
      *(float *)(iVar4 + 0x68) = *(float *)(iVar3 + 0x14) + local_30;
      *(float *)(iVar4 + 0x60) = fVar12 + local_30;
      *(float *)(iVar4 + 100) = fVar14 + local_30;
      *(float *)(iVar4 + 8) = local_30 * local_30;
      FUN_005dde30();
      local_8 = CONCAT31(local_8._1_3_,10);
      FUN_0040b980();
      if (local_108 != 0) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0xb;
      FUN_006ba940();
      local_8 = CONCAT31(local_8._1_3_,9);
      thunk_FUN_0060fc30();
      if (local_dc == -2) {
        FUN_005e12a0();
        FUN_005e12a0();
      }
      if (local_cc == 0) {
        piVar5 = (int *)Tcl_NewIntObj();
        *piVar5 = *piVar5 + 1;
        iVar3 = *piVar5;
        if (local_50 != 0) {
          Tcl_SetObjResult();
          iVar3 = *piVar5;
        }
        *piVar5 = iVar3 + -1;
        if (iVar3 + -1 < 1) {
          TclFreeObj();
        }
        FUN_005ddfc0();
        local_8._0_1_ = 0xc;
        FUN_004297b0();
        local_8 = CONCAT31(local_8._1_3_,0xd);
      }
      else {
        while( true ) {
          if (local_dc == -2) {
            FUN_005e12a0();
          }
          local_dc = local_dc + 1;
          if (local_cc <= local_dc) break;
          if ((local_dc < 0) || (local_cc <= local_dc)) {
            puStack_178 = (undefined1 *)0x6980cc;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar5 = local_d0;
          }
          else {
            piVar5 = local_d0 + local_dc;
          }
          iVar4 = *piVar5;
          local_24 = (*(float *)(iVar3 + 0xc) - *(float *)(iVar4 + 0xc)) + local_24;
          local_28 = (*(float *)(iVar3 + 0x10) - *(float *)(iVar4 + 0x10)) + local_28;
          local_20 = (undefined1 *)
                     ((*(float *)(iVar3 + 0x14) - *(float *)(iVar4 + 0x14)) + (float)local_20);
          if ((local_dc < local_cc) && ((local_dc < 0 || (local_cc <= local_dc)))) {
            puStack_178 = (undefined1 *)0x69813d;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        fVar10 = local_24 * local_24 + local_28 * local_28 + (float)local_20 * (float)local_20;
        FUN_0040b7e0();
        fVar14 = param_3;
        fVar12 = param_3;
        if (0.0 < fVar10) {
          fVar14 = local_24 / fVar10;
          fVar12 = (float)local_20 / fVar10;
        }
        fVar12 = fVar12 * local_2c;
        local_3c = 0;
        fVar10 = *(float *)(iVar3 + 0x14);
        local_24 = fVar14 * local_2c + *(float *)(iVar3 + 0xc);
        fVar14 = *(float *)(iVar3 + 0x10);
        local_28 = (float)(int)fVar14;
        do {
          iVar4 = _rand();
          local_20 = (undefined1 *)((float)iVar4 * param_3 * 3.0517578e-05 + fVar10 + fVar12);
          iVar6 = _rand();
          iVar4 = DAT_0077241c;
          puStack_34 = (undefined1 *)((float)iVar6 * param_3 * 3.0517578e-05 + local_24);
          if (((((int)(float)puStack_34 * 8 < *(int *)(DAT_0077241c + 0x94) + 10) ||
               (*(int *)(DAT_0077241c + 0x9c) + -10 <= (int)(float)puStack_34 * 8)) ||
              ((int)local_28 * 8 < *(int *)(DAT_0077241c + 0x98) + 10)) ||
             (*(int *)(DAT_0077241c + 0xa0) + -10 <= (int)local_28 * 8)) break;
          piVar5 = (int *)FUN_00592f10();
          iVar4 = *(int *)(iVar4 + 0x24);
          iVar6 = *piVar5;
          if ((iVar6 < 0) || (*(int *)(iVar4 + 0x14) <= iVar6)) {
            puStack_178 = (undefined1 *)0x6982bf;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pbVar7 = *(byte **)(iVar4 + 0x10);
          }
          else {
            pbVar7 = (byte *)(iVar6 * 0x59 + *(int *)(iVar4 + 0x10));
          }
          puVar15 = local_20;
          if ((float)local_20 <= (float)*pbVar7 + 0.5) {
            puVar15 = (undefined1 *)((float)*pbVar7 + 0.5);
          }
          if (14.5 <= (float)puVar15) {
            puVar15 = (undefined1 *)0x41680000;
          }
          fVar13 = *(float *)(iVar3 + 0xc) - (float)puStack_34;
          fVar16 = *(float *)(iVar3 + 0x10) - fVar14;
          fVar11 = *(float *)(iVar3 + 0x14) - (float)puVar15;
          fVar11 = fVar16 * fVar16 + fVar13 * fVar13 + fVar11 * fVar11;
          if ((local_2c * 0.75 * local_2c * 0.75 < fVar11) &&
             (fVar11 < local_2c * 1.25 * local_2c * 1.25)) {
            puStack_180 = puStack_34;
            uStack_18c = *(undefined4 *)(iVar3 + 0xc);
            local_20 = (undefined1 *)&uStack_18c;
            uStack_188 = *(undefined4 *)(iVar3 + 0x10);
            uStack_184 = *(undefined4 *)(iVar3 + 0x14);
            ppuVar18 = &local_40;
            local_8._0_1_ = 0xf;
            fStack_17c = fVar14;
            puStack_178 = puVar15;
            puStack_34 = (undefined1 *)&puStack_180;
            FUN_0059a4b0(ppuVar18);
            local_8 = CONCAT31(local_8._1_3_,9);
            FUN_0059d440(ppuVar18);
            if (local_40 != (undefined4 *)0x0) {
              FUN_006badc0();
              FUN_006bc670();
              FUN_006bad60();
              if (local_40 != (undefined4 *)0x0) {
                LOCK();
                iVar3 = local_40[1] + -1;
                local_40[1] = iVar3;
                UNLOCK();
                if ((iVar3 == 0) && (local_40 != (undefined4 *)0x0)) {
                  (**(code **)*local_40)();
                }
              }
              FUN_005ddfc0();
              FUN_00429650();
              goto LAB_006984b3;
            }
          }
          iVar4 = local_3c + 1;
          param_3 = (float)(local_3c / 5) + local_2c * 0.2 + param_3;
          local_3c = iVar4;
        } while (iVar4 < 10);
        piVar5 = (int *)Tcl_NewIntObj();
        *piVar5 = *piVar5 + 1;
        iVar3 = *piVar5;
        if (local_50 != 0) {
          Tcl_SetObjResult();
          iVar3 = *piVar5;
        }
        *piVar5 = iVar3 + -1;
        if (iVar3 + -1 < 1) {
          TclFreeObj();
        }
        local_8 = CONCAT31(local_8._1_3_,0x10);
        FUN_0040b980();
        if (local_90 != 0) {
          FUN_006ba940();
        }
        local_8._0_1_ = 0x11;
        FUN_006ba940();
        thunk_FUN_0060fc30();
        local_8._0_1_ = 0x12;
        FUN_004297b0();
        local_8 = CONCAT31(local_8._1_3_,0x13);
      }
      FUN_004297b0();
      if (local_1c != (undefined4 *)0x0) {
        FUN_006ba940();
      }
LAB_006984b3:
      FUN_006bc0d0();
      FUN_0043fd30();
      ExceptionList = local_10;
      return 0;
    }
    if (local_14 < 2) {
      puStack_178 = (undefined1 *)0x697d69;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar8 = local_1c;
      if (local_18 == 0) {
        puStack_178 = (undefined1 *)0x697d79;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar8 = local_1c;
      }
    }
    else {
      if (local_18 < 2) {
        puStack_178 = (undefined1 *)0x697d95;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar8 = local_1c + 1;
    }
    piVar5 = (int *)*puVar8;
    if (piVar5 != (int *)0x0) {
      *piVar5 = *piVar5 + 1;
    }
    FUN_006bc6a0();
    local_8._0_1_ = 5;
    FUN_004297b0();
    local_8 = CONCAT31(local_8._1_3_,6);
  }
  FUN_004297b0();
  if (local_1c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

