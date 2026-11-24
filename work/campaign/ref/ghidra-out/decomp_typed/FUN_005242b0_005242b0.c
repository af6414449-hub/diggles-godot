
undefined1 FUN_005242b0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int this;
  undefined1 *puVar3;
  undefined1 uVar4;
  int *piVar5;
  code *pcVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  uint *puVar13;
  float in_XMM0_Da;
  char *pcVar14;
  undefined4 uVar15;
  undefined **ppuVar16;
  undefined4 uVar17;
  uint *local_2c;
  int *local_28;
  int *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  pcVar6 = RaiseException_exref;
  puStack_c = &LAB_007024a5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = this;
  if (param_1[2] == DAT_007723b8) {
    if (param_1[0x10] == 0) {
      uVar11 = *(uint *)(DAT_00772400 + 0xa0cc);
      if (uVar11 != 0xffffffff) {
        piVar12 = (int *)(DAT_0077244c + 0x488);
        if (uVar11 < 0x2000) {
          piVar12 = piVar12 + uVar11;
        }
        else {
          RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
        }
        iVar1 = *piVar12;
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
  iVar1 = param_1[2];
  if ((((iVar1 == DAT_007723c4) || (iVar1 == DAT_007723c8)) ||
      ((iVar1 == DAT_007723d4 && (iVar1 = FUN_00501450(), *(char *)(iVar1 + 0x10) != '\0')))) &&
     ((iVar1 = param_1[9], 0x28 < (int)param_1[10] && (this->i_2036c != 0)))) {
    if (iVar1 < 0x23) {
      if (param_1[2] == DAT_007723c4) {
        this->i_20374 = this->i_20374 + -0x32;
        FUN_00524ca0();
        uVar4 = 1;
        goto LAB_00524c2f;
      }
    }
    else {
      if (iVar1 <= (this->i_14 - this->i_0c) + -0x1e) {
        this->i_20374 = (iVar1 - **(int **)(this + 0x2036c) / 2) + -0x1e;
        FUN_00524ca0();
        uVar4 = 1;
        goto LAB_00524c2f;
      }
      if (param_1[2] == DAT_007723c4) {
        this->i_20374 = this->i_20374 + 0x32;
        FUN_00524ca0();
        uVar4 = 1;
        goto LAB_00524c2f;
      }
    }
  }
  else {
    uVar11 = this->i_48;
    if (0 < (int)uVar11) {
      piVar12 = (int *)(DAT_0077244c + 0x488);
      if (uVar11 < 0x2000) {
        piVar12 = piVar12 + uVar11;
      }
      else {
        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
      }
      local_1c = *piVar12;
      if (local_1c != 0) {
        piVar8 = *(int **)(local_1c + 0xd8);
        piVar12 = (int *)(this + 0x2035c);
        piVar9 = (int *)*piVar12;
        *piVar12 = (int)piVar8;
        if (piVar8 != (int *)0x0) {
          *piVar8 = *piVar8 + 1;
        }
        if ((piVar9 != (int *)0x0) && (*piVar9 = *piVar9 + -1, *piVar9 == 0)) {
          FUN_006ba940();
        }
        *(undefined4 *)(*piVar12 + 8) = *(undefined4 *)(*(int *)(local_1c + 0xd8) + 8);
        iVar1 = FUN_006cfeb0(*piVar12 + 0xc,0x5f);
        if (iVar1 == 0) {
          iVar1 = -1;
        }
        else {
          iVar1 = (iVar1 - *piVar12) + -0xc;
        }
        FUN_006b9b20(&local_2c,0,iVar1);
        puVar13 = local_2c;
        local_8._0_1_ = 1;
        piVar8 = (int *)*piVar12;
        *piVar12 = (int)local_2c;
        if (local_2c != (uint *)0x0) {
          *local_2c = *local_2c + 1;
        }
        if ((piVar8 != (int *)0x0) && (*piVar8 = *piVar8 + -1, *piVar8 == 0)) {
          FUN_006ba940();
        }
        *(uint *)(*piVar12 + 8) = puVar13[2];
        local_8._0_1_ = 2;
        *puVar13 = *puVar13 - 1;
        if (*puVar13 == 0) {
          FUN_006ba940();
        }
        local_8 = (uint)local_8._1_3_ << 8;
        puVar13 = *(uint **)(local_1c + 0x3e0);
        local_2c = puVar13;
        if (puVar13 != (uint *)0x0) {
          iVar1 = FUN_004ecd40();
          local_20 = 10;
          if (*(char *)(iVar1 + 0x123) == '\0') {
            local_20 = 1;
          }
          if (param_1[2] == DAT_007723a0) {
            iVar1 = local_14 + 0x54;
            local_18 = iVar1;
            do {
              iVar2 = local_14;
              piVar12 = *(int **)(local_14 + 0x20354);
              piVar9 = (int *)0x0;
              local_24 = (int *)0x0;
              piVar8 = local_24;
              if (0 < (int)piVar12) {
                local_24 = (int *)0x0;
                do {
                  local_28 = piVar12;
                  if (piVar9 < (int *)0x20) {
                    piVar5 = (int *)(iVar2 + 0x54 + (int)local_24);
                  }
                  else {
                    (*pcVar6)(0xc000008c,1,0,0);
                    piVar12 = *(int **)(iVar2 + 0x20354);
                    piVar5 = (int *)(iVar2 + 0x54);
                  }
                  iVar1 = local_18;
                  pcVar6 = RaiseException_exref;
                  puVar13 = local_2c;
                  piVar8 = piVar9;
                  if (param_1[6] == *piVar5) break;
                  piVar9 = (int *)((int)piVar9 + 1);
                  local_24 = (int *)((int)local_24 + 0x1018);
                  local_28 = piVar12;
                  piVar8 = piVar9;
                } while ((int)piVar9 < (int)piVar12);
              }
              local_24 = piVar8;
              piVar8 = local_24;
              if ((((int)local_24 < (int)piVar12 + -1) && (*(int *)(local_1c + 0xe8) != 6)) &&
                 (*(int *)(local_1c + 0xe8) != 10)) {
                if (local_24 < (int *)0x20) {
                  iVar1 = (int)local_24 * 0x1018 + iVar1;
                }
                else {
                  (*pcVar6)(0xc000008c,1,0,0);
                  iVar1 = local_18;
                }
                uVar11 = *(uint *)(iVar1 + 0x10);
                if (((char)puVar13[0x10] != '\0') &&
                   (uVar10 = 0, piVar8 = local_24, 0 < (int)puVar13[4])) {
                  do {
                    if (uVar10 != uVar11) {
                      FUN_005edc70(uVar10);
                    }
                    uVar10 = uVar10 + 1;
                    piVar8 = local_24;
                  } while ((int)uVar10 < (int)puVar13[4]);
                }
                if (piVar8 < (int *)0x20) {
                  iVar1 = (int)piVar8 * 0x1018 + local_18;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar1 = local_18;
                }
                if ((*(int *)(iVar1 + 0x1014) == 0) && (-1 < (int)uVar11)) {
                  if (*(char *)((int)puVar13 + 0x3f) == '\0') {
                    if ((int)uVar11 < (int)puVar13[4]) {
                      *puVar13 = uVar11;
                      if (puVar13[4] <= uVar11) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      iVar2 = *(int *)(puVar13[3] + 0x10 + uVar11 * 0x1c) + 1;
                      iVar1 = 0;
                      if (-1 < iVar2) {
                        iVar1 = iVar2;
                      }
                      if (10 < iVar1) {
                        iVar1 = 10;
                      }
                      *(int *)(puVar13[3] + 0x10 + uVar11 * 0x1c) = iVar1;
                      piVar8 = local_24;
                    }
                  }
                  else {
                    if ((int)uVar11 < (int)puVar13[4]) {
                      if (puVar13[4] <= uVar11) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      uVar10 = puVar13[3];
                      local_28 = (int *)(uVar11 * 0x1c);
                      if (*(int *)(uVar10 + 0x10 + (int)local_28) != 0) {
                        if ((int)uVar11 < (int)puVar13[4]) {
                          if (puVar13[4] <= uVar11) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            uVar10 = puVar13[3];
                          }
                          *(undefined4 *)(uVar10 + 0x10 + (int)local_28) = 0;
                        }
                        goto LAB_0052478a;
                      }
                    }
                    if ((int)uVar11 < (int)puVar13[4]) {
                      if (puVar13[4] <= uVar11) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                      }
                      *(undefined4 *)(puVar13[3] + 0x10 + uVar11 * 0x1c) = 10;
                    }
                  }
                }
              }
LAB_0052478a:
              pcVar6 = RaiseException_exref;
              local_28 = (int *)((int)piVar8 * 0x1018);
              if (piVar8 < (int *)0x20) {
                iVar1 = (int)local_28 + local_18;
              }
              else {
                RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                iVar1 = local_18;
              }
              switch(*(undefined4 *)(iVar1 + 0x1014)) {
              case 0:
                if (piVar8 < (int *)0x20) {
                  iVar1 = local_18 + (int)local_28;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar1 = local_18;
                }
                uVar11 = *(uint *)(iVar1 + 0x10);
                if (((int)uVar11 < 0) || ((int)puVar13[4] <= (int)uVar11)) {
                  ppuVar16 = (undefined **)(iRam0000000c + 0xc);
                  pcVar14 = "prodincrement";
                }
                else {
                  if (puVar13[4] <= uVar11) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  ppuVar16 = (undefined **)
                             (*(int *)(*(int *)(puVar13[3] + 8 + uVar11 * 0x1c) + 0xc) + 0xc);
                  pcVar14 = "prodincrement";
                }
                goto LAB_0052494b;
              case 1:
                uVar17 = 0;
                uVar15 = 1;
                iVar1 = local_1c;
                FUN_00501450(local_1c,1,0);
                FUN_00530e80(iVar1,uVar15,uVar17);
                FUN_00523760();
                ppuVar16 = &PTR_0071ce50;
                *(undefined1 *)(puVar13 + 0x19) = 1;
                *(undefined1 *)((int)puVar13 + 0x43) = 1;
                pcVar14 = "unpack";
                goto LAB_0052494b;
              case 2:
                iVar1 = 0;
                if (0 < (int)puVar13[4]) {
                  do {
                    FUN_005edc70(iVar1);
                    iVar1 = iVar1 + 1;
                  } while (iVar1 < (int)puVar13[4]);
                }
                *(undefined1 *)(puVar13 + 0x19) = 1;
                *(undefined1 *)((int)puVar13 + 0x43) = 1;
                iVar1 = FUN_004ecd40();
                if (*(char *)(iVar1 + 0x11a) == '\0') {
                  *(undefined2 *)((int)puVar13 + 0x29) = 1;
                  *(undefined1 *)(puVar13 + 0xb) = 1;
                  *(undefined2 *)((int)puVar13 + 0x3d) = 0;
                  FUN_00523760();
                  ppuVar16 = &PTR_0071ce50;
                  pcVar14 = "pack";
                  goto LAB_0052494b;
                }
                uVar17 = 1;
                uVar15 = 1;
                iVar1 = local_1c;
                FUN_00501450(local_1c,1,1);
                FUN_00530e80(iVar1,uVar15,uVar17);
                *(undefined1 *)(puVar13 + 0xf) = 1;
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
                *(undefined2 *)((int)puVar13 + 0x29) = 0x100;
                *(undefined1 *)(puVar13 + 0xb) = 0;
                *(undefined2 *)((int)puVar13 + 0x3d) = 0;
                FUN_00523760();
                ppuVar16 = &PTR_0071ce50;
                *(undefined1 *)(puVar13 + 0x19) = 1;
                *(undefined1 *)((int)puVar13 + 0x43) = 1;
                pcVar14 = "buildup";
LAB_0052494b:
                FUN_005235a0(pcVar14,ppuVar16);
              }
              local_20 = local_20 + -1;
              iVar1 = local_14 + 0x54;
            } while (0 < local_20);
          }
          if ((param_1[2] == DAT_00772398) && (iVar1 = local_14, 0 < local_20)) {
            do {
              iVar2 = *(int *)(iVar1 + 0x20354);
              uVar11 = 0;
              if (0 < iVar2) {
                local_24 = (int *)(iVar1 + 0x54);
                iVar7 = 0;
                do {
                  if (uVar11 < 0x20) {
                    local_28 = (int *)((int)local_24 + iVar7);
                  }
                  else {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                    local_28 = local_24;
                    iVar2 = *(int *)(local_14 + 0x20354);
                  }
                  iVar1 = local_14;
                  puVar13 = local_2c;
                  if (param_1[6] == *local_28) break;
                  uVar11 = uVar11 + 1;
                  iVar7 = iVar7 + 0x1018;
                } while ((int)uVar11 < iVar2);
              }
              if (uVar11 == iVar2 - 1U) {
                local_28 = (int *)(iVar1 + 0x1068);
                if (uVar11 < 0x20) {
                  piVar12 = local_28 + uVar11 * 0x406;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  piVar12 = local_28;
                }
                if ((*piVar12 == 2) && (*(char *)((int)puVar13 + 0x3d) == '\0')) {
                  *(undefined1 *)(puVar13 + 0xb) = 0;
                  *(undefined1 *)((int)puVar13 + 0x29) = 0;
                  FUN_0046a960(*(undefined4 *)(local_1c + 0xdc));
                }
              }
              if ((int)uVar11 < *(int *)(iVar1 + 0x20354) + -1) {
                iVar1 = iVar1 + 0x54;
                local_18 = iVar1;
                if (uVar11 < 0x20) {
                  iVar2 = uVar11 * 0x1018 + iVar1;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  iVar2 = iVar1;
                }
                piVar12 = *(int **)(iVar2 + 0x10);
                local_24 = piVar12;
                if (*(char *)((int)puVar13 + 0x3f) == '\0') {
                  FUN_005edc10(piVar12);
                }
                else {
                  uVar10 = puVar13[4];
                  piVar8 = (int *)0x0;
                  if (0 < (int)uVar10) {
                    do {
                      if (piVar8 != piVar12) {
                        FUN_005edc70(piVar8);
                        piVar12 = local_24;
                      }
                      uVar10 = puVar13[4];
                      piVar8 = (int *)((int)piVar8 + 1);
                    } while ((int)piVar8 < (int)uVar10);
                  }
                  iVar1 = local_18;
                  if (-1 < (int)piVar12) {
                    if ((int)piVar12 < (int)uVar10) {
                      if ((int *)puVar13[4] <= piVar12) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        piVar12 = local_24;
                      }
                      uVar10 = puVar13[3];
                      local_28 = (int *)((int)piVar12 * 0x1c);
                      if (*(int *)(uVar10 + 0x10 + (int)local_28) != 0) {
                        iVar1 = local_18;
                        if ((int)piVar12 < (int)puVar13[4]) {
                          if ((int *)puVar13[4] <= piVar12) {
                            RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                            uVar10 = puVar13[3];
                          }
                          *(undefined4 *)((int)local_28 + uVar10 + 0x10) = 0;
                          iVar1 = local_18;
                        }
                        goto LAB_00524b1b;
                      }
                    }
                    iVar1 = local_18;
                    if ((int)piVar12 < (int)puVar13[4]) {
                      if ((int *)puVar13[4] <= piVar12) {
                        RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                        piVar12 = local_24;
                      }
                      *(undefined4 *)(puVar13[3] + 0x10 + (int)piVar12 * 0x1c) = 10;
                      iVar1 = local_18;
                    }
                  }
                }
LAB_00524b1b:
                if (uVar11 < 0x20) {
                  local_18 = iVar1 + uVar11 * 0x1018;
                }
                else {
                  RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                }
                uVar11 = *(uint *)(local_18 + 0x10);
                iVar1 = local_14;
                if ((-1 < (int)uVar11) && ((int)uVar11 < (int)puVar13[4])) {
                  if (puVar13[4] <= uVar11) {
                    RaiseException(0xc000008c,1,0,(ULONG_PTR *)0x0);
                  }
                  iVar1 = local_14;
                  iVar2 = *(int *)(puVar13[3] + 8 + uVar11 * 0x1c);
                  if (iVar2 != 0) {
                    FUN_005235a0("proddecrement",*(int *)(iVar2 + 0xc) + 0xc);
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
    if (param_1 != (undefined4 *)0x0) {
      LOCK();
      param_1[1] = param_1[1] + 1;
      UNLOCK();
    }
    if ((param_1[2] != DAT_007723ec) && (param_1[2] != DAT_007723e8)) {
      if (param_1 != (undefined4 *)0x0) {
        LOCK();
        iVar1 = param_1[1] + -1;
        param_1[1] = iVar1;
        UNLOCK();
        if (iVar1 == 0) {
          (**(code **)*param_1)(1);
        }
      }
      uVar4 = 0;
      goto LAB_00524c2f;
    }
    if (param_1 != (undefined4 *)0x0) {
      LOCK();
      iVar1 = param_1[1] + -1;
      param_1[1] = iVar1;
      UNLOCK();
      if (iVar1 == 0) {
        (**(code **)*param_1)(1);
      }
    }
  }
LAB_00524c0d:
  uVar4 = 1;
LAB_00524c2f:
  if (param_1 != (undefined4 *)0x0) {
    LOCK();
    iVar1 = param_1[1] + -1;
    param_1[1] = iVar1;
    UNLOCK();
    if ((iVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
      (**(code **)*param_1)(1);
    }
  }
  ExceptionList = local_10;
  return uVar4;
}

