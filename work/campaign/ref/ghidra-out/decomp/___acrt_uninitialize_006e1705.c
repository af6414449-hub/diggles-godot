
/* Library Function - Single Match
    ___acrt_uninitialize
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 ___acrt_uninitialize(char param_1)

{
  undefined4 uVar1;
  
  if (param_1 != '\0') {
    if (DAT_00769b44 != 0) {
      __flushall();
    }
    return 1;
  }
  uVar1 = ___acrt_execute_uninitializers(&PTR_LAB_00717188,&DAT_00717208);
  return uVar1;
}

