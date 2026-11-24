
void FUN_10028780(int param_1,uint *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  code *in_ECX;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  byte local_14;
  byte local_13;
  byte local_12;
  byte local_11;
  uint local_10;
  
  uVar1 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (param_1 == 0) {
    iVar2 = (*in_ECX)();
    if (iVar2 != 4) {
LAB_10028817:
      __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar2 = (*in_ECX)();
    if (iVar2 != 4) {
LAB_1002883e:
      __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
      return;
    }
    *(undefined4 *)(param_3 + 0x14) = 0;
    *(uint *)(param_3 + 0x10) =
         ((local_10 >> 0x10) << 8 | local_10 >> 8 & 0xff) << 8 | local_10 & 0xff;
    *(uint *)(param_3 + 0x18) = local_10 & 1;
    bVar7 = 0xfffffff7 < *param_2;
    *param_2 = *param_2 + 8;
  }
  else {
    iVar2 = (*in_ECX)();
    if (iVar2 != 0x10) goto LAB_10028817;
    iVar2 = (*in_ECX)();
    if (iVar2 != 8) goto LAB_1002883e;
    uVar3 = (local_10 << 8 | (uint)local_11) << 8;
    uVar4 = (uVar3 | local_12) << 8;
    uVar5 = (uVar4 | local_13) << 8 | (uint)local_14;
    uVar6 = uVar5 - 0x18;
    *(uint *)(param_3 + 0x10) = uVar6;
    *(uint *)(param_3 + 0x14) =
         (((((local_10 >> 0x18) << 8 | (local_10 << 8) >> 0x18) << 8 | uVar3 >> 0x18) << 8 |
          uVar4 >> 0x18) - 1) + (uint)(0x17 < uVar5);
    *(uint *)(param_3 + 0x18) = uVar6 & 7;
    bVar7 = 0xffffffe7 < *param_2;
    *param_2 = *param_2 + 0x18;
  }
  param_2[1] = param_2[1] + (uint)bVar7;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

