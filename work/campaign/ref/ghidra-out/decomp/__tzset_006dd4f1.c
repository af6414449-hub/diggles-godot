
/* Library Function - Single Match
    __tzset
   
   Library: Visual Studio 2019 Release */

void __cdecl __tzset(void)

{
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007633c0,8);
  ___acrt_lock(6);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  tzset_nolock();
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006dd52a();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

