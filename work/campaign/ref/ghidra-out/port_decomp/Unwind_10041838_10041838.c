
void Unwind_10041838(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x1c8) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x1c8) = *(uint *)(unaff_EBP + -0x1c8) & 0xfffffffe;
    FUN_10007af0();
    return;
  }
  return;
}

