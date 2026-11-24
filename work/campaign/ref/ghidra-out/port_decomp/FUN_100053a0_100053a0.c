
void FUN_100053a0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  *(undefined8 *)(in_ECX + 1) = 0;
  in_ECX[3] = param_1;
  *in_ECX = DX::com_exception::vftable;
  return;
}

