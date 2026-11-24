
/* Library Function - Single Match
    ___scrt_dllmain_exception_filter
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___scrt_dllmain_exception_filter
               (undefined4 param_1,int param_2,undefined4 param_3,code *param_4,undefined4 param_5,
               undefined4 param_6)

{
  int iVar1;
  
  iVar1 = ___scrt_is_ucrt_dll_in_use();
  if ((iVar1 == 0) && (param_2 == 1)) {
    guard_check_icall(param_1,0,param_3);
    (*param_4)();
  }
  seh_filter_dll(param_5,param_6);
  return;
}

