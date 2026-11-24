
/* WARNING: Removing unreachable block (ram,0x00628041) */
/* WARNING: Removing unreachable block (ram,0x0062804a) */
/* WARNING: Removing unreachable block (ram,0x0062805f) */
/* WARNING: Removing unreachable block (ram,0x00628081) */
/* WARNING: Removing unreachable block (ram,0x0062809c) */
/* WARNING: Removing unreachable block (ram,0x006280a6) */
/* WARNING: Removing unreachable block (ram,0x006280c1) */
/* WARNING: Removing unreachable block (ram,0x006280ce) */
/* WARNING: Removing unreachable block (ram,0x006280e4) */
/* WARNING: Removing unreachable block (ram,0x006280eb) */
/* WARNING: Removing unreachable block (ram,0x006280f1) */
/* WARNING: Removing unreachable block (ram,0x006280f8) */
/* WARNING: Removing unreachable block (ram,0x006280fe) */
/* WARNING: Removing unreachable block (ram,0x00628106) */
/* WARNING: Removing unreachable block (ram,0x0062810e) */
/* WARNING: Removing unreachable block (ram,0x0062813e) */
/* WARNING: Removing unreachable block (ram,0x00628147) */
/* WARNING: Removing unreachable block (ram,0x00628151) */
/* WARNING: Removing unreachable block (ram,0x00628165) */
/* WARNING: Removing unreachable block (ram,0x0062815c) */
/* WARNING: Removing unreachable block (ram,0x0062816e) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int CTclGlobalMethods__CallMethodStatic
              (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  code *pcVar9;
  int *piVar10;
  undefined8 uVar11;
  int local_6c;
  int local_64;
  undefined4 *local_5c;
  uint local_58;
  int local_54;
  int *local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c25d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d10) &&
     (FUN_006cebf4(&DAT_00ca6d10,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca6d10 == -1)) {
    iVar6 = DAT_00783650 * 0x40;
    DAT_00ca6d14 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar6) = "TCL:CTclGlobalMethods::CallMethodStatic()";
    *(int *)(&DAT_00773650 + iVar6) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6d10);
  }
  iVar6 = DAT_00ca6d14;
  uVar7 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d14 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar7;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar6 * 0x10];
  if (iVar3 == 0) {
    uVar11 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar6 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar6 * 0x10) = uVar11;
  }
  (&DAT_00773654)[iVar6 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  iVar3 = (int)param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if (iVar3 < 3) {
    FUN_006bc8f0(2);
    iVar3 = 1;
    goto LAB_006281b2;
  }
  if (local_54 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_5c;
    if (local_58 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_58 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_5c + 1;
  }
  piVar10 = (int *)*puVar5;
  if (piVar10 != (int *)0x0) {
    *piVar10 = *piVar10 + 1;
  }
  local_24 = piVar10;
  if (local_54 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_5c;
    if (local_58 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_58 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_5c + 2;
  }
  piVar8 = (int *)*puVar5;
  if (piVar8 != (int *)0x0) {
    *piVar8 = *piVar8 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  local_28 = piVar8;
  if (piVar10 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
  }
  else {
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar10,0);
  }
  FUN_006b8fb0(ppuVar4);
  local_20 = DAT_00772478;
  cVar2 = FUN_006037d0(&local_18,&local_1c);
  if (cVar2 == '\0') {
    local_14 = (int *)0x0;
  }
  else {
    if ((int *)local_20[0x2007] <= local_1c) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    local_14 = *(int **)(local_20[0x2006] + (int)local_1c * 4);
  }
  local_8._0_1_ = 5;
  if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
    FUN_006ba940();
  }
  local_8._0_1_ = 4;
  if (local_14 == (int *)0x0) {
    if (local_54 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar5 = local_5c;
      if (local_58 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_58 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar5 = local_5c + 1;
    }
    piVar1 = (int *)*puVar5;
    if (piVar1 != (int *)0x0) {
      *piVar1 = *piVar1 + 1;
    }
    FUN_006bc6a0("unknown class",piVar1);
    param_3 = (int *)0x1;
  }
  else {
    if (piVar8 == (int *)0x0) {
      ppuVar4 = &PTR_0071ce50;
    }
    else {
      ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar8,0);
    }
    FUN_006b8fb0(ppuVar4);
    local_1c = (int *)FUN_00601d30(&local_20);
    local_8._0_1_ = 6;
    if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 4;
    if (local_1c == (int *)0xffffffff) {
      puVar5 = (undefined4 *)FUN_004295e0(2);
      piVar1 = (int *)*puVar5;
      if (piVar1 != (int *)0x0) {
        *piVar1 = *piVar1 + 1;
      }
      FUN_006bc6a0("unknown method",piVar1);
      param_3 = (int *)0x1;
    }
    else {
      if ((int *)local_14[0x1f] <= local_1c) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_18 = (int *)(local_14[0x1e] + (int)local_1c * 0x28);
      if (local_18[1] == 0) {
        local_14 = (int *)0x0;
      }
      else {
        iVar3 = Tcl_ListObjLength(0,local_18[1],&local_34);
        local_14 = local_34;
        if (iVar3 != 0) {
          local_14 = (int *)0x0;
        }
      }
      if ((int)param_3 + -3 < (int)local_14) {
        FUN_006bc8f0(local_14);
        param_3 = (int *)0x1;
      }
      else {
        local_8 = CONCAT31(local_8._1_3_,7);
        FUN_004297b0(local_14);
        param_3 = (int *)0x0;
        local_1c = (int *)0x0;
        if (0 < (int)local_14) {
          do {
            if (local_18[1] == 0) {
              piVar10 = (int *)0x0;
            }
            else {
              iVar3 = Tcl_ListObjIndex(0,local_18[1],param_3,&local_34);
              if (iVar3 == 0) {
                piVar10 = local_34;
                if (local_34 != (int *)0x0) {
                  *local_34 = *local_34 + 1;
                }
              }
              else {
                piVar10 = (int *)0x0;
              }
            }
            if (local_6c == 0) {
              piVar8 = (int *)0x0;
            }
            else {
              piVar8 = (int *)Tcl_ObjGetVar2(local_6c,piVar10,0,0);
              if (piVar8 != (int *)0x0) {
                *piVar8 = *piVar8 + 1;
              }
            }
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar1 = *(int **)((int)param_3 * 4);
            *(int **)((int)param_3 * 4) = piVar8;
            if (piVar8 != (int *)0x0) {
              *piVar8 = *piVar8 + 1;
            }
            if ((piVar1 != (int *)0x0) && (*piVar1 = *piVar1 + -1, *piVar1 < 1)) {
              TclFreeObj(piVar1);
            }
            pcVar9 = TclFreeObj_exref;
            if ((piVar8 != (int *)0x0) &&
               (*piVar8 = *piVar8 + -1, pcVar9 = TclFreeObj_exref, *piVar8 < 1)) {
              TclFreeObj(piVar8);
            }
            if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
              (*pcVar9)(piVar10);
            }
            iVar3 = (int)param_3;
            if ((local_18[1] == 0) ||
               (iVar6 = Tcl_ListObjIndex(0,local_18[1],param_3,&local_30), iVar6 != 0)) {
              param_3 = (int *)0x0;
            }
            else {
              param_3 = local_30;
              if (local_30 != (int *)0x0) {
                *local_30 = *local_30 + 1;
              }
            }
            piVar10 = param_3;
            local_8 = CONCAT31(local_8._1_3_,8);
            uVar7 = FUN_004295e0(iVar3 + 3);
            FUN_006bc9c0(&param_3,uVar7);
            if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
              TclFreeObj(piVar10);
            }
            param_3 = (int *)(iVar3 + 1);
          } while ((int)param_3 < (int)local_14);
        }
        piVar10 = local_18;
        piVar8 = (int *)0x0;
        param_3 = (int *)0x0;
        local_20 = (int *)0x0;
        local_2c = (int *)0x0;
        local_8 = CONCAT31(local_8._1_3_,9);
        cVar2 = FUN_00555b60(local_18 + 2);
        if (cVar2 == '\0') {
          piVar10 = (int *)piVar10[6];
          if (piVar10 != (int *)0x0) {
            *piVar10 = *piVar10 + 1;
          }
          FUN_006bc6a0(local_64 + 0xc,piVar10);
          param_3 = (int *)0x1;
          pcVar9 = TclFreeObj_exref;
        }
        else {
          piVar8 = (int *)Tcl_GetObjResult(local_6c);
          pcVar9 = TclFreeObj_exref;
          local_2c = piVar8;
          local_20 = piVar8;
          if (piVar8 != (int *)0x0) {
            *piVar8 = *piVar8 + 1;
            iVar3 = *piVar8;
            *piVar8 = iVar3;
            pcVar9 = TclFreeObj_exref;
            if (iVar3 < 1) {
              TclFreeObj(piVar8);
            }
          }
        }
        if (0 < (int)local_14) {
          iVar3 = 0;
          do {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            iVar6 = local_18[1];
            if (*local_1c == 0) {
              if ((iVar6 == 0) || (iVar6 = Tcl_ListObjIndex(0,iVar6,iVar3,&local_3c), iVar6 != 0)) {
                local_30 = (int *)0x0;
              }
              else {
                local_30 = local_3c;
                if (local_3c != (int *)0x0) {
                  *local_3c = *local_3c + 1;
                }
              }
              piVar10 = local_30;
              local_8._0_1_ = 0xb;
              if (local_30 == (int *)0x0) {
                ppuVar4 = &PTR_0071ce50;
              }
              else {
                ppuVar4 = (undefined **)Tcl_GetStringFromObj(local_30,0);
              }
              FUN_006b8fb0(ppuVar4);
              local_8._0_1_ = 0xc;
              FUN_006bca80(&local_34);
              local_8 = CONCAT31(local_8._1_3_,0xd);
              if ((local_34 != (int *)0x0) && (*local_34 = *local_34 + -1, *local_34 == 0)) {
                FUN_006ba940();
              }
              pcVar9 = TclFreeObj_exref;
              if ((piVar10 != (int *)0x0) &&
                 (*piVar10 = *piVar10 + -1, pcVar9 = TclFreeObj_exref, *piVar10 < 1)) {
                TclFreeObj(piVar10);
              }
            }
            else {
              if ((iVar6 == 0) || (iVar6 = Tcl_ListObjIndex(0,iVar6,iVar3,&local_38), iVar6 != 0)) {
                local_30 = (int *)0x0;
              }
              else {
                local_30 = local_38;
                if (local_38 != (int *)0x0) {
                  *local_38 = *local_38 + 1;
                }
              }
              piVar10 = local_30;
              local_8 = CONCAT31(local_8._1_3_,10);
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              FUN_006bc9c0(&local_30,local_1c);
              pcVar9 = TclFreeObj_exref;
              if ((piVar10 != (int *)0x0) &&
                 (*piVar10 = *piVar10 + -1, pcVar9 = TclFreeObj_exref, *piVar10 < 1)) {
                TclFreeObj(piVar10);
              }
            }
            local_1c = local_1c + 1;
            iVar3 = iVar3 + 1;
            piVar8 = local_20;
          } while (iVar3 < (int)local_14);
        }
        if ((piVar8 == (int *)0x0) || (local_6c == 0)) {
          if (piVar8 != (int *)0x0) goto LAB_0062801b;
        }
        else {
          Tcl_SetObjResult(local_6c,piVar8);
LAB_0062801b:
          *piVar8 = *piVar8 + -1;
          if (*piVar8 < 1) {
            (*pcVar9)(piVar8);
          }
        }
        local_8._0_1_ = 0xe;
        FUN_004297b0(0);
        piVar10 = local_24;
        piVar8 = local_28;
      }
    }
  }
  pcVar9 = TclFreeObj_exref;
  if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, pcVar9 = TclFreeObj_exref, *piVar8 < 1)) {
    TclFreeObj(piVar8);
  }
  iVar3 = (int)param_3;
  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
    (*pcVar9)(piVar10);
    iVar3 = (int)param_3;
  }
LAB_006281b2:
  local_8._0_1_ = 0xf;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x10);
  FUN_004297b0(0);
  if (local_5c != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return iVar3;
}

