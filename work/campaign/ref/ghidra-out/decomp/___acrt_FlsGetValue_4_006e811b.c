
/* Library Function - Single Match
    ___acrt_FlsGetValue@4
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_FlsGetValue_4(DWORD param_1)

{
  code *pcVar1;
  
  pcVar1 = (code *)try_get_function(5,"FlsGetValue",(module_id *)&DAT_00717fb0,
                                    (module_id *)&DAT_00717fb8);
  if (pcVar1 != (code *)0x0) {
    guard_check_icall(param_1);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x006e8154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlsGetValue(param_1);
  return;
}

