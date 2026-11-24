
void __thiscall FUN_005237b0(ViWinProduction *this)

{
  uint uVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  undefined4 *puVar14;
  int *piVar15;
  float10 fVar16;
  int *local_3c;
  undefined8 local_38;
  int *local_30;
  ViWinProduction *local_2c;
  int *local_28;
  uint local_24;
  int *local_20;
  int local_1c;
  int *local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0070246d;
  local_10 = ExceptionList;
  uVar4 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (this->field_0x1c == '\0') {
    return;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(DAT_00772400 + 0xa0d0) = 0xffffffff;
  local_2c = this;
  iVar5 = FUN_00501450(uVar4);
  if (*(int *)(*(int *)(iVar5 + 0x8194) + 0xe8) == 0) {
    FUN_00505ed0();
  }
  iVar5 = *(int *)&this->field_0x20354;
  if (0 < iVar5) {
    piVar15 = (int *)&this->field_0x54;
    if (iVar5 - 1U < 0x20) {
      puVar6 = (undefined1 *)((int)piVar15 + (iVar5 * 0x406 + -0x406) * 4);
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      puVar6 = (undefined1 *)piVar15;
    }
    if (*(int *)(puVar6 + 0x1014) == 2) {
      uVar7 = *(int *)&this->field_0x20354 - 1;
      if (uVar7 < 0x20) {
        piVar15 = (int *)((int)this + uVar7 * 0x1018 + 0x54);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*piVar15 != 0) {
        iVar5 = FUN_004ecd40();
        if (*(char *)(iVar5 + 0x11a) == '\0') {
          cVar3 = FUN_006b9930();
          if (cVar3 != '\0') {
            FUN_00507d40();
            uVar8 = FUN_004435d0(&local_28);
            FUN_00443730(uVar8);
            local_8 = 2;
            FUN_006b91c0();
            local_8 = 3;
            goto LAB_00523933;
          }
        }
        else {
          cVar3 = FUN_006b9930();
          if (cVar3 != '\0') {
            FUN_00507d40();
            uVar8 = FUN_004435d0(&local_28);
            FUN_00443730(uVar8);
            local_8 = 0;
            FUN_006b91c0();
            local_8 = 1;
LAB_00523933:
            if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
              FUN_006ba940();
            }
            local_8 = 0xffffffff;
          }
        }
      }
    }
  }
  if (*(int *)(DAT_00772400 + 0xa0c8) == 1) {
    uVar7 = **(uint **)(DAT_00772400 + 0xa0c4);
  }
  else {
    uVar7 = 0xffffffff;
  }
  uVar1 = this->i_48;
  if (uVar1 == uVar7) {
    if (0 < (int)uVar1) {
      piVar15 = (int *)(DAT_0077244c + 0x488);
      if (uVar1 < 0x2000) {
        piVar15 = piVar15 + uVar1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*piVar15 != 0) {
        if (*(int *)(*piVar15 + 0x3e0) != 0) {
          if ((this->field_0x45 != '\0') && (this->field_0x44 == '\0')) {
            *(undefined2 *)&this->field_0x44 = 1;
            FUN_00524c80();
          }
          iVar5 = FUN_005eda80();
          if (*(int *)&this->field_0x50 != iVar5) {
            *(int *)&this->field_0x50 = iVar5;
            FUN_00523760();
          }
        }
        iVar5 = FUN_005cf210();
        if (*(int *)&this->field_0x4c != iVar5) {
          uVar8 = FUN_005cf210();
          *(undefined4 *)&this->field_0x4c = uVar8;
          goto LAB_005239fc;
        }
      }
    }
  }
  else {
    this->i_48 = uVar7;
LAB_005239fc:
    FUN_00523760();
  }
  iVar9 = FUN_00501450(uVar4);
  iVar5 = *(int *)&this->field_0x10;
  local_1c = this->i_0c;
  local_28 = *(int **)(iVar9 + 0x101d8);
  for (iVar12 = *(int *)&this->field_0x34; iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x34)) {
    local_1c = local_1c + *(int *)(iVar12 + 0xc);
    iVar5 = iVar5 + *(int *)(iVar12 + 0x10);
  }
  local_1c = *(int *)(iVar9 + 0x101d4) - local_1c;
  local_18 = (int *)0xffffffff;
  if (((((uint)((int)local_28 - iVar5) < 0x28) && (local_1c < this->i_14 - this->i_0c)) &&
      (0 < local_1c)) && (piVar15 = (int *)0x0, 0 < *(int *)&this->field_0x20354)) {
    puVar6 = &this->field_0x54;
    do {
      local_28 = (int *)((int)piVar15 * 0x1018);
      if (piVar15 < (int *)0x20) {
        piVar10 = (int *)((int)local_28 + (int)puVar6);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar10 = (int *)puVar6;
      }
      piVar13 = piVar15;
      if (*piVar10 != 0) {
        if (piVar15 < (int *)0x20) {
          piVar10 = *(int **)(*(int *)((int)local_28 + (int)puVar6) + 0xc);
          piVar11 = (int *)((int)local_28 + (int)puVar6);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_28 = *(int **)(*(int *)puVar6 + 0xc);
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar10 = local_28;
          piVar11 = (int *)puVar6;
        }
        if (((int)piVar10 < local_1c) &&
           (local_1c < (int)piVar10 + (*(int *)(*piVar11 + 0x14) - *(int *)(*piVar11 + 0xc)))) {
          piVar13 = *(int **)&this->field_0x20354;
          local_18 = piVar15;
        }
      }
      piVar15 = (int *)((int)piVar13 + 1);
    } while ((int)piVar15 < *(int *)&this->field_0x20354);
    if (local_18 != (int *)0xffffffff) {
      *(int *)(DAT_00772400 + 0xa0d0) = this->i_48;
      piVar15 = local_18;
      goto LAB_00523b2e;
    }
  }
  piVar15 = local_18;
  FUN_006b9200();
