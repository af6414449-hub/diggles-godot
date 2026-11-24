
/* Library Function - Single Match
    __set_new_mode
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 __set_new_mode(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = DAT_00769d58;
  if ((param_1 != 0) && (param_1 != 1)) {
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
    return 0xffffffff;
  }
  LOCK();
  DAT_00769d58 = param_1;
  UNLOCK();
  return uVar1;
}

