
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_38edbb1296d33220d7e4dd0ed76b244a>,class <lambda_5ce1d447e08cb34b2473517608e21441> &,class
   <lambda_fb385d3da700c9147fc39e65dd577a8c> >(class <lambda_38edbb1296d33220d7e4dd0ed76b244a>
   &&,class <lambda_5ce1d447e08cb34b2473517608e21441> &,class
   <lambda_fb385d3da700c9147fc39e65dd577a8c> &&)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_38edbb1296d33220d7e4dd0ed76b244a>,class_<lambda_5ce1d447e08cb34b2473517608e21441>&,class_<lambda_fb385d3da700c9147fc39e65dd577a8c>_>
          (__crt_seh_guarded_call<void> *this,<lambda_38edbb1296d33220d7e4dd0ed76b244a> *param_1,
          <lambda_5ce1d447e08cb34b2473517608e21441> *param_2,
          <lambda_fb385d3da700c9147fc39e65dd577a8c> *param_3)

{
  int iVar1;
  int *_Memory;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763728,8);
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  _Memory = *(int **)(*(int *)**(undefined4 **)(unaff_EBP + 0xc) + 0x48);
  if (_Memory != (int *)0x0) {
    LOCK();
    iVar1 = *_Memory;
    *_Memory = iVar1 + -1;
    UNLOCK();
    if ((iVar1 + -1 == 0) && (_Memory != (int *)&DAT_007673b8)) {
      FID_conflict__free(_Memory);
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e605c();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

