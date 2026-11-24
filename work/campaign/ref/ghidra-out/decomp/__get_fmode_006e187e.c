
/* Library Function - Single Match
    __get_fmode
   
   Library: Visual Studio 2019 Release */

errno_t __cdecl __get_fmode(int *_PMode)

{
  int *piVar1;
  
  if (_PMode == (int *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    return 0x16;
  }
  *_PMode = DAT_0076a218;
  return 0;
}

