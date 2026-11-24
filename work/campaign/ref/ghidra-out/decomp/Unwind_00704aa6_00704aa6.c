
void Unwind_00704aa6(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x440) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x440) = *(uint *)(unaff_EBP + -0x440) & 0xfffffffe;
    FUN_006b8ed0();
    return;
  }
  return;
}

