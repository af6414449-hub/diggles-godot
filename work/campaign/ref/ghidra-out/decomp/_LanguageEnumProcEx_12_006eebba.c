
/* Library Function - Single Match
    _LanguageEnumProcEx@12
   
   Library: Visual Studio 2019 Release */

void _LanguageEnumProcEx_12(short *param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  wchar_t local_f8 [120];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  iVar2 = ___acrt_getptd();
  iVar3 = ___acrt_GetLocaleInfoEx_16
                    (param_1,(-(uint)(*(int *)(iVar2 + 0x60) != 0) & 0xfffff002) + 0x1001,local_f8,
                     0x78);
  if (iVar3 == 0) {
    *(undefined4 *)(iVar2 + 0x58) = 0;
  }
  else {
    iVar3 = __wcsicmp(*(wchar_t **)(iVar2 + 0x50),local_f8);
    if (iVar3 == 0) {
      psVar4 = param_1;
      do {
        sVar1 = *psVar4;
        psVar4 = psVar4 + 1;
      } while (sVar1 != 0);
      iVar3 = FUN_006ed6af(iVar2 + 0x2a0,0x55,param_1,((int)psVar4 - (int)(param_1 + 1) >> 1) + 1);
      if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
        __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
      }
      *(uint *)(iVar2 + 0x58) = *(uint *)(iVar2 + 0x58) | 4;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

