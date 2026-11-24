
/* Library Function - Single Match
    __strupr_s_l
   
   Library: Visual Studio 2019 Release */

errno_t __cdecl __strupr_s_l(char *_Str,size_t _Size,_locale_t _Locale)

{
  int iVar1;
  int local_14;
  __crt_locale_pointers local_10 [8];
  char local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,(__crt_locale_pointers *)_Locale);
  iVar1 = _strupr_s_l_stat(_Str,_Size,local_10);
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
  }
  return iVar1;
}

