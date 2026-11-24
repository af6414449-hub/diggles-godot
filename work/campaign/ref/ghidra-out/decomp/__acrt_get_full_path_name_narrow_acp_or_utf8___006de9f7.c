
/* Library Function - Multiple Matches With Same Base Name
    int __cdecl __acrt_get_full_path_name_narrow_acp_or_utf8<struct
   __crt_win32_buffer_no_resizing>(char const * const,class __crt_win32_buffer<char,struct
   __crt_win32_buffer_no_resizing> &)
    int __cdecl __acrt_get_full_path_name_narrow_acp_or_utf8<struct
   __crt_win32_buffer_public_dynamic_resizing>(char const * const,class
   __crt_win32_buffer<char,struct __crt_win32_buffer_public_dynamic_resizing> &)
   
   Library: Visual Studio 2019 Release */

void __acrt_get_full_path_name_narrow_acp_or_utf8<>
               (char *param_1,
               __crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing> *param_2)

{
  uint uVar1;
  int iVar2;
  wchar_t *_Memory;
  wchar_t *local_44c;
  undefined4 local_448;
  wchar_t *local_444;
  undefined4 local_440;
  undefined4 local_43c;
  char local_438;
  wchar_t *local_434;
  undefined4 local_430;
  wchar_t *local_42c;
  undefined4 local_428;
  undefined4 local_424;
  char local_420;
  __crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing> *local_41c;
  wchar_t local_418 [260];
  wchar_t local_210 [260];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  local_41c = param_2;
  _Memory = local_210;
  local_434 = local_418;
  local_448 = 0x104;
  local_440 = 0x104;
  local_43c = 0;
  local_438 = '\0';
  local_430 = 0x104;
  local_428 = 0x104;
  local_424 = 0;
  local_420 = '\0';
  local_44c = _Memory;
  local_444 = _Memory;
  local_42c = local_434;
  uVar1 = __acrt_get_utf8_acp_compatibility_codepage();
  iVar2 = __acrt_mbs_to_wcs_cp<struct___crt_win32_buffer_internal_dynamic_resizing>
                    (param_1,(__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_internal_dynamic_resizing>
                              *)&local_434,uVar1);
  if (iVar2 == 0) {
    iVar2 = __acrt_get_full_path_name_wide<struct___crt_win32_buffer_internal_dynamic_resizing>
                      (local_42c,
                       (__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_internal_dynamic_resizing>
                        *)&local_44c);
    _Memory = local_444;
    if (iVar2 == 0) {
      __acrt_wcs_to_mbs_cp<struct___crt_win32_buffer_no_resizing>(local_444,local_41c,uVar1);
    }
  }
  if (local_420 != '\0') {
    FID_conflict__free(local_42c);
  }
  if (local_438 != '\0') {
    FID_conflict__free(_Memory);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

