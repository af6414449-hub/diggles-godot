
/* Library Function - Single Match
    unsigned int __cdecl __crt_mbstring::__mbsrtowcs_utf8(wchar_t *,char const * *,unsigned
   int,struct _Mbstatet *)
   
   Library: Visual Studio 2019 Release */

uint __cdecl
__crt_mbstring::__mbsrtowcs_utf8(wchar_t *param_1,char **param_2,uint param_3,_Mbstatet *param_4)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  wchar32 in_ECX;
  wchar32 wVar4;
  wchar_t *pwVar5;
  char *pcVar6;
  wchar32 local_c;
  <lambda_3d301b9e52f5099be73030e1f0bf487e> local_5;
  
  pcVar6 = *param_2;
  if (param_1 == (wchar_t *)0x0) {
    uVar1 = 0;
    while( true ) {
      uVar3 = <lambda_3d301b9e52f5099be73030e1f0bf487e>::operator()(&local_5,pcVar6);
      uVar3 = __mbrtoc32_utf8((wchar32 *)0x0,pcVar6,uVar3,param_4);
      if (uVar3 == 0xffffffff) break;
      if (uVar3 == 0) {
        return uVar1;
      }
      if (uVar3 == 4) {
        uVar1 = uVar1 + 1;
      }
      pcVar6 = pcVar6 + uVar3;
      uVar1 = uVar1 + 1;
    }
    piVar2 = __errno();
    *piVar2 = 0x2a;
    uVar1 = 0xffffffff;
  }
  else {
    pwVar5 = param_1;
    local_c = in_ECX;
    if (param_3 != 0) {
      do {
        uVar1 = <lambda_3d301b9e52f5099be73030e1f0bf487e>::operator()(&local_5,pcVar6);
        uVar1 = __mbrtoc32_utf8(&local_c,pcVar6,uVar1,param_4);
        if (uVar1 == 0xffffffff) {
          *param_2 = pcVar6;
          piVar2 = __errno();
          *piVar2 = 0x2a;
          return 0xffffffff;
        }
        if (uVar1 == 0) {
          pcVar6 = (char *)0x0;
          *pwVar5 = L'\0';
          break;
        }
        wVar4 = local_c;
        if (0xffff < (uint)local_c) {
          if (param_3 < 2) break;
          local_c = local_c + L'\xffff0000';
          param_3 = param_3 - 1;
          *pwVar5 = (ushort)((uint)local_c >> 10) | 0xd800;
          pwVar5 = pwVar5 + 1;
          wVar4 = local_c & 0x3ffU | 0xdc00;
        }
        *pwVar5 = (wchar_t)wVar4;
        pcVar6 = pcVar6 + uVar1;
        pwVar5 = pwVar5 + 1;
        param_3 = param_3 - 1;
      } while (param_3 != 0);
    }
    uVar1 = (int)pwVar5 - (int)param_1 >> 1;
    *param_2 = pcVar6;
  }
  return uVar1;
}

