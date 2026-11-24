
/* Library Function - Single Match
    int __cdecl common_tcsncat_s<wchar_t>(wchar_t * const,unsigned int,wchar_t const *
   const,unsigned int)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_tcsncat_s<wchar_t>(wchar_t *param_1,uint param_2,wchar_t *param_3,uint param_4)

{
  wchar_t wVar1;
  int *piVar2;
  uint uVar3;
  wchar_t *pwVar4;
  int iVar5;
  uint uVar6;
  int iStack_18;
  
  if (param_4 == 0) {
    if (param_1 == (wchar_t *)0x0) {
      if (param_2 == 0) {
        return 0;
      }
    }
    else {
LAB_006ee21e:
      if (param_2 != 0) {
        pwVar4 = param_1;
        uVar6 = param_2;
        if ((param_4 == 0) || (param_3 != (wchar_t *)0x0)) {
          do {
            if (*pwVar4 == L'\0') break;
            pwVar4 = pwVar4 + 1;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
          if (uVar6 != 0) {
            if (param_4 == 0xffffffff) {
              iVar5 = (int)param_3 - (int)pwVar4;
              do {
                wVar1 = *(wchar_t *)(iVar5 + (int)pwVar4);
                *pwVar4 = wVar1;
                pwVar4 = pwVar4 + 1;
                if (wVar1 == L'\0') break;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
            }
            else {
              uVar3 = param_4;
              if (param_4 != 0) {
                do {
                  wVar1 = *param_3;
                  param_3 = param_3 + 1;
                  *pwVar4 = wVar1;
                  pwVar4 = pwVar4 + 1;
                  if ((wVar1 == L'\0') || (uVar6 = uVar6 - 1, uVar6 == 0)) break;
                  uVar3 = uVar3 - 1;
                } while (uVar3 != 0);
              }
              if (uVar3 == 0) {
                *pwVar4 = L'\0';
              }
            }
            if (uVar6 != 0) {
              return 0;
            }
            if (param_4 == 0xffffffff) {
              param_1[param_2 - 1] = L'\0';
              return 0x50;
            }
            *param_1 = L'\0';
            piVar2 = __errno();
            iStack_18 = 0x22;
            goto LAB_006ee23c;
          }
        }
        *param_1 = L'\0';
      }
    }
  }
  else if (param_1 != (wchar_t *)0x0) goto LAB_006ee21e;
  piVar2 = __errno();
  iStack_18 = 0x16;
LAB_006ee23c:
  *piVar2 = iStack_18;
  FUN_006e510d();
  return iStack_18;
}

