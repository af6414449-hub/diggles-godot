
/* Library Function - Single Match
    bool __cdecl __crt_time_is_day_valid(int,int,int)
   
   Library: Visual Studio 2019 Release */

bool __cdecl __crt_time_is_day_valid(int param_1,int param_2,int param_3)

{
  bool bVar1;
  
  if (param_3 < 1) {
LAB_006e9710:
    bVar1 = false;
  }
  else {
    if ((int)((&DAT_00718950)[param_2] - (&DAT_0071894c)[param_2]) < param_3) {
      bVar1 = __crt_time_is_leap_year<int>(param_1);
      if (((!bVar1) || (param_2 != 1)) || (0x1d < param_3)) goto LAB_006e9710;
    }
    bVar1 = true;
  }
  return bVar1;
}

