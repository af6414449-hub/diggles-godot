
void FUN_1003f210(uint *param_1)

{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  byte bVar4;
  int in_ECX;
  int *in_EDX;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte local_40 [22];
  uint local_2a;
  byte local_26;
  uint *local_24;
  int *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  byte local_9;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  local_24 = param_1;
  local_20 = in_EDX;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar6 = *(int *)(in_ECX + 0x6c);
  while (iVar6 == 0) {
    pbVar1 = *(byte **)(in_ECX + 0x2c);
    if (pbVar1 == (byte *)0x0) {
      piVar2 = *(int **)(in_ECX + 0x20);
      iVar6 = (**(code **)(*piVar2 + 4))();
      if (iVar6 != 0) goto LAB_1003f264;
      local_9 = 0;
      (**(code **)(*piVar2 + 8))(&local_9,1);
      bVar4 = local_9;
LAB_1003f285:
      if (bVar4 == 0x4f) {
        if (*(char *)(in_ECX + 0x3c) == '\0') {
          if (*(int *)(in_ECX + 0x2c) == 0) {
            iVar6 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x14))();
            local_14 = iVar6 - *(int *)(in_ECX + 0x24);
          }
          else {
            local_14 = *(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x30);
          }
        }
        else {
          local_14 = 0;
        }
        if (*(uint *)(in_ECX + 0x38) < local_14 - 0x19) break;
        iVar6 = 1;
        do {
          pbVar1 = *(byte **)(in_ECX + 0x2c);
          if (pbVar1 == (byte *)0x0) {
            piVar2 = *(int **)(in_ECX + 0x20);
            iVar3 = (**(code **)(*piVar2 + 4))();
            if (iVar3 == 0) {
              local_9 = 0;
              (**(code **)(*piVar2 + 8))(&local_9,1);
              bVar4 = local_9;
            }
            else {
              *(undefined4 *)(in_ECX + 0x6c) = 1;
              bVar4 = 0;
            }
          }
          else if (pbVar1 < *(byte **)(in_ECX + 0x34)) {
            bVar4 = *pbVar1;
            *(byte **)(in_ECX + 0x2c) = pbVar1 + 1;
          }
          else {
            *(undefined4 *)(in_ECX + 0x6c) = 1;
            bVar4 = 0;
          }
        } while ((bVar4 == s_OggSvorbis_100501b8[iVar6]) && (iVar6 = iVar6 + 1, iVar6 < 4));
        if (*(int *)(in_ECX + 0x6c) != 0) break;
        if (iVar6 == 4) {
          local_40[0] = s_OggSvorbis_100501b8[0];
          local_40[1] = s_OggSvorbis_100501b8[1];
          local_40[2] = s_OggSvorbis_100501b8[2];
          local_40[3] = s_OggSvorbis_100501b8[3];
          uVar7 = 4;
          do {
            pbVar1 = *(byte **)(in_ECX + 0x2c);
            if (pbVar1 == (byte *)0x0) {
              piVar2 = *(int **)(in_ECX + 0x20);
              iVar6 = (**(code **)(*piVar2 + 4))();
              if (iVar6 == 0) {
                local_9 = 0;
                (**(code **)(*piVar2 + 8))(&local_9,1);
                bVar4 = local_9;
              }
              else {
                *(undefined4 *)(in_ECX + 0x6c) = 1;
                bVar4 = 0;
              }
            }
            else if (pbVar1 < *(byte **)(in_ECX + 0x34)) {
              bVar4 = *pbVar1;
              *(byte **)(in_ECX + 0x2c) = pbVar1 + 1;
            }
            else {
              *(undefined4 *)(in_ECX + 0x6c) = 1;
              bVar4 = 0;
            }
            local_40[uVar7] = bVar4;
            uVar7 = uVar7 + 1;
          } while (uVar7 < 0x1b);
          if (*(int *)(in_ECX + 0x6c) != 0) break;
          if (local_40[4] == '\0') {
            uVar7 = 0x16;
            local_1c = local_2a;
            do {
              local_40[uVar7] = 0;
              uVar7 = uVar7 + 1;
            } while (uVar7 < 0x1a);
            uVar7 = 0;
            uVar5 = 0;
            do {
              uVar7 = uVar7 << 8 ^ (&DAT_1416ded0)[(uint)local_40[uVar5] ^ uVar7 >> 0x18];
              uVar7 = uVar7 << 8 ^ (&DAT_1416ded0)[uVar7 >> 0x18 ^ (uint)local_40[uVar5 + 1]];
              iVar6 = uVar5 + 2;
              uVar5 = uVar5 + 3;
              uVar7 = uVar7 << 8 ^ (&DAT_1416ded0)[(uint)local_40[iVar6] ^ uVar7 >> 0x18];
            } while (uVar5 < 0x1b);
            local_10 = 0;
            local_18 = (uint)local_26;
            if (local_26 != 0) {
              do {
                pbVar1 = *(byte **)(in_ECX + 0x2c);
                if (pbVar1 == (byte *)0x0) {
                  piVar2 = *(int **)(in_ECX + 0x20);
                  iVar6 = (**(code **)(*piVar2 + 4))();
                  if (iVar6 == 0) {
                    local_9 = 0;
                    (**(code **)(*piVar2 + 8))(&local_9,1);
                    bVar4 = local_9;
                  }
                  else {
                    *(undefined4 *)(in_ECX + 0x6c) = 1;
                    bVar4 = 0;
                  }
                }
                else if (pbVar1 < *(byte **)(in_ECX + 0x34)) {
                  bVar4 = *pbVar1;
                  *(byte **)(in_ECX + 0x2c) = pbVar1 + 1;
                }
                else {
                  *(undefined4 *)(in_ECX + 0x6c) = 1;
                  bVar4 = 0;
                }
                local_10 = local_10 + (uint)bVar4;
                uVar7 = uVar7 << 8 ^ (&DAT_1416ded0)[uVar7 >> 0x18 ^ (uint)bVar4];
                local_18 = local_18 - 1;
              } while (local_18 != 0);
              if (local_10 != 0) {
                if (*(int *)(in_ECX + 0x6c) != 0) break;
                while (local_10 != 0) {
                  pbVar1 = *(byte **)(in_ECX + 0x2c);
                  if (pbVar1 == (byte *)0x0) {
                    piVar2 = *(int **)(in_ECX + 0x20);
                    iVar6 = (**(code **)(*piVar2 + 4))();
                    if (iVar6 == 0) {
                      local_9 = 0;
                      (**(code **)(*piVar2 + 8))(&local_9,1);
                      uVar5 = (uint)local_9;
                    }
                    else {
                      *(undefined4 *)(in_ECX + 0x6c) = 1;
                      uVar5 = 0;
                    }
                  }
                  else if (pbVar1 < *(byte **)(in_ECX + 0x34)) {
                    uVar5 = (uint)*pbVar1;
                    *(byte **)(in_ECX + 0x2c) = pbVar1 + 1;
                  }
                  else {
                    *(undefined4 *)(in_ECX + 0x6c) = 1;
                    uVar5 = 0;
                  }
                  uVar7 = uVar7 << 8 ^ (&DAT_1416ded0)[uVar7 >> 0x18 ^ uVar5];
                  local_10 = local_10 + -1;
                }
              }
            }
            if (uVar7 == local_1c) {
              if (local_20 != (int *)0x0) {
                if (*(char *)(in_ECX + 0x3c) == '\0') {
                  if (*(int *)(in_ECX + 0x2c) == 0) {
                    iVar6 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x14))();
                    iVar6 = iVar6 - *(int *)(in_ECX + 0x24);
                  }
                  else {
                    iVar6 = *(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x30);
                  }
                }
                else {
                  iVar6 = 0;
                }
                *local_20 = iVar6;
              }
              if (local_24 != (uint *)0x0) {
                *local_24 = local_40[5] >> 2 & 1;
              }
              uVar7 = local_14 - 1;
              if (*(char *)(in_ECX + 0x3c) == '\0') {
                *(undefined4 *)(in_ECX + 0x6c) = 0;
                if (*(int *)(in_ECX + 0x2c) != 0) {
                  uVar7 = *(uint *)(in_ECX + 0x30) + uVar7;
                  if ((uVar7 < *(uint *)(in_ECX + 0x34)) && (*(uint *)(in_ECX + 0x30) <= uVar7)) {
                    *(uint *)(in_ECX + 0x2c) = uVar7;
                    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
                    return;
                  }
                  *(uint *)(in_ECX + 0x2c) = *(uint *)(in_ECX + 0x34);
                  *(undefined4 *)(in_ECX + 0x6c) = 1;
                  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
                  return;
                }
                uVar5 = *(int *)(in_ECX + 0x24) + uVar7;
                if ((uVar5 < uVar7) || (0x7fffffff < uVar7)) {
                  uVar5 = 0x7fffffff;
                  *(undefined4 *)(in_ECX + 0x6c) = 1;
                }
                (**(code **)(**(int **)(in_ECX + 0x20) + 0x10))(uVar5);
              }
              __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
              return;
            }
          }
        }
        if (*(char *)(in_ECX + 0x3c) == '\0') {
          *(undefined4 *)(in_ECX + 0x6c) = 0;
          if (*(int *)(in_ECX + 0x2c) == 0) {
            uVar7 = *(int *)(in_ECX + 0x24) + local_14;
            if ((uVar7 < local_14) || (0x7fffffff < local_14)) {
              uVar7 = 0x7fffffff;
              *(undefined4 *)(in_ECX + 0x6c) = 1;
            }
            (**(code **)(**(int **)(in_ECX + 0x20) + 0x10))(uVar7);
          }
          else {
            uVar7 = local_14 + *(uint *)(in_ECX + 0x30);
            if ((uVar7 < *(uint *)(in_ECX + 0x34)) && (*(uint *)(in_ECX + 0x30) <= uVar7)) {
              *(uint *)(in_ECX + 0x2c) = uVar7;
            }
            else {
              *(uint *)(in_ECX + 0x2c) = *(uint *)(in_ECX + 0x34);
              *(undefined4 *)(in_ECX + 0x6c) = 1;
            }
          }
        }
      }
    }
    else {
      if (pbVar1 < *(byte **)(in_ECX + 0x34)) {
        bVar4 = *pbVar1;
        *(byte **)(in_ECX + 0x2c) = pbVar1 + 1;
        goto LAB_1003f285;
      }
LAB_1003f264:
      *(undefined4 *)(in_ECX + 0x6c) = 1;
    }
    iVar6 = *(int *)(in_ECX + 0x6c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

