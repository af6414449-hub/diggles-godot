
/* Library Function - Single Match
    int __cdecl __acrt_wcs_to_mbs_cp<struct __crt_win32_buffer_no_resizing>(wchar_t const *
   const,class __crt_win32_buffer<char,struct __crt_win32_buffer_no_resizing> &,unsigned int)
   
   Library: Visual Studio 2019 Release */

int __cdecl
__acrt_wcs_to_mbs_cp<struct___crt_win32_buffer_no_resizing>
          (wchar_t *param_1,__crt_win32_buffer<char,struct___crt_win32_buffer_no_resizing> *param_2,
          uint param_3)

{
  int iVar1;
  <lambda_0fec1a7b3f42a53036604e18c2d5e07e> local_5;
  
  iVar1 = __acrt_convert_wcs_mbs_cp<wchar_t,char,class_<lambda_0fec1a7b3f42a53036604e18c2d5e07e>,struct___crt_win32_buffer_no_resizing>
                    (param_1,param_2,&local_5,param_3);
  return iVar1;
}

