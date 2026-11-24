
/* Library Function - Single Match
    int __cdecl common_gmtime_s<__int64>(struct tm * const,__int64 const * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_gmtime_s<__int64>(tm *param_1,__int64 *param_2)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  tm *ptVar9;
  uint local_10;
  uint local_c;
  bool local_5;
  
  if (param_1 == (tm *)0x0) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
  }
  else {
    ptVar9 = param_1;
    for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
      ptVar9->tm_sec = -1;
      ptVar9 = (tm *)&ptVar9->tm_min;
    }
    if (param_2 == (__int64 *)0x0) {
      piVar2 = __errno();
      *piVar2 = 0x16;
      FUN_006e510d();
    }
    else {
      local_c = *(uint *)((int)param_2 + 4);
      local_10 = (uint)*param_2;
      if (((local_c < 0x80000000) || ((-2 < (int)local_c && (0xffff573f < local_10)))) &&
         (((int)local_c < 7 || (((int)local_c < 8 && (local_10 < 0x9358efe0)))))) {
        local_5 = false;
        iVar5 = compute_year((__int64 *)&local_10,&local_5);
        uVar1 = local_10;
        param_1->tm_year = iVar5;
        iVar5 = __alldiv(local_10,local_c,0x15180,0);
        uVar3 = (uint)((longlong)iVar5 * 0x15180);
        param_1->tm_yday = iVar5;
        uVar7 = uVar1 - uVar3;
        local_c = (local_c - (int)((ulonglong)((longlong)iVar5 * 0x15180) >> 0x20)) -
                  (uint)(uVar1 < uVar3);
        puVar6 = (undefined4 *)&DAT_00718980;
        if (local_5 == false) {
          puVar6 = &DAT_0071894c;
        }
        iVar4 = 1;
        iVar8 = puVar6[1];
        while (iVar8 < iVar5) {
          iVar4 = iVar4 + 1;
          iVar8 = puVar6[iVar4];
        }
        param_1->tm_mon = iVar4 + -1;
        param_1->tm_mday = iVar5 - puVar6[iVar4 + -1];
        iVar5 = __alldiv((int)*param_2,*(undefined4 *)((int)param_2 + 4),0x15180,0);
        uVar1 = local_c;
        param_1->tm_wday = (iVar5 + 4) % 7;
        iVar5 = __alldiv(uVar7,local_c,0xe10,0);
        param_1->tm_hour = iVar5;
        uVar3 = (uint)((longlong)iVar5 * 0xe10);
        iVar8 = uVar7 - uVar3;
        iVar5 = __alldiv(iVar8,(uVar1 - (int)((ulonglong)((longlong)iVar5 * 0xe10) >> 0x20)) -
                               (uint)(uVar7 < uVar3),0x3c,0);
        param_1->tm_isdst = 0;
        param_1->tm_min = iVar5;
        param_1->tm_sec = iVar8 + iVar5 * -0x3c;
        return 0;
      }
      piVar2 = __errno();
      *piVar2 = 0x16;
    }
  }
  return 0x16;
}

