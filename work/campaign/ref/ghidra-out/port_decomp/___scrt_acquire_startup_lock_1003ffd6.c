
/* Library Function - Single Match
    ___scrt_acquire_startup_lock
   
   Library: Visual Studio 2019 Release */

undefined4 ___scrt_acquire_startup_lock(void)

{
  void *pvVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = ___scrt_is_ucrt_dll_in_use();
  if (iVar2 != 0) {
    while( true ) {
      pvVar3 = (void *)0x0;
      LOCK();
      pvVar1 = StackBase;
      if (DAT_100508bc != (void *)0x0) {
        pvVar3 = DAT_100508bc;
        pvVar1 = DAT_100508bc;
      }
      DAT_100508bc = pvVar1;
      UNLOCK();
      if (pvVar3 == (void *)0x0) break;
      if (StackBase == pvVar3) {
        return 1;
      }
    }
  }
  return 0;
}

