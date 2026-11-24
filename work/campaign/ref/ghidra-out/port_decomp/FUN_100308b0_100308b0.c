
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_100308b0(byte param_1,uint param_2,uint param_3,undefined1 (*param_4) [16],
            undefined1 (*param_5) [16])

{
  undefined1 (*pauVar1) [16];
  undefined1 auVar2 [32];
  undefined1 auVar3 [32];
  undefined1 auVar4 [32];
  undefined1 auVar5 [32];
  undefined1 auVar6 [32];
  undefined1 auVar7 [32];
  undefined1 auVar8 [32];
  undefined1 auVar9 [32];
  undefined1 auVar10 [32];
  undefined1 auVar11 [32];
  undefined1 auVar12 [32];
  undefined1 auVar13 [32];
  undefined1 auVar14 [32];
  undefined1 auVar15 [32];
  undefined1 auVar16 [32];
  undefined1 auVar17 [32];
  undefined1 auVar18 [32];
  undefined1 auVar19 [32];
  undefined1 auVar20 [32];
  undefined1 auVar21 [32];
  undefined1 auVar22 [32];
  undefined1 auVar23 [32];
  undefined1 auVar24 [32];
  undefined1 auVar25 [32];
  undefined1 auVar26 [16];
  undefined1 auVar27 [12];
  undefined1 auVar28 [16];
  undefined1 auVar29 [16];
  undefined1 auVar30 [16];
  undefined1 auVar31 [16];
  undefined1 auVar32 [16];
  undefined1 auVar33 [16];
  undefined1 auVar34 [16];
  undefined1 auVar35 [16];
  undefined1 auVar36 [16];
  undefined1 auVar37 [16];
  undefined1 auVar38 [16];
  undefined1 auVar39 [16];
  undefined1 auVar40 [16];
  undefined1 auVar41 [16];
  undefined1 auVar42 [16];
  undefined1 auVar43 [16];
  undefined1 auVar44 [16];
  undefined1 auVar45 [16];
  undefined1 auVar46 [16];
  undefined1 auVar47 [16];
  undefined1 auVar48 [16];
  undefined1 auVar49 [16];
  undefined1 auVar50 [16];
  uint uVar51;
  uint uVar52;
  int iVar53;
  int in_ECX;
  uint in_EDX;
  uint uVar54;
  int iVar55;
  int iVar56;
  uint uVar57;
  bool bVar58;
  undefined1 auVar59 [16];
  undefined1 auVar60 [16];
  undefined1 auVar61 [16];
  undefined1 auVar62 [16];
  undefined1 auVar63 [16];
  undefined1 auVar64 [16];
  undefined1 auVar65 [16];
  undefined1 auVar66 [16];
  undefined1 auVar67 [16];
  int iVar68;
  int iVar73;
  int iVar74;
  undefined1 auVar69 [16];
  undefined1 auVar70 [16];
  undefined1 auVar71 [16];
  undefined1 auVar72 [16];
  int iVar75;
  ulonglong uVar77;
  undefined1 auVar76 [16];
  ulonglong uVar78;
  undefined1 auVar79 [16];
  undefined1 auVar81 [16];
  undefined1 auVar82 [16];
  undefined1 auVar83 [16];
  undefined1 auVar84 [16];
  undefined1 auVar85 [16];
  undefined1 auVar86 [16];
  undefined1 auVar87 [16];
  undefined1 auVar88 [16];
  undefined1 auVar89 [16];
  undefined1 auVar90 [16];
  int iVar93;
  undefined1 auVar91 [16];
  undefined1 auVar92 [16];
  undefined1 auVar94 [16];
  uint local_d4 [4];
  int local_c4;
  undefined4 local_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined1 local_a0 [16];
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  int local_74;
  undefined1 local_70 [16];
  undefined1 (*local_5c) [16];
  uint local_58;
  uint local_54;
  undefined1 local_50 [16];
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined1 (*local_18) [16];
  undefined1 (*local_14) [16];
  undefined1 auVar80 [16];
  
  local_14 = param_4;
  local_18 = param_5;
  local_74 = in_ECX;
  local_58 = in_EDX;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  auVar64 = ZEXT816(0);
  local_d4[0] = 0;
  local_54 = local_58 & 0xfffffffc;
  auVar89 = ZEXT816(0);
  local_d4[1] = 0xffffffff;
  uStack_84 = 0;
  uStack_88 = 0;
  uStack_8c = 0;
  local_90 = 0;
  auVar88 = ZEXT816(0);
  local_50 = auVar64;
  local_5c = (undefined1 (*) [16])(*param_5 + (local_58 & 0xfffffffc) * 4);
  local_70 = auVar64;
  local_24 = (uint)param_1;
  uVar51 = ~(-1 << (param_1 & 0x1f));
  local_d4[2] = uVar51;
  local_a0 = auVar64;
  if ((int)param_2 < 4) {
    if (param_2 == 1) {
      uVar78 = (ulonglong)*(uint *)*local_14;
      auVar82._0_12_ = ZEXT812(0);
      auVar82._12_4_ = *(undefined4 *)(param_5[-1] + 0xc);
      uVar77 = auVar82._8_8_;
    }
    else {
      if (param_2 != 2) {
        if (param_2 == 3) {
          auVar89._12_4_ = 0;
          auVar89._0_12_ = *(undefined1 (*) [12])*local_14;
          auVar91._12_4_ = 0;
          auVar91._0_12_ = *(undefined1 (*) [12])(param_5[-1] + 4);
          local_50 = auVar91 << 0x20;
        }
        goto LAB_10030c72;
      }
      uVar78 = *(ulonglong *)*local_14;
      uVar77 = *(ulonglong *)(param_5[-1] + 8);
    }
    auVar94._8_8_ = 0;
    auVar94._0_8_ = uVar77;
    auVar89._8_8_ = 0;
    auVar89._0_8_ = uVar78;
    local_50 = auVar94 << 0x40;
  }
  else {
    auVar64 = param_5[-1];
    local_50 = auVar64;
    auVar89 = *local_14;
    if ((int)(param_2 - 4) < 4) {
      if (param_2 == 5) {
        uStack_84 = *(undefined4 *)local_14[1];
        uStack_88 = 0;
        uStack_8c = 0;
        local_90 = 0;
        auVar92._0_12_ = ZEXT812(0);
        auVar92._12_4_ = *(undefined4 *)(param_5[-2] + 0xc);
        auVar87._8_8_ = 0;
        auVar87._0_8_ = auVar92._8_8_;
        local_70 = auVar87 << 0x40;
      }
      else if (param_2 == 6) {
        uStack_84 = *(undefined4 *)local_14[1];
        uStack_88 = *(undefined4 *)(local_14[1] + 4);
        uStack_8c = 0;
        local_90 = 0;
        auVar50._8_8_ = 0;
        auVar50._0_8_ = *(ulonglong *)(param_5[-2] + 8);
        local_70 = auVar50 << 0x40;
      }
      else if (param_2 == 7) {
        uStack_8c = *(undefined4 *)(local_14[1] + 8);
        uStack_84 = *(undefined4 *)local_14[1];
        uStack_88 = *(undefined4 *)(local_14[1] + 4);
        local_70._12_4_ = 0;
        local_70._0_12_ = *(undefined1 (*) [12])(param_5[-2] + 4);
        local_70 = local_70 << 0x20;
        local_90 = 0;
      }
    }
    else {
      pauVar1 = param_5 + -2;
      uStack_84 = *(undefined4 *)local_14[1];
      uStack_88 = *(undefined4 *)(local_14[1] + 4);
      uStack_8c = *(undefined4 *)(local_14[1] + 8);
      local_90 = *(undefined4 *)(local_14[1] + 0xc);
      local_70 = *pauVar1;
      if (param_2 == 0xc) {
        auVar88 = local_14[2];
        local_a0 = param_5[-3];
      }
      else {
        local_70 = *pauVar1;
        if (param_2 == 9) {
          uVar78 = (ulonglong)*(uint *)local_14[2];
          auVar79._0_12_ = ZEXT812(0);
          auVar79._12_4_ = *(undefined4 *)(param_5[-3] + 0xc);
          auVar26._8_8_ = 0;
          auVar26._0_8_ = auVar79._8_8_;
          local_a0 = auVar26 << 0x40;
        }
        else {
          if (param_2 != 10) {
            if (param_2 == 0xb) {
              auVar88._12_4_ = 0;
              auVar88._0_12_ = *(undefined1 (*) [12])local_14[2];
              local_a0._12_4_ = 0;
              local_a0._0_12_ = *(undefined1 (*) [12])(param_5[-3] + 4);
              local_a0 = local_a0 << 0x20;
              local_70 = *pauVar1;
            }
            goto LAB_10030c72;
          }
          uVar78 = *(ulonglong *)local_14[2];
          auVar49._8_8_ = 0;
          auVar49._0_8_ = *(ulonglong *)(param_5[-3] + 8);
          local_a0 = auVar49 << 0x40;
        }
        auVar88._8_8_ = 0;
        auVar88._0_8_ = uVar78;
        local_70 = *pauVar1;
      }
    }
  }
LAB_10030c72:
  local_b0 = auVar89._12_4_;
  uStack_ac = auVar89._8_4_;
  uStack_a8 = auVar89._4_4_;
  uStack_a4 = auVar89._0_4_;
  local_c0 = auVar88._12_4_;
  uStack_bc = auVar88._8_4_;
  uStack_b8 = auVar88._4_4_;
  uStack_b4 = auVar88._0_4_;
  if (param_5 < local_5c) {
    local_3c = 0x20 - (param_1 + 1);
    do {
      uVar52 = *(uint *)(in_ECX + 0x101c);
      iVar56 = *(int *)(in_ECX + 0x18);
      if (DAT_1005109c == 0) {
        if (uVar52 == 0) {
          uVar57 = 0x20;
        }
        else {
          iVar55 = 0x1f;
          if (uVar52 != 0) {
            for (; uVar52 >> iVar55 == 0; iVar55 = iVar55 + -1) {
            }
          }
          uVar57 = 0x1f - iVar55;
        }
      }
      else {
        uVar57 = LZCOUNT(uVar52);
      }
      local_28 = uVar57;
      if (0x1f < uVar57) {
        local_28 = 0x20 - iVar56;
        do {
          uVar52 = *(uint *)(in_ECX + 0x14);
          if (uVar52 < 0x400) {
            uVar57 = *(uint *)(in_ECX + 0x1c + uVar52 * 4);
            *(uint *)(in_ECX + 0x14) = uVar52 + 1;
            iVar56 = 0;
            uVar52 = uVar57 >> 0x18 | (uVar57 & 0xff0000) >> 8 | (uVar57 & 0xff00) << 8 |
                     uVar57 << 0x18;
          }
          else {
            iVar56 = FUN_1002d310();
            if (iVar56 == 0) {
              return 0;
            }
            uVar52 = *(uint *)(in_ECX + 0x101c);
            iVar56 = *(int *)(in_ECX + 0x18);
          }
          if (DAT_1005109c == 0) {
            if (uVar52 == 0) {
              uVar57 = 0x20;
            }
            else {
              iVar55 = 0x1f;
              if (uVar52 != 0) {
                for (; uVar52 >> iVar55 == 0; iVar55 = iVar55 + -1) {
                }
              }
              uVar57 = 0x1f - iVar55;
            }
          }
          else {
            uVar57 = LZCOUNT(uVar52);
          }
          local_28 = local_28 + uVar57;
        } while (0x1f < uVar57);
      }
      uVar54 = iVar56 + uVar57;
      uVar52 = uVar52 << ((byte)uVar57 & 0x1f);
      local_20 = uVar52 >> ((byte)local_3c & 0x1f);
      local_1c = local_20;
      if (local_3c < uVar54) {
        iVar56 = uVar54 - local_3c;
        uVar52 = *(uint *)(in_ECX + 0x14);
        if (uVar52 < 0x400) {
          uVar57 = *(uint *)(in_ECX + 0x1c + uVar52 * 4);
          *(uint *)(in_ECX + 0x14) = uVar52 + 1;
          uVar57 = uVar57 >> 0x18 | (uVar57 & 0xff0000) >> 8 | (uVar57 & 0xff00) << 8 |
                   uVar57 << 0x18;
          iVar55 = iVar56;
        }
        else {
          iVar55 = FUN_1002d310();
          if (iVar55 == 0) {
            return 0;
          }
          uVar57 = *(uint *)(in_ECX + 0x101c);
          iVar55 = *(int *)(in_ECX + 0x18) + iVar56;
        }
        uVar52 = uVar57 << ((byte)iVar56 & 0x1f);
        local_1c = uVar57 >> (0x20 - (byte)iVar56 & 0x1f) | local_20;
      }
      else {
        uVar52 = uVar52 << ((byte)(local_24 + 1) & 0x1f);
        iVar55 = uVar54 + local_24 + 1;
      }
      bVar58 = DAT_1005109c == 0;
      *(uint *)(in_ECX + 0x101c) = uVar52;
      *(int *)(in_ECX + 0x18) = iVar55;
      if (bVar58) {
        if (uVar52 == 0) {
          uVar57 = 0x20;
        }
        else {
          iVar56 = 0x1f;
          if (uVar52 != 0) {
            for (; uVar52 >> iVar56 == 0; iVar56 = iVar56 + -1) {
            }
          }
          uVar57 = 0x1f - iVar56;
        }
      }
      else {
        uVar57 = LZCOUNT(uVar52);
      }
      if (uVar57 < 0x20) {
        local_20 = uVar57;
      }
      else {
        local_20 = 0x20 - iVar55;
        do {
          uVar52 = *(uint *)(in_ECX + 0x14);
          if (uVar52 < 0x400) {
            uVar57 = *(uint *)(in_ECX + 0x1c + uVar52 * 4);
            *(uint *)(in_ECX + 0x14) = uVar52 + 1;
            iVar55 = 0;
            uVar52 = uVar57 >> 0x18 | (uVar57 & 0xff0000) >> 8 | (uVar57 & 0xff00) << 8 |
                     uVar57 << 0x18;
          }
          else {
            iVar56 = FUN_1002d310();
            if (iVar56 == 0) {
              return 0;
            }
            uVar52 = *(uint *)(in_ECX + 0x101c);
            iVar55 = *(int *)(in_ECX + 0x18);
          }
          if (DAT_1005109c == 0) {
            if (uVar52 == 0) {
              uVar57 = 0x20;
            }
            else {
              iVar56 = 0x1f;
              if (uVar52 != 0) {
                for (; uVar52 >> iVar56 == 0; iVar56 = iVar56 + -1) {
                }
              }
              uVar57 = 0x1f - iVar56;
            }
          }
          else {
            uVar57 = LZCOUNT(uVar52);
          }
          local_20 = local_20 + uVar57;
        } while (0x1f < uVar57);
      }
      uVar54 = iVar55 + uVar57;
      uVar52 = uVar52 << ((byte)uVar57 & 0x1f);
      local_38 = uVar52 >> ((byte)local_3c & 0x1f);
      local_30 = local_38;
      if (local_3c < uVar54) {
        iVar56 = uVar54 - local_3c;
        uVar52 = *(uint *)(in_ECX + 0x14);
        if (uVar52 < 0x400) {
          uVar57 = *(uint *)(in_ECX + 0x1c + uVar52 * 4);
          *(uint *)(in_ECX + 0x14) = uVar52 + 1;
          uVar57 = uVar57 >> 0x18 | (uVar57 & 0xff0000) >> 8 | (uVar57 & 0xff00) << 8 |
                   uVar57 << 0x18;
          iVar55 = iVar56;
        }
        else {
          iVar55 = FUN_1002d310();
          if (iVar55 == 0) {
            return 0;
          }
          uVar57 = *(uint *)(in_ECX + 0x101c);
          iVar55 = *(int *)(in_ECX + 0x18) + iVar56;
        }
        uVar52 = uVar57 << ((byte)iVar56 & 0x1f);
        local_30 = uVar57 >> (0x20 - (byte)iVar56 & 0x1f) | local_38;
      }
      else {
        uVar52 = uVar52 << ((byte)(local_24 + 1) & 0x1f);
        iVar55 = uVar54 + local_24 + 1;
      }
      bVar58 = DAT_1005109c == 0;
      *(uint *)(in_ECX + 0x101c) = uVar52;
      *(int *)(in_ECX + 0x18) = iVar55;
      if (bVar58) {
        if (uVar52 == 0) {
          uVar57 = 0x20;
        }
        else {
          iVar56 = 0x1f;
          if (uVar52 != 0) {
            for (; uVar52 >> iVar56 == 0; iVar56 = iVar56 + -1) {
            }
          }
          uVar57 = 0x1f - iVar56;
        }
      }
      else {
        uVar57 = LZCOUNT(uVar52);
      }
      if (uVar57 < 0x20) {
        local_38 = uVar57;
      }
      else {
        local_38 = 0x20 - iVar55;
        do {
          uVar52 = *(uint *)(in_ECX + 0x14);
          if (uVar52 < 0x400) {
            uVar57 = *(uint *)(in_ECX + 0x1c + uVar52 * 4);
            *(uint *)(in_ECX + 0x14) = uVar52 + 1;
            iVar55 = 0;
            uVar52 = uVar57 >> 0x18 | (uVar57 & 0xff0000) >> 8 | (uVar57 & 0xff00) << 8 |
                     uVar57 << 0x18;
          }
          else {
            iVar56 = FUN_1002d310();
            if (iVar56 == 0) {
              return 0;
            }
            uVar52 = *(uint *)(in_ECX + 0x101c);
            iVar55 = *(int *)(in_ECX + 0x18);
          }
          if (DAT_1005109c == 0) {
            if (uVar52 == 0) {
              uVar57 = 0x20;
            }
            else {
              iVar56 = 0x1f;
              if (uVar52 != 0) {
                for (; uVar52 >> iVar56 == 0; iVar56 = iVar56 + -1) {
                }
              }
              uVar57 = 0x1f - iVar56;
            }
          }
          else {
            uVar57 = LZCOUNT(uVar52);
          }
          local_38 = local_38 + uVar57;
        } while (0x1f < uVar57);
      }
      uVar54 = iVar55 + uVar57;
      uVar52 = uVar52 << ((byte)uVar57 & 0x1f);
      local_34 = uVar52 >> ((byte)local_3c & 0x1f);
      local_2c = local_34;
      if (local_3c < uVar54) {
        iVar56 = uVar54 - local_3c;
        uVar52 = *(uint *)(in_ECX + 0x14);
        if (uVar52 < 0x400) {
          uVar57 = *(uint *)(in_ECX + 0x1c + uVar52 * 4);
          *(uint *)(in_ECX + 0x14) = uVar52 + 1;
          uVar57 = uVar57 >> 0x18 | (uVar57 & 0xff0000) >> 8 | (uVar57 & 0xff00) << 8 |
                   uVar57 << 0x18;
          iVar55 = iVar56;
        }
        else {
          iVar55 = FUN_1002d310();
          if (iVar55 == 0) {
            return 0;
          }
          uVar57 = *(uint *)(in_ECX + 0x101c);
          iVar55 = *(int *)(in_ECX + 0x18) + iVar56;
        }
        uVar52 = uVar57 << ((byte)iVar56 & 0x1f);
        local_2c = uVar57 >> (0x20 - (byte)iVar56 & 0x1f) | local_34;
      }
      else {
        uVar52 = uVar52 << ((byte)(local_24 + 1) & 0x1f);
        iVar55 = uVar54 + local_24 + 1;
      }
      bVar58 = DAT_1005109c == 0;
      *(uint *)(in_ECX + 0x101c) = uVar52;
      *(int *)(in_ECX + 0x18) = iVar55;
      if (bVar58) {
        if (uVar52 == 0) {
          uVar57 = 0x20;
        }
        else {
          iVar56 = 0x1f;
          if (uVar52 != 0) {
            for (; uVar52 >> iVar56 == 0; iVar56 = iVar56 + -1) {
            }
          }
          uVar57 = 0x1f - iVar56;
        }
      }
      else {
        uVar57 = LZCOUNT(uVar52);
      }
      if (uVar57 < 0x20) {
        local_34 = uVar57;
      }
      else {
        local_34 = 0x20 - iVar55;
        do {
          uVar52 = *(uint *)(in_ECX + 0x14);
          if (uVar52 < 0x400) {
            uVar57 = *(uint *)(in_ECX + 0x1c + uVar52 * 4);
            *(uint *)(in_ECX + 0x14) = uVar52 + 1;
            iVar55 = 0;
            uVar52 = uVar57 >> 0x18 | (uVar57 & 0xff0000) >> 8 | (uVar57 & 0xff00) << 8 |
                     uVar57 << 0x18;
          }
          else {
            iVar56 = FUN_1002d310();
            if (iVar56 == 0) {
              return 0;
            }
            uVar52 = *(uint *)(in_ECX + 0x101c);
            iVar55 = *(int *)(in_ECX + 0x18);
          }
          if (DAT_1005109c == 0) {
            if (uVar52 == 0) {
              uVar57 = 0x20;
            }
            else {
              iVar56 = 0x1f;
              if (uVar52 != 0) {
                for (; uVar52 >> iVar56 == 0; iVar56 = iVar56 + -1) {
                }
              }
              uVar57 = 0x1f - iVar56;
            }
          }
          else {
            uVar57 = LZCOUNT(uVar52);
          }
          local_34 = local_34 + uVar57;
        } while (0x1f < uVar57);
      }
      uVar54 = iVar55 + uVar57;
      uVar52 = uVar52 << ((byte)uVar57 & 0x1f);
      uVar57 = uVar52 >> ((byte)local_3c & 0x1f);
      if (local_3c < uVar54) {
        iVar56 = uVar54 - local_3c;
        local_d4[3] = uVar57;
        uVar52 = *(uint *)(in_ECX + 0x14);
        local_c4 = iVar56;
        if (uVar52 < 0x400) {
          uVar57 = *(uint *)(in_ECX + 0x1c + uVar52 * 4);
          *(uint *)(in_ECX + 0x14) = uVar52 + 1;
          uVar52 = uVar57 >> 0x18 | (uVar57 & 0xff0000) >> 8 | (uVar57 & 0xff00) << 8 |
                   uVar57 << 0x18;
          iVar55 = iVar56;
        }
        else {
          iVar55 = FUN_1002d310();
          if (iVar55 == 0) {
            return 0;
          }
          uVar52 = *(uint *)(in_ECX + 0x101c);
          iVar55 = *(int *)(in_ECX + 0x18) + iVar56;
        }
        iVar53 = uVar52 << ((byte)local_c4 & 0x1f);
        uVar57 = uVar52 >> (0x20U - (char)iVar56 & 0x1f) | local_d4[3];
      }
      else {
        iVar53 = uVar52 << ((byte)(local_24 + 1) & 0x1f);
        iVar55 = uVar54 + local_24 + 1;
        in_ECX = local_74;
      }
      auVar89 = _DAT_100479d0;
      *(int *)(in_ECX + 0x18) = iVar55;
      *(int *)(in_ECX + 0x101c) = iVar53;
      auVar84._0_4_ = local_28 << local_24;
      auVar84._4_4_ = local_20;
      auVar84._8_4_ = local_38;
      auVar84._12_4_ = local_34;
      auVar81._4_4_ = local_2c;
      auVar81._0_4_ = local_1c;
      auVar81._8_4_ = local_2c;
      auVar81._12_4_ = uVar57;
      auVar80._8_8_ = auVar81._8_8_;
      auVar80._4_4_ = local_30;
      auVar80._0_4_ = local_1c;
      auVar28._4_4_ = uVar51;
      auVar28._0_4_ = uVar51;
      auVar28._8_4_ = uVar51;
      auVar28._12_4_ = uVar51;
      auVar84 = auVar84 | auVar80 & auVar28;
      auVar85._0_4_ = auVar84._0_4_ >> 1;
      auVar85._4_4_ = auVar84._4_4_ >> 1;
      auVar85._8_4_ = auVar84._8_4_ >> 1;
      auVar85._12_4_ = auVar84._12_4_ >> 1;
      auVar89 = auVar89 & auVar84 ^ _DAT_10047d70;
      auVar90._0_4_ = auVar89._0_4_ + 1;
      auVar90._4_4_ = auVar89._4_4_ + 1;
      auVar90._8_4_ = auVar89._8_4_ + 1;
      auVar90._12_4_ = auVar89._12_4_ + 1;
      auVar90 = auVar90 ^ auVar85;
      iVar55 = auVar90._0_4_;
      iVar53 = auVar90._4_4_;
      iVar56 = auVar90._8_4_;
      iVar93 = auVar90._12_4_;
      auVar27 = auVar90._4_12_;
      if (param_2 < 5) {
        auVar88._4_4_ = uStack_ac;
        auVar88._0_4_ = local_b0;
        auVar88._8_4_ = uStack_a8;
        auVar88._12_4_ = uStack_a4;
        auVar76._12_4_ = 0;
        auVar76._0_12_ = auVar27;
        auVar89 = pmulld(auVar88,local_50);
        auVar69._0_4_ = auVar89._8_4_ + auVar89._0_4_;
        auVar69._4_4_ = auVar89._12_4_ + auVar89._4_4_;
        auVar69._8_4_ = auVar89._0_4_ + auVar89._8_4_;
        auVar69._12_4_ = auVar89._4_4_ + auVar89._12_4_;
        auVar89 = ZEXT416(param_3);
        auVar82 = pshuflw(auVar80 & auVar28,auVar69,0x4e);
        auVar2._20_4_ = (auVar82._4_4_ + auVar69._4_4_ >> auVar89) + iVar53;
        auVar2._16_4_ = (auVar82._0_4_ + auVar69._0_4_ >> auVar89) + iVar55;
        auVar2._24_4_ = (auVar82._8_4_ + auVar69._8_4_ >> auVar89) + iVar56;
        auVar2._28_4_ = (auVar82._12_4_ + auVar69._12_4_ >> auVar89) + iVar93;
        auVar2._0_16_ = local_50;
        auVar89 = pmulld(auVar88,auVar2._4_16_);
        auVar70._0_4_ = auVar89._8_4_ + auVar89._0_4_;
        auVar70._4_4_ = auVar89._12_4_ + auVar89._4_4_;
        auVar70._8_4_ = auVar89._0_4_ + auVar89._8_4_;
        auVar70._12_4_ = auVar89._4_4_ + auVar89._12_4_;
        auVar89 = ZEXT416(param_3);
        auVar82 = pshuflw(auVar85,auVar70,0x4e);
        auVar6._20_4_ = (auVar82._4_4_ + auVar70._4_4_ >> auVar89) + iVar56;
        auVar6._16_4_ = (auVar82._0_4_ + auVar70._0_4_ >> auVar89) + iVar53;
        auVar6._24_4_ = (auVar82._8_4_ + auVar70._8_4_ >> auVar89) + iVar93;
        auVar6._28_4_ = auVar82._12_4_ + auVar70._12_4_ >> auVar89;
        auVar6._0_16_ = auVar2._4_16_;
        auVar89 = pmulld(auVar88,auVar6._4_16_);
        auVar71._0_4_ = auVar89._8_4_ + auVar89._0_4_;
        auVar71._4_4_ = auVar89._12_4_ + auVar89._4_4_;
        auVar71._8_4_ = auVar89._0_4_ + auVar89._8_4_;
        auVar71._12_4_ = auVar89._4_4_ + auVar89._12_4_;
        auVar82 = pshuflw(auVar76,auVar71,0x4e);
        auVar89 = ZEXT416(param_3);
        auVar7._20_4_ = (auVar82._4_4_ + auVar71._4_4_ >> auVar89) + iVar93;
        auVar7._16_4_ = (auVar82._0_4_ + auVar71._0_4_ >> auVar89) + iVar56;
        auVar7._24_4_ = auVar82._8_4_ + auVar71._8_4_ >> auVar89;
        auVar7._28_4_ = auVar82._12_4_ + auVar71._12_4_ >> auVar89;
        auVar7._0_16_ = auVar6._4_16_;
        auVar89 = pmulld(auVar88,auVar7._4_16_);
        auVar72._0_4_ = auVar89._8_4_ + auVar89._0_4_;
        auVar72._4_4_ = auVar89._12_4_ + auVar89._4_4_;
        auVar72._8_4_ = auVar89._0_4_ + auVar89._8_4_;
        auVar72._12_4_ = auVar89._4_4_ + auVar89._12_4_;
        auVar89 = ZEXT416(param_3);
        auVar82 = pshuflw(auVar90,auVar72,0x4e);
        auVar8._20_4_ = auVar82._4_4_ + auVar72._4_4_ >> auVar89;
        auVar8._16_4_ = (auVar82._0_4_ + auVar72._0_4_ >> auVar89) + iVar93;
        auVar8._24_4_ = auVar82._8_4_ + auVar72._8_4_ >> auVar89;
        auVar8._28_4_ = auVar82._12_4_ + auVar72._12_4_ >> auVar89;
        auVar8._0_16_ = auVar7._4_16_;
        local_50 = auVar8._4_16_;
      }
      else {
        if (param_2 < 9) {
          auVar41._4_4_ = uStack_8c;
          auVar41._0_4_ = local_90;
          auVar41._8_4_ = uStack_88;
          auVar41._12_4_ = uStack_84;
          auVar82 = pmulld(auVar41,local_70);
          auVar33._4_4_ = uStack_ac;
          auVar33._0_4_ = local_b0;
          auVar33._8_4_ = uStack_a8;
          auVar33._12_4_ = uStack_a4;
          auVar89 = pmulld(auVar33,local_50);
          iVar68 = auVar82._0_4_ + auVar89._0_4_;
          iVar73 = auVar82._4_4_ + auVar89._4_4_;
          iVar74 = auVar82._8_4_ + auVar89._8_4_;
          iVar75 = auVar82._12_4_ + auVar89._12_4_;
          auVar3._16_16_ = local_50;
          auVar3._0_16_ = local_70;
          auVar59._0_4_ = iVar74 + iVar68;
          auVar59._4_4_ = iVar75 + iVar73;
          auVar59._8_4_ = iVar68 + iVar74;
          auVar59._12_4_ = iVar73 + iVar75;
          auVar42._4_4_ = uStack_8c;
          auVar42._0_4_ = local_90;
          auVar42._8_4_ = uStack_88;
          auVar42._12_4_ = uStack_84;
          auVar88 = pshuflw(auVar88,auVar59,0x4e);
          auVar89 = ZEXT416(param_3);
          auVar34._4_4_ = uStack_ac;
          auVar34._0_4_ = local_b0;
          auVar34._8_4_ = uStack_a8;
          auVar34._12_4_ = uStack_a4;
          iVar55 = (auVar88._0_4_ + auVar59._0_4_ >> auVar89) + iVar55;
          auVar9._20_4_ = (auVar88._4_4_ + auVar59._4_4_ >> auVar89) + iVar53;
          auVar9._16_4_ = iVar55;
          auVar9._24_4_ = (auVar88._8_4_ + auVar59._8_4_ >> auVar89) + iVar56;
          auVar9._28_4_ = (auVar88._12_4_ + auVar59._12_4_ >> auVar89) + iVar93;
          auVar9._0_16_ = local_50;
          auVar89 = pmulld(auVar34,auVar9._4_16_);
          auVar88 = pmulld(auVar42,auVar3._4_16_);
          iVar68 = auVar88._0_4_ + auVar89._0_4_;
          iVar73 = auVar88._4_4_ + auVar89._4_4_;
          iVar74 = auVar88._8_4_ + auVar89._8_4_;
          iVar75 = auVar88._12_4_ + auVar89._12_4_;
          auVar83._12_4_ = 0;
          auVar83._0_12_ = auVar27;
          auVar10._28_4_ = iVar55;
          auVar10._16_12_ = local_50._4_12_;
          auVar60._0_4_ = iVar74 + iVar68;
          auVar60._4_4_ = iVar75 + iVar73;
          auVar60._8_4_ = iVar68 + iVar74;
          auVar60._12_4_ = iVar73 + iVar75;
          auVar10._0_16_ = auVar3._4_16_;
          auVar43._4_4_ = uStack_8c;
          auVar43._0_4_ = local_90;
          auVar43._8_4_ = uStack_88;
          auVar43._12_4_ = uStack_84;
          auVar88 = pshuflw(auVar90,auVar60,0x4e);
          auVar89 = ZEXT416(param_3);
          auVar35._4_4_ = uStack_ac;
          auVar35._0_4_ = local_b0;
          auVar35._8_4_ = uStack_a8;
          auVar35._12_4_ = uStack_a4;
          iVar53 = (auVar88._0_4_ + auVar60._0_4_ >> auVar89) + iVar53;
          auVar11._20_4_ = (auVar88._4_4_ + auVar60._4_4_ >> auVar89) + iVar56;
          auVar11._16_4_ = iVar53;
          auVar11._24_4_ = (auVar88._8_4_ + auVar60._8_4_ >> auVar89) + iVar93;
          auVar11._28_4_ = auVar88._12_4_ + auVar60._12_4_ >> auVar89;
          auVar11._0_16_ = auVar9._4_16_;
          auVar91 = auVar11._4_16_;
          auVar89 = pmulld(auVar35,auVar91);
          auVar88 = pmulld(auVar43,auVar10._4_16_);
          iVar68 = auVar88._0_4_ + auVar89._0_4_;
          iVar73 = auVar88._4_4_ + auVar89._4_4_;
          iVar74 = auVar88._8_4_ + auVar89._8_4_;
          iVar75 = auVar88._12_4_ + auVar89._12_4_;
          auVar88._8_8_ = 0;
          auVar88._0_8_ = auVar90._8_8_;
          auVar12._24_4_ = iVar55;
          auVar12._16_8_ = local_50._8_8_;
          auVar12._28_4_ = iVar53;
          auVar61._0_4_ = iVar74 + iVar68;
          auVar61._4_4_ = iVar75 + iVar73;
          auVar61._8_4_ = iVar68 + iVar74;
          auVar61._12_4_ = iVar73 + iVar75;
          auVar12._0_16_ = auVar10._4_16_;
          auVar44._4_4_ = uStack_8c;
          auVar44._0_4_ = local_90;
          auVar44._8_4_ = uStack_88;
          auVar44._12_4_ = uStack_84;
          auVar82 = pshuflw(auVar83,auVar61,0x4e);
          auVar89 = ZEXT416(param_3);
          auVar36._4_4_ = uStack_ac;
          auVar36._0_4_ = local_b0;
          auVar36._8_4_ = uStack_a8;
          auVar36._12_4_ = uStack_a4;
          iVar56 = (auVar82._0_4_ + auVar61._0_4_ >> auVar89) + iVar56;
          auVar13._20_4_ = (auVar82._4_4_ + auVar61._4_4_ >> auVar89) + iVar93;
          auVar13._16_4_ = iVar56;
          auVar13._24_4_ = auVar82._8_4_ + auVar61._8_4_ >> auVar89;
          auVar13._28_4_ = auVar82._12_4_ + auVar61._12_4_ >> auVar89;
          auVar13._0_16_ = auVar91;
          auVar89 = pmulld(auVar36,auVar13._4_16_);
          auVar82 = pmulld(auVar44,auVar12._4_16_);
          iVar55 = auVar82._0_4_ + auVar89._0_4_;
          iVar68 = auVar82._4_4_ + auVar89._4_4_;
          iVar73 = auVar82._8_4_ + auVar89._8_4_;
          iVar74 = auVar82._12_4_ + auVar89._12_4_;
          auVar62._0_4_ = iVar73 + iVar55;
          auVar62._4_4_ = iVar74 + iVar68;
          auVar62._8_4_ = iVar55 + iVar73;
          auVar62._12_4_ = iVar68 + iVar74;
          auVar14._24_4_ = iVar53;
          auVar14._16_8_ = auVar9._12_8_;
          auVar14._28_4_ = iVar56;
          auVar82 = pshuflw(auVar91,auVar62,0x4e);
          auVar14._0_16_ = auVar12._4_16_;
          local_70 = auVar14._4_16_;
          auVar89 = ZEXT416(param_3);
          auVar15._20_4_ = auVar82._4_4_ + auVar62._4_4_ >> auVar89;
          auVar15._16_4_ = (auVar82._0_4_ + auVar62._0_4_ >> auVar89) + iVar93;
          auVar15._24_4_ = auVar82._8_4_ + auVar62._8_4_ >> auVar89;
          auVar15._28_4_ = auVar82._12_4_ + auVar62._12_4_ >> auVar89;
          auVar15._0_16_ = auVar13._4_16_;
          local_50 = auVar15._4_16_;
        }
        else {
          auVar29._4_4_ = uStack_bc;
          auVar29._0_4_ = local_c0;
          auVar29._8_4_ = uStack_b8;
          auVar29._12_4_ = uStack_b4;
          auVar82 = pmulld(auVar29,local_a0);
          auVar45._4_4_ = uStack_8c;
          auVar45._0_4_ = local_90;
          auVar45._8_4_ = uStack_88;
          auVar45._12_4_ = uStack_84;
          auVar89 = pmulld(auVar45,local_70);
          auVar4._16_16_ = local_70;
          auVar4._0_16_ = local_a0;
          auVar37._4_4_ = uStack_ac;
          auVar37._0_4_ = local_b0;
          auVar37._8_4_ = uStack_a8;
          auVar37._12_4_ = uStack_a4;
          auVar88 = pmulld(auVar37,local_50);
          iVar68 = auVar82._0_4_ + auVar89._0_4_ + auVar88._0_4_;
          iVar73 = auVar82._4_4_ + auVar89._4_4_ + auVar88._4_4_;
          iVar74 = auVar82._8_4_ + auVar89._8_4_ + auVar88._8_4_;
          iVar75 = auVar82._12_4_ + auVar89._12_4_ + auVar88._12_4_;
          auVar16._16_16_ = local_50;
          auVar16._0_16_ = local_70;
          auVar91 = auVar16._4_16_;
          auVar17._28_4_ = local_50._0_4_;
          auVar17._16_12_ = local_70._4_12_;
          auVar63._0_4_ = iVar74 + iVar68;
          auVar63._4_4_ = iVar75 + iVar73;
          auVar63._8_4_ = iVar68 + iVar74;
          auVar63._12_4_ = iVar73 + iVar75;
          auVar17._0_16_ = auVar4._4_16_;
          auVar88 = auVar17._4_16_;
          auVar30._4_4_ = uStack_bc;
          auVar30._0_4_ = local_c0;
          auVar30._8_4_ = uStack_b8;
          auVar30._12_4_ = uStack_b4;
          auVar94 = pshuflw(auVar64,auVar63,0x4e);
          auVar64 = ZEXT416(param_3);
          auVar46._4_4_ = uStack_8c;
          auVar46._0_4_ = local_90;
          auVar46._8_4_ = uStack_88;
          auVar46._12_4_ = uStack_84;
          auVar89 = pmulld(auVar46,auVar91);
          auVar82 = pmulld(auVar30,auVar4._4_16_);
          iVar55 = (auVar94._0_4_ + auVar63._0_4_ >> auVar64) + iVar55;
          auVar18._20_4_ = (auVar94._4_4_ + auVar63._4_4_ >> auVar64) + iVar53;
          auVar18._16_4_ = iVar55;
          auVar18._24_4_ = (auVar94._8_4_ + auVar63._8_4_ >> auVar64) + iVar56;
          auVar18._28_4_ = (auVar94._12_4_ + auVar63._12_4_ >> auVar64) + iVar93;
          auVar38._4_4_ = uStack_ac;
          auVar38._0_4_ = local_b0;
          auVar38._8_4_ = uStack_a8;
          auVar38._12_4_ = uStack_a4;
          auVar18._0_16_ = local_50;
          auVar64 = pmulld(auVar38,auVar18._4_16_);
          iVar68 = auVar82._0_4_ + auVar89._0_4_ + auVar64._0_4_;
          iVar73 = auVar82._4_4_ + auVar89._4_4_ + auVar64._4_4_;
          iVar74 = auVar82._8_4_ + auVar89._8_4_ + auVar64._8_4_;
          iVar75 = auVar82._12_4_ + auVar89._12_4_ + auVar64._12_4_;
          auVar86._12_4_ = 0;
          auVar86._0_12_ = auVar27;
          auVar19._28_4_ = iVar55;
          auVar19._16_12_ = local_50._4_12_;
          auVar65._0_4_ = iVar74 + iVar68;
          auVar65._4_4_ = iVar75 + iVar73;
          auVar65._8_4_ = iVar68 + iVar74;
          auVar65._12_4_ = iVar73 + iVar75;
          auVar19._0_16_ = auVar91;
          auVar92 = auVar19._4_16_;
          auVar31._4_4_ = uStack_bc;
          auVar31._0_4_ = local_c0;
          auVar31._8_4_ = uStack_b8;
          auVar31._12_4_ = uStack_b4;
          auVar20._24_4_ = local_50._0_4_;
          auVar20._16_8_ = local_70._8_8_;
          auVar20._28_4_ = local_50._4_4_;
          auVar91 = pshuflw(auVar91,auVar65,0x4e);
          auVar20._0_16_ = auVar88;
          auVar82 = pmulld(auVar31,auVar88);
          auVar64 = ZEXT416(param_3);
          auVar47._4_4_ = uStack_8c;
          auVar47._0_4_ = local_90;
          auVar47._8_4_ = uStack_88;
          auVar47._12_4_ = uStack_84;
          auVar89 = pmulld(auVar47,auVar92);
          auVar21._20_4_ = (auVar91._4_4_ + auVar65._4_4_ >> auVar64) + iVar56;
          auVar21._16_4_ = (auVar91._0_4_ + auVar65._0_4_ >> auVar64) + iVar53;
          auVar21._24_4_ = (auVar91._8_4_ + auVar65._8_4_ >> auVar64) + iVar93;
          auVar21._28_4_ = auVar91._12_4_ + auVar65._12_4_ >> auVar64;
          auVar39._4_4_ = uStack_ac;
          auVar39._0_4_ = local_b0;
          auVar39._8_4_ = uStack_a8;
          auVar39._12_4_ = uStack_a4;
          auVar21._0_16_ = auVar18._4_16_;
          auVar94 = auVar21._4_16_;
          auVar64 = pmulld(auVar39,auVar94);
          iVar55 = auVar82._0_4_ + auVar89._0_4_ + auVar64._0_4_;
          iVar53 = auVar82._4_4_ + auVar89._4_4_ + auVar64._4_4_;
          iVar68 = auVar82._8_4_ + auVar89._8_4_ + auVar64._8_4_;
          iVar73 = auVar82._12_4_ + auVar89._12_4_ + auVar64._12_4_;
          auVar64._8_8_ = 0;
          auVar64._0_8_ = auVar90._8_8_;
          auVar66._0_4_ = iVar68 + iVar55;
          auVar66._4_4_ = iVar73 + iVar53;
          auVar66._8_4_ = iVar55 + iVar68;
          auVar66._12_4_ = iVar53 + iVar73;
          auVar32._4_4_ = uStack_bc;
          auVar32._0_4_ = local_c0;
          auVar32._8_4_ = uStack_b8;
          auVar32._12_4_ = uStack_b4;
          auVar87 = pshuflw(auVar86,auVar66,0x4e);
          auVar22._16_16_ = auVar94;
          auVar22._0_16_ = auVar92;
          auVar89 = ZEXT416(param_3);
          auVar48._4_4_ = uStack_8c;
          auVar48._0_4_ = local_90;
          auVar48._8_4_ = uStack_88;
          auVar48._12_4_ = uStack_84;
          auVar91 = pmulld(auVar32,auVar20._4_16_);
          auVar82 = pmulld(auVar48,auVar22._4_16_);
          iVar56 = (auVar87._0_4_ + auVar66._0_4_ >> auVar89) + iVar56;
          auVar5._20_4_ = (auVar87._4_4_ + auVar66._4_4_ >> auVar89) + iVar93;
          auVar5._16_4_ = iVar56;
          auVar5._24_4_ = auVar87._8_4_ + auVar66._8_4_ >> auVar89;
          auVar5._28_4_ = auVar87._12_4_ + auVar66._12_4_ >> auVar89;
          auVar5._0_16_ = auVar94;
          auVar40._4_4_ = uStack_ac;
          auVar40._0_4_ = local_b0;
          auVar40._8_4_ = uStack_a8;
          auVar40._12_4_ = uStack_a4;
          auVar89 = pmulld(auVar40,auVar5._4_16_);
          iVar55 = auVar91._0_4_ + auVar82._0_4_ + auVar89._0_4_;
          iVar53 = auVar91._4_4_ + auVar82._4_4_ + auVar89._4_4_;
          iVar68 = auVar91._8_4_ + auVar82._8_4_ + auVar89._8_4_;
          iVar73 = auVar91._12_4_ + auVar82._12_4_ + auVar89._12_4_;
          auVar67._0_4_ = iVar68 + iVar55;
          auVar67._4_4_ = iVar73 + iVar53;
          auVar67._8_4_ = iVar55 + iVar68;
          auVar67._12_4_ = iVar53 + iVar73;
          auVar23._24_4_ = local_50._4_4_;
          auVar23._16_8_ = auVar16._12_8_;
          auVar23._28_4_ = local_50._8_4_;
          auVar23._0_16_ = auVar20._4_16_;
          local_a0 = auVar23._4_16_;
          auVar24._28_4_ = iVar56;
          auVar24._16_12_ = auVar21._8_12_;
          auVar24._0_16_ = auVar22._4_16_;
          local_70 = auVar24._4_16_;
          auVar82 = pshuflw(auVar92,auVar67,0x4e);
          auVar89 = ZEXT416(param_3);
          auVar25._20_4_ = auVar82._4_4_ + auVar67._4_4_ >> auVar89;
          auVar25._16_4_ = (auVar82._0_4_ + auVar67._0_4_ >> auVar89) + iVar93;
          auVar25._24_4_ = auVar82._8_4_ + auVar67._8_4_ >> auVar89;
          auVar25._28_4_ = auVar82._12_4_ + auVar67._12_4_ >> auVar89;
          auVar25._0_16_ = auVar5._4_16_;
          local_50 = auVar25._4_16_;
        }
      }
      *local_18 = local_50;
      local_18 = local_18 + 1;
    } while (local_18 < local_5c);
  }
  if ((int)local_54 < (int)local_58) {
    local_5c = (undefined1 (*) [16])(0x20 - (local_24 + 1));
    do {
      uVar51 = *(uint *)(in_ECX + 0x101c);
      iVar56 = *(int *)(in_ECX + 0x18);
      if (DAT_1005109c == 0) {
        if (uVar51 == 0) {
          uVar52 = 0x20;
        }
        else {
          iVar55 = 0x1f;
          if (uVar51 != 0) {
            for (; uVar51 >> iVar55 == 0; iVar55 = iVar55 + -1) {
            }
          }
          uVar52 = 0x1f - iVar55;
        }
      }
      else {
        uVar52 = LZCOUNT(uVar51);
      }
      if (uVar52 < 0x20) {
        local_28 = uVar52;
      }
      else {
        local_28 = 0x20 - iVar56;
        do {
          uVar51 = *(uint *)(in_ECX + 0x14);
          if (uVar51 < 0x400) {
            uVar52 = *(uint *)(in_ECX + 0x1c + uVar51 * 4);
            *(uint *)(in_ECX + 0x14) = uVar51 + 1;
            iVar56 = 0;
            uVar51 = uVar52 >> 0x18 | (uVar52 & 0xff0000) >> 8 | (uVar52 & 0xff00) << 8 |
                     uVar52 << 0x18;
          }
          else {
            iVar56 = FUN_1002d310();
            if (iVar56 == 0) {
              return 0;
            }
            uVar51 = *(uint *)(in_ECX + 0x101c);
            iVar56 = *(int *)(in_ECX + 0x18);
          }
          if (DAT_1005109c == 0) {
            if (uVar51 == 0) {
              uVar52 = 0x20;
            }
            else {
              iVar55 = 0x1f;
              if (uVar51 != 0) {
                for (; uVar51 >> iVar55 == 0; iVar55 = iVar55 + -1) {
                }
              }
              uVar52 = 0x1f - iVar55;
            }
          }
          else {
            uVar52 = LZCOUNT(uVar51);
          }
          local_28 = local_28 + uVar52;
        } while (0x1f < uVar52);
      }
      uVar51 = uVar51 << ((byte)uVar52 & 0x1f);
      uVar52 = iVar56 + uVar52;
      local_1c = uVar51 >> ((byte)local_5c & 0x1f);
      if (local_5c < uVar52) {
        uVar52 = uVar52 - (int)local_5c;
        uVar51 = *(uint *)(in_ECX + 0x14);
        local_20 = uVar52;
        if (uVar51 < 0x400) {
          uVar57 = *(uint *)(in_ECX + 0x1c + uVar51 * 4);
          *(uint *)(in_ECX + 0x14) = uVar51 + 1;
          uVar51 = uVar57 >> 0x18 | (uVar57 & 0xff0000) >> 8 | (uVar57 & 0xff00) << 8 |
                   uVar57 << 0x18;
        }
        else {
          iVar56 = FUN_1002d310();
          if (iVar56 == 0) {
                    /* WARNING: Read-only address (ram,0x100479d0) is written */
                    /* WARNING: Read-only address (ram,0x10047d70) is written */
            return 0;
          }
          uVar52 = *(int *)(in_ECX + 0x18) + local_20;
          uVar51 = *(uint *)(in_ECX + 0x101c);
        }
        iVar56 = uVar51 << ((byte)local_20 & 0x1f);
        local_1c = local_1c | uVar51 >> (0x20 - (byte)local_20 & 0x1f);
      }
      else {
        iVar56 = uVar51 << ((byte)(local_24 + 1) & 0x1f);
        uVar52 = uVar52 + local_24 + 1;
        in_ECX = local_74;
      }
      *(int *)(in_ECX + 0x101c) = iVar56;
      local_1c = local_1c & local_d4[2] | local_28 << ((byte)local_24 & 0x1f);
      *(uint *)(in_ECX + 0x18) = uVar52;
      iVar56 = 0;
      switch(param_2) {
      case 1:
        break;
      case 2:
        iVar56 = *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 3:
        iVar56 = *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 4:
        iVar56 = *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 5:
        iVar56 = *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 6:
        iVar56 = *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 7:
        iVar56 = *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 8:
        iVar56 = *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 9:
        iVar56 = *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 10:
        iVar56 = *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0xb:
        iVar56 = *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0xc:
        iVar56 = *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0xd:
        iVar56 = *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0xe:
        iVar56 = *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0xf:
        iVar56 = *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x10:
        iVar56 = *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x11:
        iVar56 = *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x12:
        iVar56 = *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x13:
        iVar56 = *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x14:
        iVar56 = *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x15:
        iVar56 = *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x16:
        iVar56 = *(int *)(local_14[5] + 4) * *(int *)(local_18[-6] + 8) +
                 *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x17:
        iVar56 = *(int *)(local_14[5] + 8) * *(int *)(local_18[-6] + 4) +
                 *(int *)(local_14[5] + 4) * *(int *)(local_18[-6] + 8) +
                 *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x18:
        iVar56 = *(int *)(local_14[5] + 0xc) * *(int *)local_18[-6] +
                 *(int *)(local_14[5] + 8) * *(int *)(local_18[-6] + 4) +
                 *(int *)(local_14[5] + 4) * *(int *)(local_18[-6] + 8) +
                 *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x19:
        iVar56 = *(int *)local_14[6] * *(int *)(local_18[-7] + 0xc) +
                 *(int *)(local_14[5] + 0xc) * *(int *)local_18[-6] +
                 *(int *)(local_14[5] + 8) * *(int *)(local_18[-6] + 4) +
                 *(int *)(local_14[5] + 4) * *(int *)(local_18[-6] + 8) +
                 *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x1a:
        iVar56 = *(int *)(local_14[6] + 4) * *(int *)(local_18[-7] + 8) +
                 *(int *)local_14[6] * *(int *)(local_18[-7] + 0xc) +
                 *(int *)(local_14[5] + 0xc) * *(int *)local_18[-6] +
                 *(int *)(local_14[5] + 8) * *(int *)(local_18[-6] + 4) +
                 *(int *)(local_14[5] + 4) * *(int *)(local_18[-6] + 8) +
                 *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x1b:
        iVar56 = *(int *)(local_14[6] + 8) * *(int *)(local_18[-7] + 4) +
                 *(int *)(local_14[6] + 4) * *(int *)(local_18[-7] + 8) +
                 *(int *)local_14[6] * *(int *)(local_18[-7] + 0xc) +
                 *(int *)(local_14[5] + 0xc) * *(int *)local_18[-6] +
                 *(int *)(local_14[5] + 8) * *(int *)(local_18[-6] + 4) +
                 *(int *)(local_14[5] + 4) * *(int *)(local_18[-6] + 8) +
                 *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x1c:
        iVar56 = *(int *)(local_14[6] + 0xc) * *(int *)local_18[-7] +
                 *(int *)(local_14[6] + 8) * *(int *)(local_18[-7] + 4) +
                 *(int *)(local_14[6] + 4) * *(int *)(local_18[-7] + 8) +
                 *(int *)local_14[6] * *(int *)(local_18[-7] + 0xc) +
                 *(int *)(local_14[5] + 0xc) * *(int *)local_18[-6] +
                 *(int *)(local_14[5] + 8) * *(int *)(local_18[-6] + 4) +
                 *(int *)(local_14[5] + 4) * *(int *)(local_18[-6] + 8) +
                 *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x1d:
        iVar56 = *(int *)local_14[7] * *(int *)(local_18[-8] + 0xc) +
                 *(int *)(local_14[6] + 0xc) * *(int *)local_18[-7] +
                 *(int *)(local_14[6] + 8) * *(int *)(local_18[-7] + 4) +
                 *(int *)(local_14[6] + 4) * *(int *)(local_18[-7] + 8) +
                 *(int *)local_14[6] * *(int *)(local_18[-7] + 0xc) +
                 *(int *)(local_14[5] + 0xc) * *(int *)local_18[-6] +
                 *(int *)(local_14[5] + 8) * *(int *)(local_18[-6] + 4) +
                 *(int *)(local_14[5] + 4) * *(int *)(local_18[-6] + 8) +
                 *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x1e:
        iVar56 = *(int *)(local_14[7] + 4) * *(int *)(local_18[-8] + 8) +
                 *(int *)local_14[7] * *(int *)(local_18[-8] + 0xc) +
                 *(int *)(local_14[6] + 0xc) * *(int *)local_18[-7] +
                 *(int *)(local_14[6] + 8) * *(int *)(local_18[-7] + 4) +
                 *(int *)(local_14[6] + 4) * *(int *)(local_18[-7] + 8) +
                 *(int *)local_14[6] * *(int *)(local_18[-7] + 0xc) +
                 *(int *)(local_14[5] + 0xc) * *(int *)local_18[-6] +
                 *(int *)(local_14[5] + 8) * *(int *)(local_18[-6] + 4) +
                 *(int *)(local_14[5] + 4) * *(int *)(local_18[-6] + 8) +
                 *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x1f:
        iVar56 = *(int *)(local_14[7] + 8) * *(int *)(local_18[-8] + 4) +
                 *(int *)(local_14[7] + 4) * *(int *)(local_18[-8] + 8) +
                 *(int *)local_14[7] * *(int *)(local_18[-8] + 0xc) +
                 *(int *)(local_14[6] + 0xc) * *(int *)local_18[-7] +
                 *(int *)(local_14[6] + 8) * *(int *)(local_18[-7] + 4) +
                 *(int *)(local_14[6] + 4) * *(int *)(local_18[-7] + 8) +
                 *(int *)local_14[6] * *(int *)(local_18[-7] + 0xc) +
                 *(int *)(local_14[5] + 0xc) * *(int *)local_18[-6] +
                 *(int *)(local_14[5] + 8) * *(int *)(local_18[-6] + 4) +
                 *(int *)(local_14[5] + 4) * *(int *)(local_18[-6] + 8) +
                 *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      case 0x20:
        iVar56 = *(int *)(local_14[7] + 0xc) * *(int *)local_18[-8] +
                 *(int *)(local_14[7] + 8) * *(int *)(local_18[-8] + 4) +
                 *(int *)(local_14[7] + 4) * *(int *)(local_18[-8] + 8) +
                 *(int *)local_14[7] * *(int *)(local_18[-8] + 0xc) +
                 *(int *)(local_14[6] + 0xc) * *(int *)local_18[-7] +
                 *(int *)(local_14[6] + 8) * *(int *)(local_18[-7] + 4) +
                 *(int *)(local_14[6] + 4) * *(int *)(local_18[-7] + 8) +
                 *(int *)local_14[6] * *(int *)(local_18[-7] + 0xc) +
                 *(int *)(local_14[5] + 0xc) * *(int *)local_18[-6] +
                 *(int *)(local_14[5] + 8) * *(int *)(local_18[-6] + 4) +
                 *(int *)(local_14[5] + 4) * *(int *)(local_18[-6] + 8) +
                 *(int *)local_14[5] * *(int *)(local_18[-6] + 0xc) +
                 *(int *)(local_14[4] + 0xc) * *(int *)local_18[-5] +
                 *(int *)(local_14[4] + 8) * *(int *)(local_18[-5] + 4) +
                 *(int *)(local_14[4] + 4) * *(int *)(local_18[-5] + 8) +
                 *(int *)local_14[4] * *(int *)(local_18[-5] + 0xc) +
                 *(int *)(local_14[3] + 0xc) * *(int *)local_18[-4] +
                 *(int *)(local_14[3] + 8) * *(int *)(local_18[-4] + 4) +
                 *(int *)(local_14[3] + 4) * *(int *)(local_18[-4] + 8) +
                 *(int *)local_14[3] * *(int *)(local_18[-4] + 0xc) +
                 *(int *)(local_14[2] + 0xc) * *(int *)local_18[-3] +
                 *(int *)(local_14[2] + 8) * *(int *)(local_18[-3] + 4) +
                 *(int *)(local_14[2] + 4) * *(int *)(local_18[-3] + 8) +
                 *(int *)local_14[2] * *(int *)(local_18[-3] + 0xc) +
                 *(int *)(local_14[1] + 0xc) * *(int *)local_18[-2] +
                 *(int *)(local_14[1] + 8) * *(int *)(local_18[-2] + 4) +
                 *(int *)(local_14[1] + 4) * *(int *)(local_18[-2] + 8) +
                 *(int *)local_14[1] * *(int *)(local_18[-2] + 0xc) +
                 *(int *)(*local_14 + 0xc) * *(int *)local_18[-1] +
                 *(int *)(*local_14 + 8) * *(int *)(local_18[-1] + 4) +
                 *(int *)(*local_14 + 4) * *(int *)(local_18[-1] + 8);
        break;
      default:
        goto switchD_100316e5_default;
      }
      iVar56 = iVar56 + *(int *)(local_18[-1] + 0xc) * *(int *)*local_14;
switchD_100316e5_default:
      local_54 = local_54 + 1;
      *(uint *)*local_18 =
           (iVar56 >> ((byte)param_3 & 0x1f)) + (local_1c >> 1 ^ local_d4[local_1c & 1]);
      local_18 = (undefined1 (*) [16])(*local_18 + 4);
    } while ((int)local_54 < (int)local_58);
  }
  return 1;
}

