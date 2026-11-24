
/* Library Function - Single Match
    int __cdecl __acrt_get_current_directory_wide<struct
   __crt_win32_buffer_internal_dynamic_resizing>(class __crt_win32_buffer<wchar_t,struct
   __crt_win32_buffer_internal_dynamic_resizing> &)
   
   Library: Visual Studio 2019 Release */

int __cdecl
__acrt_get_current_directory_wide<struct___crt_win32_buffer_internal_dynamic_resizing>
          (__crt_win32_buffer<wchar_t,struct___crt_win32_buffer_internal_dynamic_resizing> *param_1)

{
  DWORD DVar1;
  int *piVar2;
  int iVar3;
  
  DVar1 = GetCurrentDirectoryW(*(DWORD *)(param_1 + 0xc),*(LPWSTR *)(param_1 + 8));
  if (DVar1 == 0) {
LAB_006df206:
    DVar1 = GetLastError();
    ___acrt_errno_map_os_error(DVar1);
    piVar2 = __errno();
    iVar3 = *piVar2;
  }
  else {
    if (*(uint *)(param_1 + 0xc) < DVar1) {
      iVar3 = __crt_win32_buffer<wchar_t,struct___crt_win32_buffer_internal_dynamic_resizing>::
              allocate(param_1,DVar1 + 1);
      if (iVar3 != 0) {
        return iVar3;
      }
      DVar1 = GetCurrentDirectoryW(*(DWORD *)(param_1 + 0xc),*(LPWSTR *)(param_1 + 8));
      if (DVar1 == 0) goto LAB_006df206;
    }
    *(DWORD *)(param_1 + 0x10) = DVar1;
    iVar3 = 0;
  }
  return iVar3;
}

