
/* Library Function - Single Match
    int __cdecl compute_iso_week(int,int,int)
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int __cdecl compute_iso_week(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = compute_iso_week_internal(param_1,param_2,param_3);
  if (iVar2 == 0) {
    bVar1 = __crt_time_is_leap_year<int>(param_1 + -1);
    iVar2 = compute_iso_week_internal(param_1 + -1,(param_2 - param_3) + 7,bVar1 + 0x16d);
  }
  else if (iVar2 < 1) {
    iVar2 = 1;
  }
  return iVar2;
}

