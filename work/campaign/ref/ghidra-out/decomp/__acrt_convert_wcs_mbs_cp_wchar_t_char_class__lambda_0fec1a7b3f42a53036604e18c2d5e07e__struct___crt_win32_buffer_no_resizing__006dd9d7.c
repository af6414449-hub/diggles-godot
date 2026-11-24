
/* Library Function - Single Match
    int __cdecl __acrt_convert_wcs_mbs_cp<wchar_t,char,class
   <lambda_0fec1a7b3f42a53036604e18c2d5e07e>,struct __crt_win32_buffer_no_resizing>(wchar_t const *
   const,class __crt_win32_buffer<char,struct __crt_win32_buffer_no_resizing> &,class
   <lambda_0fec1a7b3f42a53036604e18c2d5e07e> const &,unsigned int)
   
   Library: Visual Studio 2019 Release */

int __cdecl
__acrt_convert_wcs_mbs_cp<wchar_t,char,class_<lambda_0fec1a7b3f42a53036604e18c2d5e07e>,struct___crt_win32_buffer_no_resizing>
          (wchar_t *param_1,__crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing> *param_2,
          <lambda_0fec1a7b3f42a53036604e18c2d5e07e> *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  int *piVar4;
  
  if (param_1 == (wchar_t *)0x0) {
    __crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing>::set_to_nullptr(param_2);
    iVar1 = 0;
  }
  else if (*param_1 == L'\0') {
    if ((*(int *)(param_2 + 0xc) != 0) ||
       (iVar1 = __crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing>::allocate(param_2,1),
       iVar1 == 0)) {
      **(undefined1 **)(param_2 + 8) = 0;
      iVar1 = 0;
      *(undefined4 *)(param_2 + 0x10) = 0;
    }
  }
  else {
    uVar2 = ___acrt_WideCharToMultiByte(param_4,0,param_1,0xffffffff,0,0,0,0);
    if (uVar2 == 0) {
      DVar3 = GetLastError();
      ___acrt_errno_map_os_error(DVar3);
      piVar4 = __errno();
      iVar1 = *piVar4;
    }
    else if ((uVar2 <= *(uint *)(param_2 + 0xc)) ||
            (iVar1 = __crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing>::allocate
                               (param_2,uVar2), iVar1 == 0)) {
      iVar1 = ___acrt_WideCharToMultiByte
                        (param_4,0,param_1,0xffffffff,*(undefined4 *)(param_2 + 8),
                         *(undefined4 *)(param_2 + 0xc),0,0);
      if (iVar1 == 0) {
        DVar3 = GetLastError();
        ___acrt_errno_map_os_error(DVar3);
        piVar4 = __errno();
        iVar1 = *piVar4;
      }
      else {
        *(int *)(param_2 + 0x10) = iVar1 + -1;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}

