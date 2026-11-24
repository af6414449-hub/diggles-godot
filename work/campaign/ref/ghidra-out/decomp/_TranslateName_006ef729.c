
/* Library Function - Single Match
    _TranslateName
   
   Library: Visual Studio 2019 Release */

uint _TranslateName(int param_1,int param_2,int *param_3)

{
  uint in_EAX;
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (-1 < param_2) {
    do {
      iVar1 = (iVar2 + param_2) / 2;
      in_EAX = __wcsicmp((wchar_t *)*param_3,*(wchar_t **)(iVar1 * 0xc + param_1));
      if (in_EAX == 0) {
        param_1 = param_1 + iVar1 * 0xc + 4;
        *param_3 = param_1;
        return CONCAT31((int3)((uint)param_1 >> 8),1);
      }
      if ((int)in_EAX < 0) {
        param_2 = iVar1 + -1;
      }
      else {
        iVar2 = iVar1 + 1;
      }
    } while (iVar2 <= param_2);
  }
  return in_EAX & 0xffffff00;
}

