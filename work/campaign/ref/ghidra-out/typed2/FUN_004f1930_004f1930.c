
undefined1 FUN_004f1930(undefined4 *param_1)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  BOOL BVar6;
  int in_ECX;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int *piVar10;
  code *pcVar11;
  int *piVar12;
  float fVar13;
  int *piVar14;
  undefined4 in_stack_ffffff98;
  void *in_stack_ffffff9c;
  void *pvVar15;
  undefined4 uVar16;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  int *local_38;
  int *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  char local_12;
  char local_11;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007000cd;
  local_10 = ExceptionList;
  uVar3 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  pvVar15 = *(void **)(in_ECX + 0x48);
  local_3c = 0.0;
  local_40 = 0.0;
  local_44 = 0.0;
  local_18 = in_ECX;
  if (pvVar15 != (void *)0x0) {
    in_stack_ffffff98 = 0x4f1988;
    IsBadReadPtr(pvVar15,0x10);
    in_stack_ffffff9c = pvVar15;
  }
  *(undefined4 *)(in_ECX + 0xb8) = 0x3ca3d70a;
  local_12 = '\0';
  uVar16 = 0x4f199b;
  iVar4 = FUN_004ecd40(uVar3);
  if (*(char *)(iVar4 + 0x123) != '\0') {
    local_12 = '\x01';
    *(undefined4 *)(in_ECX + 0xb8) = 0x3dcccccd;
  }
  pcVar11 = RaiseException_exref;
  if ((param_1[2] == DAT_0077238c) && (*(char *)(in_ECX + 0x44) != '\0')) {
    piVar8 = (int *)(in_ECX + 0x10c);
    local_1c = (int *)0x0;
    local_28 = piVar8;
    do {
      if (local_1c < 3) {
        piVar10 = piVar8 + (int)local_1c;
      }
      else {
        uVar16 = 0;
        in_stack_ffffff9c = (void *)0x0;
        in_stack_ffffff98 = 1;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar10 = piVar8;
      }
      if (param_1[6] == *piVar10) {
        local_2c = (int *)0x0;
        piVar8 = local_1c;
        if (0 < DAT_00772400[0x2832]) {
          do {
            piVar10 = local_2c;
            local_24 = DAT_00772400;
            if (((int)local_2c < 0) || (DAT_00772400[0x2832] <= (int)local_2c)) {
              iVar4 = 0;
            }
            else {
              if ((int *)DAT_00772400[0x2832] <= local_2c) {
                in_stack_ffffff9c = (void *)0x0;
                in_stack_ffffff98 = 1;
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              }
              uVar3 = *(uint *)(local_24[0x2831] + (int)piVar10 * 4);
              piVar8 = (int *)(DAT_0077244c + 0x488);
              if (uVar3 < 0x2000) {
                iVar4 = piVar8[uVar3];
                piVar8 = local_1c;
              }
              else {
                in_stack_ffffff9c = (void *)0x0;
                in_stack_ffffff98 = 1;
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar4 = *piVar8;
                piVar8 = local_1c;
              }
            }
            local_24 = *(int **)(iVar4 + 0x40);
            local_20 = *(int **)(iVar4 + 0x44);
            local_30 = *(int **)(iVar4 + 0x48);
            if (piVar8 < 3) {
              piVar10 = local_28 + (int)piVar8;
            }
            else {
              in_stack_ffffff9c = (void *)0x0;
              in_stack_ffffff98 = 1;
              RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
              piVar10 = local_28;
              piVar8 = local_1c;
            }
            piVar12 = (int *)(((float)*(int *)(*piVar10 + 100) * 6.2831855) / 100.0);
            piVar10 = piVar12;
            piVar7 = local_20;
            piVar14 = local_30;
            if (((piVar8 != (int *)0x0) &&
                (piVar10 = local_24, piVar7 = piVar12, piVar8 != (int *)0x1)) &&
               (piVar7 = local_20, piVar8 == (int *)0x2)) {
              piVar14 = piVar12;
            }
            *(int **)(iVar4 + 0x48) = piVar14;
            *(int **)(iVar4 + 0x44) = piVar7;
            *(int **)(iVar4 + 0x40) = piVar10;
            if ((10000.0 <= (float)piVar10) || ((float)piVar10 <= -10000.0)) {
              *(undefined4 *)(iVar4 + 0x40) = 0;
            }
            if ((10000.0 <= *(float *)(iVar4 + 0x44)) || (*(float *)(iVar4 + 0x44) <= -10000.0)) {
              *(undefined4 *)(iVar4 + 0x44) = 0;
            }
            if ((10000.0 <= *(float *)(iVar4 + 0x48)) || (*(float *)(iVar4 + 0x48) <= -10000.0)) {
              *(undefined4 *)(iVar4 + 0x48) = 0;
            }
            *(uint *)(iVar4 + 0x3d8) = *(uint *)(iVar4 + 0x3d8) | 2;
            *(undefined1 *)(iVar4 + 0x402) = 1;
            if (*(int *)(iVar4 + 0x238) == 0) {
              FUN_005ebc90(iVar4);
              in_stack_ffffff9c = (void *)0x4f1b8d;
              FUN_005eb470(iVar4);
              piVar8 = local_1c;
            }
            local_2c = (int *)((int)local_2c + 1);
          } while ((int)local_2c < DAT_00772400[0x2832]);
        }
        FUN_004f3630();
        uVar16 = 0x4f1bb8;
        FUN_00504ee0();
        piVar8 = local_28;
      }
      local_1c = (int *)((int)local_1c + 1);
      in_ECX = local_18;
    } while ((int)local_1c < 3);
  }
  iVar4 = param_1[2];
  if (iVar4 == DAT_00772388) {
    local_20 = (int *)(in_ECX + 0xe4);
    local_1c = (int *)0x0;
    do {
      piVar8 = local_20;
      if (local_1c < (int *)0x9) {
        piVar10 = local_20 + (int)local_1c;
      }
      else {
        (*pcVar11)(0xc000008c,1,0,0);
        piVar10 = piVar8;
      }
      piVar7 = local_1c;
      if (param_1[6] == *piVar10) {
        local_28 = (int *)0x0;
        do {
          if (local_28 != piVar7) {
            if (local_28 < (int *)0x9) {
              piVar8 = piVar8 + (int)local_28;
            }
            else {
              (*pcVar11)(0xc000008c,1,0,0);
            }
            iVar4 = *piVar8;
            iVar9 = 0;
            if (*(char *)(iVar4 + 0x2c) != '\0') {
              iVar5 = FUN_00501450();
              if ((*(int *)(iVar5 + 0x8198) == iVar4) &&
                 ((iVar5 = FUN_00501450(), *(int *)(iVar5 + 0x81a4) == 0 ||
                  (iVar5 = FUN_00501450(), *(int *)(iVar5 + 0x81a4) == iVar4)))) {
                iVar9 = 1;
              }
              iVar5 = FUN_00501450();
              if ((*(int *)(iVar5 + 0x819c) != iVar4) && (iVar9 == 1)) {
                iVar9 = 0;
              }
              FUN_00501450();
            }
            piVar7 = local_1c;
            piVar8 = local_20;
            pcVar11 = RaiseException_exref;
            if (iVar9 != *(int *)(iVar4 + 0x48)) {
              *(int *)(iVar4 + 0x48) = iVar9;
              FUN_00504ee0();
              piVar7 = local_1c;
              piVar8 = local_20;
              pcVar11 = RaiseException_exref;
            }
          }
          local_28 = (int *)((int)local_28 + 1);
        } while ((int)local_28 < 9);
        if (*(char *)(local_18 + 0x44) != '\0') {
          *(int **)(local_18 + 0x4c) = piVar7;
          uVar3 = 0;
          piVar8 = DAT_00772400;
          if (0 < DAT_00772400[0x2832]) {
            do {
              local_30 = piVar8 + 0x2831;
              if (((int)uVar3 < 0) || (piVar8[0x2832] <= (int)uVar3)) {
                iVar4 = 0;
              }
              else {
                if ((uint)piVar8[0x2832] <= uVar3) {
                  (*pcVar11)(0xc000008c,1,0,0);
                  piVar8 = DAT_00772400;
                }
                uVar1 = *(uint *)(*local_30 + uVar3 * 4);
                local_30 = (int *)(DAT_0077244c + 0x488);
                if (uVar1 < 0x2000) {
                  iVar4 = local_30[uVar1];
                }
                else {
                  (*pcVar11)(0xc000008c,1,0,0);
                  iVar4 = *local_30;
                  piVar8 = DAT_00772400;
                }
              }
              uVar3 = uVar3 + 1;
              *(int *)(iVar4 + 0x36c) = *(int *)(local_18 + 0x4c) + -1;
            } while ((int)uVar3 < piVar8[0x2832]);
          }
          FUN_004f3880();
          FUN_00504ee0();
          piVar7 = local_1c;
        }
      }
      local_1c = (int *)((int)piVar7 + 1);
    } while ((int)local_1c < 9);
    if (*(char *)(local_18 + 0x44) != '\0') {
      local_1c = (int *)0x0;
      if (0 < *(int *)(local_18 + 0x54)) {
        piVar8 = (int *)(local_18 + 0xc4);
        local_28 = (int *)0x0;
        local_38 = piVar8;
        do {
          if (&DAT_00000007 < local_1c) {
            (*pcVar11)(0xc000008c,1,0,0);
            piVar10 = piVar8;
          }
          else {
            piVar10 = piVar8 + (int)local_1c;
          }
          if (param_1[6] == *piVar10) {
            if (&DAT_00000007 < local_1c) {
              (*pcVar11)(0xc000008c,1,0,0);
            }
            else {
              piVar8 = piVar8 + (int)local_1c;
            }
            uVar3 = 0;
            local_34 = *(int **)(*piVar8 + 0x48);
            if (0 < DAT_00772400[0x2832]) {
              local_24 = (int *)(local_18 + 0x58);
              do {
                local_30 = DAT_00772400;
                if (((int)uVar3 < 0) || (DAT_00772400[0x2832] <= (int)uVar3)) {
                  local_2c = (int *)0x0;
                }
                else {
                  if ((uint)DAT_00772400[0x2832] <= uVar3) {
                    (*pcVar11)(0xc000008c,1,0,0);
                  }
                  uVar1 = *(uint *)(local_30[0x2831] + uVar3 * 4);
                  local_30 = (int *)(DAT_0077244c + 0x488);
                  if (uVar1 < 0x2000) {
                    local_2c = (int *)local_30[uVar1];
                  }
                  else {
                    (*pcVar11)(0xc000008c,1,0,0);
                    local_2c = (int *)*local_30;
                  }
                }
                if (local_34 == (int *)&DAT_00000005) {
                  if (&DAT_00000007 < local_1c) {
                    (*pcVar11)(0xc000008c,1,0,0);
                    local_2c[0xf4] = local_2c[0xf4] | local_24[2];
                  }
                  else {
                    local_2c[0xf4] =
                         local_2c[0xf4] |
                         *(uint *)((undefined1 *)((int)local_28 + (int)local_24) + 8);
                  }
                }
                else {
                  if (&DAT_00000007 < local_1c) {
                    (*pcVar11)(0xc000008c,1,0,0);
                    piVar8 = local_24;
                  }
                  else {
                    piVar8 = (int *)((int)local_28 + (int)local_24);
                  }
                  local_2c[0xf4] = local_2c[0xf4] & ~piVar8[2];
                }
                uVar3 = uVar3 + 1;
              } while ((int)uVar3 < DAT_00772400[0x2832]);
            }
            FUN_004f3450();
            FUN_00504ee0();
            piVar8 = local_38;
          }
          local_1c = (int *)((int)local_1c + 1);
          local_28 = local_28 + 3;
        } while ((int)local_1c < *(int *)(local_18 + 0x54));
      }
      piVar8 = DAT_00772400;
      if (param_1[6] == *(int *)(local_18 + 0x108)) {
        *(int *)(local_18 + 0x4c) = (*(int *)(local_18 + 0x4c) + 1) % 9;
        local_2c = (int *)0x0;
        if (0 < piVar8[0x2832]) {
          do {
            if (((int)local_2c < 0) || (piVar8[0x2832] <= (int)local_2c)) {
              iVar4 = 0;
            }
            else {
              if ((int *)piVar8[0x2832] <= local_2c) {
                (*pcVar11)(0xc000008c,1,0,0);
              }
              piVar10 = (int *)(DAT_0077244c + 0x488);
              uVar3 = *(uint *)(piVar8[0x2831] + (int)local_2c * 4);
              if (uVar3 < 0x2000) {
                iVar4 = piVar10[uVar3];
              }
              else {
                (*pcVar11)(0xc000008c,1,0,0);
                iVar4 = *piVar10;
              }
            }
            *(int *)(iVar4 + 0x36c) = *(int *)(local_18 + 0x4c) + -1;
            local_28 = (int *)0x0;
            do {
              if (local_28 < (int *)0x9) {
                piVar8 = local_20 + (int)local_28;
              }
              else {
                (*pcVar11)(0xc000008c,1,0,0);
                piVar8 = local_20;
              }
              iVar4 = *piVar8;
              iVar9 = 0;
              if (*(char *)(iVar4 + 0x2c) != '\0') {
                iVar5 = FUN_00501450();
                if ((*(int *)(iVar5 + 0x8198) == iVar4) &&
                   ((iVar5 = FUN_00501450(), *(int *)(iVar5 + 0x81a4) == 0 ||
                    (iVar5 = FUN_00501450(), *(int *)(iVar5 + 0x81a4) == iVar4)))) {
                  iVar9 = 1;
                }
                iVar5 = FUN_00501450();
                if ((*(int *)(iVar5 + 0x819c) != iVar4) && (iVar9 == 1)) {
                  iVar9 = 0;
                }
                FUN_00501450();
              }
              if (iVar9 != *(int *)(iVar4 + 0x48)) {
                *(int *)(iVar4 + 0x48) = iVar9;
                FUN_00504ee0();
              }
              local_28 = (int *)((int)local_28 + 1);
              pcVar11 = RaiseException_exref;
            } while ((int)local_28 < 9);
            local_2c = (int *)((int)local_2c + 1);
            piVar8 = DAT_00772400;
          } while ((int)local_2c < DAT_00772400[0x2832]);
        }
        FUN_004f3880();
        FUN_00504ee0();
      }
    }
    pcVar11 = RaiseException_exref;
    if (param_1[6] == *(int *)(local_18 + 0x118)) {
      if (local_12 == '\0') {
        if ((*(char *)(local_18 + 0x44) != '\0') &&
           (uVar3 = 0, piVar8 = DAT_00772400, 0 < DAT_00772400[0x2832])) {
          do {
            local_38 = piVar8 + 0x2831;
            if (((int)uVar3 < 0) || (piVar8[0x2832] <= (int)uVar3)) {
              iVar4 = 0;
            }
            else {
              if ((uint)piVar8[0x2832] <= uVar3) {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                piVar8 = DAT_00772400;
              }
              uVar1 = *(uint *)(*local_38 + uVar3 * 4);
              local_38 = (int *)(DAT_0077244c + 0x488);
              if (uVar1 < 0x2000) {
                iVar4 = local_38[uVar1];
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar4 = *local_38;
                piVar8 = DAT_00772400;
              }
            }
            uVar3 = uVar3 + 1;
            *(undefined4 *)(iVar4 + 0x2a8) = 2;
          } while ((int)uVar3 < piVar8[0x2832]);
        }
      }
      else {
        *(undefined4 *)(local_18 + 0x124) = 2;
        pcVar11 = RaiseException_exref;
      }
      FUN_004f40d0();
      FUN_00504ee0();
    }
    if (param_1[6] == *(int *)(local_18 + 0x11c)) {
      if (local_12 == '\0') {
        if (*(char *)(local_18 + 0x44) != '\0') {
          uVar3 = 0;
          local_2c = DAT_00772400;
          if (0 < DAT_00772400[0x2832]) {
            do {
              if (((int)uVar3 < 0) || (DAT_00772400[0x2832] <= (int)uVar3)) {
                local_2c = (int *)0x0;
              }
              else {
                local_2c = DAT_00772400;
                if ((uint)DAT_00772400[0x2832] <= uVar3) {
                  (*pcVar11)(0xc000008c,1,0,0);
                }
                uVar1 = *(uint *)(local_2c[0x2831] + uVar3 * 4);
                local_38 = (int *)(DAT_0077244c + 0x488);
                if (uVar1 < 0x2000) {
                  local_2c = (int *)local_38[uVar1];
                }
                else {
                  (*pcVar11)(0xc000008c,1,0,0);
                  local_2c = (int *)*local_38;
                }
              }
              local_38 = (int *)FUN_006ba810(0x19);
              local_38[1] = 0x14;
              local_38[2] = -1;
              *local_38 = 0;
              *(undefined1 *)(local_38 + 3) = 0;
              local_38[3] = 0x74696445;
              local_38[4] = 0x535f726f;
              local_38[5] = 0x495f7465;
              local_38[6] = 0x6f666e;
              local_38[2] = 0xf;
              *local_38 = 1;
              local_34 = local_38;
              iVar4 = FUN_00601d30(&local_38);
              local_11 = iVar4 == -1;
              local_8._0_1_ = 1;
              *local_34 = *local_34 + -1;
              if (*local_34 == 0) {
                FUN_006ba940();
              }
              local_8 = (uint)local_8._1_3_ << 8;
              if (local_11 != '\0') {
                *(undefined4 *)((int)local_2c + 0x2a8) = 1;
              }
              uVar3 = uVar3 + 1;
              local_2c = DAT_00772400;
            } while ((int)uVar3 < DAT_00772400[0x2832]);
          }
        }
      }
      else {
        *(undefined4 *)(local_18 + 0x124) = 1;
      }
      FUN_004f40d0();
      FUN_00504ee0();
    }
    if (param_1[6] == *(int *)(local_18 + 0x120)) {
      if (local_12 == '\0') {
        if (*(char *)(local_18 + 0x44) != '\0') {
          local_28 = (int *)0x0;
          local_2c = DAT_00772400;
          if (0 < DAT_00772400[0x2832]) {
            do {
              piVar8 = local_28;
              if (((int)local_28 < 0) || (DAT_00772400[0x2832] <= (int)local_28)) {
                local_2c = (int *)0x0;
              }
              else {
                local_2c = DAT_00772400;
                if ((int *)DAT_00772400[0x2832] <= local_28) {
                  (*pcVar11)(0xc000008c,1,0,0);
                }
                uVar3 = *(uint *)(local_2c[0x2831] + (int)piVar8 * 4);
                piVar8 = (int *)(DAT_0077244c + 0x488);
                if (uVar3 < 0x2000) {
                  local_2c = (int *)piVar8[uVar3];
                }
                else {
                  (*pcVar11)(0xc000008c,1,0,0);
                  local_2c = (int *)*piVar8;
                }
              }
              piVar8 = (int *)FUN_006ba810(0x19);
              piVar8[1] = 0x14;
              piVar8[2] = -1;
              *piVar8 = 0;
              *(undefined1 *)(piVar8 + 3) = 0;
              piVar8[3] = 0x74696445;
              piVar8[4] = 0x535f726f;
              piVar8[5] = 0x495f7465;
              piVar8[6] = 0x6f666e;
              piVar8[2] = 0xf;
              *piVar8 = 1;
              local_38 = piVar8;
              iVar4 = FUN_00601d30(&local_38);
              local_12 = iVar4 == -1;
              local_8._0_1_ = 2;
              *piVar8 = *piVar8 + -1;
              if (*piVar8 == 0) {
                FUN_006ba940();
              }
              local_8 = (uint)local_8._1_3_ << 8;
              if (local_12 != '\0') {
                *(undefined4 *)((int)local_2c + 0x2a8) = 0;
              }
              local_28 = (int *)((int)local_28 + 1);
              local_2c = DAT_00772400;
            } while ((int)local_28 < DAT_00772400[0x2832]);
          }
        }
      }
      else {
        *(undefined4 *)(local_18 + 0x124) = 0;
      }
      FUN_004f40d0();
      FUN_00504ee0();
    }
    if (param_1 != (undefined4 *)0x0) {
      LOCK();
      iVar4 = param_1[1] + -1;
      param_1[1] = iVar4;
      UNLOCK();
      if ((iVar4 == 0) && (param_1 != (undefined4 *)0x0)) {
        (**(code **)*param_1)(1);
      }
    }
    ExceptionList = local_10;
    return 1;
  }
  if ((iVar4 != DAT_00772384) && (iVar4 != DAT_00772380)) {
    LOCK();
    iVar4 = param_1[1] + -1;
    param_1[1] = iVar4;
    UNLOCK();
    if ((iVar4 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
    ExceptionList = local_10;
    return 0;
  }
  local_11 = 0;
  local_50 = 0.0;
  local_4c = 0.0;
  iVar4 = *(int *)(DAT_00772374 + 0x1e8);
  local_12 = *(char *)(DAT_00772374 + 0x1b8);
  local_48 = 0.0;
  local_38 = DAT_00772400;
  if ((0 < DAT_00772400[0x2832]) && (0 < DAT_00772400[0x2832])) {
    if (DAT_00772400[0x2832] == 0) {
      uVar16 = 0;
      in_stack_ffffff9c = (void *)0x0;
      in_stack_ffffff98 = 1;
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    uVar3 = *(uint *)local_38[0x2831];
    if (uVar3 != 0xffffffff) {
      local_38 = (int *)(DAT_0077244c + 0x488);
      if (uVar3 < 0x2000) {
        piVar8 = local_38 + uVar3;
      }
      else {
        uVar16 = 0;
        in_stack_ffffff9c = (void *)0x0;
        in_stack_ffffff98 = 1;
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar8 = local_38;
      }
      iVar9 = *piVar8;
      local_50 = *(float *)(iVar9 + 0x40);
      local_4c = *(float *)(iVar9 + 0x44);
      local_48 = *(float *)(iVar9 + 0x48);
    }
  }
  switch(param_1[0x10]) {
  case 0x21:
    if (local_12 == '\0') {
      local_3c = local_3c - *(float *)(local_18 + 0xb8);
      FUN_004f1740(&local_44);
    }
    else {
      local_3c = local_3c - 2.0;
      FUN_004f1740(&local_44);
    }
    break;
  case 0x22:
    if (local_12 == '\0') {
      local_3c = local_3c + *(float *)(local_18 + 0xb8);
      FUN_004f1740(&local_44);
    }
    else {
      local_3c = local_3c + 2.0;
      FUN_004f1740(&local_44);
    }
    break;
  default:
    goto switchD_004f2587_caseD_23;
  case 0x25:
    if (local_12 == '\0') {
      local_44 = local_44 - *(float *)(local_18 + 0xb8);
      FUN_004f1740(&local_44);
    }
    else {
      local_44 = local_44 - 1.0;
      FUN_004f1740(&local_44);
    }
    break;
  case 0x26:
    if (local_12 == '\0') {
      local_40 = local_40 - *(float *)(local_18 + 0xb8);
      FUN_004f1740(&local_44);
    }
    else {
      local_40 = local_40 - 1.0;
      FUN_004f1740(&local_44);
    }
    break;
  case 0x27:
    if (local_12 == '\0') {
      local_44 = local_44 + *(float *)(local_18 + 0xb8);
      FUN_004f1740(&local_44);
    }
    else {
      local_44 = local_44 + 1.0;
      FUN_004f1740(&local_44);
    }
    break;
  case 0x28:
    if (local_12 == '\0') {
      local_40 = local_40 + *(float *)(local_18 + 0xb8);
      FUN_004f1740(&local_44);
    }
    else {
      local_40 = local_40 + 1.0;
      FUN_004f1740(&local_44);
    }
    break;
  case 0x42:
    uVar3 = 0;
    if (0 < DAT_00772400[0x2832]) {
      do {
        local_38 = DAT_00772400;
        if ((-1 < (int)uVar3) && ((int)uVar3 < DAT_00772400[0x2832])) {
          if ((uint)DAT_00772400[0x2832] <= uVar3) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar1 = *(uint *)(local_38[0x2831] + uVar3 * 4);
          local_38 = (int *)(DAT_0077244c + 0x488);
          if (uVar1 < 0x2000) {
            local_30 = local_38 + uVar1;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            local_30 = local_38;
          }
          local_30 = (int *)*local_30;
          if (local_30 != (int *)0x0) {
            local_34 = (int *)(int)ROUND((float)local_30[3] * 8.0);
            local_38 = (int *)((float)local_30[4] * 8.0);
            DAT_00772dd8 = (int)ROUND((float)local_38);
            local_2c = (int *)(DAT_00772dd8 + -2);
            if (((PTR_0077241c != (CMap *)0x0) && ((char)PTR_0077241c->mapFlags != '\0')) &&
               ((PTR_0077241c->x0_8 + 0x40 <= (int)local_34 &&
                ((((int)local_34 < PTR_0077241c->x1_8 + -0x40 &&
                  (PTR_0077241c->y0_8 + 0x40 <= (int)local_2c)) &&
                 ((int)local_2c < PTR_0077241c->y1_8 + -0x40)))))) {
              bVar2 = FUN_004093f0(PTR_0077241c);
              local_50 = (float)local_30[3];
              local_4c = (float)local_30[4];
              local_48 = (float)bVar2 + 0.02;
              FUN_005cd7e0(&local_50);
            }
          }
        }
        uVar3 = uVar3 + 1;
      } while ((int)uVar3 < DAT_00772400[0x2832]);
    }
    break;
  case 0x46:
    local_20 = (int *)0x0;
    if (0 < DAT_00772400[0x2832]) {
      do {
        piVar8 = DAT_00772400;
        if ((-1 < (int)local_20) && ((int)local_20 < DAT_00772400[0x2832])) {
          if ((int *)DAT_00772400[0x2832] <= local_20) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          piVar10 = (int *)(DAT_0077244c + 0x488);
          uVar3 = *(uint *)(piVar8[0x2831] + (int)local_20 * 4);
          if (uVar3 < 0x2000) {
            piVar10 = piVar10 + uVar3;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          iVar4 = *piVar10;
          if (iVar4 != 0) {
            local_50 = *(float *)(iVar4 + 0xc);
            local_4c = *(float *)(iVar4 + 0x10);
            local_48 = 15.0;
            if ((((NAN(local_50)) || (NAN(local_4c))) || (*(float *)(iVar4 + 0x14) != 15.0)) &&
               (FUN_005cd8e0(&local_50), *(int *)(iVar4 + 0x238) == 0)) {
              FUN_005ebc90(iVar4);
              FUN_005eb470(iVar4);
            }
          }
        }
        local_20 = (int *)((int)local_20 + 1);
      } while ((int)local_20 < DAT_00772400[0x2832]);
    }
    break;
  case 0x47:
    uVar3 = 0;
    if (0 < DAT_00772400[0x2832]) {
      do {
        local_38 = DAT_00772400;
        if ((-1 < (int)uVar3) && ((int)uVar3 < DAT_00772400[0x2832])) {
          if ((uint)DAT_00772400[0x2832] <= uVar3) {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          }
          uVar1 = *(uint *)(local_38[0x2831] + uVar3 * 4);
          local_38 = (int *)(DAT_0077244c + 0x488);
          if (uVar1 < 0x2000) {
            piVar8 = local_38 + uVar1;
          }
          else {
            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
            piVar8 = local_38;
          }
          if (*piVar8 != 0) {
            FUN_004f4720(*piVar8);
          }
        }
        uVar3 = uVar3 + 1;
      } while ((int)uVar3 < DAT_00772400[0x2832]);
    }
    break;
  case 0x61:
    if (*(int *)(iVar4 + 0x48) == 5) {
      local_3c = 0.7853982;
    }
    else {
      fVar13 = *(float *)(local_18 + 0xb8) + *(float *)(local_18 + 0xb8);
LAB_004f2998:
      DAT_00772dd8 = 0xf570;
      local_38 = (int *)0x47756fdb;
      local_3c = (float)((int)ROUND(fVar13 * 10000.0) % 0xf570) / 10000.0;
    }
    goto LAB_004f29ae;
  case 0x62:
    if (*(int *)(iVar4 + 0x48) == 5) {
      local_44 = -0.7853982;
      local_40 = 0.0;
    }
    else {
      fVar13 = -*(float *)(local_18 + 0xb8) + -*(float *)(local_18 + 0xb8);
LAB_004f28ab:
      DAT_00772dd8 = 0xf570;
      local_38 = (int *)0x47756fdb;
      local_40 = 0.0;
      local_44 = (float)((int)ROUND(fVar13 * 10000.0) % 0xf570) / 10000.0;
    }
    goto LAB_004f27c0;
  case 99:
    if (*(int *)(iVar4 + 0x48) != 5) {
      fVar13 = -*(float *)(local_18 + 0xb8) + -*(float *)(local_18 + 0xb8);
      goto LAB_004f2998;
    }
    local_3c = -0.7853982;
LAB_004f29ae:
    local_44 = 0.0;
    local_40 = 0.0;
    goto LAB_004f27c7;
  case 100:
    if (*(int *)(iVar4 + 0x48) == 5) {
      local_40 = 0.7853982;
    }
    else {
      fVar13 = *(float *)(local_18 + 0xb8) + *(float *)(local_18 + 0xb8);
LAB_004f279e:
      DAT_00772dd8 = 0xf570;
      local_38 = (int *)0x47756fdb;
      local_40 = (float)((int)ROUND(fVar13 * 10000.0) % 0xf570) / 10000.0;
    }
    goto LAB_004f27b4;
  case 0x65:
    FUN_004f2e90(0,0,0);
    break;
  case 0x66:
    if (*(int *)(iVar4 + 0x48) != 5) {
      fVar13 = -*(float *)(local_18 + 0xb8) + -*(float *)(local_18 + 0xb8);
      goto LAB_004f279e;
    }
    local_40 = -0.7853982;
LAB_004f27b4:
    local_44 = 0.0;
    goto LAB_004f27c0;
  case 0x68:
    if (*(int *)(iVar4 + 0x48) != 5) {
      fVar13 = *(float *)(local_18 + 0xb8) + *(float *)(local_18 + 0xb8);
      goto LAB_004f28ab;
    }
    local_44 = 0.7853982;
    local_40 = 0.0;
LAB_004f27c0:
    local_3c = 0.0;
LAB_004f27c7:
    FUN_005e6060(&local_44);
    FUN_004f2e90(in_stack_ffffff98,in_stack_ffffff9c,uVar16);
  }
  local_11 = 1;
switchD_004f2587_caseD_23:
  pvVar15 = *(void **)(DAT_00772374 + 0x1a8);
  if (((pvVar15 == (void *)0x0) || (BVar6 = IsBadReadPtr(pvVar15,0x10), BVar6 != 0)) ||
     ((*(int *)((int)pvVar15 + 8) != 0x616e4f62 ||
      ((DAT_00768398 != '\0' && (*(int *)((int)pvVar15 + 0xdc) == 0)))))) {
    piVar8 = DAT_00772400;
    if (DAT_00772400[0x2832] < 1) goto LAB_004f2dca;
    if (DAT_00772400[0x2832] == 0) {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    piVar10 = (int *)(DAT_0077244c + 0x488);
    if (*(uint *)piVar8[0x2831] < 0x2000) {
      piVar10 = piVar10 + *(uint *)piVar8[0x2831];
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
    }
    iVar4 = *piVar10;
    if (iVar4 == 0) goto LAB_004f2dca;
  }
  else {
    iVar4 = *(int *)(DAT_00772374 + 0x1a8);
  }
  *(undefined4 *)(local_18 + 0xbc) = *(undefined4 *)(iVar4 + 0x14);
LAB_004f2dca:
  FUN_004f3630();
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar4 = param_1[1] + -1;
    param_1[1] = iVar4;
    UNLOCK();
    if ((iVar4 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return local_11;
}

