
/* Library Function - Single Match
    ___set_fpsr_sse2
   
   Library: Visual Studio 2019 Release */

void ___set_fpsr_sse2(void)

{
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763788,8);
  if (0 < DAT_00769a88) {
    if (((*(uint *)(unaff_EBP + 8) & 0x40) == 0) || (DAT_00767318 == 0)) {
      *(uint *)(unaff_EBP + 8) = *(uint *)(unaff_EBP + 8) & 0xffffffbf;
      MXCSR = *(undefined4 *)(unaff_EBP + 8);
    }
    else {
      *(undefined4 *)(unaff_EBP + -4) = 0;
      MXCSR = *(undefined4 *)(unaff_EBP + 8);
      *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

