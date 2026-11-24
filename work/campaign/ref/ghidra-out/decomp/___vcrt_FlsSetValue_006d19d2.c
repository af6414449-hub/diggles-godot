
/* Library Function - Single Match
    ___vcrt_FlsSetValue
   
   Library: Visual Studio 2019 Release */

void ___vcrt_FlsSetValue(DWORD param_1,LPVOID param_2)

{
  code *pcVar1;
  
  pcVar1 = (code *)try_get_function(3,"FlsSetValue",(module_id *)&DAT_00716254,
                                    (module_id *)"FlsSetValue");
  if (pcVar1 == (code *)0x0) {
    TlsSetValue(param_1,param_2);
  }
  else {
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}

