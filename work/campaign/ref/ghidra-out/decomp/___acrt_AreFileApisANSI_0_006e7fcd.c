
/* Library Function - Single Match
    ___acrt_AreFileApisANSI@0
   
   Library: Visual Studio 2019 Release */

int ___acrt_AreFileApisANSI_0(void)

{
  _func_int *p_Var1;
  int iVar2;
  
  p_Var1 = try_get_AreFileApisANSI();
  if (p_Var1 != (_func_int *)0x0) {
    guard_check_icall();
    iVar2 = (*p_Var1)();
    return iVar2;
  }
  return 1;
}

