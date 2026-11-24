
/* Library Function - Single Match
    _fwrite
   
   Library: Visual Studio 2019 Release */

size_t __cdecl _fwrite(void *_Str,size_t _Size,size_t _Count,FILE *_File)

{
  int *piVar1;
  uint uVar2;
  FILE **local_20;
  void **local_1c;
  size_t *local_18;
  size_t *local_14;
  FILE *local_10;
  FILE *local_c;
  __crt_seh_guarded_call<unsigned_int> local_5;
  
  if ((_Size != 0) && (_Count != 0)) {
    if (_File != (FILE *)0x0) {
      local_20 = &_File;
      local_c = _File;
      local_1c = &_Str;
      local_10 = _File;
      local_18 = &_Size;
      local_14 = &_Count;
      uVar2 = __crt_seh_guarded_call<unsigned_int>::
              operator()<class_<lambda_4ac01c32aa5b53846f05d0620572872e>,class_<lambda_5856287d7ecd2be6c9197bb4007c3f6e>&,class_<lambda_e7a9868ed898c75c0f0637692d94351a>_>
                        (&local_5,(<lambda_4ac01c32aa5b53846f05d0620572872e> *)&local_10,
                         (<lambda_5856287d7ecd2be6c9197bb4007c3f6e> *)&local_20,
                         (<lambda_e7a9868ed898c75c0f0637692d94351a> *)&local_c);
      return uVar2;
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  return 0;
}

