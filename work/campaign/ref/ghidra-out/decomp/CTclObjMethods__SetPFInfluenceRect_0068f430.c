
undefined4
CTclObjMethods__SetPFInfluenceRect
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined4 *puVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  int iVar11;
  code *pcVar12;
  bool bVar13;
  undefined8 uVar14;
  undefined4 uVar15;
  int *local_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  undefined4 *local_4c;
  uint local_48;
  int local_44;
  int *local_3c;
  int *local_38;
  uint local_34;
  int *local_30;
  int *local_2c;
  uint local_28;
  int local_24;
  int *local_20;
  uint local_1c;
  uint local_18;
  byte local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00711965;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7920) &&
     (FUN_006cebf4(&DAT_00ca7920,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7920 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca7924 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclObjMethods::SetPFInfluenceRect()";
    *(int *)(&DAT_00773650 + iVar8) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7920);
  }
  iVar8 = DAT_00ca7924;
  uVar15 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7924 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar15;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar3 == 0) {
    uVar14 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar14;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  local_24 = FUN_005c71c0(param_4,8,1);
  if (local_24 == 0) {
    uVar15 = 1;
  }
  else {
    if (local_44 < 6) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 6) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_4c + 5;
    }
    piVar9 = (int *)*puVar5;
    if (piVar9 != (int *)0x0) {
      *piVar9 = *piVar9 + 1;
    }
    if (local_44 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_4c + 4;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if (local_44 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_4c + 3;
    }
    local_20 = (int *)*puVar5;
    if (local_20 != (int *)0x0) {
      *local_20 = *local_20 + 1;
    }
    if (local_44 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_4c + 2;
    }
    local_30 = (int *)*puVar5;
    if (local_30 != (int *)0x0) {
      *local_30 = *local_30 + 1;
    }
    if (piVar9 == (int *)0x0) {
      local_1c = 0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,piVar9,&local_2c);
      local_1c = -(uint)(iVar3 != 1) & (uint)local_2c;
    }
    if (piVar2 == (int *)0x0) {
      local_18 = 0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_34);
      local_18 = -(uint)(iVar3 != 1) & local_34;
    }
    if (local_20 == (int *)0x0) {
      uStack_58 = 0;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,local_20,&local_38);
      uStack_58 = -(uint)(iVar3 != 1) & (uint)local_38;
    }
    local_28 = uStack_58;
    if (local_30 == (int *)0x0) {
      uStack_50 = local_1c;
      local_2c = local_30;
      local_5c = local_30;
      uStack_54 = local_18;
    }
    else {
      iVar3 = Tcl_GetIntFromObj(0,local_30,&local_3c);
      uStack_50 = local_1c;
      uStack_58 = local_28;
      uStack_54 = local_18;
      if (iVar3 == 1) {
        local_2c = (int *)0x0;
      }
      else {
        local_2c = local_3c;
      }
      local_5c = local_2c;
      *local_30 = *local_30 + -1;
      if (*local_30 < 1) {
        TclFreeObj(local_30);
      }
    }
    if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 < 1)) {
      TclFreeObj(local_20);
    }
    pcVar12 = TclFreeObj_exref;
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, pcVar12 = TclFreeObj_exref, *piVar2 < 1))
    {
      TclFreeObj(piVar2);
    }
    if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
      (*pcVar12)(piVar9);
    }
    if (local_44 < 7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 7) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_4c + 6;
    }
    piVar9 = (int *)*puVar5;
    if (piVar9 != (int *)0x0) {
      *piVar9 = *piVar9 + 1;
    }
    local_8._0_1_ = 2;
    local_38 = piVar9;
    if (piVar9 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar9,0);
    }
    local_30 = piVar9;
    FUN_006b8fb0(ppuVar4);
    local_8 = CONCAT31(local_8._1_3_,4);
    if ((local_30 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 < 1)) {
      (*pcVar12)(piVar9);
    }
    pcVar10 = "INT_MAX";
    pbVar6 = (byte *)(local_3c + 3);
    do {
      local_11 = *pbVar6;
      bVar13 = local_11 < (byte)*pcVar10;
      if (local_11 != *pcVar10) {
LAB_0068f857:
        uVar7 = -(uint)bVar13 | 1;
        goto LAB_0068f85c;
      }
      if (local_11 == 0) break;
      local_11 = pbVar6[1];
      bVar13 = local_11 < ((byte *)pcVar10)[1];
      if (local_11 != ((byte *)pcVar10)[1]) goto LAB_0068f857;
      pbVar6 = pbVar6 + 2;
      pcVar10 = (char *)((byte *)pcVar10 + 2);
    } while (local_11 != 0);
    uVar7 = 0;
