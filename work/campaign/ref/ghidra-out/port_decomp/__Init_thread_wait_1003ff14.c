
/* Library Function - Single Match
    __Init_thread_wait
   
   Library: Visual Studio 2019 Release */

void __Init_thread_wait(DWORD param_1)

{
  code *pcVar1;
  
  pcVar1 = DAT_100508b0;
  if (DAT_100508b0 == (code *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_10050898);
    WaitForSingleObjectEx(DAT_10050894,param_1,0);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_10050898);
  }
  else {
    guard_check_icall(&DAT_10050890,&DAT_10050898,param_1);
    (*pcVar1)();
  }
  return;
}

