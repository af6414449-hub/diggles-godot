
/* Library Function - Single Match
    __mbstowcs_s_l
   
   Library: Visual Studio 2019 Release */

errno_t __cdecl
__mbstowcs_s_l(size_t *_PtNumOfCharConverted,wchar_t *_DstBuf,size_t _SizeInWords,char *_SrcBuf,
              size_t _MaxCount,_locale_t _Locale)

{
  size_t sVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int local_14;
  __crt_locale_pointers local_10 [8];
  char local_8;
  
  iVar4 = 0;
  if (_DstBuf == (wchar_t *)0x0) {
    if (_SizeInWords != 0) {
LAB_006eb57b:
      piVar2 = __errno();
      *piVar2 = 0x16;
      FUN_006e510d();
      return 0x16;
    }
  }
  else if (_SizeInWords == 0) goto LAB_006eb57b;
  if (_DstBuf != (wchar_t *)0x0) {
    *_DstBuf = L'\0';
  }
  if (_PtNumOfCharConverted != (size_t *)0x0) {
    *_PtNumOfCharConverted = 0;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_14,(__crt_locale_pointers *)_Locale);
  sVar1 = _SizeInWords;
  if (_MaxCount <= _SizeInWords) {
    sVar1 = _MaxCount;
  }
  if (sVar1 < 0x80000000) {
    uVar3 = _mbstowcs_l_helper(_DstBuf,_SrcBuf,sVar1,local_10);
    if (uVar3 == 0xffffffff) {
      if (_DstBuf != (wchar_t *)0x0) {
        *_DstBuf = L'\0';
      }
      piVar2 = __errno();
      iVar4 = *piVar2;
      goto LAB_006eb5ee;
    }
    uVar3 = uVar3 + 1;
    if (_DstBuf != (wchar_t *)0x0) {
      if (_SizeInWords < uVar3) {
        if (_MaxCount != 0xffffffff) {
          *_DstBuf = L'\0';
          piVar2 = __errno();
          iVar4 = 0x22;
          goto LAB_006eb5cf;
        }
        iVar4 = 0x50;
        uVar3 = _SizeInWords;
      }
      _DstBuf[uVar3 - 1] = L'\0';
    }
    if (_PtNumOfCharConverted != (size_t *)0x0) {
      *_PtNumOfCharConverted = uVar3;
    }
  }
  else {
    piVar2 = __errno();
    iVar4 = 0x16;
LAB_006eb5cf:
    *piVar2 = iVar4;
    FUN_006e510d();
  }
LAB_006eb5ee:
  if (local_8 != '\0') {
    *(uint *)(local_14 + 0x350) = *(uint *)(local_14 + 0x350) & 0xfffffffd;
  }
  return iVar4;
}

