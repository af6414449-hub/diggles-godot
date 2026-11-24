
/* Library Function - Single Match
    __int64 __cdecl convert_file_time_to_time_t<__int64>(struct _FILETIME const &)
   
   Library: Visual Studio 2019 Release */

__int64 __cdecl convert_file_time_to_time_t<__int64>(_FILETIME *param_1)

{
  BOOL BVar1;
  undefined4 extraout_EDX;
  undefined4 uVar2;
  __int64 _Var3;
  _SYSTEMTIME local_28;
  _SYSTEMTIME local_18;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if ((param_1->dwLowDateTime != 0) || (param_1->dwHighDateTime != 0)) {
    BVar1 = FileTimeToSystemTime(param_1,&local_28);
    if (BVar1 != 0) {
      BVar1 = SystemTimeToTzSpecificLocalTime((TIME_ZONE_INFORMATION *)0x0,&local_28,&local_18);
      if (BVar1 != 0) {
        FUN_006e9715(local_18.wYear,local_18.wMonth,local_18.wDay,local_18.wHour,local_18.wMinute,
                     local_18.wSecond,0xffffffff);
        uVar2 = extraout_EDX;
        goto LAB_006dcab0;
      }
    }
  }
  uVar2 = 0xffffffff;
LAB_006dcab0:
  _Var3 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,uVar2);
  return _Var3;
}

