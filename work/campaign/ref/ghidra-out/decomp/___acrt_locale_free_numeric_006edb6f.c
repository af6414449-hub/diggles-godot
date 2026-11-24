
/* Library Function - Single Match
    ___acrt_locale_free_numeric
   
   Library: Visual Studio 2019 Release */

void ___acrt_locale_free_numeric(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((undefined *)*param_1 != PTR_DAT_007678d8) {
      FID_conflict__free((undefined *)*param_1);
    }
    if ((undefined *)param_1[1] != PTR_DAT_007678dc) {
      FID_conflict__free((undefined *)param_1[1]);
    }
    if ((undefined *)param_1[2] != PTR_DAT_007678e0) {
      FID_conflict__free((undefined *)param_1[2]);
    }
    if ((undefined *)param_1[0xc] != PTR_DAT_00767908) {
      FID_conflict__free((undefined *)param_1[0xc]);
    }
    if ((undefined *)param_1[0xd] != PTR_DAT_0076790c) {
      FID_conflict__free((undefined *)param_1[0xd]);
    }
  }
  return;
}

