
/* Library Function - Single Match
    int (__stdcall*__cdecl try_get_IsValidLocaleName(void))(wchar_t const *)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_func_int_wchar_t_ptr * __cdecl try_get_IsValidLocaleName(void)

{
  _func_int_wchar_t_ptr *p_Var1;
  
  p_Var1 = (_func_int_wchar_t_ptr *)
           try_get_function(0x13,"IsValidLocaleName",(module_id *)&DAT_00718058,
                            (module_id *)"IsValidLocaleName");
  return p_Var1;
}

