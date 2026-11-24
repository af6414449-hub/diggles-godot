
/* Library Function - Single Match
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_65fd67b065f6eb2f69d2b40e70f741d1>,class <lambda_0bd0bd1e46f8138169959d81163ebf0c> &,class
   <lambda_3dd5c5b82bb549ede7d0dd5b9a094995> >(class <lambda_65fd67b065f6eb2f69d2b40e70f741d1>
   &&,class <lambda_0bd0bd1e46f8138169959d81163ebf0c> &,class
   <lambda_3dd5c5b82bb549ede7d0dd5b9a094995> &&)
   
   Library: Visual Studio 2019 Release */

int __thiscall
__crt_seh_guarded_call<int>::
operator()<class_<lambda_65fd67b065f6eb2f69d2b40e70f741d1>,class_<lambda_0bd0bd1e46f8138169959d81163ebf0c>&,class_<lambda_3dd5c5b82bb549ede7d0dd5b9a094995>_>
          (__crt_seh_guarded_call<int> *this,<lambda_65fd67b065f6eb2f69d2b40e70f741d1> *param_1,
          <lambda_0bd0bd1e46f8138169959d81163ebf0c> *param_2,
          <lambda_3dd5c5b82bb549ede7d0dd5b9a094995> *param_3)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007633a0,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  __lock_file((FILE *)**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = <lambda_0bd0bd1e46f8138169959d81163ebf0c>::operator()
                    (*(<lambda_0bd0bd1e46f8138169959d81163ebf0c> **)(unaff_EBP + 0xc));
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006dc221();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar1;
}

