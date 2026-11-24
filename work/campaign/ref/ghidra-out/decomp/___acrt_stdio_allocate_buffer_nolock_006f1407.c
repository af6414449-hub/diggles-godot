
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Library Function - Single Match
    ___acrt_stdio_allocate_buffer_nolock
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void ___acrt_stdio_allocate_buffer_nolock(undefined4 *param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  _DAT_00769b48 = _DAT_00769b48 + 1;
  uVar3 = 0x1000;
  uVar2 = __malloc_base(0x1000);
  param_1[1] = uVar2;
  FID_conflict__free((void *)0x0);
  puVar1 = param_1 + 3;
  if (param_1[1] == 0) {
    LOCK();
    *puVar1 = *puVar1 | 0x400;
    UNLOCK();
    param_1[1] = param_1 + 5;
    uVar3 = 2;
  }
  else {
    LOCK();
    *puVar1 = *puVar1 | 0x40;
    UNLOCK();
  }
  param_1[6] = uVar3;
  param_1[2] = 0;
  *param_1 = param_1[1];
  return;
}

