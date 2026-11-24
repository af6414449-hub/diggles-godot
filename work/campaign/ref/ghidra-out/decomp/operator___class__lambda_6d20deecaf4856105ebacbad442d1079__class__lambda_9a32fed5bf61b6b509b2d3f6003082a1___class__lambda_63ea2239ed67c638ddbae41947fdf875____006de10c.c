
/* Library Function - Single Match
    public: int __thiscall __crt_seh_guarded_call<int>::operator()<class
   <lambda_6d20deecaf4856105ebacbad442d1079>,class <lambda_9a32fed5bf61b6b509b2d3f6003082a1> &,class
   <lambda_63ea2239ed67c638ddbae41947fdf875> >(class <lambda_6d20deecaf4856105ebacbad442d1079>
   &&,class <lambda_9a32fed5bf61b6b509b2d3f6003082a1> &,class
   <lambda_63ea2239ed67c638ddbae41947fdf875> &&)
   
   Library: Visual Studio 2019 Release */

int __thiscall
__crt_seh_guarded_call<int>::
operator()<class_<lambda_6d20deecaf4856105ebacbad442d1079>,class_<lambda_9a32fed5bf61b6b509b2d3f6003082a1>&,class_<lambda_63ea2239ed67c638ddbae41947fdf875>_>
          (__crt_seh_guarded_call<int> *this,<lambda_6d20deecaf4856105ebacbad442d1079> *param_1,
          <lambda_9a32fed5bf61b6b509b2d3f6003082a1> *param_2,
          <lambda_63ea2239ed67c638ddbae41947fdf875> *param_3)

{
  int iVar1;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_00763480,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  __lock_file((FILE *)**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = __fflush_nolock(*(FILE **)**(undefined4 **)(unaff_EBP + 0xc));
  *(int *)(unaff_EBP + -0x1c) = iVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006de160();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return iVar1;
}

