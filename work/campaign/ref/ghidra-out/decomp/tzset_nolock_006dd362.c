
/* Library Function - Single Match
    void __cdecl tzset_nolock(void)
   
   Library: Visual Studio 2019 Release */

void __cdecl tzset_nolock(void)

{
  int iVar1;
  char *_Memory;
  undefined1 local_110 [4];
  undefined4 local_10c;
  char local_108 [256];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  DAT_007670f4 = 0xffffffff;
  DAT_007670e8 = 0xffffffff;
  DAT_00769b60 = 0;
  iVar1 = FUN_006e9892(&local_10c,local_108,0x100,&DAT_00716f3c);
  if (iVar1 == 0) {
    _Memory = local_108;
  }
  else {
    _Memory = (char *)0x0;
    if (iVar1 == 0x22) {
      _Memory = (char *)__malloc_base(local_10c);
      if (_Memory == (char *)0x0) {
        _Memory = (char *)0x0;
      }
      else {
        iVar1 = FUN_006e9892(local_110,_Memory,local_10c,&DAT_00716f3c);
        if (iVar1 == 0) {
          FID_conflict__free((void *)0x0);
          goto LAB_006dd403;
        }
      }
      FID_conflict__free(_Memory);
      _Memory = (char *)0x0;
    }
  }
LAB_006dd403:
  if ((_Memory == (char *)0x0) || (*_Memory == '\0')) {
    tzset_from_system_nolock();
  }
  else {
    tzset_from_environment_nolock(_Memory);
  }
  FID_conflict__free((void *)(-(uint)(_Memory != local_108) & (uint)_Memory));
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

