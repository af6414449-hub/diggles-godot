
/* Library Function - Single Match
    int __cdecl common_getenv_s_nolock<char>(unsigned int * const,char * const,unsigned int,char
   const * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_getenv_s_nolock<char>(uint *param_1,char *param_2,uint param_3,char *param_4)

{
  char cVar1;
  int *piVar2;
  char *_Src;
  errno_t eVar3;
  char *pcVar4;
  
  if (param_1 == (uint *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    return 0x16;
  }
  *param_1 = 0;
  if (param_2 == (char *)0x0) {
    if (param_3 == 0) goto LAB_006e9820;
  }
  else if (param_3 != 0) {
LAB_006e9820:
    if (param_2 != (char *)0x0) {
      *param_2 = '\0';
    }
    _Src = common_getenv_nolock<char>(param_4);
    if (_Src != (char *)0x0) {
      pcVar4 = _Src;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      *param_1 = (uint)(pcVar4 + (1 - (int)(_Src + 1)));
      if (param_3 != 0) {
        if (param_3 < pcVar4 + (1 - (int)(_Src + 1))) {
          return 0x22;
        }
        eVar3 = _strcpy_s(param_2,param_3,_Src);
        if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
          __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
      }
    }
    return 0;
  }
  piVar2 = __errno();
  *piVar2 = 0x16;
  FUN_006e510d();
  return 0x16;
}

