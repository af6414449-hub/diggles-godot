
uint FUN_10021630(void)

{
  byte bVar1;
  uint uVar2;
  int in_ECX;
  uint in_EDX;
  int local_c;
  
  __CheckForDebuggerJustMyCode(&DAT_14170cf0);
  bVar1 = *(byte *)(in_ECX + 1);
  if ((bVar1 & 6) == 6) {
    local_c = 0x180;
  }
  else {
    local_c = 0x480;
    if ((bVar1 & 0xe) == 2) {
      local_c = 0x240;
    }
  }
  uVar2 = ((uint)(byte)(&DAT_10046de9)
                       [(uint)(*(byte *)(in_ECX + 2) >> 4) +
                        ((bVar1 >> 1 & 3) + (bVar1 >> 3 & 1) * 3) * 0xf] * local_c * 0xfa) /
          ((*(uint *)(&DAT_1004590c + (*(byte *)(in_ECX + 2) >> 2 & 3) * 4) >> (~(bVar1 >> 3) & 1))
          >> (~(bVar1 >> 4) & 1));
  if ((bVar1 & 6) == 6) {
    uVar2 = uVar2 & 0xfffffffc;
  }
  if (uVar2 != 0) {
    in_EDX = uVar2;
  }
  return in_EDX;
}

