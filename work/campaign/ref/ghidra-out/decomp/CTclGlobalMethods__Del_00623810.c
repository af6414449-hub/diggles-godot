
undefined4
CTclGlobalMethods__Del(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  BOOL BVar4;
  undefined4 *puVar5;
  undefined **ppuVar6;
  void *pvVar7;
  int *piVar8;
  int *extraout_ECX;
  int *extraout_ECX_00;
  int *extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 uVar9;
  int iVar10;
  undefined8 uVar11;
  char *pcVar12;
  int local_38;
  int local_28;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070bd5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if (*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6ca8) {
    FUN_006cebf4(&DAT_00ca6ca8,DAT_0076700c ^ (uint)&stack0xfffffffc);
    iVar2 = DAT_00783650;
    if (DAT_00ca6ca8 == -1) {
      iVar10 = DAT_00783650 * 0x40;
      DAT_00ca6cac = DAT_00783650;
      *(char **)(&DAT_0077368c + iVar10) = "TCL:CTclGlobalMethods::Del()";
      *(int *)(&DAT_00773650 + iVar10) = iVar2;
      DAT_00783650 = DAT_00783650 + 1;
      FUN_006cebaa(&DAT_00ca6ca8);
    }
  }
  iVar10 = DAT_00ca6cac;
  uVar9 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6cac * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar9;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar10 * 0x10];
  if (iVar2 == 0) {
    uVar11 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar10 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar10 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar10 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 1;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar3 = (int *)FUN_006ba810(0x19);
  piVar8 = piVar3 + 3;
  piVar3[2] = -1;
  *piVar3 = 0;
  *(undefined1 *)piVar8 = 0;
  piVar3[1] = 0x14;
  *piVar8 = 0x73696874;
  *(undefined1 *)(piVar3 + 4) = 0;
  piVar3[2] = 4;
  *piVar3 = 1;
  if (local_38 == 0) {
    iVar10 = 0;
    iVar2 = 1;
  }
  else {
    iVar10 = Tcl_GetAssocData(local_38,piVar8,0);
    iVar2 = *piVar3;
  }
  local_8._0_1_ = 3;
  *piVar3 = iVar2 + -1;
  if (iVar2 + -1 == 0) {
    FUN_006ba940();
  }
  local_8._0_1_ = 2;
  uVar1 = (undefined1)local_8;
  local_8._0_1_ = 2;
  if (iVar10 != 0) {
    if (param_3 == 1) {
      pvVar7 = *(void **)(iVar10 + 0xd0);
      if (pvVar7 != (void *)0x0) {
        BVar4 = IsBadReadPtr(pvVar7,0x10);
        if (((BVar4 == 0) && (*(int *)((int)pvVar7 + 8) == 0x616e4f62)) &&
           ((DAT_00768398 == '\0' || (*(int *)((int)pvVar7 + 0xdc) != 0)))) {
          pvVar7 = *(void **)(iVar10 + 0xd0);
          local_14 = extraout_ECX;
          goto LAB_00623a35;
        }
      }
      *(int *)(iVar10 + 0xd0) = iVar10;
      pcVar12 = "object already deleted";
LAB_00623b2f:
      piVar8 = (int *)0x0;
    }
    else {
      if (param_3 != 2) {
        local_8._0_1_ = uVar1;
        FUN_006bc8f0(1);
LAB_00623b27:
        pcVar12 = "unknown object";
        goto LAB_00623b2f;
      }
      puVar5 = (undefined4 *)FUN_004295e0(1);
      piVar8 = (int *)*puVar5;
      if (piVar8 != (int *)0x0) {
        *piVar8 = *piVar8 + 1;
      }
      local_8._0_1_ = 4;
      if (piVar8 == (int *)0x0) {
        ppuVar6 = &PTR_0071ce50;
      }
      else {
        ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar8,0);
      }
      FUN_006b8fb0(ppuVar6);
      local_8._0_1_ = 5;
      pvVar7 = (void *)FUN_006055d0(param_2,iVar10,&local_14);
      local_8._0_1_ = 6;
      if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
        FUN_006ba940();
        local_14 = extraout_ECX_00;
      }
      local_8._0_1_ = 2;
      if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 < 1)) {
        TclFreeObj(piVar8);
        local_14 = extraout_ECX_01;
      }
LAB_00623a35:
      if (pvVar7 == (void *)0x0) goto LAB_00623b27;
      if ((*(uint *)((int)pvVar7 + 0x3d0) & 0x40000000) == 0) {
        if (*(int *)((int)pvVar7 + 0x378) != *(int *)(DAT_00772400 + 100)) {
          FUN_005b28d0();
          iVar2 = FUN_005ad820();
          if (iVar2 != 0) {
            piVar8 = (int *)Tcl_NewIntObj(*(undefined4 *)((int)pvVar7 + 0xdc),extraout_ECX_02);
            *piVar8 = *piVar8 + 1;
            pcVar12 = "illegal del";
            goto LAB_00623b35;
          }
        }
        if (*(int *)((int)pvVar7 + 0xd4) == 0) {
          pcVar12 = "no user class";
        }
        else {
          BVar4 = IsBadReadPtr(pvVar7,0x10);
          if (((BVar4 == 0) && (*(int *)((int)pvVar7 + 8) == 0x616e4f62)) &&
             (((DAT_00768398 == '\0' || (*(int *)((int)pvVar7 + 0xdc) != 0)) &&
              (*(int *)((int)pvVar7 + 0x3e4) != 0)))) {
            FUN_005ed0b0();
          }
          if (*(int *)(*(int *)((int)pvVar7 + 0xd4) + 0x74) != 0) {
            *(undefined4 *)((int)pvVar7 + 0xd0) = 0;
            FUN_005d0a10();
            uVar9 = 0;
            goto LAB_00623b42;
          }
          pcVar12 = "no deletable class";
        }
        goto LAB_00623b2f;
      }
      piVar8 = (int *)Tcl_NewIntObj(*(undefined4 *)((int)pvVar7 + 0xdc),local_14);
      *piVar8 = *piVar8 + 1;
      pcVar12 = "illegal del (object is undeletable)";
    }
LAB_00623b35:
    FUN_006bc6a0(pcVar12,piVar8);
    uVar1 = (undefined1)local_8;
  }
  local_8._0_1_ = uVar1;
  uVar9 = 1;
LAB_00623b42:
  FUN_006bc0d0();
  local_8._0_1_ = 7;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_004297b0(0);
  if (local_28 != 0) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar9;
}

