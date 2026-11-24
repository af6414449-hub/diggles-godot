
/* Library Function - Single Match
    public: unsigned int __thiscall __crt_seh_guarded_call<unsigned int>::operator()<class
   <lambda_4ac01c32aa5b53846f05d0620572872e>,class <lambda_5856287d7ecd2be6c9197bb4007c3f6e> &,class
   <lambda_e7a9868ed898c75c0f0637692d94351a> >(class <lambda_4ac01c32aa5b53846f05d0620572872e>
   &&,class <lambda_5856287d7ecd2be6c9197bb4007c3f6e> &,class
   <lambda_e7a9868ed898c75c0f0637692d94351a> &&)
   
   Library: Visual Studio 2019 Release */

uint __thiscall
__crt_seh_guarded_call<unsigned_int>::
operator()<class_<lambda_4ac01c32aa5b53846f05d0620572872e>,class_<lambda_5856287d7ecd2be6c9197bb4007c3f6e>&,class_<lambda_e7a9868ed898c75c0f0637692d94351a>_>
          (__crt_seh_guarded_call<unsigned_int> *this,
          <lambda_4ac01c32aa5b53846f05d0620572872e> *param_1,
          <lambda_5856287d7ecd2be6c9197bb4007c3f6e> *param_2,
          <lambda_e7a9868ed898c75c0f0637692d94351a> *param_3)

{
  uint uVar1;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007632e0,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  __lock_file((FILE *)**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar1 = <lambda_5856287d7ecd2be6c9197bb4007c3f6e>::operator()
                    (*(<lambda_5856287d7ecd2be6c9197bb4007c3f6e> **)(unaff_EBP + 0xc));
  *(uint *)(unaff_EBP + -0x1c) = uVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006d49ac();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return uVar1;
}

