
/* Library Function - Single Match
    ___acrt_update_thread_multibyte_data
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_update_thread_multibyte_data(void)

{
  __acrt_ptd *p_Var1;
  __crt_multibyte_data **pp_Var2;
  
  pp_Var2 = (__crt_multibyte_data **)&DAT_0076a1ec;
  p_Var1 = (__acrt_ptd *)___acrt_getptd();
  update_thread_multibyte_data_internal(p_Var1,pp_Var2);
  return;
}

