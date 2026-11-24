
/* Library Function - Single Match
    int (__stdcall*__cdecl try_get_GetDateFormatEx(void))(wchar_t const *,unsigned long,struct
   _SYSTEMTIME const *,wchar_t const *,wchar_t *,int,wchar_t const *)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_func_int_wchar_t_ptr_ulong__SYSTEMTIME_ptr_wchar_t_ptr_wchar_t_ptr_int_wchar_t_ptr * __cdecl
try_get_GetDateFormatEx(void)

{
  _func_int_wchar_t_ptr_ulong__SYSTEMTIME_ptr_wchar_t_ptr_wchar_t_ptr_int_wchar_t_ptr *p_Var1;
  
  p_Var1 = (_func_int_wchar_t_ptr_ulong__SYSTEMTIME_ptr_wchar_t_ptr_wchar_t_ptr_int_wchar_t_ptr *)
           try_get_function(8,"GetDateFormatEx",(module_id *)&DAT_00717fc0,
                            (module_id *)"GetDateFormatEx");
  return p_Var1;
}

