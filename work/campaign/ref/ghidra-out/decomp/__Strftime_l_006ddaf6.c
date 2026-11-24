
/* Library Function - Single Match
    __Strftime_l
   
   Library: Visual Studio 2019 Release */

uint __Strftime_l(undefined1 *param_1,int param_2,char *param_3,int param_4,undefined4 param_5,
                 __crt_locale_pointers *param_6)

{
  int *piVar1;
  int iVar2;
  wchar_t *_Memory;
  uint uVar3;
  undefined1 *local_48;
  int local_44;
  undefined1 *local_40;
  int local_3c;
  uint local_38;
  undefined1 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  void *local_28;
  undefined4 local_24;
  undefined4 local_20;
  char local_1c;
  int local_18;
  int local_14;
  char local_c;
  uint local_8;
  
  _LocaleUpdate::_LocaleUpdate((_LocaleUpdate *)&local_18,param_6);
  uVar3 = 0;
  local_8 = *(uint *)(local_14 + 0x14);
  if ((((param_1 == (undefined1 *)0x0) || (param_2 == 0)) || (*param_1 = 0, param_3 == (char *)0x0))
     || (param_4 == 0)) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_006e510d();
  }
  else {
    local_30 = 0;
    local_2c = 0;
    local_28 = (void *)0x0;
    local_24 = 0;
    local_20 = 0;
    local_1c = '\0';
    iVar2 = __acrt_mbs_to_wcs_cp<struct___crt_win32_buffer_internal_dynamic_resizing>
                      (param_3,(__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_internal_dynamic_resizing>
                                *)&local_30,local_8);
    if (iVar2 == 0) {
      _Memory = (wchar_t *)__malloc_base(param_2 * 2);
      if (_Memory != (wchar_t *)0x0) {
        iVar2 = __Wcsftime_l(_Memory,param_2,local_28,param_4,param_5,param_6);
        if (iVar2 != 0) {
          local_48 = param_1;
          local_40 = param_1;
          local_44 = param_2;
          local_3c = param_2;
          local_38 = 0;
          local_34 = 0;
          iVar2 = __acrt_wcs_to_mbs_cp<struct___crt_win32_buffer_no_resizing>
                            (_Memory,(__crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing>
                                      *)&local_48,local_8);
          uVar3 = ~-(uint)(iVar2 != 0) & local_38;
        }
      }
      FID_conflict__free(_Memory);
    }
    if (local_1c != '\0') {
      FID_conflict__free(local_28);
    }
  }
  if (local_c != '\0') {
    *(uint *)(local_18 + 0x350) = *(uint *)(local_18 + 0x350) & 0xfffffffd;
  }
  return uVar3;
}

