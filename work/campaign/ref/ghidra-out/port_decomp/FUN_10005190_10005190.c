
void FUN_10005190(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170b62);
  *in_ECX = param_2;
  in_ECX[1] = param_1;
  switch(param_1) {
  case 3:
  case 5:
  case 8:
    in_ECX[4] = 0xffffffff;
  case 1:
    in_ECX[3] = 0;
  case 2:
  case 4:
    in_ECX[2] = 0;
    return;
  default:
    return;
  case 7:
    in_ECX[3] = 0xffffffff;
    in_ECX[2] = 0;
    return;
  }
}

