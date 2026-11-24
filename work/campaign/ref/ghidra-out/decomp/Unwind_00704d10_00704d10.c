
void Unwind_00704d10(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x438) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x438) = *(uint *)(unaff_EBP + -0x438) & 0xfffffffe;
    FUN_006b8ed0();
    return;
  }
  return;
}

