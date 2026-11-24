
/* Library Function - Single Match
    ___vcrt_FlsGetValue
   
   Library: Visual Studio 2019 Release */

void ___vcrt_FlsGetValue(DWORD param_1)

{
  code *pcVar1;
  
  pcVar1 = (code *)try_get_function(2,"FlsGetValue",(module_id *)&DAT_00716240,
                                    (module_id *)"FlsGetValue");
  if (pcVar1 == (code *)0x0) {
    TlsGetValue(param_1);
  }
  else {
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}

