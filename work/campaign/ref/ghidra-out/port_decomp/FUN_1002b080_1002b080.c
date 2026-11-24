
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_1002b080(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *in_ECX;
  int iVar5;
  void *in_EDX;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  int local_102c;
  uint local_1028;
  void *local_1010;
  undefined1 local_100c [4100];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if ((*(ushort *)((int)in_ECX + 0x52) & 7) == 0) {
    uVar7 = (int)((uint)*(ushort *)((int)in_ECX + 0x26) * (uint)*(ushort *)((int)in_ECX + 0x52)) >>
            3;
  }
  else {
    uVar7 = (uint)*(ushort *)(in_ECX + 0xc);
  }
  if (uVar7 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_102c = param_2;
  local_1028 = param_1;
  if ((param_2 == 0) && (param_1 == 0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  uVar3 = (uint)(0x1000 / (ulonglong)uVar7);
  local_1010 = in_EDX;
  do {
    if (local_102c != 0) goto LAB_1002b160;
    uVar4 = local_1028;
    if (uVar3 <= local_1028) goto LAB_1002b160;
    while( true ) {
      if (((uVar4 == 0) || (*(short *)(in_ECX + 0x15) == 2)) || (*(short *)(in_ECX + 0x15) == 0x11))
      goto LAB_1002b2d4;
      if ((*(ushort *)((int)in_ECX + 0x52) & 7) == 0) {
        uVar6 = (int)((uint)*(ushort *)((int)in_ECX + 0x26) * (uint)*(ushort *)((int)in_ECX + 0x52))
                >> 3;
      }
      else {
        uVar6 = (uint)*(ushort *)(in_ECX + 0xc);
      }
      if (uVar6 == 0) goto LAB_1002b2d4;
      if ((int)((ulonglong)uVar4 * (ulonglong)uVar6 >> 0x20) != 0) {
        uVar4 = (uint)(0xffffffff / (ulonglong)uVar6);
      }
      uVar4 = uVar4 * uVar6;
      if (uVar4 == 0) {
        uVar4 = 0;
      }
      else {
        uVar2 = in_ECX[0x1c];
        if ((in_ECX[0x1d] == 0) && (uVar2 <= uVar4 && uVar4 - uVar2 != 0)) {
          uVar4 = uVar2;
        }
        uVar4 = (*(code *)*in_ECX)(in_ECX[3],local_100c,uVar4);
        puVar1 = in_ECX + 0x1c;
        uVar2 = *puVar1;
        *puVar1 = *puVar1 - uVar4;
        in_ECX[0x1d] = in_ECX[0x1d] - (uint)(uVar2 < uVar4);
      }
      uVar4 = uVar4 / uVar6;
      if (uVar4 == 0) goto LAB_1002b2d4;
      uVar6 = uVar7 / *(ushort *)(in_ECX + 0x14);
      iVar5 = *(ushort *)(in_ECX + 0x14) * uVar4;
      if (uVar6 == 4) {
        FUN_1002b8d0(iVar5);
      }
      else if (uVar6 == 8) {
        FUN_1002ba30(iVar5);
      }
      else {
        memset(local_1010,0,iVar5 * 2);
      }
      local_1010 = (void *)((int)local_1010 + *(ushort *)(in_ECX + 0x14) * uVar4 * 2);
      bVar8 = local_1028 < uVar4;
      local_1028 = local_1028 - uVar4;
      local_102c = local_102c - (uint)bVar8;
      if (local_102c == 0) break;
LAB_1002b160:
      uVar4 = uVar3;
    }
  } while (local_1028 != 0);
LAB_1002b2d4:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

