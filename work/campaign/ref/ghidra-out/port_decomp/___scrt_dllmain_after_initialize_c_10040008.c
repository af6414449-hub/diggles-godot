
/* Library Function - Single Match
    ___scrt_dllmain_after_initialize_c
   
   Library: Visual Studio 2019 Release */

undefined4 ___scrt_dllmain_after_initialize_c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ___scrt_is_ucrt_dll_in_use();
  if (iVar1 == 0) {
    uVar2 = FUN_10040d56();
    iVar1 = configure_narrow_argv(uVar2);
    if (iVar1 != 0) {
      return 0;
    }
    initialize_narrow_environment();
  }
  else {
    ___isa_available_init();
  }
  return 1;
}

