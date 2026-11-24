
void Unwind_00705b0c(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x430) & 2) != 0) {
    *(uint *)(unaff_EBP + -0x430) = *(uint *)(unaff_EBP + -0x430) & 0xfffffffd;
    FUN_006b8ed0();
    return;
  }
  return;
}

