
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    __mbtowc_l
   
   Library: Visual Studio 2019 Release */

int __cdecl __mbtowc_l(wchar_t *_DstCh,char *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int local_14;
  localeinfo_struct local_10;
  char local_8;
  
  if ((_SrcCh == (char *)0x0) || (_SrcSizeInBytes == 0)) {
    _DAT_00769d68 = 0;
    _DAT_00769d64 = 0;
    return 0;
  }
  if (*_SrcCh == '\0') {
    if (_DstCh == (wchar_t *)0x0) {
      return 0;
    }
    *_DstCh = L'\0';
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,(__crt_locale_pointers *)_Locale);
  if ((local_10.locinfo)->lc_collate_cp == 0xfde9) {
    uVar1 = __crt_mbstring::__mbrtowc_utf8(_DstCh,_SrcCh,_SrcSizeInBytes,(_Mbstatet *)&DAT_00769d64)
    ;
    if (-1 < (int)uVar1) goto LAB_006e5b1d;
  }
  else {
    if ((local_10.locinfo)->locale_name[2] == (wchar_t *)0x0) {
      if (_DstCh != (wchar_t *)0x0) {
        *_DstCh = (ushort)(byte)*_SrcCh;
      }
      uVar1 = 1;
      goto LAB_006e5b1d;
    }
    iVar2 = __isleadbyte_l((uint)(byte)*_SrcCh,&local_10);
    if (iVar2 != 0) {
      if ((int)(local_10.locinfo)->lc_codepage < 2) {
LAB_006e5ada:
        uVar1 = (local_10.locinfo)->lc_codepage;
LAB_006e5add:
        if ((_SrcSizeInBytes < uVar1) || (_SrcCh[1] == '\0')) goto LAB_006e5b0f;
      }
      else {
        uVar1 = (local_10.locinfo)->lc_codepage;
        if ((int)_SrcSizeInBytes < (int)uVar1) goto LAB_006e5add;
        iVar2 = ___acrt_MultiByteToWideChar
                          ((local_10.locinfo)->lc_collate_cp,9,_SrcCh,
                           (local_10.locinfo)->lc_codepage,_DstCh,_DstCh != (wchar_t *)0x0);
        if (iVar2 == 0) goto LAB_006e5ada;
      }
      uVar1 = (local_10.locinfo)->lc_codepage;
      goto LAB_006e5b1d;
    }
    uVar1 = 1;
    iVar2 = ___acrt_MultiByteToWideChar
                      ((local_10.locinfo)->lc_collate_cp,9,_SrcCh,1,_DstCh,_DstCh != (wchar_t *)0x0)
    ;
    if (iVar2 != 0) goto LAB_006e5b1d;
LAB_006e5b0f:
    piVar3 = __errno();
    *piVar3 = 0x2a;
  }
  uVar1 = 0xffffffff;
LAB_006e5b1d:
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
    return uVar1;
  }
  return uVar1;
}

