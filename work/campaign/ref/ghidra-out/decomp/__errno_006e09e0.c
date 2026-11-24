
/* Library Function - Single Match
    __errno
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

int * __cdecl __errno(void)

{
  int iVar1;
  
  iVar1 = ___acrt_getptd_noexit();
  if (iVar1 == 0) {
    return (int *)&DAT_00767100;
  }
  return (int *)(iVar1 + 0x10);
}

