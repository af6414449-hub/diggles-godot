
/* Library Function - Single Match
    __ischartype_l
   
   Library: Visual Studio 2019 Release */

uint __ischartype_l(int param_1,uint param_2,_locale_t param_3)

{
  ushort *puVar1;
  
  if (param_3 == (_locale_t)0x0) {
    puVar1 = ___pctype_func();
    param_2 = ___acrt_locale_get_ctype_array_value(puVar1,param_1,param_2);
  }
  else if (param_1 + 1U < 0x101) {
    param_2 = *(ushort *)(param_3->locinfo->refcount + param_1 * 2) & param_2;
  }
  else if ((int)param_3->locinfo->lc_codepage < 2) {
    param_2 = 0;
  }
  else {
    param_2 = __isctype_l(param_1,param_2,param_3);
  }
  return param_2;
}

