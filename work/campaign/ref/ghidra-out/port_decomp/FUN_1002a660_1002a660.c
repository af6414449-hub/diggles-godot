
void FUN_1002a660(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined4 *in_ECX;
  uint uVar4;
  int iVar5;
  int in_EDX;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  int *piVar9;
  bool bVar10;
  uint local_3c;
  int local_38;
  int local_34;
  uint local_30;
  int local_2c;
  int local_28;
  byte local_1c [4];
  uint local_18;
  undefined8 local_14;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  local_14 = 0;
  local_28 = param_2;
  local_2c = param_1;
  local_38 = in_EDX;
  if ((param_2 == 0) && (param_1 == 0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_1002a6d0:
  if (((uint)in_ECX[0x39] <= (uint)in_ECX[0x17]) &&
     (((uint)in_ECX[0x39] < (uint)in_ECX[0x17] || ((uint)in_ECX[0x38] < (uint)in_ECX[0x16])))) {
    iVar2 = in_ECX[0x5c];
    if ((iVar2 == 0) && (in_ECX[0x47] == 0)) {
      if (*(short *)(in_ECX + 0x14) == 1) {
        iVar2 = (*(code *)*in_ECX)(in_ECX[3],&local_18,4);
        if (iVar2 != 4) {
LAB_1002aad5:
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
        in_ECX[0x47] = *(ushort *)(in_ECX + 0xc) - 4;
        uVar4 = (int)(short)((short)(local_18 >> 8) << 8) | local_18 & 0xff;
        in_ECX[0x48] = uVar4;
        in_ECX[0x4a] = local_18 >> 0x10 & 0xff;
      }
      else {
        iVar2 = (*(code *)*in_ECX)(in_ECX[3],&local_14,8);
        if (iVar2 != 8) goto LAB_1002aad5;
        in_ECX[0x47] = *(ushort *)(in_ECX + 0xc) - 8;
        uVar6 = (int)(short)((ushort)local_14._1_1_ << 8) | (uint)(byte)local_14;
        in_ECX[0x4a] = (uint)local_14._2_1_;
        uVar4 = (int)(short)((ushort)local_14._5_1_ << 8) | (uint)local_14._4_1_;
        in_ECX[0x48] = uVar6;
        in_ECX[0x49] = uVar4;
        in_ECX[0x4b] = (uint)local_14._6_1_;
        in_ECX[0x5a] = uVar6;
      }
      in_ECX[0x5b] = uVar4;
      iVar2 = 1;
      in_ECX[0x5c] = 1;
    }
    while( true ) {
      if ((local_28 == 0) && (local_2c == 0)) goto LAB_1002aad5;
      if (iVar2 == 0) break;
      uVar4 = in_ECX[0x39];
      uVar6 = in_ECX[0x38];
      if (((uint)in_ECX[0x17] < uVar4) ||
         (((uint)in_ECX[0x17] <= uVar4 && ((uint)in_ECX[0x16] <= uVar6)))) goto LAB_1002aa9d;
      uVar3 = (uint)*(ushort *)(in_ECX + 0x14);
      uVar7 = 0;
      if (*(ushort *)(in_ECX + 0x14) != 0) {
        do {
          *(undefined2 *)(local_38 + uVar7 * 2) =
               *(undefined2 *)
                (in_ECX + (uVar7 - (uint)*(ushort *)(in_ECX + 0x14) * in_ECX[0x5c]) + 0x5c);
          uVar7 = uVar7 + 1;
          uVar3 = (uint)*(ushort *)(in_ECX + 0x14);
        } while (uVar7 < uVar3);
        uVar4 = in_ECX[0x39];
        uVar6 = in_ECX[0x38];
        iVar2 = in_ECX[0x5c];
      }
      local_38 = local_38 + uVar3 * 2;
      bVar10 = local_2c != 0;
      local_2c = local_2c + -1;
      local_28 = local_28 + -1 + (uint)bVar10;
      in_ECX[0x38] = uVar6 + 1;
      iVar2 = iVar2 + -1;
      in_ECX[0x5c] = iVar2;
      in_ECX[0x39] = uVar4 + (0xfffffffe < uVar6);
    }
    if ((in_ECX[0x47] != 0) && (in_ECX[0x5c] = 8, *(short *)(in_ECX + 0x14) != 0)) {
      piVar9 = in_ECX + 0x4a;
      local_30 = 0;
      goto LAB_1002a904;
    }
    goto LAB_1002aa9d;
  }
  goto LAB_1002aab2;
  while( true ) {
    in_ECX[0x47] = in_ECX[0x47] + -4;
    local_34 = 0;
    local_3c = 0;
    do {
      bVar1 = local_1c[local_34];
      bVar8 = bVar1 >> 4;
      iVar2 = *(int *)(&DAT_10045920 + *piVar9 * 4);
      iVar5 = iVar2 >> 3;
      if ((bVar1 & 1) != 0) {
        iVar5 = iVar5 + (iVar2 >> 2);
      }
      if ((bVar1 & 2) != 0) {
        iVar5 = iVar5 + (iVar2 >> 1);
      }
      iVar2 = iVar5 + iVar2;
      if ((bVar1 & 4) == 0) {
        iVar2 = iVar5;
      }
      iVar5 = -iVar2;
      if ((bVar1 & 8) == 0) {
        iVar5 = iVar2;
      }
      iVar5 = piVar9[-2] + iVar5;
      if (iVar5 < 0x8000) {
        if (iVar5 < -0x8000) {
          iVar5 = -0x8000;
        }
      }
      else {
        iVar5 = 0x7fff;
      }
      piVar9[-2] = iVar5;
      iVar2 = *(int *)(&DAT_100474d0 + (bVar1 & 0xf) * 4) + *piVar9;
      if (iVar2 < 0x59) {
        if (iVar2 < 0) {
          iVar2 = 0;
        }
      }
      else {
        iVar2 = 0x58;
      }
      *piVar9 = iVar2;
      in_ECX[(local_3c - in_ECX[0x5c]) * (uint)*(ushort *)(in_ECX + 0x14) + local_30 + 0x5c] = iVar5
      ;
      iVar2 = *(int *)(&DAT_10045920 + *piVar9 * 4);
      iVar5 = iVar2 >> 3;
      if ((bVar8 & 1) != 0) {
        iVar5 = iVar5 + (iVar2 >> 2);
      }
      if ((bVar8 & 2) != 0) {
        iVar5 = iVar5 + (iVar2 >> 1);
      }
      iVar2 = iVar5 + iVar2;
      if ((bVar8 & 4) == 0) {
        iVar2 = iVar5;
      }
      iVar5 = -iVar2;
      if ((bVar8 & 8) == 0) {
        iVar5 = iVar2;
      }
      iVar5 = piVar9[-2] + iVar5;
      if (iVar5 < 0x8000) {
        if (iVar5 < -0x8000) {
          iVar5 = -0x8000;
        }
      }
      else {
        iVar5 = 0x7fff;
      }
      piVar9[-2] = iVar5;
      iVar2 = *(int *)(&DAT_100474d0 + (uint)bVar8 * 4) + *piVar9;
      if (iVar2 < 0x59) {
        if (iVar2 < 0) {
          iVar2 = 0;
        }
      }
      else {
        iVar2 = 0x58;
      }
      *piVar9 = iVar2;
      uVar4 = local_3c + 2;
      local_34 = local_34 + 1;
      in_ECX[((local_3c - in_ECX[0x5c]) + 1) * (uint)*(ushort *)(in_ECX + 0x14) + local_30 + 0x5c] =
           iVar5;
      local_3c = uVar4;
    } while (uVar4 < 8);
    piVar9 = piVar9 + 1;
    local_30 = local_30 + 1;
    if (*(ushort *)(in_ECX + 0x14) <= local_30) break;
LAB_1002a904:
    iVar2 = (*(code *)*in_ECX)(in_ECX[3],local_1c,4);
    if (iVar2 != 4) {
      in_ECX[0x5c] = 0;
      goto LAB_1002aad5;
    }
  }
LAB_1002aa9d:
  if ((local_28 == 0) && (local_2c == 0)) {
LAB_1002aab2:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  goto LAB_1002a6d0;
}

