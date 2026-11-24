
/* Library Function - Single Match
    int __stdcall dllmain_crt_dispatch(struct HINSTANCE__ * const,unsigned long,void * const)
   
   Library: Visual Studio 2019 Release */

int dllmain_crt_dispatch(HINSTANCE__ *param_1,ulong param_2,void *param_3)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = dllmain_crt_process_detach(param_3 != (void *)0x0);
  }
  else if (param_2 == 1) {
    uVar1 = dllmain_crt_process_attach(param_1,param_3);
  }
  else {
    if (param_2 == 2) {
      uVar1 = ___scrt_dllmain_crt_thread_attach();
    }
    else {
      if (param_2 != 3) {
        return 1;
      }
      uVar1 = ___scrt_dllmain_crt_thread_detach();
    }
    uVar1 = uVar1 & 0xff;
  }
  return uVar1;
}

