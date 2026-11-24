
void FUN_100028e0(int param_1)

{
  undefined4 *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b78);
  *in_ECX = std::exception::vftable;
  *(undefined8 *)(in_ECX + 1) = 0;
  __std_exception_copy(param_1 + 4,in_ECX + 1);
  return;
}

