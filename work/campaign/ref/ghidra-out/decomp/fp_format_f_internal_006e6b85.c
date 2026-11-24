
/* Library Function - Single Match
    int __cdecl fp_format_f_internal(char * const,unsigned int,int,struct _strflt *
   const,bool,struct __crt_locale_pointers * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl
fp_format_f_internal
          (char *param_1,uint param_2,int param_3,_strflt *param_4,bool param_5,
          __crt_locale_pointers *param_6)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  int local_14;
  int local_10;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,param_6);
  iVar2 = *(int *)(param_4 + 4);
  if ((param_5) && (iVar2 + -1 == param_3)) {
    iVar1 = *(int *)param_4;
    (param_1 + (uint)(iVar1 == 0x2d) + iVar2 + -1)[0] = '0';
    (param_1 + (uint)(iVar1 == 0x2d) + iVar2 + -1)[1] = '\0';
  }
  pcVar4 = param_1;
  if (*(int *)param_4 == 0x2d) {
    *param_1 = '-';
    pcVar4 = param_1 + 1;
  }
  iVar2 = *(int *)(param_4 + 4);
  if (iVar2 < 1) {
    shift_bytes(param_1,param_2,pcVar4,1);
    *pcVar4 = '0';
    iVar2 = 1;
  }
  pcVar4 = pcVar4 + iVar2;
  if (0 < param_3) {
    shift_bytes(param_1,param_2,pcVar4,1);
    *pcVar4 = *(char *)**(undefined4 **)(local_10 + 0x88);
    if (*(int *)(param_4 + 4) < 0) {
      sVar3 = -*(int *)(param_4 + 4);
      if ((param_5) || ((int)sVar3 < param_3)) {
        param_3 = sVar3;
      }
      shift_bytes(param_1,param_2,pcVar4 + 1,param_3);
      _memset(pcVar4 + 1,0x30,param_3);
    }
  }
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
  }
  return 0;
}

