
/* Library Function - Single Match
    __strcoll_l
   
   Library: Visual Studio 2019 Release */

int __cdecl __strcoll_l(char *_Str1,char *_Str2,_locale_t _Locale)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  int local_14;
  int local_10 [2];
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,(__crt_locale_pointers *)_Locale);
  if ((_Str1 == (char *)0x0) || (_Str2 == (char *)0x0)) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
  }
  else {
    if (*(int *)(local_10[0] + 0xa4) == 0) {
      do {
        bVar1 = *_Str1;
        bVar5 = bVar1 < (byte)*_Str2;
        if (bVar1 != *_Str2) {
LAB_006df701:
          uVar4 = -(uint)bVar5 | 1;
          goto LAB_006df73c;
        }
        if (bVar1 == 0) break;
        bVar1 = ((byte *)_Str1)[1];
        bVar5 = bVar1 < ((byte *)_Str2)[1];
        if (bVar1 != ((byte *)_Str2)[1]) goto LAB_006df701;
        _Str1 = (char *)((byte *)_Str1 + 2);
        _Str2 = (char *)((byte *)_Str2 + 2);
      } while (bVar1 != 0);
      uVar4 = 0;
      goto LAB_006df73c;
    }
    iVar3 = ___acrt_CompareStringA
                      (local_10,*(int *)(local_10[0] + 0xa4),0x1000,_Str1,0xffffffff,_Str2,
                       0xffffffff,*(undefined4 *)(local_10[0] + 0x10));
    if (iVar3 != 0) {
      uVar4 = iVar3 - 2;
      goto LAB_006df73c;
    }
    piVar2 = __errno();
    *piVar2 = 0x16;
  }
  uVar4 = 0x7fffffff;
LAB_006df73c:
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
  }
  return uVar4;
}

