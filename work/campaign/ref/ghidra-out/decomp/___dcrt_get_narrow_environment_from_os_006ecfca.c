
/* Library Function - Single Match
    ___dcrt_get_narrow_environment_from_os
   
   Library: Visual Studio 2019 Release */

void * ___dcrt_get_narrow_environment_from_os(void)

{
  LPWCH pWVar1;
  wchar_t *pwVar2;
  int iVar3;
  void *_Memory;
  int iVar4;
  void *pvVar5;
  
  pWVar1 = GetEnvironmentStringsW();
  if (pWVar1 != (LPWCH)0x0) {
    pwVar2 = find_end_of_double_null_terminated_sequence(pWVar1);
    iVar4 = (int)pwVar2 - (int)pWVar1 >> 1;
    iVar3 = ___acrt_WideCharToMultiByte(0,0,pWVar1,iVar4,0,0,0,0);
    if (iVar3 != 0) {
      _Memory = (void *)__malloc_base(iVar3);
      if (_Memory == (void *)0x0) {
LAB_006ed02f:
        pvVar5 = (void *)0x0;
      }
      else {
        iVar3 = ___acrt_WideCharToMultiByte(0,0,pWVar1,iVar4,_Memory,iVar3,0,0);
        if (iVar3 == 0) goto LAB_006ed02f;
        pvVar5 = _Memory;
        _Memory = (void *)0x0;
      }
      FID_conflict__free(_Memory);
      goto LAB_006ed03c;
    }
  }
  pvVar5 = (void *)0x0;
LAB_006ed03c:
  if (pWVar1 != (LPWCH)0x0) {
    FreeEnvironmentStringsW(pWVar1);
  }
  return pvVar5;
}

