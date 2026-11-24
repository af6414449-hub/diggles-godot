
void FUN_10022f20(int *param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int iVar6;
  int in_EDX;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint local_14 [4];
  
  local_14[3] = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  bVar3 = *(byte *)((int)param_1 + 0xe);
  bVar2 = *(byte *)((int)param_1 + 0xd);
  iVar4 = (uint)bVar2 + (uint)bVar3;
  local_14[2] = 0xffffffff;
  local_14[1] = 0xffffffff;
  iVar9 = in_ECX + 0x900;
  local_14[0] = 0xffffffff;
  iVar1 = (uint)(bVar3 != 0) * 2 + 1;
  iVar6 = *param_1;
  uVar8 = 0;
  if (iVar4 != 0) {
    do {
      uVar10 = (uint)*(byte *)(uVar8 + iVar6);
      iVar5 = 0;
      if (uVar10 != 0) {
        do {
          if ((*(float *)(iVar9 + iVar5 * 4) != 0.0) || (*(float *)(iVar9 + 4 + iVar5 * 4) != 0.0))
          {
            local_14[uVar8 % 3] = uVar8;
            break;
          }
          iVar5 = iVar5 + 2;
        } while (iVar5 < (int)uVar10);
      }
      uVar8 = uVar8 + 1;
      iVar9 = iVar9 + uVar10 * 4;
    } while ((int)uVar8 < iVar4);
  }
  if (bVar2 != 0) {
    uVar8 = local_14[0];
    if ((int)local_14[0] < (int)local_14[1]) {
      uVar8 = local_14[1];
    }
    if (((int)local_14[2] <= (int)uVar8) &&
       (local_14[2] = local_14[0], (int)local_14[0] < (int)local_14[1])) {
      local_14[2] = local_14[1];
    }
    local_14[1] = local_14[2];
    local_14[0] = local_14[2];
  }
  iVar6 = 0;
  pbVar7 = (byte *)((in_EDX - iVar1) + iVar4);
  iVar9 = (uint)(bVar3 != 0) * 4 + 2;
  do {
    if ((int)local_14[iVar6] < (iVar4 - iVar9) + iVar6) {
      bVar3 = *(byte *)((in_EDX - iVar9) + iVar6 + iVar4);
    }
    else {
      bVar3 = -((*(byte *)(param_2 + 1) & 8) != 0) & 3;
    }
    *pbVar7 = bVar3;
    iVar6 = iVar6 + 1;
    pbVar7 = pbVar7 + 1;
  } while (iVar6 < iVar1);
  FUN_10022d20(*param_1,param_2,local_14,*(ushort *)(param_1 + 9) & 1);
  __security_check_cookie(local_14[3] ^ (uint)&stack0xfffffffc);
  return;
}

