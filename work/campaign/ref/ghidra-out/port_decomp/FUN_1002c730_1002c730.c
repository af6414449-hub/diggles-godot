
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_1002c730(uint param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *in_ECX;
  uint uVar4;
  uint uVar5;
  float *in_EDX;
  float *pfVar6;
  uint uVar7;
  bool bVar8;
  int local_102c;
  uint local_1028;
  float *local_1020;
  byte local_100c [4100];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if ((*(ushort *)((int)in_ECX + 0x52) & 7) == 0) {
    uVar4 = (int)((uint)*(ushort *)((int)in_ECX + 0x26) * (uint)*(ushort *)((int)in_ECX + 0x52)) >>
            3;
  }
  else {
    uVar4 = (uint)*(ushort *)(in_ECX + 0xc);
  }
  if (uVar4 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_102c = param_2;
  local_1028 = param_1;
  if ((param_2 != 0) || (param_1 != 0)) {
    uVar4 = (uint)(0x1000 / (ulonglong)uVar4);
    local_1020 = in_EDX;
    do {
      uVar3 = uVar4;
      if ((local_102c == 0) && (local_1028 < uVar4)) {
        uVar3 = local_1028;
      }
      if (((uVar3 == 0) || (*(short *)(in_ECX + 0x15) == 2)) || (*(short *)(in_ECX + 0x15) == 0x11))
      break;
      if ((*(ushort *)((int)in_ECX + 0x52) & 7) == 0) {
        uVar7 = (int)((uint)*(ushort *)((int)in_ECX + 0x26) * (uint)*(ushort *)((int)in_ECX + 0x52))
                >> 3;
      }
      else {
        uVar7 = (uint)*(ushort *)(in_ECX + 0xc);
      }
      if (uVar7 == 0) break;
      if ((int)((ulonglong)uVar3 * (ulonglong)uVar7 >> 0x20) != 0) {
        uVar3 = (uint)(0xffffffff / (ulonglong)uVar7);
      }
      uVar3 = uVar3 * uVar7;
      if (uVar3 == 0) {
        uVar3 = 0;
      }
      else {
        uVar5 = in_ECX[0x1c];
        if ((in_ECX[0x1d] == 0) && (uVar5 <= uVar3 && uVar3 - uVar5 != 0)) {
          uVar3 = uVar5;
        }
        uVar3 = (*(code *)*in_ECX)(in_ECX[3],local_100c,uVar3);
        puVar1 = in_ECX + 0x1c;
        uVar5 = *puVar1;
        *puVar1 = *puVar1 - uVar3;
        in_ECX[0x1d] = in_ECX[0x1d] - (uint)(uVar5 < uVar3);
      }
      uVar3 = uVar3 / uVar7;
      if (uVar3 == 0) break;
      uVar7 = *(ushort *)(in_ECX + 0x14) * uVar3;
      if (local_1020 != (float *)0x0) {
        uVar5 = 0;
        pfVar6 = local_1020;
        if (3 < uVar7) {
          do {
            *pfVar6 = (float)(int)*(short *)(&DAT_10043b50 + (uint)local_100c[uVar5] * 2) *
                      3.0517578e-05;
            pfVar6[1] = (float)(int)*(short *)(&DAT_10043b50 + (uint)local_100c[uVar5 + 1] * 2) *
                        3.0517578e-05;
            pfVar6[2] = (float)(int)*(short *)(&DAT_10043b50 + (uint)local_100c[uVar5 + 2] * 2) *
                        3.0517578e-05;
            iVar2 = uVar5 + 3;
            uVar5 = uVar5 + 4;
            pfVar6[3] = (float)(int)*(short *)(&DAT_10043b50 + (uint)local_100c[iVar2] * 2) *
                        3.0517578e-05;
            pfVar6 = pfVar6 + 4;
          } while (uVar5 < uVar7 - 3);
        }
        for (; uVar5 < uVar7; uVar5 = uVar5 + 1) {
          *pfVar6 = (float)(int)*(short *)(&DAT_10043b50 + (uint)local_100c[uVar5] * 2) *
                    3.0517578e-05;
          pfVar6 = pfVar6 + 1;
        }
      }
      bVar8 = local_1028 < uVar3;
      local_1028 = local_1028 - uVar3;
      local_1020 = local_1020 + *(ushort *)(in_ECX + 0x14) * uVar3;
      local_102c = local_102c - (uint)bVar8;
    } while ((local_102c != 0) || (local_1028 != 0));
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

