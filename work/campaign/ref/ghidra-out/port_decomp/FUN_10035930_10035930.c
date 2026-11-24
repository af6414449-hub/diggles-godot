
void FUN_10035930(undefined4 *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  code *in_ECX;
  undefined4 in_EDX;
  undefined1 local_20;
  undefined1 local_1f;
  undefined4 local_1e;
  undefined4 local_1a;
  undefined4 local_16;
  undefined4 local_12;
  undefined4 local_e;
  undefined1 local_a;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170ce2);
  iVar1 = (*in_ECX)(in_EDX,&local_20,0x17);
  if (iVar1 == 0x17) {
    *param_2 = *param_2 + 0x17;
    *(undefined1 *)(param_1 + 1) = local_20;
    *(undefined1 *)((int)param_1 + 5) = local_1f;
    param_1[2] = local_1e;
    param_1[4] = local_16;
    param_1[5] = local_12;
    param_1[6] = local_e;
    *(undefined1 *)(param_1 + 7) = local_a;
    *param_1 = 0x5367674f;
    param_1[3] = local_1a;
    local_e = 0;
    uVar2 = (*in_ECX)(in_EDX,(int)param_1 + 0x1d,local_a);
    if (uVar2 == *(byte *)(param_1 + 7)) {
      *param_2 = *param_2 + (uint)*(byte *)(param_1 + 7);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

