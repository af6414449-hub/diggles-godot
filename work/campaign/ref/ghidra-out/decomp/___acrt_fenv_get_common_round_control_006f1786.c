
/* Library Function - Single Match
    ___acrt_fenv_get_common_round_control
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

uint ___acrt_fenv_get_common_round_control(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 >> 0xe & 0x300;
  if (uVar1 != (param_1 >> 0x16 & 0x300)) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

