
/* Library Function - Single Match
    ___scrt_is_nonwritable_in_current_image
   
   Library: Visual Studio 2019 Release */

undefined4 ___scrt_is_nonwritable_in_current_image(void)

{
  _IMAGE_SECTION_HEADER *p_Var1;
  undefined4 uVar2;
  int unaff_EBP;
  
  FUN_10040d70(&DAT_1004a0d8,8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  p_Var1 = find_pe_section((uchar *)&IMAGE_DOS_HEADER_10000000,*(int *)(unaff_EBP + 8) + 0xf0000000)
  ;
  if ((p_Var1 == (_IMAGE_SECTION_HEADER *)0x0) || (*(int *)(p_Var1 + 0x24) < 0)) {
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    uVar2 = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return uVar2;
}

