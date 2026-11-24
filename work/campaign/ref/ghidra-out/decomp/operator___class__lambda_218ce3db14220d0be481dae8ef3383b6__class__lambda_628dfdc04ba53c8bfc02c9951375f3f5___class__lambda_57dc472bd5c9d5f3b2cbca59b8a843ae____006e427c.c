
/* Library Function - Single Match
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_218ce3db14220d0be481dae8ef3383b6>,class <lambda_628dfdc04ba53c8bfc02c9951375f3f5> &,class
   <lambda_57dc472bd5c9d5f3b2cbca59b8a843ae> >(class <lambda_218ce3db14220d0be481dae8ef3383b6>
   &&,class <lambda_628dfdc04ba53c8bfc02c9951375f3f5> &,class
   <lambda_57dc472bd5c9d5f3b2cbca59b8a843ae> &&)
   
   Library: Visual Studio 2019 Release */

int __thiscall
__crt_seh_guarded_call<int>::
operator()<class_<lambda_218ce3db14220d0be481dae8ef3383b6>,class_<lambda_628dfdc04ba53c8bfc02c9951375f3f5>&,class_<lambda_57dc472bd5c9d5f3b2cbca59b8a843ae>_>
          (__crt_seh_guarded_call<int> *this,<lambda_218ce3db14220d0be481dae8ef3383b6> *param_1,
          <lambda_628dfdc04ba53c8bfc02c9951375f3f5> *param_2,
          <lambda_57dc472bd5c9d5f3b2cbca59b8a843ae> *param_3)

{
  uint _FileHandle;
  int iVar1;
  int *piVar2;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763688,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  ___acrt_lowio_lock_fh(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  _FileHandle = *(uint *)**(undefined4 **)(unaff_EBP + 0xc);
  if ((*(byte *)((&DAT_00769d80)[(int)_FileHandle >> 6] + 0x28 + (_FileHandle & 0x3f) * 0x38) & 1)
      == 0) {
    piVar2 = __errno();
    *piVar2 = 9;
    iVar1 = -1;
  }
  else {
    iVar1 = __close_nolock(_FileHandle);
  }
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e42fc();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar1;
}

