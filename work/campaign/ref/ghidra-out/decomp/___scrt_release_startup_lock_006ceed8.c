
/* Library Function - Single Match
    ___scrt_release_startup_lock
   
   Library: Visual Studio 2019 Release */

int ___scrt_release_startup_lock(char param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = ___scrt_is_ucrt_dll_in_use();
  iVar1 = DAT_0076973c;
  if ((iVar2 != 0) && (param_1 == '\0')) {
    LOCK();
    DAT_0076973c = 0;
    UNLOCK();
    iVar2 = iVar1;
  }
  return iVar2;
}

