
uint FUN_10041270(void)

{
  undefined1 auVar1 [16];
  uint uVar2;
  bool bVar3;
  float in_XMM0_Da;
  undefined1 in_register_00001204 [12];
  
  if (5 < DAT_10050c08) {
    auVar1._4_12_ = in_register_00001204;
    auVar1._0_4_ = in_XMM0_Da;
    uVar2 = vcvttss2usi_avx512f(auVar1);
    return uVar2;
  }
  uVar2 = (int)in_XMM0_Da * 2;
  if ((int)in_XMM0_Da < 0) {
    bVar3 = uVar2 < 0x7f000000;
    if (!bVar3) goto LAB_100412aa;
  }
  else if (0x9dffffff < uVar2) {
    bVar3 = uVar2 < 0x9f000000;
    if (bVar3) {
      return (int)in_XMM0_Da << 8 | 0x80000000;
    }
LAB_100412aa:
    return -(uint)!bVar3;
  }
  return (int)in_XMM0_Da;
}

