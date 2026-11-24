
undefined4
CTclObjMethods__GetFSource(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  undefined **ppuVar5;
  byte *pbVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  char *pcVar12;
  byte *pbVar13;
  code *pcVar14;
  bool bVar15;
  undefined8 uVar16;
  undefined4 uVar17;
  int **ppiVar18;
  undefined1 *puVar19;
  undefined1 *puVar20;
  undefined1 *puVar21;
  int local_50;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  undefined4 *local_28;
  undefined1 local_24 [4];
  undefined1 local_20 [4];
  undefined1 local_1c [4];
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711ccd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7aa0) &&
     (FUN_006cebf4(&DAT_00ca7aa0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7aa0 == -1)) {
    iVar9 = DAT_00783650 * 0x40;
    DAT_00ca7aa4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar9) = "TCL:CTclObjMethods::GetFSource()";
    *(int *)(&DAT_00773650 + iVar9) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7aa0);
  }
  iVar9 = DAT_00ca7aa4;
  local_28 = &DAT_00ca7aa4;
  uVar17 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7aa4 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar17;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar9 * 0x10];
  if (iVar4 == 0) {
    uVar16 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar9 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar9 * 0x10) = uVar16;
  }
  (&DAT_00773654)[iVar9 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar17 = param_4;
  iVar4 = (int)param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  uVar3 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (iVar4 == 3) {
    local_8._0_1_ = uVar3;
    iVar4 = FUN_005c71c0(uVar17,2,1);
    if (iVar4 != 0) {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar10 = local_34;
        if (local_30 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar10 = local_34;
        }
      }
      else {
        if (local_30 < 3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar10 = local_34 + 2;
      }
      piVar2 = (int *)*puVar10;
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      local_8._0_1_ = 7;
      param_3 = piVar2;
      if (piVar2 == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
        piVar8 = (int *)0x0;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
        piVar8 = piVar2;
      }
      FUN_006b8fb0(ppuVar5);
      local_8 = CONCAT31(local_8._1_3_,9);
      if ((piVar8 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
        TclFreeObj(piVar2);
      }
      iVar9 = (int)&param_3 + 3;
      local_38 = 0;
      puVar21 = local_24;
      local_3c = 0;
      puVar20 = local_20;
      local_40 = 0;
      puVar19 = local_1c;
      puVar10 = &local_40;
      ppiVar18 = &local_18;
      uVar17 = *(undefined4 *)(iVar4 + 0xdc);
      FUN_0057d980(uVar17,ppiVar18,puVar10,puVar19,puVar20,puVar21,iVar9);
      FUN_0057b6e0(uVar17,ppiVar18,puVar10,puVar19,puVar20,puVar21,iVar9);
      piVar2 = local_14;
      pbVar11 = &DAT_0072bee8;
      pbVar13 = (byte *)(local_14 + 3);
      pbVar6 = pbVar13;
      do {
        bVar1 = *pbVar6;
        bVar15 = bVar1 < *pbVar11;
        if (bVar1 != *pbVar11) {
LAB_00699a72:
          uVar7 = -(uint)bVar15 | 1;
          goto LAB_00699a77;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar15 = bVar1 < pbVar11[1];
        if (bVar1 != pbVar11[1]) goto LAB_00699a72;
        pbVar6 = pbVar6 + 2;
        pbVar11 = pbVar11 + 2;
      } while (bVar1 != 0);
      uVar7 = 0;
LAB_00699a77:
      if (uVar7 == 0) {
        piVar8 = (int *)FUN_006badc0(&local_40);
        if (local_50 != 0) {
          if (*piVar8 == 0) {
            Tcl_ResetResult(local_50);
          }
          else {
            Tcl_SetObjResult(local_50,*piVar8);
          }
        }
        if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
          TclFreeObj(local_14);
        }
      }
      pcVar12 = "-type";
      pbVar6 = pbVar13;
      do {
        bVar1 = *pbVar6;
        bVar15 = bVar1 < (byte)*pcVar12;
        if (bVar1 != *pcVar12) {
LAB_00699af0:
          uVar7 = -(uint)bVar15 | 1;
          goto LAB_00699af5;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar15 = bVar1 < ((byte *)pcVar12)[1];
        if (bVar1 != ((byte *)pcVar12)[1]) goto LAB_00699af0;
        pbVar6 = pbVar6 + 2;
        pcVar12 = (char *)((byte *)pcVar12 + 2);
      } while (bVar1 != 0);
      uVar7 = 0;
LAB_00699af5:
      pcVar14 = TclFreeObj_exref;
      if (uVar7 == 0) {
        if (local_18 == (int *)0x1) {
          piVar8 = (int *)Tcl_NewStringObj("water",0xffffffff);
          *piVar8 = *piVar8 + 1;
          local_18 = piVar8;
          FUN_006bc670(&local_18);
          *piVar8 = *piVar8 + -1;
          pcVar14 = TclFreeObj_exref;
          if (*piVar8 < 1) {
            TclFreeObj(piVar8);
          }
        }
        else if (local_18 == (int *)0x2) {
          piVar8 = (int *)Tcl_NewStringObj(&DAT_00734864,0xffffffff);
          *piVar8 = *piVar8 + 1;
          local_18 = piVar8;
          FUN_006bc670(&local_18);
          *piVar8 = *piVar8 + -1;
          pcVar14 = TclFreeObj_exref;
          if (*piVar8 < 1) {
            TclFreeObj(piVar8);
          }
        }
        else if (local_18 == (int *)0x3) {
          piVar8 = (int *)Tcl_NewStringObj(&DAT_0072fe8c,0xffffffff);
          *piVar8 = *piVar8 + 1;
          local_18 = piVar8;
          FUN_006bc670(&local_18);
          *piVar8 = *piVar8 + -1;
          pcVar14 = TclFreeObj_exref;
          if (*piVar8 < 1) {
            TclFreeObj(piVar8);
          }
        }
      }
      pcVar12 = "-volume";
      pbVar6 = pbVar13;
      do {
        bVar1 = *pbVar6;
        bVar15 = bVar1 < (byte)*pcVar12;
        if (bVar1 != *pcVar12) {
LAB_00699bf0:
          uVar7 = -(uint)bVar15 | 1;
          goto LAB_00699bf5;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar15 = bVar1 < ((byte *)pcVar12)[1];
        if (bVar1 != ((byte *)pcVar12)[1]) goto LAB_00699bf0;
        pbVar6 = pbVar6 + 2;
        pcVar12 = (char *)((byte *)pcVar12 + 2);
      } while (bVar1 != 0);
      uVar7 = 0;
LAB_00699bf5:
      if (uVar7 == 0) {
        piVar8 = (int *)FUN_006bad90();
        if (local_50 != 0) {
          if (*piVar8 == 0) {
            Tcl_ResetResult(local_50);
          }
          else {
            Tcl_SetObjResult(local_50,*piVar8);
          }
        }
        if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
          (*pcVar14)(local_14);
        }
      }
      pcVar12 = "-height";
      pbVar6 = pbVar13;
      do {
        bVar1 = *pbVar6;
        bVar15 = bVar1 < (byte)*pcVar12;
        if (bVar1 != *pcVar12) {
LAB_00699c70:
          uVar7 = -(uint)bVar15 | 1;
          goto LAB_00699c75;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar15 = bVar1 < ((byte *)pcVar12)[1];
        if (bVar1 != ((byte *)pcVar12)[1]) goto LAB_00699c70;
        pbVar6 = pbVar6 + 2;
        pcVar12 = (char *)((byte *)pcVar12 + 2);
      } while (bVar1 != 0);
      uVar7 = 0;
LAB_00699c75:
      if (uVar7 == 0) {
        piVar8 = (int *)FUN_006bad90();
        if (local_50 != 0) {
          if (*piVar8 == 0) {
            Tcl_ResetResult(local_50);
          }
          else {
            Tcl_SetObjResult(local_50,*piVar8);
          }
        }
        if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
          (*pcVar14)(local_14);
        }
      }
      pbVar11 = &DAT_00734888;
      pbVar6 = pbVar13;
      do {
        bVar1 = *pbVar6;
        bVar15 = bVar1 < *pbVar11;
        if (bVar1 != *pbVar11) {
LAB_00699cf0:
          uVar7 = -(uint)bVar15 | 1;
          goto LAB_00699cf5;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar15 = bVar1 < pbVar11[1];
        if (bVar1 != pbVar11[1]) goto LAB_00699cf0;
        pbVar6 = pbVar6 + 2;
        pbVar11 = pbVar11 + 2;
      } while (bVar1 != 0);
      uVar7 = 0;
LAB_00699cf5:
      if (uVar7 == 0) {
        piVar8 = (int *)FUN_006bad90();
        if (local_50 != 0) {
          if (*piVar8 == 0) {
            Tcl_ResetResult(local_50);
          }
          else {
            Tcl_SetObjResult(local_50,*piVar8);
          }
        }
        if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 < 1)) {
          (*pcVar14)(local_14);
        }
      }
      pcVar12 = "-ventil";
      do {
        bVar1 = *pbVar13;
        bVar15 = bVar1 < (byte)*pcVar12;
        if (bVar1 != *pcVar12) {
LAB_00699d70:
          uVar7 = -(uint)bVar15 | 1;
          goto LAB_00699d75;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar13[1];
        bVar15 = bVar1 < ((byte *)pcVar12)[1];
        if (bVar1 != ((byte *)pcVar12)[1]) goto LAB_00699d70;
        pbVar13 = pbVar13 + 2;
        pcVar12 = (char *)((byte *)pcVar12 + 2);
      } while (bVar1 != 0);
      uVar7 = 0;
LAB_00699d75:
      if (uVar7 == 0) {
        piVar8 = (int *)Tcl_NewBooleanObj((uint)param_3 >> 0x18);
        *piVar8 = *piVar8 + 1;
        iVar4 = *piVar8;
        if (local_50 != 0) {
          Tcl_SetObjResult(local_50,piVar8);
          iVar4 = *piVar8;
        }
        *piVar8 = iVar4 + -1;
        if (iVar4 + -1 < 1) {
          TclFreeObj(piVar8);
        }
      }
      local_8._0_1_ = 10;
      if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 0xb;
      FUN_004297b0(0);
      local_8 = CONCAT31(local_8._1_3_,0xc);
      FUN_004297b0(0);
      if (local_34 != (undefined4 *)0x0) {
        FUN_006ba940();
      }
      FUN_006bc0d0();
      FUN_0043fd30();
      ExceptionList = local_10;
      return 0;
    }
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar10 = local_34;
      }
    }
    else {
      if (local_30 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_34 + 1;
    }
    piVar2 = (int *)*puVar10;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    FUN_006bc6a0("invalid object",piVar2);
    local_8._0_1_ = 5;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,6);
  }
  else {
    FUN_006bc8f0(2);
    local_8._0_1_ = 3;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return 1;
}

