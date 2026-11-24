
/* Library Function - Single Match
    ___acrt_fenv_get_control
   
   Library: Visual Studio 2019 Release */

__acrt_fenv_abstract_control ___acrt_fenv_get_control(void)

{
  __acrt_fenv_abstract_control _Var1;
  __acrt_fenv_abstract_control _Var2;
  int iVar3;
  __acrt_fenv_machine_sse_control _Var4;
  ushort *puVar5;
  ushort in_FPUControlWord;
  ushort local_24 [14];
  __acrt_fenv_machine_sse_control local_8;
  
  puVar5 = local_24;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    puVar5[0] = 0;
    puVar5[1] = 0;
    puVar5 = puVar5 + 2;
  }
  local_24[0] = in_FPUControlWord;
  _Var1 = to_abstract_control(in_FPUControlWord & 7999);
  if (DAT_00769a88 < 1) {
    _Var4 = 0;
  }
  else {
    local_8 = MXCSR;
    _Var4 = MXCSR & 0xffc0;
  }
  _Var2 = to_abstract_control(_Var4);
  return _Var2 | ((((_Var2 & 0x3f) << 2 | _Var2 & 0xffffff00) << 6 | _Var1 & 0x3f) << 2 |
                 _Var1 & 0x300) << 0xe | _Var1;
}

