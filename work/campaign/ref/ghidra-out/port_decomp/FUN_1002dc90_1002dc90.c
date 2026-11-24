
undefined4
FUN_1002dc90(uint param_1,uint param_2,int param_3,int param_4,int *param_5,uint *param_6)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  byte bVar9;
  byte bVar10;
  uint in_ECX;
  uint uVar11;
  uint in_EDX;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  bool bVar16;
  uint local_74 [5];
  uint local_60;
  uint *local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  undefined8 local_4c;
  undefined8 local_44;
  uint *local_38;
  undefined8 local_34;
  uint local_28;
  uint local_24;
  uint local_20;
  undefined8 local_1c;
  uint local_10;
  int *local_c;
  uint *local_8;
  
  local_c = param_5;
  local_8 = param_6;
  local_74[4] = in_ECX;
  local_10 = in_EDX;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  local_74[0] = 0;
  local_74[1] = 0xffffffff;
  if (param_3 == 0) {
    uVar5 = FUN_1002dae0(param_1,param_2,0,param_4,param_5,param_6);
    return uVar5;
  }
  local_58 = param_2 & 0xff;
  local_60 = ~(-1 << ((byte)param_2 & 0x1f));
  local_5c = param_6 + (param_1 & 0xfffffffc);
  uVar6 = param_4 + local_10;
  bVar9 = (byte)param_4;
  if (param_6 < param_6 + (param_1 & 0xfffffffc)) {
    iVar13 = (param_2 & 0xff) + 1;
    if (uVar6 < 0x21) {
      local_38 = (uint *)(0x20 - iVar13);
      do {
        iVar13 = *(int *)(in_ECX + 0x18);
        uVar12 = *(uint *)(in_ECX + 0x101c);
        if (DAT_1005109c == 0) {
          if (uVar12 == 0) {
            local_1c._4_4_ = 0x20;
          }
          else {
            iVar15 = 0x1f;
            if (uVar12 != 0) {
              for (; uVar12 >> iVar15 == 0; iVar15 = iVar15 + -1) {
              }
            }
            local_1c._4_4_ = 0x1f - iVar15;
          }
        }
        else {
          local_1c._4_4_ = LZCOUNT(uVar12);
        }
        local_34._4_4_ = iVar13;
        if (local_1c._4_4_ < 0x20) {
          local_50 = local_1c._4_4_;
          uVar7 = local_1c._4_4_;
        }
        else {
          local_50 = 0x20 - iVar13;
          do {
            uVar12 = *(uint *)(in_ECX + 0x14);
            if (uVar12 < 0x400) {
              uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
              *(uint *)(in_ECX + 0x14) = uVar12 + 1;
              local_34._4_4_ = 0;
              uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                       uVar7 << 0x18;
            }
            else {
              iVar13 = FUN_1002d310();
              if (iVar13 == 0) {
                return 0;
              }
              uVar12 = *(uint *)(in_ECX + 0x101c);
              local_34._4_4_ = *(int *)(in_ECX + 0x18);
            }
            if (DAT_1005109c == 0) {
              if (uVar12 == 0) {
                uVar7 = 0x20;
              }
              else {
                iVar13 = 0x1f;
                if (uVar12 != 0) {
                  for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
                  }
                }
                uVar7 = 0x1f - iVar13;
              }
            }
            else {
              uVar7 = LZCOUNT(uVar12);
            }
            local_50 = local_50 + uVar7;
          } while (0x1f < uVar7);
        }
        uVar12 = uVar12 << ((byte)uVar7 & 0x1f);
        puVar8 = (uint *)(local_34._4_4_ + uVar7);
        uVar7 = uVar12 >> ((byte)local_38 & 0x1f);
        local_44 = CONCAT44(uVar7,(undefined4)local_44);
        if (local_38 < puVar8) {
          uVar11 = (int)puVar8 - (int)local_38;
          uVar12 = *(uint *)(in_ECX + 0x14);
          local_10 = uVar11;
          local_1c._4_4_ = uVar7;
          if (uVar12 < 0x400) {
            uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
            *(uint *)(in_ECX + 0x14) = uVar12 + 1;
            uVar7 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
          }
          else {
            iVar13 = FUN_1002d310();
            if (iVar13 == 0) {
              return 0;
            }
            uVar11 = *(int *)(in_ECX + 0x18) + local_10;
            uVar7 = *(uint *)(in_ECX + 0x101c);
          }
          uVar12 = uVar7 << ((byte)local_10 & 0x1f);
          local_44 = CONCAT44(uVar7 >> (0x20 - (byte)local_10 & 0x1f) | local_1c._4_4_,
                              (undefined4)local_44);
          local_34._4_4_ = uVar11;
        }
        else {
          uVar12 = uVar12 << ((byte)(local_58 + 1) & 0x1f);
          param_6 = local_8;
          local_34._4_4_ = (int)puVar8 + local_58 + 1;
        }
        bVar16 = DAT_1005109c == 0;
        *(uint *)(in_ECX + 0x101c) = uVar12;
        *(uint *)(in_ECX + 0x18) = local_34._4_4_;
        if (bVar16) {
          if (uVar12 == 0) {
            uVar7 = 0x20;
          }
          else {
            iVar13 = 0x1f;
            if (uVar12 != 0) {
              for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
              }
            }
            uVar7 = 0x1f - iVar13;
          }
        }
        else {
          uVar7 = LZCOUNT(uVar12);
        }
        local_54 = uVar7;
        if (0x1f < uVar7) {
          local_54 = 0x20 - local_34._4_4_;
          do {
            uVar12 = *(uint *)(in_ECX + 0x14);
            if (uVar12 < 0x400) {
              uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
              *(uint *)(in_ECX + 0x14) = uVar12 + 1;
              local_34._4_4_ = 0;
              uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                       uVar7 << 0x18;
            }
            else {
              iVar13 = FUN_1002d310();
              if (iVar13 == 0) {
                return 0;
              }
              uVar12 = *(uint *)(in_ECX + 0x101c);
              local_34._4_4_ = *(uint *)(in_ECX + 0x18);
            }
            if (DAT_1005109c == 0) {
              if (uVar12 == 0) {
                uVar7 = 0x20;
              }
              else {
                iVar13 = 0x1f;
                if (uVar12 != 0) {
                  for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
                  }
                }
                uVar7 = 0x1f - iVar13;
              }
            }
            else {
              uVar7 = LZCOUNT(uVar12);
            }
            local_54 = local_54 + uVar7;
          } while (0x1f < uVar7);
        }
        uVar12 = uVar12 << ((byte)uVar7 & 0x1f);
        puVar8 = (uint *)(local_34._4_4_ + uVar7);
        local_1c._4_4_ = uVar12 >> ((byte)local_38 & 0x1f);
        if (local_38 < puVar8) {
          uVar7 = (int)puVar8 - (int)local_38;
          uVar12 = *(uint *)(in_ECX + 0x14);
          local_10 = uVar7;
          if (uVar12 < 0x400) {
            uVar11 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
            *(uint *)(in_ECX + 0x14) = uVar12 + 1;
            uVar11 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 |
                     uVar11 << 0x18;
          }
          else {
            iVar13 = FUN_1002d310();
            if (iVar13 == 0) {
              return 0;
            }
            uVar7 = *(int *)(in_ECX + 0x18) + local_10;
            uVar11 = *(uint *)(in_ECX + 0x101c);
          }
          uVar12 = uVar11 << ((byte)local_10 & 0x1f);
          local_1c = CONCAT44(local_1c._4_4_ | uVar11 >> (0x20 - (byte)local_10 & 0x1f),
                              (undefined4)local_1c);
        }
        else {
          uVar12 = uVar12 << ((byte)(local_58 + 1) & 0x1f);
          uVar7 = (int)puVar8 + local_58 + 1;
          param_5 = local_c;
        }
        bVar16 = DAT_1005109c == 0;
        *(uint *)(in_ECX + 0x101c) = uVar12;
        *(uint *)(in_ECX + 0x18) = uVar7;
        if (bVar16) {
          if (uVar12 == 0) {
            uVar11 = 0x20;
          }
          else {
            iVar13 = 0x1f;
            if (uVar12 != 0) {
              for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
              }
            }
            uVar11 = 0x1f - iVar13;
          }
        }
        else {
          uVar11 = LZCOUNT(uVar12);
        }
        local_28 = uVar11;
        local_34._4_4_ = uVar7;
        if (0x1f < uVar11) {
          local_28 = 0x20 - uVar7;
          do {
            uVar12 = *(uint *)(in_ECX + 0x14);
            if (uVar12 < 0x400) {
              uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
              *(uint *)(in_ECX + 0x14) = uVar12 + 1;
              local_34._4_4_ = 0;
              uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                       uVar7 << 0x18;
            }
            else {
              iVar13 = FUN_1002d310();
              if (iVar13 == 0) {
                return 0;
              }
              uVar12 = *(uint *)(in_ECX + 0x101c);
              local_34._4_4_ = *(uint *)(in_ECX + 0x18);
            }
            if (DAT_1005109c == 0) {
              if (uVar12 == 0) {
                uVar11 = 0x20;
              }
              else {
                iVar13 = 0x1f;
                if (uVar12 != 0) {
                  for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
                  }
                }
                uVar11 = 0x1f - iVar13;
              }
            }
            else {
              uVar11 = LZCOUNT(uVar12);
            }
            local_28 = local_28 + uVar11;
          } while (0x1f < uVar11);
        }
        uVar12 = uVar12 << ((byte)uVar11 & 0x1f);
        puVar8 = (uint *)(local_34._4_4_ + uVar11);
        local_20 = uVar12 >> ((byte)local_38 & 0x1f);
        if (local_38 < puVar8) {
          uVar7 = (int)puVar8 - (int)local_38;
          uVar12 = *(uint *)(in_ECX + 0x14);
          local_10 = uVar7;
          if (uVar12 < 0x400) {
            uVar11 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
            *(uint *)(in_ECX + 0x14) = uVar12 + 1;
            uVar11 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 |
                     uVar11 << 0x18;
          }
          else {
            iVar13 = FUN_1002d310();
            if (iVar13 == 0) {
              return 0;
            }
            uVar7 = *(int *)(in_ECX + 0x18) + local_10;
            uVar11 = *(uint *)(in_ECX + 0x101c);
          }
          local_34 = CONCAT44(uVar7,(undefined4)local_34);
          uVar12 = uVar11 << ((byte)local_10 & 0x1f);
          local_20 = local_20 | uVar11 >> (0x20 - (byte)local_10 & 0x1f);
        }
        else {
          uVar12 = uVar12 << ((byte)(local_58 + 1) & 0x1f);
          uVar7 = (int)puVar8 + local_58 + 1;
          local_34 = CONCAT44(uVar7,(undefined4)local_34);
          param_6 = local_8;
        }
        bVar16 = DAT_1005109c == 0;
        *(uint *)(in_ECX + 0x101c) = uVar12;
        *(uint *)(in_ECX + 0x18) = uVar7;
        if (bVar16) {
          if (uVar12 == 0) {
            uVar11 = 0x20;
          }
          else {
            iVar13 = 0x1f;
            if (uVar12 != 0) {
              for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
              }
            }
            uVar11 = 0x1f - iVar13;
            uVar7 = local_34._4_4_;
          }
        }
        else {
          uVar11 = LZCOUNT(uVar12);
        }
        if (uVar11 < 0x20) {
          local_4c = CONCAT44(uVar11,(undefined4)local_4c);
        }
        else {
          local_4c = CONCAT44(0x20 - uVar7,(undefined4)local_4c);
          do {
            uVar12 = *(uint *)(in_ECX + 0x14);
            if (uVar12 < 0x400) {
              uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
              *(uint *)(in_ECX + 0x14) = uVar12 + 1;
              uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                       uVar7 << 0x18;
              local_34 = local_34 & 0xffffffff;
            }
            else {
              iVar13 = FUN_1002d310();
              if (iVar13 == 0) {
                return 0;
              }
              uVar12 = *(uint *)(in_ECX + 0x101c);
              local_34 = CONCAT44(*(undefined4 *)(in_ECX + 0x18),(undefined4)local_34);
            }
            if (DAT_1005109c == 0) {
              if (uVar12 == 0) {
                uVar11 = 0x20;
              }
              else {
                iVar13 = 0x1f;
                if (uVar12 != 0) {
                  for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
                  }
                }
                uVar11 = 0x1f - iVar13;
              }
            }
            else {
              uVar11 = LZCOUNT(uVar12);
            }
            local_4c = CONCAT44(local_4c._4_4_ + uVar11,(undefined4)local_4c);
          } while (0x1f < uVar11);
        }
        uVar12 = uVar12 << ((byte)uVar11 & 0x1f);
        puVar8 = (uint *)(local_34._4_4_ + uVar11);
        local_24 = uVar12 >> ((byte)local_38 & 0x1f);
        if (local_38 < puVar8) {
          iVar13 = (int)puVar8 - (int)local_38;
          uVar12 = *(uint *)(in_ECX + 0x14);
          local_10 = iVar13;
          if (uVar12 < 0x400) {
            uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
            *(uint *)(in_ECX + 0x14) = uVar12 + 1;
            uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18
            ;
          }
          else {
            iVar13 = FUN_1002d310();
            if (iVar13 == 0) {
              return 0;
            }
            iVar13 = *(int *)(in_ECX + 0x18) + local_10;
            uVar12 = *(uint *)(in_ECX + 0x101c);
          }
          local_34 = CONCAT44(iVar13,(undefined4)local_34);
          iVar15 = uVar12 << ((byte)local_10 & 0x1f);
          local_24 = local_24 | uVar12 >> (0x20 - (byte)local_10 & 0x1f);
        }
        else {
          iVar15 = uVar12 << ((byte)(local_58 + 1) & 0x1f);
          iVar13 = (int)puVar8 + local_58 + 1;
          param_5 = local_c;
        }
        *(int *)(in_ECX + 0x18) = iVar13;
        *(int *)(in_ECX + 0x101c) = iVar15;
        bVar10 = (byte)local_58;
        local_50 = local_50 << (bVar10 & 0x1f) | (uint)local_44._4_4_ & local_60;
        local_54 = local_54 << (bVar10 & 0x1f) | local_1c._4_4_ & local_60;
        local_28 = local_28 << (bVar10 & 0x1f) | local_20 & local_60;
        uVar11 = local_4c._4_4_ << (bVar10 & 0x1f) | local_24 & local_60;
        uVar12 = local_74[local_50 & 1] ^ local_50 >> 1;
        local_1c = CONCAT44(uVar12,(undefined4)local_1c);
        local_20 = local_74[local_54 & 1] ^ local_54 >> 1;
        uVar7 = local_74[local_28 & 1] ^ local_28 >> 1;
        iVar13 = 0;
        local_24 = uVar7;
        uVar14 = uVar11 >> 1 ^ local_74[uVar11 & 1];
        uVar11 = param_3 - 1;
        local_4c = CONCAT44(uVar14,(undefined4)local_4c);
        local_10 = uVar11;
        switch(uVar11) {
        case 0x1f:
          iVar13 = param_5[0x1f] * param_6[-0x20];
        case 0x1e:
          iVar13 = iVar13 + param_5[0x1e] * param_6[-0x1f];
        case 0x1d:
          iVar13 = iVar13 + param_5[0x1d] * param_6[-0x1e];
        case 0x1c:
          iVar13 = iVar13 + param_5[0x1c] * param_6[-0x1d];
        case 0x1b:
          iVar13 = iVar13 + param_5[0x1b] * param_6[-0x1c];
        case 0x1a:
          iVar13 = iVar13 + param_5[0x1a] * param_6[-0x1b];
        case 0x19:
          iVar13 = iVar13 + param_5[0x19] * param_6[-0x1a];
        case 0x18:
          iVar13 = iVar13 + param_5[0x18] * param_6[-0x19];
        case 0x17:
          iVar13 = iVar13 + param_5[0x17] * param_6[-0x18];
        case 0x16:
          iVar13 = iVar13 + param_5[0x16] * param_6[-0x17];
        case 0x15:
          iVar13 = iVar13 + param_5[0x15] * param_6[-0x16];
        case 0x14:
          iVar13 = iVar13 + param_5[0x14] * param_6[-0x15];
        case 0x13:
          iVar13 = iVar13 + param_5[0x13] * param_6[-0x14];
        case 0x12:
          iVar13 = iVar13 + param_5[0x12] * param_6[-0x13];
        case 0x11:
          iVar13 = iVar13 + param_5[0x11] * param_6[-0x12];
        case 0x10:
          iVar13 = iVar13 + param_5[0x10] * param_6[-0x11];
        case 0xf:
          iVar13 = iVar13 + param_5[0xf] * param_6[-0x10];
        case 0xe:
          iVar13 = iVar13 + param_5[0xe] * param_6[-0xf];
        case 0xd:
          iVar13 = iVar13 + param_5[0xd] * param_6[-0xe];
        case 0xc:
          iVar13 = iVar13 + param_5[0xc] * param_6[-0xd];
        case 0xb:
          iVar13 = iVar13 + param_5[0xb] * param_6[-0xc];
        case 10:
          iVar13 = iVar13 + param_5[10] * param_6[-0xb];
        case 9:
          iVar13 = iVar13 + param_5[9] * param_6[-10];
        case 8:
          iVar13 = iVar13 + param_5[8] * param_6[-9];
        case 7:
          iVar13 = iVar13 + param_5[7] * param_6[-8];
        case 6:
          iVar13 = iVar13 + param_5[6] * param_6[-7];
        case 5:
          iVar13 = iVar13 + param_5[5] * param_6[-6];
        case 4:
          iVar13 = iVar13 + param_5[4] * param_6[-5];
        case 3:
          iVar13 = iVar13 + param_5[3] * param_6[-4];
        case 2:
          iVar13 = iVar13 + param_5[2] * param_6[-3];
        case 1:
          iVar13 = iVar13 + param_5[1] * param_6[-2];
        case 0:
          uVar12 = ((int)(param_6[-1] * *param_5 + iVar13) >> (bVar9 & 0x1f)) + uVar12;
          local_44 = CONCAT44(uVar12,(undefined4)local_44);
          *param_6 = uVar12;
LAB_1002fcde:
          iVar13 = 0;
          switch((&switchD_1002fce0::switchdataD_100306ac)[uVar11]) {
          case (undefined *)0x1002fce7:
            iVar13 = param_5[0x1f] * param_6[-0x1f];
          case (undefined *)0x1002fcee:
            iVar13 = iVar13 + param_5[0x1e] * param_6[-0x1e];
          case (undefined *)0x1002fcf7:
            iVar13 = iVar13 + param_5[0x1d] * param_6[-0x1d];
          case (undefined *)0x1002fd00:
            iVar13 = iVar13 + param_5[0x1c] * param_6[-0x1c];
          case (undefined *)0x1002fd09:
            iVar13 = iVar13 + param_5[0x1b] * param_6[-0x1b];
          case (undefined *)0x1002fd12:
            iVar13 = iVar13 + param_5[0x1a] * param_6[-0x1a];
          case (undefined *)0x1002fd1b:
            iVar13 = iVar13 + param_5[0x19] * param_6[-0x19];
          case (undefined *)0x1002fd24:
            iVar13 = iVar13 + param_5[0x18] * param_6[-0x18];
          case (undefined *)0x1002fd2d:
            iVar13 = iVar13 + param_5[0x17] * param_6[-0x17];
          case (undefined *)0x1002fd36:
            iVar13 = iVar13 + param_5[0x16] * param_6[-0x16];
          case (undefined *)0x1002fd3f:
            iVar13 = iVar13 + param_5[0x15] * param_6[-0x15];
          case (undefined *)0x1002fd48:
            iVar13 = iVar13 + param_5[0x14] * param_6[-0x14];
          case (undefined *)0x1002fd51:
            iVar13 = iVar13 + param_5[0x13] * param_6[-0x13];
          case (undefined *)0x1002fd5a:
            iVar13 = iVar13 + param_5[0x12] * param_6[-0x12];
          case (undefined *)0x1002fd63:
            iVar13 = iVar13 + param_5[0x11] * param_6[-0x11];
          case (undefined *)0x1002fd6c:
            iVar13 = iVar13 + param_5[0x10] * param_6[-0x10];
          case (undefined *)0x1002fd75:
            iVar13 = iVar13 + param_5[0xf] * param_6[-0xf];
          case (undefined *)0x1002fd7e:
            iVar13 = iVar13 + param_5[0xe] * param_6[-0xe];
          case (undefined *)0x1002fd87:
            iVar13 = iVar13 + param_5[0xd] * param_6[-0xd];
          case (undefined *)0x1002fd90:
            iVar13 = iVar13 + param_5[0xc] * param_6[-0xc];
          case (undefined *)0x1002fd99:
            iVar13 = iVar13 + param_5[0xb] * param_6[-0xb];
          case (undefined *)0x1002fda2:
            iVar13 = iVar13 + param_5[10] * param_6[-10];
          case (undefined *)0x1002fdab:
            iVar13 = iVar13 + param_5[9] * param_6[-9];
          case (undefined *)0x1002fdb4:
            iVar13 = iVar13 + param_5[8] * param_6[-8];
          case (undefined *)0x1002fdbd:
            iVar13 = iVar13 + param_5[7] * param_6[-7];
          case (undefined *)0x1002fdc6:
            iVar13 = iVar13 + param_5[6] * param_6[-6];
          case (undefined *)0x1002fdcf:
            iVar13 = iVar13 + param_5[5] * param_6[-5];
          case (undefined *)0x1002fdd8:
            iVar13 = iVar13 + param_5[4] * param_6[-4];
          case (undefined *)0x1002fde1:
            iVar13 = iVar13 + param_5[3] * param_6[-3];
          case (undefined *)0x1002fdea:
            iVar13 = iVar13 + param_5[2] * param_6[-2];
          case (undefined *)0x1002fdf3:
            iVar13 = iVar13 + param_5[1] * param_6[-1];
          case (undefined *)0x1002fdff:
            uVar12 = (*param_5 * (int)local_44._4_4_ + iVar13 >> (bVar9 & 0x1f)) + local_20;
            local_1c = CONCAT44(uVar12,(undefined4)local_1c);
            param_6[1] = uVar12;
          }
LAB_1002fe30:
          iVar13 = 0;
          switch((&switchD_1002fe32::switchdataD_1003072c)[uVar11]) {
          case (undefined *)0x1002fe39:
            iVar13 = param_5[0x1f] * param_6[-0x1e];
          case (undefined *)0x1002fe40:
            iVar13 = iVar13 + param_5[0x1e] * param_6[-0x1d];
          case (undefined *)0x1002fe49:
            iVar13 = iVar13 + param_5[0x1d] * param_6[-0x1c];
          case (undefined *)0x1002fe52:
            iVar13 = iVar13 + param_5[0x1c] * param_6[-0x1b];
          case (undefined *)0x1002fe5b:
            iVar13 = iVar13 + param_5[0x1b] * param_6[-0x1a];
          case (undefined *)0x1002fe64:
            iVar13 = iVar13 + param_5[0x1a] * param_6[-0x19];
          case (undefined *)0x1002fe6d:
            iVar13 = iVar13 + param_5[0x19] * param_6[-0x18];
          case (undefined *)0x1002fe76:
            iVar13 = iVar13 + param_5[0x18] * param_6[-0x17];
          case (undefined *)0x1002fe7f:
            iVar13 = iVar13 + param_5[0x17] * param_6[-0x16];
          case (undefined *)0x1002fe88:
            iVar13 = iVar13 + param_5[0x16] * param_6[-0x15];
          case (undefined *)0x1002fe91:
            iVar13 = iVar13 + param_5[0x15] * param_6[-0x14];
          case (undefined *)0x1002fe9a:
            iVar13 = iVar13 + param_5[0x14] * param_6[-0x13];
          case (undefined *)0x1002fea3:
            iVar13 = iVar13 + param_5[0x13] * param_6[-0x12];
          case (undefined *)0x1002feac:
            iVar13 = iVar13 + param_5[0x12] * param_6[-0x11];
          case (undefined *)0x1002feb5:
            iVar13 = iVar13 + param_5[0x11] * param_6[-0x10];
          case (undefined *)0x1002febe:
            iVar13 = iVar13 + param_5[0x10] * param_6[-0xf];
          case (undefined *)0x1002fec7:
            iVar13 = iVar13 + param_5[0xf] * param_6[-0xe];
          case (undefined *)0x1002fed0:
            iVar13 = iVar13 + param_5[0xe] * param_6[-0xd];
          case (undefined *)0x1002fed9:
            iVar13 = iVar13 + param_5[0xd] * param_6[-0xc];
          case (undefined *)0x1002fee2:
            iVar13 = iVar13 + param_5[0xc] * param_6[-0xb];
          case (undefined *)0x1002feeb:
            iVar13 = iVar13 + param_5[0xb] * param_6[-10];
          case (undefined *)0x1002fef4:
            iVar13 = iVar13 + param_5[10] * param_6[-9];
          case (undefined *)0x1002fefd:
            iVar13 = iVar13 + param_5[9] * param_6[-8];
          case (undefined *)0x1002ff06:
            iVar13 = iVar13 + param_5[8] * param_6[-7];
          case (undefined *)0x1002ff0f:
            iVar13 = iVar13 + param_5[7] * param_6[-6];
          case (undefined *)0x1002ff18:
            iVar13 = iVar13 + param_5[6] * param_6[-5];
          case (undefined *)0x1002ff21:
            iVar13 = iVar13 + param_5[5] * param_6[-4];
          case (undefined *)0x1002ff2a:
            iVar13 = iVar13 + param_5[4] * param_6[-3];
          case (undefined *)0x1002ff33:
            iVar13 = iVar13 + param_5[3] * param_6[-2];
          case (undefined *)0x1002ff3c:
            iVar13 = iVar13 + param_5[2] * param_6[-1];
          case (undefined *)0x1002ff45:
            iVar13 = iVar13 + param_5[1] * (int)local_44._4_4_;
          case (undefined *)0x1002ff51:
            uVar7 = ((int)(*param_5 * local_1c._4_4_ + iVar13) >> (bVar9 & 0x1f)) + uVar7;
            local_10 = uVar7;
            param_6[2] = uVar7;
            in_ECX = local_74[4];
          }
LAB_1002ff83:
          iVar13 = 0;
          switch((&switchD_1002ff85::switchdataD_100307ac)[uVar11]) {
          case (undefined *)0x1002ff8c:
            iVar13 = param_5[0x1f] * param_6[-0x1d];
          case (undefined *)0x1002ff93:
            iVar13 = iVar13 + param_5[0x1e] * param_6[-0x1c];
          case (undefined *)0x1002ff9c:
            iVar13 = iVar13 + param_5[0x1d] * param_6[-0x1b];
          case (undefined *)0x1002ffa5:
            iVar13 = iVar13 + param_5[0x1c] * param_6[-0x1a];
          case (undefined *)0x1002ffae:
            iVar13 = iVar13 + param_5[0x1b] * param_6[-0x19];
          case (undefined *)0x1002ffb7:
            iVar13 = iVar13 + param_5[0x1a] * param_6[-0x18];
          case (undefined *)0x1002ffc0:
            iVar13 = iVar13 + param_5[0x19] * param_6[-0x17];
          case (undefined *)0x1002ffc9:
            iVar13 = iVar13 + param_5[0x18] * param_6[-0x16];
          case (undefined *)0x1002ffd2:
            iVar13 = iVar13 + param_5[0x17] * param_6[-0x15];
          case (undefined *)0x1002ffdb:
            iVar13 = iVar13 + param_5[0x16] * param_6[-0x14];
          case (undefined *)0x1002ffe4:
            iVar13 = iVar13 + param_5[0x15] * param_6[-0x13];
          case (undefined *)0x1002ffed:
            iVar13 = iVar13 + param_5[0x14] * param_6[-0x12];
          case (undefined *)0x1002fff6:
            iVar13 = iVar13 + param_5[0x13] * param_6[-0x11];
          case (undefined *)0x1002ffff:
            iVar13 = iVar13 + param_5[0x12] * param_6[-0x10];
          case (undefined *)0x10030008:
            iVar13 = iVar13 + param_5[0x11] * param_6[-0xf];
          case (undefined *)0x10030011:
            iVar13 = iVar13 + param_5[0x10] * param_6[-0xe];
          case (undefined *)0x1003001a:
            iVar13 = iVar13 + param_5[0xf] * param_6[-0xd];
          case (undefined *)0x10030023:
            iVar13 = iVar13 + param_5[0xe] * param_6[-0xc];
          case (undefined *)0x1003002c:
            iVar13 = iVar13 + param_5[0xd] * param_6[-0xb];
          case (undefined *)0x10030035:
            iVar13 = iVar13 + param_5[0xc] * param_6[-10];
          case (undefined *)0x1003003e:
            iVar13 = iVar13 + param_5[0xb] * param_6[-9];
          case (undefined *)0x10030047:
            iVar13 = iVar13 + param_5[10] * param_6[-8];
          case (undefined *)0x10030050:
            iVar13 = iVar13 + param_5[9] * param_6[-7];
          case (undefined *)0x10030059:
            iVar13 = iVar13 + param_5[8] * param_6[-6];
          case (undefined *)0x10030062:
            iVar13 = iVar13 + param_5[7] * param_6[-5];
          case (undefined *)0x1003006b:
            iVar13 = iVar13 + param_5[6] * param_6[-4];
          case (undefined *)0x10030074:
            iVar13 = iVar13 + param_5[5] * param_6[-3];
          case (undefined *)0x1003007d:
            iVar13 = iVar13 + param_5[4] * param_6[-2];
          case (undefined *)0x10030086:
            iVar13 = iVar13 + param_5[3] * param_6[-1];
          case (undefined *)0x1003008f:
            iVar13 = iVar13 + param_5[2] * (int)local_44._4_4_;
          case (undefined *)0x10030098:
            iVar13 = iVar13 + param_5[1] * local_1c._4_4_;
          case (undefined *)0x100300a1:
            iVar13 = iVar13 + *param_5 * uVar7;
          }
          break;
        default:
          *param_6 = uVar12;
          local_44 = CONCAT44(uVar12,(undefined4)local_44);
          if (uVar11 < 0x20) goto LAB_1002fcde;
          param_6[1] = local_20;
          local_1c = CONCAT44(local_20,(undefined4)local_1c);
          if (uVar11 < 0x20) goto LAB_1002fe30;
          iVar13 = 0;
          param_6[2] = uVar7;
          if (uVar11 < 0x20) goto LAB_1002ff83;
        }
        param_6[3] = (iVar13 >> (bVar9 & 0x1f)) + uVar14;
        param_6 = param_6 + 4;
        local_8 = param_6;
      } while (param_6 < local_5c);
    }
    else {
      local_50 = 0x20 - iVar13;
      do {
        iVar13 = *(int *)(in_ECX + 0x18);
        uVar12 = *(uint *)(in_ECX + 0x101c);
        if (DAT_1005109c == 0) {
          if (uVar12 == 0) {
            local_1c._4_4_ = 0x20;
          }
          else {
            iVar15 = 0x1f;
            if (uVar12 != 0) {
              for (; uVar12 >> iVar15 == 0; iVar15 = iVar15 + -1) {
              }
            }
            local_1c._4_4_ = 0x1f - iVar15;
          }
        }
        else {
          local_1c._4_4_ = LZCOUNT(uVar12);
        }
        local_34._4_4_ = iVar13;
        if (local_1c._4_4_ < 0x20) {
          local_4c = CONCAT44(local_1c._4_4_,(undefined4)local_4c);
          uVar7 = local_1c._4_4_;
        }
        else {
          local_4c = CONCAT44(0x20 - iVar13,(undefined4)local_4c);
          do {
            uVar12 = *(uint *)(in_ECX + 0x14);
            if (uVar12 < 0x400) {
              uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
              *(uint *)(in_ECX + 0x14) = uVar12 + 1;
              local_34._4_4_ = 0;
              uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                       uVar7 << 0x18;
            }
            else {
              iVar13 = FUN_1002d310();
              if (iVar13 == 0) {
                return 0;
              }
              uVar12 = *(uint *)(in_ECX + 0x101c);
              local_34._4_4_ = *(int *)(in_ECX + 0x18);
            }
            if (DAT_1005109c == 0) {
              if (uVar12 == 0) {
                uVar7 = 0x20;
              }
              else {
                iVar13 = 0x1f;
                if (uVar12 != 0) {
                  for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
                  }
                }
                uVar7 = 0x1f - iVar13;
              }
            }
            else {
              uVar7 = LZCOUNT(uVar12);
            }
            local_4c = CONCAT44(local_4c._4_4_ + uVar7,(undefined4)local_4c);
          } while (0x1f < uVar7);
        }
        uVar12 = uVar12 << ((byte)uVar7 & 0x1f);
        uVar7 = local_34._4_4_ + uVar7;
        local_38 = (uint *)(uVar12 >> ((byte)local_50 & 0x1f));
        if (local_50 < uVar7) {
          uVar7 = uVar7 - local_50;
          uVar12 = *(uint *)(in_ECX + 0x14);
          local_1c._4_4_ = uVar7;
          if (uVar12 < 0x400) {
            uVar11 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
            *(uint *)(in_ECX + 0x14) = uVar12 + 1;
            uVar11 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 |
                     uVar11 << 0x18;
          }
          else {
            iVar13 = FUN_1002d310();
            if (iVar13 == 0) {
              return 0;
            }
            uVar7 = *(int *)(in_ECX + 0x18) + local_1c._4_4_;
            uVar11 = *(uint *)(in_ECX + 0x101c);
          }
          uVar12 = uVar11 << ((byte)local_1c._4_4_ & 0x1f);
          local_38 = (uint *)((uint)local_38 | uVar11 >> (0x20 - (byte)local_1c._4_4_ & 0x1f));
        }
        else {
          uVar12 = uVar12 << ((byte)(local_58 + 1) & 0x1f);
          uVar7 = uVar7 + local_58 + 1;
          param_5 = local_c;
        }
        bVar16 = DAT_1005109c == 0;
        *(uint *)(in_ECX + 0x101c) = uVar12;
        *(uint *)(in_ECX + 0x18) = uVar7;
        if (bVar16) {
          if (uVar12 == 0) {
            uVar11 = 0x20;
          }
          else {
            iVar13 = 0x1f;
            if (uVar12 != 0) {
              for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
              }
            }
            uVar11 = 0x1f - iVar13;
          }
        }
        else {
          uVar11 = LZCOUNT(uVar12);
        }
        local_28 = uVar11;
        local_34._4_4_ = uVar7;
        if (0x1f < uVar11) {
          local_28 = 0x20 - uVar7;
          do {
            uVar12 = *(uint *)(in_ECX + 0x14);
            if (uVar12 < 0x400) {
              uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
              *(uint *)(in_ECX + 0x14) = uVar12 + 1;
              local_34._4_4_ = 0;
              uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                       uVar7 << 0x18;
            }
            else {
              iVar13 = FUN_1002d310();
              if (iVar13 == 0) {
                return 0;
              }
              uVar12 = *(uint *)(in_ECX + 0x101c);
              local_34._4_4_ = *(uint *)(in_ECX + 0x18);
            }
            if (DAT_1005109c == 0) {
              if (uVar12 == 0) {
                uVar11 = 0x20;
              }
              else {
                iVar13 = 0x1f;
                if (uVar12 != 0) {
                  for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
                  }
                }
                uVar11 = 0x1f - iVar13;
              }
            }
            else {
              uVar11 = LZCOUNT(uVar12);
            }
            local_28 = local_28 + uVar11;
          } while (0x1f < uVar11);
        }
        uVar12 = uVar12 << ((byte)uVar11 & 0x1f);
        uVar11 = local_34._4_4_ + uVar11;
        local_24 = uVar12 >> ((byte)local_50 & 0x1f);
        if (local_50 < uVar11) {
          uVar11 = uVar11 - local_50;
          uVar12 = *(uint *)(in_ECX + 0x14);
          local_1c._4_4_ = uVar11;
          if (uVar12 < 0x400) {
            uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
            *(uint *)(in_ECX + 0x14) = uVar12 + 1;
            uVar7 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18;
          }
          else {
            iVar13 = FUN_1002d310();
            if (iVar13 == 0) {
              return 0;
            }
            uVar11 = *(int *)(in_ECX + 0x18) + local_1c._4_4_;
            uVar7 = *(uint *)(in_ECX + 0x101c);
          }
          uVar12 = uVar7 << ((byte)local_1c._4_4_ & 0x1f);
          local_24 = local_24 | uVar7 >> (0x20 - (byte)local_1c._4_4_ & 0x1f);
        }
        else {
          uVar12 = uVar12 << ((byte)(local_58 + 1) & 0x1f);
          uVar11 = uVar11 + local_58 + 1;
          param_6 = local_8;
        }
        bVar16 = DAT_1005109c == 0;
        *(uint *)(in_ECX + 0x101c) = uVar12;
        *(uint *)(in_ECX + 0x18) = uVar11;
        if (bVar16) {
          if (uVar12 == 0) {
            uVar7 = 0x20;
          }
          else {
            iVar13 = 0x1f;
            if (uVar12 != 0) {
              for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
              }
            }
            uVar7 = 0x1f - iVar13;
          }
        }
        else {
          uVar7 = LZCOUNT(uVar12);
        }
        local_34._4_4_ = uVar11;
        if (uVar7 < 0x20) {
          local_44 = CONCAT44(uVar7,(undefined4)local_44);
        }
        else {
          local_44 = CONCAT44(0x20 - uVar11,(undefined4)local_44);
          do {
            uVar12 = *(uint *)(in_ECX + 0x14);
            if (uVar12 < 0x400) {
              uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
              *(uint *)(in_ECX + 0x14) = uVar12 + 1;
              local_34._4_4_ = 0;
              uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                       uVar7 << 0x18;
            }
            else {
              iVar13 = FUN_1002d310();
              if (iVar13 == 0) {
                return 0;
              }
              uVar12 = *(uint *)(in_ECX + 0x101c);
              local_34._4_4_ = *(uint *)(in_ECX + 0x18);
            }
            if (DAT_1005109c == 0) {
              if (uVar12 == 0) {
                uVar7 = 0x20;
              }
              else {
                iVar13 = 0x1f;
                if (uVar12 != 0) {
                  for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
                  }
                }
                uVar7 = 0x1f - iVar13;
              }
            }
            else {
              uVar7 = LZCOUNT(uVar12);
            }
            local_44 = CONCAT44((int)local_44._4_4_ + uVar7,(undefined4)local_44);
          } while (0x1f < uVar7);
        }
        uVar12 = uVar12 << ((byte)uVar7 & 0x1f);
        uVar7 = local_34._4_4_ + uVar7;
        local_20 = uVar12 >> ((byte)local_50 & 0x1f);
        if (local_50 < uVar7) {
          uVar7 = uVar7 - local_50;
          uVar12 = *(uint *)(in_ECX + 0x14);
          local_1c._4_4_ = uVar7;
          if (uVar12 < 0x400) {
            uVar11 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
            *(uint *)(in_ECX + 0x14) = uVar12 + 1;
            uVar11 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 |
                     uVar11 << 0x18;
          }
          else {
            iVar13 = FUN_1002d310();
            if (iVar13 == 0) {
              return 0;
            }
            uVar7 = *(int *)(in_ECX + 0x18) + local_1c._4_4_;
            uVar11 = *(uint *)(in_ECX + 0x101c);
          }
          local_34 = CONCAT44(uVar7,(undefined4)local_34);
          uVar12 = uVar11 << ((byte)local_1c._4_4_ & 0x1f);
          local_20 = local_20 | uVar11 >> (0x20 - (byte)local_1c._4_4_ & 0x1f);
        }
        else {
          uVar12 = uVar12 << ((byte)(local_58 + 1) & 0x1f);
          uVar7 = uVar7 + local_58 + 1;
          local_34 = CONCAT44(uVar7,(undefined4)local_34);
          param_5 = local_c;
        }
        bVar16 = DAT_1005109c == 0;
        *(uint *)(in_ECX + 0x101c) = uVar12;
        *(uint *)(in_ECX + 0x18) = uVar7;
        if (bVar16) {
          if (uVar12 == 0) {
            uVar11 = 0x20;
          }
          else {
            iVar13 = 0x1f;
            if (uVar12 != 0) {
              for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
              }
            }
            uVar11 = 0x1f - iVar13;
            uVar7 = local_34._4_4_;
          }
        }
        else {
          uVar11 = LZCOUNT(uVar12);
        }
        local_54 = uVar11;
        if (0x1f < uVar11) {
          local_54 = 0x20 - uVar7;
          do {
            uVar12 = *(uint *)(in_ECX + 0x14);
            if (uVar12 < 0x400) {
              uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
              *(uint *)(in_ECX + 0x14) = uVar12 + 1;
              uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 |
                       uVar7 << 0x18;
              local_34 = local_34 & 0xffffffff;
            }
            else {
              iVar13 = FUN_1002d310();
              if (iVar13 == 0) {
                return 0;
              }
              uVar12 = *(uint *)(in_ECX + 0x101c);
              local_34 = CONCAT44(*(undefined4 *)(in_ECX + 0x18),(undefined4)local_34);
            }
            if (DAT_1005109c == 0) {
              if (uVar12 == 0) {
                uVar11 = 0x20;
              }
              else {
                iVar13 = 0x1f;
                if (uVar12 != 0) {
                  for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
                  }
                }
                uVar11 = 0x1f - iVar13;
              }
            }
            else {
              uVar11 = LZCOUNT(uVar12);
            }
            local_54 = local_54 + uVar11;
          } while (0x1f < uVar11);
        }
        uVar12 = uVar12 << ((byte)uVar11 & 0x1f);
        uVar11 = local_34._4_4_ + uVar11;
        local_1c._4_4_ = uVar12 >> ((byte)local_50 & 0x1f);
        if (local_50 < uVar11) {
          uVar11 = uVar11 - local_50;
          uVar12 = *(uint *)(in_ECX + 0x14);
          local_10 = uVar11;
          if (uVar12 < 0x400) {
            uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
            *(uint *)(in_ECX + 0x14) = uVar12 + 1;
            uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18
            ;
          }
          else {
            iVar13 = FUN_1002d310();
            if (iVar13 == 0) {
              return 0;
            }
            uVar11 = *(int *)(in_ECX + 0x18) + local_10;
            uVar12 = *(uint *)(in_ECX + 0x101c);
          }
          local_34 = CONCAT44(uVar11,(undefined4)local_34);
          iVar13 = uVar12 << ((byte)local_10 & 0x1f);
          local_1c = CONCAT44(local_1c._4_4_ | uVar12 >> (0x20 - (byte)local_10 & 0x1f),
                              (undefined4)local_1c);
        }
        else {
          iVar13 = uVar12 << ((byte)(local_58 + 1) & 0x1f);
          uVar11 = uVar11 + local_58 + 1;
          param_6 = local_8;
        }
        *(uint *)(in_ECX + 0x18) = uVar11;
        *(int *)(in_ECX + 0x101c) = iVar13;
        bVar10 = (byte)local_58;
        uVar12 = local_4c._4_4_ << (bVar10 & 0x1f) | (uint)local_38 & local_60;
        local_4c = CONCAT44(uVar12,(undefined4)local_4c);
        local_28 = local_28 << (bVar10 & 0x1f) | local_24 & local_60;
        uVar7 = (int)local_44._4_4_ << (bVar10 & 0x1f) | local_20 & local_60;
        local_54 = local_54 << (bVar10 & 0x1f) | local_1c._4_4_ & local_60;
        local_4c = CONCAT44(uVar12 >> 1 ^ local_74[uVar12 & 1],(undefined4)local_4c);
        local_28 = local_28 >> 1 ^ local_74[local_28 & 1];
        local_44._4_4_ = (int *)(uVar7 >> 1 ^ local_74[uVar7 & 1]);
        local_54 = local_54 >> 1 ^ local_74[local_54 & 1];
        if (param_3 == 8) {
          iVar13 = __allshr();
          *local_8 = iVar13 + local_4c._4_4_;
          iVar13 = __allshr();
          param_5 = local_c;
          local_8[1] = iVar13 + local_28;
          iVar13 = __allshr();
          uVar12 = iVar13 + (int)local_44._4_4_;
          local_44 = CONCAT44(local_8 + 3,(undefined4)local_44);
          local_8[2] = uVar12;
          lVar1 = (longlong)param_5[7] * (longlong)(int)local_8[-5];
LAB_1002f27f:
          lVar1 = lVar1 + (longlong)param_5[6] * (longlong)(int)local_8[-4];
LAB_1002f28a:
          lVar1 = lVar1 + (longlong)param_5[5] * (longlong)(int)local_8[-3];
LAB_1002f295:
          lVar1 = lVar1 + (longlong)param_5[4] * (longlong)(int)local_8[-2];
LAB_1002f2a0:
          lVar1 = lVar1 + (longlong)param_5[3] * (longlong)(int)local_8[-1];
LAB_1002f2ab:
          lVar1 = lVar1 + (longlong)param_5[1] * (longlong)(int)local_8[1];
LAB_1002f2b6:
          lVar3 = CONCAT44(local_24,local_20);
          lVar1 = lVar1 + (longlong)*param_5 * (longlong)(int)local_8[2];
          param_6 = local_8;
          local_8 = (uint *)((int)((ulonglong)lVar1 >> 0x20) +
                             (int)((ulonglong)((longlong)param_5[2] * (longlong)(int)*local_8) >>
                                  0x20) +
                            (uint)CARRY4((uint)lVar1,
                                         (uint)((longlong)param_5[2] * (longlong)(int)*local_8)));
        }
        else {
          if (param_3 == 7) {
            iVar13 = __allshr();
            *local_8 = iVar13 + local_4c._4_4_;
            iVar13 = __allshr();
            param_5 = local_c;
            local_8[1] = iVar13 + local_28;
            iVar13 = __allshr();
            uVar12 = iVar13 + (int)local_44._4_4_;
            local_44 = CONCAT44(local_8 + 3,(undefined4)local_44);
            local_8[2] = uVar12;
            lVar1 = (longlong)param_5[6] * (longlong)(int)local_8[-4];
            goto LAB_1002f28a;
          }
          if (param_3 == 3) {
            iVar13 = __allshr();
            *local_8 = iVar13 + local_4c._4_4_;
            iVar13 = __allshr();
            param_5 = local_c;
            local_8[1] = iVar13 + local_28;
            iVar13 = __allshr();
            uVar12 = iVar13 + (int)local_44._4_4_;
            local_44 = CONCAT44(local_8 + 3,(undefined4)local_44);
            local_8[2] = uVar12;
            lVar1 = (longlong)param_5[1] * (longlong)(int)local_8[1];
            goto LAB_1002f2b6;
          }
          if (param_3 == 6) {
            iVar13 = __allshr();
            *local_8 = iVar13 + local_4c._4_4_;
            iVar13 = __allshr();
            param_5 = local_c;
            local_8[1] = iVar13 + local_28;
            iVar13 = __allshr();
            uVar12 = iVar13 + (int)local_44._4_4_;
            local_44 = CONCAT44(local_8 + 3,(undefined4)local_44);
            local_8[2] = uVar12;
            lVar1 = (longlong)param_5[5] * (longlong)(int)local_8[-3];
            goto LAB_1002f295;
          }
          if (param_3 == 5) {
            iVar13 = __allshr();
            *local_8 = iVar13 + local_4c._4_4_;
            iVar13 = __allshr();
            param_5 = local_c;
            local_8[1] = iVar13 + local_28;
            iVar13 = __allshr();
            uVar12 = iVar13 + (int)local_44._4_4_;
            local_44 = CONCAT44(local_8 + 3,(undefined4)local_44);
            local_8[2] = uVar12;
            lVar1 = (longlong)param_5[4] * (longlong)(int)local_8[-2];
            goto LAB_1002f2a0;
          }
          if (param_3 == 4) {
            iVar13 = __allshr();
            *local_8 = iVar13 + local_4c._4_4_;
            iVar13 = __allshr();
            param_5 = local_c;
            local_8[1] = iVar13 + local_28;
            iVar13 = __allshr();
            uVar12 = iVar13 + (int)local_44._4_4_;
            local_44 = CONCAT44(local_8 + 3,(undefined4)local_44);
            local_8[2] = uVar12;
            lVar1 = (longlong)param_5[3] * (longlong)(int)local_8[-1];
            goto LAB_1002f2ab;
          }
          if (param_3 == 0xc) {
            iVar13 = __allshr();
            *local_8 = iVar13 + local_4c._4_4_;
            iVar13 = __allshr();
            param_5 = local_c;
            local_8[1] = iVar13 + local_28;
            iVar13 = __allshr();
            uVar12 = iVar13 + (int)local_44._4_4_;
            local_44 = CONCAT44(local_8 + 3,(undefined4)local_44);
            local_8[2] = uVar12;
            lVar1 = (longlong)param_5[0xb] * (longlong)(int)local_8[-9] +
                    (longlong)param_5[10] * (longlong)(int)local_8[-8];
LAB_1002f25e:
            lVar1 = lVar1 + (longlong)param_5[9] * (longlong)(int)local_8[-7];
LAB_1002f269:
            lVar1 = lVar1 + (longlong)param_5[8] * (longlong)(int)local_8[-6];
LAB_1002f274:
            lVar1 = lVar1 + (longlong)param_5[7] * (longlong)(int)local_8[-5];
            goto LAB_1002f27f;
          }
          if (param_3 == 2) {
            iVar13 = __allshr();
            *local_8 = iVar13 + local_4c._4_4_;
            iVar13 = __allshr();
            param_5 = local_c;
            local_8[1] = iVar13 + local_28;
            iVar13 = __allshr();
            lVar3 = CONCAT44(local_24,local_20);
            uVar12 = iVar13 + (int)local_44._4_4_;
            local_44 = CONCAT44(local_8 + 3,(undefined4)local_44);
            local_8[2] = uVar12;
            param_6 = local_8;
            local_8 = (uint *)((int)((ulonglong)((longlong)param_5[1] * (longlong)(int)local_8[1])
                                    >> 0x20) +
                               (int)((ulonglong)((longlong)*param_5 * (longlong)(int)local_8[2]) >>
                                    0x20) +
                              (uint)CARRY4((uint)((longlong)param_5[1] * (longlong)(int)local_8[1]),
                                           (uint)((longlong)*param_5 * (longlong)(int)local_8[2])));
          }
          else if (param_3 == 1) {
            iVar13 = __allshr();
            *param_6 = iVar13 + local_4c._4_4_;
            iVar13 = __allshr();
            param_6[1] = iVar13 + local_28;
            iVar13 = __allshr();
            lVar3 = CONCAT44(local_24,local_20);
            param_6[2] = iVar13 + (int)local_44._4_4_;
            local_44 = CONCAT44(param_6 + 3,(undefined4)local_44);
            local_8 = (uint *)(int)((ulonglong)((longlong)*param_5 * (longlong)(int)param_6[2]) >>
                                   0x20);
          }
          else {
            if (param_3 == 10) {
              iVar13 = __allshr();
              *local_8 = iVar13 + local_4c._4_4_;
              iVar13 = __allshr();
              param_5 = local_c;
              local_8[1] = iVar13 + local_28;
              iVar13 = __allshr();
              uVar12 = iVar13 + (int)local_44._4_4_;
              local_44 = CONCAT44(local_8 + 3,(undefined4)local_44);
              local_8[2] = uVar12;
              lVar1 = (longlong)param_5[9] * (longlong)(int)local_8[-7];
              goto LAB_1002f269;
            }
            if (param_3 == 9) {
              iVar13 = __allshr();
              *local_8 = iVar13 + local_4c._4_4_;
              iVar13 = __allshr();
              param_5 = local_c;
              local_8[1] = iVar13 + local_28;
              iVar13 = __allshr();
              uVar12 = iVar13 + (int)local_44._4_4_;
              local_44 = CONCAT44(local_8 + 3,(undefined4)local_44);
              local_8[2] = uVar12;
              lVar1 = (longlong)param_5[8] * (longlong)(int)local_8[-6];
              goto LAB_1002f274;
            }
            if (param_3 == 0xb) {
              iVar13 = __allshr();
              *local_8 = iVar13 + local_4c._4_4_;
              iVar13 = __allshr();
              param_5 = local_c;
              local_8[1] = iVar13 + local_28;
              iVar13 = __allshr();
              uVar12 = iVar13 + (int)local_44._4_4_;
              local_44 = CONCAT44(local_8 + 3,(undefined4)local_44);
              local_8[2] = uVar12;
              lVar1 = (longlong)param_5[10] * (longlong)(int)local_8[-8];
              goto LAB_1002f25e;
            }
            iVar13 = 0;
            local_34 = 0;
            local_74[2] = 0;
            local_74[3] = 0;
            uVar4 = local_74._8_8_;
            local_1c._0_4_ = 0;
            if (param_3 < 2) {
              lVar3 = 0;
              lVar1 = 0;
            }
            else {
              iVar13 = 0;
              lVar3 = 0;
              lVar1 = 0;
              puVar8 = param_6;
              do {
                lVar1 = (longlong)param_5[iVar13] * (longlong)(int)puVar8[-1] + lVar1;
                lVar3 = (longlong)param_5[iVar13 + 1] * (longlong)(int)puVar8[-2] + lVar3;
                iVar13 = iVar13 + 2;
                in_ECX = local_74[4];
                param_6 = local_8;
                puVar8 = puVar8 + -2;
              } while (iVar13 < param_3 + -1);
            }
            local_24 = (uint)((ulonglong)lVar3 >> 0x20);
            local_20 = (uint)lVar3;
            local_38 = (uint *)((ulonglong)lVar1 >> 0x20);
            local_1c._4_4_ = (uint)lVar1;
            if (iVar13 < param_3) {
              local_74[2] = param_5[iVar13] * param_6[-1 - iVar13];
            }
            else {
              local_74[2] = 0;
            }
            local_10 = local_74[2];
            local_74._8_8_ = uVar4;
            iVar13 = __allshr();
            local_38 = param_6 + 1;
            *param_6 = iVar13 + local_4c._4_4_;
            iVar13 = 0;
            local_34 = 0;
            local_74[2] = 0;
            local_74[3] = 0;
            uVar4 = local_74._8_8_;
            local_1c._0_4_ = 0;
            if (param_3 < 2) {
              lVar1 = 0;
              lVar3 = 0;
            }
            else {
              iVar13 = 0;
              lVar1 = 0;
              lVar3 = 0;
              puVar8 = param_6 + -1;
              do {
                lVar1 = (longlong)param_5[iVar13] * (longlong)(int)puVar8[1] + lVar1;
                lVar3 = (longlong)param_5[iVar13 + 1] * (longlong)(int)*puVar8 + lVar3;
                iVar13 = iVar13 + 2;
                in_ECX = local_74[4];
                puVar8 = puVar8 + -2;
                param_6 = local_8;
              } while (iVar13 < param_3 + -1);
            }
            local_1c._4_4_ = (uint)lVar3;
            local_24 = (uint)((ulonglong)lVar1 >> 0x20);
            local_20 = (uint)lVar1;
            local_4c = CONCAT44((int)((ulonglong)lVar3 >> 0x20),(undefined4)local_4c);
            if (iVar13 < param_3) {
              local_74[2] = param_5[iVar13] * local_38[-1 - iVar13];
            }
            else {
              local_74[2] = 0;
            }
            local_10 = local_74[2];
            local_74._8_8_ = uVar4;
            iVar13 = __allshr();
            local_38 = param_6 + 2;
            param_6[1] = iVar13 + local_28;
            iVar13 = 0;
            local_4c = 0;
            local_74[2] = 0;
            local_74[3] = 0;
            uVar4 = local_74._8_8_;
            local_1c._0_4_ = 0;
            if (param_3 < 2) {
              lVar3 = 0;
              lVar1 = 0;
            }
            else {
              iVar13 = 0;
              lVar3 = 0;
              lVar1 = 0;
              puVar8 = param_6;
              do {
                lVar1 = (longlong)param_5[iVar13] * (longlong)(int)puVar8[1] + lVar1;
                lVar3 = (longlong)param_5[iVar13 + 1] * (longlong)(int)*puVar8 + lVar3;
                iVar13 = iVar13 + 2;
                in_ECX = local_74[4];
                puVar8 = puVar8 + -2;
                param_6 = local_8;
              } while (iVar13 < param_3 + -1);
            }
            local_24 = (uint)((ulonglong)lVar3 >> 0x20);
            local_20 = (uint)lVar3;
            local_28 = (uint)((ulonglong)lVar1 >> 0x20);
            local_1c._4_4_ = (uint)lVar1;
            if (iVar13 < param_3) {
              local_74[2] = param_5[iVar13] * local_38[-1 - iVar13];
            }
            else {
              local_74[2] = 0;
            }
            local_10 = local_74[2];
            local_74._8_8_ = uVar4;
            iVar13 = __allshr();
            param_6[2] = iVar13 + (int)local_44._4_4_;
            local_38 = param_6 + 3;
            local_4c = 0;
            local_74[2] = 0;
            local_74[3] = 0;
            local_10 = 0;
            if (param_3 < 2) {
              lVar3 = 0;
              lVar1 = 0;
              local_8 = param_6;
            }
            else {
              local_10 = 0;
              lVar3 = 0;
              lVar1 = 0;
              puVar8 = param_6 + 1;
              do {
                lVar3 = (longlong)param_5[local_10] * (longlong)(int)puVar8[1] + lVar3;
                lVar1 = (longlong)param_5[local_10 + 1] * (longlong)(int)*puVar8 + lVar1;
                local_10 = local_10 + 2;
                in_ECX = local_74[4];
                puVar8 = puVar8 + -2;
              } while ((int)local_10 < param_3 + -1);
            }
            local_28 = (uint)((ulonglong)lVar1 >> 0x20);
            local_44 = CONCAT44(local_38,(undefined4)local_44);
            if ((int)local_10 < param_3) {
              lVar2 = (longlong)param_5[local_10] * (longlong)(int)local_38[-1 - local_10];
            }
            else {
              lVar2 = 0;
            }
            lVar1 = lVar1 + lVar3;
            local_1c = lVar1 << 0x20;
            param_6 = local_8;
            local_8 = (uint *)((int)((ulonglong)lVar2 >> 0x20) + (int)((ulonglong)lVar1 >> 0x20) +
                              (uint)CARRY4((uint)lVar2,(uint)lVar1));
          }
        }
        local_24 = (uint)((ulonglong)lVar3 >> 0x20);
        local_20 = (uint)lVar3;
        iVar13 = __allshr();
        param_6 = param_6 + 4;
        local_8 = param_6;
        *local_44._4_4_ = iVar13 + local_54;
      } while (param_6 < local_5c);
    }
  }
  local_54 = param_1 & 0xfffffffc;
  if ((param_1 & 0xfffffffc) < param_1) {
    local_10 = 0x20 - (local_58 + 1);
    do {
      uVar12 = *(uint *)(in_ECX + 0x101c);
      local_1c = CONCAT44(*(int *)(in_ECX + 0x18),(undefined4)local_1c);
      if (DAT_1005109c == 0) {
        if (uVar12 == 0) {
          uVar7 = 0x20;
        }
        else {
          iVar13 = 0x1f;
          if (uVar12 != 0) {
            for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
            }
          }
          uVar7 = 0x1f - iVar13;
        }
      }
      else {
        uVar7 = LZCOUNT(uVar12);
      }
      if (uVar7 < 0x20) {
        local_24 = uVar7;
      }
      else {
        local_24 = 0x20 - *(int *)(in_ECX + 0x18);
        do {
          uVar12 = *(uint *)(in_ECX + 0x14);
          if (uVar12 < 0x400) {
            uVar7 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
            *(uint *)(in_ECX + 0x14) = uVar12 + 1;
            uVar12 = uVar7 >> 0x18 | (uVar7 & 0xff0000) >> 8 | (uVar7 & 0xff00) << 8 | uVar7 << 0x18
            ;
            local_1c = local_1c & 0xffffffff;
          }
          else {
            iVar13 = FUN_1002d310();
            if (iVar13 == 0) {
              return 0;
            }
            uVar12 = *(uint *)(in_ECX + 0x101c);
            local_1c = CONCAT44(*(undefined4 *)(in_ECX + 0x18),(undefined4)local_1c);
          }
          if (DAT_1005109c == 0) {
            if (uVar12 == 0) {
              uVar7 = 0x20;
            }
            else {
              iVar13 = 0x1f;
              if (uVar12 != 0) {
                for (; uVar12 >> iVar13 == 0; iVar13 = iVar13 + -1) {
                }
              }
              uVar7 = 0x1f - iVar13;
            }
          }
          else {
            uVar7 = LZCOUNT(uVar12);
          }
          local_24 = local_24 + uVar7;
        } while (0x1f < uVar7);
      }
      uVar12 = uVar12 << ((byte)uVar7 & 0x1f);
      uVar7 = local_1c._4_4_ + uVar7;
      local_20 = uVar12 >> ((byte)local_10 & 0x1f);
      if (local_10 < uVar7) {
        uVar12 = *(uint *)(in_ECX + 0x14);
        local_5c = (uint *)(uVar7 - local_10);
        if (uVar12 < 0x400) {
          uVar11 = *(uint *)(in_ECX + 0x1c + uVar12 * 4);
          *(uint *)(in_ECX + 0x14) = uVar12 + 1;
          uVar12 = uVar11 >> 0x18 | (uVar11 & 0xff0000) >> 8 | (uVar11 & 0xff00) << 8 |
                   uVar11 << 0x18;
          local_1c = CONCAT44((uint *)(uVar7 - local_10),(undefined4)local_1c);
        }
        else {
          iVar13 = FUN_1002d310();
          if (iVar13 == 0) {
            return 0;
          }
          uVar12 = *(uint *)(in_ECX + 0x101c);
          local_1c = CONCAT44(*(int *)(in_ECX + 0x18) + (int)local_5c,(undefined4)local_1c);
        }
        iVar15 = uVar12 << ((byte)local_5c & 0x1f);
        local_20 = local_20 | uVar12 >> (0x20 - (byte)local_5c & 0x1f);
        iVar13 = local_1c._4_4_;
      }
      else {
        iVar15 = uVar12 << ((byte)(local_58 + 1) & 0x1f);
        iVar13 = uVar7 + local_58 + 1;
        param_6 = local_8;
      }
      *(int *)(in_ECX + 0x101c) = iVar15;
      *(int *)(in_ECX + 0x18) = iVar13;
      uVar12 = local_24 << ((byte)local_58 & 0x1f) | local_20 & local_60;
      local_24 = uVar12 >> 1 ^ local_74[uVar12 & 1];
      if (uVar6 < 0x21) {
        iVar13 = 0;
        switch(param_3) {
        case 0x20:
          iVar13 = param_5[0x1f] * param_6[-0x20];
        case 0x1f:
          iVar13 = iVar13 + param_5[0x1e] * param_6[-0x1f];
        case 0x1e:
          iVar13 = iVar13 + param_5[0x1d] * param_6[-0x1e];
        case 0x1d:
          iVar13 = iVar13 + param_5[0x1c] * param_6[-0x1d];
        case 0x1c:
          iVar13 = iVar13 + param_5[0x1b] * param_6[-0x1c];
        case 0x1b:
          iVar13 = iVar13 + param_5[0x1a] * param_6[-0x1b];
        case 0x1a:
          iVar13 = iVar13 + param_5[0x19] * param_6[-0x1a];
        case 0x19:
          iVar13 = iVar13 + param_5[0x18] * param_6[-0x19];
        case 0x18:
          iVar13 = iVar13 + param_5[0x17] * param_6[-0x18];
        case 0x17:
          iVar13 = iVar13 + param_5[0x16] * param_6[-0x17];
        case 0x16:
          iVar13 = iVar13 + param_5[0x15] * param_6[-0x16];
        case 0x15:
          iVar13 = iVar13 + param_5[0x14] * param_6[-0x15];
        case 0x14:
          iVar13 = iVar13 + param_5[0x13] * param_6[-0x14];
        case 0x13:
          iVar13 = iVar13 + param_5[0x12] * param_6[-0x13];
        case 0x12:
          iVar13 = iVar13 + param_5[0x11] * param_6[-0x12];
        case 0x11:
          iVar13 = iVar13 + param_5[0x10] * param_6[-0x11];
        case 0x10:
          iVar13 = iVar13 + param_5[0xf] * param_6[-0x10];
        case 0xf:
          iVar13 = iVar13 + param_5[0xe] * param_6[-0xf];
        case 0xe:
          iVar13 = iVar13 + param_5[0xd] * param_6[-0xe];
        case 0xd:
          iVar13 = iVar13 + param_5[0xc] * param_6[-0xd];
        case 0xc:
          iVar13 = iVar13 + param_5[0xb] * param_6[-0xc];
        case 0xb:
          iVar13 = iVar13 + param_5[10] * param_6[-0xb];
        case 10:
          iVar13 = iVar13 + param_5[9] * param_6[-10];
        case 9:
          iVar13 = iVar13 + param_5[8] * param_6[-9];
        case 8:
          iVar13 = iVar13 + param_5[7] * param_6[-8];
        case 7:
          iVar13 = iVar13 + param_5[6] * param_6[-7];
        case 6:
          iVar13 = iVar13 + param_5[5] * param_6[-6];
        case 5:
          iVar13 = iVar13 + param_5[4] * param_6[-5];
        case 4:
          iVar13 = iVar13 + param_5[3] * param_6[-4];
        case 3:
          iVar13 = iVar13 + param_5[2] * param_6[-3];
        case 2:
          iVar13 = iVar13 + param_5[1] * param_6[-2];
        case 1:
          iVar13 = iVar13 + param_6[-1] * *param_5;
        default:
          iVar13 = iVar13 >> (bVar9 & 0x1f);
        }
        goto LAB_100305fc;
      }
      if (param_3 == 8) {
        lVar1 = (longlong)param_5[7] * (longlong)(int)param_6[-8];
LAB_1003038b:
        lVar1 = lVar1 + (longlong)param_5[6] * (longlong)(int)param_6[-7];
LAB_10030396:
        lVar1 = lVar1 + (longlong)param_5[5] * (longlong)(int)param_6[-6];
LAB_100303a1:
        lVar1 = lVar1 + (longlong)param_5[4] * (longlong)(int)param_6[-5];
LAB_100303ac:
        lVar1 = lVar1 + (longlong)param_5[3] * (longlong)(int)param_6[-4];
LAB_100303b7:
        lVar1 = lVar1 + (longlong)param_5[2] * (longlong)(int)param_6[-3];
LAB_100303c2:
        lVar1 = lVar1 + (longlong)param_5[1] * (longlong)(int)param_6[-2];
        local_8 = (uint *)((int)((ulonglong)lVar1 >> 0x20) +
                           (int)((ulonglong)((longlong)*param_5 * (longlong)(int)param_6[-1]) >>
                                0x20) +
                          (uint)CARRY4((uint)lVar1,
                                       (uint)((longlong)*param_5 * (longlong)(int)param_6[-1])));
        iVar13 = __allshr();
      }
      else {
        if (param_3 == 7) {
          lVar1 = (longlong)param_5[6] * (longlong)(int)param_6[-7];
          goto LAB_10030396;
        }
        if (param_3 == 3) {
          lVar1 = (longlong)param_5[2] * (longlong)(int)param_6[-3];
          goto LAB_100303c2;
        }
        if (param_3 == 6) {
          lVar1 = (longlong)param_5[5] * (longlong)(int)param_6[-6];
          goto LAB_100303a1;
        }
        if (param_3 == 5) {
          lVar1 = (longlong)param_5[4] * (longlong)(int)param_6[-5];
          goto LAB_100303ac;
        }
        if (param_3 == 4) {
          lVar1 = (longlong)param_5[3] * (longlong)(int)param_6[-4];
          goto LAB_100303b7;
        }
        if (param_3 == 0xc) {
          lVar1 = (longlong)param_5[0xb] * (longlong)(int)param_6[-0xc] +
                  (longlong)param_5[10] * (longlong)(int)param_6[-0xb];
LAB_1003036a:
          lVar1 = lVar1 + (longlong)param_5[9] * (longlong)(int)param_6[-10];
LAB_10030375:
          lVar1 = lVar1 + (longlong)param_5[8] * (longlong)(int)param_6[-9];
LAB_10030380:
          lVar1 = lVar1 + (longlong)param_5[7] * (longlong)(int)param_6[-8];
          goto LAB_1003038b;
        }
        if (param_3 == 2) {
          local_8 = (uint *)((int)((ulonglong)((longlong)param_5[1] * (longlong)(int)param_6[-2]) >>
                                  0x20) +
                             (int)((ulonglong)((longlong)*param_5 * (longlong)(int)param_6[-1]) >>
                                  0x20) +
                            (uint)CARRY4((uint)((longlong)param_5[1] * (longlong)(int)param_6[-2]),
                                         (uint)((longlong)*param_5 * (longlong)(int)param_6[-1])));
          iVar13 = __allshr();
        }
        else if (param_3 == 1) {
          local_8 = (uint *)((ulonglong)((longlong)*param_5 * (longlong)(int)param_6[-1]) >> 0x20);
          iVar13 = __allshr();
        }
        else {
          if (param_3 == 10) {
            lVar1 = (longlong)param_5[9] * (longlong)(int)param_6[-10];
            goto LAB_10030375;
          }
          if (param_3 == 9) {
            lVar1 = (longlong)param_5[8] * (longlong)(int)param_6[-9];
            goto LAB_10030380;
          }
          if (param_3 == 0xb) {
            lVar1 = (longlong)param_5[10] * (longlong)(int)param_6[-0xb];
            goto LAB_1003036a;
          }
          local_44 = 0;
          local_74[2] = 0;
          local_74[3] = 0;
          local_5c = (uint *)0x0;
          if (param_3 < 2) {
            lVar1 = 0;
            lVar3 = 0;
          }
          else {
            local_5c = (uint *)0x0;
            lVar1 = 0;
            lVar3 = 0;
            puVar8 = param_6;
            do {
              lVar1 = (longlong)param_5[(int)local_5c] * (longlong)(int)puVar8[-1] + lVar1;
              lVar3 = (longlong)param_5[(int)local_5c + 1] * (longlong)(int)puVar8[-2] + lVar3;
              local_5c = (uint *)((int)local_5c + 2);
              in_ECX = local_74[4];
              param_6 = local_8;
              puVar8 = puVar8 + -2;
            } while ((int)local_5c < param_3 + -1);
          }
          local_50 = (uint)((ulonglong)lVar3 >> 0x20);
          local_38 = (uint *)((ulonglong)lVar1 >> 0x20);
          local_20 = (uint)lVar1;
          if ((int)local_5c < param_3) {
            lVar2 = (longlong)param_5[(int)local_5c] * (longlong)(int)param_6[-1 - (int)local_5c];
          }
          else {
            lVar2 = 0;
          }
          lVar1 = lVar1 + lVar3;
          local_1c = lVar1 << 0x20;
          local_8 = (uint *)((int)((ulonglong)lVar2 >> 0x20) + (int)((ulonglong)lVar1 >> 0x20) +
                            (uint)CARRY4((uint)lVar2,(uint)lVar1));
          iVar13 = __allshr();
        }
      }
LAB_100305fc:
      local_54 = local_54 + 1;
      *param_6 = iVar13 + local_24;
      param_6 = param_6 + 1;
      local_8 = param_6;
    } while (local_54 < param_1);
  }
  return 1;
}

