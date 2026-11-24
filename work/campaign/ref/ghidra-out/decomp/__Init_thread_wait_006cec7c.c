
/* Library Function - Single Match
    __Init_thread_wait
   
   Library: Visual Studio 2019 Release */

void __Init_thread_wait(DWORD param_1)

{
  code *pcVar1;
  
  pcVar1 = DAT_00769730;
  if (DAT_00769730 == (code *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00769718);
    WaitForSingleObjectEx(DAT_00769714,param_1,0);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00769718);
  }
  else {
    guard_check_icall(&DAT_00769710,&DAT_00769718,param_1);
    (*pcVar1)();
  }
  return;
}

