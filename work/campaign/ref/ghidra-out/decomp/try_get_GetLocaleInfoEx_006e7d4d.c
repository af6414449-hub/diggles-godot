
/* Library Function - Single Match
    int (__stdcall*__cdecl try_get_GetLocaleInfoEx(void))(wchar_t const *,unsigned long,wchar_t
   *,int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_func_int_wchar_t_ptr_ulong_wchar_t_ptr_int * __cdecl try_get_GetLocaleInfoEx(void)

{
  _func_int_wchar_t_ptr_ulong_wchar_t_ptr_int *p_Var1;
  
  p_Var1 = (_func_int_wchar_t_ptr_ulong_wchar_t_ptr_int *)
           try_get_function(0xb,"GetLocaleInfoEx",(module_id *)&DAT_00717fd8,
                            (module_id *)"GetLocaleInfoEx");
  return p_Var1;
}

