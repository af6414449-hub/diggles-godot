
undefined4
CTclGlobalMethods__Option(undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  undefined **ppuVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  byte *pbVar9;
  char *pcVar10;
  undefined4 uVar11;
  int *piVar12;
  byte *pbVar13;
  int iVar14;
  bool bVar15;
  undefined8 uVar16;
  int local_48;
  undefined4 *local_38;
  uint local_34;
  int local_30;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070b92d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca6c28) &&
     (FUN_006cebf4(&DAT_00ca6c28,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar2 = DAT_00783650,
     DAT_00ca6c28 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca6c2c = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::Option()";
    *(int *)(&DAT_00773650 + iVar8) = iVar2;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca6c28);
  }
  iVar8 = DAT_00ca6c2c;
  uVar11 = *(undefined4 *)(&DAT_00773650 + DAT_00ca6c2c * 0x40);
  iVar2 = FUN_0043fcc0();
  *(undefined4 *)(iVar2 + *(int *)(iVar2 + 0x8000) * 4) = uVar11;
  *(int *)(iVar2 + 0x8000) = *(int *)(iVar2 + 0x8000) + 1;
  iVar2 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar2 == 0) {
    uVar16 = FUN_006bd180();
    iVar2 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar16;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar2 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar12 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar12 < 2) {
    FUN_006bc8f0(1);
    uVar11 = 1;
    goto LAB_00620b82;
  }
  if (local_30 < 2) {
    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    puVar5 = local_38;
    if (local_34 == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
  }
  else {
    if (local_34 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    puVar5 = local_38 + 1;
  }
  piVar12 = (int *)*puVar5;
  if (piVar12 != (int *)0x0) {
    *piVar12 = *piVar12 + 1;
  }
  local_8 = CONCAT31(local_8._1_3_,3);
  local_1c = piVar12;
  local_14 = piVar12;
  if (piVar12 == (int *)0x0) {
    ppuVar3 = &PTR_0071ce50;
  }
  else {
    ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
  }
  pbVar9 = &DAT_0072e624;
  do {
    bVar1 = *(byte *)ppuVar3;
    bVar15 = bVar1 < *pbVar9;
    if (bVar1 != *pbVar9) {
LAB_006202e0:
      uVar4 = -(uint)bVar15 | 1;
      goto LAB_006202e5;
    }
    if (bVar1 == 0) break;
    bVar1 = *(byte *)((int)ppuVar3 + 1);
    bVar15 = bVar1 < pbVar9[1];
    if (bVar1 != pbVar9[1]) goto LAB_006202e0;
    ppuVar3 = (undefined **)((int)ppuVar3 + 2);
    pbVar9 = pbVar9 + 2;
  } while (bVar1 != 0);
  uVar4 = 0;
LAB_006202e5:
  if (uVar4 == 0) {
    if ((int)param_3 < 3) {
LAB_006207cb:
      FUN_006bc8f0(2);
      goto LAB_00620b68;
    }
    puVar5 = (undefined4 *)FUN_004295e0(2);
    piVar12 = (int *)*puVar5;
    if (piVar12 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      *piVar12 = *piVar12 + 1;
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
    }
    iVar2 = FUN_0055c0f0(ppuVar3);
    if (iVar2 == -1) {
      iVar2 = 0;
    }
    piVar6 = (int *)Tcl_NewIntObj(iVar2);
    *piVar6 = *piVar6 + 1;
    iVar2 = *piVar6;
    if (local_48 != 0) {
      Tcl_SetObjResult(local_48,piVar6);
      iVar2 = *piVar6;
    }
    *piVar6 = iVar2 + -1;
    if (iVar2 + -1 < 1) {
      TclFreeObj(piVar6);
    }
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      TclFreeObj(piVar12);
    }
    uVar11 = 0;
    piVar12 = local_14;
  }
  else {
    if (piVar12 == (int *)0x0) {
      ppuVar3 = &PTR_0071ce50;
    }
    else {
      ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
    }
    pcVar10 = "getname";
    do {
      bVar1 = *(byte *)ppuVar3;
      bVar15 = bVar1 < (byte)*pcVar10;
      if (bVar1 != *pcVar10) {
LAB_006203c0:
        uVar4 = -(uint)bVar15 | 1;
        goto LAB_006203c5;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar3 + 1);
      bVar15 = bVar1 < ((byte *)pcVar10)[1];
      if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_006203c0;
      ppuVar3 = (undefined **)((int)ppuVar3 + 2);
      pcVar10 = (char *)((byte *)pcVar10 + 2);
    } while (bVar1 != 0);
    uVar4 = 0;
LAB_006203c5:
    if (uVar4 == 0) {
      if ((int)param_3 < 3) goto LAB_006207cb;
      puVar5 = (undefined4 *)FUN_004295e0(2);
      local_20 = (int *)*puVar5;
      if (local_20 != (int *)0x0) {
        *local_20 = *local_20 + 1;
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      if (local_20 == (int *)0x0) {
        ppuVar3 = &PTR_0071ce50;
      }
      else {
        ppuVar3 = (undefined **)Tcl_GetStringFromObj(local_20,0);
      }
      iVar2 = DAT_00772400;
      piVar12 = (int *)(DAT_00772400 + 0xa078);
      param_3 = (int *)FUN_0055bfb0(ppuVar3);
      if (param_3 == (int *)0xffffffff) {
        piVar12 = (int *)FUN_006ba810(0x19);
        piVar12[1] = 4;
        *(undefined1 *)(piVar12 + 3) = 0;
        piVar12[2] = 0;
        *piVar12 = 1;
      }
      else {
        piVar6 = *(int **)(iVar2 + 0xa07c);
        if (piVar6 <= param_3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar6 = *(int **)(iVar2 + 0xa07c);
        }
        iVar8 = *piVar12;
        iVar14 = (int)param_3 * 0x1c;
        local_24 = *(int **)(iVar8 + 8 + iVar14);
        if (piVar6 <= param_3) {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          iVar8 = *piVar12;
        }
        local_24 = (int *)FUN_0055c090(iVar14 + iVar8,local_24);
        if (local_24 == (int *)0xffffffff) {
          FUN_006b8fb0(&PTR_0071ce50);
          piVar12 = param_3;
        }
        else {
          if (*(int **)(iVar2 + 0xa07c) <= param_3) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          piVar6 = local_24;
          iVar2 = *piVar12;
          if (*(int **)(iVar2 + iVar14 + 0x18) <= local_24) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          piVar12 = *(int **)(*(int *)(iVar2 + iVar14 + 0x14) + 4 + (int)piVar6 * 8);
          if (piVar12 != (int *)0x0) {
            *piVar12 = *piVar12 + 1;
          }
        }
      }
      if (piVar12 + 3 == (int *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)Tcl_NewStringObj(piVar12 + 3,0xffffffff);
        *piVar6 = *piVar6 + 1;
      }
      param_3 = piVar6;
      FUN_006bc670(&param_3);
      if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
        TclFreeObj(piVar6);
      }
      local_8 = CONCAT31(local_8._1_3_,5);
      if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 == 0)) {
        FUN_006ba940();
      }
      FUN_006bad60();
      uVar11 = 0;
      piVar12 = local_14;
    }
    else {
      if (piVar12 == (int *)0x0) {
        ppuVar3 = &PTR_0071ce50;
      }
      else {
        ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
      }
      pbVar9 = &DAT_0072e630;
      do {
        bVar1 = *(byte *)ppuVar3;
        bVar15 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_00620596:
          uVar4 = -(uint)bVar15 | 1;
          goto LAB_0062059b;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar3 + 1);
        bVar15 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_00620596;
        ppuVar3 = (undefined **)((int)ppuVar3 + 2);
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      uVar4 = 0;
LAB_0062059b:
      if (uVar4 == 0) {
        if ((int)param_3 < 4) {
          FUN_006bc8f0(3);
          goto LAB_00620b68;
        }
        puVar5 = (undefined4 *)FUN_004295e0(2);
        local_1c = (int *)*puVar5;
        if (local_1c != (int *)0x0) {
          *local_1c = *local_1c + 1;
        }
        puVar5 = (undefined4 *)FUN_004295e0(3);
        param_3 = (int *)*puVar5;
        if (param_3 != (int *)0x0) {
          *param_3 = *param_3 + 1;
        }
        uVar11 = FUN_006baee0();
        uVar7 = FUN_006bafc0(uVar11);
        FUN_0055c140(uVar7,uVar11);
        FUN_006bad60();
        FUN_006bad60();
        uVar11 = 0;
      }
      else {
        if (piVar12 == (int *)0x0) {
          ppuVar3 = &PTR_0071ce50;
        }
        else {
          ppuVar3 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
        }
        pcVar10 = "setname";
        do {
          bVar1 = *(byte *)ppuVar3;
          bVar15 = bVar1 < (byte)*pcVar10;
          if (bVar1 != *pcVar10) {
LAB_00620654:
            uVar4 = -(uint)bVar15 | 1;
            goto LAB_00620659;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar3 + 1);
          bVar15 = bVar1 < ((byte *)pcVar10)[1];
          if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00620654;
          ppuVar3 = (undefined **)((int)ppuVar3 + 2);
          pcVar10 = (char *)((byte *)pcVar10 + 2);
        } while (bVar1 != 0);
        uVar4 = 0;
LAB_00620659:
        if (uVar4 == 0) {
          if ((int)param_3 < 4) {
            FUN_006bc8f0(3);
            goto LAB_00620b68;
          }
          puVar5 = (undefined4 *)FUN_004295e0(2);
          local_20 = (int *)*puVar5;
          if (local_20 != (int *)0x0) {
            *local_20 = *local_20 + 1;
          }
          puVar5 = (undefined4 *)FUN_004295e0(3);
          local_14 = (int *)*puVar5;
          if (local_14 != (int *)0x0) {
            *local_14 = *local_14 + 1;
          }
          local_24 = (int *)FUN_006bafc0();
          uVar11 = FUN_006bafc0();
          iVar2 = DAT_00772400;
          piVar6 = (int *)(DAT_00772400 + 0xa078);
          param_3 = (int *)FUN_0055bfb0(uVar11);
          if (param_3 != (int *)0xffffffff) {
            if (*(int **)(iVar2 + 0xa07c) <= param_3) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            }
            local_18 = (int *)((int)param_3 * 0x1c);
            local_1c = (int *)FUN_0055c020(*piVar6 + (int)local_18,local_24);
            if (local_1c != (int *)0xffffffff) {
              if (*(int **)(iVar2 + 0xa07c) <= param_3) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              local_24 = (int *)(*piVar6 + (int)local_18);
              if ((int *)local_24[6] <= local_1c) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              local_24 = (int *)(local_24[5] + (int)local_1c * 8);
              if (*(int **)(iVar2 + 0xa07c) <= param_3) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              *(int *)(*piVar6 + 8 + (int)local_18) = *local_24;
            }
          }
          FUN_006bad60();
          FUN_006bad60();
          uVar11 = 0;
        }
        else {
          pcVar10 = "getinfo";
          pbVar9 = (byte *)FUN_006bafc0();
          do {
            bVar1 = *pbVar9;
            bVar15 = bVar1 < (byte)*pcVar10;
            if (bVar1 != *pcVar10) {
LAB_006207b8:
              uVar4 = -(uint)bVar15 | 1;
              goto LAB_006207bd;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar9[1];
            bVar15 = bVar1 < ((byte *)pcVar10)[1];
            if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_006207b8;
            pbVar9 = pbVar9 + 2;
            pcVar10 = (char *)((byte *)pcVar10 + 2);
          } while (bVar1 != 0);
          uVar4 = 0;
LAB_006207bd:
          if (uVar4 == 0) {
            if ((int)param_3 < 3) goto LAB_006207cb;
            puVar5 = (undefined4 *)FUN_004295e0(2);
            piVar6 = (int *)*puVar5;
            if (piVar6 != (int *)0x0) {
              *piVar6 = *piVar6 + 1;
            }
            local_18 = piVar6;
            FUN_006bb910();
            local_8 = CONCAT31(local_8._1_3_,7);
            uVar11 = FUN_006bafc0();
            local_24 = (int *)FUN_0055bfb0(uVar11);
            if (local_24 == (int *)0xffffffff) {
              if (piVar6 != (int *)0x0) {
                *piVar6 = *piVar6 + 1;
              }
              FUN_006bc6a0("unknown option",piVar6);
              FUN_006bad60();
              FUN_006bad60();
              goto LAB_00620b68;
            }
            iVar2 = FUN_0043d740(local_24);
            uVar4 = 0;
            iVar2 = *(int *)(iVar2 + 0x18);
            if (0 < iVar2) {
              local_1c = (int *)((int)local_24 * 0x1c);
              do {
                iVar8 = DAT_00772400;
                if (*(int **)(DAT_00772400 + 0xa07c) <= local_24) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                piVar12 = local_1c;
                iVar8 = *(int *)(iVar8 + 0xa078);
                if (*(uint *)((int)local_1c + iVar8 + 0x18) <= uVar4) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                iVar8 = *(int *)(*(int *)((int)piVar12 + iVar8 + 0x14) + 4 + uVar4 * 8) + 0xc;
                if (iVar8 == 0) {
                  piVar12 = (int *)0x0;
                }
                else {
                  piVar12 = (int *)Tcl_NewStringObj(iVar8,0xffffffff);
                  *piVar12 = *piVar12 + 1;
                }
                local_20 = piVar12;
                FUN_006bb930(&local_20);
                if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
                  TclFreeObj(piVar12);
                }
                uVar4 = uVar4 + 1;
                piVar12 = local_14;
              } while ((int)uVar4 < iVar2);
            }
            FUN_006bc670(&param_3);
            FUN_006bad60();
            FUN_006bad60();
            uVar11 = 0;
          }
          else {
            pcVar10 = "getdesc";
            pbVar9 = (byte *)FUN_006bafc0();
            do {
              bVar1 = *pbVar9;
              bVar15 = bVar1 < (byte)*pcVar10;
              if (bVar1 != *pcVar10) {
LAB_00620970:
                uVar4 = -(uint)bVar15 | 1;
                goto LAB_00620975;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar9[1];
              bVar15 = bVar1 < ((byte *)pcVar10)[1];
              if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00620970;
              pbVar9 = pbVar9 + 2;
              pcVar10 = (char *)((byte *)pcVar10 + 2);
            } while (bVar1 != 0);
            uVar4 = 0;
LAB_00620975:
            if (uVar4 == 0) {
              if ((int)param_3 < 3) {
                FUN_006bc8f0(2);
              }
              else {
                puVar5 = (undefined4 *)FUN_004295e0(2);
                piVar6 = (int *)*puVar5;
                if (piVar6 != (int *)0x0) {
                  *piVar6 = *piVar6 + 1;
                }
                param_3 = piVar6;
                FUN_006bb910();
                local_8 = CONCAT31(local_8._1_3_,9);
                uVar11 = FUN_006bafc0();
                iVar2 = FUN_0055bfb0(uVar11);
                if (iVar2 != -1) {
                  iVar2 = FUN_0043d740(iVar2);
                  iVar2 = *(int *)(iVar2 + 4) + 0xc;
                  if (iVar2 == 0) {
                    piVar6 = (int *)0x0;
                  }
                  else {
                    piVar6 = (int *)Tcl_NewStringObj(iVar2,0xffffffff);
                    *piVar6 = *piVar6 + 1;
                  }
                  local_24 = piVar6;
                  FUN_006bc670(&local_24);
                  if ((piVar6 != (int *)0x0) && (*piVar6 = *piVar6 + -1, *piVar6 < 1)) {
                    TclFreeObj(piVar6);
                  }
                  FUN_006bad60();
                  FUN_006bad60();
                  uVar11 = 0;
                  goto LAB_00620b6d;
                }
                if (piVar6 != (int *)0x0) {
                  *piVar6 = *piVar6 + 1;
                }
                FUN_006bc6a0("unknown option",piVar6);
                FUN_006bad60();
                FUN_006bad60();
              }
            }
            else {
              pbVar13 = &DAT_0072e64c;
              pbVar9 = (byte *)FUN_006bafc0();
              do {
                bVar1 = *pbVar9;
                bVar15 = bVar1 < *pbVar13;
                if (bVar1 != *pbVar13) {
LAB_00620a93:
                  uVar4 = -(uint)bVar15 | 1;
                  goto LAB_00620a98;
                }
                if (bVar1 == 0) break;
                bVar1 = pbVar9[1];
                bVar15 = bVar1 < pbVar13[1];
                if (bVar1 != pbVar13[1]) goto LAB_00620a93;
                pbVar9 = pbVar9 + 2;
                pbVar13 = pbVar13 + 2;
              } while (bVar1 != 0);
              uVar4 = 0;
LAB_00620a98:
              if (uVar4 == 0) {
                FUN_006bb910();
                uVar4 = 0;
                iVar2 = *(int *)(DAT_00772400 + 0xa07c);
                if (0 < iVar2) {
                  param_3 = (int *)0x0;
                  do {
                    iVar8 = DAT_00772400;
                    if (*(uint *)(DAT_00772400 + 0xa07c) <= uVar4) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    }
                    iVar8 = *(int *)(*(int *)(iVar8 + 0xa078) + (int)param_3) + 0xc;
                    if (iVar8 == 0) {
                      piVar12 = (int *)0x0;
                    }
                    else {
                      piVar12 = (int *)Tcl_NewStringObj(iVar8,0xffffffff);
                      *piVar12 = *piVar12 + 1;
                    }
                    local_24 = piVar12;
                    FUN_006bb930(&local_24);
                    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
                      TclFreeObj(piVar12);
                    }
                    param_3 = param_3 + 7;
                    uVar4 = uVar4 + 1;
                    piVar12 = local_14;
                  } while ((int)uVar4 < iVar2);
                }
                FUN_006bc670(&local_1c);
                FUN_006bad60();
                uVar11 = 0;
                goto LAB_00620b6d;
              }
              if (piVar12 != (int *)0x0) {
                *piVar12 = *piVar12 + 1;
              }
              FUN_006bc6a0("invalid command",piVar12);
            }
LAB_00620b68:
            uVar11 = 1;
          }
        }
      }
    }
  }
LAB_00620b6d:
  if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
    TclFreeObj(piVar12);
  }
LAB_00620b82:
  local_8._0_1_ = 10;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,0xb);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  FUN_006bc0d0();
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar11;
}

