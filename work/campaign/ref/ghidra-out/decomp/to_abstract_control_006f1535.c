
/* Library Function - Single Match
    enum __acrt_fenv_abstract_control __cdecl to_abstract_control(enum
   __acrt_fenv_machine_x87_control)
   
   Library: Visual Studio 2019 Release */

__acrt_fenv_abstract_control __cdecl to_abstract_control(__acrt_fenv_machine_x87_control param_1)

{
  __acrt_fenv_machine_x87_control _Var1;
  __acrt_fenv_abstract_control _Var2;
  undefined4 local_8;
  
  local_8 = 0x1000;
  _Var2 = 0;
  if ((param_1 & 0x300) == 0) {
    local_8 = 0x2000;
  }
  else if ((param_1 & 0x300) != 0x200) {
    local_8 = 0;
  }
  _Var1 = param_1 & 0xc00;
  if (_Var1 != 0) {
    if (_Var1 == 0x400) {
      _Var2 = 0x100;
    }
    else if (_Var1 == 0x800) {
      _Var2 = 0x200;
    }
    else if (_Var1 == 0xc00) {
      _Var2 = 0x300;
    }
  }
  return (param_1 >> 4 & 1) * 2 |
         (param_1 >> 1 & 1) << 5 | (param_1 >> 2 & 1) << 3 | (param_1 >> 3 & 1) << 2 |
         (param_1 & 1) << 4 | param_1 >> 5 & 1 | (param_1 & 0x1000) << 2 | _Var2 | local_8;
}

