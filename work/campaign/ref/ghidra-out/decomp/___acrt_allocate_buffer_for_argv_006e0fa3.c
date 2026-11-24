
/* Library Function - Single Match
    ___acrt_allocate_buffer_for_argv
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_allocate_buffer_for_argv(uint param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  if ((param_1 < 0x3fffffff) && (param_2 < (uint)(0xffffffff / (ulonglong)param_3))) {
    if (param_2 * param_3 < ~(param_1 * 4)) {
      uVar1 = __calloc_base(param_1 * 4 + param_2 * param_3,1);
      FID_conflict__free((void *)0x0);
      return uVar1;
    }
  }
  return 0;
}

