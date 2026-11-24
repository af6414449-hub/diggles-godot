
/* Library Function - Single Match
    __commit
   
   Library: Visual Studio 2019 Release */

int __cdecl __commit(int _FileHandle)

{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  int local_c;
  __crt_seh_guarded_call<int> local_5;
  
  if (_FileHandle == -2) {
    piVar1 = __errno();
    *piVar1 = 9;
  }
  else {
    if (((-1 < _FileHandle) && ((uint)_FileHandle < DAT_00769f80)) &&
       ((*(byte *)((&DAT_00769d80)[_FileHandle >> 6] + 0x28 + (_FileHandle & 0x3fU) * 0x38) & 1) !=
        0)) {
      local_10 = &_FileHandle;
      local_c = _FileHandle;
      local_14 = _FileHandle;
      iVar2 = __crt_seh_guarded_call<int>::
              operator()<class_<lambda_9e9de3de5fa147e2223d7db92bc10aa6>,class_<lambda_38ce7e780aa69e748d6df282ebc68efe>&,class_<lambda_8ca6da459f0f6780f1cff60fdc3d00e5>_>
                        (&local_5,(<lambda_9e9de3de5fa147e2223d7db92bc10aa6> *)&local_14,
                         (<lambda_38ce7e780aa69e748d6df282ebc68efe> *)&local_10,
                         (<lambda_8ca6da459f0f6780f1cff60fdc3d00e5> *)&local_c);
      return iVar2;
    }
    piVar1 = __errno();
    *piVar1 = 9;
    FUN_006e510d();
  }
  return -1;
}

