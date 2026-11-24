
/* Library Function - Single Match
    int __cdecl common_localtime_s<__int64>(struct tm * const,__int64 const * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_localtime_s<__int64>(tm *param_1,__int64 *param_2)

{
  uint uVar1;
  int *piVar2;
  errno_t eVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  tm *ptVar7;
  uint uVar8;
  bool bVar9;
  longlong lVar10;
  uint local_18;
  int local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  if (param_1 == (tm *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    return 0x16;
  }
  ptVar7 = param_1;
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    ptVar7->tm_sec = -1;
    ptVar7 = (tm *)&ptVar7->tm_min;
  }
  if (param_2 == (__int64 *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    return 0x16;
  }
  if (((*(int *)((int)param_2 + 4) < 1) && (*(int *)((int)param_2 + 4) < 0)) ||
     ((6 < *(int *)((int)param_2 + 4) &&
      ((7 < *(int *)((int)param_2 + 4) || (0x93582aff < (uint)*param_2)))))) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    return 0x16;
  }
  ___tzset();
  local_c = 0;
  local_10 = 0;
  local_8 = 0;
  eVar3 = __get_daylight(&local_c);
  if (((eVar3 != 0) || (eVar3 = __get_dstbias((long *)&local_10), eVar3 != 0)) ||
     (eVar3 = __get_timezone((long *)&local_8), eVar3 != 0)) {
                    /* WARNING: Subroutine does not return */
    __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
  }
  uVar1 = (uint)*param_2;
  uVar4 = *(int *)((int)param_2 + 4) + -1 + (uint)(0x3f480 < uVar1);
  if ((7 < uVar4) || ((6 < uVar4 && (0x935041fd < uVar1 - 0x3f481)))) {
    iVar5 = FUN_006dd9cc(param_1,param_2);
    if (iVar5 != 0) {
      return iVar5;
    }
    uVar1 = param_1->tm_sec;
    uVar4 = local_8;
    if ((local_c != 0) && (iVar5 = __isindst(param_1), uVar4 = local_8, iVar5 != 0)) {
      param_1->tm_isdst = 1;
      uVar4 = local_8 + local_10;
    }
    uVar8 = uVar1 - uVar4;
    iVar6 = (((int)uVar1 >> 0x1f) - ((int)uVar4 >> 0x1f)) - (uint)(uVar1 < uVar4);
    iVar5 = __allrem(uVar8,iVar6,0x3c,0);
    param_1->tm_sec = iVar5;
    if (iVar5 < 0) {
      bVar9 = 0x3b < uVar8;
      uVar8 = uVar8 - 0x3c;
      param_1->tm_sec = iVar5 + 0x3c;
      iVar6 = iVar6 + -1 + (uint)bVar9;
    }
    lVar10 = __alldiv(uVar8,iVar6,0x3c,0);
    lVar10 = lVar10 + param_1->tm_min;
    iVar5 = __allrem(lVar10,0x3c,0);
    param_1->tm_min = iVar5;
    if (iVar5 < 0) {
      param_1->tm_min = iVar5 + 0x3c;
      lVar10 = lVar10 + -0x3c;
    }
    lVar10 = __alldiv(lVar10,0x3c,0);
    lVar10 = lVar10 + param_1->tm_hour;
    iVar5 = __allrem(lVar10,0x18,0);
    param_1->tm_hour = iVar5;
    if (iVar5 < 0) {
      param_1->tm_hour = iVar5 + 0x18;
      lVar10 = lVar10 + -0x18;
    }
    lVar10 = __alldiv(lVar10,0x18,0);
    iVar5 = (int)lVar10;
    if (-1 < lVar10) {
      if ((0xffffffff < lVar10) || (iVar5 != 0)) {
        param_1->tm_mday = param_1->tm_mday + iVar5;
        param_1->tm_yday = param_1->tm_yday + iVar5;
        param_1->tm_wday = (param_1->tm_wday + iVar5) % 7;
        return 0;
      }
      if (0xffffffff < lVar10) {
        return 0;
      }
      if (-1 < lVar10) {
        return 0;
      }
    }
    param_1->tm_mday = param_1->tm_mday + iVar5;
    param_1->tm_wday = (param_1->tm_wday + 7 + iVar5) % 7;
    iVar5 = param_1->tm_yday + iVar5;
    if (param_1->tm_mday < 1) {
      param_1->tm_mon = 0xb;
      param_1->tm_year = param_1->tm_year + -1;
      param_1->tm_mday = param_1->tm_mday + 0x1f;
      param_1->tm_yday = iVar5 + 0x16d;
    }
    else {
      param_1->tm_yday = iVar5;
    }
    return 0;
  }
  local_18 = uVar1 - local_8;
  local_14 = (*(int *)((int)param_2 + 4) - ((int)local_8 >> 0x1f)) - (uint)(uVar1 < local_8);
  iVar5 = FUN_006dd9cc(param_1,&local_18);
  if (iVar5 != 0) {
    return iVar5;
  }
  if (local_c == 0) {
    return 0;
  }
  iVar5 = __isindst(param_1);
  if (iVar5 == 0) {
    return 0;
  }
  bVar9 = local_18 < local_10;
  local_18 = local_18 - local_10;
  local_14 = (local_14 - ((int)local_10 >> 0x1f)) - (uint)bVar9;
  iVar5 = FUN_006dd9cc(param_1,&local_18);
  if (iVar5 == 0) {
    param_1->tm_isdst = 1;
    return 0;
  }
  return iVar5;
}

