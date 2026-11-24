
/* Library Function - Single Match
    _TestDefaultCountry
   
   Library: Visual Studio 2019 Release */

void _TestDefaultCountry(wchar_t *param_1)

{
  int iVar1;
  wchar_t local_1c [10];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  iVar1 = ___acrt_GetLocaleInfoEx_16(param_1,0x59,local_1c,9);
  if (iVar1 != 0) {
    _wcsncmp(local_1c,param_1,9);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

