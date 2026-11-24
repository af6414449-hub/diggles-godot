
/* Library Function - Single Match
    enum __acrt_fenv_machine_sse_control __cdecl to_machine_sse_control(enum
   __acrt_fenv_abstract_control)
   
   Library: Visual Studio 2019 Release */

__acrt_fenv_machine_sse_control __cdecl to_machine_sse_control(__acrt_fenv_abstract_control param_1)

{
  uint uVar1;
  __acrt_fenv_abstract_control _Var2;
  __acrt_fenv_machine_sse_control _Var3;
  uint uVar4;
  __acrt_fenv_machine_sse_control _Var5;
  
  uVar1 = param_1 >> 2;
  _Var2 = param_1 & 0xc00;
  uVar4 = (param_1 & 0xc03fffff) >> 0x16;
  _Var5 = 0;
  if (_Var2 == 0x400) {
    _Var3 = 0x8040;
  }
  else if (_Var2 == 0x800) {
    _Var3 = 0x40;
  }
  else if (_Var2 == 0xc00) {
    _Var3 = 0x8000;
  }
  else {
    _Var3 = 0;
  }
  if (uVar4 != 0) {
    if (uVar4 == 0x100) {
      _Var5 = 0x2000;
    }
    else if (uVar4 == 0x200) {
      _Var5 = 0x4000;
    }
    else if (uVar4 == 0x300) {
      _Var5 = 0x6000;
    }
  }
  return ((uVar1 & 0x8000000) >> 0x1b) << 8 |
         ((uVar1 & 0x800000) >> 0x17) << 0xb | ((uVar1 & 0x1000000) >> 0x18) << 10 |
         ((uVar1 & 0x2000000) >> 0x19) << 9 | ((uVar1 & 0x4000000) >> 0x1a) << 7 |
         ((uVar1 & 0x400000) >> 0x16) << 0xc | _Var3 | _Var5;
}

