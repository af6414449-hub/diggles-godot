
/* Library Function - Single Match
    _fesetenv
   
   Library: Visual Studio 2019 Release */

undefined4 __cdecl fesetenv(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  ___acrt_fenv_set_control(*param_1);
  ___acrt_fenv_set_status(param_1[1]);
  local_c = 0;
  local_8 = 0;
  iVar1 = fegetenv(&local_c);
  if (((iVar1 == 0) && (*param_1 == local_c)) && (param_1[1] == local_8)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

