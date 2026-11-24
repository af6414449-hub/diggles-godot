
int FUN_10038070(void)

{
  uint in_ECX;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cec);
  if ((int)in_ECX < 0) {
    return 0;
  }
  if (0x3fff < (int)in_ECX) {
    if (0xffffff < (int)in_ECX) {
      if ((int)in_ECX < 0x20000000) {
        return (char)(&DAT_10043f80)[in_ECX >> 0x19] + 0x19;
      }
      return (char)(&DAT_10043f80)[in_ECX >> 0x1e] + 0x1e;
    }
    if ((int)in_ECX < 0x80000) {
      return (char)(&DAT_10043f80)[in_ECX >> 0xf] + 0xf;
    }
    return (char)(&DAT_10043f80)[in_ECX >> 0x14] + 0x14;
  }
  if ((int)in_ECX < 0x10) {
    return (int)(char)(&DAT_10043f80)[in_ECX];
  }
  if ((int)in_ECX < 0x200) {
    return (char)(&DAT_10043f80)[in_ECX >> 5] + 5;
  }
  return (char)(&DAT_10043f80)[in_ECX >> 10] + 10;
}

