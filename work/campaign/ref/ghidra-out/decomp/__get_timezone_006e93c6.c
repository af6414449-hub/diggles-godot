
/* Library Function - Multiple Matches With Different Base Names
    __get_daylight
    __get_timezone
   
   Library: Visual Studio 2019 Release */

errno_t __cdecl __get_timezone(long *_Timezone)

{
  int *piVar1;
  
  if (_Timezone == (long *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    return 0x16;
  }
  *_Timezone = DAT_0076a1d0;
  return 0;
}

