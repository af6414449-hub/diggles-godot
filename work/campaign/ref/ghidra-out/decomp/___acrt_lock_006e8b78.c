
/* Library Function - Single Match
    ___acrt_lock
   
   Library: Visual Studio 2019 Release */

void ___acrt_lock(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_0076a068 + param_1 * 0x18));
  return;
}

