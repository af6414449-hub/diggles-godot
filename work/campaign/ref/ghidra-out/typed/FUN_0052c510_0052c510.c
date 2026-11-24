
undefined1 __thiscall FUN_0052c510(ViWinRoot *this)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  uint uVar8;
  bool bVar9;
  float10 fVar10;
  double dVar11;
  float fVar12;
  float fVar13;
  undefined4 *in_stack_00000004;
  undefined8 local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00702ba5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (((*(char *)(DAT_00772400 + 0x8c) == '\0') &&
      (iVar3 = FUN_00501450(DAT_0076700c ^ (uint)&stack0xfffffffc), iVar5 = DAT_00772400,
      *(int *)(iVar3 + 0x101f8) != 1)) && (in_stack_00000004[2] == DAT_007723d8)) {
    if (in_stack_00000004[0x10] == 0x13) {
      bVar9 = *(char *)(DAT_00772400 + 0xa098) == '\0';
      if (bVar9) {
        *(undefined1 *)(DAT_00772400 + 0x8b) = 0;
        if (bVar9) {
          *(undefined1 *)(iVar5 + 0xa098) = 1;
        }
      }
      else {
        *(undefined1 *)(DAT_00772400 + 0x8b) = 1;
        if (*(char *)(iVar5 + 0xa098) != '\0') {
          *(undefined1 *)(iVar5 + 0xa098) = 0;
        }
      }
      FUN_00504ee0();
    }
    if (((in_stack_00000004[0x10] == 9) && (*(char *)(DAT_00772400 + 0x3d3) != '\0')) &&
       (cVar2 = FUN_00509540(), cVar2 == '\0')) {
      iVar5 = *(int *)(this->i_104 + 200);
      if (*(char *)(iVar5 + 0x1c) != '\x01') {
        *(undefined1 *)(iVar5 + 0x1c) = 1;
        FUN_00504ee0();
      }
      FUN_00504a00();
    }
    iVar5 = DAT_00772400;
    if (*(char *)(DAT_00772400 + 0x8b) == '\0') {
      if ((in_stack_00000004[0x10] == 0x6b) || (in_stack_00000004[0x10] == 0x9a)) {
        dVar11 = (double)DAT_007683b8;
        local_18 = *(double *)(DAT_00772400 + 0xa090) + 0.01;
        fVar10 = (float10)FUN_006f6da0(local_18);
        local_18 = (double)fVar10 * 2.001 + 0.01;
        fVar10 = (float10)FUN_006f6da0(local_18);
        local_18 = (double)fVar10;
        if (local_18 <= dVar11) {
          dVar11 = local_18;
        }
        if ((dVar11 != *(double *)(iVar5 + 0xa090)) &&
           (*(double *)(iVar5 + 0xa090) = dVar11, *(char *)(iVar5 + 0xa098) != '\0')) {
          *(undefined1 *)(iVar5 + 0xa098) = 1;
        }
        FUN_00504ee0();
      }
      iVar5 = DAT_00772400;
      if (in_stack_00000004[0x10] == 0x6d) {
        fVar10 = (float10)FUN_006f6da0(*(double *)(DAT_00772400 + 0xa090) + 0.01);
        fVar10 = (float10)FUN_006f6da0((double)fVar10 / 1.999 + 0.01);
        dVar11 = 1.0;
        if (1.0 <= (double)fVar10) {
          dVar11 = (double)fVar10;
        }
        if ((dVar11 != *(double *)(iVar5 + 0xa090)) &&
           (*(double *)(iVar5 + 0xa090) = dVar11, *(char *)(iVar5 + 0xa098) != '\0')) {
          *(undefined1 *)(iVar5 + 0xa098) = 1;
        }
        FUN_00504ee0();
      }
    }
  }
  if ((*(char *)(DAT_00772400 + 0x3c9) == '\0') && (this->i_e8 == 0)) {
    if ((in_stack_00000004[2] == DAT_00772388) && (in_stack_00000004[6] == this->i_f0)) {
      if (*(char *)(this->i_dc + 0x6c) == '\0') {
        FUN_00519790();
      }
      else {
        FUN_005197d0();
      }
      FUN_00507d40();
    }
    if ((in_stack_00000004[2] == DAT_00772388) && (in_stack_00000004[6] == this->i_f4)) {
      iVar5 = this->i_e4;
      if (*(char *)(iVar5 + 0x1c) == '\0') {
        *(undefined1 *)(iVar5 + 0x1c) = 1;
        FUN_00504ee0();
        FUN_00536190();
      }
      else {
        FUN_00504ee0();
        *(undefined1 *)(iVar5 + 0x1c) = 0;
      }
      FUN_00507d40();
    }
    if ((in_stack_00000004[2] == DAT_00772388) && (in_stack_00000004[6] == this->i_fc)) {
      iVar5 = this->i_100;
      if (*(char *)(iVar5 + 0x1c) == '\0') {
        *(undefined1 *)(iVar5 + 0x1c) = 1;
        FUN_00504ee0();
      }
      else {
        FUN_00504ee0();
        *(undefined1 *)(iVar5 + 0x1c) = 0;
      }
    }
    if ((in_stack_00000004[2] == DAT_00772388) && (in_stack_00000004[6] == this->i_f8)) {
      FUN_00534d60();
      FUN_00507d40();
    }
    if ((((in_stack_00000004[2] == DAT_007723cc) && (*(char *)(DAT_00772400 + 0x590) != '\0')) &&
        (1 < *(int *)(DAT_00772400 + 0xa0cc))) &&
       ((*(int *)(DAT_00772400 + 0xa0c8) == 0 && (*(int *)(DAT_00772374 + 0x1a8) == 0)))) {
      piVar4 = (int *)FUN_00407340();
      iVar3 = DAT_00772374;
      iVar5 = *piVar4;
      local_18 = (double)CONCAT44(iVar5,(undefined4)local_18);
      piVar4 = *(int **)(*(int *)(iVar5 + 0xd4) + 0xc);
      if (piVar4 != (int *)0x0) {
        *piVar4 = *piVar4 + 1;
      }
      FUN_004fa7e0();
      iVar1 = *(int *)(iVar3 + 0x1a8);
      if ((((*(float *)(iVar1 + 0xc) != *(float *)(iVar5 + 0xc)) ||
           (*(float *)(iVar1 + 0x10) != *(float *)(iVar5 + 0x10))) ||
          (*(float *)(iVar1 + 0x14) != *(float *)(iVar5 + 0x14))) &&
         (FUN_005cd8e0(), *(int *)(iVar1 + 0x238) == 0)) {
        FUN_005ebc90();
        FUN_005eb470();
      }
      iVar5 = (int)local_18._4_4_;
      FUN_005cd840();
      *(undefined4 *)(*(int *)(iVar3 + 0x1a8) + 0x3d0) = *(undefined4 *)(iVar5 + 0x3d0);
      *(undefined4 *)(*(int *)(iVar3 + 0x1b0) + 0xbc) = *(undefined4 *)(iVar5 + 0x14);
    }
    if (((in_stack_00000004[2] == DAT_00772384) && (*(char *)(DAT_00772400 + 0x590) == '\0')) &&
       (*(char *)(DAT_00772400 + 0x8c) == '\0')) {
      iVar5 = in_stack_00000004[0x10];
      fVar13 = 0.0;
      fVar12 = 0.0;
      if (((iVar5 == 0x67) || (iVar5 == 100)) || (iVar5 == 0x61)) {
        fVar13 = -1.0;
      }
      if (((iVar5 == 0x69) || (iVar5 == 0x66)) || (iVar5 == 99)) {
        fVar13 = 1.0;
      }
      if (((iVar5 == 0x67) || (iVar5 == 0x68)) || (iVar5 == 0x69)) {
        fVar12 = -1.0;
      }
      if (((iVar5 == 0x61) || (iVar5 == 0x62)) || (iVar5 == 99)) {
        fVar12 = 1.0;
      }
      if (fVar13 != 0.0) {
        iVar5 = *(int *)(DAT_00772400 + 0x5a4);
        *(float *)(iVar5 + 0x154) =
             *(float *)(iVar5 + 0x15c) * 4.0 * fVar13 + *(float *)(iVar5 + 0x154);
      }
      if (fVar12 != 0.0) {
        iVar5 = *(int *)(DAT_00772400 + 0x5a4);
        *(float *)(iVar5 + 0x158) =
             *(float *)(iVar5 + 0x15c) * 3.0 * fVar12 + *(float *)(iVar5 + 0x158);
      }
      if ((in_stack_00000004[0x10] == 0x65) || (in_stack_00000004[0x10] == 0x99)) {
        *(undefined4 *)(*(int *)(DAT_00772400 + 0x5a4) + 0x160) = 0xbe4ccccd;
        *(undefined4 *)(*(int *)(DAT_00772400 + 0x5a4) + 0x164) = 0;
        *(undefined4 *)(*(int *)(DAT_00772400 + 0x5a4) + 0x15c) = 0x3f99999a;
      }
      if ((in_stack_00000004[0x10] == 0x6a) || (in_stack_00000004[0x10] == 0x98)) {
        *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x15c) =
             *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x15c) - 0.5;
      }
      if ((in_stack_00000004[0x10] == 0x6f) || (in_stack_00000004[0x10] == 0x97)) {
        *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x15c) =
             *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x15c) + 0.5;
      }
    }
    if (in_stack_00000004[2] == DAT_007723d8) {
      if (*(char *)(DAT_00772400 + 0x8c) == '\0') {
        if (*(char *)(DAT_00772400 + 0x590) == '\0') {
          if (in_stack_00000004[0x10] == 0x70) {
            FUN_00531fb0();
          }
          iVar5 = in_stack_00000004[0x10];
          if ((0x30 < iVar5) && (iVar5 < 0x3a)) {
            iVar3 = FUN_004ecd40();
            if (*(char *)(iVar3 + 0x11b) == '\0') {
              iVar3 = FUN_005321b0();
              iVar5 = DAT_00772400;
              local_18 = (double)CONCAT44(iVar3,(undefined4)local_18);
              if (*(int *)(DAT_00772400 + 0xa0c8) == *(int *)(iVar3 + 4)) {
                if (*(int *)(DAT_00772400 + 0xa0c8) == 0) {
LAB_0052cd36:
                  iVar5 = FUN_005e3690();
                  if (iVar5 != 0) {
                    fVar13 = *(float *)(iVar5 + 0x10);
                    *(undefined4 *)(*(int *)(DAT_00772400 + 0x5a4) + 0x154) =
                         *(undefined4 *)(iVar5 + 0xc);
                    *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x158) =
                         fVar13 - *(float *)(*(int *)(DAT_00772400 + 0x5a4) + 0x15c) * 1.5;
                  }
                  goto LAB_0052ccc3;
                }
                uVar8 = 0;
                do {
                  if ((int)*(uint *)(iVar5 + 0xa0c8) <= (int)uVar8) goto LAB_0052cd36;
                  if (*(uint *)(iVar5 + 0xa0c8) <= uVar8) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  uVar8 = uVar8 + 1;
                  cVar2 = FUN_005e35a0();
                } while (cVar2 != '\0');
              }
              FUN_00531280();
              FUN_005321b0();
            }
            else {
              FUN_005321b0(iVar5 + -0x31);
            }
            FUN_005e3760();
          }
LAB_0052ccc3:
          if (in_stack_00000004[0x10] == 0x78) {
            iVar5 = *(int *)(DAT_00772400 + 0xa0c8);
            FUN_006b8f50();
            uVar8 = 0;
            local_8._0_1_ = 1;
            if (iVar5 < 1) {
              piVar4 = local_18._4_4_;
            }
            else {
              do {
                iVar3 = DAT_00772400;
                if ((int)uVar8 < (int)*(uint *)(DAT_00772400 + 0xa0c8)) {
                  if (*(uint *)(DAT_00772400 + 0xa0c8) <= uVar8) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  uVar6 = *(undefined4 *)(*(int *)(iVar3 + 0xa0c4) + uVar8 * 4);
                }
                else {
                  uVar6 = 0xffffffff;
                }
                FUN_006b9040((int)&local_18 + 4,"set_event %d evt_task_dropall -target %d",uVar6);
                piVar4 = local_18._4_4_;
                if (local_18._4_4_ != (int *)0x0) {
                  *local_18._4_4_ = *local_18._4_4_ + 1;
                }
                FUN_0054ea20();
                uVar8 = uVar8 + 1;
              } while ((int)uVar8 < iVar5);
            }
            local_8._0_1_ = 2;
            if ((piVar4 != (int *)0x0) && (*piVar4 = *piVar4 + -1, *piVar4 == 0)) {
              FUN_006ba940();
            }
            local_8 = (uint)local_8._1_3_ << 8;
          }
          if (in_stack_00000004[0x10] == 0x77) {
            if (*(int *)(DAT_00772400 + 0xa0d4) == -1) {
              if (0 < *(int *)(DAT_00772400 + 0xa0c8)) {
                if (*(int *)(DAT_00772400 + 0xa0c8) < 1) {
                  uVar6 = 0xffffffff;
                }
                else {
                  uVar6 = **(undefined4 **)(DAT_00772400 + 0xa0c4);
                }
                *(undefined4 *)(DAT_00772400 + 0xa0d4) = uVar6;
              }
            }
            else {
              *(undefined4 *)(DAT_00772400 + 0xa0d4) = 0xffffffff;
            }
          }
          if (in_stack_00000004[0x10] == 0x79) {
            FUN_0050db10();
          }
          if (in_stack_00000004[0x10] == 0x7a) {
            FUN_0050db10();
          }
          iVar5 = in_stack_00000004[0x10];
          if (iVar5 == 0x71) {
            FUN_00556280();
            uVar7 = 1;
            goto LAB_0052d13a;
          }
          if (iVar5 == 0x72) {
            FUN_00531fb0();
            uVar7 = 1;
            goto LAB_0052d13a;
          }
          if (iVar5 == 0x73) {
            FUN_00531fb0();
            uVar7 = 1;
            goto LAB_0052d13a;
          }
          if (iVar5 == 0x74) {
            FUN_00531fb0();
            uVar7 = 1;
            goto LAB_0052d13a;
          }
          if (iVar5 == 0x75) {
            FUN_00531fb0();
            uVar7 = 1;
            goto LAB_0052d13a;
          }
          if (iVar5 == 0x76) {
            FUN_00531fb0();
            uVar7 = 1;
            goto LAB_0052d13a;
          }
          if ((iVar5 == 0x1b) && (*(char *)(DAT_00772400 + 0x8c) == '\0')) {
            iVar5 = FUN_00501450();
            *(undefined4 *)(iVar5 + 0x81a0) = 0;
            if ((*(char *)(this->i_118 + 0x1c) == '\0') && (this->i_11c == 0)) {
              iVar5 = FUN_00501450();
              if (*(int *)(iVar5 + 0x10210) < 1) {
                if (*(char *)(DAT_00772400 + 0x8f) != '\0') {
                  FUN_00501450();
                  FUN_00504260();
                }
              }
              else {
                FUN_00501450();
                FUN_005018b0();
              }
            }
            else {
              FUN_00531f40();
            }
          }
        }
      }
      else if ((in_stack_00000004[0x10] == 0x1b) && (*(char *)(DAT_00772400 + 0x90) == '\0')) {
        *(undefined1 *)(DAT_00772400 + 0x8d) = 1;
      }
    }
    if (((in_stack_00000004[2] == DAT_007723e8) && ((ViWinRoot *)in_stack_00000004[6] == this)) &&
       (*(char *)(DAT_00772400 + 0x590) == '\0')) {
      FUN_00527f40(in_stack_00000004[9],in_stack_00000004[10]);
    }
    if ((this->c_8d != '\0') && (in_stack_00000004 != (undefined4 *)0x0)) {
      LOCK();
      in_stack_00000004[1] = in_stack_00000004[1] + 1;
      UNLOCK();
      FUN_0052f620();
    }
    if ((*(char *)(DAT_00772400 + 0x591) != '\0') &&
       (iVar5 = FUN_00501450(), *(char *)(iVar5 + 0x14) == '\0')) {
      iVar5 = FUN_004ecd40();
      if (*(char *)(iVar5 + 0x118) != '\0') {
        FUN_00532a70(*(undefined4 *)(*(int *)(DAT_00772374 + 0x1ac) + 0x48),
                     *(undefined4 *)(*(int *)(DAT_00772374 + 0x1ac) + 0x74));
      }
      iVar5 = FUN_004ecd40();
      if (*(char *)(iVar5 + 0x119) != '\0') {
        FUN_00532a70(0,*(undefined4 *)(*(int *)(DAT_00772374 + 0x1ac) + 0x74));
      }
    }
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      in_stack_00000004[1] = in_stack_00000004[1] + 1;
      UNLOCK();
    }
    piVar4 = in_stack_00000004 + 1;
    if (in_stack_00000004[2] != DAT_007723ec) {
      if (in_stack_00000004[2] == DAT_007723e8) {
        LOCK();
        iVar5 = *piVar4;
        *piVar4 = iVar5 + -1;
        UNLOCK();
        if (iVar5 + -1 == 0) {
          (**(code **)*in_stack_00000004)();
        }
        uVar7 = 1;
      }
      else {
        LOCK();
        iVar5 = *piVar4;
        *piVar4 = iVar5 + -1;
        UNLOCK();
        if (iVar5 + -1 == 0) {
          (**(code **)*in_stack_00000004)();
        }
        uVar7 = 0;
      }
      goto LAB_0052d13a;
    }
    LOCK();
    iVar5 = *piVar4;
    *piVar4 = iVar5 + -1;
    UNLOCK();
    if (iVar5 + -1 == 0) {
      (**(code **)*in_stack_00000004)();
      uVar7 = 1;
      goto LAB_0052d13a;
    }
  }
  else {
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      in_stack_00000004[1] = in_stack_00000004[1] + 1;
      UNLOCK();
    }
    piVar4 = in_stack_00000004 + 1;
    if (in_stack_00000004[2] == DAT_007723ec) {
      LOCK();
      iVar5 = *piVar4;
      *piVar4 = iVar5 + -1;
      UNLOCK();
      if (iVar5 + -1 == 0) {
        (**(code **)*in_stack_00000004)();
      }
    }
    else {
      if (in_stack_00000004[2] != DAT_007723e8) {
        LOCK();
        iVar5 = *piVar4;
        *piVar4 = iVar5 + -1;
        UNLOCK();
        if (iVar5 + -1 == 0) {
          (**(code **)*in_stack_00000004)();
        }
        uVar7 = 0;
        goto LAB_0052d13a;
      }
      LOCK();
      iVar5 = *piVar4;
      *piVar4 = iVar5 + -1;
      UNLOCK();
      if (iVar5 + -1 == 0) {
        (**(code **)*in_stack_00000004)();
        uVar7 = 1;
        goto LAB_0052d13a;
      }
    }
  }
  uVar7 = 1;
LAB_0052d13a:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    piVar4 = in_stack_00000004 + 1;
    iVar5 = *piVar4;
    *piVar4 = *piVar4 + -1;
    UNLOCK();
    if ((iVar5 == 1) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)();
    }
  }
  ExceptionList = local_10;
  return uVar7;
}

