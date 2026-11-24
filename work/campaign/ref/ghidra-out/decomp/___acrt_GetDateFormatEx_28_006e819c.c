
/* Library Function - Single Match
    ___acrt_GetDateFormatEx@28
   
   Library: Visual Studio 2019 Release */

void ___acrt_GetDateFormatEx_28
               (wchar_t *param_1,ulong param_2,_SYSTEMTIME *param_3,wchar_t *param_4,
               wchar_t *param_5,int param_6,wchar_t *param_7)

{
  _func_int_wchar_t_ptr_ulong__SYSTEMTIME_ptr_wchar_t_ptr_wchar_t_ptr_int_wchar_t_ptr *p_Var1;
  LCID Locale;
  
  p_Var1 = try_get_GetDateFormatEx();
  if (p_Var1 == (_func_int_wchar_t_ptr_ulong__SYSTEMTIME_ptr_wchar_t_ptr_wchar_t_ptr_int_wchar_t_ptr
                 *)0x0) {
    Locale = ___acrt_LocaleNameToLCID_8(param_1,0);
    GetDateFormatW(Locale,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    guard_check_icall();
    (*p_Var1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}

