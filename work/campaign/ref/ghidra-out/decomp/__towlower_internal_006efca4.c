
/* Library Function - Single Match
    __towlower_internal
   
   Library: Visual Studio 2019 Release */

uint __towlower_internal(uint param_1,_locale_t param_2)

{
  wint_t wVar1;
  
  if ((ushort)param_1 < 0x100) {
    if (((&DAT_0071874a)[(param_1 & 0xff) * 2] & 1) != 0) {
      param_1 = (uint)param_2->locinfo->pclmap[param_1 & 0xff];
    }
    return param_1 & 0xff;
  }
  wVar1 = __towlower_l((ushort)param_1,param_2);
  return (uint)wVar1;
}

