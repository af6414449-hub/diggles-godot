
/* WARNING: Removing unreachable block (ram,0x0063c1b7) */
/* WARNING: Removing unreachable block (ram,0x0063c1c0) */
/* WARNING: Removing unreachable block (ram,0x0063c1d5) */
/* WARNING: Removing unreachable block (ram,0x0063c1eb) */
/* WARNING: Removing unreachable block (ram,0x0063c217) */
/* WARNING: Removing unreachable block (ram,0x0063c282) */
/* WARNING: Removing unreachable block (ram,0x0063c28e) */
/* WARNING: Removing unreachable block (ram,0x0063c29a) */
/* WARNING: Removing unreachable block (ram,0x0063c2a0) */
/* WARNING: Removing unreachable block (ram,0x0063c2ac) */
/* WARNING: Removing unreachable block (ram,0x0063c2b4) */
/* WARNING: Removing unreachable block (ram,0x0063c2bc) */
/* WARNING: Removing unreachable block (ram,0x0063c2f2) */
/* WARNING: Removing unreachable block (ram,0x0063c2fb) */
/* WARNING: Removing unreachable block (ram,0x0063c305) */
/* WARNING: Removing unreachable block (ram,0x0063c317) */
/* WARNING: Removing unreachable block (ram,0x0063c310) */
/* WARNING: Removing unreachable block (ram,0x0063c238) */
/* WARNING: Removing unreachable block (ram,0x0063c242) */
/* WARNING: Removing unreachable block (ram,0x0063c200) */
/* WARNING: Removing unreachable block (ram,0x0063c20a) */
/* WARNING: Removing unreachable block (ram,0x0063c24c) */
/* WARNING: Removing unreachable block (ram,0x0063c25f) */
/* WARNING: Removing unreachable block (ram,0x0063c26c) */
/* WARNING: Removing unreachable block (ram,0x0063c320) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
CTclGlobalMethods__MapTemplate
          (undefined4 param_1,undefined4 param_2,undefined **param_3,undefined4 param_4)

{
  char cVar1;
  byte bVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  byte *pbVar8;
  uint uVar9;
  AchievementManager *pAVar10;
  uint uVar11;
  int iVar12;
  undefined **ppuVar13;
  undefined *puVar14;
  char *pcVar15;
  uint extraout_ECX;
  code *pcVar16;
  int *piVar17;
  undefined4 uVar18;
  bool bVar19;
  undefined8 uVar20;
  undefined4 *local_54;
  uint local_50;
  int local_4c;
  int *local_28;
  int *local_24;
  uint local_20;
  uint local_1c;
  byte *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070d4ad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6ff0) &&
     (FUN_006cebf4(&DAT_00ca6ff0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca6ff0 == -1)) {
    iVar12 = DAT_00783650 * 0x40;
    DAT_00ca6ff4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar12) = "TCL:CTclGlobalMethods::MapTemplate()";
    *(int *)(&DAT_00773650 + iVar12) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6ff0);
  }
  iVar12 = DAT_00ca6ff4;
  uVar18 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6ff4 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar18;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar12 * 0x10];
  if (iVar5 == 0) {
    uVar20 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar12 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar12 * 0x10) = uVar20;
  }
  (&DAT_00773654)[iVar12 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 == (undefined **)0x4) {
    if (local_4c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_54;
      if (local_50 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_50 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_54 + 1;
    }
    piVar3 = (int *)*puVar6;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    if (local_4c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_54;
      if (local_50 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_50 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_54 + 2;
    }
    piVar7 = (int *)*puVar6;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
    }
    local_24 = piVar7;
    if (local_4c < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = local_54;
      if (local_50 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_50 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar6 = local_54 + 3;
    }
    piVar4 = (int *)*puVar6;
    if (piVar4 != (int *)0x0) {
      *piVar4 = *piVar4 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    if (piVar3 == (int *)0x0) {
      param_3 = &PTR_0071ce50;
    }
    else {
      param_3 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
    }
    if (piVar7 == (int *)0x0) {
      local_20 = 0;
    }
    else {
      iVar5 = Tcl_GetIntFromObj(0,piVar7,&local_28);
      local_20 = -(uint)(iVar5 != 1) & (uint)local_28;
    }
    if (piVar4 == (int *)0x0) {
      local_1c = 0;
    }
    else {
      iVar5 = Tcl_GetIntFromObj(0,piVar4,&local_28);
      local_1c = -(uint)(iVar5 != 1) & (uint)local_28;
    }
    FUN_004402c0();
    local_8._0_1_ = 6;
    iVar5 = local_14[2];
    if (iVar5 == -1) {
      piVar17 = local_14 + 3;
      param_3 = (undefined **)((int)local_14 + 0xd);
      do {
        iVar5 = *piVar17;
        piVar17 = (int *)((int)piVar17 + 1);
      } while ((char)iVar5 != '\0');
      iVar5 = (int)piVar17 - (int)param_3;
      local_14[2] = iVar5;
    }
    if ((iVar5 != 0) && (*(char *)(DAT_0077241c + 0x29) != '\0')) {
      if (*(char *)(DAT_00772400 + 0x91) == '\0') {
        FUN_0055a950(&local_14,0);
        FUN_006b59e0();
      }
      local_8._0_1_ = 9;
      iVar5 = FUN_006b9e50(0x2f);
      if (iVar5 == -1) {
        param_3 = (undefined **)FUN_006b9410(&local_14);
        local_8._0_1_ = 10;
        piVar17 = (int *)*param_3;
        if (piVar17 != (int *)0x0) {
          *piVar17 = *piVar17 + 1;
        }
        if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
          local_14 = piVar17;
          FUN_006ba940();
          piVar17 = local_14;
        }
        local_14 = piVar17;
        local_14[2] = *(int *)(*param_3 + 8);
        local_8._0_1_ = 0xb;
        if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
          FUN_006ba940();
        }
        local_8._0_1_ = 9;
      }
      iVar5 = FUN_006b9f40(&DAT_007254d8);
      if (iVar5 == -1) {
        local_18 = (byte *)(local_14 + 3);
        FUN_006b8fb0(local_18);
        local_8._0_1_ = 0xc;
        puVar14 = param_3[2];
        if (puVar14 == (undefined *)0xffffffff) {
          ppuVar13 = param_3 + 3;
          do {
            cVar1 = *(char *)ppuVar13;
            ppuVar13 = (undefined **)((int)ppuVar13 + 1);
          } while (cVar1 != '\0');
          puVar14 = (undefined *)((int)ppuVar13 - ((int)param_3 + 0xd));
          param_3[2] = puVar14;
        }
        FUN_006b9b20(&local_28,0,puVar14 + -4);
        piVar7 = local_28;
        local_8._0_1_ = 0xd;
        if (local_28 != (int *)0x0) {
          *local_28 = *local_28 + 1;
        }
        if ((param_3 != (undefined **)0x0) &&
           (*param_3 = *param_3 + -1, *param_3 == (undefined *)0x0)) {
          FUN_006ba940();
        }
        local_8._0_1_ = 0xe;
        *local_28 = *local_28 + -1;
        if (*local_28 == 0) {
          FUN_006ba940();
        }
        local_8._0_1_ = 0xc;
        piVar17 = (int *)local_28[2];
        if (piVar17 == (int *)0xffffffff) {
          piVar17 = local_28 + 3;
          do {
            iVar5 = *piVar17;
            piVar17 = (int *)((int)piVar17 + 1);
          } while ((char)iVar5 != '\0');
          piVar17 = (int *)((int)piVar17 - ((int)local_28 + 0xd));
          local_28[2] = (int)piVar17;
        }
        local_28 = piVar17;
        piVar7 = (int *)FUN_006b8df0(piVar7,(int)piVar17 + 5);
        *(undefined4 *)((int)(local_28 + 3) + (int)piVar7) = 0x706d702e;
        *(undefined1 *)((int)(local_28 + 4) + (int)piVar7) = 0;
        piVar7[2] = (int)(local_28 + 1);
        FUN_005992b0(piVar7 + 3,local_20,local_1c);
        local_8._0_1_ = 0xf;
        *piVar7 = *piVar7 + -1;
        if (*piVar7 == 0) {
          FUN_006ba940();
        }
        local_8._0_1_ = 9;
        piVar7 = local_24;
      }
      else {
        local_18 = (byte *)(local_14 + 3);
        FUN_005992b0(local_18,local_20,local_1c);
      }
      pcVar15 = "data/templates/obw_tutorial.pmp";
      pbVar8 = local_18;
      do {
        bVar2 = *pbVar8;
        bVar19 = bVar2 < (byte)*pcVar15;
        if (bVar2 != *pcVar15) {
LAB_0063c135:
          uVar9 = -(uint)bVar19 | 1;
          goto LAB_0063c13a;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar8[1];
        bVar19 = bVar2 < ((byte *)pcVar15)[1];
        if (bVar2 != ((byte *)pcVar15)[1]) goto LAB_0063c135;
        pbVar8 = pbVar8 + 2;
        pcVar15 = (char *)((byte *)pcVar15 + 2);
      } while (bVar2 != 0);
      uVar9 = 0;
LAB_0063c13a:
      if (uVar9 == 0) {
        pcVar15 = "Trigger_Tutorial";
        pAVar10 = AchievementManager::GetInstance();
        AchievementManager::CheckTriggerName(pAVar10,pcVar15);
      }
      pcVar15 = "data/templates/unq_ende_seq.pmp";
      pbVar8 = local_18;
      do {
        bVar2 = *pbVar8;
        uVar9 = (uint)bVar2;
        bVar19 = bVar2 < (byte)*pcVar15;
        if (bVar2 != *pcVar15) {
LAB_0063c180:
          uVar11 = -(uint)bVar19 | 1;
          goto LAB_0063c185;
        }
        if (bVar2 == 0) break;
        bVar2 = pbVar8[1];
        uVar9 = (uint)bVar2;
        bVar19 = bVar2 < ((byte *)pcVar15)[1];
        if (bVar2 != ((byte *)pcVar15)[1]) goto LAB_0063c180;
        pbVar8 = pbVar8 + 2;
        pcVar15 = (char *)((byte *)pcVar15 + 2);
      } while (bVar2 != 0);
      uVar11 = 0;
LAB_0063c185:
      if (uVar11 == 0) {
        pcVar15 = "Riesenelfe_der_tot";
        pAVar10 = AchievementManager::GetInstance();
        AchievementManager::CheckTriggerName(pAVar10,pcVar15);
        uVar9 = extraout_ECX;
      }
      local_8._0_1_ = 0x10;
      FUN_0059a1f0(uVar9);
    }
    local_8 = CONCAT31(local_8._1_3_,0x11);
    *local_14 = *local_14 + -1;
    if (*local_14 == 0) {
      FUN_006ba940();
    }
    pcVar16 = TclFreeObj_exref;
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
      pcVar16 = TclFreeObj_exref;
    }
    if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
      (*pcVar16)(piVar7);
    }
    uVar18 = 0;
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
      TclFreeObj(piVar3);
    }
  }
  else {
    FUN_006bc8f0(3);
    uVar18 = 1;
  }
  local_8._0_1_ = 0x12;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x13);
  FUN_004297b0(0);
  if (local_54 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar18;
}

