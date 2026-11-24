
/* Library Function - Single Match
    int __cdecl __crt_time_elapsed_leap_years<int>(int)
   
   Library: Visual Studio 2019 Release */

int __cdecl __crt_time_elapsed_leap_years<int>(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 + -1;
  return ((int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2) + -0x11 + ((param_1 + 299) / 400 - iVar1 / 100);
}

