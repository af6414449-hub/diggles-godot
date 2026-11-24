
/* Library Function - Single Match
    wchar_t * __cdecl common_getdcwd<wchar_t>(int,wchar_t *,int,int,char const * const,int)
   
   Library: Visual Studio 2019 Release */

wchar_t * __cdecl
common_getdcwd<wchar_t>
          (int param_1,wchar_t *param_2,int param_3,int param_4,char *param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  ulong *puVar3;
  wchar_t *pwVar4;
  wchar_t *local_28;
  int local_24;
  wchar_t *local_20;
  int local_1c;
  undefined4 local_18;
  char local_14;
  wchar_t local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (param_3 < 0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
    goto LAB_006deeec;
  }
  if (param_1 == 0) {
    param_1 = __getdrive();
LAB_006def01:
    if (param_1 == 0) {
      local_10 = L'.';
      local_e = 0;
    }
    else {
      local_10 = (short)param_1 + L'@';
      local_e = 0x3a;
      local_c = 0x2e;
      local_a = 0;
    }
    if (param_2 == (wchar_t *)0x0) {
      local_28 = (wchar_t *)0x0;
      local_24 = 0;
      local_20 = (wchar_t *)0x0;
      local_1c = 0;
      local_18 = 0;
      local_14 = '\0';
      __crt_win32_buffer<wchar_t,struct___crt_win32_buffer_public_dynamic_resizing>::allocate
                ((__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_public_dynamic_resizing> *)
                 &local_28,param_3);
      iVar2 = __acrt_get_full_path_name_wide<struct___crt_win32_buffer_public_dynamic_resizing>
                        (&local_10,
                         (__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_public_dynamic_resizing>
                          *)&local_28);
      if (iVar2 == 0) {
        __crt_win32_buffer<wchar_t,struct___crt_win32_buffer_public_dynamic_resizing>::detach
                  ((__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_public_dynamic_resizing> *)
                   &local_28);
        if (local_14 != '\0') {
          FUN_006df631(local_20);
        }
      }
      else if (local_14 != '\0') {
        FUN_006df631(local_20);
      }
      goto LAB_006deeec;
    }
    if (0 < param_3) {
      local_28 = param_2;
      *param_2 = L'\0';
      local_18 = 0;
      local_14 = '\0';
      local_24 = param_3;
      local_20 = param_2;
      local_1c = param_3;
      __acrt_get_full_path_name_wide<struct___crt_win32_buffer_no_resizing>
                (&local_10,
                 (__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_no_resizing> *)&local_28);
      goto LAB_006deeec;
    }
    piVar1 = __errno();
    *piVar1 = 0x16;
  }
  else {
    iVar2 = is_valid_drive(param_1);
    if (iVar2 != 0) goto LAB_006def01;
    puVar3 = ___doserrno();
    *puVar3 = 0xf;
    piVar1 = __errno();
    *piVar1 = 0xd;
  }
  FUN_006e510d();
LAB_006deeec:
  pwVar4 = (wchar_t *)__security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return pwVar4;
}

