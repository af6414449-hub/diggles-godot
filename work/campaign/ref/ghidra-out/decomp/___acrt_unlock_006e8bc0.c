
/* Library Function - Single Match
    ___acrt_unlock
   
   Library: Visual Studio 2019 Release */

void ___acrt_unlock(int param_1)

{
  LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_0076a068 + param_1 * 0x18));
  return;
}

