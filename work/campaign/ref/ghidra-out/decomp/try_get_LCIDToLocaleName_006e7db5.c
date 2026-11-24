
/* Library Function - Single Match
    int (__stdcall*__cdecl try_get_LCIDToLocaleName(void))(unsigned long,wchar_t *,int,unsigned
   long)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_func_int_ulong_wchar_t_ptr_int_ulong * __cdecl try_get_LCIDToLocaleName(void)

{
  _func_int_ulong_wchar_t_ptr_int_ulong *p_Var1;
  
  p_Var1 = (_func_int_ulong_wchar_t_ptr_int_ulong *)
           try_get_function(0x15,"LCIDToLocaleName",(module_id *)&DAT_0071808c,
                            (module_id *)"LCIDToLocaleName");
  return p_Var1;
}

