
uint FUN_10041395(void)

{
  undefined1 auVar1 [16];
  uint uVar2;
  double in_XMM0_Qa;
  undefined8 in_XMM0_Qb;
  uint local_8;
  uint uStack_4;
  
  if (5 < DAT_10050c08) {
    auVar1._8_8_ = in_XMM0_Qb;
    auVar1._0_8_ = in_XMM0_Qa;
    uVar2 = vcvttsd2usi_avx512f(auVar1);
    return uVar2;
  }
  local_8 = SUB84(in_XMM0_Qa,0);
  uStack_4 = (uint)((ulonglong)in_XMM0_Qa >> 0x20);
  uStack_4 = uStack_4 & 0x7fffffff;
  if ((longlong)in_XMM0_Qa < 0) {
    if (uStack_4 < 0x3ff00000) {
      return 0;
    }
  }
  else {
    if (uStack_4 < 0x41e00000) {
      return (int)in_XMM0_Qa;
    }
    if (uStack_4 < 0x41f00000) {
      return local_8 >> 0x15 | uStack_4 << 0xb | 0x80000000;
    }
  }
  return 0xffffffff;
}

