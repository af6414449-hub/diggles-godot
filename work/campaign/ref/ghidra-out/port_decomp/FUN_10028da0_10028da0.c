
undefined4 FUN_10028da0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170ce3);
  if (in_ECX != (undefined4 *)0x0) {
    in_ECX[1] = 0;
    memset(in_ECX + 8,0,0x158);
    *in_ECX = FUN_1001ec50;
    in_ECX[2] = FUN_1001ec70;
    in_ECX[4] = 0;
    in_ECX[5] = FUN_10028720;
    in_ECX[6] = FUN_10028740;
    in_ECX[7] = FUN_10028760;
    in_ECX[3] = param_2;
    if ((in_ECX[7] != 0) && ((in_ECX[5] != 0 || (in_ECX[6] != 0)))) {
      return 1;
    }
  }
  return 0;
}

