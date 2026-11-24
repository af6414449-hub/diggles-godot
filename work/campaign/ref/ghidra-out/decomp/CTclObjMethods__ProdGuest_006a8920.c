
undefined4
CTclObjMethods__ProdGuest(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  void *lp;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  byte *pbVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  BOOL BVar9;
  int *piVar10;
  char *pcVar11;
  undefined4 extraout_ECX;
  int *piVar12;
  int iVar13;
  code *pcVar14;
  undefined4 uVar15;
  bool bVar16;
  undefined8 uVar17;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0071247d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7cb8) &&
     (FUN_006cebf4(&DAT_00ca7cb8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7cb8 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca7cbc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclObjMethods::ProdGuest()";
    *(int *)(&DAT_00773650 + iVar8) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7cb8);
  }
  iVar8 = DAT_00ca7cbc;
  uVar15 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7cbc * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar15;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar3 == 0) {
    uVar17 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar17;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  uVar15 = param_4;
  piVar12 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8._0_1_ = 2;
  if ((int)piVar12 < 3) {
    FUN_006bc8f0(2);
    uVar15 = 1;
    goto LAB_006a94ed;
  }
  iVar3 = FUN_005c71c0(uVar15,3,2);
  pcVar14 = RaiseException_exref;
  if (iVar3 == 0) {
    if (local_2c < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar7 = local_34;
      if (local_30 == 0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
    }
    else {
      if (local_30 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar7 = local_34 + 2;
    }
    piVar12 = (int *)*puVar7;
    if (piVar12 != (int *)0x0) {
      *piVar12 = *piVar12 + 1;
    }
    FUN_006bc6a0("invalid object",piVar12);
    uVar15 = 1;
    goto LAB_006a94ed;
  }
  if (local_2c < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar7 = local_34;
    if (local_30 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar7 = local_34 + 1;
  }
  piVar12 = (int *)*puVar7;
  if (piVar12 != (int *)0x0) {
    *piVar12 = *piVar12 + 1;
  }
  local_8._0_1_ = 3;
  if (piVar12 == (int *)0x0) {
    ppuVar4 = &PTR_0071ce50;
    piVar10 = (int *)0x0;
  }
  else {
    ppuVar4 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
    piVar10 = piVar12;
  }
  FUN_006b8fb0(ppuVar4);
  local_8 = CONCAT31(local_8._1_3_,5);
  if ((piVar10 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
    TclFreeObj(piVar12);
  }
  pcVar11 = "addlink";
  pbVar5 = (byte *)(local_14 + 3);
  do {
    bVar1 = *pbVar5;
    bVar16 = bVar1 < (byte)*pcVar11;
    if (bVar1 != *pcVar11) {
LAB_006a8b40:
      uVar6 = -(uint)bVar16 | 1;
      goto LAB_006a8b45;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar5[1];
    bVar16 = bVar1 < ((byte *)pcVar11)[1];
    if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_006a8b40;
    pbVar5 = pbVar5 + 2;
    pcVar11 = (char *)((byte *)pcVar11 + 2);
  } while (bVar1 != 0);
  uVar6 = 0;
LAB_006a8b45:
  if (uVar6 == 0) {
    if (*(int *)(iVar3 + 0xe8) != 5) goto LAB_006a8f29;
    uVar15 = 3;
    if (3 < (int)param_3) {
      puVar7 = (undefined4 *)FUN_004295e0(3);
      param_3 = (int *)*puVar7;
      if (param_3 != (int *)0x0) {
        *param_3 = *param_3 + 1;
      }
      iVar8 = FUN_006baee0();
      FUN_006bad60();
      uVar6 = 0;
      piVar12 = (int *)(*(int *)(iVar3 + 0x3e0) + 0x6c);
      param_3 = (int *)0x0;
      do {
        if (uVar6 < 0x10) {
          piVar10 = (int *)((int)piVar12 + (int)param_3);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar10 = piVar12;
        }
        if (*piVar10 == -1) {
          if (0xf < (int)uVar6) goto LAB_006a94a5;
          if (uVar6 < 0x10) {
            uVar15 = 0;
            piVar12[uVar6 * 3] = iVar8;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            uVar15 = 0;
            *piVar12 = iVar8;
          }
          goto LAB_006a94d9;
        }
        param_3 = param_3 + 3;
        uVar6 = uVar6 + 1;
      } while ((int)param_3 < 0xc0);
      uVar15 = 0;
      goto LAB_006a94d9;
    }
LAB_006a8d6e:
    FUN_006bc8f0(uVar15);
LAB_006a94d4:
    uVar15 = 1;
  }
  else {
    pcVar11 = "setlink";
    pbVar5 = (byte *)(local_14 + 3);
    do {
      bVar1 = *pbVar5;
      bVar16 = bVar1 < (byte)*pcVar11;
      if (bVar1 != *pcVar11) {
LAB_006a8c40:
        uVar6 = -(uint)bVar16 | 1;
        goto LAB_006a8c45;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar5[1];
      bVar16 = bVar1 < ((byte *)pcVar11)[1];
      if (bVar1 != ((byte *)pcVar11)[1]) goto LAB_006a8c40;
      pbVar5 = pbVar5 + 2;
      pcVar11 = (char *)((byte *)pcVar11 + 2);
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_006a8c45:
    if (uVar6 == 0) {
      if (*(int *)(iVar3 + 0xe8) != 5) goto LAB_006a8f29;
      if (4 < (int)param_3) {
        puVar7 = (undefined4 *)FUN_004295e0(3);
        param_3 = (int *)*puVar7;
        if (param_3 != (int *)0x0) {
          *param_3 = *param_3 + 1;
        }
        uVar6 = FUN_006baee0();
        FUN_006bad60();
        puVar7 = (undefined4 *)FUN_004295e0(4);
        param_3 = (int *)*puVar7;
        if (param_3 != (int *)0x0) {
          *param_3 = *param_3 + 1;
        }
        uVar15 = FUN_006baee0();
        FUN_006bad60();
        if (0xf < uVar6) goto LAB_006a94a5;
        *(undefined4 *)(*(int *)(iVar3 + 0x3e0) + 0x6c + uVar6 * 0xc) = uVar15;
        uVar15 = 0;
        goto LAB_006a94d9;
      }
LAB_006a8d6c:
      uVar15 = 4;
      goto LAB_006a8d6e;
    }
    cVar2 = FUN_006b9930();
    if (cVar2 != '\0') {
      if (*(int *)(iVar3 + 0xe8) != 5) goto LAB_006a8f29;
      uVar15 = 3;
      if (3 < (int)param_3) {
        puVar7 = (undefined4 *)FUN_004295e0(3);
        param_3 = (int *)*puVar7;
        if (param_3 != (int *)0x0) {
          *param_3 = *param_3 + 1;
        }
        uVar6 = FUN_006baee0();
        FUN_006bad60();
        if (uVar6 < 0x10) {
          local_1c = *(int *)(*(int *)(iVar3 + 0x3e0) + 0x6c + uVar6 * 0xc);
        }
        else {
LAB_006a924a:
          local_1c = -1;
        }
        goto LAB_006a924e;
      }
      goto LAB_006a8d6e;
    }
    cVar2 = FUN_006b9930();
    if (cVar2 == '\0') {
      cVar2 = FUN_006b9930();
      if (cVar2 != '\0') {
        if (*(int *)(iVar3 + 0xe8) == 5) {
          if ((int)param_3 < 4) {
            FUN_006bc8f0(3);
            goto LAB_006a94d4;
          }
          iVar8 = FUN_005c71c0(param_4,3,3);
          iVar3 = *(int *)(iVar3 + 0x3e0) + 0x6c;
          uVar6 = 0;
          local_1c = 0;
          param_3 = (int *)iVar3;
          do {
            if (uVar6 < 0x10) {
              iVar13 = iVar3 + local_1c;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              iVar3 = (int)param_3;
              iVar13 = (int)param_3;
            }
            if (*(int *)(iVar13 + 4) == iVar8) break;
            local_1c = local_1c + 0xc;
            uVar6 = uVar6 + 1;
          } while ((int)local_1c < 0xc0);
          if ((int)uVar6 < 0x10) {
            local_1c = uVar6;
            if (uVar6 < 0x10) {
              *(undefined4 *)(iVar3 + 4 + uVar6 * 0xc) = 0;
              *(undefined4 *)(iVar3 + uVar6 * 0xc + 8) = 0;
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              *(undefined4 *)((int)param_3 + 4) = 0;
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              *(undefined4 *)((int)param_3 + 8) = 0;
            }
          }
          else {
            local_1c = 1;
          }
LAB_006a9480:
          param_3 = (int *)Tcl_NewIntObj(local_1c);
          *param_3 = *param_3 + 1;
          FUN_006bc670(&param_3);
          FUN_006bad60();
LAB_006a94a5:
          uVar15 = 0;
        }
        else {
          uVar15 = 0;
        }
        goto LAB_006a94d9;
      }
      cVar2 = FUN_006b9930();
      if (cVar2 != '\0') {
        if (*(int *)(iVar3 + 0xe8) != 5) goto LAB_006a8f29;
        if ((int)param_3 < 4) {
          FUN_006bc8f0(3);
          goto LAB_006a94d4;
        }
        puVar7 = (undefined4 *)FUN_004295e0(3);
        param_3 = (int *)*puVar7;
        if (param_3 != (int *)0x0) {
          *param_3 = *param_3 + 1;
        }
        uVar6 = FUN_006baee0();
        FUN_006bad60();
        if ((0xf < uVar6) || (*(int *)(*(int *)(iVar3 + 0x3e0) + 0x70 + uVar6 * 0xc) == 0)) {
          local_1c = 0;
          goto LAB_006a924e;
        }
        iVar3 = FUN_005caf90();
        if (iVar3 == 0) {
          piVar12 = (int *)0x0;
        }
        else {
          piVar12 = (int *)Tcl_NewStringObj(iVar3,0xffffffff);
          *piVar12 = *piVar12 + 1;
        }
        param_3 = piVar12;
        FUN_006bc670(&param_3);
        if ((piVar12 == (int *)0x0) || (*piVar12 = *piVar12 + -1, 0 < *piVar12)) goto LAB_006a94a5;
        TclFreeObj(piVar12);
        uVar15 = 0;
        goto LAB_006a94d9;
      }
      cVar2 = FUN_006b9930();
      if (cVar2 != '\0') {
        if (*(int *)(iVar3 + 0xe8) == 5) {
          iVar3 = *(int *)(iVar3 + 0x3e0);
          piVar12 = (int *)(iVar3 + 0x6c);
          local_1c = 0;
          local_18 = 0;
          param_3 = (int *)0x0;
          do {
            if (param_3 < (int *)0x10) {
              piVar10 = (int *)((int)piVar12 + local_18);
            }
            else {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar10 = piVar12;
            }
            if (*piVar10 != -1) {
              if (param_3 < (int *)0x10) {
                piVar10 = (int *)((int)piVar12 + local_18);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar10 = piVar12;
              }
              if (piVar10[1] == 0) goto LAB_006a924e;
              if (param_3 < (int *)0x10) {
                piVar10 = (int *)((int)piVar12 + local_18);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar10 = piVar12;
              }
              lp = (void *)piVar10[1];
              if ((((lp == (void *)0x0) || (BVar9 = IsBadReadPtr(lp,0x10), BVar9 != 0)) ||
                  (*(int *)((int)lp + 8) != 0x616e4f62)) ||
                 ((DAT_00768398 != '\0' && (*(int *)((int)lp + 0xdc) == 0)))) {
                if (param_3 < (int *)0x10) {
                  *(undefined4 *)(iVar3 + 0x70 + local_18) = 0;
                  piVar10 = (int *)(local_18 + (int)piVar12);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  *(undefined4 *)(iVar3 + 0x70) = 0;
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar10 = piVar12;
                }
                piVar10[2] = 0;
              }
            }
            local_1c = local_1c + 1;
            param_3 = (int *)((int)param_3 + 1);
            local_18 = local_18 + 0xc;
          } while ((int)param_3 < 0x10);
          local_1c = -1;
LAB_006a924e:
          param_3 = (int *)Tcl_NewIntObj(local_1c);
          *param_3 = *param_3 + 1;
          FUN_006bc670(&param_3);
          FUN_006bad60();
          uVar15 = 0;
        }
        else {
          param_3 = (int *)Tcl_NewIntObj(0xffffffff);
          *param_3 = *param_3 + 1;
          FUN_006bc670(&param_3);
          FUN_006bad60();
          uVar15 = 0;
        }
        goto LAB_006a94d9;
      }
      cVar2 = FUN_006b9930();
      if (cVar2 == '\0') {
        cVar2 = FUN_006b9930();
        if (cVar2 == '\0') {
          cVar2 = FUN_006b9930();
          if (cVar2 != '\0') {
            if (*(int *)(iVar3 + 0xe8) == 5) {
              if ((int)param_3 < 4) {
                FUN_006bc8f0(3);
                goto LAB_006a94d4;
              }
              puVar7 = (undefined4 *)FUN_004295e0(3);
              param_3 = (int *)*puVar7;
              if (param_3 != (int *)0x0) {
                *param_3 = *param_3 + 1;
              }
              uVar6 = FUN_006baee0();
              FUN_006bad60();
              if (0xf < uVar6) goto LAB_006a94a5;
              uVar15 = 0;
              iVar8 = *(int *)(*(int *)(iVar3 + 0x3e0) + 0x74 + uVar6 * 0xc) + -1;
              if (iVar8 < 0) {
                iVar8 = 0;
              }
              *(int *)(*(int *)(iVar3 + 0x3e0) + 0x74 + uVar6 * 0xc) = iVar8;
              goto LAB_006a94d9;
            }
            goto LAB_006a8f29;
          }
          cVar2 = FUN_006b9930();
          if (cVar2 != '\0') {
            if (*(int *)(iVar3 + 0xe8) == 5) {
              if ((int)param_3 < 4) {
                FUN_006bc8f0(3);
                goto LAB_006a94d4;
              }
              puVar7 = (undefined4 *)FUN_004295e0(3);
              param_3 = (int *)*puVar7;
              if (param_3 != (int *)0x0) {
                *param_3 = *param_3 + 1;
              }
              uVar6 = FUN_006baee0();
              FUN_006bad60();
              if (0xf < uVar6) goto LAB_006a94a5;
              uVar15 = 0;
              *(undefined4 *)(*(int *)(iVar3 + 0x3e0) + 0x74 + uVar6 * 0xc) = 0;
              goto LAB_006a94d9;
            }
            goto LAB_006a8f29;
          }
          cVar2 = FUN_006b9930();
          if (cVar2 != '\0') {
            if (*(int *)(iVar3 + 0xe8) == 5) {
              iVar3 = *(int *)(iVar3 + 0x3e0) + 0x6c;
              local_24 = 0;
              local_1c = 0xffffffff;
              uVar6 = 0;
              param_3 = (int *)0x0;
              do {
                if (uVar6 < 0x10) {
                  iVar8 = (int)param_3 + iVar3;
                }
                else {
                  (*pcVar14)(0xc000008c,1,0,0);
                  iVar8 = iVar3;
                }
                if (*(int *)(iVar8 + 8) != 0) {
                  if (uVar6 < 0x10) {
                    iVar8 = (int)param_3 + iVar3;
                  }
                  else {
                    (*pcVar14)(0xc000008c,1,0,0);
                    iVar8 = iVar3;
                  }
                  if (*(int *)(iVar8 + 4) != 0) {
                    if (uVar6 < 0x10) {
                      iVar8 = (int)param_3 + iVar3;
                      local_20 = iVar8;
                    }
                    else {
                      (*pcVar14)(0xc000008c,1,0,0);
                      iVar8 = iVar3 + (int)param_3;
                      local_20 = iVar3;
                    }
                    pcVar14 = RaiseException_exref;
                    if (local_24 < *(int *)(local_20 + 8)) {
                      if (0xf < uVar6) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        iVar8 = iVar3;
                      }
                      local_24 = *(int *)(iVar8 + 8);
                      local_1c = uVar6;
                    }
                  }
                }
                uVar6 = uVar6 + 1;
                param_3 = (int *)((int)param_3 + 0xc);
              } while ((int)uVar6 < 0x10);
              goto LAB_006a9480;
            }
            goto LAB_006a8f29;
          }
          if (local_14 + 3 == (int *)0x0) {
            piVar12 = (int *)0x0;
          }
          else {
            piVar12 = (int *)Tcl_NewStringObj(local_14 + 3,0xffffffff,extraout_ECX);
            *piVar12 = *piVar12 + 1;
          }
          pcVar11 = "invalid param";
        }
        else {
          if (*(int *)(iVar3 + 0xe8) == 5) {
            if (3 < (int)param_3) {
              puVar7 = (undefined4 *)FUN_004295e0(3);
              param_3 = (int *)*puVar7;
              if (param_3 != (int *)0x0) {
                *param_3 = *param_3 + 1;
              }
              uVar6 = FUN_006baee0();
              FUN_006bad60();
              if (0xf < uVar6) goto LAB_006a924a;
              local_1c = *(int *)(*(int *)(iVar3 + 0x3e0) + 0x74 + uVar6 * 0xc);
              goto LAB_006a924e;
            }
            FUN_006bc8f0(3);
            goto LAB_006a94d4;
          }
LAB_006a8f29:
          puVar7 = (undefined4 *)FUN_004295e0(2);
          piVar12 = (int *)*puVar7;
          if (piVar12 != (int *)0x0) {
            *piVar12 = *piVar12 + 1;
          }
          pcVar11 = "not a production type";
        }
        FUN_006bc6a0(pcVar11,piVar12);
      }
      else {
        if (*(int *)(iVar3 + 0xe8) != 5) goto LAB_006a8f29;
        if (3 < (int)param_3) {
          puVar7 = (undefined4 *)FUN_004295e0(3);
          param_3 = (int *)*puVar7;
          if (param_3 != (int *)0x0) {
            *param_3 = *param_3 + 1;
          }
          uVar6 = FUN_006baee0();
          FUN_006bad60();
          if (0xf < uVar6) goto LAB_006a94a5;
          piVar12 = (int *)(*(int *)(iVar3 + 0x3e0) + 0x74 + uVar6 * 0xc);
          *piVar12 = *piVar12 + 1;
          uVar15 = 0;
          goto LAB_006a94d9;
        }
        FUN_006bc8f0(3);
      }
      goto LAB_006a94d4;
    }
    if (*(int *)(iVar3 + 0xe8) != 5) goto LAB_006a8f29;
    if ((int)param_3 < 5) goto LAB_006a8d6c;
    puVar7 = (undefined4 *)FUN_004295e0(3);
    param_3 = (int *)*puVar7;
    if (param_3 != (int *)0x0) {
      *param_3 = *param_3 + 1;
    }
    uVar6 = FUN_006baee0();
    FUN_006bad60();
    iVar8 = FUN_005c71c0(param_4,4,4);
    if ((iVar8 == 0) && (uVar6 < 0x10)) {
      *(undefined4 *)(*(int *)(iVar3 + 0x3e0) + 0x74 + uVar6 * 0xc) = 0;
      uVar15 = 0;
      *(undefined4 *)(*(int *)(iVar3 + 0x3e0) + 0x70 + uVar6 * 0xc) = 0;
    }
    else {
      if (0xf < uVar6) goto LAB_006a94a5;
      uVar15 = 0;
      *(int *)(*(int *)(iVar3 + 0x3e0) + 0x70 + uVar6 * 0xc) = iVar8;
    }
  }
LAB_006a94d9:
  local_8._0_1_ = 0x1d;
  if ((local_14 != (int *)0x0) && (*local_14 = *local_14 + -1, *local_14 == 0)) {
    FUN_006ba940();
  }
LAB_006a94ed:
  local_8._0_1_ = 0x1e;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0x1f);
  FUN_004297b0(0);
  if (local_34 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar15;
}

