
void FUN_10006df0(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *in_EDX;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  undefined1 local_38 [16];
  uint local_28;
  uint local_24;
  undefined4 *local_20;
  uint *local_1c;
  uint local_18;
  uint *local_14;
  uint *local_10;
  uint local_c;
  int *local_8;
  
  local_1c = in_EDX;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_20 = (undefined4 *)
             FUN_100402f0(-(uint)((int)((ulonglong)*in_EDX * 0x1c >> 0x20) != 0) |
                          (uint)((ulonglong)*in_EDX * 0x1c));
  uVar12 = *in_EDX;
  uVar11 = 0;
  if (uVar12 != 0) {
    puVar9 = (uint *)(*local_8 + 0xc);
    do {
      if (((799 < puVar9[-3]) && (599 < puVar9[-2])) && (0x1d < puVar9[-1] / *puVar9)) break;
      uVar11 = uVar11 + 1;
      puVar9 = puVar9 + 7;
    } while (uVar11 < uVar12);
  }
  if (uVar11 == uVar12) {
    FUN_100053a0(0xffffffff);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_38,(ThrowInfo *)&DAT_1004a24c);
  }
  uVar12 = uVar11 + 1;
  iVar10 = *local_8;
  puVar1 = (undefined4 *)(iVar10 + uVar11 * 0x1c);
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  uVar4 = puVar1[3];
  *local_20 = *puVar1;
  local_20[1] = uVar2;
  local_20[2] = uVar3;
  local_20[3] = uVar4;
  puVar1 = (undefined4 *)(iVar10 + 0x10 + uVar11 * 0x1c);
  uVar2 = puVar1[1];
  local_20[4] = *puVar1;
  local_20[5] = uVar2;
  local_20[6] = *(undefined4 *)(iVar10 + 0x18 + uVar11 * 0x1c);
  local_c = 1;
  piVar13 = local_8;
  if (uVar12 < *in_EDX) {
    local_10 = local_20 + 1;
    iVar10 = uVar12 * 0x1c;
    do {
      uVar8 = local_c;
      uVar11 = *(uint *)(*local_8 + 4 + iVar10);
      local_14 = (uint *)(*local_8 + iVar10);
      local_18 = *local_14;
      local_24 = local_14[2] / local_14[3];
      local_28 = local_c;
      if (((((local_10[-1] != local_18) || (*local_10 != uVar11)) &&
           ((799 < (int)local_18 && ((599 < (int)uVar11 && (uVar11 * local_18 < 0x1000000)))))) &&
          (local_18 <= param_1)) && ((uVar11 <= param_2 && (0x1d < local_24)))) {
        uVar5 = local_14[1];
        uVar6 = local_14[2];
        uVar7 = local_14[3];
        local_10[6] = *local_14;
        local_10[7] = uVar5;
        local_10[8] = uVar6;
        local_10[9] = uVar7;
        uVar5 = local_14[5];
        local_10[10] = local_14[4];
        local_10[0xb] = uVar5;
        local_10[0xc] = local_14[6];
        local_10 = local_10 + 7;
        local_c = local_c + 1;
        FUN_100028b0(&DAT_1416ec00,0x40,"Mode %d : (%d x %d) with %u Hz \n",uVar8,local_18,uVar11,
                     local_24);
        OutputDebugStringA(&DAT_1416ec00);
      }
      uVar12 = uVar12 + 1;
      iVar10 = iVar10 + 0x1c;
      in_EDX = local_1c;
      piVar13 = local_8;
    } while (uVar12 < *local_1c);
  }
  free((void *)*piVar13);
  *piVar13 = (int)local_20;
  *in_EDX = local_c;
  return;
}

