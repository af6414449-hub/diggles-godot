
void CTclGlobalMethods__GroundPos(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  CHeightBlockArray *pCVar3;
  CMap *pCVar4;
  undefined1 uVar5;
  int iVar6;
  int *piVar7;
  int **ppiVar8;
  float *pfVar9;
  int iVar10;
  byte bVar11;
  CHeightBlock *pCVar12;
  int *piVar13;
  undefined4 *puVar14;
  uint uVar15;
  code *pcVar16;
  bool bVar17;
  float fVar18;
  undefined8 uVar19;
  undefined4 **ppuVar20;
  float local_e8;
  float local_e4;
  int local_a4;
  undefined4 *local_90;
  float local_8c;
  int *local_88;
  uint local_84;
  undefined4 *local_80;
  uint local_7c;
  int local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float *local_64;
  int local_60;
  int *local_5c;
  byte local_56;
  byte local_55;
  int *local_54;
  int **local_50;
  int *local_4c;
  int *local_48;
  float local_44 [9];
  int *local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d196;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6f10) &&
     (FUN_006cebf4(), iVar6 = DAT_00783650, DAT_00ca6f10 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca6f14 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CTclGlobalMethods::GroundPos()";
    *(int *)(&DAT_00773650 + iVar10) = iVar6;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar10 = DAT_00ca6f14;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6f14 * 0x40);
  iVar6 = FUN_0043fcc0();
  *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar1;
  *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
  iVar6 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar6 == 0) {
    uVar19 = FUN_006bd180();
    iVar6 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar19;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar6 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0();
  local_8._0_1_ = 2;
  uVar5 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (param_3 < 2) {
    FUN_006bc8f0();
    local_8._0_1_ = 3;
    FUN_004297b0();
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_004297b0();
    if (local_80 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
    FUN_006bc0d0();
    FUN_0043fd30();
    goto LAB_006363c8;
  }
  local_8._0_1_ = uVar5;
  if (local_78 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar14 = local_80;
    if (local_7c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar14 = local_80;
    }
  }
  else {
    if (local_7c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar14 = local_80 + 1;
  }
  piVar2 = (int *)*puVar14;
  if (piVar2 != (int *)0x0) {
    *piVar2 = *piVar2 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,5);
  local_88 = piVar2;
  FUN_006bafe0();
  _eh_vector_constructor_iterator_(local_44,0xc,3,FUN_00405b50,guard_check_icall);
  local_48 = (int *)(local_74 * 8.0);
  DAT_00772dd8 = (int *)(int)ROUND((float)local_48);
  local_20 = DAT_00772dd8;
  local_54 = (int *)0xffffffff;
  local_1c = (int)DAT_00772dd8 + 10;
  local_18 = (int)DAT_00772dd8 + -10;
  local_60 = 100000;
  if ((((local_74 <= (float)(PTR_0077241c->cellX0 + 10)) ||
       (local_70 <= (float)PTR_0077241c->cellY0)) ||
      ((float)(PTR_0077241c->cellX1 + -0xb) <= local_74)) ||
     ((float)(PTR_0077241c->cellY1 + -0x19) <= local_70)) {
LAB_006362ef:
    local_74 = 0.0;
    local_70 = 0.0;
    local_6c = 0.0;
    piVar13 = (int *)FUN_006badc0();
    if (local_a4 != 0) {
      if (*piVar13 == 0) {
        Tcl_ResetResult();
      }
      else {
        Tcl_SetObjResult();
      }
    }
    pcVar16 = TclFreeObj_exref;
    if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 < 1)) {
      TclFreeObj();
      pcVar16 = TclFreeObj_exref;
    }
  }
  else {
    local_64 = local_44;
    local_50 = &local_20;
    local_5c = (int *)0x0;
    local_8c = local_70 * 8.0;
    do {
      piVar13 = (int *)(int)ROUND(local_8c);
      local_4c = piVar13;
      local_48 = piVar13 + 0x32;
      bVar17 = piVar13 == local_48;
      DAT_00772dd8 = piVar13;
      if ((int)piVar13 < (int)local_48) {
        do {
          ppiVar8 = local_50;
          if ((int *)0x2 < local_5c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            ppiVar8 = &local_20;
          }
          local_84 = ((uint)piVar13 & 7) << 3;
          uVar15 = (uint)*ppiVar8 & 7 | local_84;
          local_68 = (float)((int)piVar13 >> 3);
          iVar6 = FUN_00592f10(PTR_0077241c);
          local_56 = *(byte *)(uVar15 + 0x3c + iVar6);
          ppiVar8 = local_50;
          if ((int *)0x2 < local_5c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            ppiVar8 = &local_20;
          }
          uVar15 = (int)*ppiVar8 + 1U & 7 | local_84;
          iVar6 = FUN_00592f10(PTR_0077241c);
          local_55 = *(byte *)(uVar15 + 0x3c + iVar6);
          ppiVar8 = local_50;
          if ((int *)0x2 < local_5c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            ppiVar8 = &local_20;
          }
          uVar15 = (int)*ppiVar8 - 1U & 7 | local_84;
          iVar6 = FUN_00592f10(PTR_0077241c);
          bVar11 = ~((*(byte *)(uVar15 + 0x3c + iVar6) & local_55 & local_56) >> 1) & 1;
          if ((int)piVar13 < PTR_0077241c->cellY1 * 8) {
            bVar11 = 1;
          }
        } while ((bVar11 != 0) &&
                (piVar13 = (int *)((int)piVar13 + 1), (int)piVar13 < (int)local_48));
        bVar17 = piVar13 == local_48;
      }
      piVar7 = local_5c;
      if ((!bVar17) && (piVar13 != local_4c)) {
        ppiVar8 = local_50;
        if ((int *)0x2 < local_5c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          ppiVar8 = &local_20;
        }
        pCVar4 = PTR_0077241c;
        local_4c = *ppiVar8;
        piVar7 = (int *)FUN_00592f10(PTR_0077241c);
        pCVar3 = pCVar4->heightBlocks;
        iVar6 = *piVar7;
        if ((iVar6 < 0) || (pCVar3->count <= iVar6)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pCVar12 = pCVar3->data;
        }
        else {
          pCVar12 = pCVar3->data + iVar6;
        }
        piVar7 = local_5c;
        if ((float)pCVar12->heights[((uint)piVar13 & 7) << 3 | (uint)local_4c & 7] <= local_6c) {
          local_48 = (int *)local_6c;
        }
        else {
          local_48 = (int *)(float)pCVar12->heights[((uint)piVar13 & 7) << 3 | (uint)local_4c & 7];
        }
        DAT_00772dd8 = (int *)(int)ROUND((float)local_48);
        local_4c = DAT_00772dd8;
        ppiVar8 = local_50;
        if ((int *)0x2 < local_5c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          ppiVar8 = &local_20;
        }
        local_48 = (int *)((float)(int)*ppiVar8 * 0.125);
        local_68 = (float)(int)piVar13 * 0.125;
        local_4c = (int *)(float)(int)local_4c;
        pfVar9 = local_64;
        if ((int *)0x2 < piVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = local_44;
        }
        *pfVar9 = (float)local_48;
        pfVar9[1] = local_68;
        pfVar9[2] = (float)local_4c;
        pfVar9 = local_64;
        if ((int *)0x2 < piVar7) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar9 = local_44;
        }
        fVar18 = (pfVar9[1] - local_70) * (pfVar9[1] - local_70) +
                 (*pfVar9 - local_74) * (*pfVar9 - local_74);
        FUN_0040b7e0();
        local_4c = (int *)((float)((int)fVar18 * (int)fVar18) * 1.3);
        DAT_00772dd8 = (int *)(int)ROUND((float)local_4c);
        if ((int *)0x2 < piVar7) {
          local_e4 = 9.126756e-39;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_4c = (int *)&stack0xffffff24;
        local_48 = (int *)&local_e8;
        local_e8 = local_74;
        local_e4 = local_70;
        ppuVar20 = &local_90;
        local_8._0_1_ = 8;
        FUN_0059a4b0(ppuVar20);
        local_8 = CONCAT31(local_8._1_3_,6);
        FUN_0059d440(ppuVar20);
        if (local_90 != (undefined4 *)0x0) {
          iVar6 = local_90[8];
          piVar13 = piVar7;
          if (local_60 <= (int)local_90[8]) {
            iVar6 = local_60;
            piVar13 = local_54;
          }
          local_54 = piVar13;
          local_60 = iVar6;
          LOCK();
          iVar10 = local_90[1] + -1;
          local_90[1] = iVar10;
          UNLOCK();
          local_4c = local_54;
          if (iVar10 == 0) {
            local_60 = iVar6;
            if (local_90 != (undefined4 *)0x0) {
              (**(code **)*local_90)();
              local_60 = iVar6;
              local_54 = local_4c;
            }
          }
        }
      }
      local_64 = local_64 + 3;
      local_50 = local_50 + 1;
      local_5c = (int *)((int)piVar7 + 1);
    } while ((int)piVar7 + 1 < 3);
    if ((int)local_54 < 0) goto LAB_006362ef;
    if (2 < (int)local_54) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar13 = (int *)FUN_006badc0();
    if (local_a4 != 0) {
      if (*piVar13 == 0) {
        Tcl_ResetResult();
      }
      else {
        Tcl_SetObjResult();
      }
    }
    pcVar16 = TclFreeObj_exref;
    if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 < 1)) {
      TclFreeObj();
    }
  }
  local_8 = CONCAT31(local_8._1_3_,9);
  _eh_vector_destructor_iterator_(local_44,0xc,3,guard_check_icall);
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    (*pcVar16)();
  }
  local_8._0_1_ = 10;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_004297b0();
  if (local_80 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
LAB_006363c8:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

