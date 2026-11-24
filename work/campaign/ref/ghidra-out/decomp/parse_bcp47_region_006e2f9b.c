
/* Library Function - Single Match
    _parse_bcp47_region
   
   Library: Visual Studio 2019 Release */

uint __cdecl parse_bcp47_region(int param_1,int *param_2)

{
  uint in_EAX;
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  if (param_2[2] == 0) {
    if ((param_2[1] != 2) || (in_EAX = string_is_alpha(*param_2,2), (char)in_EAX == '\0')) {
      if (param_2[1] != 3) goto LAB_006e3042;
      iVar3 = *param_2;
      uVar4 = 0;
      do {
        uVar1 = (uint)*(ushort *)(iVar3 + uVar4 * 2);
        uVar5 = 4;
        puVar2 = ___pctype_func();
        in_EAX = ___acrt_locale_get_ctype_array_value(puVar2,uVar1,uVar5);
        if (in_EAX == 0) goto LAB_006e3042;
        uVar4 = uVar4 + 1;
      } while (uVar4 < 3);
    }
    iVar3 = FUN_006ed6af(param_1 + 0x80,0x40,*param_2,param_2[1]);
    if (iVar3 == 0) {
      iVar3 = FUN_006ee2e1(param_1 + 0x120,0x55,&DAT_0071735c,1);
      if ((iVar3 == 0) &&
         (iVar3 = FUN_006ee2e1(param_1 + 0x120,0x55,*param_2,param_2[1]), iVar3 == 0)) {
        return 1;
      }
    }
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
LAB_006e3042:
  return in_EAX & 0xffffff00;
}

