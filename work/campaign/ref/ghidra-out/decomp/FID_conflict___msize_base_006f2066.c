
/* Library Function - Multiple Matches With Different Base Names
    __msize
    __msize_base
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

size_t __cdecl FID_conflict___msize_base(void *_Memory)

{
  int *piVar1;
  SIZE_T SVar2;
  
  if (_Memory == (void *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    return 0xffffffff;
  }
  SVar2 = HeapSize(DAT_0076a210,0,_Memory);
  return SVar2;
}

