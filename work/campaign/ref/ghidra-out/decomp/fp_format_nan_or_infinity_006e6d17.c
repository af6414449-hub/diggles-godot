
/* Library Function - Single Match
    int __cdecl fp_format_nan_or_infinity(enum __acrt_fp_class,bool,char *,unsigned int,bool)
   
   Library: Visual Studio 2019 Release */

int __cdecl
fp_format_nan_or_infinity
          (__acrt_fp_class param_1,bool param_2,char *param_3,uint param_4,bool param_5)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  errno_t eVar4;
  char *pcVar5;
  
  if (param_4 < param_2 + 4) {
    *param_3 = '\0';
    return 0xc;
  }
  if (param_2) {
    *param_3 = '-';
    param_3 = param_3 + 1;
    *param_3 = '\0';
    if (param_4 != 0xffffffff) {
      param_4 = param_4 - 1;
    }
  }
  iVar3 = (param_5 ^ 1) * 2;
  pcVar5 = (&PTR_DAT_007173d0)[param_1 * 4 + -4 + iVar3];
  pcVar1 = pcVar5 + 1;
  do {
    cVar2 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar2 != '\0');
  eVar4 = _strcpy_s(param_3,param_4,
                    (&PTR_DAT_007173d0)
                    [((param_1 * 4 + -3) - (uint)((uint)((int)pcVar5 - (int)pcVar1) < param_4)) +
                     iVar3]);
  if (eVar4 == 0) {
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
}

