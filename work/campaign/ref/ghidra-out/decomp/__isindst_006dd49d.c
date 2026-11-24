
/* Library Function - Single Match
    __isindst
   
   Library: Visual Studio 2019 Release */

int __cdecl __isindst(tm *_Time)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007633e0,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  ___acrt_lock(6);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = _isindst_nolock(*(tm **)(unaff_EBP + 8));
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006dd4e8();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar1;
}

