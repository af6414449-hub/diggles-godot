
void Unwind_00704c57(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x434) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x434) = *(uint *)(unaff_EBP + -0x434) & 0xfffffffe;
    FUN_006b8ed0();
    return;
  }
  return;
}