LAB_0068f85c:
    pbVar6 = (byte *)(local_3c + 3);
    if (uVar7 == 0) {
      local_20 = (int *)0x7fffffff;
    }
    else {
      pcVar10 = "INT_MIN";
      do {
        bVar1 = *pbVar6;
        bVar13 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_0068f891:
          uVar7 = -(uint)bVar13 | 1;
          goto LAB_0068f896;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar6[1];
        bVar13 = bVar1 < ((byte *)pcVar10)[1];
        if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_0068f891;
        pbVar6 = pbVar6 + 2;
        pcVar10 = (char *)((byte *)pcVar10 + 2);
      } while (bVar1 != 0);
      uVar7 = 0;
LAB_0068f896:
      if (uVar7 == 0) {
        local_20 = (int *)0x80000000;
      }
      else {
        puVar5 = (undefined4 *)FUN_004295e0(6);
        piVar9 = (int *)*puVar5;
        if (piVar9 == (int *)0x0) {
          local_20 = (int *)0x0;
        }
        else {
          *piVar9 = *piVar9 + 1;
          iVar3 = Tcl_GetIntFromObj(0,piVar9,&local_38);
          *piVar9 = *piVar9 + -1;
          local_20 = (int *)(-(uint)(iVar3 != 1) & (uint)local_38);
          if (*piVar9 < 1) {
            TclFreeObj(piVar9);
          }
        }
      }
    }
    if (local_44 < 8) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_4c;
      if (local_48 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_48 < 8) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_4c + 7;
    }
    piVar9 = (int *)*puVar5;
    if (piVar9 == (int *)0x0) {
      local_30 = (int *)0x0;
    }
    else {
      *piVar9 = *piVar9 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar9,&local_38);
      *piVar9 = *piVar9 + -1;
      local_30 = (int *)(-(uint)(iVar3 != 1) & (uint)local_38);
      if (*piVar9 < 1) {
        TclFreeObj(piVar9);
      }
    }
    local_38 = *(int **)(local_24 + 0x254);
    if (((((local_38 != local_2c) || (*(uint *)(local_24 + 600) != local_28)) ||
         (*(uint *)(local_24 + 0x25c) != local_18)) ||
        ((*(uint *)(local_24 + 0x260) != local_1c ||
         ((int *)*(uint *)(local_24 + 0x264) != local_20)))) ||
       ((int *)*(uint *)(local_24 + 0x268) != local_30)) {
      iVar3 = (int)(*(float *)(local_24 + 0x10) * -8.0);
      uVar15 = 7;
      iVar8 = (int)(*(float *)(local_24 + 0xc) * -8.0);
      uVar7 = *(int *)(local_24 + 0x260) - iVar3;
      iVar3 = *(int *)(local_24 + 600) - iVar3;
      iVar11 = *(int *)(local_24 + 0x25c) - iVar8;
      iVar8 = (int)local_38 - iVar8;
      local_34 = uVar7;
      FUN_005a3dd0(iVar8,iVar3,iVar11,uVar7,7);
      FUN_005a3fd0(iVar8,iVar3,iVar11,uVar7,uVar15);
      uVar15 = 7;
      *(int **)(local_24 + 0x264) = local_20;
      *(int **)(local_24 + 0x254) = local_5c;
      *(uint *)(local_24 + 600) = uStack_58;
      *(uint *)(local_24 + 0x25c) = uStack_54;
      *(uint *)(local_24 + 0x260) = uStack_50;
      *(int **)(local_24 + 0x268) = local_30;
      iVar8 = (int)(*(float *)(local_24 + 0xc) * -8.0);
      iVar3 = (int)(*(float *)(local_24 + 0x10) * -8.0);
      iVar11 = *(int *)(local_24 + 0x25c) - iVar8;
      piVar9 = (int *)(*(int *)(local_24 + 0x260) - iVar3);
      iVar3 = *(int *)(local_24 + 600) - iVar3;
      iVar8 = *(int *)(local_24 + 0x254) - iVar8;
      local_38 = piVar9;
      FUN_005a3dd0(iVar8,iVar3,iVar11,piVar9,7);
      FUN_005a3fd0(iVar8,iVar3,iVar11,piVar9,uVar15);
    }
    uVar15 = 0;
    local_8._0_1_ = 5;
    if ((local_3c != (int *)0x0) && (*local_3c = *local_3c + -1, *local_3c == 0)) {
      FUN_006ba940();
    }
  }
  local_8._0_1_ = 6;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,7);
  FUN_004297b0(0);
  if (local_4c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar15;
}

