
/* Library Function - Single Match
    _fegetenv
   
   Library: Visual Studio 2019 Release */

undefined4 __cdecl fegetenv(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = ___acrt_fenv_get_control();
  *param_1 = uVar1;
  uVar1 = ___acrt_fenv_get_status();
  param_1[1] = uVar1;
  return 0;
}

