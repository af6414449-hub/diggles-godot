
/* Library Function - Single Match
    ___acrt_locale_initialize_time
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_locale_initialize_time(__crt_locale_data *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined **ppuVar3;
  __crt_lc_time_data *_Memory;
  
  if (*(int *)(param_1 + 0xb4) == 0) {
    ppuVar3 = &PTR_DAT_00717458;
LAB_006ee1e1:
    ___acrt_locale_release_lc_time_reference(*(undefined4 *)(param_1 + 0x9c));
    *(undefined ***)(param_1 + 0x9c) = ppuVar3;
    uVar2 = 0;
  }
  else {
    ppuVar3 = (undefined **)__calloc_base(1,0x164);
    _Memory = (__crt_lc_time_data *)0x0;
    if ((__crt_lc_time_data *)ppuVar3 != (__crt_lc_time_data *)0x0) {
      bVar1 = initialize_lc_time((__crt_lc_time_data *)ppuVar3,param_1);
      if (bVar1) {
        *(undefined4 *)((int)ppuVar3 + 0xb0) = 1;
        FID_conflict__free((void *)0x0);
        goto LAB_006ee1e1;
      }
      ___acrt_locale_free_time(ppuVar3);
      _Memory = (__crt_lc_time_data *)ppuVar3;
    }
    FID_conflict__free(_Memory);
    uVar2 = 1;
  }
  return uVar2;
}

