
/* Library Function - Single Match
    ___acrt_FlsAlloc@4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_FlsAlloc_4(undefined4 param_1)

{
  code *pcVar1;
  
  pcVar1 = (code *)try_get_function(3,"FlsAlloc",(module_id *)&DAT_00717fa0,
                                    (module_id *)&DAT_00717fa8);
  if (pcVar1 == (code *)0x0) {
    TlsAlloc();
  }
  else {
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}

