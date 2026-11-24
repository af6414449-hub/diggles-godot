
/* Library Function - Single Match
    ___acrt_getptd_noexit
   
   Library: Visual Studio 2019 Release */

uint ___acrt_getptd_noexit(void)

{
  DWORD dwErrCode;
  __acrt_ptd *_Memory;
  int iVar1;
  
  dwErrCode = GetLastError();
  if ((DAT_00767214 == -1) ||
     (_Memory = (__acrt_ptd *)___acrt_FlsGetValue_4(DAT_00767214), _Memory == (__acrt_ptd *)0x0)) {
    iVar1 = ___acrt_FlsSetValue_8(DAT_00767214,0xffffffff);
    if (iVar1 != 0) {
      _Memory = (__acrt_ptd *)__calloc_base(1,0x364);
      if (_Memory == (__acrt_ptd *)0x0) {
        ___acrt_FlsSetValue_8(DAT_00767214,0);
        _Memory = (__acrt_ptd *)0x0;
      }
      else {
        iVar1 = ___acrt_FlsSetValue_8(DAT_00767214,_Memory);
        if (iVar1 != 0) {
          construct_ptd(_Memory,(__crt_locale_data **)&DAT_00769d78);
          FID_conflict__free((void *)0x0);
          goto LAB_006e64e2;
        }
        ___acrt_FlsSetValue_8(DAT_00767214,0);
      }
      FID_conflict__free(_Memory);
    }
  }
  else if (_Memory != (__acrt_ptd *)0xffffffff) goto LAB_006e64e2;
  _Memory = (__acrt_ptd *)0x0;
LAB_006e64e2:
  SetLastError(dwErrCode);
  return -(uint)(_Memory != (__acrt_ptd *)0x0) & (uint)_Memory;
}

