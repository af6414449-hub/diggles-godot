
/* Library Function - Single Match
    int __cdecl compute_year(__int64 &,bool &)
   
   Library: Visual Studio 2019 Release */

int __cdecl compute_year(__int64 *param_1,bool *param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar1 = (uint)*param_1;
  iVar10 = *(int *)((int)param_1 + 4);
  iVar3 = __alldiv(uVar1,iVar10,0x1e13380,0);
  iVar7 = iVar3 + 0x46;
  iVar4 = __crt_time_elapsed_leap_years<int>(iVar7);
  uVar5 = (uint)((longlong)iVar4 * 0x15180);
  uVar6 = (uint)((longlong)iVar3 * 0x1e13380);
  uVar8 = uVar1 - uVar6;
  uVar9 = uVar8 - uVar5;
  iVar10 = (((iVar10 - (int)((ulonglong)((longlong)iVar3 * 0x1e13380) >> 0x20)) -
            (uint)(uVar1 < uVar6)) - (int)((ulonglong)((longlong)iVar4 * 0x15180) >> 0x20)) -
           (uint)(uVar8 < uVar5);
  *(uint *)param_1 = uVar9;
  *(int *)((int)param_1 + 4) = iVar10;
  if ((iVar10 < 1) && (iVar10 < 0)) {
    *(uint *)param_1 = uVar9 + 0x1e13380;
    iVar10 = iVar10 + (uint)(0xfe1ecc7f < uVar9);
    iVar7 = iVar3 + 0x45;
    *(int *)((int)param_1 + 4) = iVar10;
    bVar2 = __crt_time_is_leap_year<int>(iVar7);
    if (bVar2) {
      *(uint *)param_1 = uVar9 + 0x1e28500;
      *(uint *)((int)param_1 + 4) = iVar10 + (uint)(0xfffeae7f < uVar9 + 0x1e13380);
      *param_2 = true;
    }
  }
  else {
    bVar2 = __crt_time_is_leap_year<int>(iVar7);
    if (bVar2) {
      *param_2 = true;
    }
  }
  return iVar7;
}

