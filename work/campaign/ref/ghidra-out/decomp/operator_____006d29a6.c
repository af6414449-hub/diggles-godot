
/* Library Function - Multiple Matches With Same Base Name
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_3cfd252a7c5e244e8f20fc56fe35ebe9>,class <lambda_d7427dbf72509eba5fa970998bac2a27> &,class
   <lambda_8f55a0afecd2292d47fde3ce68e72492> >(class <lambda_3cfd252a7c5e244e8f20fc56fe35ebe9>
   &&,class <lambda_d7427dbf72509eba5fa970998bac2a27> &,class
   <lambda_8f55a0afecd2292d47fde3ce68e72492> &&)
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_5d912c5eb12d68f7685796d855ab8da6>,class <lambda_81587a929b95143618da2bd798ca9df2> &,class
   <lambda_bfd63e08e93a545639db6d324cf10d1a> >(class <lambda_5d912c5eb12d68f7685796d855ab8da6>
   &&,class <lambda_81587a929b95143618da2bd798ca9df2> &,class
   <lambda_bfd63e08e93a545639db6d324cf10d1a> &&)
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_9b2bd5c6bb91c5c032542faa5c3cb611>,class <lambda_be68057ced330f874c40fe9612235e36> &,class
   <lambda_dbd837d1c0b7fc6e2d81c287c81c071b> >(class <lambda_9b2bd5c6bb91c5c032542faa5c3cb611>
   &&,class <lambda_be68057ced330f874c40fe9612235e36> &,class
   <lambda_dbd837d1c0b7fc6e2d81c287c81c071b> &&)
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_c29ee0499b841886b80d843682cc403a>,class <lambda_0be4ab1c2a6918fda4e39227d83ea893> &,class
   <lambda_5a3ed3da325c8ea037a470278c0f2d16> >(class <lambda_c29ee0499b841886b80d843682cc403a>
   &&,class <lambda_0be4ab1c2a6918fda4e39227d83ea893> &,class
   <lambda_5a3ed3da325c8ea037a470278c0f2d16> &&)
   
   Library: Visual Studio 2019 Release */

int operator()<>(void)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007632a0,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  __lock_file((FILE *)**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = <lambda_0be4ab1c2a6918fda4e39227d83ea893>::operator()
                    (*(<lambda_0be4ab1c2a6918fda4e39227d83ea893> **)(unaff_EBP + 0xc));
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006d29f5();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar1;
}

