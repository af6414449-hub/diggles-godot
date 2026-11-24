
/* Library Function - Single Match
    int __cdecl GetTableIndexFromLocaleName(wchar_t const *)
   
   Library: Visual Studio 2019 Release */

int __cdecl GetTableIndexFromLocaleName(wchar_t *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = 0xe3;
  do {
    iVar3 = (iVar2 + iVar4) / 2;
    iVar1 = ___ascii_wcsnicmp(param_1,*(undefined4 *)(&UNK_0071ade8 + iVar3 * 8),0x55);
    if (iVar1 == 0) {
      return *(int *)(&UNK_0071adec + iVar3 * 8);
    }
    if (iVar1 < 0) {
      iVar2 = iVar3 + -1;
    }
    else {
      iVar4 = iVar3 + 1;
    }
  } while (iVar4 <= iVar2);
  return -1;
}

