
/* Library Function - Single Match
    ___acrt_get_process_end_policy
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_get_process_end_policy(void)

{
  int local_8;
  
  local_8 = 0;
  if ((-1 < *(int *)(*(int *)((int)ProcessEnvironmentBlock + 0x10) + 8)) &&
     (___acrt_AppPolicyGetProcessTerminationMethodInternal_4(&local_8), local_8 == 1)) {
    return 0;
  }
  return 1;
}

