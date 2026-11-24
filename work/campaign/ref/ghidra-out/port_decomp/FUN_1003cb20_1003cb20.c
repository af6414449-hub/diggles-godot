
void FUN_1003cb20(void)

{
  char cVar1;
  undefined1 uVar2;
  code cVar3;
  code cVar4;
  byte bVar5;
  ushort uVar6;
  short sVar7;
  undefined2 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  void *pvVar13;
  size_t sVar14;
  code *pcVar15;
  undefined4 *puVar16;
  uint uVar17;
  int *in_ECX;
  uint uVar18;
  int iVar19;
  code *pcVar20;
  short *psVar21;
  int *piVar22;
  code *pcVar23;
  double dVar24;
  undefined1 auStack_4a8 [2];
  undefined1 local_4a6;
  undefined1 local_4a5;
  code *local_4a4;
  code *local_4a0;
  code *local_49c;
  code *local_498;
  code *local_494;
  code *local_490;
  void *local_48c;
  code *local_488;
  code *local_484;
  double local_480;
  code *local_474;
  code *local_470;
  int *local_46c;
  uint local_468;
  int local_464;
  undefined8 local_460;
  byte abStack_448 [64];
  short sStack_408;
  undefined1 auStack_406 [2];
  short asStack_404 [500];
  char local_1c [8];
  uint local_14;
  
  local_14 = DAT_1005000c ^ (uint)auStack_4a8;
  local_46c = in_ECX;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  local_468 = 0;
  local_464 = 0;
  *(undefined1 *)((int)in_ECX + 0x56d) = 1;
  cVar1 = FUN_10038a40();
  if ((((cVar1 == 'O') && (cVar1 = FUN_10038a40(), cVar1 == 'g')) &&
      (cVar1 = FUN_10038a40(), cVar1 == 'g')) && (cVar1 = FUN_10038a40(), cVar1 == 'S')) {
    iVar9 = FUN_10038c50();
    if (iVar9 != 0) {
      bVar5 = *(byte *)((int)in_ECX + 0x56b);
      if ((((bVar5 & 2) != 0) && ((bVar5 & 4) == 0)) && (((bVar5 & 1) == 0 && (in_ECX[0x11a] == 1)))
         ) {
        if ((char)in_ECX[0x11b] == '\x1e') {
          cVar1 = FUN_10038a40();
          if (cVar1 == '\x01') {
            iVar9 = FUN_10038b20(6);
            if (iVar9 == 0) {
              in_ECX[0x1c] = 10;
              __security_check_cookie(local_14 ^ (uint)auStack_4a8);
              return;
            }
            iVar9 = FUN_100385a0();
            if ((iVar9 != 0) && (iVar9 = FUN_10038ad0(), iVar9 == 0)) {
              uVar10 = FUN_10038a40();
              uVar10 = uVar10 & 0xff;
              in_ECX[1] = uVar10;
              if (uVar10 != 0) {
                if (0x10 < uVar10) {
                  in_ECX[0x1c] = 5;
                  __security_check_cookie(local_14 ^ (uint)auStack_4a8);
                  return;
                }
                iVar9 = FUN_10038ad0();
                *in_ECX = iVar9;
                if (iVar9 != 0) {
                  FUN_10038ad0();
                  FUN_10038ad0();
                  FUN_10038ad0();
                  uVar10 = FUN_10038a40();
                  uVar18 = (uVar10 & 0xff) >> 4;
                  uVar10 = uVar10 & 0xf;
                  in_ECX[0x1f] = 1 << (sbyte)uVar10;
                  in_ECX[0x20] = 1 << (sbyte)uVar18;
                  if ((((uVar10 < 6) || (0xd < uVar10)) || (7 < uVar18 - 6)) || (uVar18 < uVar10))
                  goto LAB_1003cfde;
                  uVar10 = FUN_10038a40();
                  if ((uVar10 & 1) != 0) {
                    iVar9 = FUN_10038e70();
                    if (((iVar9 == 0) || (iVar9 = FUN_10038ec0(), iVar9 == 0)) ||
                       (iVar9 = FUN_10039100(), iVar9 == 0)) goto LAB_1003ee81;
                    iVar9 = FUN_100391b0();
                    if (iVar9 == 3) {
                      iVar9 = 0;
                      do {
                        cVar1 = FUN_100391b0();
                        local_1c[iVar9] = cVar1;
                        iVar9 = iVar9 + 1;
                      } while (iVar9 < 6);
                      iVar9 = FUN_100385a0();
                      if (iVar9 != 0) {
                        local_490 = (code *)FUN_10039210();
                        iVar9 = FUN_10037f70();
                        iVar19 = 0;
                        in_ECX[5] = iVar9;
                        if (0 < (int)local_490) {
                          do {
                            uVar2 = FUN_100391b0();
                            *(undefined1 *)(iVar19 + in_ECX[5]) = uVar2;
                            iVar19 = iVar19 + 1;
                          } while (iVar19 < (int)local_490);
                        }
                        local_490[in_ECX[5]] = (code)0x0;
                        iVar9 = FUN_10039210();
                        in_ECX[6] = iVar9;
                        iVar9 = FUN_10037f70();
                        in_ECX[7] = iVar9;
                        local_498 = (code *)0x0;
                        local_474 = malloc_exref;
                        if (0 < in_ECX[6]) {
                          do {
                            iVar9 = FUN_100391b0();
                            iVar19 = FUN_100391b0();
                            iVar11 = FUN_100391b0();
                            iVar12 = FUN_100391b0();
                            local_490 = (code *)(iVar12 * 0x1000000 +
                                                iVar9 + iVar19 * 0x100 + iVar11 * 0x10000);
                            uVar10 = (uint)(local_490 + 8) & 0xfffffff8;
                            in_ECX[2] = in_ECX[2] + uVar10;
                            if (in_ECX[0x17] == 0) {
                              if (uVar10 == 0) goto LAB_1003cef7;
                              iVar9 = (*local_474)(uVar10);
                            }
                            else {
                              iVar9 = in_ECX[0x19];
                              iVar19 = uVar10 + iVar9;
                              if (in_ECX[0x1a] < iVar19) {
LAB_1003cef7:
                                iVar9 = 0;
                              }
                              else {
                                in_ECX[0x19] = iVar19;
                                iVar9 = iVar9 + in_ECX[0x17];
                              }
                            }
                            iVar19 = 0;
                            *(int *)(in_ECX[7] + (int)local_498 * 4) = iVar9;
                            if (0 < (int)local_490) {
                              do {
                                uVar2 = FUN_100391b0();
                                *(undefined1 *)(iVar19 + *(int *)(in_ECX[7] + (int)local_498 * 4)) =
                                     uVar2;
                                iVar19 = iVar19 + 1;
                              } while (iVar19 < (int)local_490);
                            }
                            iVar9 = (int)local_498 * 4;
                            local_498 = local_498 + 1;
                            local_490[*(int *)(in_ECX[7] + iVar9)] = (code)0x0;
                          } while ((int)local_498 < in_ECX[6]);
                        }
                        uVar10 = FUN_100391b0();
                        if ((uVar10 & 1) != 0) {
                          FUN_10038b80();
                          *(undefined1 *)(in_ECX + 0x15b) = 0;
                          do {
                            iVar9 = FUN_10039100();
                            if (in_ECX[0xb] == 0) {
                              iVar19 = (**(code **)(*(int *)in_ECX[8] + 0x14))();
                              (**(code **)(*(int *)in_ECX[8] + 0x10))(iVar19 + iVar9);
                            }
                            else {
                              uVar10 = in_ECX[0xb] + iVar9;
                              in_ECX[0xb] = uVar10;
                              if ((uint)in_ECX[0xd] <= uVar10) {
                                in_ECX[0x1b] = 1;
                              }
                            }
                            *(undefined1 *)(in_ECX + 0x15b) = 0;
                          } while (iVar9 != 0);
                          iVar9 = FUN_10038ec0();
                          if (iVar9 == 0) goto LAB_1003ee81;
                          if (((char)in_ECX[0xf] == '\0') || (iVar9 = FUN_1003c9e0(), iVar9 != 0)) {
                            in_ECX = local_46c;
                            iVar9 = 0;
                            do {
                              uVar10 = (-(uint)((uint)(iVar9 << 0x18) < 0x80000000) & 0xfb3ee249) +
                                       0x4c11db7 ^ iVar9 << 0x19;
                              uVar10 = (-(uint)(uVar10 < 0x80000000) & 0xfb3ee249) + 0x4c11db7 ^
                                       uVar10 * 2;
                              uVar10 = (-(uint)(uVar10 < 0x80000000) & 0xfb3ee249) + 0x4c11db7 ^
                                       uVar10 * 2;
                              uVar10 = (-(uint)(uVar10 < 0x80000000) & 0xfb3ee249) + 0x4c11db7 ^
                                       uVar10 * 2;
                              uVar10 = (-(uint)(uVar10 < 0x80000000) & 0xfb3ee249) + 0x4c11db7 ^
                                       uVar10 * 2;
                              uVar10 = (-(uint)(uVar10 < 0x80000000) & 0xfb3ee249) + 0x4c11db7 ^
                                       uVar10 * 2;
                              uVar10 = (-(uint)(uVar10 < 0x80000000) & 0xfb3ee249) + 0x4c11db7 ^
                                       uVar10 * 2;
                              (&DAT_1416ded0)[iVar9] =
                                   (-(uint)(uVar10 < 0x80000000) & 0xfb3ee249) + 0x4c11db7 ^
                                   uVar10 * 2;
                              iVar9 = iVar9 + 1;
                            } while (iVar9 < 0x100);
                            iVar9 = FUN_100391b0();
                            if (iVar9 == 5) {
                              iVar9 = 0;
                              do {
                                if ((char)in_ECX[0x15b] == '\0') {
                                  if (in_ECX[0x15d] == 0) {
                                    iVar19 = FUN_10039100();
                                    if (iVar19 != 0) goto LAB_1003d11a;
                                    cVar1 = -1;
                                  }
                                  else {
                                    cVar1 = -1;
                                  }
                                }
                                else {
LAB_1003d11a:
                                  *(char *)(in_ECX + 0x15b) = (char)in_ECX[0x15b] + -1;
                                  in_ECX[0x161] = in_ECX[0x161] + 1;
                                  cVar1 = FUN_10038a40();
                                }
                                local_1c[iVar9] = cVar1;
                                iVar9 = iVar9 + 1;
                                in_ECX[0x160] = 0;
                              } while (iVar9 < 6);
                              iVar9 = FUN_100385a0();
                              if (iVar9 != 0) {
                                iVar9 = FUN_100392f0();
                                in_ECX[0x21] = iVar9 + 1;
                                pvVar13 = (void *)FUN_10037f70();
                                in_ECX[0x22] = (int)pvVar13;
                                if (pvVar13 != (void *)0x0) {
                                  memset(pvVar13,0,in_ECX[0x21] * 0x830);
                                  local_49c = (code *)0x0;
                                  if (0 < in_ECX[0x21]) {
                                    local_460 = 0x8000000000000000;
                                    local_490 = free_exref;
                                    do {
                                      local_488 = (code *)0x0;
                                      pcVar20 = (code *)((int)local_49c * 0x830 + in_ECX[0x22]);
                                      local_484 = pcVar20;
                                      cVar1 = FUN_100392f0();
                                      if (((cVar1 != 'B') || (cVar1 = FUN_100392f0(), cVar1 != 'C'))
                                         || (cVar1 = FUN_100392f0(), cVar1 != 'V'))
                                      goto LAB_1003cfde;
                                      local_4a5 = (code)FUN_100392f0();
                                      iVar9 = FUN_100392f0();
                                      *(uint *)pcVar20 = iVar9 * 0x100 + (uint)(byte)local_4a5;
                                      local_4a6 = (code)FUN_100392f0();
                                      local_4a5 = (code)FUN_100392f0();
                                      iVar9 = FUN_100392f0();
                                      *(uint *)(pcVar20 + 4) =
                                           (iVar9 * 0x100 + (uint)(byte)local_4a5) * 0x100 +
                                           (uint)(byte)local_4a6;
                                      iVar9 = FUN_100392f0();
                                      local_480 = (double)CONCAT44(local_480._4_4_,iVar9);
                                      if (iVar9 == 0) {
                                        cVar3 = (code)FUN_100392f0();
                                      }
                                      else {
                                        cVar3 = (code)0x0;
                                      }
                                      pcVar20[0x17] = cVar3;
                                      if ((*(int *)pcVar20 == 0) && (*(int *)(pcVar20 + 4) != 0))
                                      goto LAB_1003cfde;
                                      iVar9 = in_ECX[0x17];
                                      uVar10 = *(int *)(pcVar20 + 4) + 7U & 0xfffffff8;
                                      if (cVar3 == (code)0x0) {
                                        in_ECX[2] = in_ECX[2] + uVar10;
                                        if (iVar9 == 0) {
                                          if (uVar10 == 0) goto LAB_1003d330;
                                          local_48c = (void *)(*local_474)(uVar10);
                                        }
                                        else {
                                          iVar19 = in_ECX[0x19];
                                          iVar11 = uVar10 + iVar19;
                                          if (in_ECX[0x1a] < iVar11) {
LAB_1003d330:
                                            local_48c = (void *)0x0;
                                          }
                                          else {
                                            in_ECX[0x19] = iVar11;
                                            local_48c = (void *)(iVar9 + iVar19);
                                          }
                                        }
                                        *(void **)(pcVar20 + 8) = local_48c;
                                      }
                                      else if (iVar9 == 0) {
                                        local_48c = (void *)(*local_474)(uVar10);
                                      }
                                      else {
                                        iVar19 = in_ECX[0x1a] - uVar10;
                                        if (iVar19 < in_ECX[0x19]) goto LAB_1003df02;
                                        local_48c = (void *)(iVar9 + iVar19);
                                        in_ECX[0x1a] = iVar19;
                                      }
                                      if (local_48c == (void *)0x0) goto LAB_1003df02;
                                      if (local_480._0_4_ == (code *)0x0) {
                                        local_494 = *(code **)(pcVar20 + 4);
                                        local_498 = (code *)0x0;
                                        if (0 < (int)local_494) {
                                          do {
                                            if ((pcVar20[0x17] == (code)0x0) ||
                                               (iVar9 = FUN_100392f0(), iVar9 != 0)) {
                                              cVar1 = FUN_100392f0();
                                              local_488 = local_488 + 1;
                                              *(byte *)((int)local_48c + (int)local_498) =
                                                   cVar1 + 1U;
                                              if ((code)(cVar1 + 1U) == (code)0x20)
                                              goto LAB_1003cfde;
                                            }
                                            else {
                                              *(code *)((int)local_48c + (int)local_498) =
                                                   (code)0xff;
                                            }
                                            local_494 = *(code **)(pcVar20 + 4);
                                            local_498 = local_498 + 1;
                                          } while ((int)local_498 < (int)local_494);
                                        }
                                      }
                                      else {
                                        local_498 = (code *)0x0;
                                        iVar9 = FUN_100392f0();
                                        local_494 = *(code **)(pcVar20 + 4);
                                        local_4a0 = (code *)(iVar9 + 1);
                                        if (0 < (int)local_494) {
                                          do {
                                            FUN_10038070();
                                            sVar14 = FUN_100392f0();
                                            local_480 = (double)CONCAT44(local_480._4_4_,sVar14);
                                            if ((0x1f < (int)local_4a0) ||
                                               (local_470 = local_498 + sVar14,
                                               *(int *)(pcVar20 + 4) < (int)local_470))
                                            goto LAB_1003cfde;
                                            memset((code *)((int)local_48c + (int)local_498),
                                                   (int)local_4a0,sVar14);
                                            local_498 = local_470;
                                            local_494 = *(code **)(pcVar20 + 4);
                                            local_4a0 = local_4a0 + 1;
                                          } while ((int)local_470 < (int)local_494);
                                        }
                                      }
                                      if (pcVar20[0x17] == (code)0x0) {
LAB_1003d4f1:
                                        pcVar15 = (code *)0x0;
                                        iVar9 = 0;
                                        local_488 = (code *)0x0;
                                        if ((int)local_494 < 1) {
                                          cVar3 = (code)0x0;
                                        }
                                        else {
                                          do {
                                            local_4a6 = *(code *)((int)local_48c + iVar9);
                                            if ((10 < (byte)local_4a6) && (local_4a6 != (code)0xff))
                                            {
                                              local_488 = local_488 + 1;
                                            }
                                            iVar9 = iVar9 + 1;
                                          } while (iVar9 < (int)local_494);
                                          cVar3 = pcVar20[0x17];
                                          pcVar15 = local_488;
                                        }
                                        *(code **)(pcVar20 + 0x82c) = pcVar15;
                                        local_488 = (code *)0x0;
                                        if (cVar3 != (code)0x0) goto LAB_1003d538;
                                        uVar10 = *(int *)(pcVar20 + 4) * 4 + 7U & 0xfffffff8;
                                        in_ECX[2] = in_ECX[2] + uVar10;
                                        if (in_ECX[0x17] != 0) {
                                          iVar9 = in_ECX[0x19];
                                          iVar19 = uVar10 + iVar9;
                                          if (iVar19 <= in_ECX[0x1a]) {
                                            in_ECX[0x19] = iVar19;
                                            iVar9 = iVar9 + in_ECX[0x17];
                                            goto LAB_1003d5bf;
                                          }
LAB_1003df1f:
                                          *(undefined4 *)(pcVar20 + 0x20) = 0;
                                          goto LAB_1003df02;
                                        }
                                        if (uVar10 == 0) goto LAB_1003df1f;
                                        iVar9 = (*local_474)(uVar10);
LAB_1003d5bf:
                                        *(int *)(pcVar20 + 0x20) = iVar9;
                                        if (iVar9 == 0) goto LAB_1003df02;
                                      }
                                      else {
                                        if ((int)local_494 >> 2 <= (int)local_488) {
                                          pcVar15 = local_494;
                                          if (in_ECX[4] < (int)local_494) {
                                            in_ECX[4] = (int)local_494;
                                            pcVar15 = *(code **)(pcVar20 + 4);
                                          }
                                          uVar10 = (uint)(pcVar15 + 7) & 0xfffffff8;
                                          in_ECX[2] = in_ECX[2] + uVar10;
                                          if (in_ECX[0x17] == 0) {
                                            if (uVar10 == 0) goto LAB_1003defb;
                                            pvVar13 = (void *)(*local_474)(uVar10);
                                          }
                                          else {
                                            iVar9 = in_ECX[0x19];
                                            iVar19 = uVar10 + iVar9;
                                            if (in_ECX[0x1a] < iVar19) {
LAB_1003defb:
                                              *(undefined4 *)(pcVar20 + 8) = 0;
                                              goto LAB_1003df02;
                                            }
                                            in_ECX[0x19] = iVar19;
                                            pvVar13 = (void *)(iVar9 + in_ECX[0x17]);
                                          }
                                          *(void **)(pcVar20 + 8) = pvVar13;
                                          if (pvVar13 != (void *)0x0) {
                                            memcpy(pvVar13,local_48c,*(size_t *)(pcVar20 + 4));
                                            if (in_ECX[0x17] == 0) {
                                              (*local_490)(local_48c);
                                            }
                                            else {
                                              in_ECX[0x1a] = in_ECX[0x1a] +
                                                             (*(int *)(pcVar20 + 4) + 3U &
                                                             0xfffffffc);
                                            }
                                            local_48c = *(void **)(pcVar20 + 8);
                                            local_494 = *(code **)(pcVar20 + 4);
                                            pcVar20[0x17] = (code)0x0;
                                            goto LAB_1003d4f1;
                                          }
                                          goto LAB_1003df02;
                                        }
                                        if (pcVar20[0x17] == (code)0x0) goto LAB_1003d4f1;
                                        *(code **)(pcVar20 + 0x82c) = local_488;
                                        pcVar15 = local_488;
LAB_1003d538:
                                        local_488 = (code *)0x0;
                                        if (pcVar15 != (code *)0x0) {
                                          uVar10 = (uint)(pcVar15 + 7) & 0xfffffff8;
                                          in_ECX[2] = in_ECX[2] + uVar10;
                                          if (in_ECX[0x17] == 0) {
                                            if (uVar10 == 0) goto LAB_1003df28;
                                            iVar9 = (*local_474)(uVar10);
                                          }
                                          else {
                                            iVar9 = in_ECX[0x19];
                                            iVar19 = uVar10 + iVar9;
                                            if (in_ECX[0x1a] < iVar19) {
LAB_1003df28:
                                              *(undefined4 *)(pcVar20 + 8) = 0;
                                              in_ECX[0x1c] = 3;
                                              __security_check_cookie(local_14 ^ (uint)auStack_4a8);
                                              return;
                                            }
                                            in_ECX[0x19] = iVar19;
                                            iVar9 = iVar9 + in_ECX[0x17];
                                          }
                                          *(int *)(pcVar20 + 8) = iVar9;
                                          if (iVar9 == 0) goto LAB_1003df56;
                                          uVar10 = *(int *)(pcVar20 + 0x82c) * 4 + 7U & 0xfffffff8;
                                          if (in_ECX[0x17] == 0) {
                                            iVar9 = (*local_474)(uVar10);
                                          }
                                          else {
                                            iVar9 = in_ECX[0x1a] - uVar10;
                                            if (iVar9 < in_ECX[0x19]) goto LAB_1003df1f;
                                            in_ECX[0x1a] = iVar9;
                                            iVar9 = iVar9 + in_ECX[0x17];
                                          }
                                          *(int *)(pcVar20 + 0x20) = iVar9;
                                          if (iVar9 == 0) goto LAB_1003df02;
                                          uVar10 = *(int *)(pcVar20 + 0x82c) * 4 + 7U & 0xfffffff8;
                                          if (in_ECX[0x17] == 0) {
                                            local_488 = (code *)(*local_474)(uVar10);
                                          }
                                          else {
                                            iVar9 = in_ECX[0x1a] - uVar10;
                                            if (iVar9 < in_ECX[0x19]) goto LAB_1003df02;
                                            in_ECX[0x1a] = iVar9;
                                            local_488 = (code *)(iVar9 + in_ECX[0x17]);
                                          }
                                          if (local_488 == (code *)0x0) goto LAB_1003df02;
                                        }
                                        uVar10 = *(int *)(pcVar20 + 4) +
                                                 *(int *)(pcVar20 + 0x82c) * 8;
                                        if ((uint)in_ECX[4] < uVar10) {
                                          in_ECX[4] = uVar10;
                                        }
                                      }
                                      iVar9 = FUN_10038120(*(undefined4 *)(pcVar20 + 4),local_488);
                                      if (iVar9 == 0) {
                                        if (pcVar20[0x17] != (code)0x0) {
                                          iVar9 = 0;
LAB_1003e019:
                                          FUN_10037fc0(iVar9);
                                        }
                                        in_ECX[0x1c] = 0x14;
                                        __security_check_cookie(local_14 ^ (uint)auStack_4a8);
                                        return;
                                      }
                                      if (*(int *)(pcVar20 + 0x82c) != 0) {
                                        uVar10 = *(int *)(pcVar20 + 0x82c) * 4 + 0xbU & 0xfffffff8;
                                        in_ECX[2] = in_ECX[2] + uVar10;
                                        if (in_ECX[0x17] == 0) {
                                          if (uVar10 == 0) goto LAB_1003df73;
                                          iVar9 = (*local_474)(uVar10);
                                        }
                                        else {
                                          iVar9 = in_ECX[0x19];
                                          iVar19 = uVar10 + iVar9;
                                          if (in_ECX[0x1a] < iVar19) {
LAB_1003df73:
                                            *(undefined4 *)(pcVar20 + 0x824) = 0;
                                            goto LAB_1003df7d;
                                          }
                                          in_ECX[0x19] = iVar19;
                                          iVar9 = iVar9 + in_ECX[0x17];
                                        }
                                        *(int *)(pcVar20 + 0x824) = iVar9;
                                        if (iVar9 == 0) {
LAB_1003df7d:
                                          in_ECX[0x1c] = 3;
                                          __security_check_cookie(local_14 ^ (uint)auStack_4a8);
                                          return;
                                        }
                                        uVar10 = *(int *)(pcVar20 + 0x82c) * 4 + 0xbU & 0xfffffff8;
                                        in_ECX[2] = in_ECX[2] + uVar10;
                                        if (in_ECX[0x17] == 0) {
                                          if (uVar10 == 0) goto LAB_1003df4c;
                                          puVar16 = (undefined4 *)(*local_474)(uVar10);
                                        }
                                        else {
                                          iVar9 = in_ECX[0x19];
                                          iVar19 = uVar10 + iVar9;
                                          if (in_ECX[0x1a] < iVar19) {
LAB_1003df4c:
                                            *(undefined4 *)(pcVar20 + 0x828) = 0;
                                            goto LAB_1003df56;
                                          }
                                          in_ECX[0x19] = iVar19;
                                          puVar16 = (undefined4 *)(iVar9 + in_ECX[0x17]);
                                        }
                                        *(undefined4 **)(pcVar20 + 0x828) = puVar16;
                                        if (puVar16 == (undefined4 *)0x0) {
LAB_1003df56:
                                          in_ECX[0x1c] = 3;
                                          __security_check_cookie(local_14 ^ (uint)auStack_4a8);
                                          return;
                                        }
                                        *(undefined4 **)(pcVar20 + 0x828) = puVar16 + 1;
                                        *puVar16 = 0xffffffff;
                                        FUN_10038390(local_488);
                                      }
                                      if (pcVar20[0x17] != (code)0x0) {
                                        if (in_ECX[0x17] == 0) {
                                          (*local_490)(local_488);
                                          if (in_ECX[0x17] == 0) {
                                            (*local_490)(*(undefined4 *)(pcVar20 + 0x20));
                                            if (in_ECX[0x17] == 0) {
                                              (*local_490)(local_48c);
                                            }
                                            else {
                                              in_ECX[0x1a] = in_ECX[0x1a] +
                                                             (*(int *)(pcVar20 + 4) + 3U &
                                                             0xfffffffc);
                                            }
                                          }
                                          else {
                                            in_ECX[0x1a] = in_ECX[0x1a] +
                                                           *(int *)(pcVar20 + 0x82c) * 4;
                                            in_ECX[0x1a] = in_ECX[0x1a] +
                                                           (*(int *)(pcVar20 + 4) + 3U & 0xfffffffc)
                                            ;
                                          }
                                        }
                                        else {
                                          in_ECX[0x1a] = in_ECX[0x1a] +
                                                         *(int *)(pcVar20 + 0x82c) * 4;
                                          in_ECX[0x1a] = in_ECX[0x1a] +
                                                         *(int *)(pcVar20 + 0x82c) * 4;
                                          in_ECX[0x1a] = in_ECX[0x1a] +
                                                         (*(int *)(pcVar20 + 4) + 3U & 0xfffffffc);
                                        }
                                        *(undefined4 *)(pcVar20 + 0x20) = 0;
                                      }
                                      in_ECX = local_46c;
                                      pcVar15 = pcVar20 + 0x24;
                                      for (iVar9 = 0x200; iVar9 != 0; iVar9 = iVar9 + -1) {
                                        *(undefined4 *)pcVar15 = 0xffffffff;
                                        pcVar15 = pcVar15 + 4;
                                      }
                                      if (pcVar20[0x17] == (code)0x0) {
                                        local_498 = *(code **)(pcVar20 + 4);
                                      }
                                      else {
                                        local_498 = *(code **)(pcVar20 + 0x82c);
                                      }
                                      if ((int)local_498 < 0x8000) {
                                        if (0 < (int)local_498) goto LAB_1003d82e;
                                      }
                                      else {
                                        local_498 = (code *)0x7fff;
LAB_1003d82e:
                                        iVar9 = *(int *)(pcVar20 + 8);
                                        local_4a4 = (code *)0x0;
                                        do {
                                          if ((byte)local_4a4[iVar9] < 0xb) {
                                            if (pcVar20[0x17] == (code)0x0) {
                                              uVar10 = *(uint *)(*(int *)(pcVar20 + 0x20) +
                                                                (int)local_4a4 * 4);
                                            }
                                            else {
                                              uVar10 = *(uint *)(*(int *)(pcVar20 + 0x824) +
                                                                (int)local_4a4 * 4);
                                              uVar10 = (uVar10 >> 1 ^ uVar10 * 2) & 0x55555555 ^
                                                       uVar10 * 2;
                                              uVar10 = (uVar10 >> 2 ^ uVar10 * 4) & 0x33333333 ^
                                                       uVar10 * 4;
                                              uVar10 = (uVar10 >> 4 ^ uVar10 << 4) & 0xf0f0f0f ^
                                                       uVar10 << 4;
                                              uVar10 = (uVar10 >> 8 ^ uVar10 << 8) & 0xff00ff ^
                                                       uVar10 << 8;
                                              uVar10 = uVar10 << 0x10 | uVar10 >> 0x10;
                                            }
                                            for (; uVar10 < 0x400;
                                                uVar10 = uVar10 + (1 << ((byte)local_4a4[*(int *)(
                                                  pcVar20 + 8)] & 0x1f))) {
                                              *(short *)(pcVar20 + uVar10 * 2 + 0x24) =
                                                   (short)local_4a4;
                                            }
                                            iVar9 = *(int *)(pcVar20 + 8);
                                          }
                                          local_4a4 = local_4a4 + 1;
                                        } while ((int)local_4a4 < (int)local_498);
                                      }
                                      cVar3 = (code)FUN_100392f0();
                                      pcVar20[0x15] = cVar3;
                                      if (2 < (byte)cVar3) goto LAB_1003cfde;
                                      if (cVar3 != (code)0x0) {
                                        uVar10 = FUN_100392f0();
                                        dVar24 = (double)(uVar10 & 0x1fffff) + 0.0;
                                        if ((int)uVar10 < 0) {
                                          dVar24 = (double)CONCAT44((uint)((ulonglong)dVar24 >> 0x20
                                                                          ) ^ local_460._4_4_,
                                                                    SUB84(dVar24,0) ^
                                                                    (uint)local_460);
                                        }
                                        dVar24 = ldexp((double)(float)dVar24,
                                                       (uVar10 >> 0x15 & 0x3ff) - 0x314);
                                        *(float *)(pcVar20 + 0xc) = (float)dVar24;
                                        uVar10 = FUN_100392f0();
                                        dVar24 = (double)(uVar10 & 0x1fffff) + 0.0;
                                        if ((int)uVar10 < 0) {
                                          dVar24 = (double)CONCAT44((uint)((ulonglong)dVar24 >> 0x20
                                                                          ) ^ local_460._4_4_,
                                                                    SUB84(dVar24,0) ^
                                                                    (uint)local_460);
                                        }
                                        dVar24 = ldexp((double)(float)dVar24,
                                                       (uVar10 >> 0x15 & 0x3ff) - 0x314);
                                        *(float *)(pcVar20 + 0x10) = (float)dVar24;
                                        cVar1 = FUN_100392f0();
                                        pcVar20[0x14] = (code)(cVar1 + 1);
                                        cVar3 = (code)FUN_100392f0();
                                        pcVar20[0x16] = cVar3;
                                        if (pcVar20[0x15] == (code)0x1) {
                                          local_4a4 = *(code **)(pcVar20 + 4);
                                          iVar9 = *(int *)pcVar20;
                                          dVar24 = (double)(int)local_4a4;
                                          libm_sse2_log_precise();
                                          dVar24 = (double)((float)dVar24 / (float)iVar9);
                                          libm_sse2_exp_precise();
                                          local_480 = dVar24;
                                          local_480 = floor(dVar24);
                                          pcVar20 = (code *)(int)local_480;
                                          dVar24 = (double)((float)(int)pcVar20 + 1.0);
                                          libm_sse2_pow_precise();
                                          local_480 = dVar24;
                                          local_480 = floor(dVar24);
                                          local_4a0 = pcVar20 + 1;
                                          if ((int)local_4a4 < (int)local_480) {
                                            local_4a0 = pcVar20;
                                          }
                                          dVar24 = (double)((float)(int)local_4a0 + 1.0);
                                          libm_sse2_pow_precise();
                                          pcVar20 = local_4a4;
                                          if (dVar24 <= (double)(int)local_4a4) {
LAB_1003df9a:
                                            local_46c[0x1c] = 0x14;
                                            __security_check_cookie(local_14 ^ (uint)auStack_4a8);
                                            return;
                                          }
                                          dVar24 = (double)(int)local_4a0;
                                          libm_sse2_pow_precise();
                                          local_480 = dVar24;
                                          local_480 = floor(dVar24);
                                          if (((int)pcVar20 < (int)local_480) ||
                                             (pcVar15 = local_4a0, pcVar20 = local_484,
                                             in_ECX = local_46c, (int)local_4a0 < 0))
                                          goto LAB_1003df9a;
                                        }
                                        else {
                                          pcVar15 = (code *)(*(int *)pcVar20 * *(int *)(pcVar20 + 4)
                                                            );
                                        }
                                        *(code **)(pcVar20 + 0x18) = pcVar15;
                                        if (pcVar15 == (code *)0x0) goto LAB_1003cfde;
                                        local_494 = pcVar20 + 0x18;
                                        uVar10 = *(int *)(pcVar20 + 0x18) * 2 + 7U & 0xfffffff8;
                                        if (in_ECX[0x17] == 0) {
                                          local_48c = (void *)(*local_474)(uVar10);
                                        }
                                        else {
                                          iVar9 = in_ECX[0x1a] - uVar10;
                                          if (iVar9 < in_ECX[0x19]) goto LAB_1003df02;
                                          in_ECX[0x1a] = iVar9;
                                          local_48c = (void *)(iVar9 + in_ECX[0x17]);
                                        }
                                        if (local_48c == (void *)0x0) goto LAB_1003df02;
                                        uVar10 = *(uint *)local_494;
                                        local_4a4 = (code *)0x0;
                                        if (0 < (int)uVar10) {
                                          do {
                                            iVar9 = FUN_100392f0();
                                            if (iVar9 == -1) {
                                              iVar9 = *(uint *)local_494 * 2;
                                              goto LAB_1003e019;
                                            }
                                            *(short *)((int)local_48c + (int)local_4a4 * 2) =
                                                 (short)iVar9;
                                            local_4a4 = local_4a4 + 1;
                                            uVar10 = *(uint *)local_494;
                                          } while ((int)local_4a4 < (int)uVar10);
                                        }
                                        local_4a0 = (code *)0x0;
                                        if (pcVar20[0x15] == (code)0x1) {
                                          local_4a5 = pcVar20[0x17];
                                          if ((local_4a5 == (code)0x0) ||
                                             (*(int *)(pcVar20 + 0x82c) != 0)) {
                                            iVar9 = FUN_10037f70();
                                            *(int *)(pcVar20 + 0x1c) = iVar9;
                                            if (iVar9 == 0) {
                                              uVar10 = *(uint *)(pcVar20 + 0x18);
                                              goto LAB_1003dfdc;
                                            }
                                            if (local_4a5 == (code)0x0) {
                                              iVar9 = *(int *)(pcVar20 + 4);
                                            }
                                            else {
                                              iVar9 = *(int *)(pcVar20 + 0x82c);
                                            }
                                            local_480 = (double)CONCAT44(local_480._4_4_,iVar9);
                                            local_488 = (code *)0x0;
                                            pcVar15 = local_4a0;
                                            if (0 < iVar9) {
                                              do {
                                                local_470 = local_488;
                                                if (local_4a5 != (code)0x0) {
                                                  local_470 = *(code **)(*(int *)(pcVar20 + 0x828) +
                                                                        (int)local_488 * 4);
                                                }
                                                iVar19 = *(int *)pcVar20;
                                                local_498 = (code *)0x1;
                                                local_4a0 = (code *)0x0;
                                                if (0 < iVar19) {
                                                  do {
                                                    pcVar23 = (code *)((float)*(ushort *)
                                                                               ((int)local_48c +
                                                                               (int)((ZEXT48(
                                                  local_470) / ZEXT48(local_498)) %
                                                  (ulonglong)*(uint *)local_494) * 2) *
                                                  *(float *)(pcVar20 + 0x10) +
                                                  *(float *)(pcVar20 + 0xc) + (float)pcVar15);
                                                  *(code **)(*(int *)(pcVar20 + 0x1c) +
                                                            (int)(local_4a0 +
                                                                 iVar19 * (int)local_488) * 4) =
                                                       pcVar23;
                                                  if (pcVar20[0x16] != (code)0x0) {
                                                    pcVar15 = pcVar23;
                                                  }
                                                  iVar19 = *(int *)pcVar20;
                                                  local_4a0 = local_4a0 + 1;
                                                  in_ECX = local_46c;
                                                  if ((int)local_4a0 < iVar19) {
                                                    local_4a4 = *(code **)local_494;
                                                    if ((code *)(0xffffffff / ZEXT48(local_4a4)) <
                                                        local_498) {
                                                      iVar9 = (int)local_4a4 * 2;
                                                      goto LAB_1003e019;
                                                    }
                                                    local_498 = (code *)((int)local_498 *
                                                                        (int)local_4a4);
                                                  }
                                                  } while ((int)local_4a0 < iVar19);
                                                }
                                                local_488 = local_488 + 1;
                                              } while ((int)local_488 < iVar9);
                                            }
                                            uVar10 = *(uint *)(pcVar20 + 0x18);
                                            pcVar20[0x15] = (code)0x2;
                                          }
                                        }
                                        else {
                                          iVar9 = FUN_10037f70();
                                          *(int *)(pcVar20 + 0x1c) = iVar9;
                                          uVar10 = *(uint *)local_494;
                                          if (iVar9 == 0) {
LAB_1003dfdc:
                                            FUN_10037fc0(uVar10 * 2);
                                            goto LAB_1003dfeb;
                                          }
                                          local_484 = (code *)0x0;
                                          if (0 < (int)uVar10) {
                                            iVar9 = 0;
                                            pcVar15 = local_4a0;
                                            do {
                                              pcVar23 = (code *)((float)*(ushort *)
                                                                         ((int)local_48c + iVar9 * 2
                                                                         ) *
                                                                 *(float *)(pcVar20 + 0x10) +
                                                                 *(float *)(pcVar20 + 0xc) +
                                                                (float)pcVar15);
                                              *(code **)(*(int *)(pcVar20 + 0x1c) + iVar9 * 4) =
                                                   pcVar23;
                                              if (pcVar20[0x16] != (code)0x0) {
                                                local_4a0 = pcVar23;
                                                pcVar15 = pcVar23;
                                              }
                                              uVar10 = *(uint *)local_494;
                                              iVar9 = iVar9 + 1;
                                              in_ECX = local_46c;
                                            } while (iVar9 < (int)uVar10);
                                          }
                                        }
                                        FUN_10037fc0(uVar10 * 2);
                                      }
                                      local_49c = local_49c + 1;
                                    } while ((int)local_49c < in_ECX[0x21]);
                                  }
                                  iVar9 = 0;
                                  cVar1 = FUN_100392f0();
                                  local_484 = (code *)(uint)(byte)(cVar1 + 1U);
                                  if ((byte)(cVar1 + 1U) != 0) {
                                    do {
                                      iVar19 = FUN_100392f0();
                                      if (iVar19 != 0) goto LAB_1003cfde;
                                      iVar9 = iVar9 + 1;
                                    } while (iVar9 < (int)local_484);
                                  }
                                  iVar9 = FUN_100392f0();
                                  in_ECX[0x23] = iVar9 + 1;
                                  iVar9 = FUN_10037f70();
                                  in_ECX[0x44] = iVar9;
                                  if (iVar9 != 0) {
                                    local_498 = (code *)0x0;
                                    if (0 < in_ECX[0x23]) {
                                      pcVar20 = (code *)(in_ECX + 0x24);
                                      local_490 = (code *)0x0;
                                      do {
                                        local_488 = pcVar20;
                                        uVar6 = FUN_100392f0();
                                        *(ushort *)pcVar20 = uVar6;
                                        if (1 < uVar6) goto LAB_1003cfde;
                                        pcVar20 = local_490 + in_ECX[0x44];
                                        local_480 = (double)CONCAT44(local_480._4_4_,pcVar20);
                                        if (uVar6 == 0) {
                                          cVar3 = (code)FUN_100392f0();
                                          *pcVar20 = cVar3;
                                          uVar8 = FUN_100392f0();
                                          *(undefined2 *)(pcVar20 + 2) = uVar8;
                                          uVar8 = FUN_100392f0();
                                          *(undefined2 *)(pcVar20 + 4) = uVar8;
                                          cVar3 = (code)FUN_100392f0();
                                          pcVar20[6] = cVar3;
                                          cVar3 = (code)FUN_100392f0();
                                          pcVar20[7] = cVar3;
                                          cVar1 = FUN_100392f0();
                                          local_49c = (code *)0x0;
                                          pcVar20[8] = (code)(cVar1 + 1U);
                                          if ((code)(cVar1 + 1U) != (code)0x0) {
                                            do {
                                              cVar3 = (code)FUN_100392f0();
                                              pcVar20[(int)local_49c + 9] = cVar3;
                                              local_49c = (code *)((int)local_49c + 1);
                                            } while ((int)local_49c < (int)(uint)(byte)pcVar20[8]);
                                          }
                                          in_ECX[0x1c] = 4;
                                          __security_check_cookie(local_14 ^ (uint)auStack_4a8);
                                          return;
                                        }
                                        local_4a0 = (code *)0xffffffff;
                                        cVar3 = (code)FUN_100392f0();
                                        *pcVar20 = cVar3;
                                        local_49c = (code *)0x0;
                                        pcVar15 = local_4a0;
                                        if (cVar3 == (code)0x0) {
                                          pcVar23 = (code *)0xffffffff;
                                        }
                                        else {
                                          do {
                                            cVar3 = (code)FUN_100392f0();
                                            (local_480._0_4_ + 1)[(int)local_49c] = cVar3;
                                            pcVar23 = (code *)(uint)(byte)cVar3;
                                            if ((int)(uint)(byte)cVar3 <= (int)pcVar15) {
                                              pcVar23 = pcVar15;
                                            }
                                            local_49c = local_49c + 1;
                                            pcVar15 = pcVar23;
                                            pcVar20 = local_480._0_4_;
                                          } while ((int)local_49c <
                                                   (int)(uint)(byte)*local_480._0_4_);
                                        }
                                        local_4a0 = pcVar15;
                                        local_470 = (code *)0x0;
                                        if (-1 < (int)pcVar23) {
                                          local_494 = pcVar20 + 0x31;
                                          local_4a4 = pcVar20 + 0x52;
                                          do {
                                            cVar1 = FUN_100392f0();
                                            local_494[-0x10] = (code)(cVar1 + 1);
                                            cVar3 = (code)FUN_100392f0();
                                            *local_494 = cVar3;
                                            if (cVar3 != (code)0x0) {
                                              cVar3 = (code)FUN_100392f0();
                                              local_494[0x10] = cVar3;
                                              if (in_ECX[0x21] <= (int)(uint)(byte)cVar3)
                                              goto LAB_1003cfde;
                                            }
                                            local_49c = (code *)0x0;
                                            if (0 < 1 << ((byte)*local_494 & 0x1f)) {
                                              local_480 = (double)CONCAT44(local_480._4_4_,local_4a4
                                                                          );
                                              do {
                                                sVar7 = FUN_100392f0();
                                                *(short *)local_480._0_4_ = sVar7 + -1;
                                                if (in_ECX[0x21] <= (int)(short)(sVar7 + -1))
                                                goto LAB_1003cfde;
                                                local_480 = (double)CONCAT44(local_480._4_4_,
                                                                             (short *)((int)
                                                  local_480._0_4_ + 2));
                                                local_49c = local_49c + 1;
                                              } while ((int)local_49c <
                                                       1 << ((byte)*local_494 & 0x1f));
                                            }
                                            local_494 = local_494 + 1;
                                            local_470 = local_470 + 1;
                                            local_4a4 = local_4a4 + 0x10;
                                          } while ((int)local_470 <= (int)local_4a0);
                                        }
                                        cVar1 = FUN_100392f0();
                                        pcVar20[0x634] = (code)(cVar1 + 1);
                                        cVar3 = (code)FUN_100392f0();
                                        pcVar20[0x635] = cVar3;
                                        *(undefined2 *)(pcVar20 + 0x152) = 0;
                                        iVar9 = 0;
                                        *(short *)(pcVar20 + 0x154) = 1 << ((byte)cVar3 & 0x1f);
                                        *(undefined4 *)(pcVar20 + 0x638) = 2;
                                        local_480 = (double)((ulonglong)local_480 &
                                                            0xffffffff00000000);
                                        sVar14 = 2;
                                        if (*pcVar20 != (code)0x0) {
                                          do {
                                            local_484 = (code *)(uint)(byte)pcVar20[iVar9 + 1];
                                            local_49c = (code *)0x0;
                                            if ((local_484 + 0x21)[(int)pcVar20] != (code)0x0) {
                                              do {
                                                uVar8 = FUN_100392f0();
                                                *(undefined2 *)
                                                 (pcVar20 + *(int *)(pcVar20 + 0x638) * 2 + 0x152) =
                                                     uVar8;
                                                *(int *)(pcVar20 + 0x638) =
                                                     *(int *)(pcVar20 + 0x638) + 1;
                                                local_49c = local_49c + 1;
                                              } while ((int)local_49c <
                                                       (int)(uint)(byte)(local_484 + 0x21)
                                                                        [(int)pcVar20]);
                                              iVar9 = (int)local_480._0_4_;
                                            }
                                            iVar9 = iVar9 + 1;
                                            local_480 = (double)CONCAT44(local_480._4_4_,iVar9);
                                          } while (iVar9 < (int)(uint)(byte)*pcVar20);
                                          sVar14 = *(size_t *)(pcVar20 + 0x638);
                                        }
                                        iVar9 = 0;
                                        if (0 < (int)sVar14) {
                                          pcVar15 = pcVar20 + 0x152;
                                          do {
                                            sVar7 = *(short *)pcVar15;
                                            pcVar15 = pcVar15 + 2;
                                            (&sStack_408)[iVar9 * 2] = sVar7;
                                            asStack_404[iVar9 * 2 + -1] = (short)iVar9;
                                            iVar9 = iVar9 + 1;
                                            sVar14 = *(size_t *)(pcVar20 + 0x638);
                                          } while (iVar9 < (int)sVar14);
                                        }
                                        qsort(&sStack_408,sVar14,4,FUN_10038a10);
                                        iVar9 = *(int *)(pcVar20 + 0x638);
                                        iVar19 = 0;
                                        if (0 < iVar9 + -1) {
                                          do {
                                            if ((&sStack_408)[iVar19 * 2] == asStack_404[iVar19 * 2]
                                               ) goto LAB_1003cfde;
                                            iVar19 = iVar19 + 1;
                                          } while (iVar19 < iVar9 + -1);
                                        }
                                        iVar19 = 0;
                                        if (0 < iVar9) {
                                          do {
                                            pcVar20[iVar19 + 0x346] =
                                                 *(code *)(asStack_404 + iVar19 * 2 + -1);
                                            iVar19 = iVar19 + 1;
                                            iVar9 = *(int *)(pcVar20 + 0x638);
                                          } while (iVar19 < iVar9);
                                        }
                                        iVar19 = 2;
                                        if (2 < iVar9) {
                                          do {
                                            local_4a4 = (code *)0x0;
                                            pcVar15 = (code *)0x0;
                                            local_4a0 = (code *)0x0;
                                            local_470 = (code *)0xffffffff;
                                            local_480 = (double)CONCAT44(local_480._4_4_,0x10000);
                                            if (0 < iVar19) {
                                              do {
                                                uVar6 = *(ushort *)
                                                         (pcVar20 + (int)pcVar15 * 2 + 0x152);
                                                local_49c = (code *)(uint)uVar6;
                                                if (((int)local_470 < (int)local_49c) &&
                                                   (uVar6 < *(ushort *)
                                                             (pcVar20 + iVar19 * 2 + 0x152))) {
                                                  local_4a4 = pcVar15;
                                                  local_470 = local_49c;
                                                }
                                                if ((local_49c < local_480._0_4_) &&
                                                   (*(ushort *)(pcVar20 + iVar19 * 2 + 0x152) <
                                                    uVar6)) {
                                                  local_480 = (double)CONCAT44(local_480._4_4_,
                                                                               local_49c);
                                                  local_4a0 = pcVar15;
                                                }
                                                pcVar15 = pcVar15 + 1;
                                              } while ((int)pcVar15 < iVar19);
                                            }
                                            pcVar20[iVar19 * 2 + 0x440] = SUB41(local_4a4,0);
                                            pcVar20[iVar19 * 2 + 0x441] = SUB41(local_4a0,0);
                                            iVar19 = iVar19 + 1;
                                            iVar9 = *(int *)(pcVar20 + 0x638);
                                            in_ECX = local_46c;
                                          } while (iVar19 < iVar9);
                                        }
                                        if (iVar9 <= local_464) {
                                          iVar9 = local_464;
                                        }
                                        local_498 = local_498 + 1;
                                        local_490 = local_490 + 0x63c;
                                        pcVar20 = local_488 + 2;
                                        local_488 = pcVar20;
                                        local_464 = iVar9;
                                      } while ((int)local_498 < in_ECX[0x23]);
                                    }
                                    iVar9 = FUN_100392f0();
                                    in_ECX[0x45] = iVar9 + 1;
                                    pvVar13 = (void *)FUN_10037f70();
                                    in_ECX[0x66] = (int)pvVar13;
                                    if (pvVar13 != (void *)0x0) {
                                      memset(pvVar13,0,in_ECX[0x45] * 0x18);
                                      local_480 = (double)((ulonglong)local_480 & 0xffffffff00000000
                                                          );
                                      if (0 < in_ECX[0x45]) {
                                        local_4a0 = (code *)(in_ECX + 0x46);
                                        local_470 = (code *)0x0;
                                        do {
                                          pcVar20 = local_470 + in_ECX[0x66];
                                          uVar6 = FUN_100392f0();
                                          *(ushort *)local_4a0 = uVar6;
                                          if (2 < uVar6) goto LAB_1003cfde;
                                          uVar10 = FUN_100392f0();
                                          *(uint *)pcVar20 = uVar10;
                                          uVar10 = FUN_100392f0();
                                          *(uint *)(pcVar20 + 4) = uVar10;
                                          if (uVar10 < *(uint *)pcVar20) goto LAB_1003cfde;
                                          iVar9 = FUN_100392f0();
                                          *(uint *)(pcVar20 + 8) = iVar9 + 1;
                                          cVar1 = FUN_100392f0();
                                          pcVar20[0xc] = (code)(cVar1 + '\x01');
                                          cVar3 = (code)FUN_100392f0();
                                          pcVar20[0xd] = cVar3;
                                          if (in_ECX[0x21] <= (int)(uint)(byte)cVar3)
                                          goto LAB_1003cfde;
                                          cVar3 = pcVar20[0xc];
                                          local_49c = (code *)0x0;
                                          if (cVar3 != (code)0x0) {
                                            do {
                                              local_4a6 = (code)0x0;
                                              local_4a5 = (code)FUN_100392f0();
                                              iVar9 = FUN_100392f0();
                                              cVar4 = local_4a6;
                                              if (iVar9 != 0) {
                                                cVar4 = (code)FUN_100392f0();
                                              }
                                              cVar3 = pcVar20[0xc];
                                              abStack_448[(int)local_49c] =
                                                   (char)cVar4 * '\b' + (char)local_4a5;
                                              local_49c = local_49c + 1;
                                            } while ((int)local_49c < (int)(uint)(byte)cVar3);
                                          }
                                          iVar9 = (uint)(byte)cVar3 * 0x10;
                                          in_ECX[2] = in_ECX[2] + iVar9;
                                          if (in_ECX[0x17] == 0) {
                                            if ((byte)cVar3 == 0) goto LAB_1003e914;
                                            uVar10 = (*local_474)(iVar9);
                                          }
                                          else {
                                            iVar19 = in_ECX[0x19];
                                            iVar9 = iVar9 + iVar19;
                                            if (in_ECX[0x1a] < iVar9) {
LAB_1003e914:
                                              *(uint *)(pcVar20 + 0x14) = 0;
                                              goto LAB_1003dfeb;
                                            }
                                            in_ECX[0x19] = iVar9;
                                            uVar10 = in_ECX[0x17] + iVar19;
                                          }
                                          *(uint *)(pcVar20 + 0x14) = uVar10;
                                          if (uVar10 == 0) goto LAB_1003dfeb;
                                          local_4a4 = (code *)0x0;
                                          if (pcVar20[0xc] != (code)0x0) {
                                            do {
                                              local_484 = (code *)(uint)abStack_448[(int)local_4a4];
                                              local_49c = (code *)0x0;
                                              do {
                                                in_ECX = local_46c;
                                                local_490 = (code *)((int)(local_49c +
                                                                          (int)local_4a4 * 8) * 2);
                                                if (((uint)local_484 & 1 << ((byte)local_49c & 0x1f)
                                                    ) == 0) {
                                                  *(undefined2 *)
                                                   (local_490 + *(uint *)(pcVar20 + 0x14)) = 0xffff;
                                                }
                                                else {
                                                  uVar8 = FUN_100392f0();
                                                  *(undefined2 *)
                                                   (local_490 + *(uint *)(pcVar20 + 0x14)) = uVar8;
                                                  if (in_ECX[0x21] <=
                                                      (int)*(short *)(local_490 +
                                                                     *(uint *)(pcVar20 + 0x14)))
                                                  goto LAB_1003cfde;
                                                }
                                                local_49c = local_49c + 1;
                                              } while ((int)local_49c < 8);
                                              local_4a4 = local_4a4 + 1;
                                            } while ((int)local_4a4 < (int)(uint)(byte)pcVar20[0xc])
                                            ;
                                          }
                                          uVar10 = *(int *)((uint)(byte)pcVar20[0xd] * 0x830 + 4 +
                                                           in_ECX[0x22]) * 4 + 7U & 0xfffffff8;
                                          in_ECX[2] = in_ECX[2] + uVar10;
                                          if (in_ECX[0x17] == 0) {
                                            if (uVar10 == 0) goto LAB_1003e908;
                                            pvVar13 = (void *)(*local_474)(uVar10);
                                          }
                                          else {
                                            iVar9 = in_ECX[0x19];
                                            iVar19 = uVar10 + iVar9;
                                            if (in_ECX[0x1a] < iVar19) {
LAB_1003e908:
                                              *(uint *)(pcVar20 + 0x10) = 0;
                                              goto LAB_1003dfeb;
                                            }
                                            in_ECX[0x19] = iVar19;
                                            pvVar13 = (void *)(in_ECX[0x17] + iVar9);
                                          }
                                          *(void **)(pcVar20 + 0x10) = pvVar13;
                                          if (pvVar13 == (void *)0x0) goto LAB_1003dfeb;
                                          memset(pvVar13,0,
                                                 *(int *)((uint)(byte)pcVar20[0xd] * 0x830 + 4 +
                                                         in_ECX[0x22]) << 2);
                                          local_4a4 = (code *)in_ECX[0x22];
                                          cVar3 = pcVar20[0xd];
                                          local_494 = (code *)0x0;
                                          if (0 < *(int *)(local_4a4 + (uint)(byte)cVar3 * 0x830 + 4
                                                          )) {
                                            do {
                                              local_49c = *(code **)((uint)(byte)cVar3 * 0x830 +
                                                                    local_46c[0x22]);
                                              uVar10 = (uint)(local_49c + 7) & 0xfffffff8;
                                              local_46c[2] = local_46c[2] + uVar10;
                                              local_498 = local_494;
                                              if (local_46c[0x17] == 0) {
                                                if (uVar10 == 0) goto LAB_1003e797;
                                                local_490 = (code *)(*local_474)(uVar10);
                                              }
                                              else {
                                                local_484 = (code *)local_46c[0x19];
                                                if (local_46c[0x1a] < (int)(local_484 + uVar10)) {
LAB_1003e797:
                                                  local_490 = (code *)0x0;
                                                }
                                                else {
                                                  local_46c[0x19] = (int)(local_484 + uVar10);
                                                  local_490 = local_484 + local_46c[0x17];
                                                }
                                              }
                                              *(code **)(*(uint *)(pcVar20 + 0x10) +
                                                        (int)local_494 * 4) = local_490;
                                              in_ECX = local_46c;
                                              if (*(int *)(*(uint *)(pcVar20 + 0x10) +
                                                          (int)local_494 * 4) == 0)
                                              goto LAB_1003df02;
                                              local_484 = local_49c + -1;
                                              if (-1 < (int)local_484) {
                                                uVar10 = (uint)(byte)pcVar20[0xc];
                                                pcVar15 = local_484;
                                                do {
                                                  pcVar15[*(int *)(*(uint *)(pcVar20 + 0x10) +
                                                                  (int)local_494 * 4)] =
                                                       SUB41((int)local_498 % (int)uVar10,0);
                                                  uVar10 = (uint)(byte)pcVar20[0xc];
                                                  local_498 = (code *)((int)local_498 / (int)uVar10)
                                                  ;
                                                  pcVar15 = pcVar15 + -1;
                                                } while (-1 < (int)pcVar15);
                                              }
                                              local_4a4 = (code *)local_46c[0x22];
                                              local_494 = local_494 + 1;
                                              cVar3 = pcVar20[0xd];
                                            } while ((int)local_494 <
                                                     *(int *)(local_4a4 +
                                                             (uint)(byte)cVar3 * 0x830 + 4));
                                          }
                                          iVar9 = (int)local_480._0_4_ + 1;
                                          local_4a0 = local_4a0 + 2;
                                          local_470 = local_470 + 0x18;
                                          local_480 = (double)CONCAT44(local_480._4_4_,iVar9);
                                          in_ECX = local_46c;
                                        } while (iVar9 < local_46c[0x45]);
                                      }
                                      iVar9 = FUN_100392f0();
                                      in_ECX[0x67] = iVar9 + 1;
                                      pvVar13 = (void *)FUN_10037f70();
                                      in_ECX[0x68] = (int)pvVar13;
                                      if (pvVar13 != (void *)0x0) {
                                        memset(pvVar13,0,in_ECX[0x67] * 0x28);
                                        local_470 = (code *)0x0;
                                        if (0 < in_ECX[0x67]) {
                                          local_490 = (code *)0x0;
                                          do {
                                            pcVar20 = local_490 + in_ECX[0x68];
                                            iVar9 = FUN_100392f0();
                                            if (iVar9 != 0) goto LAB_1003cfde;
                                            uVar10 = in_ECX[1] * 3 + 7U & 0xfffffff8;
                                            in_ECX[2] = in_ECX[2] + uVar10;
                                            if (in_ECX[0x17] == 0) {
                                              if (uVar10 == 0) goto LAB_1003ec7c;
                                              iVar9 = (*local_474)(uVar10);
                                            }
                                            else {
                                              iVar9 = in_ECX[0x19];
                                              iVar19 = uVar10 + iVar9;
                                              if (in_ECX[0x1a] < iVar19) {
LAB_1003ec7c:
                                                *(undefined4 *)(pcVar20 + 4) = 0;
LAB_1003dfeb:
                                                in_ECX[0x1c] = 3;
                                                __security_check_cookie
                                                          (local_14 ^ (uint)auStack_4a8);
                                                return;
                                              }
                                              in_ECX[0x19] = iVar19;
                                              iVar9 = in_ECX[0x17] + iVar9;
                                            }
                                            *(int *)(pcVar20 + 4) = iVar9;
                                            if (iVar9 == 0) goto LAB_1003dfeb;
                                            iVar9 = FUN_100392f0();
                                            if (iVar9 == 0) {
                                              cVar3 = (code)0x1;
                                            }
                                            else {
                                              cVar1 = FUN_100392f0();
                                              cVar3 = (code)(cVar1 + '\x01');
                                            }
                                            pcVar20[8] = cVar3;
                                            if ((int)local_468 < (int)(uint)(byte)cVar3) {
                                              local_468 = (uint)(byte)cVar3;
                                            }
                                            iVar9 = FUN_100392f0();
                                            if (iVar9 == 0) {
                                              *(ushort *)pcVar20 = 0;
                                            }
                                            else {
                                              sVar7 = FUN_100392f0();
                                              uVar6 = sVar7 + 1;
                                              *(ushort *)pcVar20 = uVar6;
                                              if (in_ECX[1] < (int)(uint)uVar6) goto LAB_1003cfde;
                                              local_4a0 = (code *)0x0;
                                              if (uVar6 != 0) {
                                                local_4a4 = (code *)0x0;
                                                do {
                                                  FUN_10038070();
                                                  cVar3 = (code)FUN_100392f0();
                                                  local_4a4[*(int *)(pcVar20 + 4)] = cVar3;
                                                  FUN_10038070();
                                                  cVar3 = (code)FUN_100392f0();
                                                  local_4a4[*(int *)(pcVar20 + 4) + 1] = cVar3;
                                                  local_4a6 = local_4a4[*(int *)(pcVar20 + 4)];
                                                  if (((in_ECX[1] <= (int)(uint)(byte)local_4a6) ||
                                                      (local_4a5 = local_4a4[*(int *)(pcVar20 + 4) +
                                                                             1],
                                                      in_ECX[1] <= (int)(uint)(byte)local_4a5)) ||
                                                     (local_4a6 == local_4a5)) goto LAB_1003cfde;
                                                  local_4a0 = local_4a0 + 1;
                                                  local_4a4 = local_4a4 + 3;
                                                } while ((int)local_4a0 <
                                                         (int)(uint)*(ushort *)pcVar20);
                                              }
                                            }
                                            iVar9 = FUN_100392f0();
                                            if (iVar9 != 0) goto LAB_1003cfde;
                                            cVar3 = pcVar20[8];
                                            if ((byte)cVar3 < 2) {
                                              iVar9 = 0;
                                              if (0 < in_ECX[1]) {
                                                iVar19 = 0;
                                                do {
                                                  iVar9 = iVar9 + 1;
                                                  *(undefined1 *)
                                                   (iVar19 + 2 + *(int *)(pcVar20 + 4)) = 0;
                                                  iVar19 = iVar19 + 3;
                                                } while (iVar9 < in_ECX[1]);
                                                cVar3 = pcVar20[8];
                                              }
                                            }
                                            else {
                                              local_49c = (code *)0x0;
                                              if (0 < in_ECX[1]) {
                                                local_480 = (double)((ulonglong)local_480 &
                                                                    0xffffffff00000000);
                                                do {
                                                  uVar2 = FUN_100392f0();
                                                  *(undefined1 *)
                                                   ((int)local_480._0_4_ + 2 + *(int *)(pcVar20 + 4)
                                                   ) = uVar2;
                                                  cVar3 = pcVar20[8];
                                                  if ((byte)cVar3 <=
                                                      (byte)*(code *)((int)local_480._0_4_ + 2 +
                                                                     *(int *)(pcVar20 + 4)))
                                                  goto LAB_1003cfde;
                                                  local_49c = local_49c + 1;
                                                  local_480 = (double)CONCAT44(local_480._4_4_,
                                                                               (int)local_480._0_4_
                                                                               + 3);
                                                } while ((int)local_49c < in_ECX[1]);
                                              }
                                            }
                                            if (cVar3 != (code)0x0) {
                                              local_4a4 = pcVar20 + 9;
                                              local_484 = (code *)(-9 - (int)pcVar20);
                                              do {
                                                FUN_100392f0();
                                                cVar3 = (code)FUN_100392f0();
                                                *local_4a4 = cVar3;
                                                cVar3 = (code)FUN_100392f0();
                                                local_4a4[0xf] = cVar3;
                                                if ((in_ECX[0x23] <= (int)(uint)(byte)*local_4a4) ||
                                                   (in_ECX[0x45] <= (int)(uint)(byte)cVar3))
                                                goto LAB_1003cfde;
                                                local_4a4 = local_4a4 + 1;
                                              } while ((int)(local_484 + (int)local_4a4) <
                                                       (int)(uint)(byte)pcVar20[8]);
                                            }
                                            local_470 = local_470 + 1;
                                            local_490 = local_490 + 0x28;
                                          } while ((int)local_470 < in_ECX[0x67]);
                                        }
                                        iVar9 = FUN_100392f0();
                                        local_468 = 0;
                                        in_ECX[0x69] = iVar9 + 1;
                                        if (0 < iVar9 + 1) {
                                          psVar21 = (short *)((int)in_ECX + 0x1aa);
                                          do {
                                            uVar2 = FUN_100392f0();
                                            *(undefined1 *)(psVar21 + -1) = uVar2;
                                            sVar7 = FUN_100392f0();
                                            *psVar21 = sVar7;
                                            sVar7 = FUN_100392f0();
                                            psVar21[1] = sVar7;
                                            bVar5 = FUN_100392f0();
                                            *(byte *)((int)psVar21 + -1) = bVar5;
                                            if (((*psVar21 != 0) || (psVar21[1] != 0)) ||
                                               (in_ECX[0x67] <= (int)(uint)bVar5))
                                            goto LAB_1003cfde;
                                            psVar21 = psVar21 + 3;
                                            local_468 = local_468 + 1;
                                          } while ((int)local_468 < in_ECX[0x69]);
                                        }
                                        FUN_10039250();
                                        in_ECX[0xfb] = 0;
                                        local_468 = 0;
                                        if (0 < in_ECX[1]) {
                                          piVar22 = in_ECX + 0xcb;
                                          local_484 = (code *)(local_464 * 2 + 7U & 0xfffffff8);
                                          do {
                                            uVar10 = in_ECX[0x20] * 4 + 7U & 0xfffffff8;
                                            in_ECX[2] = in_ECX[2] + uVar10;
                                            if (in_ECX[0x17] == 0) {
                                              if (uVar10 == 0) goto LAB_1003ec96;
                                              iVar9 = (*local_474)(uVar10);
                                            }
                                            else {
                                              iVar9 = in_ECX[0x19];
                                              iVar19 = uVar10 + iVar9;
                                              if (in_ECX[0x1a] < iVar19) {
LAB_1003ec96:
                                                iVar9 = 0;
                                              }
                                              else {
                                                in_ECX[0x19] = iVar19;
                                                iVar9 = in_ECX[0x17] + iVar9;
                                              }
                                            }
                                            *piVar22 = iVar9;
                                            uVar10 = ((uint)(in_ECX[0x20] << 2) >> 1) + 7 &
                                                     0xfffffff8;
                                            in_ECX[2] = in_ECX[2] + uVar10;
                                            if (in_ECX[0x17] == 0) {
                                              if (uVar10 == 0) goto LAB_1003ecd5;
                                              iVar9 = (*local_474)(uVar10);
                                            }
                                            else {
                                              iVar9 = in_ECX[0x19];
                                              iVar19 = uVar10 + iVar9;
                                              if (in_ECX[0x1a] < iVar19) {
LAB_1003ecd5:
                                                iVar9 = 0;
                                              }
                                              else {
                                                in_ECX[0x19] = iVar19;
                                                iVar9 = in_ECX[0x17] + iVar9;
                                              }
                                            }
                                            piVar22[0x20] = iVar9;
                                            in_ECX[2] = (int)(local_484 + in_ECX[2]);
                                            if (in_ECX[0x17] == 0) {
                                              if (local_484 == (code *)0x0) goto LAB_1003ed0b;
                                              iVar9 = (*local_474)(local_484);
                                            }
                                            else {
                                              iVar9 = in_ECX[0x19];
                                              if (in_ECX[0x1a] < (int)(local_484 + iVar9)) {
LAB_1003ed0b:
                                                iVar9 = 0;
                                              }
                                              else {
                                                in_ECX[0x19] = (int)(local_484 + iVar9);
                                                iVar9 = in_ECX[0x17] + iVar9;
                                              }
                                            }
                                            piVar22[0x31] = iVar9;
                                            if ((((void *)*piVar22 == (void *)0x0) ||
                                                (piVar22[0x20] == 0)) || (iVar9 == 0))
                                            goto LAB_1003df02;
                                            memset((void *)*piVar22,0,in_ECX[0x20] << 2);
                                            local_468 = local_468 + 1;
                                            piVar22 = piVar22 + 1;
                                          } while ((int)local_468 < in_ECX[1]);
                                        }
                                        iVar9 = FUN_100385d0(in_ECX[0x1f]);
                                        if ((iVar9 == 0) ||
                                           (iVar9 = FUN_100385d0(in_ECX[0x20]), iVar9 == 0))
                                        goto LAB_1003ee81;
                                        uVar10 = 0;
                                        in_ECX[0x1d] = in_ECX[0x1f];
                                        iVar9 = in_ECX[0x20];
                                        in_ECX[0x1e] = iVar9;
                                        local_468 = in_ECX[0x45];
                                        uVar18 = (uint)(iVar9 * 4) >> 1;
                                        local_480 = (double)CONCAT44(local_480._4_4_,uVar18);
                                        if (0 < (int)local_468) {
                                          local_49c = (code *)(iVar9 / 2);
                                          puVar16 = (undefined4 *)in_ECX[0x66];
                                          do {
                                            pcVar20 = local_49c;
                                            if ((code *)*puVar16 < local_49c) {
                                              pcVar20 = (code *)*puVar16;
                                            }
                                            pcVar15 = local_49c;
                                            if ((code *)puVar16[1] < local_49c) {
                                              pcVar15 = (code *)puVar16[1];
                                            }
                                            uVar17 = (uint)((int)pcVar15 - (int)pcVar20) /
                                                     (uint)puVar16[2];
                                            if ((int)uVar10 < (int)uVar17) {
                                              uVar10 = uVar17;
                                            }
                                            local_468 = local_468 - 1;
                                            puVar16 = puVar16 + 6;
                                          } while (local_468 != 0);
                                          local_468 = 0;
                                          in_ECX = local_46c;
                                        }
                                        uVar10 = (uVar10 + 1) * in_ECX[1] * 4;
                                        in_ECX[3] = uVar10;
                                        if (uVar10 < uVar18) {
                                          in_ECX[3] = uVar18;
                                          uVar10 = uVar18;
                                        }
                                        if ((in_ECX[0x17] == 0) ||
                                           (in_ECX[0x19] + 0x5f4 + uVar10 <= (uint)in_ECX[0x1a])) {
                                          if (in_ECX[0x15c] == -1) {
                                            iVar9 = FUN_1003f1e0();
                                            in_ECX[0x10] = iVar9;
                                            __security_check_cookie(local_14 ^ (uint)auStack_4a8);
                                            return;
                                          }
                                          in_ECX[0x10] = 0;
                                          __security_check_cookie(local_14 ^ (uint)auStack_4a8);
                                          return;
                                        }
                                      }
                                    }
                                  }
                                }
LAB_1003df02:
                                in_ECX[0x1c] = 3;
                                __security_check_cookie(local_14 ^ (uint)auStack_4a8);
                                return;
                              }
                            }
                          }
                          else if (in_ECX[0x1c] != 0x15) goto LAB_1003ee81;
                        }
                      }
                    }
LAB_1003cfde:
                    in_ECX[0x1c] = 0x14;
                    __security_check_cookie(local_14 ^ (uint)auStack_4a8);
                    return;
                  }
                }
              }
            }
          }
        }
        else if ((((char)in_ECX[0x11b] == '@') && (iVar9 = FUN_10038b20(6), iVar9 != 0)) &&
                ((((local_1c[0] == 'f' &&
                   (((local_1c[1] == 'i' && (local_1c[2] == 's')) && (local_1c[3] == 'h')))) &&
                  (((local_1c[4] == 'e' && (local_1c[5] == 'a')) &&
                   (cVar1 = FUN_10038a40(), cVar1 == 'd')))) &&
                 (cVar1 = FUN_10038a40(), cVar1 == '\0')))) {
          in_ECX[0x1c] = 0x26;
          __security_check_cookie(local_14 ^ (uint)auStack_4a8);
          return;
        }
      }
      in_ECX[0x1c] = 0x22;
      __security_check_cookie(local_14 ^ (uint)auStack_4a8);
      return;
    }
  }
  else {
    in_ECX[0x1c] = 0x1e;
  }
LAB_1003ee81:
  __security_check_cookie(local_14 ^ (uint)auStack_4a8);
  return;
}

