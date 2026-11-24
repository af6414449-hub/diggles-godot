
/* Library Function - Single Match
    void __cdecl cvtdate(enum `anonymous namespace'::transition_type,enum
   A0x7639d0b4::date_type,int,int,int,int,int,int,int,int,int)
   
   Library: Visual Studio 2019 Release */

void __cdecl
cvtdate(transition_type param_1,date_type param_2,int param_3,int param_4,int param_5,int param_6,
       int param_7,int param_8,int param_9,int param_10,int param_11)

{
  bool bVar1;
  int iVar2;
  errno_t eVar3;
  int iVar4;
  long local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  bVar1 = __crt_time_is_leap_year<int>(param_3);
  uStack_8._3_1_ = bVar1;
  if (param_2 == 1) {
    if (bVar1) {
      iVar4 = *(int *)(&DAT_0071897c + param_4 * 4);
    }
    else {
      iVar4 = *(int *)(&DAT_00718948 + param_4 * 4);
    }
    iVar2 = __crt_time_elapsed_leap_years<int>(param_3);
    iVar2 = (iVar2 + iVar4 + 1 + param_3 * 0x16d + -0x63ca) % 7;
    iVar4 = iVar4 + 1 + (param_5 * 7 - iVar2) + param_6;
    if (iVar2 <= param_6) {
      iVar4 = iVar4 + -7;
    }
    if (uStack_8._3_1_ == '\0') {
      iVar2 = (&DAT_0071894c)[param_4];
    }
    else {
      iVar2 = *(int *)(&DAT_00718980 + param_4 * 4);
    }
    if ((param_5 == 5) && (iVar2 < iVar4)) {
      iVar4 = iVar4 + -7;
    }
  }
  else {
    if (bVar1) {
      iVar4 = *(int *)(&DAT_0071897c + param_4 * 4);
    }
    else {
      iVar4 = *(int *)(&DAT_00718948 + param_4 * 4);
    }
    iVar4 = iVar4 + param_7;
  }
  iVar2 = param_11 + ((param_8 * 0x3c + param_9) * 0x3c + param_10) * 1000;
  if (param_1 == 0) {
    DAT_007670e8 = param_3;
    DAT_007670ec = iVar4;
    DAT_007670f0 = iVar2;
  }
  else {
    DAT_007670f8 = iVar4;
    DAT_007670fc = iVar2;
    eVar3 = __get_dstbias(&local_c);
    if (eVar3 != 0) {
                    /* WARNING: Subroutine does not return */
      __invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);
    }
    DAT_007670fc = DAT_007670fc + local_c * 1000;
    DAT_007670f4 = param_3;
    if (DAT_007670fc < 0) {
      DAT_007670fc = DAT_007670fc + 86400000;
      DAT_007670f8 = DAT_007670f8 + -1;
    }
    else if (86399999 < DAT_007670fc) {
      DAT_007670fc = DAT_007670fc + -86400000;
      DAT_007670f8 = DAT_007670f8 + 1;
    }
  }
  return;
}

