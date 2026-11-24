
void CTclGlobalMethods__GroundPos(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  int **ppiVar6;
  float *pfVar7;
  int iVar8;
  byte bVar9;
  int *piVar10;
  undefined4 *puVar11;
  uint uVar12;
  code *pcVar13;
  bool bVar14;
  float fVar15;
  undefined8 uVar16;
  undefined4 **ppuVar17;
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
     (FUN_006cebf4(), iVar4 = DAT_00783650, DAT_00ca6f10 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca6f14 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::GroundPos()";
    *(int *)(&DAT_00773650 + iVar8) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar8 = DAT_00ca6f14;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6f14 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar1;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar4 == 0) {
    uVar16 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar16;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170();
  local_8._0_1_ = 1;
  FUN_004298b0();
  local_8._0_1_ = 2;
  uVar3 = (undefined1)local_8;
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
  local_8._0_1_ = uVar3;
  if (local_78 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar11 = local_80;
    if (local_7c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar11 = local_80;
    }
  }
  else {
    if (local_7c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar11 = local_80 + 1;
  }
  piVar2 = (int *)*puVar11;
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
  if ((((local_74 <= (float)(*(int *)(DAT_0077241c + 0x84) + 10)) ||
       (local_70 <= (float)*(int *)(DAT_0077241c + 0x88))) ||
      ((float)(*(int *)(DAT_0077241c + 0x8c) + -0xb) <= local_74)) ||
     ((float)(*(int *)(DAT_0077241c + 0x90) + -0x19) <= local_70)) {
LAB_006362ef:
    local_74 = 0.0;
    local_70 = 0.0;
    local_6c = 0.0;
    piVar10 = (int *)FUN_006badc0();
    if (local_a4 != 0) {
      if (*piVar10 == 0) {
        Tcl_ResetResult();
      }
      else {
        Tcl_SetObjResult();
      }
    }
    pcVar13 = TclFreeObj_exref;
    if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 < 1)) {
      TclFreeObj();
      pcVar13 = TclFreeObj_exref;
    }
  }
  else {
    local_64 = local_44;
    local_50 = &local_20;
    local_5c = (int *)0x0;
    local_8c = local_70 * 8.0;
    do {
      piVar10 = (int *)(int)ROUND(local_8c);
      local_4c = piVar10;
      local_48 = piVar10 + 0x32;
      bVar14 = piVar10 == local_48;
      DAT_00772dd8 = piVar10;
      if ((int)piVar10 < (int)local_48) {
        do {
          ppiVar6 = local_50;
          if ((int *)0x2 < local_5c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            ppiVar6 = &local_20;
          }
          local_84 = ((uint)piVar10 & 7) << 3;
          uVar12 = (uint)*ppiVar6 & 7 | local_84;
          local_68 = (float)((int)piVar10 >> 3);
          iVar4 = FUN_00592f10();
          local_56 = *(byte *)(uVar12 + 0x3c + iVar4);
          ppiVar6 = local_50;
          if ((int *)0x2 < local_5c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            ppiVar6 = &local_20;
          }
          uVar12 = (int)*ppiVar6 + 1U & 7 | local_84;
          iVar4 = FUN_00592f10();
          local_55 = *(byte *)(uVar12 + 0x3c + iVar4);
          ppiVar6 = local_50;
          if ((int *)0x2 < local_5c) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            ppiVar6 = &local_20;
          }
          uVar12 = (int)*ppiVar6 - 1U & 7 | local_84;
          iVar4 = FUN_00592f10();
          bVar9 = ~((*(byte *)(uVar12 + 0x3c + iVar4) & local_55 & local_56) >> 1) & 1;
          if ((int)piVar10 < *(int *)(DAT_0077241c + 0x90) * 8) {
            bVar9 = 1;
          }
        } while ((bVar9 != 0) && (piVar10 = (int *)((int)piVar10 + 1), (int)piVar10 < (int)local_48)
                );
        bVar14 = piVar10 == local_48;
      }
      piVar5 = local_5c;
      if ((!bVar14) && (piVar10 != local_4c)) {
        ppiVar6 = local_50;
        if ((int *)0x2 < local_5c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          ppiVar6 = &local_20;
        }
        iVar4 = DAT_0077241c;
        local_4c = *ppiVar6;
        piVar5 = (int *)FUN_00592f10();
        iVar4 = *(int *)(iVar4 + 0x24);
        iVar8 = *piVar5;
        if ((iVar8 < 0) || (*(int *)(iVar4 + 0x14) <= iVar8)) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar4 = *(int *)(iVar4 + 0x10);
        }
        else {
          iVar4 = iVar8 * 0x59 + *(int *)(iVar4 + 0x10);
        }
        piVar5 = local_5c;
        local_48 = (int *)(float)*(byte *)((((uint)piVar10 & 7) << 3 | (uint)local_4c & 7) + iVar4);
        if ((float)local_48 <= local_6c) {
          local_48 = (int *)local_6c;
        }
        else {
        }
        DAT_00772dd8 = (int *)(int)ROUND((float)local_48);
        local_4c = DAT_00772dd8;
        ppiVar6 = local_50;
        if ((int *)0x2 < local_5c) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          ppiVar6 = &local_20;
        }
        local_48 = (int *)((float)(int)*ppiVar6 * 0.125);
        local_68 = (float)(int)piVar10 * 0.125;
        local_4c = (int *)(float)(int)local_4c;
        pfVar7 = local_64;
        if ((int *)0x2 < piVar5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = local_44;
        }
        *pfVar7 = (float)local_48;
        pfVar7[1] = local_68;
        pfVar7[2] = (float)local_4c;
        pfVar7 = local_64;
        if ((int *)0x2 < piVar5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          pfVar7 = local_44;
        }
        fVar15 = (pfVar7[1] - local_70) * (pfVar7[1] - local_70) +
                 (*pfVar7 - local_74) * (*pfVar7 - local_74);
        FUN_0040b7e0();
        local_4c = (int *)((float)((int)fVar15 * (int)fVar15) * 1.3);
        DAT_00772dd8 = (int *)(int)ROUND((float)local_4c);
        if ((int *)0x2 < piVar5) {
          local_e4 = 9.126756e-39;
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        local_4c = (int *)&stack0xffffff24;
        local_48 = (int *)&local_e8;
        local_e8 = local_74;
        local_e4 = local_70;
        ppuVar17 = &local_90;
        local_8._0_1_ = 8;
        FUN_0059a4b0(ppuVar17);
        local_8 = CONCAT31(local_8._1_3_,6);
        FUN_0059d440(ppuVar17);
        if (local_90 != (undefined4 *)0x0) {
          iVar4 = local_90[8];
          piVar10 = piVar5;
          if (local_60 <= (int)local_90[8]) {
            iVar4 = local_60;
            piVar10 = local_54;
          }
          local_54 = piVar10;
          local_60 = iVar4;
          LOCK();
          iVar8 = local_90[1] + -1;
          local_90[1] = iVar8;
          UNLOCK();
          local_4c = local_54;
          if (iVar8 == 0) {
            local_60 = iVar4;
            if (local_90 != (undefined4 *)0x0) {
              (**(code **)*local_90)();
              local_60 = iVar4;
              local_54 = local_4c;
            }
          }
        }
      }
      local_64 = local_64 + 3;
      local_50 = local_50 + 1;
      local_5c = (int *)((int)piVar5 + 1);
    } while ((int)piVar5 + 1 < 3);
    if ((int)local_54 < 0) goto LAB_006362ef;
    if (2 < (int)local_54) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar10 = (int *)FUN_006badc0();
    if (local_a4 != 0) {
      if (*piVar10 == 0) {
        Tcl_ResetResult();
      }
      else {
        Tcl_SetObjResult();
      }
    }
    pcVar13 = TclFreeObj_exref;
    if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 < 1)) {
      TclFreeObj();
    }
  }
  local_8 = CONCAT31(local_8._1_3_,9);
  _eh_vector_destructor_iterator_(local_44,0xc,3,guard_check_icall);
  if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
    (*pcVar13)();
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

