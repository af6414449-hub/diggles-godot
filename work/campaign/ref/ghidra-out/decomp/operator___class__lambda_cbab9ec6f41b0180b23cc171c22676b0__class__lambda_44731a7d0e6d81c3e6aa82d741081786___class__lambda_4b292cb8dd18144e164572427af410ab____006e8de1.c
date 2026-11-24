
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    public: void (__cdecl*__thiscall __crt_seh_guarded_call<void (__cdecl*)(int)>::operator()<class
   <lambda_cbab9ec6f41b0180b23cc171c22676b0>,class <lambda_44731a7d0e6d81c3e6aa82d741081786> &,class
   <lambda_4b292cb8dd18144e164572427af410ab> >(class <lambda_cbab9ec6f41b0180b23cc171c22676b0>
   &&,class <lambda_44731a7d0e6d81c3e6aa82d741081786> &,class
   <lambda_4b292cb8dd18144e164572427af410ab> &&))(int)
   
   Library: Visual Studio 2019 Release */

_func_void_int * __thiscall
__crt_seh_guarded_call<void_(__cdecl*)(int)>::
operator()<class_<lambda_cbab9ec6f41b0180b23cc171c22676b0>,class_<lambda_44731a7d0e6d81c3e6aa82d741081786>&,class_<lambda_4b292cb8dd18144e164572427af410ab>_>
          (__crt_seh_guarded_call<void_(__cdecl*)(int)> *this,
          <lambda_cbab9ec6f41b0180b23cc171c22676b0> *param_1,
          <lambda_44731a7d0e6d81c3e6aa82d741081786> *param_2,
          <lambda_4b292cb8dd18144e164572427af410ab> *param_3)

{
  byte bVar1;
  int unaff_EBP;
  _func_void_int *p_Var2;
  
  FUN_006cf3b0(&DAT_00763808,0xc);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  ___acrt_lock(**(undefined4 **)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  bVar1 = (byte)DAT_0076700c & 0x1f;
  p_Var2 = (_func_void_int *)
           ((DAT_0076700c ^ _DAT_0076a1c8) >> bVar1 | (DAT_0076700c ^ _DAT_0076a1c8) << 0x20 - bVar1
           );
  *(_func_void_int **)(unaff_EBP + -0x1c) = p_Var2;
  *(undefined4 *)(unaff_EBP + -4) = 0xfffffffe;
  FUN_006e8e39();
  ExceptionList = *(void **)(unaff_EBP + -0x10);
  return p_Var2;
}

