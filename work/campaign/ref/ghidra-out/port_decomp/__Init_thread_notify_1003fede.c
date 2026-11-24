
/* Library Function - Single Match
    __Init_thread_notify
   
   Library: Visual Studio 2019 Release */

void __Init_thread_notify(void)

{
  code *pcVar1;
  
  pcVar1 = DAT_100508b4;
  if (DAT_100508b4 != (code *)0x0) {
    guard_check_icall(&DAT_10050890);
    (*pcVar1)();
    return;
  }
  SetEvent(DAT_10050894);
  ResetEvent(DAT_10050894);
  return;
}

