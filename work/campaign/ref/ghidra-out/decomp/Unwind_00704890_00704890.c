
void Unwind_00704890(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x38) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x38) = *(uint *)(unaff_EBP + -0x38) & 0xfffffffe;
    FUN_006b8ed0();
    return;
  }
  return;
}

