
void FUN_1003f970(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  int *piVar5;
  int local_604 [9];
  undefined4 local_5e0;
  undefined4 local_5dc;
  int local_5cc;
  int local_5a8;
  int local_5a0;
  int local_59c;
  undefined4 local_594;
  undefined4 local_6c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  iVar3 = *in_ECX;
  uVar2 = (**(code **)(iVar3 + 0xc))();
  (**(code **)(iVar3 + 0x10))(uVar2);
  iVar3 = (**(code **)(*in_ECX + 0x14))();
  (**(code **)(*in_ECX + 0x10))(iVar1);
  memset(local_604,0,0x5f4);
  local_6c = 0xffffffff;
  local_5e0 = (**(code **)(*in_ECX + 0x14))();
  local_5dc = 0;
  local_5cc = iVar3 - iVar1;
  iVar3 = FUN_1003cb20();
  if (iVar3 != 0) {
    local_604[2] = local_604[2] + 0x5f8;
    if (local_5a8 == 0) {
      piVar4 = (int *)malloc(0x5f8);
    }
    else {
      piVar4 = (int *)(local_5a0 + local_5a8);
      if (local_59c < local_5a0 + 0x5f8) goto LAB_1003fa82;
      local_5a0 = local_5a0 + 0x5f8;
    }
    if (piVar4 != (int *)0x0) {
      piVar5 = local_604;
      for (iVar3 = 0x17d; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar4 = *piVar5;
        piVar5 = piVar5 + 1;
        piVar4 = piVar4 + 1;
      }
      FUN_1003c930();
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
LAB_1003fa82:
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = local_594;
  }
  FUN_1003eea0();
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

