
void FUN_10005340(void)

{
  undefined4 *in_ECX;
  char *local_10;
  undefined1 local_c;
  uint local_8;
  
  local_8 = DAT_1005000c ^ (uint)&stack0xfffffffc;
  __CheckForDebuggerJustMyCode(&DAT_14170b84);
  *in_ECX = std::exception::vftable;
  local_10 = "minFeatureLevel too high";
  local_c = 1;
  *(undefined8 *)(in_ECX + 1) = 0;
  __std_exception_copy(&local_10,in_ECX + 1);
  *in_ECX = std::out_of_range::vftable;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

