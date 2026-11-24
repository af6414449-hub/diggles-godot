
/* Library Function - Single Match
    __stricmp_l
   
   Library: Visual Studio 2019 Release */

int __cdecl __stricmp_l(char *_Str1,char *_Str2,_locale_t _Locale)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  int local_10;
  char local_8;
  
  if (_Str1 == (char *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    iVar3 = 0x7fffffff;
  }
  else if (_Str2 == (char *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    iVar3 = 0x7fffffff;
  }
  else {
    _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,(__crt_locale_pointers *)_Locale);
    do {
      bVar1 = *_Str1;
      _Str1 = (char *)((byte *)_Str1 + 1);
      uVar4 = (uint)*(byte *)((uint)bVar1 + *(int *)(local_10 + 0x94));
      bVar1 = *_Str2;
      _Str2 = (char *)((byte *)_Str2 + 1);
      iVar3 = uVar4 - *(byte *)((uint)bVar1 + *(int *)(local_10 + 0x94));
      if (iVar3 != 0) break;
    } while (uVar4 != 0);
    if (local_8 != '\0') {
      *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
    }
  }
  return iVar3;
}

