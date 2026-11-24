
/* Library Function - Single Match
    bool __cdecl __crt_strtox::is_overflow_condition<unsigned long>(unsigned int,unsigned long)
   
   Library: Visual Studio 2019 Release */

bool __cdecl __crt_strtox::is_overflow_condition<unsigned_long>(uint param_1,ulong param_2)

{
  if ((param_1 & 4) != 0) {
    return true;
  }
  if ((param_1 & 1) == 0) {
    return false;
  }
  if ((param_1 & 2) == 0) {
    if (param_2 < 0x80000000) {
      return false;
    }
  }
  else if (param_2 < 0x80000001) {
    return false;
  }
  return true;
}

