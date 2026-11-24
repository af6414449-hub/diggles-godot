
/* Library Function - Single Match
    bool __cdecl common_flush_all_should_try_to_flush_stream(class __crt_stdio_stream,int * const)
   
   Library: Visual Studio 2019 Release */

bool __cdecl common_flush_all_should_try_to_flush_stream(int param_1,int *param_2)

{
  bool bVar1;
  
  if ((param_1 != 0) && ((*(uint *)(param_1 + 0xc) >> 0xd & 1) != 0)) {
    bVar1 = is_stream_flushable_or_commitable(*(uint *)(param_1 + 0xc));
    if (bVar1) {
      return true;
    }
    *param_2 = *param_2 + 1;
  }
  return false;
}

