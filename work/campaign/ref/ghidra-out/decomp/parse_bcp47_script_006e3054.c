
/* Library Function - Single Match
    _parse_bcp47_script
   
   Library: Visual Studio 2019 Release */

uint __cdecl parse_bcp47_script(int param_1,undefined4 *param_2)

{
  uint in_EAX;
  int iVar1;
  
  if (((param_2[2] == 0) && (param_2[1] == 4)) &&
     (in_EAX = string_is_alpha(*param_2,4), (char)in_EAX != '\0')) {
    iVar1 = FUN_006ee2e1(param_1 + 0x120,0x55,&DAT_0071735c,1);
    if ((iVar1 == 0) && (iVar1 = FUN_006ee2e1(param_1 + 0x120,0x55,*param_2,param_2[1]), iVar1 == 0)
       ) {
      return 1;
    }
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  return in_EAX & 0xffffff00;
}

