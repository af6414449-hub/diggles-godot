
/* Library Function - Single Match
    __isalpha_l
   
   Library: Visual Studio 2019 Release */

int __cdecl __isalpha_l(int _C,_locale_t _Locale)

{
  int iVar1;
  int local_14;
  undefined1 local_10 [8];
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,(__crt_locale_pointers *)_Locale);
  iVar1 = __ischartype_l(_C,0x103,local_10);
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
  }
  return iVar1;
}

