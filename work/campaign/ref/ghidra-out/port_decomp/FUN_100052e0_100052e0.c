
void FUN_100052e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  undefined4 local_14;
  undefined1 local_10;
  uint local_c;
  
  local_c = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170b78);
  *in_ECX = std::exception::vftable;
  local_14 = param_1;
  local_10 = 1;
  *(undefined8 *)(in_ECX + 1) = 0;
  __std_exception_copy(&local_14,in_ECX + 1);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

