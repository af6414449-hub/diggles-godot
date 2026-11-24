
/* Library Function - Single Match
    __updatetlocinfoEx_nolock
   
   Library: Visual Studio 2019 Release */

undefined ** __updatetlocinfoEx_nolock(int *param_1,undefined **param_2)

{
  undefined **ppuVar1;
  
  if ((param_2 == (undefined **)0x0) || (param_1 == (int *)0x0)) {
    param_2 = (undefined **)0x0;
  }
  else {
    ppuVar1 = (undefined **)*param_1;
    if (ppuVar1 != param_2) {
      *param_1 = (int)param_2;
      ___acrt_add_locale_ref(param_2);
      if (((ppuVar1 != (undefined **)0x0) &&
          (___acrt_release_locale_ref(ppuVar1), ppuVar1[3] == (undefined *)0x0)) &&
         (ppuVar1 != &PTR_DAT_00767218)) {
        ___acrt_free_locale(ppuVar1);
      }
    }
  }
  return param_2;
}

