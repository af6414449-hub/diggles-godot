
/* Library Function - Single Match
    int (__stdcall*__cdecl try_get_GetTimeFormatEx(void))(wchar_t const *,unsigned long,struct
   _SYSTEMTIME const *,wchar_t const *,wchar_t *,int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_func_int_wchar_t_ptr_ulong__SYSTEMTIME_ptr_wchar_t_ptr_wchar_t_ptr_int * __cdecl
try_get_GetTimeFormatEx(void)

{
  _func_int_wchar_t_ptr_ulong__SYSTEMTIME_ptr_wchar_t_ptr_wchar_t_ptr_int *p_Var1;
  
  p_Var1 = (_func_int_wchar_t_ptr_ulong__SYSTEMTIME_ptr_wchar_t_ptr_wchar_t_ptr_int *)
           try_get_function(0xe,"GetTimeFormatEx",(module_id *)&DAT_00718014,
                            (module_id *)"GetTimeFormatEx");
  return p_Var1;
}

