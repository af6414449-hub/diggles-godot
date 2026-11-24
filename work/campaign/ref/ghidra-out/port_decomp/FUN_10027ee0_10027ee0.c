
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_10027ee0(uint param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  int in_EDX;
  bool bVar5;
  longlong lVar6;
  undefined8 uVar7;
  
  uVar3 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  if ((in_ECX == 0) || (*(int *)(in_ECX + 0x1a28) == 0)) {
    __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (in_EDX != 0) {
    piVar1 = (int *)(in_ECX + 0x3e68);
    if ((piVar1 != (int *)0x0) && (param_1 != 0 || param_2 != 0)) {
      if ((*piVar1 == *(int *)(in_ECX + 0x3e6c)) || (*(int *)(in_ECX + 0x3e74) == 0)) {
        uVar7 = (**(code **)(in_ECX + 0x3e7c))(piVar1,param_1,param_2);
        puVar2 = (uint *)(in_ECX + 0x3e58);
        uVar4 = *puVar2;
        *puVar2 = *puVar2 + (uint)uVar7;
        *(int *)(in_ECX + 0x3e5c) =
             *(int *)(in_ECX + 0x3e5c) + (int)((ulonglong)uVar7 >> 0x20) +
             (uint)CARRY4(uVar4,(uint)uVar7);
        __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
        return;
      }
      if (*(int *)(in_ECX + 0x3e74) == 1) {
        uVar7 = FUN_10027610(param_1,param_2,piVar1);
        puVar2 = (uint *)(in_ECX + 0x3e58);
        uVar4 = *puVar2;
        *puVar2 = *puVar2 + (uint)uVar7;
        *(int *)(in_ECX + 0x3e5c) =
             *(int *)(in_ECX + 0x3e5c) + (int)((ulonglong)uVar7 >> 0x20) +
             (uint)CARRY4(uVar4,(uint)uVar7);
        __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    *(undefined4 *)(in_ECX + 0x3e58) = *(undefined4 *)(in_ECX + 0x3e58);
    *(undefined4 *)(in_ECX + 0x3e5c) = *(undefined4 *)(in_ECX + 0x3e5c);
    __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((param_2 == 0) && (param_1 == 0)) {
    __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
    return;
  }
  while( true ) {
    uVar4 = (uint)(0x1000 / (ulonglong)*(uint *)(in_ECX + 0x1a20));
    if ((param_2 == 0) && (param_1 < uVar4)) {
      uVar4 = param_1;
    }
    lVar6 = FUN_10027ee0(uVar4,0);
    if (lVar6 == 0) break;
    bVar5 = param_1 < (uint)lVar6;
    param_1 = param_1 - (uint)lVar6;
    param_2 = (param_2 - (int)((ulonglong)lVar6 >> 0x20)) - (uint)bVar5;
    if ((param_2 == 0) && (param_1 == 0)) {
      __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(uVar3 ^ (uint)&stack0xfffffffc);
  return;
}

