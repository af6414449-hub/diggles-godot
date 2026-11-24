
/* Library Function - Single Match
    int __cdecl common_find_first_narrow<struct _wfinddata64i32_t,struct _finddata64i32_t>(char
   const * const,struct _finddata64i32_t * const,unsigned int)
   
   Library: Visual Studio 2019 Release */

int __cdecl
common_find_first_narrow<struct__wfinddata64i32_t,struct__finddata64i32_t>
          (char *param_1,_finddata64i32_t *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 local_250;
  undefined4 local_24c;
  wchar_t *local_248;
  undefined4 local_244;
  undefined4 local_240;
  char local_23c;
  _wfinddata64i32_t local_238 [560];
  uint local_8;
  
  local_8 = DAT_0076700c ^ (uint)&stack0xfffffffc;
  if (param_2 == (_finddata64i32_t *)0x0) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  else {
    local_250 = 0;
    local_24c = 0;
    local_248 = (wchar_t *)0x0;
    local_244 = 0;
    local_240 = 0;
    local_23c = '\0';
    iVar2 = __acrt_mbs_to_wcs_cp<struct___crt_win32_buffer_internal_dynamic_resizing>
                      (param_1,(__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_internal_dynamic_resizing>
                                *)&local_250,param_3);
    if ((iVar2 == 0) &&
       (iVar2 = common_find_first_wide<struct__wfinddata64i32_t>(local_248,local_238), iVar2 != -1))
    {
      copy_wide_to_narrow_find_data<struct__wfinddata64i32_t,struct__finddata64i32_t>
                (local_238,param_2,param_3);
    }
    if (local_23c != '\0') {
      FID_conflict__free(local_248);
    }
  }
  iVar2 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar2;
}

