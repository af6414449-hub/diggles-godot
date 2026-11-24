
void Unwind_006fcd88(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x94) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x94) = *(uint *)(unaff_EBP + -0x94) & 0xfffffffe;
    FUN_006b8ed0();
    return;
  }
  return;
}

