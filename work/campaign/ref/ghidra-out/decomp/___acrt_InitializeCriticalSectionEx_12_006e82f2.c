
/* Library Function - Single Match
    ___acrt_InitializeCriticalSectionEx@12
   
   Library: Visual Studio 2019 Release */

void ___acrt_InitializeCriticalSectionEx_12
               (LPCRITICAL_SECTION param_1,DWORD param_2,undefined4 param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)try_get_function(0x12,"InitializeCriticalSectionEx",(module_id *)&DAT_00718050,
                                    (module_id *)&DAT_00718058);
  if (pcVar1 == (code *)0x0) {
    InitializeCriticalSectionAndSpinCount(param_1,param_2);
  }
  else {
    guard_check_icall(param_1,param_2,param_3);
    (*pcVar1)();
  }
  return;
}

