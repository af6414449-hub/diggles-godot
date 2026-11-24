
/* Library Function - Single Match
    int __cdecl common_chdir<wchar_t>(wchar_t const * const)
   
   Library: Visual Studio 2019 Release */

int __cdecl common_chdir<wchar_t>(wchar_t *param_1)

{
  ulong *puVar1;
  int *piVar2;
  BOOL BVar3;
  DWORD DVar4;
  int iVar5;
  wchar_t *local_22c;
  undefined4 local_228;
  wchar_t *local_224;
  undefined4 local_220;
  undefined4 local_21c;
  char local_218;
  wchar_t local_214 [262];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (param_1 == (wchar_t *)0x0) {
    puVar1 = ___doserrno();
    *puVar1 = 0;
    piVar2 = __errno();
    *piVar2 = 0x16;
    FUN_006e510d();
  }
  else {
    BVar3 = SetCurrentDirectoryW(param_1);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      ___acrt_errno_map_os_error(DVar4);
    }
    else {
      local_21c = 0;
      local_22c = local_214;
      local_228 = 0x105;
      local_220 = 0x105;
      local_218 = '\0';
      local_224 = local_22c;
      iVar5 = __acrt_get_current_directory_wide<struct___crt_win32_buffer_internal_dynamic_resizing>
                        ((__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_internal_dynamic_resizing>
                          *)&local_22c);
      if (iVar5 == 0) {
        set_cwd_environment_variable<wchar_t>(local_224);
      }
      if (local_218 != '\0') {
        FID_conflict__free(local_224);
      }
    }
  }
  iVar5 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar5;
}

