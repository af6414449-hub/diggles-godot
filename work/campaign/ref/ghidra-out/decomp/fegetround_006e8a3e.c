
/* Library Function - Single Match
    _fegetround
   
   Library: Visual Studio 2019 Release */

void __cdecl fegetround(void)

{
  undefined4 uVar1;
  
  uVar1 = ___acrt_fenv_get_control();
  ___acrt_fenv_get_common_round_control(uVar1);
  return;
}

