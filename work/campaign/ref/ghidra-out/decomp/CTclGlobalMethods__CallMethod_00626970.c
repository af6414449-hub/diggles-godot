
/* WARNING: Removing unreachable block (ram,0x00627334) */
/* WARNING: Removing unreachable block (ram,0x0062733d) */
/* WARNING: Removing unreachable block (ram,0x00627352) */
/* WARNING: Removing unreachable block (ram,0x00627374) */
/* WARNING: Removing unreachable block (ram,0x0062738f) */
/* WARNING: Removing unreachable block (ram,0x00627399) */
/* WARNING: Removing unreachable block (ram,0x006273b4) */
/* WARNING: Removing unreachable block (ram,0x006273c1) */
/* WARNING: Removing unreachable block (ram,0x006273d7) */
/* WARNING: Removing unreachable block (ram,0x006273de) */
/* WARNING: Removing unreachable block (ram,0x006273e4) */
/* WARNING: Removing unreachable block (ram,0x006273eb) */
/* WARNING: Removing unreachable block (ram,0x006273f1) */
/* WARNING: Removing unreachable block (ram,0x006273f9) */
/* WARNING: Removing unreachable block (ram,0x00627401) */
/* WARNING: Removing unreachable block (ram,0x00627431) */
/* WARNING: Removing unreachable block (ram,0x0062743a) */
/* WARNING: Removing unreachable block (ram,0x00627444) */
/* WARNING: Removing unreachable block (ram,0x00627458) */
/* WARNING: Removing unreachable block (ram,0x0062744f) */
/* WARNING: Removing unreachable block (ram,0x00627461) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * CTclGlobalMethods__CallMethod
                (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  char *pcVar9;
  undefined4 extraout_ECX;
  int *piVar10;
  code *pcVar11;
  int *piVar12;
  bool bVar13;
  undefined8 uVar14;
  undefined4 uVar15;
  int **ppiVar16;
  int local_70;
  undefined4 *local_60;
  uint local_5c;
  int local_58;
  int *local_40;
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
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070c18d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6d00) &&
     (FUN_006cebf4(), iVar3 = DAT_00783650, DAT_00ca6d00 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca6d04 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::CallMethod()";
    *(int *)(&DAT_00773650 + iVar8) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa();
  }
  iVar8 = DAT_00ca6d04;
  uVar15 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6d04 * 0x40);
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
  FUN_006bc170();
  piVar12 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3);
  local_8._0_1_ = 2;
  if ((int)piVar12 < 3) {
    FUN_006bc8f0();
    piVar12 = (int *)0x1;
    goto LAB_006274a8;
  }
  if (local_58 < 3) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_60;
    if (local_5c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_5c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_60 + 2;
  }
  piVar6 = (int *)*puVar7;
  if (piVar6 != (int *)0x0) {
    *piVar6 = *piVar6 + 1;
  }
  local_8._0_1_ = 3;
  local_18 = piVar6;
  if (*(char *)(DAT_00772400 + 0x91) == '\0') {
LAB_00626b22:
    local_8._0_1_ = 3;
    FUN_006b8fb0();
    if (local_70 == 0) {
      local_28 = (int *)0x0;
    }
    else {
      local_28 = (int *)Tcl_GetAssocData(local_70,local_38 + 3);
    }
    local_8 = CONCAT31(local_8._1_3_,8);
    if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
      FUN_006ba940();
    }
    if (local_58 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_60;
      if (local_5c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_5c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_60 + 1;
    }
    piVar12 = (int *)*puVar7;
    if (piVar12 != (int *)0x0) {
      *piVar12 = *piVar12 + 1;
    }
    local_8._0_1_ = 9;
    local_2c = piVar12;
    if (piVar12 != (int *)0x0) {
      Tcl_GetStringFromObj(piVar12);
    }
    FUN_006b8fb0();
    local_8._0_1_ = 10;
    local_14 = FUN_006055d0(param_2,local_28);
    local_8._0_1_ = 0xb;
    if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 9;
    if (local_14 == 0) {
      if (local_58 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar7 = local_60;
        if (local_5c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
      }
      else {
        if (local_5c < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar7 = local_60 + 1;
      }
      piVar6 = (int *)*puVar7;
      if (piVar6 != (int *)0x0) {
        *piVar6 = *piVar6 + 1;
      }
      FUN_006bc6a0("invalid reference");
      param_3 = (int *)0x1;
    }
    else {
      local_24 = *(int **)(local_14 + 0xd4);
      if (local_18 != (int *)0x0) {
        Tcl_GetStringFromObj(local_18);
      }
      FUN_006b8fb0();
      piVar6 = (int *)FUN_00601d30();
      local_8._0_1_ = 0xc;
      local_34 = piVar6;
      if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
        FUN_006ba940();
      }
      local_8._0_1_ = 9;
      if (piVar6 == (int *)0xffffffff) {
        puVar7 = (undefined4 *)FUN_004295e0();
        piVar6 = (int *)*puVar7;
        if (piVar6 != (int *)0x0) {
          *piVar6 = *piVar6 + 1;
        }
        FUN_006bc6a0("unknown method");
        param_3 = (int *)0x1;
      }
      else {
        if ((int *)local_24[0x1f] <= piVar6) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        piVar10 = (int *)(local_24[0x1e] + (int)piVar6 * 0x28);
        local_28 = piVar10;
        if (((*(char *)(local_24[0x1e] + 0x21 + (int)piVar6 * 0x28) == '\0') &&
            ((char)piVar10[8] == '\0')) &&
           (*(int *)(local_14 + 0x378) != *(int *)(DAT_00772400 + 100))) {
          FUN_005b28d0();
          iVar3 = FUN_005ad820();
          if (iVar3 != 0) {
            local_38 = (int *)0x0;
            local_8 = CONCAT31(local_8._1_3_,0xd);
            if ((3 < (int)param_3) &&
               (local_38 = (int *)Tcl_NewListObj((int)param_3 + -3), local_38 != (int *)0x0)) {
              *local_38 = *local_38 + 1;
            }
            local_30 = *(int **)(local_14 + 0xdc);
            FUN_006abed0();
            if (local_38 != (int *)0x0) {
              Tcl_GetStringFromObj(local_38);
            }
            uVar15 = 0x626f1e;
            FUN_006b8fb0();
            local_8._0_1_ = 0xe;
            FUN_006ad390(extraout_ECX,local_30,local_34,&param_3,uVar15);
            local_8._0_1_ = 0xf;
            if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
              FUN_006ba940();
            }
            if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 < 1)) {
              TclFreeObj();
            }
            param_3 = (int *)0x0;
            goto LAB_0062746f;
          }
        }
        local_24 = piVar10 + 1;
        local_20 = (int *)FUN_006bb9d0();
        if ((int)param_3 + -3 < (int)local_20) {
          FUN_006bc8f0();
          param_3 = (int *)0x1;
        }
        else {
          local_8 = CONCAT31(local_8._1_3_,0x10);
          FUN_004297b0();
          param_3 = (int *)0x0;
          local_1c = (int *)0x0;
          if (0 < (int)local_20) {
            do {
              if ((*local_24 == 0) || (iVar3 = Tcl_ListObjIndex(0,*local_24,param_3), iVar3 != 0)) {
                local_34 = (int *)0x0;
              }
              else {
                local_34 = local_38;
                if (local_38 != (int *)0x0) {
                  *local_38 = *local_38 + 1;
                }
              }
              piVar12 = local_34;
              local_8 = CONCAT31(local_8._1_3_,0x11);
              piVar6 = (int *)FUN_005c9cc0();
              if (*piVar6 == 0) {
                piVar6 = (int *)0x0;
              }
              else {
                piVar6 = (int *)Tcl_ObjGetVar2(*piVar6,piVar12,0);
                if (piVar6 != (int *)0x0) {
                  *piVar6 = *piVar6 + 1;
                }
              }
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar10 = *(int **)((int)param_3 * 4);
              *(int **)((int)param_3 * 4) = piVar6;
              if (piVar6 != (int *)0x0) {
                *piVar6 = *piVar6 + 1;
              }
              if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
                TclFreeObj();
              }
              pcVar11 = TclFreeObj_exref;
              if ((piVar6 != (int *)0x0) &&
                 (*piVar6 = *piVar6 + -1, pcVar11 = TclFreeObj_exref, *piVar6 < 1)) {
                TclFreeObj();
              }
              if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
                (*pcVar11)();
              }
              iVar3 = (int)param_3;
              if ((*local_24 == 0) || (iVar8 = Tcl_ListObjIndex(0,*local_24,param_3), iVar8 != 0)) {
                param_3 = (int *)0x0;
              }
              else {
                param_3 = local_30;
                if (local_30 != (int *)0x0) {
                  *local_30 = *local_30 + 1;
                }
              }
              piVar12 = param_3;
              local_8 = CONCAT31(local_8._1_3_,0x12);
              FUN_004295e0();
              puVar7 = &param_3;
              FUN_005c9cc0(puVar7);
              FUN_006bc9c0(puVar7);
              if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
                TclFreeObj();
              }
              param_3 = (int *)(iVar3 + 1);
              piVar10 = local_28;
            } while ((int)param_3 < (int)local_20);
          }
          piVar12 = (int *)0x0;
          param_3 = (int *)0x0;
          local_28 = (int *)0x0;
          local_30 = (int *)0x0;
          local_8._0_1_ = 0x13;
          FUN_005c9cc0();
          cVar2 = FUN_00555b60();
          if (cVar2 == '\0') {
            piVar6 = (int *)piVar10[6];
            if (piVar6 != (int *)0x0) {
              *piVar6 = *piVar6 + 1;
            }
            local_8._0_1_ = 0x14;
            param_3 = (int *)&stack0xffffff80;
            iVar3 = FUN_005c9cc0();
            local_8._0_1_ = 0x13;
            FUN_006bc6a0(*(int *)(iVar3 + 8) + 0xc);
            param_3 = (int *)0x1;
          }
          else {
            FUN_005c9cc0();
            piVar12 = (int *)Tcl_GetObjResult();
            local_30 = piVar12;
            local_28 = piVar12;
            if (piVar12 != (int *)0x0) {
              *piVar12 = *piVar12 + 1;
              iVar3 = *piVar12;
              *piVar12 = iVar3;
              if (iVar3 < 1) {
                TclFreeObj();
              }
            }
          }
          if (0 < (int)local_20) {
            iVar3 = 0;
            do {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar8 = *local_24;
              if (*local_1c == 0) {
                if ((iVar8 == 0) || (iVar8 = Tcl_ListObjIndex(0,iVar8,iVar3), iVar8 != 0)) {
                  local_34 = (int *)0x0;
                }
                else {
                  local_34 = local_40;
                  if (local_40 != (int *)0x0) {
                    *local_40 = *local_40 + 1;
                  }
                }
                piVar12 = local_34;
                local_8._0_1_ = 0x16;
                if (local_34 != (int *)0x0) {
                  Tcl_GetStringFromObj(local_34);
                }
                FUN_006b8fb0();
                local_8._0_1_ = 0x17;
                FUN_005c9cc0();
                FUN_006bca80();
                local_8._0_1_ = 0x18;
                if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 == 0)) {
                  FUN_006ba940();
                }
              }
              else {
                if ((iVar8 == 0) || (iVar8 = Tcl_ListObjIndex(0,iVar8,iVar3), iVar8 != 0)) {
                  local_34 = (int *)0x0;
                }
                else {
                  local_34 = local_3c;
                  if (local_3c != (int *)0x0) {
                    *local_3c = *local_3c + 1;
                  }
                }
                piVar12 = local_34;
                local_8._0_1_ = 0x15;
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                ppiVar16 = &local_34;
                FUN_005c9cc0(ppiVar16);
                FUN_006bc9c0(ppiVar16);
              }
              if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
                TclFreeObj();
              }
              local_1c = local_1c + 1;
              iVar3 = iVar3 + 1;
              piVar12 = local_28;
            } while (iVar3 < (int)local_20);
          }
          if ((piVar12 == (int *)0x0) || (local_70 == 0)) {
            if (piVar12 != (int *)0x0) goto LAB_0062730a;
          }
          else {
            Tcl_SetObjResult(local_70);
LAB_0062730a:
            *piVar12 = *piVar12 + -1;
            if (*piVar12 < 1) {
              TclFreeObj();
            }
          }
          local_8._0_1_ = 0x19;
          FUN_004297b0();
          piVar12 = local_2c;
        }
      }
    }
LAB_0062746f:
    pcVar11 = TclFreeObj_exref;
    piVar6 = local_18;
    if ((piVar12 != (int *)0x0) &&
       (*piVar12 = *piVar12 + -1, pcVar11 = TclFreeObj_exref, *piVar12 < 1)) {
      TclFreeObj();
      piVar6 = local_18;
    }
  }
  else {
    if (piVar6 != (int *)0x0) {
      Tcl_GetStringFromObj(piVar6);
    }
    FUN_006b8fb0();
    piVar12 = local_24;
    local_8 = CONCAT31(local_8._1_3_,4);
    pcVar9 = "Editor_Set_Info";
    pbVar4 = (byte *)(local_24 + 3);
    do {
      bVar1 = *pbVar4;
      bVar13 = bVar1 < (byte)*pcVar9;
      if (bVar1 != *pcVar9) {
LAB_00626b01:
        uVar5 = -(uint)bVar13 | 1;
        goto LAB_00626b06;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar4[1];
      bVar13 = bVar1 < ((byte *)pcVar9)[1];
      if (bVar1 != ((byte *)pcVar9)[1]) goto LAB_00626b01;
      pbVar4 = pbVar4 + 2;
      pcVar9 = (char *)((byte *)pcVar9 + 2);
    } while (bVar1 != 0);
    uVar5 = 0;
LAB_00626b06:
    if (uVar5 != 0) {
      local_8._0_1_ = 7;
      if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 == 0)) {
        FUN_006ba940();
      }
      goto LAB_00626b22;
    }
    if ((int)param_3 < 4) {
      FUN_006bc8f0();
      param_3 = (int *)0x1;
    }
    else {
      puVar7 = (undefined4 *)FUN_004295e0();
      local_20 = (int *)*puVar7;
      if (local_20 != (int *)0x0) {
        *local_20 = *local_20 + 1;
      }
      local_28 = (int *)FUN_004295e0();
      param_3 = (int *)FUN_006baee0();
      local_2c = DAT_0077244c;
      if ((int)param_3 < 0x10000) {
        if ((-1 < (int)param_3) && ((int)param_3 < DAT_0077244c[0x109])) {
          if ((int *)DAT_0077244c[0x109] <= param_3) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar3 = (int)param_3 * 0x2c;
          param_3 = (int *)*local_28;
          piVar10 = *(int **)(iVar3 + 0x24 + local_2c[0x108]);
          *(int **)(iVar3 + 0x24 + local_2c[0x108]) = param_3;
          piVar12 = local_24;
          goto LAB_00626c34;
        }
      }
      else {
        param_3 = param_3 + -0x4000;
        if ((int)param_3 < DAT_0077244c[0x10b]) {
          if ((int *)DAT_0077244c[0x10b] <= param_3) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar3 = (int)param_3 * 0x2c;
          param_3 = (int *)*local_28;
          piVar10 = *(int **)(iVar3 + 0x24 + local_2c[0x10a]);
          *(int **)(iVar3 + 0x24 + local_2c[0x10a]) = param_3;
          piVar6 = local_18;
LAB_00626c34:
          if (param_3 != (int *)0x0) {
            *param_3 = *param_3 + 1;
          }
          if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
            TclFreeObj();
          }
        }
      }
      FUN_006bad60();
      param_3 = (int *)0x0;
    }
    local_8._0_1_ = 6;
    pcVar11 = TclFreeObj_exref;
    if ((piVar12 != (int *)0x0) &&
       (*piVar12 = *piVar12 + -1, pcVar11 = TclFreeObj_exref, *piVar12 == 0)) {
      FUN_006ba940();
      pcVar11 = TclFreeObj_exref;
    }
  }
  piVar12 = param_3;
  if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
    (*pcVar11)();
    piVar12 = param_3;
  }
LAB_006274a8:
  local_8._0_1_ = 0x1a;
  FUN_004297b0();
  local_8 = CONCAT31(local_8._1_3_,0x1b);
  FUN_004297b0();
  if (local_60 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return piVar12;
}

