
void Unwind_006fbd80(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x418) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x418) = *(uint *)(unaff_EBP + -0x418) & 0xfffffffe;
    FUN_006b8ed0();
    return;
  }
  return;
}

