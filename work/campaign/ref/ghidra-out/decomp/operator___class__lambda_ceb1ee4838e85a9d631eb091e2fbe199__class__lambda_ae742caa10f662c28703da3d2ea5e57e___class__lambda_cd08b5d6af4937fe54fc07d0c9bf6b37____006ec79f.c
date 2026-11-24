
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_ceb1ee4838e85a9d631eb091e2fbe199>,class <lambda_ae742caa10f662c28703da3d2ea5e57e> &,class
   <lambda_cd08b5d6af4937fe54fc07d0c9bf6b37> >(class <lambda_ceb1ee4838e85a9d631eb091e2fbe199>
   &&,class <lambda_ae742caa10f662c28703da3d2ea5e57e> &,class
   <lambda_cd08b5d6af4937fe54fc07d0c9bf6b37> &&)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_ceb1ee4838e85a9d631eb091e2fbe199>,class_<lambda_ae742caa10f662c28703da3d2ea5e57e>&,class_<lambda_cd08b5d6af4937fe54fc07d0c9bf6b37>_>
          (__crt_seh_guarded_call<void> *this,<lambda_ceb1ee4838e85a9d631eb091e2fbe199> *param_1,
          <lambda_ae742caa10f662c28703da3d2ea5e57e> *param_2,
          <lambda_cd08b5d6af4937fe54fc07d0c9bf6b37> *param_3)

{
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007638c8,8);
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  <lambda_ae742caa10f662c28703da3d2ea5e57e>::operator()
            (*(<lambda_ae742caa10f662c28703da3d2ea5e57e> **)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006ec7e0();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

