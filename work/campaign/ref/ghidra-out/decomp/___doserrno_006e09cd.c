
/* Library Function - Single Match
    ___doserrno
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

ulong * __cdecl ___doserrno(void)

{
  int iVar1;
  
  iVar1 = ___acrt_getptd_noexit();
  if (iVar1 == 0) {
    return (ulong *)&DAT_00767104;
  }
  return (ulong *)(iVar1 + 0x14);
}

