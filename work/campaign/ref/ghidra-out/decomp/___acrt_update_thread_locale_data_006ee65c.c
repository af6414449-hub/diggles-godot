
/* Library Function - Single Match
    ___acrt_update_thread_locale_data
   
   Library: Visual Studio 2019 Release */

int ___acrt_update_thread_locale_data(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763908,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  iVar2 = ___acrt_getptd();
  if (((*(uint *)(iVar2 + 0x350) & DAT_007673b0) != 0) &&
     (iVar1 = *(int *)(iVar2 + 0x4c), iVar1 != 0)) {
    ExceptionList = *(void **)(unaff_EBP + -0x10);
    return iVar1;
  }
  ___acrt_lock(4);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar2 = __updatetlocinfoEx_nolock((int *)(iVar2 + 0x4c),DAT_00769d78);
  *(int *)(unaff_EBP + -0x1c) = iVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006ee6bc();
  if (iVar2 != 0) {
    iVar2 = FUN_006ee6c5();
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}

