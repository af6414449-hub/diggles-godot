
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_4fdada1b837b2abbf20876fac97688ad>,class <lambda_b57350f2640456a0859d250846f69caf> &,class
   <lambda_eed5e4f92b5b7d55fa22c48c484aaa54> >(class <lambda_4fdada1b837b2abbf20876fac97688ad>
   &&,class <lambda_b57350f2640456a0859d250846f69caf> &,class
   <lambda_eed5e4f92b5b7d55fa22c48c484aaa54> &&)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_4fdada1b837b2abbf20876fac97688ad>,class_<lambda_b57350f2640456a0859d250846f69caf>&,class_<lambda_eed5e4f92b5b7d55fa22c48c484aaa54>_>
          (__crt_seh_guarded_call<void> *this,<lambda_4fdada1b837b2abbf20876fac97688ad> *param_1,
          <lambda_b57350f2640456a0859d250846f69caf> *param_2,
          <lambda_eed5e4f92b5b7d55fa22c48c484aaa54> *param_3)

{
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763628,8);
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  <lambda_b57350f2640456a0859d250846f69caf>::operator()
            (*(<lambda_b57350f2640456a0859d250846f69caf> **)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e1a3d();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

