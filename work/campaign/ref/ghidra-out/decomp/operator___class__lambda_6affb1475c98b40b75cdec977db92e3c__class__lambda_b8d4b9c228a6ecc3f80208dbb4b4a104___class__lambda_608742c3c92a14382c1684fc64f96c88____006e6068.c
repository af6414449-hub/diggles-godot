
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_6affb1475c98b40b75cdec977db92e3c>,class <lambda_b8d4b9c228a6ecc3f80208dbb4b4a104> &,class
   <lambda_608742c3c92a14382c1684fc64f96c88> >(class <lambda_6affb1475c98b40b75cdec977db92e3c>
   &&,class <lambda_b8d4b9c228a6ecc3f80208dbb4b4a104> &,class
   <lambda_608742c3c92a14382c1684fc64f96c88> &&)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_6affb1475c98b40b75cdec977db92e3c>,class_<lambda_b8d4b9c228a6ecc3f80208dbb4b4a104>&,class_<lambda_608742c3c92a14382c1684fc64f96c88>_>
          (__crt_seh_guarded_call<void> *this,<lambda_6affb1475c98b40b75cdec977db92e3c> *param_1,
          <lambda_b8d4b9c228a6ecc3f80208dbb4b4a104> *param_2,
          <lambda_608742c3c92a14382c1684fc64f96c88> *param_3)

{
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763748,8);
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  replace_current_thread_locale_nolock
            (*(__acrt_ptd **)**(undefined4 **)(unaff_EBP + 0xc),(__crt_locale_data *)0x0);
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e60b1();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

