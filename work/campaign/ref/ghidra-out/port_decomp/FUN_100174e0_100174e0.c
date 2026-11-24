
void FUN_100174e0(code *param_1,undefined4 param_2)

{
  int iVar1;
  undefined **ppuVar2;
  undefined1 local_2c [32];
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)local_2c;
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  ppuVar2 = &PTR_FUN_10043890;
  do {
    (*(code *)*ppuVar2)(local_2c);
    iVar1 = (*param_1)(local_2c,param_2);
    if (iVar1 != 1) break;
    ppuVar2 = ppuVar2 + 1;
  } while ((int)ppuVar2 < 0x100438ac);
  __security_check_cookie(local_c ^ (uint)local_2c);
  return;
}

