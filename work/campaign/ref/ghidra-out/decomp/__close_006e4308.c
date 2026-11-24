
/* Library Function - Single Match
    __close
   
   Library: Visual Studio 2019 Release */

int __cdecl __close(int _FileHandle)

{
  ulong *puVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  int local_c;
  __crt_seh_guarded_call<int> local_5;
  
  if (_FileHandle == -2) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
  }
  else {
    if (((-1 < _FileHandle) && ((uint)_FileHandle < DAT_00769f80)) &&
       ((*(byte *)((&DAT_00769d80)[_FileHandle >> 6] + 0x28 + (_FileHandle & 0x3fU) * 0x38) & 1) !=
        0)) {
      local_10 = &_FileHandle;
      local_c = _FileHandle;
      local_14 = _FileHandle;
      iVar3 = __crt_seh_guarded_call<int>::
              operator()<class_<lambda_218ce3db14220d0be481dae8ef3383b6>,class_<lambda_628dfdc04ba53c8bfc02c9951375f3f5>&,class_<lambda_57dc472bd5c9d5f3b2cbca59b8a843ae>_>
                        (&local_5,(<lambda_218ce3db14220d0be481dae8ef3383b6> *)&local_14,
                         (<lambda_628dfdc04ba53c8bfc02c9951375f3f5> *)&local_10,
                         (<lambda_57dc472bd5c9d5f3b2cbca59b8a843ae> *)&local_c);
      return iVar3;
    }
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 9;
    FUN_006e510d();
  }
  return -1;
}

