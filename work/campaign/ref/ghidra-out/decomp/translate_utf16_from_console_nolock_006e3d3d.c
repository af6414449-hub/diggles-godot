
/* Library Function - Single Match
    int __cdecl translate_utf16_from_console_nolock(int,wchar_t * const,unsigned int)
   
   Library: Visual Studio 2019 Release */

int __cdecl translate_utf16_from_console_nolock(int param_1,wchar_t *param_2,uint param_3)

{
  wchar_t *pwVar1;
  byte *pbVar2;
  wchar_t wVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  int iStack_14;
  
  pwVar1 = param_2 + param_3;
  pwVar4 = param_2;
  pwVar5 = param_2;
  if (param_2 < pwVar1) {
    do {
      wVar3 = *pwVar4;
      if (wVar3 == L'\x1a') {
        pbVar2 = (byte *)((&DAT_00769d80)[param_1 >> 6] + 0x28 + (param_1 & 0x3fU) * 0x38);
        *pbVar2 = *pbVar2 | 2;
        break;
      }
      if (((wVar3 == L'\r') && (pwVar4 + 1 < pwVar1)) && (wVar3 = *pwVar4, pwVar4[1] == L'\n')) {
        wVar3 = L'\n';
        iStack_14 = 4;
      }
      else {
        iStack_14 = 2;
      }
      pwVar4 = (wchar_t *)((int)pwVar4 + iStack_14);
      *pwVar5 = wVar3;
      pwVar5 = pwVar5 + 1;
    } while (pwVar4 < pwVar1);
  }
  return (int)pwVar5 - (int)param_2 & 0xfffffffe;
}

