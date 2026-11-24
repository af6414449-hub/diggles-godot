
/* Library Function - Single Match
    ___lc_wcstolc
   
   Library: Visual Studio 2019 Release */

undefined4 ___lc_wcstolc(void *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_8;
  
  _memset(param_1,0,0x1ca);
  if (*param_2 != L'\0') {
    if ((*param_2 != L'.') || (param_2[1] == L'\0')) {
      local_8 = 0;
      uVar3 = _wcscspn(param_2,L"_.,");
      do {
        if (uVar3 == 0) {
          return 0xffffffff;
        }
        wVar1 = param_2[uVar3];
        if (local_8 == 0) {
          if (0x3f < uVar3) {
            return 0xffffffff;
          }
          iVar2 = FUN_006ed6af(param_1,0x40,param_2,uVar3);
          if (iVar2 != 0) goto LAB_006e1f59;
          if (wVar1 == L'.') {
            local_8 = 1;
          }
        }
        else {
          if (local_8 == 1) {
            if (0x3f < uVar3) {
              return 0xffffffff;
            }
            if (wVar1 == L'_') {
              return 0xffffffff;
            }
            uVar4 = 0x40;
            iVar2 = (int)param_1 + 0x80;
          }
          else {
            if (local_8 != 2) {
              return 0xffffffff;
            }
            if (0xf < uVar3) {
              return 0xffffffff;
            }
            if ((wVar1 != L'\0') && (wVar1 != L',')) {
              return 0xffffffff;
            }
            uVar4 = 0x10;
            iVar2 = (int)param_1 + 0x100;
          }
          iVar2 = FUN_006ed6af(iVar2,uVar4,param_2,uVar3);
          if (iVar2 != 0) goto LAB_006e1f59;
        }
        if (wVar1 == L',') {
          return 0;
        }
        if (wVar1 == L'\0') {
          return 0;
        }
        param_2 = param_2 + uVar3 + 1;
        local_8 = local_8 + 1;
        uVar3 = _wcscspn(param_2,L"_.,");
      } while( true );
    }
    iVar2 = FUN_006ed6af((int)param_1 + 0x100,0x10,param_2 + 1,0xf);
    if (iVar2 != 0) {
LAB_006e1f59:
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    *(undefined2 *)((int)param_1 + 0x11e) = 0;
  }
  return 0;
}

