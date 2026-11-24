
undefined4
CTclObjMethods__PartnerInfo(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  byte bVar2;
  int *piVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  undefined **ppuVar7;
  byte *pbVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  char *pcVar12;
  undefined4 extraout_ECX;
  undefined4 uVar13;
  int *piVar14;
  int *piVar15;
  bool bVar16;
  undefined8 uVar17;
  int *piVar18;
  undefined4 *local_30;
  uint local_2c;
  int local_28;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007124d5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7cc0) &&
     (FUN_006cebf4(&DAT_00ca7cc0,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar6 = DAT_00783650,
     DAT_00ca7cc0 == -1)) {
    iVar11 = DAT_00783650 * 0x40;
    DAT_00ca7cc4 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar11) = "TCL:CTclObjMethods::PartnerInfo()";
    *(int *)(&DAT_00773650 + iVar11) = iVar6;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7cc0);
  }
  iVar11 = DAT_00ca7cc4;
  uVar13 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7cc4 * 0x40);
  iVar6 = FUN_0043fcc0();
  *(undefined4 *)(iVar6 + *(int *)(iVar6 + 0x8000) * 4) = uVar13;
  *(int *)(iVar6 + 0x8000) = *(int *)(iVar6 + 0x8000) + 1;
  iVar6 = (&DAT_00773654)[iVar11 * 0x10];
  if (iVar6 == 0) {
    uVar17 = FUN_006bd180();
    iVar6 = (&DAT_00773654)[iVar11 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar11 * 0x10) = uVar17;
  }
  (&DAT_00773654)[iVar11 * 0x10] = iVar6 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar13 = param_4;
  piVar18 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if ((int)piVar18 < 3) {
    FUN_006bc8f0(2);
    uVar13 = 1;
    goto LAB_006a9e8d;
  }
  param_3 = (int *)FUN_005c71c0(uVar13,3,2);
  if (param_3 == (int *)0x0) {
    if (local_28 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar10 = local_30;
      if (local_2c == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_2c < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar10 = local_30 + 2;
    }
    piVar18 = (int *)*puVar10;
    if (piVar18 != (int *)0x0) {
      *piVar18 = *piVar18 + 1;
    }
    FUN_006bc6a0("invalid object",piVar18);
    uVar13 = 1;
    goto LAB_006a9e8d;
  }
  if ((param_3[0x3a] != 1) && (param_3[0x3a] != 0xb)) {
    if (param_3[0x36] + 0xc == 0) {
      piVar18 = (int *)0x0;
    }
    else {
      piVar18 = (int *)Tcl_NewStringObj(param_3[0x36] + 0xc,0xffffffff,param_3);
      *piVar18 = *piVar18 + 1;
    }
    FUN_006bc6a0("not a gnome or a baby type",piVar18);
    uVar13 = 1;
    goto LAB_006a9e8d;
  }
  if (local_28 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar10 = local_30;
    if (local_2c == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_2c < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar10 = local_30 + 1;
  }
  piVar14 = (int *)*puVar10;
  if (piVar14 != (int *)0x0) {
    *piVar14 = *piVar14 + 1;
  }
  local_8._0_1_ = 3;
  if (piVar14 == (int *)0x0) {
    ppuVar7 = &PTR_0071ce50;
    piVar15 = (int *)0x0;
  }
  else {
    ppuVar7 = (undefined **)Tcl_GetStringFromObj(piVar14,0);
    piVar15 = piVar14;
  }
  FUN_006b8fb0(ppuVar7);
  local_8._0_1_ = 5;
  if ((piVar15 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
    TclFreeObj(piVar14);
  }
  piVar14 = local_14;
  pcVar12 = "setpartner";
  pbVar8 = (byte *)(local_14 + 3);
  do {
    bVar2 = *pbVar8;
    bVar16 = bVar2 < (byte)*pcVar12;
    if (bVar2 != *pcVar12) {
LAB_006a9811:
      uVar9 = -(uint)bVar16 | 1;
      goto LAB_006a9816;
    }
    if (bVar2 == 0) break;
    bVar2 = pbVar8[1];
    bVar16 = bVar2 < ((byte *)pcVar12)[1];
    if (bVar2 != ((byte *)pcVar12)[1]) goto LAB_006a9811;
    pbVar8 = pbVar8 + 2;
    pcVar12 = (char *)((byte *)pcVar12 + 2);
  } while (bVar2 != 0);
  uVar9 = 0;
LAB_006a9816:
  if (uVar9 == 0) {
    if (piVar18 == (int *)&DAT_00000004) {
      iVar6 = FUN_005c71c0(param_4,3,3);
      if (iVar6 == 0) {
LAB_006a984e:
        puVar10 = (undefined4 *)FUN_004295e0(3);
        piVar18 = (int *)*puVar10;
        if (piVar18 != (int *)0x0) {
          *piVar18 = *piVar18 + 1;
        }
        pcVar12 = "invalid object";
        goto LAB_006a9e6c;
      }
      puVar10 = (undefined4 *)param_3[0xfc];
      FUN_00445640(iVar6 + 4);
      puVar10[4] = FUN_005db6f0;
      puVar10[5] = puVar10;
      *puVar10 = *(undefined4 *)(iVar6 + 0xdc);
      puVar10[6] = 1;
      uVar13 = 0;
      goto LAB_006a9e79;
    }
    FUN_006bc8f0(3);
LAB_006a9e74:
    uVar13 = 1;
  }
  else {
    pcVar12 = "addchild";
    pbVar8 = (byte *)(local_14 + 3);
    do {
      bVar2 = *pbVar8;
      bVar16 = bVar2 < (byte)*pcVar12;
      if (bVar2 != *pcVar12) {
LAB_006a98d0:
        uVar9 = -(uint)bVar16 | 1;
        goto LAB_006a98d5;
      }
      if (bVar2 == 0) break;
      bVar2 = pbVar8[1];
      bVar16 = bVar2 < ((byte *)pcVar12)[1];
      if (bVar2 != ((byte *)pcVar12)[1]) goto LAB_006a98d0;
      pbVar8 = pbVar8 + 2;
      pcVar12 = (char *)((byte *)pcVar12 + 2);
    } while (bVar2 != 0);
    uVar9 = 0;
LAB_006a98d5:
    if (uVar9 == 0) {
      if (piVar18 != (int *)&DAT_00000004) {
        FUN_006bc8f0(3);
        goto LAB_006a9e74;
      }
      iVar6 = FUN_005c71c0(param_4,3,3);
      if (iVar6 == 0) goto LAB_006a984e;
      iVar11 = param_3[0xfc];
      FUN_00444ca0(1);
      piVar18 = *(int **)(iVar11 + 0x58);
      param_3 = (int *)((int)piVar18 + -1);
      if (piVar18 <= param_3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      piVar18 = (int *)(*(int *)(iVar11 + 0x54) + (int)param_3 * 4);
      piVar15 = *(int **)(iVar6 + 0xd8);
      piVar3 = (int *)*piVar18;
      *piVar18 = (int)piVar15;
      if (piVar15 != (int *)0x0) {
        *piVar15 = *piVar15 + 1;
      }
      if ((piVar3 != (int *)0x0) && (*piVar3 = *piVar3 + -1, *piVar3 == 0)) {
        FUN_006ba940();
      }
      uVar13 = 0;
      *(undefined4 *)(*piVar18 + 8) = *(undefined4 *)(*(int *)(iVar6 + 0xd8) + 8);
    }
    else {
      cVar4 = FUN_006b9930();
      if (cVar4 == '\0') {
        cVar4 = FUN_006b9930();
        if (cVar4 == '\0') {
          cVar4 = FUN_006b9930();
          if (cVar4 == '\0') {
            cVar4 = FUN_006b9930();
            if (cVar4 == '\0') {
              cVar4 = FUN_006b9930();
              if (cVar4 == '\0') {
                cVar4 = FUN_006b9930();
                if (cVar4 == '\0') {
                  cVar4 = FUN_006b9930();
                  if (cVar4 != '\0') {
                    iVar6 = FUN_005db870();
                    goto LAB_006a9bbf;
                  }
                  cVar4 = FUN_006b9930();
                  if (cVar4 != '\0') {
                    FUN_006bb910();
                    iVar6 = *(int *)(param_3[0xfc] + 0x58);
                    if (0 < iVar6) {
                      uVar9 = 0;
                      do {
                        local_8._0_1_ = 0xf;
                        iVar11 = param_3[0xfc];
                        uVar1 = *(uint *)(iVar11 + 0x58);
                        if ((int)uVar9 < (int)uVar1) {
                          if (uVar1 <= uVar9) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          }
                          piVar18 = *(int **)(*(int *)(iVar11 + 0x54) + uVar9 * 4);
                          if (piVar18 != (int *)0x0) {
                            *piVar18 = *piVar18 + 1;
                          }
                        }
                        else {
                          piVar18 = (int *)FUN_006ba810(0x19);
                          piVar18[1] = 4;
                          *(undefined1 *)(piVar18 + 3) = 0;
                          piVar18[2] = 0;
                          *piVar18 = 1;
                        }
                        if (piVar18 + 3 == (int *)0x0) {
                          piVar14 = (int *)0x0;
                        }
                        else {
                          piVar14 = (int *)Tcl_NewStringObj(piVar18 + 3,0xffffffff);
                          *piVar14 = *piVar14 + 1;
                        }
                        local_1c = piVar14;
                        FUN_006bb930(&local_1c);
                        if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 < 1)) {
                          TclFreeObj(piVar14);
                        }
                        local_8._0_1_ = 0x10;
                        if ((piVar18 != (int *)0x0) && (*piVar18 = *piVar18 + -1, *piVar18 == 0)) {
                          FUN_006ba940();
                        }
                        uVar9 = uVar9 + 1;
                        piVar14 = local_14;
                      } while ((int)uVar9 < iVar6);
                    }
                    local_8._0_1_ = 0xf;
                    FUN_006bc670(&local_18);
                    FUN_006bad60();
                    uVar13 = 0;
                    goto LAB_006a9e79;
                  }
                  cVar4 = FUN_006b9930();
                  if (cVar4 == '\0') {
                    if (piVar14 + 3 == (int *)0x0) {
                      piVar18 = (int *)0x0;
                    }
                    else {
                      piVar18 = (int *)Tcl_NewStringObj(piVar14 + 3,0xffffffff,extraout_ECX);
                      *piVar18 = *piVar18 + 1;
                    }
                    pcVar12 = "invalid param";
                    goto LAB_006a9e6c;
                  }
                  if (piVar18 != (int *)&DAT_00000004) {
                    FUN_006bc8f0(3);
                    goto LAB_006a9e74;
                  }
                  iVar6 = FUN_005c71c0(param_4,3,3);
                  if (iVar6 == 0) goto LAB_006a984e;
                  if (*(int *)(iVar6 + 0x3f0) == 0) {
                    puVar10 = (undefined4 *)FUN_004295e0(3);
                    piVar18 = (int *)*puVar10;
                    if (piVar18 != (int *)0x0) {
                      *piVar18 = *piVar18 + 1;
                    }
                    pcVar12 = "no family (baby)";
LAB_006a9e6c:
                    FUN_006bc6a0(pcVar12,piVar18);
                    goto LAB_006a9e74;
                  }
                  if (param_3[0xfc] == 0) {
                    puVar10 = (undefined4 *)FUN_004295e0(3);
                    piVar18 = (int *)*puVar10;
                    if (piVar18 != (int *)0x0) {
                      *piVar18 = *piVar18 + 1;
                    }
                    pcVar12 = "no family";
                    goto LAB_006a9e6c;
                  }
                  param_3 = DAT_0077244c;
                  iVar6 = FUN_005db870();
                  iVar11 = FUN_005db890();
                  if (iVar6 < 1) {
                    uVar13 = 0;
                  }
                  else {
                    puVar10 = (undefined4 *)FUN_00407340(iVar6);
                    uVar13 = *puVar10;
                  }
                  FUN_005db710(uVar13);
                  if (0 < iVar11) {
                    puVar10 = (undefined4 *)FUN_00407340(iVar11);
                    FUN_005db7c0(*puVar10);
                    uVar13 = 0;
                    goto LAB_006a9e79;
                  }
                  FUN_005db7c0(0);
LAB_006a9e45:
                  uVar13 = 0;
                  goto LAB_006a9e79;
                }
                iVar6 = FUN_005db890();
LAB_006a9bbf:
                if (0 < iVar6) {
                  FUN_00407340(iVar6);
                  iVar6 = FUN_005caf90();
                  if (iVar6 != 0) goto LAB_006a9b29;
                  piVar18 = (int *)0x0;
                  goto LAB_006a9b39;
                }
              }
              else {
                piVar18 = (int *)param_3[0xfc];
                FUN_005db640();
                iVar6 = piVar18[6];
                if (iVar6 == 1) {
                  iVar6 = *piVar18;
                  if (0 < iVar6) {
                    FUN_00407340(iVar6);
                    iVar6 = FUN_005caf90();
                    if (iVar6 == 0) {
                      piVar18 = (int *)0x0;
                    }
                    else {
LAB_006a9b29:
                      piVar18 = (int *)Tcl_NewStringObj(iVar6,0xffffffff);
                      *piVar18 = *piVar18 + 1;
                    }
LAB_006a9b39:
                    param_3 = piVar18;
                    FUN_006bc670(&param_3);
                    if ((piVar18 == (int *)0x0) || (*piVar18 = *piVar18 + -1, 0 < *piVar18))
                    goto LAB_006a9e45;
                    TclFreeObj(piVar18);
                    uVar13 = 0;
                    goto LAB_006a9e79;
                  }
                }
                else {
                  iVar6 = (iVar6 != 2) - 1;
                }
              }
              param_3 = (int *)Tcl_NewIntObj(iVar6);
              *param_3 = *param_3 + 1;
              FUN_006bc670(&param_3);
              FUN_006bad60();
              uVar13 = 0;
            }
            else {
              param_3 = (int *)Tcl_NewBooleanObj(*(undefined1 *)(param_3[0xfc] + 0x5c));
              *param_3 = *param_3 + 1;
              FUN_006bc670(&param_3);
              FUN_006bad60();
              uVar13 = 0;
            }
          }
          else {
            if (piVar18 != (int *)&DAT_00000004) {
              FUN_006bc8f0(3);
              goto LAB_006a9e74;
            }
            puVar10 = (undefined4 *)FUN_004295e0(3);
            local_18 = (int *)*puVar10;
            if (local_18 != (int *)0x0) {
              *local_18 = *local_18 + 1;
            }
            uVar5 = FUN_006baf10();
            *(undefined1 *)(param_3[0xfc] + 0x5c) = uVar5;
            FUN_006bad60();
            uVar13 = 0;
          }
        }
        else {
          if (piVar18 != (int *)&DAT_00000004) {
            FUN_006bc8f0(3);
            goto LAB_006a9e74;
          }
          iVar6 = FUN_005c71c0(param_4,3,3);
          if (iVar6 == 0) goto LAB_006a984e;
          FUN_005db710(iVar6);
          uVar13 = 0;
        }
      }
      else {
        if (piVar18 != (int *)&DAT_00000004) {
          FUN_006bc8f0(3);
          goto LAB_006a9e74;
        }
        iVar6 = FUN_005c71c0(param_4,3,3);
        if (iVar6 == 0) goto LAB_006a984e;
        FUN_005db7c0(iVar6);
        uVar13 = 0;
      }
    }
  }
LAB_006a9e79:
  local_8._0_1_ = 0x16;
  if ((piVar14 != (int *)0x0) && (*piVar14 = *piVar14 + -1, *piVar14 == 0)) {
    FUN_006ba940();
  }
LAB_006a9e8d:
  local_8._0_1_ = 0x17;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x18);
  FUN_004297b0(0);
  if (local_30 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar13;
}

