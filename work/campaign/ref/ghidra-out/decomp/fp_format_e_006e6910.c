
/* Library Function - Single Match
    int __cdecl fp_format_e(double const * const,char * const,unsigned int,char * const,unsigned
   int,int,bool,unsigned int,struct __crt_locale_pointers * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl
fp_format_e(double *param_1,char *param_2,uint param_3,char *param_4,uint param_5,int param_6,
           bool param_7,uint param_8,__crt_locale_pointers *param_9)

{
  uint uVar1;
  int iVar2;
  int local_10 [3];
  
  uVar1 = param_6 + 3U;
  if (param_5 <= param_6 + 3U) {
    uVar1 = param_5;
  }
  ___acrt_fltout(*(undefined4 *)param_1,*(undefined4 *)((int)param_1 + 4),param_6 + 1,local_10,
                 param_4,uVar1);
  iVar2 = -1;
  if (param_3 != 0xffffffff) {
    iVar2 = (param_3 - (local_10[0] == 0x2d)) - (uint)(0 < param_6);
  }
  iVar2 = ___acrt_fp_strflt_to_string
                    (param_2 + (uint)(0 < param_6) + (uint)(local_10[0] == 0x2d),iVar2,param_6 + 1,
                     local_10);
  if (iVar2 == 0) {
    iVar2 = fp_format_e_internal
                      (param_2,param_3,param_6,param_7,param_8,(_strflt *)local_10,false,param_9);
  }
  else {
    *param_2 = '\0';
  }
  return iVar2;
}

