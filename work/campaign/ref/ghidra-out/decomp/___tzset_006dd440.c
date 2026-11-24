
/* Library Function - Single Match
    ___tzset
   
   Library: Visual Studio 2019 Release */

void ___tzset(void)

{
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763400,8);
  if (DAT_00769c14 == 0) {
    ___acrt_lock(6);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (DAT_00769c14 == 0) {
      tzset_nolock();
      LOCK();
      DAT_00769c14 = DAT_00769c14 + 1;
      UNLOCK();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
    FUN_006dd494();
  }
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

