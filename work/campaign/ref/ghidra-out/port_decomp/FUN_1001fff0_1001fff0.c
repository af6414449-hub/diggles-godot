
void FUN_1001fff0(uint param_1,undefined4 param_2)

{
  int in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170d01);
  if (param_1 < 8) {
    *(undefined4 *)(in_ECX + 0x30 + param_1 * 4) = param_2;
  }
  return;
}

