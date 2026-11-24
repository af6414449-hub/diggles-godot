
void FUN_10005210(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b62);
  *in_ECX = param_2;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  switch(param_1) {
  case 1:
  case 3:
    break;
  case 2:
  case 4:
    in_ECX[4] = 0;
    in_ECX[5] = 0xffffffff;
    in_ECX[3] = 0;
    return;
  default:
    return;
  case 6:
    in_ECX[4] = 0xffffffff;
  }
  in_ECX[3] = 0;
  return;
}

