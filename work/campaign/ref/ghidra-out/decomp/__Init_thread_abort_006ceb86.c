
/* Library Function - Single Match
    __Init_thread_abort
   
   Library: Visual Studio 2019 Release */

void __Init_thread_abort(undefined4 *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00769718);
  *param_1 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00769718);
  __Init_thread_notify();
  return;
}

