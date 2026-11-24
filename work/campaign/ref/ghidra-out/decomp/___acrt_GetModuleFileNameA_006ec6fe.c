
/* Library Function - Single Match
    ___acrt_GetModuleFileNameA
   
   Library: Visual Studio 2019 Release */

void ___acrt_GetModuleFileNameA(HMODULE param_1,undefined4 param_2,undefined4 param_3)

{
  DWORD DVar1;
  uint uVar2;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined1 local_21c;
  <lambda_0fec1a7b3f42a53036604e18c2d5e07e> local_215;
  WCHAR local_214 [262];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  DVar1 = GetModuleFileNameW(param_1,local_214,0x105);
  if (DVar1 == 0) {
    DVar1 = GetLastError();
    ___acrt_errno_map_os_error(DVar1);
  }
  else {
    local_220 = 0;
    local_230 = param_2;
    local_22c = param_3;
    local_228 = param_2;
    local_224 = param_3;
    local_21c = 0;
    uVar2 = __acrt_get_utf8_acp_compatibility_codepage();
    __acrt_convert_wcs_mbs_cp<wchar_t,char,class_<lambda_0fec1a7b3f42a53036604e18c2d5e07e>,struct___crt_win32_buffer_no_resizing>
              (local_214,
               (__crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing> *)&local_230,
               &local_215,uVar2);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

