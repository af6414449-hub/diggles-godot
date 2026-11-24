
/* Library Function - Single Match
    ___scrt_dllmain_crt_thread_attach
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined1 ___scrt_dllmain_crt_thread_attach(void)

{
  char cVar1;
  
  cVar1 = FUN_10040fb0();
  if (cVar1 != '\0') {
    cVar1 = FUN_10040fb0();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_10040fb0();
  }
  return 0;
}

