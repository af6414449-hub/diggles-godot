
/* Library Function - Single Match
    int __cdecl fp_format_e_internal(char * const,unsigned int,int,bool,unsigned int,struct _strflt
   * const,bool,struct __crt_locale_pointers * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl
fp_format_e_internal
          (char *param_1,uint param_2,int param_3,bool param_4,uint param_5,_strflt *param_6,
          bool param_7,__crt_locale_pointers *param_8)

{
  int *piVar1;
  char *_SizeInBytes;
  errno_t eVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int local_14;
  int local_10;
  char local_8;
  
  iVar4 = param_3;
  if (param_3 < 1) {
    iVar4 = 0;
  }
  if (iVar4 + 9U < param_2) {
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,param_8);
    if (param_7) {
      shift_bytes(param_1,param_2,param_1 + (*(int *)param_6 == 0x2d),(uint)(0 < param_3));
    }
    pcVar5 = param_1;
    if (*(int *)param_6 == 0x2d) {
      *param_1 = '-';
      pcVar5 = param_1 + 1;
    }
    if (0 < param_3) {
      *pcVar5 = pcVar5[1];
      pcVar5 = pcVar5 + 1;
      *pcVar5 = *(char *)**(undefined4 **)(local_10 + 0x88);
    }
    pcVar5 = pcVar5 + (param_7 ^ 1) + param_3;
    _SizeInBytes = (char *)0xffffffff;
    if (param_2 != 0xffffffff) {
      _SizeInBytes = param_1 + (param_2 - (int)pcVar5);
    }
    eVar2 = _strcpy_s(pcVar5,(rsize_t)_SizeInBytes,"e+000");
    if (eVar2 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    if (param_4) {
      *pcVar5 = 'E';
    }
    if (**(char **)(param_6 + 8) != '0') {
      iVar4 = *(int *)(param_6 + 4) + -1;
      if (iVar4 < 0) {
        iVar4 = -iVar4;
        pcVar5[1] = '-';
      }
      if (99 < iVar4) {
        iVar3 = iVar4 / 100;
        iVar4 = iVar4 % 100;
        pcVar5[2] = pcVar5[2] + (char)iVar3;
      }
      if (9 < iVar4) {
        iVar3 = iVar4 / 10;
        iVar4 = iVar4 % 10;
        pcVar5[3] = pcVar5[3] + (char)iVar3;
      }
      pcVar5[4] = pcVar5[4] + (char)iVar4;
    }
    if ((param_5 == 2) && (pcVar5[2] == '0')) {
      FUN_006d1b90(pcVar5 + 2,pcVar5 + 3,3);
    }
    if (local_8 != '\0') {
      *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
    }
    iVar4 = 0;
  }
  else {
    piVar1 = __errno();
    iVar4 = 0x22;
    *piVar1 = 0x22;
    FUN_006e510d();
  }
  return iVar4;
}

