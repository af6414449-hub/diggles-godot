
undefined4
CTclClassDefMethods__SetClassAnimSet
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined **ppuVar8;
  int *piVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  undefined8 local_6c;
  uint local_64;
  undefined4 *local_60;
  uint local_5c;
  int local_58;
  int *local_54;
  undefined4 *local_50;
  int *local_4c;
  int *local_48;
  int *local_44;
  int local_40;
  int *local_3c;
  int *local_38;
  int local_34;
  uint local_30;
  int *local_2c;
  int *local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070aa5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6bd8) &&
     (FUN_006cebf4(&DAT_00ca6bd8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca6bd8 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca6bdc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclClassDefMethods::SetClassAnimSet()";
    *(int *)(&DAT_00773650 + iVar7) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6bd8);
  }
  iVar7 = DAT_00ca6bdc;
  local_50 = &DAT_00ca6bdc;
  uVar11 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6bdc * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar11;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar4 == 0) {
    uVar12 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar12;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  local_24 = DAT_00772440;
  if (*(int *)(DAT_00772440 + 4) == 0) {
    FUN_006bc6a0("no class defined.",0);
    uVar11 = 1;
  }
  else if (param_3 == 3) {
    if (local_58 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_60;
      if (local_5c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_60;
      }
    }
    else {
      if (local_5c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_60 + 1;
    }
    piVar2 = (int *)*puVar5;
    if (piVar2 == (int *)0x0) {
      uVar10 = 0;
      local_14 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar4 = Tcl_GetIntFromObj(0,piVar2,&local_30);
      *piVar2 = *piVar2 + -1;
      uVar10 = -(uint)(iVar4 != 1) & local_30;
      local_14 = uVar10;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (*(int *)(*(int *)(local_24 + 4) + 0xce0) <= (int)uVar10) {
      FUN_00603df0(uVar10 + 1);
    }
    if (local_58 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_60;
      if (local_5c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar5 = local_60;
      }
    }
    else {
      if (local_5c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_60 + 2;
    }
    local_54 = (int *)*puVar5;
    if (local_54 != (int *)0x0) {
      *local_54 = *local_54 + 1;
    }
    iVar4 = 0;
    local_2c = local_54;
    while( true ) {
      local_18 = iVar4;
      if (local_2c == (int *)0x0) {
        iVar7 = 0;
      }
      else {
        iVar6 = Tcl_ListObjLength(0,local_2c,&local_34);
        iVar7 = local_34;
        if (iVar6 != 0) {
          iVar7 = 0;
        }
      }
      if (iVar7 <= iVar4) break;
      if ((local_2c == (int *)0x0) ||
         (iVar7 = Tcl_ListObjIndex(0,local_2c,iVar4,&local_38), iVar7 != 0)) {
        local_3c = (int *)0x0;
      }
      else {
        local_3c = local_38;
        if (local_38 != (int *)0x0) {
          *local_38 = *local_38 + 1;
        }
      }
      piVar2 = local_3c;
      if (local_3c != (int *)0x0) {
        iVar7 = Tcl_ListObjLength(0,local_3c,&local_40);
        if ((iVar7 == 0) && (local_40 == 2)) {
          iVar4 = Tcl_ListObjIndex(0,piVar2,1,&local_44);
          if (iVar4 == 0) {
            local_28 = local_44;
            if (local_44 != (int *)0x0) {
              *local_44 = *local_44 + 1;
            }
          }
          else {
            local_28 = (int *)0x0;
          }
          piVar3 = local_28;
          local_8._0_1_ = 5;
          if (local_28 == (int *)0x0) {
            ppuVar8 = &PTR_0071ce50;
          }
          else {
            ppuVar8 = (undefined **)Tcl_GetStringFromObj(local_28,0);
          }
          FUN_006b8fb0(ppuVar8);
          local_8._0_1_ = 6;
          FUN_00460fc0(&local_20,&local_6c,&local_64,(int)&local_6c + 4);
          local_8 = CONCAT31(local_8._1_3_,7);
          if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
            FUN_006ba940();
          }
          if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
            TclFreeObj(piVar3);
          }
          local_64 = uVar10;
          iVar4 = Tcl_ListObjIndex(0,piVar2,0,&local_48);
          if (iVar4 == 0) {
            local_4c = local_48;
            if (local_48 != (int *)0x0) {
              *local_48 = *local_48 + 1;
            }
          }
          else {
            local_4c = (int *)0x0;
          }
          piVar3 = local_4c;
          local_8._0_1_ = 8;
          if (local_4c == (int *)0x0) {
            ppuVar8 = &PTR_0071ce50;
          }
          else {
            ppuVar8 = (undefined **)Tcl_GetStringFromObj(local_4c,0);
          }
          FUN_006b8fb0(ppuVar8);
          local_8 = CONCAT31(local_8._1_3_,9);
          iVar4 = *(int *)(local_24 + 4);
          if (*(uint *)(iVar4 + 0xce0) <= local_14) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar10 = 0;
          piVar9 = local_1c + 3;
          cVar1 = (char)*piVar9;
          while (cVar1 != '\0') {
            uVar10 = uVar10 * 9 + (int)cVar1;
            piVar9 = (int *)((int)piVar9 + 1);
            cVar1 = *(char *)piVar9;
          }
          local_28 = (int *)(local_14 * 0x100 + *(int *)(iVar4 + 0xcdc) + (uVar10 & 0x1f) * 8);
          uVar10 = FUN_00603a60(&local_1c);
          if ((uint)local_28[1] <= uVar10) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar4 = *local_28;
          *(undefined8 *)(iVar4 + 4 + uVar10 * 0x10) = local_6c;
          *(uint *)(iVar4 + 0xc + uVar10 * 0x10) = local_14;
          local_8 = CONCAT31(local_8._1_3_,10);
          if ((local_1c != (int *)0x0) && (*local_1c = *local_1c + -1, *local_1c == 0)) {
            FUN_006ba940();
          }
          uVar10 = local_14;
          iVar4 = local_18;
          if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 < 1)) {
            TclFreeObj(piVar3);
            uVar10 = local_14;
            iVar4 = local_18;
          }
        }
        *piVar2 = *piVar2 + -1;
        if (*piVar2 < 1) {
          TclFreeObj(piVar2);
        }
      }
      iVar4 = iVar4 + 1;
    }
    uVar11 = 0;
    if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c < 1)) {
      TclFreeObj(local_2c);
    }
  }
  else {
    FUN_006bc8f0(1);
    uVar11 = 1;
  }
  local_8._0_1_ = 0xb;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xc);
  FUN_004297b0(0);
  if (local_60 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar11;
}

