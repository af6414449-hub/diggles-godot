
/* Library Function - Single Match
    void __stdcall destroy_fls(void *)
   
   Library: Visual Studio 2019 Release */

void destroy_fls(void *param_1)

{
  if (param_1 != (void *)0x0) {
    destroy_ptd((__acrt_ptd *)param_1);
    FID_conflict__free(param_1);
  }
  return;
}

