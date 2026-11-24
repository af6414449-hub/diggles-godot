
/* Library Function - Single Match
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_8e746cf0007f6ed984d6f78af1fec997>,class <lambda_22ebabd17bc4fa466a2aca6d8deb888d> &,class
   <lambda_18ed0c0b38a6dc0daf1e7ac6d6adf05e> >(class <lambda_8e746cf0007f6ed984d6f78af1fec997>
   &&,class <lambda_22ebabd17bc4fa466a2aca6d8deb888d> &,class
   <lambda_18ed0c0b38a6dc0daf1e7ac6d6adf05e> &&)
   
   Library: Visual Studio 2019 Release */

int __thiscall
__crt_seh_guarded_call<int>::
operator()<class_<lambda_8e746cf0007f6ed984d6f78af1fec997>,class_<lambda_22ebabd17bc4fa466a2aca6d8deb888d>&,class_<lambda_18ed0c0b38a6dc0daf1e7ac6d6adf05e>_>
          (__crt_seh_guarded_call<int> *this,<lambda_8e746cf0007f6ed984d6f78af1fec997> *param_1,
          <lambda_22ebabd17bc4fa466a2aca6d8deb888d> *param_2,
          <lambda_18ed0c0b38a6dc0daf1e7ac6d6adf05e> *param_3)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007635c8,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = <lambda_22ebabd17bc4fa466a2aca6d8deb888d>::operator()
                    (*(<lambda_22ebabd17bc4fa466a2aca6d8deb888d> **)(unaff_EBP + 0xc));
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e134a();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar1;
}

