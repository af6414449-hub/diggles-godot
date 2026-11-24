
/* Library Function - Single Match
    __wcscats
   
   Library: Visual Studio 2019 Release */

void __wcscats(wchar_t *param_1,rsize_t param_2,int param_3)

{
  errno_t eVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  if (0 < param_3) {
    puVar3 = &param_3;
    do {
      puVar3 = puVar3 + 1;
      eVar1 = _wcscat_s(param_1,param_2,(wchar_t *)*puVar3);
      if (eVar1 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  return;
}

