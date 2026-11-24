
/* Library Function - Single Match
    ___acrt_can_use_vista_locale_apis
   
   Library: Visual Studio 2019 Release */

bool ___acrt_can_use_vista_locale_apis(void)

{
  _func_int_wchar_t_ptr_ulong_wchar_t_ptr_int_wchar_t_ptr_int__nlsversioninfo_ptr_void_ptr_long
  *p_Var1;
  
  p_Var1 = try_get_CompareStringEx();
  return p_Var1 != (_func_int_wchar_t_ptr_ulong_wchar_t_ptr_int_wchar_t_ptr_int__nlsversioninfo_ptr_void_ptr_long
                    *)0x0;
}

