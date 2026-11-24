
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_6b4b7855443974f2b4b77000ea21c99c>,class <lambda_8f7d3b162ab39427f4fa9995c67a7986> &,class
   <lambda_cc9a5ba8a5d8428b9634eab82665e5dc> >(class <lambda_6b4b7855443974f2b4b77000ea21c99c>
   &&,class <lambda_8f7d3b162ab39427f4fa9995c67a7986> &,class
   <lambda_cc9a5ba8a5d8428b9634eab82665e5dc> &&)
   
   Library: Visual Studio 2019 Release */

int __thiscall
__crt_seh_guarded_call<int>::
operator()<class_<lambda_6b4b7855443974f2b4b77000ea21c99c>,class_<lambda_8f7d3b162ab39427f4fa9995c67a7986>&,class_<lambda_cc9a5ba8a5d8428b9634eab82665e5dc>_>
          (__crt_seh_guarded_call<int> *this,<lambda_6b4b7855443974f2b4b77000ea21c99c> *param_1,
          <lambda_8f7d3b162ab39427f4fa9995c67a7986> *param_2,
          <lambda_cc9a5ba8a5d8428b9634eab82665e5dc> *param_3)

{
  BOOL BVar1;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007637a8,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  _DAT_0076a060 = __crt_fast_encode_pointer<>(*(undefined4 *)**(undefined4 **)(unaff_EBP + 0xc));
  BVar1 = EnumSystemLocalesW(<lambda_29d3c280b90b41c2ae070ffca879996a>::<lambda_invoker_stdcall>,1);
  _DAT_0076a060 = DAT_0076700c;
  *(BOOL *)(unaff_EBP + -0x1c) = BVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e7caa();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return BVar1;
}

