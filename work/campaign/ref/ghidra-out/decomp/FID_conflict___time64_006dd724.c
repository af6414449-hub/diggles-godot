
/* Library Function - Multiple Matches With Different Base Names
    __int64 __cdecl common_time<__int64>(__int64 * const)
    __time64
   
   Library: Visual Studio 2019 Release */

__time64_t __cdecl FID_conflict___time64(__time64_t *_Time)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_14 = 0;
  local_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  iVar1 = common_timespec_get<struct__timespec64>((_timespec64 *)&local_14,1);
  if (iVar1 != 1) {
    local_14 = 0xffffffff;
    local_10 = 0xffffffff;
  }
  if (_Time != (__time64_t *)0x0) {
    *(undefined4 *)_Time = local_14;
    *(undefined4 *)((int)_Time + 4) = local_10;
  }
  return CONCAT44(local_10,local_14);
}

