
undefined4
CTclGlobalMethods__SMDefTempGroup
          (undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined **ppuVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  undefined4 uVar14;
  uint uVar15;
  int *piVar16;
  int *piVar17;
  bool bVar18;
  undefined8 uVar19;
  int *piVar20;
  int local_c4;
  int *local_a4;
  int *local_a0;
  int *local_9c;
  int *local_98;
  uint local_94;
  int *local_90;
  uint local_8c;
  int *local_88;
  int local_84;
  uint local_80;
  int *local_7c;
  uint local_78;
  int *local_74;
  uint local_70;
  int *local_6c;
  uint local_68;
  int *local_64;
  uint local_60;
  int *local_5c;
  int *local_58;
  int *local_54;
  int local_50;
  int *local_4c;
  int *local_48;
  int *local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int *local_30;
  uint local_2c;
  int *local_28;
  uint local_24;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070ee91;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7310) &&
     (FUN_006cebf4(&DAT_00ca7310,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00783650,
     DAT_00ca7310 == -1)) {
    iVar7 = DAT_00783650 * 0x40;
    DAT_00ca7314 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar7) = "TCL:CTclGlobalMethods::SMDefTempGroup()";
    *(int *)(&DAT_00773650 + iVar7) = iVar5;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7310);
  }
  iVar7 = DAT_00ca7314;
  uVar14 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7314 * 0x40);
  iVar5 = FUN_0043fcc0();
  *(undefined4 *)(iVar5 + *(int *)(iVar5 + 0x8000) * 4) = uVar14;
  *(int *)(iVar5 + 0x8000) = *(int *)(iVar5 + 0x8000) + 1;
  iVar5 = (&DAT_00773654)[iVar7 * 0x10];
  if (iVar5 == 0) {
    uVar19 = FUN_006bd180();
    iVar5 = (&DAT_00773654)[iVar7 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar7 * 0x10) = uVar19;
  }
  (&DAT_00773654)[iVar7 * 0x10] = iVar5 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == 3) {
    FUN_004298b0(3,param_4);
    if (local_18 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar12 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar12 = local_20;
      }
    }
    else {
      if (local_1c < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar12 = local_20 + 1;
    }
    piVar16 = (int *)*puVar12;
    if (piVar16 != (int *)0x0) {
      *piVar16 = *piVar16 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    if (piVar16 == (int *)0x0) {
      ppuVar6 = &PTR_0071ce50;
      piVar17 = (int *)0x0;
    }
    else {
      ppuVar6 = (undefined **)Tcl_GetStringFromObj(piVar16,0);
      piVar17 = piVar16;
    }
    FUN_006b8fb0(ppuVar6);
    if ((piVar17 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 < 1)) {
      TclFreeObj(piVar16);
    }
    if (local_18 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar12 = local_20;
      if (local_1c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar12 = local_20;
      }
    }
    else {
      if (local_1c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar12 = local_20 + 2;
    }
    piVar16 = (int *)*puVar12;
    if (piVar16 != (int *)0x0) {
      *piVar16 = *piVar16 + 1;
    }
    local_8 = CONCAT31(local_8._1_3_,6);
    local_a0 = piVar16;
    iVar5 = FUN_005f8080();
    local_34 = FUN_005f9f00(&local_44);
    if (local_34 == 0xffffffff) {
      if (local_18 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar12 = local_20;
        if (local_1c == 0) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          puVar12 = local_20;
        }
      }
      else {
        if (local_1c < 2) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        puVar12 = local_20 + 1;
      }
      piVar17 = (int *)*puVar12;
      if (piVar17 != (int *)0x0) {
        *piVar17 = *piVar17 + 1;
      }
      FUN_006bc6a0("Template Group redefinition",piVar17);
      uVar14 = 1;
    }
    else {
      local_38 = 0;
      while( true ) {
        if (piVar16 == (int *)0x0) {
          iVar7 = 0;
        }
        else {
          iVar8 = Tcl_ListObjLength(0,piVar16,&local_84);
          iVar7 = local_84;
          if (iVar8 != 0) {
            iVar7 = 0;
          }
        }
        uVar15 = local_34;
        if (iVar7 <= local_38) break;
        if ((piVar16 == (int *)0x0) ||
           (iVar7 = Tcl_ListObjIndex(0,piVar16,local_38,&local_a4), iVar7 != 0)) {
          local_30 = (int *)0x0;
        }
        else {
          local_30 = local_a4;
          if (local_a4 != (int *)0x0) {
            *local_a4 = *local_a4 + 1;
          }
        }
        piVar16 = local_30;
        local_48 = local_30;
        if ((local_30 == (int *)0x0) ||
           (iVar7 = Tcl_ListObjIndex(0,local_30,0,&local_4c), piVar17 = local_4c, iVar7 != 0)) {
          piVar17 = (int *)0x0;
LAB_0065b473:
          ppuVar6 = &PTR_0071ce50;
        }
        else {
          if (local_4c == (int *)0x0) goto LAB_0065b473;
          *local_4c = *local_4c + 1;
          ppuVar6 = (undefined **)Tcl_GetStringFromObj(local_4c,0);
        }
        pbVar13 = &DAT_00730e24;
        do {
          bVar2 = *(byte *)ppuVar6;
          bVar18 = bVar2 < *pbVar13;
          if (bVar2 != *pbVar13) {
LAB_0065b4a5:
            local_24 = -(uint)bVar18 | 1;
            goto LAB_0065b4ad;
          }
          if (bVar2 == 0) break;
          bVar2 = *(byte *)((int)ppuVar6 + 1);
          bVar18 = bVar2 < pbVar13[1];
          if (bVar2 != pbVar13[1]) goto LAB_0065b4a5;
          ppuVar6 = (undefined **)((int)ppuVar6 + 2);
          pbVar13 = pbVar13 + 2;
        } while (bVar2 != 0);
        local_24 = 0;
LAB_0065b4ad:
        if ((piVar17 != (int *)0x0) && (*piVar17 = *piVar17 + -1, *piVar17 < 1)) {
          TclFreeObj(piVar17);
        }
        if (local_24 == 0) {
          uVar15 = 1;
          while( true ) {
            local_2c = uVar15;
            if (piVar16 == (int *)0x0) {
              iVar7 = 0;
            }
            else {
              iVar8 = Tcl_ListObjLength(0,piVar16,&local_50);
              iVar7 = local_50;
              if (iVar8 != 0) {
                iVar7 = 0;
              }
            }
            if (iVar7 <= (int)uVar15) break;
            if ((piVar16 == (int *)0x0) ||
               (iVar7 = Tcl_ListObjIndex(0,piVar16,uVar15,&local_54), iVar7 != 0)) {
              local_58 = (int *)0x0;
            }
            else {
              local_58 = local_54;
              if (local_54 != (int *)0x0) {
                *local_54 = *local_54 + 1;
              }
            }
            piVar16 = local_58;
            local_8 = CONCAT31(local_8._1_3_,9);
            if (((local_58 == (int *)0x0) ||
                (iVar7 = Tcl_ListObjIndex(0,local_58,0,&local_5c), piVar17 = local_5c, iVar7 != 0))
               || (local_5c == (int *)0x0)) {
              local_40 = 0;
            }
            else {
              *local_5c = *local_5c + 1;
              iVar7 = Tcl_GetIntFromObj(0,local_5c,&local_60);
              *piVar17 = *piVar17 + -1;
              local_40 = -(uint)(iVar7 != 1) & local_60;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
              }
            }
            if (((piVar16 == (int *)0x0) ||
                (iVar7 = Tcl_ListObjIndex(0,piVar16,1,&local_64), piVar17 = local_64, iVar7 != 0))
               || (local_64 == (int *)0x0)) {
              local_24 = 0;
            }
            else {
              *local_64 = *local_64 + 1;
              iVar7 = Tcl_GetIntFromObj(0,local_64,&local_68);
              *piVar17 = *piVar17 + -1;
              local_24 = -(uint)(iVar7 != 1) & local_68;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
              }
            }
            if (((piVar16 == (int *)0x0) ||
                (iVar7 = Tcl_ListObjIndex(0,piVar16,2,&local_6c), piVar17 = local_6c, iVar7 != 0))
               || (local_6c == (int *)0x0)) {
              local_3c = 0;
            }
            else {
              *local_6c = *local_6c + 1;
              iVar7 = Tcl_GetIntFromObj(0,local_6c,&local_70);
              *piVar17 = *piVar17 + -1;
              local_3c = -(uint)(iVar7 != 1) & local_70;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
              }
            }
            if (((piVar16 == (int *)0x0) ||
                (iVar7 = Tcl_ListObjIndex(0,piVar16,3,&local_74), piVar17 = local_74, iVar7 != 0))
               || (local_74 == (int *)0x0)) {
              local_28 = (int *)0x0;
            }
            else {
              *local_74 = *local_74 + 1;
              iVar7 = Tcl_GetIntFromObj(0,local_74,&local_78);
              *piVar17 = *piVar17 + -1;
              local_28 = (int *)(-(uint)(iVar7 != 1) & local_78);
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
              }
            }
            if (((piVar16 == (int *)0x0) ||
                (iVar7 = Tcl_ListObjIndex(0,piVar16,4,&local_7c), piVar17 = local_7c, iVar7 != 0))
               || (local_7c == (int *)0x0)) {
              piVar9 = (int *)0x0;
            }
            else {
              *local_7c = *local_7c + 1;
              iVar7 = Tcl_GetIntFromObj(0,local_7c,&local_80);
              *piVar17 = *piVar17 + -1;
              local_14 = (int *)(-(uint)(iVar7 != 1) & local_80);
              piVar9 = local_14;
              if (*piVar17 < 1) {
                TclFreeObj(piVar17);
                piVar9 = local_14;
              }
            }
            uVar4 = local_24;
            uVar3 = local_34;
            uVar15 = local_3c;
            uVar10 = (int)piVar9 + local_3c;
            uVar11 = (int)local_28 + local_24;
            if (*(uint *)(iVar5 + 0x14) <= local_34) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            piVar17 = (int *)(uVar3 * 0x28 + 0xc + *(int *)(iVar5 + 0x10));
            local_28 = piVar17;
            FUN_0058fb10(1);
            piVar17 = (int *)piVar17[1];
            local_14 = (int *)((int)piVar17 - 1);
            if (piVar17 <= local_14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            piVar17 = local_14;
            puVar1 = (uint *)(*local_28 + (int)local_14 * 0x14);
            *puVar1 = uVar4;
            puVar1[1] = uVar15;
            puVar1[2] = uVar11;
            puVar1[3] = uVar10;
            if ((int *)local_28[1] <= local_14) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(uint *)(*local_28 + 0x10 + (int)piVar17 * 0x14) = local_40;
            if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 < 1)) {
              TclFreeObj(piVar16);
            }
            uVar15 = local_2c + 1;
            piVar16 = local_30;
          }
        }
        else {
          if (((piVar16 == (int *)0x0) ||
              (iVar7 = Tcl_ListObjIndex(0,piVar16,0,&local_88), piVar17 = local_88, iVar7 != 0)) ||
             (local_88 == (int *)0x0)) {
            local_2c = 0;
          }
          else {
            *local_88 = *local_88 + 1;
            iVar7 = Tcl_GetIntFromObj(0,local_88,&local_8c);
            *piVar17 = *piVar17 + -1;
            local_2c = -(uint)(iVar7 != 1) & local_8c;
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          if (((piVar16 == (int *)0x0) ||
              (iVar7 = Tcl_ListObjIndex(0,piVar16,1,&local_90), piVar17 = local_90, iVar7 != 0)) ||
             (local_90 == (int *)0x0)) {
            local_30 = (int *)0x0;
          }
          else {
            *local_90 = *local_90 + 1;
            iVar7 = Tcl_GetIntFromObj(0,local_90,&local_94);
            *piVar17 = *piVar17 + -1;
            local_30 = (int *)(-(uint)(iVar7 != 1) & local_94);
            if (*piVar17 < 1) {
              TclFreeObj(piVar17);
            }
          }
          if ((piVar16 == (int *)0x0) ||
             (iVar7 = Tcl_ListObjIndex(0,piVar16,2,&local_98), iVar7 != 0)) {
            local_14 = (int *)0x0;
          }
          else {
            local_14 = local_98;
            if (local_98 != (int *)0x0) {
              *local_98 = *local_98 + 1;
            }
          }
          piVar17 = local_14;
          local_8._0_1_ = 10;
          if (local_14 == (int *)0x0) {
            ppuVar6 = &PTR_0071ce50;
          }
          else {
            ppuVar6 = (undefined **)Tcl_GetStringFromObj(local_14,0);
          }
          FUN_006b8fb0(ppuVar6);
          local_8 = CONCAT31(local_8._1_3_,0xc);
          if ((piVar17 != (int *)0x0) && (*piVar17 = *piVar17 + -1, *piVar17 < 1)) {
            TclFreeObj(piVar17);
          }
          piVar17 = local_9c;
          if (local_9c != (int *)0x0) {
            *local_9c = *local_9c + 1;
          }
          piVar9 = local_9c;
          uVar15 = local_2c;
          piVar20 = local_30;
          if (*(uint *)(iVar5 + 0x14) <= local_34) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          FUN_005f9430(piVar9,uVar15,piVar20);
          local_8 = CONCAT31(local_8._1_3_,0xd);
          if ((piVar17 != (int *)0x0) && (*piVar17 = *piVar17 + -1, *piVar17 == 0)) {
            FUN_006ba940();
          }
        }
        if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 < 1)) {
          TclFreeObj(piVar16);
        }
        local_38 = local_38 + 1;
        piVar16 = local_a0;
      }
      if (*(uint *)(iVar5 + 0x14) <= local_34) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      FUN_005f9650();
      piVar17 = (int *)Tcl_NewIntObj(uVar15);
      *piVar17 = *piVar17 + 1;
      iVar5 = *piVar17;
      if (local_c4 != 0) {
        Tcl_SetObjResult(local_c4,piVar17);
        iVar5 = *piVar17;
      }
      *piVar17 = iVar5 + -1;
      if (iVar5 + -1 < 1) {
        TclFreeObj(piVar17);
      }
      uVar14 = 0;
    }
    if ((piVar16 != (int *)0x0) && (*piVar16 = *piVar16 + -1, *piVar16 < 1)) {
      TclFreeObj(piVar16);
    }
    local_8._0_1_ = 0xe;
    if ((local_44 != (int *)0x0) && (*local_44 = *local_44 + -1, *local_44 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0xf;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,0x10);
    FUN_004297b0(0);
    if (local_20 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  else {
    FUN_006bc8f0(2);
    uVar14 = 1;
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar14;
}

