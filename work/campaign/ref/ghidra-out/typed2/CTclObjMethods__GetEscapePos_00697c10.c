
undefined4 CTclObjMethods__GetEscapePos(undefined4 param_1,undefined4 param_2,float param_3)

{
  undefined4 uVar1;
  CHeightBlockArray *pCVar2;
  CMap *pCVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  CHeightBlock *pCVar8;
  undefined4 *puVar9;
  uint uVar10;
  float fVar11;
  undefined1 *puVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  undefined1 *puVar17;
  float fVar18;
  undefined8 uVar19;
  undefined4 **ppuVar20;
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
     (FUN_006cebf4(), iVar5 = DAT_00783650, DAT_00ca7a68 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca7a6c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclObjMethods::GetEscapePos()";
    *(int *)(&DAT_00773650 + iVar6) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar6 = DAT_00ca7a6c;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7a6c * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar1;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar5 == 0) {
    uVar19 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar19;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0();
  local_8._0_1_ = 2;
  uVar4 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if ((int)param_3 < 4) {
    FUN_006bc8f0();
    local_8._0_1_ = 3;
    FUN_004297b0();
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  else {
    local_8._0_1_ = uVar4;
    iVar5 = FUN_005c71c0();
    if (iVar5 != 0) {
      if (local_14 < 3) {
        puStack_178 = (undefined1 *)0x697de5;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar9 = local_1c;
        if (local_18 == 0) {
          puStack_178 = (undefined1 *)0x697df8;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar9 = local_1c;
        }
      }
      else {
        if (local_18 < 3) {
          puStack_178 = (undefined1 *)0x697e10;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar9 = local_1c + 2;
      }
      piVar7 = (int *)*puVar9;
      if (piVar7 == (int *)0x0) {
        local_30 = 0.0;
      }
      else {
        *piVar7 = *piVar7 + 1;
        iVar6 = Tcl_GetDoubleFromObj();
        local_30 = 0.0;
        if (iVar6 != 1) {
          local_30 = (float)(double)CONCAT44(puStack_34,local_38);
        }
        *piVar7 = *piVar7 + -1;
        if (*piVar7 < 1) {
          TclFreeObj();
        }
      }
      param_3 = 0.0;
      if (local_14 < 4) {
        puStack_178 = (undefined1 *)0x697e7c;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar9 = local_1c;
        if (local_18 == 0) {
          puStack_178 = (undefined1 *)0x697e8f;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar9 = local_1c;
        }
      }
      else {
        if (local_18 < 4) {
          puStack_178 = (undefined1 *)0x697ea7;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar9 = local_1c + 3;
      }
      piVar7 = (int *)*puVar9;
      if (piVar7 == (int *)0x0) {
        local_2c = 0.0;
      }
      else {
        *piVar7 = *piVar7 + 1;
        iVar6 = Tcl_GetDoubleFromObj();
        if (iVar6 == 1) {
          local_2c = 0.0;
        }
        else {
          local_2c = (float)(double)CONCAT44(puStack_34,local_38);
        }
        *piVar7 = *piVar7 + -1;
        if (*piVar7 < 1) {
          TclFreeObj();
        }
      }
      local_24 = 0.0;
      local_28 = 0.0;
      local_20 = (undefined1 *)0x0;
      iVar6 = FUN_005ddd60();
      local_8._0_1_ = 7;
      uVar10 = *(uint *)(iVar6 + 0x14);
      *(undefined4 *)(iVar6 + 0x34) = 1;
      if (uVar10 == 0xffffffff) {
        uVar10 = 0;
      }
      *(uint *)(iVar6 + 0x14) = uVar10 | 2;
      fVar14 = *(float *)(iVar5 + 0x10);
      fVar16 = *(float *)(iVar5 + 0x14);
      *(float *)(iVar6 + 0x54) = *(float *)(iVar5 + 0xc) - local_30;
      *(float *)(iVar6 + 0x58) = fVar14 - local_30;
      *(float *)(iVar6 + 0x5c) = fVar16 - local_30;
      fVar14 = *(float *)(iVar5 + 0xc);
      fVar16 = *(float *)(iVar5 + 0x10);
      *(float *)(iVar6 + 0x68) = *(float *)(iVar5 + 0x14) + local_30;
      *(float *)(iVar6 + 0x60) = fVar14 + local_30;
      *(float *)(iVar6 + 100) = fVar16 + local_30;
      *(float *)(iVar6 + 8) = local_30 * local_30;
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
        piVar7 = (int *)Tcl_NewIntObj();
        *piVar7 = *piVar7 + 1;
        iVar5 = *piVar7;
        if (local_50 != 0) {
          Tcl_SetObjResult();
          iVar5 = *piVar7;
        }
        *piVar7 = iVar5 + -1;
        if (iVar5 + -1 < 1) {
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
            piVar7 = local_d0;
          }
          else {
            piVar7 = local_d0 + local_dc;
          }
          iVar6 = *piVar7;
          local_24 = (*(float *)(iVar5 + 0xc) - *(float *)(iVar6 + 0xc)) + local_24;
          local_28 = (*(float *)(iVar5 + 0x10) - *(float *)(iVar6 + 0x10)) + local_28;
          local_20 = (undefined1 *)
                     ((*(float *)(iVar5 + 0x14) - *(float *)(iVar6 + 0x14)) + (float)local_20);
          if ((local_dc < local_cc) && ((local_dc < 0 || (local_cc <= local_dc)))) {
            puStack_178 = (undefined1 *)0x69813d;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
        }
        fVar11 = local_24 * local_24 + local_28 * local_28 + (float)local_20 * (float)local_20;
        FUN_0040b7e0();
        fVar16 = param_3;
        fVar14 = param_3;
        if (0.0 < fVar11) {
          fVar16 = local_24 / fVar11;
          fVar14 = (float)local_20 / fVar11;
        }
        fVar14 = fVar14 * local_2c;
        local_3c = 0;
        fVar11 = *(float *)(iVar5 + 0x14);
        local_24 = fVar16 * local_2c + *(float *)(iVar5 + 0xc);
        fVar16 = *(float *)(iVar5 + 0x10);
        local_28 = (float)(int)fVar16;
        do {
          iVar6 = _rand();
          local_20 = (undefined1 *)((float)iVar6 * param_3 * 3.0517578e-05 + fVar11 + fVar14);
          iVar6 = _rand();
          pCVar3 = PTR_0077241c;
          puStack_34 = (undefined1 *)((float)iVar6 * param_3 * 3.0517578e-05 + local_24);
          if (((((int)(float)puStack_34 * 8 < PTR_0077241c->x0_8 + 10) ||
               (PTR_0077241c->x1_8 + -10 <= (int)(float)puStack_34 * 8)) ||
              ((int)local_28 * 8 < PTR_0077241c->y0_8 + 10)) ||
             (PTR_0077241c->y1_8 + -10 <= (int)local_28 * 8)) break;
          piVar7 = (int *)FUN_00592f10(PTR_0077241c);
          pCVar2 = pCVar3->heightBlocks;
          iVar6 = *piVar7;
          if ((iVar6 < 0) || (pCVar2->count <= iVar6)) {
            puStack_178 = (undefined1 *)0x6982bf;
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            pCVar8 = pCVar2->data;
          }
          else {
            pCVar8 = pCVar2->data + iVar6;
          }
          puVar12 = (undefined1 *)((float)pCVar8->heights[0] + 0.5);
          puVar17 = local_20;
          if ((float)local_20 <= (float)puVar12) {
            puVar17 = puVar12;
          }
          if (14.5 <= (float)puVar17) {
            puVar17 = (undefined1 *)0x41680000;
          }
          fVar15 = *(float *)(iVar5 + 0xc) - (float)puStack_34;
          fVar18 = *(float *)(iVar5 + 0x10) - fVar16;
          fVar13 = *(float *)(iVar5 + 0x14) - (float)puVar17;
          fVar13 = fVar18 * fVar18 + fVar15 * fVar15 + fVar13 * fVar13;
          if ((local_2c * 0.75 * local_2c * 0.75 < fVar13) &&
             (fVar13 < local_2c * 1.25 * local_2c * 1.25)) {
            puStack_180 = puStack_34;
            uStack_18c = *(undefined4 *)(iVar5 + 0xc);
            local_20 = (undefined1 *)&uStack_18c;
            uStack_188 = *(undefined4 *)(iVar5 + 0x10);
            uStack_184 = *(undefined4 *)(iVar5 + 0x14);
            ppuVar20 = &local_40;
            local_8._0_1_ = 0xf;
            fStack_17c = fVar16;
            puStack_178 = puVar17;
            puStack_34 = (undefined1 *)&puStack_180;
            FUN_0059a4b0(ppuVar20);
            local_8 = CONCAT31(local_8._1_3_,9);
            FUN_0059d440(ppuVar20);
            if (local_40 != (undefined4 *)0x0) {
              FUN_006badc0();
              FUN_006bc670();
              FUN_006bad60();
              if (local_40 != (undefined4 *)0x0) {
                LOCK();
                iVar5 = local_40[1] + -1;
                local_40[1] = iVar5;
                UNLOCK();
                if ((iVar5 == 0) && (local_40 != (undefined4 *)0x0)) {
                  (**(code **)*local_40)();
                }
              }
              FUN_005ddfc0();
              FUN_00429650();
              goto LAB_006984b3;
            }
          }
          iVar6 = local_3c + 1;
          param_3 = (float)(local_3c / 5) + local_2c * 0.2 + param_3;
          local_3c = iVar6;
        } while (iVar6 < 10);
        piVar7 = (int *)Tcl_NewIntObj();
        *piVar7 = *piVar7 + 1;
        iVar5 = *piVar7;
        if (local_50 != 0) {
          Tcl_SetObjResult();
          iVar5 = *piVar7;
        }
        *piVar7 = iVar5 + -1;
        if (iVar5 + -1 < 1) {
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
      puVar9 = local_1c;
      if (local_18 == 0) {
        puStack_178 = (undefined1 *)0x697d79;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar9 = local_1c;
      }
    }
    else {
      if (local_18 < 2) {
        puStack_178 = (undefined1 *)0x697d95;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar9 = local_1c + 1;
    }
    piVar7 = (int *)*puVar9;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
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

