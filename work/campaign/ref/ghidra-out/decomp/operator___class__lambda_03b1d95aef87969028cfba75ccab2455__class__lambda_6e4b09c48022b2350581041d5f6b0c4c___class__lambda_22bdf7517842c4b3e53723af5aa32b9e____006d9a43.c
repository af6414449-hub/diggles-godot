
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_03b1d95aef87969028cfba75ccab2455>,class <lambda_6e4b09c48022b2350581041d5f6b0c4c> &,class
   <lambda_22bdf7517842c4b3e53723af5aa32b9e> >(class <lambda_03b1d95aef87969028cfba75ccab2455>
   &&,class <lambda_6e4b09c48022b2350581041d5f6b0c4c> &,class
   <lambda_22bdf7517842c4b3e53723af5aa32b9e> &&)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_03b1d95aef87969028cfba75ccab2455>,class_<lambda_6e4b09c48022b2350581041d5f6b0c4c>&,class_<lambda_22bdf7517842c4b3e53723af5aa32b9e>_>
          (__crt_seh_guarded_call<void> *this,<lambda_03b1d95aef87969028cfba75ccab2455> *param_1,
          <lambda_6e4b09c48022b2350581041d5f6b0c4c> *param_2,
          <lambda_22bdf7517842c4b3e53723af5aa32b9e> *param_3)

{
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763340,8);
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  <lambda_6e4b09c48022b2350581041d5f6b0c4c>::operator()
            (*(<lambda_6e4b09c48022b2350581041d5f6b0c4c> **)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006d9a84();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

