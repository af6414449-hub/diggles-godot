
undefined4
CTclGlobalMethods__Call(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  int *piVar5;
  undefined4 *puVar6;
  int **ppiVar7;
  int iVar8;
  int *piVar9;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar10;
  int *piVar11;
  undefined8 uVar12;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070cc0d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6e60) &&
     (FUN_006cebf4(&DAT_00ca6e60,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6e60 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca6e64 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::Call()";
    *(int *)(&DAT_00773650 + iVar8) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6e60);
  }
  iVar8 = DAT_00ca6e64;
  uVar10 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6e64 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar10;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar3 == 0) {
    uVar12 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar1 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar1 < 2) {
    FUN_006bc8f0(1);
    uVar10 = 1;
    goto LAB_006317aa;
  }
  if (local_28 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar6 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar6 = local_30 + 1;
  }
  piVar1 = (int *)*puVar6;
  if (piVar1 != (int *)0x0) {
    *piVar1 = *piVar1 + 1;
  }
  local_8._0_1_ = 3;
  if (piVar1 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
  }
  else {
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar1,0);
  }
  FUN_006b8fb0(ppuVar4);
  piVar11 = param_3;
  local_8._0_1_ = 4;
  iVar3 = param_3[2];
  if (iVar3 == -1) {
    piVar9 = param_3 + 3;
    do {
      iVar3 = *piVar9;
      piVar9 = (int *)((int)piVar9 + 1);
    } while ((char)iVar3 != '\0');
    iVar3 = (int)piVar9 - ((int)param_3 + 0xd);
    param_3[2] = iVar3;
  }
  if (iVar3 == 0) {
    FUN_006bc6a0("call filename was empty !",0);
    uVar10 = 1;
  }
  else {
    local_14 = (int *)0x0;
    piVar9 = param_3 + 3;
    local_8._0_1_ = 6;
    iVar3 = __strnicmp((char *)piVar9,"scripts/",8);
    if (iVar3 == 0) {
      piVar5 = (int *)FUN_006b95d0(&param_3);
      local_8._0_1_ = 7;
      piVar9 = (int *)*piVar5;
      if (piVar9 != (int *)0x0) {
        *piVar9 = *piVar9 + 1;
      }
      param_3 = piVar9;
      if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 == 0)) {
        FUN_006ba940();
      }
      piVar9[2] = *(int *)(*piVar5 + 8);
      local_8 = CONCAT31(local_8._1_3_,8);
LAB_006315f6:
      if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 6;
    }
    else {
      iVar3 = __strnicmp((char *)piVar9,"templates/",10);
      piVar9 = piVar11;
      if (iVar3 == 0) {
        piVar5 = (int *)FUN_006b95d0(&param_3);
        local_8._0_1_ = 9;
        piVar9 = (int *)*piVar5;
        if (piVar9 != (int *)0x0) {
          *piVar9 = *piVar9 + 1;
        }
        param_3 = piVar9;
        if ((piVar11 != (int *)0x0) && (*piVar11 = *piVar11 + -1, *piVar11 == 0)) {
          FUN_006ba940();
        }
        piVar9[2] = *(int *)(*piVar5 + 8);
        local_8 = CONCAT31(local_8._1_3_,10);
        goto LAB_006315f6;
      }
    }
    iVar3 = __strnicmp((char *)(piVar9 + 3),"data/templates",0xe);
    if (iVar3 == 0) {
      puVar6 = (undefined4 *)FUN_006bb140();
      local_14 = (int *)*puVar6;
      if (local_14 != (int *)0x0) {
LAB_0063166d:
        *local_14 = *local_14 + 1;
      }
      piVar5 = local_14;
      if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 < 1)) {
        TclFreeObj(local_18);
      }
      piVar11 = piVar9;
      if (piVar5 == (int *)0x0) goto LAB_00631693;
LAB_00631802:
      cVar2 = FUN_00555a00(&local_14);
      if (cVar2 != '\0') goto LAB_0063176b;
      uVar10 = 1;
    }
    else {
      if (DAT_00772dd0 == 0) {
        FUN_006bb140();
      }
      else {
        FUN_006bbb00(&local_18,piVar9 + 3,extraout_ECX);
      }
      local_14 = local_18;
      if (local_18 != (int *)0x0) goto LAB_0063166d;
LAB_00631693:
      piVar5 = (int *)FUN_004402c0();
      local_8._0_1_ = 0xb;
      piVar11 = (int *)*piVar5;
      if (piVar11 != (int *)0x0) {
        *piVar11 = *piVar11 + 1;
      }
      param_3 = piVar11;
      if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
        FUN_006ba940();
      }
      piVar11[2] = *(int *)(*piVar5 + 8);
      local_8._0_1_ = 0xc;
      if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 6;
      iVar3 = __strnicmp((char *)(piVar11 + 3),"data/templates",0xe);
      if (iVar3 == 0) {
        ppiVar7 = (int **)FUN_006bb140();
      }
      else {
        if (DAT_00772dd0 == 0) {
          FUN_006bb140();
        }
        else {
          FUN_006bbb00(&local_18,piVar11 + 3,extraout_ECX_00);
        }
        ppiVar7 = &local_18;
      }
      FUN_006baea0(ppiVar7);
      FUN_006bad60();
      piVar5 = local_14;
      if (local_14 != (int *)0x0) goto LAB_00631802;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("file not found.",piVar1);
LAB_0063176b:
      uVar10 = 0;
    }
    if ((piVar5 != (int *)0x0) && (*piVar5 = *piVar5 + -1, *piVar5 < 1)) {
      TclFreeObj(piVar5);
    }
  }
  local_8 = CONCAT31(local_8._1_3_,0xf);
  *piVar11 = *piVar11 + -1;
  if (*piVar11 == 0) {
    FUN_006ba940();
  }
  if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
    TclFreeObj(piVar1);
  }
LAB_006317aa:
  local_8._0_1_ = 0x10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x11);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar10;
}

