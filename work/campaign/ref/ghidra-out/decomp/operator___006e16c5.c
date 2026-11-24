
/* Library Function - Single Match
    public: void __thiscall <lambda_af42a3ee9806e9a7305d451646e05244>::operator()(struct
   __crt_multibyte_data * &)const 
   
   Library: Visual Studio 2019 Release */

void __thiscall
<lambda_af42a3ee9806e9a7305d451646e05244>::operator()
          (<lambda_af42a3ee9806e9a7305d451646e05244> *this,__crt_multibyte_data **param_1)

{
  int iVar1;
  
  LOCK();
  iVar1 = *(int *)*param_1 + -1;
  *(int *)*param_1 = iVar1;
  UNLOCK();
  if ((iVar1 == 0) && (*param_1 != (__crt_multibyte_data *)&DAT_007673b8)) {
    FID_conflict__free(*param_1);
    *param_1 = (__crt_multibyte_data *)&DAT_007673b8;
  }
  return;
}

