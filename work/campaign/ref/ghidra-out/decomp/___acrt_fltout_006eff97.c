
/* Library Function - Single Match
    ___acrt_fltout
   
   Library: Visual Studio 2019 Release */

void ___acrt_fltout(int param_1,uint param_2,int param_3,undefined4 *param_4,uint ***param_5,
                   rsize_t param_6)

{
  uint *puVar1;
  byte bVar2;
  uint **ppuVar3;
  uint **ppuVar4;
  ulonglong uVar5;
  longlong lVar6;
  bool bVar7;
  undefined4 uVar8;
  __acrt_fp_class _Var9;
  rsize_t rVar10;
  char *pcVar11;
  errno_t eVar12;
  uint uVar13;
  int iVar14;
  uint ***pppuVar15;
  int iVar16;
  uint ***pppuVar17;
  uint ***pppuVar18;
  uint ***pppuVar19;
  uint **ppuVar20;
  uint uVar21;
  __uint64 _Var22;
  ulonglong uVar23;
  uint *local_964 [115];
  byte local_798 [8];
  char local_790;
  uint **local_788;
  undefined4 *local_784;
  uint ***local_780;
  undefined8 local_77c;
  uint ***local_774;
  uint ***local_770;
  uint local_76c;
  uint ***local_768;
  uint ***local_764;
  uint ***local_760;
  uint **local_75c;
  uint ***local_758;
  uint ***local_754;
  uint ***local_750;
  uint ***local_74c;
  uint ***local_748;
  uint *local_744 [115];
  uint ***local_578;
  uint **local_574 [115];
  uint ***local_3a8;
  uint **local_3a4 [115];
  uint ***local_1d8;
  uint **local_1d4;
  uint *local_1d0 [114];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_784 = param_4;
  local_770 = param_5;
  fegetenv(local_798);
  local_790 = (local_798[0] & 0x1f) != 0x1f;
  if ((bool)local_790) {
    feholdexcept(local_798);
  }
  uVar13 = param_2;
  iVar14 = param_1;
  uVar8 = 0x20;
  if (((int)param_2 < 1) && ((int)param_2 < 0)) {
    uVar8 = 0x2d;
  }
  *local_784 = uVar8;
  local_784[2] = local_770;
  if (((param_2 & 0x7ff00000) == 0) && (param_1 == 0 && (param_2 & 0xfffff) == 0)) {
    pcVar11 = "0";
    local_784[1] = 0;
  }
  else {
    _Var9 = __acrt_fp_classify((double *)&param_1);
    if (_Var9 != 0) {
      local_784[1] = 1;
    }
    if (_Var9 == 1) {
      pcVar11 = "1#INF";
    }
    else if (_Var9 == 2) {
      pcVar11 = "1#QNAN";
    }
    else if (_Var9 == 3) {
      pcVar11 = "1#SNAN";
    }
    else {
      if (_Var9 != 4) {
        param_2 = uVar13 & 0x7fffffff;
        local_788 = (uint **)0x0;
        local_780 = (uint ***)(param_3 + 1);
        uVar23 = CONCAT44(uVar13,iVar14) & 0x7fffffffffffffff;
        local_77c._4_4_ = (uint)(uVar23 >> 0x20);
        uVar13 = local_77c._4_4_ >> 0x14;
        if (uVar13 != 0) {
          iVar16 = 0x100000;
        }
        else {
          iVar16 = 0;
        }
        local_77c._0_4_ = (uint **)uVar23;
        local_760 = (uint ***)(uint **)local_77c;
        uVar21 = (local_77c._4_4_ & 0xfffff) + iVar16;
        local_74c = (uint ***)(uVar13 + (uVar13 == 0));
        param_1 = iVar14;
        local_77c = uVar23;
        FUN_006f25a0();
        FUN_006f26b0();
        local_76c = FUN_006f3c20();
        if ((local_76c == 0x7fffffff) || (local_76c == 0x80000000)) {
          local_76c = 0;
        }
        local_1d4 = (uint **)local_760;
        uVar13 = (uint)(uVar21 != 0);
        local_1d0[0] = (uint *)uVar21;
        local_3a8 = (uint ***)0x0;
        pppuVar17 = (uint ***)(uVar13 + 1);
        local_1d8 = pppuVar17;
        if (local_74c < (uint ***)0x433) {
          local_760 = pppuVar17;
          if (local_74c == (uint ***)&DAT_00000035) {
LAB_006f066d:
            ppuVar20 = (&local_1d4)[uVar13];
            local_77c = local_77c & 0xffffffff;
            iVar14 = 0x1f;
            if (ppuVar20 != (uint **)0x0) {
              for (; (uint)ppuVar20 >> iVar14 == 0; iVar14 = iVar14 + -1) {
              }
            }
            if (ppuVar20 == (uint **)0x0) {
              iVar14 = 0;
            }
            else {
              iVar14 = iVar14 + 1;
            }
            local_75c = (uint **)(&local_1d4 + uVar13);
            pppuVar18 = pppuVar17;
            pppuVar15 = (uint ***)local_75c;
            do {
              if (pppuVar17 < pppuVar18) {
                local_750 = (uint ***)(&local_1d4)[(int)pppuVar17];
              }
              else {
                local_750 = (uint ***)0x0;
              }
              if ((uint ***)((int)pppuVar17 + -1) < pppuVar18) {
                ppuVar20 = *pppuVar15;
              }
              else {
                ppuVar20 = (uint **)0x0;
              }
              pppuVar15 = pppuVar15 + -1;
              (&local_1d4)[(int)pppuVar17] = (uint **)((uint)ppuVar20 >> 0x1f | (int)local_750 * 2);
              pppuVar17 = (uint ***)((int)pppuVar17 + -1);
              pppuVar18 = local_1d8;
            } while (pppuVar17 != (uint ***)0xffffffff);
            if (iVar14 == 0x20) {
              local_1d8 = (uint ***)(uVar13 + 2);
            }
            uVar13 = 0x434 - (int)local_74c;
            uVar21 = uVar13 >> 5;
            _memset(local_574,0,uVar21 * 4);
            local_574[uVar21] = (uint **)(1 << ((byte)uVar13 & 0x1f));
          }
          else {
            local_574[0] = (uint **)0x0;
            local_574[1] = (uint **)0x100000;
            local_578 = (uint ***)0x2;
            if (uVar21 == 0) goto LAB_006f066d;
            iVar14 = 0;
            do {
              if (*(int *)((int)local_574 + iVar14) != *(int *)((int)&local_1d4 + iVar14))
              goto LAB_006f066d;
              iVar14 = iVar14 + 4;
            } while (iVar14 != 8);
            local_77c = local_77c & 0xffffffff;
            iVar14 = 0x1f;
            if (uVar21 != 0) {
              for (; uVar21 >> iVar14 == 0; iVar14 = iVar14 + -1) {
              }
            }
            if (uVar21 == 0) {
              iVar14 = 0;
            }
            else {
              iVar14 = iVar14 + 1;
            }
            local_75c = (uint **)(&local_1d4 + uVar13);
            pppuVar18 = pppuVar17;
            pppuVar15 = (uint ***)local_75c;
            do {
              if (pppuVar17 < pppuVar18) {
                local_750 = (uint ***)(&local_1d4)[(int)pppuVar17];
              }
              else {
                local_750 = (uint ***)0x0;
              }
              if ((uint ***)((int)pppuVar17 + -1) < pppuVar18) {
                ppuVar20 = *pppuVar15;
              }
              else {
                ppuVar20 = (uint **)0x0;
              }
              pppuVar15 = pppuVar15 + -1;
              (&local_1d4)[(int)pppuVar17] = (uint **)((uint)ppuVar20 >> 0x1e | (int)local_750 << 2)
              ;
              pppuVar17 = (uint ***)((int)pppuVar17 + -1);
              pppuVar18 = local_1d8;
            } while (pppuVar17 != (uint ***)0xffffffff);
            if (0x20U - iVar14 < 2) {
              local_1d8 = (uint ***)(uVar13 + 2);
            }
            uVar13 = 0x435 - (int)local_74c;
            uVar21 = uVar13 >> 5;
            _memset(local_574,0,uVar21 * 4);
            local_574[uVar21] = (uint **)(1 << ((byte)uVar13 & 0x1f));
          }
          local_578 = (uint ***)(uVar21 + 1);
          local_3a8 = local_578;
          _memcpy_s(local_3a4,0x1cc,local_574,(int)local_578 * 4);
        }
        else {
          local_574[0] = (uint **)0x0;
          local_574[1] = (uint **)0x100000;
          local_578 = (uint ***)0x2;
          if (uVar21 == 0) {
LAB_006f0391:
            pcVar11 = (char *)((int)local_74c + -0x432);
            local_74c = (uint ***)((uint)pcVar11 & 0x1f);
            pppuVar18 = (uint ***)((uint)pcVar11 >> 5);
            local_760 = (uint ***)(0x20 - (int)local_74c);
            local_754 = pppuVar18;
            iVar14 = __allshl();
            ppuVar20 = (&local_1d4)[uVar13];
            local_774 = (uint ***)(iVar14 + -1);
            local_77c = local_77c & 0xffffffff;
            local_75c = (uint **)~(uint)local_774;
            iVar14 = 0x1f;
            if (ppuVar20 != (uint **)0x0) {
              for (; (uint)ppuVar20 >> iVar14 == 0; iVar14 = iVar14 + -1) {
              }
            }
            if (ppuVar20 == (uint **)0x0) {
              iVar14 = 0;
            }
            else {
              iVar14 = iVar14 + 1;
            }
            local_764 = (uint ***)((int)pppuVar17 + (int)pppuVar18);
            local_758 = (uint ***)(0x20 - iVar14);
            if ((local_764 == (uint ***)0x73) && (local_758 < local_74c)) {
              bVar7 = true;
            }
            else {
              bVar7 = false;
            }
            if (((uint ***)0x73 < local_764) || (bVar7)) {
              local_578 = (uint ***)0x0;
              local_1d8 = (uint ***)0x0;
              _memcpy_s(&local_1d4,0x1cc,local_574,0);
            }
            else {
              if ((uint ***)0x71 < local_764) {
                local_764 = (uint ***)0x72;
              }
              local_768 = local_764;
              if (local_764 != (uint ***)0xffffffff) {
                pppuVar19 = (uint ***)((int)local_764 - (int)local_754);
                pppuVar15 = &local_1d4 + (int)pppuVar19;
                do {
                  pppuVar18 = local_754;
                  if (local_768 < local_754) break;
                  if (pppuVar19 < pppuVar17) {
                    local_750 = (uint ***)*pppuVar15;
                  }
                  else {
                    local_750 = (uint ***)0x0;
                  }
                  if ((uint ***)((int)pppuVar19 + -1) < pppuVar17) {
                    ppuVar20 = pppuVar15[-1];
                  }
                  else {
                    ppuVar20 = (uint **)0x0;
                  }
                  pppuVar15 = pppuVar15 + -1;
                  (&local_1d4)[(int)local_768] =
                       (uint **)(((uint)ppuVar20 & (uint)local_75c) >> ((byte)local_760 & 0x1f) |
                                ((uint)local_750 & (uint)local_774) << ((byte)local_74c & 0x1f));
                  local_768 = (uint ***)((int)local_768 + -1);
                  pppuVar19 = (uint ***)((int)pppuVar19 + -1);
                  pppuVar17 = local_1d8;
                } while (local_768 != (uint ***)0xffffffff);
              }
              if (pppuVar18 != (uint ***)0x0) {
                pppuVar17 = &local_1d4;
                for (; pppuVar18 != (uint ***)0x0; pppuVar18 = (uint ***)((int)pppuVar18 + -1)) {
                  *pppuVar17 = (uint **)0x0;
                  pppuVar17 = pppuVar17 + 1;
                }
              }
              local_1d8 = local_764;
              if (local_758 < local_74c) {
                local_1d8 = (uint ***)((int)local_764 + 1);
              }
            }
            local_574[0] = (uint **)0x2;
          }
          else {
            iVar14 = 0;
            do {
              if (*(int *)((int)local_574 + iVar14) != *(int *)((int)&local_1d4 + iVar14))
              goto LAB_006f0391;
              iVar14 = iVar14 + 4;
            } while (iVar14 != 8);
            pcVar11 = (char *)((int)local_74c + -0x431);
            local_74c = (uint ***)((uint)pcVar11 & 0x1f);
            pppuVar18 = (uint ***)((uint)pcVar11 >> 5);
            local_774 = (uint ***)(0x20 - (int)local_74c);
            local_750 = pppuVar18;
            iVar14 = __allshl();
            ppuVar20 = (&local_1d4)[uVar13];
            local_75c = (uint **)(iVar14 + -1);
            local_77c = local_77c & 0xffffffff;
            local_760 = (uint ***)~(uint)local_75c;
            iVar14 = 0x1f;
            if (ppuVar20 != (uint **)0x0) {
              for (; (uint)ppuVar20 >> iVar14 == 0; iVar14 = iVar14 + -1) {
              }
            }
            if (ppuVar20 == (uint **)0x0) {
              iVar14 = 0;
            }
            else {
              iVar14 = iVar14 + 1;
            }
            local_768 = (uint ***)((int)pppuVar17 + (int)pppuVar18);
            local_758 = (uint ***)(0x20 - iVar14);
            if ((local_768 == (uint ***)0x73) && (local_758 < local_74c)) {
              bVar7 = true;
            }
            else {
              bVar7 = false;
            }
            if (((uint ***)0x73 < local_768) || (bVar7)) {
              local_578 = (uint ***)0x0;
              local_1d8 = (uint ***)0x0;
              _memcpy_s(&local_1d4,0x1cc,local_574,0);
            }
            else {
              if ((uint ***)0x71 < local_768) {
                local_768 = (uint ***)0x72;
              }
              local_764 = local_768;
              if (local_768 != (uint ***)0xffffffff) {
                pppuVar19 = (uint ***)((int)local_768 - (int)local_750);
                pppuVar15 = &local_1d4 + (int)pppuVar19;
                do {
                  pppuVar18 = local_750;
                  if (local_764 < local_750) break;
                  if (pppuVar19 < pppuVar17) {
                    local_754 = (uint ***)*pppuVar15;
                  }
                  else {
                    local_754 = (uint ***)0x0;
                  }
                  if ((uint ***)((int)pppuVar19 + -1) < pppuVar17) {
                    ppuVar20 = pppuVar15[-1];
                  }
                  else {
                    ppuVar20 = (uint **)0x0;
                  }
                  pppuVar15 = pppuVar15 + -1;
                  (&local_1d4)[(int)local_764] =
                       (uint **)(((uint)ppuVar20 & (uint)local_760) >> ((byte)local_774 & 0x1f) |
                                ((uint)local_754 & (uint)local_75c) << ((byte)local_74c & 0x1f));
                  local_764 = (uint ***)((int)local_764 + -1);
                  pppuVar19 = (uint ***)((int)pppuVar19 + -1);
                  pppuVar17 = local_1d8;
                } while (local_764 != (uint ***)0xffffffff);
              }
              if (pppuVar18 != (uint ***)0x0) {
                pppuVar17 = &local_1d4;
                for (; pppuVar18 != (uint ***)0x0; pppuVar18 = (uint ***)((int)pppuVar18 + -1)) {
                  *pppuVar17 = (uint **)0x0;
                  pppuVar17 = pppuVar17 + 1;
                }
              }
              local_1d8 = local_768;
              if (local_758 < local_74c) {
                local_1d8 = (uint ***)((int)local_768 + 1);
              }
            }
            local_574[0] = (uint **)0x4;
          }
          local_3a8 = (uint ***)0x1;
          local_574[1] = (uint **)0x0;
          local_578 = (uint ***)0x1;
          _memcpy_s(local_3a4,0x1cc,local_574,4);
        }
        local_760 = (uint ***)0xa;
        if ((int)local_76c < 0) {
          local_764 = (uint ***)(-local_76c / 10);
          uVar13 = -local_76c % 10;
          local_77c = CONCAT44(uVar13,(uint **)local_77c);
          if (local_764 != (uint ***)0x0) {
            do {
              local_74c = local_764;
              if ((uint ***)0x26 < local_764) {
                local_74c = (uint ***)0x26;
              }
              uVar13 = (uint)(byte)(&DAT_00719c0e)[(int)local_74c * 4];
              bVar2 = (&DAT_00719c0f)[(int)local_74c * 4];
              local_578 = (uint ***)(uVar13 + bVar2);
              _memset(local_574,0,uVar13 * 4);
              FUN_006d2250(local_574 + uVar13,
                           &DAT_00716308 + (uint)*(ushort *)(&UNK_00719c0c + (int)local_74c * 4) * 4
                           ,(uint)bVar2 << 2);
              ppuVar20 = local_1d4;
              if (local_578 < (uint ***)0x2) {
                if (local_574[0] == (uint **)0x0) {
LAB_006f0c76:
                  local_1d8 = (uint ***)0x0;
                  rVar10 = 0;
                  ppuVar20 = local_964;
                  goto LAB_006f0efd;
                }
                if ((local_574[0] == (uint **)0x1) || (local_1d8 == (uint ***)0x0))
                goto LAB_006f0f0e;
                ppuVar20 = (uint **)0x0;
                pppuVar17 = (uint ***)0x0;
                do {
                  lVar6 = ZEXT48(local_574[0]) * ZEXT48((&local_1d4)[(int)pppuVar17]) +
                          ZEXT48(ppuVar20);
                  (&local_1d4)[(int)pppuVar17] = (uint **)lVar6;
                  ppuVar20 = (uint **)((ulonglong)lVar6 >> 0x20);
                  pppuVar17 = (uint ***)((int)pppuVar17 + 1);
                } while (pppuVar17 != local_1d8);
LAB_006f0cce:
                if (ppuVar20 == (uint **)0x0) goto LAB_006f0f0e;
                if (local_1d8 < (uint ***)0x73) {
                  (&local_1d4)[(int)local_1d8] = ppuVar20;
                  local_1d8 = (uint ***)((int)local_1d8 + 1);
                  goto LAB_006f0f0e;
                }
LAB_006f0fac:
                local_1d8 = (uint ***)0x0;
                _memcpy_s(&local_1d4,0x1cc,local_964,0);
                bVar7 = false;
              }
              else {
                if (local_1d8 < (uint ***)0x2) {
                  local_788 = local_1d4;
                  local_1d8 = local_578;
                  _memcpy_s(&local_1d4,0x1cc,local_574,(int)local_578 << 2);
                  if (ppuVar20 != (uint **)0x0) {
                    if ((ppuVar20 != (uint **)0x1) && (local_1d8 != (uint ***)0x0)) {
                      ppuVar20 = (uint **)0x0;
                      pppuVar17 = (uint ***)0x0;
                      do {
                        lVar6 = ZEXT48(local_788) * ZEXT48((&local_1d4)[(int)pppuVar17]) +
                                ZEXT48(ppuVar20);
                        (&local_1d4)[(int)pppuVar17] = (uint **)lVar6;
                        ppuVar20 = (uint **)((ulonglong)lVar6 >> 0x20);
                        pppuVar17 = (uint ***)((int)pppuVar17 + 1);
                      } while (pppuVar17 != local_1d8);
                      goto LAB_006f0cce;
                    }
                    goto LAB_006f0f0e;
                  }
                  goto LAB_006f0c76;
                }
                local_754 = local_574;
                if (local_1d8 <= local_578) {
                  local_754 = &local_1d4;
                }
                local_774 = &local_1d4;
                pppuVar17 = local_1d8;
                local_768 = local_578;
                if (local_1d8 <= local_578) {
                  local_774 = local_574;
                  pppuVar17 = local_578;
                  local_768 = local_1d8;
                }
                local_1d8 = (uint ***)0x0;
                pppuVar18 = (uint ***)0x0;
                local_748 = (uint ***)0x0;
                if (local_768 != (uint ***)0x0) {
                  do {
                    if (local_754[(int)pppuVar18] == (uint **)0x0) {
                      if (pppuVar18 == local_1d8) {
                        local_744[(int)pppuVar18] = (uint *)0x0;
                        local_1d8 = (uint ***)((int)pppuVar18 + 1);
                        local_748 = local_1d8;
                      }
                    }
                    else {
                      local_758 = (uint ***)0x0;
                      local_750 = (uint ***)0x0;
                      pppuVar15 = pppuVar18;
                      if (pppuVar17 != (uint ***)0x0) {
                        do {
                          pppuVar19 = local_750;
                          if (pppuVar15 == (uint ***)0x73) break;
                          if (pppuVar15 == local_1d8) {
                            local_744[(int)pppuVar15] = (uint *)0x0;
                            local_748 = (uint ***)((char *)((int)local_758 + 1) + (int)pppuVar18);
                          }
                          ppuVar3 = local_774[(int)local_758];
                          ppuVar4 = local_754[(int)pppuVar18];
                          uVar13 = (uint)(ZEXT48(ppuVar3) * ZEXT48(ppuVar4));
                          pcVar11 = (char *)((int)local_750 + uVar13);
                          ppuVar20 = local_744 + (int)pppuVar15;
                          puVar1 = *ppuVar20;
                          *ppuVar20 = (uint *)(pcVar11 + (int)*ppuVar20);
                          pppuVar19 = (uint ***)
                                      ((int)(ZEXT48(ppuVar3) * ZEXT48(ppuVar4) >> 0x20) +
                                       (uint)CARRY4(uVar13,(uint)local_750) +
                                      (uint)CARRY4((uint)puVar1,(uint)pcVar11));
                          local_758 = (uint ***)((int)local_758 + 1);
                          pppuVar15 = (uint ***)((int)pppuVar15 + 1);
                          local_1d8 = local_748;
                          local_750 = pppuVar19;
                        } while (local_758 != pppuVar17);
                        do {
                          if (pppuVar19 == (uint ***)0x0) break;
                          if (pppuVar15 == (uint ***)0x73) goto LAB_006f0fac;
                          if (pppuVar15 == local_1d8) {
                            local_744[(int)pppuVar15] = (uint *)0x0;
                            local_748 = (uint ***)((int)pppuVar15 + 1);
                          }
                          ppuVar20 = local_744 + (int)pppuVar15;
                          puVar1 = *ppuVar20;
                          *ppuVar20 = (uint *)((int)pppuVar19 + (int)*ppuVar20);
                          pppuVar19 = (uint ***)(uint)CARRY4((uint)puVar1,(uint)pppuVar19);
                          pppuVar15 = (uint ***)((int)pppuVar15 + 1);
                          local_1d8 = local_748;
                        } while( true );
                      }
                      if (pppuVar15 == (uint ***)0x73) goto LAB_006f0fac;
                    }
                    pppuVar18 = (uint ***)((int)pppuVar18 + 1);
                  } while (pppuVar18 != local_768);
                }
                rVar10 = (int)local_1d8 << 2;
                ppuVar20 = local_744;
LAB_006f0efd:
                _memcpy_s(&local_1d4,0x1cc,ppuVar20,rVar10);
LAB_006f0f0e:
                bVar7 = true;
              }
              if (!bVar7) goto LAB_006f0ffa;
              local_764 = (uint ***)((int)local_764 - (int)local_74c);
            } while (local_764 != (uint ***)0x0);
            uVar13 = local_77c._4_4_;
          }
          if (uVar13 != 0) {
            uVar13 = *(uint *)(&DAT_00716ca4 + uVar13 * 2);
            local_77c = CONCAT44(uVar13,(uint **)local_77c);
            if (uVar13 == 0) {
LAB_006f0ffa:
              local_1d8 = (uint ***)0x0;
              pppuVar17 = &local_1d4;
              goto LAB_006f1007;
            }
            if ((uVar13 != 1) && (local_1d8 != (uint ***)0x0)) {
              ppuVar20 = (uint **)0x0;
              pppuVar17 = (uint ***)0x0;
              do {
                lVar6 = (ulonglong)uVar13 * ZEXT48((&local_1d4)[(int)pppuVar17]) + ZEXT48(ppuVar20);
                (&local_1d4)[(int)pppuVar17] = (uint **)lVar6;
                ppuVar20 = (uint **)((ulonglong)lVar6 >> 0x20);
                pppuVar17 = (uint ***)((int)pppuVar17 + 1);
              } while (pppuVar17 != local_1d8);
              if (ppuVar20 != (uint **)0x0) {
                if ((uint ***)0x72 < local_1d8) goto LAB_006f0ffa;
                (&local_1d4)[(int)local_1d8] = ppuVar20;
                local_1d8 = (uint ***)((int)local_1d8 + 1);
              }
            }
          }
        }
        else {
          local_788 = (uint **)(local_76c % 10);
          for (local_774 = (uint ***)(local_76c / 10); local_774 != (uint ***)0x0;
              local_774 = (uint ***)((int)local_774 - (int)local_754)) {
            local_754 = local_774;
            if ((uint ***)0x26 < local_774) {
              local_754 = (uint ***)0x26;
            }
            uVar13 = (uint)(byte)(&DAT_00719c0e)[(int)local_754 * 4];
            bVar2 = (&DAT_00719c0f)[(int)local_754 * 4];
            local_578 = (uint ***)(uVar13 + bVar2);
            _memset(local_574,0,uVar13 * 4);
            FUN_006d2250(local_574 + uVar13,
                         &DAT_00716308 + (uint)*(ushort *)(&UNK_00719c0c + (int)local_754 * 4) * 4,
                         (uint)bVar2 << 2);
            ppuVar20 = local_3a4[0];
            if (local_578 < (uint ***)0x2) {
              if (local_574[0] == (uint **)0x0) {
                rVar10 = 0;
                local_748 = (uint ***)0x0;
                local_3a8 = (uint ***)0x0;
LAB_006f0ac5:
                pppuVar17 = (uint ***)local_744;
                goto LAB_006f0acc;
              }
              if ((local_574[0] == (uint **)0x1) || (local_3a8 == (uint ***)0x0)) goto LAB_006f0add;
              ppuVar20 = (uint **)0x0;
              pppuVar17 = (uint ***)0x0;
              do {
                lVar6 = ZEXT48(local_574[0]) * ZEXT48(local_3a4[(int)pppuVar17]) + ZEXT48(ppuVar20);
                local_3a4[(int)pppuVar17] = (uint **)lVar6;
                ppuVar20 = (uint **)((ulonglong)lVar6 >> 0x20);
                pppuVar17 = (uint ***)((int)pppuVar17 + 1);
              } while (pppuVar17 != local_3a8);
LAB_006f0922:
              if (ppuVar20 == (uint **)0x0) goto LAB_006f0add;
              if (local_3a8 < (uint ***)0x73) {
                local_3a4[(int)local_3a8] = ppuVar20;
                local_3a8 = (uint ***)((int)local_3a8 + 1);
                goto LAB_006f0add;
              }
              local_578 = (uint ***)0x0;
              pppuVar17 = local_574;
LAB_006f0b40:
              local_3a8 = (uint ***)0x0;
              _memcpy_s(local_3a4,0x1cc,pppuVar17,0);
              bVar7 = false;
            }
            else {
              if ((uint ***)0x1 < local_3a8) {
                local_74c = local_574;
                if (local_3a8 <= local_578) {
                  local_74c = local_3a4;
                }
                local_750 = local_3a4;
                pppuVar17 = local_3a8;
                local_764 = local_578;
                if (local_3a8 <= local_578) {
                  local_750 = local_574;
                  pppuVar17 = local_578;
                  local_764 = local_3a8;
                }
                local_3a8 = (uint ***)0x0;
                pppuVar18 = (uint ***)0x0;
                local_748 = (uint ***)0x0;
                if (local_764 != (uint ***)0x0) {
                  do {
                    if (local_74c[(int)pppuVar18] == (uint **)0x0) {
                      if (pppuVar18 == local_3a8) {
                        local_744[(int)pppuVar18] = (uint *)0x0;
                        local_3a8 = (uint ***)((int)pppuVar18 + 1);
                        local_748 = local_3a8;
                      }
                    }
                    else {
                      local_758 = (uint ***)0x0;
                      local_768 = (uint ***)0x0;
                      pppuVar15 = pppuVar18;
                      if (pppuVar17 != (uint ***)0x0) {
                        do {
                          pppuVar19 = local_768;
                          if (pppuVar15 == (uint ***)0x73) break;
                          if (pppuVar15 == local_3a8) {
                            local_744[(int)pppuVar15] = (uint *)0x0;
                            local_748 = (uint ***)((char *)((int)local_758 + 1) + (int)pppuVar18);
                          }
                          ppuVar3 = local_750[(int)local_758];
                          ppuVar4 = local_74c[(int)pppuVar18];
                          uVar13 = (uint)(ZEXT48(ppuVar3) * ZEXT48(ppuVar4));
                          pcVar11 = (char *)((int)local_768 + uVar13);
                          ppuVar20 = local_744 + (int)pppuVar15;
                          puVar1 = *ppuVar20;
                          *ppuVar20 = (uint *)(pcVar11 + (int)*ppuVar20);
                          pppuVar19 = (uint ***)
                                      ((int)(ZEXT48(ppuVar3) * ZEXT48(ppuVar4) >> 0x20) +
                                       (uint)CARRY4(uVar13,(uint)local_768) +
                                      (uint)CARRY4((uint)puVar1,(uint)pcVar11));
                          local_758 = (uint ***)((int)local_758 + 1);
                          pppuVar15 = (uint ***)((int)pppuVar15 + 1);
                          local_3a8 = local_748;
                          local_768 = pppuVar19;
                        } while (local_758 != pppuVar17);
                        do {
                          if (pppuVar19 == (uint ***)0x0) break;
                          if (pppuVar15 == (uint ***)0x73) goto LAB_006f0b2b;
                          if (pppuVar15 == local_3a8) {
                            local_744[(int)pppuVar15] = (uint *)0x0;
                            local_748 = (uint ***)((int)pppuVar15 + 1);
                          }
                          ppuVar20 = local_744 + (int)pppuVar15;
                          puVar1 = *ppuVar20;
                          *ppuVar20 = (uint *)((int)pppuVar19 + (int)*ppuVar20);
                          pppuVar19 = (uint ***)(uint)CARRY4((uint)puVar1,(uint)pppuVar19);
                          pppuVar15 = (uint ***)((int)pppuVar15 + 1);
                          local_3a8 = local_748;
                        } while( true );
                      }
                      if (pppuVar15 == (uint ***)0x73) {
LAB_006f0b2b:
                        pppuVar17 = (uint ***)local_964;
                        goto LAB_006f0b40;
                      }
                    }
                    pppuVar18 = (uint ***)((int)pppuVar18 + 1);
                  } while (pppuVar18 != local_764);
                }
                rVar10 = (int)local_3a8 << 2;
                goto LAB_006f0ac5;
              }
              local_75c = local_3a4[0];
              local_3a8 = local_578;
              _memcpy_s(local_3a4,0x1cc,local_574,(int)local_578 << 2);
              if ((uint ***)ppuVar20 != (uint ***)0x0) {
                if (((uint ***)ppuVar20 != (uint ***)0x1) && (local_3a8 != (uint ***)0x0)) {
                  ppuVar20 = (uint **)0x0;
                  pppuVar17 = (uint ***)0x0;
                  do {
                    lVar6 = ZEXT48(local_75c) * ZEXT48(local_3a4[(int)pppuVar17]) + ZEXT48(ppuVar20)
                    ;
                    local_3a4[(int)pppuVar17] = (uint **)lVar6;
                    ppuVar20 = (uint **)((ulonglong)lVar6 >> 0x20);
                    pppuVar17 = (uint ***)((int)pppuVar17 + 1);
                  } while (pppuVar17 != local_3a8);
                  goto LAB_006f0922;
                }
                goto LAB_006f0add;
              }
              local_578 = (uint ***)0x0;
              local_3a8 = (uint ***)0x0;
              rVar10 = 0;
              pppuVar17 = local_574;
LAB_006f0acc:
              _memcpy_s(local_3a4,0x1cc,pppuVar17,rVar10);
LAB_006f0add:
              bVar7 = true;
            }
            if (!bVar7) goto LAB_006f0b65;
          }
          if (local_788 != (uint **)0x0) {
            local_788 = *(uint ***)(&DAT_00716ca4 + (int)local_788 * 2);
            if (local_788 == (uint **)0x0) {
LAB_006f0b65:
              local_3a8 = (uint ***)0x0;
              pppuVar17 = local_3a4;
LAB_006f1007:
              _memcpy_s(pppuVar17,0x1cc,local_964,0);
            }
            else if ((local_788 != (uint **)0x1) && (local_3a8 != (uint ***)0x0)) {
              ppuVar20 = (uint **)0x0;
              pppuVar17 = (uint ***)0x0;
              do {
                lVar6 = ZEXT48(local_788) * ZEXT48(local_3a4[(int)pppuVar17]) + ZEXT48(ppuVar20);
                local_3a4[(int)pppuVar17] = (uint **)lVar6;
                ppuVar20 = (uint **)((ulonglong)lVar6 >> 0x20);
                pppuVar17 = (uint ***)((int)pppuVar17 + 1);
              } while (pppuVar17 != local_3a8);
              if (ppuVar20 != (uint **)0x0) {
                if ((uint ***)0x72 < local_3a8) goto LAB_006f0b65;
                local_3a4[(int)local_3a8] = ppuVar20;
                local_3a8 = (uint ***)((int)local_3a8 + 1);
              }
            }
          }
        }
        pppuVar17 = local_770;
        local_754 = local_770;
        if (local_1d8 != (uint ***)0x0) {
          ppuVar20 = (uint **)0x0;
          pppuVar18 = (uint ***)0x0;
          do {
            lVar6 = ZEXT48((&local_1d4)[(int)pppuVar18]) * 10 + ZEXT48(ppuVar20);
            (&local_1d4)[(int)pppuVar18] = (uint **)lVar6;
            ppuVar20 = (uint **)((ulonglong)lVar6 >> 0x20);
            pppuVar18 = (uint ***)((int)pppuVar18 + 1);
          } while (pppuVar18 != local_1d8);
          local_77c = CONCAT44(ppuVar20,(uint **)local_77c);
          if (ppuVar20 != (uint **)0x0) {
            if (local_1d8 < (uint ***)0x73) {
              (&local_1d4)[(int)local_1d8] = ppuVar20;
              local_1d8 = (uint ***)((int)local_1d8 + 1);
            }
            else {
              local_1d8 = (uint ***)0x0;
              _memcpy_s(&local_1d4,0x1cc,local_964,0);
            }
          }
        }
        _Var22 = __crt_strtox::divide((big_integer *)&local_1d8,(big_integer *)&local_3a8);
        if ((int)_Var22 == 10) {
          local_76c = local_76c + 1;
          local_754 = (uint ***)((int)pppuVar17 + 1);
          *(char *)pppuVar17 = '1';
          if (local_3a8 != (uint ***)0x0) {
            ppuVar20 = (uint **)0x0;
            pppuVar18 = (uint ***)0x0;
            do {
              lVar6 = ZEXT48(local_3a4[(int)pppuVar18]) * 10 + ZEXT48(ppuVar20);
              local_3a4[(int)pppuVar18] = (uint **)lVar6;
              ppuVar20 = (uint **)((ulonglong)lVar6 >> 0x20);
              pppuVar18 = (uint ***)((int)pppuVar18 + 1);
            } while (pppuVar18 != local_3a8);
            if (ppuVar20 != (uint **)0x0) {
              if (local_3a8 < (uint ***)0x73) {
                local_3a4[(int)local_3a8] = ppuVar20;
                local_3a8 = (uint ***)((int)local_3a8 + 1);
              }
              else {
                local_3a8 = (uint ***)0x0;
                _memcpy_s(local_3a4,0x1cc,local_964,0);
              }
            }
          }
LAB_006f116d:
          pppuVar17 = (uint ***)((int)pppuVar17 + 1);
          uVar13 = local_76c;
        }
        else {
          if ((int)_Var22 != 0) {
            *(char *)pppuVar17 = (char)_Var22 + '0';
            goto LAB_006f116d;
          }
          uVar13 = local_76c - 1;
        }
        local_784[1] = uVar13;
        if ((-1 < (int)uVar13) && (local_780 < 0x80000000)) {
          local_780 = (uint ***)((int)local_780 + uVar13);
        }
        uVar13 = param_6 - 1;
        if (local_780 <= param_6 - 1) {
          uVar13 = (uint)local_780;
        }
        local_780 = (uint ***)((int)local_770 + uVar13);
        if (pppuVar17 != local_780) {
          do {
            if (local_1d8 == (uint ***)0x0) break;
            ppuVar20 = (uint **)0x0;
            pppuVar18 = (uint ***)0x0;
            do {
              lVar6 = ZEXT48((&local_1d4)[(int)pppuVar18]) * 1000000000 + ZEXT48(ppuVar20);
              (&local_1d4)[(int)pppuVar18] = (uint **)lVar6;
              ppuVar20 = (uint **)((ulonglong)lVar6 >> 0x20);
              pppuVar18 = (uint ***)((int)pppuVar18 + 1);
            } while (pppuVar18 != local_1d8);
            if (ppuVar20 != (uint **)0x0) {
              if (local_1d8 < (uint ***)0x73) {
                (&local_1d4)[(int)local_1d8] = ppuVar20;
                local_1d8 = (uint ***)((int)local_1d8 + 1);
              }
              else {
                local_1d8 = (uint ***)0x0;
                _memcpy_s(&local_1d4,0x1cc,local_964,0);
              }
            }
            uVar23 = __crt_strtox::divide((big_integer *)&local_1d8,(big_integer *)&local_3a8);
            uVar21 = 8;
            uVar13 = (int)local_780 - (int)pppuVar17;
            do {
              uVar5 = uVar23 & 0xffffffff;
              uVar23 = uVar5 / ZEXT48(local_760);
              if (uVar21 <= uVar13) {
                *(char *)((int)pppuVar17 + uVar21) = (char)(uVar5 % ZEXT48(local_760)) + '0';
              }
              uVar21 = uVar21 - 1;
            } while (uVar21 != 0xffffffff);
            if (9 < uVar13) {
              uVar13 = 9;
            }
            pppuVar17 = (uint ***)((int)pppuVar17 + uVar13);
          } while (pppuVar17 != local_780);
        }
        *(char *)pppuVar17 = '\0';
        goto LAB_006f127d;
      }
      pcVar11 = "1#IND";
    }
  }
  eVar12 = _strcpy_s((char *)local_770,param_6,pcVar11);
  if (eVar12 != 0) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
LAB_006f127d:
  if (local_790 != '\0') {
    fesetenv(local_798);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

