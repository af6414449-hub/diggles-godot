
/* Library Function - Single Match
    ___lc_lctowcs
   
   Library: Visual Studio 2019 Release */

void ___lc_lctowcs(wchar_t *param_1,rsize_t param_2,wchar_t *param_3)

{
  errno_t eVar1;
  
  eVar1 = _wcscpy_s(param_1,param_2,param_3);
  if (eVar1 == 0) {
    if (param_3[0x40] != L'\0') {
      __wcscats(param_1,param_2,2,&DAT_00717374,param_3 + 0x40);
    }
    if (param_3[0x80] != L'\0') {
      __wcscats(param_1,param_2,2,&DAT_00717378,param_3 + 0x80);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
}

