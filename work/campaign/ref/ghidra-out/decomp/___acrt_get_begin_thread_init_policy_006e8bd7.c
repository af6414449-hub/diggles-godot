
/* Library Function - Single Match
    ___acrt_get_begin_thread_init_policy
   
   Library: Visual Studio 2019 Release */

int ___acrt_get_begin_thread_init_policy(void)

{
  int iVar1;
  int local_8;
  
  if (DAT_0076a1bc == 0) {
    local_8 = 0;
    iVar1 = 1;
    if (-1 < *(int *)(*(int *)((int)ProcessEnvironmentBlock + 0x10) + 8)) {
      ___acrt_AppPolicyGetThreadInitializationTypeInternal_4(&local_8);
      if (local_8 == 1) {
        iVar1 = 2;
      }
    }
    LOCK();
    UNLOCK();
    DAT_0076a1bc = iVar1;
  }
  return DAT_0076a1bc;
}

