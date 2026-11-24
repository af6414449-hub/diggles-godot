
/* WARNING: Removing unreachable block (ram,0x006d8ac8) */
/* WARNING: Removing unreachable block (ram,0x006d8aa3) */
/* Library Function - Single Match
    unsigned __int64 __cdecl __crt_strtox::divide(struct __crt_strtox::big_integer &,struct
   __crt_strtox::big_integer const &)
   
   Library: Visual Studio 2019 Release */

__uint64 __cdecl __crt_strtox::divide(big_integer *param_1,big_integer *param_2)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 extraout_ECX;
  big_integer *pbVar4;
  uint extraout_ECX_00;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  big_integer *pbVar9;
  undefined4 uVar10;
  uint uVar11;
  bool bVar12;
  undefined8 uVar13;
  longlong lVar14;
  ulonglong uVar15;
  undefined1 local_21c [460];
  big_integer *local_50;
  uint local_4c;
  undefined8 local_48;
  big_integer *local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_28;
  uint local_24;
  big_integer *local_20;
  big_integer *local_1c;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  iVar8 = *(int *)param_1;
  if ((iVar8 != 0) && (local_38 = *(uint *)param_2, local_38 != 0)) {
    uVar2 = local_38 - 1;
    uVar6 = iVar8 - 1;
    if (uVar2 == 0) {
      local_c = *(uint *)(param_2 + 4);
      if (local_c == 1) {
        uVar2 = *(uint *)(param_1 + 4);
        *(undefined4 *)param_1 = 0;
        _memcpy_s(param_1 + 4,0x1cc,local_21c,0);
        return (__uint64)uVar2;
      }
      if (uVar6 == 0) {
        uVar2 = *(uint *)(param_1 + 4);
        *(undefined4 *)param_1 = 0;
        _memcpy_s(param_1 + 4,0x1cc,local_21c,0);
        uVar6 = uVar2 % local_c;
        *(uint *)(param_1 + 4) = uVar6;
        *(uint *)param_1 = (uint)(uVar6 != 0);
        return (ulonglong)uVar2 / (ulonglong)local_c;
      }
      uVar10 = 0;
      local_10 = 0;
      local_28 = 0;
      local_1c = (big_integer *)0x0;
      if (uVar6 != 0xffffffff) {
        local_20 = param_1 + iVar8 * 4;
        pbVar4 = param_1;
        do {
          pbVar9 = pbVar4;
          pbVar4 = pbVar9;
          uVar13 = __aulldvrm(*(undefined4 *)local_20,uVar10,local_c,0);
          local_48._4_4_ = (int)((ulonglong)uVar13 >> 0x20);
          local_28 = local_10;
          local_20 = local_20 + -4;
          iVar8 = iVar8 + -1;
          uVar10 = extraout_ECX;
          local_1c = pbVar9;
          local_10 = (int)uVar13;
        } while (iVar8 != 0);
      }
      *(undefined4 *)param_1 = 0;
      _memcpy_s(param_1 + 4,0x1cc,local_21c,0);
      *(undefined4 *)(param_1 + 4) = uVar10;
      *(big_integer **)(param_1 + 8) = local_1c;
      *(uint *)param_1 = (local_1c != (big_integer *)0x0) + 1;
      return CONCAT44(local_28,local_10);
    }
    if (uVar2 <= uVar6) {
      iVar7 = uVar6 - uVar2;
      if (iVar7 <= (int)uVar6) {
        pbVar4 = param_1 + iVar8 * 4;
        pbVar9 = param_2 + uVar2 * 4 + 4;
        uVar2 = uVar6;
        do {
          if (*(uint *)pbVar9 != *(uint *)pbVar4) {
            if (*(uint *)pbVar4 <= *(uint *)pbVar9) goto LAB_006d891c;
            break;
          }
          uVar2 = uVar2 - 1;
          pbVar9 = pbVar9 + -4;
          pbVar4 = pbVar4 + -4;
        } while (iVar7 <= (int)uVar2);
      }
      iVar7 = iVar7 + 1;
LAB_006d891c:
      if (iVar7 != 0) {
        local_34 = *(uint *)(param_2 + local_38 * 4);
        local_24 = *(uint *)(param_2 + local_38 * 4 + -4);
        local_10 = 0x1f;
        if (local_34 != 0) {
          for (; local_34 >> local_10 == 0; local_10 = local_10 + -1) {
          }
        }
        if (local_34 == 0) {
          local_10 = 0x20;
        }
        else {
          local_10 = 0x1f - local_10;
        }
        local_30 = 0x20 - local_10;
        if (local_10 != 0) {
          uVar2 = local_24 >> ((byte)local_30 & 0x1f);
          local_24 = local_24 << ((byte)local_10 & 0x1f);
          local_34 = local_34 << ((byte)local_10 & 0x1f) | uVar2;
          if (2 < local_38) {
            local_24 = local_24 | *(uint *)(param_2 + local_38 * 4 + -8) >> ((byte)local_30 & 0x1f);
          }
        }
        local_20 = (big_integer *)0x0;
        local_1c = (big_integer *)(iVar7 + -1);
        pbVar4 = (big_integer *)0;
        local_c = uVar6;
        if (-1 < (int)local_1c) {
          local_3c = (int)local_1c + local_38;
          local_40 = param_1 + (int)local_1c * 4 + 4;
          local_50 = param_1 + local_3c * 4 + -4;
          do {
            if (local_c < local_3c) {
              local_4c = 0;
            }
            else {
              local_4c = *(uint *)(local_50 + 8);
            }
            uVar2 = *(uint *)(local_50 + 4);
            local_18 = *(uint *)local_50;
            local_28 = 0;
            local_8 = local_4c;
            if (local_10 != 0) {
              uVar2 = local_18 >> ((byte)local_30 & 0x1f);
              uVar13 = __allshl();
              local_8 = (uint)((ulonglong)uVar13 >> 0x20);
              uVar2 = uVar2 | (uint)uVar13;
              local_18 = local_18 << ((byte)local_10 & 0x1f);
              if (2 < local_3c) {
                local_18 = local_18 |
                           *(uint *)(param_1 + (local_38 + (int)local_1c) * 4 + -8) >>
                           ((byte)local_30 & 0x1f);
              }
            }
            local_48 = __aulldvrm(uVar2,local_8,local_34,0);
            local_14 = (int)((ulonglong)local_48 >> 0x20);
            local_8 = (uint)local_48;
            local_28 = 0;
            uVar1 = (ulonglong)extraout_ECX_00;
            if (local_14 != 0) {
              lVar14 = __allmul(local_48 + -0xffffffff,local_34,0);
              uVar1 = lVar14 + (ulonglong)extraout_ECX_00;
              local_8 = 0xffffffff;
            }
            local_28 = (int)(uVar1 >> 0x20);
            local_14 = 0;
            local_48._0_4_ = local_8;
            local_48._4_4_ = local_14;
            if (local_28 == 0) {
              while( true ) {
                uVar2 = (uint)local_48;
                local_28 = (int)(uVar1 >> 0x20);
                uVar6 = (uint)uVar1;
                local_8 = local_18;
                local_48._4_4_ = local_14;
                uVar15 = __allmul(local_24,0,(uint)local_48,local_14);
                uVar1 = CONCAT44(uVar6,local_8);
                local_8 = uVar2;
                if (uVar15 <= uVar1) break;
                local_48._0_4_ = uVar2 - 1;
                local_48._4_4_ = local_14 + -1 + (uint)(uVar2 != 0);
                local_14 = local_48._4_4_;
                local_8 = (uint)local_48;
                if (local_28 + (uint)CARRY4(uVar6,local_34) != 0) break;
                uVar1 = (ulonglong)(uVar6 + local_34);
              }
            }
            if ((local_14 != 0) || (local_8 != 0)) {
              uVar6 = 0;
              uVar2 = 0;
              if (local_38 != 0) {
                pbVar9 = param_2 + 4;
                local_18 = local_38;
                pbVar4 = local_40;
                do {
                  lVar14 = (ulonglong)(uint)local_48 * (ulonglong)*(uint *)pbVar9;
                  uVar3 = (uint)lVar14;
                  uVar11 = uVar6 + uVar3;
                  uVar6 = uVar2 + (int)((ulonglong)lVar14 >> 0x20) +
                                  local_48._4_4_ * *(uint *)pbVar9 + (uint)CARRY4(uVar6,uVar3);
                  uVar2 = 0;
                  if (*(uint *)pbVar4 < uVar11) {
                    bVar12 = 0xfffffffe < uVar6;
                    uVar6 = uVar6 + 1;
                    uVar2 = (uint)bVar12;
                  }
                  *(uint *)pbVar4 = *(uint *)pbVar4 - uVar11;
                  pbVar4 = pbVar4 + 4;
                  pbVar9 = pbVar9 + 4;
                  local_18 = local_18 - 1;
                } while (local_18 != 0);
              }
              if ((uVar2 != 0) || (local_4c < uVar6)) {
                if (local_38 != 0) {
                  uVar6 = 0;
                  pbVar9 = local_40;
                  uVar2 = local_38;
                  pbVar4 = param_2;
                  do {
                    pbVar4 = pbVar4 + 4;
                    uVar3 = *(uint *)pbVar9;
                    uVar11 = *(uint *)pbVar4;
                    uVar5 = uVar3 + *(uint *)pbVar4;
                    *(uint *)pbVar9 = uVar5 + uVar6;
                    uVar6 = (uint)CARRY4(uVar3,uVar11) + (uint)CARRY4(uVar5,uVar6);
                    uVar2 = uVar2 - 1;
                    pbVar9 = pbVar9 + 4;
                  } while (uVar2 != 0);
                }
                bVar12 = local_8 != 0;
                local_8 = local_8 - 1;
                local_14 = local_14 + -1 + (uint)bVar12;
              }
              local_c = local_3c - 1;
            }
            local_40 = local_40 + -4;
            local_1c = (big_integer *)((int)local_1c + -1);
            local_50 = local_50 + -4;
            local_3c = local_3c - 1;
            pbVar4 = local_20;
            local_20 = (big_integer *)local_8;
          } while (-1 < (int)local_1c);
        }
        local_c = local_c + 1;
        if (local_c < *(uint *)param_1) {
          pbVar9 = param_1 + local_c * 4 + 4;
          uVar2 = local_c;
          do {
            *(undefined4 *)pbVar9 = 0;
            pbVar9 = pbVar9 + 4;
            uVar2 = uVar2 + 1;
          } while (uVar2 < *(uint *)param_1);
        }
        *(uint *)param_1 = local_c;
        while ((local_c != 0 && (*(int *)(param_1 + local_c * 4) == 0))) {
          local_c = local_c - 1;
          *(uint *)param_1 = local_c;
        }
        return CONCAT44(pbVar4,local_20);
      }
    }
  }
  return 0;
}

