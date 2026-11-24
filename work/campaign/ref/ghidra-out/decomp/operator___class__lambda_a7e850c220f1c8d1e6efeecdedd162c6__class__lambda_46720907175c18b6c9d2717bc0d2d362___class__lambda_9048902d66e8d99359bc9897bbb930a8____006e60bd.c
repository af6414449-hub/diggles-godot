
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_a7e850c220f1c8d1e6efeecdedd162c6>,class <lambda_46720907175c18b6c9d2717bc0d2d362> &,class
   <lambda_9048902d66e8d99359bc9897bbb930a8> >(class <lambda_a7e850c220f1c8d1e6efeecdedd162c6>
   &&,class <lambda_46720907175c18b6c9d2717bc0d2d362> &,class
   <lambda_9048902d66e8d99359bc9897bbb930a8> &&)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_a7e850c220f1c8d1e6efeecdedd162c6>,class_<lambda_46720907175c18b6c9d2717bc0d2d362>&,class_<lambda_9048902d66e8d99359bc9897bbb930a8>_>
          (__crt_seh_guarded_call<void> *this,<lambda_a7e850c220f1c8d1e6efeecdedd162c6> *param_1,
          <lambda_46720907175c18b6c9d2717bc0d2d362> *param_2,
          <lambda_9048902d66e8d99359bc9897bbb930a8> *param_3)

{
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763708,8);
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  replace_current_thread_locale_nolock
            (*(__acrt_ptd **)**(undefined4 **)(unaff_EBP + 0xc),
             (__crt_locale_data *)**(undefined4 **)(*(undefined4 **)(unaff_EBP + 0xc))[1]);
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e610b();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

