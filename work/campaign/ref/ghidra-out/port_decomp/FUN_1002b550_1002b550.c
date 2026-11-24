
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_1002b550(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined4 *in_ECX;
  uint uVar3;
  uint uVar4;
  int in_EDX;
  uint uVar5;
  bool bVar6;
  int local_1024;
  uint local_1020;
  int local_1018;
  byte local_100c [4100];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if ((*(ushort *)((int)in_ECX + 0x52) & 7) == 0) {
    uVar3 = (int)((uint)*(ushort *)((int)in_ECX + 0x26) * (uint)*(ushort *)((int)in_ECX + 0x52)) >>
            3;
  }
  else {
    uVar3 = (uint)*(ushort *)(in_ECX + 0xc);
  }
  if (uVar3 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_1024 = param_2;
  local_1020 = param_1;
  if ((param_2 == 0) && (param_1 == 0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  uVar3 = (uint)(0x1000 / (ulonglong)uVar3);
  local_1018 = in_EDX;
LAB_1002b620:
  if (local_1024 != 0) goto LAB_1002b630;
  uVar2 = local_1020;
  if (uVar3 <= local_1020) goto LAB_1002b630;
  do {
    if (((uVar2 == 0) || (*(short *)(in_ECX + 0x15) == 2)) || (*(short *)(in_ECX + 0x15) == 0x11)) {
LAB_1002b799:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    if ((*(ushort *)((int)in_ECX + 0x52) & 7) == 0) {
      uVar5 = (int)((uint)*(ushort *)((int)in_ECX + 0x26) * (uint)*(ushort *)((int)in_ECX + 0x52))
              >> 3;
    }
    else {
      uVar5 = (uint)*(ushort *)(in_ECX + 0xc);
    }
    if (uVar5 == 0) goto LAB_1002b799;
    if ((int)((ulonglong)uVar2 * (ulonglong)uVar5 >> 0x20) != 0) {
      uVar2 = (uint)(0xffffffff / (ulonglong)uVar5);
    }
    uVar2 = uVar2 * uVar5;
    if (uVar2 == 0) {
      uVar2 = 0;
    }
    else {
      uVar4 = in_ECX[0x1c];
      if ((in_ECX[0x1d] == 0) && (uVar4 <= uVar2 && uVar2 - uVar4 != 0)) {
        uVar2 = uVar4;
      }
      uVar2 = (*(code *)*in_ECX)(in_ECX[3],local_100c,uVar2);
      puVar1 = in_ECX + 0x1c;
      uVar4 = *puVar1;
      *puVar1 = *puVar1 - uVar2;
      in_ECX[0x1d] = in_ECX[0x1d] - (uint)(uVar4 < uVar2);
    }
    uVar2 = uVar2 / uVar5;
    if (uVar2 == 0) goto LAB_1002b799;
    uVar4 = (uint)*(ushort *)(in_ECX + 0x14);
    uVar5 = 0;
    if (uVar4 * uVar2 != 0) {
      do {
        *(undefined2 *)(local_1018 + uVar5 * 2) =
             *(undefined2 *)(&DAT_10043b50 + (uint)local_100c[uVar5] * 2);
        uVar5 = uVar5 + 1;
      } while (uVar5 < uVar4 * uVar2);
      uVar4 = (uint)*(ushort *)(in_ECX + 0x14);
    }
    bVar6 = local_1020 < uVar2;
    local_1020 = local_1020 - uVar2;
    local_1018 = local_1018 + uVar4 * uVar2 * 2;
    local_1024 = local_1024 - (uint)bVar6;
    if (local_1024 == 0) break;
LAB_1002b630:
    uVar2 = uVar3;
  } while( true );
  if (local_1020 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  goto LAB_1002b620;
}

