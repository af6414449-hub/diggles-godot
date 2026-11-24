
void FUN_1000dbc0(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int *in_EDX;
  uint uVar2;
  int *local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  local_10 = (int *)0x0;
  local_c = 0;
  iVar1 = MFCreateTopology(&local_10);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*in_EDX + 0x84))(), -1 < iVar1)) {
    uVar2 = 0;
    if (local_c != 0) {
      do {
        iVar1 = FUN_1000d900();
        if (iVar1 < 0) goto LAB_1000dc54;
        uVar2 = uVar2 + 1;
      } while (uVar2 < local_c);
    }
    *param_2 = local_10;
    (**(code **)(*local_10 + 4))(local_10);
  }
LAB_1000dc54:
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

