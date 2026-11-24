
/* Library Function - Single Match
    public: char * __thiscall __crt_seh_guarded_call<char *>::operator()<class
   <lambda_646e26742ed01d5bc03234f44bb6d3d3>,class <lambda_b37934c380d97b75fd242ea49540127a> &,class
   <lambda_bbd9d45274666fbb50f81a29ad795c13> >(class <lambda_646e26742ed01d5bc03234f44bb6d3d3>
   &&,class <lambda_b37934c380d97b75fd242ea49540127a> &,class
   <lambda_bbd9d45274666fbb50f81a29ad795c13> &&)
   
   Library: Visual Studio 2019 Release */

char * __thiscall
__crt_seh_guarded_call<char*>::
operator()<class_<lambda_646e26742ed01d5bc03234f44bb6d3d3>,class_<lambda_b37934c380d97b75fd242ea49540127a>&,class_<lambda_bbd9d45274666fbb50f81a29ad795c13>_>
          (__crt_seh_guarded_call<char*> *this,<lambda_646e26742ed01d5bc03234f44bb6d3d3> *param_1,
          <lambda_b37934c380d97b75fd242ea49540127a> *param_2,
          <lambda_bbd9d45274666fbb50f81a29ad795c13> *param_3)

{
  char *pcVar1;
  int unaff_EBP;
  
  FUN_006cf3b0(&DAT_007634c0,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pcVar1 = <lambda_b37934c380d97b75fd242ea49540127a>::operator()
                     (*(<lambda_b37934c380d97b75fd242ea49540127a> **)(unaff_EBP + 0xc));
  *(char **)(unaff_EBP + -0x1c) = pcVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006df3ee();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return pcVar1;
}

