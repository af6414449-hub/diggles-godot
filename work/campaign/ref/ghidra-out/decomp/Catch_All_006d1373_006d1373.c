
void Catch_All_006d1373(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = ___vcrt_getptd();
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(unaff_EBP + 8);
  __CxxThrowException_8(0,0);
                    /* WARNING: Subroutine does not return */
  _abort();
}

