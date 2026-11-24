
void FUN_005237b0(void)

{
  uint uVar1;
  undefined1 uVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int *this;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  undefined4 *puVar15;
  float10 fVar16;
  int *local_3c;
  undefined8 local_38;
  int *local_30;
  int *local_2c;
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
  if ((char)this[7] == '\0') {
    return;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(DAT_00772400 + 0xa0d0) = 0xffffffff;
  local_2c = this;
  iVar5 = FUN_00501450(uVar4);
  if (*(int *)(*(int *)(iVar5 + 0x8194) + 0xe8) == 0) {
    FUN_00505ed0();
  }
  iVar5 = this[0x80d5];
  if (0 < iVar5) {
    piVar13 = this + 0x15;
    if (iVar5 - 1U < 0x20) {
      piVar6 = piVar13 + iVar5 * 0x406 + -0x406;
    }
    else {
      RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      piVar6 = piVar13;
    }
    if (piVar6[0x405] == 2) {
      if (this[0x80d5] - 1U < 0x20) {
        piVar13 = this + (this[0x80d5] - 1U) * 0x406 + 0x15;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*piVar13 != 0) {
        iVar5 = FUN_004ecd40();
        if (*(char *)(iVar5 + 0x11a) == '\0') {
          cVar3 = FUN_006b9930();
          if (cVar3 != '\0') {
            FUN_00507d40();
            uVar7 = FUN_004435d0(&local_28);
            FUN_00443730(uVar7);
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
            uVar7 = FUN_004435d0(&local_28);
            FUN_00443730(uVar7);
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
    uVar8 = **(uint **)(DAT_00772400 + 0xa0c4);
  }
  else {
    uVar8 = 0xffffffff;
  }
  uVar1 = this[0x12];
  if (uVar1 == uVar8) {
    if (0 < (int)uVar1) {
      piVar13 = (int *)(DAT_0077244c + 0x488);
      if (uVar1 < 0x2000) {
        piVar13 = piVar13 + uVar1;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      if (*piVar13 != 0) {
        if (*(int *)(*piVar13 + 0x3e0) != 0) {
          if ((*(char *)((int)this + 0x45) != '\0') && ((char)this[0x11] == '\0')) {
            this->s_11 = 1;
            FUN_00524c80();
          }
          iVar5 = FUN_005eda80();
          if (this[0x14] != iVar5) {
            this[0x14] = iVar5;
            FUN_00523760();
          }
        }
        iVar5 = FUN_005cf210();
        if (this[0x13] != iVar5) {
          iVar5 = FUN_005cf210();
          this[0x13] = iVar5;
          goto LAB_005239fc;
        }
      }
    }
  }
  else {
    this[0x12] = uVar8;
LAB_005239fc:
    FUN_00523760();
  }
  iVar9 = FUN_00501450(uVar4);
  iVar5 = this[4];
  local_1c = this[3];
  local_28 = *(int **)(iVar9 + 0x101d8);
  for (iVar12 = this[0xd]; iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x34)) {
    local_1c = local_1c + *(int *)(iVar12 + 0xc);
    iVar5 = iVar5 + *(int *)(iVar12 + 0x10);
  }
  local_1c = *(int *)(iVar9 + 0x101d4) - local_1c;
  local_18 = (int *)0xffffffff;
  if (((((uint)((int)local_28 - iVar5) < 0x28) && (local_1c < this[5] - this[3])) &&
      (0 < local_1c)) && (piVar13 = (int *)0x0, 0 < this[0x80d5])) {
    piVar6 = this + 0x15;
    do {
      local_28 = (int *)((int)piVar13 * 0x1018);
      if (piVar13 < (int *)0x20) {
        piVar10 = (int *)((int)local_28 + (int)piVar6);
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        piVar10 = piVar6;
      }
      piVar14 = piVar13;
      if (*piVar10 != 0) {
        if (piVar13 < (int *)0x20) {
          piVar10 = *(int **)(*(int *)((int)local_28 + (int)piVar6) + 0xc);
          piVar11 = (int *)((int)local_28 + (int)piVar6);
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          local_28 = *(int **)(*piVar6 + 0xc);
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
          piVar10 = local_28;
          piVar11 = piVar6;
        }
        if (((int)piVar10 < local_1c) &&
           (local_1c < (int)piVar10 + (*(int *)(*piVar11 + 0x14) - *(int *)(*piVar11 + 0xc)))) {
          piVar14 = (int *)this[0x80d5];
          local_18 = piVar13;
        }
      }
      piVar13 = (int *)((int)piVar14 + 1);
    } while ((int)piVar13 < this[0x80d5]);
    if (local_18 != (int *)0xffffffff) {
      *(int *)(DAT_00772400 + 0xa0d0) = this[0x12];
      piVar13 = local_18;
      goto LAB_00523b2e;
    }
  }
  piVar13 = local_18;
  FUN_006b9200();
LAB_00523b2e:
  if (DAT_007687b4 != piVar13) {
    DAT_007687b4 = piVar13;
    FUN_006b8f50();
    local_8._0_1_ = 4;
    local_8._1_3_ = 0;
    if (piVar13 != (int *)0xffffffff) {
      local_30 = this + 0x15;
      iVar5 = FUN_00524da0();
      if (*(int *)(iVar5 + 0x1014) == 0) {
        iVar5 = FUN_00524da0();
        if (*(int *)(iVar5 + 4) == 0) {
          FUN_00524da0();
          uVar7 = FUN_004435d0(&local_28);
          FUN_00443730(uVar7);
          local_8._0_1_ = 7;
          FUN_006b91c0();
          local_8._0_1_ = 8;
          if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
            FUN_006ba940();
          }
          local_8._0_1_ = 4;
          iVar5 = FUN_00524da0();
          if ((*(int *)(iVar5 + 0x10) != -1) && ((int)piVar13 < this[0x80d5] + -1)) {
            FUN_0043d690();
            FUN_006b9390();
            uVar7 = FUN_004435d0(&local_28);
            FUN_00443730(uVar7);
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
                  piVar13 = local_14 + 3;
                  do {
                    iVar5 = *piVar13;
                    piVar13 = (int *)((int)piVar13 + 1);
                  } while ((char)iVar5 != '\0');
                  iVar5 = (int)piVar13 - ((int)local_14 + 0xd);
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
                puVar15 = (undefined4 *)(iVar5 + 0x2004);
                if (local_28 < (int *)0x200) {
                  puVar15 = puVar15 + (int)local_28;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                piVar13 = (int *)*puVar15;
                if (piVar13 != (int *)0x0) {
                  *piVar13 = *piVar13 + 1;
                }
                local_8 = CONCAT31(local_8._1_3_,0xb);
                uVar8 = *(uint *)(local_1c + 0x44);
                local_3c = piVar13;
                if (uVar8 <= uVar4) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  uVar8 = *(uint *)(local_1c + 0x44);
                }
                local_28 = (int *)(*(float *)(*(int *)(local_1c + 0x40) + 4 + uVar4 * 8) * 100.0);
                if (uVar8 <= uVar4) {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                local_38 = (double)(float)local_28;
                fVar16 = (float10)FUN_006f26b0(local_38);
                local_38 = (double)fVar16;
                FUN_006b90d0(&local_20,"%s:%3.0f",piVar13 + 3,local_38);
                local_8._0_1_ = 0xc;
                FUN_006b9290();
                local_8._0_1_ = 0xd;
                if ((local_20 != (int *)0x0) && (*local_20 = *local_20 + -1, *local_20 == 0)) {
                  FUN_006ba940();
                }
                local_8._0_1_ = 0xe;
                if ((piVar13 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 == 0)) {
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
          uVar7 = FUN_004435d0(&local_28);
          FUN_00443730(uVar7);
          local_8._0_1_ = 5;
          FUN_006b91c0();
          local_8._0_1_ = 6;
          if ((local_28 != (int *)0x0) && (*local_28 = *local_28 + -1, *local_28 == 0)) {
            FUN_006ba940();
          }
          local_8._0_1_ = 4;
        }
        iVar5 = FUN_00524da0();
        piVar13 = *(int **)(iVar5 + 8);
        local_30 = piVar13;
        if (((piVar13 != (int *)0x0) && (iVar5 = FUN_00524da0(), *(int *)(iVar5 + 4) != 0)) &&
           (iVar5 = FUN_00524da0(), *(char *)(*(int *)(*(int *)(iVar5 + 4) + 0xc) + 0xc) != '_')) {
          local_1c = 0;
          FUN_006b8f50();
          local_8._0_1_ = 0xf;
          local_28 = (int *)piVar13[9];
          if (0 < (int)local_28) {
            FUN_006b9200();
            iVar5 = 0;
            local_24 = 0;
            piVar13 = (int *)((int)local_28 + 1);
            local_20 = piVar13;
            if (0 < (int)piVar13) {
              do {
                uVar4 = local_24;
                piVar6 = local_30;
                if ((int)local_24 < (int)local_28) {
                  if ((uint)local_30[9] <= local_24) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    piVar13 = local_20;
                  }
                  iVar12 = *(int *)(piVar6[8] + uVar4 * 4);
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
                      piVar13 = local_18 + 3;
                      do {
                        iVar5 = *piVar13;
                        piVar13 = (int *)((int)piVar13 + 1);
                      } while ((char)iVar5 != '\0');
                      iVar5 = (int)piVar13 - ((int)local_18 + 0xd);
                      local_18[2] = iVar5;
                    }
                    local_18 = (int *)FUN_006b8df0(local_18,iVar5 + 3);
                    *(undefined2 *)(iVar5 + 0xc + (int)local_18) = 0x202c;
                    *(undefined1 *)(iVar5 + 0xe + (int)local_18) = 0;
                    local_18[2] = iVar5 + 2;
                    uVar4 = local_24;
LAB_00523f88:
                    local_1c = iVar12;
                    uVar7 = FUN_004435d0(&local_3c);
                    FUN_00443730(uVar7);
                    local_8._0_1_ = 0x12;
                    FUN_006b9290();
                    local_8._0_1_ = 0x13;
                    if ((local_3c != (int *)0x0) && (*local_3c = *local_3c + -1, *local_3c == 0)) {
                      FUN_006ba940();
                    }
                    local_8._0_1_ = 0xf;
                  }
                  iVar5 = 1;
                  piVar13 = local_20;
                }
                local_24 = uVar4 + 1;
                this = local_2c;
              } while ((int)local_24 < (int)piVar13);
            }
            iVar5 = FUN_006b8f20();
            if (0 < iVar5) {
              uVar7 = FUN_004435d0(&local_2c,"Material:");
              uVar7 = FUN_00443730(uVar7);
              local_8._0_1_ = 0x14;
              FUN_006b95d0(uVar7);
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
              if ((local_2c != (int *)0x0) && (*local_2c = *local_2c + -1, *local_2c == 0)) {
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
    piVar6 = local_14;
    piVar13 = (int *)this[0xc];
    this[0xc] = (int)local_14;
    if (local_14 != (int *)0x0) {
      *local_14 = *local_14 + 1;
    }
    if ((piVar13 != (int *)0x0) && (*piVar13 = *piVar13 + -1, *piVar13 == 0)) {
      FUN_006ba940();
    }
    *(int *)(this[0xc] + 8) = piVar6[2];
    local_8 = 0x1d;
    *piVar6 = *piVar6 + -1;
    if (*piVar6 == 0) {
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

