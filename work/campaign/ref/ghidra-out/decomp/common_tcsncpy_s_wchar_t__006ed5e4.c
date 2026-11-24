
/* Library Function - Single Match
    int __cdecl common_tcsncpy_s<wchar_t>(wchar_t * const,unsigned int,wchar_t const *
   const,unsigned int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl common_tcsncpy_s<wchar_t>(wchar_t *param_1,uint param_2,wchar_t *param_3,uint param_4)

{
  wchar_t wVar1;
  int *piVar2;
  uint uVar3;
  wchar_t *pwVar4;
  uint uVar5;
  int iVar6;
  
  if (param_4 == 0) {
    if (param_1 == (wchar_t *)0x0) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
LAB_006ed61a:
      if (param_2 != 0) {
        if (param_4 == 0) {
          *param_1 = L'\0';
          return 0;
        }
        if (param_3 != (wchar_t *)0x0) {
          uVar3 = param_4;
          pwVar4 = param_1;
          uVar5 = param_2;
          if (param_4 == 0xffffffff) {
            do {
              wVar1 = *(wchar_t *)(((int)param_3 - (int)param_1) + (int)pwVar4);
              *pwVar4 = wVar1;
              pwVar4 = pwVar4 + 1;
              if (wVar1 == L'\0') break;
              uVar5 = uVar5 - 1;
            } while (uVar5 != 0);
          }
          else {
            do {
              wVar1 = *(wchar_t *)(((int)param_3 - (int)param_1) + (int)pwVar4);
              *pwVar4 = wVar1;
              pwVar4 = pwVar4 + 1;
              if ((wVar1 == L'\0') || (uVar5 = uVar5 - 1, uVar5 == 0)) break;
              uVar3 = uVar3 - 1;
            } while (uVar3 != 0);
            if (uVar3 == 0) {
              *pwVar4 = L'\0';
            }
          }
          if (uVar5 != 0) {
            return 0;
          }
          if (param_4 == 0xffffffff) {
            param_1[param_2 - 1] = L'\0';
            return 0x50;
          }
          *param_1 = L'\0';
          piVar2 = __errno();
          iVar6 = 0x22;
          goto LAB_006ed608;
        }
        *param_1 = L'\0';
      }
    }
  }
  else if (param_1 != (wchar_t *)0x0) goto LAB_006ed61a;
  piVar2 = __errno();
  iVar6 = 0x16;
LAB_006ed608:
  *piVar2 = iVar6;
  FUN_006e510d();
  return iVar6;
}

