
/* Library Function - Single Match
    unsigned int __cdecl __crt_mbstring::__mbrtowc_utf8(wchar_t *,char const *,unsigned int,struct
   _Mbstatet *)
   
   Library: Visual Studio 2019 Release */

uint __cdecl
__crt_mbstring::__mbrtowc_utf8(wchar_t *param_1,char *param_2,uint param_3,_Mbstatet *param_4)

{
  uint uVar1;
  wchar32 local_8;
  
  uVar1 = __mbrtoc32_utf8(&local_8,param_2,param_3,param_4);
  if (uVar1 < 5) {
    if (0xffff < (uint)local_8) {
      local_8 = L'�';
    }
    if (param_1 != (wchar_t *)0x0) {
      *param_1 = (wchar_t)local_8;
    }
  }
  return uVar1;
}

