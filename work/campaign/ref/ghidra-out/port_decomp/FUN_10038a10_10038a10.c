
uint FUN_10038a10(ushort *param_1,ushort *param_2)

{
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if (*param_1 < *param_2) {
    return 0xffffffff;
  }
  return (uint)(*param_2 < *param_1);
}

