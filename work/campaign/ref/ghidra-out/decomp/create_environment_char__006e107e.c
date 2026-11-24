
/* Library Function - Single Match
    char * * __cdecl create_environment<char>(char * const)
   
   Library: Visual Studio 2019 Release */

char ** __cdecl create_environment<char>(char *param_1)

{
  char cVar1;
  char **ppcVar2;
  char *_Dst;
  errno_t eVar3;
  char *pcVar4;
  int iVar5;
  char **local_8;
  
  iVar5 = 0;
  cVar1 = *param_1;
  pcVar4 = param_1;
  while (cVar1 != '\0') {
    if (cVar1 != '=') {
      iVar5 = iVar5 + 1;
    }
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    cVar1 = *pcVar4;
  }
  ppcVar2 = (char **)__calloc_base(iVar5 + 1,4);
  local_8 = ppcVar2;
  if (ppcVar2 == (char **)0x0) {
LAB_006e1130:
    ppcVar2 = (char **)0x0;
  }
  else {
    for (; *param_1 != '\0'; param_1 = param_1 + (int)pcVar4) {
      pcVar4 = param_1;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      pcVar4 = pcVar4 + (1 - (int)(param_1 + 1));
      if (*param_1 != '=') {
        _Dst = (char *)__calloc_base(pcVar4,1);
        if (_Dst == (char *)0x0) {
          free_environment<char>(ppcVar2);
          FID_conflict__free((void *)0x0);
          goto LAB_006e1130;
        }
        eVar3 = _strcpy_s(_Dst,(rsize_t)pcVar4,param_1);
        if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
          __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        *local_8 = _Dst;
        local_8 = local_8 + 1;
        FID_conflict__free((void *)0x0);
      }
    }
  }
  FID_conflict__free((void *)0x0);
  return ppcVar2;
}

