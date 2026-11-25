
/* WARNING: Removing unreachable block (ram,0x0058aedb) */

undefined4 FUN_0058a8b0(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  code *pcVar11;
  uint uVar12;
  undefined4 uVar13;
  bool bVar14;
  int local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int *local_30;
  uint local_2c;
  uint local_28;
  int *local_24;
  int local_20;
  int local_1c;
  uint local_18;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00706555;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0040ba00(DAT_0076700c ^ (uint)&stack0xfffffffc);
  local_3c = 0;
  local_8 = 1;
  iVar2 = FUN_0058a820();
  local_18 = 0;
  local_1c = iVar2;
  if (0 < *(int *)(iVar2 + 0x1a8)) {
    bVar14 = *(int *)(iVar2 + 0x1a8) != 0;
    local_20 = 0;
    pcVar11 = RaiseException_exref;
    do {
      if (!bVar14) {
        (*pcVar11)(0xc000008c,1,0,0);
        iVar2 = local_1c;
      }
      iVar6 = *(int *)(iVar2 + 0x1a4);
      if (*(char *)(iVar6 + 0x41 + local_20) == '\0') {
        if (*(uint *)(iVar2 + 0x1a8) <= local_18) {
          (*pcVar11)(0xc000008c,1,0,0);
          iVar6 = *(int *)(local_1c + 0x1a4);
          iVar2 = local_1c;
        }
        if (*(char *)(iVar6 + 0x40 + local_20) == '\0') {
          if (*(uint *)(iVar2 + 0x1a8) <= local_18) {
            (*pcVar11)(0xc000008c,1,0,0);
            iVar6 = *(int *)(local_1c + 0x1a4);
            iVar2 = local_1c;
          }
          if (-1 < *(int *)(iVar6 + 0x48 + local_20)) {
            if (*(uint *)(iVar2 + 0x1a8) <= local_18) {
              (*pcVar11)(0xc000008c,1,0,0);
              iVar6 = *(int *)(local_1c + 0x1a4);
              iVar2 = local_1c;
            }
            uVar7 = local_3c;
            if (*(int *)(iVar6 + 0x4c + local_20) == param_6) {
              uVar9 = *(uint *)(iVar2 + 0x1a8);
              if (uVar9 <= local_18) {
                (*pcVar11)(0xc000008c,1,0,0);
                iVar6 = *(int *)(local_1c + 0x1a4);
                uVar9 = *(uint *)(local_1c + 0x1a8);
              }
              local_34 = *(int *)(iVar6 + 8 + local_20);
              if (uVar9 <= local_18) {
                (*pcVar11)(0xc000008c,1,0,0);
                iVar6 = *(int *)(local_1c + 0x1a4);
              }
              local_38 = *(int *)(iVar6 + 0xc + local_20);
              iVar2 = local_1c;
              if (local_38 * local_34 < 0x11) {
                if (*(uint *)(local_1c + 0x1a8) <= local_18) {
                  (*pcVar11)(0xc000008c,1,0,0);
                }
                piVar3 = (int *)FUN_00581b40();
                uVar9 = 0;
                local_30 = piVar3;
                if (0 < (int)uVar7) {
                  bVar14 = uVar7 != 0;
                  do {
                    if (!bVar14) {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      piVar3 = local_30;
                    }
                    if (*(int **)(uVar9 * 8) == piVar3) {
                      if (uVar7 <= uVar9) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      uVar12 = *(uint *)(uVar9 * 8 + 4);
                      iVar2 = local_1c;
                      pcVar11 = RaiseException_exref;
                      if (uVar12 != 0xffffffff) {
                        if (uVar7 <= uVar9) {
                          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                          uVar12 = *(uint *)(uVar9 * 8 + 4);
                        }
                        local_58 = (uVar12 ^ local_18) & 0xffff ^ uVar12;
                        FUN_00491db0(&local_58);
                        iVar2 = local_1c;
                        pcVar11 = RaiseException_exref;
                      }
                      goto LAB_0058ad51;
                    }
                    uVar9 = uVar9 + 1;
                    bVar14 = uVar9 < uVar7;
                  } while ((int)uVar9 < (int)uVar7);
                }
                iVar2 = local_1c;
                pcVar11 = RaiseException_exref;
                if (piVar3 != (int *)0x0) {
                  local_2c = (param_4 - local_34) + 1;
                  iVar4 = param_5 + -1 + local_38;
                  local_28 = (param_5 - local_38) + 1;
                  iVar6 = local_34 + -1 + param_4;
                  if ((((-1 < (int)local_28) && (-1 < (int)local_2c)) && (iVar6 < param_2)) &&
                     (iVar4 < param_3)) {
                    local_11 = '\0';
                    local_4c = param_3 - local_38;
                    if (iVar4 < param_3 - local_38) {
                      local_4c = iVar4;
                    }
                    local_50 = param_2 - local_34;
                    if (iVar6 < param_2 - local_34) {
                      local_50 = iVar6;
                    }
                    local_58 = 0;
                    local_54 = 0;
                    piVar3 = local_30;
                    iVar2 = local_34;
                    iVar6 = local_38;
                    if ((int)local_2c < local_50) {
                      do {
                        local_40 = local_28;
                        if ((int)local_28 < local_4c) {
                          uVar7 = local_28 * param_2;
LAB_0058ab50:
                          local_48 = 0;
                          local_3c = uVar7;
                          if (0 < iVar2) {
                            do {
                              local_44 = 0;
                              if (0 < iVar6) {
                                iVar10 = uVar7 + local_48 + local_2c;
                                iVar4 = local_48;
                                do {
                                  if ((iVar4 < 0) || (piVar3[1] <= iVar4)) {
                                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                    piVar3 = (int *)*local_30;
                                  }
                                  else {
                                    piVar3 = (int *)(*piVar3 + iVar4 * 4);
                                  }
                                  iVar1 = *piVar3;
                                  if ((iVar10 < 0) || (param_1[1] <= iVar10)) {
                                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                                    piVar5 = (int *)*param_1;
                                  }
                                  else {
                                    piVar5 = (int *)(*param_1 + iVar10 * 4);
                                  }
                                  piVar3 = local_30;
                                  iVar2 = local_34;
                                  iVar6 = local_38;
                                  if (iVar1 != *piVar5) {
                                    local_40 = local_40 + 1;
                                    uVar7 = local_3c + param_2;
                                    local_3c = uVar7;
                                    if (local_4c <= (int)local_40) goto LAB_0058ad16;
                                    goto LAB_0058ab50;
                                  }
                                  iVar4 = iVar4 + local_34;
                                  iVar10 = iVar10 + param_2;
                                  local_44 = local_44 + 1;
                                  uVar7 = local_3c;
                                } while (local_44 < local_38);
                              }
                              local_48 = local_48 + 1;
                            } while (local_48 < iVar2);
                          }
                          local_58 = local_2c;
                          local_11 = '\x01';
                          local_54 = local_40;
                          break;
                        }
LAB_0058ad16:
                        local_2c = local_2c + 1;
                      } while ((int)local_2c < local_50);
                    }
                    FUN_004151e0(1);
                    local_3c = 0;
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piRamfffffff8 = local_30;
                    if (local_11 == '\0') {
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      uRamfffffffc = 0xffffffff;
                      iVar2 = local_1c;
                      pcVar11 = RaiseException_exref;
                    }
                    else {
                      uVar7 = (local_54 & 0xff | local_58 << 8) << 0x10 | local_18 & 0xffff;
                      FUN_0040b930(1);
                      *(uint *)(local_60 + -4 + local_5c * 4) = uVar7;
                      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      iVar2 = local_1c;
                      pcVar11 = RaiseException_exref;
                      uRamfffffffc = uVar7;
                    }
                  }
                }
              }
            }
          }
        }
      }
LAB_0058ad51:
      local_20 = local_20 + 0x54;
      local_18 = local_18 + 1;
      bVar14 = local_18 < *(uint *)(iVar2 + 0x1a8);
    } while ((int)local_18 < (int)*(uint *)(iVar2 + 0x1a8));
  }
  if (local_5c == 0) {
    uVar13 = 0xffffffff;
  }
  else {
    if (1 < (int)local_5c) {
      uVar9 = local_24[1];
      piVar3 = local_24;
      uVar7 = local_5c;
      do {
        uVar9 = uVar9 - 1;
        if ((int)uVar9 < 0) break;
        uVar12 = 0;
        if (0 < (int)uVar7) {
          do {
            if ((uint)piVar3[1] <= uVar9) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              uVar7 = local_5c;
            }
            iVar2 = *piVar3;
            if (uVar7 <= uVar12) {
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              uVar7 = local_5c;
            }
            if (*(uint *)(iVar2 + uVar9 * 4) == (uint)*(ushort *)(local_60 + uVar12 * 4)) {
              uVar8 = uVar7;
              if (uVar7 <= uVar12) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                uVar8 = local_5c;
              }
              uVar7 = uVar8 - 1;
              piVar3 = local_24;
              local_5c = uVar7;
              if ((int)uVar12 < (int)uVar7) {
                *(undefined4 *)(local_60 + uVar12 * 4) = *(undefined4 *)(local_60 + -4 + uVar8 * 4);
              }
              break;
            }
            uVar12 = uVar12 + 1;
            piVar3 = local_24;
          } while ((int)uVar12 < (int)uVar7);
        }
      } while (1 < (int)uVar7);
    }
    uVar7 = FUN_0049c670();
    uVar7 = (uint)((longlong)(ulonglong)(uVar7 & 0x7fff) % (longlong)(int)local_5c);
    if (3 < local_24[1]) {
      FUN_0040b5c0(0);
    }
    if (local_5c <= uVar7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar9 = FUN_0040b580();
    if ((uint)local_24[1] <= uVar9) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    *(uint *)(*local_24 + uVar9 * 4) = (uint)*(ushort *)(local_60 + uVar7 * 4);
    if (local_5c <= uVar7) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar13 = *(undefined4 *)(local_60 + uVar7 * 4);
  }
  local_8 = CONCAT31(local_8._1_3_,4);
  if ((int)local_3c < 0) {
    FUN_004151e0(-local_3c);
  }
  local_8 = 5;
  FUN_0040b980(0);
  if (local_60 != 0) {
    FUN_006ba940();
  }
  ExceptionList = local_10;
  return uVar13;
}

