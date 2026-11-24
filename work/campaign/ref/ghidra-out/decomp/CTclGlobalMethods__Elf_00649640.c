
undefined4 CTclGlobalMethods__Elf(undefined4 param_1,undefined4 param_2,int *param_3,int param_4)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined **ppuVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 *puVar9;
  char *pcVar10;
  byte *pbVar11;
  int *piVar12;
  code *pcVar13;
  bool bVar14;
  bool bVar15;
  int *in_XMM0_Da;
  undefined8 uVar16;
  undefined4 uVar17;
  int local_58;
  float local_48;
  float local_44;
  float local_40;
  int local_3c;
  int local_38;
  int local_34;
  int *local_30;
  undefined4 *local_2c;
  int *local_28;
  int *local_24;
  undefined1 *local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070df38;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca7120) &&
     (FUN_006cebf4(&DAT_00ca7120,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar3 = DAT_00783650,
     DAT_00ca7120 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca7124 = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::Elf()";
    *(int *)(&DAT_00773650 + iVar8) = iVar3;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca7120);
  }
  iVar8 = DAT_00ca7124;
  local_2c = &DAT_00ca7124;
  uVar17 = *(undefined4 *)(&DAT_00773650 + DAT_00ca7124 * 0x40);
  iVar3 = FUN_0043fcc0();
  *(undefined4 *)(iVar3 + *(int *)(iVar3 + 0x8000) * 4) = uVar17;
  *(int *)(iVar3 + 0x8000) = *(int *)(iVar3 + 0x8000) + 1;
  iVar3 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar3 == 0) {
    uVar16 = FUN_006bd180();
    iVar3 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar16;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar3 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  local_8._0_1_ = 1;
  if ((int)param_3 < 2) {
    FUN_006bc8f0(2);
    goto LAB_006496fa;
  }
  piVar12 = *(int **)(param_4 + 4);
  if (piVar12 != (int *)0x0) {
    *piVar12 = *piVar12 + 1;
  }
  local_8._0_1_ = 2;
  local_30 = piVar12;
  local_28 = piVar12;
  if (DAT_0076a274 == (int *)0x0) {
    piVar4 = (int *)FUN_006ba810(0x26);
    local_8._0_1_ = 3;
    local_24 = piVar4;
    if (piVar4 == (int *)0x0) {
      DAT_0076a274 = (int *)0x0;
    }
    else {
      FUN_00424cc0();
      DAT_0076a274 = piVar4;
    }
  }
  piVar4 = DAT_0076a274;
  local_8._0_1_ = 2;
  *(undefined1 *)((int)DAT_0076a274 + 0x21) = 1;
  if (piVar12 == (int *)0x0) {
    ppuVar5 = &PTR_0071ce50;
  }
  else {
    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
  }
  pcVar10 = "action";
  do {
    bVar1 = *(byte *)ppuVar5;
    bVar14 = bVar1 < (byte)*pcVar10;
    if (bVar1 != *pcVar10) {
LAB_006497c3:
      uVar6 = -(uint)bVar14 | 1;
      goto LAB_006497c8;
    }
    if (bVar1 == 0) break;
    bVar1 = *(byte *)((int)ppuVar5 + 1);
    bVar14 = bVar1 < ((byte *)pcVar10)[1];
    if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_006497c3;
    ppuVar5 = (undefined **)((int)ppuVar5 + 2);
    pcVar10 = (char *)((byte *)pcVar10 + 2);
  } while (bVar1 != 0);
  uVar6 = 0;
LAB_006497c8:
  if (uVar6 == 0) {
    if (param_3 != (int *)0x3) goto LAB_006497d6;
    piVar7 = *(int **)(param_4 + 8);
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
    }
    local_8._0_1_ = 4;
    local_28 = piVar7;
    if (piVar7 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
    }
    FUN_006b8fb0(ppuVar5);
    iVar3 = FUN_00427950(&param_3);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    iVar8 = piVar4[0xc] + -1;
    if (iVar3 <= piVar4[0xc] + -1) {
      iVar8 = iVar3;
    }
    piVar4[0xf] = iVar8;
    local_8._0_1_ = 5;
    if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
      FUN_006ba940();
    }
    pcVar13 = TclFreeObj_exref;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + -1;
      iVar3 = *piVar7;
      goto LAB_00649878;
    }
