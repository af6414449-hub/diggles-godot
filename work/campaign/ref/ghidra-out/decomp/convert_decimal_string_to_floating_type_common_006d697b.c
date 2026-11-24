
/* Library Function - Single Match
    enum SLD_STATUS __cdecl __crt_strtox::convert_decimal_string_to_floating_type_common(struct
   __crt_strtox::floating_point_string const &,class __crt_strtox::floating_point_value const &)
   
   Library: Visual Studio 2019 Release */

SLD_STATUS __cdecl
__crt_strtox::convert_decimal_string_to_floating_type_common
          (floating_point_string *param_1,floating_point_value *param_2)

{
  byte bVar1;
  floating_point_string fVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  SLD_STATUS SVar6;
  uint uVar7;
  uint uVar8;
  floating_point_string *pfVar9;
  floating_point_string *pfVar10;
  uint uVar11;
  floating_point_string *pfVar12;
  floating_point_string *pfVar13;
  floating_point_string *pfVar14;
  uint *puVar15;
  bool bVar16;
  __uint64 _Var17;
  longlong lVar18;
  rsize_t _MaxCount;
  uint local_b2c [115];
  uint local_960;
  floating_point_string *local_95c;
  floating_point_string *local_958;
  floating_point_value *local_954;
  floating_point_string *local_950;
  floating_point_string *local_94c;
  floating_point_string *local_948;
  floating_point_string *local_944;
  floating_point_string *local_940;
  floating_point_string *local_93c;
  floating_point_string *local_938;
  floating_point_string *local_934;
  floating_point_string *local_930;
  floating_point_string *local_92c;
  floating_point_string *local_928;
  floating_point_string *local_924;
  floating_point_string *local_920;
  floating_point_string *local_91c;
  floating_point_string *local_918;
  uint local_914 [115];
  floating_point_string *local_748;
  uint local_744 [115];
  floating_point_string *local_578;
  uint local_574 [115];
  floating_point_string *local_3a8;
  uint local_3a4 [115];
  floating_point_string *local_1d8;
  uint local_1d4 [115];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  uVar11 = *(uint *)param_1;
  local_94c = param_1;
  local_954 = param_2;
  local_950 = (floating_point_string *)
              (((param_2[4] == (floating_point_value)0x0) - 1 & 0x1d) + 0x19);
  if ((int)uVar11 < 0) {
    uVar11 = 0;
  }
  uVar8 = *(uint *)(param_1 + 4);
  uVar7 = uVar11;
  if (uVar8 <= uVar11) {
    uVar7 = uVar8;
  }
  local_93c = (floating_point_string *)(uVar11 - uVar7);
  pfVar14 = param_1 + 8;
  local_958 = param_1 + uVar7 + 8;
  local_95c = param_1 + uVar8 + 8;
  pfVar12 = (floating_point_string *)0x0;
  local_920 = local_95c + -(int)local_958;
  local_91c = (floating_point_string *)0x0;
  uVar11 = 0;
  local_1d8 = (floating_point_string *)0x0;
  local_924 = (floating_point_string *)0x0;
  local_940 = pfVar14;
  if (pfVar14 != local_958) {
    do {
      if (uVar11 == 9) {
        local_940 = pfVar14;
        if (pfVar12 != (floating_point_string *)0x0) {
          uVar11 = 0;
          pfVar13 = (floating_point_string *)0x0;
          do {
            lVar18 = (ulonglong)local_1d4[(int)pfVar13] * 1000000000 + (ulonglong)uVar11;
            local_1d4[(int)pfVar13] = (uint)lVar18;
            uVar11 = (uint)((ulonglong)lVar18 >> 0x20);
            pfVar13 = pfVar13 + 1;
          } while (pfVar13 != pfVar12);
          pfVar12 = local_1d8;
          if (uVar11 != 0) {
            if (local_1d8 < (floating_point_string *)0x73) {
              local_1d4[(int)local_1d8] = uVar11;
              local_1d8 = local_1d8 + 1;
              pfVar12 = local_1d8;
            }
            else {
              local_918 = (floating_point_string *)0x0;
              local_1d8 = (floating_point_string *)0x0;
              _memcpy_s(local_1d4,0x1cc,local_914,0);
              pfVar12 = local_1d8;
            }
          }
        }
        if (local_924 != (floating_point_string *)0x0) {
          pfVar9 = (floating_point_string *)0x0;
          pfVar13 = local_924;
          if (pfVar12 != (floating_point_string *)0x0) {
            do {
              puVar15 = local_1d4 + (int)pfVar9;
              uVar11 = *puVar15;
              *puVar15 = (uint)(pfVar13 + *puVar15);
              pfVar13 = (floating_point_string *)(uint)CARRY4(uVar11,(uint)pfVar13);
              pfVar9 = pfVar9 + 1;
              pfVar12 = local_1d8;
            } while (pfVar9 != local_1d8);
          }
          if (pfVar13 != (floating_point_string *)0x0) {
            if (pfVar12 < (floating_point_string *)0x73) {
              local_1d4[(int)pfVar12] = (uint)pfVar13;
              local_1d8 = local_1d8 + 1;
              pfVar12 = local_1d8;
            }
            else {
              local_918 = (floating_point_string *)0x0;
              local_1d8 = (floating_point_string *)0x0;
              _memcpy_s(local_1d4,0x1cc,local_914,0);
              pfVar12 = local_1d8;
            }
          }
        }
        local_924 = (floating_point_string *)0x0;
        uVar11 = 0;
      }
      local_924 = (floating_point_string *)((int)local_924 * 10 + (uint)(byte)*pfVar14);
      uVar11 = uVar11 + 1;
      pfVar14 = pfVar14 + 1;
    } while (pfVar14 != local_958);
    local_940 = pfVar14;
    local_91c = pfVar12;
    if (uVar11 != 0) {
      local_938 = (floating_point_string *)(uVar11 % 10);
      for (local_934 = (floating_point_string *)(uVar11 / 10); local_91c = pfVar12,
          local_934 != (floating_point_string *)0x0; local_934 = local_934 + -(int)local_92c) {
        local_92c = local_934;
        if ((floating_point_string *)0x26 < local_934) {
          local_92c = (floating_point_string *)0x26;
        }
        uVar11 = (uint)(byte)(&DAT_00716c0e)[(int)local_92c * 4];
        bVar1 = (&DAT_00716c0f)[(int)local_92c * 4];
        local_918 = (floating_point_string *)(bVar1 + uVar11);
        _memset(local_914,0,uVar11 * 4);
        FUN_006d2250(local_914 + uVar11,
                     &DAT_00716308 + (uint)*(ushort *)(&DAT_00716c0c + (int)local_92c * 4) * 4,
                     (uint)bVar1 << 2);
        uVar11 = local_1d4[0];
        if (local_918 < (floating_point_string *)0x2) {
          if (local_914[0] == 0) {
            local_578 = (floating_point_string *)0x0;
            puVar15 = local_574;
LAB_006d6c1a:
            local_1d8 = (floating_point_string *)0x0;
            _memcpy_s(local_1d4,0x1cc,puVar15,0);
          }
          else {
            if ((local_914[0] == 1) || (pfVar12 == (floating_point_string *)0x0)) {
              bVar16 = true;
              goto LAB_006d6ef6;
            }
            uVar11 = 0;
            pfVar14 = (floating_point_string *)0x0;
            do {
              lVar18 = (ulonglong)local_914[0] * (ulonglong)local_1d4[(int)pfVar14] +
                       (ulonglong)uVar11;
              local_1d4[(int)pfVar14] = (uint)lVar18;
              uVar11 = (uint)((ulonglong)lVar18 >> 0x20);
              pfVar14 = pfVar14 + 1;
            } while (pfVar14 != pfVar12);
            if (uVar11 != 0) {
              if ((floating_point_string *)0x72 < local_1d8) {
LAB_006d6c93:
                local_918 = (floating_point_string *)0x0;
                local_1d8 = (floating_point_string *)0x0;
                _memcpy_s(local_1d4,0x1cc,local_914,0);
                bVar16 = false;
                local_91c = local_1d8;
                goto LAB_006d6ef6;
              }
              local_1d4[(int)local_1d8] = uVar11;
LAB_006d6c84:
              local_1d8 = local_1d8 + 1;
            }
          }
LAB_006d6c2f:
          bVar16 = true;
          local_91c = local_1d8;
        }
        else if (pfVar12 < (floating_point_string *)0x2) {
          local_1d8 = local_918;
          _memcpy_s(local_1d4,0x1cc,local_914,(int)local_918 << 2);
          if (uVar11 == 0) {
            local_918 = (floating_point_string *)0x0;
            puVar15 = local_914;
            goto LAB_006d6c1a;
          }
          bVar16 = true;
          local_91c = local_1d8;
          if ((uVar11 != 1) && (local_1d8 != (floating_point_string *)0x0)) {
            uVar8 = 0;
            pfVar14 = (floating_point_string *)0x0;
            do {
              lVar18 = (ulonglong)uVar11 * (ulonglong)local_1d4[(int)pfVar14] + (ulonglong)uVar8;
              local_1d4[(int)pfVar14] = (uint)lVar18;
              uVar8 = (uint)((ulonglong)lVar18 >> 0x20);
              pfVar14 = pfVar14 + 1;
            } while (pfVar14 != local_1d8);
            if (uVar8 != 0) {
              if ((floating_point_string *)0x72 < local_1d8) goto LAB_006d6c93;
              local_1d4[(int)local_1d8] = uVar8;
              goto LAB_006d6c84;
            }
            goto LAB_006d6c2f;
          }
        }
        else {
          local_91c = (floating_point_string *)local_914;
          if (pfVar12 <= local_918) {
            local_91c = (floating_point_string *)local_1d4;
          }
          local_940 = (floating_point_string *)local_1d4;
          pfVar14 = pfVar12;
          local_930 = local_918;
          if (pfVar12 <= local_918) {
            local_940 = (floating_point_string *)local_914;
            pfVar14 = local_918;
            local_930 = pfVar12;
          }
          local_1d8 = (floating_point_string *)0x0;
          pfVar12 = (floating_point_string *)0x0;
          local_578 = (floating_point_string *)0x0;
          if (local_930 != (floating_point_string *)0x0) {
            do {
              if (*(uint *)((int)local_91c + pfVar12 * 4) == 0) {
                if (pfVar12 == local_1d8) {
                  local_574[(int)pfVar12] = 0;
                  local_1d8 = pfVar12 + 1;
                  local_578 = local_1d8;
                }
              }
              else {
                pfVar9 = (floating_point_string *)0x0;
                local_928 = (floating_point_string *)0x0;
                pfVar13 = pfVar12;
                if (pfVar14 != (floating_point_string *)0x0) {
                  do {
                    pfVar10 = local_928;
                    if (pfVar13 == (floating_point_string *)0x73) break;
                    if (pfVar13 == local_1d8) {
                      local_574[(int)pfVar13] = 0;
                      local_578 = pfVar12 + 1 + (int)pfVar9;
                    }
                    uVar11 = *(uint *)(local_940 + (int)pfVar9 * 4);
                    uVar8 = *(uint *)((int)local_91c + pfVar12 * 4);
                    uVar3 = (uint)((ulonglong)uVar11 * (ulonglong)uVar8);
                    uVar7 = local_574[(int)pfVar13];
                    uVar4 = uVar3 + local_574[(int)pfVar13];
                    local_574[(int)pfVar13] = (uint)(local_928 + uVar4);
                    pfVar10 = (floating_point_string *)
                              ((int)((ulonglong)uVar11 * (ulonglong)uVar8 >> 0x20) +
                               (uint)CARRY4(uVar3,uVar7) + (uint)CARRY4(uVar4,(uint)local_928));
                    pfVar9 = pfVar9 + 1;
                    pfVar13 = pfVar13 + 1;
                    local_1d8 = local_578;
                    local_928 = pfVar10;
                  } while (pfVar9 != pfVar14);
                  do {
                    if (pfVar10 == (floating_point_string *)0x0) break;
                    if (pfVar13 == (floating_point_string *)0x73) goto LAB_006d6f67;
                    if (pfVar13 == local_1d8) {
                      local_574[(int)pfVar13] = 0;
                      local_578 = pfVar13 + 1;
                    }
                    puVar15 = local_574 + (int)pfVar13;
                    uVar11 = *puVar15;
                    *puVar15 = (uint)(pfVar10 + *puVar15);
                    pfVar10 = (floating_point_string *)(uint)CARRY4(uVar11,(uint)pfVar10);
                    pfVar13 = pfVar13 + 1;
                    local_1d8 = local_578;
                  } while( true );
                }
                if (pfVar13 == (floating_point_string *)0x73) {
LAB_006d6f67:
                  local_1d8 = (floating_point_string *)0x0;
                  _memcpy_s(local_1d4,0x1cc,local_b2c,0);
                  bVar16 = false;
                  goto LAB_006d6ee7;
                }
              }
              pfVar12 = pfVar12 + 1;
            } while (pfVar12 != local_930);
          }
          _memcpy_s(local_1d4,0x1cc,local_574,(int)local_1d8 << 2);
          bVar16 = true;
LAB_006d6ee7:
          local_91c = local_1d8;
        }
LAB_006d6ef6:
        if (!bVar16) goto LAB_006d6f2b;
        pfVar12 = local_91c;
      }
      if (local_938 != (floating_point_string *)0x0) {
        uVar11 = *(uint *)(&DAT_00716ca4 + (int)local_938 * 2);
        if (uVar11 == 0) {
LAB_006d6f2b:
          local_1d8 = (floating_point_string *)0x0;
          _memcpy_s(local_1d4,0x1cc,local_b2c,0);
LAB_006d6f56:
          local_91c = local_1d8;
        }
        else if ((uVar11 != 1) && (pfVar12 != (floating_point_string *)0x0)) {
          uVar8 = 0;
          pfVar14 = (floating_point_string *)0x0;
          do {
            lVar18 = (ulonglong)uVar11 * (ulonglong)local_1d4[(int)pfVar14] + (ulonglong)uVar8;
            local_1d4[(int)pfVar14] = (uint)lVar18;
            uVar8 = (uint)((ulonglong)lVar18 >> 0x20);
            pfVar14 = pfVar14 + 1;
          } while (pfVar14 != pfVar12);
          if (uVar8 == 0) goto LAB_006d6f56;
          if ((floating_point_string *)0x72 < local_1d8) goto LAB_006d6f2b;
          local_1d4[(int)local_1d8] = uVar8;
          local_1d8 = local_1d8 + 1;
          local_91c = local_1d8;
        }
      }
      if (local_924 != (floating_point_string *)0x0) {
        pfVar12 = (floating_point_string *)0x0;
        pfVar14 = local_924;
        if (local_91c != (floating_point_string *)0x0) {
          do {
            puVar15 = local_1d4 + (int)pfVar12;
            uVar11 = *puVar15;
            *puVar15 = (uint)(pfVar14 + *puVar15);
            pfVar14 = (floating_point_string *)(uint)CARRY4(uVar11,(uint)pfVar14);
            local_91c = local_1d8;
            pfVar12 = pfVar12 + 1;
          } while (pfVar12 != local_1d8);
        }
        if (pfVar14 != (floating_point_string *)0x0) {
          if (local_91c < (floating_point_string *)0x73) {
            local_1d4[(int)local_91c] = (uint)pfVar14;
            local_1d8 = local_1d8 + 1;
            local_91c = local_1d8;
          }
          else {
            local_1d8 = (floating_point_string *)0x0;
            _memcpy_s(local_1d4,0x1cc,local_b2c,0);
            local_91c = local_1d8;
          }
        }
      }
    }
  }
  if (local_93c == (floating_point_string *)0x0) {
LAB_006d749e:
    if (local_91c == (floating_point_string *)0x0) goto LAB_006d74a6;
    uVar11 = local_1d4[(int)(local_91c + -1)];
    local_948 = (floating_point_string *)0x0;
    iVar5 = 0x1f;
    if (uVar11 != 0) {
      for (; uVar11 >> iVar5 == 0; iVar5 = iVar5 + -1) {
      }
    }
    if (uVar11 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar5 + 1;
    }
    local_940 = (floating_point_string *)((int)(local_91c + -1) * 0x20 + iVar5);
  }
  else {
    local_938 = (floating_point_string *)((uint)local_93c % 10);
    pfVar14 = local_91c;
    for (local_928 = (floating_point_string *)((uint)local_93c / 10); local_91c = pfVar14,
        local_928 != (floating_point_string *)0x0; local_928 = local_928 + -(int)local_924) {
      local_924 = local_928;
      if ((floating_point_string *)0x26 < local_928) {
        local_924 = (floating_point_string *)0x26;
      }
      uVar11 = (uint)(byte)(&DAT_00716c0e)[(int)local_924 * 4];
      bVar1 = (&DAT_00716c0f)[(int)local_924 * 4];
      local_918 = (floating_point_string *)(uVar11 + bVar1);
      _memset(local_914,0,uVar11 * 4);
      FUN_006d2250(local_914 + uVar11,
                   &DAT_00716308 + (uint)*(ushort *)(&DAT_00716c0c + (int)local_924 * 4) * 4,
                   (uint)bVar1 << 2);
      uVar11 = local_1d4[0];
      if (local_918 < (floating_point_string *)0x2) {
        if (local_914[0] == 0) {
LAB_006d7156:
          local_1d8 = (floating_point_string *)0x0;
          _memcpy_s(local_1d4,0x1cc,local_b2c,0);
        }
        else {
          if ((local_914[0] == 1) || (pfVar14 == (floating_point_string *)0x0)) {
            bVar16 = true;
            goto LAB_006d742f;
          }
          uVar11 = 0;
          pfVar12 = (floating_point_string *)0x0;
          do {
            lVar18 = (ulonglong)local_914[0] * (ulonglong)local_1d4[(int)pfVar12] +
                     (ulonglong)uVar11;
            local_1d4[(int)pfVar12] = (uint)lVar18;
            uVar11 = (uint)((ulonglong)lVar18 >> 0x20);
            pfVar12 = pfVar12 + 1;
          } while (pfVar12 != pfVar14);
          if (uVar11 != 0) {
            if ((floating_point_string *)0x72 < local_1d8) {
LAB_006d71cf:
              local_1d8 = (floating_point_string *)0x0;
              _memcpy_s(local_1d4,0x1cc,local_b2c,0);
              bVar16 = false;
              local_91c = local_1d8;
              goto LAB_006d742f;
            }
            local_1d4[(int)local_1d8] = uVar11;
LAB_006d71c0:
            local_1d8 = local_1d8 + 1;
          }
        }
LAB_006d716b:
        bVar16 = true;
        local_91c = local_1d8;
      }
      else if (pfVar14 < (floating_point_string *)0x2) {
        local_1d8 = local_918;
        _memcpy_s(local_1d4,0x1cc,local_914,(int)local_918 << 2);
        if (uVar11 == 0) goto LAB_006d7156;
        bVar16 = true;
        local_91c = local_1d8;
        if ((uVar11 != 1) && (local_1d8 != (floating_point_string *)0x0)) {
          uVar8 = 0;
          pfVar14 = (floating_point_string *)0x0;
          do {
            lVar18 = (ulonglong)uVar11 * (ulonglong)local_1d4[(int)pfVar14] + (ulonglong)uVar8;
            local_1d4[(int)pfVar14] = (uint)lVar18;
            uVar8 = (uint)((ulonglong)lVar18 >> 0x20);
            pfVar14 = pfVar14 + 1;
          } while (pfVar14 != local_1d8);
          if (uVar8 != 0) {
            if ((floating_point_string *)0x72 < local_1d8) goto LAB_006d71cf;
            local_1d4[(int)local_1d8] = uVar8;
            goto LAB_006d71c0;
          }
          goto LAB_006d716b;
        }
      }
      else {
        local_92c = (floating_point_string *)local_914;
        if (pfVar14 <= local_918) {
          local_92c = (floating_point_string *)local_1d4;
        }
        local_934 = (floating_point_string *)local_1d4;
        pfVar12 = pfVar14;
        local_940 = local_918;
        if (pfVar14 <= local_918) {
          local_934 = (floating_point_string *)local_914;
          pfVar12 = local_918;
          local_940 = pfVar14;
        }
        local_1d8 = (floating_point_string *)0x0;
        pfVar14 = (floating_point_string *)0x0;
        local_578 = (floating_point_string *)0x0;
        if (local_940 != (floating_point_string *)0x0) {
          do {
            if (*(int *)(local_92c + (int)pfVar14 * 4) == 0) {
              if (pfVar14 == local_1d8) {
                local_574[(int)pfVar14] = 0;
                local_1d8 = pfVar14 + 1;
                local_578 = local_1d8;
              }
            }
            else {
              uVar11 = 0;
              local_930 = (floating_point_string *)0x0;
              pfVar13 = pfVar14;
              if (pfVar12 != (floating_point_string *)0x0) {
                do {
                  if (pfVar13 == (floating_point_string *)0x73) break;
                  if (pfVar13 == local_1d8) {
                    local_574[(int)pfVar13] = 0;
                    local_578 = pfVar14 + 1 + (int)local_930;
                  }
                  lVar18 = (ulonglong)*(uint *)(local_934 + (int)local_930 * 4) *
                           (ulonglong)*(uint *)(local_92c + (int)pfVar14 * 4) + (ulonglong)uVar11;
                  uVar8 = (uint)lVar18;
                  puVar15 = local_574 + (int)pfVar13;
                  uVar11 = *puVar15;
                  *puVar15 = *puVar15 + uVar8;
                  uVar11 = (int)((ulonglong)lVar18 >> 0x20) + (uint)CARRY4(uVar11,uVar8);
                  local_930 = local_930 + 1;
                  pfVar13 = pfVar13 + 1;
                  local_1d8 = local_578;
                } while (local_930 != pfVar12);
                do {
                  if (uVar11 == 0) break;
                  if (pfVar13 == (floating_point_string *)0x73) goto LAB_006d74ad;
                  if (pfVar13 == local_1d8) {
                    local_574[(int)pfVar13] = 0;
                    local_578 = pfVar13 + 1;
                  }
                  puVar15 = local_574 + (int)pfVar13;
                  uVar8 = *puVar15;
                  *puVar15 = *puVar15 + uVar11;
                  uVar11 = (uint)CARRY4(uVar8,uVar11);
                  pfVar13 = pfVar13 + 1;
                  local_1d8 = local_578;
                } while( true );
              }
              if (pfVar13 == (floating_point_string *)0x73) {
LAB_006d74ad:
                local_1d8 = (floating_point_string *)0x0;
                _memcpy_s(local_1d4,0x1cc,local_b2c,0);
                bVar16 = false;
                goto LAB_006d7423;
              }
            }
            pfVar14 = pfVar14 + 1;
          } while (pfVar14 != local_940);
        }
        _memcpy_s(local_1d4,0x1cc,local_574,(int)local_1d8 << 2);
        bVar16 = true;
LAB_006d7423:
        local_91c = local_1d8;
      }
LAB_006d742f:
      if (!bVar16) goto LAB_006d7554;
      pfVar14 = local_91c;
    }
    if (local_938 == (floating_point_string *)0x0) goto LAB_006d749e;
    uVar11 = *(uint *)(&DAT_00716ca4 + (int)local_938 * 2);
    if (uVar11 == 0) {
      local_1d8 = (floating_point_string *)0x0;
      _memcpy_s(local_1d4,0x1cc,local_b2c,0);
      local_91c = local_1d8;
      goto LAB_006d749e;
    }
    if (uVar11 == 1) goto LAB_006d749e;
    if (pfVar14 != (floating_point_string *)0x0) {
      uVar8 = 0;
      pfVar12 = (floating_point_string *)0x0;
      do {
        lVar18 = (ulonglong)uVar11 * (ulonglong)local_1d4[(int)pfVar12] + (ulonglong)uVar8;
        local_1d4[(int)pfVar12] = (uint)lVar18;
        uVar8 = (uint)((ulonglong)lVar18 >> 0x20);
        pfVar12 = pfVar12 + 1;
      } while (pfVar12 != pfVar14);
      local_91c = local_1d8;
      if (uVar8 != 0) {
        local_91c = pfVar14;
        if ((floating_point_string *)0x72 < local_1d8) {
LAB_006d7554:
          local_1d8 = (floating_point_string *)0x0;
          _memcpy_s(local_1d4,0x1cc,local_b2c,0);
          assemble_floating_point_infinity((bool)local_94c[0x308],local_954);
          goto LAB_006d86ab;
        }
        local_1d4[(int)local_1d8] = uVar8;
        local_1d8 = local_1d8 + 1;
        local_91c = local_1d8;
      }
      goto LAB_006d749e;
    }
LAB_006d74a6:
    local_940 = (floating_point_string *)0x0;
  }
  if ((local_950 <= local_940) || (local_920 == (floating_point_string *)0x0)) {
    bVar16 = local_95c != local_958;
    fVar2 = local_94c[0x308];
LAB_006d869c:
    assemble_floating_point_value_from_big_integer
              ((big_integer *)&local_1d8,(uint)local_940,(bool)fVar2,bVar16,local_954);
    goto LAB_006d86ab;
  }
  pfVar14 = (floating_point_string *)0x0;
  local_3a8 = (floating_point_string *)0x0;
  uVar11 = 0;
  local_928 = (floating_point_string *)0x0;
  local_924 = local_958;
  pfVar12 = local_958;
  if (local_958 != local_95c) {
    do {
      pfVar13 = local_928;
      if (uVar11 == 9) {
        local_924 = pfVar12;
        if (pfVar14 != (floating_point_string *)0x0) {
          uVar11 = 0;
          pfVar12 = (floating_point_string *)0x0;
          do {
            lVar18 = (ulonglong)local_3a4[(int)pfVar12] * 1000000000 + (ulonglong)uVar11;
            local_3a4[(int)pfVar12] = (uint)lVar18;
            uVar11 = (uint)((ulonglong)lVar18 >> 0x20);
            pfVar12 = pfVar12 + 1;
          } while (pfVar12 != pfVar14);
          pfVar14 = local_3a8;
          if (uVar11 != 0) {
            if (local_3a8 < (floating_point_string *)0x73) {
              local_3a4[(int)local_3a8] = uVar11;
              local_3a8 = local_3a8 + 1;
              pfVar14 = local_3a8;
            }
            else {
              local_3a8 = (floating_point_string *)0x0;
              _memcpy_s(local_3a4,0x1cc,local_b2c,0);
              pfVar14 = local_3a8;
            }
          }
        }
        pfVar12 = local_924;
        if (pfVar13 != (floating_point_string *)0x0) {
          pfVar9 = (floating_point_string *)0x0;
          if (pfVar14 != (floating_point_string *)0x0) {
            do {
              puVar15 = local_3a4 + (int)pfVar9;
              uVar11 = *puVar15;
              *puVar15 = (uint)(pfVar13 + *puVar15);
              pfVar13 = (floating_point_string *)(uint)CARRY4(uVar11,(uint)pfVar13);
              pfVar9 = pfVar9 + 1;
              pfVar14 = local_3a8;
            } while (pfVar9 != local_3a8);
          }
          if (pfVar13 != (floating_point_string *)0x0) {
            if (pfVar14 < (floating_point_string *)0x73) {
              local_3a4[(int)pfVar14] = (uint)pfVar13;
              local_3a8 = local_3a8 + 1;
              pfVar14 = local_3a8;
            }
            else {
              local_3a8 = (floating_point_string *)0x0;
              _memcpy_s(local_3a4,0x1cc,local_b2c,0);
              pfVar14 = local_3a8;
            }
          }
        }
        local_928 = (floating_point_string *)0x0;
        uVar11 = 0;
      }
      local_928 = (floating_point_string *)((int)local_928 * 10 + (uint)(byte)*pfVar12);
      uVar11 = uVar11 + 1;
      pfVar12 = pfVar12 + 1;
    } while (pfVar12 != local_95c);
    local_924 = pfVar12;
    if (uVar11 != 0) {
      local_944 = (floating_point_string *)(uVar11 % 10);
      for (local_938 = (floating_point_string *)(uVar11 / 10);
          local_938 != (floating_point_string *)0x0; local_938 = local_938 + -(int)local_924) {
        local_924 = local_938;
        if ((floating_point_string *)0x26 < local_938) {
          local_924 = (floating_point_string *)0x26;
        }
        uVar11 = (uint)(byte)(&DAT_00716c0e)[(int)local_924 * 4];
        bVar1 = (&DAT_00716c0f)[(int)local_924 * 4];
        local_918 = (floating_point_string *)(uVar11 + bVar1);
        _memset(local_914,0,uVar11 * 4);
        FUN_006d2250(local_914 + uVar11,
                     &DAT_00716308 + (uint)*(ushort *)(&DAT_00716c0c + (int)local_924 * 4) * 4,
                     (uint)bVar1 << 2);
        uVar11 = local_3a4[0];
        if (local_918 < (floating_point_string *)0x2) {
          if (local_914[0] == 0) {
            local_3a8 = (floating_point_string *)0x0;
            _MaxCount = 0;
            puVar15 = local_b2c;
            goto LAB_006d7a68;
          }
          if ((local_914[0] == 1) || (pfVar14 == (floating_point_string *)0x0)) {
            bVar16 = true;
          }
          else {
            uVar8 = 0;
            pfVar12 = (floating_point_string *)0x0;
            do {
              lVar18 = (ulonglong)local_914[0] * (ulonglong)local_3a4[(int)pfVar12] +
                       (ulonglong)uVar8;
              local_3a4[(int)pfVar12] = (uint)lVar18;
              uVar8 = (uint)((ulonglong)lVar18 >> 0x20);
              pfVar12 = pfVar12 + 1;
            } while (pfVar12 != pfVar14);
LAB_006d7820:
            if (uVar8 != 0) {
              if ((floating_point_string *)0x72 < local_3a8) {
                local_3a8 = (floating_point_string *)0x0;
                _memcpy_s(local_3a4,0x1cc,local_b2c,0);
                bVar16 = false;
                pfVar14 = local_3a8;
                goto LAB_006d7a7f;
              }
              local_3a4[(int)local_3a8] = uVar8;
              local_3a8 = local_3a8 + 1;
            }
            bVar16 = true;
            pfVar14 = local_3a8;
          }
        }
        else {
          if (pfVar14 < (floating_point_string *)0x2) {
            local_3a8 = local_918;
            _memcpy_s(local_3a4,0x1cc,local_914,(int)local_918 << 2);
            if (uVar11 != 0) {
              bVar16 = true;
              pfVar14 = local_3a8;
              if ((uVar11 != 1) && (local_3a8 != (floating_point_string *)0x0)) {
                uVar8 = 0;
                pfVar14 = (floating_point_string *)0x0;
                do {
                  lVar18 = (ulonglong)uVar11 * (ulonglong)local_3a4[(int)pfVar14] + (ulonglong)uVar8
                  ;
                  local_3a4[(int)pfVar14] = (uint)lVar18;
                  uVar8 = (uint)((ulonglong)lVar18 >> 0x20);
                  pfVar14 = pfVar14 + 1;
                } while (pfVar14 != local_3a8);
                goto LAB_006d7820;
              }
              goto LAB_006d7a7f;
            }
            _MaxCount = 0;
            local_3a8 = (floating_point_string *)0x0;
            puVar15 = local_b2c;
          }
          else {
            local_92c = (floating_point_string *)local_914;
            if (pfVar14 <= local_918) {
              local_92c = (floating_point_string *)local_3a4;
            }
            local_934 = (floating_point_string *)local_3a4;
            pfVar12 = pfVar14;
            local_93c = local_918;
            if (pfVar14 <= local_918) {
              local_934 = (floating_point_string *)local_914;
              pfVar12 = local_918;
              local_93c = pfVar14;
            }
            local_3a8 = (floating_point_string *)0x0;
            pfVar14 = (floating_point_string *)0x0;
            local_578 = (floating_point_string *)0x0;
            if (local_93c != (floating_point_string *)0x0) {
              do {
                if (*(int *)(local_92c + (int)pfVar14 * 4) == 0) {
                  if (pfVar14 == local_3a8) {
                    local_574[(int)pfVar14] = 0;
                    local_3a8 = pfVar14 + 1;
                    local_578 = local_3a8;
                  }
                }
                else {
                  uVar11 = 0;
                  local_930 = (floating_point_string *)0x0;
                  pfVar13 = pfVar14;
                  if (pfVar12 != (floating_point_string *)0x0) {
                    do {
                      if (pfVar13 == (floating_point_string *)0x73) break;
                      if (pfVar13 == local_3a8) {
                        local_574[(int)pfVar13] = 0;
                        local_578 = pfVar14 + 1 + (int)local_930;
                      }
                      lVar18 = (ulonglong)*(uint *)(local_934 + (int)local_930 * 4) *
                               (ulonglong)*(uint *)(local_92c + (int)pfVar14 * 4) +
                               (ulonglong)uVar11;
                      uVar8 = (uint)lVar18;
                      puVar15 = local_574 + (int)pfVar13;
                      uVar11 = *puVar15;
                      *puVar15 = *puVar15 + uVar8;
                      uVar11 = (int)((ulonglong)lVar18 >> 0x20) + (uint)CARRY4(uVar11,uVar8);
                      local_930 = local_930 + 1;
                      pfVar13 = pfVar13 + 1;
                      local_3a8 = local_578;
                    } while (local_930 != pfVar12);
                    do {
                      if (uVar11 == 0) break;
                      if (pfVar13 == (floating_point_string *)0x73) goto LAB_006d7b16;
                      if (pfVar13 == local_3a8) {
                        local_574[(int)pfVar13] = 0;
                        local_578 = pfVar13 + 1;
                      }
                      puVar15 = local_574 + (int)pfVar13;
                      uVar8 = *puVar15;
                      *puVar15 = *puVar15 + uVar11;
                      uVar11 = (uint)CARRY4(uVar8,uVar11);
                      pfVar13 = pfVar13 + 1;
                      local_3a8 = local_578;
                    } while( true );
                  }
                  if (pfVar13 == (floating_point_string *)0x73) {
LAB_006d7b16:
                    local_3a8 = (floating_point_string *)0x0;
                    _memcpy_s(local_3a4,0x1cc,local_b2c,0);
                    bVar16 = false;
                    pfVar14 = local_3a8;
                    goto LAB_006d7a7f;
                  }
                }
                pfVar14 = pfVar14 + 1;
              } while (pfVar14 != local_93c);
            }
            _MaxCount = (int)local_3a8 << 2;
            puVar15 = local_574;
          }
LAB_006d7a68:
          _memcpy_s(local_3a4,0x1cc,puVar15,_MaxCount);
          bVar16 = true;
          pfVar14 = local_3a8;
        }
LAB_006d7a7f:
        if (!bVar16) goto LAB_006d7b68;
      }
      if (local_944 != (floating_point_string *)0x0) {
        uVar11 = *(uint *)(&DAT_00716ca4 + (int)local_944 * 2);
        if (uVar11 == 0) {
LAB_006d7b68:
          local_3a8 = (floating_point_string *)0x0;
          _memcpy_s(local_3a4,0x1cc,local_b2c,0);
          pfVar14 = local_3a8;
        }
        else if ((uVar11 != 1) && (pfVar14 != (floating_point_string *)0x0)) {
          uVar8 = 0;
          pfVar12 = (floating_point_string *)0x0;
          do {
            lVar18 = (ulonglong)uVar11 * (ulonglong)local_3a4[(int)pfVar12] + (ulonglong)uVar8;
            local_3a4[(int)pfVar12] = (uint)lVar18;
            uVar8 = (uint)((ulonglong)lVar18 >> 0x20);
            pfVar12 = pfVar12 + 1;
          } while (pfVar12 != pfVar14);
          pfVar14 = local_3a8;
          if (uVar8 != 0) {
            if ((floating_point_string *)0x72 < local_3a8) goto LAB_006d7b68;
            local_3a4[(int)local_3a8] = uVar8;
            local_3a8 = local_3a8 + 1;
            pfVar14 = local_3a8;
          }
        }
      }
      if (local_928 != (floating_point_string *)0x0) {
        pfVar13 = (floating_point_string *)0x0;
        pfVar12 = local_928;
        if (pfVar14 != (floating_point_string *)0x0) {
          do {
            puVar15 = local_3a4 + (int)pfVar13;
            uVar11 = *puVar15;
            *puVar15 = (uint)(pfVar12 + *puVar15);
            pfVar12 = (floating_point_string *)(uint)CARRY4(uVar11,(uint)pfVar12);
            pfVar13 = pfVar13 + 1;
            pfVar14 = local_3a8;
          } while (pfVar13 != local_3a8);
        }
        if (pfVar12 != (floating_point_string *)0x0) {
          if (pfVar14 < (floating_point_string *)0x73) {
            local_3a4[(int)pfVar14] = (uint)pfVar12;
            local_3a8 = local_3a8 + 1;
            pfVar14 = local_3a8;
          }
          else {
            local_3a8 = (floating_point_string *)0x0;
            _memcpy_s(local_3a4,0x1cc,local_b2c,0);
            pfVar14 = local_3a8;
          }
        }
      }
    }
  }
  local_92c = local_920;
  if (*(int *)local_94c < 0) {
    local_92c = local_920 + -*(int *)local_94c;
  }
  local_744[1] = 0;
  local_944 = (floating_point_string *)((uint)local_92c % 10);
  local_744[0] = 1;
  local_920 = (floating_point_string *)0x1;
  local_748 = (floating_point_string *)0x1;
  for (local_92c = (floating_point_string *)((uint)local_92c / 10);
      local_92c != (floating_point_string *)0x0; local_92c = local_92c + -(int)local_930) {
    local_930 = local_92c;
    if ((floating_point_string *)0x26 < local_92c) {
      local_930 = (floating_point_string *)0x26;
    }
    pfVar14 = local_930;
    uVar11 = (uint)(byte)(&DAT_00716c0e)[(int)local_930 * 4];
    bVar1 = (&DAT_00716c0f)[(int)local_930 * 4];
    local_918 = (floating_point_string *)(uVar11 + bVar1);
    _memset(local_914,0,uVar11 * 4);
    FUN_006d2250(local_914 + uVar11,
                 &DAT_00716308 + (uint)*(ushort *)(&DAT_00716c0c + (int)pfVar14 * 4) * 4,
                 (uint)bVar1 << 2);
    uVar11 = local_744[0];
    if (local_918 < (floating_point_string *)0x2) {
      if (local_914[0] == 0) {
LAB_006d7ced:
        local_748 = (floating_point_string *)0x0;
        _memcpy_s(local_744,0x1cc,local_b2c,0);
      }
      else {
        if ((local_914[0] == 1) || (local_920 == (floating_point_string *)0x0)) {
          bVar16 = true;
          goto LAB_006d7fbc;
        }
        uVar8 = 0;
        pfVar14 = (floating_point_string *)0x0;
        do {
          lVar18 = (ulonglong)local_914[0] * (ulonglong)local_744[(int)pfVar14] + (ulonglong)uVar8;
          local_744[(int)pfVar14] = (uint)lVar18;
          uVar8 = (uint)((ulonglong)lVar18 >> 0x20);
          pfVar14 = pfVar14 + 1;
        } while (pfVar14 != local_920);
LAB_006d7df9:
        if (uVar8 != 0) {
          if ((floating_point_string *)0x72 < local_748) {
            local_748 = (floating_point_string *)0x0;
            _memcpy_s(local_744,0x1cc,local_b2c,0);
            bVar16 = false;
            local_920 = local_748;
            goto LAB_006d7fbc;
          }
          local_744[(int)local_748] = uVar8;
          local_748 = local_748 + 1;
        }
      }
      bVar16 = true;
      local_920 = local_748;
    }
    else if (local_920 < (floating_point_string *)0x2) {
      local_748 = local_918;
      _memcpy_s(local_744,0x1cc,local_914,(int)local_918 << 2);
      if (uVar11 == 0) goto LAB_006d7ced;
      bVar16 = true;
      local_920 = local_748;
      if ((uVar11 != 1) && (local_748 != (floating_point_string *)0x0)) {
        uVar8 = 0;
        pfVar14 = (floating_point_string *)0x0;
        do {
          lVar18 = (ulonglong)uVar11 * (ulonglong)local_744[(int)pfVar14] + (ulonglong)uVar8;
          local_744[(int)pfVar14] = (uint)lVar18;
          uVar8 = (uint)((ulonglong)lVar18 >> 0x20);
          pfVar14 = pfVar14 + 1;
        } while (pfVar14 != local_748);
        goto LAB_006d7df9;
      }
    }
    else {
      local_928 = (floating_point_string *)local_914;
      if (local_920 <= local_918) {
        local_928 = (floating_point_string *)local_744;
      }
      local_938 = (floating_point_string *)local_744;
      pfVar14 = local_920;
      local_934 = local_918;
      if (local_920 <= local_918) {
        local_938 = (floating_point_string *)local_914;
        pfVar14 = local_918;
        local_934 = local_920;
      }
      local_748 = (floating_point_string *)0x0;
      pfVar12 = (floating_point_string *)0x0;
      local_578 = (floating_point_string *)0x0;
      if (local_934 != (floating_point_string *)0x0) {
        do {
          if (*(int *)(local_928 + (int)pfVar12 * 4) == 0) {
            if (pfVar12 == local_748) {
              local_574[(int)pfVar12] = 0;
              local_748 = pfVar12 + 1;
              local_578 = local_748;
            }
          }
          else {
            uVar11 = 0;
            local_93c = (floating_point_string *)0x0;
            pfVar13 = pfVar12;
            if (pfVar14 != (floating_point_string *)0x0) {
              do {
                if (pfVar13 == (floating_point_string *)0x73) break;
                if (pfVar13 == local_748) {
                  local_574[(int)pfVar13] = 0;
                  local_578 = pfVar12 + 1 + (int)local_93c;
                }
                lVar18 = (ulonglong)*(uint *)(local_938 + (int)local_93c * 4) *
                         (ulonglong)*(uint *)(local_928 + (int)pfVar12 * 4) + (ulonglong)uVar11;
                uVar8 = (uint)lVar18;
                puVar15 = local_574 + (int)pfVar13;
                uVar11 = *puVar15;
                *puVar15 = *puVar15 + uVar8;
                uVar11 = (int)((ulonglong)lVar18 >> 0x20) + (uint)CARRY4(uVar11,uVar8);
                local_93c = local_93c + 1;
                pfVar13 = pfVar13 + 1;
                local_748 = local_578;
              } while (local_93c != pfVar14);
              do {
                if (uVar11 == 0) break;
                if (pfVar13 == (floating_point_string *)0x73) goto LAB_006d8044;
                if (pfVar13 == local_748) {
                  local_574[(int)pfVar13] = 0;
                  local_578 = pfVar13 + 1;
                }
                puVar15 = local_574 + (int)pfVar13;
                uVar8 = *puVar15;
                *puVar15 = *puVar15 + uVar11;
                uVar11 = (uint)CARRY4(uVar8,uVar11);
                pfVar13 = pfVar13 + 1;
                local_748 = local_578;
              } while( true );
            }
            if (pfVar13 == (floating_point_string *)0x73) {
LAB_006d8044:
              local_748 = (floating_point_string *)0x0;
              _memcpy_s(local_744,0x1cc,local_b2c,0);
              bVar16 = false;
              goto LAB_006d7fb0;
            }
          }
          pfVar12 = pfVar12 + 1;
        } while (pfVar12 != local_934);
      }
      _memcpy_s(local_744,0x1cc,local_574,(int)local_748 << 2);
      bVar16 = true;
LAB_006d7fb0:
      local_920 = local_748;
    }
LAB_006d7fbc:
    if (!bVar16) goto LAB_006d80fb;
    pfVar14 = local_3a8;
  }
  if (local_944 != (floating_point_string *)0x0) {
    local_944 = *(floating_point_string **)(&DAT_00716ca4 + (int)local_944 * 2);
    if (local_944 == (floating_point_string *)0x0) {
      local_748 = local_944;
      _memcpy_s(local_744,0x1cc,local_b2c,0);
      pfVar14 = local_3a8;
LAB_006d8033:
      local_920 = local_748;
    }
    else if ((local_944 != (floating_point_string *)0x1) &&
            (local_920 != (floating_point_string *)0x0)) {
      uVar11 = 0;
      pfVar12 = (floating_point_string *)0x0;
      do {
        lVar18 = ZEXT48(local_944) * (ulonglong)local_744[(int)pfVar12] + (ulonglong)uVar11;
        local_744[(int)pfVar12] = (uint)lVar18;
        uVar11 = (uint)((ulonglong)lVar18 >> 0x20);
        pfVar12 = pfVar12 + 1;
      } while (pfVar12 != local_920);
      if (uVar11 == 0) goto LAB_006d8033;
      if ((floating_point_string *)0x72 < local_748) {
LAB_006d80fb:
        local_748 = (floating_point_string *)0x0;
        _memcpy_s(local_744,0x1cc,local_b2c,0);
        assemble_floating_point_zero((bool)local_94c[0x308],local_954);
        goto LAB_006d86ab;
      }
      local_744[(int)local_748] = uVar11;
      local_920 = local_748 + 1;
      local_748 = local_920;
    }
  }
  if (pfVar14 == (floating_point_string *)0x0) {
    uVar11 = 0;
  }
  else {
    uVar11 = local_3a4[(int)(pfVar14 + -1)];
    local_948 = (floating_point_string *)0x0;
    iVar5 = 0x1f;
    if (uVar11 != 0) {
      for (; uVar11 >> iVar5 == 0; iVar5 = iVar5 + -1) {
      }
    }
    if (uVar11 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar5 + 1;
    }
    uVar11 = (int)(pfVar14 + -1) * 0x20 + iVar5;
  }
  if (local_920 == (floating_point_string *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = local_744[(int)(local_920 + -1)];
    local_948 = (floating_point_string *)0x0;
    iVar5 = 0x1f;
    if (uVar8 != 0) {
      for (; uVar8 >> iVar5 == 0; iVar5 = iVar5 + -1) {
      }
    }
    if (uVar8 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar5 + 1;
    }
    uVar8 = (int)(local_920 + -1) * 0x20 + iVar5;
  }
  local_924 = (floating_point_string *)(-(uint)(uVar11 < uVar8) & uVar8 - uVar11);
  pfVar12 = local_920;
  if (local_924 != (floating_point_string *)0x0) {
    pfVar13 = (floating_point_string *)((uint)local_924 & 0x1f);
    pfVar12 = (floating_point_string *)((uint)local_924 >> 5);
    local_92c = (floating_point_string *)(0x20 - (int)pfVar13);
    local_930 = pfVar12;
    local_928 = pfVar13;
    iVar5 = __allshl();
    uVar11 = local_3a4[(int)(pfVar14 + -1)];
    local_960 = iVar5 - 1;
    local_944 = (floating_point_string *)~local_960;
    iVar5 = 0x1f;
    if (uVar11 != 0) {
      for (; uVar11 >> iVar5 == 0; iVar5 = iVar5 + -1) {
      }
    }
    if (uVar11 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar5 + 1;
    }
    local_934 = pfVar12 + (int)pfVar14;
    local_948 = (floating_point_string *)(0x20 - iVar5);
    if ((local_934 == (floating_point_string *)0x73) && (local_948 < pfVar13)) {
      bVar16 = true;
    }
    else {
      bVar16 = false;
    }
    if (((floating_point_string *)0x73 < local_934) || (bVar16)) {
      local_3a8 = (floating_point_string *)0x0;
      _memcpy_s(local_3a4,0x1cc,local_b2c,0);
      pfVar12 = local_748;
      pfVar14 = local_3a8;
    }
    else {
      if ((floating_point_string *)0x71 < local_934) {
        local_934 = (floating_point_string *)0x72;
      }
      local_938 = local_934;
      if (local_934 != (floating_point_string *)0xffffffff) {
        pfVar13 = local_934 + -(int)local_930;
        local_93c = (floating_point_string *)(local_3a4 + (int)pfVar13);
        do {
          pfVar12 = local_930;
          if (local_938 < local_930) break;
          if (pfVar13 < pfVar14) {
            uVar11 = *(uint *)local_93c;
          }
          else {
            uVar11 = 0;
          }
          if (pfVar13 + -1 < pfVar14) {
            uVar8 = *(uint *)(local_93c + -4);
          }
          else {
            uVar8 = 0;
          }
          local_93c = local_93c + -4;
          local_3a4[(int)local_938] =
               (uVar8 & (uint)local_944) >> ((byte)local_92c & 0x1f) |
               (uVar11 & local_960) << ((byte)local_928 & 0x1f);
          local_938 = local_938 + -1;
          pfVar13 = pfVar13 + -1;
          pfVar14 = local_3a8;
        } while (local_938 != (floating_point_string *)0xffffffff);
      }
      if (pfVar12 != (floating_point_string *)0x0) {
        puVar15 = local_3a4;
        for (; pfVar12 != (floating_point_string *)0x0; pfVar12 = pfVar12 + -1) {
          *puVar15 = 0;
          puVar15 = puVar15 + 1;
        }
      }
      local_3a8 = local_934;
      if (local_948 < local_928) {
        local_3a8 = local_934 + 1;
      }
      pfVar12 = local_920;
      pfVar14 = local_3a8;
    }
  }
  local_950 = local_950 + -(int)local_940;
  pfVar13 = local_950;
  if (local_940 != (floating_point_string *)0x0) {
    if (local_950 < local_924) {
      bVar16 = local_95c != local_958;
      fVar2 = local_94c[0x308];
      goto LAB_006d869c;
    }
    pfVar13 = local_950 + -(int)local_924;
  }
  if (pfVar14 <= pfVar12) {
    if (pfVar14 < pfVar12) {
LAB_006d83d1:
      local_924 = local_924 + 1;
    }
    else {
      pfVar12 = pfVar14 + -1;
      if (pfVar12 != (floating_point_string *)0xffffffff) {
        do {
          if (local_3a4[(int)pfVar12] != local_744[(int)pfVar12]) break;
          pfVar12 = pfVar12 + -1;
        } while (pfVar12 != (floating_point_string *)0xffffffff);
        if ((pfVar12 != (floating_point_string *)0xffffffff) &&
           (local_3a4[(int)pfVar12] <= local_744[(int)pfVar12])) goto LAB_006d83d1;
      }
    }
  }
  pfVar12 = (floating_point_string *)((uint)pfVar13 & 0x1f);
  pfVar13 = (floating_point_string *)((uint)pfVar13 >> 5);
  local_960 = 0x20 - (int)pfVar12;
  local_934 = pfVar12;
  local_930 = pfVar13;
  iVar5 = __allshl();
  uVar11 = local_3a4[(int)(pfVar14 + -1)];
  local_944 = (floating_point_string *)(iVar5 + -1);
  local_938 = (floating_point_string *)0x0;
  local_948 = (floating_point_string *)~(uint)local_944;
  iVar5 = 0x1f;
  if (uVar11 != 0) {
    for (; uVar11 >> iVar5 == 0; iVar5 = iVar5 + -1) {
    }
  }
  if (uVar11 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = iVar5 + 1;
  }
  local_93c = pfVar13 + (int)pfVar14;
  local_92c = (floating_point_string *)(0x20 - iVar5);
  if ((local_93c == (floating_point_string *)0x73) && (local_92c < pfVar12)) {
    bVar16 = true;
  }
  else {
    bVar16 = false;
  }
  if (((floating_point_string *)0x73 < local_93c) || (bVar16)) {
    local_3a8 = (floating_point_string *)0x0;
    _memcpy_s(local_3a4,0x1cc,local_b2c,0);
  }
  else {
    if ((floating_point_string *)0x71 < local_93c) {
      local_93c = (floating_point_string *)0x72;
    }
    local_938 = local_93c;
    if (local_93c != (floating_point_string *)0xffffffff) {
      pfVar9 = local_93c + -(int)local_930;
      local_928 = (floating_point_string *)(local_3a4 + (int)pfVar9);
      do {
        pfVar12 = local_934;
        pfVar13 = local_930;
        if (local_938 < local_930) break;
        if (pfVar9 < pfVar14) {
          uVar11 = *(uint *)local_928;
        }
        else {
          uVar11 = 0;
        }
        if (pfVar9 + -1 < pfVar14) {
          uVar8 = *(uint *)(local_928 + -4);
        }
        else {
          uVar8 = 0;
        }
        local_3a4[(int)local_938] =
             (uVar8 & (uint)local_948) >> ((byte)local_960 & 0x1f) |
             (uVar11 & (uint)local_944) << ((byte)local_934 & 0x1f);
        local_938 = local_938 + -1;
        pfVar9 = pfVar9 + -1;
        local_928 = local_928 + -4;
        pfVar14 = local_3a8;
      } while (local_938 != (floating_point_string *)0xffffffff);
    }
    if (pfVar13 != (floating_point_string *)0x0) {
      puVar15 = local_3a4;
      for (; pfVar13 != (floating_point_string *)0x0; pfVar13 = pfVar13 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
    }
    local_3a8 = local_93c;
    if (local_92c < pfVar12) {
      local_3a8 = local_93c + 1;
    }
  }
  _Var17 = divide((big_integer *)&local_3a8,(big_integer *)&local_748);
  uVar8 = (uint)(_Var17 >> 0x20);
  uVar11 = (uint)_Var17;
  local_928 = (floating_point_string *)
              CONCAT31(local_928._1_3_,local_3a8 == (floating_point_string *)0x0);
  if (uVar8 == 0) {
    iVar5 = 0x1f;
    if (uVar11 != 0) {
      for (; uVar11 >> iVar5 == 0; iVar5 = iVar5 + -1) {
      }
    }
    if (uVar11 == 0) {
      pfVar14 = (floating_point_string *)0x0;
    }
    else {
      pfVar14 = (floating_point_string *)(iVar5 + 1);
    }
  }
  else {
    iVar5 = 0x1f;
    if (uVar8 != 0) {
      for (; uVar8 >> iVar5 == 0; iVar5 = iVar5 + -1) {
      }
    }
    if (uVar8 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar5 + 1;
    }
    pfVar14 = (floating_point_string *)(iVar5 + 0x20);
  }
  if (local_950 < pfVar14) {
    if (local_3a8 == (floating_point_string *)0x0) {
      lVar18 = __allshl();
      local_928 = (floating_point_string *)CONCAT31(local_928._1_3_,1);
      if ((lVar18 - 1U & _Var17) != 0) goto LAB_006d85e9;
    }
    else {
LAB_006d85e9:
      local_928 = (floating_point_string *)((uint)local_928 & 0xffffff00);
    }
    _Var17 = __aullshr();
  }
  lVar18 = __allshl();
  if (local_940 == (floating_point_string *)0x0) {
    pfVar14 = (floating_point_string *)~(uint)local_924;
  }
  else {
    pfVar14 = local_940 + -2;
  }
  assemble_floating_point_value
            (_Var17 + lVar18,(int)pfVar14,(bool)local_94c[0x308],SUB41(local_928,0),local_954);
LAB_006d86ab:
  SVar6 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return SVar6;
}

