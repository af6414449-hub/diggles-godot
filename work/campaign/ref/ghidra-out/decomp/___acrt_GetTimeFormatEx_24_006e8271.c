
/* Library Function - Single Match
    ___acrt_GetTimeFormatEx@24
   
   Library: Visual Studio 2019 Release */

void ___acrt_GetTimeFormatEx_24
               (wchar_t *param_1,ulong param_2,_SYSTEMTIME *param_3,wchar_t *param_4,
               wchar_t *param_5,int param_6)

{
  _func_int_wchar_t_ptr_ulong__SYSTEMTIME_ptr_wchar_t_ptr_wchar_t_ptr_int *p_Var1;
  LCID Locale;
  
  p_Var1 = try_get_GetTimeFormatEx();
  if (p_Var1 == (_func_int_wchar_t_ptr_ulong__SYSTEMTIME_ptr_wchar_t_ptr_wchar_t_ptr_int *)0x0) {
    Locale = ___acrt_LocaleNameToLCID_8(param_1,0);
    GetTimeFormatW(Locale,param_2,param_3,param_4,param_5,param_6);
  }
  else {
    guard_check_icall();
    (*p_Var1)(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return;
}