LAB_00649880:
    if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
      (*pcVar13)(piVar12);
    }
  }
  else {
    if (piVar12 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
    }
    pbVar11 = &DAT_00730254;
    do {
      bVar1 = *(byte *)ppuVar5;
      bVar14 = bVar1 < *pbVar11;
      if (bVar1 != *pbVar11) {
LAB_006498d8:
        uVar6 = -(uint)bVar14 | 1;
        goto LAB_006498dd;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar5 + 1);
      bVar14 = bVar1 < pbVar11[1];
      if (bVar1 != pbVar11[1]) goto LAB_006498d8;
      ppuVar5 = (undefined **)((int)ppuVar5 + 2);
      pbVar11 = pbVar11 + 2;
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_006498dd:
    if (uVar6 == 0) {
      if (param_3 == (int *)0x3) {
        param_3 = *(int **)(param_4 + 8);
        if (param_3 != (int *)0x0) {
          *param_3 = *param_3 + 1;
        }
        iVar3 = FUN_006baee0();
        piVar4[0xd] = iVar3;
        FUN_006bad60();
      }
      piVar7 = (int *)Tcl_NewIntObj(piVar4[0xd]);
      *piVar7 = *piVar7 + 1;
      iVar3 = *piVar7;
      if (local_58 != 0) {
        Tcl_SetObjResult(local_58,piVar7);
        iVar3 = *piVar7;
      }
      pcVar13 = TclFreeObj_exref;
      iVar3 = iVar3 + -1;
      *piVar7 = iVar3;
LAB_00649878:
      if (iVar3 < 1) {
        (*pcVar13)(piVar7);
      }
      goto LAB_00649880;
    }
    if (piVar12 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
    }
    iVar3 = param_4;
    pcVar10 = "finishcode";
    do {
      bVar1 = *(byte *)ppuVar5;
      bVar14 = bVar1 < (byte)*pcVar10;
      if (bVar1 != *pcVar10) {
LAB_00649980:
        uVar6 = -(uint)bVar14 | 1;
        goto LAB_00649985;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar5 + 1);
      bVar14 = bVar1 < ((byte *)pcVar10)[1];
      if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00649980;
      ppuVar5 = (undefined **)((int)ppuVar5 + 2);
      pcVar10 = (char *)((byte *)pcVar10 + 2);
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_00649985:
    if (uVar6 == 0) {
      if (param_3 != (int *)&DAT_00000004) {
        uVar17 = 3;
        goto LAB_006497d8;
      }
      iVar8 = FUN_005c71c0(param_4,3,2);
      param_3 = *(int **)(iVar3 + 0xc);
      if (param_3 != (int *)0x0) {
        *param_3 = *param_3 + 1;
      }
      if (iVar8 != 0) {
        piVar4[9] = *(int *)(iVar8 + 0xdc);
        piVar7 = (int *)piVar4[10];
        piVar4[10] = (int)param_3;
        if (param_3 != (int *)0x0) {
          *param_3 = *param_3 + 1;
        }
        if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
          TclFreeObj(piVar7);
        }
      }
      FUN_006bad60();
      if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
        TclFreeObj(piVar12);
      }
    }
    else {
      if (piVar12 == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
      }
      pcVar10 = "lookat";
      do {
        bVar1 = *(byte *)ppuVar5;
        bVar14 = bVar1 < (byte)*pcVar10;
        if (bVar1 != *pcVar10) {
LAB_00649a50:
          uVar6 = -(uint)bVar14 | 1;
          goto LAB_00649a55;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar5 + 1);
        bVar14 = bVar1 < ((byte *)pcVar10)[1];
        if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00649a50;
        ppuVar5 = (undefined **)((int)ppuVar5 + 2);
        pcVar10 = (char *)((byte *)pcVar10 + 2);
      } while (bVar1 != 0);
      uVar6 = 0;
LAB_00649a55:
      if (uVar6 == 0) {
        iVar3 = 0;
        if (param_3 == (int *)0x3) {
          iVar3 = FUN_005c71c0(param_4,3,2);
        }
        if (iVar3 == 0) {
          piVar4[0x13] = -1;
        }
        else {
          piVar4[0x13] = *(int *)(iVar3 + 0xdc);
        }
      }
      if (piVar12 == (int *)0x0) {
        ppuVar5 = &PTR_0071ce50;
      }
      else {
        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
      }
      pbVar11 = (byte *)&DAT_00720f40;
      do {
        bVar1 = *(byte *)ppuVar5;
        bVar14 = bVar1 < *pbVar11;
        if (bVar1 != *pbVar11) {
LAB_00649ac6:
          uVar6 = -(uint)bVar14 | 1;
          goto LAB_00649acb;
        }
        if (bVar1 == 0) break;
        bVar1 = *(byte *)((int)ppuVar5 + 1);
        bVar14 = bVar1 < pbVar11[1];
        if (bVar1 != pbVar11[1]) goto LAB_00649ac6;
        ppuVar5 = (undefined **)((int)ppuVar5 + 2);
        pbVar11 = pbVar11 + 2;
      } while (bVar1 != 0);
      uVar6 = 0;
LAB_00649acb:
      if (uVar6 == 0) {
        FUN_006b8fb0(&DAT_00720f40);
        FUN_004279c0(&param_3);
        local_8._0_1_ = 6;
        if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
          FUN_006ba940();
        }
LAB_0064a546:
        if (piVar12 == (int *)0x0) goto LAB_0064a55b;
        *piVar12 = *piVar12 + -1;
        bVar14 = *piVar12 < 0;
        bVar15 = *piVar12 == 0;
      }
      else {
        if (piVar12 == (int *)0x0) {
          ppuVar5 = &PTR_0071ce50;
        }
        else {
          ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
        }
        pbVar11 = &DAT_0072e56c;
        do {
          bVar1 = *(byte *)ppuVar5;
          bVar14 = bVar1 < *pbVar11;
          if (bVar1 != *pbVar11) {
LAB_00649b45:
            uVar6 = -(uint)bVar14 | 1;
            goto LAB_00649b4a;
          }
          if (bVar1 == 0) break;
          bVar1 = *(byte *)((int)ppuVar5 + 1);
          bVar14 = bVar1 < pbVar11[1];
          if (bVar1 != pbVar11[1]) goto LAB_00649b45;
          ppuVar5 = (undefined **)((int)ppuVar5 + 2);
          pbVar11 = pbVar11 + 2;
        } while (bVar1 != 0);
        uVar6 = 0;
LAB_00649b4a:
        if (uVar6 != 0) {
          if (piVar12 == (int *)0x0) {
            ppuVar5 = &PTR_0071ce50;
          }
          else {
            ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
          }
          pcVar10 = "drawoverui";
          do {
            bVar1 = *(byte *)ppuVar5;
            bVar14 = bVar1 < (byte)*pcVar10;
            if (bVar1 != *pcVar10) {
LAB_00649bb0:
              uVar6 = -(uint)bVar14 | 1;
              goto LAB_00649bb5;
            }
            if (bVar1 == 0) break;
            bVar1 = *(byte *)((int)ppuVar5 + 1);
            bVar14 = bVar1 < ((byte *)pcVar10)[1];
            if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00649bb0;
            ppuVar5 = (undefined **)((int)ppuVar5 + 2);
            pcVar10 = (char *)((byte *)pcVar10 + 2);
          } while (bVar1 != 0);
          uVar6 = 0;
LAB_00649bb5:
          if (uVar6 == 0) {
            uVar2 = (char)piVar4[0x1f];
            if (param_3 == (int *)0x3) {
              local_14 = *(int **)(param_4 + 8);
              if (local_14 != (int *)0x0) {
                *local_14 = *local_14 + 1;
              }
              uVar2 = FUN_006baf10();
              param_3 = (int *)CONCAT13(uVar2,param_3._0_3_);
              FUN_006bad60();
              uVar2 = param_3._3_1_;
            }
            *(undefined1 *)(piVar4 + 0x1f) = uVar2;
            param_3 = (int *)Tcl_NewBooleanObj(uVar2);
            *param_3 = *param_3 + 1;
            puVar9 = &param_3;
LAB_0064a535:
            FUN_006bc670(puVar9);
LAB_0064a541:
            FUN_006bad60();
          }
          else {
            if (piVar12 == (int *)0x0) {
              ppuVar5 = &PTR_0071ce50;
            }
            else {
              ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
            }
            pbVar11 = (byte *)&DAT_00720f08;
            do {
              bVar1 = *(byte *)ppuVar5;
              bVar14 = bVar1 < *pbVar11;
              if (bVar1 != *pbVar11) {
LAB_00649c40:
                uVar6 = -(uint)bVar14 | 1;
                goto LAB_00649c45;
              }
              if (bVar1 == 0) break;
              bVar1 = *(byte *)((int)ppuVar5 + 1);
              bVar14 = bVar1 < pbVar11[1];
              if (bVar1 != pbVar11[1]) goto LAB_00649c40;
              ppuVar5 = (undefined **)((int)ppuVar5 + 2);
              pbVar11 = pbVar11 + 2;
            } while (bVar1 != 0);
            uVar6 = 0;
LAB_00649c45:
            if (uVar6 == 0) {
              FUN_006b8fb0(&DAT_00720f08);
              FUN_004279c0(&param_3);
              local_8._0_1_ = 7;
              if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
                FUN_006ba940();
              }
            }
            else {
              if (piVar12 == (int *)0x0) {
                ppuVar5 = &PTR_0071ce50;
              }
              else {
                ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
              }
              pcVar10 = "standard";
              do {
                bVar1 = *(byte *)ppuVar5;
                bVar14 = bVar1 < (byte)*pcVar10;
                if (bVar1 != *pcVar10) {
LAB_00649cc0:
                  uVar6 = -(uint)bVar14 | 1;
                  goto LAB_00649cc5;
                }
                if (bVar1 == 0) break;
                bVar1 = *(byte *)((int)ppuVar5 + 1);
                bVar14 = bVar1 < ((byte *)pcVar10)[1];
                if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00649cc0;
                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                pcVar10 = (char *)((byte *)pcVar10 + 2);
              } while (bVar1 != 0);
              uVar6 = 0;
LAB_00649cc5:
              if (uVar6 == 0) {
                FUN_006b8fb0("standard");
                FUN_004279c0(&param_3);
                local_8._0_1_ = 8;
                if ((param_3 != (int *)0x0) && (*param_3 = *param_3 + -1, *param_3 == 0)) {
                  FUN_006ba940();
                }
              }
              else {
                if (piVar12 == (int *)0x0) {
                  ppuVar5 = &PTR_0071ce50;
                }
                else {
                  ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                }
                pbVar11 = &DAT_00727b58;
                do {
                  bVar1 = *(byte *)ppuVar5;
                  bVar14 = bVar1 < *pbVar11;
                  if (bVar1 != *pbVar11) {
LAB_00649d40:
                    uVar6 = -(uint)bVar14 | 1;
                    goto LAB_00649d45;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = *(byte *)((int)ppuVar5 + 1);
                  bVar14 = bVar1 < pbVar11[1];
                  if (bVar1 != pbVar11[1]) goto LAB_00649d40;
                  ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                  pbVar11 = pbVar11 + 2;
                } while (bVar1 != 0);
                uVar6 = 0;
LAB_00649d45:
                if (uVar6 == 0) {
                  piVar4[0x13] = -1;
                  *(undefined1 *)(piVar4 + 8) = 0;
                  piVar4[0x1d] = 3;
                }
                else {
                  if (piVar12 == (int *)0x0) {
                    ppuVar5 = &PTR_0071ce50;
                  }
                  else {
                    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                  }
                  pbVar11 = &DAT_0071ccb8;
                  do {
                    bVar1 = *(byte *)ppuVar5;
                    bVar14 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_00649da0:
                      uVar6 = -(uint)bVar14 | 1;
                      goto LAB_00649da5;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = *(byte *)((int)ppuVar5 + 1);
                    bVar14 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_00649da0;
                    ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  uVar6 = 0;
LAB_00649da5:
                  if (uVar6 == 0) {
                    if (param_3 == (int *)0x3) {
                      param_3 = *(int **)(param_4 + 8);
                      if (param_3 != (int *)0x0) {
                        *param_3 = *param_3 + 1;
                      }
                      FUN_006bafe0(&local_3c);
                      FUN_006bad60();
                      iVar3 = piVar4[0xc] + -1;
                      if (-1 < iVar3) {
                        iVar3 = 0;
                      }
                      piVar4[0xf] = iVar3;
                      piVar4[0x1a] = local_3c;
                      piVar4[0x1b] = local_38;
                      piVar4[0x1c] = local_34;
                      piVar4[0x1d] = 2;
                      if (piVar12 != (int *)0x0) {
                        *piVar12 = *piVar12 + -1;
                        bVar14 = *piVar12 < 0;
                        bVar15 = *piVar12 == 0;
                        goto LAB_0064a54f;
                      }
                      goto LAB_0064a55b;
                    }
LAB_006497d6:
                    uVar17 = 2;
                    goto LAB_006497d8;
                  }
                  if (piVar12 == (int *)0x0) {
                    ppuVar5 = &PTR_0071ce50;
                  }
                  else {
                    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                  }
                  iVar3 = param_4;
                  pbVar11 = &DAT_0072dc40;
                  do {
                    bVar1 = *(byte *)ppuVar5;
                    bVar14 = bVar1 < *pbVar11;
                    if (bVar1 != *pbVar11) {
LAB_00649e56:
                      uVar6 = -(uint)bVar14 | 1;
                      goto LAB_00649e5b;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = *(byte *)((int)ppuVar5 + 1);
                    bVar14 = bVar1 < pbVar11[1];
                    if (bVar1 != pbVar11[1]) goto LAB_00649e56;
                    ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                    pbVar11 = pbVar11 + 2;
                  } while (bVar1 != 0);
                  uVar6 = 0;
LAB_00649e5b:
                  if (uVar6 == 0) {
                    if (param_3 != (int *)&DAT_00000005) {
                      uVar17 = 4;
                      goto LAB_006497d8;
                    }
                    param_3 = *(int **)(param_4 + 8);
                    if (param_3 != (int *)0x0) {
                      *param_3 = *param_3 + 1;
                    }
                    FUN_006bafe0(&local_48);
                    FUN_006bad60();
                    param_3 = *(int **)(iVar3 + 0xc);
                    if (param_3 != (int *)0x0) {
                      *param_3 = *param_3 + 1;
                    }
                    FUN_006bafe0(&local_3c);
                    FUN_006bad60();
                    param_3 = *(int **)(iVar3 + 0x10);
                    if (param_3 != (int *)0x0) {
                      *param_3 = *param_3 + 1;
                    }
                    FUN_006baf80();
                    local_1c = in_XMM0_Da;
                    FUN_006bad60();
                    FUN_004288c0(local_48,local_44,local_40,local_3c,local_38,local_34);
                  }
                  else {
                    if (piVar12 == (int *)0x0) {
                      ppuVar5 = &PTR_0071ce50;
                    }
                    else {
                      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                    }
                    pcVar10 = "crash";
                    do {
                      bVar1 = *(byte *)ppuVar5;
                      bVar14 = bVar1 < (byte)*pcVar10;
                      if (bVar1 != *pcVar10) {
LAB_00649f65:
                        uVar6 = -(uint)bVar14 | 1;
                        goto LAB_00649f6a;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = *(byte *)((int)ppuVar5 + 1);
                      bVar14 = bVar1 < ((byte *)pcVar10)[1];
                      if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00649f65;
                      ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                      pcVar10 = (char *)((byte *)pcVar10 + 2);
                    } while (bVar1 != 0);
                    uVar6 = 0;
LAB_00649f6a:
                    if (uVar6 == 0) {
                      if (param_3 != (int *)0x3) goto LAB_006497d6;
                      param_3 = *(int **)(param_4 + 8);
                      if (param_3 != (int *)0x0) {
                        *param_3 = *param_3 + 1;
                      }
                      FUN_006bafe0(&local_48);
                      FUN_006bad60();
                      piVar4[1] = -1;
                      iVar3 = 0x19;
                      if (piVar4[0xc] + -1 < 0x19) {
                        iVar3 = piVar4[0xc] + -1;
                      }
                      piVar4[0xf] = iVar3;
                      piVar4[0x14] = (int)(local_48 + 0.0);
                      piVar4[0x15] = (int)(local_44 - 15.0);
                      piVar4[0x16] = (int)(local_40 + 0.0);
                      piVar4[0x1a] = (int)local_48;
                      piVar4[0x1b] = (int)local_44;
                      piVar4[0x1c] = (int)local_40;
                      piVar4[0xe] = iVar3;
                      piVar4[0x1d] = 4;
                    }
                    else {
                      if (piVar12 == (int *)0x0) {
                        ppuVar5 = &PTR_0071ce50;
                      }
                      else {
                        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                      }
                      pcVar10 = "movescreen";
                      do {
                        bVar1 = *(byte *)ppuVar5;
                        bVar14 = bVar1 < (byte)*pcVar10;
                        if (bVar1 != *pcVar10) {
LAB_0064a050:
                          uVar6 = -(uint)bVar14 | 1;
                          goto LAB_0064a055;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = *(byte *)((int)ppuVar5 + 1);
                        bVar14 = bVar1 < ((byte *)pcVar10)[1];
                        if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_0064a050;
                        ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                        pcVar10 = (char *)((byte *)pcVar10 + 2);
                      } while (bVar1 != 0);
                      uVar6 = 0;
LAB_0064a055:
                      if (uVar6 == 0) {
                        if (param_3 == (int *)0x3) {
                          param_3 = *(int **)(param_4 + 8);
                          if (param_3 != (int *)0x0) {
                            *param_3 = *param_3 + 1;
                          }
                          FUN_006bafe0(&local_48);
                          FUN_006bad60();
                          iVar3 = piVar4[0xc] + -1;
                          if (-1 < iVar3) {
                            iVar3 = 0;
                          }
                          piVar4[0xf] = iVar3;
                          iVar3 = 1;
                          piVar4[0x1a] = (int)local_48;
                          piVar4[0x1b] = (int)local_44;
                          piVar4[0x1c] = (int)local_40;
                        }
                        else {
                          iVar3 = *(int *)(*(int *)(DAT_00772400 + 0x5a4) + 0x158);
                          iVar8 = piVar4[0xc] + -1;
                          piVar4[0x1a] = *(int *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154);
                          piVar4[0x1b] = iVar3;
                          if (-1 < iVar8) {
                            iVar8 = 0;
                          }
                          piVar4[0x1c] = 0x41800000;
                          piVar4[0xf] = iVar8;
                          iVar3 = 2;
                        }
                        piVar4[0x1d] = iVar3;
                        if ((piVar12 != (int *)0x0) && (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
                          TclFreeObj(piVar12);
                        }
                        FUN_006bc0d0();
                        goto LAB_0064a569;
                      }
                      if (piVar12 == (int *)0x0) {
                        ppuVar5 = &PTR_0071ce50;
                      }
                      else {
                        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                      }
                      pcVar10 = "lockview";
                      do {
                        bVar1 = *(byte *)ppuVar5;
                        bVar14 = bVar1 < (byte)*pcVar10;
                        if (bVar1 != *pcVar10) {
LAB_0064a160:
                          uVar6 = -(uint)bVar14 | 1;
                          goto LAB_0064a165;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = *(byte *)((int)ppuVar5 + 1);
                        bVar14 = bVar1 < ((byte *)pcVar10)[1];
                        if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_0064a160;
                        ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                        pcVar10 = (char *)((byte *)pcVar10 + 2);
                      } while (bVar1 != 0);
                      uVar6 = 0;
LAB_0064a165:
                      if (uVar6 == 0) {
                        *(undefined1 *)(piVar4 + 8) = 1;
                      }
                      else {
                        if (piVar12 == (int *)0x0) {
                          ppuVar5 = &PTR_0071ce50;
                        }
                        else {
                          ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                        }
                        pcVar10 = "unlockview";
                        do {
                          bVar1 = *(byte *)ppuVar5;
                          bVar14 = bVar1 < (byte)*pcVar10;
                          if (bVar1 != *pcVar10) {
LAB_0064a1b0:
                            uVar6 = -(uint)bVar14 | 1;
                            goto LAB_0064a1b5;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = *(byte *)((int)ppuVar5 + 1);
                          bVar14 = bVar1 < ((byte *)pcVar10)[1];
                          if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_0064a1b0;
                          ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                          pcVar10 = (char *)((byte *)pcVar10 + 2);
                        } while (bVar1 != 0);
                        uVar6 = 0;
LAB_0064a1b5:
                        if (uVar6 == 0) {
                          *(undefined1 *)(piVar4 + 8) = 0;
                        }
                        else {
                          if (piVar12 == (int *)0x0) {
                            ppuVar5 = &PTR_0071ce50;
                          }
                          else {
                            ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                          }
                          pcVar10 = "followview";
                          do {
                            bVar1 = *(byte *)ppuVar5;
                            bVar14 = bVar1 < (byte)*pcVar10;
                            if (bVar1 != *pcVar10) {
LAB_0064a200:
                              uVar6 = -(uint)bVar14 | 1;
                              goto LAB_0064a205;
                            }
                            if (bVar1 == 0) break;
                            bVar1 = *(byte *)((int)ppuVar5 + 1);
                            bVar14 = bVar1 < ((byte *)pcVar10)[1];
                            if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_0064a200;
                            ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                            pcVar10 = (char *)((byte *)pcVar10 + 2);
                          } while (bVar1 != 0);
                          uVar6 = 0;
LAB_0064a205:
                          if (uVar6 == 0) {
                            if (param_3 != (int *)0x3) goto LAB_006497d6;
                            param_3 = *(int **)(param_4 + 8);
                            if (param_3 != (int *)0x0) {
                              *param_3 = *param_3 + 1;
                            }
                            FUN_006bafe0(&local_48);
                            FUN_006bad60();
                            piVar4[0x1a] = (int)local_48;
                            piVar4[0x1b] = (int)local_44;
                            piVar4[0x1c] = (int)local_40;
                            piVar4[0x1d] = 1;
                          }
                          else {
                            if (piVar12 == (int *)0x0) {
                              ppuVar5 = &PTR_0071ce50;
                            }
                            else {
                              ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                            }
                            pcVar10 = "unfollowview";
                            do {
                              bVar1 = *(byte *)ppuVar5;
                              bVar14 = bVar1 < (byte)*pcVar10;
                              if (bVar1 != *pcVar10) {
LAB_0064a298:
                                uVar6 = -(uint)bVar14 | 1;
                                goto LAB_0064a29d;
                              }
                              if (bVar1 == 0) break;
                              bVar1 = *(byte *)((int)ppuVar5 + 1);
                              bVar14 = bVar1 < ((byte *)pcVar10)[1];
                              if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_0064a298;
                              ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                              pcVar10 = (char *)((byte *)pcVar10 + 2);
                            } while (bVar1 != 0);
                            uVar6 = 0;
LAB_0064a29d:
                            if (uVar6 == 0) {
                              piVar4[0x1d] = 0;
                            }
                            else {
                              if (piVar12 == (int *)0x0) {
                                ppuVar5 = &PTR_0071ce50;
                              }
                              else {
                                ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                              }
                              pbVar11 = &DAT_007302c4;
                              do {
                                bVar1 = *(byte *)ppuVar5;
                                bVar14 = bVar1 < *pbVar11;
                                if (bVar1 != *pbVar11) {
LAB_0064a2e1:
                                  uVar6 = -(uint)bVar14 | 1;
                                  goto LAB_0064a2e6;
                                }
                                if (bVar1 == 0) break;
                                bVar1 = *(byte *)((int)ppuVar5 + 1);
                                bVar14 = bVar1 < pbVar11[1];
                                if (bVar1 != pbVar11[1]) goto LAB_0064a2e1;
                                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                                pbVar11 = pbVar11 + 2;
                              } while (bVar1 != 0);
                              uVar6 = 0;
LAB_0064a2e6:
                              if (uVar6 == 0) {
                                if (param_3 == (int *)0x3) {
                                  local_1c = *(int **)(param_4 + 8);
                                  if (local_1c != (int *)0x0) {
                                    *local_1c = *local_1c + 1;
                                  }
                                  local_8._0_1_ = 9;
                                  uVar17 = FUN_006bafc0();
                                  FUN_006b8fb0(uVar17);
                                  local_8 = CONCAT31(local_8._1_3_,10);
                                  iVar3 = FUN_00501450();
                                  piVar4 = local_14;
                                  local_18 = *(int *)(iVar3 + 0x8194);
                                  if ((local_18 != 0) && (*(int *)(local_18 + 0xe0) != 0)) {
                                    FUN_0051ee20();
                                    param_3 = (int *)piVar4[2];
                                    if (param_3 == (int *)0xffffffff) {
                                      param_3 = piVar4 + 3;
                                      do {
                                        iVar3 = *param_3;
                                        param_3 = (int *)((int)param_3 + 1);
                                      } while ((char)iVar3 != '\0');
                                      param_3 = (int *)((int)param_3 - ((int)piVar4 + 0xd));
                                      piVar4[2] = (int)param_3;
                                    }
                                    piVar7 = (int *)0xffffffff;
                                    if (-1 < (int)param_3) {
                                      do {
                                        iVar3 = piVar4[2];
                                        local_20 = (undefined1 *)((int)piVar7 + 1);
                                        if (iVar3 == -1) {
                                          piVar12 = piVar4 + 3;
                                          do {
                                            iVar3 = *piVar12;
                                            piVar12 = (int *)((int)piVar12 + 1);
                                          } while ((char)iVar3 != '\0');
                                          iVar3 = (int)piVar12 - ((int)piVar4 + 0xd);
                                          piVar4[2] = iVar3;
                                        }
                                        if (((iVar3 <= (int)local_20) ||
                                            (iVar3 = FUN_006d0190((undefined1 *)
                                                                  ((int)piVar4 +
                                                                  (int)((int)piVar7 + 0xd)),10),
                                            iVar3 == 0)) ||
                                           (piVar7 = (int *)((iVar3 - (int)piVar4) + -0xc),
                                           piVar7 == (int *)0xffffffff)) {
                                          piVar7 = param_3;
                                        }
                                        uVar17 = FUN_006b9b20(&local_24,local_20,
                                                              (int)piVar7 - (int)local_20);
                                        local_8._0_1_ = 0xb;
                                        FUN_0051eda0(uVar17);
                                        local_8._0_1_ = 0xc;
                                        if ((local_24 != (int *)0x0) &&
                                           (*local_24 = *local_24 + -1, *local_24 == 0)) {
                                          FUN_006ba940();
                                        }
                                        local_8 = CONCAT31(local_8._1_3_,10);
                                        piVar12 = local_28;
                                      } while ((int)piVar7 < (int)param_3);
                                    }
                                    FUN_0051f090();
                                  }
                                  local_8._0_1_ = 0xd;
                                  if ((piVar4 != (int *)0x0) &&
                                     (*piVar4 = *piVar4 + -1, *piVar4 == 0)) {
                                    FUN_006ba940();
                                  }
                                  goto LAB_0064a541;
                                }
                                uVar17 = 3;
LAB_006497d8:
                                FUN_006bc8f0(uVar17);
                                if ((piVar12 != (int *)0x0) &&
                                   (*piVar12 = *piVar12 + -1, *piVar12 < 1)) {
                                  TclFreeObj(piVar12);
                                }
LAB_006496fa:
                                FUN_006bc0d0();
                                FUN_0043fd30();
                                ExceptionList = local_10;
                                return 1;
                              }
                              if (piVar12 == (int *)0x0) {
                                ppuVar5 = &PTR_0071ce50;
                              }
                              else {
                                ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                              }
                              pcVar10 = "set_pos";
                              do {
                                bVar1 = *(byte *)ppuVar5;
                                bVar14 = bVar1 < (byte)*pcVar10;
                                if (bVar1 != *pcVar10) {
LAB_0064a480:
                                  uVar6 = -(uint)bVar14 | 1;
                                  goto LAB_0064a485;
                                }
                                if (bVar1 == 0) break;
                                bVar1 = *(byte *)((int)ppuVar5 + 1);
                                bVar14 = bVar1 < ((byte *)pcVar10)[1];
                                if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_0064a480;
                                ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                                pcVar10 = (char *)((byte *)pcVar10 + 2);
                              } while (bVar1 != 0);
                              uVar6 = 0;
LAB_0064a485:
                              if (uVar6 == 0) {
                                if (param_3 != (int *)0x3) {
                                  uVar17 = 3;
                                  goto LAB_006497d8;
                                }
                                param_3 = *(int **)(param_4 + 8);
                                if (param_3 != (int *)0x0) {
                                  *param_3 = *param_3 + 1;
                                }
                                FUN_006bafe0(&local_48);
                                FUN_006bad60();
                                piVar4[0x14] = (int)local_48;
                                piVar4[0x15] = (int)local_44;
                                piVar4[0x16] = (int)local_40;
                                piVar4[0x1a] = (int)local_48;
                                piVar4[0x1b] = (int)local_44;
                                piVar4[0x1c] = (int)local_40;
                              }
                              else {
                                if (piVar12 == (int *)0x0) {
                                  ppuVar5 = &PTR_0071ce50;
                                }
                                else {
                                  ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar12,0);
                                }
                                pcVar10 = "get_pos";
                                do {
                                  bVar1 = *(byte *)ppuVar5;
                                  bVar14 = bVar1 < (byte)*pcVar10;
                                  if (bVar1 != *pcVar10) {
LAB_0064a520:
                                    uVar6 = -(uint)bVar14 | 1;
                                    goto LAB_0064a525;
                                  }
                                  if (bVar1 == 0) break;
                                  bVar1 = *(byte *)((int)ppuVar5 + 1);
                                  bVar14 = bVar1 < ((byte *)pcVar10)[1];
                                  if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_0064a520;
                                  ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                                  pcVar10 = (char *)((byte *)pcVar10 + 2);
                                } while (bVar1 != 0);
                                uVar6 = 0;
LAB_0064a525:
                                if (uVar6 == 0) {
                                  puVar9 = (undefined4 *)FUN_006badc0(piVar4 + 0x14);
                                  goto LAB_0064a535;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          goto LAB_0064a546;
        }
        iVar3 = piVar4[0xc] + -1;
        piVar4[0x1d] = 0;
        if (-1 < iVar3) {
          iVar3 = 0;
        }
        piVar4[0xf] = iVar3;
        if (piVar12 == (int *)0x0) goto LAB_0064a55b;
        *piVar12 = *piVar12 + -1;
        bVar14 = *piVar12 < 0;
        bVar15 = *piVar12 == 0;
      }
LAB_0064a54f:
      if (bVar15 || bVar14) {
        TclFreeObj(piVar12);
      }
    }
  }
LAB_0064a55b:
  FUN_006bc0d0();
LAB_0064a569:
  FUN_0043fd30();
  ExceptionList = local_10;
  return 0;
}

