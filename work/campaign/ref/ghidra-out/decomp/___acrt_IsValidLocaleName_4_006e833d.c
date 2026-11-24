
/* Library Function - Single Match
    ___acrt_IsValidLocaleName@4
   
   Library: Visual Studio 2019 Release */

void ___acrt_IsValidLocaleName_4(wchar_t *param_1)

{
  _func_int_wchar_t_ptr *p_Var1;
  LCID Locale;
  DWORD dwFlags;
  
  p_Var1 = try_get_IsValidLocaleName();
  if (p_Var1 == (_func_int_wchar_t_ptr *)0x0) {
    dwFlags = 1;
    Locale = ___acrt_LocaleNameToLCID_8(param_1,0);
    IsValidLocale(Locale,dwFlags);
  }
  else {
    guard_check_icall();
    (*p_Var1)(param_1);
  }
  return;
}

