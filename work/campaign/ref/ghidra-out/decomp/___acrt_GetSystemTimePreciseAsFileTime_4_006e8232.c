
/* Library Function - Single Match
    ___acrt_GetSystemTimePreciseAsFileTime@4
   
   Library: Visual Studio 2019 Release */

void ___acrt_GetSystemTimePreciseAsFileTime_4(LPFILETIME param_1)

{
  code *pcVar1;
  
  pcVar1 = (code *)try_get_function(0xd,"GetSystemTimePreciseAsFileTime",(module_id *)&DAT_00717ff0,
                                    (module_id *)"GetSystemTimePreciseAsFileTime");
  if (pcVar1 != (code *)0x0) {
    guard_check_icall(param_1);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x006e826b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  GetSystemTimeAsFileTime(param_1);
  return;
}

