
/* Library Function - Single Match
    _parse_bcp47_code_page
   
   Library: Visual Studio 2019 Release */

uint __cdecl parse_bcp47_code_page(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_2[2] != 2) {
    return (uint)param_2 & 0xffffff00;
  }
  iVar1 = FUN_006ed6af(param_1 + 0x100,0x10,*param_2,param_2[1]);
  if (iVar1 == 0) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
}

