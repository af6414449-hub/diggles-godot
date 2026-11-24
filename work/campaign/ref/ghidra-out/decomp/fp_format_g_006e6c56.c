
/* Library Function - Single Match
    int __cdecl fp_format_g(double const * const,char * const,unsigned int,char * const,unsigned
   int,int,bool,unsigned int,struct __crt_locale_pointers * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl
fp_format_g(double *param_1,char *param_2,uint param_3,char *param_4,uint param_5,int param_6,
           bool param_7,uint param_8,__crt_locale_pointers *param_9)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  int local_14;
  int local_10;
  undefined4 uStack_c;
  int local_8;
  
  local_14 = 0;
  local_10 = 0;
  uStack_c = 0;
  ___acrt_fltout(*(undefined4 *)param_1,*(undefined4 *)((int)param_1 + 4),param_6,&local_14,param_4,
                 param_5);
  bVar4 = local_14 == 0x2d;
  local_8 = local_10 + -1;
  iVar2 = -1;
  if (param_3 != 0xffffffff) {
    iVar2 = param_3 - bVar4;
  }
  iVar2 = ___acrt_fp_strflt_to_string(param_2 + bVar4,iVar2,param_6,&local_14);
  if (iVar2 == 0) {
    iVar2 = local_10 + -1;
    if ((iVar2 < -4) || (param_6 <= iVar2)) {
      iVar2 = fp_format_e_internal
                        (param_2,param_3,param_6,param_7,param_8,(_strflt *)&local_14,true,param_9);
    }
    else {
      pcVar1 = param_2 + bVar4;
      if (local_8 < iVar2) {
        do {
          pcVar3 = pcVar1;
          pcVar1 = pcVar3 + 1;
        } while (*pcVar3 != '\0');
        pcVar3[-1] = '\0';
      }
      iVar2 = fp_format_f_internal(param_2,param_3,param_6,(_strflt *)&local_14,true,param_9);
    }
  }
  else {
    *param_2 = '\0';
  }
  return iVar2;
}

