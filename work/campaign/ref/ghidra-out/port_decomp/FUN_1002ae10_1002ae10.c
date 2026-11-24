
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_1002ae10(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *in_ECX;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  int local_1028;
  uint local_1024;
  undefined1 local_100c [4100];
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if ((*(short *)(in_ECX + 0x15) == 1) && (*(short *)((int)in_ECX + 0x52) == 0x10)) {
    FUN_10029cf0(param_1,param_2);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((*(ushort *)((int)in_ECX + 0x52) & 7) == 0) {
    uVar6 = (int)((uint)*(ushort *)((int)in_ECX + 0x26) * (uint)*(ushort *)((int)in_ECX + 0x52)) >>
            3;
  }
  else {
    uVar6 = (uint)*(ushort *)(in_ECX + 0xc);
  }
  if (uVar6 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_1028 = param_2;
  local_1024 = param_1;
  if ((param_2 == 0) && (param_1 == 0)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  uVar3 = (uint)(0x1000 / (ulonglong)uVar6);
  do {
    if (local_1028 != 0) goto LAB_1002af21;
    uVar4 = local_1024;
    if (uVar3 <= local_1024) goto LAB_1002af21;
    while( true ) {
      if (((uVar4 == 0) || (*(short *)(in_ECX + 0x15) == 2)) || (*(short *)(in_ECX + 0x15) == 0x11))
      goto LAB_1002b05d;
      if ((*(ushort *)((int)in_ECX + 0x52) & 7) == 0) {
        uVar5 = (int)((uint)*(ushort *)((int)in_ECX + 0x26) * (uint)*(ushort *)((int)in_ECX + 0x52))
                >> 3;
      }
      else {
        uVar5 = (uint)*(ushort *)(in_ECX + 0xc);
      }
      if (uVar5 == 0) goto LAB_1002b05d;
      if ((int)((ulonglong)uVar4 * (ulonglong)uVar5 >> 0x20) != 0) {
        uVar4 = (uint)(0xffffffff / (ulonglong)uVar5);
      }
      uVar4 = uVar4 * uVar5;
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
      uVar4 = uVar4 / uVar5;
      if (uVar4 == 0) goto LAB_1002b05d;
      FUN_1002aaf0(*(ushort *)(in_ECX + 0x14) * uVar4,uVar6 / *(ushort *)(in_ECX + 0x14));
      bVar7 = local_1024 < uVar4;
      local_1024 = local_1024 - uVar4;
      local_1028 = local_1028 - (uint)bVar7;
      if (local_1028 == 0) break;
LAB_1002af21:
      uVar4 = uVar3;
    }
  } while (local_1024 != 0);
LAB_1002b05d:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

