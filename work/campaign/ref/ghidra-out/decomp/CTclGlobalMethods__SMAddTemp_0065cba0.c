
undefined4
CTclGlobalMethods__SMAddTemp(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined **ppuVar5;
  uint uVar6;
  undefined4 *puVar7;
  byte *pbVar8;
  float fVar9;
  int *piVar10;
  undefined4 extraout_ECX;
  int iVar11;
  uint uVar12;
  float fVar13;
  code *pcVar14;
  undefined4 uVar15;
  uint uVar16;
  char *pcVar17;
  bool bVar18;
  undefined8 uVar19;
  int **ppiVar20;
  int *piVar21;
  double local_d8;
  undefined4 *local_d0;
  double local_cc;
  double local_c4;
  int *local_bc;
  uint local_b8;
  uint local_b4;
  int *local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int *local_a0;
  int *local_9c;
  uint local_98;
  int *local_94;
  int *local_90;
  uint local_8c;
  int *local_88;
  int *local_84;
  uint local_80;
  int *local_7c;
  int *local_78;
  int local_74;
  uint local_70;
  int local_6c;
  int *local_5c;
  int *local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  int *local_48;
  int *local_44;
  int *local_40;
  int *local_3c;
  int *local_38;
  int *local_34;
  float local_30;
  int local_2c;
  uint local_28;
  int local_24;
  undefined4 *local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070efd6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7350) &&
     (FUN_006cebf4(&DAT_00ca7350,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca7350 == -1)) {
    iVar11 = DAT_00783650 * 0x40;
    DAT_00ca7354 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar11) = "TCL:CTclGlobalMethods::SMAddTemp()";
    *(int *)(&DAT_00773650 + iVar11) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7350);
  }
  iVar11 = DAT_00ca7354;
  local_d0 = &DAT_00ca7354;
  uVar15 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7354 * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar15;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar11 * 0x10];
  if (iVar4 == 0) {
    uVar19 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar11 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar11 * 0x10) = uVar19;
  }
  (&DAT_00773654)[iVar11 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if ((int)param_3 < 2) {
    FUN_006bc8f0(1);
    uVar15 = 1;
  }
  else {
    FUN_004298b0(param_3,param_4);
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
    piVar10 = (int *)*puVar7;
    if (piVar10 != (int *)0x0) {
      *piVar10 = *piVar10 + 1;
    }
    local_8._0_1_ = 3;
    local_5c = piVar10;
    if (piVar10 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
      piVar21 = (int *)0x0;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar10,0);
      piVar21 = piVar10;
    }
    FUN_006b8fb0(ppuVar5);
    local_8 = CONCAT31(local_8._1_3_,5);
    if ((piVar21 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
      TclFreeObj(piVar10);
    }
    uVar16 = 0;
    uVar12 = 0;
    if (2 < (int)param_3) {
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
      piVar10 = (int *)*puVar7;
      if (piVar10 == (int *)0x0) {
        uVar16 = 0;
      }
      else {
        *piVar10 = *piVar10 + 1;
        iVar4 = Tcl_GetIntFromObj(0,piVar10,&local_3c);
        *piVar10 = *piVar10 + -1;
        uVar16 = -(uint)(iVar4 != 1) & (uint)local_3c;
        if (*piVar10 < 1) {
          TclFreeObj(piVar10);
        }
      }
    }
    if (3 < (int)param_3) {
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
      piVar10 = (int *)*puVar7;
      if (piVar10 == (int *)0x0) {
        uVar12 = 0;
      }
      else {
        *piVar10 = *piVar10 + 1;
        iVar4 = Tcl_GetIntFromObj(0,piVar10,&local_3c);
        *piVar10 = *piVar10 + -1;
        uVar12 = -(uint)(iVar4 != 1) & (uint)local_3c;
        if (*piVar10 < 1) {
          TclFreeObj(piVar10);
        }
      }
    }
    iVar4 = FUN_005f8080();
    local_24 = iVar4;
    local_28 = FUN_005f91e0(&local_58);
    if (local_28 == 0xffffffff) {
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
      piVar10 = (int *)*puVar7;
      if (piVar10 != (int *)0x0) {
        *piVar10 = *piVar10 + 1;
      }
      FUN_006bc6a0("Unique Template redefinition",piVar10);
      uVar15 = 1;
    }
    else {
      if (*(uint *)(iVar4 + 0xc) <= local_28) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      uVar12 = uVar12 + 1;
      local_2c = local_28 * 100;
      iVar11 = *(int *)(iVar4 + 8) + local_2c;
      uVar6 = uVar16;
      if ((int)uVar12 <= (int)uVar16) {
        uVar6 = uVar12;
      }
      if ((int)uVar16 <= (int)uVar12) {
        uVar16 = uVar12;
      }
      *(uint *)(iVar11 + 0x20) = uVar6;
      *(uint *)(iVar11 + 0x24) = uVar16;
      if ((4 < (int)param_3) && (local_14 = (int *)&DAT_00000004, 5 < (int)param_3)) {
        do {
          puVar7 = (undefined4 *)FUN_004295e0(local_14);
          piVar10 = (int *)*puVar7;
          if (piVar10 == (int *)0x0) {
LAB_0065d102:
            piVar21 = local_14;
            puVar7 = (undefined4 *)FUN_004295e0(local_14);
            piVar10 = (int *)*puVar7;
            if (piVar10 != (int *)0x0) {
              *piVar10 = *piVar10 + 1;
              pcVar17 = "-mindist";
              pbVar8 = (byte *)Tcl_GetStringFromObj(piVar10,0);
              do {
                bVar1 = *pbVar8;
                bVar18 = bVar1 < (byte)*pcVar17;
                if (bVar1 != *pcVar17) {
LAB_0065d150:
                  uVar12 = -(uint)bVar18 | 1;
                  goto LAB_0065d155;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar8[1];
                bVar18 = bVar1 < ((byte *)pcVar17)[1];
                if (bVar1 != ((byte *)pcVar17)[1]) goto LAB_0065d150;
                pbVar8 = pbVar8 + 2;
                pcVar17 = (char *)((byte *)pcVar17 + 2);
              } while (bVar1 != 0);
              uVar12 = 0;
LAB_0065d155:
              *piVar10 = *piVar10 + -1;
              if (*piVar10 < 1) {
                TclFreeObj(piVar10);
              }
              piVar21 = local_14;
              if (uVar12 == 0) {
                piVar21 = (int *)((int)local_14 + 1);
                puVar7 = (undefined4 *)FUN_004295e0(piVar21);
                piVar10 = (int *)*puVar7;
                if (piVar10 != (int *)0x0) {
                  *piVar10 = *piVar10 + 1;
                }
                local_8._0_1_ = 0xe;
                local_34 = piVar10;
                if (piVar10 == (int *)0x0) {
                  ppuVar5 = &PTR_0071ce50;
                }
                else {
                  ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar10,0);
                }
                FUN_006b8fb0(ppuVar5);
                local_8 = CONCAT31(local_8._1_3_,0x10);
                if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
                  TclFreeObj(piVar10);
                }
                puVar7 = (undefined4 *)FUN_004295e0((undefined1 *)((int)local_14 + 2));
                piVar10 = (int *)*puVar7;
                if (piVar10 == (int *)0x0) {
                  local_38 = (int *)0x0;
                }
                else {
                  *piVar10 = *piVar10 + 1;
                  iVar4 = Tcl_GetDoubleFromObj(0,piVar10,&local_d8);
                  if (iVar4 == 1) {
                    local_38 = (int *)0x0;
                  }
                  else {
                    local_38 = (int *)(float)local_d8;
                  }
                  *piVar10 = *piVar10 + -1;
                  if (*piVar10 < 1) {
                    TclFreeObj(piVar10);
                  }
                }
                iVar4 = local_24;
                iVar11 = FUN_005f93d0(&local_48);
                if (iVar11 == -1) {
                  puVar7 = (undefined4 *)FUN_004295e0(piVar21);
                  piVar10 = (int *)*puVar7;
                  if (piVar10 != (int *)0x0) {
                    *piVar10 = *piVar10 + 1;
                  }
                  FUN_006bc6a0("Unique Template not defined",piVar10);
                }
                if (*(uint *)(iVar4 + 0xc) <= local_28) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                iVar4 = *(int *)(iVar4 + 8) + local_2c;
                *(int **)(iVar4 + 0x28) = local_38;
                *(int *)(iVar4 + 0x2c) = iVar11;
                local_8._0_1_ = 0x11;
                local_14 = piVar21;
                if ((local_48 != (int *)0x0) && (*local_48 = *local_48 + -1, *local_48 == 0)) {
                  FUN_006ba940();
                }
                local_8 = CONCAT31(local_8._1_3_,5);
                goto LAB_0065de3d;
              }
            }
            puVar7 = (undefined4 *)FUN_004295e0(piVar21);
            piVar10 = (int *)*puVar7;
            if (piVar10 != (int *)0x0) {
              *piVar10 = *piVar10 + 1;
              pcVar17 = "-digconnect";
              pbVar8 = (byte *)Tcl_GetStringFromObj(piVar10,0);
              do {
                bVar1 = *pbVar8;
                bVar18 = bVar1 < (byte)*pcVar17;
                if (bVar1 != *pcVar17) {
LAB_0065d2f0:
                  uVar12 = -(uint)bVar18 | 1;
                  goto LAB_0065d2f5;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar8[1];
                bVar18 = bVar1 < ((byte *)pcVar17)[1];
                if (bVar1 != ((byte *)pcVar17)[1]) goto LAB_0065d2f0;
                pbVar8 = pbVar8 + 2;
                pcVar17 = (char *)((byte *)pcVar17 + 2);
              } while (bVar1 != 0);
              uVar12 = 0;
LAB_0065d2f5:
              *piVar10 = *piVar10 + -1;
              if (*piVar10 < 1) {
                TclFreeObj(piVar10);
              }
              if (uVar12 == 0) {
                local_34 = (int *)((int)piVar21 + 1);
                puVar7 = (undefined4 *)FUN_004295e0(local_34);
                piVar10 = (int *)*puVar7;
                if (piVar10 == (int *)0x0) {
                  uVar12 = 0;
                }
                else {
                  *piVar10 = *piVar10 + 1;
                  iVar4 = Tcl_GetIntFromObj(0,piVar10,&local_b8);
                  *piVar10 = *piVar10 + -1;
                  uVar12 = -(uint)(iVar4 != 1) & local_b8;
                  if (*piVar10 < 1) {
                    TclFreeObj(piVar10);
                  }
                }
                puVar7 = (undefined4 *)FUN_004295e0((undefined1 *)((int)local_14 + 2));
                piVar10 = (int *)*puVar7;
                if (piVar10 == (int *)0x0) {
                  uVar16 = 0;
                }
                else {
                  *piVar10 = *piVar10 + 1;
                  iVar4 = Tcl_GetIntFromObj(0,piVar10,&local_70);
                  *piVar10 = *piVar10 + -1;
                  uVar16 = -(uint)(iVar4 != 1) & local_70;
                  if (*piVar10 < 1) {
                    TclFreeObj(piVar10);
                  }
                }
                local_14 = local_34;
                if (*(uint *)(local_24 + 0xc) <= local_28) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                iVar4 = local_24;
                *(uint *)(*(int *)(local_24 + 8) + 0x38 + local_2c) = uVar16;
                if (*(uint *)(local_24 + 0xc) <= local_28) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                iVar11 = *(int *)(iVar4 + 8);
                if (*(int *)(iVar11 + 0x3c + local_2c) != -1) {
                  if (*(uint *)(iVar4 + 0xc) <= local_28) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    iVar11 = *(int *)(iVar4 + 8);
                  }
                  uVar16 = *(uint *)(iVar11 + 0x3c + local_2c);
                  if (*(uint *)(iVar4 + 0x14) <= uVar16) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  *(uint *)(*(int *)(iVar4 + 0x10) + 0x24 + uVar16 * 0x28) = uVar12;
                }
                goto LAB_0065de3d;
              }
            }
            puVar7 = (undefined4 *)FUN_004295e0(piVar21);
            piVar10 = (int *)*puVar7;
            if (piVar10 != (int *)0x0) {
              *piVar10 = *piVar10 + 1;
              pcVar17 = "-connect";
              pbVar8 = (byte *)Tcl_GetStringFromObj(piVar10,0);
              do {
                bVar1 = *pbVar8;
                bVar18 = bVar1 < (byte)*pcVar17;
                if (bVar1 != *pcVar17) {
LAB_0065d482:
                  uVar12 = -(uint)bVar18 | 1;
                  goto LAB_0065d487;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar8[1];
                bVar18 = bVar1 < ((byte *)pcVar17)[1];
                if (bVar1 != ((byte *)pcVar17)[1]) goto LAB_0065d482;
                pbVar8 = pbVar8 + 2;
                pcVar17 = (char *)((byte *)pcVar17 + 2);
              } while (bVar1 != 0);
              uVar12 = 0;
LAB_0065d487:
              *piVar10 = *piVar10 + -1;
              if (*piVar10 < 1) {
                TclFreeObj(piVar10);
              }
              iVar4 = local_24;
              if (uVar12 == 0) {
                if (*(uint *)(local_24 + 0xc) <= local_28) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                if (*(int *)(*(int *)(iVar4 + 8) + 0x3c + local_2c) != -1) {
                  puVar7 = (undefined4 *)FUN_004295e0((undefined1 *)((int)piVar21 + 1));
                  local_bc = (int *)*puVar7;
                  if (local_bc != (int *)0x0) {
                    *local_bc = *local_bc + 1;
                  }
                  local_8 = CONCAT31(local_8._1_3_,0x12);
                  piVar10 = (int *)0x0;
                  local_38 = local_bc;
                  while( true ) {
                    local_34 = piVar10;
                    if (local_38 == (int *)0x0) {
                      iVar4 = 0;
                    }
                    else {
                      iVar11 = Tcl_ListObjLength(0,local_38,&local_74);
                      iVar4 = local_74;
                      if (iVar11 != 0) {
                        iVar4 = 0;
                      }
                    }
                    if (iVar4 <= (int)piVar10) break;
                    if ((local_38 == (int *)0x0) ||
                       (iVar4 = Tcl_ListObjIndex(0,local_38,piVar10,&local_78), piVar21 = local_78,
                       iVar4 != 0)) {
                      piVar21 = (int *)0x0;
LAB_0065d591:
                      local_4c = 0;
                      pcVar14 = TclFreeObj_exref;
                      if (piVar21 != (int *)0x0) goto LAB_0065d5a2;
                    }
                    else {
                      if (local_78 == (int *)0x0) goto LAB_0065d591;
                      *local_78 = *local_78 + 1;
                      iVar4 = Tcl_ListObjIndex(0,local_78,0,&local_7c);
                      piVar2 = local_7c;
                      if ((iVar4 != 0) || (local_7c == (int *)0x0)) goto LAB_0065d591;
                      *local_7c = *local_7c + 1;
                      iVar4 = Tcl_GetIntFromObj(0,local_7c,&local_80);
                      *piVar2 = *piVar2 + -1;
                      pcVar14 = TclFreeObj_exref;
                      local_4c = -(uint)(iVar4 != 1) & local_80;
                      if (*piVar2 < 1) {
                        TclFreeObj(piVar2);
                      }
LAB_0065d5a2:
                      *piVar21 = *piVar21 + -1;
                      if (*piVar21 < 1) {
                        (*pcVar14)(piVar21);
                      }
                    }
                    if ((local_38 == (int *)0x0) ||
                       (iVar4 = Tcl_ListObjIndex(0,local_38,piVar10,&local_84), piVar21 = local_84,
                       iVar4 != 0)) {
                      piVar21 = (int *)0x0;
LAB_0065d62f:
                      local_54 = 0;
                      pcVar14 = TclFreeObj_exref;
                      if (piVar21 != (int *)0x0) goto LAB_0065d640;
                    }
                    else {
                      if (local_84 == (int *)0x0) goto LAB_0065d62f;
                      *local_84 = *local_84 + 1;
                      iVar4 = Tcl_ListObjIndex(0,local_84,1,&local_88);
                      piVar2 = local_88;
                      if ((iVar4 != 0) || (local_88 == (int *)0x0)) goto LAB_0065d62f;
                      *local_88 = *local_88 + 1;
                      iVar4 = Tcl_GetIntFromObj(0,local_88,&local_8c);
                      *piVar2 = *piVar2 + -1;
                      pcVar14 = TclFreeObj_exref;
                      local_54 = -(uint)(iVar4 != 1) & local_8c;
                      if (*piVar2 < 1) {
                        TclFreeObj(piVar2);
                      }
LAB_0065d640:
                      *piVar21 = *piVar21 + -1;
                      if (*piVar21 < 1) {
                        (*pcVar14)(piVar21);
                      }
                    }
                    if ((local_38 == (int *)0x0) ||
                       (iVar4 = Tcl_ListObjIndex(0,local_38,piVar10,&local_90), piVar21 = local_90,
                       iVar4 != 0)) {
                      piVar21 = (int *)0x0;
LAB_0065d6d3:
                      local_50 = 0;
                      pcVar14 = TclFreeObj_exref;
                      if (piVar21 != (int *)0x0) goto LAB_0065d6e4;
                    }
                    else {
                      if (local_90 == (int *)0x0) goto LAB_0065d6d3;
                      *local_90 = *local_90 + 1;
                      iVar4 = Tcl_ListObjIndex(0,local_90,2,&local_94);
                      piVar2 = local_94;
                      if ((iVar4 != 0) || (local_94 == (int *)0x0)) goto LAB_0065d6d3;
                      *local_94 = *local_94 + 1;
                      iVar4 = Tcl_GetIntFromObj(0,local_94,&local_98);
                      *piVar2 = *piVar2 + -1;
                      pcVar14 = TclFreeObj_exref;
                      local_50 = -(uint)(iVar4 != 1) & local_98;
                      if (*piVar2 < 1) {
                        TclFreeObj(piVar2);
                      }
LAB_0065d6e4:
                      *piVar21 = *piVar21 + -1;
                      if (*piVar21 < 1) {
                        (*pcVar14)(piVar21);
                      }
                    }
                    if ((local_38 == (int *)0x0) ||
                       (iVar4 = Tcl_ListObjIndex(0,local_38,piVar10,&local_9c), piVar10 = local_9c,
                       iVar4 != 0)) {
                      piVar10 = (int *)0x0;
LAB_0065d777:
                      local_44 = (int *)0x0;
                      pcVar14 = TclFreeObj_exref;
                      if (piVar10 != (int *)0x0) goto LAB_0065d788;
                    }
                    else {
                      if (local_9c == (int *)0x0) goto LAB_0065d777;
                      *local_9c = *local_9c + 1;
                      iVar4 = Tcl_ListObjIndex(0,local_9c,3,&local_a0);
                      piVar21 = local_a0;
                      if ((iVar4 != 0) || (local_a0 == (int *)0x0)) goto LAB_0065d777;
                      *local_a0 = *local_a0 + 1;
                      iVar4 = Tcl_GetIntFromObj(0,local_a0,&local_b4);
                      pcVar14 = TclFreeObj_exref;
                      *piVar21 = *piVar21 + -1;
                      local_44 = (int *)(-(uint)(iVar4 != 1) & local_b4);
                      if (*piVar21 < 1) {
                        TclFreeObj(piVar21);
                      }
LAB_0065d788:
                      *piVar10 = *piVar10 + -1;
                      if (*piVar10 < 1) {
                        (*pcVar14)(piVar10);
                      }
                    }
                    iVar4 = local_24;
                    if (*(uint *)(local_24 + 0xc) <= local_28) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    uVar12 = *(uint *)(*(int *)(iVar4 + 8) + 0x3c + local_2c);
                    if (*(uint *)(iVar4 + 0x14) <= uVar12) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    iVar4 = *(int *)(iVar4 + 0x10);
                    fVar13 = *(float *)(iVar4 + 0x18 + uVar12 * 0x28);
                    if (((int)fVar13 + 0x10U & 0xfffffff0) != ((int)fVar13 + 0xfU & 0xfffffff0)) {
                      uVar15 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                            ,0x9b);
                      fVar13 = *(float *)(iVar4 + 0x18 + uVar12 * 0x28);
                      *(undefined4 *)(iVar4 + 0x14 + uVar12 * 0x28) = uVar15;
                    }
                    fVar9 = (float)((int)fVar13 + 1);
                    *(float *)(iVar4 + 0x18 + uVar12 * 0x28) = fVar9;
                    if ((uint)fVar9 <= (uint)fVar13) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      fVar9 = *(float *)(iVar4 + 0x18 + uVar12 * 0x28);
                    }
                    local_30 = (float)((int)fVar9 - 1);
                    if ((uint)fVar9 <= (uint)local_30) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    fVar13 = local_30;
                    *(uint *)(*(int *)(iVar4 + 0x14 + uVar12 * 0x28) + (int)local_30 * 0x10) =
                         local_4c;
                    if ((uint)*(float *)(iVar4 + 0x18 + uVar12 * 0x28) <= (uint)local_30) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    *(uint *)(*(int *)(iVar4 + 0x14 + uVar12 * 0x28) + 4 + (int)fVar13 * 0x10) =
                         local_50;
                    if ((uint)*(float *)(iVar4 + 0x18 + uVar12 * 0x28) <= (uint)local_30) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    *(uint *)(*(int *)(iVar4 + 0x14 + uVar12 * 0x28) + 8 + (int)fVar13 * 0x10) =
                         local_54;
                    if ((uint)*(float *)(iVar4 + 0x18 + uVar12 * 0x28) <= (uint)local_30) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    *(int **)(*(int *)(iVar4 + 0x14 + uVar12 * 0x28) + 0xc + (int)fVar13 * 0x10) =
                         local_44;
                    piVar10 = (int *)((int)local_34 + 1);
                  }
                  local_8 = CONCAT31(local_8._1_3_,5);
                  if ((local_38 != (int *)0x0) && (*local_38 = *local_38 + -1, *local_38 < 1)) {
                    TclFreeObj(local_38);
                  }
                }
                goto LAB_0065de3d;
              }
            }
            puVar7 = (undefined4 *)FUN_004295e0(piVar21);
            piVar10 = (int *)*puVar7;
            if (piVar10 != (int *)0x0) {
              *piVar10 = *piVar10 + 1;
              pcVar17 = "-exclusive";
              pbVar8 = (byte *)Tcl_GetStringFromObj(piVar10,0);
              do {
                bVar1 = *pbVar8;
                bVar18 = bVar1 < (byte)*pcVar17;
                if (bVar1 != *pcVar17) {
LAB_0065d930:
                  uVar12 = -(uint)bVar18 | 1;
                  goto LAB_0065d935;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar8[1];
                bVar18 = bVar1 < ((byte *)pcVar17)[1];
                if (bVar1 != ((byte *)pcVar17)[1]) goto LAB_0065d930;
                pbVar8 = pbVar8 + 2;
                pcVar17 = (char *)((byte *)pcVar17 + 2);
              } while (bVar1 != 0);
              uVar12 = 0;
LAB_0065d935:
              *piVar10 = *piVar10 + -1;
              if (*piVar10 < 1) {
                TclFreeObj(piVar10);
              }
              if (uVar12 == 0) {
                puVar7 = (undefined4 *)FUN_004295e0((undefined1 *)((int)piVar21 + 1));
                piVar10 = (int *)*puVar7;
                if (piVar10 == (int *)0x0) {
LAB_0065d980:
                  bVar18 = false;
                }
                else {
                  *piVar10 = *piVar10 + 1;
                  iVar4 = Tcl_GetBooleanFromObj(0,piVar10,&local_a8);
                  if (iVar4 == 1) goto LAB_0065d980;
                  bVar18 = local_a8 != 0;
                }
                iVar4 = local_24;
                if (*(uint *)(local_24 + 0xc) <= local_28) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                *(bool *)(*(int *)(iVar4 + 8) + 0x40 + local_2c) = bVar18;
                if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
                  TclFreeObj(piVar10);
                }
                goto LAB_0065de3d;
              }
            }
            puVar7 = (undefined4 *)FUN_004295e0(piVar21);
            piVar10 = (int *)*puVar7;
            if (piVar10 == (int *)0x0) {
LAB_0065daa3:
              puVar7 = (undefined4 *)FUN_004295e0(piVar21);
              piVar10 = (int *)*puVar7;
              if (piVar10 != (int *)0x0) {
                *piVar10 = *piVar10 + 1;
                pcVar17 = "-middist";
                pbVar8 = (byte *)Tcl_GetStringFromObj(piVar10,0);
                do {
                  bVar1 = *pbVar8;
                  bVar18 = bVar1 < (byte)*pcVar17;
                  if (bVar1 != *pcVar17) {
LAB_0065daf0:
                    uVar12 = -(uint)bVar18 | 1;
                    goto LAB_0065daf5;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar8[1];
                  bVar18 = bVar1 < ((byte *)pcVar17)[1];
                  if (bVar1 != ((byte *)pcVar17)[1]) goto LAB_0065daf0;
                  pbVar8 = pbVar8 + 2;
                  pcVar17 = (char *)((byte *)pcVar17 + 2);
                } while (bVar1 != 0);
                uVar12 = 0;
LAB_0065daf5:
                *piVar10 = *piVar10 + -1;
                pcVar14 = TclFreeObj_exref;
                if (*piVar10 < 1) {
                  TclFreeObj(piVar10);
                }
                piVar21 = local_14;
                if (uVar12 == 0) {
                  puVar7 = (undefined4 *)FUN_004295e0((undefined1 *)((int)local_14 + 1));
                  piVar10 = (int *)*puVar7;
                  if (piVar10 == (int *)0x0) {
LAB_0065db46:
                    local_30 = 0.0;
                  }
                  else {
                    *piVar10 = *piVar10 + 1;
                    iVar4 = Tcl_GetDoubleFromObj(0,piVar10,&local_cc);
                    if (iVar4 == 1) goto LAB_0065db46;
                    local_30 = (float)local_cc;
                  }
                  iVar4 = local_24;
                  if (*(uint *)(local_24 + 0xc) <= local_28) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  *(float *)(*(int *)(iVar4 + 8) + 0x60 + local_2c) = local_30;
                  goto LAB_0065de2c;
                }
              }
              puVar7 = (undefined4 *)FUN_004295e0(piVar21);
              piVar10 = (int *)*puVar7;
              if (piVar10 != (int *)0x0) {
                *piVar10 = *piVar10 + 1;
                pcVar17 = "-zoneborder";
                pbVar8 = (byte *)Tcl_GetStringFromObj(piVar10,0);
                do {
                  bVar1 = *pbVar8;
                  bVar18 = bVar1 < (byte)*pcVar17;
                  if (bVar1 != *pcVar17) {
LAB_0065dbd0:
                    uVar12 = -(uint)bVar18 | 1;
                    goto LAB_0065dbd5;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar8[1];
                  bVar18 = bVar1 < ((byte *)pcVar17)[1];
                  if (bVar1 != ((byte *)pcVar17)[1]) goto LAB_0065dbd0;
                  pbVar8 = pbVar8 + 2;
                  pcVar17 = (char *)((byte *)pcVar17 + 2);
                } while (bVar1 != 0);
                uVar12 = 0;
LAB_0065dbd5:
                *piVar10 = *piVar10 + -1;
                pcVar14 = TclFreeObj_exref;
                if (*piVar10 < 1) {
                  TclFreeObj(piVar10);
                }
                piVar21 = local_14;
                if (uVar12 == 0) {
                  puVar7 = (undefined4 *)FUN_004295e0((undefined1 *)((int)local_14 + 1));
                  piVar10 = (int *)*puVar7;
                  if (piVar10 != (int *)0x0) {
                    *piVar10 = *piVar10 + 1;
                  }
                  local_8._0_1_ = 0x13;
                  local_bc = piVar10;
                  if (piVar10 == (int *)0x0) {
                    ppuVar5 = &PTR_0071ce50;
                  }
                  else {
                    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar10,0);
                  }
                  FUN_006b8fb0(ppuVar5);
                  iVar4 = local_24;
                  local_8._0_1_ = 0x14;
                  if (*(uint *)(local_24 + 0xc) <= local_28) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  ppiVar20 = &local_3c;
                  iVar11 = *(int *)(iVar4 + 8) + local_2c;
                  FUN_005f8080(ppiVar20);
                  iVar4 = FUN_005fcea0(ppiVar20);
                  if (iVar4 != -1) {
                    *(int *)(iVar11 + 0x54) = iVar4;
                  }
                  local_8._0_1_ = 0x15;
                  if ((local_3c != (int *)0x0) && (*local_3c = *local_3c + -1, *local_3c == 0)) {
                    FUN_006ba940();
                  }
                  local_8 = CONCAT31(local_8._1_3_,5);
                  goto LAB_0065de2c;
                }
              }
              puVar7 = (undefined4 *)FUN_004295e0(piVar21);
              piVar10 = (int *)*puVar7;
              if (piVar10 != (int *)0x0) {
                *piVar10 = *piVar10 + 1;
                pcVar17 = "-checkalign";
                pbVar8 = (byte *)Tcl_GetStringFromObj(piVar10,0);
                do {
                  bVar1 = *pbVar8;
                  bVar18 = bVar1 < (byte)*pcVar17;
                  if (bVar1 != *pcVar17) {
LAB_0065dcd4:
                    uVar12 = -(uint)bVar18 | 1;
                    goto LAB_0065dcd9;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar8[1];
                  bVar18 = bVar1 < ((byte *)pcVar17)[1];
                  if (bVar1 != ((byte *)pcVar17)[1]) goto LAB_0065dcd4;
                  pbVar8 = pbVar8 + 2;
                  pcVar17 = (char *)((byte *)pcVar17 + 2);
                } while (bVar1 != 0);
                uVar12 = 0;
LAB_0065dcd9:
                *piVar10 = *piVar10 + -1;
                if (*piVar10 < 1) {
                  TclFreeObj(piVar10);
                }
                if (uVar12 == 0) {
                  puVar7 = (undefined4 *)FUN_004295e0((undefined1 *)((int)piVar21 + 1));
                  piVar10 = (int *)*puVar7;
                  if (piVar10 == (int *)0x0) {
LAB_0065dd24:
                    bVar18 = false;
                  }
                  else {
                    *piVar10 = *piVar10 + 1;
                    iVar4 = Tcl_GetBooleanFromObj(0,piVar10,&local_ac);
                    if (iVar4 == 1) goto LAB_0065dd24;
                    bVar18 = local_ac != 0;
                  }
                  iVar4 = local_24;
                  if (*(uint *)(local_24 + 0xc) <= local_28) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  *(bool *)(*(int *)(iVar4 + 8) + 0x58 + local_2c) = bVar18;
                  if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 < 1)) {
                    TclFreeObj(piVar10);
                  }
                  goto LAB_0065de3d;
                }
              }
              puVar7 = (undefined4 *)FUN_004295e0(piVar21);
              piVar10 = (int *)*puVar7;
              if (piVar10 != (int *)0x0) {
                *piVar10 = *piVar10 + 1;
                pcVar17 = "-stoneidx";
                pbVar8 = (byte *)Tcl_GetStringFromObj(piVar10,0);
                do {
                  bVar1 = *pbVar8;
                  bVar18 = bVar1 < (byte)*pcVar17;
                  if (bVar1 != *pcVar17) {
LAB_0065ddb1:
                    uVar12 = -(uint)bVar18 | 1;
                    goto LAB_0065ddb6;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = pbVar8[1];
                  bVar18 = bVar1 < ((byte *)pcVar17)[1];
                  if (bVar1 != ((byte *)pcVar17)[1]) goto LAB_0065ddb1;
                  pbVar8 = pbVar8 + 2;
                  pcVar17 = (char *)((byte *)pcVar17 + 2);
                } while (bVar1 != 0);
                uVar12 = 0;
LAB_0065ddb6:
                *piVar10 = *piVar10 + -1;
                pcVar14 = TclFreeObj_exref;
                if (*piVar10 < 1) {
                  TclFreeObj(piVar10);
                }
                piVar21 = local_14;
                if (uVar12 == 0) {
                  puVar7 = (undefined4 *)FUN_004295e0((undefined1 *)((int)local_14 + 1));
                  piVar10 = (int *)*puVar7;
                  if (piVar10 == (int *)0x0) {
                    uVar12 = 0;
                  }
                  else {
                    *piVar10 = *piVar10 + 1;
                    iVar4 = Tcl_GetIntFromObj(0,piVar10,&local_5c);
                    uVar12 = -(uint)(iVar4 != 1) & (uint)local_5c;
                  }
                  if (*(uint *)(local_24 + 0xc) <= local_28) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  *(uint *)(*(int *)(local_24 + 8) + 0x5c + local_2c) = uVar12;
                  goto LAB_0065de2c;
                }
              }
              puVar7 = (undefined4 *)FUN_004295e0(piVar21);
              piVar10 = (int *)*puVar7;
              if (piVar10 != (int *)0x0) {
                *piVar10 = *piVar10 + 1;
              }
              FUN_006bc6a0("invalid param",piVar10);
              uVar15 = 1;
              goto LAB_0065dfc3;
            }
            *piVar10 = *piVar10 + 1;
            pcVar17 = "-nonrelevant";
            pbVar8 = (byte *)Tcl_GetStringFromObj(piVar10,0);
            do {
              bVar1 = *pbVar8;
              bVar18 = bVar1 < (byte)*pcVar17;
              if (bVar1 != *pcVar17) {
LAB_0065da10:
                uVar12 = -(uint)bVar18 | 1;
                goto LAB_0065da15;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar8[1];
              bVar18 = bVar1 < ((byte *)pcVar17)[1];
              if (bVar1 != ((byte *)pcVar17)[1]) goto LAB_0065da10;
              pbVar8 = pbVar8 + 2;
              pcVar17 = (char *)((byte *)pcVar17 + 2);
            } while (bVar1 != 0);
            uVar12 = 0;
LAB_0065da15:
            *piVar10 = *piVar10 + -1;
            pcVar14 = TclFreeObj_exref;
            if (*piVar10 < 1) {
              TclFreeObj(piVar10);
            }
            piVar21 = local_14;
            if (uVar12 != 0) goto LAB_0065daa3;
            puVar7 = (undefined4 *)FUN_004295e0((undefined1 *)((int)local_14 + 1));
            piVar10 = (int *)*puVar7;
            if (piVar10 == (int *)0x0) {
LAB_0065da66:
              local_30 = 0.0;
            }
            else {
              *piVar10 = *piVar10 + 1;
              iVar4 = Tcl_GetDoubleFromObj(0,piVar10,&local_c4);
              if (iVar4 == 1) goto LAB_0065da66;
              local_30 = (float)local_c4;
            }
            iVar4 = local_24;
            if (*(uint *)(local_24 + 0xc) <= local_28) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            *(float *)(*(int *)(iVar4 + 8) + 0x44 + local_2c) = local_30;
LAB_0065de2c:
            if (piVar10 != (int *)0x0) {
              *piVar10 = *piVar10 + -1;
              iVar4 = *piVar10;
              goto joined_r0x0065de35;
            }
          }
          else {
            *piVar10 = *piVar10 + 1;
            pcVar17 = "-events";
            pbVar8 = (byte *)Tcl_GetStringFromObj(piVar10,0);
            do {
              bVar1 = *pbVar8;
              bVar18 = bVar1 < (byte)*pcVar17;
              if (bVar1 != *pcVar17) {
LAB_0065cf56:
                uVar12 = -(uint)bVar18 | 1;
                goto LAB_0065cf5b;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar8[1];
              bVar18 = bVar1 < ((byte *)pcVar17)[1];
              if (bVar1 != ((byte *)pcVar17)[1]) goto LAB_0065cf56;
              pbVar8 = pbVar8 + 2;
              pcVar17 = (char *)((byte *)pcVar17 + 2);
            } while (bVar1 != 0);
            uVar12 = 0;
LAB_0065cf5b:
            *piVar10 = *piVar10 + -1;
            if (*piVar10 < 1) {
              TclFreeObj(piVar10);
            }
            if (uVar12 != 0) goto LAB_0065d102;
            puVar7 = (undefined4 *)FUN_004295e0((undefined1 *)((int)local_14 + 1));
            piVar10 = (int *)*puVar7;
            if (piVar10 != (int *)0x0) {
              *piVar10 = *piVar10 + 1;
            }
            fVar13 = 0.0;
            local_44 = piVar10;
            while( true ) {
              local_30 = fVar13;
              if (piVar10 == (int *)0x0) {
                iVar4 = 0;
              }
              else {
                iVar11 = Tcl_ListObjLength(0,piVar10,&local_a4);
                iVar4 = local_a4;
                if (iVar11 != 0) {
                  iVar4 = 0;
                }
              }
              if (iVar4 <= (int)fVar13) break;
              if ((piVar10 == (int *)0x0) ||
                 (iVar4 = Tcl_ListObjIndex(0,piVar10,fVar13,&local_b0), iVar4 != 0)) {
                local_34 = (int *)0x0;
              }
              else {
                local_34 = local_b0;
                if (local_b0 != (int *)0x0) {
                  *local_b0 = *local_b0 + 1;
                }
              }
              piVar21 = local_34;
              local_8._0_1_ = 8;
              if (local_34 == (int *)0x0) {
                ppuVar5 = &PTR_0071ce50;
              }
              else {
                ppuVar5 = (undefined **)Tcl_GetStringFromObj(local_34,0);
              }
              FUN_006b8fb0(ppuVar5);
              local_8 = CONCAT31(local_8._1_3_,10);
              if ((piVar21 != (int *)0x0) && (*piVar21 = *piVar21 + -1, *piVar21 < 1)) {
                TclFreeObj(piVar21);
              }
              iVar4 = local_24;
              local_34 = (int *)FUN_005f8a70(&local_40);
              if (local_34 == (int *)0xffffffff) {
                if ((piVar10 == (int *)0x0) ||
                   (iVar4 = Tcl_ListObjIndex(0,piVar10,fVar13,&param_3,extraout_ECX), iVar4 != 0)) {
                  piVar21 = (int *)0x0;
                }
                else {
                  piVar21 = param_3;
                  if (param_3 != (int *)0x0) {
                    *param_3 = *param_3 + 1;
                  }
                }
                FUN_006bc6a0("Story Event not found",piVar21);
                local_8 = CONCAT31(local_8._1_3_,0xb);
                if ((local_40 != (int *)0x0) && (*local_40 = *local_40 + -1, *local_40 == 0)) {
                  FUN_006ba940();
                }
                if ((piVar10 == (int *)0x0) || (*piVar10 = *piVar10 + -1, 0 < *piVar10))
                goto LAB_0065df85;
                TclFreeObj(piVar10);
                uVar15 = 1;
                goto LAB_0065dfc3;
              }
              if (*(uint *)(iVar4 + 0xc) <= local_28) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              iVar4 = *(int *)(iVar4 + 8) + local_2c;
              uVar12 = *(uint *)(iVar4 + 0x19);
              if ((uVar12 + 0x10 & 0xfffffff0) != (uVar12 + 0xf & 0xfffffff0)) {
                uVar15 = FUN_006baad0("C:\\dev\\wiggles\\CodeLib\\StdTools\\KStdLib\\Include\\DSFastArray.h"
                                      ,0x9b);
                uVar12 = *(uint *)(iVar4 + 0x19);
                *(undefined4 *)(iVar4 + 0x15) = uVar15;
              }
              *(uint *)(iVar4 + 0x19) = uVar12 + 1;
              if (uVar12 + 1 <= uVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              *(int **)(*(int *)(iVar4 + 0x15) + uVar12 * 4) = local_34;
              local_8 = CONCAT31(local_8._1_3_,0xd);
              if ((local_40 != (int *)0x0) && (*local_40 = *local_40 + -1, *local_40 == 0)) {
                FUN_006ba940();
              }
              fVar13 = (float)((int)local_30 + 1);
            }
            local_8 = CONCAT31(local_8._1_3_,5);
            if (piVar10 != (int *)0x0) {
              *piVar10 = *piVar10 + -1;
              iVar4 = *piVar10;
              pcVar14 = TclFreeObj_exref;
joined_r0x0065de35:
              if (iVar4 < 1) {
                (*pcVar14)(piVar10);
              }
            }
          }
LAB_0065de3d:
          piVar21 = (int *)((int)local_14 + 2);
          piVar10 = local_14 + 1;
          iVar4 = local_24;
          local_14 = piVar21;
        } while ((int)piVar10 <= (int)param_3);
      }
      uVar12 = local_28;
      if (*(uint *)(iVar4 + 0xc) <= local_28) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      cVar3 = FUN_005f9a10();
      if (cVar3 == '\0') {
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
        piVar10 = (int *)*puVar7;
        if (piVar10 != (int *)0x0) {
          *piVar10 = *piVar10 + 1;
        }
        FUN_006bc6a0("Invalid connection link in",piVar10);
LAB_0065df85:
        uVar15 = 1;
      }
      else {
        piVar10 = (int *)Tcl_NewIntObj(uVar12);
        *piVar10 = *piVar10 + 1;
        iVar4 = *piVar10;
        if (local_6c != 0) {
          Tcl_SetObjResult(local_6c,piVar10);
          iVar4 = *piVar10;
        }
        *piVar10 = iVar4 + -1;
        if (iVar4 + -1 < 1) {
          TclFreeObj(piVar10);
        }
        uVar15 = 0;
      }
    }
LAB_0065dfc3:
    local_8._0_1_ = 0x18;
    if ((local_58 != (int *)0x0) && (*local_58 = *local_58 + -1, *local_58 == 0)) {
      FUN_006ba940();
    }
    local_8._0_1_ = 0x19;
    FUN_004297b0(0);
    local_8 = CONCAT31(local_8._1_3_,0x1a);
    FUN_004297b0(0);
    if (local_20 != (undefined4 *)0x0) {
      FUN_006ba940();
    }
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar15;
}

