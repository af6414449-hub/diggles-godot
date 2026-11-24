
void FUN_100353e0(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  int *in_EDX;
  uint uVar3;
  uint uVar4;
  uint local_30;
  uint local_2c;
  undefined8 local_28;
  uint local_20;
  undefined4 local_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  local_28 = 0;
  iVar2 = (**(code **)(*in_EDX + 8))(&local_20,4);
  if (iVar2 == 4) {
    iVar2 = (**(code **)(*in_EDX + 8))(&local_28,6);
    if (iVar2 == 6) {
      iVar2 = (**(code **)(*in_EDX + 8))(&local_30,8);
      if (iVar2 == 8) {
        iVar2 = (**(code **)(*in_EDX + 8))(&local_1c,0x10);
        if (iVar2 == 0x10) {
          uVar4 = local_2c >> 0x18 | (local_2c & 0xff0000) >> 8 | (local_2c & 0xff00) << 8 |
                  local_2c << 0x18;
          uVar1 = (ushort)(local_20 >> 8);
          *param_1 = uVar1 & 0xff | (ushort)((local_20 << 0x18) >> 0x10);
          uVar3 = local_30 >> 0x18 | (local_30 & 0xff0000) >> 8 | (local_30 & 0xff00) << 8 |
                  local_30 << 0x18;
          param_1[1] = (ushort)(byte)(local_20 >> 0x18) | uVar1 & 0xff00;
          *(uint *)(param_1 + 2) =
               (((uint)local_28 & 0xff0000) >> 8 | ((uint)local_28 & 0xff00) << 8 |
               (uint)local_28 << 0x18) >> 8;
          *(uint *)(param_1 + 6) = uVar3 >> 0xc;
          *(uint *)(param_1 + 4) =
               ((local_28._4_4_ & 0xff00) << 8 | local_28._4_4_ << 0x18) >> 0x10 |
               ((uint)local_28 >> 0x18) << 0x10;
          *(uint *)(param_1 + 0xc) = uVar4;
          *(byte *)(param_1 + 8) = ((byte)(uVar3 >> 9) & 7) + 1;
          *(byte *)((int)param_1 + 0x11) = ((byte)(uVar3 >> 4) & 0x1f) + 1;
          *(uint *)(param_1 + 0xe) = local_30 >> 0x18 & 0xf;
          *(undefined4 *)(param_1 + 0x10) = local_1c;
          *(undefined4 *)(param_1 + 0x12) = uStack_18;
          *(undefined4 *)(param_1 + 0x14) = uStack_14;
          *(undefined4 *)(param_1 + 0x16) = uStack_10;
          local_20 = uVar4;
          __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

