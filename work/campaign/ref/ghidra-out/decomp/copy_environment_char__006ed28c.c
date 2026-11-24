
/* Library Function - Single Match
    char * * __cdecl copy_environment<char>(char * * const)
   
   Library: Visual Studio 2019 Release */

char ** __cdecl copy_environment<char>(char **param_1)

{
  char *pcVar1;
  char cVar2;
  char **ppcVar3;
  undefined4 uVar4;
  errno_t eVar5;
  int iVar6;
  char *pcVar7;
  
  if (param_1 == (char **)0x0) {
    ppcVar3 = (char **)0x0;
  }
  else {
    iVar6 = 0;
    pcVar7 = *param_1;
    ppcVar3 = param_1;
    while (pcVar7 != (char *)0x0) {
      ppcVar3 = ppcVar3 + 1;
      iVar6 = iVar6 + 1;
      pcVar7 = *ppcVar3;
    }
    ppcVar3 = (char **)__calloc_base(iVar6 + 1,4);
    if (ppcVar3 == (char **)0x0) {
LAB_006ed32a:
                    /* WARNING: Subroutine does not return */
      _abort();
    }
    pcVar7 = *param_1;
    if (pcVar7 != (char *)0x0) {
      iVar6 = (int)ppcVar3 - (int)param_1;
      do {
        pcVar1 = pcVar7 + 1;
        do {
          cVar2 = *pcVar7;
          pcVar7 = pcVar7 + 1;
        } while (cVar2 != '\0');
        uVar4 = __calloc_base(pcVar7 + (1 - (int)pcVar1),1);
        *(undefined4 *)(iVar6 + (int)param_1) = uVar4;
        FID_conflict__free((void *)0x0);
        if (*(int *)(iVar6 + (int)param_1) == 0) goto LAB_006ed32a;
        eVar5 = _strcpy_s(*(char **)(iVar6 + (int)param_1),(rsize_t)(pcVar7 + (1 - (int)pcVar1)),
                          *param_1);
        if (eVar5 != 0) {
                    /* WARNING: Subroutine does not return */
          __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
        }
        param_1 = param_1 + 1;
        pcVar7 = *param_1;
      } while (pcVar7 != (char *)0x0);
    }
    FID_conflict__free((void *)0x0);
  }
  return ppcVar3;
}

