
/* Library Function - Single Match
    unsigned long (__stdcall*__cdecl try_get_LocaleNameToLCID(void))(wchar_t const *,unsigned long)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

_func_ulong_wchar_t_ptr_ulong * __cdecl try_get_LocaleNameToLCID(void)

{
  _func_ulong_wchar_t_ptr_ulong *p_Var1;
  
  p_Var1 = (_func_ulong_wchar_t_ptr_ulong *)
           try_get_function(0x16,"LocaleNameToLCID",(module_id *)&DAT_007180a8,
                            (module_id *)"LocaleNameToLCID");
  return p_Var1;
}

