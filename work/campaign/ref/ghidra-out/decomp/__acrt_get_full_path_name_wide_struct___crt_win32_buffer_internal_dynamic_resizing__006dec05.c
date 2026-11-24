
/* Library Function - Single Match
    int __cdecl __acrt_get_full_path_name_wide<struct
   __crt_win32_buffer_internal_dynamic_resizing>(wchar_t const * const,class
   __crt_win32_buffer<wchar_t,struct __crt_win32_buffer_internal_dynamic_resizing> &)
   
   Library: Visual Studio 2019 Release */

int __cdecl
__acrt_get_full_path_name_wide<struct___crt_win32_buffer_internal_dynamic_resizing>
          (wchar_t *param_1,
          __crt_win32_buffer<wchar_t,struct___crt_win32_buffer_internal_dynamic_resizing> *param_2)

{
  DWORD DVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  DVar1 = GetFullPathNameW(param_1,*(DWORD *)(param_2 + 0xc),*(LPWSTR *)(param_2 + 8),(LPWSTR *)0x0)
  ;
  if (DVar1 == 0) {
LAB_006dec25:
    DVar1 = GetLastError();
    ___acrt_errno_map_os_error(DVar1);
    piVar2 = __errno();
    iVar4 = *piVar2;
  }
  else {
    if (*(uint *)(param_2 + 0xc) < DVar1) {
      iVar3 = __crt_win32_buffer<wchar_t,struct___crt_win32_buffer_internal_dynamic_resizing>::
              allocate(param_2,DVar1 + 1);
      if (iVar3 != 0) {
        return iVar3;
      }
      DVar1 = GetFullPathNameW(param_1,*(DWORD *)(param_2 + 0xc),*(LPWSTR *)(param_2 + 8),
                               (LPWSTR *)0x0);
      if (DVar1 == 0) goto LAB_006dec25;
    }
    *(DWORD *)(param_2 + 0x10) = DVar1;
  }
  return iVar4;
}

