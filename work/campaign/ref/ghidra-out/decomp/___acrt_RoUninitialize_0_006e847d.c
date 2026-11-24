
/* Library Function - Single Match
    ___acrt_RoUninitialize@0
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_RoUninitialize_0(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)try_get_function(0x1b,"RoUninitialize",(module_id *)&DAT_007180d8,
                                    (module_id *)"RoUninitialize");
  if (pcVar1 != (code *)0x0) {
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}

