
undefined4
CTclGlobalMethods__TimeSchedule
          (undefined4 param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  int *piVar2;
  float fVar3;
  int iVar4;
  undefined **ppuVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  byte *pbVar9;
  char *pcVar10;
  code *pcVar11;
  code *pcVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  int *piVar15;
  bool bVar16;
  float10 fVar17;
  undefined8 uVar18;
  double local_d4;
  double local_cc;
  double local_c4;
  double local_bc;
  int *local_b4;
  undefined4 *local_b0;
  int *local_ac;
  int *local_a8;
  undefined4 local_a4;
  int *piStack_a0;
  undefined4 local_9c;
  int *piStack_98;
  int *local_94;
  int *local_90;
  int *local_8c;
  undefined8 local_88;
  int local_80;
  char local_7c;
  int *local_78;
  int *local_74;
  uint local_70;
  int *local_6c;
  int *local_68;
  int *local_64;
  int *local_60;
  int local_5c;
  float local_58;
  int *local_54;
  int *local_50;
  int *local_4c;
  float local_48;
  int *local_44;
  int local_40;
  int *local_3c;
  undefined4 *local_38;
  float local_34;
  int local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  char local_1d;
  int *local_1c;
  int *local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070dc9b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
                    /* WARNING: Load size is inaccurate */
  if ((*(int *)(*ThreadLocalStoragePointer + 4) < DAT_00ca70c8) &&
     (FUN_006cebf4(&DAT_00ca70c8,DAT_0076700c ^ (uint)&stack0xfffffffc), iVar4 = DAT_00783650,
     DAT_00ca70c8 == -1)) {
    iVar8 = DAT_00783650 * 0x40;
    DAT_00ca70cc = DAT_00783650;
    *(char **)(&DAT_0077368c + iVar8) = "TCL:CTclGlobalMethods::TimeSchedule()";
    *(int *)(&DAT_00773650 + iVar8) = iVar4;
    DAT_00783650 = DAT_00783650 + 1;
    FUN_006cebaa(&DAT_00ca70c8);
  }
  iVar8 = DAT_00ca70cc;
  local_b0 = &DAT_00ca70cc;
  uVar13 = *(undefined4 *)(&DAT_00773650 + DAT_00ca70cc * 0x40);
  iVar4 = FUN_0043fcc0();
  *(undefined4 *)(iVar4 + *(int *)(iVar4 + 0x8000) * 4) = uVar13;
  *(int *)(iVar4 + 0x8000) = *(int *)(iVar4 + 0x8000) + 1;
  iVar4 = (&DAT_00773654)[iVar8 * 0x10];
  if (iVar4 == 0) {
    uVar18 = FUN_006bd180();
    iVar4 = (&DAT_00773654)[iVar8 * 0x10];
    *(undefined8 *)(&DAT_00773658 + iVar8 * 0x10) = uVar18;
  }
  (&DAT_00773654)[iVar8 * 0x10] = iVar4 + 1;
  local_8 = 0;
  FUN_006bc170(param_2);
  piVar7 = param_3;
  local_8._0_1_ = 1;
  FUN_004298b0(param_3,param_4);
  local_8 = CONCAT31(local_8._1_3_,2);
  if ((int)piVar7 < 4) {
    FUN_006bc8f0(3);
    uVar13 = 1;
  }
  else {
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar14 = local_38;
      if (local_34 == 0.0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar14 = local_38;
      }
    }
    else {
      if ((uint)local_34 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar14 = local_38 + 1;
    }
    piVar7 = (int *)*puVar14;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
    }
    local_b4 = piVar7;
    local_a8 = piVar7;
    if (local_30 < 2) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar14 = local_38;
      if (local_34 == 0.0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar14 = local_38;
      }
    }
    else {
      if ((uint)local_34 < 2) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar14 = local_38 + 1;
    }
    pcVar12 = TclFreeObj_exref;
    piVar15 = (int *)*puVar14;
    if (piVar15 == (int *)0x0) {
      local_48 = 0.0;
    }
    else {
      *piVar15 = *piVar15 + 1;
      iVar4 = Tcl_GetDoubleFromObj(0,piVar15,&local_88);
      local_48 = 0.0;
      if (iVar4 != 1) {
        local_48 = (float)local_88;
      }
      *piVar15 = *piVar15 + -1;
      if (*piVar15 < 1) {
        TclFreeObj(piVar15);
      }
    }
    if (local_30 < 3) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar14 = local_38;
      if (local_34 == 0.0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar14 = local_38;
      }
    }
    else {
      if ((uint)local_34 < 3) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar14 = local_38 + 2;
    }
    piVar15 = (int *)*puVar14;
    if (piVar15 == (int *)0x0) {
      local_44 = (int *)0x0;
    }
    else {
      *piVar15 = *piVar15 + 1;
      iVar4 = Tcl_GetDoubleFromObj(0,piVar15,&local_a4);
      if (iVar4 == 1) {
        local_44 = (int *)0x0;
      }
      else {
        local_44 = (int *)(float)(double)CONCAT44(piStack_a0,local_a4);
      }
      *piVar15 = *piVar15 + -1;
      if (*piVar15 < 1) {
        TclFreeObj(piVar15);
      }
    }
    if (local_30 < 4) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar14 = local_38;
      if (local_34 == 0.0) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        puVar14 = local_38;
      }
    }
    else {
      if ((uint)local_34 < 4) {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      puVar14 = local_38 + 3;
    }
    piVar15 = (int *)*puVar14;
    if (piVar15 == (int *)0x0) {
      local_3c = (int *)0x0;
    }
    else {
      *piVar15 = *piVar15 + 1;
      iVar4 = Tcl_GetDoubleFromObj(0,piVar15,&local_9c);
      if (iVar4 == 1) {
        local_3c = (int *)0x0;
      }
      else {
        local_3c = (int *)(float)(double)CONCAT44(piStack_98,local_9c);
      }
      *piVar15 = *piVar15 + -1;
      if (*piVar15 < 1) {
        TclFreeObj(piVar15);
      }
    }
    if (piVar7 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
    }
    pbVar9 = &DAT_0072fff4;
    do {
      bVar1 = *(byte *)ppuVar5;
      bVar16 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_00645752:
        uVar6 = -(uint)bVar16 | 1;
        goto LAB_00645757;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar5 + 1);
      bVar16 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_00645752;
      ppuVar5 = (undefined **)((int)ppuVar5 + 2);
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    uVar6 = 0;
LAB_00645757:
    if (uVar6 == 0) {
      local_88 = (double)((float)*(double *)(DAT_00772400 + 0xa088) / 150.0);
      fVar17 = (float10)FUN_006f52b0();
      local_58 = (float)fVar17;
      local_48 = local_58;
    }
    if (piVar7 == (int *)0x0) {
      ppuVar5 = &PTR_0071ce50;
    }
    else {
      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
    }
    pbVar9 = &DAT_0072b6e8;
    do {
      bVar1 = *(byte *)ppuVar5;
      bVar16 = bVar1 < *pbVar9;
      if (bVar1 != *pbVar9) {
LAB_006457d5:
        local_70 = -(uint)bVar16 | 1;
        goto LAB_006457da;
      }
      if (bVar1 == 0) break;
      bVar1 = *(byte *)((int)ppuVar5 + 1);
      bVar16 = bVar1 < pbVar9[1];
      if (bVar1 != pbVar9[1]) goto LAB_006457d5;
      ppuVar5 = (undefined **)((int)ppuVar5 + 2);
      pbVar9 = pbVar9 + 2;
    } while (bVar1 != 0);
    local_70 = 0;
LAB_006457da:
    if (local_70 == 0) {
      local_48 = -1.0;
    }
    if ((float)local_3c < (float)local_44) {
      local_3c = (int *)((float)local_3c + 12.0);
    }
    for (; 12.0 <= (float)local_44; local_44 = (int *)((float)local_44 - 12.0)) {
      local_3c = (int *)((float)local_3c - 12.0);
    }
    if ((0.0 < local_48) && (local_48 < (float)local_44)) {
      local_48 = local_48 + 12.0;
    }
    piVar7 = (int *)Tcl_NewListObj(0,0);
    local_2c = piVar7;
    local_24 = piVar7;
    if (piVar7 != (int *)0x0) {
      *piVar7 = *piVar7 + 1;
      iVar4 = *piVar7;
      *piVar7 = iVar4;
      if (iVar4 < 1) {
        TclFreeObj(piVar7);
      }
    }
    local_4c = (int *)((float)local_3c - (float)local_44);
    local_58 = 5.60519e-45;
    if (4 < (int)param_3) {
      do {
        fVar3 = local_58;
        local_18 = (int *)0x461c4000;
        local_28 = (int *)0x0;
        local_1c = (int *)0x47c35000;
        local_1d = '\0';
        local_11 = '\0';
        if ((int)local_58 < local_30) {
          if ((uint)local_34 <= (uint)local_58) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar14 = local_38 + (int)fVar3;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          if (local_34 == 0.0) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          puVar14 = local_38;
        }
        piVar15 = (int *)*puVar14;
        local_88 = (double)CONCAT44(piVar15,(undefined4)local_88);
        local_50 = piVar15;
        if (piVar15 != (int *)0x0) {
          *piVar15 = *piVar15 + 1;
          iVar4 = Tcl_ListObjLength(0,piVar15,&local_40);
          pcVar11 = Tcl_ListObjIndex_exref;
          if ((iVar4 == 0) && (local_40 != 0)) {
            iVar4 = Tcl_ListObjIndex(0,piVar15,0,&local_8c);
            if (iVar4 == 0) {
              local_54 = local_8c;
              if (local_8c != (int *)0x0) {
                *local_8c = *local_8c + 1;
              }
            }
            else {
              local_54 = (int *)0x0;
            }
            local_5c = 1;
            if (local_40 < 2) {
LAB_00645e27:
              if ((float)local_18 <= (float)local_28) {
                local_18 = local_28;
              }
              if ((float)local_1c <= (float)local_18) {
                local_18 = local_1c;
              }
              local_28 = (int *)0x0;
              if (0.0 <= (float)local_18) {
                local_28 = local_18;
              }
              if ((float)local_4c <= (float)local_28) {
                local_28 = local_4c;
              }
              local_18 = local_44;
              local_44 = (int *)((float)local_28 + (float)local_44);
            }
            else {
              do {
                iVar4 = local_5c;
                iVar8 = (*pcVar11)(0,piVar15,local_5c,&local_ac);
                if (iVar8 == 0) {
                  local_6c = local_ac;
                  if (local_ac != (int *)0x0) {
                    *local_ac = *local_ac + 1;
                  }
                }
                else {
                  local_6c = (int *)0x0;
                }
                piVar7 = local_6c;
                local_8 = CONCAT31(local_8._1_3_,7);
                if (local_6c == (int *)0x0) {
                  ppuVar5 = &PTR_0071ce50;
                }
                else {
                  ppuVar5 = (undefined **)Tcl_GetStringFromObj(local_6c,0);
                }
                pbVar9 = &DAT_0072fff8;
                do {
                  bVar1 = *(byte *)ppuVar5;
                  bVar16 = bVar1 < *pbVar9;
                  if (bVar1 != *pbVar9) {
LAB_00645a00:
                    uVar6 = -(uint)bVar16 | 1;
                    goto LAB_00645a05;
                  }
                  if (bVar1 == 0) break;
                  bVar1 = *(byte *)((int)ppuVar5 + 1);
                  bVar16 = bVar1 < pbVar9[1];
                  if (bVar1 != pbVar9[1]) goto LAB_00645a00;
                  ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                  pbVar9 = pbVar9 + 2;
                } while (bVar1 != 0);
                uVar6 = 0;
LAB_00645a05:
                iVar4 = iVar4 + 1;
                if ((uVar6 == 0) && (iVar4 < local_40)) {
                  iVar8 = Tcl_ListObjIndex(0,piVar15,iVar4,&local_90);
                  piVar2 = local_90;
                  if ((iVar8 == 0) && (local_90 != (int *)0x0)) {
                    *local_90 = *local_90 + 1;
                    iVar8 = Tcl_GetDoubleFromObj(0,local_90,&local_bc);
                    if (iVar8 == 1) {
                      local_28 = (int *)0x0;
                    }
                    else {
                      local_28 = (int *)(float)local_bc;
                    }
                    *piVar2 = *piVar2 + -1;
                    piVar15 = local_50;
                    if (*piVar2 < 1) {
                      TclFreeObj(piVar2);
                      piVar15 = local_50;
                    }
                  }
                  else {
                    local_28 = (int *)0x0;
                    piVar15 = local_50;
                  }
                }
                else {
                  if (piVar7 == (int *)0x0) {
                    ppuVar5 = &PTR_0071ce50;
                  }
                  else {
                    ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
                  }
                  pbVar9 = &DAT_0072fffc;
                  do {
                    bVar1 = *(byte *)ppuVar5;
                    bVar16 = bVar1 < *pbVar9;
                    if (bVar1 != *pbVar9) {
LAB_00645ad0:
                      uVar6 = -(uint)bVar16 | 1;
                      goto LAB_00645ad5;
                    }
                    if (bVar1 == 0) break;
                    bVar1 = *(byte *)((int)ppuVar5 + 1);
                    bVar16 = bVar1 < pbVar9[1];
                    if (bVar1 != pbVar9[1]) goto LAB_00645ad0;
                    ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                    pbVar9 = pbVar9 + 2;
                  } while (bVar1 != 0);
                  uVar6 = 0;
LAB_00645ad5:
                  if ((uVar6 == 0) && (iVar4 < local_40)) {
                    iVar8 = Tcl_ListObjIndex(0,piVar15,iVar4,&local_94);
                    piVar2 = local_94;
                    if ((iVar8 == 0) && (local_94 != (int *)0x0)) {
                      *local_94 = *local_94 + 1;
                      iVar8 = Tcl_GetDoubleFromObj(0,local_94,&local_c4);
                      if (iVar8 == 1) {
                        local_1c = (int *)0x0;
                      }
                      else {
                        local_1c = (int *)(float)local_c4;
                      }
                      *piVar2 = *piVar2 + -1;
                      piVar15 = local_50;
                      if (*piVar2 < 1) {
                        TclFreeObj(piVar2);
                        piVar15 = local_50;
                      }
                    }
                    else {
                      local_1c = (int *)0x0;
                      piVar15 = local_50;
                    }
                  }
                  else {
                    if (piVar7 == (int *)0x0) {
                      ppuVar5 = &PTR_0071ce50;
                    }
                    else {
                      ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
                    }
                    pbVar9 = &DAT_00730000;
                    do {
                      bVar1 = *(byte *)ppuVar5;
                      bVar16 = bVar1 < *pbVar9;
                      if (bVar1 != *pbVar9) {
LAB_00645ba0:
                        uVar6 = -(uint)bVar16 | 1;
                        goto LAB_00645ba5;
                      }
                      if (bVar1 == 0) break;
                      bVar1 = *(byte *)((int)ppuVar5 + 1);
                      bVar16 = bVar1 < pbVar9[1];
                      if (bVar1 != pbVar9[1]) goto LAB_00645ba0;
                      ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                      pbVar9 = pbVar9 + 2;
                    } while (bVar1 != 0);
                    uVar6 = 0;
LAB_00645ba5:
                    if ((uVar6 == 0) && (iVar4 < local_40)) {
                      iVar8 = Tcl_ListObjIndex(0,piVar15,iVar4,&piStack_98);
                      piVar2 = piStack_98;
                      if ((iVar8 == 0) && (piStack_98 != (int *)0x0)) {
                        *piStack_98 = *piStack_98 + 1;
                        iVar8 = Tcl_GetDoubleFromObj(0,piStack_98,&local_cc);
                        if (iVar8 == 1) {
                          local_18 = (int *)((float)local_4c * 0.0);
                        }
                        else {
                          local_18 = (int *)((float)local_cc * 0.01 * (float)local_4c);
                        }
                        *piVar2 = *piVar2 + -1;
                        piVar15 = local_50;
                        if (*piVar2 < 1) {
                          TclFreeObj(piVar2);
                          piVar15 = local_50;
                        }
                      }
                      else {
                        local_18 = (int *)((float)local_4c * 0.0);
                        piVar15 = local_50;
                      }
                    }
                    else {
                      if (piVar7 == (int *)0x0) {
                        ppuVar5 = &PTR_0071ce50;
                      }
                      else {
                        ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
                      }
                      pbVar9 = &DAT_00730004;
                      do {
                        bVar1 = *(byte *)ppuVar5;
                        bVar16 = bVar1 < *pbVar9;
                        if (bVar1 != *pbVar9) {
LAB_00645c90:
                          uVar6 = -(uint)bVar16 | 1;
                          goto LAB_00645c95;
                        }
                        if (bVar1 == 0) break;
                        bVar1 = *(byte *)((int)ppuVar5 + 1);
                        bVar16 = bVar1 < pbVar9[1];
                        if (bVar1 != pbVar9[1]) goto LAB_00645c90;
                        ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                        pbVar9 = pbVar9 + 2;
                      } while (bVar1 != 0);
                      uVar6 = 0;
LAB_00645c95:
                      if ((uVar6 == 0) && (iVar4 < local_40)) {
                        iVar8 = Tcl_ListObjIndex(0,piVar15,iVar4,&piStack_a0);
                        piVar2 = piStack_a0;
                        if ((iVar8 == 0) && (piStack_a0 != (int *)0x0)) {
                          *piStack_a0 = *piStack_a0 + 1;
                          iVar8 = Tcl_GetDoubleFromObj(0,piStack_a0,&local_d4);
                          if (iVar8 == 1) {
                            local_18 = (int *)0x0;
                          }
                          else {
                            local_18 = (int *)(float)local_d4;
                          }
                          *piVar2 = *piVar2 + -1;
                          piVar15 = local_50;
                          if (*piVar2 < 1) {
                            TclFreeObj(piVar2);
                            piVar15 = local_50;
                          }
                        }
                        else {
                          local_18 = (int *)0x0;
                          piVar15 = local_50;
                        }
                      }
                      else {
                        if (piVar7 == (int *)0x0) {
                          ppuVar5 = &PTR_0071ce50;
                        }
                        else {
                          ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
                        }
                        pcVar10 = "start";
                        do {
                          bVar1 = *(byte *)ppuVar5;
                          bVar16 = bVar1 < (byte)*pcVar10;
                          if (bVar1 != *pcVar10) {
LAB_00645d60:
                            uVar6 = -(uint)bVar16 | 1;
                            goto LAB_00645d65;
                          }
                          if (bVar1 == 0) break;
                          bVar1 = *(byte *)((int)ppuVar5 + 1);
                          bVar16 = bVar1 < ((byte *)pcVar10)[1];
                          if (bVar1 != ((byte *)pcVar10)[1]) goto LAB_00645d60;
                          ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                          pcVar10 = (char *)((byte *)pcVar10 + 2);
                        } while (bVar1 != 0);
                        uVar6 = 0;
LAB_00645d65:
                        if (uVar6 == 0) {
                          local_11 = '\x01';
                          iVar4 = local_5c;
                        }
                        else {
                          if (piVar7 == (int *)0x0) {
                            ppuVar5 = &PTR_0071ce50;
                          }
                          else {
                            ppuVar5 = (undefined **)Tcl_GetStringFromObj(piVar7,0);
                          }
                          pbVar9 = &DAT_00724710;
                          do {
                            bVar1 = *(byte *)ppuVar5;
                            bVar16 = bVar1 < *pbVar9;
                            if (bVar1 != *pbVar9) {
LAB_00645da7:
                              uVar6 = -(uint)bVar16 | 1;
                              goto LAB_00645dac;
                            }
                            if (bVar1 == 0) break;
                            bVar1 = *(byte *)((int)ppuVar5 + 1);
                            bVar16 = bVar1 < pbVar9[1];
                            if (bVar1 != pbVar9[1]) goto LAB_00645da7;
                            ppuVar5 = (undefined **)((int)ppuVar5 + 2);
                            pbVar9 = pbVar9 + 2;
                          } while (bVar1 != 0);
                          uVar6 = 0;
LAB_00645dac:
                          if (uVar6 != 0) {
                            if (piVar7 != (int *)0x0) {
                              *piVar7 = *piVar7 + 1;
                            }
                            FUN_006bc6a0("invalid parameter",piVar7);
                            pcVar12 = TclFreeObj_exref;
                            if ((piVar7 != (int *)0x0) &&
                               (*piVar7 = *piVar7 + -1, pcVar12 = TclFreeObj_exref, *piVar7 < 1)) {
                              TclFreeObj(piVar7);
                            }
                            goto LAB_006461ac;
                          }
                          local_1d = '\x01';
                          iVar4 = local_5c;
                        }
                      }
                    }
                  }
                }
                local_8 = CONCAT31(local_8._1_3_,6);
                if ((piVar7 != (int *)0x0) && (*piVar7 = *piVar7 + -1, *piVar7 < 1)) {
                  TclFreeObj(piVar7);
                }
                local_5c = iVar4 + 1;
                pcVar11 = Tcl_ListObjIndex_exref;
              } while (local_5c < local_40);
              if (local_1d == '\0') goto LAB_00645e27;
              if (local_11 != '\0') {
                *piVar15 = *piVar15 + 1;
                FUN_006bc6a0("end and start specified",piVar15);
                pcVar12 = TclFreeObj_exref;
LAB_006461ac:
                if ((local_54 != (int *)0x0) && (*local_54 = *local_54 + -1, *local_54 < 1)) {
                  (*pcVar12)(local_54);
                }
                *piVar15 = *piVar15 + -1;
                if (*piVar15 < 1) {
                  (*pcVar12)(piVar15);
                }
                uVar13 = 1;
                goto LAB_00646212;
              }
              if ((float)local_18 <= (float)local_28) {
                local_18 = local_28;
              }
              if ((float)local_1c <= (float)local_18) {
                local_18 = local_1c;
              }
              local_28 = (int *)0x0;
              if (0.0 <= (float)local_18) {
                local_28 = local_18;
              }
              if ((float)local_4c <= (float)local_28) {
                local_28 = local_4c;
              }
              local_3c = (int *)((float)local_3c - (float)local_28);
              local_18 = local_3c;
            }
            local_1c = (int *)Tcl_NewListObj(0,0);
            if ((local_1c != (int *)0x0) ||
               (local_1c = (int *)Tcl_NewListObj(0,0), pcVar12 = Tcl_ListObjAppendElement_exref,
               local_1c != (int *)0x0)) {
              *local_1c = *local_1c + 1;
              if (1 < *local_1c) {
                *local_1c = *local_1c + -1;
                local_1c = (int *)Tcl_DuplicateObj(local_1c);
                *local_1c = *local_1c + 1;
              }
              piVar7 = local_1c;
              pcVar12 = Tcl_ListObjAppendElement_exref;
              if (local_54 != (int *)0x0) {
                if (*local_54 < 2) {
                  Tcl_ListObjAppendElement(0,local_1c,local_54);
                }
                else {
                  uVar13 = Tcl_DuplicateObj();
                  pcVar12 = Tcl_ListObjAppendElement_exref;
                  Tcl_ListObjAppendElement(0,piVar7,uVar13);
                }
              }
            }
            uVar13 = FUN_006bad90();
            FUN_006bb930(uVar13);
            if (local_60 != (int *)0x0) {
              *local_60 = *local_60 + -1;
              if (*local_60 < 1) {
                TclFreeObj(local_60);
              }
              local_60 = (int *)0x0;
            }
            uVar13 = FUN_006bad90();
            FUN_006bb930(uVar13);
            if (local_64 != (int *)0x0) {
              *local_64 = *local_64 + -1;
              if (*local_64 < 1) {
                TclFreeObj(local_64);
              }
              local_64 = (int *)0x0;
            }
            local_6c = (int *)((float)local_18 + (float)local_28);
            uVar13 = FUN_006bad90();
            FUN_006bb930(uVar13);
            if (local_68 != (int *)0x0) {
              *local_68 = *local_68 + -1;
              if (*local_68 < 1) {
                TclFreeObj(local_68);
              }
              local_68 = (int *)0x0;
            }
            piVar2 = local_1c;
            piVar15 = local_24;
            if (local_70 == 0) {
              if (local_24 == (int *)0x0) {
                local_2c = (int *)Tcl_NewListObj(0,0);
                pcVar11 = TclFreeObj_exref;
                piVar7 = local_2c;
                local_24 = local_2c;
                if (local_2c == (int *)0x0) goto LAB_00646049;
                *local_2c = *local_2c + 1;
              }
              if (1 < *local_24) {
                *local_24 = *local_24 + -1;
                local_2c = (int *)Tcl_DuplicateObj(local_24);
                *local_2c = *local_2c + 1;
                local_24 = local_2c;
              }
              piVar7 = local_24;
              if (piVar2 != (int *)0x0) {
                if (*piVar2 < 2) {
                  (*pcVar12)(0,local_24,piVar2);
                  pcVar11 = TclFreeObj_exref;
                }
                else {
                  uVar13 = Tcl_DuplicateObj();
                  (*pcVar12)(0,piVar7,uVar13);
                  pcVar11 = TclFreeObj_exref;
                }
                goto LAB_00646049;
              }
            }
            else {
              pcVar11 = TclFreeObj_exref;
              piVar7 = local_24;
              if (((float)local_18 <= local_48) && (local_48 < (float)local_6c)) {
                local_24 = local_1c;
                local_2c = local_1c;
                if (local_1c != (int *)0x0) {
                  *local_1c = *local_1c + 1;
                }
                pcVar11 = TclFreeObj_exref;
                piVar7 = piVar2;
                if ((piVar15 != (int *)0x0) &&
                   (*piVar15 = *piVar15 + -1, pcVar11 = TclFreeObj_exref, *piVar15 < 1)) {
                  TclFreeObj(piVar15);
                }
              }
LAB_00646049:
              if ((piVar2 != (int *)0x0) && (*piVar2 = *piVar2 + -1, *piVar2 < 1)) {
                (*pcVar11)(piVar2);
              }
            }
            pcVar12 = TclFreeObj_exref;
            if ((local_54 != (int *)0x0) && (*local_54 = *local_54 + -1, *local_54 < 1)) {
              TclFreeObj(local_54);
            }
            *local_50 = *local_50 + -1;
            iVar4 = *local_50;
            piVar15 = local_50;
          }
          else {
            *piVar15 = *piVar15 + -1;
            iVar4 = *piVar15;
          }
          if (iVar4 < 1) {
            (*pcVar12)(piVar15);
          }
        }
        local_58 = (float)((int)local_58 + 1);
      } while ((int)local_58 < (int)param_3);
    }
    if (((piVar7 == (int *)0x0) || (iVar4 = Tcl_ListObjLength(0,piVar7,&param_3), iVar4 != 0)) ||
       (param_3 == (int *)0x0)) {
      piVar7 = (int *)Tcl_NewStringObj(&DAT_00722ca4,0xffffffff);
      *piVar7 = *piVar7 + 1;
      param_3 = piVar7;
      FUN_006bb930(&param_3);
      *piVar7 = *piVar7 + -1;
      if (*piVar7 < 1) {
        (*pcVar12)(piVar7);
      }
      piVar7 = (int *)Tcl_NewIntObj(0);
      *piVar7 = *piVar7 + 1;
      param_3 = piVar7;
      FUN_006bb930(&param_3);
      *piVar7 = *piVar7 + -1;
      if (*piVar7 < 1) {
        (*pcVar12)(piVar7);
      }
      piVar7 = (int *)Tcl_NewIntObj(0);
      *piVar7 = *piVar7 + 1;
      param_3 = piVar7;
      FUN_006bb930(&param_3);
      *piVar7 = *piVar7 + -1;
      if (*piVar7 < 1) {
        (*pcVar12)(piVar7);
      }
      piVar7 = (int *)Tcl_NewIntObj(0);
      *piVar7 = *piVar7 + 1;
      param_3 = piVar7;
      FUN_006bb930(&param_3);
      *piVar7 = *piVar7 + -1;
      if (*piVar7 < 1) {
        (*pcVar12)(piVar7);
      }
      local_24 = local_2c;
      piVar7 = local_2c;
    }
    if (local_80 != 0) {
      if (piVar7 == (int *)0x0) {
        Tcl_ResetResult(local_80);
      }
      else {
        Tcl_SetObjResult(local_80,piVar7);
      }
    }
    uVar13 = 0;
LAB_00646212:
    if ((local_24 != (int *)0x0) && (*local_24 = *local_24 + -1, *local_24 < 1)) {
      TclFreeObj(local_24);
    }
    if ((local_a8 != (int *)0x0) && (*local_a8 = *local_a8 + -1, *local_a8 < 1)) {
      TclFreeObj(local_a8);
    }
  }
  local_8._0_1_ = 8;
  FUN_004297b0(0);
  local_8 = CONCAT31(local_8._1_3_,9);
  FUN_004297b0(0);
  if (local_38 != (undefined4 *)0x0) {
    FUN_006ba940();
  }
  if ((local_7c != '\0') && (local_80 != 0)) {
    LOCK();
    DAT_00772dd4 = DAT_00772dd4 + -1;
    UNLOCK();
    Tcl_DeleteInterp(local_80);
  }
  local_80 = 0;
  if (DAT_00772dd4 == 0) {
    Tcl_Finalize();
  }
  local_8._0_1_ = 10;
  if ((local_74 != (int *)0x0) && (*local_74 = *local_74 + -1, *local_74 == 0)) {
    FUN_006ba940();
  }
  local_8 = CONCAT31(local_8._1_3_,0xb);
  if ((local_78 != (int *)0x0) && (*local_78 = *local_78 + -1, *local_78 == 0)) {
    FUN_006ba940();
  }
  FUN_0043fd30();
  ExceptionList = local_10;
  return uVar13;
}

