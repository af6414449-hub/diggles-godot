
/* Library Function - Single Match
    enum __acrt_fenv_machine_x87_control __cdecl to_machine_x87_control(enum
   __acrt_fenv_abstract_control)
   
   Library: Visual Studio 2019 Release */

__acrt_fenv_machine_x87_control __cdecl to_machine_x87_control(__acrt_fenv_abstract_control param_1)

{
  uint uVar1;
  __acrt_fenv_machine_x87_control _Var2;
  uint uVar3;
  __acrt_fenv_machine_x87_control _Var4;
  
  uVar3 = param_1 >> 2;
  _Var4 = 0;
  if ((param_1 & 0x3000) == 0) {
    _Var2 = 0x300;
  }
  else {
    _Var2 = _Var4;
    if ((param_1 & 0x3000) == 0x1000) {
      _Var2 = 0x200;
    }
  }
  uVar1 = (param_1 & 0xc00000) >> 0xe;
  if (uVar1 != 0) {
    if (uVar1 == 0x100) {
      _Var4 = 0x400;
    }
    else if (uVar1 == 0x200) {
      _Var4 = 0x800;
    }
    else if (uVar1 == 0x300) {
      _Var4 = 0xc00;
    }
  }
  return ((uVar3 & 0x20000) >> 0x11) << 2 |
         ((uVar3 & 0x8000) >> 0xf) << 4 | ((uVar3 & 0x10000) >> 0x10) << 3 |
         ((uVar3 & 0x80000) >> 0x13) * 2 | (uVar3 & 0x40000) >> 0x12 |
         ((uVar3 & 0x4000) >> 0xe) << 5 | param_1 >> 2 & 0x1000 | _Var2 | _Var4;
}

