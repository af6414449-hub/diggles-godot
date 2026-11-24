
/* Library Function - Single Match
    __wctomb_s_l
   
   Library: Visual Studio 2019 Release */

errno_t __cdecl
__wctomb_s_l(int *_SizeConverted,char *_MbCh,size_t _SizeInBytes,wchar_t _WCh,_locale_t _Locale)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  DWORD DVar4;
  int iVar5;
  int local_1c;
  int local_18;
  char local_10;
  undefined4 local_c;
  int local_8;
  
  if ((_MbCh == (char *)0x0) && (_SizeInBytes != 0)) {
    if (_SizeConverted != (int *)0x0) {
      *_SizeConverted = 0;
    }
    return 0;
  }
  if (_SizeConverted != (int *)0x0) {
    *_SizeConverted = -1;
  }
  if (0x7fffffff < _SizeInBytes) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    return 0x16;
  }
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_1c,(__crt_locale_pointers *)_Locale);
  iVar5 = 0;
  if (*(int *)(local_18 + 8) == 0xfde9) {
    local_c = 0;
    local_8 = 0;
    uVar2 = __crt_mbstring::__c32rtomb_utf8(_MbCh,(uint)(ushort)_WCh,(_Mbstatet *)&local_c);
    if (_SizeConverted != (int *)0x0) {
      *_SizeConverted = uVar2;
    }
    if (4 < (int)uVar2) {
      piVar1 = __errno();
      iVar5 = *piVar1;
    }
    goto LAB_006e5c2b;
  }
  if (*(int *)(local_18 + 0xa8) == 0) {
    if ((ushort)_WCh < 0x100) {
      if (_MbCh != (char *)0x0) {
        if (_SizeInBytes == 0) goto LAB_006e5ca7;
        *_MbCh = (char)_WCh;
      }
      if (_SizeConverted != (int *)0x0) {
        *_SizeConverted = 1;
      }
      goto LAB_006e5c2b;
    }
    if ((_MbCh != (char *)0x0) && (_SizeInBytes != 0)) {
      _memset(_MbCh,0,_SizeInBytes);
    }
  }
  else {
    local_8 = 0;
    iVar3 = ___acrt_WideCharToMultiByte
                      (*(int *)(local_18 + 8),0,&_WCh,1,_MbCh,_SizeInBytes,0,&local_8);
    if (iVar3 == 0) {
      DVar4 = GetLastError();
      if (DVar4 == 0x7a) {
        if ((_MbCh != (char *)0x0) && (_SizeInBytes != 0)) {
          _memset(_MbCh,0,_SizeInBytes);
        }
LAB_006e5ca7:
        piVar1 = __errno();
        iVar5 = 0x22;
        *piVar1 = 0x22;
        FUN_006e510d();
        goto LAB_006e5c2b;
      }
    }
    else if (local_8 == 0) {
      if (_SizeConverted != (int *)0x0) {
        *_SizeConverted = iVar3;
      }
      goto LAB_006e5c2b;
    }
  }
  piVar1 = __errno();
  iVar5 = 0x2a;
  *piVar1 = 0x2a;
LAB_006e5c2b:
  if (local_10 != '\0') {
    *(uint *)(local_1c + 0x350) = *(uint *)(local_1c + 0x350) & 0xfffffffd;
  }
  return iVar5;
}

