
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_e5124f882df8998aaf41531e079ba474>,class <lambda_3e16ef9562a7dcce91392c22ab16ea36> &,class
   <lambda_e25ca0880e6ef98be67edffd8c599615> >(class <lambda_e5124f882df8998aaf41531e079ba474>
   &&,class <lambda_3e16ef9562a7dcce91392c22ab16ea36> &,class
   <lambda_e25ca0880e6ef98be67edffd8c599615> &&)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_e5124f882df8998aaf41531e079ba474>,class_<lambda_3e16ef9562a7dcce91392c22ab16ea36>&,class_<lambda_e25ca0880e6ef98be67edffd8c599615>_>
          (__crt_seh_guarded_call<void> *this,<lambda_e5124f882df8998aaf41531e079ba474> *param_1,
          <lambda_3e16ef9562a7dcce91392c22ab16ea36> *param_2,
          <lambda_e25ca0880e6ef98be67edffd8c599615> *param_3)

{
  int iVar1;
  int unaff_EBP;
  int *piVar2;
  
  FUN_006cf3b0(&DAT_00763608,0xc);
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  for (piVar2 = &DAT_00769d78; *(int **)(unaff_EBP + -0x1c) = piVar2, piVar2 != &DAT_00769d7c;
      piVar2 = piVar2 + 1) {
    if ((undefined **)*piVar2 != &PTR_DAT_00767218) {
      iVar1 = __updatetlocinfoEx_nolock(piVar2,&PTR_DAT_00767218);
      *piVar2 = iVar1;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e1aab();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

