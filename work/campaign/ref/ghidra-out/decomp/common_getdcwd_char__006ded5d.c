
/* Library Function - Single Match
    char * __cdecl common_getdcwd<char>(int,char *,int,int,char const * const,int)
   
   Library: Visual Studio 2019 Release */

char * __cdecl
common_getdcwd<char>(int param_1,char *param_2,int param_3,int param_4,char *param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  ulong *puVar3;
  char *pcVar4;
  char *local_20;
  int local_1c;
  char *local_18;
  int local_14;
  undefined4 local_10;
  char local_c;
  undefined1 local_8 [3];
  undefined1 local_5;
  
  if (param_3 < 0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  else {
    if (param_1 == 0) {
      param_1 = __getdrive();
    }
    else {
      iVar2 = is_valid_drive(param_1);
      if (iVar2 == 0) {
        puVar3 = ___doserrno();
        *puVar3 = 0xf;
        piVar1 = __errno();
        *piVar1 = 0xd;
        FUN_006e510d();
        return (char *)0x0;
      }
    }
    if (param_1 == 0) {
      local_8._0_2_ = 0x2e;
    }
    else {
      local_8._1_2_ = 0x2e3a;
      local_8[0] = (char)param_1 + '@';
      local_5 = 0;
    }
    if (param_2 == (char *)0x0) {
      local_20 = (char *)0x0;
      local_1c = 0;
      local_18 = (char *)0x0;
      local_14 = 0;
      local_10 = 0;
      local_c = '\0';
      __crt_win32_buffer<char,struct___crt_win32_buffer_public_dynamic_resizing>::allocate
                ((__crt_win32_buffer<char,struct___crt_win32_buffer_public_dynamic_resizing> *)
                 &local_20,param_3);
      iVar2 = __acrt_get_full_path_name_narrow_acp_or_utf8<>(local_8,&local_20);
      if (iVar2 == 0) {
        pcVar4 = __crt_win32_buffer<char,struct___crt_win32_buffer_public_dynamic_resizing>::detach
                           ((__crt_win32_buffer<char,struct___crt_win32_buffer_public_dynamic_resizing>
                             *)&local_20);
        if (local_c != '\0') {
          FUN_006df631(local_18);
          return pcVar4;
        }
        return pcVar4;
      }
      if (local_c != '\0') {
        FUN_006df631(local_18);
      }
    }
    else if (param_3 < 1) {
      piVar1 = __errno();
      *piVar1 = 0x16;
      FUN_006e510d();
    }
    else {
      *param_2 = '\0';
      local_10 = 0;
      local_c = 0;
      local_20 = param_2;
      local_1c = param_3;
      local_18 = param_2;
      local_14 = param_3;
      iVar2 = __acrt_get_full_path_name_narrow_acp_or_utf8<>(local_8,&local_20);
      if (iVar2 == 0) {
        return param_2;
      }
    }
  }
  return (char *)0x0;
}

