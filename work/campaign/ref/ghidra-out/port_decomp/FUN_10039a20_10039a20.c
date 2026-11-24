
void FUN_10039a20(int param_1,int param_2,int *param_3,int *param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  int *in_EDX;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  float fVar11;
  int local_1c;
  int local_18;
  int local_10;
  byte local_9;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar8 = *param_3;
  iVar6 = *param_4;
  local_18 = *in_EDX;
  if (*(char *)((int)in_EDX + 0x15) == '\0') {
LAB_10039ba2:
    *(undefined4 *)(in_ECX + 0x70) = 0x15;
LAB_10039ba9:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_1c = iVar8;
  if (0 < param_6) {
    do {
      if (*(int *)(in_ECX + 0x580) < 10) {
        if (*(int *)(in_ECX + 0x580) == 0) {
          *(undefined4 *)(in_ECX + 0x57c) = 0;
        }
        do {
          iVar8 = local_1c;
          if (*(int *)(in_ECX + 0x574) == 0) {
            if (*(char *)(in_ECX + 0x56c) == '\0') {
              iVar7 = FUN_10039100();
              bVar10 = iVar7 == 0;
              goto LAB_10039ace;
            }
          }
          else {
            bVar10 = *(char *)(in_ECX + 0x56c) == '\0';
LAB_10039ace:
            if (bVar10) break;
          }
          *(char *)(in_ECX + 0x56c) = *(char *)(in_ECX + 0x56c) + -1;
          *(int *)(in_ECX + 0x584) = *(int *)(in_ECX + 0x584) + 1;
          pbVar4 = *(byte **)(in_ECX + 0x2c);
          if (pbVar4 == (byte *)0x0) {
            piVar2 = *(int **)(in_ECX + 0x20);
            iVar7 = (**(code **)(*piVar2 + 4))();
            if (iVar7 == 0) {
              local_9 = 0;
              (**(code **)(*piVar2 + 8))(&local_9,1);
              uVar5 = (uint)local_9;
            }
            else {
              *(undefined4 *)(in_ECX + 0x6c) = 1;
              uVar5 = 0;
            }
          }
          else if (pbVar4 < *(byte **)(in_ECX + 0x34)) {
            bVar3 = *pbVar4;
            *(byte **)(in_ECX + 0x2c) = pbVar4 + 1;
            uVar5 = (uint)bVar3;
          }
          else {
            *(undefined4 *)(in_ECX + 0x6c) = 1;
            uVar5 = 0;
          }
          *(int *)(in_ECX + 0x57c) =
               *(int *)(in_ECX + 0x57c) + (uVar5 << ((byte)*(int *)(in_ECX + 0x580) & 0x1f));
          iVar7 = *(int *)(in_ECX + 0x580) + 8;
          *(int *)(in_ECX + 0x580) = iVar7;
        } while (iVar7 < 0x19);
      }
      local_10 = (int)*(short *)((int)in_EDX + (*(uint *)(in_ECX + 0x57c) & 0x3ff) * 2 + 0x24);
      if (local_10 < 0) {
        local_10 = FUN_100393d0();
        if (local_10 < 0) goto LAB_10039b90;
      }
      else {
        bVar3 = *(byte *)(in_EDX[2] + local_10);
        piVar2 = (int *)(in_ECX + 0x580);
        *piVar2 = *piVar2 - (uint)bVar3;
        *(uint *)(in_ECX + 0x57c) = *(uint *)(in_ECX + 0x57c) >> (bVar3 & 0x1f);
        if (*piVar2 < 0) {
          *(undefined4 *)(in_ECX + 0x580) = 0;
LAB_10039b90:
          if ((*(char *)(in_ECX + 0x56c) != '\0') || (*(int *)(in_ECX + 0x574) == 0))
          goto LAB_10039ba2;
          goto LAB_10039ba9;
        }
      }
      if (param_2 * param_5 < iVar6 * param_2 + local_18 + iVar8) {
        local_18 = (param_5 - iVar6) * param_2 + iVar8;
      }
      if (0 < local_18) {
        iVar7 = *in_EDX * local_10 * 4;
        if (*(char *)((int)in_EDX + 0x16) == '\0') {
          local_10 = local_18;
          iVar9 = iVar6;
          do {
            iVar6 = *(int *)(param_1 + iVar8 * 4);
            if (iVar6 != 0) {
              *(float *)(iVar6 + iVar9 * 4) =
                   *(float *)(in_EDX[7] + iVar7) + 0.0 + *(float *)(iVar6 + iVar9 * 4);
            }
            iVar1 = iVar8 + 1;
            iVar6 = iVar9 + 1;
            if (iVar1 != param_2) {
              iVar6 = iVar9;
            }
            iVar8 = 0;
            if (iVar1 != param_2) {
              iVar8 = iVar1;
            }
            iVar7 = iVar7 + 4;
            local_10 = local_10 + -1;
            iVar9 = iVar6;
            local_1c = iVar8;
          } while (local_10 != 0);
        }
        else {
          fVar11 = 0.0;
          local_10 = local_18;
          iVar9 = iVar6;
          do {
            fVar11 = fVar11 + *(float *)(iVar7 + in_EDX[7]);
            iVar6 = *(int *)(param_1 + iVar8 * 4);
            if (iVar6 != 0) {
              *(float *)(iVar6 + iVar9 * 4) = *(float *)(iVar6 + iVar9 * 4) + fVar11;
            }
            iVar1 = iVar8 + 1;
            iVar6 = iVar9 + 1;
            if (iVar1 != param_2) {
              iVar6 = iVar9;
            }
            iVar8 = 0;
            if (iVar1 != param_2) {
              iVar8 = iVar1;
            }
            iVar7 = iVar7 + 4;
            local_10 = local_10 + -1;
            iVar9 = iVar6;
            local_1c = iVar8;
          } while (local_10 != 0);
        }
      }
      param_6 = param_6 - local_18;
    } while (0 < param_6);
  }
  *param_3 = iVar8;
  *param_4 = iVar6;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

