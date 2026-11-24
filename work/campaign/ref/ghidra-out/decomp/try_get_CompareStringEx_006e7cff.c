
/* Library Function - Single Match
    int (__stdcall*__cdecl try_get_CompareStringEx(void))(wchar_t const *,unsigned long,wchar_t
   const *,int,wchar_t const *,int,struct _nlsversioninfo *,void *,long)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_func_int_wchar_t_ptr_ulong_wchar_t_ptr_int_wchar_t_ptr_int__nlsversioninfo_ptr_void_ptr_long *
__cdecl try_get_CompareStringEx(void)

{
  _func_int_wchar_t_ptr_ulong_wchar_t_ptr_int_wchar_t_ptr_int__nlsversioninfo_ptr_void_ptr_long
  *p_Var1;
  
  p_Var1 = (_func_int_wchar_t_ptr_ulong_wchar_t_ptr_int_wchar_t_ptr_int__nlsversioninfo_ptr_void_ptr_long
            *)try_get_function(1,"CompareStringEx",(module_id *)&DAT_00717f6c,
                               (module_id *)"CompareStringEx");
  return p_Var1;
}

