
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_1002ca50(uint param_1,int param_2)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  int in_EDX;
  bool bVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  uVar3 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (((in_ECX != 0) && (param_1 != 0 || param_2 != 0)) && (in_EDX != 0)) {
    uVar6 = __allmul(*(undefined2 *)(in_ECX + 0x50),0,param_1,param_2);
    if ((uVar6 & 0x3fffffff00000000) != 0 || (uint)uVar6 >> 0x1e != 0) {
      param_1 = (uint)(0x3fffffff / (ulonglong)*(ushort *)(in_ECX + 0x50));
      param_2 = 0;
    }
    sVar1 = *(short *)(in_ECX + 0x54);
    if (sVar1 == 1) {
      FUN_1002bd80(param_1,param_2);
      __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (sVar1 == 2) {
      if ((param_2 == 0) && (param_1 == 0)) {
        __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
        return;
      }
      uVar2 = *(ushort *)(in_ECX + 0x50);
      while( true ) {
        uVar4 = (uint)(0x800 / (ulonglong)uVar2);
        if ((param_2 == 0) && (param_1 < uVar4)) {
          uVar4 = param_1;
        }
        lVar7 = FUN_1002b7b0(uVar4,0);
        uVar4 = (uint)lVar7;
        if (lVar7 == 0) break;
        FUN_1002cfe0(*(ushort *)(in_ECX + 0x50) * uVar4);
        bVar5 = param_1 < uVar4;
        param_1 = param_1 - uVar4;
        param_2 = (param_2 - (int)((ulonglong)lVar7 >> 0x20)) - (uint)bVar5;
        uVar2 = *(ushort *)(in_ECX + 0x50);
        if ((param_2 == 0) && (param_1 == 0)) {
          __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
      __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (sVar1 == 3) {
      FUN_1002c1a0(param_1,param_2);
      __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (sVar1 == 6) {
      FUN_1002c410(param_1,param_2);
      __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (sVar1 == 7) {
      FUN_1002c730(param_1,param_2);
      __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (sVar1 == 0x11) {
      if ((param_2 == 0) && (param_1 == 0)) {
        __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
        return;
      }
      uVar2 = *(ushort *)(in_ECX + 0x50);
      while( true ) {
        uVar4 = (uint)(0x800 / (ulonglong)uVar2);
        if ((param_2 == 0) && (param_1 < uVar4)) {
          uVar4 = param_1;
        }
        lVar7 = FUN_1002b7b0(uVar4,0);
        uVar4 = (uint)lVar7;
        if (lVar7 == 0) break;
        FUN_1002cfe0(*(ushort *)(in_ECX + 0x50) * uVar4);
        bVar5 = param_1 < uVar4;
        param_1 = param_1 - uVar4;
        param_2 = (param_2 - (int)((ulonglong)lVar7 >> 0x20)) - (uint)bVar5;
        uVar2 = *(ushort *)(in_ECX + 0x50);
        if ((param_2 == 0) && (param_1 == 0)) {
          __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
      __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

