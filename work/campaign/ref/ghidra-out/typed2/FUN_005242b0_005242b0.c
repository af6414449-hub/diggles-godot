
undefined1 __thiscall FUN_005242b0(ViWinProduction *this)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 uVar4;
  int *piVar5;
  code *pcVar6;
  int iVar7;
  int *piVar8;
  ViWinProduction *pVVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  uint *puVar14;
  float in_XMM0_Da;
  undefined4 *in_stack_00000004;
  char *pcVar15;
  undefined4 uVar16;
  undefined **ppuVar17;
  undefined4 uVar18;
  uint *local_2c;
  int *local_28;
  int *local_24;
  int local_20;
  int local_1c;
  undefined1 *local_18;
  ViWinProduction *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  pcVar6 = RaiseException_exref;
  puStack_c = &LAB_007024a5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = this;
  if (in_stack_00000004[2] == DAT_007723b8) {
    if (in_stack_00000004[0x10] == 0) {
      uVar12 = *(uint *)(DAT_00772400 + 0xa0cc);
      if (uVar12 != 0xffffffff) {
        piVar13 = (int *)(DAT_0077244c + 0x488);
        if (uVar12 < 0x2000) {
          piVar13 = piVar13 + uVar12;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar1 = *piVar13;
        if ((iVar1 != 0) && (*(int *)(iVar1 + 0xe8) == 1)) {
          FUN_005dae40("atr_Hitpoints");
          local_2c = (uint *)(in_XMM0_Da * 15.0);
          DAT_00772dd8 = (int)ROUND((float)local_2c);
          FUN_005dc850(0,iVar1,0,DAT_00772dd8,0x41200000);
        }
      }
    }
    else {
      FUN_00523760(DAT_0076700c ^ (uint)&stack0xfffffffc);
    }
  }
  iVar1 = in_stack_00000004[2];
  if ((((iVar1 == DAT_007723c4) || (iVar1 == DAT_007723c8)) ||
      ((iVar1 == DAT_007723d4 && (iVar1 = FUN_00501450(), *(char *)(iVar1 + 0x10) != '\0')))) &&
     ((iVar1 = in_stack_00000004[9], 0x28 < (int)in_stack_00000004[10] && (this->i_2036c != 0)))) {
    if (iVar1 < 0x23) {
      if (in_stack_00000004[2] == DAT_007723c4) {
        this->i_20374 = this->i_20374 + -0x32;
        FUN_00524ca0();
        uVar4 = 1;
        goto LAB_00524c2f;
      }
    }
    else {
      if (iVar1 <= (this->i_14 - this->i_0c) + -0x1e) {
        this->i_20374 = (iVar1 - *(int *)this->i_2036c / 2) + -0x1e;
        FUN_00524ca0();
        uVar4 = 1;
        goto LAB_00524c2f;
      }
      if (in_stack_00000004[2] == DAT_007723c4) {
        this->i_20374 = this->i_20374 + 0x32;
        FUN_00524ca0();
        uVar4 = 1;
        goto LAB_00524c2f;
      }
    }
  }
  else {
    uVar12 = this->i_48;
    if (0 < (int)uVar12) {
      piVar13 = (int *)(DAT_0077244c + 0x488);
      if (uVar12 < 0x2000) {
        piVar13 = piVar13 + uVar12;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_1c = *piVar13;
      if (local_1c != 0) {
        piVar8 = *(int **)(local_1c + 0xd8);
        piVar13 = &this->i_2035c;
        piVar10 = (int *)*piVar13;
        *piVar13 = (int)piVar8;
        if (piVar8 != (int *)0x0) {
          *piVar8 = *piVar8 + 1;
        }
        if ((piVar10 != (int *)0x0) && (*piVar10 = *piVar10 + -1, *piVar10 == 0)) {
          FUN_006ba940();
        }
        *(undefined4 *)(*piVar13 + 8) = *(undefined4 *)(*(int *)(local_1c + 0xd8) + 8);
        iVar1 = FUN_006cfeb0(*piVar13 + 0xc,0x5f);
        if (iVar1 == 0) {
          iVar1 = -1;
        }
        else {
          iVar1 = (iVar1 - *piVar13) + -0xc;
        }
        FUN_006b9b20(&local_2c,0,iVar1);
        puVar14 = local_2c;
        local_8._0_1_ = 1;
        piVar8 = (int *)*piVar13;
        *piVar13 = (int)local_2c;
        if (local_2c != (uint *)0x0) {
          *local_2c = *local_2c + 1;
        }
        if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 == 0)) {
          FUN_006ba940();
        }
        *(uint *)(*piVar13 + 8) = puVar14[2];
        local_8._0_1_ = 2;
        *puVar14 = *puVar14 - 1;
        if (*puVar14 == 0) {
          FUN_006ba940();
        }
        local_8 = (uint)local_8._1_3_ << 8;
        puVar14 = *(uint **)(local_1c + 0x3e0);
        local_2c = puVar14;
        if (puVar14 != (uint *)0x0) {
          iVar1 = FUN_004ecd40();
          local_20 = 10;
          if (*(char *)(iVar1 + 0x123) == '\0') {
            local_20 = 1;
          }
          if (in_stack_00000004[2] == DAT_007723a0) {
            puVar3 = &local_14->field_0x54;
            local_18 = puVar3;
            do {
              pVVar9 = local_14;
              piVar13 = *(int **)&local_14->field_0x20354;
              piVar10 = (int *)0x0;
              local_24 = (int *)0x0;
              piVar8 = local_24;
              if (0 < (int)piVar13) {
                local_24 = (int *)0x0;
                do {
                  local_28 = piVar13;
                  if (piVar10 < (int *)0x20) {
                    piVar5 = (int *)(&pVVar9->field_0x54 + (int)local_24);
                  }
                  else {
                    (*pcVar6)(0xc000008c,1,0,0);
                    piVar13 = *(int **)&pVVar9->field_0x20354;
                    piVar5 = (int *)&pVVar9->field_0x54;
                  }
                  puVar3 = local_18;
                  pcVar6 = RaiseException_exref;
                  puVar14 = local_2c;
                  piVar8 = piVar10;
                  if (in_stack_00000004[6] == *piVar5) break;
                  piVar10 = (int *)((int)piVar10 + 1);
                  local_24 = (int *)((int)local_24 + 0x1018);
                  local_28 = piVar13;
                  piVar8 = piVar10;
                } while ((int)piVar10 < (int)piVar13);
              }
              local_24 = piVar8;
              piVar8 = local_24;
              if ((((int)local_24 < (int)piVar13 + -1) && (*(int *)(local_1c + 0xe8) != 6)) &&
                 (*(int *)(local_1c + 0xe8) != 10)) {
                if (local_24 < (int *)0x20) {
                  puVar3 = puVar3 + (int)local_24 * 0x1018;
                }
                else {
                  (*pcVar6)(0xc000008c,1,0,0);
                  puVar3 = local_18;
                }
                uVar12 = *(uint *)(puVar3 + 0x10);
                if (((char)puVar14[0x10] != '\0') &&
                   (uVar11 = 0, piVar8 = local_24, 0 < (int)puVar14[4])) {
                  do {
                    if (uVar11 != uVar12) {
                      FUN_005edc70(uVar11);
                    }
                    uVar11 = uVar11 + 1;
                    piVar8 = local_24;
                  } while ((int)uVar11 < (int)puVar14[4]);
                }
                if (piVar8 < (int *)0x20) {
                  puVar3 = local_18 + (int)piVar8 * 0x1018;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar3 = local_18;
                }
                if ((*(int *)(puVar3 + 0x1014) == 0) && (-1 < (int)uVar12)) {
                  if (*(char *)((int)puVar14 + 0x3f) == '\0') {
                    if ((int)uVar12 < (int)puVar14[4]) {
                      *puVar14 = uVar12;
                      if (puVar14[4] <= uVar12) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      iVar7 = *(int *)(puVar14[3] + 0x10 + uVar12 * 0x1c) + 1;
                      iVar1 = 0;
                      if (-1 < iVar7) {
                        iVar1 = iVar7;
                      }
                      if (10 < iVar1) {
                        iVar1 = 10;
                      }
                      *(int *)(puVar14[3] + 0x10 + uVar12 * 0x1c) = iVar1;
                      piVar8 = local_24;
                    }
                  }
                  else {
                    if ((int)uVar12 < (int)puVar14[4]) {
                      if (puVar14[4] <= uVar12) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      uVar11 = puVar14[3];
                      local_28 = (int *)(uVar12 * 0x1c);
                      if (*(int *)(uVar11 + 0x10 + (int)local_28) != 0) {
                        if ((int)uVar12 < (int)puVar14[4]) {
                          if (puVar14[4] <= uVar12) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            uVar11 = puVar14[3];
                          }
                          *(undefined4 *)(uVar11 + 0x10 + (int)local_28) = 0;
                        }
                        goto LAB_0052478a;
                      }
                    }
                    if ((int)uVar12 < (int)puVar14[4]) {
                      if (puVar14[4] <= uVar12) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      *(undefined4 *)(puVar14[3] + 0x10 + uVar12 * 0x1c) = 10;
                    }
                  }
                }
              }
LAB_0052478a:
              pcVar6 = RaiseException_exref;
              local_28 = (int *)((int)piVar8 * 0x1018);
              if (piVar8 < (int *)0x20) {
                puVar3 = (undefined1 *)((int)local_28 + (int)local_18);
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                puVar3 = local_18;
              }
              switch(*(undefined4 *)(puVar3 + 0x1014)) {
              case 0:
                if (piVar8 < (int *)0x20) {
                  puVar3 = local_18 + (int)local_28;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar3 = local_18;
                }
                uVar12 = *(uint *)(puVar3 + 0x10);
                if (((int)uVar12 < 0) || ((int)puVar14[4] <= (int)uVar12)) {
                  ppuVar17 = (undefined **)(iRam0000000c + 0xc);
                  pcVar15 = "prodincrement";
                }
                else {
                  if (puVar14[4] <= uVar12) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  ppuVar17 = (undefined **)
                             (*(int *)(*(int *)(puVar14[3] + 8 + uVar12 * 0x1c) + 0xc) + 0xc);
                  pcVar15 = "prodincrement";
                }
                goto LAB_0052494b;
              case 1:
                uVar18 = 0;
                uVar16 = 1;
                iVar1 = local_1c;
                FUN_00501450(local_1c,1,0);
                FUN_00530e80(iVar1,uVar16,uVar18);
                FUN_00523760();
                ppuVar17 = &PTR_0071ce50;
                *(undefined1 *)(puVar14 + 0x19) = 1;
                *(undefined1 *)((int)puVar14 + 0x43) = 1;
                pcVar15 = "unpack";
                goto LAB_0052494b;
              case 2:
                iVar1 = 0;
                if (0 < (int)puVar14[4]) {
                  do {
                    FUN_005edc70(iVar1);
                    iVar1 = iVar1 + 1;
                  } while (iVar1 < (int)puVar14[4]);
                }
                *(undefined1 *)(puVar14 + 0x19) = 1;
                *(undefined1 *)((int)puVar14 + 0x43) = 1;
                iVar1 = FUN_004ecd40();
                if (*(char *)(iVar1 + 0x11a) == '\0') {
                  *(undefined2 *)((int)puVar14 + 0x29) = 1;
                  *(undefined1 *)(puVar14 + 0xb) = 1;
                  *(undefined2 *)((int)puVar14 + 0x3d) = 0;
                  FUN_00523760();
                  ppuVar17 = &PTR_0071ce50;
                  pcVar15 = "pack";
                  goto LAB_0052494b;
                }
                uVar18 = 1;
                uVar16 = 1;
                iVar1 = local_1c;
                FUN_00501450(local_1c,1,1);
                FUN_00530e80(iVar1,uVar16,uVar18);
                *(undefined1 *)(puVar14 + 0xf) = 1;
                break;
              case 3:
                *(bool *)(*(int *)(local_1c + 0x3e0) + 100) =
                     *(char *)(*(int *)(local_1c + 0x3e0) + 100) == '\0';
                puVar3 = &DAT_007221b4;
                if (*(char *)(*(int *)(local_1c + 0x3e0) + 100) == '\0') {
                  puVar3 = &DAT_007273dc;
                }
                FUN_005235a0("switch",puVar3);
                FUN_00523760();
                break;
              case 4:
                *(undefined2 *)((int)puVar14 + 0x29) = 0x100;
                *(undefined1 *)(puVar14 + 0xb) = 0;
                *(undefined2 *)((int)puVar14 + 0x3d) = 0;
                FUN_00523760();
                ppuVar17 = &PTR_0071ce50;
                *(undefined1 *)(puVar14 + 0x19) = 1;
                *(undefined1 *)((int)puVar14 + 0x43) = 1;
                pcVar15 = "buildup";
LAB_0052494b:
                FUN_005235a0(pcVar15,ppuVar17);
              }
              local_20 = local_20 + -1;
              puVar3 = &local_14->field_0x54;
            } while (0 < local_20);
          }
          if ((in_stack_00000004[2] == DAT_00772398) && (pVVar9 = local_14, 0 < local_20)) {
            do {
              iVar1 = *(int *)&pVVar9->field_0x20354;
              uVar12 = 0;
              if (0 < iVar1) {
                local_24 = (int *)&pVVar9->field_0x54;
                iVar7 = 0;
                do {
                  if (uVar12 < 0x20) {
                    local_28 = (int *)((int)local_24 + iVar7);
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    local_28 = local_24;
                    iVar1 = *(int *)&local_14->field_0x20354;
                  }
                  pVVar9 = local_14;
                  puVar14 = local_2c;
                  if (in_stack_00000004[6] == *local_28) break;
                  uVar12 = uVar12 + 1;
                  iVar7 = iVar7 + 0x1018;
                } while ((int)uVar12 < iVar1);
              }
              if (uVar12 == iVar1 - 1U) {
                local_28 = (int *)&pVVar9->field_0x1068;
                if (uVar12 < 0x20) {
                  piVar13 = (int *)((int)local_28 + uVar12 * 0x1018);
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar13 = local_28;
                }
                if ((*piVar13 == 2) && (*(char *)((int)puVar14 + 0x3d) == '\0')) {
                  *(undefined1 *)(puVar14 + 0xb) = 0;
                  *(undefined1 *)((int)puVar14 + 0x29) = 0;
                  FUN_0046a960(*(undefined4 *)(local_1c + 0xdc));
                }
              }
              if ((int)uVar12 < *(int *)&pVVar9->field_0x20354 + -1) {
                puVar3 = &pVVar9->field_0x54;
                local_18 = puVar3;
                if (uVar12 < 0x20) {
                  puVar2 = puVar3 + uVar12 * 0x1018;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  puVar2 = puVar3;
                }
                piVar13 = *(int **)(puVar2 + 0x10);
                local_24 = piVar13;
                if (*(char *)((int)puVar14 + 0x3f) == '\0') {
                  FUN_005edc10(piVar13);
                }
                else {
                  uVar11 = puVar14[4];
                  piVar8 = (int *)0x0;
                  if (0 < (int)uVar11) {
                    do {
                      if (piVar8 != piVar13) {
                        FUN_005edc70(piVar8);
                        piVar13 = local_24;
                      }
                      uVar11 = puVar14[4];
                      piVar8 = (int *)((int)piVar8 + 1);
                    } while ((int)piVar8 < (int)uVar11);
                  }
                  puVar3 = local_18;
                  if (-1 < (int)piVar13) {
                    if ((int)piVar13 < (int)uVar11) {
                      if ((int *)puVar14[4] <= piVar13) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        piVar13 = local_24;
                      }
                      uVar11 = puVar14[3];
                      local_28 = (int *)((int)piVar13 * 0x1c);
                      if (*(int *)(uVar11 + 0x10 + (int)local_28) != 0) {
                        puVar3 = local_18;
                        if ((int)piVar13 < (int)puVar14[4]) {
                          if ((int *)puVar14[4] <= piVar13) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            uVar11 = puVar14[3];
                          }
                          *(undefined4 *)((int)local_28 + uVar11 + 0x10) = 0;
                          puVar3 = local_18;
                        }
                        goto LAB_00524b1b;
                      }
                    }
                    puVar3 = local_18;
                    if ((int)piVar13 < (int)puVar14[4]) {
                      if ((int *)puVar14[4] <= piVar13) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        piVar13 = local_24;
                      }
                      *(undefined4 *)(puVar14[3] + 0x10 + (int)piVar13 * 0x1c) = 10;
                      puVar3 = local_18;
                    }
                  }
                }
LAB_00524b1b:
                if (uVar12 < 0x20) {
                  local_18 = puVar3 + uVar12 * 0x1018;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                uVar12 = *(uint *)(local_18 + 0x10);
                pVVar9 = local_14;
                if ((-1 < (int)uVar12) && ((int)uVar12 < (int)puVar14[4])) {
                  if (puVar14[4] <= uVar12) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  pVVar9 = local_14;
                  iVar1 = *(int *)(puVar14[3] + 8 + uVar12 * 0x1c);
                  if (iVar1 != 0) {
                    FUN_005235a0("proddecrement",*(int *)(iVar1 + 0xc) + 0xc);
                  }
                }
              }
              local_20 = local_20 + -1;
            } while (0 < local_20);
            uVar4 = 1;
            goto LAB_00524c2f;
          }
          goto LAB_00524c0d;
        }
      }
    }
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      in_stack_00000004[1] = in_stack_00000004[1] + 1;
      UNLOCK();
    }
    if ((in_stack_00000004[2] != DAT_007723ec) && (in_stack_00000004[2] != DAT_007723e8)) {
      if (in_stack_00000004 != (undefined4 *)0x0) {
        LOCK();
        iVar1 = in_stack_00000004[1] + -1;
        in_stack_00000004[1] = iVar1;
        UNLOCK();
        if (iVar1 == 0) {
          (**(code **)*in_stack_00000004)(1);
        }
      }
      uVar4 = 0;
      goto LAB_00524c2f;
    }
    if (in_stack_00000004 != (undefined4 *)0x0) {
      LOCK();
      iVar1 = in_stack_00000004[1] + -1;
      in_stack_00000004[1] = iVar1;
      UNLOCK();
      if (iVar1 == 0) {
        (**(code **)*in_stack_00000004)(1);
      }
    }
  }
LAB_00524c0d:
  uVar4 = 1;
LAB_00524c2f:
  if (in_stack_00000004 != (undefined4 *)0x0) {
    LOCK();
    iVar1 = in_stack_00000004[1] + -1;
    in_stack_00000004[1] = iVar1;
    UNLOCK();
    if ((iVar1 == 0) && (in_stack_00000004 != (undefined4 *)0x0)) {
      (**(code **)*in_stack_00000004)(1);
    }
  }
  ExceptionList = local_10;
  return uVar4;
}

