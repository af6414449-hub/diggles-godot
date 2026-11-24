
void FUN_100029d0(void)

{
  undefined4 *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b78);
  *(undefined8 *)(in_ECX + 1) = 0;
  in_ECX[1] = "bad array new length";
  *in_ECX = std::bad_array_new_length::vftable;
  return;
}

