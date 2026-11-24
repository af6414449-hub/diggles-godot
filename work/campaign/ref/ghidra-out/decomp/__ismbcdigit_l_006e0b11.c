
/* Library Function - Single Match
    __ismbcdigit_l
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

int __cdecl __ismbcdigit_l(uint _Ch,_locale_t _Locale)

{
  uint uVar1;
  int local_14;
  int *local_10 [2];
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,(__crt_locale_pointers *)_Locale);
  if (_Ch < 0x100) {
    uVar1 = *(ushort *)(*local_10[0] + (_Ch & 0xff) * 2) & 4;
  }
  else {
    uVar1 = ___dcrt_multibyte_check_type(_Ch,local_10,4,1);
  }
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
  }
  return uVar1;
}

