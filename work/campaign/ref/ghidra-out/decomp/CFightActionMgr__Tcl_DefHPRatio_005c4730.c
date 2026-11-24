
undefined4
CFightActionMgr__Tcl_DefHPRatio
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined **ppuVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  undefined4 uVar12;
  uint uVar13;
  code *pcVar14;
  bool bVar15;
  undefined8 uVar16;
  float fVar17;
  undefined4 *local_48;
  uint local_44;
  int local_40;
  undefined1 local_28 [4];
  int *piStack_24;
  undefined4 local_20;
  uint uStack_1c;
  int local_18;
  float local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007080d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca65f8) &&
     (FUN_006cebf4(&DAT_00ca65f8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar6 = DAT_00783650,
     DAT_00ca65f8 == -1)) {
    iVar10 = DAT_00783650 * 0x40;
    DAT_00ca65fc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar10) = "TCL:CFightActionMgr::Tcl_DefHPRatio()";
    *(int *)(&DAT_00773650 + iVar10) = iVar6;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca65f8);
  }
  iVar10 = DAT_00ca65fc;
  uVar12 = *(undefined4 *)(&DAT_00773650 + DAT_00ca65fc * 0x40);
  iVar6 = FUN_0043fcc0();
  *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar12;
  *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
  iVar6 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar6 == 0) {
    uVar16 = FUN_006bd180();
    iVar6 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar16;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar6 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 4) {
    FUN_006bc8f0(3);
    uVar12 = 1;
  }
  else {
    if (local_40 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_48 + 1;
    }
    piVar2 = (int *)*puVar7;
    if (piVar2 != (int *)0x0) {
      *piVar2 = *piVar2 + 1;
    }
    if (local_40 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_48 + 2;
    }
    piVar3 = (int *)*puVar7;
    if (piVar3 != (int *)0x0) {
      *piVar3 = *piVar3 + 1;
    }
    if (local_40 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_48;
      if (local_44 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_44 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_48 + 3;
    }
    piVar4 = (int *)*puVar7;
    if (piVar4 != (int *)0x0) {
      *piVar4 = *piVar4 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    local_14 = -1.0;
    if (4 < param_3) {
      if (local_40 < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_48;
        if (local_44 == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_44 < 5) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar7 = local_48 + 4;
      }
      piStack_24 = (int *)*puVar7;
      if (piStack_24 == (int *)0x0) {
        local_14 = 0.0;
      }
      else {
        *piStack_24 = *piStack_24 + 1;
        iVar6 = Tcl_GetDoubleFromObj(0,piStack_24,&local_20);
        if (iVar6 == 1) {
          local_14 = 0.0;
        }
        else {
          local_14 = (float)(double)CONCAT44(uStack_1c,local_20);
        }
        *piStack_24 = *piStack_24 + -1;
        if (*piStack_24 < 1) {
          TclFreeObj(piStack_24);
        }
      }
    }
    if (piVar2 == (int *)0x0) {
      ppuVar8 = &PTR_0071ce50;
    }
    else {
      ppuVar8 = (undefined **)Tcl_GetStringFromObj(piVar2,0);
    }
    FUN_006b8fb0(ppuVar8);
    local_18 = DAT_00772478;
    cVar5 = FUN_006037d0(&piStack_24,&uStack_1c);
    if (cVar5 == '\0') {
      iVar6 = 0;
    }
    else {
      if (*(uint *)(local_18 + 0x801c) <= uStack_1c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      iVar6 = *(int *)(*(int *)(local_18 + 0x8018) + uStack_1c * 4);
    }
    local_8._0_1_ = 6;
    if ((piStack_24 != (int *)0x0) && (*piStack_24 = *piStack_24 + -1, *piStack_24 == 0)) {
      FUN_006ba940();
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    if (iVar6 == 0) {
      if (piVar2 != (int *)0x0) {
        *piVar2 = *piVar2 + 1;
      }
      FUN_006bc6a0("unknown class",piVar2);
      uVar12 = 1;
    }
    else {
      uStack_1c = *(uint *)(iVar6 + 8);
      if (piVar3 == (int *)0x0) {
        uVar13 = 0;
        ppuVar8 = &PTR_0071ce50;
      }
      else {
        iVar6 = Tcl_GetIntFromObj(0,piVar3,&piStack_24);
        uVar13 = -(uint)(iVar6 != 1) & (uint)piStack_24;
        ppuVar8 = (undefined **)Tcl_GetStringFromObj(piVar3,0);
      }
      pbVar11 = &DAT_0072b6e8;
      do {
        bVar1 = *(byte *)ppuVar8;
        bVar15 = bVar1 < *pbVar11;
        if (bVar1 != *pbVar11) {
LAB_005c4ab7:
          uVar9 = -(uint)bVar15 | 1;
          goto LAB_005c4abc;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar8 + 1);
        bVar15 = bVar1 < pbVar11[1];
        if (bVar1 != pbVar11[1]) goto LAB_005c4ab7;
        ppuVar8 = (undefined **)((int)ppuVar8 + 2);
        pbVar11 = pbVar11 + 2;
      } while (bVar1 != 0);
      uVar9 = 0;
LAB_005c4abc:
      if (uVar9 == 0) {
        uVar13 = 0xfffffffe;
      }
      if (piVar4 != (int *)0x0) {
        Tcl_GetDoubleFromObj(0,piVar4,local_28);
      }
      uVar9 = uStack_1c;
      fVar17 = local_14;
      FUN_005bbb20(uStack_1c,uVar13,local_14);
      FUN_005c44d0(uVar9,uVar13,fVar17);
      uVar12 = 0;
    }
    if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 < 1)) {
      TclFreeObj(piVar4);
    }
    pcVar14 = TclFreeObj_exref;
    if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, pcVar14 = TclFreeObj_exref, *piVar3 < 1))
    {
      TclFreeObj(piVar3);
    }
    if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
      (*pcVar14)(piVar2);
    }
  }
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_48 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar12;
}

