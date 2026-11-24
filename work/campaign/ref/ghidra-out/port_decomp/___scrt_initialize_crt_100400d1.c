
/* Library Function - Single Match
    ___scrt_initialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 ___scrt_initialize_crt(int param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    DAT_100508c0 = 1;
  }
  ___isa_available_init();
  cVar1 = FUN_10040fb0();
  if (cVar1 != '\0') {
    cVar1 = FUN_10040fb0();
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_10040fb0(0);
  }
  return 0;
}