LAB_00523b2e:
  if (DAT_007687b4 != piVar15) {
    DAT_007687b4 = piVar15;
    FUN_006b8f50();
    local_8._0_1_ = 4;
    local_8._1_3_ = 0;
    if (piVar15 != (int *)0xffffffff) {
      local_30 = (int *)&this->field_0x54;
      iVar5 = FUN_00524da0();
      if (*(int *)(iVar5 + 0x1014) == 0) {
        iVar5 = FUN_00524da0();
        if (*(int *)(iVar5 + 4) == 0) {
          FUN_00524da0();
          uVar8 = FUN_004435d0(&local_28);
          FUN_00443730(uVar8);
          local_8._0_1_ = 7;
          FUN_006b91c0();
          local_8._0_1_ = 8;
          if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
            FUN_006ba940();
          }
          local_8._0_1_ = 4;
          iVar5 = FUN_00524da0();
          if ((*(int *)(iVar5 + 0x10) != -1) && ((int)piVar15 < *(int *)&this->field_0x20354 + -1))
          {
            FUN_0043d690();
            FUN_006b9390();
            uVar8 = FUN_004435d0(&local_28);
            FUN_00443730(uVar8);
            local_8._0_1_ = 9;
            FUN_006b9290();
            local_8._0_1_ = 10;
            if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
              FUN_006ba940();
            }
            local_8._0_1_ = 4;
            iVar5 = FUN_00524da0();
            local_1c = *(int *)(iVar5 + 8);
            if ((local_1c != 0) && (local_24 = *(uint *)(local_1c + 0x44), 0 < (int)local_24)) {
              uVar4 = 0;
              uVar2 = (undefined1)local_8;
              do {
                local_8._0_1_ = uVar2;
                iVar5 = local_14[2];
                if (iVar5 == -1) {
                  piVar15 = local_14 + 3;
                  do {
                    iVar5 = *piVar15;
                    piVar15 = (int *)((int)piVar15 + 1);
                  } while ((char)iVar5 != '\0');
                  iVar5 = (int)piVar15 - ((int)local_14 + 0xd);
                  local_14[2] = iVar5;
                }
                local_14 = (int *)FUN_006b8df0(local_14,iVar5 + 2);
                iVar12 = local_1c;
                *(undefined2 *)(iVar5 + 0xc + (int)local_14) = 10;
                local_14[2] = iVar5 + 1;
                if (*(uint *)(local_1c + 0x44) <= uVar4) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                local_28 = *(int **)(*(int *)(iVar12 + 0x40) + uVar4 * 8);
                iVar5 = FUN_005da0f0();
                puVar14 = (undefined4 *)(iVar5 + 0x2004);
                if (local_28 < (int *)0x200) {
                  puVar14 = puVar14 + (int)local_28;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                piVar15 = (int *)*puVar14;
                if (piVar15 != (int *)0x0) {
                  *piVar15 = *piVar15 + 1;
                }
                local_8 = CONCAT31(local_8._1_3_,0xb);
                uVar7 = *(uint *)(local_1c + 0x44);
                local_3c = piVar15;
                if (uVar7 <= uVar4) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  uVar7 = *(uint *)(local_1c + 0x44);
                }
                local_28 = (int *)(*(float *)(*(int *)(local_1c + 0x40) + 4 + uVar4 * 8) * 100.0);
                if (uVar7 <= uVar4) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                local_38 = (double)(float)local_28;
                fVar16 = (float10)FUN_006f26b0(local_38);
                local_38 = (double)fVar16;
                FUN_006b90d0(&local_20,"%s:%3.0f",piVar15 + 3,local_38);
                local_8._0_1_ = 0xc;
                FUN_006b9290();
                local_8._0_1_ = 0xd;
                if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
                  FUN_006ba940();
                }
                local_8._0_1_ = 0xe;
                if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 == 0)) {
                  FUN_006ba940();
                }
                uVar4 = uVar4 + 1;
                local_8._0_1_ = 4;
                uVar2 = (undefined1)local_8;
                local_8._0_1_ = 4;
                this = local_2c;
              } while ((int)uVar4 < (int)local_24);
            }
          }
        }
        else {
          FUN_00524da0();
          uVar8 = FUN_004435d0(&local_28);
          FUN_00443730(uVar8);
          local_8._0_1_ = 5;
          FUN_006b91c0();
          local_8._0_1_ = 6;
          if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
            FUN_006ba940();
          }
          local_8._0_1_ = 4;
        }
        iVar5 = FUN_00524da0();
        piVar15 = *(int **)(iVar5 + 8);
        local_30 = piVar15;
        if (((piVar15 != (int *)0x0) && (iVar5 = FUN_00524da0(), *(int *)(iVar5 + 4) != 0)) &&
           (iVar5 = FUN_00524da0(), *(char *)(*(int *)(*(int *)(iVar5 + 4) + 0xc) + 0xc) != '_')) {
          local_1c = 0;
          FUN_006b8f50();
          local_8._0_1_ = 0xf;
          local_28 = (int *)piVar15[9];
          if (0 < (int)local_28) {
            FUN_006b9200();
            iVar5 = 0;
            local_24 = 0;
            piVar15 = (int *)((int)local_28 + 1);
            local_20 = piVar15;
            if (0 < (int)piVar15) {
              do {
                uVar4 = local_24;
                piVar10 = local_30;
                if ((int)local_24 < (int)local_28) {
                  if ((uint)local_30[9] <= local_24) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar15 = local_20;
                  }
                  iVar12 = *(int *)(piVar10[8] + uVar4 * 4);
                }
                else {
                  iVar12 = 0;
                }
                if (local_1c == iVar12) {
                  if (iVar12 != 0) {
                    iVar5 = iVar5 + 1;
                  }
                }
                else {
                  if (1 < iVar5) {
                    FUN_006b90d0((int)&local_38 + 4,&DAT_007273ac);
                    local_8._0_1_ = 0x10;
                    FUN_006b9290();
                    local_8._0_1_ = 0x11;
                    if ((local_38._4_4_ != (int *)0x0) &&
                       (*local_38._4_4_ = *local_38._4_4_ + -1, *local_38._4_4_ == 0)) {
                      FUN_006ba940();
                    }
                    local_8._0_1_ = 0xf;
                  }
                  if ((local_1c == 0) || (iVar12 == 0)) {
                    local_1c = iVar12;
                    if (iVar12 != 0) goto LAB_00523f88;
                  }
                  else {
                    iVar5 = local_18[2];
                    if (iVar5 == -1) {
                      piVar15 = local_18 + 3;
                      do {
                        iVar5 = *piVar15;
                        piVar15 = (int *)((int)piVar15 + 1);
                      } while ((char)iVar5 != '\0');
                      iVar5 = (int)piVar15 - ((int)local_18 + 0xd);
                      local_18[2] = iVar5;
                    }
                    local_18 = (int *)FUN_006b8df0(local_18,iVar5 + 3);
                    *(undefined2 *)(iVar5 + 0xc + (int)local_18) = 0x202c;
                    *(undefined1 *)(iVar5 + 0xe + (int)local_18) = 0;
                    local_18[2] = iVar5 + 2;
                    uVar4 = local_24;
LAB_00523f88:
                    local_1c = iVar12;
                    uVar8 = FUN_004435d0(&local_3c);
                    FUN_00443730(uVar8);
                    local_8._0_1_ = 0x12;
                    FUN_006b9290();
                    local_8._0_1_ = 0x13;
                    if ((local_3c != (int *)0x0) && (*local_3c = *local_3c + -1, *local_3c == 0)) {
                      FUN_006ba940();
                    }
                    local_8._0_1_ = 0xf;
                  }
                  iVar5 = 1;
                  piVar15 = local_20;
                }
                local_24 = uVar4 + 1;
                this = local_2c;
              } while ((int)local_24 < (int)piVar15);
            }
            iVar5 = FUN_006b8f20();
            if (0 < iVar5) {
              uVar8 = FUN_004435d0(&local_2c,"Material:");
              uVar8 = FUN_00443730(uVar8);
              local_8._0_1_ = 0x14;
              FUN_006b95d0(uVar8);
              local_8._0_1_ = 0x15;
              FUN_006b9500(&DAT_0072127c);
              local_8._0_1_ = 0x16;
              FUN_006b9410(&local_18);
              local_8._0_1_ = 0x17;
              FUN_006b9290();
              local_8._0_1_ = 0x18;
              if ((local_3c != (int *)0x0) && (*local_3c = *local_3c + -1, *local_3c == 0)) {
                FUN_006ba940();
              }
              local_8._0_1_ = 0x19;
              if ((local_38._4_4_ != (int *)0x0) &&
                 (*local_38._4_4_ = *local_38._4_4_ + -1, *local_38._4_4_ == 0)) {
                FUN_006ba940();
              }
              local_8._0_1_ = 0x1a;
              if ((local_30 != (int *)0x0) && (*local_30 = *local_30 + -1, *local_30 == 0)) {
                FUN_006ba940();
              }
              local_8._0_1_ = 0x1b;
              if ((local_2c != (ViWinProduction *)0x0) &&
                 (*(int *)local_2c = *(int *)local_2c + -1, *(int *)local_2c == 0)) {
                FUN_006ba940();
              }
            }
          }
          local_8._0_1_ = 0x1c;
          if ((local_18 != (int *)0x0) && (*local_18 = *local_18 + -1, *local_18 == 0)) {
            FUN_006ba940();
          }
          local_8._0_1_ = 4;
        }
      }
    }
    piVar10 = local_14;
    piVar15 = *(int **)&this->field_0x30;
    *(int **)&this->field_0x30 = local_14;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    if ((piVar15 != (int *)0x0) && (*piVar15 = *piVar15 + -1, *piVar15 == 0)) {
      FUN_006ba940();
    }
    *(int *)(*(int *)&this->field_0x30 + 8) = piVar10[2];
    local_8 = 0x1d;
    *piVar10 = *piVar10 + -1;
    if (*piVar10 == 0) {
      FUN_006ba940();
    }
    local_8 = 0xffffffff;
  }
  iVar5 = FUN_00501450();
  local_3c = (int *)((*(int *)(*(int *)(iVar5 + 0x8194) + 0x18) -
                     *(int *)(*(int *)(iVar5 + 0x8194) + 0x10)) + -0x46);
  FUN_00504a70();
  FUN_00501450();
  local_3c = (int *)0x46;
  FUN_00504ba0();
  ExceptionList = local_10;
  return;
}

