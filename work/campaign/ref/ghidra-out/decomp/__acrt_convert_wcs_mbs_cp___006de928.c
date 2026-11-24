
/* Library Function - Multiple Matches With Same Base Name
    int __cdecl __acrt_convert_wcs_mbs_cp<wchar_t,char,class
   <lambda_28bda7af82a03b66c1cb3803a755f95d>,struct
   __crt_win32_buffer_internal_dynamic_resizing>(wchar_t const * const,class
   __crt_win32_buffer<char,struct __crt_win32_buffer_internal_dynamic_resizing> &,class
   <lambda_28bda7af82a03b66c1cb3803a755f95d> const &,unsigned int)
    int __cdecl __acrt_convert_wcs_mbs_cp<wchar_t,char,class
   <lambda_fecc33a432ccb74a901dff60d61ca385>,struct
   __crt_win32_buffer_public_dynamic_resizing>(wchar_t const * const,class
   __crt_win32_buffer<char,struct __crt_win32_buffer_public_dynamic_resizing> &,class
   <lambda_fecc33a432ccb74a901dff60d61ca385> const &,unsigned int)
   
   Library: Visual Studio 2019 Release */

int __acrt_convert_wcs_mbs_cp<>
              (short *param_1,
              __crt_win32_buffer<char,struct___crt_win32_buffer_public_dynamic_resizing> *param_2,
              undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  int *piVar4;
  
  if (param_1 == (short *)0x0) {
    deallocate();
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  else {
    if (*param_1 != 0) {
      uVar2 = ___acrt_WideCharToMultiByte(param_4,0,param_1,0xffffffff,0,0,0,0);
      if (uVar2 == 0) {
        DVar3 = GetLastError();
        ___acrt_errno_map_os_error(DVar3);
        piVar4 = __errno();
        return *piVar4;
      }
      if ((*(uint *)(param_2 + 0xc) < uVar2) &&
         (iVar1 = __crt_win32_buffer<char,struct___crt_win32_buffer_public_dynamic_resizing>::
                  allocate(param_2,uVar2), iVar1 != 0)) {
        return iVar1;
      }
      iVar1 = ___acrt_WideCharToMultiByte
                        (param_4,0,param_1,0xffffffff,*(undefined4 *)(param_2 + 8),
                         *(undefined4 *)(param_2 + 0xc),0,0);
      if (iVar1 == 0) {
        DVar3 = GetLastError();
        ___acrt_errno_map_os_error(DVar3);
        piVar4 = __errno();
        return *piVar4;
      }
      *(int *)(param_2 + 0x10) = iVar1 + -1;
      return 0;
    }
    if ((*(int *)(param_2 + 0xc) == 0) &&
       (iVar1 = __crt_win32_buffer<char,struct___crt_win32_buffer_public_dynamic_resizing>::allocate
                          (param_2,1), iVar1 != 0)) {
      return iVar1;
    }
    **(undefined1 **)(param_2 + 8) = 0;
  }
  *(undefined4 *)(param_2 + 0x10) = 0;
  return 0;
}

