
/* Library Function - Single Match
    ___acrt_locale_free_lc_time_if_unreferenced
   
   Library: Visual Studio 2019 Release */

void ___acrt_locale_free_lc_time_if_unreferenced(undefined **param_1)

{
  if (((param_1 != (undefined **)0x0) && (param_1 != &PTR_DAT_00717458)) &&
     (param_1[0x2c] == (undefined *)0x0)) {
    ___acrt_locale_free_time(param_1);
    FID_conflict__free(param_1);
  }
  return;
}

