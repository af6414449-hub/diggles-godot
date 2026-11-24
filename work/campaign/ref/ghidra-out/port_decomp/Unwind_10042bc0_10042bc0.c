
void Unwind_10042bc0(void)

{
  longlong lVar1;
  uint uVar2;
  int unaff_EBP;
  
  lVar1 = (ulonglong)*(uint *)(unaff_EBP + 8) * 0xc;
  uVar2 = -(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1;
  FUN_100402e2(*(undefined4 *)(unaff_EBP + 0xc),-(uint)(0xfffffffb < uVar2) | uVar2 + 4);
  return;
}

