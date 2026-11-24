
/* Library Function - Single Match
    ___vcrt_initialize
   
   Library: Visual Studio 2019 Release */

undefined1 ___vcrt_initialize(void)

{
  char cVar1;
  
  cVar1 = ___vcrt_initialize_locks();
  if (cVar1 != '\0') {
    cVar1 = ___vcrt_initialize_ptd();
    if (cVar1 != '\0') {
      return 1;
    }
    ___vcrt_uninitialize_locks();
  }
  return 0;
}

