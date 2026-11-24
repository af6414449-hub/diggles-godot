
/* Library Function - Single Match
    __Init_thread_notify
   
   Library: Visual Studio 2019 Release */

void __Init_thread_notify(void)

{
  code *pcVar1;
  
  pcVar1 = DAT_00769734;
  if (DAT_00769734 != (code *)0x0) {
    guard_check_icall(&DAT_00769710);
    (*pcVar1)();
    return;
  }
  SetEvent(DAT_00769714);
  ResetEvent(DAT_00769714);
  return;
}

