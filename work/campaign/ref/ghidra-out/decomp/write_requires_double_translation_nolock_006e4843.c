
/* Library Function - Single Match
    bool __cdecl write_requires_double_translation_nolock(int)
   
   Library: Visual Studio 2019 Release */

bool __cdecl write_requires_double_translation_nolock(int param_1)

{
  int iVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  DWORD local_8;
  
  iVar1 = __isatty(param_1);
  if (iVar1 != 0) {
    iVar4 = param_1 >> 6;
    iVar1 = (param_1 & 0x3fU) * 0x38;
    if ((*(char *)((&DAT_00769d80)[iVar4] + 0x28 + iVar1) < '\0') &&
       (((iVar2 = ___acrt_getptd(), *(int *)(*(int *)(iVar2 + 0x4c) + 0xa8) != 0 ||
         (*(char *)((&DAT_00769d80)[iVar4] + 0x29 + iVar1) != '\0')) &&
        (BVar3 = GetConsoleMode(*(HANDLE *)((&DAT_00769d80)[iVar4] + 0x18 + iVar1),&local_8),
        BVar3 != 0)))) {
      return true;
    }
  }
  return false;
}

