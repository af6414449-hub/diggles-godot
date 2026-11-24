
void __cdecl Unwind_006cfe9d(void)

{
  code *pcVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007635a8,8);
  iVar2 = ___acrt_getptd();
  pcVar1 = *(code **)(iVar2 + 0xc);
  if (pcVar1 != (code *)0x0) {
    *(undefined4 *)(unaff_EBP + -4) = 0;
    guard_check_icall();
    (*pcVar1)();
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}

