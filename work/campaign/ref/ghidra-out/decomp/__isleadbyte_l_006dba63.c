
/* Library Function - Single Match
    __isleadbyte_l
   
   Library: Visual Studio 2019 Release */

int __cdecl __isleadbyte_l(int _C,_locale_t _Locale)

{
  int iVar1;
  int local_14;
  undefined4 *local_10;
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,(__crt_locale_pointers *)_Locale);
  iVar1 = ___acrt_locale_get_ctype_array_value(*local_10,_C,0x8000);
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
  }
  return iVar1;
}

