
/* Library Function - Single Match
    ___acrt_fp_format
   
   Library: Visual Studio 2019 Release */

int ___acrt_fp_format(double *param_1,char *param_2,uint param_3,char *param_4,uint param_5,
                     int param_6,int param_7,uint param_8,undefined4 param_9,
                     __crt_locale_pointers *param_10)

{
  int *piVar1;
  __acrt_fp_class _Var2;
  int iVar3;
  uint uVar4;
  bool local_c;
  bool local_8;
  
  if ((((param_2 == (char *)0x0) || (param_3 == 0)) || (param_4 == (char *)0x0)) || (param_5 == 0))
  {
    piVar1 = __errno();
    iVar3 = 0x16;
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  else {
    if (((param_6 == 0x41) || (param_6 == 0x45)) ||
       ((param_6 == 0x46 || (local_8 = false, param_6 == 0x47)))) {
      local_8 = true;
    }
    if (((param_8 & 8) == 0) && (_Var2 = __acrt_fp_classify(param_1), _Var2 != 0)) {
      if ((*(int *)((int)param_1 + 4) < 1) && (*(int *)((int)param_1 + 4) < 0)) {
        local_c = true;
      }
      else {
        local_c = false;
      }
      iVar3 = fp_format_nan_or_infinity(_Var2,local_c,param_2,param_3,local_8);
    }
    else {
      if ((param_8 & 0x10) == 0) {
        uVar4 = 2;
      }
      else {
        uVar4 = 3;
      }
      if (param_6 < 0x62) {
        if ((param_6 == 0x61) || (param_6 == 0x41)) {
          iVar3 = fp_format_a(param_1,param_2,param_3,param_4,param_5,param_7,local_8,uVar4,param_10
                             );
          return iVar3;
        }
        param_6 = param_6 + -0x45;
      }
      else {
        param_6 = param_6 + -0x65;
      }
      if (param_6 == 0) {
        iVar3 = fp_format_e(param_1,param_2,param_3,param_4,param_5,param_7,local_8,uVar4,param_10);
      }
      else if (param_6 == 1) {
        iVar3 = fp_format_f(param_1,param_2,param_3,param_4,param_5,param_7,param_10);
      }
      else {
        iVar3 = fp_format_g(param_1,param_2,param_3,param_4,param_5,param_7,local_8,uVar4,param_10);
      }
    }
  }
  return iVar3;
}

