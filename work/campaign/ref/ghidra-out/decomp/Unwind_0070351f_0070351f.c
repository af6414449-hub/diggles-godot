
void Unwind_0070351f(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x45c) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x45c) = *(uint *)(unaff_EBP + -0x45c) & 0xfffffffd;
    FUN_006b8ed0();
    return;
  }
  return;
}

