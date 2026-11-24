
void FUN_10005120(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b62);
  *in_ECX = param_2;
  in_ECX[1] = param_1;
  switch(param_1) {
  case 3:
  case 5:
  case 10:
    in_ECX[5] = 0xffffffff;
  case 0xb:
    in_ECX[4] = 0;
  case 1:
  case 2:
  case 4:
  case 7:
  case 8:
  case 9:
    in_ECX[2] = 0;
    in_ECX[3] = 0xffffffff;
    return;
  default:
    return;
  }
}

