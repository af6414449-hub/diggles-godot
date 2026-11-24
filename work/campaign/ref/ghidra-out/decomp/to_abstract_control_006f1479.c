
/* Library Function - Single Match
    enum __acrt_fenv_abstract_control __cdecl to_abstract_control(enum
   __acrt_fenv_machine_sse_control)
   
   Library: Visual Studio 2019 Release */

__acrt_fenv_abstract_control __cdecl to_abstract_control(__acrt_fenv_machine_sse_control param_1)

{
  ushort uVar1;
  __acrt_fenv_machine_sse_control _Var2;
  __acrt_fenv_abstract_control _Var3;
  __acrt_fenv_abstract_control _Var4;
  
  _Var4 = 0;
  uVar1 = (ushort)param_1 & 0x8040;
  if (uVar1 == 0x8000) {
    _Var3 = 0xc00;
  }
  else if (uVar1 == 0x40) {
    _Var3 = 0x800;
  }
  else {
    _Var3 = 0x400;
    if (uVar1 != 0x8040) {
      _Var3 = 0;
    }
  }
  _Var2 = param_1 & 0x6000;
  if (_Var2 != 0) {
    if (_Var2 == 0x2000) {
      _Var4 = 0x100;
    }
    else if (_Var2 == 0x4000) {
      _Var4 = 0x200;
    }
    else if (_Var2 == 0x6000) {
      _Var4 = 0x300;
    }
  }
  return (param_1 >> 10 & 1) << 2 |
         (param_1 >> 8 & 1) << 5 | (param_1 >> 7 & 1) << 4 | (param_1 >> 9 & 1) << 3 |
         (param_1 >> 0xb & 1) * 2 | param_1 >> 0xc & 1 | _Var4 | _Var3;
}

