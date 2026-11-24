
void FUN_10041560(void)

{
  undefined1 auVar1 [16];
  uint in_ECX;
  undefined4 in_EDX;
  
  if (5 < DAT_10050c08) {
    auVar1 = vpinsrd_avx(ZEXT416(in_ECX),in_EDX,1);
    vcvtuqq2pd_avx512vl(auVar1);
    return;
  }
  return;
}

