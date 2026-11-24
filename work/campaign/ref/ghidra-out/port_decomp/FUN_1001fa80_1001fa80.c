
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_1001fa80(int *param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 extraout_ECX;
  undefined8 local_52e0;
  undefined1 local_52d8 [6688];
  uint local_38b8;
  int local_38b4;
  undefined4 local_38a4;
  code *local_3898;
  int local_28;
  uint local_c;
  undefined4 uStack_8;
  
  uStack_8 = 0x1001fa8d;
  local_c = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  (**(code **)(*param_1 + 0x10))(0);
  memset(local_52d8,0,0x52c8);
  iVar1 = FUN_10027e00(extraout_ECX,param_1);
  if (iVar1 == 0) {
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  if (8 < local_38b8) {
    local_38b8 = 8;
  }
  *(uint *)(in_ECX + 0x14) = local_38b8;
  iVar1 = FUN_10028570(&local_52e0);
  if (iVar1 == 0) {
    local_52e0 = 0;
  }
  *(undefined4 *)(in_ECX + 0x78) = (undefined4)local_52e0;
  *(undefined4 *)(in_ECX + 0x68) = 3;
  *(float *)(in_ECX + 0xc) =
       (float)((double)local_38b4 + *(double *)(&DAT_10047c80 + (local_38b4 >> 0x1f) * -8));
  if ((local_28 != 0) && (local_3898 != (code *)0x0)) {
    (*local_3898)(local_28,local_38a4);
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

