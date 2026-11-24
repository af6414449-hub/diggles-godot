
/* Library Function - Single Match
    _wcscat_s
   
   Library: Visual Studio 2019 Release */

errno_t __cdecl _wcscat_s(wchar_t *_Dst,rsize_t _SizeInWords,wchar_t *_Src)

{
  wchar_t wVar1;
  int *piVar2;
  wchar_t *pwVar3;
  int iVar4;
  int iStack_14;
  
  if ((_Dst != (wchar_t *)0x0) && (_SizeInWords != 0)) {
    pwVar3 = _Dst;
    if (_Src != (wchar_t *)0x0) {
      do {
        if (*pwVar3 == L'\0') break;
        pwVar3 = pwVar3 + 1;
        _SizeInWords = _SizeInWords - 1;
      } while (_SizeInWords != 0);
      if (_SizeInWords != 0) {
        iVar4 = (int)_Src - (int)pwVar3;
        do {
          wVar1 = *(wchar_t *)(iVar4 + (int)pwVar3);
          *pwVar3 = wVar1;
          pwVar3 = pwVar3 + 1;
          if (wVar1 == L'\0') break;
          _SizeInWords = _SizeInWords - 1;
        } while (_SizeInWords != 0);
        if (_SizeInWords != 0) {
          return 0;
        }
        *_Dst = L'\0';
        piVar2 = __errno();
        iStack_14 = 0x22;
        goto LAB_006ed598;
      }
    }
    *_Dst = L'\0';
  }
  piVar2 = __errno();
  iStack_14 = 0x16;
LAB_006ed598:
  *piVar2 = iStack_14;
  FUN_006e510d();
  return iStack_14;
}

