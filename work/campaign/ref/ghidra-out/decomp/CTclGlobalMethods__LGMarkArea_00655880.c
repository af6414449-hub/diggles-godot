
void CTclGlobalMethods__LGMarkArea
               (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined8 uVar9;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070eadd;
  local_10 = ExceptionList;
  local_14 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7270) &&
     (FUN_006cebf4(&DAT_00ca7270,local_14), iVar3 = DAT_00783650, DAT_00ca7270 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca7274 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::LGMarkArea()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7270);
  }
  iVar6 = DAT_00ca7274;
  uVar1 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7274 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar1;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar9 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar9;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (param_3 < 5) {
    FUN_006bc8f0(4);
  }
  else {
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_20;
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_20 + 1;
    }
    piVar2 = (int *)*puVar7;
    if (piVar2 == (int *)0x0) {
      local_24 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_34);
      *piVar2 = *piVar2 + -1;
      local_24 = -(uint)(iVar3 != 1) & local_34;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_18 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_20;
      }
    }
    else {
      if (local_1c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_20 + 2;
    }
    piVar2 = (int *)*puVar7;
    if (piVar2 == (int *)0x0) {
      local_28 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_38);
      *piVar2 = *piVar2 + -1;
      local_28 = -(uint)(iVar3 != 1) & local_38;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_18 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_20;
      }
    }
    else {
      if (local_1c < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_20 + 3;
    }
    piVar2 = (int *)*puVar7;
    if (piVar2 == (int *)0x0) {
      local_2c = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_3c);
      *piVar2 = *piVar2 + -1;
      local_2c = -(uint)(iVar3 != 1) & local_3c;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    if (local_18 < 5) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_20;
      }
    }
    else {
      if (local_1c < 5) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_20 + 4;
    }
    piVar2 = (int *)*puVar7;
    if (piVar2 == (int *)0x0) {
      uVar8 = 0;
    }
    else {
      *piVar2 = *piVar2 + 1;
      iVar3 = Tcl_GetIntFromObj(0,piVar2,&local_40);
      *piVar2 = *piVar2 + -1;
      uVar8 = -(uint)(iVar3 != 1) & local_40;
      if (*piVar2 < 1) {
        TclFreeObj(piVar2);
      }
    }
    FUN_0058a820();
    uVar4 = *(uint *)(DAT_0077241c + 0x84);
    if ((int)*(uint *)(DAT_0077241c + 0x84) <= (int)local_24) {
      uVar4 = local_24;
    }
    local_24 = *(uint *)(DAT_0077241c + 0x88);
    if ((int)*(uint *)(DAT_0077241c + 0x88) <= (int)local_28) {
      local_24 = local_28;
    }
    uVar5 = *(uint *)(DAT_0077241c + 0x8c);
    if ((int)local_2c <= (int)*(uint *)(DAT_0077241c + 0x8c)) {
      uVar5 = local_2c;
    }
    local_28 = *(uint *)(DAT_0077241c + 0x90);
    if ((int)uVar8 <= (int)*(uint *)(DAT_0077241c + 0x90)) {
      local_28 = uVar8;
    }
    iVar3 = DAT_0077241c;
    local_30 = uVar4;
    local_2c = uVar5;
    if ((int)local_24 < (int)local_28) {
      do {
        uVar8 = uVar4;
        if ((int)uVar4 < (int)uVar5) {
          do {
            uVar4 = *(uint *)(iVar3 + 0x84);
            if ((int)*(uint *)(iVar3 + 0x84) <= (int)uVar8) {
              uVar4 = uVar8;
            }
            uVar5 = *(int *)(iVar3 + 0x8c) - 1;
            if ((int)uVar4 < *(int *)(iVar3 + 0x8c)) {
              uVar5 = uVar4;
            }
            uVar4 = *(uint *)(iVar3 + 0x88);
            if ((int)*(uint *)(iVar3 + 0x88) <= (int)local_24) {
              uVar4 = local_24;
            }
            if (*(int *)(iVar3 + 0x90) <= (int)uVar4) {
              uVar4 = *(int *)(iVar3 + 0x90) - 1;
            }
            iVar6 = (int)(*(int *)(iVar3 + 0x44) * uVar4 + uVar5) % *(int *)(iVar3 + 0x4c);
            if ((iVar6 < 0) || (*(int *)(iVar3 + 0x18) <= iVar6)) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar6 = *(int *)(iVar3 + 0x14);
              iVar3 = DAT_0077241c;
            }
            else {
              iVar6 = iVar6 * 0x7c + *(int *)(iVar3 + 0x14);
            }
            *(byte *)(iVar6 + 0x13) = *(byte *)(iVar6 + 0x13) | 1;
            uVar8 = uVar8 + 1;
            uVar5 = local_2c;
            uVar4 = local_30;
          } while ((int)uVar8 < (int)local_2c);
        }
        local_24 = local_24 + 1;
      } while ((int)local_24 < (int)local_28);
    }
  }
  local_8._0_1_ = 3;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004297b0(0);
  if (local_20 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

