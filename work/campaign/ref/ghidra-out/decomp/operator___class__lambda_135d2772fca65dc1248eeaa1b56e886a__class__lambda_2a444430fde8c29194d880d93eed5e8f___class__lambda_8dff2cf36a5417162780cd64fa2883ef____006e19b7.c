
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_135d2772fca65dc1248eeaa1b56e886a>,class <lambda_2a444430fde8c29194d880d93eed5e8f> &,class
   <lambda_8dff2cf36a5417162780cd64fa2883ef> &>(class <lambda_135d2772fca65dc1248eeaa1b56e886a>
   &&,class <lambda_2a444430fde8c29194d880d93eed5e8f> &,class
   <lambda_8dff2cf36a5417162780cd64fa2883ef> &)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_135d2772fca65dc1248eeaa1b56e886a>,class_<lambda_2a444430fde8c29194d880d93eed5e8f>&,class_<lambda_8dff2cf36a5417162780cd64fa2883ef>&>
          (__crt_seh_guarded_call<void> *this,<lambda_135d2772fca65dc1248eeaa1b56e886a> *param_1,
          <lambda_2a444430fde8c29194d880d93eed5e8f> *param_2,
          <lambda_8dff2cf36a5417162780cd64fa2883ef> *param_3)

{
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763648,8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  <lambda_2a444430fde8c29194d880d93eed5e8f>::operator()
            (*(<lambda_2a444430fde8c29194d880d93eed5e8f> **)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e19ed();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

