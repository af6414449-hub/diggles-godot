
/* Library Function - Single Match
    _call_wsetlocale
   
   Library: Visual Studio 2019 Release */

wchar_t * __cdecl call_wsetlocale(int param_1,char *param_2)

{
  wchar_t *pwVar1;
  errno_t eVar2;
  wchar_t *_DstBuf;
  size_t local_8;
  
  if (param_2 == (char *)0x0) {
    pwVar1 = __wsetlocale(param_1,(wchar_t *)0x0);
    return pwVar1;
  }
  pwVar1 = (wchar_t *)0x0;
  eVar2 = _mbstowcs_s(&local_8,(wchar_t *)0x0,0,param_2,0x7fffffff);
  if ((eVar2 != 0) && ((eVar2 == 0x16 || (eVar2 == 0x22)))) {
LAB_006df5ee:
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  _DstBuf = (wchar_t *)__calloc_base(local_8,2);
  if (_DstBuf != (wchar_t *)0x0) {
    eVar2 = _mbstowcs_s((size_t *)0x0,_DstBuf,local_8,param_2,0xffffffff);
    if (eVar2 == 0) {
      pwVar1 = __wsetlocale(param_1,_DstBuf);
    }
    else if ((eVar2 == 0x16) || (eVar2 == 0x22)) goto LAB_006df5ee;
  }
  FID_conflict__free(_DstBuf);
  return pwVar1;
}

