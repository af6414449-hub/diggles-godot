
void Unwind_006fce90(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x74) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x74) = *(uint *)(unaff_EBP + -0x74) & 0xfffffffe;
    FUN_006b8ed0();
    return;
  }
  return;
}

