
/* Library Function - Single Match
    int (__stdcall*__cdecl try_get_GetUserDefaultLocaleName(void))(wchar_t *,int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_func_int_wchar_t_ptr_int * __cdecl try_get_GetUserDefaultLocaleName(void)

{
  _func_int_wchar_t_ptr_int *p_Var1;
  
  p_Var1 = (_func_int_wchar_t_ptr_int *)
           try_get_function(0xf,"GetUserDefaultLocaleName",(module_id *)&DAT_0071802c,
                            (module_id *)"GetUserDefaultLocaleName");
  return p_Var1;
}

