
/* Library Function - Single Match
    bool __cdecl __crt_time_is_leap_year<int>(int)
   
   Library: Visual Studio 2019 Release */

bool __cdecl __crt_time_is_leap_year<int>(int param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = param_1 & 0x80000003;
  bVar2 = uVar1 == 0;
  if ((int)uVar1 < 0) {
    bVar2 = (uVar1 - 1 | 0xfffffffc) == 0xffffffff;
  }
  if ((bVar2) && (param_1 % 100 != 0)) {
    return true;
  }
  if ((param_1 + 0x76c) % 400 == 0) {
    return true;
  }
  return false;
}

