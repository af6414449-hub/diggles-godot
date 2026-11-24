
/* Library Function - Single Match
    ___vcrt_FlsFree
   
   Library: Visual Studio 2019 Release */

void ___vcrt_FlsFree(DWORD param_1)

{
  code *pcVar1;
  
  pcVar1 = (code *)try_get_function(1,"FlsFree",(module_id *)&DAT_00716230,(module_id *)"FlsFree");
  if (pcVar1 == (code *)0x0) {
    TlsFree(param_1);
  }
  else {
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}

