
/* Library Function - Single Match
    ___acrt_initialize_multibyte
   
   Library: Visual Studio 2019 Release */

undefined4 ___acrt_initialize_multibyte(void)

{
  __acrt_ptd *p_Var1;
  
  if (DAT_0076a1f4 == '\0') {
    DAT_0076a1ec = &DAT_007673b8;
    DAT_0076a1e8 = &DAT_007676e0;
    DAT_0076a1e4 = &DAT_007675d8;
    p_Var1 = (__acrt_ptd *)___acrt_getptd_head();
    setmbcp_internal(-3,true,p_Var1,(__crt_multibyte_data **)&DAT_0076a1ec);
    DAT_0076a1f4 = '\x01';
  }
  return 1;
}

