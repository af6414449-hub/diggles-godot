
/* Library Function - Single Match
    _fflush
   
   Library: Visual Studio 2019 Release */

int __cdecl _fflush(FILE *_File)

{
  bool bVar1;
  int iVar2;
  FILE *local_18;
  FILE **local_14;
  FILE *local_10;
  FILE *local_c;
  __crt_seh_guarded_call<int> local_5;
  
  local_c = _File;
  if (_File == (FILE *)0x0) {
    iVar2 = common_flush_all(false);
    return iVar2;
  }
  bVar1 = is_stream_flushable_or_commitable(_File->_flag);
  if (!bVar1) {
    return 0;
  }
  local_14 = &local_c;
  local_10 = local_c;
  local_18 = local_c;
  iVar2 = __crt_seh_guarded_call<int>::
          operator()<class_<lambda_6d20deecaf4856105ebacbad442d1079>,class_<lambda_9a32fed5bf61b6b509b2d3f6003082a1>&,class_<lambda_63ea2239ed67c638ddbae41947fdf875>_>
                    (&local_5,(<lambda_6d20deecaf4856105ebacbad442d1079> *)&local_18,
                     (<lambda_9a32fed5bf61b6b509b2d3f6003082a1> *)&local_14,
                     (<lambda_63ea2239ed67c638ddbae41947fdf875> *)&local_10);
  return iVar2;
}

