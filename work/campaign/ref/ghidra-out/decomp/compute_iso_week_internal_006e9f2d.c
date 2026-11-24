
/* Library Function - Single Match
    int __cdecl compute_iso_week_internal(int,int,int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl compute_iso_week_internal(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = ((param_3 - (param_2 + 6) % 7) + 7) / 7;
  bVar1 = __crt_time_is_leap_year<int>(param_1);
  iVar5 = param_3 - (uint)bVar1;
  iVar3 = ((param_2 - param_3) + 0x173) % 7;
  iVar4 = (int)(bVar1 + 0x16d + iVar3) % 7;
  if ((((iVar5 < 0x16c) || (iVar4 != 2)) && ((iVar5 < 0x16b || (iVar4 != 3)))) &&
     ((iVar5 < 0x16a || (iVar4 != 4)))) {
    if ((iVar3 == 2) || ((iVar3 == 3 || (iVar3 == 4)))) {
      iVar2 = iVar2 + 1;
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}

