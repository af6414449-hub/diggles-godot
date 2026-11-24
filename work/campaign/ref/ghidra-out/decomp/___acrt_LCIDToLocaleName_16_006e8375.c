
/* Library Function - Single Match
    ___acrt_LCIDToLocaleName@16
   
   Library: Visual Studio 2019 Release */

void ___acrt_LCIDToLocaleName_16(ulong param_1,wchar_t *param_2,int param_3,ulong param_4)

{
  _func_int_ulong_wchar_t_ptr_int_ulong *p_Var1;
  
  p_Var1 = try_get_LCIDToLocaleName();
  if (p_Var1 == (_func_int_ulong_wchar_t_ptr_int_ulong *)0x0) {
    ___acrt_DownlevelLCIDToLocaleName(param_1,param_2,param_3);
  }
  else {
    guard_check_icall();
    (*p_Var1)(param_1,param_2,param_3,param_4);
  }
  return;
}

