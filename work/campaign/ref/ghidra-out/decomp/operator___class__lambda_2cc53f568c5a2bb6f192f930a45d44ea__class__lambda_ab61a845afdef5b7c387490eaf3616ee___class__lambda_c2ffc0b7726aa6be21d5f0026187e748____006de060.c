
/* Library Function - Single Match
    public: void __thiscall __crt_seh_guarded_call<void>::operator()<class
   <lambda_2cc53f568c5a2bb6f192f930a45d44ea>,class <lambda_ab61a845afdef5b7c387490eaf3616ee> &,class
   <lambda_c2ffc0b7726aa6be21d5f0026187e748> >(class <lambda_2cc53f568c5a2bb6f192f930a45d44ea>
   &&,class <lambda_ab61a845afdef5b7c387490eaf3616ee> &,class
   <lambda_c2ffc0b7726aa6be21d5f0026187e748> &&)
   
   Library: Visual Studio 2019 Release */

void __thiscall
__crt_seh_guarded_call<void>::
operator()<class_<lambda_2cc53f568c5a2bb6f192f930a45d44ea>,class_<lambda_ab61a845afdef5b7c387490eaf3616ee>&,class_<lambda_c2ffc0b7726aa6be21d5f0026187e748>_>
          (__crt_seh_guarded_call<void> *this,<lambda_2cc53f568c5a2bb6f192f930a45d44ea> *param_1,
          <lambda_ab61a845afdef5b7c387490eaf3616ee> *param_2,
          <lambda_c2ffc0b7726aa6be21d5f0026187e748> *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  bool bVar5;
  int unaff_EBP;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  FUN_006cf3b0(&DAT_00763460,0x2c);
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar1 = DAT_00769b44 + DAT_00769b40;
  puVar7 = *(undefined4 **)(unaff_EBP + 0xc);
  for (puVar6 = DAT_00769b44; *(undefined4 **)(unaff_EBP + -0x2c) = puVar6, puVar6 != puVar1;
      puVar6 = puVar6 + 1) {
    uVar2 = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x20) = uVar2;
    bVar5 = common_flush_all_should_try_to_flush_stream(uVar2,*puVar7);
    if (bVar5) {
      uVar2 = puVar7[2];
      uVar3 = puVar7[1];
      uVar4 = *puVar7;
      *(int *)(unaff_EBP + -0x3c) = unaff_EBP + -0x20;
      *(undefined4 *)(unaff_EBP + -0x38) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
      *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x20);
      operator()<class_<lambda_2866be3712abc81a800a822484c830d8>,class_<lambda_39ca0ed439415581b5b15c265174cece>&,class_<lambda_2b24c74d71094a6cd0cb82e44167d71b>_>
                ((__crt_seh_guarded_call<void> *)(unaff_EBP + -0x19),
                 (<lambda_2866be3712abc81a800a822484c830d8> *)(unaff_EBP + -0x28),
                 (<lambda_39ca0ed439415581b5b15c265174cece> *)(unaff_EBP + -0x3c),
                 (<lambda_2b24c74d71094a6cd0cb82e44167d71b> *)(unaff_EBP + -0x24));
      puVar7 = *(undefined4 **)(unaff_EBP + 0xc);
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006de100();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return;
}

