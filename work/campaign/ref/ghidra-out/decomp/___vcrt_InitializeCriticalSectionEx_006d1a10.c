
/* Library Function - Single Match
    ___vcrt_InitializeCriticalSectionEx
   
   Library: Visual Studio 2019 Release */

void ___vcrt_InitializeCriticalSectionEx
               (LPCRITICAL_SECTION param_1,DWORD param_2,undefined4 param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)try_get_function(4,"InitializeCriticalSectionEx",(module_id *)&DAT_00716268,
                                    (module_id *)"InitializeCriticalSectionEx");
  if (pcVar1 == (code *)0x0) {
    InitializeCriticalSectionAndSpinCount(param_1,param_2);
  }
  else {
    guard_check_icall(param_1,param_2,param_3);
    (*pcVar1)();
  }
  return;
}

