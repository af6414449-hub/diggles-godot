
/* Library Function - Single Match
    __get_dstbias
   
   Library: Visual Studio 2019 Release */

errno_t __cdecl __get_dstbias(long *_Daylight_savings_bias)

{
  int *piVar1;
  
  if (_Daylight_savings_bias == (long *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    return 0x16;
  }
  *_Daylight_savings_bias = DAT_0076a1d8;
  return 0;
}

