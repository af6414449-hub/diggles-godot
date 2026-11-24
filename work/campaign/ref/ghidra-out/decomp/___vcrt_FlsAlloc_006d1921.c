
/* Library Function - Single Match
    ___vcrt_FlsAlloc
   
   Library: Visual Studio 2019 Release */

void ___vcrt_FlsAlloc(undefined4 param_1)

{
  code *pcVar1;
  
  pcVar1 = (code *)try_get_function(0,"FlsAlloc",(module_id *)&DAT_0071621c,(module_id *)"FlsAlloc")
  ;
  if (pcVar1 != (code *)0x0) {
    guard_check_icall(param_1);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x006d1956. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlsAlloc();
  return;
}

