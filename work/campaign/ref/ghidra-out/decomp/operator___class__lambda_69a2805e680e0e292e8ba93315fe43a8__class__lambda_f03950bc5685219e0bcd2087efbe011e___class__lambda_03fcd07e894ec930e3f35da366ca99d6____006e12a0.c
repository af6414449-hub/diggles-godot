
/* Library Function - Single Match
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_69a2805e680e0e292e8ba93315fe43a8>,class <lambda_f03950bc5685219e0bcd2087efbe011e> &,class
   <lambda_03fcd07e894ec930e3f35da366ca99d6> >(class <lambda_69a2805e680e0e292e8ba93315fe43a8>
   &&,class <lambda_f03950bc5685219e0bcd2087efbe011e> &,class
   <lambda_03fcd07e894ec930e3f35da366ca99d6> &&)
   
   Library: Visual Studio 2019 Release */

int __thiscall
__crt_seh_guarded_call<int>::
operator()<class_<lambda_69a2805e680e0e292e8ba93315fe43a8>,class_<lambda_f03950bc5685219e0bcd2087efbe011e>&,class_<lambda_03fcd07e894ec930e3f35da366ca99d6>_>
          (__crt_seh_guarded_call<int> *this,<lambda_69a2805e680e0e292e8ba93315fe43a8> *param_1,
          <lambda_f03950bc5685219e0bcd2087efbe011e> *param_2,
          <lambda_03fcd07e894ec930e3f35da366ca99d6> *param_3)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007635e8,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = <lambda_f03950bc5685219e0bcd2087efbe011e>::operator()
                    (*(<lambda_f03950bc5685219e0bcd2087efbe011e> **)(unaff_EBP + 0xc));
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e12ef();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar1;
}

