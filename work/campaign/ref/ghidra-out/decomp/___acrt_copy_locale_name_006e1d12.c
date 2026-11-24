
/* Library Function - Single Match
    ___acrt_copy_locale_name
   
   Library: Visual Studio 2019 Release */

int ___acrt_copy_locale_name(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (((param_1 == 0) || (uVar1 = FUN_006e5dfa(param_1,0x55), 0x54 < uVar1)) ||
     (iVar2 = __malloc_base(uVar1 * 2 + 2), iVar2 == 0)) {
    iVar2 = 0;
  }
  else {
    iVar3 = FUN_006ed6af(iVar2,uVar1 + 1,param_1,uVar1 + 1);
    if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
  }
  return iVar2;
}

