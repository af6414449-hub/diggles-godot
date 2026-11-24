
/* Library Function - Single Match
    ___scrt_initialize_crt
   
   Library: Visual Studio 2019 Release */

undefined1 ___scrt_initialize_crt(int param_1)

{
  char cVar1;
  
  if (param_1 == 0) {
    DAT_00769740 = 1;
  }
  ___isa_available_init();
  cVar1 = ___vcrt_initialize();
  if (cVar1 != '\0') {
    cVar1 = ___acrt_initialize();
    if (cVar1 != '\0') {
      return 1;
    }
    ___vcrt_uninitialize(0);
  }
  return 0;
}

