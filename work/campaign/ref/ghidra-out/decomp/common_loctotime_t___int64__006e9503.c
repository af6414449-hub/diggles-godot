
/* Library Function - Single Match
    __int64 __cdecl common_loctotime_t<__int64>(int,int,int,int,int,int,int)
   
   Library: Visual Studio 2019 Release */

__int64 __cdecl
common_loctotime_t<__int64>
          (int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7)

{
  uint uVar1;
  longlong lVar2;
  bool bVar3;
  errno_t eVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  __int64 _Var9;
  int local_40;
  uint local_3c;
  long local_38;
  uint local_34;
  int local_30;
  tm local_2c;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  uVar8 = param_1 - 0x76c;
  if (((((int)uVar8 < 0x46) || (0x44d < uVar8)) || (0xb < param_2 - 1U)) ||
     (((bVar3 = __crt_time_is_day_valid(uVar8,param_2 - 1U,param_3), !bVar3 ||
       (0x17 < (uint)param_4)) || ((0x3b < (uint)param_5 || (0x3b < (uint)param_6)))))) {
    piVar6 = __errno();
    *piVar6 = 0x16;
    iVar5 = -1;
  }
  else {
    iVar7 = *(int *)(&DAT_00718948 + param_2 * 4) + param_3;
    bVar3 = __crt_time_is_leap_year<int>(uVar8);
    if ((bVar3) && (2 < param_2)) {
      iVar7 = iVar7 + 1;
    }
    ___tzset();
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    eVar4 = __get_daylight(&local_40);
    if (((eVar4 != 0) || (eVar4 = __get_dstbias((long *)&local_3c), eVar4 != 0)) ||
       (eVar4 = __get_timezone(&local_38), eVar4 != 0)) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    iVar5 = __crt_time_elapsed_leap_years<int>(uVar8);
    lVar2 = (longlong)iVar5 * 0x15180 + (longlong)iVar7 * 0x15180 + (longlong)(int)uVar8 * 0x1e13380
            + (longlong)param_4 * 0xe10 + (longlong)param_5 * 0x3c + (longlong)local_38 +
            (longlong)param_6;
    uVar1 = (uint)lVar2;
    local_34 = uVar1 + 0x7c6beb00;
    local_30 = (int)((ulonglong)lVar2 >> 0x20) - (uint)(uVar1 < 0x83941500);
    iVar5 = ((int)local_3c >> 0x1f) + local_30 + (uint)CARRY4(local_3c,local_34);
    if (param_7 != 1) {
      local_2c.tm_mon = param_2 + -1;
      local_2c.tm_hour = param_4;
      local_2c.tm_min = param_5;
      local_2c.tm_sec = param_6;
      local_2c.tm_year = uVar8;
      local_2c.tm_yday = iVar7;
      if (((param_7 != -1) || (local_40 == 0)) || (iVar7 = __isindst(&local_2c), iVar7 == 0)) {
        iVar5 = local_30;
      }
    }
  }
  _Var9 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc,iVar5);
  return _Var9;
}

