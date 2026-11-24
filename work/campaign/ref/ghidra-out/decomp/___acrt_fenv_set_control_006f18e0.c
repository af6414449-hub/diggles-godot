
/* Library Function - Single Match
    ___acrt_fenv_set_control
   
   Library: Visual Studio 2019 Release */

void ___acrt_fenv_set_control(__acrt_fenv_abstract_control param_1)

{
  __acrt_fenv_machine_x87_control _Var1;
  __acrt_fenv_machine_sse_control _Var2;
  int iVar3;
  __acrt_fenv_machine_x87_control *p_Var4;
  undefined2 in_FPUControlWord;
  __acrt_fenv_machine_x87_control local_24 [8];
  
  _Var1 = to_machine_x87_control(param_1);
  p_Var4 = local_24;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *p_Var4 = 0;
    p_Var4 = p_Var4 + 1;
  }
  local_24[0] = CONCAT22(local_24[0]._2_2_,in_FPUControlWord);
  local_24[0] = local_24[0] ^ (_Var1 & 0xffff ^ local_24[0]) & 7999;
  _Var2 = to_machine_sse_control(param_1);
  if (0 < DAT_00769a88) {
    MXCSR = MXCSR & 0xffff003f | _Var2 & 0xffc0;
  }
  return;
}

