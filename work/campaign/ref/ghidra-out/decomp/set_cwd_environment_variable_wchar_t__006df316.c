
/* Library Function - Single Match
    int __cdecl set_cwd_environment_variable<wchar_t>(wchar_t const * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl set_cwd_environment_variable<wchar_t>(wchar_t *param_1)

{
  wchar_t wVar1;
  int iVar2;
  BOOL BVar3;
  DWORD DVar4;
  WCHAR local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  wVar1 = *param_1;
  if (((wVar1 != L'\\') && (wVar1 != L'/')) || (wVar1 != param_1[1])) {
    iVar2 = _toupper((int)(char)*param_1);
    local_e = (undefined2)iVar2;
    local_c = 0x3a;
    local_a = 0;
    local_10 = L'=';
    BVar3 = SetEnvironmentVariableW(&local_10,param_1);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      ___acrt_errno_map_os_error(DVar4);
    }
  }
  iVar2 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar2;
}

