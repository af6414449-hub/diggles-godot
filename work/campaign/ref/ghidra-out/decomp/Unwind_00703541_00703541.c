
void Unwind_00703541(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x45c) & 4) != 0) {
    *(uint *)(unaff_EBP + -0x45c) = *(uint *)(unaff_EBP + -0x45c) & 0xfffffffb;
    FUN_006b8ed0();
    return;
  }
  return;
}

