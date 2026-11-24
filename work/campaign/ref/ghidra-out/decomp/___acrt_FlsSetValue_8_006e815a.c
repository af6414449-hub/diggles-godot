
/* Library Function - Single Match
    ___acrt_FlsSetValue@8
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_FlsSetValue_8(DWORD param_1,LPVOID param_2)

{
  code *pcVar1;
  
  pcVar1 = (code *)try_get_function(6,"FlsSetValue",(module_id *)&DAT_00717fb8,
                                    (module_id *)&DAT_00717fc0);
  if (pcVar1 != (code *)0x0) {
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x006e8196. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TlsSetValue(param_1,param_2);
  return;
}

