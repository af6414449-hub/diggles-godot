
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_15ade71b0218206bbe3333a0c9b79046>,class <lambda_da44e0f8b0f19ba52fefafb335991732> &,class
   <lambda_207f2d024fc103971653565357d6cd41> >(class <lambda_15ade71b0218206bbe3333a0c9b79046>
   &&,class <lambda_da44e0f8b0f19ba52fefafb335991732> &,class
   <lambda_207f2d024fc103971653565357d6cd41> &&)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_15ade71b0218206bbe3333a0c9b79046>,class_<lambda_da44e0f8b0f19ba52fefafb335991732>&,class_<lambda_207f2d024fc103971653565357d6cd41>_>
          (__crt_seh_guarded_call<void> *this,<lambda_15ade71b0218206bbe3333a0c9b79046> *param_1,
          <lambda_da44e0f8b0f19ba52fefafb335991732> *param_2,
          <lambda_207f2d024fc103971653565357d6cd41> *param_3)

{
  int *piVar1;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007636e8,8);
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piVar1 = *(int **)(*(int *)**(undefined4 **)(unaff_EBP + 0xc) + 0x48);
  LOCK();
  *piVar1 = *piVar1 + 1;
  UNLOCK();
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e5ff0();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

