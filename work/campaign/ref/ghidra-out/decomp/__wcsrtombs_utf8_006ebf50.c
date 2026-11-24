
/* Library Function - Single Match
    unsigned int __cdecl __crt_mbstring::__wcsrtombs_utf8(char *,wchar_t const * *,unsigned
   int,struct _Mbstatet *)
   
   Library: Visual Studio 2019 Release */

uint __cdecl
__crt_mbstring::__wcsrtombs_utf8(char *param_1,wchar_t **param_2,uint param_3,_Mbstatet *param_4)

{
  uint uVar1;
  wchar16 *pwVar2;
  char *pcVar3;
  wchar16 *pwVar4;
  undefined4 local_14;
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  pwVar4 = *param_2;
  pwVar2 = pwVar4;
  if (param_1 == (char *)0x0) {
    while ((uVar1 = __c16rtomb_utf8(local_10,*pwVar4,param_4), uVar1 != 0xffffffff &&
           ((uVar1 == 0 || (local_10[uVar1 - 1] != '\0'))))) {
      pwVar4 = pwVar4 + 1;
    }
  }
  else {
    while( true ) {
      local_14 = pwVar2;
      pcVar3 = param_1;
      if (param_3 < 4) {
        pcVar3 = local_10;
      }
      uVar1 = __c16rtomb_utf8(pcVar3,*pwVar4,param_4);
      if (uVar1 == 0xffffffff) {
        *param_2 = local_14;
        goto LAB_006ec03f;
      }
      if (pcVar3 != param_1) {
        pwVar2 = local_14;
        if (param_3 < uVar1) goto LAB_006ebff7;
        FUN_006d2250(param_1,pcVar3,uVar1);
      }
      if ((uVar1 != 0) && (param_1[uVar1 - 1] == '\0')) break;
      pwVar4 = pwVar4 + 1;
      if (uVar1 != 0) {
        local_14 = pwVar4;
      }
      param_3 = param_3 - uVar1;
      param_1 = param_1 + uVar1;
      pwVar2 = local_14;
    }
    pwVar2 = (wchar16 *)0x0;
LAB_006ebff7:
    *param_2 = pwVar2;
  }
LAB_006ec03f:
  uVar1 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return uVar1;
}

