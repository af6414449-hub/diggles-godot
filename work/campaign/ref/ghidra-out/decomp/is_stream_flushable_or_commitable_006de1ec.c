
/* Library Function - Single Match
    bool __cdecl is_stream_flushable_or_commitable(long)
   
   Library: Visual Studio 2019 Release */

bool __cdecl is_stream_flushable_or_commitable(long param_1)

{
  if (((((byte)param_1 & 3) != 2) || ((param_1 & 0xc0U) == 0)) && ((param_1 & 0x800U) == 0)) {
    return false;
  }
  return true;
}

