
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_2866be3712abc81a800a822484c830d8>,class <lambda_39ca0ed439415581b5b15c265174cece> &,class
   <lambda_2b24c74d71094a6cd0cb82e44167d71b> >(class <lambda_2866be3712abc81a800a822484c830d8>
   &&,class <lambda_39ca0ed439415581b5b15c265174cece> &,class
   <lambda_2b24c74d71094a6cd0cb82e44167d71b> &&)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_2866be3712abc81a800a822484c830d8>,class_<lambda_39ca0ed439415581b5b15c265174cece>&,class_<lambda_2b24c74d71094a6cd0cb82e44167d71b>_>
          (__crt_seh_guarded_call<void> *this,<lambda_2866be3712abc81a800a822484c830d8> *param_1,
          <lambda_39ca0ed439415581b5b15c265174cece> *param_2,
          <lambda_2b24c74d71094a6cd0cb82e44167d71b> *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763440,8);
  __lock_file((FILE *)**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
  bVar2 = common_flush_all_should_try_to_flush_stream(*(undefined4 *)*puVar1,puVar1[1]);
  if ((bVar2) &&
     ((*(char *)puVar1[2] != '\0' || ((*(uint *)(*(int *)*puVar1 + 0xc) >> 1 & 1) != 0)))) {
    iVar3 = __fflush_nolock(*(FILE **)*puVar1);
    if (iVar3 == -1) {
      *(undefined4 *)puVar1[3] = 0xffffffff;
    }
    else {
      *(int *)puVar1[1] = *(int *)puVar1[1] + 1;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006de054();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

